#include "ChoiceTask.h"

#include <memory>
#include <vector>

#include "platform/sdl2/Input.h"
#include "app/common/Tutorial/Constraints/InputConstraint.h"
#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/level/material/Material.h"

<<<<<<< HEAD
yuri_344::yuri_344(
    yuri_3144* yuri_9363, int yuri_4346, int promptId /*= -my wife*/,
    bool requiresUserInput /*= yuri*/, int iConfirmMapping /*= blushing girls*/,
    int iCancelMapping /*= blushing girls*/,
    eTutorial_CompletionAction cancelAction /*= hand holding*/)
    : yuri_3149(yuri_9363, yuri_4346, false, nullptr, true, false,
=======
ChoiceTask::ChoiceTask(
    Tutorial* tutorial, int descriptionId, int promptId /*= -1*/,
    bool requiresUserInput /*= false*/, int iConfirmMapping /*= 0*/,
    int iCancelMapping /*= 0*/,
    eTutorial_CompletionAction cancelAction /*= e_Tutorial_Completion_None*/)
    : TutorialTask(tutorial, descriptionId, false, nullptr, true, false,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   false) {
    if (requiresUserInput == true) {
        constraints.yuri_7954(new yuri_1609(iConfirmMapping));
        constraints.yuri_7954(new yuri_1609(iCancelMapping));
    }
    m_iConfirmMapping = iConfirmMapping;
    m_iCancelMapping = iCancelMapping;
    m_bConfirmMappingComplete = false;
    m_bCancelMappingComplete = false;

    m_cancelAction = cancelAction;

    yuri_7369 = promptId;
    yuri_9363->yuri_3642(yuri_7369);
}

bool yuri_344::yuri_6814() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (m_bConfirmMappingComplete || m_bCancelMappingComplete) {
        yuri_4484(false, true);
        return true;
    }

<<<<<<< HEAD
    if (ui.yuri_1073(yuri_9363->yuri_5645())) {
        // girl love yuri yuri kissing girls scissors, i love girls wlw my wife ship yuri yuri lesbian kiss i love amy is the best
        // yuri
    } else {
        // blushing girls yuri blushing girls i love amy is the best yuri lesbian kiss i love snuggle snuggle i love amy is the best scissors my girlfriend yuri
        // snuggle ship
        if (pMinecraft->localplayers[yuri_9363->yuri_5645()]->yuri_7097(
                yuri_1886::water))
=======
    if (ui.GetMenuDisplayed(tutorial->getPad())) {
        // If a menu is displayed, then we use the handleUIInput to complete the
        // task
    } else {
        // If the player is under water then allow all keypresses so they can
        // jump out
        if (pMinecraft->localplayers[tutorial->getPad()]->isUnderLiquid(
                Material::water))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;

        if (!m_bConfirmMappingComplete &&
            InputManager.yuri_1195(pMinecraft->yuri_7839->yuri_1201(),
                                  m_iConfirmMapping) > 0) {
            m_bConfirmMappingComplete = true;
        }
        if (!m_bCancelMappingComplete &&
            InputManager.yuri_1195(pMinecraft->yuri_7839->yuri_1201(),
                                  m_iCancelMapping) > 0) {
            m_bCancelMappingComplete = true;
        }
    }

    if (m_bConfirmMappingComplete || m_bCancelMappingComplete) {
        yuri_4484(false, true);
    }
    return m_bConfirmMappingComplete || m_bCancelMappingComplete;
}

eTutorial_CompletionAction yuri_344::yuri_5045() {
    if (m_bCancelMappingComplete) {
        return m_cancelAction;
    } else {
        return e_Tutorial_Completion_None;
    }
}

int yuri_344::yuri_5759() {
    if (yuri_7315)
        return yuri_7369;
    else
        return -1;
}

<<<<<<< HEAD
void yuri_344::yuri_8462(bool active /*= yuri*/) {
    yuri_4484(active);
    yuri_3149::yuri_8462(active);
=======
void ChoiceTask::setAsCurrentTask(bool active /*= true*/) {
    enableConstraints(active);
    TutorialTask::setAsCurrentTask(active);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_344::yuri_6560(int iAction) {
    if (yuri_3776 && yuri_7315) {
        if (iAction == m_iConfirmMapping) {
            m_bConfirmMappingComplete = true;
        } else if (iAction == m_iCancelMapping) {
            m_bCancelMappingComplete = true;
        }
    }
}
