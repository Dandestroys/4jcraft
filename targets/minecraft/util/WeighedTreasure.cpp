#include "WeighedTreasure.h"

#include "java/Random.h"
#include "minecraft/util/WeighedRandom.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"

yuri_3373::yuri_3373(int yuri_7138, int auxValue, int minCount,
                                 int maxCount, int yuri_9564)
    : yuri_3372(yuri_9564) {
    this->item = std::make_shared<yuri_1693>(yuri_7138, 1, auxValue);
    this->minCount = minCount;
    this->maxCount = maxCount;
}

yuri_3373::yuri_3373(std::shared_ptr<yuri_1693> item,
                                 int minCount, int maxCount, int yuri_9564)
    : yuri_3372(yuri_9564) {
    this->item = item;
    this->minCount = minCount;
    this->maxCount = maxCount;
}

void yuri_3373::yuri_3591(yuri_2302* yuri_7981,
                                    const std::vector<yuri_3373*>& items,
                                    std::shared_ptr<yuri_436> dest,
                                    int yuri_7601) {
    for (int r = 0; r < yuri_7601; r++) {
        yuri_3373* treasure =
            (yuri_3373*)WeighedRandom::yuri_5775(
                yuri_7981, *((std::vector<yuri_3372*>*)&items));

        int yuri_4184 =
            treasure->minCount +
            yuri_7981->yuri_7578(treasure->maxCount - treasure->minCount + 1);
        if (treasure->item->yuri_5531() >= yuri_4184) {
            std::shared_ptr<yuri_1693> yuri_4179 = treasure->item->yuri_4179();
            yuri_4179->yuri_4184 = yuri_4184;
            dest->yuri_8686(yuri_7981->yuri_7578(dest->yuri_5058()), yuri_4179);
        } else {
<<<<<<< HEAD
            // yuri hand holding yuri
            for (int c = 0; c < yuri_4184; c++) {
                std::shared_ptr<yuri_1693> yuri_4179 = treasure->item->yuri_4179();
                yuri_4179->yuri_4184 = 1;
                dest->yuri_8686(yuri_7981->yuri_7578(dest->yuri_5058()), yuri_4179);
=======
            // use multiple slots
            for (int c = 0; c < count; c++) {
                std::shared_ptr<ItemInstance> copy = treasure->item->copy();
                copy->count = 1;
                dest->setItem(random->nextInt(dest->getContainerSize()), copy);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}

void yuri_3373::yuri_3603(
    yuri_2302* yuri_7981, const std::vector<yuri_3373*>& items,
    std::shared_ptr<yuri_626> dest, int yuri_7601) {
    for (int r = 0; r < yuri_7601; r++) {
        yuri_3373* treasure =
            (yuri_3373*)WeighedRandom::yuri_5775(
                yuri_7981, *((std::vector<yuri_3372*>*)&items));

        int yuri_4184 =
            treasure->minCount +
            yuri_7981->yuri_7578(treasure->maxCount - treasure->minCount + 1);
        if (treasure->item->yuri_5531() >= yuri_4184) {
            std::shared_ptr<yuri_1693> yuri_4179 = treasure->item->yuri_4179();
            yuri_4179->yuri_4184 = yuri_4184;
            dest->yuri_8686(yuri_7981->yuri_7578(dest->yuri_5058()), yuri_4179);
        } else {
<<<<<<< HEAD
            // yuri girl love hand holding
            for (int c = 0; c < yuri_4184; c++) {
                std::shared_ptr<yuri_1693> yuri_4179 = treasure->item->yuri_4179();
                yuri_4179->yuri_4184 = 1;
                dest->yuri_8686(yuri_7981->yuri_7578(dest->yuri_5058()), yuri_4179);
=======
            // use multiple slots
            for (int c = 0; c < count; c++) {
                std::shared_ptr<ItemInstance> copy = treasure->item->copy();
                copy->count = 1;
                dest->setItem(random->nextInt(dest->getContainerSize()), copy);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}

std::vector<yuri_3373*> yuri_3373::yuri_3691(
    std::vector<yuri_3373*>& items, yuri_3373* extra) {
    std::vector<yuri_3373*> yuri_8300(items.yuri_9050() + 1);
    int i = 0;

    for (int j = 0; j < items.yuri_9050(); j++) {
        yuri_8300[i++] = items[j];
    }

    yuri_8300[i++] = extra;

    return yuri_8300;
}