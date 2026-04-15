/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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
 * @file native_cencinfo.h
 *
 * @brief The file declares the native APIs used to set decryption parameters.
 * 
 * @kit AVCodecKit
 * @library libnative_media_avcencinfo.so
 * @syscap SystemCapability.Multimedia.Media.Spliter
 * @since 12
 */
/**
 * @addtogroup Multimedia_Drm
 * @{
 *
 * @brief This feature enables third-party applications to implement the
 * media decapsulation and demultiplexing functions by themselves instead
 * of using the functions provided by the system.
 *
 * After the DRM instance and session are created, the decryption interface
 * provided by the DRM can be invoked for decryption. The decryption parameter
 * structure defines the transmission format of decryption parameters.
 *
 * @since 12
 */

#ifndef NATIVE_AVCENCINFO_H
#define NATIVE_AVCENCINFO_H

#include <stdint.h>
#include "native_averrors.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 为媒体内存接口定义native层对象。
 * 
 * @since 12
 * @version 1.0
 */
typedef struct OH_AVBuffer OH_AVBuffer;
/**
 * @brief AVCencInfo结构。
 * 
 * @since 12
 * @version 1.0
 */
typedef struct OH_AVCencInfo OH_AVCencInfo;

/**
 * @brief Drm CENC算法类型。
 * 
 * @since 12
 * @version 1.0
 */
typedef enum DrmCencAlgorithm {
    /**
     * 不加密算法。
     */
    DRM_ALG_CENC_UNENCRYPTED = 0x0,
    /**
     * AES CTR算法。
     */
    DRM_ALG_CENC_AES_CTR = 0x1,
    /**
     * AES WV算法。
     */
    DRM_ALG_CENC_AES_WV = 0x2,
    /**
     * AES CBC算法。
     */
    DRM_ALG_CENC_AES_CBC = 0x3,
    /**
     * SM4 CBC算法。
     */
    DRM_ALG_CENC_SM4_CBC = 0x4,
    /**
     * SM4 CTR算法。
     */
    DRM_ALG_CENC_SM4_CTR = 0x5
} DrmCencAlgorithm;

/**
 * @brief 枚举类型，表示cencInfo中keyId/iv/subsample信息是否设置。
 * 
 * @since 12
 * @version 1.0
 */
typedef enum DrmCencInfoMode {
    /* key/iv/subsample set. */
    DRM_CENC_INFO_KEY_IV_SUBSAMPLES_SET = 0x0,
    /* key/iv/subsample not set. */
    DRM_CENC_INFO_KEY_IV_SUBSAMPLES_NOT_SET = 0x1
} DrmCencInfoMode;

/**
 * @brief The struct describes the subsample type.
 * 
 * @since 12
 * @version 1.0
 */
typedef struct DrmSubsample {
    /* Clear header len. */
    uint32_t clearHeaderLen;
    /* Payload Len. */
    uint32_t payLoadLen;
} DrmSubsample;

/**
 * @brief 创建用于设置cencInfo的OH_AVCencInfo实例。
 *
 * @return 返回新创建的OH_AVCencInfo对象。如果返回nullptr，则表示创建对象失败。
 *     <br>可能失败的原因：应用程序地址空间已满，或者对象中的数据初始化失败。
 * @since 12
 * @version 1.0
 */
OH_AVCencInfo *OH_AVCencInfo_Create();

/**
 * @brief 销毁OH_AVCencInfo实例并释放内部资源。
 *
 * 同一个实例只能销毁一次。在再次创建实例之前，不应使用该实例。建议在实例销毁成功后立即将实例指针设置为nullptr。
 *
 * @param cencInfo 指向OH_AVCencInfo实例的指针。
 * @return AV_ERR_OK：执行成功。
 *     <br>AV_ERR_INVALID_VAL：cencInfo为空。
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_Destroy(OH_AVCencInfo *cencInfo);

/**
 * @brief 设置cencInfo加密算法。
 *
 * @param cencInfo 指向OH_AVCencInfo实例的指针。
 * @param algo 加密算法模式。
 * @return AV_ERR_OK：执行成功。
 *     <br>AV_ERR_INVALID_VAL：cencInfo为空。
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetAlgorithm(OH_AVCencInfo *cencInfo, enum DrmCencAlgorithm algo);

/**
 * @brief 设置cencInfo的keyId和iv。
 *
 * @param cencInfo 指向OH_AVCencInfo实例的指针。
 * @param keyId Key标识。
 * @param keyIdLen Key标识长度。
 * @param iv 初始化向量。
 * @param ivLen 初始化向量长度。
 * @return AV_ERR_OK：执行成功。
 *     <br>AV_ERR_INVALID_VAL：cencInfo为空、keyId为空、keyIdLen != DRM_KEY_ID_SIZE、iv是空、ivLen != DRM_KEY_IV_SIZE、keyId拷贝失败，或者iv拷贝失败。
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetKeyIdAndIv(OH_AVCencInfo *cencInfo, uint8_t *keyId,
    uint32_t keyIdLen, uint8_t *iv, uint32_t ivLen);

/**
 * @brief 设置cencInfo的subsamples信息。
 *
 * @param cencInfo 指向OH_AVCencInfo实例的指针。
 * @param encryptedBlockCount 加密块的数量。
 * @param skippedBlockCount 不加密块的数量。
 * @param firstEncryptedOffset 第一个加密有效负载的偏移量。
 * @param subsampleCount Subsample数量。
 * @param subsamples Subsample内容集。
 * @return AV_ERR_OK：执行成功。
 *     <br>AV_ERR_INVALID_VAL：cencInfo为空、subsampleCount > DRM_KEY_MAX_SUB_SAMPLE_NUM，或者subsamples为空。
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetSubsampleInfo(OH_AVCencInfo *cencInfo, uint32_t encryptedBlockCount,
    uint32_t skippedBlockCount, uint32_t firstEncryptedOffset, uint32_t subsampleCount, DrmSubsample *subsamples);

/**
 * @brief 设置cencInfo的模式。
 *
 * @param cencInfo 指向OH_AVCencInfo实例的指针。
 * @param mode cencInfo模式，指示是否设置了keyId/iv/subsample。
 * @return AV_ERR_OK：执行成功。
 *     <br>AV_ERR_INVALID_VAL：cencInfo为空。
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetMode(OH_AVCencInfo *cencInfo, enum DrmCencInfoMode mode);

/**
 * @brief 将cencInfo设置到AVBuffer。
 *
 * @param cencInfo 指向OH_AVCencInfo实例的指针。
 * @param buffer 携带数据的帧buffer。
 * @return AV_ERR_OK：执行成功。
 *     <br>AV_ERR_INVALID_VAL：cencInfo为空、buffer为空、buffer->buffer_为空，或者buffer->buffer_->meta_为空。
 * @since 12
 * @version 1.0
 */
OH_AVErrCode OH_AVCencInfo_SetAVBuffer(OH_AVCencInfo *cencInfo, OH_AVBuffer *buffer);
/**
 * @brief The length of the key ID is 16 bytes.
 * 
 * @since 12
 * @version 1.0
 */
#define DRM_KEY_ID_SIZE 16
/**
 * @brief The length of the Initialization Vector (IV) is 16 bytes.
 * 
 * @since 12
 * @version 1.0
 */
#define DRM_KEY_IV_SIZE 16
/**
 * @brief The maximum number of subsamples is 64.
 * 
 * @since 12
 * @version 1.0
 */
#define DRM_KEY_MAX_SUB_SAMPLE_NUM 64

#ifdef __cplusplus
}
#endif

#endif // NATIVE_AVCENCINFO_H
/** @} */