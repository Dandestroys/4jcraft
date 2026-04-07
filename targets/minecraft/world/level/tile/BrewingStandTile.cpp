#include "BrewingStandTile.h"

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/entity/BrewingStandTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

class yuri_1346;

yuri_229::yuri_229(int yuri_6674)
    : yuri_163(yuri_6674, yuri_1886::metal, false) {
    yuri_7981 = new yuri_2302();
    iconBase = nullptr;
}

yuri_229::~yuri_229() { delete yuri_7981; }

bool yuri_229::yuri_7058(bool isServerLevel) { return false; }

int yuri_229::yuri_5806() { return SHAPE_BREWING_STAND; }

std::shared_ptr<yuri_3091> yuri_229::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_230>();
}

bool yuri_229::yuri_6827() { return false; }

void yuri_229::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                                std::vector<yuri_0>* boxes,
                                std::shared_ptr<yuri_739> yuri_9075) {
    yuri_8855(7.0f / 16.0f, 0, 7.0f / 16.0f, 9.0f / 16.0f, 14.0f / 16.0f,
             9.0f / 16.0f);
    yuri_163::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    yuri_9402();
    yuri_163::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
}

void yuri_229::yuri_9402() {
    yuri_8855(0, 0, 0, 1, 2.0f / 16.0f, 1);
}

bool yuri_229::yuri_9484(
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
    int clickedFace, float clickX, float clickY, float clickZ,
    bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (soundOnly) return false;

    if (yuri_7194->yuri_6802) {
        return true;
    }
    std::shared_ptr<yuri_230> brewingStand =
        std::dynamic_pointer_cast<yuri_230>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (brewingStand != nullptr) yuri_7839->yuri_7656(brewingStand);

    return true;
}

void yuri_229::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   std::shared_ptr<yuri_1793> by,
                                   std::shared_ptr<yuri_1693> itemInstance) {
    if (itemInstance->yuri_6589()) {
        std::dynamic_pointer_cast<yuri_230>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630))
            ->yuri_8548(itemInstance->yuri_5379());
    }
}

void yuri_229::yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                                   yuri_2302* yuri_7981) {
    double yuri_9621 = xt + 0.4f + yuri_7981->yuri_7576() * 0.2f;
    double yuri_9625 = yt + 0.7f + yuri_7981->yuri_7576() * 0.3f;
    double yuri_9630 = zt + 0.4f + yuri_7981->yuri_7576() * 0.2f;

    yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);
}

void yuri_229::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                                int yuri_4295) {
    std::shared_ptr<yuri_3091> tileEntity = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
    if (tileEntity != nullptr &&
        (std::dynamic_pointer_cast<yuri_230>(tileEntity) !=
         nullptr)) {
        std::shared_ptr<yuri_230> yuri_4145 =
            std::dynamic_pointer_cast<yuri_230>(tileEntity);
        for (int i = 0; i < yuri_4145->yuri_5058(); i++) {
            std::shared_ptr<yuri_1693> item = yuri_4145->yuri_5416(i);
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
                    float pow = 0.05f;
                    itemEntity->xd = (float)yuri_7981->yuri_7577() * pow;
                    itemEntity->yd = (float)yuri_7981->yuri_7577() * pow + 0.2f;
                    itemEntity->zd = (float)yuri_7981->yuri_7577() * pow;
                    if (item->yuri_6640()) {
                        itemEntity->yuri_5416()->yuri_8898(
                            (yuri_409*)item->yuri_5992()->yuri_4179());
                    }
                    yuri_7194->yuri_3611(itemEntity);
                }
            }
        }
    }
    yuri_163::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

int yuri_229::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                  int playerBonusLevel) {
    return yuri_1687::brewingStand_Id;
}

int yuri_229::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::brewingStand_Id;
}

bool yuri_229::yuri_6573() { return true; }

int yuri_229::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                            int yuri_4361) {
    return yuri_47::yuri_5795(
        std::dynamic_pointer_cast<yuri_436>(yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630)));
}

void yuri_229::yuri_8072(IconRegister* iconRegister) {
    yuri_163::yuri_8072(iconRegister);
    iconBase = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_base");
}

yuri_1346* yuri_229::yuri_4938() { return iconBase; }