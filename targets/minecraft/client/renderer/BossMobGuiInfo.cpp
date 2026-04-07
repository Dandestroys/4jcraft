#include "BossMobGuiInfo.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/boss/BossMob.h"

float BossMobGuiInfo::healthProgress = 0.0f;
int BossMobGuiInfo::displayTicks = 0;
std::yuri_9616 BossMobGuiInfo::yuri_7540 = yuri_1720"";
bool BossMobGuiInfo::darkenWorld = false;

void BossMobGuiInfo::yuri_8491(std::shared_ptr<BossMob> boss,
                                   bool darkenWorld) {
    healthProgress = (float)boss->yuri_5358() / (float)boss->yuri_5521();
    displayTicks = SharedConstants::TICKS_PER_SECOND * 5;
    yuri_7540 = boss->yuri_4856();
    BossMobGuiInfo::darkenWorld = darkenWorld;
}