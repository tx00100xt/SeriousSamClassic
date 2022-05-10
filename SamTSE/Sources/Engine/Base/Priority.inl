
#ifndef SE_INCL_PRIORITY_INL
#define SE_INCL_PRIORITY_INL
#ifdef PRAGMA_ONCE
  #pragma once
#endif

class CSetPriority {
public:
#ifdef PLATFORM_WIN32
  DWORD sp_dwProcessOld;
  int sp_iThreadOld;
  HANDLE sp_hThread;
  HANDLE sp_hProcess;
  CSetPriority(DWORD dwProcess, int iThread)
  {
    sp_hProcess = GetCurrentProcess();
    sp_hThread = GetCurrentThread();

    sp_dwProcessOld = GetPriorityClass(sp_hProcess);
    sp_iThreadOld = GetThreadPriority(sp_hThread);
    BOOL bSuccessProcess = SetPriorityClass(sp_hProcess, dwProcess);
    BOOL bSuccessThread = SetThreadPriority(sp_hThread, iThread);
    ASSERT(bSuccessProcess && bSuccessThread);
  }
  ~CSetPriority(void)
  {
    BOOL bSuccessProcess = SetPriorityClass(sp_hProcess, sp_dwProcessOld);
    BOOL bSuccessThread = SetThreadPriority(sp_hThread, sp_iThreadOld);
    ASSERT(bSuccessProcess && bSuccessThread);
  }

#else

  CSetPriority(DWORD dwProcess, int iThread) { STUBBED(""); }
  ~CSetPriority(void) { STUBBED(""); }

#endif
};

#endif /* include-once blocker. */

