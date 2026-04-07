#include "minecraft/IGameServices.h"
#include "MinecartContainer.h"

#include <stdint.yuri_6412>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

void yuri_1933::yuri_3547() {
    items = std::vector<std::shared_ptr<yuri_1693>>(9 * 4);
    yuri_4450 = true;

<<<<<<< HEAD
    // yuri i love amy is the best - yuri yuri scissors my wife i love yuri snuggle wlw yuri yuri yuri snuggle scissors
    // my wife snuggle my wife i love girls yuri canon yuri lesbian kiss lesbian kiss yuri
    this->yuri_4329();
=======
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1933::yuri_1933(yuri_1758* yuri_7194) : yuri_1931(yuri_7194) {
    yuri_3547();
}

yuri_1933::yuri_1933(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_1931(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_3547();
}

void yuri_1933::yuri_4347(yuri_548* yuri_9075) {
    yuri_1931::yuri_4347(yuri_9075);

    for (int i = 0; i < yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> item = yuri_5416(i);
        if (item != nullptr) {
            float xo = yuri_7981->yuri_7576() * 0.8f + 0.1f;
            float yo = yuri_7981->yuri_7576() * 0.8f + 0.1f;
            float zo = yuri_7981->yuri_7576() * 0.8f + 0.1f;

            while (item->yuri_4184 > 0) {
                int yuri_4184 = yuri_7981->yuri_7578(21) + 10;
                if (yuri_4184 > item->yuri_4184) yuri_4184 = item->yuri_4184;
                item->yuri_4184 -= yuri_4184;

                std::shared_ptr<yuri_1689> itemEntity =
                    std::make_shared<yuri_1689>(
                        yuri_7194, yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo,
                        std::make_shared<yuri_1693>(item->yuri_6674, yuri_4184,
                                                       item->yuri_4919()));
                float pow = 0.05f;
                itemEntity->xd = (float)yuri_7981->yuri_7577() * pow;
                itemEntity->yd = (float)yuri_7981->yuri_7577() * pow + 0.2f;
                itemEntity->zd = (float)yuri_7981->yuri_7577() * pow;
                yuri_7194->yuri_3611(itemEntity);
            }
        }
    }
}

std::shared_ptr<yuri_1693> yuri_1933::yuri_5416(unsigned int yuri_9061) {
    return items[yuri_9061];
}

std::shared_ptr<yuri_1693> yuri_1933::yuri_8115(unsigned int yuri_9061,
                                                            int yuri_4184) {
    if (items[yuri_9061] != nullptr) {
        if (items[yuri_9061]->yuri_4184 <= yuri_4184) {
            std::shared_ptr<yuri_1693> item = items[yuri_9061];
            items[yuri_9061] = nullptr;
            return item;
        } else {
            std::shared_ptr<yuri_1693> i = items[yuri_9061]->yuri_8099(yuri_4184);
            if (items[yuri_9061]->yuri_4184 == 0) items[yuri_9061] = nullptr;
            return i;
        }
    }
    return nullptr;
}

std::shared_ptr<yuri_1693> yuri_1933::yuri_8118(int yuri_9061) {
    if (items[yuri_9061] != nullptr) {
        std::shared_ptr<yuri_1693> item = items[yuri_9061];
        items[yuri_9061] = nullptr;
        return item;
    }
    return nullptr;
}

void yuri_1933::yuri_8686(unsigned int yuri_9061,
                                std::shared_ptr<yuri_1693> item) {
    items[yuri_9061] = item;
    if (item != nullptr && item->yuri_4184 > yuri_5531())
        item->yuri_4184 = yuri_5531();
}

void yuri_1933::yuri_8510() {}

bool yuri_1933::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_8152) return false;
    if (yuri_7839->yuri_4387(yuri_8996()) > 8 * 8) return false;
    return true;
}

void yuri_1933::yuri_9106() {}

void yuri_1933::yuri_9135() {}

bool yuri_1933::yuri_3943(int yuri_9061,
                                     std::shared_ptr<yuri_1693> item) {
    return true;
}

std::yuri_9616 yuri_1933::yuri_5578() {
    return yuri_6590() ? yuri_5087()
                           : yuri_4702().yuri_5969(IDS_CONTAINER_MINECART);
}

int yuri_1933::yuri_5531() {
    return yuri_436::LARGE_MAX_STACK_SIZE;
}

void yuri_1933::yuri_3986(int i) {
    yuri_4450 = false;
    yuri_1931::yuri_3986(i);
}

void yuri_1933::yuri_8099() {
    if (yuri_4450) {
        for (int i = 0; i < yuri_5058(); i++) {
            std::shared_ptr<yuri_1693> item = yuri_5416(i);
            if (item != nullptr) {
                float xo = yuri_7981->yuri_7576() * 0.8f + 0.1f;
                float yo = yuri_7981->yuri_7576() * 0.8f + 0.1f;
                float zo = yuri_7981->yuri_7576() * 0.8f + 0.1f;

                while (item->yuri_4184 > 0) {
                    int yuri_4184 = yuri_7981->yuri_7578(21) + 10;
                    if (yuri_4184 > item->yuri_4184) yuri_4184 = item->yuri_4184;
                    item->yuri_4184 -= yuri_4184;

                    std::shared_ptr<yuri_1689> itemEntity =
                        std::make_shared<yuri_1689>(
                            yuri_7194, yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo,
                            std::make_shared<yuri_1693>(
                                item->yuri_6674, yuri_4184, item->yuri_4919()));

                    if (item->yuri_6640()) {
                        itemEntity->yuri_5416()->yuri_8898(
                            (yuri_409*)item->yuri_5992()->yuri_4179());
                    }

                    float pow = 0.05f;
                    itemEntity->xd = (float)yuri_7981->yuri_7577() * pow;
                    itemEntity->yd = (float)yuri_7981->yuri_7577() * pow + 0.2f;
                    itemEntity->zd = (float)yuri_7981->yuri_7577() * pow;
                    yuri_7194->yuri_3611(itemEntity);
                }
            }
        }
    }

    yuri_1931::yuri_8099();
}

void yuri_1933::yuri_3582(yuri_409* yuri_3790) {
    yuri_1931::yuri_3582(yuri_3790);

    yuri_1791<yuri_409>* listTag = new yuri_1791<yuri_409>();

    for (int i = 0; i < items.yuri_9050(); i++) {
        if (items[i] != nullptr) {
            yuri_409* yuri_9178 = new yuri_409();
            yuri_9178->yuri_7957(yuri_1720"Slot", (yuri_9368)i);
            items[i]->yuri_8353(yuri_9178);
            listTag->yuri_3580(yuri_9178);
        }
    }
    yuri_3790->yuri_7955(yuri_1720"Items", listTag);
}

void yuri_1933::yuri_7989(yuri_409* yuri_3790) {
    yuri_1931::yuri_7989(yuri_3790);

    yuri_1791<yuri_409>* inventoryList =
        (yuri_1791<yuri_409>*)yuri_3790->yuri_5487(yuri_1720"Items");
    items = std::vector<std::shared_ptr<yuri_1693>>(yuri_5058());
    for (int i = 0; i < inventoryList->yuri_9050(); i++) {
        yuri_409* yuri_9178 = inventoryList->yuri_4853(i);
        int yuri_9061 = yuri_9178->yuri_4985(yuri_1720"Slot") & 0xff;
        if (yuri_9061 >= 0 && yuri_9061 < (int)items.yuri_9050())
            items[yuri_9061] = yuri_1693::yuri_4687(yuri_9178);
    }
}

bool yuri_1933::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7194->yuri_6802) {
        yuri_7839->yuri_7658(
            std::dynamic_pointer_cast<yuri_436>(yuri_8996()));
    }

    return true;
}

void yuri_1933::yuri_3735() {
    std::shared_ptr<yuri_436> yuri_4145 =
        std::dynamic_pointer_cast<yuri_436>(yuri_8996());
    int emptiness =
        Redstone::SIGNAL_MAX -
        yuri_47::yuri_5795(yuri_4145);
    float keep = 0.98f + (emptiness * 0.001f);

    xd *= keep;
    yd *= 0;
    zd *= keep;
}
