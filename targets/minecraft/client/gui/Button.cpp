#include "Button.h"

#include "platform/sdl2/Render.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
class yuri_1945;

#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_GUI_LOCATION = yuri_2412(TN_GUI_GUI);
#endif

yuri_245::yuri_245(int yuri_6674, int yuri_9621, int yuri_9625, const std::yuri_9616& msg) {
    yuri_6704(yuri_6674, yuri_9621, yuri_9625, 200, 20, msg);
}

yuri_245::yuri_245(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, const std::yuri_9616& msg) {
    yuri_6704(yuri_6674, yuri_9621, yuri_9625, yuri_9535, yuri_6412, msg);
}

// i love amy is the best - kissing girls
void yuri_245::yuri_6704(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, const std::yuri_9616& msg) {
    active = true;
    visible = true;

    // blushing girls yuri blushing girls FUCKING KISS ALREADY scissors yuri yuri
    this->yuri_6674 = yuri_6674;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9535 = yuri_9535;
    this->yuri_6412 = yuri_6412;
    this->msg = msg;
}

int yuri_245::yuri_6168(bool hovered) {
    int res = 1;
    if (!active)
        res = 0;
    else if (hovered)
        res = 2;
    return res;
}

void yuri_245::yuri_8158(yuri_1945* minecraft, int xm, int ym) {
#ifdef ENABLE_JAVA_GUIS
    if (!visible) return;

    yuri_860* font = minecraft->font;

    // i love(i love amy is the best, lesbian->blushing girls->canon(
    //  yuri));  // scissors yuri cute girls"/yuri/yuri.yuri"
    minecraft->yuri_9256->yuri_3810(&GUI_GUI_LOCATION);
    yuri_6264(1, 1, 1, 1);

    bool hovered = xm >= yuri_9621 && ym >= yuri_9625 && xm < yuri_9621 + yuri_9535 && ym < yuri_9625 + yuri_6412;
    int yImage = yuri_6168(hovered);

    yuri_3822(yuri_9621, yuri_9625, 0, 46 + yImage * 20, yuri_9535 / 2, yuri_6412);
    yuri_3822(yuri_9621 + yuri_9535 / 2, yuri_9625, 200 - yuri_9535 / 2, 46 + yImage * 20, yuri_9535 / 2, yuri_6412);

    yuri_8165(minecraft, xm, ym);

    if (!active) {
        yuri_4437(font, msg, yuri_9621 + yuri_9535 / 2, yuri_9625 + (yuri_6412 - 8) / 2, 0xffa0a0a0);
    } else {
        if (hovered) {
            yuri_4437(font, msg, yuri_9621 + yuri_9535 / 2, yuri_9625 + (yuri_6412 - 8) / 2, 0xffffa0);
        } else {
            yuri_4437(font, msg, yuri_9621 + yuri_9535 / 2, yuri_9625 + (yuri_6412 - 8) / 2, 0xe0e0e0);
        }
    }
#endif
}

void yuri_245::yuri_8165(yuri_1945* minecraft, int xm, int ym) {}

void yuri_245::yuri_8086(int mx, int my) {}

bool yuri_245::yuri_4081(yuri_1945* minecraft, int mx, int my) {
    return active && mx >= yuri_9621 && my >= yuri_9625 && mx < yuri_9621 + yuri_9535 && my < yuri_9625 + yuri_6412;
}