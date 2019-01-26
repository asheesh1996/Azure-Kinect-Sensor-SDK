/****************************************************************
                       Copyright (c)
                    Microsoft Corporation
                    All Rights Reserved
               Licensed under the MIT License.
****************************************************************/

#ifndef K4ASOUNDIO_UTIL_H
#define K4ASOUNDIO_UTIL_H

// System headers
//
#include <memory>

// Library headers
//
#include <soundio.h>

// Project headers
//

namespace k4aviewer
{
// Deleter functors for smart pointer types
//
struct SoundIoDeleter
{
    void operator()(SoundIo *s) const
    {
        soundio_destroy(s);
    }
};

struct SoundIoDeviceDeleter
{
    void operator()(SoundIoDevice *s) const
    {
        soundio_device_unref(s);
    }
};

struct SoundIoInStreamDeleter
{
    void operator()(SoundIoInStream *s) const
    {
        soundio_instream_destroy(s);
    }
};

struct SoundIoRingBufferDeleter
{
    void operator()(SoundIoRingBuffer *b) const
    {
        soundio_ring_buffer_destroy(b);
    }
};

using SoundIoUniquePtr = std::unique_ptr<SoundIo, SoundIoDeleter>;
using SoundIoInStreamUniquePtr = std::unique_ptr<SoundIoInStream, SoundIoInStreamDeleter>;
using SoundIoRingBufferUniquePtr = std::unique_ptr<SoundIoRingBuffer, SoundIoRingBufferDeleter>;
} // namespace k4aviewer

#endif
