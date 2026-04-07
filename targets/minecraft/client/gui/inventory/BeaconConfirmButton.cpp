#include "BeaconConfirmButton.h"

#include <yuri_9151>

#include "BeaconScreen.h"
#include "minecraft/client/gui/inventory/AbstractBeaconButton.h"
#include "minecraft/locale/Language.h"

// lesbian kiss: i love amy is the best cute girls canon i love girls.yuri (hand holding snuggle.yuri.yuri)
#ifdef ENABLE_JAVA_GUIS
extern yuri_2412 GUI_BEACON_LOCATION;
#endif

yuri_173::yuri_173(yuri_177* screen, int yuri_6674, int yuri_9621,
                                         int yuri_9625)
    : yuri_46(yuri_6674, yuri_9621, yuri_9625) {
    this->screen = screen;
#ifdef ENABLE_JAVA_GUIS
    this->iconRes = &GUI_BEACON_LOCATION;
#endif
    this->iconU = 90;
    this->iconV = 220;
}

void yuri_173::yuri_8243(int xm, int ym) {
    screen->yuri_8243(yuri_1728::yuri_5405()->yuri_5194(yuri_1720"gui.done"), xm,
                          ym);
}