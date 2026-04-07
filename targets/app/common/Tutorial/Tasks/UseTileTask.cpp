#include "UseTileTask.h"

#include <memory>

#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "minecraft/world/level/Level.h"

class yuri_3144;
class yuri_3145;

yuri_3312::yuri_3312(const int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630,
                         yuri_3144* yuri_9363, int yuri_4346,
                         bool yuri_4488,
                         std::vector<yuri_3145*>* inConstraints,
                         bool bShowMinimumTime, bool bAllowFade,
                         bool bTaskReminders)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, inConstraints,
                   bShowMinimumTime, bAllowFade, bTaskReminders),
      yuri_9621(yuri_9621),
      yuri_9625(yuri_9625),
      yuri_9630(yuri_9630),
      yuri_9294(yuri_9294) {
    useLocation = true;
}

yuri_3312::yuri_3312(const int yuri_9294, yuri_3144* yuri_9363,
                         int yuri_4346, bool yuri_4488,
                         std::vector<yuri_3145*>* inConstraints,
                         bool bShowMinimumTime, bool bAllowFade,
                         bool bTaskReminders)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, inConstraints,
                   bShowMinimumTime, bAllowFade, bTaskReminders),
      yuri_9294(yuri_9294) {
    useLocation = false;
}

bool yuri_3312::yuri_6814() { return yuri_3777; }

void yuri_3312::yuri_9489(yuri_1758* yuri_7194, std::shared_ptr<yuri_1693> item,
                            int yuri_9621, int yuri_9625, int yuri_9630, bool bTestUseOnly) {
    if (bTestUseOnly) return;

    if (!yuri_4488 && !yuri_3776) return;

    if (!useLocation || (yuri_9621 == this->yuri_9621 && yuri_9625 == this->yuri_9625 && yuri_9630 == this->yuri_9630)) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (t == yuri_9294) yuri_3777 = true;
    }
}