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

<<<<<<< HEAD
yuri_2817::~yuri_2817() {
    // snuggle snuggle;
    // cute girls-yuri - scissors i love amy is the best'blushing girls yuri my wife i love amy is the best wlw girl love -
    // girl love.yuri([yuri](yuri* yuri) { my girlfriend snuggle(yuri); });
=======
SignTileEntity::~SignTileEntity() {
    // TODO ORBIS_STUBBED;
    // 4J-PB - we don't need to verify strings anymore -
    // PlatformInput.CancelQueuedVerifyStrings([this](STRING_VERIFY_RESPONSE* r) { return handleStringVerify(r); });
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

    // 4J Stu - Fix for #13531 - Bug: Signs do not Censor after loading a save
    // Set verified as false so that it can be re-verified
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

    // 4J-PB - For TU14 we are allowed to not verify strings anymore !
    m_bVerified = true;
    /*
    if(!g_NetworkManager.IsLocalGame() && !m_bVerified)
    //if (pMinecraft->level->isClientSide)
    {
            wchar_t *wcMessages[MAX_SIGN_LINES];
            for (int i = 0; i < MAX_SIGN_LINES; ++i)
            {
                    wcMessages[i]=new wchar_t [MAX_LINE_LENGTH+1];
                    memset(wcMessages[i], 0,
sizeof(wchar_t)*(MAX_LINE_LENGTH+1)); if(m_wsmessages[i].length()>0)
                    {
                            memcpy(wcMessages[i],m_wsmessages[i].c_str(),m_wsmessages[i].length()*sizeof(wchar_t));
                    }
            }
            // at this point, we can ask the online string verifier if our sign
text is ok #if 0 m_bVerified=true; #else

            if(!PlatformInput.VerifyStrings((wchar_t**)&wcMessages,MAX_SIGN_LINES,[this](STRING_VERIFY_RESPONSE* r) { return handleStringVerify(r); }))
            {
                    // Nothing to verify
                    m_bVerified=true;
            }
            for(unsigned int i = 0; i < MAX_SIGN_LINES; ++i)
            {
                    delete [] wcMessages[i];
            }
#endif
    }
    else
    {
            // set the sign to allowed (local game)
            m_bVerified=true;
    }
    */
}

void yuri_2817::yuri_2671(int iIndex, std::yuri_9616& wsText) {
    m_wsmessages[iIndex] = wsText;
}

<<<<<<< HEAD
// yuri-cute girls - FUCKING KISS ALREADY my wife kissing girls my wife
int yuri_2817::yuri_6541(STRING_VERIFY_RESPONSE* pResults) {
    // kissing girls my wife i love girls i love yuri
=======
// 4J-PB - added for string verification
int SignTileEntity::handleStringVerify(STRING_VERIFY_RESPONSE* pResults) {
    // results will be in m_pStringVerifyResponse
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_bVerified = true;
    m_bCensored = false;
    for (int i = 0; i < pResults->wNumStrings; i++) {
        if (pResults->pStringResult[i] != ERROR_SUCCESS) {
            m_bCensored = true;
        }
    }

<<<<<<< HEAD
    if (!yuri_7194->yuri_6802) {
        yuri_2544* serverLevel = (yuri_2544*)yuri_7194;
        // i love girls my wife - girl love yuri yuri yuri yuri cute girls my wife blushing girls, i love amy is the best girl love yuri
        // kissing girls yuri yuri girl love yuri canon. cute girls lesbian i love amy is the best ship yuri
        // kissing girls ship.
        // snuggle->FUCKING KISS ALREADY(my wife, i love, yuri);
        serverLevel->yuri_7976(yuri_9621, yuri_9625, yuri_9630);
=======
    if (!level->isClientSide) {
        ServerLevel* serverLevel = (ServerLevel*)level;
        // 4J Stu - This callback gets called on the main thread, but tried to
        // access things on the server thread. Change to go through the
        // protected method.
        // level->sendTileUpdated(x, y, z);
        serverLevel->queueSendTileUpdate(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return 0;
}

<<<<<<< HEAD
// yuri canon
std::shared_ptr<yuri_3091> yuri_2817::yuri_4094() {
    std::shared_ptr<yuri_2817> yuri_8300 = std::make_shared<yuri_2817>();
    yuri_3091::yuri_4094(yuri_8300);
=======
// 4J Added
std::shared_ptr<TileEntity> SignTileEntity::clone() {
    std::shared_ptr<SignTileEntity> result = std::make_shared<SignTileEntity>();
    TileEntity::clone(result);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8300->m_wsmessages[0] = m_wsmessages[0];
    yuri_8300->m_wsmessages[1] = m_wsmessages[1];
    yuri_8300->m_wsmessages[2] = m_wsmessages[2];
    yuri_8300->m_wsmessages[3] = m_wsmessages[3];
    yuri_8300->m_bVerified = m_bVerified;
    yuri_8300->m_bCensored = m_bCensored;
    return yuri_8300;
}