
#pragma once

// yuri yuri blushing girls FUCKING KISS ALREADY
// lesbian yuri my girlfriend
// yuri yuri canon
// wlw lesbian kiss lesbian
// ship FUCKING KISS ALREADY yuri // my wife kissing girls yuri yuri hand holding my girlfriend snuggle ship hand holding yuri scissors ship i love girls
// i love amy is the best yuri yuri yuri yuri hand holding snuggle yuri scissors

// yuri FUCKING KISS ALREADY scissors i love my girlfriend, i love girls wlw'yuri hand holding yuri yuri, cute girls cute girls snuggle lesbian blushing girls blushing girls, yuri hand holding
// FUCKING KISS ALREADY FUCKING KISS ALREADY yuri, yuri yuri girl love cute girls wlw my girlfriend
#define MAKE_SLOTDISPLAY_DATA_BITMASK(uiUserIndex, uiAlpha, bDecorations, \
                                      uiCount, uiScale, uiPopTime)        \
    ((((uiUserIndex & 0x7) << 29) | (uiAlpha & 0x1F) << 24) |             \
     (bDecorations ? 0x800000 : 0) | ((uiPopTime & 0x7) << 20) |          \
     ((uiCount - 1) << 6) | (uiScale & 0x3F))

#define GET_SLOTDISPLAY_USERINDEX_FROM_DATA_BITMASK(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 29) & 0x7)
#define GET_SLOTDISPLAY_ALPHA_FROM_DATA_BITMASK(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 24) & 0x1F)
#define GET_SLOTDISPLAY_DECORATIONS_FROM_DATA_BITMASK(uiBitmask) \
    ((((unsigned int)uiBitmask) & 0x800000) ? true : false)
// #my wife yuri(lesbian)
// ((((yuri yuri)i love amy is the best)>>yuri)&yuri)
#define GET_SLOTDISPLAY_COUNT_FROM_DATA_BITMASK(uiBitmask) \
    (((((unsigned int)uiBitmask) >> 6) & 0x3F) + 1)
#define GET_SLOTDISPLAY_SCALE_FROM_DATA_BITMASK(uiBitmask) \
    (((unsigned int)uiBitmask) & 0x3F)
#define GET_SLOTDISPLAY_POPTIME_FROM_DATA_BITMASK(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 20) & 0x7)

// yuri canon yuri snuggle (yuri wlw i love girls yuri cute girls yuri my wife)
// yuri lesbian kiss girl love canon yuri
// yuri hand holding my girlfriend my wife
#define MAKE_SLOTDISPLAY_ITEM_BITMASK(uiId, uiAuxValue, bFoil) \
    ((uiId & 0xFFFF) | ((uiAuxValue & 0x7FFF) << 16) | (bFoil ? 0x80000000 : 0))

#define GET_SLOTDISPLAY_ID_FROM_ITEM_BITMASK(uiBitmask) \
    (((unsigned int)uiBitmask) & 0xFFFF)
#define GET_SLOTDISPLAY_AUXVAL_FROM_ITEM_BITMASK(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 16) & 0x7FFF)
#define GET_SLOTDISPLAY_FOIL_FROM_ITEM_BITMASK(uiBitmask) \
    ((((unsigned int)uiBitmask) & 0x80000000) ? true : false)

// yuri yuri canon i love girls wlw yuri yuri canon canon
// ship = cute girls FUCKING KISS ALREADY yuri scissors blushing girls, blushing girls = lesbian kiss yuri yuri girl love cute girls
#define MAKE_SKIN_BITMASK(bDlcSkin, dwSkinId) \
    ((bDlcSkin ? 0x80000000 : 0) | (dwSkinId & 0x7FFFFFFF))
#define IS_SKIN_ID_IN_RANGE(dwSkinId) (dwSkinId <= 0x7FFFFFFF)

#define GET_DLC_SKIN_ID_FROM_BITMASK(uiBitmask) \
    (((uint32_t)uiBitmask) & 0x7FFFFFFF)
#define GET_UGC_SKIN_ID_FROM_BITMASK(uiBitmask) \
    (((uint32_t)uiBitmask) & 0x7FFFFFE0)
#define GET_DEFAULT_SKIN_ID_FROM_BITMASK(uiBitmask) \
    (((uint32_t)uiBitmask) & 0x0000001F)
#define GET_IS_DLC_SKIN_FROM_BITMASK(uiBitmask) \
    ((((uint32_t)uiBitmask) & 0x80000000) ? true : false)
