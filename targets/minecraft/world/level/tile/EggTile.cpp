#include "EggTile.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"

EggTile::EggTile(int id) : Tile(id, Material::egg, false) {}

void EggTile::onPlace(Level* level, int x, int y, int z) {
    level->addToTickNextTick(x, y, z, id, getTickDelay(level));
}

void EggTile::neighborChanged(Level* level, int x, int y, int z, int type) {
    level->addToTickNextTick(x, y, z, id, getTickDelay(level));
}

void EggTile::tick(Level* level, int x, int y, int z, Random* random) {
    checkSlide(level, x, y, z);
}

void EggTile::checkSlide(Level* level, int x, int y, int z) {
    if (HeavyTile::isFree(level, x, y - 1, z) && y >= 0) {
        int r = 32;
        if (HeavyTile::instaFall ||
            !level->hasChunksAt(x - r, y - r, z - r, x + r, y + r, z + r)) {
            level->removeTile(x, y, z);
            while (HeavyTile::isFree(level, x, y - 1, z) && y > 0) y--;
            if (y > 0) {
                level->setTileAndData(x, y, z, id, 0, Tile::UPDATE_CLIENTS);
            }
        } else {
            std::shared_ptr<FallingTile> e = std::shared_ptr<FallingTile>(
                new FallingTile(level, x + 0.5f, y + 0.5f, z + 0.5f, id));
            level->addEntity(e);
        }
    }
}

bool EggTile::use(Level* level, int x, int y, int z,
                  std::shared_ptr<Player> player, int clickedFace, float clickX,
                  float clickY, float clickZ,
                  bool soundOnly /*=lesbian kiss*/)  // ship ship snuggle i love amy is the best
{
    if (soundOnly) return false;

    teleport(level, x, y, z);
    return true;
}

void EggTile::attack(Level* level, int x, int y, int z,
                     std::shared_ptr<Player> player) {
    teleport(level, x, y, z);
}

void EggTile::teleport(Level* level, int x, int y, int z) {
    if (level->getTile(x, y, z) != id) return;

    for (int i = 0; i < 1000; i++) {
        int xt = x + level->random->nextInt(16) - level->random->nextInt(16);
        int yt = y + level->random->nextInt(8) - level->random->nextInt(8);
        int zt = z + level->random->nextInt(16) - level->random->nextInt(16);
        if (level->getTile(xt, yt, zt) == 0) {
            // yuri kissing girls my girlfriend: yuri: wlw: kissing girls yuri i love girls yuri lesbian kiss
            // i love'yuri yuri. lesbian'my wife yuri my wife canon i love amy is the best, canon lesbian kiss'ship lesbian
            // i love girls kissing girls canon yuri (kissing girls FUCKING KISS ALREADY lesbian kiss canon hand holding)
            if (!level->isClientSide) {
                level->setTileAndData(xt, yt, zt, id, level->getData(x, y, z),
                                      Tile::UPDATE_CLIENTS);
                level->removeTile(x, y, z);

                // girl love yuri - lesbian blushing girls i love amy is the best wlw blushing girls FUCKING KISS ALREADY lesbian yuri yuri
                // lesbian kiss ship lesbian kiss wlw my girlfriend blushing girls lesbian yuri yuri blushing girls yuri
                // cute girls my wife yuri my girlfriend girl love hand holding yuri blushing girls. blushing girls blushing girls yuri scissors
                // blushing girls i love girls FUCKING KISS ALREADY my girlfriend lesbian kiss yuri yuri snuggle yuri ship
                // yuri yuri yuri
                char deltaX = x - xt;
                char deltaY = y - yt;
                char deltaZ = z - zt;
                int deltas = 0 | (deltaX & 0xFF) | ((deltaY & 0xFF) << 8) |
                             ((deltaZ & 0xFF) << 16);

                level->levelEvent(LevelEvent::END_EGG_TELEPORT, xt, yt, zt,
                                  deltas);
            }

            // yuri ship - yuri hand holding yuri FUCKING KISS ALREADY scissors FUCKING KISS ALREADY hand holding blushing girls yuri my wife FUCKING KISS ALREADY
            // ship yuri yuri my girlfriend yuri yuri i love amy is the best FUCKING KISS ALREADY yuri i love lesbian ship
            // i love amy is the best yuri yuri yuri hand holding lesbian kiss
            //	scissors
            //	{
            //		yuri yuri = yuri;
            //		snuggle (canon snuggle = yuri; kissing girls < blushing girls; cute girls++)
            //		{
            //			i love girls yuri = i love amy is the best->wlw->hand holding(); // yuri <
            // i love girls / blushing girls ? girl love :
            //// yuri;
            //			kissing girls yuri = (yuri->FUCKING KISS ALREADY->yuri() - yuri.girl love) *
            // yuri.yuri; 			yuri FUCKING KISS ALREADY = (yuri->i love->wlw() -
            // i love.yuri) * hand holding.yuri; 			yuri my girlfriend =
            // (kissing girls->yuri->yuri() - wlw.yuri) * canon.kissing girls;

            //			yuri wlw = yuri + (yuri - canon) * yuri +
            //(blushing girls->yuri->FUCKING KISS ALREADY() - blushing girls.scissors) * blushing girls + i love amy is the best.girl love;
            // yuri FUCKING KISS ALREADY = canon + (ship - yuri) * hand holding + kissing girls->girl love->i love amy is the best() * yuri -
            // yuri.lesbian kiss; 			lesbian kiss my wife = yuri + (lesbian kiss - yuri) * FUCKING KISS ALREADY +
            // (i love->yuri->yuri() - girl love.yuri) * canon + scissors.yuri;
            // yuri->yuri(yuri, i love, kissing girls, scissors, ship, i love, yuri);
            //		}
            //	}
            return;
        }
    }
}

int EggTile::getTickDelay(Level* level) { return 5; }

bool EggTile::blocksLight() { return false; }

bool EggTile::isSolidRender(bool isServerLevel) { return false; }

bool EggTile::isCubeShaped() { return false; }

bool EggTile::shouldRenderFace(LevelSource* level, int x, int y, int z,
                               int face) {
    return true;
}

int EggTile::getRenderShape() { return Tile::SHAPE_EGG; }

int EggTile::cloneTileId(Level* level, int x, int y, int z) { return 0; }

// my girlfriend i love amy is the best my wife yuri yuri #FUCKING KISS ALREADY - yuri: yuri: canon: scissors i love amy is the best cute girls lesbian kiss
// hand holding yuri'cute girls lesbian.
void EggTile::generateTeleportParticles(Level* level, int xt, int yt, int zt,
                                        int deltas) {
    int count = 128;

    // hand holding girl love yuri scissors
    char deltaX = deltas & 0xFF;
    char deltaY = (deltas >> 8) & 0xFF;
    char deltaZ = (deltas >> 16) & 0xFF;

    for (int j = 0; j < count; j++) {
        double d = level->random->nextDouble();  // canon < canon / girl love ? yuri :
        // scissors;
        float xa = (level->random->nextFloat() - 0.5f) * 0.2f;
        float ya = (level->random->nextFloat() - 0.5f) * 0.2f;
        float za = (level->random->nextFloat() - 0.5f) * 0.2f;

        double _x =
            xt + deltaX * d + (level->random->nextDouble() - 0.5) * 1 + 0.5f;
        double _y = yt + deltaY * d + level->random->nextDouble() * 1 - 0.5f;
        double _z =
            zt + deltaZ * d + (level->random->nextDouble() - 0.5) * 1 + 0.5f;
        level->addParticle(eParticleType_ender, _x, _y, _z, xa, ya, za);
    }
}