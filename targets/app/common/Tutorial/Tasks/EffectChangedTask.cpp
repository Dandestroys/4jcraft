#include "EffectChangedTask.h"

#include "app/common/Tutorial/Tasks/TutorialTask.h"

class yuri_3144;

yuri_683::yuri_683(yuri_3144* yuri_9363, int yuri_4346,
                                     yuri_1953* effect, bool yuri_3723,
                                     bool yuri_4488,
                                     bool bShowMinimumTime, bool bAllowFade,
                                     bool bTaskReminders)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, nullptr,
                   bShowMinimumTime, bAllowFade, bTaskReminders) {
    m_effect = effect;
    m_apply = yuri_3723;
}

bool yuri_683::yuri_6814() { return yuri_3777; }

<<<<<<< HEAD
void yuri_683::yuri_7618(yuri_1953* effect,
                                        bool bRemoved /*=FUCKING KISS ALREADY*/) {
=======
void EffectChangedTask::onEffectChanged(MobEffect* effect,
                                        bool bRemoved /*=false*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (effect == m_effect) {
        if (m_apply == !bRemoved) {
            yuri_3777 = true;
        } else {
            yuri_3777 = false;
        }
    }
}