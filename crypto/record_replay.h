#ifndef OPENSSL_HEADER_RECORD_REPLAY_H
#define OPENSSL_HEADER_RECORD_REPLAY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int RecordReplay_IsRecordingOrReplaying(void);
int RecordReplay_IsReplaying(void);

// Returns |value| while recording and the recorded value while replaying, or
// |value| when not recording/replaying.
uintptr_t RecordReplay_Value(const char* why, uintptr_t value);

#ifdef __cplusplus
}
#endif

#endif // OPENSSL_HEADER_RECORD_REPLAY_H
