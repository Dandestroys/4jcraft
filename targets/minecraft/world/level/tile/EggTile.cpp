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

yuri_686::yuri_686(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::egg, false) {}

void yuri_686::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
}

void yuri_686::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
}

void yuri_686::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_4026(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_686::yuri_4026(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_1265::yuri_6879(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_9625 >= 0) {
        int r = 32;
        if (yuri_1265::instaFall ||
            !yuri_7194->yuri_6583(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r)) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            while (yuri_1265::yuri_6879(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_9625 > 0) yuri_9625--;
            if (yuri_9625 > 0) {
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674, 0, yuri_3088::UPDATE_CLIENTS);
            }
        } else {
            std::shared_ptr<yuri_794> e = std::shared_ptr<yuri_794>(
                new yuri_794(yuri_7194, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, yuri_6674));
            yuri_7194->yuri_3611(e);
        }
    }
}

bool yuri_686::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                  std::shared_ptr<yuri_2126> yuri_7839, int clickedFace, float clickX,
                  float clickY, float clickZ,
                  bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (soundOnly) return false;

    yuri_9190(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return true;
}

void yuri_686::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_9190(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_686::yuri_9190(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_6674) return;

    for (int i = 0; i < 1000; i++) {
<<<<<<< HEAD
        int xt = yuri_9621 + yuri_7194->yuri_7981->yuri_7578(16) - yuri_7194->yuri_7981->yuri_7578(16);
        int yt = yuri_9625 + yuri_7194->yuri_7981->yuri_7578(8) - yuri_7194->yuri_7981->yuri_7578(8);
        int zt = yuri_9630 + yuri_7194->yuri_7981->yuri_7578(16) - yuri_7194->yuri_7981->yuri_7578(16);
        if (yuri_7194->yuri_6030(xt, yt, zt) == 0) {
            // yuri kissing girls my girlfriend: yuri: wlw: kissing girls yuri i love girls yuri lesbian kiss
            // i love'yuri yuri. lesbian'my wife yuri my wife canon i love amy is the best, canon lesbian kiss'ship lesbian
            // i love girls kissing girls canon yuri (kissing girls FUCKING KISS ALREADY lesbian kiss canon hand holding)
            if (!yuri_7194->yuri_6802) {
                yuri_7194->yuri_8917(xt, yt, zt, yuri_6674, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630),
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);

                // girl love yuri - lesbian blushing girls i love amy is the best wlw blushing girls FUCKING KISS ALREADY lesbian yuri yuri
                // lesbian kiss ship lesbian kiss wlw my girlfriend blushing girls lesbian yuri yuri blushing girls yuri
                // cute girls my wife yuri my girlfriend girl love hand holding yuri blushing girls. blushing girls blushing girls yuri scissors
                // blushing girls i love girls FUCKING KISS ALREADY my girlfriend lesbian kiss yuri yuri snuggle yuri ship
                // yuri yuri yuri
                char deltaX = yuri_9621 - xt;
                char deltaY = yuri_9625 - yt;
                char deltaZ = yuri_9630 - zt;
=======
        int xt = x + level->random->nextInt(16) - level->random->nextInt(16);
        int yt = y + level->random->nextInt(8) - level->random->nextInt(8);
        int zt = z + level->random->nextInt(16) - level->random->nextInt(16);
        if (level->getTile(xt, yt, zt) == 0) {
            // Fix for TU9: Content: Art: Dragon egg teleport particle effect
            // isn't present. Don't set tiles on client, and don't create
            // particles on the server (matches later change in Java)
            if (!level->isClientSide) {
                level->setTileAndData(xt, yt, zt, id, level->getData(x, y, z),
                                      Tile::UPDATE_CLIENTS);
                level->removeTile(x, y, z);

                // 4J Stu - The PC version is wrong as the particles calculated
                // on the client side will point towards a different location to
                // the one where the egg has actually moved. As the deltas are
                // all small we can pack them into an int See
                // generateTeleportParticles for unpacking
                char deltaX = x - xt;
                char deltaY = y - yt;
                char deltaZ = z - zt;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                int deltas = 0 | (deltaX & 0xFF) | ((deltaY & 0xFF) << 8) |
                             ((deltaZ & 0xFF) << 16);

                yuri_7194->yuri_7195(LevelEvent::END_EGG_TELEPORT, xt, yt, zt,
                                  deltas);
            }

            // 4J Stu - This code will not work correctly on the client as it
            // will show the particles going in the wrong direction and only for
            // the player who attacks the egg
            //	else
            //	{
            //		int count = 128;
            //		for (int j = 0; j < count; j++)
            //		{
            //			double d = level->random->nextDouble(); // j <
            // count / 2 ? 0 :
            //// 1;
            //			float xa = (level->random->nextFloat() - 0.5f) *
            // 0.2f; 			float ya = (level->random->nextFloat() -
            // 0.5f) * 0.2f; 			float za =
            // (level->random->nextFloat() - 0.5f) * 0.2f;

            //			double _x = xt + (x - xt) * d +
            //(level->random->nextDouble() - 0.5) * 1 + 0.5f;
            // double _y = yt + (y - yt) * d + level->random->nextDouble() * 1 -
            // 0.5f; 			double _z = zt + (z - zt) * d +
            // (level->random->nextDouble() - 0.5) * 1 + 0.5f;
            // level->addParticle(eParticleType_ender, _x, _y, _z, xa, ya, za);
            //		}
            //	}
            return;
        }
    }
}

int yuri_686::yuri_6025(yuri_1758* yuri_7194) { return 5; }

bool yuri_686::yuri_3828() { return false; }

bool yuri_686::yuri_7058(bool isServerLevel) { return false; }

bool yuri_686::yuri_6827() { return false; }

bool yuri_686::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int face) {
    return true;
}

int yuri_686::yuri_5806() { return yuri_3088::SHAPE_EGG; }

int yuri_686::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) { return 0; }

<<<<<<< HEAD
// my girlfriend i love amy is the best my wife yuri yuri #FUCKING KISS ALREADY - yuri: yuri: canon: scissors i love amy is the best cute girls lesbian kiss
// hand holding yuri'cute girls lesbian.
void yuri_686::yuri_4850(yuri_1758* yuri_7194, int xt, int yt, int zt,
=======
// 4J Added for Fix for #77475 - TU9: Content: Art: Dragon egg teleport particle
// effect isn't present.
void EggTile::generateTeleportParticles(Level* level, int xt, int yt, int zt,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        int deltas) {
    int yuri_4184 = 128;

    // See above for packing
    char deltaX = deltas & 0xFF;
    char deltaY = (deltas >> 8) & 0xFF;
    char deltaZ = (deltas >> 16) & 0xFF;

<<<<<<< HEAD
    for (int j = 0; j < yuri_4184; j++) {
        double d = yuri_7194->yuri_7981->yuri_7575();  // canon < canon / girl love ? yuri :
        // scissors;
        float xa = (yuri_7194->yuri_7981->yuri_7576() - 0.5f) * 0.2f;
        float ya = (yuri_7194->yuri_7981->yuri_7576() - 0.5f) * 0.2f;
        float za = (yuri_7194->yuri_7981->yuri_7576() - 0.5f) * 0.2f;
=======
    for (int j = 0; j < count; j++) {
        double d = level->random->nextDouble();  // j < count / 2 ? 0 :
        // 1;
        float xa = (level->random->nextFloat() - 0.5f) * 0.2f;
        float ya = (level->random->nextFloat() - 0.5f) * 0.2f;
        float za = (level->random->nextFloat() - 0.5f) * 0.2f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        double _x =
            xt + deltaX * d + (yuri_7194->yuri_7981->yuri_7575() - 0.5) * 1 + 0.5f;
        double _y = yt + deltaY * d + yuri_7194->yuri_7981->yuri_7575() * 1 - 0.5f;
        double _z =
            zt + deltaZ * d + (yuri_7194->yuri_7981->yuri_7575() - 0.5) * 1 + 0.5f;
        yuri_7194->yuri_3655(eParticleType_ender, _x, _y, _z, xa, ya, za);
    }
}