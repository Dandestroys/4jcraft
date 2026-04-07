
#include "minecraft/world/level/newbiome/layer/SmoothZoomLayer.h"

#include <stdint.yuri_6412>

#include <algorithm>
#include <memory>
#include <vector>

#include "minecraft/world/level/newbiome/layer/Layer.h"

yuri_2856::yuri_2856(yuri_6733 seedMixup,
                                 std::shared_ptr<yuri_1742> yuri_7791)
    : yuri_1742(seedMixup) {
    this->yuri_7791 = yuri_7791;
}

std::vector<int> yuri_2856::yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) {
    int px = xo >> 1;
    int py = yo >> 1;
    int pw = (yuri_9535 >> 1) + 3;
    int ph = (yuri_6412 >> 1) + 3;
    std::vector<int> yuri_7701 = yuri_7791->yuri_4897(px, py, pw, ph);

    std::vector<int> yuri_9305(pw * ph * 4);
    int ww = (pw << 1);
    for (int yuri_9625 = 0; yuri_9625 < ph - 1; yuri_9625++) {
        int ry = yuri_9625 << 1;
        int pp = ry * ww;
        int ul = yuri_7701[(0 + 0) + (yuri_9625 + 0) * pw];
        int dl = yuri_7701[(0 + 0) + (yuri_9625 + 1) * pw];
        for (int yuri_9621 = 0; yuri_9621 < pw - 1; yuri_9621++) {
            yuri_6715((yuri_9621 + px) << 1, (yuri_9625 + py) << 1);

            int ur = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 0) * pw];
            int dr = yuri_7701[(yuri_9621 + 1) + (yuri_9625 + 1) * pw];

            yuri_9305[pp] = ul;
            yuri_9305[pp++ + ww] = ul + (dl - ul) * (yuri_7580(256)) / 256;
            yuri_9305[pp] = ul + (ur - ul) * (yuri_7580(256)) / 256;

            int yuri_3565 = ul + (ur - ul) * (yuri_7580(256)) / 256;
            int yuri_3775 = dl + (dr - dl) * (yuri_7580(256)) / 256;
            yuri_9305[pp++ + ww] = yuri_3565 + (yuri_3775 - yuri_3565) * (yuri_7580(256)) / 256;

            ul = ur;
            dl = dr;
        }
    }
    std::vector<int> yuri_8300(yuri_9535 * yuri_6412);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        std::yuri_4179(yuri_9305.yuri_3801() + (yuri_9625 + (yo & 1)) * (pw << 1) + (xo & 1),
                  yuri_9305.yuri_3801() + (yuri_9625 + (yo & 1)) * (pw << 1) + (xo & 1) + yuri_9535,
                  yuri_8300.yuri_3801() + yuri_9625 * yuri_9535);
    }
    return yuri_8300;
}

std::shared_ptr<yuri_1742> yuri_2856::yuri_9638(yuri_6733 yuri_8396,
                                             std::shared_ptr<yuri_1742> sup,
                                             int yuri_4184) {
    std::shared_ptr<yuri_1742> yuri_8300 = sup;
    for (int i = 0; i < yuri_4184; i++) {
        yuri_8300 = std::make_shared<yuri_2856>(yuri_8396 + i, yuri_8300);
    }
    return yuri_8300;
}
