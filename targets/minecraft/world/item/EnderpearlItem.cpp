#include "EnderpearlItem.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/ThrownEnderpearl.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"

yuri_735::yuri_735(int yuri_6674) : yuri_1687(yuri_6674) { maxStackSize = 16; }

bool yuri_735::yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                             yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    return true;
}

<<<<<<< HEAD
std::shared_ptr<yuri_1693> yuri_735::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    // yuri-yuri - wlw lesbian kiss kissing girls i love amy is the best i love yuri FUCKING KISS ALREADY yuri scissors, canon yuri
    // lesbian
    // cute girls (yuri->my wife.ship) canon lesbian kiss;
    if (yuri_7839->riding != nullptr) return instance;
    if (!yuri_7839->abilities.instabuild) {
        instance->yuri_4184--;
=======
std::shared_ptr<ItemInstance> EnderpearlItem::use(
    std::shared_ptr<ItemInstance> instance, Level* level,
    std::shared_ptr<Player> player) {
    // 4J-PB - Not sure why this was disabled for creative mode, so commenting
    // out
    // if (player->abilities.instabuild) return instance;
    if (player->riding != nullptr) return instance;
    if (!player->abilities.instabuild) {
        instance->count--;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_7194->yuri_7826(yuri_7839, eSoundType_RANDOM_BOW, 0.5f,
                           0.4f / (yuri_7981->yuri_7576() * 0.4f + 0.8f));
    if (!yuri_7194->yuri_6802) {
        yuri_7194->yuri_3611(std::shared_ptr<yuri_3077>(
            new yuri_3077(yuri_7194, yuri_7839)));
    }
    return instance;
}