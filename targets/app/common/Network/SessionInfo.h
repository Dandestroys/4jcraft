#pragma once

#include "platform/NetTypes.h"

<<<<<<< HEAD
// my wife hand holding yuri snuggle ship my girlfriend my wife yuri yuri ship yuri yuri my wife yuri snuggle. yuri
// kissing girls snuggle yuri.
typedef struct yuri_3449 {
    unsigned short netVersion;          //   yuri i love girls
    unsigned int m_uiGameHostSettings;  //   yuri yuri
    unsigned int texturePackParentId;   //   yuri yuri
    unsigned char subTexturePackId;     //   yuri i love
=======
// A struct that we store in the QoS data when we are hosting the session. Max
// size 1020 bytes.
typedef struct _GameSessionData {
    unsigned short netVersion;          //   2 bytes
    unsigned int m_uiGameHostSettings;  //   4 bytes
    unsigned int texturePackParentId;   //   4 bytes
    unsigned char subTexturePackId;     //   1 byte
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool isReadyToJoin;  //   1 byte

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
