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
 * @addtogroup ArkUI_NativeModule
 * @{
 *
 * @brief Provides UI capabilities of ArkUI on the native side, such as UI component creation and destruction,
 * tree node operations, attribute setting, and event listening.
 *
 * @since 12
 */

/**
 * @file native_type.h
 *
 * @brief Defines the common types for the native module.
 *
 * @library libace_ndk.z.so
 * @syscap SystemCapability.ArkUI.ArkUI.Full
 * @kit ArkUI
 * @since 12
 */

#ifndef ARKUI_NATIVE_TYPE_H
#define ARKUI_NATIVE_TYPE_H

#include <stdint.h>

#include "drawable_descriptor.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the ArkUI native component object.
 *
 * @since 12
 */
struct ArkUI_Node;

/**
 * @brief Defines the pointer type of the ArkUI node content
 *
 * @since 12
 */
typedef struct ArkUI_NodeContent* ArkUI_NodeContentHandle;

/**
 * @brief Defines the custom dialog box controller of ArkUI on the native side.
 *
 * @since 12
 */
struct ArkUI_NativeDialog;

/**
 * @brief Sets the size constraints of a component during component layout.
 *
 * @since 12
 */
typedef struct ArkUI_LayoutConstraint ArkUI_LayoutConstraint;

/**
 * @brief Defines the structure of the component drawing context.
 *
 * @since 12
 */
typedef struct ArkUI_DrawContext ArkUI_DrawContext;

/**
 * @brief Defines the pointer to the ArkUI native component object.
 *
 * @since 12
 */
typedef struct ArkUI_Node* ArkUI_NodeHandle;

/**
 * @brief Defines the pointer to the custom dialog box controller of ArkUI on the native side.
 *
 * @since 12
 */
typedef struct ArkUI_NativeDialog* ArkUI_NativeDialogHandle;

/**
 * @brief Defines the water flow section configuration.
 *
 * @since 12
 */
typedef struct ArkUI_WaterFlowSectionOption ArkUI_WaterFlowSectionOption;

/**
 * @brief Define the configuration information of the Item within the ListitemSwipeActionOption method.
 *
 * @since 12
 */
typedef struct ArkUI_ListItemSwipeActionItem ArkUI_ListItemSwipeActionItem;

/**
 * @brief Define the configuration information for the ListitemSwipeActionOption method.
 *
 * @since 12
 */
typedef struct ArkUI_ListItemSwipeActionOption ArkUI_ListItemSwipeActionOption;

/**
 * @brief Defines the ArkUI native context object.
 *
 * @since 12
 */
struct ArkUI_Context;

/**
  * @brief Defines the pointer to the context instance object pointer definition of ArkUI on the native side.
  *
  * @since 12
  */
typedef struct ArkUI_Context* ArkUI_ContextHandle;

/**
 * @brief Defines the navigation indicator style for the swiper.
 *
 * @since 12
 */
typedef struct ArkUI_SwiperIndicator ArkUI_SwiperIndicator;

/**
 * @brief Defines the digital indicator style for the swiper.
 *
 * @since 19
 */
typedef struct ArkUI_SwiperDigitIndicator ArkUI_SwiperDigitIndicator;

/**
 * @brief Defines the arrow style for the swiper.
 *
 * @since 19
 */
typedef struct ArkUI_SwiperArrowStyle ArkUI_SwiperArrowStyle;

/**
* @brief Define the data objects of styled string supported by text components.
*
* @since 14
*/
typedef struct ArkUI_StyledString_Descriptor ArkUI_StyledString_Descriptor;

/**
  * @brief specifies the alignment rules for subcomponents set in relative containers.
  *
  * @since 12
  */
typedef struct ArkUI_AlignmentRuleOption ArkUI_AlignmentRuleOption;

/**
  * @brief guideLine parameters, used to define the id, direction and position of the guideline.
  *
  * @since 12
  */
typedef struct ArkUI_GuidelineOption ArkUI_GuidelineOption;

/**
  * @brief barrier parameter, used to define the id,
  * direction and components of the barrier that it depends on when generating it.
  *
  * @since 12
  */
typedef struct ArkUI_BarrierOption ArkUI_BarrierOption;

/**
 * @brief Define the ChildrenMainSize class information for a List.
 *
 * @since 12
*/
typedef struct ArkUI_ListChildrenMainSize ArkUI_ListChildrenMainSize;

/**
 * @brief Defines the image frame.
 *
 * @since 12
*/
typedef struct ArkUI_ImageAnimatorFrameInfo ArkUI_ImageAnimatorFrameInfo;

/**
 * @brief Defines the accessibility state for the component.
 *
 * @since 12
 */
typedef struct ArkUI_AccessibilityState ArkUI_AccessibilityState;

/**
 * @brief Defines the accessibility value for the component.
 *
 * @since 12
 */
typedef struct ArkUI_AccessibilityValue ArkUI_AccessibilityValue;

/**
 * @brief Define the information of the Custom Property class for custom properties.
 *
 * @since 14
 */
typedef struct ArkUI_CustomProperty ArkUI_CustomProperty;

/**
 * @brief Define the information of the HostWindowInfo class for window properties.
 *
 * @since 15
 */
typedef struct ArkUI_HostWindowInfo ArkUI_HostWindowInfo;

/**
 * @brief Define ActiveChildenInfo class information.
 *
 * @since 14
 */
typedef struct ArkUI_ActiveChildrenInfo ArkUI_ActiveChildrenInfo;

/**
 * @brief Set the linear progress indicator style.
 *
 * @since 15
 */
typedef struct ArkUI_ProgressLinearStyleOption ArkUI_ProgressLinearStyleOption;

/**
 * @brief The cross-language option.
 *
 * @since 15
 */
typedef struct ArkUI_CrossLanguageOption ArkUI_CrossLanguageOption;

/**
 * @brief Declares the Ability base want.
 *
 * @since 20
 */
typedef struct AbilityBase_Want AbilityBase_Want;

/**
 * @brief Define the EmbeddedComponentOption for the EmbeddedComponent.
 *
 * @since 20
 */
typedef struct ArkUI_EmbeddedComponentOption ArkUI_EmbeddedComponentOption;

/**
 * @brief Defines the event callback type.
 *
 * @since 12
 */
typedef struct {
    /** Custom type. */
    void* userData;
    /** Event callback. */
    void (*callback)(void* userData);
} ArkUI_ContextCallback;
/**
 * @brief Provides the number types of ArkUI in the native code.
 *
 * @since 12
 */
typedef union {
    /** Floating-point type. */
    float f32;
    /** Signed integer. */
    int32_t i32;
    /** Unsigned integer. */
    uint32_t u32;
} ArkUI_NumberValue;

/**
 * @brief Enumerates the alignment modes.
 *
 * @since 12
 */
typedef enum {
    /** Top start. */
    ARKUI_ALIGNMENT_TOP_START = 0,
    /** Top center. */
    ARKUI_ALIGNMENT_TOP,
    /** Top end. */
    ARKUI_ALIGNMENT_TOP_END,
    /** Vertically centered start. */
    ARKUI_ALIGNMENT_START,
    /** Horizontally and vertically centered. */
    ARKUI_ALIGNMENT_CENTER,
    /** Vertically centered end. */
    ARKUI_ALIGNMENT_END,
    /** Bottom start. */
    ARKUI_ALIGNMENT_BOTTOM_START,
    /** Horizontally centered on the bottom. */
    ARKUI_ALIGNMENT_BOTTOM,
    /** Bottom end. */
    ARKUI_ALIGNMENT_BOTTOM_END,
} ArkUI_Alignment;

/**
 * @brief Enumerates the image repeat patterns.
 *
 * @since 12
 */
typedef enum {
    /** The image is not repeatedly drawn. */
    ARKUI_IMAGE_REPEAT_NONE = 0,
    /** The image is repeatedly drawn only along the x-axis. */
    ARKUI_IMAGE_REPEAT_X,
    /** The image is repeatedly drawn only along the y-axis. */
    ARKUI_IMAGE_REPEAT_Y,
    /** The image is repeatedly drawn along both axes. */
    ARKUI_IMAGE_REPEAT_XY,
} ArkUI_ImageRepeat;

/**
 * @brief Enumerates the font styles.
 *
 * @since 12
 */
typedef enum {
    /** Standard font style. */
    ARKUI_FONT_STYLE_NORMAL = 0,
    /** Italic font style. */
    ARKUI_FONT_STYLE_ITALIC
} ArkUI_FontStyle;

/**
 * @brief Enumerates the font weights.
 *
 * @since 12
 */
typedef enum {
    /** 100 */
    ARKUI_FONT_WEIGHT_W100 = 0,
    /** 200 */
    ARKUI_FONT_WEIGHT_W200,
    /** 300 */
    ARKUI_FONT_WEIGHT_W300,
    /** 400 */
    ARKUI_FONT_WEIGHT_W400,
    /** 500 */
    ARKUI_FONT_WEIGHT_W500,
    /** 600 */
    ARKUI_FONT_WEIGHT_W600,
    /** 700 */
    ARKUI_FONT_WEIGHT_W700,
    /** 800 */
    ARKUI_FONT_WEIGHT_W800,
    /** 900 */
    ARKUI_FONT_WEIGHT_W900,
    /** The font weight is bold. */
    ARKUI_FONT_WEIGHT_BOLD,
    /** The font weight is normal. */
    ARKUI_FONT_WEIGHT_NORMAL,
    /** The font weight is bolder. */
    ARKUI_FONT_WEIGHT_BOLDER,
    /** The font weight is lighter. */
    ARKUI_FONT_WEIGHT_LIGHTER,
    /** The font weight is medium. */
    ARKUI_FONT_WEIGHT_MEDIUM,
    /** The font weight is normal. */
    ARKUI_FONT_WEIGHT_REGULAR,
} ArkUI_FontWeight;

/**
 * @brief Enumerates the text alignment mode.
 *
 * @since 12
 */
typedef enum {
    /** Aligned with the start. */
    ARKUI_TEXT_ALIGNMENT_START = 0,
    /** Horizontally centered. */
    ARKUI_TEXT_ALIGNMENT_CENTER,
    /** Aligned with the end. */
    ARKUI_TEXT_ALIGNMENT_END,
    /** Aligned with both margins. */
    ARKUI_TEXT_ALIGNMENT_JUSTIFY,
} ArkUI_TextAlignment;

/**
 * @brief Enumerates text vertical alignment styles.
 *
 * @since 20
 */
typedef enum {
    /** Aligned to the baseline. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE = 0,
    /** Bottom aligned. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_BOTTOM,
    /** Center aligned. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_CENTER,
    /** Top aligned. */
    ARKUI_TEXT_VERTICAL_ALIGNMENT_TOP,
} ArkUI_TextVerticalAlignment;

/**
 * @brief Enumerates the types of the Enter key for a single-line text box.
 *
 * @since 12
 */
typedef enum {
    /** The Enter key is labeled "Go." */
    ARKUI_ENTER_KEY_TYPE_GO = 2,
    /** The Enter key is labeled "Search." */
    ARKUI_ENTER_KEY_TYPE_SEARCH = 3,
    /** The Enter key is labeled "Send." */
    ARKUI_ENTER_KEY_TYPE_SEND,
    /** The Enter key is labeled "Next." */
    ARKUI_ENTER_KEY_TYPE_NEXT,
    /** The Enter key is labeled "Done." */
    ARKUI_ENTER_KEY_TYPE_DONE,
    /** The Enter key is labeled "Previous." */
    ARKUI_ENTER_KEY_TYPE_PREVIOUS,
    /** The Enter key is labeled "New Line." */
    ARKUI_ENTER_KEY_TYPE_NEW_LINE,
} ArkUI_EnterKeyType;

/**
 * @brief Enumerates the text input types.
 *
 * @since 12
 */
typedef enum {
    /** Normal input mode. */
    ARKUI_TEXTINPUT_TYPE_NORMAL = 0,
    /** Number input mode. */
    ARKUI_TEXTINPUT_TYPE_NUMBER = 2,
    /** Phone number input mode. */
    ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3,
    /** Email address input mode. */
    ARKUI_TEXTINPUT_TYPE_EMAIL = 5,
    /** Password input mode. */
    ARKUI_TEXTINPUT_TYPE_PASSWORD = 7,
    /** Numeric password input mode. */
    ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8,
    /** Lock screen password input mode. */
    ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9,
    /** Username input mode. */
    ARKUI_TEXTINPUT_TYPE_USER_NAME = 10,
    /** New password input mode. */
    ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11,
    /** Number input mode with a decimal point. */
    ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12,
    /**
     * One time code input mode.
     * @since 20
     */
    ARKUI_TEXTINPUT_TYPE_ONE_TIME_CODE = 14,
} ArkUI_TextInputType;

/**
 * @brief Enumerates the text box types.
 *
 * @since 12
 */
typedef enum {
    /** Normal input mode. */
    ARKUI_TEXTAREA_TYPE_NORMAL = 0,
    /** Number input mode. */
    ARKUI_TEXTAREA_TYPE_NUMBER = 2,
    /** Phone number input mode. */
    ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3,
    /** Email address input mode. */
    ARKUI_TEXTAREA_TYPE_EMAIL = 5,
    /**
     * One time code input mode.
     * @since 20
     */
    ARKUI_TEXTAREA_TYPE_ONE_TIME_CODE = 14,
} ArkUI_TextAreaType;

/**
 * @brief Enumerates the styles of the Cancel button.
 *
 * @since 12
 */
typedef enum {
    /** The Cancel button is always displayed. */
    ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0,
    /** The Cancel button is always hidden. */
    ARKUI_CANCELBUTTON_STYLE_INVISIBLE,
    /** The Cancel button is displayed when there is text input. */
    ARKUI_CANCELBUTTON_STYLE_INPUT,
} ArkUI_CancelButtonStyle;

/**
 * @brief Enumerates the types of the <b><XComponent></b> component.
 *
 * @since 12
 */
typedef enum {
    /** The custom content of EGL/OpenGL ES and media data is displayed individually on the screen. */
    ARKUI_XCOMPONENT_TYPE_SURFACE = 0,
    /** The custom content of EGL/OpenGL ES and media data is grouped and displayed together with content
      * of the component.
      */
    ARKUI_XCOMPONENT_TYPE_TEXTURE = 2,
} ArkUI_XComponentType;

/**
 * @brief Enumerates the styles of the progress indicator.
 *
 * @since 12
 */
typedef enum {
    /** Linear style. */
    ARKUI_PROGRESS_TYPE_LINEAR = 0,
    /** Indeterminate ring style. */
    ARKUI_PROGRESS_TYPE_RING,
    /** Eclipse style. */
    ARKUI_PROGRESS_TYPE_ECLIPSE,
    /** Determinate ring style. */
    ARKUI_PROGRESS_TYPE_SCALE_RING,
    /** Capsule style. */
    ARKUI_PROGRESS_TYPE_CAPSULE,
} ArkUI_ProgressType;

/**
 * @brief Enumerates the text decoration types.
 *
 * @since 12
 */
typedef enum {
    /** No text decoration. */
    ARKUI_TEXT_DECORATION_TYPE_NONE = 0,
    /** Line under the text. */
    ARKUI_TEXT_DECORATION_TYPE_UNDERLINE,
    /** Line over the text. */
    ARKUI_TEXT_DECORATION_TYPE_OVERLINE,
    /** Line through the text. */
    ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH,
} ArkUI_TextDecorationType;

/**
 * @brief Enumerates the text decoration styles.
 *
 * @since 12
 */
typedef enum {
    /** Single solid line. */
    ARKUI_TEXT_DECORATION_STYLE_SOLID = 0,
    /** Double solid line. */
    ARKUI_TEXT_DECORATION_STYLE_DOUBLE,
    /** Dotted line. */
    ARKUI_TEXT_DECORATION_STYLE_DOTTED,
    /** Dashed line. */
    ARKUI_TEXT_DECORATION_STYLE_DASHED,
    /** Wavy line. */
    ARKUI_TEXT_DECORATION_STYLE_WAVY,
} ArkUI_TextDecorationStyle;

/**
 * @brief Enumerates the text cases.
 *
 * @since 12
 */
typedef enum {
    /** The original case of the text is retained. */
    ARKUI_TEXT_CASE_NORMAL = 0,
    /** All letters in the text are in lowercase. */
    ARKUI_TEXT_CASE_LOWER,
    /** All letters in the text are in uppercase. */
    ARKUI_TEXT_CASE_UPPER,
} ArkUI_TextCase;

/**
 * @brief Enumerates the text copy and paste modes.
 *
 * @since 12
 */
typedef enum {
    /** Copy is not allowed. */
    ARKUI_COPY_OPTIONS_NONE = 0,
    /** Intra-application copy is allowed. */
    ARKUI_COPY_OPTIONS_IN_APP,
    /** Intra-device copy is allowed. */
    ARKUI_COPY_OPTIONS_LOCAL_DEVICE,
    /** Cross-device copy is allowed. */
    ARKUI_COPY_OPTIONS_CROSS_DEVICE,
} ArkUI_CopyOptions;

/**
 * @brief Enumerates the shadow types.
 *
 * @since 12
 */
typedef enum {
    /** Color. */
    ARKUI_SHADOW_TYPE_COLOR = 0,
    /** Blur. */
    ARKUI_SHADOW_TYPE_BLUR
} ArkUI_ShadowType;

/**
 * @brief Enumerates the modes of the date picker.
 *
 * @since 18
 */
typedef enum {
    /** A mode that displays the date in months, days of month, and years. */
    ARKUI_DATEPICKER_MODE_DATE = 0,
    /** A mode that displays the date in months and years. */
    ARKUI_DATEPICKER_YEAR_AND_MONTH = 1,
    /** A mode that displays the date in months and days of the month. */
    ARKUI_DATEPICKER_MONTH_AND_DAY = 2,
} ArkUI_DatePickerMode;

/**
 * @brief Enumerates the types of the text picker.
 *
 * @since 12
 */
typedef enum {
    /** Single-column text picker. */
    ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0,
    /** Multi-column text picker. */
    ARKUI_TEXTPICKER_RANGETYPE_MULTI,
    /** Single-column text picker with image resources. */
    ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT,
    /** Interconnected multi-column text picker. */
    ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT,
} ArkUI_TextPickerRangeType;

/**
 * @brief Defines the input structure of the single-column text picker with image resources.
 *
 * @since 12
 */
typedef struct {
    /** Image resource. */
    const char* icon;
    /** Text information. */
    const char* text;
} ARKUI_TextPickerRangeContent;

/**
 * @brief Defines the input structure of the interconnected multi-column text picker.
 *
 * @since 12
 */
typedef struct {
    /** Text information. */
    const char* text;
    /** Interconnected data. */
    const ARKUI_TextPickerRangeContent* children;
    /** Size of the interconnected data array. */
    int32_t size;
} ARKUI_TextPickerCascadeRangeContent;

/**
 * @brief Enumerates the effects used at the edges of the component when the boundary of the scrollable content is
 * reached.
 *
 * @since 12
 */
typedef enum {
    /** Spring effect. When at one of the edges, the component can move beyond the bounds based on the initial
     *  speed or through touches, and produces a bounce effect when the user releases their finger. */
    ARKUI_EDGE_EFFECT_SPRING = 0,
    /** Fade effect. When at one of the edges, the component produces a fade effect. */
    ARKUI_EDGE_EFFECT_FADE,
    /** No effect after the scrollbar is moved to the edge. */
    ARKUI_EDGE_EFFECT_NONE,
} ArkUI_EdgeEffect;

/**
 * @brief Enumerates the edges for which the effect takes effect when the boundary of the scrollable content is reached.
 *
 * @since 18
 */
typedef enum {
    /** Start edge. */
    ARKUI_EFFECT_EDGE_START = 1,
    /** End edge. */
    ARKUI_EFFECT_EDGE_END = 2,
} ArkUI_EffectEdge;

/**
 * @brief Enumerates the focus wrap mode of components.
 *
 * @since 20
 */
typedef enum {
    /** Default mode, where focus does not wrap when arrow keys are used. */
    ARKUI_FOCUS_WRAP_MODE_DEFAULT = 0,
    /** Focus wraps automatically when arrow keys are used. */
    ARKUI_FOCUS_WRAP_WITH_ARROW = 1,
} ArkUI_FocusWrapMode;

/**
 * @brief Enumerates the scroll directions for the <b><Scroll></b> component.
 *
 * @since 12
 */
typedef enum {
    /** Only vertical scrolling is supported. */
    ARKUI_SCROLL_DIRECTION_VERTICAL = 0,
    /** Only horizontal scrolling is supported. */
    ARKUI_SCROLL_DIRECTION_HORIZONTAL,
    /** Scrolling is not allowed. */
    ARKUI_SCROLL_DIRECTION_NONE = 3,
    /**
     * Free scrolling in both directions.
     *
     * @since 20
     */
    ARKUI_SCROLL_DIRECTION_FREE = 4,
} ArkUI_ScrollDirection;

/**
 * @brief Enumerates the alignment modes of list items when scrolling ends.
 *
 * @since 12
 */
typedef enum {
    /** No alignment. This is the default value. */
    ARKUI_SCROLL_SNAP_ALIGN_NONE = 0,
    /** The first item in the view is aligned at the start of the list. */
    ARKUI_SCROLL_SNAP_ALIGN_START,
    /** The middle items in the view are aligned in the center of the list. */
    ARKUI_SCROLL_SNAP_ALIGN_CENTER,
    /** The last item in the view is aligned at the end of the list. */
    ARKUI_SCROLL_SNAP_ALIGN_END,
} ArkUI_ScrollSnapAlign;

/**
 * @brief Enumerates the scrollbar display modes.
 *
 * @since 12
 */
typedef enum {
    /** Hide. */
    ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0,
    /** Display on demand (displays when the screen is touched and disappears after 2s). */
    ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO,
    /** Always display. */
    ARKUI_SCROLL_BAR_DISPLAY_MODE_ON,
} ArkUI_ScrollBarDisplayMode;

/**
 * @brief Enumerates the scroll directions for the <b><List></b> component.
 *
 * @since 12
 */
typedef enum {
    /** Only vertical scrolling is supported. */
    ARKUI_AXIS_VERTICAL = 0,
    /** Only horizontal scrolling is supported. */
    ARKUI_AXIS_HORIZONTAL,
} ArkUI_Axis;

/**
 * @brief Enumerates the modes for pinning the header to the top or the footer to the bottom.
 *
 * @since 12
 */
typedef enum {
    /** In the list item group, the header is not pinned to the top, and the footer is not pinned to the bottom. */
    ARKUI_STICKY_STYLE_NONE = 0,
    /** In the list item group, the header is pinned to the top, and the footer is not pinned to the bottom. */
    ARKUI_STICKY_STYLE_HEADER = 1,
    /** In the list item group, the footer is pinned to the bottom, and the header is not pinned to the top. */
    ARKUI_STICKY_STYLE_FOOTER = 2,
    /** In the list item group, the footer is pinned to the bottom, and the header is pinned to the top. */
    ARKUI_STICKY_STYLE_BOTH = 3,
} ArkUI_StickyStyle;

/**
 * @brief Enumerates the content clipping modes of scrollable components.
 *
 * @since 18
 */
typedef enum {
    /** clip by content */
    ARKUI_CONTENT_CLIP_MODE_CONTENT_ONLY = 0,
    /** clip by boundary */
    ARKUI_CONTENT_CLIP_MODE_BOUNDARY,
    /** clip by safe area padding */
    ARKUI_CONTENT_CLIP_MODE_SAFE_AREA,
} ArkUI_ContentClipMode;

/**
 * @brief Enumerates the layout modes of the WaterFlow component.
 *
 * @since 18
 */
typedef enum {
    /** Layout items from top to viewport. */
    ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN = 0,
    /** Layout items in viewport. */
    ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW,
} ArkUI_WaterFlowLayoutMode;

/**
 * @brief Enumerates the border styles.
 *
 * @since 12
 */
typedef enum {
    /** Solid border. */
    ARKUI_BORDER_STYLE_SOLID = 0,
    /** Dashed border. */
    ARKUI_BORDER_STYLE_DASHED,
    /** Dotted border. */
    ARKUI_BORDER_STYLE_DOTTED,
} ArkUI_BorderStyle;

/**
 * @brief Enumerates the hit test modes.
 *
 * @since 12
 */
typedef enum {
    /** Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from
     *  the hit test. */
    ARKUI_HIT_TEST_MODE_DEFAULT = 0,
    /** The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the
     *  hit test. */
    ARKUI_HIT_TEST_MODE_BLOCK,
    /** Both the node and its child node respond to the hit test of a touch event, and its sibling node is also
     * considered during the hit test. */
    ARKUI_HIT_TEST_MODE_TRANSPARENT,
    /** The node does not respond to the hit test of a touch event. */
    ARKUI_HIT_TEST_MODE_NONE,
    /**
     * The node and its child nodes participate in hit tests, while blocking hit tests for all sibling nodes and
     * parent nodes with lower priority.
     *
     * @since 20
     */
    ARKUI_HIT_TEST_MODE_BLOCK_HIERARCHY,
    /**
     * The node does not respond to hit tests, and none of its descendants (including children and grandchildren)
     * participate in hit tests either.
     *
     * @since 20
     */
    ARKUI_HIT_TEST_MODE_BLOCK_DESCENDANTS,
} ArkUI_HitTestMode;

/**
 * @brief Enumerates the shadow styles.
 *
 * @since 12
 */
typedef enum {
    /** Mini shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS = 0,
    /** Little shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM,
    /** Medium shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD,
    /** Large shadow. */
    ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG,
    /** Floating small shadow. */
    ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM,
    /** Floating medium shadow. */
    ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD,
} ArkUI_ShadowStyle;

/**
 * @brief Enumerates the animation curves.
 *
 * @since 12
 */
typedef enum {
    /** The animation speed keeps unchanged. */
    ARKUI_CURVE_LINEAR = 0,
    /** The animation starts slowly, accelerates, and then slows down towards the end. */
    ARKUI_CURVE_EASE,
    /** The animation starts at a low speed and then picks up speed until the end. */
    ARKUI_CURVE_EASE_IN,
    /** The animation ends at a low speed. */
    ARKUI_CURVE_EASE_OUT,
    /** The animation starts and ends at a low speed. */
    ARKUI_CURVE_EASE_IN_OUT,
    /** The animation uses the standard curve */
    ARKUI_CURVE_FAST_OUT_SLOW_IN,
    /** The animation uses the deceleration curve. */
    ARKUI_CURVE_LINEAR_OUT_SLOW_IN,
    /** The animation uses the acceleration curve. */
    ARKUI_CURVE_FAST_OUT_LINEAR_IN,
    /** The animation uses the extreme deceleration curve. */
    ARKUI_CURVE_EXTREME_DECELERATION,
    /** The animation uses the sharp curve. */
    ARKUI_CURVE_SHARP,
    /** The animation uses the rhythm curve. */
    ARKUI_CURVE_RHYTHM,
    /** The animation uses the smooth curve. */
    ARKUI_CURVE_SMOOTH,
    /** The animation uses the friction curve */
    ARKUI_CURVE_FRICTION,
} ArkUI_AnimationCurve;

/**
 * @brief Enumerates arrow styles of the navigation point indicator.
 *
 * @since 12
 */
typedef enum {
    /** The arrow is not displayed for the navigation point indicator. */
    ARKUI_SWIPER_ARROW_HIDE = 0,
    /** The arrow is displayed for the navigation point indicator. */
    ARKUI_SWIPER_ARROW_SHOW,
    /** The arrow is displayed only when the mouse pointer hovers over the navigation point indicator. */
    ARKUI_SWIPER_ARROW_SHOW_ON_HOVER,
} ArkUI_SwiperArrow;

/**
 * @brief Nested scrolling mode for Swiper components and parent components.
 *
 * @since 12
 */
typedef enum {
    /** Swiper only scrolls on its own and is not linked to its parent component. */
    ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY = 0,
    /** The Swiper itself scrolls first, and the parent component scrolls after it reaches the edge. After the parent
     * component scrolls to the edge, if the parent component has an edge effect, the parent component triggers the edge
     * effect; otherwise, the Swiper triggers the edge effect. */
    ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST,
} ArkUI_SwiperNestedScrollMode;

/**
 * @brief Enumerates the page flipping modes using the mouse wheel for the <b>Swiper</b> component.
 *
 * @since 15
 */
typedef enum {
    /** When the mouse wheel is scrolled continuously, multiple pages are flipped, which is determined by the number of
     *  times that mouse events are reported. */
    ARKUI_PAGE_FLIP_MODE_CONTINUOUS = 0,
    /** The system does not respond to other mouse wheel events until the page flipping animation ends. */
    ARKUI_PAGE_FLIP_MODE_SINGLE,
} ArkUI_PageFlipMode;

/**
 * @brief Enumerates the animation modes for {@link NODE_SWIPER_INDEX}.
 *
 * @since 15
 */
typedef enum {
    /** Jump to target index without animation. */
    ARKUI_SWIPER_NO_ANIMATION = 0,
    /** Scroll to target index with animation. */
    ARKUI_SWIPER_DEFAULT_ANIMATION = 1,
    /** Jump to some index near the target index without animation, then scroll to target index with animation. */
    ARKUI_SWIPER_FAST_ANIMATION = 2,
} ArkUI_SwiperAnimationMode;

/**
 * @brief Enumerates the accessibility modes.
 *
 * @since 12
 */
typedef enum {
    /** Whether the component can be identified by the accessibility service is dependent on the component. */
    ARKUI_ACCESSIBILITY_MODE_AUTO = 0,
    /** The component can be identified by the accessibility service. */
    ARKUI_ACCESSIBILITY_MODE_ENABLED,
    /** The component cannot be identified by the accessibility service. */
    ARKUI_ACCESSIBILITY_MODE_DISABLED,
    /** The component and all its child components cannot be identified by the accessibility service. */
    ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS,
} ArkUI_AccessibilityMode;

/**
 * @brief Defines whether copy and paste is allowed for text content.
 *
 * @since 12
 */
typedef enum {
    /** Copy is not allowed. */
    ARKUI_TEXT_COPY_OPTIONS_NONE = 0,
    /** Intra-application copy is allowed. */
    ARKUI_TEXT_COPY_OPTIONS_IN_APP,
    /** Intra-device copy is allowed. */
    ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE,
    /** Cross-device copy is allowed. */
    ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE,
} ArkUI_TextCopyOptions;

/**
 * @brief Defines how the adaptive height is determined for the text.
 *
 * @since 12
 */
typedef enum {
    /** Prioritize the <b>maxLines</b> settings. */
    ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0,
    /** Prioritize the <b>minFontSize</b> settings. */
    ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST,
    /** Prioritize the layout constraint settings in terms of height. */
    ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST,
} ArkUI_TextHeightAdaptivePolicy;

/**
 * @brief Defines nested scrolling options.
 *
 * @since 12
 */
typedef enum {
    /** The scrolling is contained within the component, and no scroll chaining occurs, that is, the parent component
     * does not scroll when the component scrolling reaches the boundary. */
    ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0,
    /** The component scrolls first, and when it hits the boundary, the parent component scrolls.
     *  When the parent component hits the boundary, its edge effect is displayed. If no edge
     *  effect is specified for the parent component, the edge effect of the child component is displayed instead. */
    ARKUI_SCROLL_NESTED_MODE_SELF_FIRST,
    /** The parent component scrolls first, and when it hits the boundary, the component scrolls.
     *  When the component hits the boundary, its edge effect is displayed. If no edge effect is specified for the
     *  component, the edge effect of the parent component is displayed instead. */
    ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST,
    /** The component and its parent component scroll at the same time. When both the component and its parent component
     *  hit the boundary, the edge effect of the component is displayed. If no edge effect is specified for the
     *  component, the edge effect of the parent component is displayed instead. */
    ARKUI_SCROLL_NESTED_MODE_PARALLEL,
} ArkUI_ScrollNestedMode;

/**
 * @brief Defines the edge to which the component scrolls.
 *
 * @since 12
 */
typedef enum {
    /** Top edge in the vertical direction. */
    ARKUI_SCROLL_EDGE_TOP = 0,
    /** Bottom edge in the vertical direction. */
    ARKUI_SCROLL_EDGE_BOTTOM,
    /** Start position in the horizontal direction. */
    ARKUI_SCROLL_EDGE_START,
    /** End position in the horizontal direction. */
    ARKUI_SCROLL_EDGE_END,
} ArkUI_ScrollEdge;

/**
 * @brief Alignment when scrolling to specific items.
 *
 * @since 12
 */
typedef enum {
    /** Align the head. Align the head of the specified item with the head of the container.*/
    ARKUI_SCROLL_ALIGNMENT_START = 0,
    /** Center alignment. Align the axis direction of the specified item to the center of the container.*/
    ARKUI_SCROLL_ALIGNMENT_CENTER,
    /** Tail alignment. Align the tail of the specified item with the tail of the container.*/
    ARKUI_SCROLL_ALIGNMENT_END,
    /** Automatic alignment. If the specified item is completely in the display area, no adjustments will be made.
     * Otherwise, according to the principle of the shortest sliding distance, align the head or tail of the specified
     * item with the container, so that the specified item is completely in the display area.*/
    ARKUI_SCROLL_ALIGNMENT_AUTO,
} ArkUI_ScrollAlignment;

/**
 * @brief Define the current scrolling state.
 *
 * @since 12
 */
typedef enum {
    /** Idle state. Trigger when using the method provided by the controller to control scrolling, and trigger when
     * dragging the scroll bar to scroll.*/
    ARKUI_SCROLL_STATE_IDLE = 0,
    /** Scroll state. Triggered when dragging the container with fingers to scroll.*/
    ARKUI_SCROLL_STATE_SCROLL,
    /** Inertial rolling state. Triggered when inertia rolling and bouncing back to the edge are performed after
     * releasing the hand quickly.*/
    ARKUI_SCROLL_STATE_FLING,
} ArkUI_ScrollState;

/**
 * @brief Enumerates the types of the slider in the block direction.
 *
 * @since 12
 */
typedef enum {
    /** Round slider. */
    ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0,
    /** Slider with an image background. */
    ARKUI_SLIDER_BLOCK_STYLE_IMAGE,
    /** Slider in a custom shape. */
    ARKUI_SLIDER_BLOCK_STYLE_SHAPE,
} ArkUI_SliderBlockStyle;

/**
 * @brief Enumerates the scroll directions of the slider.
 *
 * @since 12
 */
typedef enum {
    /** Vertical direction. */
    ARKUI_SLIDER_DIRECTION_VERTICAL = 0,
    /** Horizontal direction. */
    ARKUI_SLIDER_DIRECTION_HORIZONTAL,
} ArkUI_SliderDirection;

/**
 * @brief Enumerates the slider styles.
 *
 * @since 12
 */
typedef enum {
    /** The slider is on the slider track. */
    ARKUI_SLIDER_STYLE_OUT_SET = 0,
    /** The slider is in the slider track. */
    ARKUI_SLIDER_STYLE_IN_SET,
    /** No slider. */
    ARKUI_SLIDER_STYLE_NONE,
} ArkUI_SliderStyle;

/**
 * @brief Enumerates the shapes of the check box
 *
 * @since 12
 */
typedef enum {
    /** Circle. */
    ArkUI_CHECKBOX_SHAPE_CIRCLE = 0,
    /** Rounded square. */
    ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE,
} ArkUI_CheckboxShape;

/**
 * @brief Enumerates the animation playback modes.
 *
 * @since 12
 */
typedef enum {
    /** The animation is played forwards. */
    ARKUI_ANIMATION_PLAY_MODE_NORMAL = 0,
    /** The animation is played reversely. */
    ARKUI_ANIMATION_PLAY_MODE_REVERSE,
    /** The animation is played normally for an odd number of times (1, 3, 5...) and reversely for an even number
     *  of times (2, 4, 6...). */
    ARKUI_ANIMATION_PLAY_MODE_ALTERNATE,
    /** The animation is played reversely for an odd number of times (1, 3, 5...) and normally for an even number
     *  of times (2, 4, 6...). */
    ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE,
} ArkUI_AnimationPlayMode;

/**
 * @brief Defines the image size.
 *
 * @since 12
 */
typedef enum {
    /** The original image aspect ratio is retained. */
    ARKUI_IMAGE_SIZE_AUTO = 0,
    /** The image is scaled with its aspect ratio retained for both sides to be greater than or equal
     *  to the display boundaries. */
    ARKUI_IMAGE_SIZE_COVER,
    /** The image is scaled with its aspect ratio retained for the content to be completely displayed within the display
     *  boundaries. */
    ARKUI_IMAGE_SIZE_CONTAIN,
} ArkUI_ImageSize;

/**
 * @brief Enumerates the adaptive color modes.
 *
 * @since 12
 */
typedef enum {
    /** Adaptive color mode is not used. */
    ARKUI_ADAPTIVE_COLOR_DEFAULT = 0,
    /** Adaptive color mode is used. */
    ARKUI_ADAPTIVE_COLOR_AVERAGE,
} ArkUI_AdaptiveColor;

/**
 * @brief Enumerates the color modes.
 *
 * @since 12
 */
typedef enum {
    /** Following the system color mode. */
    ARKUI_COLOR_MODE_SYSTEM = 0,
    /** Light color mode. */
    ARKUI_COLOR_MODE_LIGHT,
    /** Dark color mode. */
    ARKUI_COLOR_MODE_DARK,
} ArkUI_ColorMode;

/**
 * @brief Enumerates the system color modes.
 *
 * @since 12
 */
typedef enum {
    /** Light color mode. */
    ARKUI_SYSTEM_COLOR_MODE_LIGHT = 0,
    /** Dark color mode. */
    ARKUI_SYSTEM_COLOR_MODE_DARK,
} ArkUI_SystemColorMode;

/**
 * @brief Enumerates the blur styles.
 *
 * @since 12
 */
typedef enum {
    /** Thin material. */
    ARKUI_BLUR_STYLE_THIN = 0,
    /** Regular material. */
    ARKUI_BLUR_STYLE_REGULAR,
    /** Thick material. */
    ARKUI_BLUR_STYLE_THICK,
    /** Material that creates the minimum depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_THIN,
    /** Material that creates a medium shallow depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_REGULAR,
    /** Material that creates a high shallow depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_THICK,
    /** Material that creates the maximum depth of field effect. */
    ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK,
    /** No blur. */
    ARKUI_BLUR_STYLE_NONE,
    /** Component ultra-thin material. */
    ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN,
    /** Component thin material. */
    ARKUI_BLUR_STYLE_COMPONENT_THIN,
    /** Component regular material. */
    ARKUI_BLUR_STYLE_COMPONENT_REGULAR,
    /** Component thick material. */
    ARKUI_BLUR_STYLE_COMPONENT_THICK,
    /** Component ultra-thick material. */
    ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK,
} ArkUI_BlurStyle;

/**
 * @brief Enumerates the activation policies for the background blur effect.
 *
 * @since 19
 */
typedef enum {
    /** The blur effect changes according to the window's focus state;
     *  it is inactive when the window is not in focus and active when the window is in focus. */
    ARKUI_BLUR_STYLE_ACTIVE_POLICY_FOLLOWS_WINDOW_ACTIVE_STATE = 0,
    /** The blur effect is always active. */
    ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_ACTIVE,
    /** The blur effect is always inactive. */
    ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_INACTIVE,
} ArkUI_BlurStyleActivePolicy;

/**
 * @brief Enumerates the vertical alignment modes.
 *
 * @since 12
 */
typedef enum {
    /** Top aligned. */
    ARKUI_VERTICAL_ALIGNMENT_TOP = 0,
    /** Center aligned. This is the default alignment mode. */
    ARKUI_VERTICAL_ALIGNMENT_CENTER,
    /** Bottom aligned. */
    ARKUI_VERTICAL_ALIGNMENT_BOTTOM,
} ArkUI_VerticalAlignment;

/**
 * @brief Enumerates the alignment mode in the horizontal direction.
 *
 * @since 12
 */
typedef enum {
    /** Aligned with the start edge in the same direction as the language in use. */
    ARKUI_HORIZONTAL_ALIGNMENT_START = 0,
    /** Center aligned. This is the default alignment mode. */
    ARKUI_HORIZONTAL_ALIGNMENT_CENTER,
    /** Aligned with the end edge in the same direction as the language in use. */
    ARKUI_HORIZONTAL_ALIGNMENT_END,
} ArkUI_HorizontalAlignment;

/**
 * @brief Enumerates the display modes when the text is too long.
 *
 * @since 12
 */
typedef enum {
    /** Extra-long text is not clipped. */
    ARKUI_TEXT_OVERFLOW_NONE = 0,
    /** Extra-long text is clipped. */
    ARKUI_TEXT_OVERFLOW_CLIP,
    /** An ellipsis (...) is used to represent text overflow. */
    ARKUI_TEXT_OVERFLOW_ELLIPSIS,
    /** Text continuously scrolls when text overflow occurs. */
    ARKUI_TEXT_OVERFLOW_MARQUEE,
} ArkUI_TextOverflow;

/**
 * @brief Enumerates the alignment mode of the image with the text.
 *
 * @since 12
 */
typedef enum {
    /** The image is bottom aligned with the text baseline. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0,
    /** The image is bottom aligned with the text. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM,
    /** The image is centered aligned with the text. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER,
    /** The image is top aligned with the text. */
    ARKUI_IMAGE_SPAN_ALIGNMENT_TOP,
    /**
     * The image alignment mode follows the text component's alignment mode.
     *
     * @since 20
     */
    ARKUI_IMAGE_SPAN_ALIGNMENT_FOLLOW_PARAGRAPH,
} ArkUI_ImageSpanAlignment;

/**
 * @brief Defines how the image is resized to fit its container.
 *ImageSpanAlignment
 * @since 12
 */
typedef enum {
    /** The image is scaled with its aspect ratio retained for the content to be completely displayed within the
     *  display boundaries. */
    ARKUI_OBJECT_FIT_CONTAIN = 0,
    /** The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the
     *  display boundaries. */
    ARKUI_OBJECT_FIT_COVER,
    /** The image is scaled automatically to fit the display area. */
    ARKUI_OBJECT_FIT_AUTO,
    /** The image is scaled to fill the display area, and its aspect ratio is not retained. */
    ARKUI_OBJECT_FIT_FILL,
    /** The image content is displayed with its aspect ratio retained. The size is smaller than or equal to the
     *  original size. */
    ARKUI_OBJECT_FIT_SCALE_DOWN,
    /** The original size is retained. */
    ARKUI_OBJECT_FIT_NONE,
    /** Not resized, the image is aligned with the start edge of the top of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_START,
    /** Not resized, the image is horizontally centered at the top of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP,
    /** Not resized, the image is aligned with the end edge at the top of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_END,
    /** Not resized, the image is vertically centered on the start edge of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_START,
    /** Not resized, the image is horizontally and vertically centered in the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_CENTER,
    /** Not resized, the image is vertically centered on the end edge of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_END,
    /** Not resized, the image is aligned with the start edge at the bottom of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_START,
    /** Not resized, the image is horizontally centered at the bottom of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM,
    /** Not resized, the image is aligned with the end edge at the bottom of the container. */
    ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_END,
} ArkUI_ObjectFit;

/**
 * @brief Enumerates the image interpolation effect.
 *
 * @since 12
 */
typedef enum {
    /** No image interpolation. */
    ARKUI_IMAGE_INTERPOLATION_NONE = 0,
    /** Low quality interpolation. */
    ARKUI_IMAGE_INTERPOLATION_LOW,
    /** Medium quality interpolation. */
    ARKUI_IMAGE_INTERPOLATION_MEDIUM,
    /** High quality interpolation. This mode produces scaled images of the highest possible quality. */
    ARKUI_IMAGE_INTERPOLATION_HIGH,
} ArkUI_ImageInterpolation;

/**
 * @brief Enumerates the blend modes.
 *
 * @since 12
 */
typedef enum {
    /** The top image is superimposed on the bottom image without any blending. */
    ARKUI_BLEND_MODE_NONE = 0,
    /** The target pixels covered by the source pixels are erased by being turned to completely transparent. */
    ARKUI_BLEND_MODE_CLEAR,
    /** r = s: Only the source pixels are displayed. */
    ARKUI_BLEND_MODE_SRC,
    /** r = d: Only the target pixels are displayed. */
    ARKUI_BLEND_MODE_DST,
    /** r = s + (1 - sa) * d: The source pixels are blended based on opacity and cover the target pixels. */
    ARKUI_BLEND_MODE_SRC_OVER,
    /** r = d + (1 - da) * s: The target pixels are blended based on opacity and cover on the source pixels. */
    ARKUI_BLEND_MODE_DST_OVER,
    /** r = s * da: Only the part of the source pixels that overlap with the target pixels is displayed. */
    ARKUI_BLEND_MODE_SRC_IN,
    /** r = d * sa: Only the part of the target pixels that overlap with the source pixels is displayed. */
    ARKUI_BLEND_MODE_DST_IN,
    /** r = s * (1 - da): Only the part of the source pixels that do not overlap with the target pixels is displayed. */
    ARKUI_BLEND_MODE_SRC_OUT,
    /** r = d * (1 - sa): Only the part of the target pixels that do not overlap with the source pixels is displayed. */
    ARKUI_BLEND_MODE_DST_OUT,
    /** r = s * da + d * (1 - sa): The part of the source pixels that overlap with the target pixels is displayed and
     *  the part of the target pixels that do not overlap with the source pixels are displayed.
     */
    ARKUI_BLEND_MODE_SRC_ATOP,
    /** r = d * sa + s * (1 - da): The part of the target pixels that overlap with the source pixels and the part of
     *  the source pixels that do not overlap with the target pixels are displayed.
     */
    ARKUI_BLEND_MODE_DST_ATOP,
    /** r = s * (1 - da) + d * (1 - sa): Only the non-overlapping part between the source pixels and the target pixels
     * is displayed. */
    ARKUI_BLEND_MODE_XOR,
    /** r = min(s + d, 1): New pixels resulting from adding the source pixels to the target pixels are displayed. */
    ARKUI_BLEND_MODE_PLUS,
    /** r = s * d: New pixels resulting from multiplying the source pixels with the target pixels are displayed. */
    ARKUI_BLEND_MODE_MODULATE,
    /** r = s + d - s * d: Pixels are blended by adding the source pixels to the target pixels and subtracting the
     *  product of their multiplication. */
    ARKUI_BLEND_MODE_SCREEN,
    /** The MULTIPLY or SCREEN mode is used based on the target pixels. */
    ARKUI_BLEND_MODE_OVERLAY,
    /** rc = s + d - max(s * da, d * sa), ra = kSrcOver: When two colors overlap, whichever is darker is used. */
    ARKUI_BLEND_MODE_DARKEN,
    /** rc = s + d - min(s * da, d * sa), ra =
       kSrcOver: The final pixels are composed of the lightest values of pixels. */
    ARKUI_BLEND_MODE_LIGHTEN,
    /** The colors of the target pixels are lightened to reflect the source pixels. */
    ARKUI_BLEND_MODE_COLOR_DODGE,
    /** The colors of the target pixels are darkened to reflect the source pixels. */
    ARKUI_BLEND_MODE_COLOR_BURN,
    /** The MULTIPLY or SCREEN mode is used, depending on the source pixels. */
    ARKUI_BLEND_MODE_HARD_LIGHT,
    /** The LIGHTEN or DARKEN mode is used, depending on the source pixels. */
    ARKUI_BLEND_MODE_SOFT_LIGHT,
    /** rc = s + d - 2 * (min(s * da, d * sa)), ra =
       kSrcOver: The final pixel is the result of subtracting the darker of the two pixels (source and target) from
       the lighter one. */
    ARKUI_BLEND_MODE_DIFFERENCE,
    /** rc = s + d - two(s * d), ra = kSrcOver: The final pixel is similar to <b>DIFFERENCE</b>, but with less contrast.
     */
    ARKUI_BLEND_MODE_EXCLUSION,
    /** r = s * (1 - da) + d * (1 - sa) + s * d: The final pixel is the result of multiplying the source pixel
     *  by the target pixel.	 */
    ARKUI_BLEND_MODE_MULTIPLY,
    /** The resultant image is created with the luminance and saturation of the source image and the hue of the target
     *  image. */
    ARKUI_BLEND_MODE_HUE,
    /** The resultant image is created with the luminance and hue of the target image and the saturation of the source
     *  image. */
    ARKUI_BLEND_MODE_SATURATION,
    /** The resultant image is created with the saturation and hue of the source image and the luminance of the target
     *  image. */
    ARKUI_BLEND_MODE_COLOR,
    /** The resultant image is created with the saturation and hue of the target image and the luminance of the source
     *  image. */
    ARKUI_BLEND_MODE_LUMINOSITY,
} ArkUI_BlendMode;

/**
 * @brief Enumerates the modes in which components are laid out along the main axis of the container.
 *
 * @since 12
 */
typedef enum {
    /** Components are arranged from left to right. */
    ARKUI_DIRECTION_LTR = 0,
    /** Components are arranged from right to left. */
    ARKUI_DIRECTION_RTL,
    /** The default layout direction is used. */
    ARKUI_DIRECTION_AUTO = 3,
} ArkUI_Direction;

/**
 * @brief Enumerates the modes in which components are laid out along the cross axis of the container.
 *
 * @since 12
 */
typedef enum {
    /** The default configuration in the container is used. */
    ARKUI_ITEM_ALIGNMENT_AUTO = 0,
    /** The items in the container are aligned with the cross-start edge. */
    ARKUI_ITEM_ALIGNMENT_START,
    /** The items in the container are centered along the cross axis. */
    ARKUI_ITEM_ALIGNMENT_CENTER,
    /** The items in the container are aligned with the cross-end edge. */
    ARKUI_ITEM_ALIGNMENT_END,
    /** The items in the container are stretched and padded along the cross axis. */
    ARKUI_ITEM_ALIGNMENT_STRETCH,
    /** The items in the container are aligned in such a manner that their text baselines are aligned along the
     *  cross axis. */
    ARKUI_ITEM_ALIGNMENT_BASELINE,
} ArkUI_ItemAlignment;

/**
 * @brief Enumerates the foreground colors.
 *
 * @since 12
 */
typedef enum {
    /** The foreground colors are the inverse of the component background colors. */
    ARKUI_COLOR_STRATEGY_INVERT = 0,
    /** The shadow colors of the component are the average color obtained from the component background shadow area. */
    ARKUI_COLOR_STRATEGY_AVERAGE,
    /** The shadow colors of the component are the primary color obtained from the component background shadow area. */
    ARKUI_COLOR_STRATEGY_PRIMARY,
} ArkUI_ColorStrategy;

/**
 * @brief Enumerates the vertical alignment modes.
 *
 * @since 12
 */
typedef enum {
    /** The child components are aligned with the start edge of the main axis. */
    ARKUI_FLEX_ALIGNMENT_START = 1,
    /** The child components are aligned in the center of the main axis. */
    ARKUI_FLEX_ALIGNMENT_CENTER = 2,
    /** The child components are aligned with the end edge of the main axis. */
    ARKUI_FLEX_ALIGNMENT_END = 3,
    /** The child components are evenly distributed along the main axis. The space between any two adjacent components
     *  is the same. The first component is aligned with the main-start, and the last component is aligned with
     *  the main-end. */
    ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6,
    /** The child components are evenly distributed along the main axis. The space between any two adjacent components
     *  is the same. The space between the first component and main-start, and that between the last component and
     *  cross-main are both half the size of the space between two adjacent components. */
    ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7,
    /** The child components are evenly distributed along the main axis. The space between the first component
     *  and main-start, the space between the last component and main-end, and the space between any two adjacent
     *  components are the same. */
    ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8,
} ArkUI_FlexAlignment;

/**
 * @brief Enumerates the directions of the main axis in the flex container.
 *
 * @since 12
 */
typedef enum {
    /** The child components are arranged in the same direction as the main axis runs along the rows. */
    ARKUI_FLEX_DIRECTION_ROW = 0,
    /** The child components are arranged in the same direction as the main axis runs down the columns. */
    ARKUI_FLEX_DIRECTION_COLUMN,
    /** The child components are arranged opposite to the <b>ROW</b> direction. */
    ARKUI_FLEX_DIRECTION_ROW_REVERSE,
    /** The child components are arranged opposite to the <b>COLUMN</b> direction. */
    ARKUI_FLEX_DIRECTION_COLUMN_REVERSE,
} ArkUI_FlexDirection;

/**
 * @brief Defines whether the flex container has a single line or multiple lines.
 *
 * @since 12
 */
typedef enum {
    /** The child components in the flex container are arranged in a single line, and they cannot overflow. */
    ARKUI_FLEX_WRAP_NO_WRAP = 0,
    /** The child components in the flex container are arranged in multiple lines, and they may overflow. */
    ARKUI_FLEX_WRAP_WRAP,
    /** The child components in the flex container are reversely arranged in multiple lines, and they may overflow. */
    ARKUI_FLEX_WRAP_WRAP_REVERSE,
} ArkUI_FlexWrap;

/**
 * @brief Enumerates the visibility values.
 *
 * @since 12
 */
typedef enum {
    /** The component is visible. */
    ARKUI_VISIBILITY_VISIBLE = 0,
    /** The component is hidden, and a placeholder is used for it in the layout. */
    ARKUI_VISIBILITY_HIDDEN,
    /** The component is hidden. It is not involved in the layout, and no placeholder is used for it. */
    ARKUI_VISIBILITY_NONE,
} ArkUI_Visibility;

/**
 * @brief Enumerates the alignment modes between the calendar picker and the entry component.
 *
 * @since 12
 */
typedef enum {
    /** Left aligned. */
    ARKUI_CALENDAR_ALIGNMENT_START = 0,
    /** Center aligned. */
    ARKUI_CALENDAR_ALIGNMENT_CENTER,
    /** Right aligned. */
    ARKUI_CALENDAR_ALIGNMENT_END,
} ArkUI_CalendarAlignment;

/**
 * @brief Enumerates the mask types.
 *
 * @since 12
 */
typedef enum {
    /** Rectangle. */
    ARKUI_MASK_TYPE_RECTANGLE = 0,
    /** Circle. */
    ARKUI_MASK_TYPE_CIRCLE,
    /** Ellipse. */
    ARKUI_MASK_TYPE_ELLIPSE,
    /** Path. */
    ARKUI_MASK_TYPE_PATH,
    /** Progress indicator. */
    ARKUI_MASK_TYPE_PROGRESS,
} ArkUI_MaskType;

/**
 * @brief Enumerates the clipping region types.
 *
 * @since 12
 */
typedef enum {
    /** Rectangle. */
    ARKUI_CLIP_TYPE_RECTANGLE = 0,
    /** Circle. */
    ARKUI_CLIP_TYPE_CIRCLE,
    /** Ellipse. */
    ARKUI_CLIP_TYPE_ELLIPSE,
    /** Path. */
    ARKUI_CLIP_TYPE_PATH,
} ArkUI_ClipType;

/**
 * @brief Defines the gradient color stop structure.
 *
 * @since 12
 */
typedef struct {
    /** Color array. */
    const uint32_t* colors;
    /** Position array. */
    float* stops;
    /** Length array. */
    int size;
} ArkUI_ColorStop;

/**
 * @brief Enumerates the custom shapes.
 *
 * @since 12
 */
typedef enum {
    /** Rectangle. */
    ARKUI_SHAPE_TYPE_RECTANGLE = 0,
    /** Circle. */
    ARKUI_SHAPE_TYPE_CIRCLE,
    /** Ellipse. */
    ARKUI_SHAPE_TYPE_ELLIPSE,
    /** Path. */
    ARKUI_SHAPE_TYPE_PATH,
} ArkUI_ShapeType;

/**
 * @brief Enumerates the gradient directions.
 *
 * @since 12
 */
typedef enum {
    /** From right to left. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT = 0,
    /** From bottom to top. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_TOP,
    /** From left to right. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT,
    /** From top to bottom. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM,
    /** From lower right to upper left. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP,
    /** From upper right to lower left. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM,
    /** From lower left to upper right. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP,
    /** From upper left to lower right. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM,
    /** No gradient. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_NONE,
    /** Custom direction. */
    ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM,
} ArkUI_LinearGradientDirection;

/**
 * @brief Enumerates the word break rules.
 *
 * @since 12
 */
typedef enum {
    /** Word breaks can occur between any two characters for Chinese, Japanese, and Korean (CJK) text, but can occur
     *  only at a space character for non-CJK text (such as English). */
    ARKUI_WORD_BREAK_NORMAL = 0,
    /** Word breaks can occur between any two characters for non-CJK text. CJK text behavior is the same as for
     *  <b>NORMAL</b>. */
    ARKUI_WORD_BREAK_BREAK_ALL,
    /** This option has the same effect as <b>BREAK_ALL</b> for non-CJK text, except that if it preferentially wraps
     *  lines at appropriate characters (for example, spaces) whenever possible.
        CJK text behavior is the same as for <b>NORMAL</b>. */
    ARKUI_WORD_BREAK_BREAK_WORD,
    /**
     * @brief Line breaks can occur between any two syllabic units for non-CJK text.
     * CJK text behavior is the same as for <b>NORMAL</b>.
     * @since 18
     */
    ARKUI_WORD_BREAK_HYPHENATION,
} ArkUI_WordBreak;

/**
 * @brief Enumerates the ellipsis positions.
 *
 * @since 12
 */
typedef enum {
    /** An ellipsis is used at the start of the line of text. */
    ARKUI_ELLIPSIS_MODE_START = 0,
    /** An ellipsis is used at the center of the line of text. */
    ARKUI_ELLIPSIS_MODE_CENTER,
    /** An ellipsis is used at the end of the line of text. */
    ARKUI_ELLIPSIS_MODE_END,
} ArkUI_EllipsisMode;

/**
 * @brief Enumerates the image rendering modes.
 *
 * @since 12
 */
typedef enum {
    /** Render image pixels as they are in the original source image. */
    ARKUI_IMAGE_RENDER_MODE_ORIGINAL = 0,
    /** Render image pixels to create a monochrome template image. */
    ARKUI_IMAGE_RENDER_MODE_TEMPLATE,
} ArkUI_ImageRenderMode;

/**
 * @brief Enumerates the slide-in and slide-out positions of the component from the screen edge during transition.
 *
 * @since 12
 */
typedef enum {
    /** Top edge of the window. */
    ARKUI_TRANSITION_EDGE_TOP = 0,
    /** Bottom edge of the window. */
    ARKUI_TRANSITION_EDGE_BOTTOM,
    /** Left edge of the window. */
    ARKUI_TRANSITION_EDGE_START,
    /** Right edge of the window. */
    ARKUI_TRANSITION_EDGE_END,
} ArkUI_TransitionEdge;

/**
 * @brief Defines how the specified blend mode is applied.
 *
 * @since 12
 */
typedef enum {
    /** The content of the view is blended in sequence on the target image. */
    BLEND_APPLY_TYPE_FAST = 0,
    /** The content of the component and its child components are drawn on the offscreen canvas, and then blended with
     *  the existing content on the canvas. */
    BLEND_APPLY_TYPE_OFFSCREEN,
} ArkUI_BlendApplyType;

/**
 * @brief Defines a mask area.
 *
 * @since 12
 */
typedef struct {
    /** X coordinate of the mask area. */
    float x;
    /** Y coordinate of the mask area. */
    float y;
    /** Width of the mask area. */
    float width;
    /** Height of the mask area. */
    float height;
} ArkUI_Rect;

/**
 * @brief Describes the width and height of a component.
 *
 * @since 12
 */
typedef struct {
    /** Width, in px. */
    int32_t width;
    /** Height, in px. */
    int32_t height;
} ArkUI_IntSize;

/**
 * @brief Describes the position of a component.
 *
 * @since 12
 */
typedef struct {
    /** Horizontal coordinate, in px. */
    int32_t x;
    /** Vertical coordinate, in px. */
    int32_t y;
} ArkUI_IntOffset;

/**
 * @brief Enumerates the animation onFinish callback types.
 *
 * @since 12
 */
typedef enum {
    /** The callback is invoked when the entire animation is removed once it has finished. */
    ARKUI_FINISH_CALLBACK_REMOVED = 0,
    /** The callback is invoked when the animation logically enters the falling state, though it may still be in its
      * long tail state. */
    ARKUI_FINISH_CALLBACK_LOGICALLY,
} ArkUI_FinishCallbackType;

/**
 * @brief Enumerates the alignment modes of items along the cross axis.
  *
 * @since 12
 */
typedef enum {
    /** The list items are packed toward the start edge of the list container along the cross axis. */
    ARKUI_LIST_ITEM_ALIGNMENT_START = 0,
    /** The list items are centered in the list container along the cross axis. */
    ARKUI_LIST_ITEM_ALIGNMENT_CENTER,
    /** The list items are packed toward the end edge of the list container along the cross axis. */
    ARKUI_LIST_ITEM_ALIGNMENT_END,
} ArkUI_ListItemAlignment;

/**
  * @brief defines the direction of the barrier line.
  *
  * @since 12
  */
typedef enum {
    /** The barrier is the leftmost of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_START = 0,
    /** The barrier is on the rightmost side of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_END,
    /** The barrier is at the top of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_TOP,
    /** The barrier is at the bottom of all its referencedIds. */
    ARKUI_BARRIER_DIRECTION_BOTTOM
} ArkUI_BarrierDirection;

/**
  * @brief defines the style of the chain.
  *
  * @since 12
  */
typedef enum {
    /** Components are evenly distributed among constraint anchor points. */
    ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD = 0,
    /** Except for the first and last two sub-components,
      * other components are evenly distributed between the constraint anchor points. */
    ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE,
    /** No gaps in subcomponents within the chain. */
    ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED,
} ArkUI_RelativeLayoutChainStyle;

/**
 * @brief Describes the margins of a component.
 *
 * @since 12
 */
typedef struct {
    /** Top margin, in vp. */
    float top;
    /** Right margin, in vp. */
    float right;
    /** Bottom margin, in vp. */
    float bottom;
    /** Left margin, in vp. */
    float left;
} ArkUI_Margin;

/**
 * @brief Enumerates the component units.
 *
 * @since 12
 */
typedef enum {
    /** Default, which is fp for fonts and vp for non-fonts. */
    ARKUI_LENGTH_METRIC_UNIT_DEFAULT = -1,
    /** px. */
    ARKUI_LENGTH_METRIC_UNIT_PX = 0,
    /** vp. */
    ARKUI_LENGTH_METRIC_UNIT_VP,
    /** fp. */
    ARKUI_LENGTH_METRIC_UNIT_FP
} ArkUI_LengthMetricUnit;

/**
 * @brief Enumerates the render fit.
 *
 * @since 12
 */
typedef enum {
    /** Maintains the content size of the animation's final state,
      * and the content is always centered with the component.*/
    ARKUI_RENDER_FIT_CENTER = 0,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned with the top center of the component. */
    ARKUI_RENDER_FIT_TOP,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned with the bottom center of the component. */
    ARKUI_RENDER_FIT_BOTTOM,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned to the left of the component. */
    ARKUI_RENDER_FIT_LEFT,
    /** Maintains the content size of the animation's final state,
      * and the content is always right-aligned with the component. */
    ARKUI_RENDER_FIT_RIGHT,
    /** Maintains the content size of the animation's final state,
      * and the content is always aligned with the top left corner of the component. */
    ARKUI_RENDER_FIT_TOP_LEFT,
    /** Keep the content size of the animation final state,
      * and the content is always aligned with the upper right corner of the component. */
    ARKUI_RENDER_FIT_TOP_RIGHT,
    /** Keep the content size of the animation final state,
      * and the content always aligns with the lower-left corner of the component. */
    ARKUI_RENDER_FIT_BOTTOM_LEFT,
    /** Keep the content size of the animation final state,
      *and the content always aligns with the lower-right corner of the component. */
    ARKUI_RENDER_FIT_BOTTOM_RIGHT,
    /** The aspect ratio of the animation's final state content is not considered,
      *and the content is always scaled to the size of the component. */
    ARKUI_RENDER_FIT_RESIZE_FILL,
    /** Reduce or enlarge the aspect ratio of the animation final state content,
      * so that the content is fully displayed in the component,
      * and keep the center aligned with the component. */
    ARKUI_RENDER_FIT_RESIZE_CONTAIN,
    /** Keep the aspect ratio of the animation final state content to reduce or enlarge,
      * so that the content is fully displayed in the component.
      * When there is left over in the broad direction of the component,
      * the content is aligned to the left of the component,
      * and when there is left over in the high direction of the component,
      * the content is aligned to the top of the component. */
    ARKUI_RENDER_FIT_RESIZE_CONTAIN_TOP_LEFT,
    /** Keep the aspect ratio of the animation final state content to reduce or enlarge,
      * so that the content is fully displayed in the component.
      * When there is left in the wide direction of the component,
      * the content is aligned with the component on the right.
      * When there is left in the high direction of the component,
      * the content is aligned with the component on the bottom. */
    ARKUI_RENDER_FIT_RESIZE_CONTAIN_BOTTOM_RIGHT,
    /** Keep the aspect ratio of the animation final state content reduced or enlarged,
      * so that both sides of the content are greater than or equal to both sides of the component,
      * and keep the center aligned with the component to display the middle part of the content. */
    ARKUI_RENDER_FIT_RESIZE_COVER,
    /** Keep the aspect ratio of the final content of the animation reduced or enlarged
      * so that both sides of the content are exactly greater than or equal to both sides of the component.
      * When the content width is left, the content is aligned to the left of the component,
      * and the left portion of the content is displayed. When the content is left in the high direction,
      * the content and the component remain top aligned, showing the top side of the content. */
    ARKUI_RENDER_FIT_RESIZE_COVER_TOP_LEFT,
    /** Keep the aspect ratio of the final content of the animation reduced or enlarged so
      * that both sides of the content are exactly greater than or equal to both sides of the component.
      * When the content width is left, the content and the component remain right aligned,
      * and the right part of the content is displayed. When the content is left in the high direction,
      * the content and the component remain aligned at the bottom,
      * and the bottom part of the content is displayed. */
    ARKUI_RENDER_FIT_RESIZE_COVER_BOTTOM_RIGHT
} ArkUI_RenderFit;

/**
 * @brief Enumerates the button types.
 *
 * @since 12
 */
typedef enum {
    /** Normal button (without rounded corners by default). */
    ARKUI_BUTTON_TYPE_NORMAL = 0,
    /** Capsule-type button (the round corner is half of the height by default). */
    ARKUI_BUTTON_TYPE_CAPSULE,
    /** Circle button. */
    ARKUI_BUTTON_TYPE_CIRCLE,
    /**
     * Rounded rectangle button.
     * @since 19
     */
    ARKUI_BUTTON_ROUNDED_RECTANGLE = 8
} ArkUI_ButtonType;

/**
 * @brief Enumerates the autofill types.
 *
 * @since 12
 */
typedef enum {
    /** Username. Password Vault, when enabled, can automatically save and fill in usernames. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_USER_NAME = 0,
    /** Password. Password Vault, when enabled, can automatically save and fill in passwords. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PASSWORD,
    /** New password. Password Vault, when enabled, can automatically generate a new password. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_NEW_PASSWORD,
    /** Full street address. The scenario-based autofill feature, when enabled, can automatically save and fill in full
     *  street addresses. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_STREET_ADDRESS,
    /** House number. The scenario-based autofill feature, when enabled, can automatically save and fill in house
     *  numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_HOUSE_NUMBER,
    /** District and county. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  districts and counties. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_DISTRICT_ADDRESS,
    /** City. The scenario-based autofill feature, when enabled, can automatically save and fill in cities. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_CITY_ADDRESS,
    /** Province. The scenario-based autofill feature, when enabled, can automatically save and fill in provinces. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PROVINCE_ADDRESS,
    /** Country. The scenario-based autofill feature, when enabled, can automatically save and fill in countries. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_COUNTRY_ADDRESS,
    /** Full name. The scenario-based autofill feature, when enabled, can automatically save and fill in full names. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FULL_NAME,
    /** Last name. The scenario-based autofill feature, when enabled, can automatically save and fill in last names. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_LAST_NAME,
    /** First name. The scenario-based autofill feature, when enabled, can automatically save and fill in first names.
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FIRST_NAME,
    /** Phone number. The scenario-based autofill feature, when enabled, can automatically save and fill in phone
     *  numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_NUMBER,
    /** Country code. The scenario-based autofill feature, when enabled, can automatically save and fill in country
     *  codes. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_COUNTRY_CODE,
    /** Phone number with country code. The scenario-based autofill feature, when enabled, can automatically save and
     *  fill in phone numbers with country codes. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_PHONE_NUMBER,
    /** Email address. The scenario-based autofill feature, when enabled, can automatically save and fill in email
     *  addresses. */
    ARKUI_TEXTINPUT_CONTENT_EMAIL_ADDRESS,
    /** Bank card number. The scenario-based autofill feature, when enabled, can automatically save and fill in bank
     *  card numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_BANK_CARD_NUMBER,
    /** ID card number. The scenario-based autofill feature, when enabled, can automatically save and fill in ID card
     *  numbers. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ID_CARD_NUMBER,
    /** Nickname. The scenario-based autofill feature, when enabled, can automatically save and fill in nicknames. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_NICKNAME,
    /** Address information without street address. The scenario-based autofill feature, when enabled, can automatically
     *  save and fill in address information without street addresses. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_DETAIL_INFO_WITHOUT_STREET,
    /** Standard address. The scenario-based autofill feature, when enabled, can automatically save and fill in standard
     *  addresses. */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FORMAT_ADDRESS,
    /**
     * Passport number. The scenario-based autofill feature, when enabled, can automatically save and fill in passport
     * numbers.
     * @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_PASSPORT_NUMBER,
    /**
     *  Passport validity. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  passport validities.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_VALIDITY,
    /**
     *  Place of issue. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  place of issues.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ISSUE_AT,
    /**
     *  Tax organization. The scenario-based autofill feature, when enabled, can automatically save and fill in tax
     *  organizations.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ORGANIZATION,
    /**
     *  Tax id. The scenario-based autofill feature, when enabled, can automatically save and fill in standard Tax ids.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_TAX_ID,
    /**
     *  City name and state name or state code. The scenario-based autofill feature, when enabled, can automatically
     *  save and fill in city names and state names or state codes.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ADDRESS_CITY_AND_STATE,
    /**
     *  Flight number. The scenario-based autofill feature, when enabled, can automatically save and fill in flight
     *  numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_FLIGHT_NUMBER,
    /**
     *  License number. The scenario-based autofill feature, when enabled, can automatically save and fill in license
     *  numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_NUMBER,
    /**
     *  License file number. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  license file numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_FILE_NUMBER,
    /**
     *  License plate number. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  license plate numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_PLATE,
    /**
     *  Engine number. The scenario-based autofill feature, when enabled, can automatically save and fill in engine
     *  numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_ENGINE_NUMBER,
    /**
     *  License chassis number. The scenario-based autofill feature, when enabled, can automatically save and fill in
     *  license chassis numbers.
     *  @since 18
     */
    ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_CHASSIS_NUMBER,
} ArkUI_TextInputContentType;

/**
 * @brief Defines the text input style.
 *
 * @since 12
 */
typedef enum {
    /** Default style. The caret width is fixed at 1.5 vp, and the caret height is subject to the background height and
     *  font size of the selected text. */
    ARKUI_TEXTINPUT_STYLE_DEFAULT = 0,
    /** Inline input style. The background height of the selected text is the same as the height of the text box. */
    ARKUI_TEXTINPUT_STYLE_INLINE
} ArkUI_TextInputStyle;

/**
 * @brief Defines the keyboard style of input box
 *
 * @since 15
 */
typedef enum {
    /**
     * Default appearance mode, won't adopt immersive styles.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_NONE_IMMERSIVE = 0,
    /**
     * Immersive mode.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_IMMERSIVE = 1,
    /**
     * Light immersive style.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_LIGHT_IMMERSIVE = 2,
    /**
     * Dark immersive style.
     * @since 15
     */
    ARKUI_KEYBOARD_APPEARANCE_DARK_IMMERSIVE = 3,
} ArkUI_KeyboardAppearance;

/**
 * @brief Defines the entity type for text recognition.
 *
 * @since 12
 */
typedef enum {
    /** Phone Number.*/
    ARKUI_TEXT_DATA_DETECTOR_TYPE_PHONE_NUMBER = 0,
    /** Link. */
    ARKUI_TEXT_DATA_DETECTOR_TYPE_URL,
    /** Mailbox. */
    ARKUI_TEXT_DATA_DETECTOR_TYPE_EMAIL,
    /** Address. */
    ARKUI_TEXT_DATA_DETECTOR_TYPE_ADDRESS,
} ArkUI_TextDataDetectorType;

/**
 * @brief Define the navigation indicator type of the swiper.
 *
 * @since 12
 */
typedef enum {
    /** dot type. */
    ARKUI_SWIPER_INDICATOR_TYPE_DOT,
    /** digit type. */
    ARKUI_SWIPER_INDICATOR_TYPE_DIGIT,
} ArkUI_SwiperIndicatorType;

/**
 * @brief Define the pattern of element arrangement in the main axis direction of the Swiper component.
 *
 * @since 12
 */
typedef enum {
    /** In the folded state, when the ListItem slides in the opposite direction to the main axis,
     * the operation item is hidden.*/
    ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0,
    /** In the folded state, when the ListItem slides in the opposite direction to the spindle,
     * the operation item is displayed.*/
    ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED,
    /** Long distance state, the state of deleting a ListItem after it enters the long distance deletion area.*/
    ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING,
} ArkUI_ListItemSwipeActionState;

/**
 * @brief Define the explicit and implicit mode of the SwipeAction method for the Listitem component.
 *
 * @since 12
 */
typedef enum {
    /** The ListItem can continue to be scratched after the distance exceeds the size of the scratched component.*/
    ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0,
    /** The sliding distance of the ListItem cannot exceed the size of the scratched component.*/
    ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE,
} ArkUI_ListItemSwipeEdgeEffect;

/**
 * @brief Define error code enumeration values.
 *
 * @since 12
 */
typedef enum {
    /** @error No errors. */
    ARKUI_ERROR_CODE_NO_ERROR = 0,
    /** @error Parameter error. */
    ARKUI_ERROR_CODE_PARAM_INVALID = 401,
    /**
     * @error CAPI init error.
     * @since 18
     */
    ARKUI_ERROR_CODE_CAPI_INIT_ERROR = 500,
    /**
     * @error Internal error occurs, such as failure occurs because of the internal environment error,
     * or operation failed because of the internal execution failed.
     * @since 15
     */
    ARKUI_ERROR_CODE_INTERNAL_ERROR = 100001,
    /**
     * @error The XComponent is in invalid state.
     * @since 19
     */
    ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID = 103501,
    /** @error The component does not support specific properties or events. */
    ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102,
    /** @error The corresponding operation does not support nodes created by ArkTS. */
    ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED = 106103,
    /** @error The lazy loading adapter is not bound to the component. */
    ARKUI_ERROR_CODE_ADAPTER_NOT_BOUND = 106104,
    /** @error The adapter already exists. */
    ARKUI_ERROR_CODE_ADAPTER_EXIST = 106105,
    /** @error The corresponding node already has a child node and cannot add an adapter. */
    ARKUI_ERROR_CODE_CHILD_NODE_EXIST = 106106,
    /** The parameter length in the parameter event exceeds the limit. */
    ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107,
    /** The data does not exist in the component event. */
    ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108,
    /** The component event does not support return values. */
    ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109,
    /** The index value is invalid. */
    ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200,
    /**  Failed to query route navigation information. */
    ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201,
    /** The buffer size is not large enough. */
    ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202,
    /**
     * @error The node is not on main tree.
     * @since 15
     */
    ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE = 106203,
    /**
     * @error The node is running on invalid thread.
     * @since 20
     */
    ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD = 106204,
    /**
     * @error Force dark config is invalid.
     * @since 20
     */
    ARKUI_ERROR_CODE_FORCE_DARK_CONFIG_INVALID = 106205,
    /**
     * @error The node type is not custom node.
     * @since 20
     */
    ARKUI_ERROR_CODE_NOT_CUSTOM_NODE = 106401,
    /**
     * @error Node already has children.
     * @since 20
     */
    ARKUI_ERROR_CODE_CHILD_EXISTED = 106402,
    /**
     * @error RenderNode parent is existed.
     * @since 20
     */
    ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED = 106403,
    /**
     * @error RenderNode child is not exist.
     * @since 20
     */
    ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST = 106404,
    /**
     * @error Param is out of range.
     * @since 20
     */
    ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE = 106405,
    /**
     * @error The node requesting focus is not focusable.
     * @since 15
     */
    ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE = 150001,
    /**
     * @error The node requesting focus has unfocusable ancestor.
     * @since 15
     */
    ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR = 150002,
    /**
     * @error The node requesting focus does not exists.
     * @since 15
     */
    ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT = 150003,
    /**
     * @error The snapshot taking is timeout.
     * @since 15
     */
    ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT = 160002,
    /** The component is not a scroll container. */
    ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER = 180001,
    /** The buffer is not large enough. */
    ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH = 180002,
    /**
     * @error The event is not a clone event.
     * @since 15
     */
    ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT = 180003,
    /**
     * @error The component status is abnormal.
     * @since 15
     */
    ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL = 180004,
    /**
     * @error No component hit to respond to the event.
     * @since 15
     */
    ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT = 180005,
    /**
     * @error Input event type not supported.
     * @since 20
     */
    ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED = 180006,
    /**
     * @error invalid styled string.
     * @since 14
     */
    ARKUI_ERROR_CODE_INVALID_STYLED_STRING = 180101,
    /**
     * @error The uiContext is invalid.
     * @since 18
     */
    ARKUI_ERROR_CODE_UI_CONTEXT_INVALID = 190001,
    /**
     * @error The callback function is invalid.
     * @since 18
     */
    ARKUI_ERROR_CODE_CALLBACK_INVALID = 190002,
    /**
     * @error The gesture recognizer type is not supported.
     * @since 18
     */
    ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED = 180102,
    /**
     * @error operation is not allowed for current drag drop pharse.
     * @since 19
     */
    ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED = 190004,
} ArkUI_ErrorCode;

/**
 * @brief Defines the playback status for the image animator.
 *
 * @since 12
*/
typedef enum {
    /** The animation is in the initial state. */
    ARKUI_ANIMATION_STATUS_INITIAL,
    /** The animation is being played. */
    ARKUI_ANIMATION_STATUS_RUNNING,
    /** The animation is paused. */
    ARKUI_ANIMATION_STATUS_PAUSED,
    /** The animation is stopped. */
    ARKUI_ANIMATION_STATUS_STOPPED,
} ArkUI_AnimationStatus;

/**
 * @brief Defines the status before and after execution of the animation in the current playback direction.
 *
 * @since 12
*/
typedef enum {
    /** Before execution, the animation does not apply any styles to the target component.
     * After execution, the animation restores the target component to its default state. */
    ARKUI_ANIMATION_FILL_MODE_NONE,
    /** The target component retains the state set by the last keyframe encountered
     * during execution of the animation. */
    ARKUI_ANIMATION_FILL_MODE_FORWARDS,
    /** The animation applies the values defined in the first relevant keyframe once it is applied to
     * the target component, and retains the values during the period set by delay. */
    ARKUI_ANIMATION_FILL_MODE_BACKWARDS,
    /** The animation follows the rules for both Forwards and Backwards,
     * extending the animation attributes in both directions. */
    ARKUI_ANIMATION_FILL_MODE_BOTH,
} ArkUI_AnimationFillMode;

/**
 * @brief Defines the state type for the accessibility checkbox.
 *
 * @since 12
 */
typedef enum {
    /** The Checkbox unchecked. */
    ARKUI_ACCESSIBILITY_UNCHECKED = 0,
    /** The Checkbox checked. */
    ARKUI_ACCESSIBILITY_CHECKED,
} ArkUI_AccessibilityCheckedState;

/**
 * @brief Define accessible action types.
 *
 * @since 12
 */
typedef enum {
    /** click action. */
    ARKUI_ACCESSIBILITY_ACTION_CLICK = 1 << 0,
    /** long click action. */
    ARKUI_ACCESSIBILITY_ACTION_LONG_CLICK = 1 << 1,
    /** cut action. */
    ARKUI_ACCESSIBILITY_ACTION_CUT = 1 << 2,
    /** copy action. */
    ARKUI_ACCESSIBILITY_ACTION_COPY = 1 << 3,
    /** paste action. */
    ARKUI_ACCESSIBILITY_ACTION_PASTE = 1 << 4,
} ArkUI_AccessibilityActionType;

/**
 * @brief Enumerates the animation playback modes.
 *
 * @since 12
 */
typedef enum {
    /** The animation plays in forward loop mode. */
    ARKUI_ANIMATION_DIRECTION_NORMAL = 0,
    /** The animation plays in reverse loop mode. */
    ARKUI_ANIMATION_DIRECTION_REVERSE,
    /** The animation plays in alternating loop mode. When the animation is played for an odd number of times, the
     *  playback is in forward direction. When the animation is played for an even number of times, the playback is in
     *  reverse direction. */
    ARKUI_ANIMATION_DIRECTION_ALTERNATE,
    /** The animation plays in reverse alternating loop mode. When the animation is played for an odd number of times,
     *  the playback is in reverse direction. When the animation is played for an even number of times, the playback is
     *  in forward direction. */
    ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE,
} ArkUI_AnimationDirection;

/**
 * @brief Define the rolling source enumeration value.
 *
 * @since 12
 */
typedef enum {
    /** Finger drag. */
    ARKUI_SCROLL_SOURCE_DRAG = 0,
    /** Inertial roll after finger drag. */
    ARKUI_SCROLL_SOURCE_FLING,
    /** Execute the EdgeEffect.Spring edge effect when crossing the boundary.*/
    ARKUI_SCROLL_SOURCE_EDGE_EFFECT,
    /** Other user input other than dragging, such as mouse wheel, keyboard events, etc.*/
    ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT,
    /** Drag the scroll bar.*/
    ARKUI_SCROLL_SOURCE_SCROLL_BAR,
    /** Inertia scrolling after dragging the scroll bar.*/
    ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING,
    /** The scroll controller causes unanimated scrolling.*/
    ARKUI_SCROLL_SOURCE_SCROLLER,
    /** The scroll controller causes the scroll to drive the painting.*/
    ARKUI_SCROLL_SOURCE_ANIMATION,
} ArkUI_ScrollSource;

/**
 * @brief Defines the translation options for component transition.
 *
 * @since 12
 */
typedef struct {
    /** Translation distance along the x-axis. */
    float x;
    /** Translation distance along the y-axis. */
    float y;
    /** Translation distance along the z-axis. */
    float z;
} ArkUI_TranslationOptions;

/**
 * @brief Defines the scaling options for component transition.
 *
 * @since 12
 */
typedef struct {
    /** Scale ratio along the x-axis. */
    float x;
    /** Scale ratio along the y-axis. */
    float y;
    /** Scale factor along the z-axis (not effective for the current 2D graphics). */
    float z;
    /** X coordinate of the center point. */
    float centerX;
    /** Y coordinate of the center point. */
    float centerY;
} ArkUI_ScaleOptions;

/**
 * @brief Defines the rotation options for component transition.
 *
 * @since 12
 */
typedef struct {
    /** X-component of the rotation vector. */
    float x;
    /** Y-component of the rotation vector. */
    float y;
    /** Z-component of the rotation vector. */
    float z;
    /** Rotation angle. */
    float angle;
    /** X coordinate of the center point. */
    float centerX;
    /** Y coordinate of the center point. */
    float centerY;
    /** Z-axis anchor, that is, the z-component of the 3D rotation center point. */
    float centerZ;
    /** Distance from the user to the z=0 plane. */
    float perspective;
} ArkUI_RotationOptions;

/**
 * @brief Defines a struct for the measurement information of a custom span.
 *
 * @since 12
 */
typedef struct ArkUI_CustomSpanMeasureInfo ArkUI_CustomSpanMeasureInfo;

/**
 * @brief Defines a struct for the measurement metrics of a custom span.
 *
 * @since 12
 */
typedef struct ArkUI_CustomSpanMetrics ArkUI_CustomSpanMetrics;

/**
 * @brief Defines a struct for the drawing information of a custom span.
 *
 * @since 12
 */
typedef struct ArkUI_CustomSpanDrawInfo ArkUI_CustomSpanDrawInfo;

/**
 * @brief Defines the state of the NavDestination component.
 *
 * @since 12
 */
typedef enum {
    /** The NavDestination show. */
    ARKUI_NAV_DESTINATION_STATE_ON_SHOW = 0,
    /** The NavDestination hide. */
    ARKUI_NAV_DESTINATION_STATE_ON_HIDE = 1,
    /** The NavDestination is mounted to the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_APPEAR = 2,
    /** The NavDestination removed from the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_DISAPPEAR = 3,
    /** Before the NavDestination show. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_SHOW = 4,
    /** Before the NavDestination hide. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_HIDE = 5,
    /** Before the NavDestination mount to the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_APPEAR = 6,
    /** Before the NavDestination removed from the component tree. */
    ARKUI_NAV_DESTINATION_STATE_ON_WILL_DISAPPEAR = 7,
    /** The NavDestination returns from the component.*/
    ARKUI_NAV_DESTINATION_STATE_ON_BACK_PRESS = 100,
} ArkUI_NavDestinationState;

/**
 * @brief Define the state of Router Page.
 *
 * @since 12
 */
typedef enum {
    /** The Router Page is about to be created. */
    ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_APPEAR = 0,
    /** The Router Page is about to be destroyed. */
    ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_DISAPPEAR = 1,
    /** The Router Page show. */
    ARKUI_ROUTER_PAGE_STATE_ON_SHOW = 2,
    /** The Router Page hide. */
    ARKUI_ROUTER_PAGE_STATE_ON_HIDE = 3,
    /** The Router Page returns. */
    ARKUI_ROUTER_PAGE_STATE_ON_BACK_PRESS = 4,
} ArkUI_RouterPageState;

/**
 * @brief defines the enumerated value of the extended security zone.
 *
 * @since 12
 */
typedef enum {
    /** The default security zone includes the status bar and navigation bar. */
    ARKUI_SAFE_AREA_TYPE_SYSTEM = 1,
    /** Non-secure areas of the device, such as bangs or hole holes. */
    ARKUI_SAFE_AREA_TYPE_CUTOUT = 1 << 1,
    /** Soft keyboard area. */
    ARKUI_SAFE_AREA_TYPE_KEYBOARD = 1 << 2,
} ArkUI_SafeAreaType;

/**
 * @brief Define an enum for the areas of the <b>ListItemGroup</b> component.
 *
 * @since 15
 */
typedef enum {
    /** Outside the area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_GROUP_AREA_OUTSIDE = 0,
    /** Area when the <b>ListItemGroup</b> component does not have the header, footer, or list item. */
    ARKUI_LIST_ITEM_SWIPE_AREA_NONE,
    /** List item area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_SWIPE_AREA_ITEM,
    /** Header area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_SWIPE_AREA_HEADER,
    /** Footer area of the <b>ListItemGroup</b> component. */
    ARKUI_LIST_ITEM_SWIPE_AREA_FOOTER,
} ArkUI_ListItemGroupArea;

/**
 * @brief defines the enumerated value of the direction of the extended security zone.
 *
 * @since 12
 */
typedef enum {
    /** Upper area. */
    ARKUI_SAFE_AREA_EDGE_TOP = 1,
    /** Lower area. */
    ARKUI_SAFE_AREA_EDGE_BOTTOM = 1 << 1,
    /** Front area. */
    ARKUI_SAFE_AREA_EDGE_START = 1 << 2,
    /** Tail area. */
    ARKUI_SAFE_AREA_EDGE_END = 1 << 3,
} ArkUI_SafeAreaEdge;

/**
 * @brief Define an enum for the focus movement directions.
 *
 * @since 18
*/
typedef enum {
    /** Move focus forward. */
    ARKUI_FOCUS_MOVE_FORWARD = 0,
    /** Move focus backward. */
    ARKUI_FOCUS_MOVE_BACKWARD,
    /** Move focus up. */
    ARKUI_FOCUS_MOVE_UP,
    /** Move focus down. */
    ARKUI_FOCUS_MOVE_DOWN,
    /** Move focus left. */
    ARKUI_FOCUS_MOVE_LEFT,
    /** Move focus right. */
    ARKUI_FOCUS_MOVE_RIGHT,
} ArkUI_FocusMove;

/**
 * @brief defines the enumerated value of the customDialog's keyboard avoid mode.
 *
 * @since 15
 */
typedef enum {
    /** Defines avoid keyboard when keyboard shows. */
    ARKUI_KEYBOARD_AVOID_MODE_DEFAULT = 0,
    /** Defines not avoid keyboard when keyboard shows. */
    ARKUI_KEYBOARD_AVOID_MODE_NONE,
} ArkUI_KeyboardAvoidMode;

/**
 * @brief defines the enumerated value of area in hover mode.
 *
 * @since 15
 */
typedef enum {
    /** Layout top half screen when the phone in hover mode. */
    ARKUI_HOVER_MODE_AREA_TYPE_TOP = 0,
    /** Layout bottom half screen when the phone in hover mode. */
    ARKUI_HOVER_MODE_AREA_TYPE_BOTTOM,
} ArkUI_HoverModeAreaType;

/**
 * @brief Enumerates the expand modes.
 *
 * @since 15
 */
typedef enum {
    /** Not expand. */
    ARKUI_NOT_EXPAND = 0,
    /** Expand. */
    ARKUI_EXPAND = 1,
    /** Lazy expand. Expand the children of node if needed. */
    ARKUI_LAZY_EXPAND = 2,
} ArkUI_ExpandMode;

/**
 * @brief Defines the navigation point indicator style of the <b><Swiper></b> component.
 * @brief Enumerates the UI states of a component, used for handling state-specific styles.
 *
 * @since 20
 */
typedef enum {
    /** Normal state. */
    UI_STATE_NORMAL = 0,
    /** Pressed state. */
    UI_STATE_PRESSED = 1 << 0,
    /** Focused state. */
    UI_STATE_FOCUSED = 1 << 1,
    /** Disabled state. */
    UI_STATE_DISABLED = 1 << 2,
    /**
     * Selected state. This state is supported only by specific component types:
     * <b>Checkbox</b>, <b>Radio</b>, <b>Toggle</b>, <b>List</b>, <b>Grid</b>, and <b>MenuItem</b>.
     */
    UI_STATE_SELECTED = 1 << 3,
} ArkUI_UIState;

/**
 * @brief Enumerates the edge derection.
 *
 * @since 20
 */
typedef enum {
    /** Set all edge derection. */
    ARKUI_EDGE_DIRECTION_ALL = 0,
    /** Set left edge derection. */
    ARKUI_EDGE_DIRECTION_LEFT,
    /** Set right edge derection. */
    ARKUI_EDGE_DIRECTION_RIGHT,
    /** Set top edge derection. */
    ARKUI_EDGE_DIRECTION_TOP,
    /** Set bottom edge derection. */
    ARKUI_EDGE_DIRECTION_BOTTOM,
} ArkUI_EdgeDirection;
 
/**
 * @brief Enumerates the corner derection.
 *
 * @since 20
 */
typedef enum {
    /** Set all corner derection. */
    ARKUI_CORNER_DIRECTION_ALL = 0,
    /** Set top left corner derection. */
    ARKUI_CORNER_DIRECTION_TOP_LEFT,
    /** Set top right corner derection. */
    ARKUI_CORNER_DIRECTION_TOP_RIGHT,
    /** Set bottom left corner derection. */
    ARKUI_CORNER_DIRECTION_BOTTOM_LEFT,
    /** Set bottom right corner derection. */
    ARKUI_CORNER_DIRECTION_BOTTOM_RIGHT,
} ArkUI_CornerDirection;

/**
 * @brief Defines parameter used by the system font style callback event.
 *
 * @since 12
 */
typedef struct ArkUI_SystemFontStyleEvent ArkUI_SystemFontStyleEvent;

/**
 * @brief Defines the options for taking snapshot.
 *
 * @since 15
 */
typedef struct ArkUI_SnapshotOptions ArkUI_SnapshotOptions;

/**
  * @brief TextPicker single column selector, supports mixing text and images.
  *
  * @since 19
  */
typedef struct ArkUI_TextPickerRangeContentArray ArkUI_TextPickerRangeContentArray;

 /**
   * @brief TextPicker multi column selector, supports mixing text and images.
   *
   * @since 19
   */
typedef struct ArkUI_TextCascadePickerRangeContentArray ArkUI_TextCascadePickerRangeContentArray;

/**
* @brief Creates a size constraint.
*
* @since 12
*/
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create();

/**
* @brief Creates a deep copy of a size constraint.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the pointer to the new size constraint.
* @since 12
*/
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint);

/**
* @brief Destroys the pointer to a size constraint.
*
* @param Constraint Indicates the pointer to the size constraint.
* @since 12
*/
void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint);

/**
* @brief Obtains the maximum width for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the maximum width.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint);

/**
* @brief Obtains the minimum width for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the minimum width.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint);

/**
* @brief Obtains the maximum height for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the maximum height.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint);

/**
* @brief Obtains the minimum height for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the minimum height.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint);

/**
* @brief Obtains the width percentage reference for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the width percentage reference.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint);

/**
* @brief Obtains the height percentage reference for a size constraint, in px.
*
* @param Constraint Indicates the pointer to the size constraint.
* @return Returns the height percentage reference.
* @since 12
*/
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint);

/**
* @brief Sets the maximum width.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the maximum width, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value);

/**
* @brief Sets the minimum width.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the minimum width, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value);

/**
* @brief Sets the maximum height.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the maximum height, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value);

/**
* @brief Sets the minimum height.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the minimum height, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value);

/**
* @brief Sets the width percentage reference.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the width percentage reference, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value);

/**
* @brief Sets the height percentage reference.
*
* @param Constraint Indicates the pointer to the size constraint.
* @param value Indicates the height percentage reference, in px.
* @since 12
*/
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value);

/**
* @brief Obtains the pointer to a canvas for drawing, which can be converted into the <b>OH_Drawing_Canvas</b> pointer
* in the <b>Drawing</b> module.
*
* @param context Indicates the pointer to the drawing context.
* @return Returns the pointer to the canvas for drawing.
* @since 12
*/
void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context);

/**
* @brief Obtains the size of a drawing area.
*
* @param context Indicates the pointer to the drawing context.
* @return Returns the size of the drawing area.
* @since 12
*/
ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context);

/**
* @brief Creates water flow section configuration.
*
* @return Returns the water flow section configuration.
* @since 12
*/
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create();

/**
* @brief Destroys the pointer to a water flow section configuration.
*
* @param option Indicates the pointer to a water flow section configuration.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option);

/**
* @brief Sets the FlowItem block configuration information array length.
*
* @param option FlowItem Indicates the packet configuration.
* @param size Array Length.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size);

/**
* @brief Gets the FlowItem grouping configuration information array length.
*
* @param option FlowItem Indicates the packet configuration.
* @return Array size. If -1 is returned, the return fails.
*         The possible cause of the failure is that the option parameter is abnormal, such as a null pointer.
* @since 12
*/
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option);

/**
* @brief Sets the number of items in a water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param itemCount Indicates the number of items in the water flow section.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option,
    int32_t index, int32_t itemCount);

/**
* @brief Obtains the number of items in the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the number of items in the water flow section.
* @since 12
*/
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index);

/**
* @brief The FlowItem grouping configuration information getsthe spindle size of
* the specified Item based on flowItemIndex.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param callback Gets the spindle size of the specified Item based on index.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(ArkUI_WaterFlowSectionOption* option,
    int32_t index, float(*callback)(int32_t itemIndex));

/**
* @brief The FlowItem grouping configuration information getsthe spindle size of
* the specified Item based on flowItemIndex.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param userData FlowItem Custom data.
* @param callback Gets the spindle size of the specified Item based on index.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData(
    ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData,
    float (*callback)(int32_t itemIndex, void* userData));

/**
* @brief Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param crossCount Indicates the number of columns or rows, depending on the layout direction.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(
    ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount);

/**
* @brief Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) in the water flow section
* that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the number of columns or rows.
* @since 12
*/
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index);

/**
* @brief Sets the gap between columns in the specified water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param columnGap Indicates the gap between columns to set.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option,
    int32_t index, float columnGap);

/**
* @brief Obtains the gap between columns in the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the gap between columns.
* @since 12
*/
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index);

/**
* @brief Sets the gap between rows in the specified water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param rowGap Indicates the gap between rows to set.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option,
    int32_t index, float rowGap);

/**
* @brief Obtains the gap between rows in the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the gap between rows.
* @since 12
*/
float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index);

/**
* @brief Sets the margins for the specified water flow section.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @param marginTop Indicates the top margin of the water flow section.
* @param marginRight Indicates the right margin of the water flow section.
* @param marginBottom Indicates the bottom margin of the water flow section.
* @param marginLeft Indicates the left margin of the water flow section.
* @since 12
*/
void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,
    float marginTop, float marginRight, float marginBottom, float marginLeft);

/**
* @brief Obtains the margins of the water flow section that matches the specified index.
*
* @param option Indicates the pointer to a water flow section configuration.
* @param index Indicates the index of the target water flow section.
* @return Returns the margins.
* @since 12
*/
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index);

/**
 * @brief Creates a navigation indicator.
 *
 * @param type Indicates the type of the indicator.
 * @return Returns the pointer to the new indicator.
 * @since 12
*/
ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create(ArkUI_SwiperIndicatorType type);

/**
 * @brief Destroys the pointer to the indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_Dispose(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the distance between the navigation point and the start of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the start of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetStartPosition(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief Obtains the distance between the navigation point and the start of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the start of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetStartPosition(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the distance between the navigation point and the top of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the top of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetTopPosition(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief Obtains the distance between the navigation point and the top of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the top of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetTopPosition(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the distance between the navigation point and the right of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the right of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetEndPosition(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief Obtains the distance between the navigation point and the end of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the end of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetEndPosition(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the distance between the navigation point and the bottom of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the distance between the navigation point and the bottom of the swiper.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetBottomPosition(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief Obtains the distance between the navigation point and the bottom of the swiper.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the distance between the navigation point and the bottom of the swiper.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetBottomPosition(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the width of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the width of the dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetItemWidth(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief Obtains the width of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the width of the dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetItemWidth(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the height of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the height of the dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetItemHeight(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief  Obtains the height of the dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the height of the dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetItemHeight(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the width of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the width of the selected dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief  Obtains the width of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the width of the selected dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the height of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param value Indicates the height of the selected dot for the dot indicator.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight(ArkUI_SwiperIndicator* indicator, float value);

/**
 * @brief  Obtains the height of the selected dot for the dot indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the height of the selected dot for the dot indicator.
 * @since 12
*/
float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets whether to display the mask style of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param mask Whether to display the mask style. True means to display.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetMask(ArkUI_SwiperIndicator* indicator, int32_t mask);

/**
 * @brief Obtains whether to display the mask style of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns whether to display the mask style. True means to display.
 * @since 12
*/
int32_t OH_ArkUI_SwiperIndicator_GetMask(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the color of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param color the color of the dot navigation indicator, in 0xARGB format.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetColor(ArkUI_SwiperIndicator* indicator, uint32_t color);

/**
 * @brief Obtains the color of the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the color of the dot navigation indicator, in 0xARGB format.
 * @since 12
*/
uint32_t OH_ArkUI_SwiperIndicator_GetColor(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the color of the selected dot for the navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param selectedColor the color of the selected dot, in 0xARGB format.
 * @since 12
*/
void OH_ArkUI_SwiperIndicator_SetSelectedColor(ArkUI_SwiperIndicator* indicator, uint32_t selectedColor);

/**
 * @brief Obtains the color of the selected dot for the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the color of the selected dot, in 0xARGB format.
 * @since 12
*/
uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the number of maxDisplayCount for the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param maxDisplayCount the maxDisplayCount of the navigation dot, span is 6-9.
 * @return {@link ARKUI_ERROR_CODE_NO_ERROR} Success.
 *         {@link ARKUI_ERROR_CODE_PARAM_INVALID} indicator is null or maxDisplayCount less then 6 or
 *         maxDisplayCount more then 9
 * @since 12
*/
int32_t OH_ArkUI_SwiperIndicator_SetMaxDisplayCount(ArkUI_SwiperIndicator* indicator, int32_t maxDisplayCount);

/**
 * @brief Obtains the number of maxDisplayCount for the dot navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns the number of the maxDisplayCount, span is 6-9.
 *         0 - indicator is null
 * @since 12
*/
int32_t OH_ArkUI_SwiperIndicator_GetMaxDisplayCount(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperIndicator_SetBottomPosition}.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param ignoreSize Whether to ignore the size of the indicator. The value 1 means to ignore, and 0 means the opposite.
 * The default value is 0.
 * @since 19
*/
void OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator, int32_t ignoreSize);

/**
 * @brief Obtains whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperIndicator_SetBottomPosition}.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return Returns whether to ignore the size of the indicator.
 * @since 19
*/
int32_t OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Sets the space between the dots of the navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @param space the space between the dots of the navigation indicator, the default value is 8vp.
 * @since 19
*/
void OH_ArkUI_SwiperIndicator_SetSpace(ArkUI_SwiperIndicator* indicator, float space);

/**
 * @brief Obtains the space between the dots of the navigation indicator.
 *
 * @param indicator Indicates the pointer to the indicator.
 * @return the space between the dots of the navigation indicator
 * @since 19
*/
float OH_ArkUI_SwiperIndicator_GetSpace(ArkUI_SwiperIndicator* indicator);

/**
 * @brief Creates a digital indicator.
 *
 * @return Returns the pointer to the new indicator.
 * @since 19
 */
ArkUI_SwiperDigitIndicator *OH_ArkUI_SwiperDigitIndicator_Create();

/**
 * @brief Sets the distance between the digital indicator and the start of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Indicates the distance between the digital indicator and the start of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetStartPosition(ArkUI_SwiperDigitIndicator* indicator, float value);

/**
 * @brief Gets the distance between the digital indicator and the start of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the start of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetStartPosition(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the distance between the digital indicator and the top of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Indicates the distance between the digital indicator and the top of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetTopPosition(ArkUI_SwiperDigitIndicator* indicator, float value);

/**
 * @brief Gets the distance between the digital indicator and the top of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the top of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetTopPosition(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the distance between the digital indicator and the end of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Indicates the distance between the digital indicator and the end of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetEndPosition(ArkUI_SwiperDigitIndicator* indicator, float value);

/**
 * @brief Gets the distance between the digital indicator and the end of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the end of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetEndPosition(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the distance between the digital indicator and the bottom of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @param value Returns the distance between the digital indicator and the bottom of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetBottomPosition(ArkUI_SwiperDigitIndicator* indicator, float value);

/**
 * @brief Gets the distance between the digital indicator and the bottom of the swiper.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns the distance between the digital indicator and the bottom of the swiper.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetBottomPosition(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the font color of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param color font color, in 0xARGB format. Default value: 0xFF182431.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t color);

/**
 * @brief Gets the font color of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font color, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperDigitIndicator_GetFontColor(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the font color of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param selectedColor font color, in 0xARGB format. Default value: 0xFF182431.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t selectedColor);

/**
 * @brief Gets the font color of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font color, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the font size of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param size font size, in fp.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetFontSize(ArkUI_SwiperDigitIndicator* indicator, float size);

/**
 * @brief Gets the font size of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font size, in fp.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetFontSize(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the font size of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param size font size, in fp.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator, float size);

/**
 * @brief Gets the font size of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font size, in fp.
 * @since 19
 */
float OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the font weight of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param fontWeight font weight {@link ArkUI_FontWeight}. The default value is <b>ARKUI_FONT_WEIGHT_NORMAL</b>.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight fontWeight);

/**
 * @brief Gets the font weight of total count in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font weight {@link ArkUI_FontWeight}.
 * @since 19
 */
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Sets the font weight of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @param selectedFontWeight font weight {@link ArkUI_FontWeight}. The default value is <b>ARKUI_FONT_WEIGHT_NORMAL</b>.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight(
    ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight selectedFontWeight);

/**
 * @brief Gets the font weight of selected index in the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @return font weight {@link ArkUI_FontWeight}.
 * @since 19
 */
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Destroys the digital indicator.
 *
 * @param indicator The pointer to the digital indicator.
 * @since 19
 */
void OH_ArkUI_SwiperDigitIndicator_Destroy(ArkUI_SwiperDigitIndicator *indicator);

/**
 * @brief Sets whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperDigitIndicator_SetBottomPosition}.
 *
 * @param indicator The pointer to the digital indicator.
 * @param ignoreSize Whether to ignore the size of the indicator. The value 1 means to ignore, and 0 means the opposite.
 * The default value is 0.
 * @since 19
*/
void OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator, int32_t ignoreSize);

/**
 * @brief Obtains whether to ignore the size of the indicator for {@link OH_ArkUI_SwiperDigitIndicator_SetBottomPosition}.
 *
 * @param indicator The pointer to the digital indicator.
 * @return Returns whether to ignore the size of the indicator.
 * @since 19
*/
int32_t OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator);

/**
 * @brief Creates a arrow style for swiper.
 *
 * @return Returns the pointer to the new arrow style.
 * @since 19
 */
ArkUI_SwiperArrowStyle *OH_ArkUI_SwiperArrowStyle_Create();

/**
 * @brief Sets whether to show the background for the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param showBackground whether to show the background for the arrow.
 *        The value <b>1</b> means to show the background, and <b>0</b> means the opposite.
 *        The default value is <b>0</b>.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetShowBackground(ArkUI_SwiperArrowStyle *arrowStyle, int32_t showBackground);

/**
 * @brief Gets whether to show the background for the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return whether to show the background for the arrow.
 *         The value <b>1</b> means to show the background, and <b>0</b> means the opposite.
 * @since 19
 */
int32_t OH_ArkUI_SwiperArrowStyle_GetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle);

/**
 * @brief Sets the display position of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param showSidebarMiddle the display position of the arrow.
 *        The value <b>1</b> means to display on boths sides of the swiper,
 *        and <b>0</b> means display on boths sides of the swiper indicator.
 *        The default value is <b>0</b>.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showSidebarMiddle);

/**
 * @brief Gets the display position of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return the display position of the arrow. The value <b>1</b> means to display on boths sides of the swiper,
 *         and <b>0</b> means display on boths sides of the swiper indicator.
 * @since 19
 */
int32_t OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle);

/**
 * @brief Sets the background size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param backgroundSize the background size of the arrow. The unit is vp.
 *        The default value is <b>24</b> when the arrow displays on both sides of the swiper indicator.
 *        The default value is <b>32</b> when the arrow displays on both sides of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle, float backgroundSize);

/**
 * @brief Gets the background size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return Returns the background size of the arrow. The unit is vp.
 * @since 19
 */
float OH_ArkUI_SwiperArrowStyle_GetBackgroundSize(ArkUI_SwiperArrowStyle *arrowStyle);

/**
 * @brief Destroys the arrow style.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_Destroy(ArkUI_SwiperArrowStyle *arrowStyle);

/**
 * @brief Sets the background color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param backgroundColor the background color of the arrow, in 0xARGB format.
 *        The default value is <b>0x00000000</b> when the arrow displays on both sides of the swiper indicator.
 *        The default value is <b>0x19182431</b> when the arrow displays on both sides of the swiper.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetBackgroundColor(ArkUI_SwiperArrowStyle *arrowStyle, uint32_t backgroundColor);

/**
 * @brief Gets the background color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return Returns the background color of the arrow, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperArrowStyle_GetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle);

/**
 * @brief Sets the size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param arrowSize the size of the arrow. The unit is vp.
 *        The default value is <b>18</b> when the arrow displays on both sides of the swiper indicator.
 *        The default value is <b>24</b> when the arrow displays on both sides of the swiper.
 *        The arrow size is fixed to 3/4 of the background size when the background is shown.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle, float arrowSize);

/**
 * @brief Gets the size of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return the size of the arrow. The unit is vp.
 * @since 19
 */
float OH_ArkUI_SwiperArrowStyle_GetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle);

/**
 * @brief Sets the color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @param arrowColor the color of the arrow, in 0xARGB format. The default value is <b>0x00182431</b>.
 * @since 19
 */
void OH_ArkUI_SwiperArrowStyle_SetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t arrowColor);

/**
 * @brief Gets the color of the arrow.
 *
 * @param arrowStyle The pointer to the arrow style.
 * @return Returns the color of the arrow, in 0xARGB format.
 * @since 19
 */
uint32_t OH_ArkUI_SwiperArrowStyle_GetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle);

/**
 * @brief Create auxiliary line information in the RelativeContaine container.
 *
 * @param size The number of auxiliary lines.
 * @return auxiliary line information.
 * @since 12
 */
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size);

/**
 * @brief Destroy auxiliary line information.
 *
 * @param guideline auxiliary line information.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline);

/**
 * @brief Set the Id of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param value id, must be unique and cannot have the same name as the component in the container.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index);

/**
 * @brief Set the direction of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param value direction.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index);

/**
 * @brief Set the distance from the left or top of the container.
 *
 * @param guideline auxiliary line information.
 * @param value The distance from the left or top of the container.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index);

/**
 * @brief Set the distance from the right or bottom of the container.
 *
 * @param guideline auxiliary line information.
 * @param value The distance from the right side or bottom of the container.
 * @param index auxiliary line index value.
 * @since 12
 */
void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index);

/**
 * @brief Get the Id of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return Id.
 * @since 12
 */
const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index);

/**
 * @brief Get the direction of the auxiliary line.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return direction.
 * @since 12
 */
ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index);

/**
 * @brief Get the distance from the left or top of the container.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return The distance from the left or top of the container.
 * @since 12
 */
float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index);

/**
 * @brief Get the distance from the right side or bottom of the container.
 *
 * @param guideline auxiliary line information.
 * @param index auxiliary line index value.
 * @return The distance from the right side or bottom of the container.
 * @since 12
 */
float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index);

/**
 * @brief creates barrier information within the RelativeContaine container.
 *
 * @param size Number of barriers.
 * @return barrier information.
 * @since 12
 */
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size);

/**
 * @brief Destroy barrier information.
 *
 * @param barrierStyle barrier information.
 * @since 12
 */
void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle);

/**
 * @brief Set the Id of the barrier.
 *
 * @param barrierStyle barrier information.
 * @param value id, must be unique and cannot have the same name as the component in the container.
 * @param index Barrier index value.
 * @since 12
 */
void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index);

/**
 * @brief Set the direction of the barrier.
 *
 * @param barrierStyle barrier information.
 * @param value direction.
 * @param index Barrier index value.
 * @since 12
 */
void OH_ArkUI_BarrierOption_SetDirection(
    ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index);

/**
 * @brief Sets the dependent component of the barrier.
 *
 * @param barrierStyle barrier information.
 * @param value The ID of the dependent component.
 * @param index Barrier index value.
 * @since 12
 */
void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index);

/**
 * @brief Get the Id of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @return The Id of the barrier.
 * @since 12
 */
const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index);

/**
 * @brief Gets the direction of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @return The direction of the barrier.
 * @since 12
 */
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index);

/**
 * @brief Get the dependent components of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @param referencedIndex dependent component Id index value.
 * @return The barrier's dependent components.
 * @since 12
 */
const char* OH_ArkUI_BarrierOption_GetReferencedId(
    ArkUI_BarrierOption* barrierStyle, int32_t index, int32_t referencedIndex);

/**
 * @brief Gets the number of dependent components of the barrier.
 *
 * @param barrierStyle auxiliary line information.
 * @param index auxiliary line index value.
 * @return The number of dependent components of the barrier.
 * @since 12
 */
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index);

/**
 * @brief creates alignment rule information for subcomponents in relative containers.
 *
 * @return Alignment rule information.
 * @since 12
 */
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create();

/**
 * @brief Destroys the alignment rule information of subcomponents in relative containers.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option);

/**
 * @brief Set the start alignment parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to the anchor component.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetStart(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment);

/**
 * @brief Set the end alignment parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to the anchor component.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetEnd(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment);

/**
* @brief Set the parameters for horizontal center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @param id The id value of the anchor component.
* @param alignment Alignment relative to anchor component
* @since 12
*/
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment);

/**
 * @brief Set the parameters for top alignment.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to anchor component
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id,
    ArkUI_VerticalAlignment alignment);

/**
 * @brief Set the bottom alignment parameters.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param id The id value of the anchor component.
 * @param alignment Alignment relative to anchor component
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetBottom(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment);

/**
* @brief Set the parameters for vertical center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @param id The id value of the anchor component.
* @param alignment Alignment relative to the anchor component.
* @since 12
*/
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(
    ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment);

/**
 * @brief Sets the horizontal offset parameter of the component under the anchor point constraint.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param horizontal bias value in the horizontal direction.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal);

/**
 * @brief Set the vertical offset parameter of the component under the anchor point constraint.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @param vertical bias value in the vertical direction.
 * @since 12
 */
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical);

/**
 * @brief Get the Id of the start-aligned parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return The id value of the anchor component.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option);

/**
* @brief Gets the alignment of the start-aligned parameter.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the parameters.
* @since 12
*/
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option);

/**
 * @brief Get the end alignment parameter.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return End-aligned parameter id.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option);

/**
* @brief Get the end alignment parameter.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the end-aligned parameter.
* @since 12
*/
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option);

/**
* @brief Gets the parameters of horizontal center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The id of the parameter of horizontal center alignment.
* @since 12
*/
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option);

/**
* @brief Gets the parameters of horizontal center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the horizontally centered alignment parameter.
* @since 12
*/
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option);

/**
 * @brief Get the top-aligned parameters.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return Top aligned parameter id.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option);

/**
* @brief Get the top-aligned parameters.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the top-aligned parameter.
* @since 12
*/
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option);

/**
 * @brief Get the bottom alignment parameters.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return The id of the bottom-aligned parameter.
 * @since 12
 */
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option);

/**
* @brief Get the bottom alignment parameters.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the bottom-aligned parameter.
* @since 12
*/
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option);

/**
* @brief Gets the parameters of vertical center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The id of the vertical center alignment parameter.
* @since 12
*/
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option);

/**
* @brief Gets the parameters of vertical center alignment.
*
* @param option Alignment rule information of subcomponents in the relative container.
* @return The alignment of the vertical center alignment parameter.
* @since 12
*/
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option);

/**
 * @brief Get the bias value in the horizontal direction.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return The bias value in the horizontal direction.
 * @since 12
 */
float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option);

/**
 * @brief Get the bias value in the vertical direction.
 *
 * @param option Alignment rule information of subcomponents in the relative container.
 * @return bias value in vertical direction.
 * @since 12
*/
float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option);

/**
 * @brief Create a configuration item for the ListitemSwipeActionItem interface settings.
 *
 * @return List Item SwipeActionItem configuration item instance. If the object returns a null pointer,
 *         it indicates creation failure, and the reason for the failure may be that the address space is full.
 * @since 12
*/
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create();

/**
* @brief Destroy the ListitemSwipeActionItem instance.
*
* @param item List Item SwipeActionItem instance to be destroyed.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item);

/**
* @brief Set the layout content of ListItem SwipeActionItem.
*
* @param item List Item SwipeActionItem instance.
* @param node Layout information.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node);

/**
* @brief Set the threshold for long-distance sliding deletion distance of components.
*
* @param item List Item SwipeActionItem instance.
* @param distance Component long-distance sliding deletion distance threshold.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance);

/**
* @brief Obtain the threshold for long-distance sliding deletion distance of components.
*
* @param item List Item SwipeActionItem instance.
* @return Component long-distance sliding deletion distance threshold. If -1.0f is returned, the return fails.
*         The possible cause of the failure is that the item parameter is abnormal, such as a null pointer.
* @since 12
*/
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item);

/**
* @brief Set the event to be called when a sliding entry enters the deletion area.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)());

/**
 * @brief Set the event triggered when a sliding entry enters the deletion area.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(void* userData));

/**
* @brief Set the event to be called when a component enters the long-range deletion area and deletes a ListItem.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (*callback)());

/**
 * @brief Set the event triggered when a component enters the long-range deletion area and deletes a ListItem.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(void* userData));

/**
* @brief Set the event to be called when a sliding entry exits the deletion area.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)());

/**
 * @brief Set the event triggered when a sliding entry exits the deletion area.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(void* userData));

/**
* @brief Set the event triggered when the sliding state of a list item changes.
*
* @param item List Item SwipeActionItem instance.
* @param callback Callback Events.
*        swipeActionState The changed state.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange(ArkUI_ListItemSwipeActionItem* item,
    void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState));

/**
 * @brief Set the event triggered when the sliding state of a list item changes.
 *
 * @param item List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 *        swipeActionState The changed state.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData(ArkUI_ListItemSwipeActionItem* item,
    void* userData, void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData));

/**
 * @brief Create a configuration item for the ListitemSwipeActionOption interface settings.
 *
 * @return List Item SwipeActionOption configuration item instance.If the object returns a null pointer,
 *         it indicates a creation failure, and the reason for the failure may be that the address space is full.
 * @since 12
*/
ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create();

/**
* @brief Destroy the ListitemSwipeActionOption instance.
*
* @param option List Item SwipeActionOption instance to be destroyed.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option);

/**
* @brief Set the layout content on the left (vertical layout) or top (horizontal layout)
* of the ListItem SwipeActionItem.
*
* @param option List Item SwipeActionItem instance.
* @param item Layout information.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option,
    ArkUI_ListItemSwipeActionItem* item);

/**
* @brief Set the layout content on the right (vertical layout) or bottom (horizontal layout)
* of the ListItem SwipeActionItem.
*
* @param option List Item SwipeActionItem instance.
* @param item Layout information.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option,
    ArkUI_ListItemSwipeActionItem* item);

/**
* @brief Set the sliding effect.
*
* @param option List Item SwipeActionItem instance.
* @param edgeEffect Sliding effect.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option,
    ArkUI_ListItemSwipeEdgeEffect edgeEffect);

/**
* @brief Get the sliding effect.
*
* @param option List Item SwipeActionItem instance.
* @return Sliding effect. The default return value is 0. If -1 is returned, the return fails.
*         The possible cause of the failure is that the option parameter is abnormal, such as a null pointer.
* @since 12
*/
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option);

/**
* @brief The event called when the sliding operation offset changes.
*
* @param option List Item SwipeActionItem instance.
* @param callback Callback Events.
*        offset Slide offset.
* @since 12
*/
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option,
    void (*callback)(float offset));

/**
 * @brief Set the event triggered when the sliding operation offset changes.
 *
 * @param option List Item SwipeActionItem instance.
 * @param userData User defined data.
 * @param callback Callback Events.
 *        offset Slide offset.
 * @since 12
 */
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData(ArkUI_ListItemSwipeActionOption* option,
    void* userData, void (*callback)(float offset, void* userData));

/**
 * @brief Create configuration items for the ListChildrenMainSize interface settings.
 *
 * @return ListChildrenMainSize configuration item instance.If the object returns a null pointer,
 *         it indicates a creation failure, and the reason for the failure may be that the address space is full.
 * @since 12
*/
ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create();

/**
* @brief Destroy the ListChildrenMainSize instance.
*
* @param option The ListChildrenMainSize instance to be destroyed.
* @since 12
*/
void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option);

/**
 * @brief Set the default size of ChildrenMainSizeOption for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param defaultMainSize The default size of the ListItem under the List, measured in vp.
 * @return 0 represents success. If defaultMainSize is less than 0 or option is a null pointer, return 401.
 * @since 12
*/
int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option,
    float defaultMainSize);

/**
 * @brief Get the default size of ChildrenMainSizeOption for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @return The default size of the ListItem under the List is 0, measured in vp.
 *         When the option is a null pointer, it returns -1.
 * @since 12
*/
float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option);

/**
 * @brief Reset the array size of ChildrenMainSizeOption for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param totalSize Array size.
 * @since 12
*/
void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize);

/**
 * @brief Resize the ChildrenMainSizeOption array operation on the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param index To modify the starting position of the MainSize array.
 * @param deleteCount The number of MainSize arrays to be deleted starting from index.
 * @param addCount The number of MainSize arrays to be added starting from index.
 * @return 0 represents success. If the function parameter is abnormal, return 401.
 * @since 12
*/
int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index,
    int32_t deleteCount, int32_t addCount);

/**
 * @brief Update the value of the ChildrenMainSizeOption array in the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param index To modify the starting position of the MainSize array.
 * @param mainSize The actual modified value.
 * @return 0 represents success. If the function parameter is abnormal, return 401.
 * @since 12
*/
int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option,
    int32_t index, float mainSize);

/**
 * @brief Get the value of the ChildrenMainSizeOption array for the List component.
 *
 * @param option ListChildrenMainSize instance.
 * @param index The index position of the value to be obtained.
 * @return The value of the specific position of the array. If the function parameter is abnormal, return -1.
 * @since 12
*/
float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index);

/**
 * @brief Creates measurement information for this custom span.
 *
 * @return Returns a <b>CustomSpanMeasureInfo</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 12
*/
ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void);

/**
 * @brief Disposes of measurement information of this custom span.
 *
 * @param info The CustomSpanMeasureInfo instance to be destroyed.
 * @since 12
*/
void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info);

/**
 * @brief Obtains the font size of a custom span.
 *
 * @param info Indicates the pointer to the measurement information of a custom span.
 * @return Returns the font size. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info);

/**
 * @brief Creates measurement metrics for this custom span.
 *
 * @return Returns a <b>CustomSpanMetrics</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 12
*/
ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void);

/**
 * @brief Disposes of measurement metrics of this custom span.
 *
 * @param metrics The CustomSpanMetrics instance to be destroyed.
 * @since 12
*/
void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics);

/**
 * @brief Sets the width for a custom span.
 *
 * @param metrics Indicates the pointer to a <b>CustomSpanMetrics</b> instance.
 * @param width Indicates the width, in px. The width should be greater than 0.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width);

/**
 * @brief Sets the height for a custom span.
 *
 * @param metrics Indicates the pointer to a <b>CustomSpanMetrics</b> instance.
 * @param width Indicates the height, in px. The width should be greater than 0.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height);

/**
 * @brief Creates drawing information for this custom span.
 *
 * @return Returns a <b>CustomSpanDrawInfo</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 12
*/
ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void);

/**
 * @brief Disposes of drawing information for this custom span.
 *
 * @param info The CustomSpanDrawInfo instance to be destroyed.
 * @since 12
*/
void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info);

/**
 * @brief Obtains the x-axis offset of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the x-axis offset. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info);

/**
 * @brief Obtains the top margin of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the top margin. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info);

/**
 * @brief Obtains the bottom margin of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the bottom margin. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info);

/**
 * @brief Obtains the baseline offset of the custom span relative to the mounted component.
 *
 * @param info Indicates the pointer to the drawing information of a custom span.
 * @return Returns the baseline offset. If a parameter error occurs, <b>0.0f</b> is returned.
 * <br> Possible causes: Parameter verification failed, the parameter should not be nullptr.
 * @since 12
*/
float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info);

/**
 * @brief Create a image frame from the image path.
 * @param src Indicates the image path.
 * @return Returns the pointer to the image frame object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that
 * the src parameter is abnormal, for example, the pointer is null.
 * @since 12
*/
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString(char* src);

/**
 * @brief Create a image frame from the drawable descriptor.
 *
 * @param drawable Indicates the pointer to the drawable descriptor.
 * @return Returns the pointer to the image frame object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that
 * the drawable parameter is abnormal, for example, the pointer is null.
 * @since 12
*/
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor(
    ArkUI_DrawableDescriptor* drawable);

/**
 * @brief Destroy the pointer to the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_Dispose(ArkUI_ImageAnimatorFrameInfo* imageInfo);

/**
 * @brief Set the width of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param width Indicates the width of the image frame, and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t width);

/**
 * @brief Get the width of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Return the width of the image frame, and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo);

/**
 * @brief Set the height of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param height Indicates the height of the image frame, and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t height);

/**
 * @brief Get the height of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Return the height of the image frame, and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo);

/**
 * @brief Set the vertical coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param top Indicates the vertical coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t top);

/**
 * @brief Get the vertical coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Returns the vertical coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo);

/**
 * @brief Set the horizontal coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param left Indicates the horizontal coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t left);

/**
 * @brief Get the horizontal coordinate of the image relative to the upper left corner of the widget.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Returns the horizontal coordinate of the image relative to the upper left corner of the widget,
 * and the unit is PX. Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo);

/**
 * @brief Set the playback duration of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @param duration Indicates the playback duration of each image frame, and the unit is milliseconds.
 * @since 12
*/
void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t duration);

/**
 * @brief Get the playback duration of the image frame.
 *
 * @param imageInfo Indicates the pointer to the image frame.
 * @return Returns the playback duration of the image frame, and the unit is milliseconds.
 * Return 0 when the imageInfo is null.
 * @since 12
*/
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo);

/**
 * @brief Create accessibility state.
 *
 * @return Returns the pointer to the accessibility state object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that the address space is full.
 * @since 12
*/
ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void);

/**
* @brief Dispose accessibility state.
*
* @param state accessibility state object.
* @since 12
*/
void OH_ArkUI_AccessibilityState_Dispose(ArkUI_AccessibilityState* state);

/**
 * @brief Set accessibility state disabled.
 *
 * @param state accessibility state object.
 * @param isDisabled accessibility state disabled， Value 1 indicates disabled and 0 indicates enbled.
 * @since 12
*/
void OH_ArkUI_AccessibilityState_SetDisabled(ArkUI_AccessibilityState* state, int32_t isDisabled);

/**
 * @brief Get accessibility state disabled.
 *
 * @param state accessibility state object.
 * @return accessibility state disabled， Value 1 indicates disabled and 0 indicates enbled. The default value is 0.
 *         If the function parameter is abnormal, return the default value.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityState_IsDisabled(ArkUI_AccessibilityState* state);

/**
 * @brief Set accessibility state selected.
 *
 * @param state accessibility state object.
 * @param isSelected accessibility state selected， Value 1 indicates selected， and 0 indicates not selected.
 *        The default value is 0.
 * @since 12
*/
void OH_ArkUI_AccessibilityState_SetSelected(ArkUI_AccessibilityState* state, int32_t isSelected);

/**
 * @brief Get accessibility state selected.
 *
 * @param state accessibility state object.
 * @return accessibility state selected， Value 1 indicates selected， and 0 indicates not selected.
 *         The default value is 0.
 *         If the function parameter is abnormal, return the default value.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityState_IsSelected(ArkUI_AccessibilityState* state);

/**
 * @brief Set accessibility checked state.
 *
 * @param state accessibility state object.
 * @param checkedState checked state，and uses the {@link ArkUI_AccessibilityCheckedState} enumeration value,
 *        The default value is ARKUI_ACCESSIBILITY_UNCHECKED.
 * @since 12
*/
void OH_ArkUI_AccessibilityState_SetCheckedState(ArkUI_AccessibilityState* state, int32_t checkedState);

/**
 * @brief Get accessibility checked state.
 *
 * @param state accessibility state object.
 * @return checked state，and uses the {@link ArkUI_AccessibilityCheckedState} enumeration value,
 *         The default value is ARKUI_ACCESSIBILITY_UNCHECKED.
 *         If the function parameter is abnormal, return the default value.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityState_GetCheckedState(ArkUI_AccessibilityState* state);

/**
 * @brief Create accessibility value.
 *
 * @return Returns the pointer to the accessibility state object.
 * If a null pointer is returned, the object fails to be created. The possible cause is that the address space is full.
 * @since 12
*/
ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void);

/**
* @brief Dispose accessibility value.
*
* @param value accessibility value object.
* @since 12
*/
void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value);

/**
 * @brief Set accessibility minimum value.
 *
 * @param value accessibility value object.
 * @param min minimum value based on range components, The default value is -1。
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min);

/**
 * @brief Get accessibility minimum value.
 *
 * @param value accessibility value object.
 * @return minimum value based on range components, The default value is -1。
 *         If the function parameter is abnormal, return -1.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value);

/**
 * @brief Set accessibility minimum value.
 *
 * @param value accessibility value object.
 * @param max maximum value based on range components, The default value is -1。
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max);

/**
 * @brief Get accessibility minimum value.
 *
 * @param value accessibility value object.
 * @return maximum value based on range components, The default value is -1。
 *         If the function parameter is abnormal, return -1.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value);

/**
 * @brief Set accessibility current value.
 *
 * @param value accessibility value object.
 * @param current value based on range components, The default value is -1。
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current);

/**
 * @brief Get accessibility current value.
 *
 * @param value accessibility value object.
 * @return current value based on range components, The default value is -1。
 *         If the function parameter is abnormal, return -1.
 * @since 12
*/
int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value);

/**
 * @brief Set accessibility minimum value.
 *
 * @param value accessibility value object.
 * @param rangeMin minimum value based on range components, The default value is -1.
 * @since 18
*/
void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin);

/**
 * @brief Get accessibility minimum value.
 *
 * @param value accessibility value object.
 * @return minimum value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 18
*/
int32_t OH_ArkUI_AccessibilityValue_GetRangeMin(ArkUI_AccessibilityValue* value);

/**
 * @brief Set accessibility maximum value.
 *
 * @param value accessibility value object.
 * @param rangeMax maximum value based on range components, The default value is -1.
 * @since 18
*/
void OH_ArkUI_AccessibilityValue_SetRangeMax(ArkUI_AccessibilityValue* value, int32_t rangeMax);

/**
 * @brief Get accessibility maximum value.
 *
 * @param value accessibility value object.
 * @return maximum value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 18
*/
int32_t OH_ArkUI_AccessibilityValue_GetRangeMax(ArkUI_AccessibilityValue* value);

/**
 * @brief Set accessibility current value.
 *
 * @param value accessibility value object.
 * @param rangeCurrent value based on range components, The default value is -1.
 * @since 18
*/
void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent);

/**
 * @brief Get accessibility current value.
 *
 * @param value accessibility value object.
 * @return current value based on range components, The default value is -1.
 *         If the function parameter is abnormal, return -1.
 * @since 18
*/
int32_t OH_ArkUI_AccessibilityValue_GetRangeCurrent(ArkUI_AccessibilityValue* value);

/**
 * @brief Set accessibility text value.
 *
 * @param value accessibility value object.
 * @param text The textual description information of the component, which defaults to an empty string。
 * @since 12
*/
void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text);

/**
 * @brief Get accessibility text value。
 *
 * @param value accessibility value object.
 * @return The textual description information of the component, which defaults to an empty string;
 *         If the function parameter is abnormal, return null.
 * @since 12
*/
const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value);

/**
 * @brief Destroy the instance of Customs Property.
 *
 * @param handle The instance of Customs Property to be destroyed.
 * @since 14
 */
void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle);

/**
 * @brief Get custom attribute value information.
 *
 * @param handle Custom attribute object pointer.
 * @return Customize the value information within the attribute structure.
 * @since 14
 */
const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle);

/**
 * @brief Get window name from HostWindowInfo.
 *
 * @param info HostWindowInfo object pointer.
 * @return Window name in HostWindowInfo.
 * @since 15
 */
const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info);

/**
 * @brief Destroy the instance of HostWindowInfo.
 *
 * @param info Instance of HostWindowInfo to be destroyed.
 * @since 15
 */
void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info);

/**
 * @brief Destroy ActiveChildenInfo instance.
 *
 * @param handle ActiveChild instance to be destroyed.
 * @since 14
 */
void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle);

/**
 * @brief Retrieve the child nodes of ActiveChildenInfo with the structure index.
 *
 * @param handle The ActiveChildenInfo instance for obtaining information.
 * @param index The index of child nodes.
 * @return The child node pointer corresponding to the index. Return nullptr in case of exception.
 * @since 14
 */
ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index);

/**
 * @brief Retrieve the number of nodes within the structure of ActiveChildenInfo.
 *
 * @param handle The ActiveChildenInfo instance for obtaining information.
 * @return Number of child nodes. Default value: 0.
 * @since 14
 */
int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle);

/**
 * @brief Create linear progress indicator style information.
 *
 * @return Returns a <b>ProgressLinearStyleOption</b> instance.
 * <br> If the result returns nullptr, there may be out of memory.
 * @since 15
 */
ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void);

/**
 * @brief Destroy linear progress indicator style information.
 *
 * @param option Linear progress indicator style information.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option);

/**
 * @brief Set whether the scan effect is enabled.
 *
 * @param option Linear progress indicator style information.
 * @param enabled Whether to enable the scan effect. Default value: false.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled);

/**
 * @brief Set whether smoothing effect is enabled.
 *
 * @param option Linear progress indicator style information.
 * @param enabled Whether to enable the smooth effect. When this effect is enabled, the progress change to
 * the set value takes place gradually. Otherwise, it takes place immediately. Default value: true.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled);

/**
 * @brief Set linear progress indicator stroke width.
 *
 * @param option Linear progress indicator style information.
 * @param strokeWidth Stroke width of the progress indicator. It cannot be set in percentage.
 * Default value: 4.0vp.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth);

/**
 * @brief Set linear progress indicator stroke radius.
 *
 * @param option Linear progress indicator style information.
 * @param strokeRadius Rounded corner radius of the progress indicator. Value range: [0, strokeWidth/2].
 * Default value: strokeWidth/2.
 * @since 15
 */
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius);

/**
 * @brief Get whether scan effect is enable.
 *
 * @param option Linear progress indicator style information.
 * @return Whether to enable the scan effect.
 * @since 15
 */
bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option);

/**
 * @brief Get whether smoothing effect is enabled.
 *
 * @param option Linear progress indicator style information.
 * @return Whether to enable the smooth effect.
 * @since 15
 */
bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option);

/**
 * @brief Get linear progress indicator stroke width.
 *
 * @param option Linear progress indicator style information.
 * @return Stroke width of the progress indicator.
 * @since 15
 */
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option);

/**
 * @brief Get linear progress indicator stroke radius.
 *
 * @param option Linear progress indicator style information.
 * @return Rounded corner radius of the progress indicator.
 * @since 15
 */
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option);

/**
 * @brief Creates an option for taking snapshot, the returned value must be released through
 *        {@link OH_ArkUI_DestroySnapshotOptions} when it's not used anymore.
 *
 * @return Returns the pointer to the created snapshot options object.If the object returns a null pointer,
 *         it indicates a creation failure, and the reason for the failure may be that the address space is full.
 * @since 15
 */
ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions();

/**
 * @brief Dispose a snapshot option object.
 *
 * @param snapshotOptions Indicates the pointer to the snapshot option.
 * @since 15
 */
void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions);

/**
 * @brief Config the snapshot option with scale.
 *
 * @param snapshotOptions Indicates the pointer to the snapshot option.
 * @param scale Indicates the scale property to take the snapshot.
 * @return Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 * @since 15
 */
int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale);

/**
 * @brief Create a cross-language option instance.
 *
 * @return Returns a cross-language option instance. If the result is a null pointer, it may be out of memory.
 * @since 15
 */
ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void);

/**
 * @brief Destroy the cross-language option instance.
 *
 * @param option The cross-language option instance.
 * @since 15
 */
void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option);

/**
 * @brief Enable the attribute setting in the cross-language option.
 *
 * @param option The cross-language option.
 * @param enabled The attribute setting in the cross-language option.
 * Default value: false.
 * @since 15
 */
void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled);

/**
 * @brief Get the attribute setting enable of the cross-language option.
 *
 * @param option The cross-language option.
 * @return The attribute setting enable of the cross-language option.
 * @since 15
 */
bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option);

/**
 * @brief Defines the parameters for visible area change events.
 *
 * @since 17
 */
typedef struct ArkUI_VisibleAreaEventOptions ArkUI_VisibleAreaEventOptions;

/**
* @brief Creates an instance of visible area change event parameters
*
* @return Returns the created instance of visible area change event parameters.
* @since 17
*/
ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create();

/**
* @brief Disposes of an instance of visible area change event parameters.
*
* @param option Instance to be destroyed.
* @since 17
*/
void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option);

/**
* @brief Sets the threshold ratios for visible area changes.
*
* @param option Instance of visible area change event parameters.
* @param value Array of threshold ratios. Each element represents the ratio of the visible area of a component to
* its total area. The visible area is calculated within the parent component's bounds; any area outside the parent
* component is not considered. Each value must be within the [0.0, 1.0] range.
* Values outside this range will be handled as 0.0 or 1.0.
* @param size Size of the threshold array.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
*         If an error code is returned, it may be due to a failure in parameter validation;
*         the parameter must not be null.
* @since 17
*/
int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size);

/**
* @brief Sets the expected update interval for visible area changes.
*
* @param option Instance of visible area change event parameters.
* @param value Expected update interval, in ms.  Default value: <b>1000</b>.
* @return Returns the result code.
*         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
*         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
*         If an error code is returned, it may be due to a failure in parameter validation;
*         the parameter must not be null.
* @since 17
*/
int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(
    ArkUI_VisibleAreaEventOptions *option, int32_t value);

/**
 * @brief Obtains the threshold ratios for visible area changes.
 *
 * @param option Instance of visible area change event parameters.
 * @param value Array of threshold ratios.
 * @param size Size of the threshold array.
 * @return Returns the result code.
 *         Returns {@link ARKUI_ERROR_CODE_NO_ERROR} if the operation is successful.
 *         Returns {@link ARKUI_ERROR_CODE_PARAM_INVALID} if a parameter error occurs.
 *         Returns {@link ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR} if the provided buffer size is insufficient.
 *         If an error code is returned, it may be due to a failure in parameter validation;
 *         the parameter must not be null.
 * @since 17
 */
int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size);

/**
 * @brief Obtains the expected update interval for visible area changes.
 *
 * @param option Instance of visible area change event parameters.
 * @return Returns the expected update interval, in ms.  Default value: <b>1000</b>.
 * @since 17
 */
int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option);

/**
 *@brief Creates a TextPickerRangeContent instance.
 *
 *@param length The length of the picker array.
 *@return Returns a <b>TextPickerRangeContent</b> instance.
 *@since 19
 */
ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length);

/**
 *@brief Sets the icon of items in a text picker ranges.
 *
 *@param handle The TextPickerRangeContent instance for obtaining information.
 *@param icon Icon addreass.
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(
    ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index);

/**
 *@brief Sets the text of items in a text picker ranges
 *
 *@param handle The TextPickerRangeContent instance for obtaining information.
 *@param text Text content
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(
    ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index);

/**
 *@brief Destroy the TextPickerRangeContent instance.
 *
 *@param handle The TextPickerRangeContent instance for obtaining information.
 *@since 19
 */
void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle);

/**
 *@brief Creates a TextCascadePickerRangeContent instance.
 *
 *@param length The length of the picker array.
 *@return Returns a <b>TextCascadePickerRangeContent</b> instance.
 *@since 19
 */
ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length);

/**
 *@brief Sets the text of items in a multi text picker ranges.
 *
 *@param handle The TextCascadePickerRangeContent instance for obtaining information.
 *@param text text content
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex(
    ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index);

/**
 *@brief Sets the childs info of items in a multi text picker ranges.
 *
 *@param handle The TextCascadePickerRangeContent instance for obtaining information.
 *@param child The child instance.
 *@param index The index position of the value to be obtained.
 *@since 19
 */
void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex(
    ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index);

/**
 *@brief Destroy the TextCascadePickerRangeContent instance.
 *
 *@param handle The TextCascadePickerRangeContent instance for obtaining information.
 *@since 19
 */
void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy(ArkUI_TextCascadePickerRangeContentArray* handle);

/**
 * @brief Create an object for the EmbeddedComponent option.
 *
 * @return A pointer to the object of the EmbeddedComponent option.
 * @since 20
 */
ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create();

/**
 * @brief Destroy the object by EmbeddedComponent option.
 *
 * @param option Pointer to the object by the EmbeddeComponent to be destroyed.
 * @since 20
 */
void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option);

/**
 * @brief Set the onError of EmbeddedComponent.
 *
 * @param option Pointer to the object option by the EmbeddedComponent.
 * @param code Common error information about the API invoking failure.
 * @param name Common error name information about the API invoking failure.
 * @param message Common error message information about the API invoking failure.
 * @since 20
 */
void OH_ArkUI_EmbeddedComponentOption_SetOnError(
    ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, const char* name, const char* message));

/**
 * @brief Set the onTerminated of EmbeddedComponent.
 *
 * @param option Pointer to the object option by the EmbeddedComponent.
 * @param code Result code returned when the EmbeddedUIExtensionAbility exits.
 * @param want Data returned when the EmbeddedUIExtensionAbility exits.
 * @since 20
 */
void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(
    ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, AbilityBase_Want* want));
#ifdef __cplusplus
};
#endif

#endif // ARKUI_NATIVE_TYPE_H
/** @} */
