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
 * @addtogroup netstack
 * @{
 *
 * @brief Provides C APIs for the SSL/TLS certificate chain verification module.
 *
 * @since 11
 * @version 1.0
 */

/**
 * @file net_ssl_c.h
 *
 * @brief Defines C APIs for the SSL/TLS certificate chain verification module.
 *
 * @library libnet_ssl.so
 * @kit NetworkKit
 * @syscap SystemCapability.Communication.NetStack
 * @since 11
 * @version 1.0
 */

#ifndef NET_SSL_C_H
#define NET_SSL_C_H

#include "net_ssl_c_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Provides certificate chain verification APIs for external systems.
 *
 * @param cert Certificate to be verified.
 * @param caCert CA certificate specified by the user. If this parameter is left blank, the preset certificate is used.
 * @return 0 - success.
 * 2305001 - Unspecified error.
 * 2305002 - Unable to get issuer certificate.
 * 2305003 - Unable to get certificate revocation list (CRL).
 * 2305004 - Unable to decrypt certificate signature.
 * 2305005 - Unable to decrypt CRL signature.
 * 2305006 - Unable to decode issuer public key.
 * 2305007 - Certificate signature failure.
 * 2305008 - CRL signature failure.
 * 2305009 - Certificate is not yet valid.
 * 2305010 - Certificate has expired.
 * 2305011 - CRL is not yet valid.
 * 2305012 - CRL has expired.
 * 2305023 - Certificate has been revoked.
 * 2305024 - Invalid certificate authority (CA).
 * 2305027 - Certificate is untrusted.
 * @syscap SystemCapability.Communication.NetStack
 * @since 11
 * @version 1.0
 */
uint32_t OH_NetStack_CertVerification(const struct NetStack_CertBlob *cert, const struct NetStack_CertBlob *caCert);

/**
 * @brief Gets pin set for hostname.
 *
 * @param hostname Hostname.
 * @param pin Certificate lock information.
 * @return 0 - Success.
 *         401 - Parameter error.
 *         2305999 - Out of memory.
 * @syscap SystemCapability.Communication.NetStack
 * @since 12
 * @version 1.0
 */
int32_t OH_NetStack_GetPinSetForHostName(const char *hostname, NetStack_CertificatePinning *pin);

/**
 * @brief Gets certificates for hostname.
 *
 * @param hostname Hostname.
 * @param certs Certificate Information.
 * @return 0 - Success.
 *         401 - Parameter error.
 *         2305999 - Out of memory.
 * @syscap SystemCapability.Communication.NetStack
 * @since 12
 * @version 1.0
 */
int32_t OH_NetStack_GetCertificatesForHostName(const char *hostname, NetStack_Certificates *certs);

/**
 * @brief Frees content of the certificates.
 *
 * @param certs Certificate.
 * @syscap SystemCapability.Communication.NetStack
 * @since 12
 * @version 1.0
 */
void OH_Netstack_DestroyCertificatesContent(NetStack_Certificates *certs);

/**
 * @brief Checks whether the Cleartext traffic is permitted.
 *
 * @permission ohos.permission.INTERNET
 * @return 0 - Success.
 *         201 - Permission denied.
 *         401 - Parameter error.
 * @param isCleartextPermitted Indicates output parameter,
 *        {@code true} if the Cleartext traffic is permitted, {@code false} otherwise.
 * @since 18
 */
int32_t OH_Netstack_IsCleartextPermitted(bool *isCleartextPermitted);
 
 
/**
 * @brief Checks whether the Cleartext traffic for a specified hostname is permitted.
 *
 * @permission ohos.permission.INTERNET
 * @return 0 - Success.
 *         201 - Permission denied.
 *         401 - Parameter error.
 * @param hostname Indicates the host name.
 * @param isCleartextPermitted Indicates output parameter,
 *        {@code true} if the Cleartext traffic for a specified hostname is permitted, {@code false} otherwise.
 * @since 18
 */
int32_t OH_Netstack_IsCleartextPermittedByHostName(const char *hostname, bool *isCleartextPermitted);


/**
 * @brief Checks whether the component is configured for Cleartext traffic interception.
 *
 * @return 0 - Success.
 *         2100001 - Invalid parameter value.
 * @param component Indicates the component name.
 * @param componentCfg Indicates output parameter,
 *        {@code true} if the component is configured for Cleartext traffic interception, {@code false} otherwise.
 * @since 20
 */
int32_t OH_Netstack_IsCleartextCfgByComponent(const char *component, bool *componentCfg);

#ifdef __cplusplus
}
#endif

/** @} */
#endif // NET_SSL_C_H
