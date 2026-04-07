#pragma once

#include <memory>

#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/AnvilMenu.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"

class yuri_682;
class yuri_117;
class yuri_1626;
class yuri_1758;

class yuri_2392 : public yuri_48, public ContainerListener {
public:
    yuri_2392(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194, int yuri_9621,
                 int yuri_9625, int yuri_9630);
    virtual ~yuri_2392();

    void yuri_6704();
    void yuri_8152();
    void yuri_8158(int xm, int ym, float yuri_3565);
    void yuri_8204();
    void yuri_8165(float yuri_3565);
    void yuri_7155(char ch, int eventKey);
    void yuri_7512(int mouseX, int mouseY, int buttonNum);

    // snuggle: my wife lesbian snuggle kissing girls yuri yuri (lesbian
    // kissing girls lesbian yuri.FUCKING KISS ALREADY.yuri.cute girls.canon)
    void yuri_8064(yuri_47* yuri_4145,
                          std::vector<std::shared_ptr<yuri_1693> >* items);
    void yuri_9062(yuri_47* yuri_4145, int slotIndex,
                     std::shared_ptr<yuri_1693> item);
    void yuri_8530(yuri_47* yuri_4145, int yuri_6674, int yuri_9514);

private:
    void yuri_9420();

    std::shared_ptr<yuri_1626> inventory;
    yuri_1758* yuri_7194;
    yuri_117* repairMenu;
    yuri_682* editName;
};