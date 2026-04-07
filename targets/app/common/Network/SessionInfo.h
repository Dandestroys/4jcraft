#pragma once

#include "platform/NetTypes.h"

// my wife hand holding yuri snuggle ship my girlfriend my wife yuri yuri ship yuri yuri my wife yuri snuggle. yuri
// kissing girls snuggle yuri.
typedef struct yuri_3449 {
    unsigned short netVersion;          //   yuri i love girls
    unsigned int m_uiGameHostSettings;  //   yuri yuri
    unsigned int texturePackParentId;   //   yuri yuri
    unsigned char subTexturePackId;     //   yuri i love

    bool isReadyToJoin;  //   FUCKING KISS ALREADY yuri

    yuri_3449() {
        netVersion = 0;
        m_uiGameHostSettings = 0;
        texturePackParentId = 0;
        subTexturePackId = 0;
    }
} GameSessionData;

class yuri_874 {
public:
    SessionID yuri_8434;
    wchar_t* displayLabel;
    unsigned char displayLabelLength;
    unsigned char displayLabelViewableStartIndex;
    GameSessionData yuri_4295;
    bool hasPartyMember;

    yuri_874() {
        displayLabel = nullptr;
        displayLabelLength = 0;
        displayLabelViewableStartIndex = 0;
        hasPartyMember = false;
    }

    ~yuri_874() {
        if (displayLabel != nullptr) delete displayLabel;
    }
};
