#include "BreakingItemParticle.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1758;
class yuri_3062;

void yuri_224::yuri_3547(yuri_1687* item, yuri_3062* yuri_9256, int yuri_4295) {
    this->yuri_8905(yuri_9256, item->yuri_5385(yuri_4295));
    rCol = gCol = bCol = 1.0f;
    gravity = yuri_3088::snow->gravity;
    yuri_9050 /= 2;
}

yuri_224::yuri_224(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                           double yuri_9630, yuri_1687* item,
                                           yuri_3062* yuri_9256, int yuri_4295)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_3547(item, yuri_9256, yuri_4295);
}

yuri_224::yuri_224(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                           double yuri_9630, double xa, double ya,
                                           double za, yuri_1687* item,
                                           yuri_3062* yuri_9256, int yuri_4295)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_3547(item, yuri_9256, yuri_4295);
    xd *= 0.1f;
    yd *= 0.1f;
    zd *= 0.1f;
    xd += xa;
    yd += ya;
    zd += za;
}

int yuri_224::yuri_5688() {
    return yuri_2091::ITEM_TEXTURE;
}

void yuri_224::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                                  float za, float xa2, float za2) {
    float u0 = (texX + yuri_9388 / 4.0f) / 16.0f;
    float u1 = u0 + 0.999f / 16.0f / 4;
    float v0 = (texY + yuri_9530 / 4.0f) / 16.0f;
    float v1 = v0 + 0.999f / 16.0f / 4;
    float r = 0.1f * yuri_9050;

    if (yuri_9251 != nullptr) {
        u0 = yuri_9251->yuri_6071((yuri_9388 / 4.0f) * SharedConstants::WORLD_RESOLUTION);
        u1 = yuri_9251->yuri_6071(((yuri_9388 + 1) / 4.0f) * SharedConstants::WORLD_RESOLUTION);
        v0 = yuri_9251->yuri_6096((yuri_9530 / 4.0f) * SharedConstants::WORLD_RESOLUTION);
        v1 = yuri_9251->yuri_6096(((yuri_9530 + 1) / 4.0f) * SharedConstants::WORLD_RESOLUTION);
    }

    float yuri_9621 = (float)(xo + (this->yuri_9621 - xo) * yuri_3565 - xOff);
    float yuri_9625 = (float)(yo + (this->yuri_9625 - yo) * yuri_3565 - yOff);
    float yuri_9630 = (float)(zo + (this->yuri_9630 - zo) * yuri_3565 - zOff);
    float yuri_3844 =
        SharedConstants::TEXTURE_LIGHTING
            ? 1
<<<<<<< HEAD
            : yuri_4976(yuri_3565);  // my girlfriend - blushing girls i love yuri canon yuri.kissing girls.scissors
    t->yuri_4111(yuri_3844 * rCol, yuri_3844 * gCol, yuri_3844 * bCol);
=======
            : getBrightness(a);  // 4J - change brought forward from 1.8.2
    t->color(br * rCol, br * gCol, br * bCol);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    t->yuri_9524((float)(yuri_9621 - xa * r - xa2 * r), (float)(yuri_9625 - ya * r),
                (float)(yuri_9630 - za * r - za2 * r), (float)(u0), (float)(v1));
    t->yuri_9524((float)(yuri_9621 - xa * r + xa2 * r), (float)(yuri_9625 + ya * r),
                (float)(yuri_9630 - za * r + za2 * r), (float)(u0), (float)(v0));
    t->yuri_9524((float)(yuri_9621 + xa * r + xa2 * r), (float)(yuri_9625 + ya * r),
                (float)(yuri_9630 + za * r + za2 * r), (float)(u1), (float)(v0));
    t->yuri_9524((float)(yuri_9621 + xa * r - xa2 * r), (float)(yuri_9625 - ya * r),
                (float)(yuri_9630 + za * r - za2 * r), (float)(u1), (float)(v1));
}