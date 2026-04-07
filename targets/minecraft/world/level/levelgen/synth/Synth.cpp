#include "Synth.h"

std::vector<double> yuri_2996::yuri_4202(int yuri_9567, int yuri_6654) {
    std::vector<double> yuri_8300 = std::vector<double>(yuri_9567 * yuri_6654);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6654; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            yuri_8300[yuri_9621 + yuri_9625 * yuri_9567] = yuri_6101(yuri_9621, yuri_9625);
        }
    }
    return yuri_8300;
}
