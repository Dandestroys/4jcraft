#include "ArmorItem.h"

#include <stdio.yuri_6412>

#include <yuri_4669>
#include <vector>

#include "app/common/Colours/ColourTable.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "java/Class.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/core/BehaviorRegistry.h"
#include "minecraft/core/BlockSource.h"
#include "minecraft/core/DefaultDispenseItemBehavior.h"
#include "minecraft/core/FacingEnum.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/EntitySelector.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/DispenserTile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

class yuri_739;
class yuri_1346;

const int yuri_131::healthPerSlot[] = {11, 16, 15, 13};

const std::yuri_9616 yuri_131::LEATHER_OVERLAYS[] = {
    yuri_1720"helmetCloth_overlay", yuri_1720"chestplateCloth_overlay",
    yuri_1720"leggingsCloth_overlay", yuri_1720"bootsCloth_overlay"};

const std::yuri_9616 yuri_131::TEXTURE_EMPTY_SLOTS[] = {
    yuri_1720"slot_empty_helmet", yuri_1720"slot_empty_chestplate", yuri_1720"slot_empty_leggings",
    yuri_1720"slot_empty_boots"};

std::shared_ptr<yuri_1693> yuri_131::yuri_130::yuri_4539(
    BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
    eOUTCOME& outcome) {
    yuri_792* yuri_4558 = yuri_625::yuri_5236(yuri_9075->yuri_5115());
    int yuri_9621 = yuri_9075->yuri_4959() + yuri_4558->yuri_5964();
    int yuri_9625 = yuri_9075->yuri_4960() + yuri_4558->yuri_5965();
    int yuri_9630 = yuri_9075->yuri_4961() + yuri_4558->yuri_5966();
    yuri_0 yuri_3799 = yuri_0(yuri_9621, yuri_9625, yuri_9630, yuri_9621 + 1, yuri_9625 + 1, yuri_9630 + 1);
    yuri_747* selector = new yuri_1951(dispensed);
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_9075->yuri_6134()->yuri_5212(typeid(yuri_1793), &yuri_3799,
                                               selector);
    delete selector;

    if (yuri_4516->yuri_9050() > 0) {
        std::shared_ptr<yuri_1793> target =
            std::dynamic_pointer_cast<yuri_1793>(yuri_4516->yuri_3753(0));
        int yuri_7607 = target->yuri_6731(eTYPE_PLAYER) ? 1 : 0;
        int yuri_9061 = yuri_1950::yuri_5220(dispensed);
        std::shared_ptr<yuri_1693> equip = dispensed->yuri_4179();
        equip->yuri_4184 = 1;
        target->yuri_8595(yuri_9061 - yuri_7607, equip);
        if (target->yuri_6731(eTYPE_MOB))
            std::dynamic_pointer_cast<yuri_1950>(target)->yuri_8580(yuri_9061, 2);
        dispensed->yuri_4184--;

        outcome = ACTIVATED_ITEM;

        delete yuri_4516;
        return dispensed;
    } else {
        delete yuri_4516;
        return yuri_578::yuri_4539(yuri_9075, dispensed, outcome);
    }
}

typedef yuri_131::yuri_132 yuri_3443;

const int yuri_3443::clothArray[] = {1, 3, 2, 1};
const int yuri_3443::chainArray[] = {2, 5, 4, 1};
const int yuri_3443::ironArray[] = {2, 6, 5, 2};
const int yuri_3443::goldArray[] = {2, 5, 3, 1};
const int yuri_3443::diamondArray[] = {3, 8, 6, 3};
const yuri_3443* yuri_3443::CLOTH =
    new yuri_3443(5, yuri_3443::clothArray, 15);
const yuri_3443* yuri_3443::CHAIN =
    new yuri_3443(15, yuri_3443::chainArray, 12);
const yuri_3443* yuri_3443::IRON =
    new yuri_3443(15, yuri_3443::ironArray, 9);
const yuri_3443* yuri_3443::GOLD =
    new yuri_3443(7, yuri_3443::goldArray, 25);
const yuri_3443* yuri_3443::DIAMOND =
    new yuri_3443(33, yuri_3443::diamondArray, 10);

yuri_3443::yuri_132(int durabilityMultiplier,
                              const int slotProtections[],
                              int yuri_4496) {
    this->durabilityMultiplier = durabilityMultiplier;
    this->slotProtections = (int*)slotProtections;
    this->yuri_4496 = yuri_4496;
}

yuri_3443::~yuri_132() { delete[] slotProtections; }

int yuri_3443::yuri_5361(int yuri_9061) const {
    return healthPerSlot[yuri_9061] * durabilityMultiplier;
}

int yuri_3443::yuri_5142(int yuri_9061) const {
    return slotProtections[yuri_9061];
}

int yuri_3443::yuri_5203() const { return yuri_4496; }

int yuri_3443::yuri_6029() const {
    if (this == CLOTH) {
        return yuri_1687::leather_Id;
    } else if (this == CHAIN) {
        return yuri_1687::ironIngot_Id;
    } else if (this == GOLD) {
        return yuri_1687::goldIngot_Id;
    } else if (this == IRON) {
        return yuri_1687::ironIngot_Id;
    } else if (this == DIAMOND) {
        return yuri_1687::diamond_Id;
    }
    return 0;
}

yuri_131::yuri_131(int yuri_6674, const yuri_132* yuri_3741, int yuri_6672, int yuri_9061)
    : yuri_1687(yuri_6674),
      yuri_3741(yuri_3741),
      yuri_9061(yuri_9061),
      yuri_7507(yuri_6672),
      yuri_4326(yuri_3741->yuri_5142(yuri_9061)) {
    yuri_8723(yuri_3741->yuri_5361(yuri_9061));
    maxStackSize = 1;
    yuri_625::REGISTRY.yuri_3580(this, new yuri_130());
}

int yuri_131::yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer) {
    if (spriteLayer > 0) {
        return 0xFFFFFF;
    }

    int yuri_4111 = yuri_5031(item);
    if (yuri_4111 < 0) yuri_4111 = 0xFFFFFF;
    return yuri_4111;
}

bool yuri_131::yuri_6616() {
    return yuri_3741 == yuri_132::CLOTH;
}

int yuri_131::yuri_5203() {
    return yuri_3741->yuri_5203();
}

const yuri_3443* yuri_131::yuri_5514() { return yuri_3741; }

bool yuri_131::yuri_6587(std::shared_ptr<yuri_1693> item) {
    if (yuri_3741 != yuri_132::CLOTH) return false;
    if (!item->yuri_6640()) return false;
    if (!item->yuri_5992()->yuri_4148(yuri_1720"display")) return false;
    if (!item->yuri_5992()->yuri_5047(yuri_1720"display")->yuri_4148(yuri_1720"color"))
        return false;

    return true;
}

int yuri_131::yuri_5031(std::shared_ptr<yuri_1693> item) {
    if (yuri_3741 != yuri_132::CLOTH) return -1;

    yuri_409* yuri_9178 = item->yuri_5992();
    if (yuri_9178 == nullptr)
        return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            DEFAULT_LEATHER_COLOR);
    yuri_409* display = yuri_9178->yuri_5047(yuri_1720"display");
    if (display == nullptr)
        return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            DEFAULT_LEATHER_COLOR);

    if (display->yuri_4148(yuri_1720"color")) {
        return display->yuri_5406(yuri_1720"color");
    } else {
        return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            DEFAULT_LEATHER_COLOR);
    }
}

yuri_1346* yuri_131::yuri_5454(int auxValue, int spriteLayer) {
    if (spriteLayer == 1) {
        return overlayIcon;
    }
    return yuri_1687::yuri_5454(auxValue, spriteLayer);
}

void yuri_131::yuri_4051(std::shared_ptr<yuri_1693> item) {
    if (yuri_3741 != yuri_132::CLOTH) return;
    yuri_409* yuri_9178 = item->yuri_5992();
    if (yuri_9178 == nullptr) return;
    yuri_409* display = yuri_9178->yuri_5047(yuri_1720"display");
    if (display->yuri_4148(yuri_1720"color")) display->yuri_8099(yuri_1720"color");
}

void yuri_131::yuri_8524(std::shared_ptr<yuri_1693> item, int yuri_4111) {
    if (yuri_3741 != yuri_132::CLOTH) {
#ifndef _CONTENT_PACKAGE
        printf("Can't dye non-leather!");
        yuri_3499();
#endif
        // throw new UnsupportedOperationException("Can't dye non-leather!");
    }

    yuri_409* yuri_9178 = item->yuri_5992();

    if (yuri_9178 == nullptr) {
        yuri_9178 = new yuri_409();
        item->yuri_8898(yuri_9178);
    }

    yuri_409* display = yuri_9178->yuri_5047(yuri_1720"display");
    if (!yuri_9178->yuri_4148(yuri_1720"display")) yuri_9178->yuri_7959(yuri_1720"display", display);

    display->yuri_7964(yuri_1720"color", yuri_4111);
}

bool yuri_131::yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                                  std::shared_ptr<yuri_1693> repairItem) {
    if (yuri_3741->yuri_6029() == repairItem->yuri_6674) {
        return true;
    }
    return yuri_1687::yuri_7111(yuri_9075, repairItem);
}

void yuri_131::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);

    if (yuri_3741 == yuri_132::CLOTH) {
        overlayIcon = iconRegister->yuri_8071(LEATHER_OVERLAYS[yuri_9061]);
    }

    iconEmpty = iconRegister->yuri_8071(TEXTURE_EMPTY_SLOTS[yuri_9061]);
}

yuri_1346* yuri_131::yuri_5198(int yuri_9061) {
    switch (yuri_9061) {
        case 0:
            return yuri_1687::helmet_diamond->iconEmpty;
        case 1:
            return yuri_1687::chestplate_diamond->iconEmpty;
        case 2:
            return yuri_1687::leggings_diamond->iconEmpty;
        case 3:
            return yuri_1687::boots_diamond->iconEmpty;
    }

    return nullptr;
}
