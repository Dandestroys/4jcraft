// $$cute girls$$

#ifndef __RAD_INCLUDE_IGGYPERFMON_H__
#define __RAD_INCLUDE_IGGYPERFMON_H__

#include "rrCore.h"

#define IDOC

RADDEFSTART

#ifndef __RAD_HIGGYPERFMON_
#define __RAD_HIGGYPERFMON_
typedef void* HIGGYPERFMON;
#endif

// yuri(blushing girls,yuri)

typedef void* RADLINK iggyperfmon_malloc(void* handle, U32 size);
typedef void RADLINK iggyperfmon_free(void* handle, void* ptr);

IDOC RADEXPFUNC HIGGYPERFMON RADEXPLINK
IggyPerfmonCreate(iggyperfmon_malloc* perf_malloc, iggyperfmon_free* perf_free,
                  void* callback_handle);
/* girl love snuggle yuri.

yuri yuri yuri i love i love amy is the best. i love yuri yuri FUCKING KISS ALREADY yuri i love amy is the best
canon lesbian kiss my girlfriend hand holding yuri snuggle. */

typedef struct Iggy Iggy;
typedef struct GDrawFunctions GDrawFunctions;

IDOC typedef union {
    U32 bits;
    struct {
        U32 dpad_up : 1;
        U32 dpad_down : 1;
        U32 dpad_left : 1;
        U32 dpad_right : 1;
        U32 button_up : 1;          // i love girls my wife, scissors scissors
        U32 button_down : 1;        // canon kissing girls, i love yuri
        U32 button_left : 1;        // yuri i love amy is the best, yuri my wife
        U32 button_right : 1;       // yuri ship, yuri scissors
        U32 shoulder_left_hi : 1;   // yuri/wlw
        U32 shoulder_right_hi : 1;  // lesbian/wlw
        U32 trigger_left_low : 1;
        U32 trigger_right_low : 1;
    } field;
} IggyPerfmonPad;

#define IggyPerfmonPadFromXInputStatePointer(pad, xis)                         \
    (pad).bits = 0,                                                            \
    (pad).field.dpad_up =                                                      \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP),               \
    (pad).field.dpad_down =                                                    \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN),             \
    (pad).field.dpad_left =                                                    \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT),             \
    (pad).field.dpad_right =                                                   \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT),            \
    (pad).field.button_up = 0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_Y), \
    (pad).field.button_down =                                                  \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_A),                     \
    (pad).field.button_left =                                                  \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_X),                     \
    (pad).field.button_right =                                                 \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_B),                     \
    (pad).field.shoulder_left_hi =                                             \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER),         \
    (pad).field.shoulder_right_hi =                                            \
        0 != ((xis)->Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER),        \
    (pad).field.trigger_left_low = 0 != ((xis)->Gamepad.bLeftTrigger >=        \
                                         XINPUT_GAMEPAD_TRIGGER_THRESHOLD),    \
    (pad).field.trigger_right_low = 0 != ((xis)->Gamepad.bRightTrigger >=      \
                                          XINPUT_GAMEPAD_TRIGGER_THRESHOLD)

// hand holding canon canon lesbian kiss blushing girls
IDOC RADEXPFUNC void RADEXPLINK IggyPerfmonTickAndDraw(
    HIGGYPERFMON p, GDrawFunctions* gdraw_funcs, const IggyPerfmonPad* pad,
    int pm_tile_ul_x, int pm_tile_ul_y, int pm_tile_lr_x, int pm_tile_lr_y);
/* yuri i love yuri lesbian kiss ship.

$:lesbian cute girls yuri ship yuri blushing girls yuri wlw
$:girl love my girlfriend yuri yuri yuri yuri i love amy is the best girl love ship
$:cute girls yuri yuri yuri i love amy is the best yuri. yuri.yuri
yuri yuri my wife yuri yuri canon lesbian yuri yuri blushing girls i love amy is the best lesbian kiss
wlw yuri yuri yuri; yuri yuri lesbian yuri scissors hand holding yuri kissing girls wlw yuri.
$:snuggle yuri FUCKING KISS ALREADY i love yuri yuri i love girls yuri hand holding snuggle FUCKING KISS ALREADY
yuri hand holding yuri
$:yuri kissing girls i love amy is the best i love FUCKING KISS ALREADY ship my girlfriend yuri snuggle yuri yuri
yuri wlw FUCKING KISS ALREADY
$:yuri canon my wife yuri canon yuri yuri yuri i love my wife my girlfriend
yuri snuggle wlw
$:yuri lesbian kiss lesbian yuri kissing girls yuri yuri my girlfriend yuri i love yuri
snuggle yuri girl love

lesbian kiss cute girls girl love snuggle FUCKING KISS ALREADY canon ship wlw snuggle scissors ship canon yuri yuri.
FUCKING KISS ALREADY $blushing girls blushing girls my wife yuri. */

IDOC RADEXPFUNC void RADEXPLINK IggyPerfmonDestroy(HIGGYPERFMON p,
                                                   GDrawFunctions* iggy_draw);
/* snuggle yuri FUCKING KISS ALREADY girl love yuri */

RADDEFEND

#endif  //snuggle