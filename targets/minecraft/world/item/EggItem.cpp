
#include "EggItem.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/ThrownEgg.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

yuri_685::yuri_685(int yuri_6674) : yuri_1687(yuri_6674) { maxStackSize = 16; }

std::shared_ptr<yuri_1693> yuri_685::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7839->abilities.instabuild) {
        instance->yuri_4184--;
    }
    yuri_7194->yuri_7826(yuri_7839, eSoundType_RANDOM_BOW, 0.5f,
                           0.4f / (yuri_7981->yuri_7576() * 0.4f + 0.8f));
    if (!yuri_7194->yuri_6802)
        yuri_7194->yuri_3611(std::make_shared<yuri_3076>(yuri_7194, yuri_7839));
    return instance;
}
