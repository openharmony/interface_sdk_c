/*
 * Copyright (c) 2024-2025 Huawei Device Co., Ltd.
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
 * @file drawing_gpu_context.h
 *
 * @brief This file declares the functions related to the GPU context in the drawing module.
 * 
 * @kit ArkGraphics2D
 * @library libnative_drawing.so
 * @syscap SystemCapability.Graphic.Graphic2D.NativeDrawing
 * @since 12
 * @version 1.0
 */
/**
 * @addtogroup Drawing
 * @{
 *
 * @brief Provides functions such as 2D graphics rendering, text drawing, and image display.
 *
 * @since 8
 * @version 1.0
 */

#ifndef C_INCLUDE_DRAWING_GPU_CONTEXT_H
#define C_INCLUDE_DRAWING_GPU_CONTEXT_H

#include "drawing_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 用于创建一个使用OpenGL作为后端接口的图形处理器上下文对象。
 *
 * @param gpuContextOptions 图形处理器上下文选项{@link OH_Drawing_GpuContextOptions}。
 * @return 返回一个指针，指针指向创建的图形处理器上下文对象{@link OH_Drawing_GpuContext}。
 * @since 12
 * @version 1.0
 * @deprecated since 18
 * @useinstead OH_Drawing_GpuContextCreate
 */
OH_Drawing_GpuContext* OH_Drawing_GpuContextCreateFromGL(OH_Drawing_GpuContextOptions gpuContextOptions);

/**
 * @brief 用于创建一个图形处理器上下文对象, 使用的后端类型取决于运行设备。
 *
 * @return 返回一个指针，指针指向创建的图形处理器上下文对象{@link OH_Drawing_GpuContext}。
 * @since 16
 * @version 1.0
 */
OH_Drawing_GpuContext* OH_Drawing_GpuContextCreate(void);

/**
 * @brief 用于销毁图形处理器上下文对象并回收该对象占用的内存。
 *
 * @param gpuContext 指向图形处理器上下文对象的指针{@link OH_Drawing_GpuContext}。
 * @since 12
 * @version 1.0
 */
void OH_Drawing_GpuContextDestroy(OH_Drawing_GpuContext* gpuContext);

/**
 * @brief This struct describes the options about the GPU context.
 *  
 * @since 12
 * @version 1.0
 * @deprecated since 18
 */
typedef struct {
    /**
     * Whether to allow path mask textures to be cached. The value **true** means to allow the path mask textures to be
     * cached, and **false** means the opposite.
     */
    bool allowPathMaskCaching;
} OH_Drawing_GpuContextOptions;

#ifdef __cplusplus
}
#endif
/** @} */
#endif