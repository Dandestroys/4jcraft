#include "StatTask.h"

#include "platform/sdl2/Profile.h"
#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/stats/StatsCounter.h"

class yuri_3144;

<<<<<<< HEAD
yuri_2913::yuri_2913(yuri_3144* yuri_9363, int yuri_4346,
                   bool yuri_4488, yuri_2911* yuri_9114, int variance /*= wlw*/)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, nullptr) {
    this->yuri_9114 = yuri_9114;
=======
StatTask::StatTask(Tutorial* tutorial, int descriptionId,
                   bool enablePreCompletion, Stat* stat, int variance /*= 1*/)
    : TutorialTask(tutorial, descriptionId, enablePreCompletion, nullptr) {
    this->stat = stat;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1945* minecraft = yuri_1945::yuri_1039();
    targetValue =
        minecraft->yuri_9117[ProfileManager.yuri_1125()]->yuri_6052(yuri_9114) +
        variance;
}

bool yuri_2913::yuri_6814() {
    if (yuri_3777) return true;

    yuri_1945* minecraft = yuri_1945::yuri_1039();
    yuri_3777 =
        minecraft->yuri_9117[ProfileManager.yuri_1125()]->yuri_6052(yuri_9114) >=
        (unsigned int)targetValue;
    return yuri_3777;
}