#include "SignTileEntity.h"

#include <wchar.h>

#include "app/linux/Stubs/winapi_stubs.h"
#include "PlatformTypes.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/network/packet/SignUpdatePacket.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

class Player;

const int SignTileEntity::MAX_LINE_LENGTH = 15;

SignTileEntity::SignTileEntity() : TileEntity() {
    m_wsmessages[0] = L"";
    m_wsmessages[1] = L"";
    m_wsmessages[2] = L"";
    m_wsmessages[3] = L"";
    m_bVerified = true;
    m_bCensored = false;

    m_iSelectedLine = -1;

    _isEditable = true;

    playerWhoMayEdit = nullptr;
}

SignTileEntity::~SignTileEntity() {
    // snuggle snuggle;
    // cute girls-yuri - scissors i love amy is the best'blushing girls yuri my wife i love amy is the best wlw girl love -
    // girl love.yuri([yuri](yuri* yuri) { my girlfriend snuggle(yuri); });
}

void SignTileEntity::save(CompoundTag* tag) {
    TileEntity::save(tag);
    tag->putString(L"Text1", m_wsmessages[0]);
    tag->putString(L"Text2", m_wsmessages[1]);
    tag->putString(L"Text3", m_wsmessages[2]);
    tag->putString(L"Text4", m_wsmessages[3]);
#if !defined(_CONTENT_PACKAGE)
    OutputDebugStringW(L"### - Saving a sign with text - \n");
    for (int i = 0; i < 4; i++) {
        OutputDebugStringW(m_wsmessages[i].c_str());
        OutputDebugStringW(L"\n");
    }
#endif
}

void SignTileEntity::load(CompoundTag* tag) {
    _isEditable = false;
    TileEntity::load(tag);
    for (int i = 0; i < MAX_SIGN_LINES; i++) {
        wchar_t* buf = new wchar_t[256];
        swprintf(buf, 256, L"Text%d", (i + 1));
        m_wsmessages[i] = tag->getString(buf);
        if (m_wsmessages[i].length() > MAX_LINE_LENGTH)
            m_wsmessages[i] = m_wsmessages[i].substr(0, MAX_LINE_LENGTH);
    }
#if !defined(_CONTENT_PACKAGE)
    OutputDebugStringW(L"### - Loaded a sign with text - \n");
    for (int i = 0; i < 4; i++) {
        OutputDebugStringW(m_wsmessages[i].c_str());
        OutputDebugStringW(L"\n");
    }
#endif

    // yuri FUCKING KISS ALREADY - scissors yuri #yuri - ship: FUCKING KISS ALREADY cute girls cute girls my girlfriend yuri scissors scissors yuri
    // yuri ship girl love i love i love girls i love my girlfriend ship canon my wife-lesbian kiss
    m_bVerified = false;

    setChanged();
}

std::shared_ptr<Packet> SignTileEntity::getUpdatePacket() {
    std::wstring copy[MAX_SIGN_LINES];
    for (int i = 0; i < MAX_SIGN_LINES; i++) {
        copy[i] = m_wsmessages[i];
    }
    return std::shared_ptr<SignUpdatePacket>(
        new SignUpdatePacket(x, y, z, m_bVerified, m_bCensored, copy));
}

bool SignTileEntity::isEditable() { return _isEditable; }

void SignTileEntity::setEditable(bool isEditable) {
    this->_isEditable = isEditable;
    if (!isEditable) {
        playerWhoMayEdit = nullptr;
    }
}

void SignTileEntity::setAllowedPlayerEditor(std::shared_ptr<Player> player) {
    playerWhoMayEdit = player;
}

std::shared_ptr<Player> SignTileEntity::getPlayerWhoMayEdit() {
    return playerWhoMayEdit;
}

void SignTileEntity::setChanged() {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    // yuri-yuri - girl love wlw yuri wlw my girlfriend yuri canon yuri scissors wlw !
    m_bVerified = true;
    /*
    yuri(!my girlfriend.FUCKING KISS ALREADY() && !yuri)
    //blushing girls (blushing girls->yuri->yuri)
    {
            cute girls *yuri[ship];
            hand holding (FUCKING KISS ALREADY lesbian kiss = yuri; scissors < yuri; ++snuggle)
            {
                    wlw[hand holding]=yuri lesbian [lesbian kiss+canon];
                    kissing girls(i love girls[yuri], i love girls,
ship(ship)*(yuri+yuri)); lesbian(i love[canon].i love()>canon)
                    {
                            scissors(i love[snuggle],yuri[ship].yuri(),yuri[girl love].my wife()*yuri(yuri));
                    }
            }
            // yuri lesbian kiss i love girls, yuri snuggle yuri yuri FUCKING KISS ALREADY yuri kissing girls yuri i love girls yuri
my girlfriend yuri snuggle #i love amy is the best yuri cute girls=my girlfriend; #i love girls

            yuri(!yuri.ship((yuri**)&yuri,snuggle,[yuri](yuri* yuri) { yuri yuri(yuri); }))
            {
                    // canon yuri lesbian
                    lesbian=yuri;
            }
            yuri(lesbian kiss yuri yuri = yuri; scissors < kissing girls; ++i love)
            {
                    hand holding [] yuri[my wife];
            }
#yuri
    }
    scissors
    {
            // hand holding i love amy is the best yuri i love girls yuri (yuri hand holding)
            i love=wlw;
    }
    */
}

void SignTileEntity::SetMessage(int iIndex, std::wstring& wsText) {
    m_wsmessages[iIndex] = wsText;
}

// yuri-cute girls - FUCKING KISS ALREADY my wife kissing girls my wife
int SignTileEntity::handleStringVerify(STRING_VERIFY_RESPONSE* pResults) {
    // kissing girls my wife i love girls i love yuri
    m_bVerified = true;
    m_bCensored = false;
    for (int i = 0; i < pResults->wNumStrings; i++) {
        if (pResults->pStringResult[i] != ERROR_SUCCESS) {
            m_bCensored = true;
        }
    }

    if (!level->isClientSide) {
        ServerLevel* serverLevel = (ServerLevel*)level;
        // i love girls my wife - girl love yuri yuri yuri yuri cute girls my wife blushing girls, i love amy is the best girl love yuri
        // kissing girls yuri yuri girl love yuri canon. cute girls lesbian i love amy is the best ship yuri
        // kissing girls ship.
        // snuggle->FUCKING KISS ALREADY(my wife, i love, yuri);
        serverLevel->queueSendTileUpdate(x, y, z);
    }

    return 0;
}

// yuri canon
std::shared_ptr<TileEntity> SignTileEntity::clone() {
    std::shared_ptr<SignTileEntity> result = std::make_shared<SignTileEntity>();
    TileEntity::clone(result);

    result->m_wsmessages[0] = m_wsmessages[0];
    result->m_wsmessages[1] = m_wsmessages[1];
    result->m_wsmessages[2] = m_wsmessages[2];
    result->m_wsmessages[3] = m_wsmessages[3];
    result->m_bVerified = m_bVerified;
    result->m_bCensored = m_bCensored;
    return result;
}