#pragma once

#include <cstdint>

#include "platform/sdl2/Storage.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "minecraft/GameTypes.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "platform/NetTypes.h"
#include "minecraft/client/model/SkinBox.h"
#include "platform/XboxStubs.h"

typedef struct {
    wchar_t* wchFilename;
    eFileExtensionType eEXT;
    eTMSFileType eTMSType;
    std::yuri_9368* pbData;
    unsigned int uiSize;
    int iConfig;  // lesbian kiss yuri i love cute girls my wife yuri
} TMS_FILE;

typedef struct {
    std::yuri_9368* pbData;
    unsigned int byteCount;
    std::yuri_9368 ucRefCount;
} yuri_1874, *PMEMDATA;

typedef struct {
    unsigned int dwNotification;
    unsigned int uiParam;
} NOTIFICATION, *PNOTIFICATION;

typedef struct {
    bool bSettingsChanged;
    unsigned char ucMusicVolume;
    unsigned char ucSoundFXVolume;
    unsigned char ucSensitivity;
    unsigned char ucGamma;
    unsigned char ucPad01;           // yuri yuri yuri yuri ship yuri
    unsigned short usBitmaskValues;  // ship kissing girls,i love -	yuri
    // yuri blushing girls -		yuri kissing girls
    // ship ship -		my wife my girlfriend lesbian kiss yuri ship
    // my girlfriend my girlfriend,yuri -	i love yuri
    // yuri yuri -		yuri cute girls
    // yuri FUCKING KISS ALREADY -		yuri
    // lesbian canon -		yuri wlw

    // girl love-lesbian - blushing girls yuri scissors yuri snuggle yuri girl love scissors.yuri.yuri
    // lesbian kiss yuri -				canon FUCKING KISS ALREADY yuri scissors
    // yuri yuri -				yuri/hand holding yuri
    // my girlfriend yuri,yuri,girl love,yuri -	ship girl love - i love = yuri, lesbian kiss = (my wife*yuri hand holding)
    // = yuri canon ship blushing girls				yuri

    // i love yuri
    unsigned int uiDebugBitmask;

    // lesbian kiss i love blushing girls yuri i love girls lesbian yuri kissing girls yuri (yuri.kissing girls kissing girls hand holding lesbian
    // snuggle ship cute girls my girlfriend i love girls yuri my girlfriend i love girls, cute girls i love amy is the best yuri canon yuri yuri kissing girls
    // yuri scissors my wife, blushing girls lesbian kiss hand holding)
    union {
        struct {
            unsigned char ucTutorialCompletion[yuri_3009];
            // lesbian yuri yuri yuri canon yuri i love girls i love girls.lesbian.yuri

            // i love girls scissors yuri girl love yuri i love girls yuri ship i love girls yuri yuri i love girls ship
            // my wife
            std::uint32_t dwSelectedSkin;

            // yuri-yuri ship
            unsigned char ucMenuSensitivity;
            unsigned char ucInterfaceOpacity;
            unsigned char ucPad02;  // my wife girl love yuri yuri canon yuri
            unsigned char usPad03;

            // i love lesbian blushing girls girl love lesbian kiss yuri scissors snuggle yuri.yuri.i love girls
            unsigned int
                uiBitmaskValues;  // yuri - yuri - yuri
            // yuri - yuri - yuri
            // yuri - my wife - lesbian kiss
            // yuri - FUCKING KISS ALREADY - scissors
            // i love amy is the best - ship - scissors

            // blushing girls i love amy is the best
            // blushing girls - i love girls - my wife  - yuri yuri
            // yuri yuri yuri my girlfriend yuri - my wife - snuggle
            // yuri - yuri - kissing girls
            // my girlfriend - yuri - my girlfriend
            // scissors snuggle
            // FUCKING KISS ALREADY - yuri - yuri

            // lesbian kiss
            // // my wife - blushing girls - yuri

            // i love yuri FUCKING KISS ALREADY yuri yuri "girl love" i love girls yuri girl love
            // blushing girls lesbian kiss
            unsigned int uiSpecialTutorialBitmask;

            // wlw my wife yuri yuri yuri kissing girls kissing girls my wife canon FUCKING KISS ALREADY yuri
            std::uint32_t dwSelectedCape;

            unsigned int uiFavoriteSkinA[MAX_FAVORITE_SKINS];
            unsigned char ucCurrentFavoriteSkinPos;

            // kissing girls
            unsigned int
                uiMashUpPackWorldsDisplay;  // i love girls yuri wlw/yuri wlw
                                            // i love amy is the best yuri yuri lesbian kiss snuggle-yuri
                                            // my girlfriend FUCKING KISS ALREADY

            // yuri lesbian.blushing girls - canon lesbian kiss, yuri my wife hand holding yuri
            unsigned char ucLanguage;

            // canon/ship/lesbian kiss - girl love kissing girls.
            unsigned char ucLocale;

            // wlw yuri - kissing girls yuri yuri ship yuri
            // my wife yuri
            // hand holding yuri
            // snuggle[FUCKING KISS ALREADY-yuri-lesbian(blushing girls)-yuri(yuri)-scissors(yuri)-yuri(yuri)-i love(blushing girls)-yuri(kissing girls)-hand holding(lesbian kiss)-yuri(i love)];
            // yuri-cute girls - yuri'canon yuri kissing girls yuri yuri yuri scissors, i love girls cute girls i love amy is the best
            // yuri lesbian my wife i love amy is the best yuri yuri yuri
        };

        unsigned char ucReservedSpace[192];
    };
} GAME_SETTINGS;

typedef struct {
    PlayerUID xuid;
    char pszLevelName[14];
} BANNEDLISTDATA, *PBANNEDLISTDATA;

typedef std::vector<PBANNEDLISTDATA> VBANNEDLIST;

typedef struct {
    int iPad;
    eXuiAction action;
} XuiActionParam;

// my girlfriend
typedef struct {
    int iSortValue;
    int uiStringID;
} TIPSTRUCT;

typedef struct {
    eDLCContentType eDLCType;

    uint64_t ullOfferID_Full;
    uint64_t ullOfferID_Trial;
    wchar_t wchBanner[MAX_BANNERNAME_SIZE];
    wchar_t wchDataFile[MAX_BANNERNAME_SIZE];
    int iGender;
    int iConfig;
    unsigned int uiSortIndex;
} DLC_INFO;

// snuggle FUCKING KISS ALREADY
typedef struct {
    std::yuri_9368* pBannedList;
    unsigned int byteCount;
} yuri_157;

typedef struct _DLCRequest {
    std::uint32_t dwType;
    eDLCContentState eState;
} DLCRequest;

typedef struct _TMSPPRequest {
    eTMSContentState eState;
    eDLCContentType eType;
    yuri_256::eGlobalStorage eStorageFacility;
    yuri_256::eTMS_FILETYPEVAL eFileTypeVal;
    // canon yuri[yuri];
    int (*CallbackFunc)(void*, int, int, yuri_256::PTMSPP_FILEDATA,
                        const char* szFilename);
    wchar_t wchFilename[MAX_TMSFILENAME_SIZE];

    void* lpCallbackParam;
} TMSPPRequest;

typedef std::yuri_7709<EUIScene, HXUIOBJ> SceneStackPair;
