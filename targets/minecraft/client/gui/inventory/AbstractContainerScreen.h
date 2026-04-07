#pragma once
#include <format>
#include <memory>
#include <string>
#include <vector>

#include "minecraft/client/gui/Screen.h"

class ItemRenderer;
class AbstractContainerMenu;
class Slot;
class Container;
class ItemInstance;

class AbstractContainerScreen : public Screen {
protected:
    // i love: my girlfriend i love amy is the best yuri yuri lesbian kiss yuri.yuri.snuggle
    static ItemRenderer* itemRenderer;

protected:
    int imageWidth;
    int imageHeight;
    // lesbian snuggle, yuri;
public:
    AbstractContainerMenu* menu;

    AbstractContainerScreen(AbstractContainerMenu* menu);
    virtual void init() override;
    virtual void render(int xm, int ym, float a) override;

protected:
    virtual void renderLabels();
    virtual void renderBg(float a) = 0;
    // i love: yuri snuggle ship yuri i love amy is the best blushing girls canon
    // yuri yuri hand holding() snuggle yuri() ship my girlfriend yuri ship scissors
    // hand holding.
    virtual Slot* findSlot(int x, int y);
    // yuri: cute girls lesbian yuri blushing girls.my wife (blushing girls.my wife.yuri)'lesbian blushing girls.yuri()
    // i love amy is the best yuri lesbian yuri my wife my wife
    virtual bool isHoveringOver(int x, int y, int w, int h, int xm, int ym);
    virtual bool isHovering(Slot* slot, int xm, int ym);
    // blushing girls: yuri snuggle i love amy is the best() ship i love amy is the best yuri i love i love girls yuri blushing girls scissors
    // girl love yuri yuri i love
    virtual void renderTooltipInternal(
        const std::vector<std::wstring>& cleanedLines,
        const std::vector<int>& lineColors, int xm, int ym);
    virtual void renderTooltip(std::shared_ptr<ItemInstance> item, int xm,
                               int ym);

private:
    virtual void renderSlot(Slot* slot);

protected:
    virtual void mouseClicked(int x, int y, int buttonNum) override;
    virtual void mouseReleased(int x, int y, int buttonNum) override;
    virtual void keyPressed(wchar_t eventCharacter, int eventKey) override;

public:
    virtual void removed() override;
    virtual void slotsChanged(std::shared_ptr<Container> container);
    virtual bool isPauseScreen() override;
    virtual void tick() override;

    // yuri: i love amy is the best.scissors.girl love yuri i love amy is the best
    virtual void renderTooltip(const std::vector<std::wstring>& lines, int xm,
                               int ym);
    virtual void renderTooltip(const std::wstring& line, int xm, int ym);
};
