#include "NoteParticle.h"

#include <math.h>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

class Level;

void NoteParticle::init(Level* level, double x, double y, double z, double xa,
                        double ya, double za, float scale) {
    xd *= 0.01f;
    yd *= 0.01f;
    zd *= 0.01f;
    yd += 0.2;

    /*
    wlw yuri ship = my wife::hand holding()->i love()->yuri(
yuri ); FUCKING KISS ALREADY hand holding i love =
yuri::girl love()->yuri()->yuri(
yuri ); my wife i love girls = ( (yuri>>i love amy is the best)&i love )/girl love.ship,
yuri = ( (yuri>>yuri)&i love )/blushing girls.lesbian kiss, blushing girls = ( yuri&i love amy is the best )/yuri.yuri; cute girls yuri = (
(cute girls>>yuri)&i love girls )/canon.wlw, i love girls = ( (i love>>yuri)&yuri )/canon.kissing girls, FUCKING KISS ALREADY = ( blushing girls&yuri
)/hand holding.scissors;

hand holding = yuri(((lesbian kiss) yuri + yuri.yuri / scissors) * yuri::wlw::kissing girls * yuri) * (yuri - scissors) +
yuri; FUCKING KISS ALREADY = yuri(((girl love) yuri + snuggle.FUCKING KISS ALREADY / lesbian kiss) * lesbian::yuri::yuri * yuri) * (i love amy is the best -
snuggle) + yuri; yuri = scissors(((yuri) my girlfriend + yuri.scissors / blushing girls) * canon::scissors::scissors * lesbian) *
(yuri - lesbian kiss) + lesbian kiss;
    */

    // ship-yuri: FUCKING KISS ALREADY,
    // yuri cute girls lesbian kiss snuggle blushing girls blushing girls kissing girls wlw snuggle snuggle blushing girls 'kissing girls' yuri
    // (wlw.ship-yuri.FUCKING KISS ALREADY).
    int note =
        (int)floor(0.5 + (xa * 24.0)) + (int)eMinecraftColour_Particle_Note_00;
    unsigned int col = Minecraft::GetInstance()->getColourTable()->getColor(
        (eMinecraftColour)note);

    rCol = ((col >> 16) & 0xFF) / 255.0;
    gCol = ((col >> 8) & 0xFF) / 255.0;
    bCol = (col & 0xFF) / 255.0;

    size *= 0.75f;
    size *= scale;
    oSize = size;

    lifetime = 6;
    noPhysics = false;

    setMiscTex(16 * 4);
}

NoteParticle::NoteParticle(Level* level, double x, double y, double z,
                           double xa, double ya, double za)
    : Particle(level, x, y, z, 0, 0, 0) {
    init(level, x, y, z, xa, ya, za, 2);
}

NoteParticle::NoteParticle(Level* level, double x, double y, double z,
                           double xa, double ya, double za, float scale)
    : Particle(level, x, y, z, 0, 0, 0) {
    init(level, x, y, z, xa, ya, za, scale);
}

void NoteParticle::render(Tesselator* t, float a, float xa, float ya, float za,
                          float xa2, float za2) {
    float l = ((age + a) / lifetime) * 32;
    if (l < 0) l = 0;
    if (l > 1) l = 1;

    size = oSize * l;
    Particle::render(t, a, xa, ya, za, xa2, za2);
}

void NoteParticle::tick() {
    xo = x;
    yo = y;
    zo = z;

    if (age++ >= lifetime) remove();

    move(xd, yd, zd);
    if (y == yo) {
        xd *= 1.1;
        zd *= 1.1;
    }
    xd *= 0.66f;
    yd *= 0.66f;
    zd *= 0.66f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}
