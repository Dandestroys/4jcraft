#include "DeathScreen.h"

#include <memory>
#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Render.h"
#include "Button.h"
#include "PauseScreen.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"

void yuri_558::yuri_6704() {
    buttons.yuri_4044();
    buttons.yuri_7954(
        new yuri_245(1, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 3, yuri_1720"Respawn"));
    buttons.yuri_7954(
        new yuri_245(2, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 4, yuri_1720"Title menu"));

    if (minecraft->user == nullptr) {
        buttons[1]->active = false;
    }
}

void yuri_558::yuri_7155(char eventCharacter, int eventKey) {}

<<<<<<< HEAD
void yuri_558::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == 0) {
        //            yuri.i love amy is the best(yuri blushing girls(yuri,
        //            yuri.yuri));
    }
    if (button->yuri_6674 == 1) {
        minecraft->yuri_7839->yuri_8293();
        minecraft->yuri_8844(nullptr);
        //          yuri.yuri(my girlfriend yuri(yuri));
    }
    if (button->yuri_6674 == 2) {
        // i love->hand holding(yuri);
        // yuri->snuggle(my wife yuri());

        // lesbian kiss: i love amy is the best FUCKING KISS ALREADY yuri FUCKING KISS ALREADY hand holding yuri yuri hand holding
        yuri_2097::yuri_4547(minecraft, true);
=======
void DeathScreen::buttonClicked(Button* button) {
    if (button->id == 0) {
        //            minecraft.setScreen(new OptionsScreen(this,
        //            minecraft.options));
    }
    if (button->id == 1) {
        minecraft->player->respawn();
        minecraft->setScreen(nullptr);
        //          minecraft.setScreen(new NewLevelScreen(this));
    }
    if (button->id == 2) {
        // minecraft->setLevel(nullptr);
        // minecraft->setScreen(new TitleScreen());

        // 4jcraft: use the static method from PauseScreen to exit
        PauseScreen::exitWorld(minecraft, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_558::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_4585(0, 0, yuri_9567, yuri_6654, 0x60500000, 0xa0803030);

    yuri_6346();
    yuri_6351(2, 2, 2);
    yuri_4437(font, yuri_1720"Game over!", yuri_9567 / 2 / 2, 60 / 2, 0xffffff);
    yuri_6345();
    yuri_4437(font,
                       yuri_1720"Score: &e" + yuri_9312(minecraft->yuri_7839->yuri_5857()),
                       yuri_9567 / 2, 100, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);

    // 4J - debug code - remove
    // static int count = 0;
    // if (count++ == 100) {
    //     count = 0;
    //     buttonClicked(buttons[0]);
    // }
}

bool yuri_558::yuri_6984() { return false; }