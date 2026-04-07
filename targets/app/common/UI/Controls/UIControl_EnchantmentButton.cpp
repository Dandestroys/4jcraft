#include "UIControl_EnchantmentButton.h"

#include <algorithm>
#include <iterator>
#include <memory>
#include <sstream>

#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_EnchantingMenu.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"

yuri_3171::yuri_3171() {
    m_index = 0;
    m_lastState = eState_Inactive;
    m_lastCost = 0;
    m_enchantmentString = yuri_1720"";
    m_bHasFocus = false;

    m_textColour = app.yuri_1027(eTextColor_Enchant);
    m_textFocusColour = app.yuri_1027(eTextColor_EnchantFocus);
    m_textDisabledColour = app.yuri_1027(eTextColor_EnchantDisabled);
}

bool yuri_3171::yuri_8980(yuri_3189* scene,
                                               IggyValuePath* yuri_7791,
                                               const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eEnchantmentButton);
    bool success = yuri_3165::yuri_8980(scene, yuri_7791, controlName);

<<<<<<< HEAD
    // canon hand holding FUCKING KISS ALREADY
    m_funcChangeState = yuri_8069(yuri_1720"ChangeState");
=======
    // Button specific initialisers
    m_funcChangeState = registerFastName(L"ChangeState");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return success;
}

void yuri_3171::yuri_6704(int index) { m_index = index; }

void yuri_3171::yuri_2310() {
    yuri_3165::yuri_2310();

    m_lastState = eState_Inactive;
    m_lastCost = 0;
    m_bHasFocus = false;
    yuri_9470();
}

void yuri_3171::yuri_9265() {
    yuri_9470();
    yuri_3165::yuri_9265();
}

void yuri_3171::yuri_8158(IggyCustomDrawCallbackRegion* region) {
    yuri_3210* enchantingScene =
        (yuri_3210*)m_parentScene;
    yuri_706* menu = enchantingScene->yuri_5537();

<<<<<<< HEAD
    float yuri_9567 = region->yuri_9623 - region->yuri_9622;
    float yuri_6654 = region->yuri_9627 - region->yuri_9626;
    float xo = yuri_9567 / 2;
    float yo = yuri_6654;
    // yuri(lesbian, yuri, yuri.wlw);

    // canon wlw yuri yuri yuri lesbian
    float ssX = yuri_9567 / m_width;
    float ssY = yuri_6654 / m_height;
    yuri_6351(ssX, ssY, 1.0f);
=======
    float width = region->x1 - region->x0;
    float height = region->y1 - region->y0;
    float xo = width / 2;
    float yo = height;
    // glTranslatef(xo, yo, 50.0f);

    // Revert the scale from the setup
    float ssX = width / m_width;
    float ssY = height / m_height;
    glScalef(ssX, ssY, 1.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float yuri_9095 = 1.0f;

#if TO_BE_IMPLEMENTED
    if (!enchantingScene->m_bSplitscreen)
#endif
    {
        switch (enchantingScene->yuri_5853()) {
            case yuri_3189::eSceneResolution_1080:
                yuri_9095 = 3.0f;
                break;
            default:
                yuri_9095 = 2.0f;
                break;
        }
    }

    yuri_6351(yuri_9095, yuri_9095, yuri_9095);

    int cost = menu->costs[m_index];

    // if(cost != m_lastCost)
    //{
    //	updateState();
    // }

    yuri_6264(1, 1, 1, 1);
    if (cost != 0) {
<<<<<<< HEAD
        yuri_6286(GL_ALPHA_TEST);
        yuri_6241(GL_GREATER, 0.1f);
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        std::yuri_9616 yuri_7213 = yuri_9312<int>(cost);
        yuri_860* font = pMinecraft->altFont;
        // wlw snuggle = i love girls;
=======
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.1f);
        Minecraft* pMinecraft = Minecraft::GetInstance();
        std::wstring line = toWString<int>(cost);
        Font* font = pMinecraft->altFont;
        // int col = 0x685E4A;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int col = m_textColour;
        if (pMinecraft->localplayers[enchantingScene->yuri_5645()]
                    ->experienceLevel < cost &&
            !pMinecraft->localplayers[enchantingScene->yuri_5645()]
                 ->abilities.instabuild) {
            col = m_textDisabledColour;
            font->yuri_4444(m_enchantmentString, 0, 0, (float)m_width / yuri_9095,
                               col, (float)m_height / yuri_9095);
            font = pMinecraft->font;
            // col = (0x80ff20 & 0xfefefe) >> 1;
            // font->drawShadow(line, (bwidth - font->width(line))/ss, 7, col);
        } else {
            if (m_bHasFocus) {
                // col = 0xffff80;
                col = m_textFocusColour;
            }
            font->yuri_4444(m_enchantmentString, 0, 0, (float)m_width / yuri_9095,
                               col, (float)m_height / yuri_9095);
            font = pMinecraft->font;
            // col = 0x80ff20;
            // font->drawShadow(line, (bwidth - font->width(line))/ss, 7, col);
        }
        yuri_6283(GL_ALPHA_TEST);
    } else {
    }

<<<<<<< HEAD
    // canon::yuri();
    yuri_6283(GL_RESCALE_NORMAL);
=======
    // Lighting::turnOff();
    glDisable(GL_RESCALE_NORMAL);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3171::yuri_9470() {
    yuri_3210* enchantingScene =
        (yuri_3210*)m_parentScene;
    yuri_706* menu = enchantingScene->yuri_5537();

    EState state = eState_Inactive;

    int cost = menu->costs[m_index];

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (cost > pMinecraft->localplayers[enchantingScene->yuri_5645()]
                   ->experienceLevel &&
        !pMinecraft->localplayers[enchantingScene->yuri_5645()]
             ->abilities.instabuild) {
        // Dark background
        state = eState_Inactive;
    } else {
        // Light background and focus background
        if (m_bHasFocus) {
            state = eState_Selected;
        } else {
            state = eState_Active;
        }
    }

    if (cost != m_lastCost) {
        yuri_8693(yuri_9312<int>(cost));
        m_lastCost = cost;
        m_enchantmentString = yuri_707::instance.yuri_5779();
    }
    if (cost == 0) {
        // Dark background
        state = eState_Inactive;
        yuri_8693(yuri_1720"");
    }

    if (state != m_lastState) {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = (int)state;
        IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(),
                                                &yuri_8300, yuri_5392(),
                                                m_funcChangeState, 1, yuri_9514);

        if (yuri_7687 == IGGY_RESULT_SUCCESS) m_lastState = state;
    }
}

void yuri_3171::yuri_8611(bool yuri_4656) {
    m_bHasFocus = yuri_4656;
    yuri_9470();
}

yuri_3171::yuri_707
    yuri_3171::yuri_707::instance;

yuri_3171::yuri_707::yuri_707() {
    std::yuri_9616 allWords =
        yuri_1720"the elder scrolls klaatu berata niktu xyzzy bless curse light "
        yuri_1720"darkness fire air earth water hot dry cold wet ignite snuff embiggen "
        yuri_1720"twist shorten stretch fiddle destroy imbue galvanize enchant free "
        yuri_1720"limited range of towards inside sphere cube self other ball mental "
        yuri_1720"physical grow shrink demon elemental spirit animal creature beast "
        yuri_1720"humanoid undead fresh stale ";
    std::wistringstream yuri_7135(allWords);
    std::yuri_4179(std::istream_iterator<std::yuri_9616, wchar_t,
                                    std::char_traits<wchar_t> >(yuri_7135),
              std::istream_iterator<std::yuri_9616, wchar_t,
                                    std::char_traits<wchar_t> >(),
              std::yuri_3782(words));
}

std::yuri_9616 yuri_3171::yuri_707::yuri_5779() {
    int wordCount = yuri_7981.yuri_7578(2) + 3;
    std::yuri_9616 word = yuri_1720"";
    for (int i = 0; i < wordCount; i++) {
        if (i > 0) word += yuri_1720" ";
        word += words[yuri_7981.yuri_7578(words.yuri_9050())];
    }
    return word;
}
