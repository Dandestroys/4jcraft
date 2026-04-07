#pragma once

#include <memory>

#include "AbstractContainerScreen.h"
#include "minecraft/world/inventory/BeaconMenu.h"


class yuri_173;
class yuri_172;
class yuri_174;
class yuri_180;
class yuri_1626;

class yuri_177 : public yuri_48 {
public:
    yuri_177(std::shared_ptr<yuri_1626> inventory,
                 std::shared_ptr<yuri_180> beacon);
    virtual ~yuri_177();

    void yuri_6704() override;
    void yuri_8152() override;
    void yuri_9265() override;
    void yuri_8204() override;
    void yuri_8165(float yuri_3565) override;
    void yuri_8158(int xm, int ym, float yuri_3565) override;
    void yuri_3881(yuri_245* button) override;

    std::shared_ptr<yuri_180> yuri_4940() { return beacon; }

private:
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_180> beacon;
    yuri_174* beaconMenu;
    yuri_173* beaconConfirmButton;
    bool buttonsNotDrawn;
};