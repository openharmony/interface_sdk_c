/*
 * Copyright (c) 2023-2024 Huawei Device Co., Ltd.
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
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides functions such as 2D graphics rendering, text drawing, and image display.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 *
 * @since 11
 * @version 1.0
 */

/**
 * @file drawing_filter.h
 *
 * @brief Declares functions related to the <b>filter</b> object in the drawing module.
 *
 * @kit ArkGraphics2D
 * @library libnative_drawing.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 11
 * @version 1.0
 */

#ifndef C_INCLUDE_DRAWING_FILTER_H
#define C_INCLUDE_DRAWING_FILTER_H

#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates an <b>OH_Drawing_Filter</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @return Returns the pointer to the <b>OH_Drawing_Filter</b> object created.
 * @since 11
 * @version 1.0
 */
OH_Drawing_Filter* OH_Drawing_FilterCreate(void);

/**
 * @brief Sets an <b>OH_Drawing_ImageFilter</b> object for an <b>OH_Drawing_Filter</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param filter Indicates the pointer to an <b>OH_Drawing_Filter</b> object.
 * @param imageFilter Indicates the pointer to an <b>OH_Drawing_ImageFilter</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_FilterSetImageFilter(OH_Drawing_Filter* filter, OH_Drawing_ImageFilter* imageFilter);

/**
 * @brief Sets an <b>OH_Drawing_MaskFilter</b> object for an <b>OH_Drawing_Filter</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param filter Indicates the pointer to an <b>OH_Drawing_Filter</b> object.
 * @param maskFilter Indicates the pointer to an <b>OH_Drawing_MaskFilter</b> object.
 * @since 11
 * @version 1.0
 */
void OH_Drawing_FilterSetMaskFilter(OH_Drawing_Filter* filter, OH_Drawing_MaskFilter* maskFilter);

/**
 * @brief Sets an <b>OH_Drawing_ColorFilter</b> object for an <b>OH_Drawing_Filter</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param filter Indicates the pointer to an <b>OH_Drawing_Filter</b> object.
 * @param colorFilter Indicates the pointer to an <b>OH_Drawing_ColorFilter</b> object.
 * @since 11
 * @version 1.0
 */
void OH_Drawing_FilterSetColorFilter(OH_Drawing_Filter* filter, OH_Drawing_ColorFilter* colorFilter);

/**
 * @brief Gets an <b>OH_Drawing_ColorFilter</b> object from an <b>OH_Drawing_Filter</b> object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param filter Indicates the pointer to an <b>OH_Drawing_Filter</b> object.
 * @param colorFilter Indicates the pointer to an <b>OH_Drawing_ColorFilter</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_FilterGetColorFilter(OH_Drawing_Filter* filter, OH_Drawing_ColorFilter* colorFilter);

/**
 * @brief Destroys an <b>OH_Drawing_Filter</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param filter Indicates the pointer to an <b>OH_Drawing_Filter</b> object.
 * @since 11
 * @version 1.0
 */
void OH_Drawing_FilterDestroy(OH_Drawing_Filter* filter);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
