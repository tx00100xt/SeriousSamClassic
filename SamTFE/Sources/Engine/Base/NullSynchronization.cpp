#include "Engine/StdH.h"
#include <Engine/Base/Synchronization.h>

#if (!defined SINGLE_THREADED)
#error you probably want to define SINGLE_THREADED if you compile this.
#endif

CTCriticalSection::CTCriticalSection(void) {}
CTCriticalSection::~CTCriticalSection(void) {}
INDEX CTCriticalSection::Lock(void) { return(1); }
INDEX CTCriticalSection::TryToLock(void) { return(1); }
INDEX CTCriticalSection::Unlock(void) { return(0); }
CTSingleLock::CTSingleLock(CTCriticalSection *pcs, BOOL bLock) : sl_cs(*pcs) {}
CTSingleLock::~CTSingleLock(void) {}
void CTSingleLock::Lock(void) {}
BOOL CTSingleLock::TryToLock(void) { return(TRUE); }
BOOL CTSingleLock::IsLocked(void) { return(TRUE); }
void CTSingleLock::Unlock(void) {}

// end of NullSynchronization.cpp ...

