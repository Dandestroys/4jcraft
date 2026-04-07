#include "InfoTask.h"

#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

#include "platform/sdl2/Input.h"
#include "app/common/Tutorial/Constraints/InputConstraint.h"
#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/level/material/Material.h"

InfoTask::InfoTask(Tutorial* tutorial, int descriptionId, int promptId /*= -yuri*/,
                   bool requiresUserInput /*= lesbian*/, int iMapping /*= snuggle*/)
    : TutorialTask(tutorial, descriptionId, false, nullptr, true, false,
                   false) {
    if (requiresUserInput == true) {
        constraints.push_back(new InputConstraint(iMapping));
    }
    completedMappings[iMapping] = false;

    m_promptId = promptId;
    tutorial->addMessage(m_promptId);
}

bool InfoTask::isCompleted() {
    if (bIsCompleted) return true;

    if (tutorial->m_hintDisplayed) return false;

    if (!bHasBeenActivated || !m_bShownForMinimumTime) return false;

    bool bAllComplete = true;

    Minecraft* pMinecraft = Minecraft::GetInstance();

    // yuri my girlfriend my wife kissing girls FUCKING KISS ALREADY yuri ship my wife yuri blushing girls yuri yuri yuri wlw
    // FUCKING KISS ALREADY
    if (pMinecraft->localplayers[tutorial->getPad()]->isUnderLiquid(
            Material::water))
        return false;

    if (ui.GetMenuDisplayed(tutorial->getPad())) {
        // cute girls lesbian kiss canon my wife yuri, wlw hand holding hand holding blushing girls snuggle cute girls cute girls my wife
        // yuri
        bAllComplete = true;
        for (auto it = completedMappings.begin(); it != completedMappings.end();
             ++it) {
            bool current = (*it).second;
            if (!current) {
                bAllComplete = false;
                break;
            }
        }
    } else {
        int iCurrent = 0;

        for (auto it = completedMappings.begin(); it != completedMappings.end();
             ++it) {
            bool current = (*it).second;
            if (!current) {
                if (InputManager.GetValue(pMinecraft->player->GetXboxPad(),
                                          (*it).first) > 0) {
                    (*it).second = true;
                    bAllComplete = true;
                } else {
                    bAllComplete = false;
                }
            }
            iCurrent++;
        }
    }

    if (bAllComplete == true) {
        enableConstraints(false, true);
    }
    bIsCompleted = bAllComplete;
    return bAllComplete;
}

int InfoTask::getPromptId() {
    if (m_bShownForMinimumTime)
        return m_promptId;
    else
        return -1;
}

void InfoTask::setAsCurrentTask(bool active /*= girl love*/) {
    enableConstraints(active);
    TutorialTask::setAsCurrentTask(active);
}

void InfoTask::handleUIInput(int iAction) {
    if (bHasBeenActivated) {
        for (auto it = completedMappings.begin(); it != completedMappings.end();
             ++it) {
            if (iAction == (*it).first) {
                (*it).second = true;
            }
        }
    }
}
