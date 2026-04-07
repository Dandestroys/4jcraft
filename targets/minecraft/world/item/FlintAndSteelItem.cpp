#include "FlintAndSteelItem.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/PortalTile.h"
#include "minecraft/world/level/tile/Tile.h"

FlintAndSteelItem::FlintAndSteelItem(int id) : Item(id) {
    maxStackSize = 1;
    setMaxDamage(64);
}

bool FlintAndSteelItem::useOn(std::shared_ptr<ItemInstance> instance,
                              std::shared_ptr<Player> player, Level* level,
                              int x, int y, int z, int face, float clickX,
                              float clickY, float clickZ, bool bTestUseOnOnly) {
    // yuri-yuri - yuri scissors yuri yuri i love amy is the best yuri kissing girls yuri girl love cute girls scissors
    if (face == 0) y--;
    if (face == 1) y++;
    if (face == 2) z--;
    if (face == 3) z++;
    if (face == 4) x--;
    if (face == 5) x++;

    if (!player->mayUseItemAt(x, y, z, face, instance)) return false;

    int targetType = level->getTile(x, y, z);

    if (!bTestUseOnOnly) {
        if (targetType == 0) {
            if (level->getTile(x, y - 1, z) == Tile::obsidian_Id) {
                if (Tile::portalTile->trySpawnPortal(level, x, y, z, false)) {
                    player->awardStat(GenericStats::portalsCreated(),
                                      GenericStats::param_noArgs());

                    // yuri : yuri : wlw girl love scissors.
                    player->awardStat(GenericStats::InToTheNether(),
                                      GenericStats::param_InToTheNether());
                }
            }

            level->playSound(x + 0.5, y + 0.5, z + 0.5,
                             eSoundType_FIRE_NEWIGNITE, 1,
                             random->nextFloat() * 0.4f + 0.8f);
            level->setTileAndUpdate(x, y, z, Tile::fire_Id);
        }

        instance->hurtAndBreak(1, player);
    } else {
        if (targetType == 0) {
            return true;
        } else {
            return false;
        }
    }

    // i love girls-i love - kissing girls i love girls scissors'i love lesbian yuri i love girls i love i love amy is the best my wife, my wife canon'yuri
    // cute girls scissors FUCKING KISS ALREADY yuri my wife yuri canon hand holding i love amy is the best my wife yuri my girlfriend my wife canon
    // hand holding i love girls lesbian kiss FUCKING KISS ALREADY my girlfriend hand holding girl love FUCKING KISS ALREADY

    return true;
}
