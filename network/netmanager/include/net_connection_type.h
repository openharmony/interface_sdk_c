/*
* Copyright (c) 2023 Huawei Device Co., Ltd.
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef NATIVE_NET_CONN_TYPE_H
#define NATIVE_NET_CONN_TYPE_H

/**
* @addtogroup NetConnection
* @{
*
* @brief Provides the data structures for the C APIs of the network connection module for network management.
*
* @since 11
* @version 1.0
*/

/**
* @file net_connection_type.h
* @brief Defines the data structures for the C APIs of the network connection module.
*
* @library libnet_connection.so
* @syscap SystemCapability.Communication.NetManager.Core
* @since 11
* @version 1.0
*
*/

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OH_NETCONN_MAX_NET_SIZE 32
#define OH_NETCONN_MAX_NET_SIZE 32
#define OH_NETCONN_MAX_BEAR_TYPE_SIZE 32
#define OH_NETCONN_MAX_CAP_SIZE 32
#define OH_NETCONN_MAX_ADDR_SIZE 32
#define OH_NETCONN_MAX_ROUTE_SIZE 64
#define OH_NETCONN_MAX_EXCLUSION_SIZE 256
#define OH_NETCONN_MAX_STR_LEN 256

/**
* @brief Defines network capabilities.
*
* @since 10
* @version 1.0
*/

typedef enum NetConn_NetCap {
    /* MMS */
    OH_NETCONN_NET_CAPABILITY_MMS = 0,
    /* Not Metered */
    OH_NETCONN_NET_CAPABILITY_NOT_METERED = 11,
    /* Internet */
    OH_NETCONN_NET_CAPABILITY_INTERNET = 12,
    /* Not VPN */
    OH_NETCONN_NET_CAPABILITY_NOT_VPN = 15,
    /* Validated */
    OH_NETCONN_NET_CAPABILITY_VALIDATED = 16,
} NetConn_NetCap;

/**
 * @brief Defines network bearer types.
 *
 * @since 11
 * @version 1.0
 */
typedef enum NetConn_NetBearType {
    /** Cellular network */
    OH_NETCONN_BEARER_CELLULAR = 0,
    /** WIFI */
    OH_NETCONN_BEARER_WIFI = 1,
    /** Ethernet */
    OH_NETCONN_BEARER_ETHERNET = 3,
} NetConn_NetBearType;

/**
* @brief Defines the network handle.
*
* @since 11
* @version 1.0
*/
typedef struct OH_NetConn_NetHandle {
    /** Network ID */
    int32_t netId;
} OH_NetConn_NetHandle;

/**
 * @brief Defines all network capabilities.
 *
 * @since 11
 * @version 1.0
 */
typedef struct NetConn_NetAllCapabilities {
    /** Uplink bandwidth */
    uint32_t linkUpBandwidthKbps;
    /** Downlink bandwidth */
    uint32_t linkDownBandwidthKbps;
    /** Network capability list */
    NetConn_NetCap netCaps[OH_NETCONN_MAX_CAP_SIZE];
    /** Actual size of the network capability list */
    int32_t netCapsSize;
    /** Bearer type list */
    NetConn_NetBearType bearerTypes[OH_NETCONN_MAX_BEAR_TYPE_SIZE];
    /** Actual size of the bearer type list */
    int32_t bearerTypesSize;
} NetConn_NetAllCapabilities;

/**
 * @brief Defines the network address.
 *
 * @since 11
 * @version 1.0
 */
typedef struct NetConn_INetAddr {
    /** Network address family */
    uint8_t family;
    /** Prefix length */
    uint8_t prefixlen;
    /** Port number */
    uint8_t port;
    /** Address */
    char address[OH_NETCONN_MAX_STR_LEN];
} NetConn_INetAddr;

/**
 * @brief Defines the route configuration information.
 *
 * @since 11
 * @version 1.0
 */
typedef struct NetConn_Route {
    /** Network interface */
    char iface[OH_NETCONN_MAX_STR_LEN];
    /** Destination address */
    NetConn_INetAddr destination;
    /** Gateway address */
    NetConn_INetAddr gateway;
    /** Gateway exists or not */
    int32_t hasGateway;
    /** Default route or not */
    int32_t isDefaultRoute;
} NetConn_Route;

/**
 * @brief Defines the proxy configuration information.
 *
 * @since 11
 * @version 1.0
 */
typedef struct NetConn_HttpProxy {
    /** Host name */
    char host[OH_NETCONN_MAX_STR_LEN];
    /** Exclusion list of proxy servers */
    char exclusionList[OH_NETCONN_MAX_EXCLUSION_SIZE][OH_NETCONN_MAX_STR_LEN];
    /** Actual size of the exclusion list */
    int32_t exclusionListSize;
    /** Port number */
    uint16_t port;
} NetConn_HttpProxy;

/**
 * @brief Defines the network link information.
 *
 * @since 11
 * @version 1.0
 */
typedef struct NetConn_NetLinkInfo {
    /** Network interface name */
    char ifaceName[OH_NETCONN_MAX_STR_LEN];
    /** Domain name of the network connection */
    char domain[OH_NETCONN_MAX_STR_LEN];
    /** TCP buffer size */
    char tcpBufferSizes[OH_NETCONN_MAX_STR_LEN];
    /** MTU */
    uint16_t mtu;
    /** Address list */
    NetConn_INetAddr netAddrList[OH_NETCONN_MAX_ADDR_SIZE];
    /** Actual size of the address list */
    int32_t netAddrListSize;
    /** DNS list */
    NetConn_INetAddr dnsList[OH_NETCONN_MAX_ADDR_SIZE];
    /** Actual size of the DNS list */
    int32_t dnsListSize;
    /** Route list */
    NetConn_Route routeList[OH_NETCONN_MAX_ROUTE_SIZE];
    /** Actual size of the route list */
    int32_t routeListSize;
    /** HTTP proxy information */
    NetConn_HttpProxy httpProxy;
} NetConn_NetLinkInfo;

/**
* @brief Defines the network handle list.
*
* @since 11
* @version 1.0
*/
typedef struct OH_NetConn_NetHandleList {
    /** Network handle list */
    OH_NetConn_NetHandle netHandles[OH_NETCONN_MAX_NET_SIZE];
    /** Actual size of the network handle list */
    int32_t netHandleListSize;
} OH_NetConn_NetHandleList;

/*
 * @brief Pointer to the custom DNS resolver.
 *
 * @param host The host name to query.
 * @param serv Service name.
 * @param hint Pointer to the addrinfo structure.
 * @param res Store DNS query results and return them in a linked list format.
 *
 * @since 11
 * @version 1.0
 */
typedef int (*OH_NetConn_CustomDnsResolver)(const char *host, const char *serv,
                                            const struct addrinfo *hint, struct addrinfo **res);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* NATIVE_NET_CONN_TYPE_H */