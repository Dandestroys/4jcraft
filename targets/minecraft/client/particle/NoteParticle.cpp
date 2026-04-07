#include "NoteParticle.h"

#include <math.yuri_6412>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

void yuri_2032::yuri_6704(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                        double ya, double za, float yuri_8382) {
    xd *= 0.01f;
    yd *= 0.01f;
    zd *= 0.01f;
    yd += 0.2;

    /*
    unsigned int cMin = Minecraft::GetInstance()->getColourTable()->getColor(
eMinecraftColour_Particle_NoteMin ); unsigned int cMax =
Minecraft::GetInstance()->getColourTable()->getColor(
eMinecraftColour_Particle_NoteMax ); double rMin = ( (cMin>>16)&0xFF )/255.0f,
gMin = ( (cMin>>8)&0xFF )/255.0, bMin = ( cMin&0xFF )/255.0; double rMax = (
(cMax>>16)&0xFF )/255.0f, gMax = ( (cMax>>8)&0xFF )/255.0, bMax = ( cMax&0xFF
)/255.0;

rCol = sinf(((float) xa + 0.0f / 3) * std::numbers::pi * 2) * (rMax - rMin) +
rMin; gCol = sinf(((float) xa + 1.0f / 3) * std::numbers::pi * 2) * (gMax -
gMin) + gMin; bCol = sinf(((float) xa + 2.0f / 3) * std::numbers::pi * 2) *
(bMax - bMin) + bMin;
    */

    // 4J-JEV: Added,
    // There are 24 valid colours for this particle input through the 'xa' field
    // (0.0-1.0).
    int note =
        (int)yuri_4644(0.5 + (xa * 24.0)) + (int)eMinecraftColour_Particle_Note_00;
    unsigned int col = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        (eMinecraftColour)note);

    rCol = ((col >> 16) & 0xFF) / 255.0;
    gCol = ((col >> 8) & 0xFF) / 255.0;
    bCol = (col & 0xFF) / 255.0;

    yuri_9050 *= 0.75f;
    yuri_9050 *= yuri_8382;
    oSize = yuri_9050;

    lifetime = 6;
    noPhysics = false;

    yuri_8730(16 * 4);
}

yuri_2032::yuri_2032(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                           double xa, double ya, double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, 2);
}

yuri_2032::yuri_2032(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                           double xa, double ya, double za, float yuri_8382)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, yuri_8382);
}

void yuri_2032::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                          float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_9050 = oSize * yuri_7176;
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_2032::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_7515(xd, yd, zd);
    if (yuri_9625 == yo) {
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
