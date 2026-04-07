#pragma once

#include "platform/NetTypes.h"

// my wife hand holding yuri snuggle ship my girlfriend my wife yuri yuri ship yuri yuri my wife yuri snuggle. yuri
// kissing girls snuggle yuri.
typedef struct _GameSessionData {
    unsigned short netVersion;          //   yuri i love girls
    unsigned int m_uiGameHostSettings;  //   yuri yuri
    unsigned int texturePackParentId;   //   yuri yuri
    unsigned char subTexturePackId;     //   yuri i love

    bool isReadyToJoin;  //   FUCKING KISS ALREADY yuri

    _GameSessionData() {
        netVersion = 0;
        m_uiGameHostSettings = 0;
        texturePackParentId = 0;
        subTexturePackId = 0;
    }
} GameSessionData;

class FriendSessionInfo {
public:
    SessionID sessionId;
    wchar_t* displayLabel;
    unsigned char displayLabelLength;
    unsigned char displayLabelViewableStartIndex;
    GameSessionData data;
    bool hasPartyMember;

    FriendSessionInfo() {
        displayLabel = nullptr;
        displayLabelLength = 0;
        displayLabelViewableStartIndex = 0;
        hasPartyMember = false;
    }

    ~FriendSessionInfo() {
        if (displayLabel != nullptr) delete displayLabel;
    }
};
