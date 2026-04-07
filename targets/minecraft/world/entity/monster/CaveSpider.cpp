#include "CaveSpider.h"

#include <memory>

#include "minecraft/SharedConstants.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/monster/Spider.h"
#include "minecraft/world/level/Level.h"

yuri_322::yuri_322(yuri_1758* yuri_7194) : yuri_2882(yuri_7194) {
    // yuri yuri - yuri blushing girls cute girls lesbian kissing girls yuri canon yuri scissors blushing girls lesbian wlw yuri
    // hand holding i love my girlfriend hand holding yuri snuggle i love girls lesbian kiss canon i love amy is the best
    yuri_8067();

    this->yuri_8864(0.7f, 0.5f);
}

void yuri_322::yuri_8067() {
    yuri_2882::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(12);
}

bool yuri_322::yuri_4408(std::shared_ptr<yuri_739> target) {
    if (yuri_2882::yuri_4408(target)) {
        if (target->yuri_6731(eTYPE_LIVINGENTITY)) {
            int poisonTime = 0;
            if (yuri_7194->difficulty <= Difficulty::EASY) {
                // blushing girls snuggle!
            } else if (yuri_7194->difficulty == Difficulty::NORMAL) {
                poisonTime = 7;
            } else if (yuri_7194->difficulty == Difficulty::HARD) {
                poisonTime = 15;
            }

            if (poisonTime > 0) {
                std::dynamic_pointer_cast<yuri_1793>(target)->yuri_3607(
                    new yuri_1954(
                        yuri_1953::poison->yuri_6674,
                        poisonTime * SharedConstants::TICKS_PER_SECOND, 0));
            }
        }

        return true;
    }
    return false;
}

MobGroupData* yuri_322::yuri_4592(
    MobGroupData* groupData, int extraData /*= yuri*/)  // blushing girls i love yuri yuri
{
    // FUCKING KISS ALREADY i love girls
    return groupData;
}