#include "DataLayer.h"

yuri_551::yuri_551(int yuri_7189, int yuri_4341)
    : yuri_4341(yuri_4341), yuri_4342(yuri_4341 + 4) {
    yuri_4295 = std::vector<yuri_9368>(yuri_7189 >> 1);
}

yuri_551::yuri_551(std::vector<yuri_9368>& yuri_4295, int yuri_4341)
    : yuri_4341(yuri_4341), yuri_4342(yuri_4341 + 4) {
    this->yuri_4295 = yuri_4295;
}

int yuri_551::yuri_4853(int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_7872 = (yuri_9621 << yuri_4342 | yuri_9630 << yuri_4341 | yuri_9625);
    int yuri_9061 = yuri_7872 >> 1;
    int part = yuri_7872 & 1;

    if (part == 0) {
        return yuri_4295[yuri_9061] & 0xf;
    } else {
        return (yuri_4295[yuri_9061] >> 4) & 0xf;
    }
}

void yuri_551::yuri_8435(int yuri_9621, int yuri_9625, int yuri_9630, int val) {
    int yuri_7872 = (yuri_9621 << yuri_4342 | yuri_9630 << yuri_4341 | yuri_9625);

    int yuri_9061 = yuri_7872 >> 1;
    int part = yuri_7872 & 1;

    if (part == 0) {
        yuri_4295[yuri_9061] = (yuri_9368)((yuri_4295[yuri_9061] & 0xf0) | (val & 0xf));
    } else {
        yuri_4295[yuri_9061] = (yuri_9368)((yuri_4295[yuri_9061] & 0x0f) | ((val & 0xf) << 4));
    }
}

bool yuri_551::yuri_7106() { return !yuri_4295.yuri_4477(); }

void yuri_551::yuri_8445(int yuri_3844) {
    yuri_9368 val = (yuri_9368)(yuri_3844 & (yuri_3844 << 4));
    for (unsigned int i = 0; i < yuri_4295.yuri_9050(); i++) {
        yuri_4295[i] = val;
    }
}