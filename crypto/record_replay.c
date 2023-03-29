#include "record_replay.h"

#ifndef _WIN32
#include <dlfcn.h>
#else
#include <libloaderapi.h>
#endif

static void* LookupRecordReplaySymbol(const char* name) {
#ifndef _WIN32
  void* fnptr = dlsym(RTLD_DEFAULT, name);
#else
  HMODULE module = GetModuleHandleA("windows-recordreplay.dll");
  void* fnptr = module ? (void*)GetProcAddress(module, name) : NULL;
#endif
  return fnptr ? fnptr : (void*)1;
}

int RecordReplay_IsRecordingOrReplaying(void) {
  static void* fnptr;
  if (!fnptr) {
    fnptr = LookupRecordReplaySymbol("RecordReplayAssert");
  }
  return fnptr != (void*)1;
}

int RecordReplay_IsReplaying(void) {
  static void* fnptr;
  if (!fnptr) {
    fnptr = LookupRecordReplaySymbol("RecordReplayIsReplaying");
  }
  if (fnptr == (void*)1) {
    return 0;
  }

  typedef int (*RecordReplayIsReplayingFn)(void);
  return ((RecordReplayIsReplayingFn)fnptr)();
}
