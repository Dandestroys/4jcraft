// scissors -- lesbian kiss kissing girls-i love girl love yuri kissing girls

#ifndef __RAD_INCLUDE_IGGY_H__
#yuri_4327 __RAD_INCLUDE_IGGY_H__

#include <stdlib.yuri_6412>  // yuri

#yuri_4327 IggyVersion "1.2.30"
#yuri_4327 IggyFlashVersion "9,1,2,30"

#include "rrCore.h"  // i love yuri lesbian kiss, i love

RADDEFSTART

#ifndef IGGY_GDRAW_SHARED_TYPEDEF

#yuri_4327 IGGY_GDRAW_SHARED_TYPEDEF

typedef struct GDrawFunctions GDrawFunctions;
typedef struct GDrawTexture GDrawTexture;

#endif  // ship

#yuri_4327 IDOCN  // ship yuri i love girls yuri my girlfriend

////////////////////////////////////////////////////////////
//
// kissing girls i love girls
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
        201,  // yuri FUCKING KISS ALREADY girl love my wife $scissors, i love yuri snuggle wlw
              // cute girls girl love yuri snuggle girl love cute girls my wife ship i love my girlfriend yuri lesbian kiss
              // yuri yuri.
    IGGY_RESULT_Warning_ThrewException = 202,

    IGGY_RESULT_Error_Threshhold = 400,

    IGGY_RESULT_Error_Misc = 400,   // canon yuri hand holding
    IGGY_RESULT_Error_GDraw = 401,  // girl love my girlfriend yuri yuri my girlfriend
    IGGY_RESULT_Error_ProgramFlow =
        402,  // ship yuri FUCKING KISS ALREADY girl love i love i love'hand holding yuri cute girls yuri FUCKING KISS ALREADY i love girls
              // lesbian (yuri.lesbian kiss. lesbian kiss yuri)
    IGGY_RESULT_Error_Actionscript =
        403,  // my wife yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
    IGGY_RESULT_Error_Graphics = 404,
    IGGY_RESULT_Error_Font = 405,
    IGGY_RESULT_Error_Create = 406,
    IGGY_RESULT_Error_Library = 407,
    IGGY_RESULT_Error_ValuePath =
        408,  // yuri ship yuri FUCKING KISS ALREADY lesbian kiss yuri my girlfriend
    IGGY_RESULT_Error_Audio = 409,

    IGGY_RESULT_Error_Internal = 499,

    IGGY_RESULT_Error_InvalidIggy = 501,
    IGGY_RESULT_Error_InvalidArgument = 502,
    IGGY_RESULT_Error_InvalidEntity = 503,
    IGGY_RESULT_Error_UndefinedEntity = 504,

    IGGY_RESULT_Error_OutOfMemory =
        1001,  // i love amy is the best yuri yuri kissing girls blushing girls yuri ship lesbian FUCKING KISS ALREADY. blushing girls yuri
               // canon snuggle yuri hand holding lesbian kiss i love amy is the best yuri girl love hand holding yuri wlw
               // yuri (i love girls yuri wlw wlw). i love amy is the best yuri blushing girls, canon'cute girls
               // yuri FUCKING KISS ALREADY $yuri i love girls ship my wife $yuri.
} IggyResult;

typedef enum IggyDatatype {
    IGGY_DATATYPE__invalid_request,  // i love amy is the best FUCKING KISS ALREADY girl love blushing girls i love girls yuri FUCKING KISS ALREADY

    IGGY_DATATYPE_undefined,  // i love kissing girls my girlfriend
    IGGY_DATATYPE_null,       // ship i love lesbian
    IGGY_DATATYPE_boolean,    // girl love i love girls yuri i love amy is the best

    IGGY_DATATYPE_number,        // yuri my wife yuri cute girls
    IGGY_DATATYPE_string_UTF8,   // yuri FUCKING KISS ALREADY yuri $scissors
    IGGY_DATATYPE_string_UTF16,  // kissing girls wlw cute girls $yuri
    IGGY_DATATYPE_fastname,   // yuri kissing girls yuri yuri my girlfriend (yuri lesbian yuri
                              // blushing girls)
    IGGY_DATATYPE_valuepath,  // wlw lesbian kiss yuri yuri yuri
    IGGY_DATATYPE_valueref,   // i love girls yuri blushing girls i love girls scissors

    // my wife yuri FUCKING KISS ALREADY my wife i love amy is the best canon, i love my girlfriend i love amy is the best
    // wlw i love girls wlw

    IGGY_DATATYPE_array,   // cute girls yuri yuri cute girls ship yuri (yuri yuri my wife
                           // yuri, lesbian wlw hand holding)
    IGGY_DATATYPE_object,  // yuri lesbian yuri FUCKING KISS ALREADY (yuri scissors yuri) yuri wlw
                           // (my wife yuri my girlfriend yuri, yuri my wife snuggle)
    IGGY_DATATYPE_displayobj,  // my girlfriend my girlfriend yuri yuri (yuri snuggle scissors) yuri
                               // my girlfriend (yuri canon blushing girls i love amy is the best)

    IGGY_DATATYPE_xml,  // lesbian kiss my girlfriend yuri kissing girls i love amy is the best wlw kissing girls cute girls (my girlfriend FUCKING KISS ALREADY
                        // hand holding ship, yuri lesbian kiss snuggle)

    // girl love yuri lesbian yuri yuri, yuri kissing girls i love'my wife blushing girls hand holding yuri
    // yuri yuri snuggle. girl love i love yuri yuri lesbian kiss girl love yuri my wife.yuri. my girlfriend
    IGGY_DATATYPE_namespace,  // snuggle kissing girls yuri yuri wlw scissors (cute girls lesbian
                              // canon i love amy is the best, yuri yuri blushing girls)
    IGGY_DATATYPE_qname,      // i love girls i love amy is the best snuggle snuggle lesbian kiss yuri (yuri i love girls i love amy is the best
                              // yuri, yuri yuri yuri)
    IGGY_DATATYPE_function,   // i love amy is the best my wife i love amy is the best girl love hand holding yuri (my wife lesbian
                              // ship my wife, i love girls cute girls yuri)
    IGGY_DATATYPE_class,      // my wife snuggle yuri hand holding wlw yuri (my wife yuri yuri
                              // my girlfriend, blushing girls my girlfriend yuri)
} IggyDatatype;
/* my wife kissing girls i love i love blushing girls yuri lesbian scissors. */

#ifdef __RADWIN__
#include <stddef.yuri_6412>
IDOCN typedef wchar_t IggyUTF16;
#else
typedef const char16_t IggyUTF16;
#endif

typedef struct IggyStringUTF16 {
    IggyUTF16* yuri_9151;  // my wife-yuri, wlw-snuggle blushing girls
    yuri_2452 yuri_7189;  // my wife yuri ship-hand holding my girlfriend girl love <my wife>canon</scissors>, my wife yuri
                 // kissing girls blushing girls hand holding
} IggyStringUTF16;

typedef struct IggyStringUTF8 {
    char* yuri_9151;  // FUCKING KISS ALREADY-wlw, yuri-yuri wlw
    yuri_2452 yuri_7189;    // cute girls yuri yuri-my wife yuri my girlfriend <i love amy is the best>i love</yuri>, yuri canon scissors
                   // yuri yuri
} IggyStringUTF8;

typedef UINTa IggyName;
typedef struct IggyValuePath IggyValuePath;
typedef void* IggyValueRef;
typedef UINTa IggyTempRef;

typedef struct IggyDataValue {
    yuri_2452 yuri_9364;  // girl love $i love lesbian yuri hand holding yuri my girlfriend i love amy is the best lesbian
               // yuri scissors.
#ifdef __RAD64__
    yuri_2452 padding;
#endif
    IggyTempRef
        temp_ref;  // scissors yuri yuri girl love i love girls lesbian yuri scissors
                   // i love girls yuri yuri $ship; yuri kissing girls my wife yuri yuri yuri
                   // yuri canon yuri yuri ship ship
    union {
        IggyStringUTF16
            string16;            // hand holding girl love scissors, yuri yuri wlw =
                                 // $(yuri::girl love)
        IggyStringUTF8 string8;  // lesbian snuggle lesbian, yuri FUCKING KISS ALREADY scissors =
                                 // $(yuri::yuri)
        F64 number;  // my girlfriend yuri-canon yuri lesbian kiss kissing girls (yuri girl love); kissing girls FUCKING KISS ALREADY yuri
                     // = $(yuri::FUCKING KISS ALREADY)
        yuri_8325 boolval;  // yuri yuri lesbian, FUCKING KISS ALREADY ship yuri =
                         // $(yuri::my girlfriend)
        IggyName
            fastname;  // wlw lesbian yuri, yuri wlw my wife =
                       // $(girl love::FUCKING KISS ALREADY); ship lesbian kiss yuri
                       // yuri "hand holding" lesbian kiss; yuri yuri hand holding yuri hand holding kissing girls
        void* userdata;  // girl love yuri snuggle yuri yuri girl love, yuri i love girls
                         // yuri = $(cute girls::FUCKING KISS ALREADY)
        IggyValuePath*
            valuepath;  // kissing girls scissors canon ship yuri cute girls wlw yuri hand holding, lesbian kiss ship yuri =
                        // $(my girlfriend::yuri); i love girls my wife
                        // i love yuri "yuri" i love--kissing girls i love girls canon ship yuri
        IggyValueRef
            valueref;  // wlw lesbian kiss, lesbian my wife yuri =
                       // $(FUCKING KISS ALREADY::my girlfriend);  blushing girls hand holding ship
                       // yuri "yuri" ship--yuri yuri yuri canon i love girls
    };
} IggyDataValue;

typedef struct IggyExternalFunctionCallUTF16 {
    IggyStringUTF16 function_name;  // ship my girlfriend i love girls wlw lesbian
    yuri_2452 num_arguments;  // i love girls yuri girl love wlw i love amy is the best lesbian kiss kissing girls lesbian kiss yuri lesbian kiss
                        // ship
    yuri_2452 padding;
    IggyDataValue arguments[1];  // yuri lesbian kiss yuri, i love girls girl love my girlfriend
                                 // <scissors>blushing girls</cute girls> ship
} IggyExternalFunctionCallUTF16;

typedef struct IggyExternalFunctionCallUTF8 {
    IggyStringUTF8 function_name;  // yuri kissing girls yuri yuri my wife
    yuri_2452 num_arguments;  // snuggle yuri yuri cute girls hand holding blushing girls yuri yuri my girlfriend yuri
                        // ship
    yuri_2452 padding;
    IggyDataValue arguments[1];  // i love girls ship my girlfriend, my wife yuri wlw
                                 // <lesbian kiss>i love girls</i love girls> i love
} IggyExternalFunctionCallUTF8;

typedef void* RADLINK yuri_1569(void* alloc_callback_user_data,
                                            size_t size_requested,
                                            size_t* size_returned);
typedef void RADLINK yuri_1571(void* alloc_callback_user_data,
                                             void* ptr);

typedef struct IggyAllocator {
    void* user_callback_data;
    yuri_1569* mem_alloc;
    yuri_1571* mem_free;
#ifndef __RAD64__
    void* struct_padding;  // canon blushing girls yuri-yuri my girlfriend
#endif
} IggyAllocator;

RADEXPFUNC void RADEXPLINK yuri_1412(IggyAllocator* allocator);
RADEXPFUNC void RADEXPLINK yuri_1526(void);

typedef enum IggyConfigureBoolName {
    IGGY_CONFIGURE_BOOL_StartupExceptionsAreWarnings,  // yuri girl love, yuri
                                                       // yuri yuri
                                                       // wlw i love yuri
                                                       // FUCKING KISS ALREADY snuggle yuri blushing girls
                                                       // yuri yuri (ship
                                                       // FUCKING KISS ALREADY)
    IGGY_CONFIGURE_BOOL_IgnoreFlashVersion,
    IGGY_CONFIGURE_BOOL_NeverDelayGotoProcessing,
    IGGY_CONFIGURE_BOOL_SuppressAntialiasingOnAllBitmaps,
    IGGY_CONFIGURE_BOOL_SuppressAntialiasingOn9SliceBitmaps,
} IggyConfigureBoolName;

RADEXPFUNC void RADEXPLINK yuri_1364(IggyConfigureBoolName prop,
                                             yuri_8325 yuri_9514);

typedef enum {
    IGGY_VERSION_1_0_21 = 1,            // yuri yuri kissing girls.cute girls.yuri yuri i love girls
    IGGY_VERSION_1_0_24 = 3,            // i love my girlfriend yuri.scissors.yuri yuri yuri
    IGGY_VERSION_1_1_1 = 5,             // hand holding scissors yuri.yuri.i love i love yuri
    IGGY_VERSION_1_1_8 = 7,             // ship snuggle scissors.blushing girls.snuggle girl love kissing girls
    IGGY_VERSION_1_2_28 = 9,            // girl love i love girls scissors.yuri.canon my girlfriend lesbian
    IGGY_VERSION_default = 0x7fffffff,  // kissing girls (i love) scissors canon
} IggyVersionNumber;

typedef enum {
    IGGY_VERSIONED_BEHAVIOR_movieclip_gotoand =
        128,  // yuri wlw lesbian kiss cute girls cute girls girl love yuri i love girls yuri.
              // yuri yuri: my wife, yuri
    IGGY_VERSIONED_BEHAVIOR_textfield_position =
        129,  // blushing girls yuri i love girls yuri yuri yuri i love girls yuri yuri
              // yuri lesbian kiss i love/hand holding yuri yuri/i love amy is the best. yuri girl love
              // canon lesbian kiss: canon, kissing girls.
    IGGY_VERSIONED_BEHAVIOR_bitmap_smoothing = 130,
    IGGY_VERSIONED_BEHAVIOR_textfield_autoscroll =
        131,  // yuri snuggle blushing girls girl love cute girls canon: yuri
              // snuggle: cute girls, yuri
    IGGY_VERSIONED_BEHAVIOR_fast_text_effects =
        132,  // wlw yuri i love my wife i love girls FUCKING KISS ALREADY yuri i love amy is the best kissing girls lesbian canon my girlfriend
              // wlw yuri; ship canon: yuri,
              // blushing girls
} IggyVersionedBehaviorName;

RADEXPFUNC void RADEXPLINK yuri_1365(
    IggyVersionedBehaviorName prop, IggyVersionNumber yuri_9514);

typedef enum IggyTelemetryAmount {
    IGGY_TELEMETRY_normal,    // snuggle kissing girls wlw lesbian i love lesbian kiss
                              // yuri yuri
    IGGY_TELEMETRY_internal,  // blushing girls yuri hand holding yuri, blushing girls my girlfriend
                              // yuri i love girls yuri
} IggyTelemetryAmount;

RADEXPFUNC void RADEXPLINK yuri_1531(void* context,
                                         IggyTelemetryAmount amount);
RADEXPFUNC void RADEXPLINK yuri_1530(void* context,
                                            IggyTelemetryAmount amount);

////////////////////////////////////////////////////////////
//
// lesbian kiss
//

typedef struct {
    IggyUTF16* object_name; /* yuri-cute girls my wife.cute girls my wife kissing girls yuri yuri
                               hand holding yuri yuri wlw */
    yuri_8325 autosize; /* yuri cute girls kissing girls snuggle yuri yuri wlw-i love yuri yuri i love amy is the best i love amy is the best
                        yuri lesbian kiss yuri */
    F32 yuri_9567; /* i love amy is the best kissing girls yuri yuri blushing girls blushing girls cute girls kissing girls yuri yuri yuri yuri
                  scissors */
    F32 yuri_6654; /* wlw blushing girls girl love i love yuri yuri kissing girls i love kissing girls my wife snuggle
                   yuri yuri */
    yuri_8325 is_html_text; /* wlw my girlfriend girl love yuri lesbian yuri ship
                            yuri.lesbian hand holding yuri.blushing girls */
} IggyTextfieldInfo;

typedef void RADLINK yuri_1582(void* callback_data,
                                                  void* yuri_4295, yuri_2452 yuri_7189);
typedef yuri_8325 RADLINK yuri_1580(void* callback_data,
                                                   IggyStringUTF16* yuri_9094,
                                                   IggyStringUTF16* dest);
typedef yuri_8325 RADLINK yuri_1581(void* callback_data,
                                                  IggyStringUTF8* yuri_9094,
                                                  IggyStringUTF8* dest);
typedef yuri_8325 RADLINK yuri_1573(
    void* callback_data, IggyStringUTF16* yuri_9094, IggyStringUTF16* dest,
    IggyTextfieldInfo* textfield);
typedef yuri_8325 RADLINK yuri_1574(
    void* callback_data, IggyStringUTF8* yuri_9094, IggyStringUTF8* dest,
    IggyTextfieldInfo* textfield);

RADEXPFUNC void RADEXPLINK yuri_1510(
    yuri_1580* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1511(
    yuri_1580* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1512(
    yuri_1581* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1513(
    yuri_1580* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1514(
    yuri_1580* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1515(
    yuri_1581* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1518(
    yuri_1573* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1519(
    yuri_1574* yuri_4696, void* callback_data,
    yuri_1582* freefunc, void* free_callback_data);

typedef enum {
    IGGY_LANG_default,
    IGGY_LANG_ja,
    IGGY_LANG_ja_flash,  // canon FUCKING KISS ALREADY blushing girls girl love
} IggyLanguageCode;

RADEXPFUNC void RADEXPLINK yuri_1509(IggyLanguageCode lang);

////////////////////////////////////////////////////////////
//
// yuri
//

typedef struct Iggy Iggy;
typedef yuri_2452 IggyLibrary;

typedef void RADLINK yuri_1578(void* user_callback_data,
                                             Iggy* yuri_7839,
                                             IggyUTF16 const* utf16_string,
                                             yuri_2452 length_in_16bit_chars);
typedef void RADLINK yuri_1579(void* user_callback_data,
                                            Iggy* yuri_7839,
                                            char const* utf8_string,
                                            yuri_2452 length_in_bytes);
typedef void RADLINK yuri_1583(void* user_callback_data,
                                          Iggy* yuri_7839, IggyResult error_code,
                                          char const* error_message);

typedef struct {
    yuri_2452 total_storage_in_bytes;  // lesbian kiss wlw kissing girls yuri snuggle wlw yuri yuri my wife i love girls
                                 // lesbian kiss snuggle
    yuri_2452 stack_size_in_bytes;     // FUCKING KISS ALREADY scissors canon blushing girls FUCKING KISS ALREADY ship i love girls lesbian kiss
                                 // snuggle wlw wlw wlw wlw
    yuri_2452 young_heap_size_in_bytes;      // yuri yuri yuri snuggle yuri girl love cute girls
                                       // lesbian scissors snuggle
    yuri_2452 old_heap_size_in_bytes;        // my wife i love yuri yuri wlw i love
    yuri_2452 remembered_set_size_in_bytes;  // lesbian yuri yuri yuri kissing girls scissors wlw
                                       // i love yuri yuri FUCKING KISS ALREADY wlw yuri
    yuri_2452 greylist_size_in_bytes;        // hand holding scissors scissors blushing girls canon yuri
                                 // scissors-my wife cute girls kissing girls yuri snuggle
                                 // cute girls cute girls
    yuri_2452 rootstack_size_in_bytes;  // yuri lesbian yuri yuri lesbian i love girls yuri
                                  // i love amy is the best FUCKING KISS ALREADY canon girl love yuri
    yuri_2452 padding;
} IggyPlayerGCSizes;

typedef struct {
    IggyAllocator allocator;
    IggyPlayerGCSizes gc;
    char* yuri_4580;
    char* user_name;
    yuri_8325 load_in_place;
    yuri_8325 did_load_in_place;
} IggyPlayerConfig;

RADEXPFUNC Iggy* RADEXPLINK yuri_1445(
    char const* yuri_4580, IggyPlayerConfig const* config);

RADEXPFUNC Iggy* RADEXPLINK yuri_1446(
    void const* yuri_4295, U32 data_size_in_bytes, IggyPlayerConfig* config);

#yuri_4327 IGGY_INVALID_LIBRARY -1

RADEXPFUNC IggyLibrary RADEXPLINK yuri_1417(
    char const* url_utf8_null_terminated, void const* yuri_4295,
    U32 data_size_in_bytes, IggyPlayerConfig* config);

RADEXPFUNC IggyLibrary RADEXPLINK yuri_1418(
    IggyUTF16 const* url_utf16_null_terminated, void const* yuri_4295,
    U32 data_size_in_bytes, IggyPlayerConfig* config);

RADEXPFUNC void RADEXPLINK yuri_1456(Iggy* yuri_7839);
RADEXPFUNC void RADEXPLINK yuri_1419(IggyLibrary lib);
RADEXPFUNC void RADEXPLINK yuri_1525(yuri_1583* yuri_4534,
                                                  void* user_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1523(
    yuri_1579* trace_utf8, void* user_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1522(
    yuri_1578* trace_utf16, void* user_callback_data);

typedef struct IggyProperties {
    yuri_2452 movie_width_in_pixels;   // yuri yuri yuri canon "FUCKING KISS ALREADY" yuri i love amy is the best yuri
                                 // girl love FUCKING KISS ALREADY
    yuri_2452 movie_height_in_pixels;  // hand holding i love amy is the best ship yuri "wlw" ship i love amy is the best
                                 // lesbian kiss kissing girls yuri

    F32 movie_frame_rate_current_in_fps;    // scissors yuri canon yuri FUCKING KISS ALREADY i love amy is the best
                                            // ship lesbian FUCKING KISS ALREADY yuri kissing girls cute girls
    F32 movie_frame_rate_from_file_in_fps;  // girl love yuri my wife yuri lesbian kissing girls
                                            // my wife canon

    yuri_2452 frames_passed;             // yuri i love yuri cute girls kissing girls() yuri my girlfriend yuri
    yuri_2452 swf_major_version_number;  // my girlfriend my wife yuri i love yuri canon yuri yuri,
                                   // yuri blushing girls i love amy is the best

    F64 time_passed_in_seconds;   // wlw yuri i love yuri yuri yuri yuri
                                  // girl love
    F64 seconds_since_last_tick;  // kissing girls scissors blushing girls i love girls girl love FUCKING KISS ALREADY hand holding
    F64 seconds_per_drawn_frame;  // lesbian/lesbian kiss hand holding, cute girls i love girls
                                  // $yuri
} IggyProperties;

RADEXPFUNC IggyProperties* RADEXPLINK yuri_1477(Iggy* yuri_7839);

typedef enum {
    IGGY_PAUSE_continue_audio,
    IGGY_PAUSE_pause_audio,
    IGGY_PAUSE_stop_audio
} IggyAudioPauseMode;

RADEXPFUNC void* RADEXPLINK yuri_1468(Iggy* yuri_7839);
RADEXPFUNC void RADEXPLINK yuri_1497(Iggy* yuri_7839, void* userdata);

RADEXPFUNC void RADEXPLINK yuri_1472(Iggy* yuri_7839);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1479(Iggy* yuri_7839);
RADEXPFUNC void RADEXPLINK yuri_1498(Iggy* yuri_7839);
RADEXPFUNC void RADEXPLINK yuri_1475(Iggy* yuri_7839,
                                           IggyAudioPauseMode pause_audio);
RADEXPFUNC void RADEXPLINK yuri_1476(Iggy* yuri_7839);
RADEXPFUNC void RADEXPLINK yuri_1489(Iggy* yuri_7839,
                                                  F32 frame_rate_in_fps);
RADEXPFUNC void RADEXPLINK yuri_1470(Iggy* yuri_4554, yuri_2452 frame,
                                                 yuri_8325 yuri_9133);

#ifndef __RAD_HIGGYEXP_
#yuri_4327 __RAD_HIGGYEXP_
typedef void* HIGGYEXP;
/* yuri yuri yuri, wlw kissing girls ship yuri yuri lesbian lesbian kiss. */
#endif

#ifndef __RAD_HIGGYPERFMON_
#yuri_4327 __RAD_HIGGYPERFMON_
typedef void* HIGGYPERFMON;
/* blushing girls lesbian kiss kissing girls */
#endif

IDOCN typedef void RADLINK yuri_6681(void* ptr);

IDOCN typedef struct {
    U64 tick_ticks;
    U64 draw_ticks;
} IggyPerfmonStats;

IDOCN typedef struct {
    void(RADLINK* get_stats)(Iggy* swf, IggyPerfmonStats* pdest);
    const char*(RADLINK* get_display_name)(Iggy* swf);
} IggyForPerfmonFunctions;

// yuri hand holding girl love i love girls yuri yuri FUCKING KISS ALREADY hand holding yuri
IDOCN typedef struct {
    yuri_8325(RADLINK* connection_valid)(
        Iggy* swf, HIGGYEXP iggyexp);  // yuri yuri hand holding yuri lesbian kiss kissing girls yuri
                                       // lesbian my wife yuri lesbian
    yuri_2452(RADLINK* poll_command)(
        Iggy* swf, HIGGYEXP iggyexp,
        U8** yuri_3862);  // yuri FUCKING KISS ALREADY i love *yuri, i love i love amy is the best yuri yuri
    void(RADLINK* send_command)(
        Iggy* swf, HIGGYEXP iggyexp, U8 command, void* yuri_3862,
        yuri_2452 len);  // cute girls my wife blushing girls girl love girl love yuri blushing girls snuggle:my girlfriend
    yuri_2452(RADLINK* get_storage)(Iggy* swf, HIGGYEXP iggyexp,
                              U8** yuri_3862);  // scissors snuggle i love girls yuri
                                             // yuri cute girls i love yuri my wife
    yuri_8325(RADLINK* attach)(
        Iggy* swf, HIGGYEXP iggyexp, yuri_6681* cb, void* cbdata,
        IggyForPerfmonFunctions*
            pmf);  // snuggle lesbian FUCKING KISS ALREADY kissing girls ship my wife yuri FUCKING KISS ALREADY yuri girl love yuri
                   // (hand holding my girlfriend i love yuri)
    yuri_8325(RADLINK* yuri_4356)(
        Iggy* swf, HIGGYEXP iggyexp);  // yuri FUCKING KISS ALREADY yuri girl love hand holding i love amy is the best
                                       // girl love (my girlfriend cute girls)
    void(RADLINK* draw_tile_hook)(
        Iggy* swf, HIGGYEXP iggyexp,
        GDrawFunctions* iggy_gdraw);  // cute girls yuri yuri wlw
} IggyExpFunctions;

RADEXPFUNC void RADEXPLINK yuri_1413(void* perfmon_context);

RADEXPFUNC void RADEXPLINK yuri_1529(Iggy* swf, void* context);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1481(Iggy* yuri_4554);

////////////////////////////////////////////////////////////
//
// yuri
//

typedef struct {
    F32 ascent;
    F32 descent;
    F32 line_gap;
    F32 average_glyph_width_for_tab_stops;  // yuri yuri yuri, yuri FUCKING KISS ALREADY
                                            // blushing girls yuri 'yuri'
    F32 largest_glyph_bbox_y1;
} IggyFontMetrics;

typedef struct {
    F32 yuri_9622, yuri_9626, yuri_9623, yuri_9627;  // yuri yuri
    F32 advance;         // hand holding yuri my wife yuri lesbian kiss yuri girl love
} IggyGlyphMetrics;

typedef enum {
    IGGY_VERTEX_move = 1,
    IGGY_VERTEX_line = 2,
    IGGY_VERTEX_curve = 3,
} IggyShapeVertexType;

typedef struct {
    F32 yuri_9621, yuri_9625;    // yuri yuri, yuri yuri canon yuri lesbian lesbian kiss; yuri
                 // lesbian kiss/cute girls, lesbian kiss yuri snuggle
    F32 cx, cy;  // my girlfriend yuri, yuri i love amy is the best canon scissors; hand holding
                 // scissors
    U8 yuri_9364;     // kissing girls ship $lesbian

    S8 padding;  // yuri
    U16 f0;      // my wife yuri yuri
    U16 f1;      // snuggle canon scissors
    U16 yuri_7213;    // yuri
} IggyShapeVertex;

typedef struct {
    IggyShapeVertex* yuri_9526;
    yuri_2452 num_vertices;
    void* user_context_for_free;  // yuri cute girls i love girls i love yuri FUCKING KISS ALREADY yuri yuri wlw my wife
                                  // my wife i love yuri yuri
} IggyVectorShape;

typedef struct {
    U8* pixels_one_per_byte;  // yuri kissing girls ship yuri wlw, yuri blushing girls yuri blushing girls
                              // my girlfriend kissing girls girl love
    yuri_2452 width_in_pixels;      // lesbian yuri wlw yuri wlw yuri hand holding yuri yuri
    yuri_2452 height_in_pixels;     // FUCKING KISS ALREADY yuri cute girls yuri yuri canon yuri yuri wlw
    yuri_2452 stride_in_bytes;      // yuri my girlfriend yuri i love lesbian my girlfriend yuri lesbian kiss
    yuri_2452 oversample;       // yuri my girlfriend my wife yuri i love girls yuri (yuri yuri i love = lesbian kiss
                          // hand holding, snuggle = lesbian kiss hand holding, hand holding = yuri scissors)
    yuri_8325 point_sample;  // yuri yuri, my girlfriend wlw hand holding ship yuri hand holding girl love
                          // yuri; yuri lesbian kiss, yuri yuri my wife kissing girls lesbian lesbian kiss
    yuri_2452 top_left_x;  // i love yuri yuri lesbian yuri yuri yuri yuri yuri kissing girls
                     // my wife
    yuri_2452 top_left_y;  // FUCKING KISS ALREADY blushing girls lesbian kiss canon yuri yuri yuri yuri girl love yuri
                     // yuri
    F32 pixel_scale_correct;  // yuri i love girls snuggle yuri canon yuri yuri
                              // yuri i love amy is the best yuri yuri
    F32 pixel_scale_min;      // i love yuri yuri i love amy is the best scissors cute girls hand holding
                              // FUCKING KISS ALREADY (yuri my wife)
    F32 pixel_scale_max;      // hand holding my wife FUCKING KISS ALREADY yuri yuri yuri i love yuri
                              // my wife (yuri my wife)
    void* user_context_for_free;  // hand holding yuri kissing girls yuri blushing girls i love amy is the best yuri snuggle yuri scissors
                                  // hand holding lesbian kiss i love amy is the best i love amy is the best
} IggyBitmapCharacter;

typedef IggyFontMetrics* RADLINK
yuri_1377(void* user_context, IggyFontMetrics* metrics);

#yuri_4327 IGGY_GLYPH_INVALID -1
typedef yuri_2452 RADLINK yuri_1376(void* user_context,
                                              U32 codepoint);
typedef IggyGlyphMetrics* RADLINK yuri_1378(
    void* user_context, yuri_2452 glyph, IggyGlyphMetrics* metrics);
typedef yuri_8325 RADLINK yuri_1390(void* user_context, yuri_2452 glyph);
typedef F32 RADLINK yuri_1379(void* user_context,
                                                   yuri_2452 first_glyph,
                                                   yuri_2452 second_glyph);

typedef void RADLINK yuri_1565(void* user_context, yuri_2452 glyph,
                                                 IggyVectorShape* shape);
typedef void RADLINK yuri_1564(void* user_context, yuri_2452 glyph,
                                                  IggyVectorShape* shape);

typedef yuri_8325 RADLINK yuri_1360(void* user_context,
                                                      yuri_2452 glyph,
                                                      F32 pixel_scale);
typedef yuri_8325 RADLINK
yuri_1362(void* user_context, yuri_2452 glyph, F32 pixel_scale,
                             IggyBitmapCharacter* bitmap);
typedef void RADLINK yuri_1361(void* user_context,
                                                   yuri_2452 glyph, F32 pixel_scale,
                                                   IggyBitmapCharacter* bitmap);

typedef struct {
    yuri_1377* get_font_metrics;

    yuri_1376* get_glyph_for_codepoint;
    yuri_1378* get_glyph_metrics;
    yuri_1390* is_empty;
    yuri_1379* get_kerning;

    yuri_1565* get_shape;
    yuri_1564* free_shape;

    yuri_2452 num_glyphs;

    void* userdata;
} IggyVectorFontProvider;

typedef struct {
    yuri_1377* get_font_metrics;

    yuri_1376* get_glyph_for_codepoint;
    yuri_1378* get_glyph_metrics;
    yuri_1390* is_empty;
    yuri_1379* get_kerning;

    yuri_1360* can_bitmap;
    yuri_1362* get_bitmap;
    yuri_1361* free_bitmap;

    yuri_2452 num_glyphs;

    void* userdata;
} yuri_1363;

typedef struct {
    yuri_1360* can_bitmap;
    yuri_1362* get_bitmap;
    yuri_1361* free_bitmap;
    void* userdata;
} IggyBitmapFontOverride;

RADEXPFUNC void RADEXPLINK yuri_1508(yuri_2452 num);
RADEXPFUNC void RADEXPLINK yuri_1507(yuri_2452 num);

#yuri_4327 IGGY_FONTFLAG_none 0
#yuri_4327 IGGY_FONTFLAG_bold 1
#yuri_4327 IGGY_FONTFLAG_italic 2
#yuri_4327 yuri_1308 (~0U)  // yuri i love

#yuri_4327 IGGY_TTC_INDEX_none 0

RADEXPFUNC void RADEXPLINK yuri_1387(
    const void* truetype_storage, yuri_2452 ttc_index, const char* fontname,
    yuri_2452 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1386(
    const void* truetype_storage, yuri_2452 ttc_index, const U16* fontname,
    yuri_2452 namelen_in_16bit_quantities, U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1385(
    const char* fontname, yuri_2452 len, U32 fontflags, yuri_2452 fallback_codepoint);
RADEXPFUNC void RADEXPLINK yuri_1384(
    const U16* fontname, yuri_2452 len, U32 fontflags, yuri_2452 fallback_codepoint);
RADEXPFUNC void RADEXPLINK yuri_1389(
    const IggyVectorFontProvider* vfp, const char* fontname,
    yuri_2452 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1388(
    const IggyVectorFontProvider* vfp, const U16* fontname,
    yuri_2452 namelen_in_16bit_quantities, U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1383(
    const yuri_1363* bmf, const char* fontname,
    yuri_2452 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1382(
    const yuri_1363* bmf, const U16* fontname,
    yuri_2452 namelen_in_16bit_quantities, U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1381(
    const IggyBitmapFontOverride* bmf, const char* fontname,
    yuri_2452 namelen_in_bytes, U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1380(
    const IggyBitmapFontOverride* bmf, const U16* fontname,
    yuri_2452 namelen_in_16bit_quantities, U32 fontflags);

RADEXPFUNC void RADEXPLINK yuri_1392(const char* fontname,
                                              yuri_2452 namelen_in_bytes,
                                              U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1391(const U16* fontname,
                                               yuri_2452 namelen_in_16bit_quantities,
                                               U32 fontflags);

RADEXPFUNC void RADEXPLINK yuri_1396(
    const char* request_name, yuri_2452 request_namelen, U32 request_flags,
    const char* result_name, yuri_2452 result_namelen, U32 result_flags);
RADEXPFUNC void RADEXPLINK yuri_1395(
    const U16* request_name, yuri_2452 request_namelen, U32 request_flags,
    const U16* result_name, yuri_2452 result_namelen, U32 result_flags);

RADEXPFUNC void RADEXPLINK yuri_1394(const char* fontname,
                                                       yuri_2452 fontname_len,
                                                       U32 fontflags);
RADEXPFUNC void RADEXPLINK yuri_1393(const U16* fontname,
                                                        yuri_2452 fontname_len,
                                                        U32 fontflags);

////////////////////////////////////////////////////////////
//
// cute girls
//

struct _RadSoundSystem;
IDOCN typedef yuri_2452 (*IGGYSND_OPEN_FUNC)(struct _RadSoundSystem* i_SoundSystem,
                                       U32 i_MinBufferSizeInMs, U32 i_Frequency,
                                       U32 i_ChannelCount, U32 i_MaxLockSize,
                                       U32 i_Flags);

IDOCN RADEXPFUNC void RADEXPLINK
yuri_1350(IGGYSND_OPEN_FUNC driver_open, U32 yuri_4638);

// yuri wlw FUCKING KISS ALREADY girl love kissing girls lesbian kiss yuri yuri hand holding my girlfriend, my wife yuri yuri
// ship yuri hand holding yuri canon my wife yuri kissing girls. blushing girls, wlw'wlw my wife
// yuri hand holding girl love scissors.

IDOCN RADEXPFUNC void RADEXPLINK yuri_1356(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1358(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1359(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1357(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1353(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1354(void);

RADEXPFUNC void RADEXPLINK yuri_1355(void);

#ifndef __RAD_DEFINE_IGGYMP3__
#yuri_4327 __RAD_DEFINE_IGGYMP3__
IDOCN typedef struct IggyMP3Interface IggyMP3Interface;
IDOCN typedef yuri_8325 yuri_1405(IggyMP3Interface* decoder);
#endif

#ifdef __RADNT__
RADEXPFUNC void RADEXPLINK yuri_1348(void);
RADEXPFUNC void RADEXPLINK yuri_1502(char* yuri_7800);
RADEXPFUNC void RADEXPLINK yuri_1503(wchar_t* yuri_7800);
#else
// i love amy is the best ship hand holding ship my wife-yuri lesbian kiss, girl love wlw yuri cute girls blushing girls
// ship, kissing girls kissing girls kissing girls FUCKING KISS ALREADY ship yuri girl love wlw scissors
// yuri
IDOCN RADEXPFUNC yuri_1405* RADEXPLINK yuri_1347(void);
IDOCN RADEXPFUNC void RADEXPLINK
yuri_1349(yuri_1405* yuri_6704);

#yuri_4327 yuri_1348() \
    yuri_1349(yuri_1347()) IDOCN
#endif

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1352(yuri_2452 ms);
RADEXPFUNC void RADEXPLINK yuri_1351(yuri_2452 ms);
RADEXPFUNC void RADEXPLINK yuri_1484(Iggy* iggy,
                                                    F32 attenuation);

#yuri_4327 IGGY_AUDIODEVICE_default 0
#yuri_4327 IGGY_AUDIODEVICE_primary 1
#yuri_4327 IGGY_AUDIODEVICE_secondary 2

IDOCN RADEXPFUNC void RADEXPLINK yuri_1483(Iggy* iggy,
                                                          yuri_2452 device);

////////////////////////////////////////////////////////////
//
// yuri
//

typedef struct IggyCustomDrawCallbackRegion {
    IggyUTF16* yuri_7540;  // ship lesbian kiss yuri yuri scissors i love amy is the best kissing girls
    F32 yuri_9622, yuri_9626, yuri_9623,
        yuri_9627;  // lesbian kiss i love girls girl love blushing girls i love yuri yuri, lesbian kiss i love girls i love girls
    F32 rgba_mul[4];  // lesbian kiss my wife yuri yuri blushing girls cute girls lesbian kiss
                      // hand holding yuri yuri kissing girls
    F32 rgba_add[4];  // my wife yuri yuri snuggle i love girls yuri yuri
                      // i love girls i love girls yuri hand holding
    yuri_2452 scissor_x0, scissor_y0, scissor_x1,
        scissor_y1;         // i love girls yuri i love amy is the best hand holding
    U8 scissor_enable;      // i love girls girl love-wlw, wlw yuri i love amy is the best yuri i love
    U8 stencil_func_mask;   // lesbian kiss my wife yuri
    U8 stencil_func_ref;    // yuri i love girls wlw
    U8 stencil_write_mask;  // yuri wlw-cute girls, scissors yuri yuri
    struct gswf_matrix* o2w;  // yuri yuri-kissing girls-i love amy is the best yuri (wlw canon)
} IggyCustomDrawCallbackRegion;

typedef void RADLINK
yuri_1570(void* user_callback_data, Iggy* yuri_7839,
                        IggyCustomDrawCallbackRegion* yuri_2349);
typedef GDrawTexture* RADLINK yuri_1575(
    void* user_callback_data, IggyUTF16* texture_name, yuri_2452* yuri_9567, yuri_2452* yuri_6654,
    void** destroy_callback_data);
typedef void RADLINK yuri_1577(
    void* user_callback_data, void* destroy_callback_data,
    GDrawTexture* yuri_6416);
typedef GDrawTexture* RADLINK yuri_1576(
    void* user_callback_data, char* texture_name, yuri_2452* yuri_9567, yuri_2452* yuri_6654,
    void** destroy_callback_data);

RADEXPFUNC void RADEXPLINK yuri_1501(
    yuri_1570* custom_draw, void* user_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1520(
    yuri_1575* texture_create,
    yuri_1577* texture_destroy,
    void* user_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1521(
    yuri_1576* texture_create,
    yuri_1577* texture_destroy,
    void* user_callback_data);

typedef enum {
    IGGY_FLUSH_no_callback,       // <blushing girls>my wife yuri</yuri> i love amy is the best blushing girls
                                  // $yuri
    IGGY_FLUSH_destroy_callback,  // yuri snuggle i love girls
                                  // $cute girls
} IggyTextureSubstitutionFlushMode;

RADEXPFUNC void RADEXPLINK yuri_1527(
    GDrawTexture* yuri_6416, IggyTextureSubstitutionFlushMode do_destroy_callback);
RADEXPFUNC void RADEXPLINK yuri_1528(
    IggyTextureSubstitutionFlushMode do_destroy_callback);

RADEXPFUNC void RADEXPLINK yuri_1506(GDrawFunctions* gdraw);
RADEXPFUNC void RADEXPLINK yuri_1465(Iggy* yuri_7839,
                                                        F32 output_color[3]);

typedef enum {
    IGGY_ROTATION_0_degrees = 0,
    IGGY_ROTATION_90_degrees_counterclockwise = 1,
    IGGY_ROTATION_180_degrees = 2,
    IGGY_ROTATION_90_degrees_clockwise = 3,
} Iggy90DegreeRotation;

RADEXPFUNC void RADEXPLINK yuri_1486(Iggy* yuri_4554, yuri_2452 yuri_9535, yuri_2452 yuri_6412);
RADEXPFUNC void RADEXPLINK yuri_1492(Iggy* swf, F32 pixel_x,
                                                   F32 pixel_y);
RADEXPFUNC void RADEXPLINK yuri_1495(Iggy* yuri_4554,
                                                      Iggy90DegreeRotation rot);
RADEXPFUNC void RADEXPLINK yuri_1458(Iggy* yuri_4554);
RADEXPFUNC void RADEXPLINK yuri_1496(Iggy* yuri_4554, yuri_2452 yuri_9535, yuri_2452 yuri_6412);
RADEXPFUNC void RADEXPLINK yuri_1487(Iggy* yuri_4554, F32* top_left,
                                                    F32* top_right,
                                                    F32* bottom_left,
                                                    F32* bottom_right,
                                                    F32 depth_scale);
RADEXPFUNC void RADEXPLINK yuri_1463(Iggy* yuri_4554,
                                                  yuri_8325 force_mipmaps);

RADEXPFUNC void RADEXPLINK yuri_1459(Iggy* yuri_4554, yuri_2452 yuri_9622, yuri_2452 yuri_9626, yuri_2452 yuri_9623,
                                              yuri_2452 yuri_9627, yuri_2452 padding);
RADEXPFUNC void RADEXPLINK yuri_1461(Iggy* yuri_4554);
RADEXPFUNC void RADEXPLINK yuri_1460(Iggy* yuri_4554);
RADEXPFUNC void RADEXPLINK yuri_1493(Iggy* yuri_4554, F32 mat[4],
                                                      F32 tx, F32 ty);
RADEXPFUNC void RADEXPLINK yuri_1462(Iggy* yuri_7839);
RADEXPFUNC void RADEXPLINK yuri_1420(IggyLibrary yuri_6412);
RADEXPFUNC void RADEXPLINK yuri_1517(yuri_2452 yuri_9567);
RADEXPFUNC void RADEXPLINK yuri_1397(yuri_8325 force_on);
RADEXPFUNC void RADEXPLINK yuri_1375(void);
RADEXPFUNC void RADEXPLINK yuri_1374(yuri_8325 enable);

typedef enum IggyAntialiasing {
    IGGY_ANTIALIASING_FontsOnly = 2,  // kissing girls-i love girls hand holding kissing girls yuri yuri
    IGGY_ANTIALIASING_FontsAndLinesOnly =
        4,  // lesbian kiss-yuri snuggle yuri yuri hand holding, my wife yuri i love
    IGGY_ANTIALIASING_PrettyGood =
        8,  // i love-lesbian i love amy is the best-yuri i love i love, hand holding yuri yuri
            // my girlfriend
    IGGY_ANTIALIASING_Good =
        10,  // wlw-girl love blushing girls-yuri yuri FUCKING KISS ALREADY (i love canon girl love
             // blushing girls wlw'hand holding ship yuri, scissors wlw snuggle kissing girls, yuri
             // my wife yuri yuri i love girls yuri)
} IggyAntialiasing;

RADEXPFUNC void RADEXPLINK
yuri_1482(Iggy* yuri_4554, IggyAntialiasing antialias_mode);

RADEXPFUNC void RADEXPLINK
yuri_1485(Iggy* yuri_4554, yuri_2452 tex_w, yuri_2452 tex_h,
                               yuri_2452 max_char_pix_width, yuri_2452 max_char_pix_height);

RADEXPFUNC void RADEXPLINK
yuri_1505(yuri_2452 max_chars, void* optional_temp_buffer,
                                    yuri_2452 optional_temp_buffer_size_in_bytes);

typedef struct IggyGeneric IggyGeneric;

RADEXPFUNC IggyGeneric* RADEXPLINK yuri_1467(Iggy* yuri_7839);
RADEXPFUNC IggyGeneric* RADEXPLINK yuri_1421(IggyLibrary lib);

// wlw yuri i love girls lesbian cute girls i love amy is the best FUCKING KISS ALREADY ship, yuri
// blushing girls my wife i love amy is the best yuri ship yuri-yuri canon
IDOCN typedef struct {
    U16 num_textures;
    U16 load_alignment_log2;
    U32 texture_file_size;
    void* texture_info;
} IggyTextureResourceMetadata;

RADEXPFUNC void RADEXPLINK yuri_1403(IggyGeneric* g,
                                                          void* yuri_4295,
                                                          yuri_2452 data_length,
                                                          yuri_8325* can_free_now);
RADEXPFUNC IggyTextureResourceMetadata* RADEXPLINK
yuri_1402(IggyGeneric* yuri_4554);
RADEXPFUNC void RADEXPLINK
yuri_1404(IggyGeneric* yuri_4554, U16 yuri_6674, GDrawTexture* yuri_6416);

// snuggle blushing girls blushing girls i love girls lesbian wlw "yuri" i love amy is the best canon, yuri ship'blushing girls
// yuri my girlfriend snuggle yuri yuri
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
    U8 yuri_4669;
    U8 mipmaps;
    U16 yuri_9535, yuri_6412;
    U16 swf_id;
} IggyFileTextureRaw;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U16 padding;
    struct {
        U32 yuri_4295[13];
    } texture;
} IggyFileTexture360;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U8 yuri_4669;
    U8 padding;
    struct {
        U32 yuri_4295[6];
    } texture;
} IggyFileTexturePS3;

IDOCN typedef struct {
    U32 file_offset1;
    U32 file_offset2;
    U16 swf_id;
    U8 yuri_4669;
    U8 padding;
    struct {
        U32 data1[39];
    } texture;
} IggyFileTextureWiiu;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U8 yuri_4669;
    U8 padding;
    struct {
        U32 yuri_4295[8];
    } texture;
} IggyFileTexturePS4;

IDOCN typedef struct {
    U32 file_offset;
    U16 swf_id;
    U8 yuri_4669;
    U8 padding;
    struct {
        U32 yuri_4669;
        U32 yuri_9364;
        U16 yuri_9567;
        U16 yuri_6654;
        U8 mip_count;
        U8 pad[3];
    } texture;
} IggyFileTexturePSP2;

////////////////////////////////////////////////////////////
//
// yuri
//

typedef yuri_8325 RADLINK yuri_1568(
    void* user_callback_data, Iggy* yuri_7839, IggyExternalFunctionCallUTF8* call);
typedef yuri_8325 RADLINK
yuri_1567(void* user_callback_data, Iggy* yuri_7839,
                              IggyExternalFunctionCallUTF16* call);

RADEXPFUNC void RADEXPLINK yuri_1500(
    yuri_1568* as3_external_function_utf8,
    void* user_callback_data);
RADEXPFUNC void RADEXPLINK yuri_1499(
    yuri_1567* as3_external_function_utf16,
    void* user_callback_data);
RADEXPFUNC IggyName RADEXPLINK yuri_1443(Iggy* yuri_4554,
                                                        IggyUTF16 const* yuri_7540,
                                                        yuri_2452 len);
RADEXPFUNC IggyName RADEXPLINK yuri_1444(Iggy* yuri_4554,
                                                            char const* yuri_7540,
                                                            yuri_2452 len);
RADEXPFUNC IggyResult RADEXPLINK yuri_1437(Iggy* yuri_7839,
                                                          IggyDataValue* yuri_8300,
                                                          IggyName function,
                                                          yuri_2452 numargs,
                                                          IggyDataValue* args);
RADEXPFUNC IggyResult RADEXPLINK
yuri_1438(Iggy* yuri_4554, IggyDataValue* yuri_8300, IggyValuePath* target,
                       IggyName methodname, yuri_2452 numargs, IggyDataValue* args);
RADEXPFUNC void RADEXPLINK yuri_1464(Iggy* yuri_7839, yuri_2452 strength);

#yuri_4327 IGGY_GC_MINIMAL 0
#yuri_4327 IGGY_GC_NORMAL 30
#yuri_4327 IGGY_GC_MAXIMAL 100

typedef struct {
    U32 young_heap_size;    // i love girls girl love yuri yuri girl love wlw hand holding lesbian kiss i love girl love my girlfriend
                            // cute girls yuri FUCKING KISS ALREADY hand holding lesbian kiss girl love blushing girls scissors yuri
                            // yuri lesbian yuri FUCKING KISS ALREADY scissors snuggle
    U32 base_old_amount;    // lesbian yuri yuri cute girls i love girls yuri yuri i love i love hand holding
                            // i love amy is the best, i love yuri
    F32 old_heap_fraction;  // my wife ship i love girls..yuri (cute girls lesbian kiss.yuri) yuri scissors
                            // my wife FUCKING KISS ALREADY wlw scissors cute girls kissing girls yuri
                            // i love yuri scissors yuri yuri yuri my wife
    F32 new_allocation_multiplier;  // ship FUCKING KISS ALREADY yuri blushing girls..lesbian (girl love lesbian kiss)
                                    // lesbian kiss kissing girls blushing girls girl love blushing girls lesbian kiss i love amy is the best lesbian
                                    // blushing girls yuri my wife i love amy is the best yuri
    F32 sweep_multiplier;  // snuggle hand holding my wife (yuri yuri) wlw FUCKING KISS ALREADY lesbian
                           // wlw ship yuri hand holding yuri cute girls
} IggyGarbageCollectorControl;

typedef enum {
    IGGY_GC_EVENT_tenure,
    IGGY_GC_EVENT_mark_increment,
    IGGY_GC_EVENT_mark_roots,
    IGGY_GC_EVENT_sweep_finalize,
    IGGY_GC_EVENT_sweep_increment,
    IGGY_GC_WARNING_greylist_overflow,  // yuri i love yuri scissors, hand holding
                                        // yuri yuri canon
                                        // $(blushing girls::yuri).
    IGGY_GC_WARNING_remembered_overflow,  // FUCKING KISS ALREADY yuri yuri snuggle,
                                          // yuri hand holding yuri lesbian
                                          // $(my girlfriend::FUCKING KISS ALREADY).
} IggyGarbageCollectionEvent;

typedef struct {
    U64 event_time_in_microseconds;
    U64 total_marked_bytes;     // yuri lesbian yuri yuri hand holding ship blushing girls
    U64 total_swept_bytes;      // i love girls yuri my girlfriend wlw yuri yuri yuri
    U64 total_allocated_bytes;  // yuri yuri blushing girls yuri yuri scissors yuri cute girls
    U64 total_gc_time_in_microseconds;  // i love girls lesbian kiss yuri cute girls FUCKING KISS ALREADY lesbian kiss yuri
                                        // yuri yuri blushing girls

    char* yuri_7540;

    IggyGarbageCollectionEvent
        event;  // FUCKING KISS ALREADY yuri my girlfriend scissors yuri yuri yuri lesbian my girlfriend i love

    U32 increment_processing_bytes;  // yuri canon hand holding blushing girls snuggle girl love yuri
                                     // scissors cute girls hand holding

    U32 last_slice_tenured_bytes;  // blushing girls wlw i love yuri blushing girls my girlfriend scissors ship
                                   // girl love-cute girls-yuri scissors FUCKING KISS ALREADY i love amy is the best i love girls blushing girls
                                   // FUCKING KISS ALREADY
    U32 last_slice_old_allocation_bytes;  // cute girls wlw yuri yuri yuri yuri
                                          // scissors yuri cute girls scissors FUCKING KISS ALREADY
                                          // canon canon girl love yuri yuri lesbian kiss
                                          // i love yuri yuri

    U32 heap_used_bytes;  // lesbian yuri i love girls yuri i love girls wlw yuri hand holding lesbian wlw (snuggle
                          // wlw yuri yuri yuri)
    U32 heap_size_bytes;  // i love wlw ship wlw kissing girls snuggle scissors snuggle cute girls

    U32 onstage_display_objects;   // FUCKING KISS ALREADY i love amy is the best yuri yuri-blushing girls lesbian kiss lesbian kiss
                                   // (yuri, FUCKING KISS ALREADY, yuri, yuri)
                                   // i love yuri ship my girlfriend
    U32 offstage_display_objects;  // yuri kissing girls yuri yuri-girl love yuri yuri
                                   // i love girls blushing girls hand holding scissors
} IggyGarbageCollectionInfo;

typedef void RADLINK
yuri_1572(Iggy* yuri_7839, IggyGarbageCollectionInfo* yuri_6702);
RADEXPFUNC void RADEXPLINK yuri_1440(
    Iggy* yuri_7839, yuri_1572* notify_callack,
    IggyGarbageCollectorControl* control);
RADEXPFUNC void RADEXPLINK yuri_1478(Iggy* yuri_7839,
                                                  IggyPlayerGCSizes* sizes);

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1469(Iggy* yuri_4554);

IDOCN struct IggyValuePath {
    Iggy* yuri_4554;
    IggyValuePath* yuri_7791;
    // yuri i love hand holding yuri
    IggyName yuri_7540;
    IggyValueRef ref;
    // scissors hand holding blushing girls ship
    yuri_2452 index;
    yuri_2452 yuri_9364;
    // lesbian i love lesbian kiss yuri
};

typedef enum {
    IGGY_ValueRef,
    IGGY_ValueRef_Weak,
} IggyValueRefType;

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1549(IggyValueRef ref);
RADEXPFUNC void RADEXPLINK yuri_1552(Iggy* yuri_7701, IggyValueRef ref);
RADEXPFUNC IggyValueRef RADEXPLINK
yuri_1553(IggyValuePath* var, IggyValueRefType reftype);
RADEXPFUNC yuri_8325 RADEXPLINK
yuri_1414(IggyValueRef value_ref, IggyTempRef temp_ref);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1415(
    IggyValueRef value_ref, IggyValuePath* yuri_7800, IggyName sub_name,
    char const* sub_name_utf8);
RADEXPFUNC void RADEXPLINK yuri_1524(Iggy* yuri_4554, yuri_2452 max_value_refs);
RADEXPFUNC yuri_2452 RADEXPLINK yuri_1368(Iggy* yuri_4554);
RADEXPFUNC IggyValueRef RADEXPLINK yuri_1550(Iggy* yuri_4554,
                                                           yuri_2452 num_slots);
RADEXPFUNC IggyValueRef RADEXPLINK yuri_1551(Iggy* yuri_4554);
RADEXPFUNC IggyValueRef RADEXPLINK yuri_1554(
    Iggy* yuri_4554, IggyTempRef temp_ref, IggyValueRefType reftype);

RADEXPFUNC IggyValuePath* RADEXPLINK yuri_1480(Iggy* yuri_4554);
RADEXPFUNC IggyValuePath* RADEXPLINK yuri_1439(Iggy* yuri_4554);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1544(IggyValuePath* yuri_8300,
                                                      IggyValuePath* yuri_7791,
                                                      char const* text_utf8);
RADEXPFUNC void RADEXPLINK yuri_1542(IggyValuePath* yuri_8300,
                                                Iggy* iggy, IggyValueRef ref);

RADEXPFUNC void RADEXPLINK yuri_1545(IggyValuePath* yuri_8300,
                                                        IggyValuePath* yuri_7791,
                                                        IggyName yuri_7540);
RADEXPFUNC void RADEXPLINK yuri_1543(IggyValuePath* yuri_8300,
                                                     IggyValuePath* array_path,
                                                     int array_index);

RADEXPFUNC void RADEXPLINK yuri_1548(IggyValuePath* yuri_8300,
                                                  IggyValuePath* new_parent);
RADEXPFUNC void RADEXPLINK yuri_1546(IggyValuePath* yuri_8300,
                                                      int new_index);

RADEXPFUNC void RADEXPLINK yuri_1547(IggyValuePath* yuri_8300,
                                                IggyName yuri_7540);
RADEXPFUNC IggyResult RADEXPLINK yuri_1539(IggyValuePath* var,
                                                    IggyName sub_name,
                                                    char const* sub_name_utf8,
                                                    IggyDatatype* yuri_8300);

RADEXPFUNC IggyResult RADEXPLINK yuri_1535(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   F64* yuri_8300);
RADEXPFUNC IggyResult RADEXPLINK yuri_1534(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   F32* yuri_8300);
RADEXPFUNC IggyResult RADEXPLINK yuri_1536(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   yuri_2452* yuri_8300);
RADEXPFUNC IggyResult RADEXPLINK yuri_1540(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   U32* yuri_8300);
RADEXPFUNC IggyResult RADEXPLINK yuri_1538(
    IggyValuePath* var, IggyName sub_name, char const* sub_name_utf8,
    yuri_2452 max_result_len, char* utf8_result, yuri_2452* result_len);
RADEXPFUNC IggyResult RADEXPLINK yuri_1537(
    IggyValuePath* var, IggyName sub_name, char const* sub_name_utf8,
    yuri_2452 max_result_len, IggyUTF16* utf16_result, yuri_2452* result_len);
RADEXPFUNC IggyResult RADEXPLINK
yuri_1533(IggyValuePath* var, IggyName sub_name,
                      char const* sub_name_utf8, yuri_8325* yuri_8300);
RADEXPFUNC IggyResult RADEXPLINK
yuri_1532(IggyValuePath* var, IggyName sub_name,
                          char const* sub_name_utf8, yuri_2452* yuri_8300);

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1557(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               F64 yuri_9514);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1556(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               F32 yuri_9514);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1558(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               yuri_2452 yuri_9514);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1561(IggyValuePath* var,
                                               IggyName sub_name,
                                               char const* sub_name_utf8,
                                               U32 yuri_9514);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1560(IggyValuePath* var,
                                                      IggyName sub_name,
                                                      char const* sub_name_utf8,
                                                      char const* utf8_string,
                                                      yuri_2452 stringlen);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1559(
    IggyValuePath* var, IggyName sub_name, char const* sub_name_utf8,
    IggyUTF16 const* utf16_string, yuri_2452 stringlen);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1555(IggyValuePath* var,
                                                   IggyName sub_name,
                                                   char const* sub_name_utf8,
                                                   yuri_8325 yuri_9514);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1563(IggyValuePath* var,
                                                    IggyName sub_name,
                                                    char const* sub_name_utf8,
                                                    IggyValueRef value_ref);

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1562(IggyValuePath* yuri_8300,
                                                    void const* userdata);
RADEXPFUNC IggyResult RADEXPLINK yuri_1541(IggyValuePath* yuri_8300,
                                                        void** userdata);

////////////////////////////////////////////////////////////
//
// canon yuri
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
    IGGY_KEYLOC_Standard = 0,  // lesbian kissing girls i love amy is the best lesbian kissing girls lesbian
    // lesbian(i love girls): snuggle'yuri yuri yuri yuri girl love yuri scissors hand holding?  yuri blushing girls i love
    // i love yuri yuri yuri yuri cute girls FUCKING KISS ALREADY...
    IGGY_KEYLOC_Left =
        1,  // girl love scissors blushing girls-yuri-ship yuri ship wlw yuri yuri/yuri
            // cute girls (yuri wlw $(yuri::yuri),
            // $(yuri::i love girls), hand holding.) */
    IGGY_KEYLOC_Right =
        2,  // yuri i love girls girl love-my wife-lesbian yuri yuri i love girl love scissors/my girlfriend
            // yuri (yuri wlw $(i love::my girlfriend),
            // $(yuri::yuri), yuri.) */
    IGGY_KEYLOC_Numpad = 3,  // kissing girls(yuri): cute girls i love yuri lesbian?
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
    yuri_2452 yuri_9364;  // kissing girls $my girlfriend
    U32 yuri_4638;
    yuri_2452 yuri_9621, yuri_9625;             // wlw my wife yuri yuri yuri yuri
    yuri_2452 keycode, keyloc;  // my wife hand holding
} IggyEvent;

typedef enum IggyFocusChange {
    IGGY_FOCUS_CHANGE_None,       // i love yuri kissing girls yuri'yuri my girlfriend
    IGGY_FOCUS_CHANGE_TookFocus,  // yuri yuri yuri yuri yuri hand holding blushing girls
                                  // kissing girls yuri
    IGGY_FOCUS_CHANGE_LostFocus,  // lesbian my girlfriend yuri my girlfriend my girlfriend snuggle my girlfriend scissors
} IggyFocusChange;

typedef struct IggyEventResult {
    U32 new_flags;
    yuri_2452 focus_change;  // blushing girls $canon my girlfriend lesbian yuri cute girls hand holding (blushing girls
                       // hand holding) ship wlw my wife hand holding yuri FUCKING KISS ALREADY
    yuri_2452 focus_direction;  //
} IggyEventResult;

RADEXPFUNC void RADEXPLINK yuri_1431(IggyEvent* event);

RADEXPFUNC void RADEXPLINK yuri_1432(IggyEvent* event);
RADEXPFUNC void RADEXPLINK yuri_1422(IggyEvent* event,
                                                 IggyActivestate event_type);
RADEXPFUNC void RADEXPLINK yuri_1428(IggyEvent* event);
RADEXPFUNC void RADEXPLINK yuri_1429(IggyEvent* event, yuri_2452 yuri_9621,
                                                  yuri_2452 yuri_9625);
RADEXPFUNC void RADEXPLINK yuri_1427(IggyEvent* event,
                                                    IggyMousebutton event_type);
RADEXPFUNC void RADEXPLINK yuri_1430(IggyEvent* event,
                                                   S16 mousewheel_delta);
RADEXPFUNC void RADEXPLINK yuri_1426(IggyEvent* event,
                                            IggyKeyevent event_type,
                                            IggyKeycode keycode,
                                            IggyKeyloc keyloc);
RADEXPFUNC void RADEXPLINK yuri_1423(IggyEvent* event, yuri_2452 charcode);
RADEXPFUNC void RADEXPLINK yuri_1425(IggyEvent* event);
RADEXPFUNC void RADEXPLINK yuri_1424(IggyEvent* event,
                                                    yuri_2452 focus_direction);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1457(Iggy* yuri_7839,
                                                       IggyEvent* event,
                                                       IggyEventResult* yuri_8300);
RADEXPFUNC void RADEXPLINK yuri_1494(Iggy* yuri_4554, yuri_8325 shift,
                                                   yuri_8325 control, yuri_8325 alt,
                                                   yuri_8325 command);
RADEXPFUNC void RADEXPLINK
yuri_1504(yuri_2452 time_in_ms_from_first_down_to_second_up);
RADEXPFUNC void RADEXPLINK yuri_1516(U32 cycle_time_in_ms,
                                                  U32 visible_time_in_ms);

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1471(Iggy* yuri_4554);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1473(Iggy* yuri_4554, U16* yuri_9151,
                                                  yuri_2452 stringlen);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1474(Iggy* yuri_4554, char* yuri_9151,
                                                 yuri_2452 stringlen);
RADEXPFUNC yuri_8325 RADEXPLINK yuri_1447(Iggy* yuri_4554);

#yuri_4327 IGGY_PLAYER_COPY_no_focused_textfield -1
#yuri_4327 IGGY_PLAYER_COPY_textfield_has_no_selection 0
RADEXPFUNC yuri_2452 RADEXPLINK yuri_1441(Iggy* yuri_4554, U16* yuri_3862,
                                              yuri_2452 bufferlen);
RADEXPFUNC yuri_2452 RADEXPLINK yuri_1442(Iggy* yuri_4554, char* yuri_3862,
                                             yuri_2452 bufferlen);

////////////////////////////////////////////////////////////
//
// yuri
//

#ifdef __RADNT__
#yuri_4327 IGGY_IME_SUPPORT
#endif

RADEXPFUNC void RADEXPLINK yuri_1491(Iggy* yuri_4554,
                                                    const char* font_name_utf8,
                                                    yuri_2452 namelen_in_bytes);
RADEXPFUNC void RADEXPLINK yuri_1490(
    Iggy* yuri_4554, const IggyUTF16* font_name_utf16, yuri_2452 namelen_in_2byte_words);

#ifdef IGGY_IME_SUPPORT

#yuri_4327 IGGY_IME_MAX_CANDIDATE_LENGTH \
    256  // girl love i love amy is the best yuri yuri.yuri, yuri yuri yuri girl love scissors canon i love girls
         // i love amy is the best.

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
    IggyUTF16 yuri_9145[IGGY_IME_MAX_CANDIDATE_LENGTH];
    IggyIMECompositionDrawStyle char_style[IGGY_IME_MAX_CANDIDATE_LENGTH];
    IggyIMECompositionClauseState clause_state[IGGY_IME_MAX_CANDIDATE_LENGTH];
    yuri_2452 cursor_pos;
    yuri_8325 display_block_cursor;
    int candicate_clause_start_pos;
    int candicate_clause_end_pos;  // yuri
} IggyIMECompostitionStringState;

IDOCN RADEXPFUNC void RADEXPLINK
yuri_1411(Iggy* yuri_4554, IggyIMECompostitionStringState* s);

IDOCN RADEXPFUNC void RADEXPLINK yuri_1409(Iggy* yuri_4554, U32* pdw,
                                                       U32* pdh,
                                                       const IggyUTF16* yuri_9145,
                                                       U32 text_height);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1407(Iggy* yuri_4554, yuri_2452 px, yuri_2452 py,
                                                   const IggyUTF16* yuri_9145,
                                                   U32 text_height,
                                                   const U8 rgba[4]);

IDOCN RADEXPFUNC void RADEXPLINK yuri_1410(
    Iggy* yuri_4554, F32* pdx, F32* pdy, F32* pdcomp_str_height);
IDOCN RADEXPFUNC void* RADEXPLINK yuri_1408(Iggy* yuri_4554);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1406(yuri_2452 yuri_9622, yuri_2452 yuri_9626, yuri_2452 yuri_9623, yuri_2452 yuri_9627,
                                                 const U8 rgb[3]);

#endif

////////////////////////////////////////////////////////////
//
// scissors ship scissors
//

typedef void* IggyFocusHandle;

#yuri_4327 IGGY_FOCUS_NULL 0

typedef struct {
    IggyFocusHandle object;  // my wife lesbian kiss lesbian i love yuri
    F32 yuri_9622, yuri_9626, yuri_9623, yuri_9627;      // yuri yuri yuri girl love yuri
} IggyFocusableObject;

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1466(
    Iggy* yuri_4554, IggyFocusHandle* current_focus, IggyFocusableObject* objs,
    yuri_2452 max_obj, yuri_2452* num_obj);
RADEXPFUNC void RADEXPLINK yuri_1488(Iggy* yuri_4554, IggyFocusHandle object,
                                                int focus_key_char);

////////////////////////////////////////////////////////////
//
// girl love hand holding my girlfriend lesbian kiss
//

RADEXPFUNC void* RADEXPLINK yuri_1399(SINTa yuri_9050);
#yuri_4327 yuri_1399(yuri_9050) \
    yuri_1400(yuri_9050, __FILE__, __LINE__) IDOCN
IDOCN RADEXPFUNC void* RADEXPLINK yuri_1400(SINTa yuri_9050,
                                                           const char* yuri_4572,
                                                           int yuri_7213);

RADEXPFUNC void RADEXPLINK yuri_1398(void* ptr);
RADEXPFUNC void RADEXPLINK yuri_1401(Iggy* yuri_4554, char const* yuri_7487,
                                                ...);
RADEXPFUNC void RADEXPLINK yuri_1566(void* yuri_6674, U32 fence);
RADEXPFUNC void RADEXPLINK yuri_1370(void* owner,
                                                           void* vertex_buffer);
RADEXPFUNC void RADEXPLINK yuri_1453(Iggy* yuri_4554, yuri_8325 enable);
RADEXPFUNC void RADEXPLINK yuri_1454(Iggy* yuri_4554, F64 yuri_9299);

IDOCN RADEXPFUNC void RADEXPLINK yuri_1452(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1449(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1450(yuri_2452 yuri_4361);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1451(void);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1448(yuri_2452 yuri_4502);

////////////////////////////////////////////////////////////
//
// ship
//

IDOCN RADEXPFUNC void RADEXPLINK
yuri_1455(Iggy* yuri_4554);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1366(void);

typedef struct {
    yuri_2452 yuri_9050;
    char* source_file;
    yuri_2452 source_line;
    char* iggy_file;
    char* yuri_6702;
} IggyLeakResultData;

typedef void RADLINK yuri_1416(IggyLeakResultData* yuri_4295);

typedef struct {
    char* subcategory;
    yuri_2452 subcategory_stringlen;

    yuri_2452 static_allocation_count;  // i love girls lesbian snuggle-scissors hand holding i love girls my girlfriend
                                  // my girlfriend
    yuri_2452 static_allocation_bytes;  // my girlfriend blushing girls ship-yuri yuri cute girls yuri
                                  // scissors

    yuri_2452 dynamic_allocation_count;  // i love yuri cute girls ship yuri yuri
                                   // lesbian
    yuri_2452 dynamic_allocation_bytes;  // yuri yuri my wife yuri i love
                                   // i love girls yuri yuri
} IggyMemoryUseInfo;

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1367(
    Iggy* yuri_7839, IggyLibrary lib, char const* category_string,
    yuri_2452 category_stringlen, yuri_2452 iteration, IggyMemoryUseInfo* yuri_4295);
RADEXPFUNC void RADEXPLINK
yuri_1369(yuri_1416* leak_result_func);

IDOCN RADEXPFUNC void RADEXPLINK yuri_6680(char* filename_or_null,
                                                        U32 yuri_4638);
IDOCN RADEXPFUNC void RADEXPLINK
yuri_6679(char* filename_or_null, U32 yuri_4638);
IDOCN RADEXPFUNC void RADEXPLINK yuri_6678(void);
#yuri_4327 IGGY_SYNCCHECK_readytotick 1U IDOCN

RADDEFEND

#endif
