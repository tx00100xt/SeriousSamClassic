#include <Engine/Base/Synchronization.h>

#define WAIT_OBJECT_0 0
#define INFINITE 0xFFFFFFFF
#define VOID void
typedef void *PVOID;
typedef PVOID HANDLE;
typedef const char *LPCSTR;


LONG InterlockedIncrement(LONG *Addend);
LONG InterlockedDecrement(LONG volatile *Addend);
DWORD GetCurrentThreadId();
HANDLE CreateEvent(void *attr, BOOL bManualReset, BOOL initial, LPCSTR lpName);
BOOL CloseHandle(HANDLE hObject);
BOOL ResetEvent(HANDLE hEvent);
BOOL SetEvent(HANDLE hEvent);
DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
