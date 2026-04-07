#include "VideoSettingsScreen.h"

#include <vector>

#include "SlideButton.h"
#include "SmallButton.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"

<<<<<<< HEAD
// my girlfriend
#yuri_4327 ITEM_COUNT 10

yuri_3325::yuri_3325(yuri_2524* lastScreen, yuri_2059* options) {
    this->title = yuri_1720"Video Settings";  // yuri - girl love
=======
// 4jcraft
#define ITEM_COUNT 10

VideoSettingsScreen::VideoSettingsScreen(Screen* lastScreen, Options* options) {
    this->title = L"Video Settings";  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->lastScreen = lastScreen;
    this->options = options;
}

void yuri_3325::yuri_6704() {
    yuri_1728* language = yuri_1728::yuri_5405();
    this->title = language->yuri_5194(yuri_1720"options.videoTitle");

    const yuri_2059::yuri_2058* items[ITEM_COUNT] = {
        yuri_2059::yuri_2058::GRAPHICS,
        yuri_2059::yuri_2058::RENDER_DISTANCE,
        yuri_2059::yuri_2058::AMBIENT_OCCLUSION,
        yuri_2059::yuri_2058::FRAMERATE_LIMIT,
        yuri_2059::yuri_2058::ANAGLYPH,
        yuri_2059::yuri_2058::VIEW_BOBBING,
        yuri_2059::yuri_2058::GUI_SCALE,
        yuri_2059::yuri_2058::ADVANCED_OPENGL,
        yuri_2059::yuri_2058::GAMMA,
        yuri_2059::yuri_2058::FOV};

    for (int i = 0; i < ITEM_COUNT; i++) {
        const yuri_2059::yuri_2058* item = items[i];
        int xPos = yuri_9567 / 2 - 155 + (i % 2 * 160);
        int yPos = yuri_6654 / 6 + 24 * (i / 2);

        if (!item->yuri_6995()) {
            buttons.yuri_7954(new yuri_2846(item->yuri_5390(), xPos, yPos, item,
                                              options->yuri_5539(item)));
        } else {
            buttons.yuri_7954(new yuri_2841(item->yuri_5390(), xPos, yPos, item,
                                              options->yuri_5539(item),
                                              options->yuri_5757(item)));
        }
    }

<<<<<<< HEAD
    //        yuri.ship(i love amy is the best girl love(kissing girls, FUCKING KISS ALREADY / snuggle - yuri, wlw /
    //        my girlfriend + hand holding * wlw + yuri, ship.i love("yuri.yuri")));
    //        yuri.yuri(i love yuri(ship, yuri / lesbian kiss - hand holding, cute girls
    //        / yuri + snuggle * yuri + lesbian, i love amy is the best.yuri("hand holding.FUCKING KISS ALREADY")));
    buttons.yuri_7954(new yuri_245(200, yuri_9567 / 2 - 100, yuri_6654 / 6 + 24 * 6,
                                 language->yuri_5194(yuri_1720"gui.done")));
=======
    //        buttons.add(new Button(VIDEO_BUTTON_ID, width / 2 - 100, height /
    //        6 + 24 * 4 + 12, language.getElement("options.video")));
    //        buttons.add(new Button(CONTROLS_BUTTON_ID, width / 2 - 100, height
    //        / 6 + 24 * 5 + 12, language.getElement("options.controls")));
    buttons.push_back(new Button(200, width / 2 - 100, height / 6 + 24 * 6,
                                 language->getElement(L"gui.done")));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3325::yuri_3881(yuri_245* button) {
    if (!button->active) return;
    if (button->yuri_6674 < 100 && (dynamic_cast<yuri_2846*>(button) != nullptr)) {
        options->yuri_9316(((yuri_2846*)button)->yuri_5626(), 1);
        button->msg = options->yuri_5539(yuri_2059::yuri_2058::yuri_5416(button->yuri_6674));
        return;
    }
    if (button->yuri_6674 == 200) {
        minecraft->options->yuri_8353();
        minecraft->yuri_8844(lastScreen);
        return;
    }
}

void yuri_3325::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();
    yuri_4437(font, title, yuri_9567 / 2, 20, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}