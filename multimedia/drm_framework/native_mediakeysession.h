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
 * @addtogroup Drm
 * @{
 *
 * @brief Provides APIs of Drm.
 * @kit DrmKit.
 * @since 11
 * @version 1.0
 */

/**
 * @file native_mediakeysession.h
 * @brief Defines the Drm MediaKeySession APIs. Provide following function:
 * generate media key request, process media key response, event listening,
 * get content protection level, check media key status, remove media key etc..
 * @library libnative_drm.z.so
 * @syscap SystemCapability.Multimedia.Drm.Core
 * @since 11
 * @version 1.0
 */

#ifndef OHOS_DRM_NATIVE_MEDIA_KEY_SESSION_H
#define OHOS_DRM_NATIVE_MEDIA_KEY_SESSION_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "native_drm_err.h"
#include "native_drm_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Call back will be invoked when event triggers.
 * @param eventType Event type.
 * @param info Event info gotten from media key session.
 * @param infoLen Event info len.
 * @param extra Extra info gotten from media key session.
 * @return Drm_ErrCode.
 * @since 11
 * @version 1.0
 */
typedef  Drm_ErrCode (*MediaKeySession_EventCallback)(DRM_EventType eventType, uint8_t *info,
    int32_t infoLen, char *extra);

/**
 * @brief Call back will be invoked when key changes.
 * @param keysInfo Key info gotten from media key system.
 * @param newKeysAvailable Whether new keys available.
 * @return DRM_ERR_INVALID_VAL when the params checked failure, return DRM_ERR_OK when function called successfully.
 * @since 11
 * @version 1.0
 */
typedef  Drm_ErrCode (*MediaKeySession_KeyChangeCallback)(DRM_KeysInfo *keysInfo, bool newKeysAvailable);

/**
 * @brief MediaKeySession_Callback struct, used to listen event like key expired and key change etc..
 * @since 11
 * @version 1.0
 */
typedef struct MediaKeySession_Callback {
    /**
     * Normal event callback like key expired etc..
     */
    MediaKeySession_EventCallback eventCallback;
    /**
     * Key change callback for keys change event.
     */
    MediaKeySession_KeyChangeCallback keyChangeCallback;
} MediaKeySession_Callback;

/**
 * @brief Call back will be invoked when event triggers.
 * @param mediaKeySession MediaKeySession instance.
 * @param eventType Event type.
 * @param info Event info gotten from media key session.
 * @param infoLen Event info len.
 * @param extra Extra info gotten from media key session.
 * @return Drm_ErrCode.
 * @since 12
 * @version 1.0
 */
typedef Drm_ErrCode (*OH_MediaKeySession_EventCallback)(MediaKeySession *mediaKeySession, DRM_EventType eventType,
    uint8_t *info, int32_t infoLen, char *extra);

/**
 * @brief Call back will be invoked when key changes.
 * @param mediaKeySession MediaKeySession instance.
 * @param keysInfo Key info gotten from media key system.
 * @param newKeysAvailable Whether new keys available.
 * @return DRM_ERR_INVALID_VAL when the params checked failure, return DRM_ERR_OK when function called successfully.
 * @since 12
 * @version 1.0
 */
typedef Drm_ErrCode (*OH_MediaKeySession_KeyChangeCallback)(MediaKeySession *mediaKeySession, DRM_KeysInfo *keysInfo,
    bool newKeysAvailable);

/**
 * @brief MediaKeySession_Callback struct, used to listen event like key expired and key change etc..
 * @since 12
 * @version 1.0
 */
typedef struct OH_MediaKeySession_Callback {
    /**
     * Normal event callback like key expired etc..
     */
    OH_MediaKeySession_EventCallback eventCallback;
    /**
     * Key change callback for keys change event.
     */
    OH_MediaKeySession_KeyChangeCallback keyChangeCallback;
} OH_MediaKeySession_Callback;

/**
 * @brief Generate media key request.
 * @param mediaKeySession Media key session instance.
 * @param info Media key request info.
 * @param mediaKeyRequest Media key request.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_NO_MEMORY} 24700501 - Memory errors.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_GenerateMediaKeyRequest(MediaKeySession *mediaKeySession,
    DRM_MediaKeyRequestInfo *info, DRM_MediaKeyRequest *mediaKeyRequest);

/**
 * @brief Process media key response.
 * @param mediaKeySession Media key session instance.
 * @param response Media Key resposne.
 * @param responseLen Media Key resposne len.
 * @param offlineMediaKeyId Offline media key identifier.
 * @param offlineMediaKeyIdLen Offline media key identifier len for in buffer and out data.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_NO_MEMORY} 24700501 - Memory errors.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse(MediaKeySession *mediaKeySession,
    uint8_t *response, int32_t responseLen, uint8_t *offlineMediaKeyId, int32_t *offlineMediaKeyIdLen);

/**
 * @brief Check media key status.
 * @param mediaKeySession Media key session instance.
 * @param mediaKeyStatus Media key status.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_NO_MEMORY} 24700501 - Memory errors.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus(MediaKeySession *mediaKeySession,
    DRM_MediaKeyStatus *mediaKeyStatus);

/**
 * @brief Clear media keys of the current session .
 * @param mediaKeySession Media key session instance.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_ClearMediaKeys(MediaKeySession *mediaKeySession);

/**
 * @brief Generate offline media key release request.
 * @param mediaKeySession Media key session instance.
 * @param offlineMediaKeyId Offline media key identifier.
 * @param offlineMediaKeyIdLen Offline media key identifier len.
 * @param releaseRequest Media Key release request.
 * @param releaseRequestLen Media Key release request len for in buffer and out data.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_NO_MEMORY} 24700501 - Memory errors.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest(MediaKeySession *mediaKeySession,
    uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseRequest,
    int32_t *releaseRequestLen);

/**
 * @brief Process offline media key release response.
 * @param mediaKeySession Media key session instance.
 * @param offlineMediaKeyId Offline media key identifier.
 * @param offlineMediaKeyIdLen Offline media key identifier len.
 * @param releaseReponse Media Key resposne.
 * @param releaseReponseLen Media Key resposne len.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse(MediaKeySession *mediaKeySession,
    uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseReponse,
    int32_t releaseReponseLen);

/**
 * @brief Restore offline media keys by ID.
 * @param mediaKeySession Media key session instance.
 * @param offlineMediaKeyId Offline media key identifier.
 * @param offlineMediaKeyIdLen Offline media key identifier len.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_RestoreOfflineMediaKeys(MediaKeySession *mediaKeySession,
    uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen);

/**
 * @brief Get content protection level of the session.
 * @param mediaKeySession Media key session instance.
 * @param contentProtectionLevel Content protection level.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_GetContentProtectionLevel(MediaKeySession *mediaKeySession,
    DRM_ContentProtectionLevel *contentProtectionLevel);

/**
 * @brief Whether the encrypted content require a secure decoder or not.
 * @param mediaKeySession Media key session instance.
 * @param mimeType The media type.
 * @param status Whether secure decoder is required.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_RequireSecureDecoderModule(MediaKeySession *mediaKeySession,
    const char *mimeType, bool *status);

/**
 * @brief Set media key session event callback.
 * @param mediaKeySession Media key session instance.
 * @param callback Callback to be set to the media key session.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback(MediaKeySession *mediaKeySession,
    MediaKeySession_Callback *callback);

/**
 * @brief Set media key session event callback.
 * @param mediaKeySession Media key session instance.
 * @param callback Callback to be set to the media key session.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 * @since 12
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_SetCallback(MediaKeySession *mediaKeySession,
    OH_MediaKeySession_Callback *callback);

/**
 * @brief Release the resource before the session gonna be unused.
 * @param mediaKeySession Media key session instance.
 * @return {@link DRM_ERR_OK} 0 - Success.
 *         {@link DRM_ERR_INVALID_VAL} 24700503 - The parameter passed in is a null pointer or invalid.
 *         {@link DRM_ERR_UNKNOWN} 24700506 - Internal error occurred, it is recommended to check the logs.
 * @since 11
 * @version 1.0
 */
Drm_ErrCode OH_MediaKeySession_Destroy(MediaKeySession *mediaKeySession);

#ifdef __cplusplus
}
#endif

#endif // OHOS_DRM_NATIVE_MEDIA_KEY_SYSTEM_H
/** @} */