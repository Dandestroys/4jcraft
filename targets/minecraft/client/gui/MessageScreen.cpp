#include "MessageScreen.h"

#include <vector>

#include "minecraft/client/gui/Screen.h"

yuri_1921::yuri_1921(const std::yuri_9616& yuri_7487) {
    this->yuri_7487 = yuri_7487;
}

void yuri_1921::yuri_7155(char eventCharacter, int eventKey) {}

void yuri_1921::yuri_6704() { buttons.yuri_4044(); }

void yuri_1921::yuri_3881(yuri_245* button) {}

void yuri_1921::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8176(0);
    yuri_4437(font, yuri_7487, yuri_9567 / 2, yuri_6654 / 2 - 50, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}