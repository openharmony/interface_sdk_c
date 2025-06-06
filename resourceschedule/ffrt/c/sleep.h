/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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
 * @addtogroup FFRT
 * @{
 *
 * @brief Provides FFRT C APIs.
 *
 * @since 10
 */

/**
 * @file sleep.h
 *
 * @brief Declares the sleep and yield interfaces in C.
 *
 * @library libffrt.z.so
 * @kit FunctionFlowRuntimeKit
 * @syscap SystemCapability.Resourceschedule.Ffrt.Core
 * @since 10
 */

#ifndef FFRT_API_C_SLEEP_H
#define FFRT_API_C_SLEEP_H

#include <stdint.h>
#include "type_def.h"

/**
 * @brief Suspends the calling thread for a given duration.
 *
 * @param usec Indicates the duration that the calling thread is suspended, in microseconds.
 * @return Returns <b>ffrt_success</b> if the thread is suspended;
           returns <b>ffrt_error</b> otherwise.
 * @since 10
 */
FFRT_C_API int ffrt_usleep(uint64_t usec);

/**
 * @brief Passes control to other tasks so that they can be executed.
 *
 * @since 10
 */
FFRT_C_API void ffrt_yield(void);

#endif // FFRT_API_C_SLEEP_H
/** @} */