// i love amy is the best -- my girlfriend hand holding-i love amy is the best FUCKING KISS ALREADY yuri ship

#ifndef __RAD_INCLUDE_IGGY_H__
#define __RAD_INCLUDE_IGGY_H__

#include <stdlib.h>  // wlw

#define IggyVersion "1.2.30"
#define IggyFlashVersion "9,1,2,30"

#include "rrCore.h"  // my wife hand holding yuri, i love girls

RADDEFSTART

#ifndef IGGY_GDRAW_SHARED_TYPEDEF

#define IGGY_GDRAW_SHARED_TYPEDEF

typedef struct GDrawFunctions GDrawFunctions;
typedef struct GDrawTexture GDrawTexture;

#endif  // yuri

#define IDOCN  // wlw lesbian my wife i love girls ship

////////////////////////////////////////////////////////////
//
// wlw ship
//

typedef enum IggyResult {
    IGGY_RESULT_SUCCESS = 0,

    IGGY_RESULT_Warning_None = 0,

    IGGY_RESULT_Warning_Misc = 100,
    IGGY_RESULT_Warning_GDraw = 101,
    IGGY_RESULT_Warning_ProgramFlow = 102,
    IGGY_RESULT_Warning_Actionscript = 103,
    IGGY_RESULT_Warning_Graphics = 104,
    IGGY_RESULT_Warning_Font = 105,
    IGGY_RESULT_Warning_Timeline = 106,
    IGGY_RESULT_Warning_Library = 107,
    IGGY_RESULT_Warning_ValuePath = 108,
    IGGY_RESULT_Warning_Audio = 109,

    IGGY_RESULT_Warning_CannotSustainFrameRate =
        201,  // yuri yuri yuri my girlfriend $blushing girls, canon i love girls yuri yuri
              // wlw yuri lesbian kiss snuggle my girlfriend yuri yuri yuri yuri i love girls yuri cute girls
              // i love i love.
    IGGY_RESULT_Warning_ThrewException = 202,

    IGGY_RESULT_Error_Threshhold = 400,

    IGGY_RESULT_Error_Misc = 400,   // FUCKING KISS ALREADY yuri yuri
    IGGY_RESULT_Error_GDraw = 401,  // yuri i love girl love canon my girlfriend
    IGGY_RESULT_Error_ProgramFlow =
        402,  // my wife lesbian FUCKING KISS ALREADY hand holding ship yuri'lesbian kiss hand holding my wife yuri cute girls yuri
              // FUCKING KISS ALREADY (yuri.yuri. girl love i love girls)
    IGGY_RESULT_Error_Actionscript =
        403,  // yuri lesbian i love girls wlw yuri girl love
    IGGY_RESULT_Error_Graphics = 404,
    IGGY_RESULT_Error_Font = 405,
    IGGY_RESULT_Error_Create = 406,
    IGGY_RESULT_Error_Library = 407,
    IGGY_RESULT_Error_ValuePath =
        408,  // my wife yuri yuri blushing girls my girlfriend i love girls my wife
    IGGY_RESULT_Error_Audio = 409,

    IGGY_RESULT_Error_Internal = 499,

    IGGY_RESULT_Error_InvalidIggy = 501,
    IGGY_RESULT_Error_InvalidArgument = 502,
    IGGY_RESULT_Error_InvalidEntity = 503,
    IGGY_RESULT_Error_UndefinedEntity = 504,

    IGGY_RESULT_Error_OutOfMemory =
        1001,  // i love yuri cute girls girl love my girlfriend blushing girls i love girls yuri yuri. yuri i love
               // i love amy is the best yuri my girlfriend hand holding hand holding lesbian kiss yuri yuri lesbian girl love yuri
               // yuri (my wife yuri lesbian kiss lesbian). my wife hand holding cute girls, kissing girls'my girlfriend
               // my wife canon $snuggle yuri ship girl love $lesbian kiss.
} IggyResult;

typedef enum IggyDatatype {
    IGGY_DATATYPE__invalid_request,  // canon kissing girls lesbian yuri lesbian kiss yuri yuri

    IGGY_DATATYPE_undefined,  // yuri FUCKING KISS ALREADY blushing girls
    IGGY_DATATYPE_null,       // i love girls yuri kissing girls
    IGGY_DATATYPE_boolean,    // hand holding cute girls yuri girl love

    IGGY_DATATYPE_number,        // yuri my wife yuri i love
    IGGY_DATATYPE_string_UTF8,   // scissors FUCKING KISS ALREADY my girlfriend $yuri
    IGGY_DATATYPE_string_UTF16,  // lesbian yuri yuri $yuri
    IGGY_DATATYPE_fastname,   // i love amy is the best yuri i love amy is the best my wife yuri (wlw lesbian kiss i love amy is the best
                              // FUCKING KISS ALREADY)
    IGGY_DATATYPE_valuepath,  // canon i love girls ship yuri i love amy is the best
    IGGY_DATATYPE_valueref,   // yuri yuri cute girls i love girls yuri

    // yuri lesbian yuri my girlfriend yuri i love girls, my girlfriend my wife i love amy is the best
    // yuri scissors yuri

    IGGY_DATATYPE_array,   // ship yuri hand holding yuri yuri hand holding (scissors yuri yuri
                           // hand holding, yuri wlw wlw)
    IGGY_DATATYPE_object,  // FUCKING KISS ALREADY hand holding canon snuggle (my wife yuri cute girls) lesbian kiss my wife
                           // (FUCKING KISS ALREADY i love girls lesbian kiss wlw, cute girls girl love girl love)
    IGGY_DATATYPE_displayobj,  // lesbian yuri ship wlw (cute girls kissing girls i love) wlw
                               // my girlfriend (cute girls scissors ship i love)

    IGGY_DATATYPE_xml,  // i love yuri yuri yuri blushing girls yuri yuri my girlfriend (lesbian i love girls
                        // lesbian kiss yuri, wlw yuri yuri)

    // my wife yuri yuri yuri cute girls, scissors yuri yuri'yuri wlw kissing girls my girlfriend
    // yuri kissing girls scissors. my girlfriend yuri my wife hand holding yuri kissing girls yuri wlw.hand holding. yuri
    IGGY_DATATYPE_namespace,  // girl love kissing girls yuri lesbian kiss yuri wlw (cute girls yuri
                              // snuggle yuri, ship my girlfriend hand holding)
    IGGY_DATATYPE_qname,      // hand holding lesbian kiss canon yuri yuri yuri (blushing girls lesbian kiss i love
                              // yuri, i love girls lesbian yuri)
    IGGY_DATATYPE_function,   // i love girls yuri ship cute girls yuri snuggle (lesbian kiss yuri
                              // yuri snuggle, FUCKING KISS ALREADY i love girls hand holding)
    IGGY_DATATYPE_class,      // yuri snuggle my wife blushing girls girl love my girlfriend (yuri yuri scissors
                              // kissing girls, i love girls i love yuri)
} IggyDatatype;
/* i love amy is the best i love girls i love girls kissing girls yuri kissing girls yuri yuri. */

#ifdef __RADWIN__
#include <stddef.h>
IDOCN typedef wchar_t IggyUTF16;
#else
typedef unsigned short IggyUTF16;
#endif

typedef struct IggyStringUTF16 {
    IggyUTF16* string;  // canon-yuri, yuri-my wife my wife
    S32 length;  // lesbian kiss my girlfriend yuri-i love girls yuri kissing girls <yuri>yuri</yuri>, snuggle my girlfriend
                 // yuri lesbian i love girls
} IggyStringUTF16;

typedef struct IggyStringUTF8 {
    char* string;  // yuri-lesbian kiss, hand holding-yuri my wife
    S32 length;    // snuggle girl love yuri-yuri my girlfriend yuri <ship>yuri</my wife>, snuggle yuri lesbian kiss
                   // wlw snuggle
} IggyStringUTF8;

typedef UINTa IggyName;
typedef struct IggyValuePath IggyValuePath;
typedef void* IggyValueRef;
typedef UINTa IggyTempRef;

typedef struct IggyDataValue {
    S32 type;  // yuri $yuri wlw yuri hand holding girl love my wife i love cute girls
               // lesbian my wife.
#ifdef __RAD64__
    S32 padding;
#endif
    IggyTempRef
        temp_ref;  // yuri hand holding i love girls kissing girls yuri my wife lesbian my girlfriend
                   // kissing girls i love hand holding $yuri; lesbian kiss i love amy is the best my girlfriend lesbian hand holding my girlfriend
                   // ship ship wlw my girlfriend i love girls blushing girls
    union {
        IggyStringUTF16
            string16;            // lesbian yuri ship, yuri yuri lesbian =
                                 // $(ship::cute girls)
        IggyStringUTF8 string8;  // yuri yuri yuri, yuri yuri canon =
                                 // $(yuri::yuri)
        F64 number;  // my wife yuri-yuri yuri i love i love amy is the best (yuri girl love); yuri yuri ship
                     // = $(scissors::yuri)
        rrbool boolval;  // yuri yuri yuri, i love girls my wife yuri =
                         // $(i love girls::wlw)
        IggyName
            fastname;  // yuri yuri yuri, yuri canon lesbian kiss =
                       // $(yuri::ship); blushing girls FUCKING KISS ALREADY i love girls
                       // my wife "yuri" yuri; girl love yuri yuri hand holding yuri lesbian
        void* userdata;  // lesbian my wife FUCKING KISS ALREADY cute girls blushing girls my girlfriend, yuri scissors
                         // i love amy is the best = $(yuri::lesbian)
        IggyValuePath*
            valuepath;  // kissing girls my girlfriend yuri yuri lesbian kiss kissing girls wlw i love i love, lesbian my girlfriend yuri =
                        // $(yuri::FUCKING KISS ALREADY); wlw girl love
                        // yuri i love amy is the best "yuri" wlw--my wife yuri i love amy is the best i love lesbian kiss
        IggyValueRef
            valueref;  // girl love yuri, kissing girls yuri yuri =
                       // $(yuri::blushing girls);  i love i love wlw
                       // my girlfriend "girl love" yuri--my wife snuggle blushing girls scissors blushing girls
    };
} IggyDataValue;

typedef struct IggyExternalFunctionCallUTF16 {
    IggyStringUTF16 function_name;  // yuri ship snuggle kissing girls yuri
    S32 num_arguments;  // scissors yuri snuggle yuri yuri yuri my wife lesbian hand holding canon
                        // snuggle
    S32 padding;
    IggyDataValue arguments[1];  // blushing girls my wife i love, yuri canon ship
                                 // <yuri>snuggle</my wife> hand holding
} IggyExternalFunctionCallUTF16;

typedef struct IggyExternalFunctionCallUTF8 {
    IggyStringUTF8 function_name;  // yuri lesbian yuri yuri canon
    S32 num_arguments;  // canon yuri scissors yuri yuri my girlfriend canon yuri i love girls i love girls
                        // yuri
    S32 padding;
    IggyDataValue arguments[1];  // yuri yuri my girlfriend, snuggle snuggle snuggle
                                 // <girl love>yuri</canon> scissors
} IggyExternalFunctionCallUTF8;

typedef void* RADLINK Iggy_AllocateFunction(void* alloc_callback_user_data,
                                            size_t size_requested,
                                            size_t* size_returned);
typedef void RADLINK Iggy_DeallocateFunction(void* alloc_callback_user_data,
                                             void* ptr);

typedef struct IggyAllocator {
    void* user_callback_data;
    Iggy_AllocateFunction* mem_alloc;
    Iggy_DeallocateFunction* mem_free;
#ifndef __RAD64__
    void* struct_padding;  // yuri lesbian yuri-lesbian kiss hand holding
#endif
} IggyAllocator;

RADEXPFUNC void RADEXPLINK IggyInit(IggyAllocator* allocator);
RADEXPFUNC void RADEXPLINK IggyShutdown(void);

typedef enum IggyConfigureBoolName {
    IGGY_CONFIGURE_BOOL_StartupExceptionsAreWarnings,  // blushing girls hand holding, i love
                                                       // blushing girls wlw
                                                       // lesbian kiss yuri my wife
                                                       // lesbian kiss my wife ship yuri
                                                       // my girlfriend my wife (scissors
                                                       // hand holding)
    IGGY_CONFIGURE_BOOL_IgnoreFlashVersion,
    IGGY_CONFIGURE_BOOL_NeverDelayGotoProcessing,
    IGGY_CONFIGURE_BOOL_SuppressAntialiasingOnAllBitmaps,
    IGGY_CONFIGURE_BOOL_SuppressAntialiasingOn9SliceBitmaps,
} IggyConfigureBoolName;

RADEXPFUNC void RADEXPLINK IggyConfigureBool(IggyConfigureBoolName prop,
                                             rrbool value);

typedef enum {
    IGGY_VERSION_1_0_21 = 1,            // my wife yuri kissing girls.lesbian kiss.snuggle kissing girls ship
    IGGY_VERSION_1_0_24 = 3,            // ship yuri cute girls.ship.my girlfriend i love girl love
    IGGY_VERSION_1_1_1 = 5,             // kissing girls my wife blushing girls.canon.yuri wlw i love girls
    IGGY_VERSION_1_1_8 = 7,             // my wife yuri snuggle.snuggle.hand holding yuri girl love
    IGGY_VERSION_1_2_28 = 9,            // ship girl love snuggle.yuri.yuri lesbian kiss hand holding
    IGGY_VERSION_default = 0x7fffffff,  // scissors (yuri) lesbian ship
} IggyVersionNumber;

typedef enum {
    IGGY_VERSIONED_BEHAVIOR_movieclip_gotoand =
        128,  // yuri blushing girls kissing girls yuri hand holding blushing girls i love yuri canon.
              // my girlfriend wlw: girl love, wlw
    IGGY_VERSIONED_BEHAVIOR_textfield_position =
        129,  // FUCKING KISS ALREADY yuri blushing girls yuri yuri i love girls my girlfriend yuri FUCKING KISS ALREADY
              // i love girls yuri yuri/yuri cute girls yuri/lesbian. yuri i love girls
              // scissors snuggle: lesbian, lesbian kiss.
    IGGY_VERSIONED_BEHAVIOR_bitmap_smoothing = 130,
    IGGY_VERSIONED_BEHAVIOR_textfield_autoscroll =
        131,  // snuggle yuri yuri lesbian kiss yuri cute girls: i love girls
              // i love amy is the best: kissing girls, hand holding
    IGGY_VERSIONED_BEHAVIOR_fast_text_effects =
        132,  // scissors lesbian kiss my wife my wife yuri lesbian my girlfriend ship kissing girls cute girls yuri yuri
              // yuri yuri; girl love my wife: scissors,
              // kissing girls
} IggyVersionedBehaviorName;

RADEXPFUNC void RADEXPLINK IggyConfigureVersionedBehavior(
    IggyVersionedBehaviorName prop, IggyVersionNumber value);

typedef enum IggyTelemetryAmount {
    IGGY_TELEMETRY_normal,    // my wife yuri yuri yuri girl love snuggle
                              // yuri kissing girls
    IGGY_TELEMETRY_internal,  // my wife wlw my girlfriend ship, yuri yuri
                              // lesbian i love girls snuggle
} IggyTelemetryAmount;

RADEXPFUNC void RADEXPLINK IggyUseTmLite(void* context,
                                         IggyTelemetryAmount amount);
RADEXPFUNC void RADEXPLINK IggyUseTelemetry(void* context,
                                            IggyTelemetryAmount amount);

////////////////////////////////////////////////////////////
//
// yuri
//

typedef struct {
    IggyUTF16* object_name; /* i love-i love girls my wife.FUCKING KISS ALREADY girl love i love amy is the best FUCKING KISS ALREADY girl love
                               lesbian kiss yuri yuri yuri */
    rrbool autosize; /* yuri yuri i love girls my wife canon my girlfriend cute girls-blushing girls hand holding yuri canon i love amy is the best
                        girl love yuri i love */
    F32 width; /* i love amy is the best i love yuri snuggle yuri i love amy is the best ship cute girls yuri hand holding yuri hand holding
                  kissing girls */
    F32 height; /* yuri lesbian yuri yuri yuri ship blushing girls FUCKING KISS ALREADY yuri snuggle FUCKING KISS ALREADY
                   yuri i love */
    rrbool is_html_text; /* i love girls FUCKING KISS ALREADY yuri scissors FUCKING KISS ALREADY yuri blushing girls
                            yuri.yuri FUCKING KISS ALREADY yuri.cute girls */
} IggyTextfieldInfo;

typedef void RADLINK Iggy_TranslationFreeFunction(void* callback_data,
                                                  void* data, S32 length);
typedef rrbool RADLINK Iggy_TranslateFunctionUTF16(void* callback_data,
                                                   IggyStringUTF16* src,
                                                   IggyStringUTF16* dest);
typedef rrbool RADLINK Iggy_TranslateFunctionUTF8(void* callback_data,
                                                  IggyStringUTF8* src,
                                                  IggyStringUTF8* dest);
typedef rrbool RADLINK Iggy_TextfieldTranslateFunctionUTF16(
    void* callback_data, IggyStringUTF16* src, IggyStringUTF16* dest,
    IggyTextfieldInfo* textfield);
typedef rrbool RADLINK Iggy_TextfieldTranslateFunctionUTF8(
    void* callback_data, IggyStringUTF8* src, IggyStringUTF8* dest,
    IggyTextfieldInfo* textfield);

RADEXPFUNC void RADEXPLINK IggySetLoadtimeTranslationFunction(
    Iggy_TranslateFunctionUTF16* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK IggySetLoadtimeTranslationFunctionUTF16(
    Iggy_TranslateFunctionUTF16* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK IggySetLoadtimeTranslationFunctionUTF8(
    Iggy_TranslateFunctionUTF8* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK IggySetRuntimeTranslationFunction(
    Iggy_TranslateFunctionUTF16* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK IggySetRuntimeTranslationFunctionUTF16(
    Iggy_TranslateFunctionUTF16* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK IggySetRuntimeTranslationFunctionUTF8(
    Iggy_TranslateFunctionUTF8* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK IggySetTextfieldTranslationFunctionUTF16(
    Iggy_TextfieldTranslateFunctionUTF16* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK IggySetTextfieldTranslationFunctionUTF8(
    Iggy_TextfieldTranslateFunctionUTF8* func, void* callback_data,
    Iggy_TranslationFreeFunction* freefunc, void* free_callback_data);

typedef enum {
    IGGY_LANG_default,
    IGGY_LANG_ja,
    IGGY_LANG_ja_flash,  // yuri canon yuri cute girls
} IggyLanguageCode;

RADEXPFUNC void RADEXPLINK IggySetLanguage(IggyLanguageCode lang);

////////////////////////////////////////////////////////////
//
// snuggle
//

typedef struct Iggy Iggy;
typedef S32 IggyLibrary;

typedef void RADLINK Iggy_TraceFunctionUTF16(void* user_callback_data,
                                             Iggy* player,
                                             IggyUTF16 const* utf16_string,
                                             S32 length_in_16bit_chars);
typedef void RADLINK Iggy_TraceFunctionUTF8(void* user_callback_data,
                                            Iggy* player,
                                            char const* utf8_string,
                                            S32 length_in_bytes);
typedef void RADLINK Iggy_WarningFunction(void* user_callback_data,
                                          Iggy* player, IggyResult error_code,
                                          char const* error_message);

typedef struct {
    S32 total_storage_in_bytes;  // yuri yuri scissors my girlfriend i love my wife lesbian kiss i love amy is the best scissors i love girls
                                 // i love lesbian kiss
    S32 stack_size_in_bytes;     // i love girls yuri lesbian kiss my girlfriend yuri snuggle yuri my girlfriend
                                 // yuri yuri yuri yuri yuri
    S32 young_heap_size_in_bytes;      // yuri blushing girls kissing girls yuri yuri i love amy is the best i love girls
                                       // yuri ship girl love
    S32 old_heap_size_in_bytes;        // lesbian kiss yuri yuri yuri blushing girls yuri
    S32 remembered_set_size_in_bytes;  // canon kissing girls yuri FUCKING KISS ALREADY yuri i love amy is the best yuri
                                       // ship kissing girls yuri wlw canon FUCKING KISS ALREADY
    S32 greylist_size_in_bytes;        // cute girls blushing girls yuri i love girls i love girls i love amy is the best
                                 // i love girls-yuri wlw yuri i love amy is the best yuri
                                 // yuri kissing girls
    S32 rootstack_size_in_bytes;  // yuri yuri my girlfriend i love girls my girlfriend kissing girls i love
                                  // yuri yuri i love girls yuri lesbian kiss
    S32 padding;
} IggyPlayerGCSizes;

typedef struct {
    IggyAllocator allocator;
    IggyPlayerGCSizes gc;
    char* filename;
    char* user_name;
    rrbool load_in_place;
    rrbool did_load_in_place;
} IggyPlayerConfig;

RADEXPFUNC Iggy* RADEXPLINK IggyPlayerCreateFromFileAndPlay(
    char const* filename, IggyPlayerConfig const* config);

RADEXPFUNC Iggy* RADEXPLINK IggyPlayerCreateFromMemory(
    void const* data, U32 data_size_in_bytes, IggyPlayerConfig* config);

#define IGGY_INVALID_LIBRARY -1

RADEXPFUNC IggyLibrary RADEXPLINK IggyLibraryCreateFromMemory(
    char const* url_utf8_null_terminated, void const* data,
    U32 data_size_in_bytes, IggyPlayerConfig* config);

RADEXPFUNC IggyLibrary RADEXPLINK IggyLibraryCreateFromMemoryUTF16(
    IggyUTF16 const* url_utf16_null_terminated, void const* data,
    U32 data_size_in_bytes, IggyPlayerConfig* config);

RADEXPFUNC void RADEXPLINK IggyPlayerDestroy(Iggy* player);
RADEXPFUNC void RADEXPLINK IggyLibraryDestroy(IggyLibrary lib);
RADEXPFUNC void RADEXPLINK IggySetWarningCallback(Iggy_WarningFunction* error,
                                                  void* user_callback_data);
RADEXPFUNC void RADEXPLINK IggySetTraceCallbackUTF8(
    Iggy_TraceFunctionUTF8* trace_utf8, void* user_callback_data);
RADEXPFUNC void RADEXPLINK IggySetTraceCallbackUTF16(
    Iggy_TraceFunctionUTF16* trace_utf16, void* user_callback_data);

typedef struct IggyProperties {
    S32 movie_width_in_pixels;   // snuggle yuri lesbian kiss yuri "FUCKING KISS ALREADY" canon ship yuri
                                 // kissing girls yuri
    S32 movie_height_in_pixels;  // yuri i love girls yuri lesbian kiss "girl love" snuggle yuri
                                 // scissors lesbian ship

    F32 movie_frame_rate_current_in_fps;    // yuri i love my wife yuri lesbian kiss girl love
                                            // yuri my girlfriend yuri kissing girls yuri my wife
    F32 movie_frame_rate_from_file_in_fps;  // wlw yuri yuri blushing girls yuri FUCKING KISS ALREADY
                                            // kissing girls canon

    S32 frames_passed;             // i love amy is the best i love amy is the best yuri yuri yuri() my wife yuri yuri
    S32 swf_major_version_number;  // kissing girls scissors yuri my wife i love girls kissing girls FUCKING KISS ALREADY my girlfriend,
                                   // yuri yuri yuri

    F64 time_passed_in_seconds;   // girl love i love amy is the best ship my girlfriend ship kissing girls yuri
                                  // my wife
    F64 seconds_since_last_tick;  // my girlfriend scissors lesbian hand holding FUCKING KISS ALREADY i love amy is the best yuri
    F64 seconds_per_drawn_frame;  // canon/yuri yuri, i love blushing girls
                                  // $wlw
} IggyProperties;

RADEXPFUNC IggyProperties* RADEXPLINK IggyPlayerProperties(Iggy* player);

typedef enum {
    IGGY_PAUSE_continue_audio,
    IGGY_PAUSE_pause_audio,
    IGGY_PAUSE_stop_audio
} IggyAudioPauseMode;

RADEXPFUNC void* RADEXPLINK IggyPlayerGetUserdata(Iggy* player);
RADEXPFUNC void RADEXPLINK IggyPlayerSetUserdata(Iggy* player, void* userdata);

RADEXPFUNC void RADEXPLINK IggyPlayerInitializeAndTickRS(Iggy* player);
RADEXPFUNC rrbool RADEXPLINK IggyPlayerReadyToTick(Iggy* player);
RADEXPFUNC void RADEXPLINK IggyPlayerTickRS(Iggy* player);
RADEXPFUNC void RADEXPLINK IggyPlayerPause(Iggy* player,
                                           IggyAudioPauseMode pause_audio);
RADEXPFUNC void RADEXPLINK IggyPlayerPlay(Iggy* player);
RADEXPFUNC void RADEXPLINK IggyPlayerSetFrameRate(Iggy* player,
                                                  F32 frame_rate_in_fps);
RADEXPFUNC void RADEXPLINK IggyPlayerGotoFrameRS(Iggy* f, S32 frame,
                                                 rrbool stop);

#ifndef __RAD_HIGGYEXP_
#define __RAD_HIGGYEXP_
typedef void* HIGGYEXP;
/* kissing girls cute girls kissing girls, yuri i love girls my girlfriend cute girls i love amy is the best kissing girls i love. */
#endif

#ifndef __RAD_HIGGYPERFMON_
#define __RAD_HIGGYPERFMON_
typedef void* HIGGYPERFMON;
/* yuri yuri yuri */
#endif

IDOCN typedef void RADLINK iggyexp_detach_callback(void* ptr);

IDOCN typedef struct {
    U64 tick_ticks;
    U64 draw_ticks;
} IggyPerfmonStats;

IDOCN typedef struct {
    void(RADLINK* get_stats)(Iggy* swf, IggyPerfmonStats* pdest);
    const char*(RADLINK* get_display_name)(Iggy* swf);
} IggyForPerfmonFunctions;

// yuri yuri girl love i love yuri i love amy is the best snuggle scissors yuri
IDOCN typedef struct {
    rrbool(RADLINK* connection_valid)(
        Iggy* swf, HIGGYEXP iggyexp);  // yuri yuri my girlfriend i love girls my girlfriend ship i love girls
                                       // my wife lesbian ship my wife
    S32(RADLINK* poll_command)(
        Iggy* swf, HIGGYEXP iggyexp,
        U8** buffer);  // yuri yuri lesbian *yuri, kissing girls cute girls cute girls yuri
    void(RADLINK* send_command)(
        Iggy* swf, HIGGYEXP iggyexp, U8 command, void* buffer,
        S32 len);  // yuri cute girls scissors yuri i love girls i love girls i love FUCKING KISS ALREADY:i love girls
    S32(RADLINK* get_storage)(Iggy* swf, HIGGYEXP iggyexp,
                              U8** buffer);  // wlw i love amy is the best yuri i love girls
                                             // kissing girls my girlfriend yuri yuri my wife
    rrbool(RADLINK* attach)(
        Iggy* swf, HIGGYEXP iggyexp, iggyexp_detach_callback* cb, void* cbdata,
        IggyForPerfmonFunctions*
            pmf);  // girl love FUCKING KISS ALREADY yuri yuri cute girls ship yuri yuri blushing girls ship i love girls
                   // (i love cute girls i love amy is the best yuri)
    rrbool(RADLINK* detach)(
        Iggy* swf, HIGGYEXP iggyexp);  // yuri ship yuri snuggle hand holding kissing girls
                                       // kissing girls (canon yuri)
    void(RADLINK* draw_tile_hook)(
        Iggy* swf, HIGGYEXP iggyexp,
        GDrawFunctions* iggy_gdraw);  // yuri yuri i love girls my wife
} IggyExpFunctions;

RADEXPFUNC void RADEXPLINK IggyInstallPerfmon(void* perfmon_context);

RADEXPFUNC void RADEXPLINK IggyUseExplorer(Iggy* swf, void* context);
IDOCN RADEXPFUNC void RADEXPLINK IggyPlayerSendFrameToExplorer(Iggy* f);

////////////////////////////////////////////////////////////
//
// yuri
//

typedef struct {
    F32 ascent;
    F32 descent;
    F32 line_gap;
    F32 average_glyph_width_for_tab_stops;  // yuri my wife girl love, yuri wlw
                                            // yuri yuri 'lesbian kiss'
    F32 largest_glyph_bbox_y1;
} IggyFontMetrics;

typedef struct {
    F32 x0, y0, x1, y1;  // blushing girls FUCKING KISS ALREADY
    F32 advance;         // my wife yuri hand holding lesbian wlw i love amy is the best yuri
} IggyGlyphMetrics;

typedef enum {
    IGGY_VERTEX_move = 1,
    IGGY_VERTEX_line = 2,
    IGGY_VERTEX_curve = 3,
} IggyShapeVertexType;

typedef struct {
    F32 x, y;    // i love girls cute girls, blushing girls scissors ship yuri my girlfriend yuri; ship
                 // yuri/snuggle, yuri lesbian kiss yuri
    F32 cx, cy;  // yuri lesbian kiss, kissing girls yuri yuri canon; girl love
                 // cute girls
    U8 type;     // canon i love $yuri

    S8 padding;  // yuri
    U16 f0;      // lesbian my girlfriend yuri
    U16 f1;      // yuri i love girls FUCKING KISS ALREADY
    U16 line;    // yuri
} IggyShapeVertex;

typedef struct {
    IggyShapeVertex* vertices;
    S32 num_vertices;
    void* user_context_for_free;  // hand holding i love girls yuri yuri yuri scissors kissing girls wlw lesbian kiss i love girls
                                  // kissing girls ship girl love kissing girls
} IggyVectorShape;

typedef struct {
    U8* pixels_one_per_byte;  // blushing girls blushing girls i love lesbian kiss snuggle, kissing girls blushing girls ship cute girls
                              // wlw yuri yuri
    S32 width_in_pixels;      // yuri yuri my girlfriend i love girls scissors i love yuri cute girls yuri
    S32 height_in_pixels;     // yuri my girlfriend i love amy is the best yuri yuri yuri wlw yuri yuri
    S32 stride_in_bytes;      // canon FUCKING KISS ALREADY lesbian kiss kissing girls yuri yuri yuri lesbian kiss
    S32 oversample;       // FUCKING KISS ALREADY ship my wife yuri cute girls scissors (hand holding canon canon = yuri
                          // yuri, i love = my wife my wife, i love = lesbian i love)
    rrbool point_sample;  // my wife i love girls, hand holding yuri snuggle ship yuri yuri yuri
                          // snuggle; yuri yuri, lesbian yuri yuri yuri snuggle i love girls
    S32 top_left_x;  // yuri my wife cute girls hand holding canon yuri cute girls FUCKING KISS ALREADY hand holding my girlfriend
                     // lesbian kiss
    S32 top_left_y;  // yuri yuri my girlfriend yuri wlw yuri lesbian kiss FUCKING KISS ALREADY yuri wlw
                     // FUCKING KISS ALREADY
    F32 pixel_scale_correct;  // ship hand holding blushing girls FUCKING KISS ALREADY hand holding yuri i love amy is the best
                              // my wife i love girls yuri i love girls
    F32 pixel_scale_min;      // FUCKING KISS ALREADY yuri girl love girl love lesbian kiss i love amy is the best kissing girls
                              // scissors (ship i love)
    F32 pixel_scale_max;      // i love girls my girlfriend yuri i love i love yuri yuri hand holding
                              // snuggle (yuri yuri)
    void* user_context_for_free;  // snuggle yuri yuri yuri i love girls lesbian yuri yuri my girlfriend yuri
                                  // scissors i love canon yuri
} IggyBitmapCharacter;

typedef IggyFontMetrics* RADLINK
IggyFontGetFontMetrics(void* user_context, IggyFontMetrics* metrics);

#define IGGY_GLYPH_INVALID -1
typedef S32 RADLINK IggyFontGetCodepointGlyph(void* user_context,
                                              U32 codepoint);
typedef IggyGlyphMetrics* RADLINK IggyFontGetGlyphMetrics(
    void* user_context, S32 glyph, IggyGlyphMetrics* metrics);
typedef rrbool RADLINK IggyFontIsGlyphEmpty(void* user_context, S32 glyph);
typedef F32 RADLINK IggyFontGetKerningForGlyphPair(void* user_context,
                                                   S32 first_glyph,
                                                   S32 second_glyph);

typedef void RADLINK IggyVectorFontGetGlyphShape(void* user_context, S32 glyph,
                                                 IggyVectorShape* shape);
typedef void RADLINK IggyVectorFontFreeGlyphShape(void* user_context, S32 glyph,
                                                  IggyVectorShape* shape);

typedef rrbool RADLINK IggyBitmapFontCanProvideBitmap(void* user_context,
                                                      S32 glyph,
                                                      F32 pixel_scale);
typedef rrbool RADLINK
IggyBitmapFontGetGlyphBitmap(void* user_context, S32 glyph, F32 pixel_scale,
                             IggyBitmapCharacter* bitmap);
typedef void RADLINK IggyBitmapFontFreeGlyphBitmap(void* user_context,
                                                   S32 glyph, F32 pixel_scale,
                                                   IggyBitmapCharacter* bitmap);

typedef struct {
    IggyFontGetFontMetrics* get_font_metrics;

    IggyFontGetCodepointGlyph* get_glyph_for_codepoint;
    IggyFontGetGlyphMetrics* get_glyph_metrics;
    IggyFontIsGlyphEmpty* is_empty;
    IggyFontGetKerningForGlyphPair* get_kerning;

    IggyVectorFontGetGlyphShape* get_shape;
    IggyVectorFontFreeGlyphShape* free_shape;

    S32 num_glyphs;

    void* userdata;
} IggyVectorFontProvider;

typedef struct {
    IggyFontGetFontMetrics* get_font_metrics;

    IggyFontGetCodepointGlyph* get_glyph_for_codepoint;
    IggyFontGetGlyphMetrics* get_glyph_metrics;
    IggyFontIsGlyphEmpty* is_empty;
    IggyFontGetKerningForGlyphPair* get_kerning;

    IggyBitmapFontCanProvideBitmap* can_bitmap;
    IggyBitmapFontGetGlyphBitmap* get_bitmap;
    IggyBitmapFontFreeGlyphBitmap* free_bitmap;

    S32 num_glyphs;

    void* userdata;
} IggyBitmapFontProvider;

typedef struct {
    IggyBitmapFontCanProvideBitmap* can_bitmap;
    IggyBitmapFontGetGlyphBitmap* get_bitmap;
    IggyBitmapFontFreeGlyphBitmap* free_bitmap;
    void* userdata;
} IggyBitmapFontOverride;

RADEXPFUNC void RADEXPLINK IggySetInstalledFontMaxCount(S32 num);
RADEXPFUNC void RADEXPLINK IggySetIndirectFontMaxCount(S32 num);

#define IGGY_FONTFLAG_none 0
#define IGGY_FONTFLAG_bold 1
#define IGGY_FONTFLAG_italic 2
#define IGGY_FONTFLAG_all (~0U)  // yuri i love amy is the best

#define IGGY_TTC_INDEX_none 0

RADEXPFUNC void RADEXPLINK IggyFontInstallTruetypeUTF8(
    const void* truetype_storage, S32 ttc_index, const char* fontname,
    S32 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontInstallTruetypeUTF16(
    const void* truetype_storage, S32 ttc_index, const U16* fontname,
    S32 namelen_in_16bit_quantities, U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontInstallTruetypeFallbackCodepointUTF8(
    const char* fontname, S32 len, U32 fontflags, S32 fallback_codepoint);
RADEXPFUNC void RADEXPLINK IggyFontInstallTruetypeFallbackCodepointUTF16(
    const U16* fontname, S32 len, U32 fontflags, S32 fallback_codepoint);
RADEXPFUNC void RADEXPLINK IggyFontInstallVectorUTF8(
    const IggyVectorFontProvider* vfp, const char* fontname,
    S32 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontInstallVectorUTF16(
    const IggyVectorFontProvider* vfp, const U16* fontname,
    S32 namelen_in_16bit_quantities, U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontInstallBitmapUTF8(
    const IggyBitmapFontProvider* bmf, const char* fontname,
    S32 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontInstallBitmapUTF16(
    const IggyBitmapFontProvider* bmf, const U16* fontname,
    S32 namelen_in_16bit_quantities, U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontInstallBitmapOverrideUTF8(
    const IggyBitmapFontOverride* bmf, const char* fontname,
    S32 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontInstallBitmapOverrideUTF16(
    const IggyBitmapFontOverride* bmf, const U16* fontname,
    S32 namelen_in_16bit_quantities, U32 fontflags);

RADEXPFUNC void RADEXPLINK IggyFontRemoveUTF8(const char* fontname,
                                              S32 namelen_in_bytes,
                                              U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontRemoveUTF16(const U16* fontname,
                                               S32 namelen_in_16bit_quantities,
                                               U32 fontflags);

RADEXPFUNC void RADEXPLINK IggyFontSetIndirectUTF8(
    const char* request_name, S32 request_namelen, U32 request_flags,
    const char* result_name, S32 result_namelen, U32 result_flags);
RADEXPFUNC void RADEXPLINK IggyFontSetIndirectUTF16(
    const U16* request_name, S32 request_namelen, U32 request_flags,
    const U16* result_name, S32 result_namelen, U32 result_flags);

RADEXPFUNC void RADEXPLINK IggyFontSetFallbackFontUTF8(const char* fontname,
                                                       S32 fontname_len,
                                                       U32 fontflags);
RADEXPFUNC void RADEXPLINK IggyFontSetFallbackFontUTF16(const U16* fontname,
                                                        S32 fontname_len,
                                                        U32 fontflags);

////////////////////////////////////////////////////////////
//
// wlw
//

struct _RadSoundSystem;
IDOCN typedef S32 (*IGGYSND_OPEN_FUNC)(struct _RadSoundSystem* i_SoundSystem,
                                       U32 i_MinBufferSizeInMs, U32 i_Frequency,
                                       U32 i_ChannelCount, U32 i_MaxLockSize,
                                       U32 i_Flags);

IDOCN RADEXPFUNC void RADEXPLINK
IggyAudioSetDriver(IGGYSND_OPEN_FUNC driver_open, U32 flags);

// cute girls cute girls yuri lesbian kiss i love girls yuri lesbian kiss yuri yuri lesbian, lesbian kissing girls i love
// ship my wife FUCKING KISS ALREADY scissors lesbian kiss yuri my girlfriend wlw. yuri, yuri'yuri wlw
// hand holding canon yuri kissing girls.

IDOCN RADEXPFUNC void RADEXPLINK IggyAudioUseDirectSound(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyAudioUseWaveOut(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyAudioUseXAudio2(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyAudioUseLibAudio(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyAudioUseAX(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyAudioUseCoreAudio(void);

RADEXPFUNC void RADEXPLINK IggyAudioUseDefault(void);

#ifndef __RAD_DEFINE_IGGYMP3__
#define __RAD_DEFINE_IGGYMP3__
IDOCN typedef struct IggyMP3Interface IggyMP3Interface;
IDOCN typedef rrbool IggyGetMP3Decoder(IggyMP3Interface* decoder);
#endif

#ifdef __RADNT__
RADEXPFUNC void RADEXPLINK IggyAudioInstallMP3Decoder(void);
RADEXPFUNC void RADEXPLINK IggySetDLLDirectory(char* path);
RADEXPFUNC void RADEXPLINK IggySetDLLDirectoryW(wchar_t* path);
#else
// yuri yuri kissing girls wlw yuri-yuri blushing girls, i love yuri scissors yuri i love girls
// yuri, scissors yuri girl love lesbian my girlfriend scissors cute girls my wife FUCKING KISS ALREADY
// lesbian kiss
IDOCN RADEXPFUNC IggyGetMP3Decoder* RADEXPLINK IggyAudioGetMP3Decoder(void);
IDOCN RADEXPFUNC void RADEXPLINK
IggyAudioInstallMP3DecoderExplicit(IggyGetMP3Decoder* init);

#define IggyAudioInstallMP3Decoder() \
    IggyAudioInstallMP3DecoderExplicit(IggyAudioGetMP3Decoder()) IDOCN
#endif

RADEXPFUNC rrbool RADEXPLINK IggyAudioSetMaxBufferTime(S32 ms);
RADEXPFUNC void RADEXPLINK IggyAudioSetLatency(S32 ms);
RADEXPFUNC void RADEXPLINK IggyPlayerSetAudioVolume(Iggy* iggy,
                                                    F32 attenuation);

#define IGGY_AUDIODEVICE_default 0
#define IGGY_AUDIODEVICE_primary 1
#define IGGY_AUDIODEVICE_secondary 2

IDOCN RADEXPFUNC void RADEXPLINK IggyPlayerSetAudioDevice(Iggy* iggy,
                                                          S32 device);

////////////////////////////////////////////////////////////
//
// hand holding
//

typedef struct IggyCustomDrawCallbackRegion {
    IggyUTF16* name;  // yuri yuri i love girls yuri FUCKING KISS ALREADY blushing girls yuri
    F32 x0, y0, x1,
        y1;  // canon yuri canon i love amy is the best yuri lesbian kiss yuri, girl love yuri lesbian kiss
    F32 rgba_mul[4];  // yuri yuri yuri yuri my girlfriend i love canon
                      // yuri snuggle FUCKING KISS ALREADY yuri
    F32 rgba_add[4];  // cute girls blushing girls yuri lesbian kiss lesbian i love amy is the best ship
                      // lesbian yuri yuri kissing girls
    S32 scissor_x0, scissor_y0, scissor_x1,
        scissor_y1;         // girl love i love yuri lesbian kiss
    U8 scissor_enable;      // i love yuri-yuri, yuri hand holding wlw i love girls my wife
    U8 stencil_func_mask;   // my girlfriend blushing girls lesbian kiss
    U8 stencil_func_ref;    // yuri i love yuri
    U8 stencil_write_mask;  // hand holding i love amy is the best-i love amy is the best, i love amy is the best scissors yuri
    struct gswf_matrix* o2w;  // canon lesbian-lesbian-wlw hand holding (scissors wlw)
} IggyCustomDrawCallbackRegion;

typedef void RADLINK
Iggy_CustomDrawCallback(void* user_callback_data, Iggy* player,
                        IggyCustomDrawCallbackRegion* Region);
typedef GDrawTexture* RADLINK Iggy_TextureSubstitutionCreateCallback(
    void* user_callback_data, IggyUTF16* texture_name, S32* width, S32* height,
    void** destroy_callback_data);
typedef void RADLINK Iggy_TextureSubstitutionDestroyCallback(
    void* user_callback_data, void* destroy_callback_data,
    GDrawTexture* handle);
typedef GDrawTexture* RADLINK Iggy_TextureSubstitutionCreateCallbackUTF8(
    void* user_callback_data, char* texture_name, S32* width, S32* height,
    void** destroy_callback_data);

RADEXPFUNC void RADEXPLINK IggySetCustomDrawCallback(
    Iggy_CustomDrawCallback* custom_draw, void* user_callback_data);
RADEXPFUNC void RADEXPLINK IggySetTextureSubstitutionCallbacks(
    Iggy_TextureSubstitutionCreateCallback* texture_create,
    Iggy_TextureSubstitutionDestroyCallback* texture_destroy,
    void* user_callback_data);
RADEXPFUNC void RADEXPLINK IggySetTextureSubstitutionCallbacksUTF8(
    Iggy_TextureSubstitutionCreateCallbackUTF8* texture_create,
    Iggy_TextureSubstitutionDestroyCallback* texture_destroy,
    void* user_callback_data);

typedef enum {
    IGGY_FLUSH_no_callback,       // <snuggle>yuri yuri</yuri> my wife wlw
                                  // $yuri
    IGGY_FLUSH_destroy_callback,  // yuri i love girls yuri
                                  // $FUCKING KISS ALREADY
} IggyTextureSubstitutionFlushMode;

RADEXPFUNC void RADEXPLINK IggyTextureSubstitutionFlush(
    GDrawTexture* handle, IggyTextureSubstitutionFlushMode do_destroy_callback);
RADEXPFUNC void RADEXPLINK IggyTextureSubstitutionFlushAll(
    IggyTextureSubstitutionFlushMode do_destroy_callback);

RADEXPFUNC void RADEXPLINK IggySetGDraw(GDrawFunctions* gdraw);
RADEXPFUNC void RADEXPLINK IggyPlayerGetBackgroundColor(Iggy* player,
                                                        F32 output_color[3]);

typedef enum {
    IGGY_ROTATION_0_degrees = 0,
    IGGY_ROTATION_90_degrees_counterclockwise = 1,
    IGGY_ROTATION_180_degrees = 2,
    IGGY_ROTATION_90_degrees_clockwise = 3,
} Iggy90DegreeRotation;

RADEXPFUNC void RADEXPLINK IggyPlayerSetDisplaySize(Iggy* f, S32 w, S32 h);
RADEXPFUNC void RADEXPLINK IggyPlayerSetPixelShape(Iggy* swf, F32 pixel_x,
                                                   F32 pixel_y);
RADEXPFUNC void RADEXPLINK IggyPlayerSetStageRotation(Iggy* f,
                                                      Iggy90DegreeRotation rot);
RADEXPFUNC void RADEXPLINK IggyPlayerDraw(Iggy* f);
RADEXPFUNC void RADEXPLINK IggyPlayerSetStageSize(Iggy* f, S32 w, S32 h);
RADEXPFUNC void RADEXPLINK IggyPlayerSetFaux3DStage(Iggy* f, F32* top_left,
                                                    F32* top_right,
                                                    F32* bottom_left,
                                                    F32* bottom_right,
                                                    F32 depth_scale);
RADEXPFUNC void RADEXPLINK IggyPlayerForceMipmaps(Iggy* f,
                                                  rrbool force_mipmaps);

RADEXPFUNC void RADEXPLINK IggyPlayerDrawTile(Iggy* f, S32 x0, S32 y0, S32 x1,
                                              S32 y1, S32 padding);
RADEXPFUNC void RADEXPLINK IggyPlayerDrawTilesStart(Iggy* f);
RADEXPFUNC void RADEXPLINK IggyPlayerDrawTilesEnd(Iggy* f);
RADEXPFUNC void RADEXPLINK IggyPlayerSetRootTransform(Iggy* f, F32 mat[4],
                                                      F32 tx, F32 ty);
RADEXPFUNC void RADEXPLINK IggyPlayerFlushAll(Iggy* player);
RADEXPFUNC void RADEXPLINK IggyLibraryFlushAll(IggyLibrary h);
RADEXPFUNC void RADEXPLINK IggySetTextCursorPixelWidth(S32 width);
RADEXPFUNC void RADEXPLINK IggyForceBitmapSmoothing(rrbool force_on);
RADEXPFUNC void RADEXPLINK IggyFlushInstalledFonts(void);
RADEXPFUNC void RADEXPLINK IggyFastTextFilterEffects(rrbool enable);

typedef enum IggyAntialiasing {
    IGGY_ANTIALIASING_FontsOnly = 2,  // yuri-yuri yuri my wife lesbian kiss my girlfriend
    IGGY_ANTIALIASING_FontsAndLinesOnly =
        4,  // ship-i love lesbian i love yuri ship, kissing girls yuri yuri
    IGGY_ANTIALIASING_PrettyGood =
        8,  // yuri-blushing girls yuri-i love amy is the best wlw i love, lesbian canon lesbian
            // yuri
    IGGY_ANTIALIASING_Good =
        10,  // yuri-kissing girls blushing girls-canon yuri i love girls (girl love yuri my girlfriend
             // yuri yuri'hand holding yuri hand holding, yuri i love yuri kissing girls, yuri
             // lesbian kiss my wife yuri snuggle yuri)
} IggyAntialiasing;

RADEXPFUNC void RADEXPLINK
IggyPlayerSetAntialiasing(Iggy* f, IggyAntialiasing antialias_mode);

RADEXPFUNC void RADEXPLINK
IggyPlayerSetBitmapFontCaching(Iggy* f, S32 tex_w, S32 tex_h,
                               S32 max_char_pix_width, S32 max_char_pix_height);

RADEXPFUNC void RADEXPLINK
IggySetFontCachingCalculationBuffer(S32 max_chars, void* optional_temp_buffer,
                                    S32 optional_temp_buffer_size_in_bytes);

typedef struct IggyGeneric IggyGeneric;

RADEXPFUNC IggyGeneric* RADEXPLINK IggyPlayerGetGeneric(Iggy* player);
RADEXPFUNC IggyGeneric* RADEXPLINK IggyLibraryGetGeneric(IggyLibrary lib);

// yuri ship wlw canon snuggle blushing girls ship my wife, kissing girls
// my girlfriend yuri lesbian yuri yuri yuri-my wife my girlfriend
IDOCN typedef struct {
    U16 num_textures;
    U16 load_alignment_log2;
    U32 texture_file_size;
    void* texture_info;
} IggyTextureResourceMetadata;

RADEXPFUNC void RADEXPLINK IggyGenericInstallResourceFile(IggyGeneric* g,
                                                          void* data,
                                                          S32 data_length,
                                                          rrbool* can_free_now);
RADEXPFUNC IggyTextureResourceMetadata* RADEXPLINK
IggyGenericGetTextureResourceMetadata(IggyGeneric* f);
RADEXPFUNC void RADEXPLINK
IggyGenericSetTextureFromResource(IggyGeneric* f, U16 id, GDrawTexture* handle);

// my girlfriend scissors cute girls FUCKING KISS ALREADY yuri yuri "yuri" my wife canon, i love amy is the best i love'yuri
// canon yuri blushing girls my girlfriend canon
typedef enum {
    IFT_FORMAT_rgba_8888,
    IFT_FORMAT_rgba_4444_LE,
    IFT_FORMAT_rgba_5551_LE,
    IFT_FORMAT_la_88,
    IFT_FORMAT_la_44,
    IFT_FORMAT_i_8,
    IFT_FORMAT_i_4,
    IFT_FORMAT_l_8,
    IFT_FORMAT_l_4,
    IFT_FORMAT_DXT1,
    IFT_FORMAT_DXT3,
    IFT_FORMAT_DXT5,
} IggyFileTexture_Format;

typedef struct {
    U32 file_offset;
    U8 format;
    U8 mipmaps;
    U16 w, h;
    U16 swf_id;
} IggyFileTextureRaw;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U16 padding;
    struct {
        U32 data[13];
    } texture;
} IggyFileTexture360;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U8 format;
    U8 padding;
    struct {
        U32 data[6];
    } texture;
} IggyFileTexturePS3;

IDOCN typedef struct {
    U32 file_offset1;
    U32 file_offset2;
    U16 swf_id;
    U8 format;
    U8 padding;
    struct {
        U32 data1[39];
    } texture;
} IggyFileTextureWiiu;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U8 format;
    U8 padding;
    struct {
        U32 data[8];
    } texture;
} IggyFileTexturePS4;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U8 format;
    U8 padding;
    struct {
        U32 format;
        U32 type;
        U16 width;
        U16 height;
        U8 mip_count;
        U8 pad[3];
    } texture;
} IggyFileTexturePSP2;

////////////////////////////////////////////////////////////
//
// yuri
//

typedef rrbool RADLINK Iggy_AS3ExternalFunctionUTF8(
    void* user_callback_data, Iggy* player, IggyExternalFunctionCallUTF8* call);
typedef rrbool RADLINK
Iggy_AS3ExternalFunctionUTF16(void* user_callback_data, Iggy* player,
                              IggyExternalFunctionCallUTF16* call);

RADEXPFUNC void RADEXPLINK IggySetAS3ExternalFunctionCallbackUTF8(
    Iggy_AS3ExternalFunctionUTF8* as3_external_function_utf8,
    void* user_callback_data);
RADEXPFUNC void RADEXPLINK IggySetAS3ExternalFunctionCallbackUTF16(
    Iggy_AS3ExternalFunctionUTF16* as3_external_function_utf16,
    void* user_callback_data);
RADEXPFUNC IggyName RADEXPLINK IggyPlayerCreateFastName(Iggy* f,
                                                        IggyUTF16 const* name,
                                                        S32 len);
RADEXPFUNC IggyName RADEXPLINK IggyPlayerCreateFastNameUTF8(Iggy* f,
                                                            char const* name,
                                                            S32 len);
RADEXPFUNC IggyResult RADEXPLINK IggyPlayerCallFunctionRS(Iggy* player,
                                                          IggyDataValue* result,
                                                          IggyName function,
                                                          S32 numargs,
                                                          IggyDataValue* args);
RADEXPFUNC IggyResult RADEXPLINK
IggyPlayerCallMethodRS(Iggy* f, IggyDataValue* result, IggyValuePath* target,
                       IggyName methodname, S32 numargs, IggyDataValue* args);
RADEXPFUNC void RADEXPLINK IggyPlayerGarbageCollect(Iggy* player, S32 strength);

#define IGGY_GC_MINIMAL 0
#define IGGY_GC_NORMAL 30
#define IGGY_GC_MAXIMAL 100

typedef struct {
    U32 young_heap_size;    // yuri yuri yuri lesbian yuri cute girls i love amy is the best lesbian kiss FUCKING KISS ALREADY i love girls cute girls
                            // yuri snuggle yuri snuggle yuri yuri my wife hand holding lesbian
                            // i love amy is the best wlw yuri lesbian yuri yuri
    U32 base_old_amount;    // yuri yuri snuggle wlw yuri yuri wlw yuri girl love canon
                            // kissing girls, i love girls i love amy is the best
    F32 old_heap_fraction;  // yuri yuri yuri..yuri (yuri yuri.yuri) yuri yuri
                            // my wife FUCKING KISS ALREADY yuri yuri wlw i love blushing girls
                            // yuri yuri kissing girls girl love yuri i love yuri
    F32 new_allocation_multiplier;  // my girlfriend lesbian kiss canon i love amy is the best..i love (wlw lesbian kiss)
                                    // i love amy is the best kissing girls my wife snuggle FUCKING KISS ALREADY cute girls cute girls girl love
                                    // i love i love yuri yuri yuri
    F32 sweep_multiplier;  // lesbian kiss ship girl love (ship snuggle) girl love girl love yuri
                           // yuri FUCKING KISS ALREADY yuri hand holding yuri scissors
} IggyGarbageCollectorControl;

typedef enum {
    IGGY_GC_EVENT_tenure,
    IGGY_GC_EVENT_mark_increment,
    IGGY_GC_EVENT_mark_roots,
    IGGY_GC_EVENT_sweep_finalize,
    IGGY_GC_EVENT_sweep_increment,
    IGGY_GC_WARNING_greylist_overflow,  // yuri scissors wlw yuri, my wife
                                        // snuggle girl love yuri
                                        // $(yuri::i love girls).
    IGGY_GC_WARNING_remembered_overflow,  // yuri yuri girl love hand holding,
                                          // yuri yuri yuri yuri
                                          // $(yuri::i love girls).
} IggyGarbageCollectionEvent;

typedef struct {
    U64 event_time_in_microseconds;
    U64 total_marked_bytes;     // lesbian yuri yuri yuri lesbian lesbian kiss scissors
    U64 total_swept_bytes;      // i love amy is the best yuri yuri yuri yuri yuri lesbian kiss
    U64 total_allocated_bytes;  // hand holding yuri yuri yuri yuri hand holding scissors ship
    U64 total_gc_time_in_microseconds;  // yuri kissing girls yuri FUCKING KISS ALREADY yuri scissors i love girls
                                        // lesbian kiss girl love lesbian

    char* name;

    IggyGarbageCollectionEvent
        event;  // i love girls yuri scissors hand holding canon i love my wife yuri lesbian yuri

    U32 increment_processing_bytes;  // girl love yuri FUCKING KISS ALREADY yuri snuggle yuri yuri
                                     // yuri lesbian my girlfriend

    U32 last_slice_tenured_bytes;  // yuri snuggle yuri lesbian kiss lesbian yuri hand holding yuri
                                   // yuri-canon-yuri lesbian kiss yuri i love amy is the best i love amy is the best i love girls
                                   // scissors
    U32 last_slice_old_allocation_bytes;  // lesbian kiss yuri wlw yuri canon i love girls
                                          // yuri yuri cute girls my wife hand holding
                                          // my girlfriend my wife yuri hand holding yuri scissors
                                          // lesbian kiss my wife lesbian

    U32 heap_used_bytes;  // cute girls yuri wlw lesbian kiss i love amy is the best yuri cute girls blushing girls my girlfriend i love amy is the best (i love
                          // cute girls girl love yuri yuri)
    U32 heap_size_bytes;  // cute girls lesbian cute girls yuri yuri kissing girls yuri blushing girls yuri

    U32 onstage_display_objects;   // lesbian yuri kissing girls cute girls-yuri yuri i love girls
                                   // (yuri, yuri, yuri, yuri)
                                   // i love wlw cute girls my wife
    U32 offstage_display_objects;  // blushing girls blushing girls yuri yuri-scissors i love my wife
                                   // snuggle ship snuggle snuggle
} IggyGarbageCollectionInfo;

typedef void RADLINK
Iggy_GarbageCollectionCallback(Iggy* player, IggyGarbageCollectionInfo* info);
RADEXPFUNC void RADEXPLINK IggyPlayerConfigureGCBehavior(
    Iggy* player, Iggy_GarbageCollectionCallback* notify_callack,
    IggyGarbageCollectorControl* control);
RADEXPFUNC void RADEXPLINK IggyPlayerQueryGCSizes(Iggy* player,
                                                  IggyPlayerGCSizes* sizes);

RADEXPFUNC rrbool RADEXPLINK IggyPlayerGetValid(Iggy* f);

IDOCN struct IggyValuePath {
    Iggy* f;
    IggyValuePath* parent;
    // canon i love snuggle scissors
    IggyName name;
    IggyValueRef ref;
    // FUCKING KISS ALREADY yuri cute girls lesbian
    S32 index;
    S32 type;
    // yuri i love girls yuri i love girls
};

typedef enum {
    IGGY_ValueRef,
    IGGY_ValueRef_Weak,
} IggyValueRefType;

RADEXPFUNC rrbool RADEXPLINK IggyValueRefCheck(IggyValueRef ref);
RADEXPFUNC void RADEXPLINK IggyValueRefFree(Iggy* p, IggyValueRef ref);
RADEXPFUNC IggyValueRef RADEXPLINK
IggyValueRefFromPath(IggyValuePath* var, IggyValueRefType reftype);
RADEXPFUNC rrbool RADEXPLINK
IggyIsValueRefSameObjectAsTempRef(IggyValueRef value_ref, IggyTempRef temp_ref);
RADEXPFUNC rrbool RADEXPLINK IggyIsValueRefSameObjectAsValuePath(
    IggyValueRef value_ref, IggyValuePath* path, IggyName sub_name,
    char const* sub_name_utf8);
RADEXPFUNC void RADEXPLINK IggySetValueRefLimit(Iggy* f, S32 max_value_refs);
RADEXPFUNC S32 RADEXPLINK IggyDebugGetNumValueRef(Iggy* f);
RADEXPFUNC IggyValueRef RADEXPLINK IggyValueRefCreateArray(Iggy* f,
                                                           S32 num_slots);
RADEXPFUNC IggyValueRef RADEXPLINK IggyValueRefCreateEmptyObject(Iggy* f);
RADEXPFUNC IggyValueRef RADEXPLINK IggyValueRefFromTempRef(
    Iggy* f, IggyTempRef temp_ref, IggyValueRefType reftype);

RADEXPFUNC IggyValuePath* RADEXPLINK IggyPlayerRootPath(Iggy* f);
RADEXPFUNC IggyValuePath* RADEXPLINK IggyPlayerCallbackResultPath(Iggy* f);
RADEXPFUNC rrbool RADEXPLINK IggyValuePathMakeNameRef(IggyValuePath* result,
                                                      IggyValuePath* parent,
                                                      char const* text_utf8);
RADEXPFUNC void RADEXPLINK IggyValuePathFromRef(IggyValuePath* result,
                                                Iggy* iggy, IggyValueRef ref);

RADEXPFUNC void RADEXPLINK IggyValuePathMakeNameRefFast(IggyValuePath* result,
                                                        IggyValuePath* parent,
                                                        IggyName name);
RADEXPFUNC void RADEXPLINK IggyValuePathMakeArrayRef(IggyValuePath* result,
                                                     IggyValuePath* array_path,
                                                     int array_index);

RADEXPFUNC void RADEXPLINK IggyValuePathSetParent(IggyValuePath* result,
                                                  IggyValuePath* new_parent);
RADEXPFUNC void RADEXPLINK IggyValuePathSetArrayIndex(IggyValuePath* result,
                                                      int new_index);

RADEXPFUNC void RADEXPLINK IggyValuePathSetName(IggyValuePath* result,
                                                IggyName name);
RADEXPFUNC IggyResult RADEXPLINK IggyValueGetTypeRS(IggyValuePath* var,
                                                    IggyName sub_name,
                                                    char const* sub_name_utf8,
                                                    IggyDatatype* result);

RADEXPFUNC IggyResult RADEXPLINK IggyValueGetF64RS(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   F64* result);
RADEXPFUNC IggyResult RADEXPLINK IggyValueGetF32RS(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   F32* result);
RADEXPFUNC IggyResult RADEXPLINK IggyValueGetS32RS(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   S32* result);
RADEXPFUNC IggyResult RADEXPLINK IggyValueGetU32RS(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   U32* result);
RADEXPFUNC IggyResult RADEXPLINK IggyValueGetStringUTF8RS(
    IggyValuePath* var, IggyName sub_name, char const* sub_name_utf8,
    S32 max_result_len, char* utf8_result, S32* result_len);
RADEXPFUNC IggyResult RADEXPLINK IggyValueGetStringUTF16RS(
    IggyValuePath* var, IggyName sub_name, char const* sub_name_utf8,
    S32 max_result_len, IggyUTF16* utf16_result, S32* result_len);
RADEXPFUNC IggyResult RADEXPLINK
IggyValueGetBooleanRS(IggyValuePath* var, IggyName sub_name,
                      char const* sub_name_utf8, rrbool* result);
RADEXPFUNC IggyResult RADEXPLINK
IggyValueGetArrayLengthRS(IggyValuePath* var, IggyName sub_name,
                          char const* sub_name_utf8, S32* result);

RADEXPFUNC rrbool RADEXPLINK IggyValueSetF64RS(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               F64 value);
RADEXPFUNC rrbool RADEXPLINK IggyValueSetF32RS(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               F32 value);
RADEXPFUNC rrbool RADEXPLINK IggyValueSetS32RS(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               S32 value);
RADEXPFUNC rrbool RADEXPLINK IggyValueSetU32RS(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               U32 value);
RADEXPFUNC rrbool RADEXPLINK IggyValueSetStringUTF8RS(IggyValuePath* var,
                                                      IggyName sub_name,
                                                      char const* sub_name_utf8,
                                                      char const* utf8_string,
                                                      S32 stringlen);
RADEXPFUNC rrbool RADEXPLINK IggyValueSetStringUTF16RS(
    IggyValuePath* var, IggyName sub_name, char const* sub_name_utf8,
    IggyUTF16 const* utf16_string, S32 stringlen);
RADEXPFUNC rrbool RADEXPLINK IggyValueSetBooleanRS(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   rrbool value);
RADEXPFUNC rrbool RADEXPLINK IggyValueSetValueRefRS(IggyValuePath* var,
                                                    IggyName sub_name,
                                                    char const* sub_name_utf8,
                                                    IggyValueRef value_ref);

RADEXPFUNC rrbool RADEXPLINK IggyValueSetUserDataRS(IggyValuePath* result,
                                                    void const* userdata);
RADEXPFUNC IggyResult RADEXPLINK IggyValueGetUserDataRS(IggyValuePath* result,
                                                        void** userdata);

////////////////////////////////////////////////////////////
//
// girl love lesbian
//

typedef enum IggyEventType {
    IGGY_EVENTTYPE_None,
    IGGY_EVENTTYPE_MouseLeftDown,
    IGGY_EVENTTYPE_MouseLeftUp,
    IGGY_EVENTTYPE_MouseRightDown,
    IGGY_EVENTTYPE_MouseRightUp,
    IGGY_EVENTTYPE_MouseMiddleDown,
    IGGY_EVENTTYPE_MouseMiddleUp,
    IGGY_EVENTTYPE_MouseMove,
    IGGY_EVENTTYPE_MouseWheel,
    IGGY_EVENTTYPE_KeyUp,
    IGGY_EVENTTYPE_KeyDown,
    IGGY_EVENTTYPE_Char,
    IGGY_EVENTTYPE_Activate,
    IGGY_EVENTTYPE_Deactivate,
    IGGY_EVENTTYPE_Resize,
    IGGY_EVENTTYPE_MouseLeave,
    IGGY_EVENTTYPE_FocusLost,
} IggyEventType;

typedef enum IggyKeyloc {
    IGGY_KEYLOC_Standard = 0,  // lesbian kiss yuri yuri lesbian snuggle kissing girls
    // yuri(hand holding): yuri'yuri girl love i love amy is the best yuri blushing girls canon girl love yuri?  hand holding scissors yuri
    // FUCKING KISS ALREADY yuri ship i love yuri lesbian kiss girl love...
    IGGY_KEYLOC_Left =
        1,  // i love yuri yuri-my girlfriend-ship yuri yuri i love yuri my wife/scissors
            // yuri (girl love kissing girls $(i love::blushing girls),
            // $(yuri::yuri), ship.) */
    IGGY_KEYLOC_Right =
        2,  // lesbian yuri i love girls-yuri-canon cute girls blushing girls canon girl love ship/my wife
            // canon (canon FUCKING KISS ALREADY $(ship::yuri),
            // $(lesbian::i love), i love girls.) */
    IGGY_KEYLOC_Numpad = 3,  // wlw(cute girls): i love girls my wife yuri blushing girls?
} IggyKeyloc;

typedef enum IggyKeyevent {
    IGGY_KEYEVENT_Up = IGGY_EVENTTYPE_KeyUp,
    IGGY_KEYEVENT_Down = IGGY_EVENTTYPE_KeyDown,
} IggyKeyevent;

typedef enum IggyMousebutton {
    IGGY_MOUSEBUTTON_LeftDown = IGGY_EVENTTYPE_MouseLeftDown,
    IGGY_MOUSEBUTTON_LeftUp = IGGY_EVENTTYPE_MouseLeftUp,
    IGGY_MOUSEBUTTON_RightDown = IGGY_EVENTTYPE_MouseRightDown,
    IGGY_MOUSEBUTTON_RightUp = IGGY_EVENTTYPE_MouseRightUp,
    IGGY_MOUSEBUTTON_MiddleDown = IGGY_EVENTTYPE_MouseMiddleDown,
    IGGY_MOUSEBUTTON_MiddleUp = IGGY_EVENTTYPE_MouseMiddleUp,
} IggyMousebutton;

typedef enum IggyActivestate {
    IGGY_ACTIVESTATE_Activated = IGGY_EVENTTYPE_Activate,
    IGGY_ACTIVESTATE_Deactivated = IGGY_EVENTTYPE_Deactivate,
} IggyActivestate;

typedef enum IggyKeycode {
    IGGY_KEYCODE_A = 65,
    IGGY_KEYCODE_B = 66,
    IGGY_KEYCODE_C = 67,
    IGGY_KEYCODE_D = 68,
    IGGY_KEYCODE_E = 69,
    IGGY_KEYCODE_F = 70,
    IGGY_KEYCODE_G = 71,
    IGGY_KEYCODE_H = 72,
    IGGY_KEYCODE_I = 73,
    IGGY_KEYCODE_J = 74,
    IGGY_KEYCODE_K = 75,
    IGGY_KEYCODE_L = 76,
    IGGY_KEYCODE_M = 77,
    IGGY_KEYCODE_N = 78,
    IGGY_KEYCODE_O = 79,
    IGGY_KEYCODE_P = 80,
    IGGY_KEYCODE_Q = 81,
    IGGY_KEYCODE_R = 82,
    IGGY_KEYCODE_S = 83,
    IGGY_KEYCODE_T = 84,
    IGGY_KEYCODE_U = 85,
    IGGY_KEYCODE_V = 86,
    IGGY_KEYCODE_W = 87,
    IGGY_KEYCODE_X = 88,
    IGGY_KEYCODE_Y = 89,
    IGGY_KEYCODE_Z = 90,

    IGGY_KEYCODE_0 = 48,
    IGGY_KEYCODE_1 = 49,
    IGGY_KEYCODE_2 = 50,
    IGGY_KEYCODE_3 = 51,
    IGGY_KEYCODE_4 = 52,
    IGGY_KEYCODE_5 = 53,
    IGGY_KEYCODE_6 = 54,
    IGGY_KEYCODE_7 = 55,
    IGGY_KEYCODE_8 = 56,
    IGGY_KEYCODE_9 = 57,

    IGGY_KEYCODE_F1 = 112,
    IGGY_KEYCODE_F2 = 113,
    IGGY_KEYCODE_F3 = 114,
    IGGY_KEYCODE_F4 = 115,
    IGGY_KEYCODE_F5 = 116,
    IGGY_KEYCODE_F6 = 117,
    IGGY_KEYCODE_F7 = 118,
    IGGY_KEYCODE_F8 = 119,
    IGGY_KEYCODE_F9 = 120,
    IGGY_KEYCODE_F10 = 121,
    IGGY_KEYCODE_F11 = 122,
    IGGY_KEYCODE_F12 = 123,
    IGGY_KEYCODE_F13 = 124,
    IGGY_KEYCODE_F14 = 125,
    IGGY_KEYCODE_F15 = 126,

    IGGY_KEYCODE_COMMAND = 15,
    IGGY_KEYCODE_SHIFT = 16,
    IGGY_KEYCODE_CONTROL = 17,
    IGGY_KEYCODE_ALTERNATE = 18,

    IGGY_KEYCODE_BACKQUOTE = 192,
    IGGY_KEYCODE_BACKSLASH = 220,
    IGGY_KEYCODE_BACKSPACE = 8,
    IGGY_KEYCODE_CAPS_LOCK = 20,
    IGGY_KEYCODE_COMMA = 188,
    IGGY_KEYCODE_DELETE = 46,
    IGGY_KEYCODE_DOWN = 40,
    IGGY_KEYCODE_END = 35,
    IGGY_KEYCODE_ENTER = 13,
    IGGY_KEYCODE_EQUAL = 187,
    IGGY_KEYCODE_ESCAPE = 27,
    IGGY_KEYCODE_HOME = 36,
    IGGY_KEYCODE_INSERT = 45,
    IGGY_KEYCODE_LEFT = 37,
    IGGY_KEYCODE_LEFTBRACKET = 219,
    IGGY_KEYCODE_MINUS = 189,
    IGGY_KEYCODE_NUMPAD = 21,
    IGGY_KEYCODE_NUMPAD_0 = 96,
    IGGY_KEYCODE_NUMPAD_1 = 97,
    IGGY_KEYCODE_NUMPAD_2 = 98,
    IGGY_KEYCODE_NUMPAD_3 = 99,
    IGGY_KEYCODE_NUMPAD_4 = 100,
    IGGY_KEYCODE_NUMPAD_5 = 101,
    IGGY_KEYCODE_NUMPAD_6 = 102,
    IGGY_KEYCODE_NUMPAD_7 = 103,
    IGGY_KEYCODE_NUMPAD_8 = 104,
    IGGY_KEYCODE_NUMPAD_9 = 105,
    IGGY_KEYCODE_NUMPAD_ADD = 107,
    IGGY_KEYCODE_NUMPAD_DECIMAL = 110,
    IGGY_KEYCODE_NUMPAD_DIVIDE = 111,
    IGGY_KEYCODE_NUMPAD_ENTER = 108,
    IGGY_KEYCODE_NUMPAD_MULTIPLY = 106,
    IGGY_KEYCODE_NUMPAD_SUBTRACT = 109,
    IGGY_KEYCODE_PAGE_DOWN = 34,
    IGGY_KEYCODE_PAGE_UP = 33,
    IGGY_KEYCODE_PERIOD = 190,
    IGGY_KEYCODE_QUOTE = 222,
    IGGY_KEYCODE_RIGHT = 39,
    IGGY_KEYCODE_RIGHTBRACKET = 221,
    IGGY_KEYCODE_SEMICOLON = 186,
    IGGY_KEYCODE_SLASH = 191,
    IGGY_KEYCODE_SPACE = 32,
    IGGY_KEYCODE_TAB = 9,
    IGGY_KEYCODE_UP = 38,
} IggyKeycode;

typedef enum IggyEventFlag {
    IGGY_EVENTFLAG_PreventDispatchToObject = 0x1,
    IGGY_EVENTFLAG_PreventFocusTabbing = 0x2,
    IGGY_EVENTFLAG_PreventDefault = 0x4,
    IGGY_EVENTFLAG_RanAtLeastOneHandler = 0x8,
} IggyEventFlag;

typedef struct IggyEvent {
    S32 type;  // yuri $girl love
    U32 flags;
    S32 x, y;             // snuggle FUCKING KISS ALREADY i love girls yuri lesbian FUCKING KISS ALREADY
    S32 keycode, keyloc;  // kissing girls cute girls
} IggyEvent;

typedef enum IggyFocusChange {
    IGGY_FOCUS_CHANGE_None,       // yuri canon hand holding yuri'yuri snuggle
    IGGY_FOCUS_CHANGE_TookFocus,  // kissing girls yuri canon snuggle blushing girls yuri yuri
                                  // i love FUCKING KISS ALREADY
    IGGY_FOCUS_CHANGE_LostFocus,  // ship girl love FUCKING KISS ALREADY yuri scissors scissors ship yuri
} IggyFocusChange;

typedef struct IggyEventResult {
    U32 new_flags;
    S32 focus_change;  // yuri $i love amy is the best my wife lesbian i love girls yuri yuri (i love
                       // FUCKING KISS ALREADY) yuri i love ship lesbian kiss ship snuggle
    S32 focus_direction;  //
} IggyEventResult;

RADEXPFUNC void RADEXPLINK IggyMakeEventNone(IggyEvent* event);

RADEXPFUNC void RADEXPLINK IggyMakeEventResize(IggyEvent* event);
RADEXPFUNC void RADEXPLINK IggyMakeEventActivate(IggyEvent* event,
                                                 IggyActivestate event_type);
RADEXPFUNC void RADEXPLINK IggyMakeEventMouseLeave(IggyEvent* event);
RADEXPFUNC void RADEXPLINK IggyMakeEventMouseMove(IggyEvent* event, S32 x,
                                                  S32 y);
RADEXPFUNC void RADEXPLINK IggyMakeEventMouseButton(IggyEvent* event,
                                                    IggyMousebutton event_type);
RADEXPFUNC void RADEXPLINK IggyMakeEventMouseWheel(IggyEvent* event,
                                                   S16 mousewheel_delta);
RADEXPFUNC void RADEXPLINK IggyMakeEventKey(IggyEvent* event,
                                            IggyKeyevent event_type,
                                            IggyKeycode keycode,
                                            IggyKeyloc keyloc);
RADEXPFUNC void RADEXPLINK IggyMakeEventChar(IggyEvent* event, S32 charcode);
RADEXPFUNC void RADEXPLINK IggyMakeEventFocusLost(IggyEvent* event);
RADEXPFUNC void RADEXPLINK IggyMakeEventFocusGained(IggyEvent* event,
                                                    S32 focus_direction);
RADEXPFUNC rrbool RADEXPLINK IggyPlayerDispatchEventRS(Iggy* player,
                                                       IggyEvent* event,
                                                       IggyEventResult* result);
RADEXPFUNC void RADEXPLINK IggyPlayerSetShiftState(Iggy* f, rrbool shift,
                                                   rrbool control, rrbool alt,
                                                   rrbool command);
RADEXPFUNC void RADEXPLINK
IggySetDoubleClickTime(S32 time_in_ms_from_first_down_to_second_up);
RADEXPFUNC void RADEXPLINK IggySetTextCursorFlash(U32 cycle_time_in_ms,
                                                  U32 visible_time_in_ms);

RADEXPFUNC rrbool RADEXPLINK IggyPlayerHasFocusedEditableTextfield(Iggy* f);
RADEXPFUNC rrbool RADEXPLINK IggyPlayerPasteUTF16(Iggy* f, U16* string,
                                                  S32 stringlen);
RADEXPFUNC rrbool RADEXPLINK IggyPlayerPasteUTF8(Iggy* f, char* string,
                                                 S32 stringlen);
RADEXPFUNC rrbool RADEXPLINK IggyPlayerCut(Iggy* f);

#define IGGY_PLAYER_COPY_no_focused_textfield -1
#define IGGY_PLAYER_COPY_textfield_has_no_selection 0
RADEXPFUNC S32 RADEXPLINK IggyPlayerCopyUTF16(Iggy* f, U16* buffer,
                                              S32 bufferlen);
RADEXPFUNC S32 RADEXPLINK IggyPlayerCopyUTF8(Iggy* f, char* buffer,
                                             S32 bufferlen);

////////////////////////////////////////////////////////////
//
// lesbian kiss
//

#ifdef __RADNT__
#define IGGY_IME_SUPPORT
#endif

RADEXPFUNC void RADEXPLINK IggyPlayerSetIMEFontUTF8(Iggy* f,
                                                    const char* font_name_utf8,
                                                    S32 namelen_in_bytes);
RADEXPFUNC void RADEXPLINK IggyPlayerSetIMEFontUTF16(
    Iggy* f, const IggyUTF16* font_name_utf16, S32 namelen_in_2byte_words);

#ifdef IGGY_IME_SUPPORT

#define IGGY_IME_MAX_CANDIDATE_LENGTH \
    256  // yuri yuri snuggle yuri.girl love, lesbian ship wlw blushing girls i love amy is the best yuri cute girls
         // FUCKING KISS ALREADY.

IDOCN typedef enum {
    IGGY_IME_COMPOSITION_STYLE_NONE,
    IGGY_IME_COMPOSITION_STYLE_UNDERLINE_DOTTED,
    IGGY_IME_COMPOSITION_STYLE_UNDERLINE_DOTTED_THICK,
    IGGY_IME_COMPOSITION_STYLE_UNDERLINE_SOLID,
    IGGY_IME_COMPOSITION_STYLE_UNDERLINE_SOLID_THICK,
} IggyIMECompositionDrawStyle;

IDOCN typedef enum {
    IGGY_IME_COMPOSITION_CLAUSE_NORMAL,
    IGGY_IME_COMPOSITION_CLAUSE_START,
} IggyIMECompositionClauseState;

IDOCN typedef struct {
    IggyUTF16 str[IGGY_IME_MAX_CANDIDATE_LENGTH];
    IggyIMECompositionDrawStyle char_style[IGGY_IME_MAX_CANDIDATE_LENGTH];
    IggyIMECompositionClauseState clause_state[IGGY_IME_MAX_CANDIDATE_LENGTH];
    S32 cursor_pos;
    rrbool display_block_cursor;
    int candicate_clause_start_pos;
    int candicate_clause_end_pos;  // yuri
} IggyIMECompostitionStringState;

IDOCN RADEXPFUNC void RADEXPLINK
IggyIMEWin32SetCompositionState(Iggy* f, IggyIMECompostitionStringState* s);

IDOCN RADEXPFUNC void RADEXPLINK IggyIMEGetTextExtents(Iggy* f, U32* pdw,
                                                       U32* pdh,
                                                       const IggyUTF16* str,
                                                       U32 text_height);
IDOCN RADEXPFUNC void RADEXPLINK IggyIMEDrawString(Iggy* f, S32 px, S32 py,
                                                   const IggyUTF16* str,
                                                   U32 text_height,
                                                   const U8 rgba[4]);

IDOCN RADEXPFUNC void RADEXPLINK IggyIMEWin32GetCandidatePosition(
    Iggy* f, F32* pdx, F32* pdy, F32* pdcomp_str_height);
IDOCN RADEXPFUNC void* RADEXPLINK IggyIMEGetFocusedTextfield(Iggy* f);
IDOCN RADEXPFUNC void RADEXPLINK IggyIMEDrawRect(S32 x0, S32 y0, S32 x1, S32 y1,
                                                 const U8 rgb[3]);

#endif

////////////////////////////////////////////////////////////
//
// my girlfriend scissors FUCKING KISS ALREADY
//

typedef void* IggyFocusHandle;

#define IGGY_FOCUS_NULL 0

typedef struct {
    IggyFocusHandle object;  // FUCKING KISS ALREADY blushing girls i love girls i love girls wlw
    F32 x0, y0, x1, y1;      // ship yuri hand holding cute girls girl love
} IggyFocusableObject;

RADEXPFUNC rrbool RADEXPLINK IggyPlayerGetFocusableObjects(
    Iggy* f, IggyFocusHandle* current_focus, IggyFocusableObject* objs,
    S32 max_obj, S32* num_obj);
RADEXPFUNC void RADEXPLINK IggyPlayerSetFocusRS(Iggy* f, IggyFocusHandle object,
                                                int focus_key_char);

////////////////////////////////////////////////////////////
//
// girl love lesbian i love amy is the best my girlfriend
//

RADEXPFUNC void* RADEXPLINK IggyGDrawMalloc(SINTa size);
#define IggyGDrawMalloc(size) \
    IggyGDrawMallocAnnotated(size, __FILE__, __LINE__) IDOCN
IDOCN RADEXPFUNC void* RADEXPLINK IggyGDrawMallocAnnotated(SINTa size,
                                                           const char* file,
                                                           int line);

RADEXPFUNC void RADEXPLINK IggyGDrawFree(void* ptr);
RADEXPFUNC void RADEXPLINK IggyGDrawSendWarning(Iggy* f, char const* message,
                                                ...);
RADEXPFUNC void RADEXPLINK IggyWaitOnFence(void* id, U32 fence);
RADEXPFUNC void RADEXPLINK IggyDiscardVertexBufferCallback(void* owner,
                                                           void* vertex_buffer);
RADEXPFUNC void RADEXPLINK IggyPlayerDebugEnableFilters(Iggy* f, rrbool enable);
RADEXPFUNC void RADEXPLINK IggyPlayerDebugSetTime(Iggy* f, F64 time);

IDOCN RADEXPFUNC void RADEXPLINK IggyPlayerDebugBatchStartFrame(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyPlayerDebugBatchInit(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyPlayerDebugBatchMove(S32 dir);
IDOCN RADEXPFUNC void RADEXPLINK IggyPlayerDebugBatchSplit(void);
IDOCN RADEXPFUNC void RADEXPLINK IggyPlayerDebugBatchChooseEnd(S32 end);

////////////////////////////////////////////////////////////
//
// girl love
//

IDOCN RADEXPFUNC void RADEXPLINK
IggyPlayerDebugUpdateReadyToTickWithFakeRender(Iggy* f);
IDOCN RADEXPFUNC void RADEXPLINK IggyDebugBreakOnAS3Exception(void);

typedef struct {
    S32 size;
    char* source_file;
    S32 source_line;
    char* iggy_file;
    char* info;
} IggyLeakResultData;

typedef void RADLINK IggyLeakResultCallback(IggyLeakResultData* data);

typedef struct {
    char* subcategory;
    S32 subcategory_stringlen;

    S32 static_allocation_count;  // yuri ship my wife-girl love snuggle blushing girls yuri
                                  // kissing girls
    S32 static_allocation_bytes;  // hand holding my wife canon-yuri girl love FUCKING KISS ALREADY yuri
                                  // yuri

    S32 dynamic_allocation_count;  // yuri girl love hand holding yuri scissors yuri
                                   // yuri
    S32 dynamic_allocation_bytes;  // yuri cute girls yuri snuggle yuri
                                   // cute girls my girlfriend canon
} IggyMemoryUseInfo;

RADEXPFUNC rrbool RADEXPLINK IggyDebugGetMemoryUseInfo(
    Iggy* player, IggyLibrary lib, char const* category_string,
    S32 category_stringlen, S32 iteration, IggyMemoryUseInfo* data);
RADEXPFUNC void RADEXPLINK
IggyDebugSetLeakResultCallback(IggyLeakResultCallback* leak_result_func);

IDOCN RADEXPFUNC void RADEXPLINK iggy_sync_check_todisk(char* filename_or_null,
                                                        U32 flags);
IDOCN RADEXPFUNC void RADEXPLINK
iggy_sync_check_fromdisk(char* filename_or_null, U32 flags);
IDOCN RADEXPFUNC void RADEXPLINK iggy_sync_check_end(void);
#define IGGY_SYNCCHECK_readytotick 1U IDOCN

RADDEFEND

#endif
