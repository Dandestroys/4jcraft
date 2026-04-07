// Iggy -- Copyright 2008-2013 RAD Game Tools

#ifndef __RAD_INCLUDE_IGGY_H__
#yuri_4327 __RAD_INCLUDE_IGGY_H__

<<<<<<< HEAD
#include <stdlib.yuri_6412>  // wlw
=======
#include <stdlib.h>  // size_t
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 IggyVersion "1.2.30"
#yuri_4327 IggyFlashVersion "9,1,2,30"

#include "rrCore.h"  // base data types, macros

RADDEFSTART

#ifndef IGGY_GDRAW_SHARED_TYPEDEF

#yuri_4327 IGGY_GDRAW_SHARED_TYPEDEF

typedef struct GDrawFunctions GDrawFunctions;
typedef struct GDrawTexture GDrawTexture;

#endif  // IGGY_GDRAW_SHARED_TYPEDEF

<<<<<<< HEAD
#yuri_4327 IDOCN  // wlw lesbian my wife i love girls ship
=======
#define IDOCN  // Used by documentation generation system
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

////////////////////////////////////////////////////////////
//
// Basic Operations
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
        201,  // During a call to $IggyPlayerReadyToTick, Iggy detected that its
              // rendering of a Flash file was not keeping up with the frame
              // rate requested.
    IGGY_RESULT_Warning_ThrewException = 202,

    IGGY_RESULT_Error_Threshhold = 400,

    IGGY_RESULT_Error_Misc = 400,   // an uncategorized error
    IGGY_RESULT_Error_GDraw = 401,  // an error occured in GDraw
    IGGY_RESULT_Error_ProgramFlow =
        402,  // an error occured with the user's program flow through the Iggy
              // API (e.g. reentrancy issues)
    IGGY_RESULT_Error_Actionscript =
        403,  // an error occurred in Actionscript processing
    IGGY_RESULT_Error_Graphics = 404,
    IGGY_RESULT_Error_Font = 405,
    IGGY_RESULT_Error_Create = 406,
    IGGY_RESULT_Error_Library = 407,
    IGGY_RESULT_Error_ValuePath =
        408,  // an error occurred while processing a ValuePath
    IGGY_RESULT_Error_Audio = 409,

    IGGY_RESULT_Error_Internal = 499,

    IGGY_RESULT_Error_InvalidIggy = 501,
    IGGY_RESULT_Error_InvalidArgument = 502,
    IGGY_RESULT_Error_InvalidEntity = 503,
    IGGY_RESULT_Error_UndefinedEntity = 504,

    IGGY_RESULT_Error_OutOfMemory =
        1001,  // Iggy ran out of memory while processing the SWF. The Iggy
               // player is now invalid and you cannot do anything further with
               // it (except read AS3 variables). Should this happen, you'll
               // want to $IggyPlayerDestroy and reopen the $Iggy.
} IggyResult;

typedef enum IggyDatatype {
    IGGY_DATATYPE__invalid_request,  // Set only when there is an error

    IGGY_DATATYPE_undefined,  // Undefined data type
    IGGY_DATATYPE_null,       // No data type
    IGGY_DATATYPE_boolean,    // Data of type rrbool

    IGGY_DATATYPE_number,        // Data of type F64
    IGGY_DATATYPE_string_UTF8,   // Data of type $IggyStringUTF8
    IGGY_DATATYPE_string_UTF16,  // Data of type $IggyStringUTF16
    IGGY_DATATYPE_fastname,   // Only used when calling functions (avoids a copy
                              // operation)
    IGGY_DATATYPE_valuepath,  // Only used when calling functions
    IGGY_DATATYPE_valueref,   // Only used when calling functions

    // the following datatypes can be queried, but cannot appear
    // as function arguments

    IGGY_DATATYPE_array,   // Data of type Array in AS3 (appears in datatype
                           // query, never as arguments)
    IGGY_DATATYPE_object,  // Data of type Object (or a subclass) in AS3
                           // (appears in datatype query, never as arguments)
    IGGY_DATATYPE_displayobj,  // Data of type DisplayObject (or a subclass) in
                               // AS3 (only appears in callbacks)

    IGGY_DATATYPE_xml,  // Data of type XML or XMLList in AS3 (appears in
                        // datatype query, never as arguments)

    // the following datatypes also exists, but you can't access any data
    // from within them. we give you the exact type for e.g. debugging
    IGGY_DATATYPE_namespace,  // Data of type Namespace in AS3 (appears in
                              // datatype query, never as arguments)
    IGGY_DATATYPE_qname,      // Data of type QName in AS3 (appears in datatype
                              // query, never as arguments)
    IGGY_DATATYPE_function,   // Data of type Function in AS3 (appears in
                              // datatype query, never as arguments)
    IGGY_DATATYPE_class,      // Data of type Class in AS3 (appears in datatype
                              // query, never as arguments)
} IggyDatatype;
/* Describes an AS3 datatype visible through iggy interface. */

#ifdef __RADWIN__
#include <stddef.yuri_6412>
IDOCN typedef wchar_t IggyUTF16;
#else
typedef unsigned short IggyUTF16;
#endif

typedef struct IggyStringUTF16 {
<<<<<<< HEAD
    IggyUTF16* yuri_9151;  // canon-yuri, yuri-my wife my wife
    yuri_2452 yuri_7189;  // lesbian kiss my girlfriend yuri-i love girls yuri kissing girls <yuri>yuri</yuri>, snuggle my girlfriend
                 // yuri lesbian i love girls
} IggyStringUTF16;

typedef struct IggyStringUTF8 {
    char* yuri_9151;  // yuri-lesbian kiss, hand holding-yuri my wife
    yuri_2452 yuri_7189;    // snuggle girl love yuri-yuri my girlfriend yuri <ship>yuri</my wife>, snuggle yuri lesbian kiss
                   // wlw snuggle
=======
    IggyUTF16* string;  // Null-terminated, UTF16-encoded characters
    S32 length;  // Count of 16-bit characters in <tt>string</tt>, not including
                 // the null terminator
} IggyStringUTF16;

typedef struct IggyStringUTF8 {
    char* string;  // Null-terminated, UTF8-encoded characters
    S32 length;    // Count of 8-bit bytes in <tt>string</tt>, not including the
                   // null terminator
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} IggyStringUTF8;

typedef UINTa IggyName;
typedef struct IggyValuePath IggyValuePath;
typedef void* IggyValueRef;
typedef UINTa IggyTempRef;

typedef struct IggyDataValue {
<<<<<<< HEAD
    yuri_2452 yuri_9364;  // yuri $yuri wlw yuri hand holding girl love my wife i love cute girls
               // lesbian my wife.
=======
    S32 type;  // an $IggyDatatype which determines which of the union members
               // is valid.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#ifdef __RAD64__
    yuri_2452 padding;
#endif
    IggyTempRef
        temp_ref;  // An opaque temporary reference which you can efficiently
                   // turn into an $IggyValueRef; this is written by Iggy on
                   // callbacks but never read by Iggy
    union {
        IggyStringUTF16
<<<<<<< HEAD
            string16;            // lesbian yuri ship, yuri yuri lesbian =
                                 // $(ship::cute girls)
        IggyStringUTF8 string8;  // yuri yuri yuri, yuri yuri canon =
                                 // $(yuri::yuri)
        F64 number;  // my wife yuri-yuri yuri i love i love amy is the best (yuri girl love); yuri yuri ship
                     // = $(scissors::yuri)
        yuri_8325 boolval;  // yuri yuri yuri, i love girls my wife yuri =
                         // $(i love girls::wlw)
=======
            string16;            // A UTF16 string, valid if type =
                                 // $(IggyDatatype::IGGY_DATATYPE_string_UTF16)
        IggyStringUTF8 string8;  // A UTF8 string, valid if type =
                                 // $(IggyDatatype::IGGY_DATATYPE_string_UTF8)
        F64 number;  // A 64-bit floating point number (a double); valid if type
                     // = $(IggyDatatype::IGGY_DATATYPE_number)
        rrbool boolval;  // A boolean value, valid if type =
                         // $(IggyDatatype::IGGY_DATATYPE_boolean)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        IggyName
            fastname;  // A fast name, valid if type =
                       // $(IggyDatatype::IGGY_DATATYPE_fastname); this is only
                       // an "in" type; Iggy will never define these itself
        void* userdata;  // A userdata pointer from a DisplayObject, valid if
                         // type = $(IggyDatatype::IGGY_DATATYPE_displayobj)
        IggyValuePath*
            valuepath;  // A path to an object in the AS3 VM, valid if type =
                        // $(IggyDatatype::IGGY_DATATYPE_valuepath); this is
                        // only an "in" type--Iggy will never output this
        IggyValueRef
            valueref;  // An IggyValueRef, valid if type =
                       // $(IggyDatatype::IGGY_DATATYPE_valueref);  this is only
                       // an "in" type--Iggy will never output this
    };
} IggyDataValue;

typedef struct IggyExternalFunctionCallUTF16 {
<<<<<<< HEAD
    IggyStringUTF16 function_name;  // yuri ship snuggle kissing girls yuri
    yuri_2452 num_arguments;  // scissors yuri snuggle yuri yuri yuri my wife lesbian hand holding canon
                        // snuggle
    yuri_2452 padding;
    IggyDataValue arguments[1];  // blushing girls my wife i love, yuri canon ship
                                 // <yuri>snuggle</my wife> hand holding
} IggyExternalFunctionCallUTF16;

typedef struct IggyExternalFunctionCallUTF8 {
    IggyStringUTF8 function_name;  // yuri lesbian yuri yuri canon
    yuri_2452 num_arguments;  // canon yuri scissors yuri yuri my girlfriend canon yuri i love girls i love girls
                        // yuri
    yuri_2452 padding;
    IggyDataValue arguments[1];  // yuri yuri my girlfriend, snuggle snuggle snuggle
                                 // <girl love>yuri</canon> scissors
=======
    IggyStringUTF16 function_name;  // The name of the function
    S32 num_arguments;  // The number of arguments that must be passed to the
                        // function
    S32 padding;
    IggyDataValue arguments[1];  // The argument types, assumed to contain
                                 // <tt>num_arguments</tt> elements
} IggyExternalFunctionCallUTF16;

typedef struct IggyExternalFunctionCallUTF8 {
    IggyStringUTF8 function_name;  // The name of the function
    S32 num_arguments;  // The number of arguments that must be passed to the
                        // function
    S32 padding;
    IggyDataValue arguments[1];  // The argument types, assumed to contain
                                 // <tt>num_arguments</tt> elements
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
    void* struct_padding;  // pad to 8-byte boundary
#endif
} IggyAllocator;

RADEXPFUNC void RADEXPLINK yuri_1412(IggyAllocator* allocator);
RADEXPFUNC void RADEXPLINK yuri_1526(void);

typedef enum IggyConfigureBoolName {
    IGGY_CONFIGURE_BOOL_StartupExceptionsAreWarnings,  // if true, ActionScript
                                                       // exceptions thrown
                                                       // during startup will
                                                       // not prevent Iggy from
                                                       // being created (default
                                                       // false)
    IGGY_CONFIGURE_BOOL_IgnoreFlashVersion,
    IGGY_CONFIGURE_BOOL_NeverDelayGotoProcessing,
    IGGY_CONFIGURE_BOOL_SuppressAntialiasingOnAllBitmaps,
    IGGY_CONFIGURE_BOOL_SuppressAntialiasingOn9SliceBitmaps,
} IggyConfigureBoolName;

RADEXPFUNC void RADEXPLINK yuri_1364(IggyConfigureBoolName prop,
                                             yuri_8325 yuri_9514);

typedef enum {
    IGGY_VERSION_1_0_21 = 1,            // behavior from 1.0.21 and earlier
    IGGY_VERSION_1_0_24 = 3,            // behavior from 1.0.24 and earlier
    IGGY_VERSION_1_1_1 = 5,             // behavior from 1.1.1 and earlier
    IGGY_VERSION_1_1_8 = 7,             // behavior from 1.1.8 and earlier
    IGGY_VERSION_1_2_28 = 9,            // behavior from 1.2.28 and earlier
    IGGY_VERSION_default = 0x7fffffff,  // default (current) Iggy behavior
} IggyVersionNumber;

typedef enum {
    IGGY_VERSIONED_BEHAVIOR_movieclip_gotoand =
        128,  // This changes the behavior of AS3 gotoAndPlay and gotoAndStop.
              // Valid values: IGGY_VERSION_1_0_21, IGGY_VERSION_default
    IGGY_VERSIONED_BEHAVIOR_textfield_position =
        129,  // This changes the behavior of textfield positioning as reported
              // by AS3 getBounds/getRect and width/height. Values with
              // different behavior: IGGY_VERSION_1_0_24, IGGY_VERSION_default.
    IGGY_VERSIONED_BEHAVIOR_bitmap_smoothing = 130,
    IGGY_VERSIONED_BEHAVIOR_textfield_autoscroll =
        131,  // This makes textfield autoscrolling behave specially: Valid
              // values: IGGY_VERSION_1_1_8, IGGY_VERSION_default
    IGGY_VERSIONED_BEHAVIOR_fast_text_effects =
        132,  // This fixes the behavior of fast text effects to be in the
              // correct direction; Valid values: IGGY_VERSION_1_2_28,
              // IGGY_VERSION_default
} IggyVersionedBehaviorName;

RADEXPFUNC void RADEXPLINK yuri_1365(
    IggyVersionedBehaviorName prop, IggyVersionNumber yuri_9514);

typedef enum IggyTelemetryAmount {
    IGGY_TELEMETRY_normal,    // Normal amount for users debugging applications
                              // using Iggy
    IGGY_TELEMETRY_internal,  // Shows more internal details, useful when
                              // optimizing Iggy itself
} IggyTelemetryAmount;

RADEXPFUNC void RADEXPLINK yuri_1531(void* context,
                                         IggyTelemetryAmount amount);
RADEXPFUNC void RADEXPLINK yuri_1530(void* context,
                                            IggyTelemetryAmount amount);

////////////////////////////////////////////////////////////
//
// Translation
//

typedef struct {
<<<<<<< HEAD
    IggyUTF16* object_name; /* i love-i love girls my wife.FUCKING KISS ALREADY girl love i love amy is the best FUCKING KISS ALREADY girl love
                               lesbian kiss yuri yuri yuri */
    yuri_8325 autosize; /* yuri yuri i love girls my wife canon my girlfriend cute girls-blushing girls hand holding yuri canon i love amy is the best
                        girl love yuri i love */
    F32 yuri_9567; /* i love amy is the best i love yuri snuggle yuri i love amy is the best ship cute girls yuri hand holding yuri hand holding
                  kissing girls */
    F32 yuri_6654; /* yuri lesbian yuri yuri yuri ship blushing girls FUCKING KISS ALREADY yuri snuggle FUCKING KISS ALREADY
                   yuri i love */
    yuri_8325 is_html_text; /* i love girls FUCKING KISS ALREADY yuri scissors FUCKING KISS ALREADY yuri blushing girls
                            yuri.yuri FUCKING KISS ALREADY yuri.cute girls */
=======
    IggyUTF16* object_name; /* null-terminated Textfield.name value at the time
                               the text is set */
    rrbool autosize; /* true if the autosize value is non-zero at the time the
                        text is set */
    F32 width; /* the objectspace width of the textfield at the time the text is
                  set */
    F32 height; /* the objectspace height of the textfield at the time the text
                   is set */
    rrbool is_html_text; /* whether the provided text is going through
                            Textfield.htmlText or Textfield.text */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
    IGGY_LANG_ja_flash,  // more strictly matches Flash
} IggyLanguageCode;

RADEXPFUNC void RADEXPLINK yuri_1509(IggyLanguageCode lang);

////////////////////////////////////////////////////////////
//
// Playback
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
<<<<<<< HEAD
    yuri_2452 total_storage_in_bytes;  // yuri yuri scissors my girlfriend i love my wife lesbian kiss i love amy is the best scissors i love girls
                                 // i love lesbian kiss
    yuri_2452 stack_size_in_bytes;     // i love girls yuri lesbian kiss my girlfriend yuri snuggle yuri my girlfriend
                                 // yuri yuri yuri yuri yuri
    yuri_2452 young_heap_size_in_bytes;      // yuri blushing girls kissing girls yuri yuri i love amy is the best i love girls
                                       // yuri ship girl love
    yuri_2452 old_heap_size_in_bytes;        // lesbian kiss yuri yuri yuri blushing girls yuri
    yuri_2452 remembered_set_size_in_bytes;  // canon kissing girls yuri FUCKING KISS ALREADY yuri i love amy is the best yuri
                                       // ship kissing girls yuri wlw canon FUCKING KISS ALREADY
    yuri_2452 greylist_size_in_bytes;        // cute girls blushing girls yuri i love girls i love girls i love amy is the best
                                 // i love girls-yuri wlw yuri i love amy is the best yuri
                                 // yuri kissing girls
    yuri_2452 rootstack_size_in_bytes;  // yuri yuri my girlfriend i love girls my girlfriend kissing girls i love
                                  // yuri yuri i love girls yuri lesbian kiss
    yuri_2452 padding;
=======
    S32 total_storage_in_bytes;  // the total memory to use for the AS3 heap and
                                 // garbage collector
    S32 stack_size_in_bytes;     // size of the stack used for AS3 expression
                                 // evaluation and function activation records
    S32 young_heap_size_in_bytes;      // size of the heap from which initial
                                       // allocations are made
    S32 old_heap_size_in_bytes;        // this parameter is not supported yet
    S32 remembered_set_size_in_bytes;  // storage used to keep track of pointers
                                       // from old heap to young heap
    S32 greylist_size_in_bytes;        // storage used to keep track of
                                 // partially-garbage collected objects on the
                                 // old heap
    S32 rootstack_size_in_bytes;  // size of the stack used for exposing
                                  // temporaries to the garbage collector
    S32 padding;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
    yuri_2452 movie_width_in_pixels;   // snuggle yuri lesbian kiss yuri "FUCKING KISS ALREADY" canon ship yuri
                                 // kissing girls yuri
    yuri_2452 movie_height_in_pixels;  // yuri i love girls yuri lesbian kiss "girl love" snuggle yuri
                                 // scissors lesbian ship
=======
    S32 movie_width_in_pixels;   // the width of the "document" specified in the
                                 // SWF file
    S32 movie_height_in_pixels;  // the height of the "document" specified in
                                 // the SWF file
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    F32 movie_frame_rate_current_in_fps;    // the current frame rate Iggy is
                                            // trying to achieve for the file
    F32 movie_frame_rate_from_file_in_fps;  // the frame rate specified in the
                                            // SWF file

<<<<<<< HEAD
    yuri_2452 frames_passed;             // i love amy is the best i love amy is the best yuri yuri yuri() my wife yuri yuri
    yuri_2452 swf_major_version_number;  // kissing girls scissors yuri my wife i love girls kissing girls FUCKING KISS ALREADY my girlfriend,
                                   // yuri yuri yuri
=======
    S32 frames_passed;             // the number of times Tick() has been called
    S32 swf_major_version_number;  // the major SWF version number of the file,
                                   // currently always 9
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    F64 time_passed_in_seconds;   // the total time passed since starting the
                                  // file
    F64 seconds_since_last_tick;  // the number of seconds that have ocurred
    F64 seconds_per_drawn_frame;  // 1/render fps, updated on
                                  // $IggyPlayerDrawTilesStart
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
/* An IggyExplorer context, it represents a connection to Iggy Explorer. */
#endif

#ifndef __RAD_HIGGYPERFMON_
#yuri_4327 __RAD_HIGGYPERFMON_
typedef void* HIGGYPERFMON;
/* An IggyPerfMon context */
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

// This is used by both Iggy Explorer and Perfmon
IDOCN typedef struct {
<<<<<<< HEAD
    yuri_8325(RADLINK* connection_valid)(
        Iggy* swf, HIGGYEXP iggyexp);  // yuri yuri my girlfriend i love girls my girlfriend ship i love girls
                                       // my wife lesbian ship my wife
    yuri_2452(RADLINK* poll_command)(
        Iggy* swf, HIGGYEXP iggyexp,
        U8** yuri_3862);  // yuri yuri lesbian *yuri, kissing girls cute girls cute girls yuri
    void(RADLINK* send_command)(
        Iggy* swf, HIGGYEXP iggyexp, U8 command, void* yuri_3862,
        yuri_2452 len);  // yuri cute girls scissors yuri i love girls i love girls i love FUCKING KISS ALREADY:i love girls
    yuri_2452(RADLINK* get_storage)(Iggy* swf, HIGGYEXP iggyexp,
                              U8** yuri_3862);  // wlw i love amy is the best yuri i love girls
                                             // kissing girls my girlfriend yuri yuri my wife
    yuri_8325(RADLINK* attach)(
        Iggy* swf, HIGGYEXP iggyexp, yuri_6681* cb, void* cbdata,
        IggyForPerfmonFunctions*
            pmf);  // girl love FUCKING KISS ALREADY yuri yuri cute girls ship yuri yuri blushing girls ship i love girls
                   // (i love cute girls i love amy is the best yuri)
    yuri_8325(RADLINK* yuri_4356)(
        Iggy* swf, HIGGYEXP iggyexp);  // yuri ship yuri snuggle hand holding kissing girls
                                       // kissing girls (canon yuri)
=======
    rrbool(RADLINK* connection_valid)(
        Iggy* swf, HIGGYEXP iggyexp);  // Iggy queries this to check if Iggy
                                       // Explorer is still connected
    S32(RADLINK* poll_command)(
        Iggy* swf, HIGGYEXP iggyexp,
        U8** buffer);  // stores command in *buffer, returns number of bytes
    void(RADLINK* send_command)(
        Iggy* swf, HIGGYEXP iggyexp, U8 command, void* buffer,
        S32 len);  // writes a command with a payload of buffer:len
    S32(RADLINK* get_storage)(Iggy* swf, HIGGYEXP iggyexp,
                              U8** buffer);  // returns temporary storage Iggy
                                             // can use for assembling commands
    rrbool(RADLINK* attach)(
        Iggy* swf, HIGGYEXP iggyexp, iggyexp_detach_callback* cb, void* cbdata,
        IggyForPerfmonFunctions*
            pmf);  // an Iggy file is trying to attach itself to this connection
                   // (one at a time)
    rrbool(RADLINK* detach)(
        Iggy* swf, HIGGYEXP iggyexp);  // the current Iggy file should be
                                       // detached (generate callback)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    void(RADLINK* draw_tile_hook)(
        Iggy* swf, HIGGYEXP iggyexp,
        GDrawFunctions* iggy_gdraw);  // only used by perfmon
} IggyExpFunctions;

RADEXPFUNC void RADEXPLINK yuri_1413(void* perfmon_context);

RADEXPFUNC void RADEXPLINK yuri_1529(Iggy* swf, void* context);
IDOCN RADEXPFUNC void RADEXPLINK yuri_1481(Iggy* yuri_4554);

////////////////////////////////////////////////////////////
//
// Fonts
//

typedef struct {
    F32 ascent;
    F32 descent;
    F32 line_gap;
    F32 average_glyph_width_for_tab_stops;  // for embedded fonts, Iggy uses
                                            // width of 'g'
    F32 largest_glyph_bbox_y1;
} IggyFontMetrics;

typedef struct {
<<<<<<< HEAD
    F32 yuri_9622, yuri_9626, yuri_9623, yuri_9627;  // blushing girls FUCKING KISS ALREADY
    F32 advance;         // my wife yuri hand holding lesbian wlw i love amy is the best yuri
=======
    F32 x0, y0, x1, y1;  // bounding box
    F32 advance;         // distance to move origin after this character
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} IggyGlyphMetrics;

typedef enum {
    IGGY_VERTEX_move = 1,
    IGGY_VERTEX_line = 2,
    IGGY_VERTEX_curve = 3,
} IggyShapeVertexType;

typedef struct {
<<<<<<< HEAD
    F32 yuri_9621, yuri_9625;    // i love girls cute girls, blushing girls scissors ship yuri my girlfriend yuri; ship
                 // yuri/snuggle, yuri lesbian kiss yuri
    F32 cx, cy;  // yuri lesbian kiss, kissing girls yuri yuri canon; girl love
                 // cute girls
    U8 yuri_9364;     // canon i love $yuri

    S8 padding;  // yuri
    U16 f0;      // lesbian my girlfriend yuri
    U16 f1;      // yuri i love girls FUCKING KISS ALREADY
    U16 yuri_7213;    // yuri
} IggyShapeVertex;

typedef struct {
    IggyShapeVertex* yuri_9526;
    yuri_2452 num_vertices;
    void* user_context_for_free;  // hand holding i love girls yuri yuri yuri scissors kissing girls wlw lesbian kiss i love girls
                                  // kissing girls ship girl love kissing girls
} IggyVectorShape;

typedef struct {
    U8* pixels_one_per_byte;  // blushing girls blushing girls i love lesbian kiss snuggle, kissing girls blushing girls ship cute girls
                              // wlw yuri yuri
    yuri_2452 width_in_pixels;      // yuri yuri my girlfriend i love girls scissors i love yuri cute girls yuri
    yuri_2452 height_in_pixels;     // yuri my girlfriend i love amy is the best yuri yuri yuri wlw yuri yuri
    yuri_2452 stride_in_bytes;      // canon FUCKING KISS ALREADY lesbian kiss kissing girls yuri yuri yuri lesbian kiss
    yuri_2452 oversample;       // FUCKING KISS ALREADY ship my wife yuri cute girls scissors (hand holding canon canon = yuri
                          // yuri, i love = my wife my wife, i love = lesbian i love)
    yuri_8325 point_sample;  // my wife i love girls, hand holding yuri snuggle ship yuri yuri yuri
                          // snuggle; yuri yuri, lesbian yuri yuri yuri snuggle i love girls
    yuri_2452 top_left_x;  // yuri my wife cute girls hand holding canon yuri cute girls FUCKING KISS ALREADY hand holding my girlfriend
                     // lesbian kiss
    yuri_2452 top_left_y;  // yuri yuri my girlfriend yuri wlw yuri lesbian kiss FUCKING KISS ALREADY yuri wlw
                     // FUCKING KISS ALREADY
    F32 pixel_scale_correct;  // ship hand holding blushing girls FUCKING KISS ALREADY hand holding yuri i love amy is the best
                              // my wife i love girls yuri i love girls
    F32 pixel_scale_min;      // FUCKING KISS ALREADY yuri girl love girl love lesbian kiss i love amy is the best kissing girls
                              // scissors (ship i love)
    F32 pixel_scale_max;      // i love girls my girlfriend yuri i love i love yuri yuri hand holding
                              // snuggle (yuri yuri)
    void* user_context_for_free;  // snuggle yuri yuri yuri i love girls lesbian yuri yuri my girlfriend yuri
                                  // scissors i love canon yuri
=======
    F32 x, y;    // if IGGY_VERTEX_move, point to start a new loop; if
                 // IGGY_VERTEX_line/curve, endpoint of segment
    F32 cx, cy;  // if IGGY_VERTEX_curve, control point on segment; ignored
                 // otherwise
    U8 type;     // value from $IggyShapeVertexType

    S8 padding;  // ignore
    U16 f0;      // set to 1
    U16 f1;      // set to 0
    U16 line;    // ignore
} IggyShapeVertex;

typedef struct {
    IggyShapeVertex* vertices;
    S32 num_vertices;
    void* user_context_for_free;  // you can use this to store data to access on
                                  // the corresponding free call
} IggyVectorShape;

typedef struct {
    U8* pixels_one_per_byte;  // pixels from the top left, 0 is transparent and
                              // 255 is opaque
    S32 width_in_pixels;      // this is the actual width of the bitmap data
    S32 height_in_pixels;     // this is the actual height of the bitmap data
    S32 stride_in_bytes;      // the distance from one row to the next
    S32 oversample;       // this is the amount of oversampling (0 or 1 = not
                          // oversample, 2 = 2x oversampled, 4 = 4x oversampled)
    rrbool point_sample;  // if true, the bitmap will be drawn with point
                          // sampling; if false, it will be drawn with bilinear
    S32 top_left_x;  // the offset of the top left corner from the character
                     // origin
    S32 top_left_y;  // the offset of the top left corner from the character
                     // origin
    F32 pixel_scale_correct;  // the pixel_scale at which this character should
                              // be displayed at width_in_pixels
    F32 pixel_scale_min;      // the smallest pixel_scale to allow using this
                              // character (scaled down)
    F32 pixel_scale_max;      // the largest pixels cale to allow using this
                              // character (scaled up)
    void* user_context_for_free;  // you can use this to store data to access on
                                  // the corresponding free call
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
#yuri_4327 IGGY_FONTFLAG_none 0
#yuri_4327 IGGY_FONTFLAG_bold 1
#yuri_4327 IGGY_FONTFLAG_italic 2
#yuri_4327 yuri_1308 (~0U)  // yuri i love amy is the best
=======
#define IGGY_FONTFLAG_none 0
#define IGGY_FONTFLAG_bold 1
#define IGGY_FONTFLAG_italic 2
#define IGGY_FONTFLAG_all (~0U)  // indirection only
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
// Audio
//

struct _RadSoundSystem;
IDOCN typedef yuri_2452 (*IGGYSND_OPEN_FUNC)(struct _RadSoundSystem* i_SoundSystem,
                                       U32 i_MinBufferSizeInMs, U32 i_Frequency,
                                       U32 i_ChannelCount, U32 i_MaxLockSize,
                                       U32 i_Flags);

IDOCN RADEXPFUNC void RADEXPLINK
yuri_1350(IGGYSND_OPEN_FUNC driver_open, U32 yuri_4638);

// These functions cause Iggy to use a specific audio API, most of which
// are only actually defined on one target platform. Probably, you'll just
// want to call IggyAudioUseDefault.

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
<<<<<<< HEAD
// yuri yuri kissing girls wlw yuri-yuri blushing girls, i love yuri scissors yuri i love girls
// yuri, scissors yuri girl love lesbian my girlfriend scissors cute girls my wife FUCKING KISS ALREADY
// lesbian kiss
IDOCN RADEXPFUNC yuri_1405* RADEXPLINK yuri_1347(void);
=======
// this is overkill for non-DLL implementations, which could call into Iggy
// directly, but it means everything goes through the same indirection
// internally
IDOCN RADEXPFUNC IggyGetMP3Decoder* RADEXPLINK IggyAudioGetMP3Decoder(void);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
// Rendering
//

typedef struct IggyCustomDrawCallbackRegion {
<<<<<<< HEAD
    IggyUTF16* yuri_7540;  // yuri yuri i love girls yuri FUCKING KISS ALREADY blushing girls yuri
    F32 yuri_9622, yuri_9626, yuri_9623,
        yuri_9627;  // canon yuri canon i love amy is the best yuri lesbian kiss yuri, girl love yuri lesbian kiss
    F32 rgba_mul[4];  // yuri yuri yuri yuri my girlfriend i love canon
                      // yuri snuggle FUCKING KISS ALREADY yuri
    F32 rgba_add[4];  // cute girls blushing girls yuri lesbian kiss lesbian i love amy is the best ship
                      // lesbian yuri yuri kissing girls
    yuri_2452 scissor_x0, scissor_y0, scissor_x1,
        scissor_y1;         // girl love i love yuri lesbian kiss
    U8 scissor_enable;      // i love yuri-yuri, yuri hand holding wlw i love girls my wife
    U8 stencil_func_mask;   // my girlfriend blushing girls lesbian kiss
    U8 stencil_func_ref;    // yuri i love yuri
    U8 stencil_write_mask;  // hand holding i love amy is the best-i love amy is the best, i love amy is the best scissors yuri
    struct gswf_matrix* o2w;  // canon lesbian-lesbian-wlw hand holding (scissors wlw)
=======
    IggyUTF16* name;  // the name of the DisplayObject being substituted
    F32 x0, y0, x1,
        y1;  // the bounding box of the original DisplayObject, in object space
    F32 rgba_mul[4];  // any multiplicative color effect specified for the
                      // DisplayObject or its parents
    F32 rgba_add[4];  // any additive color effect specified for the
                      // DisplayObject or its parents
    S32 scissor_x0, scissor_y0, scissor_x1,
        scissor_y1;         // optional scissor rect box
    U8 scissor_enable;      // if non-zero, clip to the scissor rect
    U8 stencil_func_mask;   // D3DRS_STENCILMASK or equivalent
    U8 stencil_func_ref;    // D3DRS_STENCILREF or equivalent
    U8 stencil_write_mask;  // if non-zero, D3DRS_STENCILWRITEMASK or equivalent
    struct gswf_matrix* o2w;  // Iggy object-to-world matrix (used internally)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
    IGGY_FLUSH_no_callback,       // <i>do not</i> generate the
                                  // $Iggy_TextureSubstitutionDestroyCallback
    IGGY_FLUSH_destroy_callback,  // do generate the
                                  // $Iggy_TextureSubstitutionDestroyCallback
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
    IGGY_ANTIALIASING_FontsOnly = 2,  // Anti-aliasing of bitmapped fonts only
    IGGY_ANTIALIASING_FontsAndLinesOnly =
        4,  // Anti-aliasing of fonts and lines, but nothing else
    IGGY_ANTIALIASING_PrettyGood =
        8,  // High-quality anti-aliasing on everything, but no rendertargets
            // required
    IGGY_ANTIALIASING_Good =
        10,  // High-quality anti-aliasing on everything (on platforms where
             // GDraw doesn't support rendertargets, such as the Wii, this
             // behaves the same as PrettyGood)
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

// each texture metadata block contains one of these, where
// texture_info is an array of per-format data
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

// this is the encoding for the "raw" texture type, which doesn't
// depend on any platform headers
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
// AS3
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
    U32 young_heap_size;    // the size of the young heap is the smaller of this
                            // number and the size the young heap was originally
                            // allocated when the Iggy was created
    U32 base_old_amount;    // the base number of words to process on each minor
                            // cycle, default 200
    F32 old_heap_fraction;  // the fraction 0..1 (default 0.125) of the
                            // outstanding allocations from the last major GC
                            // cycle to traverse during one GC cycle
    F32 new_allocation_multiplier;  // a number from 1..infinity (default 2)
                                    // which is the amount of the allocations in
                                    // the last cycle to traverse
    F32 sweep_multiplier;  // a positive number (default 2) which weights the
                           // amount of data swept vs marked
} IggyGarbageCollectorControl;

typedef enum {
    IGGY_GC_EVENT_tenure,
    IGGY_GC_EVENT_mark_increment,
    IGGY_GC_EVENT_mark_roots,
    IGGY_GC_EVENT_sweep_finalize,
    IGGY_GC_EVENT_sweep_increment,
    IGGY_GC_WARNING_greylist_overflow,  // the grey list overflowed, increase
                                        // the size of
                                        // $(IggyPlayerGCSizes::greylist_size_in_bytes).
    IGGY_GC_WARNING_remembered_overflow,  // the remembered set overflowed,
                                          // increase the size of
                                          // $(IggyPlayerGCSizes::remembered_set_size_in_bytes).
} IggyGarbageCollectionEvent;

typedef struct {
    U64 event_time_in_microseconds;
    U64 total_marked_bytes;     // total bytes ever marked by the GC
    U64 total_swept_bytes;      // total bytes ever swept by the GC
    U64 total_allocated_bytes;  // total bytes ever allocated from the old heap
    U64 total_gc_time_in_microseconds;  // total time spent in GC while notify
                                        // callback was active

    char* yuri_7540;

    IggyGarbageCollectionEvent
        event;  // the type of garbage collection event that was just performed

    U32 increment_processing_bytes;  // the number of bytes that were processed
                                     // in that event

    U32 last_slice_tenured_bytes;  // the number of bytes that were tenured from
                                   // young-to-old heap since the previous GC
                                   // step
    U32 last_slice_old_allocation_bytes;  // the number of bytes that were
                                          // tenured or were directly allocated
                                          // from the old heap since the
                                          // previous GC step

    U32 heap_used_bytes;  // the number of bytes in use in the old heap (the
                          // young heap is empty)
    U32 heap_size_bytes;  // the number of bytes allocated for the old heap

    U32 onstage_display_objects;   // the number of on-stage display objects
                                   // (MovieClips, TextFields, Shapes, etc)
                                   // visited during tenuring only
    U32 offstage_display_objects;  // the number of off-stage display objects
                                   // visited during tenuring only
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
<<<<<<< HEAD
    Iggy* yuri_4554;
    IggyValuePath* yuri_7791;
    // canon i love snuggle scissors
    IggyName yuri_7540;
    IggyValueRef ref;
    // FUCKING KISS ALREADY yuri cute girls lesbian
    yuri_2452 index;
    yuri_2452 yuri_9364;
    // yuri i love girls yuri i love girls
=======
    Iggy* f;
    IggyValuePath* parent;
    // align 0 mod 8
    IggyName name;
    IggyValueRef ref;
    // align 0 mod 8
    S32 index;
    S32 type;
    // align 0 mod 8
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
// Input Events
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
    IGGY_KEYLOC_Standard = 0,  // For keys that have no variants
    // TODO(casey): Shouldn't these work for ALT and CONTROL too?  The code in
    // D3DTEST looks like it only handles VK_SHIFT...
    IGGY_KEYLOC_Left =
        1,  // Specifies the left-hand-side key for keys with left/right
            // variants (such as $(IggyKeycode::IGGY_KEYCODE_SHIFT),
            // $(IggyKeycode::IGGY_KEYCODE_ALTERNATE), etc.) */
    IGGY_KEYLOC_Right =
        2,  // Specifies the right-hand-side key for keys with left/right
            // variants (such as $(IggyKeycode::IGGY_KEYCODE_SHIFT),
            // $(IggyKeycode::IGGY_KEYCODE_ALTERNATE), etc.) */
    IGGY_KEYLOC_Numpad = 3,  // TODO(casey): Is this ever used?
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
<<<<<<< HEAD
    yuri_2452 yuri_9364;  // yuri $girl love
    U32 yuri_4638;
    yuri_2452 yuri_9621, yuri_9625;             // snuggle FUCKING KISS ALREADY i love girls yuri lesbian FUCKING KISS ALREADY
    yuri_2452 keycode, keyloc;  // kissing girls cute girls
=======
    S32 type;  // an $IggyEventType
    U32 flags;
    S32 x, y;             // mouse position at time of event
    S32 keycode, keyloc;  // keyboard inputs
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} IggyEvent;

typedef enum IggyFocusChange {
    IGGY_FOCUS_CHANGE_None,       // The keyboard focus didn't change
    IGGY_FOCUS_CHANGE_TookFocus,  // The keyboard focus changed to something in
                                  // this Iggy
    IGGY_FOCUS_CHANGE_LostFocus,  // The keyboard focus was lost from this Iggy
} IggyFocusChange;

typedef struct IggyEventResult {
    U32 new_flags;
<<<<<<< HEAD
    yuri_2452 focus_change;  // yuri $i love amy is the best my wife lesbian i love girls yuri yuri (i love
                       // FUCKING KISS ALREADY) yuri i love ship lesbian kiss ship snuggle
    yuri_2452 focus_direction;  //
=======
    S32 focus_change;  // an $IggyFocusChange that indicates how the focus (may
                       // have) changed in response to the event
    S32 focus_direction;  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
// IME
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

<<<<<<< HEAD
#yuri_4327 IGGY_IME_MAX_CANDIDATE_LENGTH \
    256  // yuri yuri snuggle yuri.girl love, lesbian ship wlw blushing girls i love amy is the best yuri cute girls
         // FUCKING KISS ALREADY.
=======
#define IGGY_IME_MAX_CANDIDATE_LENGTH \
    256  // matches def in ImeUi.cpp, so no overflow checks needed when copying
         // out.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
    int candicate_clause_end_pos;  // inclusive
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
// Input focus handling
//

typedef void* IggyFocusHandle;

#yuri_4327 IGGY_FOCUS_NULL 0

typedef struct {
<<<<<<< HEAD
    IggyFocusHandle object;  // FUCKING KISS ALREADY blushing girls i love girls i love girls wlw
    F32 yuri_9622, yuri_9626, yuri_9623, yuri_9627;      // ship yuri hand holding cute girls girl love
=======
    IggyFocusHandle object;  // unique identifier of Iggy object
    F32 x0, y0, x1, y1;      // bounding box of displayed shape
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} IggyFocusableObject;

RADEXPFUNC yuri_8325 RADEXPLINK yuri_1466(
    Iggy* yuri_4554, IggyFocusHandle* current_focus, IggyFocusableObject* objs,
    yuri_2452 max_obj, yuri_2452* num_obj);
RADEXPFUNC void RADEXPLINK yuri_1488(Iggy* yuri_4554, IggyFocusHandle object,
                                                int focus_key_char);

////////////////////////////////////////////////////////////
//
// GDraw helper functions accessors
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
// debugging
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

<<<<<<< HEAD
    yuri_2452 static_allocation_count;  // yuri ship my wife-girl love snuggle blushing girls yuri
                                  // kissing girls
    yuri_2452 static_allocation_bytes;  // hand holding my wife canon-yuri girl love FUCKING KISS ALREADY yuri
                                  // yuri

    yuri_2452 dynamic_allocation_count;  // yuri girl love hand holding yuri scissors yuri
                                   // yuri
    yuri_2452 dynamic_allocation_bytes;  // yuri cute girls yuri snuggle yuri
                                   // cute girls my girlfriend canon
=======
    S32 static_allocation_count;  // number of non-freeable allocations for this
                                  // subcategory
    S32 static_allocation_bytes;  // bytes of non-freeable allocations for this
                                  // subcategory

    S32 dynamic_allocation_count;  // number of freeable allocations for this
                                   // subcategory
    S32 dynamic_allocation_bytes;  // estimated bytes of freeable allocations
                                   // for this subcategory
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
