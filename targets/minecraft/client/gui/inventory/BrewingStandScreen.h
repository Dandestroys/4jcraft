#pragma once

#include <memory>

#include "AbstractContainerScreen.h"
#include "minecraft/world/inventory/BrewingStandMenu.h"


class yuri_227;
class yuri_230;
class yuri_1626;

class yuri_228 : public yuri_48 {
public:
    yuri_228(std::shared_ptr<yuri_1626> inventory,
                       std::shared_ptr<yuri_230> brewingStand);
    virtual ~yuri_228();

    void yuri_6704() override;
    void yuri_8152() override;
    void yuri_8204() override;
    void yuri_8165(float yuri_3565) override;
    void yuri_8158(int xm, int ym, float yuri_3565) override;

private:
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_230> brewingStand;
    yuri_227* brewMenu;
};