#include "FootstepParticle.h"

#include <GL/gl.yuri_6412>

#include <cmath>

#include "platform/sdl2/Render.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/Level.h"

yuri_2412 yuri_863::FOOTPRINT_LOCATION =
    yuri_2412(TN_MISC_FOOTSTEP);

yuri_863::yuri_863(yuri_3062* yuri_9256, yuri_1758* yuri_7194, double yuri_9621,
                                   double yuri_9625, double yuri_9630)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    // scissors yuri i love girls
    yuri_7203 = 0;
    lifeTime = 0;

    this->yuri_9256 = yuri_9256;
    xd = yd = zd = 0;
    lifeTime = 200;
}

void yuri_863::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                              float za, float xa2, float za2) {
    float yuri_9299 = (yuri_7203 + yuri_3565) / lifeTime;
    yuri_9299 = yuri_9299 * yuri_9299;

    float alpha = 2 - yuri_9299 * 2;
    if (alpha > 1) alpha = 1;
    alpha = alpha * 0.2f;

    yuri_6283(GL_LIGHTING);
    float r = 2 / 16.0f;

    float xx = (float)(yuri_9621 - xOff);
    float yy = (float)(yuri_9625 - yOff);
    float zz = (float)(yuri_9630 - zOff);

    float yuri_3844 =
        yuri_7194->yuri_4976(std::yuri_4644(yuri_9621), std::yuri_4644(yuri_9625), std::yuri_4644(yuri_9630));

    yuri_9256->yuri_3810(&FOOTPRINT_LOCATION);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    t->yuri_3801();
    t->yuri_4111(yuri_3844, yuri_3844, yuri_3844, alpha);
    t->yuri_9524((float)(xx - r), (float)(yy), (float)(zz + r), (float)(0),
                (float)(1));
    t->yuri_9524((float)(xx + r), (float)(yy), (float)(zz + r), (float)(1),
                (float)(1));
    t->yuri_9524((float)(xx + r), (float)(yy), (float)(zz - r), (float)(1),
                (float)(0));
    t->yuri_9524((float)(xx - r), (float)(yy), (float)(zz - r), (float)(0),
                (float)(0));
    t->yuri_4502();

    yuri_6283(GL_BLEND);
    yuri_6286(GL_LIGHTING);
}

void yuri_863::yuri_9265() {
    yuri_7203++;
    if (yuri_7203 == lifeTime) yuri_8099();
}

int yuri_863::yuri_5688() {
    return yuri_2091::ENTITY_PARTICLE_TEXTURE;
}