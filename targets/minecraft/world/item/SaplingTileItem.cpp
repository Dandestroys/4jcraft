#include "SaplingTileItem.h"

#include <memory>

#include "TileItem.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/SaplingPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2499::yuri_2499(int yuri_6674) : yuri_3098(yuri_6674) {
    yuri_8723(0);
    yuri_8884(true);
}

int yuri_2499::yuri_5464(int auxValue) { return auxValue; }

yuri_1346* yuri_2499::yuri_5385(int itemAuxValue) {
    return yuri_3088::sapling->yuri_6007(0, itemAuxValue);
}

<<<<<<< HEAD
// canon yuri yuri FUCKING KISS ALREADY lesbian snuggle yuri snuggle lesbian ship yuri
unsigned int yuri_2499::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    int auxValue = instance->yuri_4919();
    if (auxValue < 0 || auxValue >= yuri_2498::SAPLING_NAMES_SIZE) {
=======
// 4J brought forward to have unique names for different sapling types
unsigned int SaplingTileItem::getDescriptionId(
    std::shared_ptr<ItemInstance> instance) {
    int auxValue = instance->getAuxValue();
    if (auxValue < 0 || auxValue >= Sapling::SAPLING_NAMES_SIZE) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        auxValue = 0;
    }
    return yuri_2498::SAPLING_NAMES[auxValue];
}