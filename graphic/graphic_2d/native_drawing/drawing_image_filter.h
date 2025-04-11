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
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides functions such as 2D graphics rendering, text drawing, and image display.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 *
 * @since 8
 * @version 1.0
 */

/**
 * @file drawing_image_filter.h
 *
 * @brief Declares functions related to the <b>imageFilter</b> object in the drawing module.
 *
 * @kit ArkGraphics2D
 * @library libnative_drawing.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 12
 * @version 1.0
 */

#ifndef C_INCLUDE_DRAWING_IMAGE_FILTER_H
#define C_INCLUDE_DRAWING_IMAGE_FILTER_H

#include "drawing_shader_effect.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates an <b>OH_Drawing_ImageFilter</b> object that blurs its input by the separate x and y sigmas.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param sigmaX Indicates the Gaussian sigma value for blurring along the x axis.
 * @param sigmaY Indicates the Gaussian sigma value for blurring along the y axis.
 * @param tileMode Indicates the tile mode applied at edges.
 * @param imageFilter Indicates the input filter that is blurred, uses source bitmap if this is null.
 * @return Returns the pointer to the <b>OH_Drawing_ImageFilter</b> object created.
 *         If nullptr is returned, the creation fails.
 *         The possible cause of the failure is that the available memory is empty.
 * @since 12
 * @version 1.0
 */
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateBlur(float sigmaX, float sigmaY, OH_Drawing_TileMode tileMode,
    OH_Drawing_ImageFilter* imageFilter);

/**
 * @brief Creates an <b>OH_Drawing_ImageFilter</b> object that applies the color filter to the input.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param colorFilter Indicates the color filter that transforms the input image.
 * @param imageFilter Indicates the input filter, or uses the source bitmap if this is null.
 * @return Returns the pointer to the <b>OH_Drawing_ImageFilter</b> object created.
 *         If nullptr is returned, the creation fails.
 *         The possible cause of the failure is that the available memory is empty or
 *         a nullptr <b>OH_Drawing_ColorFilter</b> is passed.
 * @since 12
 * @version 1.0
 */
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromColorFilter(OH_Drawing_ColorFilter* colorFilter,
    OH_Drawing_ImageFilter* imageFilter);

/**
 * @brief Creates an <b>OH_Drawing_ImageFilter</b> object with the provided x and y offset.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param x Indicates the x offset.
 * @param y Indicates the y offset.
 * @param imageFilter Indicates the input filter, or uses the source bitmap if this is null.
 * @return Returns the pointer to the <b>OH_Drawing_ImageFilter</b> object created.
 *         If nullptr is returned, the creation fails.
 *         The possible cause of the failure is that the available memory is empty.
 * @since 20
 * @version 1.0
 */
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateOffset(float x, float y, OH_Drawing_ImageFilter* imageFilter);

/**
 * @brief Creates an <b>OH_Drawing_ImageFilter</b> object that applies the shader to the input.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param shaderEffct Indicates the shader effect to be applied to the image.
 * @return Returns the pointer to the <b>OH_Drawing_ImageFilter</b> object created.
 *         If nullptr is returned, the creation fails.
 *         The possible cause of the failure is that the available memory is empty or
 *         a nullptr <b>OH_Drawing_ShaderEffect</b> is passed.
 * @since 20
 * @version 1.0
 */
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromShaderEffect(OH_Drawing_ShaderEffect* shaderEffct);

/**
 * @brief Destroys an <b>OH_Drawing_ImageFilter</b> object and reclaims the memory occupied by the object.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @param imageFilter Indicates the pointer to an <b>OH_Drawing_ImageFilter</b> object.
 * @since 12
 * @version 1.0
 */
void OH_Drawing_ImageFilterDestroy(OH_Drawing_ImageFilter* imageFilter);

#ifdef __cplusplus
}
#endif
/** @} */
#endif