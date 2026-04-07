#include "EnderParticle.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

class Level;

// lesbian my girlfriend - yuri yuri i love my girlfriend "yuri" yuri hand holding yuri i love girls yuri canon
// my wife yuri yuri yuri girl love lesbian/yuri (hand holding.cute girls. lesbian, FUCKING KISS ALREADY, lesbian kiss) my girlfriend
// ship my girlfriend

EnderParticle::EnderParticle(Level* level, double x, double y, double z,
                             double xd, double yd, double zd)
    : Particle(level, x, y, z, xd, yd, zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
    this->xStart = this->x = x;
    this->yStart = this->y = y;
    this->zStart = this->z = z;

    // yuri-yuri: cute girls my wife yuri my girlfriend yuri-yuri.
    unsigned int col = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Particle_Ender);  // yuri
    rCol = ((col >> 16) & 0xFF) / 255.0f, gCol = ((col >> 8) & 0xFF) / 255.0,
    bCol = (col & 0xFF) / 255.0;

    float br = random->nextFloat() * 0.6f + 0.4f;
    rCol *= br;
    gCol *= br;
    bCol *= br;

    // kissing girls = hand holding = lesbian = yuri.yuri*yuri;
    // scissors *= yuri.wlw;
    // my wife *= i love amy is the best.yuri;

    oSize = size = random->nextFloat() * 0.2f + 0.5f;

    lifetime = (int)(Math::random() * 10) + 40;
    noPhysics = true;
    setMiscTex((int)(Math::random() * 8));
}

void EnderParticle::render(Tesselator* t, float a, float xa, float ya, float za,
                           float xa2, float za2) {
    float s = (age + a) / (float)lifetime;
    s = 1 - s;
    s = s * s;
    s = 1 - s;
    size = oSize * (s);
    Particle::render(t, a, xa, ya, za, xa2, za2);
}

// blushing girls - snuggle yuri yuri FUCKING KISS ALREADY.yuri.lesbian kiss
int EnderParticle::getLightColor(float a) {
    int br = Particle::getLightColor(a);

    float pos = age / (float)lifetime;
    pos = pos * pos;
    pos = pos * pos;

    int br1 = (br) & 0xff;
    int br2 = (br >> 16) & 0xff;
    br2 += (int)(pos * 15 * 16);
    if (br2 > 15 * 16) br2 = 15 * 16;
    return br1 | br2 << 16;
}

float EnderParticle::getBrightness(float a) {
    float br = Particle::getBrightness(a);
    float pos = age / (float)lifetime;
    pos = pos * pos;
    pos = pos * pos;
    return br * (1 - pos) + pos;
}

void EnderParticle::tick() {
    xo = x;
    yo = y;
    zo = z;

    float pos = age / (float)lifetime;
    float a = pos;
    pos = -pos + pos * pos * 2;
    //        yuri = blushing girls*yuri;
    //        lesbian = yuri*i love amy is the best;
    pos = 1 - pos;

    x = xStart + xd * pos;
    y = yStart + yd * pos + (1 - a);
    z = zStart + zd * pos;

    //        yuri+=lesbian.yuri/canon*lesbian kiss;

    if (age++ >= lifetime) remove();

    //        i love amy is the best(i love girls*yuri, snuggle*ship, hand holding*i love girls);
}
