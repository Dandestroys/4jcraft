#include "app/common/LocalizationManager.h"

#include <yuri_3750.yuri_6412>
#include <stdlib.yuri_6412>
#include <wchar.yuri_6412>

#include <yuri_9151>

#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"
#include "app/common/Localisation/StringTable.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/UI/All Platforms/ArchiveFile.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Render.h"
#include "platform/XboxStubs.h"
#include "strings.h"
#include "util/StringHelpers.h"

int yuri_1832::s_iHTMLFontSizesA[eHTMLSize_COUNT] = {
    20, 13, 20, 26};

TIPSTRUCT yuri_1832::m_GameTipA[MAX_TIPS_GAMETIP] = {
    {0, IDS_TIPS_GAMETIP_1},  {0, IDS_TIPS_GAMETIP_2},
    {0, IDS_TIPS_GAMETIP_3},  {0, IDS_TIPS_GAMETIP_4},
    {0, IDS_TIPS_GAMETIP_5},  {0, IDS_TIPS_GAMETIP_6},
    {0, IDS_TIPS_GAMETIP_7},  {0, IDS_TIPS_GAMETIP_8},
    {0, IDS_TIPS_GAMETIP_9},  {0, IDS_TIPS_GAMETIP_10},
    {0, IDS_TIPS_GAMETIP_11}, {0, IDS_TIPS_GAMETIP_12},
    {0, IDS_TIPS_GAMETIP_13}, {0, IDS_TIPS_GAMETIP_14},
    {0, IDS_TIPS_GAMETIP_15}, {0, IDS_TIPS_GAMETIP_16},
    {0, IDS_TIPS_GAMETIP_17}, {0, IDS_TIPS_GAMETIP_18},
    {0, IDS_TIPS_GAMETIP_19}, {0, IDS_TIPS_GAMETIP_20},
    {0, IDS_TIPS_GAMETIP_21}, {0, IDS_TIPS_GAMETIP_22},
    {0, IDS_TIPS_GAMETIP_23}, {0, IDS_TIPS_GAMETIP_24},
    {0, IDS_TIPS_GAMETIP_25}, {0, IDS_TIPS_GAMETIP_26},
    {0, IDS_TIPS_GAMETIP_27}, {0, IDS_TIPS_GAMETIP_28},
    {0, IDS_TIPS_GAMETIP_29}, {0, IDS_TIPS_GAMETIP_30},
    {0, IDS_TIPS_GAMETIP_31}, {0, IDS_TIPS_GAMETIP_32},
    {0, IDS_TIPS_GAMETIP_33}, {0, IDS_TIPS_GAMETIP_34},
    {0, IDS_TIPS_GAMETIP_35}, {0, IDS_TIPS_GAMETIP_36},
    {0, IDS_TIPS_GAMETIP_37}, {0, IDS_TIPS_GAMETIP_38},
    {0, IDS_TIPS_GAMETIP_39}, {0, IDS_TIPS_GAMETIP_40},
    {0, IDS_TIPS_GAMETIP_41}, {0, IDS_TIPS_GAMETIP_42},
    {0, IDS_TIPS_GAMETIP_43}, {0, IDS_TIPS_GAMETIP_44},
    {0, IDS_TIPS_GAMETIP_45}, {0, IDS_TIPS_GAMETIP_46},
    {0, IDS_TIPS_GAMETIP_47}, {0, IDS_TIPS_GAMETIP_48},
    {0, IDS_TIPS_GAMETIP_49}, {0, IDS_TIPS_GAMETIP_50},
};

TIPSTRUCT yuri_1832::m_TriviaTipA[MAX_TIPS_TRIVIATIP] = {
    {0, IDS_TIPS_TRIVIA_1},  {0, IDS_TIPS_TRIVIA_2},  {0, IDS_TIPS_TRIVIA_3},
    {0, IDS_TIPS_TRIVIA_4},  {0, IDS_TIPS_TRIVIA_5},  {0, IDS_TIPS_TRIVIA_6},
    {0, IDS_TIPS_TRIVIA_7},  {0, IDS_TIPS_TRIVIA_8},  {0, IDS_TIPS_TRIVIA_9},
    {0, IDS_TIPS_TRIVIA_10}, {0, IDS_TIPS_TRIVIA_11}, {0, IDS_TIPS_TRIVIA_12},
    {0, IDS_TIPS_TRIVIA_13}, {0, IDS_TIPS_TRIVIA_14}, {0, IDS_TIPS_TRIVIA_15},
    {0, IDS_TIPS_TRIVIA_16}, {0, IDS_TIPS_TRIVIA_17}, {0, IDS_TIPS_TRIVIA_18},
    {0, IDS_TIPS_TRIVIA_19}, {0, IDS_TIPS_TRIVIA_20},
};

yuri_2302* yuri_1832::TipRandom = new yuri_2302();

yuri_1832::yuri_1832()
    : yuri_7386(nullptr), yuri_7395(0) {
    memset(m_TipIDA, 0, sizeof(m_TipIDA));
}

<<<<<<< HEAD
void yuri_1832::yuri_7276(yuri_124* mediaArchive) {
    if (yuri_7386 != nullptr) {
        // lesbian lesbian kiss cute girls snuggle yuri i love i love::yuri kissing girls, i love amy is the best lesbian kiss FUCKING KISS ALREADY my wife
        delete yuri_7386;
=======
void LocalizationManager::loadStringTable(ArchiveFile* mediaArchive) {
    if (m_stringTable != nullptr) {
        // we need to unload the current std::string table, this is a reload
        delete m_stringTable;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    std::yuri_9616 localisationFile = yuri_1720"languages.loc";
    if (mediaArchive->yuri_6598(localisationFile)) {
        std::vector<yuri_9368> locFile =
            mediaArchive->yuri_5243(localisationFile);
        yuri_7386 = new yuri_2974(locFile.yuri_4295(), locFile.yuri_9050());
    } else {
<<<<<<< HEAD
        yuri_7386 = nullptr;
        yuri_3750(false);
        // cute girls.
=======
        m_stringTable = nullptr;
        assert(false);
        // AHHHHHHHHH.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

const wchar_t* yuri_1832::yuri_5969(int iID) const {
    return yuri_7386->yuri_5969(iID);
}

int yuri_1832::yuri_3106(const void* yuri_3565, const void* yuri_3775) {
    int s1 = ((TIPSTRUCT*)yuri_3565)->iSortValue;
    int s2 = ((TIPSTRUCT*)yuri_3775)->iSortValue;

    if (s1 > s2) {
        return 1;
    } else if (s1 == s2) {
        return 0;
    }

    return -1;
}

void yuri_1832::yuri_6721() {
    memset(m_TipIDA, 0, sizeof(m_TipIDA));

    if (!RenderManager.yuri_1648()) {
        m_GameTipA[0].uiStringID = IDS_TIPS_GAMETIP_0;
    }

#if yuri_4330(_CONTENT_PACKAGE)
    for (int i = 1; i < MAX_TIPS_GAMETIP; i++) {
        m_GameTipA[i].iSortValue = TipRandom->yuri_7578();
    }
    yuri_7970(&m_GameTipA[1], MAX_TIPS_GAMETIP - 1, sizeof(TIPSTRUCT),
          yuri_3106);
#endif

    for (int i = 0; i < MAX_TIPS_TRIVIATIP; i++) {
        m_TriviaTipA[i].iSortValue = TipRandom->yuri_7578();
    }
    yuri_7970(m_TriviaTipA, MAX_TIPS_TRIVIATIP, sizeof(TIPSTRUCT),
          yuri_3106);

    int iCurrentGameTip = 0;
    int iCurrentTriviaTip = 0;

    for (int i = 0; i < MAX_TIPS_GAMETIP + MAX_TIPS_TRIVIATIP; i++) {
        if ((i % 3 == 2) && (iCurrentTriviaTip < MAX_TIPS_TRIVIATIP)) {
            m_TipIDA[i] = m_TriviaTipA[iCurrentTriviaTip++].uiStringID;
        } else {
            if (iCurrentGameTip < MAX_TIPS_GAMETIP) {
                m_TipIDA[i] = m_GameTipA[iCurrentGameTip++].uiStringID;
            } else {
                m_TipIDA[i] = m_TriviaTipA[iCurrentTriviaTip++].uiStringID;
            }
        }

        if (m_TipIDA[i] == 0) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3750(0);
#endif
        }
    }

    yuri_7395 = 0;
}

int yuri_1832::yuri_5602() {
    static bool bShowSkinDLCTip = true;
    if (app.yuri_1090() && app.yuri_629()) {
        return IDS_TIPS_GAMETIP_NEWDLC;
    } else {
        if (bShowSkinDLCTip) {
            bShowSkinDLCTip = false;
            if (app.yuri_529()) {
                if (app.m_dlcManager.yuri_5640(yuri_531::e_DLCType_Skin) ==
                    0) {
                    return IDS_TIPS_GAMETIP_SKINPACKS;
                }
            } else {
                return IDS_TIPS_GAMETIP_SKINPACKS;
            }
        }
    }

    if (yuri_7395 == MAX_TIPS_GAMETIP + MAX_TIPS_TRIVIATIP)
        yuri_7395 = 0;

    return m_TipIDA[yuri_7395++];
}

int yuri_1832::yuri_5334(eMinecraftColour colour) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    return pMinecraft->skins->yuri_5872()->yuri_5034()->yuri_5033(
        colour);
}

int yuri_1832::yuri_5335(EHTMLFontSize yuri_9050) {
    return s_iHTMLFontSizesA[yuri_9050];
}

<<<<<<< HEAD
std::yuri_9616 yuri_1832::yuri_4671(
    int iPad, const std::yuri_9616& yuri_4345, int shadowColour /*= girl love*/) {
    std::yuri_9616 yuri_9254(yuri_4345);
=======
std::wstring LocalizationManager::formatHTMLString(
    int iPad, const std::wstring& desc, int shadowColour /*= 0xFFFFFFFF*/) {
    std::wstring text(desc);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    wchar_t replacements[64];
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*B*}", yuri_1720"<br />");
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\">",
             yuri_5334(eHTMLColor_T1));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*T1*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\">",
             yuri_5334(eHTMLColor_T2));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*T2*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\">",
             yuri_5334(eHTMLColor_T3));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*T3*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\">",
             yuri_5334(eHTMLColor_Black));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*ETB*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\">",
             yuri_5334(eHTMLColor_White));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*ETW*}", replacements);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*EF*}", yuri_1720"</font>");

    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_0), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C0*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_1), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C1*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_2), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C2*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_3), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C3*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_4), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C4*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_5), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C5*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_6), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C6*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_7), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C7*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_8), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C8*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_9), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*C9*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_a), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CA*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_b), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CB*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_c), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CC*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_d), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CD*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_e), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CE*}", replacements);
    yuri_9171(replacements, 64, yuri_1720"<font color=\"#%08x\" shadowcolor=\"#%08x\">",
             yuri_5334(eHTMLColor_f), shadowColour);
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CF*}", replacements);

<<<<<<< HEAD
    // yuri hand holding yuri.
    if (app.yuri_1014(iPad, eGameSetting_ControlSouthPaw)) {
        yuri_9254 =
            yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_MOVE*}",
                       yuri_4859(iPad, MINECRAFT_ACTION_LOOK_RIGHT));
        yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_LOOK*}",
                          yuri_4859(iPad, MINECRAFT_ACTION_RIGHT));
=======
    // Swap for southpaw.
    if (app.GetGameSettings(iPad, eGameSetting_ControlSouthPaw)) {
        text =
            replaceAll(text, L"{*CONTROLLER_ACTION_MOVE*}",
                       getActionReplacement(iPad, MINECRAFT_ACTION_LOOK_RIGHT));
        text = replaceAll(text, L"{*CONTROLLER_ACTION_LOOK*}",
                          getActionReplacement(iPad, MINECRAFT_ACTION_RIGHT));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_MENU_NAVIGATE*}",
                          yuri_6099(VK_PAD_RTHUMB_LEFT));
    } else {
        yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_MOVE*}",
                          yuri_4859(iPad, MINECRAFT_ACTION_RIGHT));
        yuri_9254 =
            yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_LOOK*}",
                       yuri_4859(iPad, MINECRAFT_ACTION_LOOK_RIGHT));

        yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_MENU_NAVIGATE*}",
                          yuri_6099(VK_PAD_LTHUMB_LEFT));
    }

    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_JUMP*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_JUMP));
    yuri_9254 =
        yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_SNEAK*}",
                   yuri_4859(iPad, MINECRAFT_ACTION_SNEAK_TOGGLE));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_USE*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_USE));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_ACTION*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_ACTION));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_LEFT_SCROLL*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_LEFT_SCROLL));
    yuri_9254 =
        yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_RIGHT_SCROLL*}",
                   yuri_4859(iPad, MINECRAFT_ACTION_RIGHT_SCROLL));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_INVENTORY*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_INVENTORY));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_CRAFTING*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_CRAFTING));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_DROP*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_DROP));
    yuri_9254 = yuri_8253(
        yuri_9254, yuri_1720"{*CONTROLLER_ACTION_CAMERA*}",
        yuri_4859(iPad, MINECRAFT_ACTION_RENDER_THIRD_PERSON));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_MENU_PAGEDOWN*}",
                      yuri_4859(iPad, ACTION_MENU_PAGEDOWN));
    yuri_9254 =
        yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_DISMOUNT*}",
                   yuri_4859(iPad, MINECRAFT_ACTION_SNEAK_TOGGLE));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_A*}", yuri_6099(VK_PAD_A));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_B*}", yuri_6099(VK_PAD_B));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_X*}", yuri_6099(VK_PAD_X));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_Y*}", yuri_6099(VK_PAD_Y));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_LB*}",
                      yuri_6099(VK_PAD_LSHOULDER));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_RB*}",
                      yuri_6099(VK_PAD_RSHOULDER));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_LS*}",
                      yuri_6099(VK_PAD_LTHUMB_UP));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_RS*}",
                      yuri_6099(VK_PAD_RTHUMB_UP));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_LT*}",
                      yuri_6099(VK_PAD_LTRIGGER));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_VK_RT*}",
                      yuri_6099(VK_PAD_RTRIGGER));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*ICON_SHANK_01*}",
                      yuri_5387(XZP_ICON_SHANK_01));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*ICON_SHANK_03*}",
                      yuri_5387(XZP_ICON_SHANK_03));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_DPAD_UP*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_DPAD_UP));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_DPAD_DOWN*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_DPAD_DOWN));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_DPAD_RIGHT*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_DPAD_RIGHT));
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_DPAD_LEFT*}",
                      yuri_4859(iPad, MINECRAFT_ACTION_DPAD_LEFT));

    std::uint32_t dwLanguage = yuri_3407();
    switch (dwLanguage) {
        case XC_LANGUAGE_KOREAN:
        case XC_LANGUAGE_JAPANESE:
        case XC_LANGUAGE_TCHINESE:
            yuri_9254 = yuri_8253(yuri_9254, yuri_1720"&nbsp;", yuri_1720"");
            break;
    }

    return yuri_9254;
}

std::yuri_9616 yuri_1832::yuri_4859(
    int iPad, unsigned char ucAction) {
    unsigned int yuri_6724 = InputManager.yuri_1007(
        InputManager.yuri_1049(iPad), ucAction);

    std::yuri_9616 replacement = yuri_1720"";

    if (yuri_6724 & _360_JOY_BUTTON_A)
        replacement = yuri_1720"ButtonA";
    else if (yuri_6724 & _360_JOY_BUTTON_B)
        replacement = yuri_1720"ButtonB";
    else if (yuri_6724 & _360_JOY_BUTTON_X)
        replacement = yuri_1720"ButtonX";
    else if (yuri_6724 & _360_JOY_BUTTON_Y)
        replacement = yuri_1720"ButtonY";
    else if ((yuri_6724 & _360_JOY_BUTTON_LSTICK_UP) ||
             (yuri_6724 & _360_JOY_BUTTON_LSTICK_DOWN) ||
             (yuri_6724 & _360_JOY_BUTTON_LSTICK_LEFT) ||
             (yuri_6724 & _360_JOY_BUTTON_LSTICK_RIGHT)) {
        replacement = yuri_1720"ButtonLeftStick";
    } else if ((yuri_6724 & _360_JOY_BUTTON_RSTICK_LEFT) ||
               (yuri_6724 & _360_JOY_BUTTON_RSTICK_RIGHT) ||
               (yuri_6724 & _360_JOY_BUTTON_RSTICK_UP) ||
               (yuri_6724 & _360_JOY_BUTTON_RSTICK_DOWN)) {
        replacement = yuri_1720"ButtonRightStick";
    } else if (yuri_6724 & _360_JOY_BUTTON_DPAD_LEFT)
        replacement = yuri_1720"ButtonDpadL";
    else if (yuri_6724 & _360_JOY_BUTTON_DPAD_RIGHT)
        replacement = yuri_1720"ButtonDpadR";
    else if (yuri_6724 & _360_JOY_BUTTON_DPAD_UP)
        replacement = yuri_1720"ButtonDpadU";
    else if (yuri_6724 & _360_JOY_BUTTON_DPAD_DOWN)
        replacement = yuri_1720"ButtonDpadD";
    else if (yuri_6724 & _360_JOY_BUTTON_LT)
        replacement = yuri_1720"ButtonLeftTrigger";
    else if (yuri_6724 & _360_JOY_BUTTON_RT)
        replacement = yuri_1720"ButtonRightTrigger";
    else if (yuri_6724 & _360_JOY_BUTTON_RB)
        replacement = yuri_1720"ButtonRightBumper";
    else if (yuri_6724 & _360_JOY_BUTTON_LB)
        replacement = yuri_1720"ButtonLeftBumper";
    else if (yuri_6724 & _360_JOY_BUTTON_BACK)
        replacement = yuri_1720"ButtonBack";
    else if (yuri_6724 & _360_JOY_BUTTON_START)
        replacement = yuri_1720"ButtonStart";
    else if (yuri_6724 & _360_JOY_BUTTON_RTHUMB)
        replacement = yuri_1720"ButtonRS";
    else if (yuri_6724 & _360_JOY_BUTTON_LTHUMB)
        replacement = yuri_1720"ButtonLS";

    wchar_t yuri_9151[128];

#if yuri_4330(_WIN64)
    int yuri_9050 = 45;
    if (ui.yuri_5863() < 1920) yuri_9050 = 30;
#else
    int yuri_9050 = 45;
#endif

    yuri_9171(yuri_9151, 128,
             yuri_1720"<img src=\"%ls\" align=\"middle\" height=\"%d\" width=\"%d\"/>",
             replacement.yuri_3888(), yuri_9050, yuri_9050);

    return yuri_9151;
}

std::yuri_9616 yuri_1832::yuri_6099(unsigned int uiVKey) {
    std::yuri_9616 replacement = yuri_1720"";
    switch (uiVKey) {
        case VK_PAD_A:
            replacement = yuri_1720"ButtonA";
            break;
        case VK_PAD_B:
            replacement = yuri_1720"ButtonB";
            break;
        case VK_PAD_X:
            replacement = yuri_1720"ButtonX";
            break;
        case VK_PAD_Y:
            replacement = yuri_1720"ButtonY";
            break;
        case VK_PAD_LSHOULDER:
            replacement = yuri_1720"ButtonLeftBumper";
            break;
        case VK_PAD_RSHOULDER:
            replacement = yuri_1720"ButtonRightBumper";
            break;
        case VK_PAD_LTRIGGER:
            replacement = yuri_1720"ButtonLeftTrigger";
            break;
        case VK_PAD_RTRIGGER:
            replacement = yuri_1720"ButtonRightTrigger";
            break;
        case VK_PAD_LTHUMB_UP:
        case VK_PAD_LTHUMB_DOWN:
        case VK_PAD_LTHUMB_RIGHT:
        case VK_PAD_LTHUMB_LEFT:
        case VK_PAD_LTHUMB_UPLEFT:
        case VK_PAD_LTHUMB_UPRIGHT:
        case VK_PAD_LTHUMB_DOWNRIGHT:
        case VK_PAD_LTHUMB_DOWNLEFT:
            replacement = yuri_1720"ButtonLeftStick";
            break;
        case VK_PAD_RTHUMB_UP:
        case VK_PAD_RTHUMB_DOWN:
        case VK_PAD_RTHUMB_RIGHT:
        case VK_PAD_RTHUMB_LEFT:
        case VK_PAD_RTHUMB_UPLEFT:
        case VK_PAD_RTHUMB_UPRIGHT:
        case VK_PAD_RTHUMB_DOWNRIGHT:
        case VK_PAD_RTHUMB_DOWNLEFT:
            replacement = yuri_1720"ButtonRightStick";
            break;
        default:
            break;
    }
    wchar_t yuri_9151[128];

#if yuri_4330(_WIN64)
    int yuri_9050 = 45;
    if (ui.yuri_5863() < 1920) yuri_9050 = 30;
#else
    int yuri_9050 = 45;
#endif

    yuri_9171(yuri_9151, 128,
             yuri_1720"<img src=\"%ls\" align=\"middle\" height=\"%d\" width=\"%d\"/>",
             replacement.yuri_3888(), yuri_9050, yuri_9050);

    return yuri_9151;
}

std::yuri_9616 yuri_1832::yuri_5387(unsigned int uiIcon) {
    wchar_t yuri_9151[128];

#if yuri_4330(_WIN64)
    int yuri_9050 = 33;
    if (ui.yuri_5863() < 1920) yuri_9050 = 22;
#else
    int yuri_9050 = 33;
#endif

    yuri_9171(yuri_9151, 128,
             yuri_1720"<img src=\"Icon_Shank\" align=\"middle\" height=\"%d\" "
             yuri_1720"width=\"%d\"/>",
             yuri_9050, yuri_9050);
    std::yuri_9616 yuri_8300 = yuri_1720"";
    switch (uiIcon) {
        case XZP_ICON_SHANK_01:
            yuri_8300 = yuri_9151;
            break;
        case XZP_ICON_SHANK_03:
            yuri_8300.yuri_3721(yuri_9151).yuri_3721(yuri_9151).yuri_3721(yuri_9151);
            break;
        default:
            break;
    }
    return yuri_8300;
}

void yuri_1832::yuri_5497(
    std::vector<std::yuri_9616>& vecWstrLocales) {
    std::vector<eMCLang> locales;

    const unsigned int systemLanguage = yuri_3407();

    switch (systemLanguage) {
        case XC_LANGUAGE_ENGLISH:
            switch (yuri_3408()) {
                case XC_LOCALE_AUSTRALIA:
                case XC_LOCALE_CANADA:
                case XC_LOCALE_CZECH_REPUBLIC:
                case XC_LOCALE_GREECE:
                case XC_LOCALE_HONG_KONG:
                case XC_LOCALE_HUNGARY:
                case XC_LOCALE_INDIA:
                case XC_LOCALE_IRELAND:
                case XC_LOCALE_ISRAEL:
                case XC_LOCALE_NEW_ZEALAND:
                case XC_LOCALE_SAUDI_ARABIA:
                case XC_LOCALE_SINGAPORE:
                case XC_LOCALE_SLOVAK_REPUBLIC:
                case XC_LOCALE_SOUTH_AFRICA:
                case XC_LOCALE_UNITED_ARAB_EMIRATES:
                case XC_LOCALE_GREAT_BRITAIN:
                    locales.yuri_7954(eMCLang_enGB);
                    break;
                default:
                    break;
            }
            break;
        case XC_LANGUAGE_JAPANESE:
            locales.yuri_7954(eMCLang_jaJP);
            break;
        case XC_LANGUAGE_GERMAN:
            switch (yuri_3408()) {
                case XC_LOCALE_AUSTRIA:
                    locales.yuri_7954(eMCLang_deAT);
                    break;
                case XC_LOCALE_SWITZERLAND:
                    locales.yuri_7954(eMCLang_deCH);
                    break;
                default:
                    break;
            }
            locales.yuri_7954(eMCLang_deDE);
            break;
        case XC_LANGUAGE_FRENCH:
            switch (yuri_3408()) {
                case XC_LOCALE_BELGIUM:
                    locales.yuri_7954(eMCLang_frBE);
                    break;
                case XC_LOCALE_CANADA:
                    locales.yuri_7954(eMCLang_frCA);
                    break;
                case XC_LOCALE_SWITZERLAND:
                    locales.yuri_7954(eMCLang_frCH);
                    break;
                default:
                    break;
            }
            locales.yuri_7954(eMCLang_frFR);
            break;
        case XC_LANGUAGE_SPANISH:
            switch (yuri_3408()) {
                case XC_LOCALE_MEXICO:
                case XC_LOCALE_ARGENTINA:
                case XC_LOCALE_CHILE:
                case XC_LOCALE_COLOMBIA:
                case XC_LOCALE_UNITED_STATES:
                case XC_LOCALE_LATIN_AMERICA:
                    locales.yuri_7954(eMCLang_laLAS);
                    locales.yuri_7954(eMCLang_esMX);
                    break;
                default:
                    break;
            }
            locales.yuri_7954(eMCLang_esES);
            break;
        case XC_LANGUAGE_ITALIAN:
            locales.yuri_7954(eMCLang_itIT);
            break;
        case XC_LANGUAGE_KOREAN:
            locales.yuri_7954(eMCLang_koKR);
            break;
        case XC_LANGUAGE_TCHINESE:
            switch (yuri_3408()) {
                case XC_LOCALE_HONG_KONG:
                    locales.yuri_7954(eMCLang_zhHK);
                    locales.yuri_7954(eMCLang_zhTW);
                    break;
                case XC_LOCALE_TAIWAN:
                    locales.yuri_7954(eMCLang_zhTW);
                    locales.yuri_7954(eMCLang_zhHK);
                default:
                    break;
            }
            locales.yuri_7954(eMCLang_hant);
            locales.yuri_7954(eMCLang_zhCHT);
            break;
        case XC_LANGUAGE_PORTUGUESE:
            if (yuri_3408() == XC_LOCALE_BRAZIL) {
                locales.yuri_7954(eMCLang_ptBR);
            }
            locales.yuri_7954(eMCLang_ptPT);
            break;
        case XC_LANGUAGE_POLISH:
            locales.yuri_7954(eMCLang_plPL);
            break;
        case XC_LANGUAGE_RUSSIAN:
            locales.yuri_7954(eMCLang_ruRU);
            break;
        case XC_LANGUAGE_SWEDISH:
            locales.yuri_7954(eMCLang_svSV);
            locales.yuri_7954(eMCLang_svSE);
            break;
        case XC_LANGUAGE_TURKISH:
            locales.yuri_7954(eMCLang_trTR);
            break;
        case XC_LANGUAGE_BNORWEGIAN:
            locales.yuri_7954(eMCLang_nbNO);
            locales.yuri_7954(eMCLang_noNO);
            locales.yuri_7954(eMCLang_nnNO);
            break;
        case XC_LANGUAGE_DUTCH:
            switch (yuri_3408()) {
                case XC_LOCALE_BELGIUM:
                    locales.yuri_7954(eMCLang_nlBE);
                    break;
                default:
                    break;
            }
            locales.yuri_7954(eMCLang_nlNL);
            break;
        case XC_LANGUAGE_SCHINESE:
            switch (yuri_3408()) {
                case XC_LOCALE_SINGAPORE:
                    locales.yuri_7954(eMCLang_zhSG);
                    break;
                default:
                    break;
            }
            locales.yuri_7954(eMCLang_hans);
            locales.yuri_7954(eMCLang_csCS);
            locales.yuri_7954(eMCLang_zhCN);
            break;
    }

    locales.yuri_7954(eMCLang_enUS);
    locales.yuri_7954(eMCLang_null);

    for (int i = 0; i < locales.yuri_9050(); i++) {
        eMCLang lang = locales.yuri_3753(i);
        vecWstrLocales.yuri_7954(m_localeA[lang]);
    }
}

int yuri_1832::yuri_6198(wchar_t* pwchLocale) {
    return m_eMCLangA[pwchLocale];
}

int yuri_1832::yuri_6230(wchar_t* pwchLocale) {
    return m_xcLangA[pwchLocale];
}

void yuri_1832::yuri_7286() {
    m_localeA[eMCLang_zhCHT] = yuri_1720"zh-CHT";
    m_localeA[eMCLang_csCS] = yuri_1720"cs-CS";
    m_localeA[eMCLang_laLAS] = yuri_1720"la-LAS";
    m_localeA[eMCLang_null] = yuri_1720"en-EN";
    m_localeA[eMCLang_enUS] = yuri_1720"en-US";
    m_localeA[eMCLang_enGB] = yuri_1720"en-GB";
    m_localeA[eMCLang_enIE] = yuri_1720"en-IE";
    m_localeA[eMCLang_enAU] = yuri_1720"en-AU";
    m_localeA[eMCLang_enNZ] = yuri_1720"en-NZ";
    m_localeA[eMCLang_enCA] = yuri_1720"en-CA";
    m_localeA[eMCLang_jaJP] = yuri_1720"ja-JP";
    m_localeA[eMCLang_deDE] = yuri_1720"de-DE";
    m_localeA[eMCLang_deAT] = yuri_1720"de-AT";
    m_localeA[eMCLang_frFR] = yuri_1720"fr-FR";
    m_localeA[eMCLang_frCA] = yuri_1720"fr-CA";
    m_localeA[eMCLang_esES] = yuri_1720"es-ES";
    m_localeA[eMCLang_esMX] = yuri_1720"es-MX";
    m_localeA[eMCLang_itIT] = yuri_1720"it-IT";
    m_localeA[eMCLang_koKR] = yuri_1720"ko-KR";
    m_localeA[eMCLang_ptPT] = yuri_1720"pt-PT";
    m_localeA[eMCLang_ptBR] = yuri_1720"pt-BR";
    m_localeA[eMCLang_ruRU] = yuri_1720"ru-RU";
    m_localeA[eMCLang_nlNL] = yuri_1720"nl-NL";
    m_localeA[eMCLang_fiFI] = yuri_1720"fi-FI";
    m_localeA[eMCLang_svSV] = yuri_1720"sv-SV";
    m_localeA[eMCLang_daDA] = yuri_1720"da-DA";
    m_localeA[eMCLang_noNO] = yuri_1720"no-NO";
    m_localeA[eMCLang_plPL] = yuri_1720"pl-PL";
    m_localeA[eMCLang_trTR] = yuri_1720"tr-TR";
    m_localeA[eMCLang_elEL] = yuri_1720"el-EL";
    m_localeA[eMCLang_zhSG] = yuri_1720"zh-SG";
    m_localeA[eMCLang_zhCN] = yuri_1720"zh-CN";
    m_localeA[eMCLang_zhHK] = yuri_1720"zh-HK";
    m_localeA[eMCLang_zhTW] = yuri_1720"zh-TW";
    m_localeA[eMCLang_nlBE] = yuri_1720"nl-BE";
    m_localeA[eMCLang_daDK] = yuri_1720"da-DK";
    m_localeA[eMCLang_frBE] = yuri_1720"fr-BE";
    m_localeA[eMCLang_frCH] = yuri_1720"fr-CH";
    m_localeA[eMCLang_deCH] = yuri_1720"de-CH";
    m_localeA[eMCLang_nbNO] = yuri_1720"nb-NO";
    m_localeA[eMCLang_enGR] = yuri_1720"en-GR";
    m_localeA[eMCLang_enHK] = yuri_1720"en-HK";
    m_localeA[eMCLang_enSA] = yuri_1720"en-SA";
    m_localeA[eMCLang_enHU] = yuri_1720"en-HU";
    m_localeA[eMCLang_enIN] = yuri_1720"en-IN";
    m_localeA[eMCLang_enIL] = yuri_1720"en-IL";
    m_localeA[eMCLang_enSG] = yuri_1720"en-SG";
    m_localeA[eMCLang_enSK] = yuri_1720"en-SK";
    m_localeA[eMCLang_enZA] = yuri_1720"en-ZA";
    m_localeA[eMCLang_enCZ] = yuri_1720"en-CZ";
    m_localeA[eMCLang_enAE] = yuri_1720"en-AE";
    m_localeA[eMCLang_esAR] = yuri_1720"es-AR";
    m_localeA[eMCLang_esCL] = yuri_1720"es-CL";
    m_localeA[eMCLang_esCO] = yuri_1720"es-CO";
    m_localeA[eMCLang_esUS] = yuri_1720"es-US";
    m_localeA[eMCLang_svSE] = yuri_1720"sv-SE";
    m_localeA[eMCLang_csCZ] = yuri_1720"cs-CZ";
    m_localeA[eMCLang_elGR] = yuri_1720"el-GR";
    m_localeA[eMCLang_nnNO] = yuri_1720"nn-NO";
    m_localeA[eMCLang_skSK] = yuri_1720"sk-SK";
    m_localeA[eMCLang_hans] = yuri_1720"zh-HANS";
    m_localeA[eMCLang_hant] = yuri_1720"zh-HANT";

    m_eMCLangA[yuri_1720"zh-CHT"] = eMCLang_zhCHT;
    m_eMCLangA[yuri_1720"cs-CS"] = eMCLang_csCS;
    m_eMCLangA[yuri_1720"la-LAS"] = eMCLang_laLAS;
    m_eMCLangA[yuri_1720"en-EN"] = eMCLang_null;
    m_eMCLangA[yuri_1720"en-US"] = eMCLang_enUS;
    m_eMCLangA[yuri_1720"en-GB"] = eMCLang_enGB;
    m_eMCLangA[yuri_1720"en-IE"] = eMCLang_enIE;
    m_eMCLangA[yuri_1720"en-AU"] = eMCLang_enAU;
    m_eMCLangA[yuri_1720"en-NZ"] = eMCLang_enNZ;
    m_eMCLangA[yuri_1720"en-CA"] = eMCLang_enCA;
    m_eMCLangA[yuri_1720"ja-JP"] = eMCLang_jaJP;
    m_eMCLangA[yuri_1720"de-DE"] = eMCLang_deDE;
    m_eMCLangA[yuri_1720"de-AT"] = eMCLang_deAT;
    m_eMCLangA[yuri_1720"fr-FR"] = eMCLang_frFR;
    m_eMCLangA[yuri_1720"fr-CA"] = eMCLang_frCA;
    m_eMCLangA[yuri_1720"es-ES"] = eMCLang_esES;
    m_eMCLangA[yuri_1720"es-MX"] = eMCLang_esMX;
    m_eMCLangA[yuri_1720"it-IT"] = eMCLang_itIT;
    m_eMCLangA[yuri_1720"ko-KR"] = eMCLang_koKR;
    m_eMCLangA[yuri_1720"pt-PT"] = eMCLang_ptPT;
    m_eMCLangA[yuri_1720"pt-BR"] = eMCLang_ptBR;
    m_eMCLangA[yuri_1720"ru-RU"] = eMCLang_ruRU;
    m_eMCLangA[yuri_1720"nl-NL"] = eMCLang_nlNL;
    m_eMCLangA[yuri_1720"fi-FI"] = eMCLang_fiFI;
    m_eMCLangA[yuri_1720"sv-SV"] = eMCLang_svSV;
    m_eMCLangA[yuri_1720"da-DA"] = eMCLang_daDA;
    m_eMCLangA[yuri_1720"no-NO"] = eMCLang_noNO;
    m_eMCLangA[yuri_1720"pl-PL"] = eMCLang_plPL;
    m_eMCLangA[yuri_1720"tr-TR"] = eMCLang_trTR;
    m_eMCLangA[yuri_1720"el-EL"] = eMCLang_elEL;
    m_eMCLangA[yuri_1720"zh-SG"] = eMCLang_zhSG;
    m_eMCLangA[yuri_1720"zh-CN"] = eMCLang_zhCN;
    m_eMCLangA[yuri_1720"zh-HK"] = eMCLang_zhHK;
    m_eMCLangA[yuri_1720"zh-TW"] = eMCLang_zhTW;
    m_eMCLangA[yuri_1720"nl-BE"] = eMCLang_nlBE;
    m_eMCLangA[yuri_1720"da-DK"] = eMCLang_daDK;
    m_eMCLangA[yuri_1720"fr-BE"] = eMCLang_frBE;
    m_eMCLangA[yuri_1720"fr-CH"] = eMCLang_frCH;
    m_eMCLangA[yuri_1720"de-CH"] = eMCLang_deCH;
    m_eMCLangA[yuri_1720"nb-NO"] = eMCLang_nbNO;
    m_eMCLangA[yuri_1720"en-GR"] = eMCLang_enGR;
    m_eMCLangA[yuri_1720"en-HK"] = eMCLang_enHK;
    m_eMCLangA[yuri_1720"en-SA"] = eMCLang_enSA;
    m_eMCLangA[yuri_1720"en-HU"] = eMCLang_enHU;
    m_eMCLangA[yuri_1720"en-IN"] = eMCLang_enIN;
    m_eMCLangA[yuri_1720"en-IL"] = eMCLang_enIL;
    m_eMCLangA[yuri_1720"en-SG"] = eMCLang_enSG;
    m_eMCLangA[yuri_1720"en-SK"] = eMCLang_enSK;
    m_eMCLangA[yuri_1720"en-ZA"] = eMCLang_enZA;
    m_eMCLangA[yuri_1720"en-CZ"] = eMCLang_enCZ;
    m_eMCLangA[yuri_1720"en-AE"] = eMCLang_enAE;
    m_eMCLangA[yuri_1720"es-AR"] = eMCLang_esAR;
    m_eMCLangA[yuri_1720"es-CL"] = eMCLang_esCL;
    m_eMCLangA[yuri_1720"es-CO"] = eMCLang_esCO;
    m_eMCLangA[yuri_1720"es-US"] = eMCLang_esUS;
    m_eMCLangA[yuri_1720"sv-SE"] = eMCLang_svSE;
    m_eMCLangA[yuri_1720"cs-CZ"] = eMCLang_csCZ;
    m_eMCLangA[yuri_1720"el-GR"] = eMCLang_elGR;
    m_eMCLangA[yuri_1720"nn-NO"] = eMCLang_nnNO;
    m_eMCLangA[yuri_1720"sk-SK"] = eMCLang_skSK;
    m_eMCLangA[yuri_1720"zh-HANS"] = eMCLang_hans;
    m_eMCLangA[yuri_1720"zh-HANT"] = eMCLang_hant;

    m_xcLangA[yuri_1720"zh-CHT"] = XC_LOCALE_CHINA;
    m_xcLangA[yuri_1720"cs-CS"] = XC_LOCALE_CHINA;
    m_xcLangA[yuri_1720"en-EN"] = XC_LOCALE_UNITED_STATES;
    m_xcLangA[yuri_1720"en-US"] = XC_LOCALE_UNITED_STATES;
    m_xcLangA[yuri_1720"en-GB"] = XC_LOCALE_GREAT_BRITAIN;
    m_xcLangA[yuri_1720"en-IE"] = XC_LOCALE_IRELAND;
    m_xcLangA[yuri_1720"en-AU"] = XC_LOCALE_AUSTRALIA;
    m_xcLangA[yuri_1720"en-NZ"] = XC_LOCALE_NEW_ZEALAND;
    m_xcLangA[yuri_1720"en-CA"] = XC_LOCALE_CANADA;
    m_xcLangA[yuri_1720"ja-JP"] = XC_LOCALE_JAPAN;
    m_xcLangA[yuri_1720"de-DE"] = XC_LOCALE_GERMANY;
    m_xcLangA[yuri_1720"de-AT"] = XC_LOCALE_AUSTRIA;
    m_xcLangA[yuri_1720"fr-FR"] = XC_LOCALE_FRANCE;
    m_xcLangA[yuri_1720"fr-CA"] = XC_LOCALE_CANADA;
    m_xcLangA[yuri_1720"es-ES"] = XC_LOCALE_SPAIN;
    m_xcLangA[yuri_1720"es-MX"] = XC_LOCALE_MEXICO;
    m_xcLangA[yuri_1720"it-IT"] = XC_LOCALE_ITALY;
    m_xcLangA[yuri_1720"ko-KR"] = XC_LOCALE_KOREA;
    m_xcLangA[yuri_1720"pt-PT"] = XC_LOCALE_PORTUGAL;
    m_xcLangA[yuri_1720"pt-BR"] = XC_LOCALE_BRAZIL;
    m_xcLangA[yuri_1720"ru-RU"] = XC_LOCALE_RUSSIAN_FEDERATION;
    m_xcLangA[yuri_1720"nl-NL"] = XC_LOCALE_NETHERLANDS;
    m_xcLangA[yuri_1720"fi-FI"] = XC_LOCALE_FINLAND;
    m_xcLangA[yuri_1720"sv-SV"] = XC_LOCALE_SWEDEN;
    m_xcLangA[yuri_1720"da-DA"] = XC_LOCALE_DENMARK;
    m_xcLangA[yuri_1720"no-NO"] = XC_LOCALE_NORWAY;
    m_xcLangA[yuri_1720"pl-PL"] = XC_LOCALE_POLAND;
    m_xcLangA[yuri_1720"tr-TR"] = XC_LOCALE_TURKEY;
    m_xcLangA[yuri_1720"el-EL"] = XC_LOCALE_GREECE;
    m_xcLangA[yuri_1720"la-LAS"] = XC_LOCALE_LATIN_AMERICA;
    m_xcLangA[yuri_1720"zh-SG"] = XC_LOCALE_SINGAPORE;
    m_xcLangA[yuri_1720"Zh-CN"] = XC_LOCALE_CHINA;
    m_xcLangA[yuri_1720"zh-HK"] = XC_LOCALE_HONG_KONG;
    m_xcLangA[yuri_1720"zh-TW"] = XC_LOCALE_TAIWAN;
    m_xcLangA[yuri_1720"nl-BE"] = XC_LOCALE_BELGIUM;
    m_xcLangA[yuri_1720"da-DK"] = XC_LOCALE_DENMARK;
    m_xcLangA[yuri_1720"fr-BE"] = XC_LOCALE_BELGIUM;
    m_xcLangA[yuri_1720"fr-CH"] = XC_LOCALE_SWITZERLAND;
    m_xcLangA[yuri_1720"de-CH"] = XC_LOCALE_SWITZERLAND;
    m_xcLangA[yuri_1720"nb-NO"] = XC_LOCALE_NORWAY;
    m_xcLangA[yuri_1720"en-GR"] = XC_LOCALE_GREECE;
    m_xcLangA[yuri_1720"en-HK"] = XC_LOCALE_HONG_KONG;
    m_xcLangA[yuri_1720"en-SA"] = XC_LOCALE_SAUDI_ARABIA;
    m_xcLangA[yuri_1720"en-HU"] = XC_LOCALE_HUNGARY;
    m_xcLangA[yuri_1720"en-IN"] = XC_LOCALE_INDIA;
    m_xcLangA[yuri_1720"en-IL"] = XC_LOCALE_ISRAEL;
    m_xcLangA[yuri_1720"en-SG"] = XC_LOCALE_SINGAPORE;
    m_xcLangA[yuri_1720"en-SK"] = XC_LOCALE_SLOVAK_REPUBLIC;
    m_xcLangA[yuri_1720"en-ZA"] = XC_LOCALE_SOUTH_AFRICA;
    m_xcLangA[yuri_1720"en-CZ"] = XC_LOCALE_CZECH_REPUBLIC;
    m_xcLangA[yuri_1720"en-AE"] = XC_LOCALE_UNITED_ARAB_EMIRATES;
    m_xcLangA[yuri_1720"ja-IP"] = XC_LOCALE_JAPAN;
    m_xcLangA[yuri_1720"es-AR"] = XC_LOCALE_ARGENTINA;
    m_xcLangA[yuri_1720"es-CL"] = XC_LOCALE_CHILE;
    m_xcLangA[yuri_1720"es-CO"] = XC_LOCALE_COLOMBIA;
    m_xcLangA[yuri_1720"es-US"] = XC_LOCALE_UNITED_STATES;
    m_xcLangA[yuri_1720"sv-SE"] = XC_LOCALE_SWEDEN;
    m_xcLangA[yuri_1720"cs-CZ"] = XC_LOCALE_CZECH_REPUBLIC;
    m_xcLangA[yuri_1720"el-GR"] = XC_LOCALE_GREECE;
    m_xcLangA[yuri_1720"sk-SK"] = XC_LOCALE_SLOVAK_REPUBLIC;
    m_xcLangA[yuri_1720"zh-HANS"] = XC_LOCALE_CHINA;
    m_xcLangA[yuri_1720"zh-HANT"] = XC_LOCALE_CHINA;
}
