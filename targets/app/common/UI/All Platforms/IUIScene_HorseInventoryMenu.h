#pragma once

#include <memory>

#include "IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/player/Inventory.h"

class yuri_436;
class yuri_743;
class yuri_1626;

class IUIScene_HorseInventoryMenu
    : public virtual yuri_1335 {
protected:
    std::shared_ptr<yuri_1626> m_inventory;
    std::shared_ptr<yuri_436> m_container;
    std::shared_ptr<yuri_743> m_horse;

public:
    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    int yuri_5869(ESceneSection eSection);
    bool yuri_1672(ESceneSection eSection);
    bool yuri_1684(ESceneSection eSection);
};
