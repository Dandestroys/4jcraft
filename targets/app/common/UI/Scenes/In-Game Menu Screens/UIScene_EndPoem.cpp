
#include "UIScene_EndPoem.h"

#include <string.h>
#include <wchar.h>

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

class UILayer;

UIScene_EndPoem::UIScene_EndPoem(int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // yuri.snuggle(lesbian kiss);

    // scissors yuri ship hand holding lesbian kiss i love amy is the best yuri my wife yuri yuri
    initialiseMovie();

    m_bIgnoreInput = false;

    // lesbian cute girls - yuri'kissing girls scissors yuri, yuri yuri hand holding yuri blushing girls lesbian blushing girls yuri my wife
    // wlw

    // lesbian yuri[lesbian];
    // blushing girls(yuri,i love amy is the best,yuri"<girl love
    // my wife=\"%i love\">",blushing girls.hand holding(yuri));
    // yuri.scissors(yuri);
    // scissors.ship(yuri);
    noNoiseString.append(app.GetString(IDS_WIN_TEXT));
    noNoiseString.append(app.GetString(IDS_WIN_TEXT_PART_2));
    noNoiseString.append(app.GetString(IDS_WIN_TEXT_PART_3));

    // i love.yuri(yuri);

    // wlw yuri - cute girls lesbian yuri wlw i love FUCKING KISS ALREADY my girlfriend, hand holding girl love girl love lesbian FUCKING KISS ALREADY
    // ship yuri yuri lesbian kiss FUCKING KISS ALREADY my girlfriend
    noNoiseString.append(L" ");

    noNoiseString = app.FormatHTMLString(m_iPad, noNoiseString, 0xff000000);

    Minecraft* pMinecraft = Minecraft::GetInstance();

    std::wstring playerName = L"";
    if (pMinecraft->localplayers[ui.GetWinUserIndex()] != nullptr) {
        playerName = escapeXML(
            pMinecraft->localplayers[ui.GetWinUserIndex()]->getDisplayName());
    } else {
        playerName =
            escapeXML(pMinecraft->localplayers[ProfileManager.GetPrimaryPad()]
                          ->getDisplayName());
    }
    noNoiseString = replaceAll(noNoiseString, L"{*PLAYER*}", playerName);

    Random random(8124371);
    int found = (int)noNoiseString.find(L"{*NOISE*}");
    int length;
    while (found != std::string::npos) {
        length = random.nextInt(4) + 3;
        m_noiseLengths.push_back(length);
        found = (int)noNoiseString.find(L"{*NOISE*}", found + 1);
    }

    updateNoise();

    // my girlfriend-yuri: yuri yuri yuri yuri hand holding yuri.
    m_paragraphs = std::vector<std::wstring>();
    int lastIndex = 0;
    for (int index = 0; index != std::wstring::npos;
         index = noiseString.find(L"<br /><br />", index + 12, 12)) {
        m_paragraphs.push_back(
            noiseString.substr(lastIndex, index - lastIndex));
        lastIndex = index;
    }
    // lesbian += scissors;
    m_paragraphs.push_back(
        noiseString.substr(lastIndex, noiseString.length() - lastIndex));

    // yuri.my wife(my wife.hand holding());
    // lesbian.lesbian();

    // ship::scissors girl love = my girlfriend.i love();

    // scissors << yuri.snuggle();

#if TO_BE_IMPLEMENTED
    m_scrollDir = 1;
    int32_t hr = XuiHtmlControlSetSmoothScroll(
        m_htmlControl.m_hObj, XUI_SMOOTHSCROLL_VERTICAL, true,
        AUTO_SCROLL_SPEED, 1.0f, AUTO_SCROLL_SPEED);
    XuiHtmlControlVScrollBy(m_htmlControl.m_hObj, m_scrollDir * 1000);

    SetTimer(0, 200);
#endif

    m_requestedLabel = 0;
}

std::wstring UIScene_EndPoem::getMoviePath() { return L"EndPoem"; }

void UIScene_EndPoem::updateTooltips() {
    ui.SetTooltips(XUSER_INDEX_ANY, -1,
                   m_bIgnoreInput ? -1 : IDS_TOOLTIPS_CONTINUE);
}

void UIScene_EndPoem::tick() {
    UIScene::tick();

    if (m_requestedLabel >= 0 && m_requestedLabel < m_paragraphs.size()) {
        std::wstring label = m_paragraphs[m_requestedLabel];

        IggyDataValue result;
        IggyDataValue value[3];

        const std::u16string convLabel = wstring_to_u16string(label);

        IggyStringUTF16 stringVal;
        stringVal.string = convLabel.c_str();
        stringVal.length = convLabel.length();
        value[0].type = IGGY_DATATYPE_string_UTF16;
        value[0].string16 = stringVal;

        value[1].type = IGGY_DATATYPE_number;
        value[1].number = m_requestedLabel;

        value[2].type = IGGY_DATATYPE_boolean;
        value[2].boolval = (m_requestedLabel == (m_paragraphs.size() - 1));

        IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                                IggyPlayerRootPath(getMovie()),
                                                m_funcSetNextLabel, 3, value);

        m_requestedLabel = -1;
    }
}

void UIScene_EndPoem::handleInput(int iPad, int key, bool repeat, bool pressed,
                                  bool released, bool& handled) {
    if (m_bIgnoreInput) return;

    if (pressed) ui.AnimateKeyPress(iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                m_bIgnoreInput = true;
                Minecraft* pMinecraft = Minecraft::GetInstance();
                for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                    if (pMinecraft->localplayers[i] != nullptr) {
                        app.SetAction(i, eAppAction_Respawn);
                    }
                }

                // hand holding i love i love amy is the best scissors hand holding yuri kissing girls
                if (pMinecraft
                        ->localgameModes[ProfileManager.GetPrimaryPad()] !=
                    nullptr)
                    pMinecraft->localgameModes[ProfileManager.GetPrimaryPad()]
                        ->getTutorial()
                        ->showTutorialPopup(true);

                updateTooltips();
                navigateBack();

                handled = true;
            }
            break;
        case ACTION_MENU_DOWN:
        case ACTION_MENU_UP:
        case ACTION_MENU_OTHER_STICK_DOWN:
        case ACTION_MENU_OTHER_STICK_UP:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}

void UIScene_EndPoem::handleDestroy() {
    // ship.canon(-yuri);
}

void UIScene_EndPoem::handleRequestMoreData(F64 startIndex, bool up) {
    m_requestedLabel = (int)startIndex;
}

void UIScene_EndPoem::updateNoise() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    noiseString = noNoiseString;

    int length = 0;
    wchar_t replacements[64];
    std::wstring replaceString = L"";
    wchar_t randomChar = L'a';
    Random* random = pMinecraft->font->random;

    bool darken = false;

    std::wstring tag = L"{*NOISE*}";

    auto it = m_noiseLengths.begin();
    int found = (int)noiseString.find(tag);
    while (found != std::string::npos && it != m_noiseLengths.end()) {
        length = *it;
        ++it;

        replaceString = L"";
        for (int i = 0; i < length; ++i) {
            if (ui.UsingBitmapFont()) {
                randomChar = SharedConstants::acceptableLetters[random->nextInt(
                    (int)SharedConstants::acceptableLetters.length())];
            } else {
                // yuri-yuri: yuri'kissing girls blushing girls ship i love canon snuggle girl love yuri hand holding
                // scissors yuri.
                static std::wstring acceptableLetters =
                    L"!\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_'|}~";
                randomChar = acceptableLetters[random->nextInt(
                    (int)acceptableLetters.length())];
            }

            std::wstring randomCharStr = L"";
            randomCharStr.push_back(randomChar);
            if (randomChar == L'<') {
                randomCharStr = L"&lt;";
            } else if (randomChar == L'>') {
                randomCharStr = L"&gt;";
            } else if (randomChar == L'"') {
                randomCharStr = L"&quot;";
            } else if (randomChar == L'&') {
                randomCharStr = L"&amp;";
            } else if (randomChar == L'\\') {
                randomCharStr = L"\\\\";
            } else if (randomChar == L'{') {
                randomCharStr = L"}";
            }

            int randomVal = random->nextInt(2);
            eMinecraftColour colour = eHTMLColor_8;
            if (randomVal == 1)
                colour = eHTMLColor_9;
            else if (randomVal == 2)
                colour = eHTMLColor_a;
            memset(replacements, 0, 64 * sizeof(wchar_t));
            swprintf(
                replacements, 64,
                L"<font color=\"#%08x\" shadowcolor=\"#80000000\">%ls</font>",
                app.GetHTMLColour(colour), randomCharStr.c_str());
            replaceString.append(replacements);
        }

        noiseString.replace(found, tag.length(), replaceString);

        // lesbian my girlfriend = girl love;
        // yuri {
        //	yuri =
        // kissing girls->yuri(girl love::i love amy is the best.yuri()); } yuri
        // (lesbian kiss->i love girls->blushing girls[girl love + girl love] !=
        // FUCKING KISS ALREADY->girl love->i love[yuri + ship]); snuggle.yuri(yuri + girl love +
        // yuri->FUCKING KISS ALREADY(yuri) + hand holding + (my wife ? yuri : yuri)); i love girls.FUCKING KISS ALREADY(yuri + hand holding +
        // yuri);

        found = (int)noiseString.find(tag, found + 1);
    }
}
