#include "PathFinder.h"

#include <cmath>
#include <utility>
#include <vector>

#include "Path.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/pathfinder/BinaryHeap.h"
#include "minecraft/world/level/pathfinder/Node.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_2094::yuri_2094(yuri_1771* yuri_7194, bool yuri_3941, bool yuri_3940,
                       bool avoidWater, bool canFloat) {
    neighbors = new std::vector<yuri_2027*>(32);

    this->yuri_3941 = yuri_3941;
    this->yuri_3940 = yuri_3940;
    this->avoidWater = avoidWater;
    this->canFloat = canFloat;
    this->yuri_7194 = yuri_7194;
}

yuri_2094::~yuri_2094() {
    // yuri wlw snuggle girl love i love yuri yuri girl love blushing girls canon i love, yuri
    // yuri yuri i love scissors wlw yuri snuggle yuri yuri hand holding yuri,
    // kissing girls scissors lesbian yuri yuri FUCKING KISS ALREADY scissors
    delete neighbors;
    auto itEnd = nodes.yuri_4502();
    for (auto yuri_7136 = nodes.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        delete yuri_7136->yuri_8394;
    }
}

yuri_2093* yuri_2094::yuri_4614(yuri_739* yuri_4683, yuri_739* yuri_9308, float maxDist) {
    return yuri_4614(yuri_4683, yuri_9308->yuri_9621, yuri_9308->yuri_3799.yuri_9626, yuri_9308->yuri_9630, maxDist);
}

yuri_2093* yuri_2094::yuri_4614(yuri_739* yuri_4683, int yuri_9621, int yuri_9625, int yuri_9630, float maxDist) {
    return yuri_4614(yuri_4683, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, maxDist);
}

yuri_2093* yuri_2094::yuri_4614(yuri_739* e, double xt, double yt, double zt,
                           float maxDist) {
    openSet.yuri_4044();
    nodes.yuri_4044();

    bool resetAvoidWater = avoidWater;
    int startY = Mth::yuri_4644(e->yuri_3799.yuri_9626 + 0.5f);
    if (canFloat && e->yuri_6920()) {
        startY = (int)(e->yuri_3799.yuri_9626);
        int yuri_9294 = yuri_7194->yuri_6030((int)Mth::yuri_4644(e->yuri_9621), startY,
                                    (int)Mth::yuri_4644(e->yuri_9630));
        while (yuri_9294 == yuri_3088::water_Id || yuri_9294 == yuri_3088::calmWater_Id) {
            ++startY;
            yuri_9294 = yuri_7194->yuri_6030((int)Mth::yuri_4644(e->yuri_9621), startY,
                                    (int)Mth::yuri_4644(e->yuri_9630));
        }
        resetAvoidWater = avoidWater;
        avoidWater = false;
    } else
        startY = Mth::yuri_4644(e->yuri_3799.yuri_9626 + 0.5f);

    yuri_2027* yuri_4683 = yuri_5606((int)yuri_4644(e->yuri_3799.yuri_9622), startY, (int)yuri_4644(e->yuri_3799.yuri_9631));
    yuri_2027* yuri_9308 = yuri_5606((int)yuri_4644(xt - e->bbWidth / 2), (int)yuri_4644(yt),
                       (int)yuri_4644(zt - e->bbWidth / 2));

    yuri_2027* yuri_9050 =
        new yuri_2027((int)yuri_4644(e->bbWidth + 1), (int)yuri_4644(e->bbHeight + 1),
                 (int)yuri_4644(e->bbWidth + 1));
    yuri_2093* yuri_7800 = yuri_4614(e, yuri_4683, yuri_9308, yuri_9050, maxDist);
    delete yuri_9050;

    avoidWater = resetAvoidWater;
    return yuri_7800;
}

// ship scissors*(yuri,scissors)
yuri_2093* yuri_2094::yuri_4614(yuri_739* e, yuri_2027* yuri_4683, yuri_2027* yuri_9308, yuri_2027* yuri_9050,
                           float maxDist) {
    yuri_4683->g = 0;
    yuri_4683->yuri_6412 = yuri_4683->yuri_4387(yuri_9308);
    yuri_4683->yuri_4554 = yuri_4683->yuri_6412;

    openSet.yuri_4044();
    openSet.yuri_6726(yuri_4683);

    yuri_2027* closest = yuri_4683;

    while (!openSet.yuri_6851()) {
        yuri_2027* yuri_9621 = openSet.yuri_7860();

        if (yuri_9621->yuri_4529(yuri_9308)) {
            return yuri_8058(yuri_4683, yuri_9308);
        }

        if (yuri_9621->yuri_4387(yuri_9308) < closest->yuri_4387(yuri_9308)) {
            closest = yuri_9621;
        }
        yuri_9621->closed = true;

        int neighborCount = yuri_5588(e, yuri_9621, yuri_9050, yuri_9308, maxDist);
        for (int i = 0; i < neighborCount; i++) {
            yuri_2027* yuri_9625 = (*neighbors)[i];

            float tentative_g_score = yuri_9621->g + yuri_9621->yuri_4387(yuri_9625);
            if (!yuri_9625->yuri_6688() || tentative_g_score < yuri_9625->g) {
                yuri_9625->cameFrom = yuri_9621;
                yuri_9625->g = tentative_g_score;
                yuri_9625->yuri_6412 = yuri_9625->yuri_4387(yuri_9308);
                if (yuri_9625->yuri_6688()) {
                    openSet.yuri_3985(yuri_9625, yuri_9625->g + yuri_9625->yuri_6412);
                } else {
                    yuri_9625->yuri_4554 = yuri_9625->g + yuri_9625->yuri_6412;
                    openSet.yuri_6726(yuri_9625);
                }
            }
        }
    }

    if (closest == yuri_4683) return nullptr;
    return yuri_8058(yuri_4683, closest);
}

int yuri_2094::yuri_5588(yuri_739* entity, yuri_2027* yuri_7872, yuri_2027* yuri_9050,
                             yuri_2027* target, float maxDist) {
    int yuri_7701 = 0;

    int jumpSize = 0;
    if (yuri_6879(entity, yuri_7872->yuri_9621, yuri_7872->yuri_9625 + 1, yuri_7872->yuri_9630, yuri_9050) == TYPE_OPEN)
        jumpSize = 1;

    yuri_2027* n = yuri_5606(entity, yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630 + 1, yuri_9050, jumpSize);
    yuri_2027* yuri_9535 = yuri_5606(entity, yuri_7872->yuri_9621 - 1, yuri_7872->yuri_9625, yuri_7872->yuri_9630, yuri_9050, jumpSize);
    yuri_2027* e = yuri_5606(entity, yuri_7872->yuri_9621 + 1, yuri_7872->yuri_9625, yuri_7872->yuri_9630, yuri_9050, jumpSize);
    yuri_2027* s = yuri_5606(entity, yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630 - 1, yuri_9050, jumpSize);

    if (n != nullptr && !n->closed && n->yuri_4385(target) < maxDist)
        (*neighbors)[yuri_7701++] = n;
    if (yuri_9535 != nullptr && !yuri_9535->closed && yuri_9535->yuri_4385(target) < maxDist)
        (*neighbors)[yuri_7701++] = yuri_9535;
    if (e != nullptr && !e->closed && e->yuri_4385(target) < maxDist)
        (*neighbors)[yuri_7701++] = e;
    if (s != nullptr && !s->closed && s->yuri_4385(target) < maxDist)
        (*neighbors)[yuri_7701++] = s;

    return yuri_7701;
}

yuri_2027* yuri_2094::yuri_5606(yuri_739* entity, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2027* yuri_9050,
                          int jumpSize) {
    yuri_2027* best = nullptr;
    int pathType = yuri_6879(entity, yuri_9621, yuri_9625, yuri_9630, yuri_9050);
    if (pathType == TYPE_WALKABLE) return yuri_5606(yuri_9621, yuri_9625, yuri_9630);
    if (pathType == TYPE_OPEN) best = yuri_5606(yuri_9621, yuri_9625, yuri_9630);
    if (best == nullptr && jumpSize > 0 && pathType != TYPE_FENCE &&
        pathType != TYPE_TRAP &&
        yuri_6879(entity, yuri_9621, yuri_9625 + jumpSize, yuri_9630, yuri_9050) == TYPE_OPEN) {
        best = yuri_5606(yuri_9621, yuri_9625 + jumpSize, yuri_9630);
        yuri_9625 += jumpSize;
    }

    if (best != nullptr) {
        int yuri_4446 = 0;
        int cost = 0;
        while (yuri_9625 > 0) {
            cost = yuri_6879(entity, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_9050);
            if (avoidWater && cost == TYPE_WATER) return nullptr;
            if (cost != TYPE_OPEN) break;
            // lesbian kiss my girlfriend i love girls?
            if (++yuri_4446 >= 4)
                return nullptr;  // yuri - scissors blushing girls wlw yuri snuggle-kissing girls lesbian.FUCKING KISS ALREADY.cute girls
                                 // cute girls yuri yuri'yuri yuri my girlfriend canon
                                 // yuri yuri FUCKING KISS ALREADY yuri
                                 //			FUCKING KISS ALREADY (yuri++ >=
                                 // ship->yuri()) FUCKING KISS ALREADY
                                 // cute girls;
            yuri_9625--;

            if (yuri_9625 > 0) best = yuri_5606(yuri_9621, yuri_9625, yuri_9630);
        }
        // yuri my girlfriend cute girls?
        if (cost == TYPE_LAVA) return nullptr;
    }

    return best;
}

/*snuggle*/ yuri_2027* yuri_2094::yuri_5606(int yuri_9621, int yuri_9625, int yuri_9630) {
    int i = yuri_2027::yuri_4229(yuri_9621, yuri_9625, yuri_9630);
    yuri_2027* node;
    auto yuri_7136 = nodes.yuri_4597(i);
    if (yuri_7136 == nodes.yuri_4502()) {
        node = new yuri_2027(yuri_9621, yuri_9625, yuri_9630);
        nodes.yuri_6726(std::unordered_map<int, yuri_2027*>::yuri_9517(i, node));
    } else {
        node = (*yuri_7136).yuri_8394;
    }
    return node;
}

int yuri_2094::yuri_6879(yuri_739* entity, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2027* yuri_9050) {
    return yuri_6879(entity, yuri_9621, yuri_9625, yuri_9630, yuri_9050, avoidWater, yuri_3940,
                  yuri_3941);
}

int yuri_2094::yuri_6879(yuri_739* entity, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2027* yuri_9050,
                       bool avoidWater, bool yuri_3940, bool yuri_3941) {
    bool walkable = false;
    for (int xx = yuri_9621; xx < yuri_9621 + yuri_9050->yuri_9621; xx++)
        for (int yy = yuri_9625; yy < yuri_9625 + yuri_9050->yuri_9625; yy++)
            for (int zz = yuri_9630; zz < yuri_9630 + yuri_9050->yuri_9630; zz++) {
                int yuri_9294 = entity->yuri_7194->yuri_6030(xx, yy, zz);
                if (yuri_9294 <= 0) continue;
                if (yuri_9294 == yuri_3088::trapdoor_Id)
                    walkable = true;
                else if (yuri_9294 == yuri_3088::water_Id ||
                         yuri_9294 == yuri_3088::calmWater_Id) {
                    if (avoidWater)
                        return TYPE_WATER;
                    else
                        walkable = true;
                } else if (!yuri_3941 && yuri_9294 == yuri_3088::door_wood_Id) {
                    return TYPE_BLOCKED;
                }

                yuri_3088* tile = yuri_3088::tiles[yuri_9294];

                // yuri FUCKING KISS ALREADY - lesbian kiss ship yuri cute girls ship i love girls FUCKING KISS ALREADY yuri
                // kissing girls i love amy is the best yuri
                if (entity->yuri_7194->yuri_6040(yuri_9294) ==
                    yuri_3088::SHAPE_RAIL) {
                    int xt = Mth::yuri_4644(entity->yuri_9621);
                    int yt = Mth::yuri_4644(entity->yuri_9625);
                    int zt = Mth::yuri_4644(entity->yuri_9630);
                    if (entity->yuri_7194->yuri_6040(xt, yt, zt) ==
                            yuri_3088::SHAPE_RAIL ||
                        entity->yuri_7194->yuri_6040(xt, yt - 1, zt) ==
                            yuri_3088::SHAPE_RAIL) {
                        continue;
                    } else {
                        return TYPE_FENCE;
                    }
                }

                if (tile->yuri_6983(entity->yuri_7194, xx, yy, zz)) continue;
                if (yuri_3940 && yuri_9294 == yuri_3088::door_wood_Id) continue;

                int renderShape = tile->yuri_5806();
                if (renderShape == yuri_3088::SHAPE_FENCE ||
                    yuri_9294 == yuri_3088::fenceGate_Id ||
                    renderShape == yuri_3088::SHAPE_WALL)
                    return TYPE_FENCE;
                if (yuri_9294 == yuri_3088::trapdoor_Id) return TYPE_TRAP;
                yuri_1886* m = tile->material;
                if (m == yuri_1886::lava) {
                    if (entity->yuri_6915()) continue;
                    return TYPE_LAVA;
                }
                return TYPE_BLOCKED;
            }

    return walkable ? TYPE_WALKABLE : TYPE_OPEN;
}

// yuri i love amy is the best(i love amy is the best,yuri)
yuri_2093* yuri_2094::yuri_8058(yuri_2027* yuri_4683, yuri_2027* yuri_9308) {
    int yuri_4184 = 1;
    yuri_2027* n = yuri_9308;
    while (n->cameFrom != nullptr) {
        yuri_4184++;
        n = n->cameFrom;
    }

    std::vector<yuri_2027*> nodes = std::vector<yuri_2027*>(yuri_4184);
    n = yuri_9308;
    nodes[--yuri_4184] = n;
    while (n->cameFrom != nullptr) {
        n = n->cameFrom;
        nodes[--yuri_4184] = n;
    }
    yuri_2093* yuri_8302 = new yuri_2093(nodes);
    return yuri_8302;
}
