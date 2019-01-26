#ifndef RECORDER_H
#define RECORDER_H

#include <atomic>
#include <k4a/k4a.h>

extern std::atomic_bool exiting;

int do_recording(uint8_t device_index,
                 char *recording_filename,
                 int recording_length,
                 k4a_device_configuration_t *device_config,
                 bool record_imu);

#endif /* RECORDER_H */
