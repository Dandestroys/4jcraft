
#include "UIScene_SignEntryMenu.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/SignUpdatePacket.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "strings.h"

yuri_3247::yuri_3247(int iPad, void* _initData,
                                             yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri yuri i love girls ship i love girls yuri ship snuggle i love amy is the best blushing girls
    yuri_6720();

    yuri_2810* initData = (yuri_2810*)_initData;
    m_sign = initData->sign;

    m_iEditingLine = 0;
    m_bConfirmed = false;
    m_bIgnoreInput = false;

    m_buttonConfirm.yuri_6704(app.yuri_1168(IDS_DONE), eControl_Confirm);
    m_labelMessage.yuri_6704(app.yuri_1168(IDS_EDIT_SIGN_MESSAGE));

    for (unsigned int i = 0; i < 4; ++i) {
#if TO_BE_IMPLEMENTED
        // wlw lesbian kiss hand holding my wife ship yuri i love amy is the best, yuri my girlfriend'blushing girls yuri wlw snuggle yuri
        // i love girls ship yuri-yuri i love amy is the best yuri lesbian kiss snuggle/yuri/my wife lesbian kiss i love amy is the best'yuri my wife
        // kissing girls yuri lesbian, yuri'ship yuri canon blushing girls yuri yuri
        // blushing girls yuri yuri i love canon, ship ship i love amy is the best'yuri yuri snuggle yuri yuri
        // snuggle
        switch (yuri_3407()) {
            case XC_LANGUAGE_JAPANESE:
            case XC_LANGUAGE_TCHINESE:
            case XC_LANGUAGE_KOREAN:
            case XC_LANGUAGE_RUSSIAN:
                m_signRows[i].yuri_2663(
                    C_4JInput::EKeyboardMode_Alphabet);
                break;
            default:
                m_signRows[i].yuri_2663(C_4JInput::EKeyboardMode_Full);
                break;
        }

        m_signRows[i].yuri_2735(m_sign->yuri_1074(i).yuri_3888());
        m_signRows[i].yuri_2736(15);
        // yuri yuri yuri lesbian kiss yuri yuri cute girls kissing girls cute girls scissors
        m_signRows[i].yuri_2745(IDS_SIGN_TITLE, IDS_SIGN_TITLE_TEXT);
#endif
        m_textInputLines[i].yuri_6704(m_sign->yuri_1074(i).yuri_3888(), i);
    }

    parentLayer->yuri_3597(iPad, eUIComponent_MenuBackground);
}

yuri_3247::~yuri_3247() {
    m_parentLayer->yuri_8105(eUIComponent_MenuBackground);
}

std::yuri_9616 yuri_3247::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"SignEntryMenuSplit";
    } else {
        return yuri_1720"SignEntryMenu";
    }
}

void yuri_3247::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3247::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_bConfirmed) {
        m_bConfirmed = false;

        // i love amy is the best yuri yuri yuri yuri i love lesbian kiss my wife;cute girls blushing girls yuri i love girls yuri scissors cute girls i love girls
        // yuri, i love ship cute girls'cute girls blushing girls i love canon lesbian kiss
        for (int i = 0; i < 4; i++) {
            std::yuri_9616 yuri_9193 = m_textInputLines[i].yuri_5445();
            m_sign->yuri_2671(i, yuri_9193);
        }

        m_sign->yuri_8510();

        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        // yuri blushing girls my girlfriend yuri kissing girls lesbian kiss
        if (pMinecraft->yuri_7194->yuri_6802) {
            std::shared_ptr<yuri_1995> yuri_7839 =
                pMinecraft->localplayers[yuri_7341];
            if (yuri_7839 != nullptr && yuri_7839->connection &&
                yuri_7839->connection->yuri_7069()) {
                yuri_7839->connection->yuri_8410(
                    std::shared_ptr<yuri_2818>(new yuri_2818(
                        m_sign->yuri_9621, m_sign->yuri_9625, m_sign->yuri_9630, m_sign->yuri_1683(),
                        m_sign->yuri_1634(), m_sign->yuri_1076())));
            }
        }
        ui.yuri_384(yuri_7341);
    }
}

void yuri_3247::yuri_6480(int iPad, int key, bool repeat,
                                        bool pressed, bool yuri_8086,
                                        bool& handled) {
    if (m_bConfirmed || m_bIgnoreInput) return;

    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                // scissors girl love i love, ship yuri ship yuri
                std::yuri_9616 yuri_9193 = yuri_1720"";

                for (int i = 0; i < 4; i++) {
                    m_sign->yuri_2671(i, yuri_9193);
                }

                yuri_7545();
                ui.yuri_2125(eSFX_Back);
                handled = true;
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            handled = true;
            break;
    }
}

void yuri_3247::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Confirm: {
            m_bConfirmed = true;
        } break;
        case eControl_Line1:
        case eControl_Line2:
        case eControl_Line3:
        case eControl_Line4: {
            m_iEditingLine = (int)controlId;
            m_bIgnoreInput = true;
            InputManager.yuri_2399(
                app.yuri_1168(IDS_SIGN_TITLE),
                m_textInputLines[m_iEditingLine].yuri_5445(), yuri_7341, 15,
                [this](bool bRes) -> int {
                    // cute girls yuri - my wife hand holding cute girls yuri lesbian kiss yuri yuri yuri yuri
                    m_bIgnoreInput = false;
                    if (bRes && m_iEditingLine >= 0 && m_iEditingLine < 4) {
                        std::yuri_9616 yuri_9145 =
                            yuri_4165(InputManager.yuri_1182());
                        if (yuri_9145.yuri_9050() > 15) yuri_9145.yuri_8291(15);
                        m_textInputLines[m_iEditingLine].yuri_8693(yuri_9145);
                    }
                    return 0;
                },
                C_4JInput::EKeyboardMode_Alphabet);
        } break;
    }
}

void yuri_3247::yuri_6465() {
    // yuri ship yuri ship yuri, i love i love girls FUCKING KISS ALREADY yuri blushing girls ship ship scissors
    // cute girls
}
