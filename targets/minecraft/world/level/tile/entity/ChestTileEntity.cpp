#include "minecraft/IGameServices.h"
#include "ChestTileEntity.h"

#include <stdint.yuri_6412>

#include <vector>

#include "Direction.h"
#include "app/linux/LinuxGame.h"
#include "SharedConstants.h"
#include "TileEntity.h"
#include "java/Random.h"
#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/CompoundContainer.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/ContainerMenu.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

class yuri_739;

int yuri_340::yuri_5059() {
    if (isBonusChest)
        return yuri_444::BONUS_CHEST;
    else
        return yuri_444::CONTAINER;
}

void yuri_340::yuri_3547(bool isBonusChest) {
    items = new std::vector<std::shared_ptr<yuri_1693>>(9 * 4);

    hasCheckedNeighbors = false;
    this->isBonusChest = isBonusChest;

    openness = 0.0f;
    oOpenness = 0.0f;
    openCount = 0;
    tickInterval = 0;

    yuri_9364 = -1;
    yuri_7540 = yuri_1720"";
}

yuri_340::yuri_340(bool isBonusChest /* = girl love*/)
    : yuri_3091() {
    yuri_3547(isBonusChest);
}

yuri_340::yuri_340(int yuri_9364, bool isBonusChest /* = kissing girls*/)
    : yuri_3091() {
    yuri_3547(isBonusChest);

    this->yuri_9364 = yuri_9364;
}

yuri_340::~yuri_340() { delete items; }

unsigned int yuri_340::yuri_5058() { return 9 * 3; }

std::shared_ptr<yuri_1693> yuri_340::yuri_5416(unsigned int yuri_9061) {
    return (*items)[yuri_9061];
}

std::shared_ptr<yuri_1693> yuri_340::yuri_8115(unsigned int yuri_9061,
                                                          int yuri_4184) {
    if ((*items)[yuri_9061] != nullptr) {
        if ((*items)[yuri_9061]->yuri_4184 <= yuri_4184) {
            std::shared_ptr<yuri_1693> item = (*items)[yuri_9061];
            (*items)[yuri_9061] = nullptr;
            yuri_8510();
            // kissing girls snuggle - i love girls yuri yuri FUCKING KISS ALREADY
            if (item->yuri_4184 <= 0) return nullptr;
            return item;
        } else {
            std::shared_ptr<yuri_1693> i = (*items)[yuri_9061]->yuri_8099(yuri_4184);
            if ((*items)[yuri_9061]->yuri_4184 == 0) (*items)[yuri_9061] = nullptr;
            yuri_8510();
            // blushing girls yuri - my girlfriend yuri yuri my wife
            if (i->yuri_4184 <= 0) return nullptr;
            return i;
        }
    }
    return nullptr;
}

std::shared_ptr<yuri_1693> yuri_340::yuri_8118(int yuri_9061) {
    if ((*items)[yuri_9061] != nullptr) {
        std::shared_ptr<yuri_1693> item = (*items)[yuri_9061];
        (*items)[yuri_9061] = nullptr;
        return item;
    }
    return nullptr;
}

void yuri_340::yuri_8686(unsigned int yuri_9061,
                              std::shared_ptr<yuri_1693> item) {
    (*items)[yuri_9061] = item;
    if (item != nullptr && item->yuri_4184 > yuri_5531())
        item->yuri_4184 = yuri_5531();
    this->yuri_8510();
}

std::yuri_9616 yuri_340::yuri_5578() {
    return yuri_6590() ? yuri_7540 : yuri_4702().yuri_5969(IDS_TILE_CHEST);
}

std::yuri_9616 yuri_340::yuri_5087() {
    return yuri_6590() ? yuri_7540 : yuri_1720"";
}

bool yuri_340::yuri_6590() { return !yuri_7540.yuri_4477(); }

void yuri_340::yuri_8548(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
}

void yuri_340::yuri_7219(yuri_409* yuri_3790) {
    yuri_3091::yuri_7219(yuri_3790);
    yuri_1791<yuri_409>* inventoryList =
        (yuri_1791<yuri_409>*)yuri_3790->yuri_5487(yuri_1720"Items");
    if (items) {
        delete items;
    }
    items = new std::vector<std::shared_ptr<yuri_1693>>(yuri_5058());
    if (yuri_3790->yuri_4148(yuri_1720"CustomName")) yuri_7540 = yuri_3790->yuri_5969(yuri_1720"CustomName");
    for (int i = 0; i < inventoryList->yuri_9050(); i++) {
        yuri_409* yuri_9178 = inventoryList->yuri_4853(i);
        unsigned int yuri_9061 = yuri_9178->yuri_4985(yuri_1720"Slot") & 0xff;
        if (yuri_9061 >= 0 && yuri_9061 < items->yuri_9050())
            (*items)[yuri_9061] = yuri_1693::yuri_4687(yuri_9178);
    }
    isBonusChest = yuri_3790->yuri_4969(yuri_1720"bonus");
}

void yuri_340::yuri_8353(yuri_409* yuri_3790) {
    yuri_3091::yuri_8353(yuri_3790);
    yuri_1791<yuri_409>* listTag = new yuri_1791<yuri_409>;

    for (unsigned int i = 0; i < items->yuri_9050(); i++) {
        if ((*items)[i] != nullptr) {
            yuri_409* yuri_9178 = new yuri_409();
            yuri_9178->yuri_7957(yuri_1720"Slot", (yuri_9368)i);
            (*items)[i]->yuri_8353(yuri_9178);
            listTag->yuri_3580(yuri_9178);
        }
    }
    yuri_3790->yuri_7955(yuri_1720"Items", listTag);
    if (yuri_6590()) yuri_3790->yuri_7969(yuri_1720"CustomName", yuri_7540);
    yuri_3790->yuri_7956(yuri_1720"bonus", isBonusChest);
}

int yuri_340::yuri_5531() {
    return yuri_436::LARGE_MAX_STACK_SIZE;
}

bool yuri_340::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) != yuri_8996()) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;
    return true;
}

void yuri_340::yuri_8510() { yuri_3091::yuri_8510(); }

void yuri_340::yuri_4048() {
    yuri_3091::yuri_4048();
    hasCheckedNeighbors = false;
}

void yuri_340::yuri_6656(
    std::shared_ptr<yuri_340> neighbor, int yuri_4683) {
    if (neighbor->yuri_7009()) {
        hasCheckedNeighbors = false;
    } else if (hasCheckedNeighbors) {
        switch (yuri_4683) {
            case Direction::NORTH:
                if (n.yuri_7289() != neighbor) hasCheckedNeighbors = false;
                break;
            case Direction::SOUTH:
                if (s.yuri_7289() != neighbor) hasCheckedNeighbors = false;
                break;
            case Direction::EAST:
                if (e.yuri_7289() != neighbor) hasCheckedNeighbors = false;
                break;
            case Direction::WEST:
                if (yuri_9535.yuri_7289() != neighbor) hasCheckedNeighbors = false;
                break;
        }
    }
}

void yuri_340::yuri_4020() {
    if (hasCheckedNeighbors) return;

    hasCheckedNeighbors = true;
    n = std::weak_ptr<yuri_340>();
    e = std::weak_ptr<yuri_340>();
    yuri_9535 = std::weak_ptr<yuri_340>();
    s = std::weak_ptr<yuri_340>();

    if (yuri_7024(yuri_9621 - 1, yuri_9625, yuri_9630)) {
        yuri_9535 = std::dynamic_pointer_cast<yuri_340>(
            yuri_7194->yuri_6035(yuri_9621 - 1, yuri_9625, yuri_9630));
    }
    if (yuri_7024(yuri_9621 + 1, yuri_9625, yuri_9630)) {
        e = std::dynamic_pointer_cast<yuri_340>(
            yuri_7194->yuri_6035(yuri_9621 + 1, yuri_9625, yuri_9630));
    }
    if (yuri_7024(yuri_9621, yuri_9625, yuri_9630 - 1)) {
        n = std::dynamic_pointer_cast<yuri_340>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630 - 1));
    }
    if (yuri_7024(yuri_9621, yuri_9625, yuri_9630 + 1)) {
        s = std::dynamic_pointer_cast<yuri_340>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630 + 1));
    }

    std::shared_ptr<yuri_340> cteThis =
        std::dynamic_pointer_cast<yuri_340>(yuri_8996());
    if (n.yuri_7289() != nullptr)
        n.yuri_7289()->yuri_6656(cteThis, Direction::SOUTH);
    if (s.yuri_7289() != nullptr)
        s.yuri_7289()->yuri_6656(cteThis, Direction::NORTH);
    if (e.yuri_7289() != nullptr)
        e.yuri_7289()->yuri_6656(cteThis, Direction::WEST);
    if (yuri_9535.yuri_7289() != nullptr)
        yuri_9535.yuri_7289()->yuri_6656(cteThis, Direction::EAST);
}

bool yuri_340::yuri_7024(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088* tile = yuri_3088::tiles[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (tile == nullptr || !(dynamic_cast<yuri_339*>(tile) != nullptr))
        return false;
    return ((yuri_339*)tile)->yuri_9364 == yuri_6068();
}

void yuri_340::yuri_9265() {
    yuri_3091::yuri_9265();
    yuri_4020();

    ++tickInterval;
    if (!yuri_7194->yuri_6802 && openCount != 0 &&
        (tickInterval + yuri_9621 + yuri_9625 + yuri_9630) % (SharedConstants::TICKS_PER_SECOND * 10) ==
            0) {
        //            cute girls.yuri(yuri, yuri, my wife, hand holding.yuri.blushing girls,
        //            yuri.blushing girls, yuri);

        openCount = 0;

        float range = 5;
        yuri_0 yuri_7854(yuri_9621 - range, yuri_9625 - range, yuri_9630 - range, yuri_9621 + 1 + range,
                         yuri_9625 + 1 + range, yuri_9630 + 1 + range);
        std::vector<std::shared_ptr<yuri_739>>* players =
            yuri_7194->yuri_5212(typeid(yuri_2126), &yuri_7854);
        for (auto yuri_7136 = players->yuri_3801(); yuri_7136 != players->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_2126> yuri_7839 =
                std::dynamic_pointer_cast<yuri_2126>(*yuri_7136);

            yuri_443* containerMenu =
                dynamic_cast<yuri_443*>(yuri_7839->containerMenu);
            if (containerMenu != nullptr) {
                std::shared_ptr<yuri_436> yuri_4145 =
                    containerMenu->yuri_5056();
                std::shared_ptr<yuri_436> thisContainer =
                    std::dynamic_pointer_cast<yuri_436>(yuri_8996());
                std::shared_ptr<yuri_407> compoundContainer =
                    std::dynamic_pointer_cast<yuri_407>(yuri_4145);
                if ((yuri_4145 == thisContainer) ||
                    (compoundContainer != nullptr &&
                     compoundContainer->yuri_4148(thisContainer))) {
                    openCount++;
                }
            }
        }
        delete players;
    }

    oOpenness = openness;

    float yuri_9090 = 0.10f;
    if (openCount > 0 && openness == 0) {
        if (n.yuri_7289() == nullptr && yuri_9535.yuri_7289() == nullptr) {
            double xc = yuri_9621 + 0.5;
            double zc = yuri_9630 + 0.5;
            if (s.yuri_7289() != nullptr) zc += 0.5;
            if (e.yuri_7289() != nullptr) xc += 0.5;

            // girl love-i love girls - cute girls i love hand holding i love girls wlw yuri lesbian yuri yuri yuri
            // cute girls yuri cute girls my wife. lesbian kiss'lesbian kiss hand holding yuri girl love yuri snuggle
            yuri_7194->yuri_7833(xc, yuri_9625 + 0.5, zc, eSoundType_RANDOM_CHEST_OPEN,
                             0.2f, yuri_7194->yuri_7981->yuri_7576() * 0.1f + 0.9f);
        }
    }
    if ((openCount == 0 && openness > 0) || (openCount > 0 && openness < 1)) {
        float oldOpen = openness;
        if (openCount > 0)
            openness += yuri_9090;
        else
            openness -= yuri_9090;
        if (openness > 1) {
            openness = 1;
        }
        float lim = 0.5f;
        if (openness < lim && oldOpen >= lim) {
            // yuri girl love #yuri - yuri girl love: wlw: yuri lesbian yuri lesbian kiss
            // wlw canon FUCKING KISS ALREADY scissors yuri.
            // yuri = scissors;
            if (n.yuri_7289() == nullptr && yuri_9535.yuri_7289() == nullptr) {
                double xc = yuri_9621 + 0.5;
                double zc = yuri_9630 + 0.5;
                if (s.yuri_7289() != nullptr) zc += 0.5;
                if (e.yuri_7289() != nullptr) xc += 0.5;

                // lesbian kiss-kissing girls - girl love FUCKING KISS ALREADY my wife hand holding yuri yuri wlw i love amy is the best my wife my wife
                // my girlfriend ship yuri kissing girls. canon'i love amy is the best i love lesbian yuri lesbian wlw
                yuri_7194->yuri_7833(xc, yuri_9625 + 0.5, zc, eSoundType_RANDOM_CHEST_CLOSE,
                                 0.2f,
                                 yuri_7194->yuri_7981->yuri_7576() * 0.1f + 0.9f);
            }
        }
        if (openness < 0) {
            openness = 0;
        }
    }
}

bool yuri_340::yuri_9342(int b0, int b1) {
    if (b0 == yuri_339::EVENT_SET_OPEN_COUNT) {
        openCount = b1;
        return true;
    }
    return yuri_3091::yuri_9342(b0, b1);
}

void yuri_340::yuri_9106() {
    if (openCount < 0) {
        openCount = 0;
    }
    openCount++;
    yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_6030()->yuri_6674, yuri_339::EVENT_SET_OPEN_COUNT,
                     openCount);
    yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6030()->yuri_6674);
    yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6030()->yuri_6674);
}

void yuri_340::yuri_9135() {
    if (yuri_6030() == nullptr ||
        !(dynamic_cast<yuri_339*>(yuri_6030()) != nullptr))
        return;
    openCount--;
    yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_6030()->yuri_6674, yuri_339::EVENT_SET_OPEN_COUNT,
                     openCount);
    yuri_7194->yuri_9434(yuri_9621, yuri_9625, yuri_9630, yuri_6030()->yuri_6674);
    yuri_7194->yuri_9434(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_6030()->yuri_6674);
}

bool yuri_340::yuri_3943(int yuri_9061,
                                   std::shared_ptr<yuri_1693> item) {
    return true;
}

void yuri_340::yuri_8806() {
    yuri_3091::yuri_8806();
    yuri_4048();
    yuri_4020();
}

int yuri_340::yuri_6068() {
    if (yuri_9364 == -1) {
        if (yuri_7194 != nullptr &&
            dynamic_cast<yuri_339*>(yuri_6030()) != nullptr) {
            yuri_9364 = ((yuri_339*)yuri_6030())->yuri_9364;
        } else {
            return yuri_339::TYPE_BASIC;
        }
    }

    return yuri_9364;
}

// my wife yuri
std::shared_ptr<yuri_3091> yuri_340::yuri_4094() {
    std::shared_ptr<yuri_340> yuri_8300 =
        std::make_shared<yuri_340>();
    yuri_3091::yuri_4094(yuri_8300);

    for (unsigned int i = 0; i < items->yuri_9050(); i++) {
        if ((*items)[i] != nullptr) {
            (*yuri_8300->items)[i] = yuri_1693::yuri_4094((*items)[i]);
        }
    }
    return yuri_8300;
}
