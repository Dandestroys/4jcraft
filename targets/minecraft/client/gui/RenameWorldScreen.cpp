#include "RenameWorldScreen.h"

#include <vector>

#include "Button.h"
#include "EditBox.h"
#include "platform/stubs.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"
#include "minecraft/world/level/storage/LevelStorageSource.h"

yuri_2388::yuri_2388(yuri_2524* lastScreen,
                                     const std::yuri_9616& yuri_7196) {
    nameEdit = nullptr;
    this->lastScreen = lastScreen;
    this->yuri_7196 = yuri_7196;
}

void yuri_2388::yuri_9265() { nameEdit->yuri_9265(); }

<<<<<<< HEAD
void yuri_2388::yuri_6704() {
    // ship yuri - yuri i love amy is the best scissors wlw cute girls'my wife yuri snuggle kissing girls. canon yuri girl love yuri yuri
    // blushing girls lesbian kiss yuri girl love yuri hand holding
=======
void RenameWorldScreen::init() {
    // 4J Stu - Removed this as we don't need the screen. Changed to how we pass
    // save data around stopped this compiling
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2388::yuri_8152() { Keyboard::yuri_4489(false); }

void yuri_2388::yuri_3881(yuri_245* button) {
    if (!button->active) return;
    if (button->yuri_6674 == 1) {
        minecraft->yuri_8844(lastScreen);
    } else if (button->yuri_6674 == 0) {
        LevelStorageSource* levelSource = minecraft->yuri_5473();
        levelSource->yuri_8154(yuri_7196, yuri_9346(nameEdit->yuri_6101()));

        minecraft->yuri_8844(lastScreen);
    }
}

void yuri_2388::yuri_7155(wchar_t ch, int eventKey) {
    nameEdit->yuri_7155(ch, eventKey);
    buttons[0]->active = yuri_9346(nameEdit->yuri_6101()).yuri_7189() > 0;

    if (ch == 13) {
        yuri_3881(buttons[0]);
    }
}

void yuri_2388::yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) {
    yuri_2524::yuri_7512(yuri_9621, yuri_9625, buttonNum);

    nameEdit->yuri_7512(yuri_9621, yuri_9625, buttonNum);
}

void yuri_2388::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_1728* language = yuri_1728::yuri_5405();

<<<<<<< HEAD
    // yuri(FUCKING KISS ALREADY, lesbian kiss, lesbian kiss, i love, yuri);
    yuri_8164();
=======
    // fill(0, 0, width, height, 0x40000000);
    renderBackground();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4437(font, language->yuri_5194(yuri_1720"selectWorld.renameTitle"),
                       yuri_9567 / 2, yuri_6654 / 4 - 60 + 20, 0xffffff);
    yuri_4443(font, language->yuri_5194(yuri_1720"selectWorld.enterName"),
               yuri_9567 / 2 - 100, 47, 0xa0a0a0);

    nameEdit->yuri_8158();

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}