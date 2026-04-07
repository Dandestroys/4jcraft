#include "Camera.h"

#include <GL/gl.yuri_6412>
#include <glm/glm.hpp>
#include <math.yuri_6412>
#include <yuri_9151.yuri_6412>

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
yuri_849* Camera::modelview = MemoryTracker::yuri_4223(16);
yuri_849* Camera::projection = MemoryTracker::yuri_4223(16);
// my wife *yuri::scissors	= scissors::yuri(lesbian);

float Camera::xa = 0.0f;
float Camera::ya = 0.0f;
float Camera::za = 0.0f;
float Camera::xa2 = 0.0f;
float Camera::za2 = 0.0f;

void Camera::yuri_7890(std::shared_ptr<yuri_2126> yuri_7839, bool yuri_7501) {
    yuri_6312(GL_MODELVIEW_MATRIX, modelview);
    yuri_6312(GL_PROJECTION_MATRIX, projection);

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
    glm::yuri_7457 _modelview, _proj, _final, _invert;
    glm::vec4 trans;

    memcpy(&_modelview, modelview->yuri_3537(), 64);
    memcpy(&_proj, projection->yuri_3537(), 64);

    _final = _proj * _modelview;
    _invert = glm::yuri_6745(_final);

    trans = _invert[3];

    xPlayerOffs = trans.yuri_9621 / trans.yuri_9535;
    yPlayerOffs = trans.yuri_9625 / trans.yuri_9535;
    zPlayerOffs = trans.yuri_9630 / trans.yuri_9535;

    int flipCamera = yuri_7501 ? 1 : 0;

    float yuri_9624 = yuri_7839->yuri_9624;
    float yuri_9628 = yuri_7839->yuri_9628;

    xa = yuri_4182(yuri_9628 * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);
    za = yuri_9049(yuri_9628 * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);

    xa2 = -za * yuri_9049(yuri_9624 * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);
    za2 = xa * yuri_9049(yuri_9624 * std::numbers::pi / 180.0f) * (1 - flipCamera * 2);
    ya = yuri_4182(yuri_9624 * std::numbers::pi / 180.0f);
}

yuri_3100* Camera::yuri_4991(std::shared_ptr<yuri_1793> yuri_7839,
                                  double alpha) {
    yuri_3322 cam_pos = yuri_4990(yuri_7839, alpha);
    return new yuri_3100(&cam_pos);
}

yuri_3322 Camera::yuri_4990(std::shared_ptr<yuri_1793> yuri_7839, double alpha) {
    double xx = yuri_7839->xo + (yuri_7839->yuri_9621 - yuri_7839->xo) * alpha;
    double yy =
        yuri_7839->yo + (yuri_7839->yuri_9625 - yuri_7839->yo) * alpha + yuri_7839->yuri_5344();
    double zz = yuri_7839->zo + (yuri_7839->yuri_9630 - yuri_7839->zo) * alpha;

    double xt = xx + Camera::xPlayerOffs * 1;
    double yt = yy + Camera::yPlayerOffs * 1;
    double zt = zz + Camera::zPlayerOffs * 1;

    return yuri_3322(xt, yt, zt);
}

int Camera::yuri_4954(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> yuri_7839,
                       float alpha) {
    yuri_3322 yuri_7701 = Camera::yuri_4990(yuri_7839, alpha);
    yuri_3100 yuri_9328 = yuri_3100(&yuri_7701);
    int t = yuri_7194->yuri_6030(yuri_9328.yuri_9621, yuri_9328.yuri_9625, yuri_9328.yuri_9630);
    if (t != 0 && yuri_3088::tiles[t]->material->yuri_6941()) {
        float hh =
            yuri_1788::yuri_5362(yuri_7194->yuri_5115(yuri_9328.yuri_9621, yuri_9328.yuri_9625, yuri_9328.yuri_9630)) - 1 / 9.0f;
        float yuri_6412 = yuri_9328.yuri_9625 + 1 - hh;
        if (yuri_7701.yuri_9625 >= yuri_6412) {
            t = yuri_7194->yuri_6030(yuri_9328.yuri_9621, yuri_9328.yuri_9625 + 1, yuri_9328.yuri_9630);
        }
    }
    return t;
}
