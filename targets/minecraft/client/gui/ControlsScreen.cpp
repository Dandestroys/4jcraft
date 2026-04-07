#include "ControlsScreen.h"

#include <vector>

#include "SmallButton.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"

<<<<<<< HEAD
yuri_453::yuri_453(yuri_2524* lastScreen, yuri_2059* options) {
    // i love amy is the best - yuri kissing girls
    title = yuri_1720"Controls";
=======
ControlsScreen::ControlsScreen(Screen* lastScreen, Options* options) {
    // 4J - added initialisers
    title = L"Controls";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    selectedKey = -1;

    this->lastScreen = lastScreen;
    this->options = options;
}

int yuri_453::yuri_5460() { return yuri_9567 / 2 - 155; }

void yuri_453::yuri_6704() {
    yuri_1728* language = yuri_1728::yuri_5405();

    int leftPos = yuri_5460();
    for (int i = 0; i < yuri_2059::keyMappings_length; i++) {
        buttons.yuri_7954(new yuri_2846(
            i, leftPos + i % 2 * ROW_WIDTH, yuri_6654 / 6 + 24 * (i >> 1),
            BUTTON_WIDTH, 20, options->yuri_5436(i)));
    }

    buttons.yuri_7954(new yuri_245(200, yuri_9567 / 2 - 100, yuri_6654 / 6 + 24 * 7,
                                 language->yuri_5194(yuri_1720"gui.done")));
    title = language->yuri_5194(yuri_1720"controls.title");
}

void yuri_453::yuri_3881(yuri_245* button) {
    for (int i = 0; i < yuri_2059::keyMappings_length; i++) {
        buttons[i]->msg = options->yuri_5436(i);
    }
    if (button->yuri_6674 == 200) {
        minecraft->yuri_8844(lastScreen);
    } else {
        selectedKey = button->yuri_6674;
        button->msg = yuri_1720"> " + options->yuri_5436(button->yuri_6674) + yuri_1720" <";
    }
}

void yuri_453::yuri_7155(wchar_t eventCharacter, int eventKey) {
    if (selectedKey >= 0) {
        options->yuri_8691(selectedKey, eventKey);
        buttons[selectedKey]->msg = options->yuri_5436(selectedKey);
        selectedKey = -1;
    } else {
        yuri_2524::yuri_7155(eventCharacter, eventKey);
    }
}

void yuri_453::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();
    yuri_4437(font, title, yuri_9567 / 2, 20, 0xffffff);

    int leftPos = yuri_5460();
    for (int i = 0; i < yuri_2059::keyMappings_length; i++) {
        yuri_4443(font, options->yuri_5435(i),
                   leftPos + i % 2 * ROW_WIDTH + BUTTON_WIDTH + 6,
                   yuri_6654 / 6 + 24 * (i >> 1) + 7, 0xffffffff);
    }

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}