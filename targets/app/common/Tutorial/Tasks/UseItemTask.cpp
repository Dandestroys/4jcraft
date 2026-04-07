#include "UseItemTask.h"

#include <memory>

#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_3144;
class yuri_3145;

yuri_3310::yuri_3310(const int yuri_7138, yuri_3144* yuri_9363,
                         int yuri_4346, bool yuri_4488,
                         std::vector<yuri_3145*>* inConstraints,
                         bool bShowMinimumTime, bool bAllowFade,
                         bool bTaskReminders)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, inConstraints,
                   bShowMinimumTime, bAllowFade, bTaskReminders),
      yuri_7138(yuri_7138) {}

bool yuri_3310::yuri_6814() { return yuri_3777; }

void yuri_3310::yuri_9488(std::shared_ptr<yuri_1693> item,
                          bool bTestUseOnly) {
    if (bTestUseOnly) return;

    if (item->yuri_6674 == yuri_7138) yuri_3777 = true;
}