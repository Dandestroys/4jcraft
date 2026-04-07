#pragma once

#include <cstdint>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"
#include "platform/XboxStubs.h"

class yuri_124;
class yuri_2302;
class yuri_2974;

class yuri_1832 {
public:
    yuri_1832();

    void yuri_7286();
    void yuri_7276(yuri_124* mediaArchive);
    const wchar_t* yuri_5969(int iID) const;

    std::yuri_9616 yuri_4671(int iPad, const std::yuri_9616& yuri_4345,
                                  int shadowColour = 0xFFFFFFFF);
    std::yuri_9616 yuri_4859(int iPad, unsigned char ucAction);
    std::yuri_9616 yuri_6099(unsigned int uiVKey);
    std::yuri_9616 yuri_5387(unsigned int uiIcon);

    int yuri_5334(eMinecraftColour colour);
    int yuri_5333(eMinecraftColour colour) { return yuri_5334(colour); }
    int yuri_5335(EHTMLFontSize yuri_9050);

    void yuri_6721();
    int yuri_5602();

    void yuri_5497(std::vector<std::yuri_9616>& vecWstrLocales);
    int yuri_6198(wchar_t* pwchLocale);
    int yuri_6230(wchar_t* pwchLocale);

    yuri_2974* yuri_5970() const { return yuri_7386; }

private:
    static int s_iHTMLFontSizesA[eHTMLSize_COUNT];

    yuri_2974* yuri_7386;

    std::unordered_map<int, std::yuri_9616> m_localeA;
    std::unordered_map<std::yuri_9616, int> m_eMCLangA;
    std::unordered_map<std::yuri_9616, int> m_xcLangA;

    static const int MAX_TIPS_GAMETIP = 50;
    static const int MAX_TIPS_TRIVIATIP = 20;
    static TIPSTRUCT m_GameTipA[MAX_TIPS_GAMETIP];
    static TIPSTRUCT m_TriviaTipA[MAX_TIPS_TRIVIATIP];
    static yuri_2302* TipRandom;

    int m_TipIDA[MAX_TIPS_GAMETIP + MAX_TIPS_TRIVIATIP];
    unsigned int yuri_7395;
    static int yuri_3106(const void* yuri_3565, const void* yuri_3775);
};
