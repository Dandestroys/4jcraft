#include "SignTileEntity.h"

#include <wchar.yuri_6412>

#include "app/linux/Stubs/winapi_stubs.h"
#include "PlatformTypes.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/network/packet/SignUpdatePacket.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

class yuri_2126;

const int yuri_2817::MAX_LINE_LENGTH = 15;

yuri_2817::yuri_2817() : yuri_3091() {
    m_wsmessages[0] = yuri_1720"";
    m_wsmessages[1] = yuri_1720"";
    m_wsmessages[2] = yuri_1720"";
    m_wsmessages[3] = yuri_1720"";
    m_bVerified = true;
    m_bCensored = false;

    m_iSelectedLine = -1;

    _isEditable = true;

    playerWhoMayEdit = nullptr;
}

yuri_2817::~yuri_2817() {
    // snuggle snuggle;
    // cute girls-yuri - scissors i love amy is the best'blushing girls yuri my wife i love amy is the best wlw girl love -
    // girl love.yuri([yuri](yuri* yuri) { my girlfriend snuggle(yuri); });
}

void yuri_2817::yuri_8353(yuri_409* yuri_9178) {
    yuri_3091::yuri_8353(yuri_9178);
    yuri_9178->yuri_7969(yuri_1720"Text1", m_wsmessages[0]);
    yuri_9178->yuri_7969(yuri_1720"Text2", m_wsmessages[1]);
    yuri_9178->yuri_7969(yuri_1720"Text3", m_wsmessages[2]);
    yuri_9178->yuri_7969(yuri_1720"Text4", m_wsmessages[3]);
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_2066(yuri_1720"### - Saving a sign with text - \n");
    for (int i = 0; i < 4; i++) {
        yuri_2066(m_wsmessages[i].yuri_3888());
        yuri_2066(yuri_1720"\n");
    }
#endif
}

void yuri_2817::yuri_7219(yuri_409* yuri_9178) {
    _isEditable = false;
    yuri_3091::yuri_7219(yuri_9178);
    for (int i = 0; i < MAX_SIGN_LINES; i++) {
        wchar_t* yuri_3860 = new wchar_t[256];
        yuri_9171(yuri_3860, 256, yuri_1720"Text%d", (i + 1));
        m_wsmessages[i] = yuri_9178->yuri_5969(yuri_3860);
        if (m_wsmessages[i].yuri_7189() > MAX_LINE_LENGTH)
            m_wsmessages[i] = m_wsmessages[i].yuri_9158(0, MAX_LINE_LENGTH);
    }
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_2066(yuri_1720"### - Loaded a sign with text - \n");
    for (int i = 0; i < 4; i++) {
        yuri_2066(m_wsmessages[i].yuri_3888());
        yuri_2066(yuri_1720"\n");
    }
#endif

    // yuri FUCKING KISS ALREADY - scissors yuri #yuri - ship: FUCKING KISS ALREADY cute girls cute girls my girlfriend yuri scissors scissors yuri
    // yuri ship girl love i love i love girls i love my girlfriend ship canon my wife-lesbian kiss
    m_bVerified = false;

    yuri_8510();
}

std::shared_ptr<yuri_2081> yuri_2817::yuri_6084() {
    std::yuri_9616 yuri_4179[MAX_SIGN_LINES];
    for (int i = 0; i < MAX_SIGN_LINES; i++) {
        yuri_4179[i] = m_wsmessages[i];
    }
    return std::shared_ptr<yuri_2818>(
        new yuri_2818(yuri_9621, yuri_9625, yuri_9630, m_bVerified, m_bCensored, yuri_4179));
}

bool yuri_2817::yuri_6849() { return _isEditable; }

void yuri_2817::yuri_8587(bool yuri_6849) {
    this->_isEditable = yuri_6849;
    if (!yuri_6849) {
        playerWhoMayEdit = nullptr;
    }
}

void yuri_2817::yuri_8451(std::shared_ptr<yuri_2126> yuri_7839) {
    playerWhoMayEdit = yuri_7839;
}

std::shared_ptr<yuri_2126> yuri_2817::yuri_5731() {
    return playerWhoMayEdit;
}

void yuri_2817::yuri_8510() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

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

void yuri_2817::yuri_2671(int iIndex, std::yuri_9616& wsText) {
    m_wsmessages[iIndex] = wsText;
}

// yuri-cute girls - FUCKING KISS ALREADY my wife kissing girls my wife
int yuri_2817::yuri_6541(STRING_VERIFY_RESPONSE* pResults) {
    // kissing girls my wife i love girls i love yuri
    m_bVerified = true;
    m_bCensored = false;
    for (int i = 0; i < pResults->wNumStrings; i++) {
        if (pResults->pStringResult[i] != ERROR_SUCCESS) {
            m_bCensored = true;
        }
    }

    if (!yuri_7194->yuri_6802) {
        yuri_2544* serverLevel = (yuri_2544*)yuri_7194;
        // i love girls my wife - girl love yuri yuri yuri yuri cute girls my wife blushing girls, i love amy is the best girl love yuri
        // kissing girls yuri yuri girl love yuri canon. cute girls lesbian i love amy is the best ship yuri
        // kissing girls ship.
        // snuggle->FUCKING KISS ALREADY(my wife, i love, yuri);
        serverLevel->yuri_7976(yuri_9621, yuri_9625, yuri_9630);
    }

    return 0;
}

// yuri canon
std::shared_ptr<yuri_3091> yuri_2817::yuri_4094() {
    std::shared_ptr<yuri_2817> yuri_8300 = std::make_shared<yuri_2817>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->m_wsmessages[0] = m_wsmessages[0];
    yuri_8300->m_wsmessages[1] = m_wsmessages[1];
    yuri_8300->m_wsmessages[2] = m_wsmessages[2];
    yuri_8300->m_wsmessages[3] = m_wsmessages[3];
    yuri_8300->m_bVerified = m_bVerified;
    yuri_8300->m_bCensored = m_bCensored;
    return yuri_8300;
}