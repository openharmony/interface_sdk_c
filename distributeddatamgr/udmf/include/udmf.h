/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
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
 * @addtogroup UDMF
 * @{
 *
 * @brief The Unified Data Management Framework(UDMF) aims to define various standards
 * for data across applications, devices, and platforms, providing a unified OpenHarmony
 * data language and standardized data access and reading paths.
 *
 * @since 12
 */

/**
 * @file udmf.h
 *
 * @brief Provides unified data management framework related functions and enumerations.
 *
 * @kit ArkData
 * @library libudmf.so
 * @syscap SystemCapability.DistributedDataManager.UDMF.Core
 *
 * @since 12
 */

#ifndef UDMF_H
#define UDMF_H

#include <inttypes.h>
#include <stdbool.h>
#include "uds.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The key minimum memory space size of Unified Data.
 *
 * @since 12
 */
#define UDMF_KEY_BUFFER_LEN (512)

/**
 * @brief Describe the intention type of the udmf.
 *
 * @since 12
 */
typedef enum Udmf_Intention {
    /**
     * @brief The intention is drag.
     */
    UDMF_INTENTION_DRAG,
    /**
     * @brief The intention is pasteboard.
     */
    UDMF_INTENTION_PASTEBOARD,
    /**
     * @brief The intention is data hub.
     *
     * @since 20
     */
    UDMF_INTENTION_DATA_HUB,
    /**
     * @brief The intention is system share.
     *
     * @since 20
     */
    UDMF_INTENTION_SYSTEM_SHARE,
    /**
     * @brief The intention is picker.
     *
     * @since 20
     */
    UDMF_INTENTION_PICKER,
    /**
     * @brief The intention is menu.
     *
     * @since 20
     */
    UDMF_INTENTION_MENU,
} Udmf_Intention;

/**
 * @brief Describe intra-device usage range type enumeration.
 *
 * @since 12
 */
typedef enum Udmf_ShareOption {
    /**
     * @brief Invalid share option.
     */
    SHARE_OPTIONS_INVALID,
    /**
     * @brief Allowed to be used in the same application on this device.
     */
    SHARE_OPTIONS_IN_APP,
    /**
     * @brief Allowed to be used in the cross application on this device.
     */
    SHARE_OPTIONS_CROSS_APP
} Udmf_ShareOption;

/**
 * @brief Describe the types of file conflict options when getting data from the udmf.
 *
 * @since 15
 */
typedef enum Udmf_FileConflictOptions {
    /**
     * @brief Overwrite when dest uri has file with same name.
     */
    UDMF_OVERWRITE = 0,
    /**
     * @brief Skip when dest uri has file with same name.
     */
    UDMF_SKIP = 1,
} Udmf_FileConflictOptions;

/**
 * @brief Describe the types of progress indicator when getting data from the udmf.
 *
 * @since 15
*/
typedef enum Udmf_ProgressIndicator {
    /**
     * @brief Getting data without system default progress indicator.
    */
    UDMF_NONE = 0,
    /**
     * @brief Getting data with system default progress indicator.
    */
    UDMF_DEFAULT = 1
} Udmf_ProgressIndicator;

/**
 * @brief Describe the visibility range of data
 *
 * @since 20
 */
typedef enum Udmf_Visibility {
    /**
     * @brief The visibility level that specifies that any hap or native can be obtained.
     */
    UDMF_ALL,

    /**
     * @brief The visibility level that specifies that only data providers can be obtained.
     */
    UDMF_OWN_PROCESS
} Udmf_Visibility;

/**
 * @brief Describes the unified data type.
 *
 * @since 12
 */
typedef struct OH_UdmfData OH_UdmfData;

/**
 * @brief Describes the record type in the unified data.
 *
 * @since 12
 */
typedef struct OH_UdmfRecord OH_UdmfRecord;

/**
 * @brief Defines the data provider.
 *
 * @since 13
 */
typedef struct OH_UdmfRecordProvider OH_UdmfRecordProvider;

/**
 * @brief Describes some property parameters of unified data.
 *
 * @since 12
 */
typedef struct OH_UdmfProperty OH_UdmfProperty;

/**
 * @brief Represents the udmf progress information.
 *
 * @since 15
*/
typedef struct OH_Udmf_ProgressInfo OH_Udmf_ProgressInfo;

/**
 * @brief Represents the parameters of udmf get data with progress info.
 *
 * @since 15
*/
typedef struct OH_UdmfGetDataParams OH_UdmfGetDataParams;

/**
 * @brief Defines the callback function used to return the progress information and data.
 *
 * @param progressInfo The progress information notified to Application.
 * @param data Represents the unified data.
 * @since 15
*/
typedef void (*OH_Udmf_DataProgressListener)(OH_Udmf_ProgressInfo* progressInfo, OH_UdmfData* data);

/**
 * @brief Describes the optional arguments of data operation
 *
 * @since 20
 */
typedef struct OH_UdmfOptions OH_UdmfOptions;

/**
 * @brief Indicates data loading params.
 *
 * @since 20
 */
typedef struct OH_UdmfDataLoadParams OH_UdmfDataLoadParams;

/**
 * @brief Indicates data loading information.
 *
 * @since 20
 */
typedef struct OH_UdmfDataLoadInfo OH_UdmfDataLoadInfo;

/**
 * @brief Indicates the callback function for loading data.
 *
 * @param acceptableInfo Indicates the type and number of data that can be accepted by the receiver.
 * @return Returns the data to be loaded.
 * @since 20
 */
typedef OH_UdmfData* (*OH_Udmf_DataLoadHandler)(OH_UdmfDataLoadInfo* acceptableInfo);

/**
 * @brief Creation a pointer to the instance of the {@link OH_UdmfData}.
 *
 * @return If the operation is successful, a pointer to the instance of the {@link OH_UdmfData}
 * structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_UdmfData.
 * @since 12
 */
OH_UdmfData* OH_UdmfData_Create();

/**
 * @brief Destroy a pointer that points to the {@link OH_UdmfData} instance.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfData}.
 * @see OH_UdmfData.
 * @since 12
 */
void OH_UdmfData_Destroy(OH_UdmfData* pThis);

/**
 * @brief Add one {OH_UdmfRecord} record to the {@link OH_UdmfData} data.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param record Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfData Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record);

/**
 * @brief Check whether the type exists in the {@link OH_UdmfData} data.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param type Represents a string pointer of the type.
 * @return Returns the status of finding type.
 *         {@code false} is not existed.
 *         {@code true} is existed.
 * @see OH_UdmfData.
 * @since 12
 */
bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type);

/**
 * @brief Get all types in the {@link OH_UdmfData} data.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param count Represents the types count that is a output param.
 * @return Returns string array that in {@link OH_UdmfData} when input parameters valid,
 * otherwise return nullptr.
 * @see OH_UdmfData.
 * @since 12
 */
char** OH_UdmfData_GetTypes(OH_UdmfData* pThis, unsigned int* count);

/**
 * @brief Get all records in the {@link OH_UdmfData} data.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param count Represents the records count that is a output param.
 * @return Returns {@link OH_UdmfRecord} pointer array when input parameters valid, otherwise return nullptr.
 * @see OH_UdmfData OH_UdmfRecord.
 * @since 12
 */
OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count);

/**
 * @brief Defines the callback function used free the context.
 * @param context Pointer to the context which is to be free.
 * @since 13
 */
typedef void (*UdmfData_Finalize)(void* context);

/**
 * @brief Creates an {@link OH_UdmfRecordProvider} instance.
 *
 * @return Returns the pointer to the {@link OH_UdmfRecordProvider} instance created if the operation is successful.
 * Returns nullptr if the memory is not enough.
 * @see OH_UdmfRecordProvider.
 * @since 13
 */
OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create();

/**
 * @brief Destroy an {@link OH_UdmfRecordProvider} instance.
 *
 * @param provider Pointer to the {@link OH_UdmfRecordProvider} instance to destroy.
 * @return Returns the status code of the execution. For details, see {@link Udmf_ErrCode}.
 *         Returns {@link UDMF_E_OK} if the operation is successful.
 *         Returns {@link UDMF_E_INVALID_PARAM} if invalid args are detected.
 * @see OH_UdmfRecordProvider Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecordProvider_Destroy(OH_UdmfRecordProvider* provider);

/**
 * @brief Defines a callback function used to obtain data by type.
 *
 * @param context Pointer to the context set by {@link OH_UdmfRecordProvider_SetData}.
 * @param type Pointer to the type of data to obtain. For details, see {@link udmf_meta.h}.
 * @return Returns the data content.
 * @since 13
 */
typedef void* (*OH_UdmfRecordProvider_GetData)(void* context, const char* type);

/**
 * @brief Sets a callback function to obtain data.
 *
 * @param provider Pointer to the {@link OH_UdmfRecordProvider} instance.
 * @param context Pointer to the context set, which is the first parameter in OH_UdmfRecordProvider_GetData.
 * @param callback Callback to set. For details, see {@link OH_UdmfRecordProvider_GetData}.
 * @param finalize Optional callback that can free context when destroy provider.
 *         For details, see {@link UdmfData_Finalize}.
 * @return Returns the status code of the execution. For details, see {@link Udmf_ErrCode}.
 *         Returns {@link UDMF_E_OK} if the operation is successful.
 *         Returns {@link UDMF_E_INVALID_PARAM} if invalid args are detected.
 * @see OH_UdmfRecordProvider OH_UdmfRecordProvider_GetData UdmfData_Finalize Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context,
    const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize);

/**
 * @brief Creation a pointer to the instance of the {@link OH_UdmfRecord}, it's relate with UDS data.
 *
 * @return If the operation is successful, a pointer to the instance of the {@link OH_UdmfRecord}
 * structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_UdmfRecord.
 * @since 12
 */
OH_UdmfRecord* OH_UdmfRecord_Create();

/**
 * @brief Destroy a pointer that points to an instance of {@link OH_UdmfRecord}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @see OH_UdmfRecord.
 * @since 12
 */
void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis);

/**
 * @brief Add one custom data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param typeId Represents record type, reference udmf_meta.h.
 * @param entry Represents custom data.
 * @param count Represents the size of data param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_AddGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count);

/**
 * @brief Add one {OH_UdsPlainText} data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param plainText Represents a pointer to an instance of {@link OH_UdsPlainText}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsPlainText Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText);

/**
 * @brief Add one {OH_UdsHyperlink} data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param hyperlink Represents a pointer to an instance of {@link OH_UdsHyperlink}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsHyperlink Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink);

/**
 * @brief Add one {OH_UdsHtml} data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param html Represents a pointer to an instance of {@link OH_UdsHtml}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsHtml Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_AddHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html);

/**
 * @brief Add one {OH_UdsAppItem} data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param appItem Represents a pointer to an instance of {@link OH_UdsAppItem}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsAppItem Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_AddAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem);

/**
 * @brief Add one {OH_UdsFileUri} data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param fileUri Represents a pointer to an instance of {@link OH_UdsFileUri}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsFileUri Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecord_AddFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri);

/**
 * @brief Add one {OH_UdsPixelMap} data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param pixelMap Represents a pointer to an instance of {@link OH_UdsPixelMap}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsPixelMap Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecord_AddPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap);

/**
 * @brief Add one {@link OH_UdsArrayBuffer} data to the {@link OH_UdmfRecord} record.
 *
 * @param record Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param type Represents record type, reference udmf_meta.h.
 * @param buffer Represents a pointer to an instance of {@link OH_UdsArrayBuffer}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsArrayBuffer Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecord_AddArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer);

/**
 * @brief Add one {@link OH_UdsContentForm} data to the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param contentForm Represents a pointer to an instance of {@link OH_UdsContentForm}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsContentForm Udmf_ErrCode.
 * @since 14
 */
int OH_UdmfRecord_AddContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm);

/**
 * @brief Get all types in the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param count Represents the types count that is a output param.
 * @return Returns string array that in {@link OH_UdmfRecord} when input parameters valid,
 * otherwise return nullptr.
 * @see OH_UdmfRecord.
 * @since 12
 */
char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count);

/**
 * @brief Get one entry data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param typeId Represents record type, reference udmf_meta.h.
 * @param entry Represents a pointer to entry data that is a output param.
 * @param count Represents the entry data length that is a output param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfRecord Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_GetGeneralEntry(OH_UdmfRecord* pThis, const char* typeId,
    unsigned char** entry, unsigned int* count);

/**
 * @brief Get one {OH_UdsPlainText} data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param plainText Represents a pointer to an instance of {@link OH_UdsPlainText}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfRecord OH_UdsPlainText Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText);

/**
 * @brief Get one {OH_UdsHyperlink} data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param hyperlink Represents a pointer to an instance of {@link OH_UdsHyperlink}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfRecord OH_UdsHyperlink Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink);

/**
 * @brief Get one {OH_UdsHtml} data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param html Represents a pointer to an instance of {@link OH_UdsHtml}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfRecord OH_UdsHtml Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_GetHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html);

/**
 * @brief Get one {OH_UdsAppItem} data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param appItem Represents a pointer to an instance of {@link OH_UdsAppItem}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfRecord OH_UdsAppItem Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfRecord_GetAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem);

/**
 * @brief Get one {OH_UdsFileUri} data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param fileUri Represents a pointer to an instance of {@link OH_UdsFileUri}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsFileUri Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecord_GetFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri);

/**
 * @brief Get one {OH_UdsPixelMap} data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param pixelMap Represents a pointer to an instance of {@link OH_UdsPixelMap}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsPixelMap Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecord_GetPixelMap(OH_UdmfRecord* pThis, OH_UdsPixelMap* pixelMap);

/**
 * @brief Set the data provider of the types.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param types Represents a pointer to a group of data types;
 * @param count Represents the number of data types;
 * @param provider Represents a pointer an instance of {@link OH_UdmfRecordProvider}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdmfRecordProvider Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count,
    OH_UdmfRecordProvider* provider);

/**
 * @brief Get one {@link OH_UdsArrayBuffer} data from the {@link OH_UdmfRecord} record.
 *
 * @param record Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param type Represents record type, reference udmf_meta.h.
 * @param buffer Represents a pointer to an instance of {@link OH_UdsArrayBuffer}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsArrayBuffer Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfRecord_GetArrayBuffer(OH_UdmfRecord* record, const char* type, OH_UdsArrayBuffer* buffer);

/**
 * @brief Get one {@link OH_UdsContentForm} data from the {@link OH_UdmfRecord} record.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfRecord}.
 * @param contentForm Represents a pointer to an instance of {@link OH_UdsContentForm}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfRecord OH_UdsContentForm Udmf_ErrCode.
 * @since 14
 */
int OH_UdmfRecord_GetContentForm(OH_UdmfRecord* pThis, OH_UdsContentForm* contentForm);

/**
 * @brief Get primary {@link OH_UdsPlainText} data from the {@link OH_UdmfData}.
 *
 * @param data Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param plainText Represents a pointer to an instance of {@link OH_UdsPlainText}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfData OH_UdsPlainText Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfData_GetPrimaryPlainText(OH_UdmfData* data, OH_UdsPlainText* plainText);

/**
 * @brief Get one {@link OH_UdsHtml} data from the {@link OH_UdmfData}.
 *
 * @param data Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param html Represents a pointer to an instance of {@link OH_UdsHtml}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfData OH_UdsHtml Udmf_ErrCode.
 * @since 13
 */
int OH_UdmfData_GetPrimaryHtml(OH_UdmfData* data, OH_UdsHtml* html);

/**
 * @brief Get the count of {@link OH_UdmfRecord} in the {@link OH_UdmfData}.
 *
 * @param data Represents a pointer to an instance of {@link OH_UdmfData}.
 * @return Returns the count of {@link OH_UdmfRecord}
 * @see OH_UdmfData.
 * @since 13
 */
int OH_UdmfData_GetRecordCount(OH_UdmfData* data);

/**
 * @brief Get the record of the specified index from the {@link OH_UdmfData}.
 *
 * @param data Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param index Represents the index of {@link OH_UdmfRecord} in the {@link OH_UdmfData}.
 * @return Returns {@link OH_UdmfRecord} pointer when input parameters valid, otherwise return nullptr.
 * @see OH_UdmfData.
 * @since 13
 */
OH_UdmfRecord* OH_UdmfData_GetRecord(OH_UdmfData* data, unsigned int index);

/**
 * @brief Checks whether the UDMF data is from a local device.
 *
 * @param data Represents a pointer to an instance of {@link OH_UdmfData}.
 * @return Returns a boolean value, which indicates whether the UDMF data is from a local device.
 *         The value {@code true} means the data is from a local device.
 *         The value {@code false} means the opposite.
 * @see OH_UdmfData.
 * @since 13
 */
bool OH_UdmfData_IsLocal(OH_UdmfData* data);

/**
 * @brief Creation a pointer to the instance of the {@link OH_UdmfProperty}
 * from a {@link OH_UdmfData} data.
 *
 * @param unifiedData Represents a pointer to an instance of {@link OH_UdmfData}.
 * @return If the operation is successful, a pointer to the instance of the {@link OH_UdmfProperty}
 * structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_UdmfData OH_UdmfProperty.
 * @since 12
 */
OH_UdmfProperty* OH_UdmfProperty_Create(OH_UdmfData* unifiedData);

/**
 * @brief Destroy a pointer that points to the {@link OH_UdmfProperty} instance.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @see OH_UdmfProperty.
 * @since 12
 */
void OH_UdmfProperty_Destroy(OH_UdmfProperty* pThis);

/**
 * @brief Get tag value from the {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @return Returns a pointer of the tag value string when input parameters valid, otherwise return nullptr.
 * @see OH_UdmfProperty.
 * @since 12
 */
const char* OH_UdmfProperty_GetTag(OH_UdmfProperty* pThis);

/**
 * @brief Get timestamp value from the {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @return Returns timestamp value.
 * @see OH_UdmfProperty
 * @since 12
 */
int64_t OH_UdmfProperty_GetTimestamp(OH_UdmfProperty* pThis);

/**
 * @brief Get share option value from the {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @return Returns {@link Udmf_ShareOption} value.
 * @see OH_UdmfProperty Udmf_ShareOption
 * @since 12
 */
Udmf_ShareOption OH_UdmfProperty_GetShareOption(OH_UdmfProperty* pThis);

/**
 * @brief Get integer value by key from the {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @param key Represents key-value pair's key
 * @param defaultValue Represents when get value failure.
 * @return Returns value associated with the key in successfully, otherwise return defaultValue.
 * @see OH_UdmfProperty.
 * @since 12
 */
int OH_UdmfProperty_GetExtrasIntParam(OH_UdmfProperty* pThis,
    const char* key, int defaultValue);

/**
 * @brief Get tag value from the {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @param key Represents key-value pair's key.
 * @return Returns a pointer of the key value string when input parameters valid, otherwise return nullptr.
 * @see OH_UdmfProperty
 * @since 12
 */
const char* OH_UdmfProperty_GetExtrasStringParam(OH_UdmfProperty* pThis, const char* key);

/**
 * @brief Set tag value to {@link OH_UdmfProperty} .
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @param tag Represents new tag param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfProperty Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfProperty_SetTag(OH_UdmfProperty* pThis, const char* tag);

/**
 * @brief Set Udmf_ShareOption value to {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @param option Represents new {@link Udmf_ShareOption} param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfProperty Udmf_ShareOption Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfProperty_SetShareOption(OH_UdmfProperty* pThis, Udmf_ShareOption option);

/**
 * @brief Set extras param to {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @param key Represents extras param's key value.
 * @param param Represents value of k-v pairs.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfProperty Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfProperty_SetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int param);

/**
 * @brief Set extras param to {@link OH_UdmfProperty}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfProperty}.
 * @param key Represents extras param's key value.
 * @param param Represents value of k-v pairs.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfProperty Udmf_ErrCode.
 * @since 12
 */
int OH_UdmfProperty_SetExtrasStringParam(OH_UdmfProperty* pThis,
    const char* key, const char* param);

/**
 * @brief Creation a pointer to the instance of the {@link OH_UdmfOptions}.
 *
 * @return If the operation is successful, a pointer to the instance of the {@link OH_UdmfOptions}
 * structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_UdmfOptions.
 * @since 20
 */
OH_UdmfOptions* OH_UdmfOptions_Create();

/**
 * @brief Destroy the heap memory pointed to by the pointer of {@link OH_UdmfOptions}.
 * Note that this function cannot be called repeatedly for the same pointer.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @see OH_UdmfOptions.
 * @since 20
 */
void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis);

/**
 * @brief Get key from the {@link OH_UdmfOptions}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @return Returns a pointer of the value string when input args normally, otherwise return nullptr.
 * @see OH_UdmfOptions
 * @since 20
 */
const char* OH_UdmfOptions_GetKey(OH_UdmfOptions* pThis);

/**
 * @brief Set the key to the {@link OH_UdmfOptions}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @param key Represents a new string value of the key.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfOptions Udmf_ErrCode
 * @since 20
 */
int OH_UdmfOptions_SetKey(OH_UdmfOptions* pThis, const char* key);

/**
 * @brief Get intention from the {@link OH_UdmfOptions}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @return Returns {@link Udmf_Intention} value.
 * @see OH_UdmfOptions Udmf_Intention
 * @since 20
 */
Udmf_Intention OH_UdmfOptions_GetIntention(OH_UdmfOptions* pThis);

/**
 * @brief Set intention value to {@link OH_UdmfOptions}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @param intention Represents new {@link Udmf_Intention} param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfOptions Udmf_Intention Udmf_ErrCode.
 * @since 20
 */
int OH_UdmfOptions_SetIntention(OH_UdmfOptions* pThis, Udmf_Intention intention);

/**
 * @brief Reset {@link OH_UdmfOptions} to default.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfOptions Udmf_ErrCode.
 * @since 20
 */
int OH_UdmfOptions_Reset(OH_UdmfOptions* pThis);

/**
 * @brief Get visibility from the {@link OH_UdmfOptions}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @return Returns {@link Udmf_Visibility} value.
 * @see OH_UdmfOptions Udmf_Visibility
 * @since 20
 */
Udmf_Visibility OH_UdmfOptions_GetVisibility(OH_UdmfOptions* pThis);

/**
 * @brief Set visibility value to {@link OH_UdmfOptions}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @param visibility Represents new {@link Udmf_Visibility} param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 * @see OH_UdmfOptions Udmf_Visibility Udmf_ErrCode.
 * @since 20
 */
int OH_UdmfOptions_SetVisibility(OH_UdmfOptions* pThis, Udmf_Visibility visibility);

/**
 * @brief Get {@link OH_UdmfData} data from udmf database.
 *
 * @param key Represents database store's key value.
 * @param intention Represents data type {@link Udmf_Intention}
 * @param unifiedData Represents output params of {@link OH_UdmfData};
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfProperty Udmf_Intention Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData);

/**
 * @brief Get {@link OH_UdmfData} data array from udmf database by intention.
 *
 * @param options Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @param dataArray Represents output params of {@link OH_UdmfData}.
 * This pointer needs to be released using the {@link OH_Udmf_DestroyDataArray} function.
 * @param dataSize Represents the data count of output params.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfData Udmf_Intention Udmf_ErrCode.
 * @since 20
 */
int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize);

/**
 * @brief Set {@link OH_UdmfData} data to database.
 *
 * @param intention Represents data type {@link Udmf_Intention}.
 * @param unifiedData Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param key Represents return value after set data to database successfully,
 * it's memory size not less than {@link UDMF_KEY_BUFFER_LEN}.
 * @param keyLen Represents size of key param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfProperty Udmf_Intention Udmf_ErrCode.
 * @since 12
 */
int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData,
    char* key, unsigned int keyLen);

/**
 * @brief Set {@link OH_UdmfData} data to database with options.
 *
 * @param options Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @param unifiedData Represents a pointer to an instance of {@link OH_UdmfData}.
 * @param key Represents return value after set data to database successfully,
 * it's memory size not less than {@link UDMF_KEY_BUFFER_LEN}.
 * @param keyLen Represents size of key param.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfOptions OH_UdmfData Udmf_ErrCode.
 * @since 20
 */
int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen);

/**
 * @brief Update {@link OH_UdmfData} data to database with options.
 *
 * @param options Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @param unifiedData Represents a pointer to an instance of {@link OH_UdmfData}.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfOptions OH_UdmfData Udmf_ErrCode.
 * @since 20
 */
int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData);

/**
 * @brief Delete {@link OH_UdmfData} data of database with options.
 *
 * @param options Represents a pointer to an instance of {@link OH_UdmfOptions}.
 * @param dataArray Represents output params of {@link OH_UdmfData}.
 * This pointer needs to be released using the {@link OH_Udmf_DestroyDataArray} function.
 * @param dataSize Represents the data count of output params.
 * @return Returns the status code of the execution. See {@link Udmf_ErrCode}.
 *         {@link UDMF_E_OK} success.
 *         {@link UDMF_E_INVALID_PARAM} The error code for common invalid args.
 *         {@link UDMF_ERR} Internal data error.
 * @see OH_UdmfData Udmf_Intention Udmf_ErrCode.
 * @since 20
 */
int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize);

/**
 * @brief Destroy data array memory.
 *
 * @param dataArray Represents a point to {@link OH_UdmfData}.
 * @param dataSize Represents data size in list.
 * @see OH_UdmfData
 * @since 20
 */
void OH_Udmf_DestroyDataArray(OH_UdmfData** dataArray, unsigned int dataSize);

/**
 * @brief Gets the progress from the {@OH_Udmf_ProgressInfo}.
 *
 * @param progressInfo Represents a pointer to an instance of {@link OH_Udmf_ProgressInfo}.
 * @return Returns the progress.
 * @see OH_Udmf_ProgressInfo
 * @since 15
 */
int OH_UdmfProgressInfo_GetProgress(OH_Udmf_ProgressInfo* progressInfo);

/**
 * @brief Gets the status from the {@OH_Udmf_ProgressInfo}.
 *
 * @param progressInfo Represents a pointer to an instance of {@link OH_Udmf_ProgressInfo}.
 * @return Returns the status code. See {@link Udmf_ListenerStatus}.
 * @see OH_Udmf_ProgressInfo Udmf_ListenerStatus
 * @since 15
 */
int OH_UdmfProgressInfo_GetStatus(OH_Udmf_ProgressInfo* progressInfo);

/**
 * @brief Creation a pointer to the instance of the {@link OH_UdmfGetDataParams}.
 *
 * @return If the operation is successful, a pointer to the instance of the {@link OH_UdmfGetDataParams}
 * structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_UdmfGetDataParams
 * @since 15
 */
OH_UdmfGetDataParams* OH_UdmfGetDataParams_Create();

/**
 * @brief Destroy a pointer that points to an instance of {@link OH_UdmfGetDataParams}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfGetDataParams}.
 * @see OH_UdmfGetDataParams
 * @since 15
 */
void OH_UdmfGetDataParams_Destroy(OH_UdmfGetDataParams* pThis);

/**
 * @brief Sets the destination uri to the {@OH_UdmfGetDataParams}.
 *
 * @param params Represents a pointer to an instance of {@link OH_UdmfGetDataParams}.
 * @param destUri Pointer to a destination uri.
 * @see OH_UdmfGetDataParams
 * @since 15
 */
void OH_UdmfGetDataParams_SetDestUri(OH_UdmfGetDataParams* params, const char* destUri);

/**
 * @brief Sets the file conflict options to the {@OH_UdmfGetDataParams}.
 *
 * @param params Represents a pointer to an instance of {@link OH_UdmfGetDataParams}.
 * @param options Represents to the file conflict options.
 * @see OH_UdmfGetDataParams Udmf_FileConflictOptions
 * @since 15
 */
void OH_UdmfGetDataParams_SetFileConflictOptions(OH_UdmfGetDataParams* params, const Udmf_FileConflictOptions options);

/**
 * @brief Sets the progress indicator to the {@OH_UdmfGetDataParams}.
 *
 * @param params Represents a pointer to an instance of {@link OH_UdmfGetDataParams}.
 * @param progressIndicator Represents to the progress indicator.
 * @see OH_UdmfGetDataParams Udmf_ProgressIndicator
 * @since 15
 */
void OH_UdmfGetDataParams_SetProgressIndicator(OH_UdmfGetDataParams* params,
    const Udmf_ProgressIndicator progressIndicator);

/**
 * @brief Sets the progress indicator to the {@OH_UdmfGetDataParams}.
 *
 * @param params Represents a pointer to an instance of {@link OH_UdmfGetDataParams}.
 * @param dataProgressListener Represents to the data progress listener.
 * @see OH_UdmfGetDataParams OH_Udmf_DataProgressListener
 * @since 15
 */
void OH_UdmfGetDataParams_SetDataProgressListener(OH_UdmfGetDataParams* params,
    const OH_Udmf_DataProgressListener dataProgressListener);

/**
 * @brief Sets the acceptable info to the {@OH_UdmfGetDataParams}.
 *
 * @param params Represents a pointer to an instance of {@link OH_UdmfGetDataParams}.
 * @param acceptableInfo Represents a pointer to an instance of {@link OH_UdmfDataLoadInfo}.
 * @see OH_UdmfGetDataParams OH_UdmfDataLoadInfo
 * @since 20
 */
void OH_UdmfGetDataParams_SetAcceptableInfo(OH_UdmfGetDataParams* params, OH_UdmfDataLoadInfo* acceptableInfo);

/**
 * @brief Creation a pointer to the instance of the {@link OH_UdmfDataLoadParams}.
 *
 * @return If the operation is successful, a pointer to the instance of the {@link OH_UdmfDataLoadParams}
 * structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_UdmfDataLoadParams
 * @since 20
 */
OH_UdmfDataLoadParams* OH_UdmfDataLoadParams_Create();

/**
 * @brief Destroy a pointer that points to an instance of {@link OH_UdmfDataLoadParams}.
 *
 * @param pThis Represents a pointer to an instance of {@link OH_UdmfDataLoadParams}.
 * @see OH_UdmfDataLoadParams
 * @since 20
 */
void OH_UdmfDataLoadParams_Destroy(OH_UdmfDataLoadParams* pThis);

/**
 * @brief Sets the data load handler to the {@OH_UdmfDataLoadParams}.
 *
 * @param params Represents a pointer to an instance of {@link OH_UdmfDataLoadParams}.
 * @param dataLoadHandler Represents to the data load handler.
 * @see OH_UdmfDataLoadParams OH_Udmf_DataLoadHandler
 * @since 20
 */
void OH_UdmfDataLoadParams_SetLoadHandler(OH_UdmfDataLoadParams* params, const OH_Udmf_DataLoadHandler dataLoadHandler);

/**
 * @brief Sets the data load info to the {@OH_UdmfDataLoadParams}.
 *
 * @param params Represents a pointer to an instance of {@link OH_UdmfDataLoadParams}.
 * @param dataLoadInfo Represents a pointer to an instance of {@link OH_UdmfDataLoadInfo}.
 * @see OH_UdmfDataLoadParams OH_UdmfDataLoadInfo
 * @since 20
 */
void OH_UdmfDataLoadParams_SetDataLoadInfo(OH_UdmfDataLoadParams* params, OH_UdmfDataLoadInfo* dataLoadInfo);

/**
 * @brief Creation a pointer to the instance of the {@link OH_UdmfDataLoadInfo}.
 *
 * @return If the operation is successful, a pointer to the instance of the {@link OH_UdmfDataLoadInfo}
 * structure is returned. If the operation is failed, nullptr is returned.
 * @see OH_UdmfDataLoadInfo
 * @since 20
 */
OH_UdmfDataLoadInfo* OH_UdmfDataLoadInfo_Create();

/**
 * @brief Destroy the heap memory pointed to by the pointer of {@link OH_UdmfDataLoadInfo}.
 * Note that this function cannot be called repeatedly for the same pointer.
 *
 * @param dataLoadInfo Represents a pointer to an instance of {@link OH_UdmfDataLoadInfo}.
 * @see OH_UdmfDataLoadInfo
 * @since 20
 */
void OH_UdmfDataLoadInfo_Destroy(OH_UdmfDataLoadInfo* dataLoadInfo);

/**
 * @brief Gets the types from the {@OH_UdmfDataLoadInfo}.
 *
 * @param dataLoadInfo Represents a pointer to an instance of {@link OH_UdmfDataLoadInfo}.
 * @param count the types count of data.
 * @return Returns the types of data.
 * @see OH_UdmfDataLoadInfo
 * @since 20
 */
char** OH_UdmfDataLoadInfo_GetTypes(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int* count);

/**
 * @brief Sets the data load info to the {@OH_UdmfDataLoadInfo}.
 *
 * @param dataLoadInfo Represents a pointer to an instance of {@link OH_UdmfDataLoadInfo}.
 * @param type Represents the type of data.
 * @see OH_UdmfDataLoadInfo
 * @since 20
 */
void OH_UdmfDataLoadInfo_SetType(OH_UdmfDataLoadInfo* dataLoadInfo, const char* type);

/**
 * @brief Gets the record count from the {@OH_UdmfDataLoadInfo}.
 *
 * @param dataLoadInfo Represents a pointer to an instance of {@link OH_UdmfDataLoadInfo}.
 * @return Returns the record count.
 * @see OH_UdmfDataLoadInfo
 * @since 20
 */
int OH_UdmfDataLoadInfo_GetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo);

/**
 * @brief Sets the record count to the {@OH_UdmfDataLoadInfo}.
 *
 * @param dataLoadInfo Represents a pointer to an instance of {@link OH_UdmfDataLoadInfo}.
 * @param recordCount Represents the types of data.
 * @see OH_UdmfDataLoadInfo
 * @since 20
 */
void OH_UdmfDataLoadInfo_SetRecordCount(OH_UdmfDataLoadInfo* dataLoadInfo, unsigned int recordCount);

#ifdef __cplusplus
};
#endif

/** @} */
#endif