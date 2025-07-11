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
 * @addtogroup AVSource
 * @{
 *
 * @brief The AVSource module provides functions for constructing media resource object functionality.
 *
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @since 10
 */

/**
 * @file native_avsource.h
 *
 * @brief Declare the interface for parsing audio and video media data.
 *
 * @kit AVCodecKit
 * @library libnative_media_avsource.so
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @since 10
 */

#ifndef NATIVE_AVSOURCE_H
#define NATIVE_AVSOURCE_H

#include <stdint.h>
#include "native_avcodec_base.h"
#include "native_averrors.h"
#include "native_avformat.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Forward declaration of OH_AVSource.
 *
 * @since 10
 */
typedef struct OH_AVSource OH_AVSource;

/**
 * @brief Creates an OH_AVSource instance that models the media with dataSource.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param dataSource An Struct for a remote media resource.
 * @return Returns a pointer to an OH_AVSource instance if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 *  1. dataSource is nullptr.
 *  2. dataSource->size == 0.
 *  3. set data source failed.
 *  4. out of memory.
 *  5. demuxer engine is nullptr.
 * @since 12
*/
OH_AVSource *OH_AVSource_CreateWithDataSource(OH_AVDataSource *dataSource);

/**
 * @brief Creates an OH_AVSource instance with dataSource and userData.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param dataSource A pointer to the data source structure, which can obtain the input data.
 * @param userData A pointer to user-defined data.
 * @return Returns a pointer to an OH_AVSource instance if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 *  1. dataSource is nullptr.
 *  2. dataSource->size == 0.
 *  3. set data source failed.
 *  4. out of memory.
 *  5. demuxer engine is nullptr.
 * @since 20
 */
OH_AVSource *OH_AVSource_CreateWithDataSourceExt(OH_AVDataSourceExt *dataSource, void *userData);

/**
 * @brief Creates an OH_AVSource instance that models the media at the URI.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param uri An URI for a remote media resource.
 * @return Returns a pointer to an OH_AVSource instance if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 *  1. network anomaly.
 *  2. resource is invalid.
 *  3. file format is not supported.
 * @since 10
*/
OH_AVSource *OH_AVSource_CreateWithURI(char *uri);

/**
 * @brief Creates an OH_AVSource instance that models the media at the FileDescriptor.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param fd The fileDescriptor of data source.
 * @param offset The offset into the file to start reading.
 * @param size The file size in bytes.
 * @return Returns a pointer to an OH_AVSource instance if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 *  1. fd is invalid.
 *  2. offset is not start pos of resource.
 *  3. size error.
 *  4. resource is invalid.
 *  5. file format is not supported.
 * @since 10
*/
OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size);

/**
 * @brief Destroy the OH_AVSource instance and free the internal resources.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param source Pointer to an OH_AVSource instance.
 * @return Returns AV_ERR_OK if the execution is successful,
 * otherwise returns a specific error code, refer to {@link OH_AVErrCode}
 *          {@link AV_ERR_INVALID_VAL} source is invalid.
 * @since 10
*/
OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source);

/**
 * @brief Get the format info of source.
 * It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs
 * to be manually released by the caller.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param source Pointer to an OH_AVSource instance.
 * @return Returns the source's format info if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 *  1. source is invalid.
 * @since 10
*/
OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source);

/**
 * @brief Get the format info of track.
 * It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs
 * to be manually released by the caller.
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param source Pointer to an OH_AVSource instance.
 * @param trackIndex The track index to get format.
 * @return Returns the track's format info if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 *  1. source is invalid.
 *  2. trackIndex is out of range.
 * @since 10
*/
OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackIndex);

/**
 * @brief Get the format info of custom metadata.
 *
 * It should be noted that the life cycle of the OH_AVFormat instance pointed to by the return value * needs
 * to be manually released by the caller.
 *
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @param source Pointer to an OH_AVSource instance.
 * @return Returns the metadata's format info if the execution is successful, otherwise returns nullptr.
 * Possible failure causes:
 * 1. source is invalid.
 * @since 18
 */
OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source);

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVSOURCE_H
/** @} */