/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License"),
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
 * @addtogroup TeeTrusted
 * @{
 *
 * @brief TEE(Trusted Excution Environment) API.
 * Provides security capability APIs such as trusted storage, encryption and decryption,
 * and trusted time for trusted application development.
 *
 * @since 20
 */

/**
 * @file tee_log.h
 *
 * @brief Provides TEE log APIs.
 *
 * Reference of TEE log APIs and internal definitions.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef __TEE_LOG_H
#define __TEE_LOG_H

#include "tee_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the ERROR level of the TA log.
 *
 * @since 20
 */
#define TA_LOG_LEVEL_ERROR   0

/**
 * @brief Defines the WARNING level of the TA log.
 *
 * @since 20
 */
#define TA_LOG_LEVEL_WARNING 1

/**
 * @brief Defines the INFO level of the TA log.
 *
 * @since 20
 */
#define TA_LOG_LEVEL_INFO    2

/**
 * @brief Defines the DEBUG level of the TA log.
 *
 * @since 20
 */
#define TA_LOG_LEVEL_DEBUG   3

/**
 * @brief Defines the VERBO level of the TA log.
 *
 * @since 20
 */
#define TA_LOG_LEVEL_VERBO   4

/**
 * @brief Defines the default level of the TA log.
 *
 * @since 20
 */
#define TA_LOG_LEVEL_DEFAULT  TA_LOG_LEVEL_INFO

#ifndef TA_LOG_LEVEL
/**
 * @brief Defines the default level of the TA log.
 * {@code TA_LOG_LEVEL} can be redefined by TA developers
 *
 * @since 20
 */
#define TA_LOG_LEVEL TA_LOG_LEVEL_DEFAULT
#endif

/**
 * @brief Defines the tag of the VERBO level TA log.
 *
 * @since 20
 */
#define TAG_VERB  "[verb]"

/**
 * @brief Defines the tag of the DEBUG level TA log.
 *
 * @since 20
 */
#define TAG_DEBUG "[debug]"

/**
 * @brief Defines the tag of the INFO level TA log.
 *
 * @since 20
 */
#define TAG_INFO  "[info]"

/**
 * @brief Defines the tag of the WARNING level TA log.
 *
 * @since 20
 */
#define TAG_WARN  "[warn]"

/**
 * @brief Defines the tag of the ERROR level TA log.
 *
 * @since 20
 */
#define TAG_ERROR "[error]"

/**
 * @brief Enumerates the levels of the log.
 *
 * @since 20
 */
typedef enum {
    /** Error level log. */
    LOG_LEVEL_ERROR = 0,
    /** Warning level log. */
    LOG_LEVEL_WARN  = 1,
    /** Information level log. */
    LOG_LEVEL_INFO  = 2,
    /** Debug level log. */
    LOG_LEVEL_DEBUG = 3,
    /** Verbose level log. */
    LOG_LEVEL_VERBO = 4,
    /** On level log. */
    LOG_LEVEL_ON    = 5,
} LOG_LEVEL;

/**
 * @brief Provides to print UART logs.
 *
 * @param fmt [IN] The log information.
 *
 * @since 20
 */
void uart_cprintf(const char *fmt, ...);

/**
 * @brief Provides to print UART logs.
 *
 * @param fmt [IN] The log information.
 *
 * @since 20
 */
void uart_printf_func(const char *fmt, ...);

/**
 * @brief Provides to print TEE logs.
 *
 * @param log_level [IN] The level of the log.
 * @param fmt [IN] The log information.
 *
 * @since 20
 */
void tee_print(LOG_LEVEL log_level, const char *fmt, ...);

/**
 * @brief Provides to print TEE driver logs.
 *
 * @param log_level [IN] The level of the log.
 * @param log_tag [IN] The tag of the log.
 * @param fmt [IN] The log information.
 *
 * @since 20
 */
void tee_print_driver(LOG_LEVEL log_level, const char *log_tag, const char *fmt, ...);

/**
 * @brief Defines the debug prefix string.
 *
 * @since 20
 */
extern const char *g_debug_prefix;

#if (TA_LOG_LEVEL >= TA_LOG_LEVEL_VERBO)
#ifdef DRIVER_LOG_TAG
/**
 * @brief Defines the API to print TEE log at the VERBO level.
 *
 * @since 20
 */
#define tlogv(fmt, args...) \
    tee_print_driver(LOG_LEVEL_VERBO, DRIVER_LOG_TAG, "%s %d:" fmt "", TAG_VERB, __LINE__, ##args)
#else
/**
 * @brief Defines the API to print TEE log at the VERBO level.
 *
 * @since 20
 */
#define tlogv(fmt, args...) tee_print(LOG_LEVEL_VERBO, "%s %d:" fmt "", TAG_VERB, __LINE__, ##args)
#endif /* DRIVER_LOG_TAG */
#else
/**
 * @brief Defines the API to print TEE log at the VERBO level.
 *
 * @since 20
 */
#define tlogv(fmt, args...) \
    do {                    \
    } while (0)
#endif /* TA_LOG_LEVEL >= TA_LOG_LEVEL_VERBO */

#if (TA_LOG_LEVEL >= TA_LOG_LEVEL_DEBUG)
#ifdef DRIVER_LOG_TAG
/**
 * @brief Defines the API to print TEE log at the DEBUG level.
 *
 * @since 20
 */
#define tlogd(fmt, args...) \
    tee_print_driver(LOG_LEVEL_DEBUG, DRIVER_LOG_TAG, "%s %d:" fmt "", TAG_DEBUG, __LINE__, ##args)
#else
/**
 * @brief Defines the API to print TEE log at the DEBUG level.
 *
 * @since 20
 */
#define tlogd(fmt, args...) tee_print(LOG_LEVEL_DEBUG, "%s %d:" fmt "", TAG_DEBUG, __LINE__, ##args)
#endif /* DRIVER_LOG_TAG */
#else
/**
 * @brief Defines the API to print TEE log at the DEBUG level.
 *
 * @since 20
 */
#define tlogd(fmt, args...) \
    do {                    \
    } while (0)
#endif /* TA_LOG_LEVEL >= TA_LOG_LEVEL_DEBUG */

#if (TA_LOG_LEVEL >= TA_LOG_LEVEL_INFO)
#ifdef DRIVER_LOG_TAG
/**
 * @brief Defines the API to print TEE log at the INFO level.
 *
 * @since 20
 */
#define tlogi(fmt, args...) \
    tee_print_driver(LOG_LEVEL_INFO, DRIVER_LOG_TAG, "%s %d:" fmt "", TAG_INFO, __LINE__, ##args)
#else
/**
 * @brief Defines the API to print TEE log at the INFO level.
 *
 * @since 20
 */
#define tlogi(fmt, args...) tee_print(LOG_LEVEL_INFO, "%s %d:" fmt "", TAG_INFO, __LINE__, ##args)
#endif /* DRIVER_LOG_TAG */
#else
/**
 * @brief Defines the API to print TEE log at the INFO level.
 *
 * @since 20
 */
#define tlogi(fmt, args...) \
    do {                    \
    } while (0)
#endif /* TA_LOG_LEVEL >= TA_LOG_LEVEL_INFO */

#if (TA_LOG_LEVEL >= TA_LOG_LEVEL_WARNING)
#ifdef DRIVER_LOG_TAG
/**
 * @brief Defines the API to print TEE log at the WARNING level.
 *
 * @since 20
 */
#define tlogw(fmt, args...) \
    tee_print_driver(LOG_LEVEL_WARN, DRIVER_LOG_TAG, "%s %d:" fmt "", TAG_WARN, __LINE__, ##args)
#else
/**
 * @brief Defines the API to print TEE log at the WARNING level.
 *
 * @since 20
 */
#define tlogw(fmt, args...) tee_print(LOG_LEVEL_WARN, "%s %d:" fmt "", TAG_WARN, __LINE__, ##args)
#endif /* DRIVER_LOG_TAG */
#else
/**
 * @brief Defines the API to print TEE log at the WARNING level.
 *
 * @since 20
 */
#define tlogw(fmt, args...) \
    do {                    \
    } while (0)
#endif /* TA_LOG_LEVEL >= TA_LOG_LEVEL_WARNING */

#if (TA_LOG_LEVEL >= TA_LOG_LEVEL_ERROR) /* Always meet this condition. */
#ifndef TLOGE_NO_TIMESTAMP
#ifdef DRIVER_LOG_TAG
/**
 * @brief Defines the API to print TEE log at the ERROR level.
 *
 * @since 20
 */
#define tloge(fmt, args...) \
    tee_print_driver(LOG_LEVEL_ERROR, DRIVER_LOG_TAG, "%s %d:" fmt " ", TAG_ERROR, __LINE__, ##args)
#else
/**
 * @brief Defines the API to print TEE log at the ERROR level.
 *
 * @since 20
 */
#define tloge(fmt, args...) tee_print(LOG_LEVEL_ERROR, "%s %d:" fmt " ", TAG_ERROR, __LINE__, ##args)
#endif /* DRIVER_LOG_TAG */
#else
/**
 * @brief Defines the API to print TEE log at the ERROR level.
 *
 * @since 20
 */
#define tloge(fmt, args...) printf("[%s] %s %d:" fmt " ", g_debug_prefix, TAG_ERROR, __LINE__, ##args)
#endif /* TLOGE_NO_TIMESTAMP */
#else
/**
 * @brief Defines the API to print TEE log at the ERROR level.
 *
 * @since 20
 */
#define tloge(fmt, args...) \
    do {                    \
    } while (0)
#endif /* TA_LOG_LEVEL >= TA_LOG_LEVEL_ERROR */

/**
 * @brief Defines an enum for system events.
 *
 * @since 20
 */
typedef enum {
    /** Fault event. */
    FAULT = 1,
    /** Statistics event. */
    STATISTIC  = 2,
    /** Security event. */
    SECURITY  = 3,
    /** Behavior event. */
    BEHAVIOR = 4,
} HISYSEVENT_TYPE;

/**
 * @brief Reports DFX messages to HiViewOcean.
 *
 * @param domain Domain name of a message.
 * @param event Event name of a message.
 * @param event_type Event type of a message.
 * @param fmt Format of a logged message.
 *
 * @since 20
 */

void tee_report(const char *domain, const char *event, HISYSEVENT_TYPE event_type, const char *fmt, ...);


#ifdef __cplusplus
}
#endif

#endif /* __TEE_LOG_H */
/** @} */