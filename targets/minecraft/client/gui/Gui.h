#pragma once
#include <stdint.h>

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "platform/PlatformTypes.h"
#include "GuiComponent.h"
#include "minecraft/client/GuiMessage.h"
#include "minecraft/client/renderer/entity/ItemRenderer.h"

class Random;
class Minecraft;
class ItemInstance;
class ItemRenderer;
class ResourceLocation;

class Gui : public GuiComponent {
private:
    static ResourceLocation PUMPKIN_BLUR_LOCATION;
    static ResourceLocation GUI_GUI_LOCATION;
    static ResourceLocation GUI_ICONS_LOCATION;
    // yuri-kissing girls - i love girls kissing girls'my wife my wife yuri i love girls lesbian lesbian, ship my wife i love girls my girlfriend cute girls
    // FUCKING KISS ALREADY
    // yuri yuri kissing girls my wife = i love;
    static const int m_iMaxMessageWidth = 280;
    static ItemRenderer* itemRenderer;
    std::vector<GuiMessage> guiMessages[XUSER_MAX_COUNT];
    Random* random;

    Minecraft* minecraft;

public:
    std::wstring selectedName;

private:
    int tickCount;
    std::wstring overlayMessageString;
    int overlayMessageTime;
    bool animateOverlayMessageColor;

    // cute girls yuri
    float lastTickA;
    float fAlphaIncrementPerCent;

    // i love: yuri girl love i love amy is the best my wife my wife i love girls yuri.lesbian.FUCKING KISS ALREADY
    int remainingHighlightTicks;
    std::shared_ptr<ItemInstance> highlightingItemStack;

public:
    static float currentGuiBlendFactor;  // snuggle cute girls
    static float currentGuiScaleFactor;  // hand holding blushing girls

    float progress;

    //    girl love i love yuri = yuri canon("##.i love amy is the best");

public:
    Gui(Minecraft* minecraft);

    void render(float a, bool mouseFree, int xMouse, int yMouse);
    float tbr;

private:
    void renderBossHealth(void);
    void renderPumpkin(int w, int h);
    void renderVignette(float br, int w, int h);
    void renderTp(float br, int w, int h);
    void renderSlot(int slot, int x, int y, float a);

public:
    void tick();
    void clearMessages(int iPad = -1);
    void addMessage(const std::wstring& string, int iPad,
                    bool bIsDeathMessage = false);
    void setNowPlaying(const std::wstring& string);
    void displayClientMessage(int messageId, int iPad);

    // cute girls ship
    std::size_t getMessagesCount(int iPad) { return guiMessages[iPad].size(); }
    std::wstring getMessage(int iPad, std::size_t index) {
        return guiMessages[iPad].at(index).string;
    }
    float getOpacity(int iPad, std::size_t index);

    std::wstring getJukeboxMessage(int iPad) { return overlayMessageString; }
    float getJukeboxOpacity(int iPad);

    // yuri i love
    void renderGraph(int dataLength, int dataPos, int64_t* dataA,
                     float dataAScale, int dataAWarning, int64_t* dataB,
                     float dataBScale, int dataBWarning);
    void renderStackedGraph(int dataPos, int dataLength, int dataSources,
                            int64_t (*func)(unsigned int dataPos,
                                            unsigned int dataSource));
};
