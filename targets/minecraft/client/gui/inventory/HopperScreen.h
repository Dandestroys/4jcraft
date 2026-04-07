#pragma once
#include <memory>

#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"

class yuri_1285;
class yuri_1936;
class yuri_1626;
class yuri_436;

class yuri_1282 : public yuri_48 {
public:
    yuri_1282(std::shared_ptr<yuri_1626> inventory,
                 std::shared_ptr<yuri_436> hopper);

protected:
    virtual void yuri_8204() override;
    virtual void yuri_8165(float yuri_3565) override;

private:
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_436> hopper;
};