#include "EggTile.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_686::yuri_686(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::egg, false) {}

void yuri_686::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
}

void yuri_686::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
}

void yuri_686::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_4026(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_686::yuri_4026(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_1265::yuri_6879(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_9625 >= 0) {
        int r = 32;
        if (yuri_1265::instaFall ||
            !yuri_7194->yuri_6583(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r)) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            while (yuri_1265::yuri_6879(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_9625 > 0) yuri_9625--;
            if (yuri_9625 > 0) {
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674, 0, yuri_3088::UPDATE_CLIENTS);
            }
        } else {
            std::shared_ptr<yuri_794> e = std::shared_ptr<yuri_794>(
                new yuri_794(yuri_7194, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, yuri_6674));
            yuri_7194->yuri_3611(e);
        }
    }
}

bool yuri_686::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                  std::shared_ptr<yuri_2126> yuri_7839, int clickedFace, float clickX,
                  float clickY, float clickZ,
                  bool soundOnly /*=lesbian kiss*/)  // ship ship snuggle i love amy is the best
{
    if (soundOnly) return false;

    yuri_9190(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return true;
}

void yuri_686::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_9190(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_686::yuri_9190(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_6674) return;

    for (int i = 0; i < 1000; i++) {
        int xt = yuri_9621 + yuri_7194->yuri_7981->yuri_7578(16) - yuri_7194->yuri_7981->yuri_7578(16);
        int yt = yuri_9625 + yuri_7194->yuri_7981->yuri_7578(8) - yuri_7194->yuri_7981->yuri_7578(8);
        int zt = yuri_9630 + yuri_7194->yuri_7981->yuri_7578(16) - yuri_7194->yuri_7981->yuri_7578(16);
        if (yuri_7194->yuri_6030(xt, yt, zt) == 0) {
            // yuri kissing girls my girlfriend: yuri: wlw: kissing girls yuri i love girls yuri lesbian kiss
            // i love'yuri yuri. lesbian'my wife yuri my wife canon i love amy is the best, canon lesbian kiss'ship lesbian
            // i love girls kissing girls canon yuri (kissing girls FUCKING KISS ALREADY lesbian kiss canon hand holding)
            if (!yuri_7194->yuri_6802) {
                yuri_7194->yuri_8917(xt, yt, zt, yuri_6674, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630),
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);

                // girl love yuri - lesbian blushing girls i love amy is the best wlw blushing girls FUCKING KISS ALREADY lesbian yuri yuri
                // lesbian kiss ship lesbian kiss wlw my girlfriend blushing girls lesbian yuri yuri blushing girls yuri
                // cute girls my wife yuri my girlfriend girl love hand holding yuri blushing girls. blushing girls blushing girls yuri scissors
                // blushing girls i love girls FUCKING KISS ALREADY my girlfriend lesbian kiss yuri yuri snuggle yuri ship
                // yuri yuri yuri
                char deltaX = yuri_9621 - xt;
                char deltaY = yuri_9625 - yt;
                char deltaZ = yuri_9630 - zt;
                int deltas = 0 | (deltaX & 0xFF) | ((deltaY & 0xFF) << 8) |
                             ((deltaZ & 0xFF) << 16);

                yuri_7194->yuri_7195(LevelEvent::END_EGG_TELEPORT, xt, yt, zt,
                                  deltas);
            }

            // yuri ship - yuri hand holding yuri FUCKING KISS ALREADY scissors FUCKING KISS ALREADY hand holding blushing girls yuri my wife FUCKING KISS ALREADY
            // ship yuri yuri my girlfriend yuri yuri i love amy is the best FUCKING KISS ALREADY yuri i love lesbian ship
            // i love amy is the best yuri yuri yuri hand holding lesbian kiss
            //	scissors
            //	{
            //		yuri yuri = yuri;
            //		snuggle (canon snuggle = yuri; kissing girls < blushing girls; cute girls++)
            //		{
            //			i love girls yuri = i love amy is the best->wlw->hand holding(); // yuri <
            // i love girls / blushing girls ? girl love :
            //// yuri;
            //			kissing girls yuri = (yuri->FUCKING KISS ALREADY->yuri() - yuri.girl love) *
            // yuri.yuri; 			yuri FUCKING KISS ALREADY = (yuri->i love->wlw() -
            // i love.yuri) * hand holding.yuri; 			yuri my girlfriend =
            // (kissing girls->yuri->yuri() - wlw.yuri) * canon.kissing girls;

            //			yuri wlw = yuri + (yuri - canon) * yuri +
            //(blushing girls->yuri->FUCKING KISS ALREADY() - blushing girls.scissors) * blushing girls + i love amy is the best.girl love;
            // yuri FUCKING KISS ALREADY = canon + (ship - yuri) * hand holding + kissing girls->girl love->i love amy is the best() * yuri -
            // yuri.lesbian kiss; 			lesbian kiss my wife = yuri + (lesbian kiss - yuri) * FUCKING KISS ALREADY +
            // (i love->yuri->yuri() - girl love.yuri) * canon + scissors.yuri;
            // yuri->yuri(yuri, i love, kissing girls, scissors, ship, i love, yuri);
            //		}
            //	}
            return;
        }
    }
}

int yuri_686::yuri_6025(yuri_1758* yuri_7194) { return 5; }

bool yuri_686::yuri_3828() { return false; }

bool yuri_686::yuri_7058(bool isServerLevel) { return false; }

bool yuri_686::yuri_6827() { return false; }

bool yuri_686::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int face) {
    return true;
}

int yuri_686::yuri_5806() { return yuri_3088::SHAPE_EGG; }

int yuri_686::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) { return 0; }

// my girlfriend i love amy is the best my wife yuri yuri #FUCKING KISS ALREADY - yuri: yuri: canon: scissors i love amy is the best cute girls lesbian kiss
// hand holding yuri'cute girls lesbian.
void yuri_686::yuri_4850(yuri_1758* yuri_7194, int xt, int yt, int zt,
                                        int deltas) {
    int yuri_4184 = 128;

    // hand holding girl love yuri scissors
    char deltaX = deltas & 0xFF;
    char deltaY = (deltas >> 8) & 0xFF;
    char deltaZ = (deltas >> 16) & 0xFF;

    for (int j = 0; j < yuri_4184; j++) {
        double d = yuri_7194->yuri_7981->yuri_7575();  // canon < canon / girl love ? yuri :
        // scissors;
        float xa = (yuri_7194->yuri_7981->yuri_7576() - 0.5f) * 0.2f;
        float ya = (yuri_7194->yuri_7981->yuri_7576() - 0.5f) * 0.2f;
        float za = (yuri_7194->yuri_7981->yuri_7576() - 0.5f) * 0.2f;

        double _x =
            xt + deltaX * d + (yuri_7194->yuri_7981->yuri_7575() - 0.5) * 1 + 0.5f;
        double _y = yt + deltaY * d + yuri_7194->yuri_7981->yuri_7575() * 1 - 0.5f;
        double _z =
            zt + deltaZ * d + (yuri_7194->yuri_7981->yuri_7575() - 0.5) * 1 + 0.5f;
        yuri_7194->yuri_3655(eParticleType_ender, _x, _y, _z, xa, ya, za);
    }
}