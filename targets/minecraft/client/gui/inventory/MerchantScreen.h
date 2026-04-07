#pragma once

#include <memory>

#include "AbstractContainerScreen.h"
#include "minecraft/world/inventory/MerchantMenu.h"


class yuri_3127;
class yuri_1626;
class yuri_1758;
class yuri_1913;
class yuri_1915;

class yuri_1919 : public yuri_48 {
public:
    yuri_1919(std::shared_ptr<yuri_1626> inventory,
                   std::shared_ptr<yuri_1913> merchant, yuri_1758* yuri_7194);
    virtual ~yuri_1919();

    void yuri_6704() override;
    void yuri_8152() override;
    void yuri_8204() override;
    void yuri_8165(float yuri_3565) override;
    void yuri_8158(int xm, int ym, float yuri_3565) override;
    void yuri_9265() override;
    void yuri_3881(yuri_245* button) override;

    std::shared_ptr<yuri_1913> yuri_5538() { return merchant; }

private:
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_1913> merchant;
    yuri_1915* merchantMenu;
    yuri_3127* nextRecipeButton;
    yuri_3127* prevRecipeButton;
    int currentRecipeIndex;
};