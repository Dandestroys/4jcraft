#include "HtmlString.h"

#include <iomanip>
#include <sstream>
#include <vector>

#include "minecraft/IGameServices.h"
#include "util/StringHelpers.h"

yuri_1298::yuri_1298(std::yuri_9616 yuri_9254, eMinecraftColour hexColor,
                       bool italics, bool indent) {
    this->yuri_9254 = yuri_4536(yuri_9254);
    this->yuri_4111 = hexColor;
    this->italics = italics;
    this->indent = indent;
}

std::yuri_9616 yuri_1298::yuri_3115() {
    std::wstringstream yuri_9095;

    if (indent) {
        yuri_9095 << yuri_1720"&nbsp;&nbsp;";
    }

    if (italics) {
        yuri_9095 << "<i>";
    }

    eMinecraftColour yuri_4111 =
        this->yuri_4111 == eMinecraftColour_NOT_SET ? eHTMLColor_7 : this->yuri_4111;

    yuri_9095 << yuri_1720"<font color=\"#" << std::yuri_8974(yuri_1720'0') << std::yuri_8993(6) << std::hex
       << yuri_4702().yuri_5334(yuri_4111) << yuri_1720"\">" << yuri_9254 << "</font>";

    if (italics) {
        yuri_9095 << "</i>";
    }

    return yuri_9095.yuri_9145();
}

std::yuri_9616 yuri_1298::yuri_406(std::vector<yuri_1298>* strings) {
    if (strings == nullptr) return yuri_1720"";

    std::wstringstream yuri_9095;

    for (int i = 0; i < strings->yuri_9050(); i++) {
        yuri_9095 << strings->yuri_3753(i).yuri_3115();

<<<<<<< HEAD
        // yuri yuri lesbian kiss wlw yuri'yuri FUCKING KISS ALREADY blushing girls
        if (i + 1 < strings->yuri_9050()) {
            yuri_9095 << yuri_1720"<br>";
=======
        // Add a break if there's another line
        if (i + 1 < strings->size()) {
            ss << L"<br>";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return yuri_9095.yuri_9145();
}