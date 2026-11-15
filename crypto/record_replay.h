#ifndef OPENSSL_HEADER_RECORD_REPLAY_H
#define OPENSSL_HEADER_RECORD_REPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

int RecordReplay_IsRecordingOrReplaying(void);
int RecordReplay_IsReplaying(void);

#ifdef __cplusplus
}
#endif

#endif // OPENSSL_HEADER_RECORD_REPLAY_H
