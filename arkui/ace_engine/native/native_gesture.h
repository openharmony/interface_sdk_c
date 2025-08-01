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
 * @addtogroup ArkUI_NativeModule
 * @{
 *
 * @brief Defines APIs for ArkUI to register gesture callbacks on the native side.
 *
 * @since 12
 */

/**
 * @file native_gesture.h
 *
 * @brief Provides type definitions for <b>NativeGesture</b> APIs.
 *
 * @library libace_ndk.z.so
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @kit ArkUI
 * @since 12
 */

#ifndef ARKUI_NATIVE_GESTTURE_H
#define ARKUI_NATIVE_GESTTURE_H

#include "ui_input_event.h"
#include "native_type.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines a gesture recognizer.
 *
 * @since 12
 */
typedef struct ArkUI_GestureRecognizer ArkUI_GestureRecognizer;

/**
 * @brief Defines the gesture interruption information.
 *
 * @since 12
 */
typedef struct ArkUI_GestureInterruptInfo ArkUI_GestureInterruptInfo;

/**
 * @brief Defines the gesture event.
 *
 * @since 12
 */
typedef struct ArkUI_GestureEvent ArkUI_GestureEvent;

/**
 * @brief Enumerates gesture event types.
 *
 * @since 12
 */
typedef enum {
    /** Triggered. */
    GESTURE_EVENT_ACTION_ACCEPT = 0x01,

    /** Updated. */
    GESTURE_EVENT_ACTION_UPDATE = 0x02,

    /** Ended. */
    GESTURE_EVENT_ACTION_END = 0x04,

    /** Canceled. */
    GESTURE_EVENT_ACTION_CANCEL = 0x08,
} ArkUI_GestureEventActionType;

/**
 * @brief Defines a set of gesture event types.
 *
 * Example: ArkUI_GestureEventActionTypeMask actions = GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE;\n
 *
 * @since 12
 */
typedef uint32_t ArkUI_GestureEventActionTypeMask;

/**
 * @brief Enumerates gesture event modes.
 *
 * @since 12
 */
typedef enum {
    /** Normal. */
    NORMAL = 0,

    /** High-priority. */
    PRIORITY = 1,

    /** Parallel. */
    PARALLEL = 2,
} ArkUI_GesturePriority;

/**
 * @brief Enumerates gesture group modes.
 *
 * @since 12
 */
typedef enum {
    /* Sequential recognition. Gestures are recognized in the registration sequence until all gestures are recognized
     * successfully. Once one gesture fails to be recognized, all subsequent gestures fail to be recognized.
     * Only the last gesture in the gesture group can respond to the end event. */
    SEQUENTIAL_GROUP = 0,

    /** Parallel recognition. Registered gestures are recognized concurrently until all gestures are recognized.
      * The recognition result of each gesture does not affect each other. */
    PARALLEL_GROUP = 1,

    /** Exclusive recognition. Registered gestures are identified concurrently.
      * If one gesture is successfully recognized, gesture recognition ends. */
    EXCLUSIVE_GROUP = 2,
} ArkUI_GroupGestureMode;

/**
 * @brief Enumerates gesture directions.
 *
 * @since 12
 */
typedef enum {
    /** All directions. */
    GESTURE_DIRECTION_ALL = 0b1111,

    /** Horizontal direction. */
    GESTURE_DIRECTION_HORIZONTAL = 0b0011,

    /** Vertical direction. */
    GESTURE_DIRECTION_VERTICAL = 0b1100,

    /** Leftward. */
    GESTURE_DIRECTION_LEFT = 0b0001,

    /** Rightward. */
    GESTURE_DIRECTION_RIGHT = 0b0010,

    /** Upward. */
    GESTURE_DIRECTION_UP = 0b0100,

    /** Downward. */
    GESTURE_DIRECTION_DOWN = 0b1000,

    /** None. */
    GESTURE_DIRECTION_NONE = 0,
} ArkUI_GestureDirection;

/**
 * @brief Defines a set of gesture directions.
 *
 * Example: ArkUI_GestureDirectionMask directions = GESTURE_DIRECTION_LEFT | GESTURE_DIRECTION_RIGHT \n
 * This example indicates that the leftward and rightward directions are supported. \n
 *
 * @since 12
 */
typedef uint32_t ArkUI_GestureDirectionMask;

/**
 * @brief Enumerates gesture masking modes.
 *
 * @since 12
 */
typedef enum {
    /** The gestures of child components are enabled and recognized based on the default gesture recognition sequence.*/
    NORMAL_GESTURE_MASK = 0,

    /** The gestures of child components are disabled, including the built-in gestures. */
    IGNORE_INTERNAL_GESTURE_MASK,
} ArkUI_GestureMask;

/**
 * @brief Enumerates gesture types.
 *
 * @since 12
 */
typedef enum {
    /** Tap. */
    TAP_GESTURE = 0,

    /** Long press. */
    LONG_PRESS_GESTURE,

    /** Pan. */
    PAN_GESTURE,

    /** Pinch. */
    PINCH_GESTURE,

    /** Rotate. */
    ROTATION_GESTURE,

    /** Swipe. */
    SWIPE_GESTURE,

    /** A group of gestures. */
    GROUP_GESTURE,

    /**
     * The click gesture registed through onClick.
     *
     * @since 20
     */
    CLICK_GESTURE,

    /**
     * Drag gesture used for drag and drop.
     *
     * @since 20
     */
    DRAG_DROP,
} ArkUI_GestureRecognizerType;

/**
 * @brief Enumerates gesture interruption results.
 *
 * @since 12
 */
typedef enum {
    /** The gesture recognition process continues. */
    GESTURE_INTERRUPT_RESULT_CONTINUE = 0,

    /** The gesture recognition process is paused. */
    GESTURE_INTERRUPT_RESULT_REJECT,
} ArkUI_GestureInterruptResult;

/**
 * @brief Enumerates the gesture recognizer states.
 *
 * @since 12
 */
typedef enum {
    /** Ready. */
    ARKUI_GESTURE_RECOGNIZER_STATE_READY = 0,

    /** Detecting. */
    ARKUI_GESTURE_RECOGNIZER_STATE_DETECTING = 1,

    /** Pending. */
    ARKUI_GESTURE_RECOGNIZER_STATE_PENDING = 2,

    /** Blocked. */
    ARKUI_GESTURE_RECOGNIZER_STATE_BLOCKED = 3,

    /** Successful. */
    ARKUI_GESTURE_RECOGNIZER_STATE_SUCCESSFUL = 4,

    /** Failed. */
    ARKUI_GESTURE_RECOGNIZER_STATE_FAILED = 5,
} ArkUI_GestureRecognizerState;

/**
 * @brief Defines the gesture recognizer handle.
 *
 * @since 12
 */
typedef ArkUI_GestureRecognizer* ArkUI_GestureRecognizerHandle;

/**
 * @brief Defines the gesture recognizer handle array.
 *
 * @since 12
 */
typedef ArkUI_GestureRecognizerHandle* ArkUI_GestureRecognizerHandleArray;

/**
 * @brief Defines a <b>GestureEventTargetInfo</b> object that provides information about a gesture event target.
 *
 * @since 12
 */
typedef struct ArkUI_GestureEventTargetInfo ArkUI_GestureEventTargetInfo;

/**
 * @brief Defines a parallel internal gesture event.
 *
 * @since 12
 */
typedef struct ArkUI_ParallelInnerGestureEvent ArkUI_ParallelInnerGestureEvent;

/**
 * @brief Defines a touch recognizer.
 *
 * @since 15
 */
typedef struct ArkUI_TouchRecognizer ArkUI_TouchRecognizer;

/**
 * @brief Defines a touch recognizer handle.
 *
 * @since 15
 */
typedef ArkUI_TouchRecognizer* ArkUI_TouchRecognizerHandle;

/**
 * @brief Defines an array of touch recognizer handle.
 *
 * @since 15
 */
typedef ArkUI_TouchRecognizerHandle* ArkUI_TouchRecognizerHandleArray;

/**
 * @brief Defines a callback function for notifying gesture recognizer destruction.
 * @since 12
 */
typedef void (*ArkUI_GestureRecognizerDisposeNotifyCallback)(ArkUI_GestureRecognizer* recognizer, void* userData);

/**
* @brief Checks whether a gesture is a built-in gesture of the component.
*
* @param event Indicates the pointer to the gesture interruption information.
* @return Returns <b>true</b> if the gesture is a built-in gesture; returns <b>false</b> otherwise.

* @since 12
*/
bool OH_ArkUI_GestureInterruptInfo_GetSystemFlag(const ArkUI_GestureInterruptInfo* event);

/**
* @brief Obtains the pointer to interrupted gesture recognizer.
*
* @param event Indicates the pointer to the gesture interruption information.
* @return Returns the pointer to interrupted gesture recognizer.
* @since 12
*/
ArkUI_GestureRecognizer* OH_ArkUI_GestureInterruptInfo_GetRecognizer(const ArkUI_GestureInterruptInfo* event);

/**
* @brief Obtains the pointer to the interrupted gesture event.
*
* @param event Indicates the pointer to the gesture interruption information.
* @return Returns the pointer to the interrupted gesture event.
* @since 12
*/
ArkUI_GestureEvent* OH_ArkUI_GestureInterruptInfo_GetGestureEvent(const ArkUI_GestureInterruptInfo* event);

/**
* @brief Obtains the type of the system gesture to trigger.
*
* @param event Indicates the pointer to the gesture interruption information.
* @return Returns the type of the system gesture to trigger. If the gesture to trigger is not a system gesture,
*         <b>-1</b> is returned.
* @since 12
*/
int32_t OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(const ArkUI_GestureInterruptInfo* event);

/**
* @brief Get the touch recognizer handles from the gesture interrupt info.
*
* @param info Indicates the pointer to a gesture interrupt info.
* @param recognizers Indicates the pointer to an array of touch recognizer handles.
* @param size Indicates the size of recognizers.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 15
*/
int32_t OH_ArkUI_GestureInterruptInfo_GetTouchRecognizers(const ArkUI_GestureInterruptInfo* info,
    ArkUI_TouchRecognizerHandleArray* recognizers, int32_t* size);

/**
* @brief Get component object of the specific touch recognizer.
*
* @param recognizer Indicates the pointer to the TouchRecognizer.
* @return Get component object of the specific touch recognizer.
* @since 15
*/
ArkUI_NodeHandle OH_ArkUI_TouchRecognizer_GetNodeHandle(const ArkUI_TouchRecognizerHandle recognizer);

/**
* @brief Send touch-cancel event to the touch recognizer in a gesture interruption callback.
*
* @param recognizer Indicates the touch recognizer handle.
* @param info Indicates the pointer to a gesture interrupt info.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 15
*/
int32_t OH_ArkUI_TouchRecognizer_CancelTouch(ArkUI_TouchRecognizerHandle recognizer, ArkUI_GestureInterruptInfo* info);

/**
* @brief Obtains the gesture event type.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the gesture event type.
* @since 12
*/
ArkUI_GestureEventActionType OH_ArkUI_GestureEvent_GetActionType(const ArkUI_GestureEvent* event);

/**
* @brief Obtains gesture input.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the pointer to the input event of the gesture event.
* @since 12
*/
const ArkUI_UIInputEvent* OH_ArkUI_GestureEvent_GetRawInputEvent(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the number of times that a long press gesture is triggered periodically.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the number of times that the long press gesture is triggered periodically.
* @since 12
*/
int32_t OH_ArkUI_LongPress_GetRepeatCount(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the velocity of a pan gesture along the main axis.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the velocity of the pan gesture along the main axis, in px/s.
*         The value is the square root of the sum of the squares of the velocity on the x-axis and y-axis.
* @since 12
*/
float OH_ArkUI_PanGesture_GetVelocity(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the velocity of a pan gesture along the x-axis.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the velocity of the pan gesture along the x-axis, in px/s.
* @since 12
*/
float OH_ArkUI_PanGesture_GetVelocityX(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the velocity of a pan gesture along the y-axis.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the velocity of the pan gesture along the y-axis, in px/s.
* @since 12
*/
float OH_ArkUI_PanGesture_GetVelocityY(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the relative offset of a pan gesture along the x-axis.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the relative offset of the gesture along the x-axis, in px.
* @since 12
*/
float OH_ArkUI_PanGesture_GetOffsetX(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the relative offset of a pan gesture along the y-axis.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the relative offset of the gesture along the y-axis, in px.
* @since 12
*/
float OH_ArkUI_PanGesture_GetOffsetY(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the angle information of the swipe gesture.
*
* After a swipe gesture is recognized, a line connecting the two fingers is identified as the initial line.
* As the fingers swipe, the line between the fingers rotates. \n
* Based on the coordinates of the initial line's and current line's end points, the arc tangent function is used to
* calculate the respective included angle of the points relative to the horizontal direction \n
* by using the following formula: Rotation angle = arctan2(cy2-cy1,cx2-cx1) - arctan2(y2-y1,x2-x1). \n
* The initial line is used as the coordinate system. Values from 0 to 180 degrees represent clockwise rotation,
* while values from –180 to 0 degrees represent counterclockwise rotation. \n
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the angle of the swipe gesture, which is the result obtained based on the aforementioned formula.
* @since 12
*/
float OH_ArkUI_SwipeGesture_GetAngle(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the average velocity of all fingers used in the swipe gesture.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the average velocity of all fingers used in the swipe gesture, in px/s.
* @since 12
*/
float OH_ArkUI_SwipeGesture_GetVelocity(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the angle information of a rotation gesture.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the rotation angle.
* @since 12
*/
float OH_ArkUI_RotationGesture_GetAngle(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the scale ratio of a pinch gesture.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the scale ratio.
* @since 12
*/
float OH_ArkUI_PinchGesture_GetScale(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the X coordinate of the center of the pinch gesture, in vp,
* relative to the upper left corner of the current component.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the X coordinate of the center of the pinch gesture, in vp,
* relative to the upper left corner of the current component.
* @since 12
*/
float OH_ArkUI_PinchGesture_GetCenterX(const ArkUI_GestureEvent* event);

/**
* @brief Obtains the Y coordinate of the center of the pinch gesture, in vp,
* relative to the upper left corner of the current component.
*
* @param event Indicates the pointer to the gesture event.
* @return Returns the Y coordinate of the center of the pinch gesture, in vp,
* relative to the upper left corner of the current component.
* @since 12
*/
float OH_ArkUI_PinchGesture_GetCenterY(const ArkUI_GestureEvent* event);

/**
* @brief Get the ARKUI component bound to the gesture.
*
* @param event gesture event.
* @return ARKUI component bound to the gesture.If Null is returned, it means event is an invalid value.
* @since 12
*/
ArkUI_NodeHandle OH_ArkUI_GestureEvent_GetNode(const ArkUI_GestureEvent* event);

/**
* @brief Obtains information about a gesture response chain.
*
* @param event Indicates the pointer to the gesture interruption information.
* @param responseChain Indicates the pointer to an array of gesture recognizers on the response chain.
* @param count Indicates the pointer to the number of gesture recognizers on the response chain.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 12
*/
int32_t OH_ArkUI_GetResponseRecognizersFromInterruptInfo(const ArkUI_GestureInterruptInfo* event,
    ArkUI_GestureRecognizerHandleArray* responseChain, int32_t* count);

/**
* @brief Sets the enabled state of a gesture recognizer.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param enabled Indicates the enabled state.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 12
*/
int32_t OH_ArkUI_SetGestureRecognizerEnabled(ArkUI_GestureRecognizer* recognizer, bool enabled);

/**
* @brief Sets whether to enable strict finger count checking. If this feature is enabled and the actual number of touch
*        fingers does not match the set number, the gesture recognition fails.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param limitFingerCount Indicates whether to enable strict finger count checking.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
* @since 15
*/
int32_t OH_ArkUI_SetGestureRecognizerLimitFingerCount(ArkUI_GestureRecognizer* recognizer, bool limitFingerCount);

/**
* @brief Obtains the enabled state of a gesture recognizer.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @return Returns <b>true</b> if the gesture recognizer is enabled.
*         Returns <b>false</b> if the gesture recognizer is disabled.
* @since 12
*/
bool OH_ArkUI_GetGestureRecognizerEnabled(ArkUI_GestureRecognizer* recognizer);

/**
* @brief Obtains the state of a gesture recognizer.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param state Indicates the pointer to the state of the gesture recognizer.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 12
*/
int32_t OH_ArkUI_GetGestureRecognizerState(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureRecognizerState* state);

/**
* @brief Obtains the information about a gesture event target.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param info Indicates the information about a gesture event target.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 12
*/
int32_t OH_ArkUI_GetGestureEventTargetInfo(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureEventTargetInfo** info);

/**
* @brief Obtains whether this scroll container is scrolled to the top.
*
* @param info Indicates the information about a gesture event target.
* @param ret Indicates whether the scroll container is scrolled to the top.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
*         Returns {@link ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER} if the component is not a scroll container.
* @since 12
*/
int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollBegin(ArkUI_GestureEventTargetInfo* info, bool* ret);

/**
* @brief Obtains whether this scroll container is scrolled to the bottom.
*
* @param info Indicates the information about a gesture event target.
* @param ret Indicates whether the scroll container is scrolled to the bottom.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
*         Returns {@link ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER} if the component is not a scroll container.
* @since 12
*/
int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollEnd(ArkUI_GestureEventTargetInfo* info, bool* ret);

/**
* @brief Obtains the direction of a pan gesture.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param directionMask Indicates the pan direction.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 12
*/
int32_t OH_ArkUI_GetPanGestureDirectionMask(ArkUI_GestureRecognizer* recognizer,
    ArkUI_GestureDirectionMask* directionMask);

/**
* @brief Obtains whether a gesture is a built-in gesture.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @return Returns <b>true</b> if the gesture is a built-in gesture; returns <b>false</b> otherwise.
* @since 12
*/
bool OH_ArkUI_IsBuiltInGesture(ArkUI_GestureRecognizer* recognizer);

/**
* @brief Obtains the tag of a gesture recognizer.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param buffer Indicates the buffer.
* @param bufferSize Indicates the buffer size.
* @param result Indicates the length of the string to be written to the buffer.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
*         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH} if the buffer is not large enough.
* @since 12
*/
int32_t OH_ArkUI_GetGestureTag(ArkUI_GestureRecognizer* recognizer, char* buffer, int32_t bufferSize, int32_t* result);

/**
* @brief Obtains the ID of the component linked to a gesture recognizer.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param nodeId Indicates the component ID.
* @param size Indicates the buffer size.
* @param result Indicates the length of the string to be written to the buffer.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
*         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH} if the buffer is not large enough.
* @since 12
*/
int32_t OH_ArkUI_GetGestureBindNodeId(ArkUI_GestureRecognizer* recognizer, char* nodeId, int32_t size,
    int32_t* result);

/**
* @brief Obtains whether a gesture recognizer is valid.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @return Returns <b>true</b> if the gesture recognizer is valid.
*         Returns <b>false</b> if the gesture recognizer is invalid.
* @since 12
*/
bool OH_ArkUI_IsGestureRecognizerValid(ArkUI_GestureRecognizer* recognizer);

/**
* @brief Obtains custom data in the parallel internal gesture event.
*
* @param event Indicates the pointer to a parallel internal gesture event.
* @return Returns the pointer to custom data.
* @since 12
*/
void* OH_ArkUI_ParallelInnerGestureEvent_GetUserData(ArkUI_ParallelInnerGestureEvent* event);

/**
* @brief Obtains the current gesture recognizer in a parallel internal gesture event.
*
* @param event Indicates the pointer to a parallel internal gesture event.
* @return Returns the pointer to the current gesture recognizer.
* @since 12
*/
ArkUI_GestureRecognizer* OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer(
    ArkUI_ParallelInnerGestureEvent* event);

/**
* @brief Obtains the conflicting gesture recognizers in a parallel internal gesture event.
*
* @param event Indicates the pointer to a parallel internal gesture event.
* @param array Indicates the pointer to the array of conflicting gesture recognizers.
* @param size Indicates the size of the array of conflicting gesture recognizers.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 12
*/
int32_t OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers(ArkUI_ParallelInnerGestureEvent* event,
    ArkUI_GestureRecognizerHandleArray* array, int32_t* size);

/**
* @brief Sets a callback function for notifying gesture recognizer destruction.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param callback Indicates the callback function for notifying gesture recognizer destruction.
* @param userData Indicates the custom data.
* @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
* @since 12
*/
int32_t OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify(ArkUI_GestureRecognizer* recognizer,
    ArkUI_GestureRecognizerDisposeNotifyCallback callback, void* userData);

/**
* @brief Obtains the swipe direction of a gesture recognizer.
*
* @param recognizer Pointer to a gesture recognizer.
* @param directMask Swipe direction of the gesture recognizer.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_DirectMask(
    ArkUI_GestureRecognizer* recognizer, ArkUI_GestureDirectionMask* directMask);

/**
* @brief Obtains the number of fingers used by a gesture recognizer.
*
* @param recognizer Pointer to a gesture recognizer.
* @param finger Number of fingers used by the gesture recognizer.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_FingerCount(ArkUI_GestureRecognizer* recognizer, int* finger);

/**
* @brief Checks whether a gesture recognizer has a finger count limit.
*
* @param recognizer Pointer to a gesture recognizer.
* @param isLimited Whether the gesture recognizer has a finger count limit.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_limitFingerCount(ArkUI_GestureRecognizer* recognizer, bool* isLimited);

/**
* @brief Checks whether a gesture recognizer supports repeated event callbacks.
*
* @param recognizer Pointer to a gesture recognizer.
* @param isRepeat Whether the gesture recognizer supports repeated event callbacks.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is not
* supported.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_repeat(ArkUI_GestureRecognizer* recognizer, bool* isRepeat);

/**
* @brief Obtains the allowed movement distance range for a gesture recognizer.
*
* @param recognizer Pointer to a gesture recognizer.
* @param distance Allowed movement distance range of the gesture recognizer.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is not
* supported.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_distance(ArkUI_GestureRecognizer* recognizer, double* distance);

/**
* @brief Obtains the minimum swipe speed recognized by a gesture recognizer.
*
* @param recognizer Pointer to a gesture recognizer.
* @param speed Minimum swipe speed recognized by a gesture recognizer.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is not
* supported.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_speed(ArkUI_GestureRecognizer* recognizer, double* speed);

/**
* @brief Obtains the minimum duration required to trigger a long press by a gesture recognizer.
*
* @param recognizer Pointer to a gesture recognizer.
* @param duration Minimum duration for a long press.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is not
* supported.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_duration(ArkUI_GestureRecognizer* recognizer, int* duration);

/**
* @brief Obtains the minimum angle change required for a rotation gesture to be recognized by a gesture recognizer.
*
* @param recognizer Pointer to a gesture recognizer.
* @param angle Minimum angle change.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is not
* supported.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_angle(ArkUI_GestureRecognizer* recognizer, double* angle);

/**
* @brief Obtains the movement threshold for gestures to be recognized by a gesture recognizer.
*
* @param recognizer Pointer to a gesture recognizer.
* @param distanceThresHold Movement threshold.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is not
* supported.
* @since 18
*/
int32_t OH_ArkUI_GetGestureParam_distanceThreshold(ArkUI_GestureRecognizer* recognizer, double* distanceThreshold);

/**
* @brief Sets the minimum movement distance thresholds for gestures to be recognized by a gesture recognizer.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param size Size of the array of minimum movement distance thresholds.
* @param toolTypeArray Pointer to the array of tool types for which thresholds are set.
* @param distanceArray Pointer to the array of minimum movement distances, in px.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is
*                 not supported.
* @since 19
*/
ArkUI_ErrorCode OH_ArkUI_PanGesture_SetDistanceMap(
    ArkUI_GestureRecognizer* recognizer, int size, int* toolTypeArray, double* distanceArray);

/**
* @brief Obtains the movement threshold for gestures to be recognized by a gesture recognizer for a specific tool type.
*
* @param recognizer Indicates the pointer to a gesture recognizer.
* @param toolType Tool type for which you want to obtain the threshold.
* @param distance Gesture movement threshold of the gesture recognizer, in px.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
*         Returns {@link ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED} if the gesture recognizer type is
*                 not supported.
* @since 19
*/
ArkUI_ErrorCode OH_ArkUI_PanGesture_GetDistanceByToolType(
    ArkUI_GestureRecognizer* recognizer, int toolType, double* distance);

/**
 * @brief Registers a callback that is executed after all gesture recognizers are collected.
 * When the user begins touching the screen, the system performs hit testing and collects gesture recognizers
 * based on the touch location. Subsequently, before processing any move events, the component can use this API
 * to determine the gesture recognizers that will participate in and compete for recognition.
 *
 * @param node Handle to the node on which the callback is to be set.
 * @param userData Custom data.
 * @param touchTestDone Callback for completion of gesture recognizer collection.
 *                      - event: Basic information of the gesture.
 *                      - recognizers: Array of gesture recognizers.
 *                      - count: Number of gesture recognizers.
 * @return Result code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR}: The operation is successful.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID}: A parameter error occurs.
 * @since 20
 */
ArkUI_ErrorCode OH_ArkUI_SetTouchTestDoneCallback(
    ArkUI_NodeHandle node,
    void* userData,
    void (*touchTestDone)(
        ArkUI_GestureEvent* event,
        ArkUI_GestureRecognizerHandleArray recognizers,
        int32_t count,
        void* userData
    )
);

/**
 * @brief Defines the gesture APIs.
 *
 * @since 12
 */
typedef struct {
    /** The struct version is 1. */
    int32_t version;

    /**
    * @brief Creates a tap gesture.
    *
    *        1. This API is used to trigger a tap gesture with one, two, or more taps. \n
    *        2. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms. \n
    *        3. If the distance between the last tapped position and the current tapped position exceeds 60 vp,
    *           gesture recognition fails. \n
    *        4. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers
    *           touching the screen within 300 ms of the first finger touch is less than the required number, \n
    *           or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted
    *           is less than the required number. \n
    *        5. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized. \n
    *
    * @param countNum Indicates the number of consecutive taps. If the value is less than 1 or is not set,
    *        the default value <b>1</b> is used.
    * @param fingersNum Indicates the number of fingers required to trigger a tap. The value ranges
    *        from 1 to 10. If the value is less than 1 or is not set, the default value <b>1</b> is used.
    * @return Returns the pointer to the created gesture.
    */
    ArkUI_GestureRecognizer* (*createTapGesture)(int32_t countNum, int32_t fingersNum);

    /**
    * @brief Creates a long press gesture.
    *
    *        1. This API is used to trigger a long press gesture, which requires one or more fingers with a minimum
    *           The value ranges 500 ms hold-down time. \n
    *        2. In components that support drag actions by default, such as <b><Text></b>, <b><TextInput></b>,
    *           <b><TextArea></b>, <b><Hyperlink></b>, <b><Image></b>, and <b>RichEditor></b>, the long press gesture \n
    *           may conflict with the drag action. If this occurs, they are handled as follows: \n
    *           If the minimum duration of the long press gesture is less than 500 ms, the long press gesture receives
    *           a higher response priority than the drag action. \n
    *           If the minimum duration of the long press gesture is greater than or equal to 500 ms,
    *           the drag action receives a higher response priority than the long press gesture. \n
    *        3. If a finger moves more than 15 px after being pressed, the gesture recognition fails. \n
    *
    * @param fingersNum Indicates the minimum number of fingers to trigger a long press gesture.
    *        The value ranges from 1 to 10.
    * @param repeatResult Indicates whether to continuously trigger the event callback.
    * @param durationNum Indicates the minimum hold-down time, in ms.
    *        If the value is less than or equal to 0, the default value <b>500</b> is used.
    * @return Returns the pointer to the created gesture.
    */
    ArkUI_GestureRecognizer* (*createLongPressGesture)(int32_t fingersNum, bool repeatResult, int32_t durationNum);

    /**
    * @brief Creates a pan gesture.
    *
    *        1. This API is used to trigger a pan gesture when the movement distance of a finger on the screen exceeds
    *           the minimum value. \n
    *        2. If a pan gesture and a tab swipe occur at the same time, set <b>distanceNum</b> to <b>1</b>
    *           so that the gesture can be more easily recognized. \n
    *
    * @param fingersNum Indicates the minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.
    *        If the value is less than 1 or is not set, the default value <b>1</b> is used.
    * @param directions Indicates the pan direction. The value supports the AND (&amp;) and OR (\|) operations.
    * @param distanceNum Indicates the minimum pan distance to trigger the gesture, in vp. If this parameter is
    *        set to a value less than or equal to 0, the default value <b>5</b> is used.
    * @return Returns the pointer to the created gesture.
    */
    ArkUI_GestureRecognizer* (*createPanGesture)(
        int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum);

    /**
    * @brief Creates a pinch gesture.
    *
    *        1. This API is used to trigger a pinch gesture, which requires two to five fingers with a minimum 5 vp
    *           distance between the fingers. \n
    *        2. While more fingers than the minimum number can be pressed to trigger the gesture, only the first
    *           fingers of the minimum number participate in gesture calculation. \n
    *
    * @param fingersNum Indicates the minimum number of fingers to trigger a pinch. The value ranges from 2 to 5.
    *        Default value: <b>2</b>
    * @param distanceNum Indicates the minimum recognition distance, in px. If this parameter is set to a value less
    *        than or equal to 0, the default value <b>5</b> is used.
    * @return Returns the pointer to the created gesture.
    */
    ArkUI_GestureRecognizer* (*createPinchGesture)(int32_t fingersNum, double distanceNum);

    /**
    * @brief Creates a rotation gesture.
    *
    *        1. This API is used to trigger a rotation gesture, which requires two to five fingers with a
    *           minimum 1-degree rotation angle. \n
    *        2. While more fingers than the minimum number can be pressed to trigger the gesture, only the first
    *           two fingers participate in gesture calculation. \n
    *
    * @param fingersNum Indicates the minimum number of fingers to trigger a rotation. The value ranges from 2 to 5.
    *        Default value: <b>2</b>
    * @param angleNum Indicates the minimum degree that can trigger the rotation gesture. Default value: <b>1</b>
    *        If this parameter is set to a value less than or equal to 0 or greater than 360,
    *        the default value <b>1</b> is used.
    * @return Returns the pointer to the created gesture.
    */
    ArkUI_GestureRecognizer* (*createRotationGesture)(int32_t fingersNum, double angleNum);

    /**
    * @brief Creates a swipe gesture.
    *
    *        This API is used to implement a swipe gesture, which can be recognized when the swipe speed is 100
    *        vp/s or higher. \n
    *
    * @param fingersNum Indicates the minimum number of fingers to trigger a swipe gesture.
    *        The value ranges from 1 to 10.
    * @param directions Indicates the swipe direction.
    * @param speedNum Indicates the minimum speed of the swipe gesture, in px/s.
    *        If this parameter is set to a value less than or equal to 0, the default value <b>100</b> is used.
    * @return Returns the pointer to the created gesture.
    */
    ArkUI_GestureRecognizer* (*createSwipeGesture)(
        int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum);

    /**
    * @brief Creates a gesture group.
    *
    * @param gestureMode Indicates the gesture group mode.
    * @return Returns the pointer to the created gesture group.
    */
    ArkUI_GestureRecognizer* (*createGroupGesture)(ArkUI_GroupGestureMode gestureMode);

    /**
    * @brief Disposes a gesture to release resources.
    *
    * @param recognizer Indicates the pointer to the gesture to dispose.
    */
    void (*dispose)(ArkUI_GestureRecognizer* recognizer);

    /**
    * @brief Adds a gesture to a gesture group.
    *
    * @param group Indicates the pointer to the gesture group.
    * @param child Indicates the gesture to be added to the gesture group.
    * @return Returns <b>0</b> if success.
    *         Returns <b>401</b> if a parameter exception occurs. Returns 401 if a parameter exception occurs.
    */
    int32_t (*addChildGesture)(ArkUI_GestureRecognizer* group, ArkUI_GestureRecognizer* child);

    /**
    * @brief Removes a gesture to a gesture group.
    *
    * @param group Indicates the pointer to the gesture group.
    * @param child Indicates the gesture to be removed to the gesture group.
    * @return Returns <b>0</b> if success.
    *         Returns <b>401</b> if a parameter exception occurs.
    */
    int32_t (*removeChildGesture)(ArkUI_GestureRecognizer* group, ArkUI_GestureRecognizer* child);

    /**
    * @brief Registers a callback for gestures.
    *
    * @param recognizer Indicates the pointer to the gesture recognizer.
    * @param actionTypeMask Indicates the set of gesture event types. Multiple callbacks can be registered at once,
    *        with the callback event types distinguished in the callbacks.
    *        Example: actionTypeMask = GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE;
    * @param extraParams Indicates the context passed in the <b>targetReceiver</b> callback.
    * @param targetReceiver Indicates the callback to register for processing the gesture event types.
    *        <b>event</b> indicates the gesture callback data.
    * @return Returns <b>0</b> if success.
    *         Returns <b>401</b> if a parameter exception occurs.
    */
    int32_t (*setGestureEventTarget)(
        ArkUI_GestureRecognizer* recognizer, ArkUI_GestureEventActionTypeMask actionTypeMask, void* extraParams,
        void (*targetReceiver)(ArkUI_GestureEvent* event, void* extraParams));

    /**
    * @brief Adds a gesture to a UI component.
    *
    * @param node Indicates the UI component to which you want to add the gesture.
    * @param recognizer Indicates the gesture to be added to the UI component.
    * @param mode Indicates the gesture event mode. Available options are <b>NORMAL_GESTURE</b>,
    *        <b>PARALLEL_GESTURE</b>, and <b>PRIORITY_GESTURE</b>.
    * @param mask Indicates the gesture masking mode.
    * @return Returns <b>0</b> if success.
    *         Returns <b>401</b> if a parameter exception occurs.
    */
    int32_t (*addGestureToNode)(
        ArkUI_NodeHandle node, ArkUI_GestureRecognizer* recognizer, ArkUI_GesturePriority mode, ArkUI_GestureMask mask);

    /**
    * @brief Removes a gesture from a node.
    *
    * @param node Indicates the node from which you want to remove the gesture.
    * @param recognizer Indicates the gesture to be removed.
    * @return Returns <b>0</b> if success.
    * Returns <b>401</b> if a parameter exception occurs.
    */
    int32_t (*removeGestureFromNode)(ArkUI_NodeHandle node, ArkUI_GestureRecognizer* recognizer);

    /**
    * @brief Sets a gesture interruption callback for a node.
    *
    * @param node Indicates the node for which you want to set a gesture interruption callback.
    * @param interrupter Indicates the gesture interruption callback to set.
    *        <b>info</b> indicates the gesture interruption data. If <b>interrupter</b> returns
    *        <b>GESTURE_INTERRUPT_RESULT_CONTINUE</b>, the gesture recognition process continues. If it returns
    *        <b>GESTURE_INTERRUPT_RESULT_REJECT</b>, the gesture recognition process is paused.
    * @return Returns <b>0</b> if success.
    * Returns <b>401</b> if a parameter exception occurs.
    */
    int32_t (*setGestureInterrupterToNode)(
        ArkUI_NodeHandle node, ArkUI_GestureInterruptResult (*interrupter)(ArkUI_GestureInterruptInfo* info));

    /**
    * @brief Obtains the type of a gesture.
    *
    * @param recognizer Indicates the pointer to the gesture.
    * @return Returns the gesture type.
    */
    ArkUI_GestureRecognizerType (*getGestureType)(ArkUI_GestureRecognizer* recognizer);

    /**
    * @brief Sets the callback function for a parallel internal gesture event.
    *
    * @param node Indicates the ArkUI node for which the callback of a parallel internal gesture event is to be set.
    * @param userData Indicates the custom data.
    * @param parallelInnerGesture Indicates the parallel internal gesture event. <b>event</b> returns the data of the
    *        parallel internal gesture event; <b>parallelInnerGesture</b> returns the pointer to the gesture recognizer
    *        that requires parallel recognition.
    * @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if success.
    *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter exception occurs.
    */
    int32_t (*setInnerGestureParallelTo)(
        ArkUI_NodeHandle node, void* userData, ArkUI_GestureRecognizer* (*parallelInnerGesture)(
            ArkUI_ParallelInnerGestureEvent* event));

    /**
    * @brief Creates a tap gesture that is subject to distance restrictions.
    *
    *        1. This API is used to trigger a tap gesture with one, two, or more taps. \n
    *        2. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms. \n
    *        3. If the distance between the last tapped position and the current tapped position exceeds 60 vp,
    *           gesture recognition fails. \n
    *        4. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers
    *           touching the screen within 300 ms of the first finger touch is less than the required number,
    *           or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted
    *           is less than the required number. \n
    *        5. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized. \n
    *        6. If the finger moves beyond the preset distance limit, gesture recognition fails. \n
    *
    * @param countNum Indicates the number of consecutive taps. If the value is less than 1 or is not set, the default
    *        value <b>1</b> is used.
    * @param fingersNum Indicates the number of fingers required to trigger a tap. The value ranges from 1 to 10.
    *        If the value is less than 1 or is not set, the default value <b>1</b> is used.
    * @param distanceThreshold Indicates the allowed moving distance of a finger.
    *        If the value is less than 0 or is not set, it will be converted to the default value of infinity.
    * @return Returns the pointer to the created gesture.
    */
    ArkUI_GestureRecognizer* (*createTapGestureWithDistanceThreshold)(
        int32_t countNum, int32_t fingersNum, double distanceThreshold);
} ArkUI_NativeGestureAPI_1;

/**
 * @brief Defines the gesture APIs.
 *
 * @since 18
 */
typedef struct {
    /**
     * @brief Pointer to the <b>ArkUI_NativeGestureAPI_1</b> struct.
     */
    ArkUI_NativeGestureAPI_1* gestureApi1;

    /**
    * @brief Sets the callback for gesture interruption events.
    *
    * @param node Node for which you want to set a gesture interruption callback.
    * @param userData Custom data.
    * @param interrupter Gesture interruption callback to set. <b>info</b> indicates the gesture interruption data.
    * If <b>interrupter</b> returns <b>GESTURE_INTERRUPT_RESULT_CONTINUE</b>, the gesture recognition process proceeds
    * properly. If it returns <b>GESTURE_INTERRUPT_RESULT_REJECT</b>, the gesture recognition process is paused.
    * @return Returns <b>0</b> if success.
    *         Returns <b>401</b> if a parameter error occurs.
    */
    int32_t (*setGestureInterrupterToNode)(ArkUI_NodeHandle node, void* userData,
        ArkUI_GestureInterruptResult (*interrupter)(ArkUI_GestureInterruptInfo* info));
} ArkUI_NativeGestureAPI_2;

/**
* @brief Obtains the custom data from a gesture interruption event.
*
* @param event Pointer to the gesture interruption information.
* @return Returns the pointer to the custom data.
* @since 18
*/
void* OH_ArkUI_GestureInterrupter_GetUserData(ArkUI_GestureInterruptInfo* event);

/**
 * @brief Prevents a gesture recognizer from participating in the current gesture recognition before all fingers are
 * lifted.
 * If the system has already determined the result of the gesture recognizer (regardless of success or failure),
 * calling this API will be ineffective.
 *
 * @param recognizer Pointer to a gesture recognizer.
 * @return Result code.
 *         {@link ARKUI_ERROR_CODE_NO_ERROR}: The operation is successful.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID}: A parameter error occurs.
 * @since 20
 */
ArkUI_ErrorCode OH_ArkUI_PreventGestureRecognizerBegin(ArkUI_GestureRecognizer* recognizer);

#ifdef __cplusplus
};
#endif

#endif // ARKUI_NATIVE_GESTTURE_H
/** @} */
