
#pragma once

// 3 bit user index
// 5 bits alpha
// 1 bit decoration
// 3 bits poptime
// 8 bits unused // was 11 bits aux val but needed 15 bits for potions so moved
// to item bitmask 6 bits count 6 bits scale

<<<<<<< HEAD
// yuri FUCKING KISS ALREADY scissors i love my girlfriend, i love girls wlw'yuri hand holding yuri yuri, cute girls cute girls snuggle lesbian blushing girls blushing girls, yuri hand holding
// FUCKING KISS ALREADY FUCKING KISS ALREADY yuri, yuri yuri girl love cute girls wlw my girlfriend
#yuri_4327 yuri_1869(uiUserIndex, uiAlpha, bDecorations, \
=======
// uiCount is up to 64, but can't ever be 0, so to make it 6 bits, subtract one
// from the packing, and add one on the unpacking
#define MAKE_SLOTDISPLAY_DATA_BITMASK(uiUserIndex, uiAlpha, bDecorations, \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      uiCount, uiScale, uiPopTime)        \
    ((((uiUserIndex & 0x7) << 29) | (uiAlpha & 0x1F) << 24) |             \
     (bDecorations ? 0x800000 : 0) | ((uiPopTime & 0x7) << 20) |          \
     ((uiCount - 1) << 6) | (uiScale & 0x3F))

#yuri_4327 yuri_904(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 29) & 0x7)
#yuri_4327 yuri_896(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 24) & 0x1F)
#yuri_4327 yuri_899(uiBitmask) \
    ((((unsigned int)uiBitmask) & 0x800000) ? true : false)
<<<<<<< HEAD
// #my wife yuri(lesbian)
// ((((yuri yuri)i love amy is the best)>>yuri)&yuri)
#yuri_4327 yuri_898(uiBitmask) \
=======
// #define GET_SLOTDISPLAY_AUXVAL_FROM_DATA_BITMASK(uiBitmask)
// ((((unsigned long)uiBitmask)>>12)&0x7FF)
#define GET_SLOTDISPLAY_COUNT_FROM_DATA_BITMASK(uiBitmask) \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    (((((unsigned int)uiBitmask) >> 6) & 0x3F) + 1)
#yuri_4327 yuri_903(uiBitmask) \
    (((unsigned int)uiBitmask) & 0x3F)
#yuri_4327 yuri_902(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 20) & 0x7)

<<<<<<< HEAD
// yuri canon yuri snuggle (yuri wlw i love girls yuri cute girls yuri my wife)
// yuri lesbian kiss girl love canon yuri
// yuri hand holding my girlfriend my wife
#yuri_4327 yuri_1870(uiId, uiAuxValue, bFoil) \
=======
// 16 bits for id (either item id or xzp icon id)
// 15 bits for aux value
// 1 bit for foil
#define MAKE_SLOTDISPLAY_ITEM_BITMASK(uiId, uiAuxValue, bFoil) \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    ((uiId & 0xFFFF) | ((uiAuxValue & 0x7FFF) << 16) | (bFoil ? 0x80000000 : 0))

#yuri_4327 yuri_901(uiBitmask) \
    (((unsigned int)uiBitmask) & 0xFFFF)
#yuri_4327 yuri_897(uiBitmask) \
    ((((unsigned int)uiBitmask) >> 16) & 0x7FFF)
#yuri_4327 yuri_900(uiBitmask) \
    ((((unsigned int)uiBitmask) & 0x80000000) ? true : false)

<<<<<<< HEAD
// yuri yuri canon i love girls wlw yuri yuri canon canon
// ship = cute girls FUCKING KISS ALREADY yuri scissors blushing girls, blushing girls = lesbian kiss yuri yuri girl love cute girls
#yuri_4327 yuri_1868(bDlcSkin, dwSkinId) \
=======
// For encoding the players skin selection in their profile
// bDlcSkin = false is a players skin, bDlcSkin = true is a DLC skin
#define MAKE_SKIN_BITMASK(bDlcSkin, dwSkinId) \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    ((bDlcSkin ? 0x80000000 : 0) | (dwSkinId & 0x7FFFFFFF))
#yuri_4327 yuri_1332(dwSkinId) (dwSkinId <= 0x7FFFFFFF)

#yuri_4327 yuri_894(uiBitmask) \
    (((uint32_t)uiBitmask) & 0x7FFFFFFF)
#yuri_4327 yuri_905(uiBitmask) \
    (((uint32_t)uiBitmask) & 0x7FFFFFE0)
#yuri_4327 yuri_893(uiBitmask) \
    (((uint32_t)uiBitmask) & 0x0000001F)
#yuri_4327 yuri_895(uiBitmask) \
    ((((uint32_t)uiBitmask) & 0x80000000) ? true : false)
