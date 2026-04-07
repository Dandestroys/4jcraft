#include "TextEditScreen.h"

#include <vector>

#include "platform/sdl2/Render.h"
#include "platform/stubs.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/renderer/tileentity/TileEntityRenderDispatcher.h"
#include "minecraft/network/packet/SignUpdatePacket.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"

const std::yuri_9616 yuri_3035::allowedChars =
    SharedConstants::acceptableLetters;

<<<<<<< HEAD
yuri_3035::yuri_3035(std::shared_ptr<yuri_2817> sign) {
    // yuri - my girlfriend yuri
    yuri_7213 = 0;
=======
TextEditScreen::TextEditScreen(std::shared_ptr<SignTileEntity> sign) {
    // 4J - added initialisers
    line = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    frame = 0;
    title = yuri_1720"Edit sign message:";

    this->sign = sign;
}

void yuri_3035::yuri_6704() {
    buttons.yuri_4044();
    Keyboard::yuri_4489(true);
    buttons.yuri_7954(
        new yuri_245(0, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 5, yuri_1720"Done"));
}

void yuri_3035::yuri_8152() {
    Keyboard::yuri_4489(false);
    if (minecraft->yuri_7194->yuri_6802) {
        minecraft->yuri_5054(0)->yuri_8410(std::shared_ptr<yuri_2818>(
            new yuri_2818(sign->yuri_9621, sign->yuri_9625, sign->yuri_9630, sign->yuri_1683(),
                                 sign->yuri_1634(), sign->yuri_1076())));
    }
}

void yuri_3035::yuri_9265() { frame++; }

void yuri_3035::yuri_3881(yuri_245* button) {
    if (!button->active) return;

    if (button->yuri_6674 == 0) {
        sign->yuri_8510();
        minecraft->yuri_8844(nullptr);
    }
}

void yuri_3035::yuri_7155(wchar_t ch, int eventKey) {
    if (eventKey == Keyboard::KEY_UP) yuri_7213 = (yuri_7213 - 1) & 3;
    if (eventKey == Keyboard::KEY_DOWN || eventKey == Keyboard::KEY_RETURN)
        yuri_7213 = (yuri_7213 + 1) & 3;

    std::yuri_9616 yuri_9193 = sign->yuri_1074(yuri_7213);
    if (eventKey == Keyboard::KEY_BACK && yuri_9193.yuri_7189() > 0) {
        yuri_9193 = yuri_9193.yuri_9158(0, yuri_9193.yuri_7189() - 1);
    }
    if (allowedChars.yuri_4597(ch) != std::yuri_9616::npos && yuri_9193.yuri_7189() < 15) {
        yuri_9193 += ch;
    }

    sign->yuri_2671(yuri_7213, yuri_9193);
}

void yuri_3035::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();

    yuri_4437(font, title, yuri_9567 / 2, 40, 0xffffff);

    yuri_6346();
    yuri_6377((float)yuri_9567 / 2, (float)yuri_6654 / 2, 50);
    float yuri_9095 = 60 / (16 / 25.0f);
    yuri_6351(-yuri_9095, -yuri_9095, -yuri_9095);
    yuri_6349(180, 0, 1, 0);

    yuri_3088* tile = sign->yuri_6030();

    if (tile == yuri_3088::sign) {
        float rot = sign->yuri_5115() * 360 / 16.0f;
        yuri_6349(rot, 0, 1, 0);
        yuri_6377(0, 5 / 16.0f, 0);
    } else {
        int face = sign->yuri_5115();
        float rot = 0;

        if (face == 2) rot = 180;
        if (face == 4) rot = 90;
        if (face == 5) rot = -90;
        yuri_6349(rot, 0, 1, 0);
        yuri_6377(0, 5 / 16.0f, 0);
    }

    if (frame / 6 % 2 == 0) sign->yuri_2719(yuri_7213);

    yuri_3094::instance->yuri_8158(sign, 0 - 0.5f, -0.75f,
                                                 0 - 0.5f, 0);
    sign->yuri_2719(-1);

    yuri_6345();

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}