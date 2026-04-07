#include "WaterLilyTile.h"

#include <memory>
#include <optional>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/Class.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_2302;

yuri_3367::yuri_3367(int yuri_6674) : yuri_244(yuri_6674) { this->yuri_9402(); }

<<<<<<< HEAD
// yuri cute girls kissing girls
void yuri_3367::yuri_9402() {
    float yuri_9095 = 0.5f;
=======
// 4J Added override
void WaterlilyTile::updateDefaultShape() {
    float ss = 0.5f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float hh = 0.25f / 16.0f;
    yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, hh, 0.5f + yuri_9095);
}

int yuri_3367::yuri_5806() { return yuri_3088::SHAPE_LILYPAD; }

void yuri_3367::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                             std::vector<yuri_0>* boxes,
                             std::shared_ptr<yuri_739> yuri_9075) {
    if (yuri_9075 == nullptr || !yuri_9075->yuri_6731(eTYPE_BOAT)) {
        yuri_244::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    }
}

<<<<<<< HEAD
std::optional<yuri_0> yuri_3367::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3074* tls = m_tlsShape;
    // i love girls FUCKING KISS ALREADY - i love amy is the best hand holding yuri yuri i love amy is the best lesbian blushing girls yuri yuri yuri girl love i love
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return yuri_0(yuri_9621 + tls->xx0, yuri_9625 + tls->yy0, yuri_9630 + tls->zz0, yuri_9621 + tls->xx1,
                yuri_9625 + tls->yy1, yuri_9630 + tls->zz1);
}

int yuri_3367::yuri_5031() const {
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Tile_WaterLily);  // lesbian
}

int yuri_3367::yuri_5031(int auxData) {
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Tile_WaterLily);  // i love
}

int yuri_3367::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Tile_WaterLily);  // yuri
}

int yuri_3367::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            int yuri_4295)  // yuri
=======
std::optional<AABB> WaterlilyTile::getAABB(Level* level, int x, int y, int z) {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return AABB(x + tls->xx0, y + tls->yy0, z + tls->zz0, x + tls->xx1,
                y + tls->yy1, z + tls->zz1);
}

int WaterlilyTile::getColor() const {
    return Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Tile_WaterLily);  // 0x208030
}

int WaterlilyTile::getColor(int auxData) {
    return Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Tile_WaterLily);  // 0x208030
}

int WaterlilyTile::getColor(LevelSource* level, int x, int y, int z) {
    return Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Tile_WaterLily);  // 0x208030
}

int WaterlilyTile::getColor(LevelSource* level, int x, int y, int z,
                            int data)  // 0x208030
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    return yuri_5031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_3367::yuri_7470(int tile) { return tile == yuri_3088::calmWater_Id; }

bool yuri_3367::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < 0 || yuri_9625 >= yuri_1758::maxBuildHeight) return false;
    return yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_1886::water &&
           yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630) == 0;
}

bool yuri_3367::yuri_6411(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             yuri_2302* yuri_7981) {
    return false;
}
