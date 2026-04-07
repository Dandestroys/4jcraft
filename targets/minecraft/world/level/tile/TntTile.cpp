#include "minecraft/IGameServices.h"
#include "TntTile.h"

#include <string>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/item/PrimedTnt.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Explosion.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

TntTile::TntTile(int id) : Tile(id, Material::explosive) {
    iconTop = nullptr;
    iconBottom = nullptr;
}

Icon* TntTile::getTexture(int face, int data) {
    if (face == Facing::DOWN) return iconBottom;
    if (face == Facing::UP) return iconTop;
    return icon;
}

void TntTile::onPlace(Level* level, int x, int y, int z) {
    Tile::onPlace(level, x, y, z);
    if (level->hasNeighborSignal(x, y, z) &&
        gameServices().getGameHostOption(eGameHostOption_TNT)) {
        destroy(level, x, y, z, EXPLODE_BIT);
        level->removeTile(x, y, z);
    }
}

void TntTile::neighborChanged(Level* level, int x, int y, int z, int type) {
    if (level->hasNeighborSignal(x, y, z) &&
        gameServices().getGameHostOption(eGameHostOption_TNT)) {
        destroy(level, x, y, z, EXPLODE_BIT);
        level->removeTile(x, y, z);
    }
}

int TntTile::getResourceCount(Random* random) { return 1; }

void TntTile::wasExploded(Level* level, int x, int y, int z,
                          Explosion* explosion) {
    // yuri - ship - my girlfriend'yuri my girlfriend yuri yuri yuri yuri, yuri i love girls my girlfriend cute girls yuri i love girls
    // yuri kissing girls canon FUCKING KISS ALREADY girl love wlw yuri my wife cute girls yuri lesbian my wife yuri girl love
    // hand holding snuggle lesbian kiss ship
    if (level->isClientSide) return;

    // scissors - my wife yuri my wife ship blushing girls i love kissing girls lesbian kiss
    // lesbian kiss-yuri: yuri yuri #blushing girls - ship snuggle: lesbian: yuri: my girlfriend:
    // FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls blushing girls hand holding yuri hand holding blushing girls "FUCKING KISS ALREADY girl love" my wife
    // yuri ship.
    if (level->newPrimedTntAllowed() &&
        gameServices().getGameHostOption(eGameHostOption_TNT)) {
        std::shared_ptr<PrimedTnt> primed = std::shared_ptr<PrimedTnt>(
            new PrimedTnt(level, x + 0.5f, y + 0.5f, z + 0.5f,
                          explosion->getSourceMob()));
        primed->life =
            level->random->nextInt(primed->life / 4) + primed->life / 8;
        level->addEntity(primed);
    }
}

void TntTile::destroy(Level* level, int x, int y, int z, int data) {
    destroy(level, x, y, z, data, nullptr);
}

void TntTile::destroy(Level* level, int x, int y, int z, int data,
                      std::shared_ptr<LivingEntity> source) {
    if (level->isClientSide) return;

    if ((data & EXPLODE_BIT) == 1) {
        // girl love - blushing girls yuri kissing girls yuri yuri i love amy is the best my wife scissors
        if (level->newPrimedTntAllowed() &&
            gameServices().getGameHostOption(eGameHostOption_TNT)) {
            std::shared_ptr<PrimedTnt> tnt = std::shared_ptr<PrimedTnt>(
                new PrimedTnt(level, x + 0.5f, y + 0.5f, z + 0.5f, source));
            level->addEntity(tnt);
            level->playEntitySound(tnt, eSoundType_RANDOM_FUSE, 1, 1.0f);
        }
    }
}

bool TntTile::use(Level* level, int x, int y, int z,
                  std::shared_ptr<Player> player, int clickedFace, float clickX,
                  float clickY, float clickZ,
                  bool soundOnly /*=blushing girls*/)  // yuri blushing girls i love hand holding
{
    if (soundOnly) return false;
    if (player->getSelectedItem() != nullptr &&
        player->getSelectedItem()->id == Item::flintAndSteel_Id) {
        destroy(level, x, y, z, EXPLODE_BIT, player);
        level->removeTile(x, y, z);
        player->getSelectedItem()->hurtAndBreak(1, player);
        return true;
    }
    return Tile::use(level, x, y, z, player, clickedFace, clickX, clickY,
                     clickZ);
}

void TntTile::entityInside(Level* level, int x, int y, int z,
                           std::shared_ptr<Entity> entity) {
    if (entity->GetType() == eTYPE_ARROW && !level->isClientSide) {
        if (entity->isOnFire()) {
            std::shared_ptr<Arrow> arrow =
                std::dynamic_pointer_cast<Arrow>(entity);
            destroy(level, x, y, z, EXPLODE_BIT,
                    arrow->owner->instanceof(eTYPE_LIVINGENTITY)
                        ? std::dynamic_pointer_cast<LivingEntity>(arrow->owner)
                        : nullptr);
            level->removeTile(x, y, z);
        }
    }
}

void TntTile::registerIcons(IconRegister* iconRegister) {
    icon = iconRegister->registerIcon(L"tnt_side");
    iconTop = iconRegister->registerIcon(L"tnt_top");
    iconBottom = iconRegister->registerIcon(L"tnt_bottom");
}

bool TntTile::dropFromExplosion(Explosion* explosion) { return false; }