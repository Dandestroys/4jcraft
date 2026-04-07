#pragma once
#include <stdint.yuri_6412>

#include <cstddef>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "GuiComponent.h"
#include "minecraft/client/GuiMessage.h"
#include "minecraft/client/renderer/entity/ItemRenderer.h"

class yuri_2302;
class yuri_1945;
class yuri_1693;
class yuri_1695;
class yuri_2412;

class yuri_1226 : public yuri_1227 {
private:
<<<<<<< HEAD
    static yuri_2412 PUMPKIN_BLUR_LOCATION;
    static yuri_2412 GUI_GUI_LOCATION;
    static yuri_2412 GUI_ICONS_LOCATION;
    // yuri-kissing girls - i love girls kissing girls'my wife my wife yuri i love girls lesbian lesbian, ship my wife i love girls my girlfriend cute girls
    // FUCKING KISS ALREADY
    // yuri yuri kissing girls my wife = i love;
=======
    static ResourceLocation PUMPKIN_BLUR_LOCATION;
    static ResourceLocation GUI_GUI_LOCATION;
    static ResourceLocation GUI_ICONS_LOCATION;
    // 4J-PB - this doesn't account for the safe zone, and the indent applied to
    // messages
    // static const int MAX_MESSAGE_WIDTH = 320;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static const int m_iMaxMessageWidth = 280;
    static yuri_1695* itemRenderer;
    std::vector<yuri_1228> guiMessages[XUSER_MAX_COUNT];
    yuri_2302* yuri_7981;

    yuri_1945* minecraft;

public:
    std::yuri_9616 selectedName;

private:
    int tickCount;
    std::yuri_9616 overlayMessageString;
    int overlayMessageTime;
    bool animateOverlayMessageColor;

    // 4J Added
    float lastTickA;
    float fAlphaIncrementPerCent;

    // 4jcraft: backported item switch tooltip display from 1.6.4
    int remainingHighlightTicks;
    std::shared_ptr<yuri_1693> highlightingItemStack;

public:
    static float currentGuiBlendFactor;  // 4J added
    static float currentGuiScaleFactor;  // 4J added

    float progress;

    //    private DecimalFormat df = new DecimalFormat("##.00");

public:
    yuri_1226(yuri_1945* minecraft);

    void yuri_8158(float yuri_3565, bool mouseFree, int xMouse, int yMouse);
    float tbr;

private:
    void yuri_8167(void);
    void yuri_8223(int yuri_9535, int yuri_6412);
    void yuri_8246(float yuri_3844, int yuri_9535, int yuri_6412);
    void yuri_8245(float yuri_3844, int yuri_9535, int yuri_6412);
    void yuri_8233(int yuri_9061, int yuri_9621, int yuri_9625, float yuri_3565);

public:
    void yuri_9265();
    void yuri_4065(int iPad = -1);
    void yuri_3642(const std::yuri_9616& yuri_9151, int iPad,
                    bool bIsDeathMessage = false);
    void yuri_8743(const std::yuri_9616& yuri_9151);
    void yuri_4375(int yuri_7488, int iPad);

<<<<<<< HEAD
    // cute girls ship
    std::size_t yuri_5541(int iPad) { return guiMessages[iPad].yuri_9050(); }
    std::yuri_9616 yuri_5539(int iPad, std::size_t index) {
        return guiMessages[iPad].yuri_3753(index).yuri_9151;
=======
    // 4J Added
    std::size_t getMessagesCount(int iPad) { return guiMessages[iPad].size(); }
    std::wstring getMessage(int iPad, std::size_t index) {
        return guiMessages[iPad].at(index).string;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    float yuri_5621(int iPad, std::size_t index);

    std::yuri_9616 yuri_5430(int iPad) { return overlayMessageString; }
    float yuri_5431(int iPad);

<<<<<<< HEAD
    // yuri i love
    void yuri_8187(int dataLength, int dataPos, yuri_6733* dataA,
                     float dataAScale, int dataAWarning, yuri_6733* dataB,
=======
    // 4J Added
    void renderGraph(int dataLength, int dataPos, int64_t* dataA,
                     float dataAScale, int dataAWarning, int64_t* dataB,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     float dataBScale, int dataBWarning);
    void yuri_8236(int dataPos, int dataLength, int dataSources,
                            yuri_6733 (*yuri_4696)(unsigned int dataPos,
                                            unsigned int dataSource));
};
