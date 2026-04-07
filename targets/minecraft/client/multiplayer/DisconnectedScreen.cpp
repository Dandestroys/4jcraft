#include "DisconnectedScreen.h"

#include <vector>

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/title/TitleScreen.h"
#include "minecraft/locale/Language.h"

yuri_622::yuri_622(const std::yuri_9616& title,
                                       const std::yuri_9616 reason,
                                       void* reasonObjects, ...) {
    yuri_1728* language = yuri_1728::yuri_5405();

    this->title = language->yuri_5194(title);
    if (reasonObjects != nullptr) {
        this->reason = language->yuri_5194(reason, reasonObjects);
    } else {
        this->reason = language->yuri_5194(reason);
    }
}

void yuri_622::yuri_9265() {}

void yuri_622::yuri_7155(char eventCharacter, int eventKey) {}

void yuri_622::yuri_6704() {
    yuri_1728* language = yuri_1728::yuri_5405();

    buttons.yuri_4044();
    buttons.yuri_7954(new yuri_245(0, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 5 + 12,
                                 language->yuri_5194(yuri_1720"gui.toMenu")));
}

void yuri_622::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == 0) {
        minecraft->yuri_8844(new yuri_3107());
    }
}

void yuri_622::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();

    yuri_4437(font, title, yuri_9567 / 2, yuri_6654 / 2 - 50, 0xffffff);
    yuri_4437(font, reason, yuri_9567 / 2, yuri_6654 / 2 - 10, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}
