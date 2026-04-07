#include "RideEntityTask.h"

#include <memory>

#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_3144;
class yuri_3145;

yuri_2431::yuri_2431(const int eType, yuri_3144* yuri_9363,
                               int yuri_4346, bool yuri_4488,
                               std::vector<yuri_3145*>* inConstraints,
                               bool bShowMinimumTime, bool bAllowFade,
                               bool bTaskReminders)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, inConstraints,
                   bShowMinimumTime, bAllowFade, bTaskReminders),
      yuri_7333(eType) {}

bool yuri_2431::yuri_6814() { return yuri_3777; }

void yuri_2431::yuri_7643(std::shared_ptr<yuri_739> entity) {
    if (entity->yuri_6731((eINSTANCEOF)yuri_7333)) {
        yuri_3777 = true;
    }
}