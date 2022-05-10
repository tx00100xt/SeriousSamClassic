/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "Engine/StdH.h"
#include <Engine/Base/Synchronization.h>
//#pragma GCC optimize 0
CTCriticalSection::CTCriticalSection(void)
{
    cs_pvObject = (void *) new pthread_mutex_t;
    pthread_mutex_init((pthread_mutex_t *) cs_pvObject, NULL);
    LockCounter = 0;
    owner = 0;
}

CTCriticalSection::~CTCriticalSection(void)
{
    pthread_mutex_destroy((pthread_mutex_t *) cs_pvObject);
    delete (pthread_mutex_t *) cs_pvObject;
}

INDEX CTCriticalSection::Lock(void)
{
    if (owner == pthread_self())
        return(++LockCounter);
    if(owner==0 && LockCounter) {
        //printf("Warning, suspicious mutex state, force unlocking...\n");
        pthread_mutex_unlock((pthread_mutex_t *) cs_pvObject);
        LockCounter=0;
    }
    if(owner!=0) {
      // do something???
    }
    pthread_mutex_lock((pthread_mutex_t *) cs_pvObject);
    owner = pthread_self();
    return(++LockCounter);
}

INDEX CTCriticalSection::TryToLock(void)
{
    if (owner == pthread_self())
        return(++LockCounter);

    if (pthread_mutex_trylock((pthread_mutex_t *) cs_pvObject) == EBUSY)
        return(0);

    owner = pthread_self();
    return(++LockCounter);
}

INDEX CTCriticalSection::Unlock(void)
{
    if (owner == pthread_self())
    {
        if (LockCounter > 0)
        {
            if (--LockCounter == 0)
            {
                int ret = pthread_mutex_unlock((pthread_mutex_t *) cs_pvObject);
                owner = 0;
            }
        }
    }

    return(LockCounter);
}

CTSingleLock::CTSingleLock(CTCriticalSection *pcs, BOOL bLock) : sl_cs(*pcs)
{
  // initially not locked
  sl_bLocked = FALSE;
  sl_iLastLockedIndex = -2;
  // critical section must have index assigned
  //ASSERT(sl_cs.cs_iIndex>=1||sl_cs.cs_iIndex==-1);
  // if should lock immediately
  if (bLock) {
    Lock();
  }
}
CTSingleLock::~CTSingleLock(void)
{
  // if locked
  if (sl_bLocked) {
    // unlock
    Unlock();
  }
}
void CTSingleLock::Lock(void)
{
  // must not be locked
  ASSERT(!sl_bLocked);
  ASSERT(sl_iLastLockedIndex==-2);

  // if not locked
  if (!sl_bLocked) {
    // lock
    INDEX ctLocks = sl_cs.Lock();
    // if this mutex was not locked already
//    if (ctLocks==1) {
//      // check that locking in given order
//      if (sl_cs.cs_iIndex!=-1) {
//        ASSERT(_iLastLockedMutex<sl_cs.cs_iIndex);
//        sl_iLastLockedIndex = _iLastLockedMutex;
//        _iLastLockedMutex = sl_cs.cs_iIndex;
//      }
//    }
  }
  sl_bLocked = TRUE;
}

BOOL CTSingleLock::TryToLock(void)
{
  // must not be locked
  ASSERT(!sl_bLocked);
  // if not locked
  if (!sl_bLocked) {
    // if can lock
    INDEX ctLocks = sl_cs.TryToLock();
    if (ctLocks>=1) {
      sl_bLocked = TRUE;

      // if this mutex was not locked already
//      if (ctLocks==1) {
//        // check that locking in given order
//        if (sl_cs.cs_iIndex!=-1) {
//          ASSERT(_iLastLockedMutex<sl_cs.cs_iIndex);
//          sl_iLastLockedIndex = _iLastLockedMutex;
//          _iLastLockedMutex = sl_cs.cs_iIndex;
//        }
//      }
    }
  }
  return sl_bLocked;
}
BOOL CTSingleLock::IsLocked(void)
{
  return sl_bLocked;
}

void CTSingleLock::Unlock(void)
{
  // must be locked
  ASSERT(sl_bLocked);
  // if locked
  if (sl_bLocked) {
    // unlock
    INDEX ctLocks = sl_cs.Unlock();
    // if unlocked completely
    if (ctLocks==0) {
      // check that unlocking in exact reverse order
//      if (sl_cs.cs_iIndex!=-1) {
//        ASSERT(_iLastLockedMutex==sl_cs.cs_iIndex);
//        _iLastLockedMutex = sl_iLastLockedIndex;
//        sl_iLastLockedIndex = -2;
//      }
    }
  }
  sl_bLocked = FALSE;
}


