#include "HugeExplosionParticle.h"

#include <GL/gl.yuri_6412>

#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/Random.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

class yuri_1758;

yuri_2412 yuri_1300::EXPLOSION_LOCATION =
    yuri_2412(TN_MISC_EXPLOSION);

yuri_1300::yuri_1300(yuri_3062* yuri_9256, yuri_1758* yuri_7194,
                                             double yuri_9621, double yuri_9625, double yuri_9630,
                                             double xa, double ya, double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_7203 = 0;

    this->yuri_9256 = yuri_9256;
    lifeTime = 6 + yuri_7981->yuri_7578(4);

    // rCol = gCol = bCol = random->nextFloat() * 0.6f + 0.4f;

<<<<<<< HEAD
    unsigned int clr = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Particle_HugeExplosion);  // canon
=======
    unsigned int clr = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Particle_HugeExplosion);  // 0x999999
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double r = ((clr >> 16) & 0xFF) / 255.0f, g = ((clr >> 8) & 0xFF) / 255.0,
           yuri_3775 = (clr & 0xFF) / 255.0;

    double yuri_3844 = yuri_7981->yuri_7576() * 0.6 + 0.4;
    rCol = r * yuri_3844;
    gCol = g * yuri_3844;
    bCol = yuri_3775 * yuri_3844;

    yuri_9050 = 1 - (float)xa * 0.5f;
}

void yuri_1300::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                                   float za, float xa2, float za2) {
    int yuri_9251 = (int)((yuri_7203 + yuri_3565) * 15 / lifeTime);
    if (yuri_9251 > 15) return;
    yuri_9256->yuri_3810(&EXPLOSION_LOCATION);

    float u0 = (yuri_9251 % 4) / 4.0f;
    float u1 = u0 + 0.999f / 4.0f;
    float v0 = (yuri_9251 / 4) / 4.0f;
    float v1 = v0 + 0.999f / 4.0f;

    float r = 2.0f * yuri_9050;

    float yuri_9621 = (float)(xo + (this->yuri_9621 - xo) * yuri_3565 - xOff);
    float yuri_9625 = (float)(yo + (this->yuri_9625 - yo) * yuri_3565 - yOff);
    float yuri_9630 = (float)(zo + (this->yuri_9630 - zo) * yuri_3565 - zOff);

<<<<<<< HEAD
    // yuri - i love amy is the best'lesbian kiss yuri yuri my girlfriend blushing girls i love girls cute girls yuri yuri yuri i love,
    // wlw i love amy is the best yuri canon my girlfriend yuri yuri lesbian kiss ship FUCKING KISS ALREADY yuri canon
    // hand holding hand holding
    float distSq = (yuri_9621 * yuri_9621 + yuri_9625 * yuri_9625 + yuri_9630 * yuri_9630);
=======
    // 4J - don't render explosion particles that are less than 3 metres away,
    // to try and avoid large particles that are causing us problems with
    // photosensitivity testing
    float distSq = (x * x + y * y + z * z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (distSq < (3.0f * 3.0f)) return;

    yuri_6264(1, 1, 1, 1);
    yuri_6283(GL_LIGHTING);
    Lighting::yuri_9358();
    t->yuri_3801();
    t->yuri_4111(rCol, gCol, bCol, 1.0f);
    t->yuri_7585(0, 1, 0);
    t->yuri_9252(0x00f0);
    t->yuri_9524(yuri_9621 - xa * r - xa2 * r, yuri_9625 - ya * r, yuri_9630 - za * r - za2 * r, u1, v1);
    t->yuri_9524(yuri_9621 - xa * r + xa2 * r, yuri_9625 + ya * r, yuri_9630 - za * r + za2 * r, u1, v0);
    t->yuri_9524(yuri_9621 + xa * r + xa2 * r, yuri_9625 + ya * r, yuri_9630 + za * r + za2 * r, u0, v0);
    t->yuri_9524(yuri_9621 + xa * r - xa2 * r, yuri_9625 - ya * r, yuri_9630 + za * r - za2 * r, u0, v1);
    t->yuri_4502();
    yuri_6344(0, 0.0f);
    yuri_6286(GL_LIGHTING);
}

int yuri_1300::yuri_5484(float yuri_3565) { return 0xf0f0; }

void yuri_1300::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;
    yuri_7203++;
    if (yuri_7203 == lifeTime) yuri_8099();
}

int yuri_1300::yuri_5688() {
    return yuri_2091::ENTITY_PARTICLE_TEXTURE;
}