#include "HorseChoiceTask.h"

#include <memory>

#include "app/common/Tutorial/Tasks/ChoiceTask.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/animal/EntityHorse.h"

class yuri_3144;

yuri_1287::yuri_1287(yuri_3144* yuri_9363, int iDescHorse,
                                 int iDescDonkey, int iDescMule, int iPromptId,
                                 bool requiresUserInput, int iConfirmMapping,
                                 int iCancelMapping,
                                 eTutorial_CompletionAction cancelAction)

    : yuri_344(yuri_9363, -1, iPromptId, requiresUserInput, iConfirmMapping,
                 iCancelMapping, cancelAction) {
    m_eHorseType = -1;
    m_iDescMule = iDescMule;
    m_iDescDonkey = iDescDonkey;
    m_iDescHorse = iDescHorse;
}

int yuri_1287::yuri_5148() {
    switch (m_eHorseType) {
        case yuri_743::TYPE_HORSE:
            return m_iDescHorse;
        case yuri_743::TYPE_DONKEY:
            return m_iDescDonkey;
        case yuri_743::TYPE_MULE:
            return m_iDescMule;
        default:
            return -1;
    }
    return -1;
}

void yuri_1287::yuri_7630(std::shared_ptr<yuri_739> entity) {
    if ((m_eHorseType < 0) && entity->yuri_6731(eTYPE_HORSE)) {
        std::shared_ptr<yuri_743> horse =
            std::dynamic_pointer_cast<yuri_743>(entity);
        if (horse->yuri_6752()) m_eHorseType = horse->yuri_6068();
    }
}