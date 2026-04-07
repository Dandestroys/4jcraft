#include "ConfirmScreen.h"

#include <vector>

#include "SmallButton.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"

yuri_419::yuri_419(yuri_2524* yuri_7791, const std::yuri_9616& title1,
                             const std::yuri_9616& title2, int yuri_6674) {
    this->yuri_7791 = yuri_7791;
    this->title1 = title1;
    this->title2 = title2;
    this->yuri_6674 = yuri_6674;

    yuri_1728* language = yuri_1728::yuri_5405();
    yesButton = language->yuri_5194(yuri_1720"gui.yes");
    noButton = language->yuri_5194(yuri_1720"gui.no");
}

yuri_419::yuri_419(yuri_2524* yuri_7791, const std::yuri_9616& title1,
                             const std::yuri_9616& title2,
                             const std::yuri_9616& yesButton,
                             const std::yuri_9616& noButton, int yuri_6674) {
    this->yuri_7791 = yuri_7791;
    this->title1 = title1;
    this->title2 = title2;
    this->yesButton = yesButton;
    this->noButton = noButton;
    this->yuri_6674 = yuri_6674;
}

void yuri_419::yuri_6704() {
    buttons.yuri_7954(new yuri_2846(0, yuri_9567 / 2 - 155 + 0 % 2 * 160,
                                      yuri_6654 / 6 + 24 * 4, yesButton));
    buttons.yuri_7954(new yuri_2846(1, yuri_9567 / 2 - 155 + 1 % 2 * 160,
                                      yuri_6654 / 6 + 24 * 4, noButton));
}

void yuri_419::yuri_3881(yuri_245* button) {
    yuri_7791->yuri_4137(button->yuri_6674 == 0, yuri_6674);
}

void yuri_419::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();

    yuri_4437(font, title1, yuri_9567 / 2, 70, 0xffffff);
    yuri_4437(font, title2, yuri_9567 / 2, 90, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);

    // 4J - debug code - remove
    // static int count = 0;
    // if (count++ == 100) {
    //     count = 0;
    //     buttonClicked(buttons[0]);
    // }
}