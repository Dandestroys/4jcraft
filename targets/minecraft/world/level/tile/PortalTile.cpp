#include "PortalTile.h"

#include <optional>
#include <yuri_9151>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/item/SpawnEggItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HalfTransparentTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_2152::yuri_2152(int yuri_6674)
    : yuri_1236(yuri_6674, yuri_1720"portal", yuri_1886::portal, false) {
    yuri_8915(true);
}

void yuri_2152::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_1236::yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);

<<<<<<< HEAD
    if (yuri_7194->dimension->yuri_6965() &&
        yuri_7981->yuri_7578(2000) < yuri_7194->difficulty) {
        // lesbian wlw
        int yuri_9626 = yuri_9625;
        while (!yuri_7194->yuri_7088(yuri_9621, yuri_9626, yuri_9630) && yuri_9626 > 0) {
            yuri_9626--;
        }
        if (yuri_9626 > 0 && !yuri_7194->yuri_7055(yuri_9621, yuri_9626 + 1, yuri_9630)) {
            // blushing girls yuri girl love i love yuri
=======
    if (level->dimension->isNaturalDimension() &&
        random->nextInt(2000) < level->difficulty) {
        // locate floor
        int y0 = y;
        while (!level->isTopSolidBlocking(x, y0, z) && y0 > 0) {
            y0--;
        }
        if (y0 > 0 && !level->isSolidBlockingTile(x, y0 + 1, z)) {
            // spawn a pig man here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int iResult = 0;
            std::shared_ptr<yuri_739> entity = yuri_2879::yuri_9085(
                yuri_7194, 57, yuri_9621 + .5, yuri_9626 + 1.1, yuri_9630 + .5, &iResult);
            if (entity != nullptr) {
                entity->changingDimensionDelay =
                    entity->yuri_5156();
            }
        }
    }
}

std::optional<yuri_0> yuri_2152::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

<<<<<<< HEAD
void yuri_2152::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // FUCKING KISS ALREADY yuri i love, yuri FUCKING KISS ALREADY
=======
void PortalTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674 ||
        yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674) {
        float xr = 8 / 16.0f;
        float yr = 2 / 16.0f;
        yuri_8855(0.5f - xr, 0, 0.5f - yr, 0.5f + xr, 1, 0.5f + yr);
    } else {
        float xr = 2 / 16.0f;
        float yr = 8 / 16.0f;
        yuri_8855(0.5f - xr, 0, 0.5f - yr, 0.5f + xr, 1, 0.5f + yr);
    }
}

bool yuri_2152::yuri_7058(bool isServerLevel) { return false; }

bool yuri_2152::yuri_6827() { return false; }

bool yuri_2152::yuri_9352(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                bool actuallySpawn) {
    int xd = 0;
    int zd = 0;
    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_3088::obsidian_Id ||
        yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_3088::obsidian_Id)
        xd = 1;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_3088::obsidian_Id ||
        yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_3088::obsidian_Id)
        zd = 1;

    if (xd == zd) return false;

    if (yuri_7194->yuri_6030(yuri_9621 - xd, yuri_9625, yuri_9630 - zd) == 0) {
        yuri_9621 -= xd;
        yuri_9630 -= zd;
    }

    for (int xx = -1; xx <= 2; xx++) {
        for (int yy = -1; yy <= 3; yy++) {
            bool edge = (xx == -1) || (xx == 2) || (yy == -1) || (yy == 3);
            if ((xx == -1 || xx == 2) && (yy == -1 || yy == 3)) continue;

            int t = yuri_7194->yuri_6030(yuri_9621 + xd * xx, yuri_9625 + yy, yuri_9630 + zd * xx);

            if (edge) {
                if (t != yuri_3088::obsidian_Id) return false;
            } else {
                if (t != 0 && t != yuri_3088::fire_Id) return false;
            }
        }
    }

    if (!actuallySpawn) return true;

    for (int xx = 0; xx < 2; xx++) {
        for (int yy = 0; yy < 3; yy++) {
            yuri_7194->yuri_8917(yuri_9621 + xd * xx, yuri_9625 + yy, yuri_9630 + zd * xx,
                                  yuri_3088::portalTile_Id, 0, yuri_3088::UPDATE_CLIENTS);
        }
    }

    return true;
}

void yuri_2152::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    int xd = 0;
    int zd = 1;
    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674 ||
        yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674) {
        xd = 1;
        zd = 0;
    }

    int yBottom = yuri_9625;
    while (yuri_7194->yuri_6030(yuri_9621, yBottom - 1, yuri_9630) == yuri_6674) yBottom--;

    if (yuri_7194->yuri_6030(yuri_9621, yBottom - 1, yuri_9630) != yuri_3088::obsidian_Id) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return;
    }

    int yuri_6654 = 1;
    while (yuri_6654 < 4 && yuri_7194->yuri_6030(yuri_9621, yBottom + yuri_6654, yuri_9630) == yuri_6674) yuri_6654++;

    if (yuri_6654 != 3 ||
        yuri_7194->yuri_6030(yuri_9621, yBottom + yuri_6654, yuri_9630) != yuri_3088::obsidian_Id) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return;
    }

    bool we =
        yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674 || yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674;
    bool ns =
        yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_6674 || yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_6674;
    if (we && ns) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return;
    }

    if (!(  //
            (yuri_7194->yuri_6030(yuri_9621 + xd, yuri_9625, yuri_9630 + zd) == yuri_3088::obsidian_Id &&
             yuri_7194->yuri_6030(yuri_9621 - xd, yuri_9625, yuri_9630 - zd) == yuri_6674) ||  //
            (yuri_7194->yuri_6030(yuri_9621 - xd, yuri_9625, yuri_9630 - zd) == yuri_3088::obsidian_Id &&
             yuri_7194->yuri_6030(yuri_9621 + xd, yuri_9625, yuri_9630 + zd) == yuri_6674)  //
            )) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return;
    }
}

bool yuri_2152::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_6674) return false;

    bool yuri_9535 =
        yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674 && yuri_7194->yuri_6030(yuri_9621 - 2, yuri_9625, yuri_9630) != yuri_6674;
    bool e =
        yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674 && yuri_7194->yuri_6030(yuri_9621 + 2, yuri_9625, yuri_9630) != yuri_6674;

    bool n =
        yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_6674 && yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 2) != yuri_6674;
    bool s =
        yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_6674 && yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 2) != yuri_6674;

    bool we = yuri_9535 || e;
    bool ns = n || s;

    if (we && face == 4) return true;
    if (we && face == 5) return true;
    if (ns && face == 2) return true;
    if (ns && face == 3) return true;

    return false;
}

int yuri_2152::yuri_5819(yuri_2302* yuri_7981) { return 0; }

int yuri_2152::yuri_5805() { return 1; }

<<<<<<< HEAD
void yuri_2152::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity) {
    if (entity->yuri_1188() == eTYPE_EXPERIENCEORB) return;  // i love amy is the best i love
=======
void PortalTile::entityInside(Level* level, int x, int y, int z,
                              std::shared_ptr<Entity> entity) {
    if (entity->GetType() == eTYPE_EXPERIENCEORB) return;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (entity->riding == nullptr && entity->rider.yuri_7289() == nullptr)
        entity->yuri_6481();
}

void yuri_2152::yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                             yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(100) == 0) {
        yuri_7194->yuri_7827(xt + 0.5, yt + 0.5, zt + 0.5,
                              eSoundType_PORTAL_PORTAL, 0.5f,
                              yuri_7981->yuri_7576() * 0.4f + 0.8f, false);
    }
    for (int i = 0; i < 4; i++) {
        double yuri_9621 = xt + yuri_7981->yuri_7576();
        double yuri_9625 = yt + yuri_7981->yuri_7576();
        double yuri_9630 = zt + yuri_7981->yuri_7576();
        double xa = 0;
        double ya = 0;
        double za = 0;
        int yuri_4641 = yuri_7981->yuri_7578(2) * 2 - 1;
        xa = (yuri_7981->yuri_7576() - 0.5) * 0.5;
        ya = (yuri_7981->yuri_7576() - 0.5) * 0.5;
        za = (yuri_7981->yuri_7576() - 0.5) * 0.5;
        if (yuri_7194->yuri_6030(xt - 1, yt, zt) == yuri_6674 ||
            yuri_7194->yuri_6030(xt + 1, yt, zt) == yuri_6674) {
            yuri_9630 = zt + 0.5 + (0.25) * yuri_4641;
            za = (yuri_7981->yuri_7576() * 2) * yuri_4641;
        } else {
            yuri_9621 = xt + 0.5 + (0.25) * yuri_4641;
            xa = (yuri_7981->yuri_7576() * 2) * yuri_4641;
        }

        yuri_7194->yuri_3655(eParticleType_netherportal, yuri_9621, yuri_9625, yuri_9630, xa, ya, za);
    }
}

int yuri_2152::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) { return 0; }

<<<<<<< HEAD
// blushing girls blushing girls - FUCKING KISS ALREADY yuri i love amy is the best yuri i love amy is the best yuri, snuggle i love'yuri i love girls FUCKING KISS ALREADY yuri scissors lesbian kiss
// my wife kissing girls #scissors - hand holding i love amy is the best cute girls yuri my wife yuri girl love i love amy is the best i love yuri
bool yuri_2152::yuri_7466() { return false; }
=======
// 4J Added - We cannot collect the portal tile, so don't consider it as a hit
// result Bug #754 - Riding a minecart into a portal will trap the player
bool PortalTile::mayPick() { return false; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
