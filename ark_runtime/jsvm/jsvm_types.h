/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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
 * @addtogroup JSVM
 * @{
 *
 * @brief Provides the standard JavaScript engine capabilities.
 *
 * Provides API to Provide independent, standard, and complete JavaScript engine capabilities for developers,
 * including managing the engine lifecycle, compiling and running JS code, implementing JS/C++ cross language calls,
 * and taking snapshots.
 *
 * @since 11
 */

/**
 * @file jsvm_types.h
 *
 * @brief Provides the JSVM API type define.
 *
 * Provides API to Provide independent, standard, and complete JavaScript engine capabilities for developers,
 * including managing the engine lifecycle, compiling and running JS code, implementing JS/C++ cross language calls,
 * and taking snapshots.
 * @library libjsvm.so
 * @kit ArkTS
 * @syscap SystemCapability.ArkCompiler.JSVM
 * @since 11
 */

#ifndef ARK_RUNTIME_JSVM_JSVM_TYPE_H
#define ARK_RUNTIME_JSVM_JSVM_TYPE_H


#include <stddef.h>  // NOLINT(modernize-deprecated-headers)
#include <stdint.h>  // NOLINT(modernize-deprecated-headers)
#include <stdbool.h>  // NOLINT(modernize-deprecated-headers)

#if !defined __cplusplus || (defined(_MSC_VER) && _MSC_VER < 1900)
typedef uint16_t char16_t;
#endif

#ifndef JSVM_CDECL
#ifdef _WIN32
#define JSVM_CDECL __cdecl
#else
#define JSVM_CDECL
#endif
#endif

/**
 * @brief To represent a JavaScript VM instance.
 *
 * @since 11
 */
typedef struct JSVM_VM__* JSVM_VM;

/**
 * @brief To represent a JavaScript VM scope.
 *
 * @since 11
 */
typedef struct JSVM_VMScope__* JSVM_VMScope;

/**
 * @brief To represent a JavaScript VM environment scope.
 *
 * @since 11
 */
typedef struct JSVM_EnvScope__* JSVM_EnvScope;

/**
 * @brief To represent a JavaScript code.
 *
 * @since 11
 */
typedef struct JSVM_Script__* JSVM_Script;

/**
 * @brief To represent a JavaScript VM instance.
 *
 * @since 11
 */
typedef struct JSVM_Env__* JSVM_Env;

/**
 * @brief To represent a JavaScript profiler.
 *
 * @since 12
 */
typedef struct JSVM_CpuProfiler__* JSVM_CpuProfiler;

/**
 * @brief To represent a JavaScript VM environment.
 *
 * @since 11
 */
typedef struct JSVM_Value__* JSVM_Value;

/**
 * @brief To represent a JavaScript value references.
 *
 * @since 11
 */
typedef struct JSVM_Ref__* JSVM_Ref;

/**
 * @brief To represent a JavaScript VM handle scope.
 *
 * @since 11
 */
typedef struct JSVM_HandleScope__* JSVM_HandleScope;

/**
 * @brief To represent a JavaScript VM escapable handle scope.
 *
 * @since 11
 */
typedef struct JSVM_EscapableHandleScope__* JSVM_EscapableHandleScope;

/**
 * @brief To represent a JavaScript VM callback additional information.
 *
 * @since 11
 */
typedef struct JSVM_CallbackInfo__* JSVM_CallbackInfo;

/**
 * @brief To represent a JavaScript VM value deferred.
 *
 * @since 11
 */
typedef struct JSVM_Deferred__* JSVM_Deferred;


/**
 * @brief Callback function pointer and data for user-provided native function which are to exposed to js via JSVM-API.
 *
 * @since 11
 */
typedef struct {
    JSVM_Value(JSVM_CDECL* callback)(JSVM_Env env,
                                   JSVM_CallbackInfo info);
    void* data;
} JSVM_CallbackStruct;

/**
 * @brief Function pointer type for user-provided native function which are to exposed to js via JSVM-API.
 *
 * @since 11
 */
typedef JSVM_CallbackStruct* JSVM_Callback;

/**
 * @brief Function pointer type for add-on provided function that allow the user to be notified.
 *
 * @since 11
 */
typedef void(JSVM_CDECL* JSVM_Finalize)(JSVM_Env env,
                                        void* finalizeData,
                                        void* finalizeHint);

/**
 * @brief Function pointer type for callback of ASCII output stream. The first parameter data is the data pointer.
 * And the second parameter size is the data size to output. A null data pointer indicates the end of the stream.
 * The third parameter streamData is the pointer passed in together with the callback to the API functions that
 * generate data to the output stream. The callback returns true to indicate the stream can continue to accept
 * data. Otherwise, it will abort the stream.
 *
 * @since 12
 */
typedef bool(JSVM_CDECL* JSVM_OutputStream)(const char* data,
                                            int size,
                                            void* streamData);

/**
 * @brief JSVM_PropertyAttributes are flag used to control the behavior of properties set on a js object.
 *
 * @since 11
 */
typedef enum {
    /** No explicit attributes are set on the property. */
    JSVM_DEFAULT = 0,
    /** The property is writable. */
    JSVM_WRITABLE = 1 << 0,
    /** The property is enumeable. */
    JSVM_ENUMERABLE = 1 << 1,
    /** The property is configurable. */
    JSVM_CONFIGURABLE = 1 << 2,
    /** Used to mark the receiver of a native method need not be checked.
     *  If JSVM_NO_RECEIVER_CHECK is not set, the method only accept instance of the defined class as receiver,
     *  Otherwise Exception "Type Error: Illegal Ivocation" will be throw into JSVM.
    */
    JSVM_NO_RECEIVER_CHECK = 1 << 3,
    /** Used with OH_JSVM_DefineClass to distinguish static properties from instance properties. */
    JSVM_STATIC = 1 << 10,
    /** Default for class methods. */
    JSVM_DEFAULT_METHOD = JSVM_WRITABLE | JSVM_CONFIGURABLE,
    /** Class method with no receiver check*/
    JSVM_METHOD_NO_RECEIVER_CHECK = JSVM_DEFAULT_METHOD | JSVM_NO_RECEIVER_CHECK,
    /** Default for object properties, like in JS obj[prop]. */
    JSVM_DEFAULT_JSPROPERTY = JSVM_WRITABLE | JSVM_ENUMERABLE | JSVM_CONFIGURABLE,
    /** Object properties with no receiver check*/
    JSVM_JSPROPERTY_NO_RECEIVER_CHECK = JSVM_DEFAULT_JSPROPERTY | JSVM_NO_RECEIVER_CHECK,
} JSVM_PropertyAttributes;

/**
 * @brief Describes the type of a JSVM_Value.
 *
 * @since 11
 */
typedef enum {
    /** undefined type. */
    JSVM_UNDEFINED,
    /** null type. */
    JSVM_NULL,
    /** boolean type. */
    JSVM_BOOLEAN,
    /** number type. */
    JSVM_NUMBER,
    /** string type. */
    JSVM_STRING,
    /** symbol type. */
    JSVM_SYMBOL,
    /** object type. */
    JSVM_OBJECT,
    /** function type. */
    JSVM_FUNCTION,
    /** external type. */
    JSVM_EXTERNAL,
    /** bigint type. */
    JSVM_BIGINT,
} JSVM_ValueType;

/**
 * @brief Describes the type of a typedarray.
 *
 * @since 11
 */
typedef enum {
    /** int8 type. */
    JSVM_INT8_ARRAY,
    /** uint8 type. */
    JSVM_UINT8_ARRAY,
    /** uint8 clamped type. */
    JSVM_UINT8_CLAMPED_ARRAY,
    /** int16 type. */
    JSVM_INT16_ARRAY,
    /** uint16 type. */
    JSVM_UINT16_ARRAY,
    /** int32 type. */
    JSVM_INT32_ARRAY,
    /** uint32 type. */
    JSVM_UINT32_ARRAY,
    /** float32 type. */
    JSVM_FLOAT32_ARRAY,
    /** float64 type. */
    JSVM_FLOAT64_ARRAY,
    /** bigint64 type. */
    JSVM_BIGINT64_ARRAY,
    /** biguint64 type. */
    JSVM_BIGUINT64_ARRAY,
} JSVM_TypedarrayType;

/**
 * @brief Integral status code indicating the success or failure of a JSVM-API call.
 *
 * @since 11
 */
typedef enum {
    /** success status. */
    JSVM_OK,
    /** invalidarg status. */
    JSVM_INVALID_ARG,
    /** object expected status. */
    JSVM_OBJECT_EXPECTED,
    /** string expected status. */
    JSVM_STRING_EXPECTED,
    /** name expected status. */
    JSVM_NAME_EXPECTED,
    /** function expected status. */
    JSVM_FUNCTION_EXPECTED,
    /** number expected status. */
    JSVM_NUMBER_EXPECTED,
    /** boolean expected status. */
    JSVM_BOOLEAN_EXPECTED,
    /** array expected status. */
    JSVM_ARRAY_EXPECTED,
    /** generic failure status. */
    JSVM_GENERIC_FAILURE,
    /** pending exception status. */
    JSVM_PENDING_EXCEPTION,
    /** cancelled status. */
    JSVM_CANCELLED,
    /** escape called twice status. */
    JSVM_ESCAPE_CALLED_TWICE,
    /** handle scope mismatch status. */
    JSVM_HANDLE_SCOPE_MISMATCH,
    /** callback scope mismatch status. */
    JSVM_CALLBACK_SCOPE_MISMATCH,
    /** queue full status. */
    JSVM_QUEUE_FULL,
    /** closing status. */
    JSVM_CLOSING,
    /** bigint expected status. */
    JSVM_BIGINT_EXPECTED,
    /** date expected status. */
    JSVM_DATE_EXPECTED,
    /** arraybuffer expected status. */
    JSVM_ARRAYBUFFER_EXPECTED,
    /** detachable arraybuffer expected status. */
    JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED,
    /** would deadlock status. */
    JSVM_WOULD_DEADLOCK,
    /** no external buffers allowed status. */
    JSVM_NO_EXTERNAL_BUFFERS_ALLOWED,
    /** cannot run +js status. */
    JSVM_CANNOT_RUN_JS,
    /** invalid input type status.
     * @since 18
     */
    JSVM_INVALID_TYPE,
    /** jit mode expected status.
     * @since 18
     */
    JSVM_JIT_MODE_EXPECTED,
} JSVM_Status;

/**
 * @brief  limits the range of collected properties..
 *
 * @since 11
 */
typedef enum {
    /** will include all keys of the objects's prototype chain as well. */
    JSVM_KEY_INCLUDE_PROTOTYPES,
    /** limits the collected properties to the given object only. */
    JSVM_KEY_OWN_ONLY
} JSVM_KeyCollectionMode;

/**
 * @brief Property filter bits. They can be or'ed to build a composite filter..
 *
 * @since 11
 */
typedef enum {
    /** key all properties. */
    JSVM_KEY_ALL_PROPERTIES = 0,
    /** key writable. */
    JSVM_KEY_WRITABLE = 1,
    /** key enumerable. */
    JSVM_KEY_ENUMERABLE = 1 << 1,
    /** key configurable. */
    JSVM_KEY_CONFIGURABLE = 1 << 2,
    /** key skip strings. */
    JSVM_KEY_SKIP_STRINGS = 1 << 3,
    /** key skip symbols. */
    JSVM_KEY_SKIP_SYMBOLS = 1 << 4
} JSVM_KeyFilter;

/**
 * @brief key conversion select.
 *
 * @since 11
 */
typedef enum {
    /** will return numbers for integer indices. */
    JSVM_KEY_KEEP_NUMBERS,
    /**  will convert integer indices to strings. */
    JSVM_KEY_NUMBERS_TO_STRINGS
} JSVM_KeyConversion;

/**
 * @brief Memory pressure level.
 *
 * @since 11
 */
typedef enum {
    /** none pressure. */
    JSVM_MEMORY_PRESSURE_LEVEL_NONE,
    /** moderate pressure. */
    JSVM_MEMORY_PRESSURE_LEVEL_MODERATE,
    /** critical pressure. */
    JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL,
} JSVM_MemoryPressureLevel;

/**
 *
 * @brief Compile mode
 *
 * @since 12
 */
typedef enum {
    /** default mode. */
    JSVM_COMPILE_MODE_DEFAULT,
    /** consume code cache. */
    JSVM_COMPILE_MODE_CONSUME_CODE_CACHE,
    /** apply eager compile. */
    JSVM_COMPILE_MODE_EAGER_COMPILE,
    /** preset for compile profile. */
    JSVM_COMPILE_MODE_PRODUCE_COMPILE_PROFILE,
    /** consume compile profile. */
    JSVM_COMPILE_MODE_CONSUME_COMPILE_PROFILE,
} JSVM_CompileMode;

/**
 * @brief Compile option id
 *
 * @since 12
 */
typedef enum {
    /** compile mode. */
    JSVM_COMPILE_MODE,
    /** code cache content. */
    JSVM_COMPILE_CODE_CACHE,
    /** script origin. */
    JSVM_COMPILE_SCRIPT_ORIGIN,
    /** compile profile content. */
    JSVM_COMPILE_COMPILE_PROFILE,
    /** switch for source map support. */
    JSVM_COMPILE_ENABLE_SOURCE_MAP,
} JSVM_CompileOptionId;

/**
 * @brief Heap statisics.
 *
 * @since 12
 */
typedef struct {
    /** the size of the total heap. */
    size_t totalHeapSize;
    /** the executable size of the total heap. */
    size_t totalHeapSizeExecutable;
    /** the physical size of the total heap. */
    size_t totalPhysicalSize;
    /** the available size of the total heap. */
    size_t totalAvailableSize;
    /** used size of the heap. */
    size_t usedHeapSize;
    /** heap size limit. */
    size_t heapSizeLimit;
    /** memory requested by the heap. */
    size_t mallocedMemory;
    /** heap-requested external memory. */
    size_t externalMemory;
    /** peak memory requested by the heap. */
    size_t peakMallocedMemory;
    /** the number of native contexts. */
    size_t numberOfNativeContexts;
    /** the number of detached contexts. */
    size_t numberOfDetachedContexts;
    /** the size of the total global handles. */
    size_t totalGlobalHandlesSize;
    /** the size of the used global handles. */
    size_t usedGlobalHandlesSize;
} JSVM_HeapStatistics;

/**
 * @brief Init the JavaScript VM with init option.
 *
 * @since 11
 */
typedef struct {
    /**
     * Optional nullptr-terminated array of raw adddresses in the embedder that the
     * VM can match against during serialization and use for deserialization. This
     * array and its content must stay valid for the entire lifetime of the VM
     * instance.
    */
    const intptr_t* externalReferences;

    /**
     * Flags for the VM. IF removeFlags is true, recognized flags will be removed
     * from (argc, argv). Note that these flags are specific to VM.
     * They are mainly used for development. Do not include them in production as
     * they might not take effect if the VM is different from the development
     * environment.
     */
    int* argc;
    /** argv . */
    char** argv;
    /** remove flags. */
    bool removeFlags;
} JSVM_InitOptions;

/**
 * @brief Create the JavaScript VM with init option.
 *
 * @since 11
 */
typedef struct {
    /** optional limits of memory use of the vm. */
    size_t maxOldGenerationSize;
    /** optional limits of memory use of the vm. */
    size_t maxYoungGenerationSize;
    /** optional limits of memory use of the vm. */
    size_t initialOldGenerationSize;
    /** optional limits of memory use of the vm. */
    size_t initialYoungGenerationSize;
    /** Optional startup snapshot data. */
    const char* snapshotBlobData;
    /** Optional size of the startup snapshot data. */
    size_t snapshotBlobSize;
    /** Whether the VM is used for creating snapshot. */
    bool isForSnapshotting;
} JSVM_CreateVMOptions;

/**
 * @brief JavaScript VM info.
 *
 * @since 11
 */
typedef struct {
    /** The highest API version this VM supports. */
    uint32_t apiVersion;
    /** The engine name implementing the VM. */
    const char* engine;
    /** The version of the VM. */
    const char* version;
    /** The cached data version tag. */
    uint32_t cachedDataVersionTag;
} JSVM_VMInfo;

/**
 * @brief Property descriptor.
 *
 * @since 11
 */
typedef struct {
    /** Optional string describing the key for the property, encoded as UTF8.
     * One of utf8name or name must be provided for the property.
     */
    const char* utf8name;
    /** Optional value that points to a JavaScript string or symbol to be used as the key for the property. */
    JSVM_Value name;
    /** Set this to make the property descriptor object's value property to be
     * a JavaScript function represented by method.
     */
    JSVM_Callback method;
    /** A function to call when a get access of the property is performed. */
    JSVM_Callback getter;
    /** A function to call when a set access of the property is performed. */
    JSVM_Callback setter;
    /** The value that's retrieved by a get access of the property if the property is a data property. */
    JSVM_Value value;
    /** The attributes associated with the particular property. */
    JSVM_PropertyAttributes attributes;
} JSVM_PropertyDescriptor;

/**
 * @brief JSVM-API uses both return values and JavaScript exceptions for error handling
 * @since 11
 */
typedef struct {
    /** UTF8-encoded string containing a VM-neutral description of the error. */
    const char* errorMessage;
    /** Reserved for VM-specific error details. This is currently not implemented for any VM. */
    void* engineReserved;
    /** VM-specific error code. This is currently not implemented for any VM. */
    uint32_t engineErrorCode;
    /** The JSVM-API status code that originated with the last error. */
    JSVM_Status errorCode;
} JSVM_ExtendedErrorInfo;

/**
 * @brief A 128-bit value stored as two unsigned 64-bit integers.
 * It serves as a UUID with which JavaScript objects or externals can be "tagged"
 * in order to ensure that they are of a certain type.
 *
 * @since 11
 */
typedef struct {
    /** lower type. */
    uint64_t lower;
    /** upper type. */
    uint64_t upper;
} JSVM_TypeTag;

/**
 * @brief When the object's getter, setter, deleter, and enumerator operations are performed, the corresponding
 * callback will be triggered.
 *
 * @since 12
 */
typedef struct {
    /** A callback function triggered by getting a named property of an instance object. */
    JSVM_Value(JSVM_CDECL* genericNamedPropertyGetterCallback)(JSVM_Env env,
                                                               JSVM_Value name,
                                                               JSVM_Value thisArg,
                                                               JSVM_Value namedPropertyData);

    /** A callback function triggered by setting a named property of an instance object. */
    JSVM_Value(JSVM_CDECL* genericNamedPropertySetterCallback)(JSVM_Env env,
                                                               JSVM_Value name,
                                                               JSVM_Value property,
                                                               JSVM_Value thisArg,
                                                               JSVM_Value namedPropertyData);

    /** A callback function triggered by deleting a named property of an instance object. */
    JSVM_Value(JSVM_CDECL* genericNamedPropertyDeleterCallback)(JSVM_Env env,
                                                                JSVM_Value name,
                                                                JSVM_Value thisArg,
                                                                JSVM_Value namedPropertyData);

    /** A callback function triggered by getting all named properties requests on an object. */
    JSVM_Value(JSVM_CDECL* genericNamedPropertyEnumeratorCallback)(JSVM_Env env,
                                                                   JSVM_Value thisArg,
                                                                   JSVM_Value namedPropertyData);

    /** A callback function triggered by getting an indexed property of an instance object. */
    JSVM_Value(JSVM_CDECL* genericIndexedPropertyGetterCallback)(JSVM_Env env,
                                                                 JSVM_Value index,
                                                                 JSVM_Value thisArg,
                                                                 JSVM_Value indexedPropertyData);

    /** A callback function triggered by setting an indexed property of an instance object. */
    JSVM_Value(JSVM_CDECL* genericIndexedPropertySetterCallback)(JSVM_Env env,
                                                                 JSVM_Value index,
                                                                 JSVM_Value property,
                                                                 JSVM_Value thisArg,
                                                                 JSVM_Value indexedPropertyData);

    /** A callback function triggered by deleting an indexed property of an instance object. */
    JSVM_Value(JSVM_CDECL* genericIndexedPropertyDeleterCallback)(JSVM_Env env,
                                                                  JSVM_Value index,
                                                                  JSVM_Value thisArg,
                                                                  JSVM_Value indexedPropertyData);

    /** A callback function triggered by getting all indexed properties requests on an object. */
    JSVM_Value(JSVM_CDECL* genericIndexedPropertyEnumeratorCallback)(JSVM_Env env,
                                                                     JSVM_Value thisArg,
                                                                     JSVM_Value indexedPropertyData);

    /** data will be utilized by the named property callbacks in this struct. */
    JSVM_Value namedPropertyData;

    /** data will be utilized by the indexed property callbacks in this struct. */
    JSVM_Value indexedPropertyData;
} JSVM_PropertyHandlerConfigurationStruct;

/**
 * @brief The pointer type of the structure which contains the property handlers.
 *
 * @since 12
 */
typedef JSVM_PropertyHandlerConfigurationStruct* JSVM_PropertyHandlerCfg;

/**
 * @brief Source code information.
 *
 * @since 12
 */
typedef struct {
    /** Sourcemap url. */
    const char* sourceMapUrl;
    /** Resource name. */
    const char* resourceName;
    /** Resource line offset. */
    size_t resourceLineOffset;
    /** Resource column offset. */
    size_t resourceColumnOffset;
} JSVM_ScriptOrigin;

/**
 * @brief Compile Options
 *
 * @since 12
 */
typedef struct {
    /** compile option id. */
    JSVM_CompileOptionId id;
    /** option content. */
    union {
        /** ptr type. */
        void *ptr;
        /** int type. */
        int num;
        /** bool type. */
        bool boolean;
    } content;
} JSVM_CompileOptions;

/**
 * @brief code cache passed with JSVM_COMPILE_CODE_CACHE
 *
 * @since 12
 */
typedef struct {
    /** cache pointer. */
    uint8_t *cache;
    /** length. */
    size_t length;
} JSVM_CodeCache;

/**
 * @brief compile profile passed with JSVM_COMPILE_COMPILE_PROFILE
 *
 * @since 12
 */
typedef const struct {
    /** profile pointer. */
    int *profile;
    /** length. */
    size_t length;
} JSVM_CompileProfile;

/**
 * @brief Regular expression flag bits. They can be or'ed to enable a set of flags.
 *
 * @since 12
 */
typedef enum {
    /** None mode. */
    JSVM_REGEXP_NONE = 0,
    /** Global mode. */
    JSVM_REGEXP_GLOBAL = 1 << 0,
    /** Ignore Case mode. */
    JSVM_REGEXP_IGNORE_CASE = 1 << 1,
    /** Multiline mode. */
    JSVM_REGEXP_MULTILINE = 1 << 2,
    /** Sticky mode. */
    JSVM_REGEXP_STICKY = 1 << 3,
    /** Unicode mode. */
    JSVM_REGEXP_UNICODE = 1 << 4,
    /** dotAll mode. */
    JSVM_REGEXP_DOT_ALL = 1 << 5,
    /** Linear mode. */
    JSVM_REGEXP_LINEAR = 1 << 6,
    /** Has Indices mode. */
    JSVM_REGEXP_HAS_INDICES = 1 << 7,
    /** Unicode Sets mode. */
    JSVM_REGEXP_UNICODE_SETS = 1 << 8,
} JSVM_RegExpFlags;

/**
 * @brief initialization flag
 *
 * @since 12
 */
typedef enum {
    /** initialize with zero. */
    JSVM_ZERO_INITIALIZED,
    /** leave uninitialized. */
    JSVM_UNINITIALIZED,
} JSVM_InitializedFlag;

/**
 * @brief WebAssembly function optimization level
 *
 * @since 12
 */
typedef enum {
    /** baseline optimization level. */
    JSVM_WASM_OPT_BASELINE = 10,
    /** high optimization level. */
    JSVM_WASM_OPT_HIGH = 20,
} JSVM_WasmOptLevel;

/**
 * @brief Cache data type
 *
 * @since 12
 */
typedef enum {
    /** js code cache, generated by OH_JSVM_CreateCodeCache */
    JSVM_CACHE_TYPE_JS,
    /** WebAssembly cache, generated by OH_JSVM_CreateWasmCache */
    JSVM_CACHE_TYPE_WASM,
} JSVM_CacheType;

/**
 * @brief Microtask policies of JSVM.
 *
 * @since 18
 */
typedef enum {
    /** Microtasks are invoked with the OH_JSVM_PerformMicrotaskCheckpoint() method. */
    JSVM_MICROTASK_EXPLICIT = 0,
    /** Microtasks are invoked when the script call depth decrements to zero.
     *  Default mode.
     */
    JSVM_MICROTASK_AUTO,
} JSVM_MicrotaskPolicy;

/**
 * @brief Trace category for jsvm internal trace events.
 *
 * @since 18
 */
typedef enum {
    /** Tracing main interface invoking of JSVM, such as run scripts. */
    JSVM_TRACE_VM,
    /** Tracing interface invoking about compilation, such as CompileCodeBackground. */
    JSVM_TRACE_COMPILE,
    /** Tracing interface invoking about execution status, such as Interrupts and Microtasks. */
    JSVM_TRACE_EXECUTE,
    /** Tracing external callback */
    JSVM_TRACE_RUNTIME,
    /** Tracing stack trace in JSVM. */
    JSVM_TRACE_STACK_TRACE,
    /** Tracing Main interface invoking of WASM, such as Compile Wasm Module and Instantiate. */
    JSVM_TRACE_WASM,
    /** Tracing more detailed interface invoking of WASM, such as background compilation and wrappers. */
    JSVM_TRACE_WASM_DETAILED
} JSVM_TraceCategory;

/**
 * @brief The promise-reject event.
 *
 * @since 18
 */
typedef enum {
    /** Promise is rejected for other reasons. */
    JSVM_PROMISE_REJECT_OTHER_REASONS = 0,
    /** Promise rejected with no handler. */
    JSVM_PROMISE_REJECT_WITH_NO_HANDLER = 1,
    /** Add the handler after Promise has been rejected. */
    JSVM_PROMISE_ADD_HANDLER_AFTER_REJECTED = 2,
    /** After the Promise has been resolved, try to reject the Promise again. */
    JSVM_PROMISE_REJECT_AFTER_RESOLVED = 3,
    /** After the Promise has been resolved, try resolving the Promise again. */
    JSVM_PROMISE_RESOLVE_AFTER_RESOLVED = 4,
} JSVM_PromiseRejectEvent;

/**
 * @brief The level of message error.
 *
 * @since 18
 */
typedef enum {
    /** Log level message. */
    JSVM_MESSAGE_LOG = (1 << 0),
    /** Debug level message. */
    JSVM_MESSAGE_DEBUG = (1 << 1),
    /** Info level message. */
    JSVM_MESSAGE_INFO = (1 << 2),
    /** Error level message. */
    JSVM_MESSAGE_ERROR = (1 << 3),
    /** Warning level message. */
    JSVM_MESSAGE_WARNING = (1 << 4),
    /** All level message. */
    JSVM_MESSAGE_ALL = JSVM_MESSAGE_LOG | JSVM_MESSAGE_DEBUG | JSVM_MESSAGE_INFO | JSVM_MESSAGE_ERROR |
                       JSVM_MESSAGE_WARNING,
} JSVM_MessageErrorLevel;

/**
 * @brief Function pointer type of OOM-Error callback.
 *
 * @param location The location information of the OOM error.
 * @param detail The detail of the OOM error.
 * @param isHeapOOM Determine whether the OOM type is Heap OOM.
 *
 * @since 18
 */
typedef void(JSVM_CDECL* JSVM_HandlerForOOMError)(const char* location,
                                                  const char* detail,
                                                  bool isHeapOOM);

/**
 * @brief Function pointer type of Fatal-Error callback.
 *
 * @param location The location information of the Fatal error.
 * @param message The message of the Fatal error.
 *
 * @since 18
 */
typedef void(JSVM_CDECL* JSVM_HandlerForFatalError)(const char* location,
                                                    const char* message);

/**
 * @brief Function pointer type of Promise-Reject callback.
 *
 * @param env The environment that the function is invoked under.
 * @param rejectEvent The promise-reject event.
 * @param rejectInfo An JS-object containing two properties: 'promise' and 'value'.
 * The 'promise' represents a reference to the Promise object that was rejected.
 * The 'value' represents the rejection reason associated with that promise.
 *
 * @since 18
 */
typedef void(JSVM_CDECL* JSVM_HandlerForPromiseReject)(JSVM_Env env,
                                                       JSVM_PromiseRejectEvent rejectEvent,
                                                       JSVM_Value rejectInfo);

/**
 * @brief DefineClass options id.
 *
 * @since 18
 */
typedef enum {
    /** Defining a class in normal mode. */
    JSVM_DEFINE_CLASS_NORMAL,
    /** Defining a class with count. */
    JSVM_DEFINE_CLASS_WITH_COUNT,
    /** Defining a class with property handler. */
    JSVM_DEFINE_CLASS_WITH_PROPERTY_HANDLER,
} JSVM_DefineClassOptionsId;

/**
 * @brief DefineClass options.
 *
 * @since 18
 */
typedef struct {
    /** DefineClass option id. */
    JSVM_DefineClassOptionsId id;
    /** option content. */
    union {
        /** for option value with pointer type. */
        void* ptr;
        /** for option value with integer type  */
        int num;
        /** for option value with bool type */
        bool boolean;
    } content;
} JSVM_DefineClassOptions;

/**
 * @brief The property-handler used to define class.
 *
 * @since 18
 */
typedef struct {
    /** The instance object triggers the corresponding callback function. */
    JSVM_PropertyHandlerCfg propertyHandlerCfg;
    /** Calling an instance object as a function will trigger this callback. */
    JSVM_Callback callAsFunctionCallback;
} JSVM_PropertyHandler;

/**
 * @brief The timing of GC callback trigger.
 *
 * @since 18
 */
typedef enum {
    /** Trigger GC callback before GC. */
    JSVM_CB_TRIGGER_BEFORE_GC,
    /** Trigger GC callback after GC. */
    JSVM_CB_TRIGGER_AFTER_GC,
} JSVM_CBTriggerTimeForGC;

/**
 * @brief The GC type.
 *
 * @since 18
 */
typedef enum {
    /** The GC algorithm is Scavenge. */
    JSVM_GC_TYPE_SCAVENGE = 1 << 0,
    /** The GC algorithm is Minor-Mark-Compact. */
    JSVM_GC_TYPE_MINOR_MARK_COMPACT = 1 << 1,
    /** The GC algorithm is Mark-Sweep-Compact. */
    JSVM_GC_TYPE_MARK_SWEEP_COMPACT = 1 << 2,
    /** The GC algorithm is Incremental-Marking. */
    JSVM_GC_TYPE_INCREMENTAL_MARKING = 1 << 3,
    /** The GC algorithm is Weak-Callbacks. */
    JSVM_GC_TYPE_PROCESS_WEAK_CALLBACKS = 1 << 4,
    /** All GC algorithm. */
    JSVM_GC_TYPE_ALL = JSVM_GC_TYPE_SCAVENGE | JSVM_GC_TYPE_MINOR_MARK_COMPACT |
                       JSVM_GC_TYPE_MARK_SWEEP_COMPACT | JSVM_GC_TYPE_INCREMENTAL_MARKING |
                       JSVM_GC_TYPE_PROCESS_WEAK_CALLBACKS,
} JSVM_GCType;

/**
 * @brief The GC callback flags.
 *
 * @since 18
 */
typedef enum {
    /** No GC callback falgs. */
    JSVM_NO_GC_CALLBACK_FLAGS,
    /** Reserved object information will be built in the garbage collection callback. */
    JSVM_GC_CALLBACK_CONSTRUCT_RETAINED_OBJECT_INFOS,
    /** Enforce Garbage Collection Callback. */
    JSVM_GC_CALLBACK_FORCED,
    /** Synchronous phantom callback processing. */
    JSVM_GC_CALLBACK_SYNCHRONOUS_PHANTOM_CALLBACK_PROCESSING,
    /** All available garbage objects are collected during garbage collection. */
    JSVM_GC_CALLBACK_COLLECT_ALL_AVAILABLE_GARBAGE,
    /** Garbage collection collects all external memory. */
    JSVM_GC_CALLBACK_COLLECT_ALL_EXTERNAL_MEMORY,
    /** Schedule Garbage Collection at Idle Time. */
    JSVM_GC_CALLBACK_SCHEDULE_IDLE_GARBAGE_COLLECTION,
} JSVM_GCCallbackFlags;

/**
 * @brief Function pointer type of GC callback.
 *
 * @param vm The VM instance that the JSVM-API call is invoked under.
 * @param gcType The gc type.
 * @param flags The GC callback flags.
 * @param data The native pointer data.
 *
 * @since 18
 */
typedef void(JSVM_CDECL* JSVM_HandlerForGC)(JSVM_VM vm,
                                            JSVM_GCType gcType,
                                            JSVM_GCCallbackFlags flags,
                                            void* data);

/**
 * @brief To represent a JavaScript Data type.
 *
 * @since 18
 */
typedef struct JSVM_Data__* JSVM_Data;

/**
 * @brief Debug options.
 *
 * @since 20
 */
typedef enum {
    /** Scope check. */
    JSVM_SCOPE_CHECK,
} JSVM_DebugOption;
/** @} */
#endif /* ARK_RUNTIME_JSVM_JSVM_TYPE_H */

