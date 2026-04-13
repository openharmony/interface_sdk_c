/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file native_color_space_manager.h
 *
 * @brief This file declares the functions for creating and using a color space.
 * 
 * @kit ArkGraphics2D
 * @library libnative_color_space_manager.so
 * @syscap SystemCapability.Graphic.Graphic2D.ColorManager.Core
 * @since 13
 * @version 1.0
 */

/**
 * @addtogroup NativeColorSpaceManager
 * @{
 *
 * @brief Provides the native colorSpaceManager capability.
 *
 * @syscap SystemCapability.Graphic.Graphic2D.ColorManager.Core
 * @since 13
 * @version 1.0
 */
/**
 * @addtogroup NativeColorSpaceManager
 * @{
 *
 * @brief Provides the native colorSpaceManager capability.
 *
 * @since 13
 * @version 1.0
 */
#ifndef C_INCLUDE_NATIVE_COLOR_SPACE_MANAGER_H_
#define C_INCLUDE_NATIVE_COLOR_SPACE_MANAGER_H_

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 提供OH_NativeColorSpaceManager结构体声明。
 *
 * @since 13
 */
typedef struct OH_NativeColorSpaceManager OH_NativeColorSpaceManager;

/**
 * @brief Defines an enum for the color space names.
 *
 * @since 13
 */
} ColorSpaceName;

/**
 * @brief Describes the color space primaries.
 * 
 * @since 13
 */
typedef struct {
    /**
     * Unknown color space.
     */
    NONE = 0,
    /**
     * Color space based on Adobe RGB.
     */
    ADOBE_RGB = 1,
    /**
     * Color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999.
     */
    DCI_P3 = 2,
    /**
     * Color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999.
     */
    DISPLAY_P3 = 3,
     */
    DISPLAY_P3 = 3,
    /**
     * Standard Red Green Blue (SRGB) color space based on IEC 61966-2.1:1999.
     */
    SRGB = 4,
    /**
     * Color space based on ITU-R BT.709.
     */
    BT709 = 6,
    /**
     * Color space based on ITU-R BT.601.
     */
    BT601_EBU = 7,
    /**
     * Color space based on ITU-R BT.601.
     */
    BT601_SMPTE_C = 8,
    /**
     * Color space based on ITU-R BT.2020.
     */
    BT2020_HLG = 9,
    /**
     * Color space based on ITU-R BT.2020.
     */
    BT2020_PQ = 10,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of HLG, and the color range of Full.
     */
    P3_HLG = 11,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of PQ, and the color range of Full.
     */
    P3_PQ = 12,
    /**
     * Color space with the color primaries of ADOBE_RGB, the transfer characteristics of ADOBE_RGB, and the color
     * range of LIMIT.
     */
    ADOBE_RGB_LIMIT = 13,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of SRGB, and the color range of
     * LIMIT.
     */
    DISPLAY_P3_LIMIT = 14,
    /**
     * Color space with the color primaries of SRGB, the transfer characteristics of SRGB, and the color range of LIMIT.
     */
    SRGB_LIMIT = 15,
    /**
     * Color space with the color primaries of BT.709, the transfer characteristics of BT.709, and the color range of
     * LIMIT.
     */
    BT709_LIMIT = 16,
    /**
     * Color space with the color primaries of BT.601_P, the transfer characteristics of BT.709, and the color range of
     * LIMIT.
     */
    BT601_EBU_LIMIT = 17,
    /**
     * Color space with the color primaries of BT.601_N, the transfer characteristics of BT.709, and the color range of
     * LIMIT.
     */
    BT601_SMPTE_C_LIMIT = 18,
    /**
     * Color space with the color primaries of BT.2020, the transfer characteristics of HLG, and the color range of
     * LIMIT.
     */
    BT2020_HLG_LIMIT = 19,
    /**
     * Color space with the color primaries of BT.2020, the transfer characteristics of PQ, and the color range of
     * LIMIT.
     */
    BT2020_PQ_LIMIT = 20,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of HLG, and the color range of
     * LIMIT.
     */
    P3_HLG_LIMIT = 21,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of PQ, and the color range of LIMIT.
     */
    P3_PQ_LIMIT = 22,
    /**
     * Color space with the color primaries of P3_D65 and the transfer characteristic of LINEAR.
     */
    LINEAR_P3 = 23,
    /**
     * Color space with the color primaries of SRGB and the transfer characteristic of LINEAR.
     */
    LINEAR_SRGB = 24,
    /**
     * Color space with the color primaries of BT.709 and the transfer characteristic of LINEAR.
     */
    LINEAR_BT709 = LINEAR_SRGB,
    /**
     * Color space with the color primaries of BT.2020 and the transfer characteristic of LINEAR.
     */
    LINEAR_BT2020 = 25,
    /**
     * Color space with the color primaries of SRGB, the transfer characteristics of SRGB, and the color range of Full.
     */
    DISPLAY_SRGB = SRGB,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of SRGB, and the color range of
     * Full.
     */
    DISPLAY_P3_SRGB = DISPLAY_P3,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of HLG, and the color range of Full.
     */
    DISPLAY_P3_HLG = P3_HLG,
    /**
     * Color space with the color primaries of P3_D65, the transfer characteristics of PQ, and the color range of Full.
     */
    DISPLAY_P3_PQ = P3_PQ,
    /**
     * Custom color space.
     */
    CUSTOM = 5,
} ColorSpacePrimaries;

 * 
 * @since 13
 */
typedef struct {
    /** Indicates white point return array */
    float arr[2];
} WhitePointArray;

/**
 * @brief 通过colorSpaceName创建OH_NativeColorSpaceManager实例。
 * 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。
 *
 * @param colorSpaceName 表示创建{@link OH_NativeColorSpaceManager}的色彩空间名称。
 * @return 返回一个指向{@link OH_NativeColorSpaceManager}实例的指针。内存不足时，会导致创建OH_NativeColorSpaceManager实例失败。
 * @since 13
 * @version 1.0
 */
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromName(ColorSpaceName colorSpaceName);

/**
 * @brief 通过原色和伽马值创建OH_NativeColorSpaceManager实例。
 * 每次调用此函数时，都会创建一个新的OH_NativeColorSpaceManager实例。
 *
 * @param primaries 表示创建{@link OH_NativeColorSpaceManager}的色彩原色。
 * @param gamma 表示创建{@link OH_NativeColorSpaceManager}的伽马值，伽马值为一个浮点数，用于校正亮度范围。
 * 伽马值通常为正值，负值会使弱光区域更亮，强光区域变暗，伽马值为0表示线性色彩空间。
 * @return 返回一个指向{@link OH_NativeColorSpaceManager}实例的指针。
 * 内存不足时，会导致创建OH_NativeColorSpaceManager实例失败。
 * @since 13
 * @version 1.0
 */
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma(
    ColorSpacePrimaries primaries, float gamma);

/**
 * @brief 销毁OH_NativeColorSpaceManager实例。
 *
 * @param nativeColorSpaceManager 表示指向OH_NativeColorSpaceManager实例的指针。
 * @since 13
 * @version 1.0
 */
void OH_NativeColorSpaceManager_Destroy(OH_NativeColorSpaceManager* nativeColorSpaceManager);

/**
 * @brief 获取色彩空间名称。
 *
 * @param nativeColorSpaceManager 表示指向OH_NativeColorSpaceManager实例的指针。
 * @return 返回色彩空间枚举{@link ColorSpaceName}对应的值。其中，当返回值为0时，表示接口操作失败。
 * @since 13
 * @version 1.0
 */
int OH_NativeColorSpaceManager_GetColorSpaceName(
    OH_NativeColorSpaceManager* nativeColorSpaceManager);

/**
 * @brief 获取白点。
 *
 * @param nativeColorSpaceManager 表示指向OH_NativeColorSpaceManager实例的指针。
 * @return 返回值为float数组，返回值为<0.0, 0.0>表示接口操作失败，其余返回值表示操作成功。
 * @since 13
 * @version 1.0
 */
WhitePointArray OH_NativeColorSpaceManager_GetWhitePoint(
    OH_NativeColorSpaceManager* nativeColorSpaceManager);

/**
 * @brief 获取伽马值。
 *
 * @param nativeColorSpaceManager 表示指向OH_NativeColorSpaceManager实例的指针。
 * @return 返回值为float类型，返回值为0.0表示接口操作失败，其余返回值表示操作成功。
 * @since 13
 * @version 1.0
 */
float OH_NativeColorSpaceManager_GetGamma(OH_NativeColorSpaceManager* nativeColorSpaceManager);

    float wX;
    /**
     * Y-coordinate of the white point.
     */
    float wY;
} ColorSpacePrimaries;

#ifdef __cplusplus
}
#endif

/** @} */
#endif