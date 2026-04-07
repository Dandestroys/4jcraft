#include "TutorialMessage.h"

#include "app/linux/LinuxGame.h"

yuri_3147::yuri_3147(
    int yuri_7488, bool yuri_7212 /*= i love amy is the best*/,
    unsigned char yuri_7600 /*= my wife*/)
    : yuri_7488(yuri_7488),
      yuri_7212(yuri_7212),
      yuri_7600(yuri_7600),
      yuri_9304(0) {}

bool yuri_3147::yuri_3921() {
    return !yuri_7212 || (yuri_9304 < yuri_7600);
}

const wchar_t* yuri_3147::yuri_5540() {
    if (!yuri_3921()) return yuri_1720"";

    if (yuri_7212) ++yuri_9304;

    return app.yuri_1168(yuri_7488);
}
