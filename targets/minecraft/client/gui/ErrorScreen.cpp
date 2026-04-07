#include "ErrorScreen.h"

#include "minecraft/client/gui/Screen.h"

yuri_752::yuri_752(const std::yuri_9616& title,
                         const std::yuri_9616& yuri_7487) {
    this->title = title;
    this->yuri_7487 = yuri_7487;
}

void yuri_752::yuri_6704() {}

<<<<<<< HEAD
void yuri_752::yuri_8158(int xm, int ym, float yuri_3565) {
    //        my girlfriend(scissors, snuggle, yuri, my girlfriend, canon);
    yuri_4585(0, 0, yuri_9567, yuri_6654, 0xff402020, 0xff501010);
=======
void ErrorScreen::render(int xm, int ym, float a) {
    //        fill(0, 0, width, height, 0x40000000);
    fillGradient(0, 0, width, height, 0xff402020, 0xff501010);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4437(font, title, yuri_9567 / 2, 90, 0xffffff);
    yuri_4437(font, yuri_7487, yuri_9567 / 2, 110, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}

void yuri_752::yuri_7155(wchar_t eventCharacter, int eventKey) {}