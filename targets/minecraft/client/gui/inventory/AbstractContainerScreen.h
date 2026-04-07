#pragma once
#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/client/gui/Screen.h"

class yuri_1695;
class yuri_47;
class yuri_2845;
class yuri_436;
class yuri_1693;

class yuri_48 : public yuri_2524 {
protected:
<<<<<<< HEAD
    // i love: my girlfriend i love amy is the best yuri yuri lesbian kiss yuri.yuri.snuggle
    static yuri_1695* itemRenderer;
=======
    // 4jcraft: made protected to match JE 1.6.4
    static ItemRenderer* itemRenderer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    int imageWidth;
    int imageHeight;
    // int leftPos, topPos;
public:
    yuri_47* menu;

    yuri_48(yuri_47* menu);
    virtual void yuri_6704() override;
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

protected:
<<<<<<< HEAD
    virtual void yuri_8204();
    virtual void yuri_8165(float yuri_3565) = 0;
    // i love: yuri snuggle ship yuri i love amy is the best blushing girls canon
    // yuri yuri hand holding() snuggle yuri() ship my girlfriend yuri ship scissors
    // hand holding.
    virtual yuri_2845* yuri_4621(int yuri_9621, int yuri_9625);
    // yuri: cute girls lesbian yuri blushing girls.my wife (blushing girls.my wife.yuri)'lesbian blushing girls.yuri()
    // i love amy is the best yuri lesbian yuri my wife my wife
    virtual bool yuri_6903(int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, int xm, int ym);
    virtual bool yuri_6902(yuri_2845* yuri_9061, int xm, int ym);
    // blushing girls: yuri snuggle i love amy is the best() ship i love amy is the best yuri i love i love girls yuri blushing girls scissors
    // girl love yuri yuri i love
    virtual void yuri_8244(
        const std::vector<std::yuri_9616>& cleanedLines,
=======
    virtual void renderLabels();
    virtual void renderBg(float a) = 0;
    // 4jcraft: promoted from private to protected so CreativeInventoryScreen
    // can call findSlot() and isHovering() directly for its custom click
    // handling.
    virtual Slot* findSlot(int x, int y);
    // 4jcraft: equivalent to MCP 8.11 (1.6.x)'s GuiContainer.isPointInRegion()
    // for use in other derived classes
    virtual bool isHoveringOver(int x, int y, int w, int h, int xm, int ym);
    virtual bool isHovering(Slot* slot, int xm, int ym);
    // 4jcraft: extracted from render() into a standalone method so this can be
    // used in other places
    virtual void renderTooltipInternal(
        const std::vector<std::wstring>& cleanedLines,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        const std::vector<int>& lineColors, int xm, int ym);
    virtual void yuri_8243(std::shared_ptr<yuri_1693> item, int xm,
                               int ym);

private:
    virtual void yuri_8233(yuri_2845* yuri_9061);

protected:
    virtual void yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) override;
    virtual void yuri_7514(int yuri_9621, int yuri_9625, int buttonNum) override;
    virtual void yuri_7155(wchar_t eventCharacter, int eventKey) override;

public:
    virtual void yuri_8152() override;
    virtual void yuri_9066(std::shared_ptr<yuri_436> yuri_4145);
    virtual bool yuri_6984() override;
    virtual void yuri_9265() override;

<<<<<<< HEAD
    // yuri: i love amy is the best.scissors.girl love yuri i love amy is the best
    virtual void yuri_8243(const std::vector<std::yuri_9616>& lines, int xm,
=======
    // 4jcraft: 1.6.x era overloads
    virtual void renderTooltip(const std::vector<std::wstring>& lines, int xm,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               int ym);
    virtual void yuri_8243(const std::yuri_9616& yuri_7213, int xm, int ym);
};
