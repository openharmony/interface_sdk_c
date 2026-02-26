/*
 * Copyright (c) 2026 Huawei Device Co., Ltd.
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
 * @addtogroup OHAudio
 * @{
 *
 * @brief Provide the definition of the C interface for the audio module.
 *
 * @syscap SystemCapability.Multimedia.Audio.Core
 *
 * @since 26.0.0
 * @version 1.0
 */

/**
 * @file native_audio_routing_enhance_manager.h
 *
 * @brief Declare audio routing manager related interfaces.
 *
 * This file interface is used for the creation of audioRoutingEnhanceManager
 * as well as the registration and deregistration functions when the device connection status changes
 * as well as the release of pointer arrays storing device information.
 *
 * @library libohaudio.so
 * @syscap SystemCapability.Multimedia.Audio.Core
 * @kit AudioKit
 * @since 12
 * @version 1.0
 */

#ifndef NATIVE_AUDIO_ROUTING_ENHANCE_MANAGER_H
#define NATIVE_AUDIO_ROUTING_ENHANCE_MANAGER_H

#include "native_audio_device_base.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Declaring the audio routing enhance manager.
 * The handle of audio routing enhance manager used for extension routing and
 * device related functions.
 *
 * @since 26.0.0
 */
typedef struct OH_AudioRoutingEnhanceManager OH_AudioRoutingEnhanceManager;

/**
 * @brief Query the audio routing enhance manager handle.
 * which should be set as the first parameter in extension routing releated functions.
 *
 * @param audioRoutingManager the {@link OH_AudioRoutingEnhanceManager}
 * handle returned by {@link OH_AudioManager_GetAudioRoutingEnhanceManager}.
 * @return Function result code:
 *         {@link AUDIOCOMMON_RESULT_SUCCESS} If the execution is successful.
 * @since 12
 */
OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingEnhanceManager(
    OH_AudioRoutingEnhanceManager **audioRoutingEnhanceManager);

/**
 * @brief Selects the output device for the application. This setting applies to
 * all playback streams created under the application, unless a specific output device
 * is designated for a particular stream. The application can use
 * {@link OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback} to register a callback
 * to listen for the actual output device. The selection will become invalid when
 * the application exits or the selected device goes offline. After the application restarts or
 * the device comes back online, the application must re-issue the selection for it to take effect.
 *
 * @param audioRoutingEnhanceManager the {@link OH_AudioRoutingEnhanceManager} handle returned
 *     by {@link OH_AudioManager_GetAudioRoutingEnhanceManager}.
 * @param deviceDescriptor The target device. The available device must be in the array returned
 *     by {@link OH_AudioRoutingManager_GetAvailableDevices}.
 *     When the nullptr is passed, system will clear the last selection.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 26.0.0
 */
OH_AudioCommon_Result OH_AudioSessionManager_SelectOutputDevice(
    OH_AudioRoutingEnhanceManager *audioRoutingEnhanceManager, OH_AudioDeviceDescriptor *deviceDescriptor);

/**
 * @brief Selects the input device for the application. This setting applies to
 * all recording streams created under the application, unless a specific input device
 * is designated for a particular stream. The application can use
 * {@link OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback} to register a callback
 * to listen for the actual input device. The selection will become invalid when
 * the application exits or the selected device goes offline. After the application restarts or
 * the device comes back online, the application must re-issue the selection for it to take effect.
 *
 * @param audioRoutingEnhanceManager the {@link OH_AudioRoutingEnhanceManager} handle returned
 *     by {@link OH_AudioManager_GetAudioRoutingEnhanceManager}.
 * @param deviceDescriptor The target device. The available device must be in the array returned
 *     by {@link OH_AudioRoutingManager_GetAvailableDevices}.
 *     When the nullptr is passed, system will clear the last selection.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 26.0.0
 */
OH_AudioCommon_Result OH_AudioSessionManager_SelectInputDevice(
    OH_AudioRoutingEnhanceManager *audioRoutingEnhanceManager, OH_AudioDeviceDescriptor *deviceDescriptor);

/**
 * @brief Selects the output device for the target renderer. The application must ensure that the specified
 * renderer is valid. This selection only applies to the designated stream; other playback streams in
 * the application will use the application's forced selection or the system's default output device.
 * The selection will become invalid when the application exits or the selected device goes offline.
 * After the application restarts or the device comes back online, the application must re-issue the
 * selection for it to take effect.
 *
 * @param audioRoutingEnhanceManager the {@link OH_AudioRoutingEnhanceManager} handle returned
 *     by {@link OH_AudioManager_GetAudioRoutingEnhanceManager}.
 * @param renderer renderer Reference created by OH_AudioStreamBuilder_GenerateRenderer().
 * @param deviceDescriptor The target device. The available device must be in the array returned
 *     by {@link OH_AudioRoutingManager_GetAvailableDevices}.
 *     When the nullptr is passed, system will clear the last selection.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 26.0.0
 */
OH_AudioCommon_Result OH_AudioSessionManager_SelectOutputDeviceForAudioRenderer(
    OH_AudioRoutingEnhanceManager *audioRoutingEnhanceManager, OH_AudioRenderer *renderer,
    OH_AudioDeviceDescriptor *deviceDescriptor);

/**
 * @brief Selects the input device for the target capturer. The application must ensure that the specified
 * capturer is valid. This selection only applies to the designated stream; other recording streams in
 * the application will use the application's forced selection or the system's default input device.
 * The selection will become invalid when the application exits or the selected device goes offline.
 * After the application restarts or the device comes back online, the application must re-issue the
 * selection for it to take effect.
 *
 * @param audioRoutingEnhanceManager the {@link OH_AudioRoutingEnhanceManager} handle returned
 *     by {@link OH_AudioManager_GetAudioRoutingEnhanceManager}.
 * @param capturer reference created by OH_AudioStreamBuilder_GenerateCapturer().
 * @param deviceDescriptor The target device. The available device must be in the array returned
 *     by {@link OH_AudioRoutingManager_GetAvailableDevices}.
 *     When the nullptr is passed, system will clear the last selection.
 * @return {@link #AUDIOCOMMON_RESULT_SUCCESS} if execution succeeds.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM} if parameter validation fails.
 *     or {@link #AUDIOCOMMON_RESULT_ERROR_SYSTEM} Audio client call audio service error, System error.
 * @since 26.0.0
 */
OH_AudioCommon_Result OH_AudioSessionManager_SelectOutputDeviceForAudioCapturer(
    OH_AudioRoutingEnhanceManager *audioRoutingEnhanceManager, OH_AudioCapturer *capturer,
    OH_AudioDeviceDescriptor *deviceDescriptor);


#ifdef __cplusplus
}
#endif

#endif // NATIVE_AUDIO_ROUTING_ENHANCE_MANAGER_H
/** @} */
