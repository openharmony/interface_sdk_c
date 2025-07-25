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
 * @file tee_crypto_hal.h
 *
 * @brief Provides APIs for cryptographic operations.
 *
 * You can use these APIs to implement encryption and decryption.
 *
 * @library NA
 * @kit TEEKit
 * @syscap SystemCapability.Tee.TeeClient
 * @since 20
 */

#ifndef TEE_CRYPTO_HAL_H
#define TEE_CRYPTO_HAL_H

#include "tee_crypto_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumerates the types of the crypto engine.
 *
 * @since 20
 */
enum CRYPTO_ENGINE {
     /** The hardware-based DX crypto engine. */
    DX_CRYPTO = 0,
    /** The hardware-based MSPE crypto engine. */
    EPS_CRYPTO = 1,
    /** The software-based crypto engine, such as OpenSSL. */
    SOFT_CRYPTO = 2,
    /** The SEC crypto engine, commonly employed in vehicle platforms. */
    SEC_CRYPTO = 3,
    /** The maximum value of the crypto engine. */
    CRYPTO_ENGINE_MAX = 1024,
};

/**
 * @brief Sets the encryption and decryption engines to an operation.
 *
 * @param operation Indicates the handle of the operation to set.
 * @param crypto Indicates the engines to set.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if <b>operation</b> is null or <b>crypto</b> is invalid.
 *
 * @since 20
 */
TEE_Result TEE_SetCryptoFlag(TEE_OperationHandle operation, uint32_t crypto);

/**
 * @brief Sets the encryption and decryption engines to an object.
 *
 * @param object Indicates the handle of the object to set.
 * @param crypto Indicates the engines to set.
 *
 * @return Returns <b>TEE_SUCCESS</b> if the operation is successful.
 *         Returns <b>TEE_ERROR_BAD_PARAMETERS</b> if <b>object</b> is null or <b>crypto</b> is invalid.
 *
 * @since 20
 */
TEE_Result TEE_SetObjectFlag(TEE_ObjectHandle object, uint32_t crypto);

#ifdef __cplusplus
}
#endif

#endif
/** @} */