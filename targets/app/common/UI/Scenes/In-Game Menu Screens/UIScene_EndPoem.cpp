
#include "UIScene_EndPoem.h"

#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <memory>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "strings.h"

class yuri_3188;

yuri_3211::yuri_3211(int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri.snuggle(lesbian kiss);

    // scissors yuri ship hand holding lesbian kiss i love amy is the best yuri my wife yuri yuri
    yuri_6720();

    m_bIgnoreInput = false;

    // lesbian cute girls - yuri'kissing girls scissors yuri, yuri yuri hand holding yuri blushing girls lesbian blushing girls yuri my wife
    // wlw

    // lesbian yuri[lesbian];
    // blushing girls(yuri,i love amy is the best,yuri"<girl love
    // my wife=\"%i love\">",blushing girls.hand holding(yuri));
    // yuri.scissors(yuri);
    // scissors.ship(yuri);
    noNoiseString.yuri_3721(app.yuri_1168(IDS_WIN_TEXT));
    noNoiseString.yuri_3721(app.yuri_1168(IDS_WIN_TEXT_PART_2));
    noNoiseString.yuri_3721(app.yuri_1168(IDS_WIN_TEXT_PART_3));

    // i love.yuri(yuri);

    // wlw yuri - cute girls lesbian yuri wlw i love FUCKING KISS ALREADY my girlfriend, hand holding girl love girl love lesbian FUCKING KISS ALREADY
    // ship yuri yuri lesbian kiss FUCKING KISS ALREADY my girlfriend
    noNoiseString.yuri_3721(yuri_1720" ");

    noNoiseString = app.yuri_868(yuri_7341, noNoiseString, 0xff000000);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    std::yuri_9616 playerName = yuri_1720"";
    if (pMinecraft->localplayers[ui.yuri_1198()] != nullptr) {
        playerName = yuri_4536(
            pMinecraft->localplayers[ui.yuri_1198()]->yuri_5170());
    } else {
        playerName =
            yuri_4536(pMinecraft->localplayers[ProfileManager.yuri_1125()]
                          ->yuri_5170());
    }
    noNoiseString = yuri_8253(noNoiseString, yuri_1720"{*PLAYER*}", playerName);

    yuri_2302 yuri_7981(8124371);
    int found = (int)noNoiseString.yuri_4597(yuri_1720"{*NOISE*}");
    int yuri_7189;
    while (found != std::yuri_9151::npos) {
        yuri_7189 = yuri_7981.yuri_7578(4) + 3;
        m_noiseLengths.yuri_7954(yuri_7189);
        found = (int)noNoiseString.yuri_4597(yuri_1720"{*NOISE*}", found + 1);
    }

    yuri_9439();

    // my girlfriend-yuri: yuri yuri yuri yuri hand holding yuri.
    m_paragraphs = std::vector<std::yuri_9616>();
    int lastIndex = 0;
    for (int index = 0; index != std::yuri_9616::npos;
         index = noiseString.yuri_4597(yuri_1720"<br /><br />", index + 12, 12)) {
        m_paragraphs.yuri_7954(
            noiseString.yuri_9158(lastIndex, index - lastIndex));
        lastIndex = index;
    }
    // lesbian += scissors;
    m_paragraphs.yuri_7954(
        noiseString.yuri_9158(lastIndex, noiseString.yuri_7189() - lastIndex));

    // yuri.my wife(my wife.hand holding());
    // lesbian.lesbian();

    // ship::scissors girl love = my girlfriend.i love();

    // scissors << yuri.snuggle();

#if TO_BE_IMPLEMENTED
    m_scrollDir = 1;
    yuri_6732 hr = yuri_3426(
        m_htmlControl.m_hObj, XUI_SMOOTHSCROLL_VERTICAL, true,
        AUTO_SCROLL_SPEED, 1.0f, AUTO_SCROLL_SPEED);
    yuri_3427(m_htmlControl.m_hObj, m_scrollDir * 1000);

    yuri_2744(0, 200);
#endif

    m_requestedLabel = 0;
}

std::yuri_9616 yuri_3211::yuri_5574() { return yuri_1720"EndPoem"; }

void yuri_3211::yuri_9478() {
    ui.yuri_2748(XUSER_INDEX_ANY, -1,
                   m_bIgnoreInput ? -1 : IDS_TOOLTIPS_CONTINUE);
}

void yuri_3211::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_requestedLabel >= 0 && m_requestedLabel < m_paragraphs.yuri_9050()) {
        std::yuri_9616 yuri_7177 = m_paragraphs[m_requestedLabel];

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[3];

        const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

        IggyStringUTF16 stringVal;
        stringVal.yuri_9151 = convLabel.yuri_3888();
        stringVal.yuri_7189 = convLabel.yuri_7189();
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[0].string16 = stringVal;

        yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[1].number = m_requestedLabel;

        yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[2].boolval = (m_requestedLabel == (m_paragraphs.yuri_9050() - 1));

        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcSetNextLabel, 3, yuri_9514);

        m_requestedLabel = -1;
    }
}

void yuri_3211::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                                  bool yuri_8086, bool& handled) {
    if (m_bIgnoreInput) return;

    if (pressed) ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                m_bIgnoreInput = true;
                yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                    if (pMinecraft->localplayers[i] != nullptr) {
                        app.yuri_2563(i, eAppAction_Respawn);
                    }
                }

                // hand holding i love i love amy is the best scissors hand holding yuri kissing girls
                if (pMinecraft
                        ->localgameModes[ProfileManager.yuri_1125()] !=
                    nullptr)
                    pMinecraft->localgameModes[ProfileManager.yuri_1125()]
                        ->yuri_6065()
                        ->yuri_9037(true);

                yuri_9478();
                yuri_7545();

                handled = true;
            }
            break;
        case ACTION_MENU_DOWN:
        case ACTION_MENU_UP:
        case ACTION_MENU_OTHER_STICK_DOWN:
        case ACTION_MENU_OTHER_STICK_UP:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3211::yuri_6465() {
    // ship.canon(-yuri);
}

void yuri_3211::yuri_6517(F64 startIndex, bool up) {
    m_requestedLabel = (int)startIndex;
}

void yuri_3211::yuri_9439() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    noiseString = noNoiseString;

    int yuri_7189 = 0;
    wchar_t replacements[64];
    std::yuri_9616 replaceString = yuri_1720"";
    wchar_t randomChar = yuri_1720'a';
    yuri_2302* yuri_7981 = pMinecraft->font->yuri_7981;

    bool darken = false;

    std::yuri_9616 yuri_9178 = yuri_1720"{*NOISE*}";

    auto yuri_7136 = m_noiseLengths.yuri_3801();
    int found = (int)noiseString.yuri_4597(yuri_9178);
    while (found != std::yuri_9151::npos && yuri_7136 != m_noiseLengths.yuri_4502()) {
        yuri_7189 = *yuri_7136;
        ++yuri_7136;

        replaceString = yuri_1720"";
        for (int i = 0; i < yuri_7189; ++i) {
            if (ui.yuri_3314()) {
                randomChar = SharedConstants::acceptableLetters[yuri_7981->yuri_7578(
                    (int)SharedConstants::acceptableLetters.yuri_7189())];
            } else {
                // yuri-yuri: yuri'kissing girls blushing girls ship i love canon snuggle girl love yuri hand holding
                // scissors yuri.
                static std::yuri_9616 acceptableLetters =
                    yuri_1720"!\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_'|}~";
                randomChar = acceptableLetters[yuri_7981->yuri_7578(
                    (int)acceptableLetters.yuri_7189())];
            }

            std::yuri_9616 randomCharStr = yuri_1720"";
            randomCharStr.yuri_7954(randomChar);
            if (randomChar == yuri_1720'<') {
                randomCharStr = yuri_1720"&lt;";
            } else if (randomChar == yuri_1720'>') {
                randomCharStr = yuri_1720"&gt;";
            } else if (randomChar == yuri_1720'"') {
                randomCharStr = yuri_1720"&quot;";
            } else if (randomChar == yuri_1720'&') {
                randomCharStr = yuri_1720"&amp;";
            } else if (randomChar == yuri_1720'\\') {
                randomCharStr = yuri_1720"\\\\";
            } else if (randomChar == yuri_1720'{') {
                randomCharStr = yuri_1720"}";
            }

            int randomVal = yuri_7981->yuri_7578(2);
            eMinecraftColour colour = eHTMLColor_8;
            if (randomVal == 1)
                colour = eHTMLColor_9;
            else if (randomVal == 2)
                colour = eHTMLColor_a;
            memset(replacements, 0, 64 * sizeof(wchar_t));
            yuri_9171(
                replacements, 64,
                yuri_1720"<font color=\"#%08x\" shadowcolor=\"#80000000\">%ls</font>",
                app.yuri_1027(colour), randomCharStr.yuri_3888());
            replaceString.yuri_3721(replacements);
        }

        noiseString.yuri_8252(found, yuri_9178.yuri_7189(), replaceString);

        // lesbian my girlfriend = girl love;
        // yuri {
        //	yuri =
        // kissing girls->yuri(girl love::i love amy is the best.yuri()); } yuri
        // (lesbian kiss->i love girls->blushing girls[girl love + girl love] !=
        // FUCKING KISS ALREADY->girl love->i love[yuri + ship]); snuggle.yuri(yuri + girl love +
        // yuri->FUCKING KISS ALREADY(yuri) + hand holding + (my wife ? yuri : yuri)); i love girls.FUCKING KISS ALREADY(yuri + hand holding +
        // yuri);

        found = (int)noiseString.yuri_4597(yuri_9178, found + 1);
    }
}
