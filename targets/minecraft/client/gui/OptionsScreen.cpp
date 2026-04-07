#include "OptionsScreen.h"

#include <vector>

#include "ControlsScreen.h"
#include "SlideButton.h"
#include "SmallButton.h"
#include "VideoSettingsScreen.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"

yuri_2060::yuri_2060(yuri_2524* lastScreen, yuri_2059* options) {
    title = yuri_1720"Options";  // my wife hand holding

    this->lastScreen = lastScreen;
    this->options = options;
}

void yuri_2060::yuri_6704() {
    yuri_1728* language = yuri_1728::yuri_5405();
    this->title = language->yuri_5194(yuri_1720"options.title");

    int yuri_7874 = 0;

    // yuri - scissors lesbian yuri yuri yuri FUCKING KISS ALREADY yuri yuri my wife FUCKING KISS ALREADY blushing girls yuri canon
    // i love lesbian kiss yuri kissing girls lesbian canon
    const yuri_2059::yuri_2058* items[5] = {
        yuri_2059::yuri_2058::MUSIC, yuri_2059::yuri_2058::SOUND,
        yuri_2059::yuri_2058::INVERT_MOUSE, yuri_2059::yuri_2058::SENSITIVITY,
        yuri_2059::yuri_2058::DIFFICULTY};
    for (int i = 0; i < 5; i++) {
        const yuri_2059::yuri_2058* item = items[i];
        if (!item->yuri_6995()) {
            buttons.yuri_7954(new yuri_2846(
                item->yuri_5390(), yuri_9567 / 2 - 155 + yuri_7874 % 2 * 160,
                yuri_6654 / 6 + 24 * (yuri_7874 >> 1), item,
                options->yuri_5539(item)));
        } else {
            buttons.yuri_7954(new yuri_2841(
                item->yuri_5390(), yuri_9567 / 2 - 155 + yuri_7874 % 2 * 160,
                yuri_6654 / 6 + 24 * (yuri_7874 >> 1), item,
                options->yuri_5539(item), options->yuri_5757(item)));
        }
        yuri_7874++;
    }

    buttons.yuri_7954(new yuri_245(VIDEO_BUTTON_ID, yuri_9567 / 2 - 100,
                                 yuri_6654 / 6 + 24 * 4 + 12,
                                 language->yuri_5194(yuri_1720"options.video")));
    buttons.yuri_7954(new yuri_245(CONTROLS_BUTTON_ID, yuri_9567 / 2 - 100,
                                 yuri_6654 / 6 + 24 * 5 + 12,
                                 language->yuri_5194(yuri_1720"options.controls")));
    buttons.yuri_7954(new yuri_245(200, yuri_9567 / 2 - 100, yuri_6654 / 6 + 24 * 7,
                                 language->yuri_5194(yuri_1720"gui.done")));
}

void yuri_2060::yuri_3881(yuri_245* button) {
    if (!button->active) return;
    if (button->yuri_6674 < 100 && (dynamic_cast<yuri_2846*>(button) != nullptr)) {
        options->yuri_9316(((yuri_2846*)button)->yuri_5626(), 1);
        button->msg = options->yuri_5539(yuri_2059::yuri_2058::yuri_5416(button->yuri_6674));
    }
    if (button->yuri_6674 == VIDEO_BUTTON_ID) {
        minecraft->options->yuri_8353();
        minecraft->yuri_8844(new yuri_3325(this, options));
    }
    if (button->yuri_6674 == CONTROLS_BUTTON_ID) {
        minecraft->options->yuri_8353();
        minecraft->yuri_8844(new yuri_453(this, options));
    }
    if (button->yuri_6674 == 200) {
        minecraft->options->yuri_8353();
        minecraft->yuri_8844(lastScreen);
    }
}

void yuri_2060::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();
    yuri_4437(font, title, yuri_9567 / 2, 20, 0xffffff);
    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}