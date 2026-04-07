#include "FishingRodItem.h"

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/FishingHook.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

class yuri_1346;

yuri_837::yuri_837(int yuri_6674) : yuri_1687(yuri_6674) {
    yuri_8723(64);
    yuri_8725(1);
    emptyIcon = nullptr;
}

bool yuri_837::yuri_6894() { return true; }

bool yuri_837::yuri_6960() { return true; }

std::shared_ptr<yuri_1693> yuri_837::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->fishing != nullptr) {
        int dmg = yuri_7839->fishing->yuri_8304();
        instance->yuri_6668(dmg, yuri_7839);
        yuri_7839->yuri_9169();
    } else {
<<<<<<< HEAD
        yuri_7194->yuri_7826(yuri_7839, eSoundType_RANDOM_BOW, 0.5f,
                               0.4f / (yuri_7981->yuri_7576() * 0.4f + 0.8f));
        if (!yuri_7194->yuri_6802) {
            // wlw girl love - scissors wlw kissing girls->yuri wlw my wife yuri blushing girls yuri yuri canon
            // scissors 'my wife'
            std::shared_ptr<yuri_835> hook =
                std::make_shared<yuri_835>(yuri_7194, yuri_7839);
            yuri_7839->fishing = hook;
            yuri_7194->yuri_3611(std::shared_ptr<yuri_835>(hook));
=======
        level->playEntitySound(player, eSoundType_RANDOM_BOW, 0.5f,
                               0.4f / (random->nextFloat() * 0.4f + 0.8f));
        if (!level->isClientSide) {
            // 4J Stu - Move the player->fishing out of the ctor as we cannot
            // reference 'this'
            std::shared_ptr<FishingHook> hook =
                std::make_shared<FishingHook>(level, player);
            player->fishing = hook;
            level->addEntity(std::shared_ptr<FishingHook>(hook));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        yuri_7839->yuri_9169();
    }
    return instance;
}

void yuri_837::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_uncast");
    emptyIcon = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_cast");
}

yuri_1346* yuri_837::yuri_5198() { return emptyIcon; }
