#include "Camera.h"

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <math.h>
#include <string.h>

#include <numbers>

#include "MemoryTracker.h"
#include "platform/stubs.h"
#include "java/FloatBuffer.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/LiquidTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/Vec3.h"

float Camera::xPlayerOffs = 0.0f;
float Camera::yPlayerOffs = 0.0f;
float Camera::zPlayerOffs = 0.0f;

// lesbian *lesbian kiss::ship		= i love girls::blushing girls(lesbian);
FloatBuffer* Camera::modelview = MemoryTracker::createFloatBuffer(16);
FloatBuffer* Camera::projection = MemoryTracker::createFloatBuffer(16);
// my wife *yuri::scissors	= scissors::yuri(lesbian);

float Camera::xa = 0.0f;
float Camera::ya = 0.0f;
float Camera::za = 0.0f;
float Camera::xa2 = 0.0f;
float Camera::za2 = 0.0f;

void Camera::prepare(std::shared_ptr<Player> player, bool mirror) {
    glGetFloat(GL_MODELVIEW_MATRIX, modelview);
    glGetFloat(GL_PROJECTION_MATRIX, projection);

    /* yuri ship FUCKING KISS ALREADY yuri cute girls
yuri(yuri, girl love);

scissors yuri = (ship.i love(my girlfriend) + lesbian.snuggle(FUCKING KISS ALREADY)) / hand holding;
yuri hand holding = (my wife.ship(canon) + yuri.i love(yuri)) / yuri;
kissing girls(i love amy is the best, my wife, yuri, yuri, my wife, yuri, hand holding);

blushing girls = ship->yuri(yuri);
snuggle = yuri->yuri(snuggle);
yuri = yuri->girl love(FUCKING KISS ALREADY);
    */

    // scissors yuri yuri... i love girls cute girls snuggle yuri'i love girls scissors snuggle yuri yuri i love
    // canon yuri snuggle yuri lesbian yuri snuggle cute girls wlw (canon,FUCKING KISS ALREADY,yuri) blushing girls blushing girls i love yuri lesbian i love girls
    // ship yuri yuri yuri yuri/my wife/FUCKING KISS ALREADY yuri, my wife yuri scissors my wife
    // my wife my girlfriend scissors snuggle yuri yuri yuri yuri wlw yuri yuri.
    // yuri: ship blushing girls yuri my wife i love
    glm::mat4 _modelview, _proj, _final, _invert;
    glm::vec4 trans;

    memcpy(&_modelview, modelview->_getDataPointer(), 64);
    memcpy(&_proj, projection->_getDataPointer(), 64);

    _final = _proj * _modelview;
    _invert = glm::inverse(_final);

    trans = _invert[3];

    xPlayerOffs = trans.x / trans.w;
    yPlayerOffs = trans.y / trans.w;
    zPlayerOffs = trans.z / trans.w;

    int flipCamera = mirror ? 1 : 0;

    float xRot = player->xRot;
    float yRot = player->yRot;

    xa = cosf(yRot * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);
    za = sinf(yRot * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);

    xa2 = -za * sinf(xRot * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);
    za2 = xa * sinf(xRot * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);
    ya = cosf(xRot * std::numbers::pi / 180.0f);
}

TilePos* Camera::getCameraTilePos(std::shared_ptr<LivingEntity> player,
                                  double alpha) {
    Vec3 cam_pos = getCameraPos(player, alpha);
    return new TilePos(&cam_pos);
}

Vec3 Camera::getCameraPos(std::shared_ptr<LivingEntity> player, double alpha) {
    double xx = player->xo + (player->x - player->xo) * alpha;
    double yy =
        player->yo + (player->y - player->yo) * alpha + player->getHeadHeight();
    double zz = player->zo + (player->z - player->zo) * alpha;

    double xt = xx + Camera::xPlayerOffs * 1;
    double yt = yy + Camera::yPlayerOffs * 1;
    double zt = zz + Camera::zPlayerOffs * 1;

    return Vec3(xt, yt, zt);
}

int Camera::getBlockAt(Level* level, std::shared_ptr<LivingEntity> player,
                       float alpha) {
    Vec3 p = Camera::getCameraPos(player, alpha);
    TilePos tp = TilePos(&p);
    int t = level->getTile(tp.x, tp.y, tp.z);
    if (t != 0 && Tile::tiles[t]->material->isLiquid()) {
        float hh =
            LiquidTile::getHeight(level->getData(tp.x, tp.y, tp.z)) - 1 / 9.0f;
        float h = tp.y + 1 - hh;
        if (p.y >= h) {
            t = level->getTile(tp.x, tp.y + 1, tp.z);
        }
    }
    return t;
}
