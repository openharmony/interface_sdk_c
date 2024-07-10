/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file native_avcodec_audioencoder.h
 *
 * @brief Provides audio encoder capabilities.
 *
 * @kit AVCodecKit
 * @library libnative_media_aenc.so
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @since 9
 */

#ifndef NATIVE_AVCODEC_AUDIOENCODER_H
#define NATIVE_AVCODEC_AUDIOENCODER_H

#include <stdint.h>
#include <stdio.h>
#include "native_avcodec_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates an audio encoder instance from the mime type, this interface is recommended in most cases.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param mime mime type description string, refer to {@link AVCODEC_MIME_TYPE}
 * @return Returns a Pointer to an OH_AVCodec instance
 * @deprecated since 11
 * @useinstead OH_AudioCodec_CreateByMime
 * @since 9
 * @version 1.0
 */
OH_AVCodec *OH_AudioEncoder_CreateByMime(const char *mime);

/**
 * @brief Create an audio encoder instance through the audio encoder name.
 * The premise of using this interface is to know the exact name of the encoder.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param name Audio encoder name
 * @return Returns a Pointer to an OH_AVCodec instance
 * @deprecated since 11
 * @useinstead OH_AudioCodec_CreateByName
 * @since 9
 * @version 1.0
 */
OH_AVCodec *OH_AudioEncoder_CreateByName(const char *name);

/**
 * @brief Clear the internal resources of the encoder and destroy the encoder instance
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_Destroy
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_Destroy(OH_AVCodec *codec);

/**
 * @brief Set the asynchronous callback function so that your application can respond to
 * the events generated by the audio encoder. This interface must be called before Prepare is called.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param callback A collection of all callback functions, see {@link OH_AVCodecAsyncCallback}
 * @param userData User specific data
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_RegisterCallback
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData);

/**
 * @brief To configure the audio encoder, typically, you need to configure the description information of
 * the encoded audio track. This interface must be called before Prepare is called.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param format OH_AVFormat handle pointer
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_Configure
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_Configure(OH_AVCodec *codec, OH_AVFormat *format);

/**
 * @brief To prepare the internal resources of the encoder,
 * the Configure interface must be called before calling this interface.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_Prepare
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_Prepare(OH_AVCodec *codec);

/**
 * @brief Start the encoder, this interface must be called after the Prepare is successful.
 * After being successfully started, the encoder will start reporting NeedInputData events.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_Start
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_Start(OH_AVCodec *codec);

/**
 * @brief Stop the encoder. After stopping, you can re-enter the Started state through Start.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_Stop
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_Stop(OH_AVCodec *codec);

/**
 * @brief Clear the input and output data buffered in the encoder. After this interface is called,
 * all the Buffer indexes previously reported through the asynchronous callback will be invalidated,
 * make sure not to access the Buffers corresponding to these indexes.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_Flush
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_Flush(OH_AVCodec *codec);

/**
 * @brief Reset the encoder. To continue coding, you need to call the Configure interface
 * again to configure the encoder instance.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_Reset
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_Reset(OH_AVCodec *codec);

/**
 * @brief Get the description information of the output data of the encoder, refer to {@link OH_AVFormat} for details.
 * It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs to
 * be manually released by the caller.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @return Returns the OH_AVFormat handle pointer, the life cycle is refreshed with the next GetOutputMediaDescription,
 * or destroyed with OH_AVCodec;
 * @deprecated since 11
 * @useinstead OH_AudioCodec_GetOutputDescription
 * @since 9
 * @version 1.0
 */
OH_AVFormat *OH_AudioEncoder_GetOutputDescription(OH_AVCodec *codec);

/**
 * @brief Set dynamic parameters to the encoder. Note: This interface can only be called after the encoder is started.
 * At the same time, incorrect parameter settings may cause the encoding to fail.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param format OH_AVFormat handle pointer
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_SetParameter
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format);

/**
 * @brief Submit the input buffer filled with data to the audio encoder. The {@link OH_AVCodecOnNeedInputData}
 * callback will report the available input buffer and the corresponding index value. Once the buffer with the
 * specified index is submitted to the audio encoder, the buffer cannot be accessed again until the
 * callback is received again reporting that the buffer with the same index is available
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param index Enter the index value corresponding to the Buffer
 * @param attr Information describing the data contained in the Buffer
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_PushInputBuffer
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr);

/**
 * @brief Return the processed output Buffer to the encoder.
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param index The index value corresponding to the output Buffer
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_FreeOutputBuffer
 * @since 9
 * @version 1.0
 */
OH_AVErrCode OH_AudioEncoder_FreeOutputData(OH_AVCodec *codec, uint32_t index);

/**
 * @brief Check whether the current codec instance is valid. It can be used fault recovery or app
 * switchback from the background
 * @syscap SystemCapability.Multimedia.Media.AudioEncoder
 * @param codec Pointer to an OH_AVCodec instance
 * @param isValid Output Parameter. A pointer to a boolean instance, it is true if the codec instance is valid,
 * false if the codec instance is invalid
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 * @deprecated since 11
 * @useinstead OH_AudioCodec_IsValid
 * @since 10
 */
OH_AVErrCode OH_AudioEncoder_IsValid(OH_AVCodec *codec, bool *isValid);

#ifdef __cplusplus
}
#endif
#endif // NATIVE_AVCODEC_AUDIOENCODER_H