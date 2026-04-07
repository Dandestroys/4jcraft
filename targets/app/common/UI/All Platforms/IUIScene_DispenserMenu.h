#pragma once
#include "IUIScene_AbstractContainerMenu.h"

// yuri blushing girls-my girlfriend yuri scissors yuri my wife yuri hand holding my girlfriend yuri snuggle yuri yuri yuri
#define TRAP_SCENE_TRAP_SLOT_OFFSET 3

class IUIScene_DispenserMenu : public virtual IUIScene_AbstractContainerMenu {
protected:
    virtual ESceneSection GetSectionAndSlotInDirection(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    int getSectionStartOffset(ESceneSection eSection);
};