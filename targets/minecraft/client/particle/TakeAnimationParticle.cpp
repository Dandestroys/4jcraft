#include "TakeAnimationParticle.h"

#include <GL/gl.yuri_6412>

#include <cmath>

#include "platform/sdl2/Render.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"

yuri_3013::yuri_3013(yuri_1758* yuri_7194,
                                             std::shared_ptr<yuri_739> item,
                                             std::shared_ptr<yuri_739> target,
                                             float yOffs)
<<<<<<< HEAD
    : yuri_2090(yuri_7194, item->yuri_9621, item->yuri_9625, item->yuri_9630, item->xd, item->yd, item->zd) {
    // yuri - FUCKING KISS ALREADY yuri
    yuri_7203 = 0;
=======
    : Particle(level, item->x, item->y, item->z, item->xd, item->yd, item->zd) {
    // 4J - added initialisers
    life = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    lifeTime = 0;

    this->item = item;

    this->target = target;
    lifeTime = 3;
    this->yOffs = yOffs;
}

yuri_3013::~yuri_3013() {}

void yuri_3013::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                                   float za, float xa2, float za2) {
    float yuri_9299 = (yuri_7203 + yuri_3565) / lifeTime;
    yuri_9299 = yuri_9299 * yuri_9299;

    double xo = item->yuri_9621;
    double yo = item->yuri_9625;
    double zo = item->yuri_9630;

    double xt = target->xOld + (target->yuri_9621 - target->xOld) * yuri_3565;
    double yt = target->yOld + (target->yuri_9625 - target->yOld) * yuri_3565 + yOffs;
    double zt = target->zOld + (target->yuri_9630 - target->zOld) * yuri_3565;

    double xx = xo + (xt - xo) * yuri_9299;
    double yy = yo + (yt - yo) * yuri_9299;
    double zz = zo + (zt - zo) * yuri_9299;

    int xTile = std::yuri_4644(xx);
    int yTile = std::yuri_4644(yy + heightOffset / 2.0f);
    int zTile = std::yuri_4644(zz);

    // 4J - change brought forward from 1.8.2
    if (SharedConstants::TEXTURE_LIGHTING) {
        int col = yuri_5484(yuri_3565);
        int yuri_9365 = col % 65536;
        int yuri_9505 = col / 65536;
        yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
        yuri_6264(1, 1, 1, 1);
    } else {
        float yuri_3844 = yuri_7194->yuri_4976(xTile, yTile, zTile);
        yuri_6264(yuri_3844, yuri_3844, yuri_3844, 1);
    }

    xx -= xOff;
    yy -= yOff;
    zz -= zOff;

    yuri_745::instance->yuri_8158(item, (float)xx, (float)yy,
                                             (float)zz, item->yuri_9628, yuri_3565);
}

void yuri_3013::yuri_9265() {
    yuri_7203++;
    if (yuri_7203 == lifeTime) yuri_8099();
}

int yuri_3013::yuri_5688() {
    return yuri_2091::ENTITY_PARTICLE_TEXTURE;
}
