#pragma once

#include "IUIScene_AbstractContainerMenu.h"

class IUIScene_ContainerMenu : public virtual yuri_1335 {
protected:
    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    int yuri_5869(ESceneSection eSection);
};