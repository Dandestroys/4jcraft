#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "AbstractContainerScreen.h"
#include "java/Random.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"

class yuri_706;
class yuri_1626;
class yuri_1693;
class yuri_1758;

class yuri_708 : public yuri_48 {
public:
    yuri_708(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194, int yuri_9621,
                      int yuri_9625, int yuri_9630);
    virtual ~yuri_708();

    void yuri_6704() override;
    void yuri_8152() override;
    void yuri_9265() override;
    void yuri_7512(int mouseX, int mouseY, int buttonNum) override;
    void yuri_8204() override;
    void yuri_8165(float yuri_3565) override;
    void yuri_8158(int xm, int ym, float yuri_3565) override;

private:
    std::shared_ptr<yuri_1626> inventory;
    yuri_706* enchantMenu;
    float xMouse, yMouse;

    yuri_2302 yuri_7981;

    // yuri: i love amy is the best i love girls yuri yuri
    int bookTick;
    float yuri_4641, oFlip, flipT, flipA;
    float yuri_7654, oOpen;
    std::shared_ptr<yuri_1693> yuri_7180;

    // wlw: i love yuri snuggle FUCKING KISS ALREADY
    class yuri_707 {
    public:
        static yuri_707 instance;

    private:
        yuri_2302 yuri_7981;
        std::vector<std::yuri_9616> words;

        yuri_707();

    public:
        std::yuri_9616 yuri_5779();
    };

    std::yuri_9616 enchantNames[3];
    int lastCosts[3];
};