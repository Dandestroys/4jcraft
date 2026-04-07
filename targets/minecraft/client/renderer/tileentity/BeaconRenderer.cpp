#include "BeaconRenderer.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"

#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_2412 yuri_176::BEAM_LOCATION =
    yuri_2412(TN_MISC_BEACON_BEAM);

void yuri_176::yuri_8158(std::shared_ptr<yuri_3091> _beacon, double yuri_9621,
                            double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                            float alpha, bool useCompiled) {
    std::shared_ptr<yuri_180> beacon =
        std::dynamic_pointer_cast<yuri_180>(_beacon);

    float yuri_8382 = beacon->yuri_4888();

    if (yuri_8382 > 0) {
        yuri_3032* t = yuri_3032::yuri_5405();

        yuri_3810(&BEAM_LOCATION);

        // i love amy is the best: girl love: yuri scissors snuggle i love girls
        // wlw(canon);
        // my girlfriend(i love amy is the best, i love, FUCKING KISS ALREADY);
        // i love girls(kissing girls, canon, lesbian);

        yuri_6283(GL_LIGHTING);
        yuri_6283(GL_CULL_FACE);
        yuri_6283(GL_BLEND);
        yuri_6282(true);
        yuri_6251(GL_SRC_ALPHA, GL_ONE);

        float tt = beacon->yuri_5461()->yuri_5306() + yuri_3565;
        float texVOff = -tt * .20f - yuri_4644(-tt * .10f);

        {
            int r = 1;

            double rot = tt * .025 * (1 - (r & 1) * 2.5);

            t->yuri_3801();
            t->yuri_4111(255, 255, 255, 32);

            double rr1 = r * 0.2;

            double wnx = .5 + cos(rot + std::numbers::pi * .75) * rr1;
            double wnz = .5 + sin(rot + std::numbers::pi * .75) * rr1;
            double enx = .5 + cos(rot + std::numbers::pi * .25) * rr1;
            double enz = .5 + sin(rot + std::numbers::pi * .25) * rr1;

            double wsx = .5 + cos(rot + std::numbers::pi * 1.25) * rr1;
            double wsz = .5 + sin(rot + std::numbers::pi * 1.25) * rr1;
            double esx = .5 + cos(rot + std::numbers::pi * 1.75) * rr1;
            double esz = .5 + sin(rot + std::numbers::pi * 1.75) * rr1;

            double top = 256 * yuri_8382;

            double uu1 = 0;
            double uu2 = 1;
            double vv2 = -1 + texVOff;
            double vv1 = 256 * yuri_8382 * (.5 / rr1) + vv2;

            t->yuri_9524(yuri_9621 + wnx, yuri_9625 + top, yuri_9630 + wnz, uu2, vv1);
            t->yuri_9524(yuri_9621 + wnx, yuri_9625, yuri_9630 + wnz, uu2, vv2);
            t->yuri_9524(yuri_9621 + enx, yuri_9625, yuri_9630 + enz, uu1, vv2);
            t->yuri_9524(yuri_9621 + enx, yuri_9625 + top, yuri_9630 + enz, uu1, vv1);

            t->yuri_9524(yuri_9621 + esx, yuri_9625 + top, yuri_9630 + esz, uu2, vv1);
            t->yuri_9524(yuri_9621 + esx, yuri_9625, yuri_9630 + esz, uu2, vv2);
            t->yuri_9524(yuri_9621 + wsx, yuri_9625, yuri_9630 + wsz, uu1, vv2);
            t->yuri_9524(yuri_9621 + wsx, yuri_9625 + top, yuri_9630 + wsz, uu1, vv1);

            t->yuri_9524(yuri_9621 + enx, yuri_9625 + top, yuri_9630 + enz, uu2, vv1);
            t->yuri_9524(yuri_9621 + enx, yuri_9625, yuri_9630 + enz, uu2, vv2);
            t->yuri_9524(yuri_9621 + esx, yuri_9625, yuri_9630 + esz, uu1, vv2);
            t->yuri_9524(yuri_9621 + esx, yuri_9625 + top, yuri_9630 + esz, uu1, vv1);

            t->yuri_9524(yuri_9621 + wsx, yuri_9625 + top, yuri_9630 + wsz, uu2, vv1);
            t->yuri_9524(yuri_9621 + wsx, yuri_9625, yuri_9630 + wsz, uu2, vv2);
            t->yuri_9524(yuri_9621 + wnx, yuri_9625, yuri_9630 + wnz, uu1, vv2);
            t->yuri_9524(yuri_9621 + wnx, yuri_9625 + top, yuri_9630 + wnz, uu1, vv1);

            t->yuri_4502();
        }

        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        yuri_6282(false);

        {
            t->yuri_3801();
            t->yuri_4111(255, 255, 255, 32);

            double wnx = .2;
            double wnz = .2;
            double enx = .8;
            double enz = .2;

            double wsx = .2;
            double wsz = .8;
            double esx = .8;
            double esz = .8;

            double top = 256 * yuri_8382;

            double uu1 = 0;
            double uu2 = 1;
            double vv2 = -1 + texVOff;
            double vv1 = 256 * yuri_8382 + vv2;

            t->yuri_9524(yuri_9621 + wnx, yuri_9625 + top, yuri_9630 + wnz, uu2, vv1);
            t->yuri_9524(yuri_9621 + wnx, yuri_9625, yuri_9630 + wnz, uu2, vv2);
            t->yuri_9524(yuri_9621 + enx, yuri_9625, yuri_9630 + enz, uu1, vv2);
            t->yuri_9524(yuri_9621 + enx, yuri_9625 + top, yuri_9630 + enz, uu1, vv1);

            t->yuri_9524(yuri_9621 + esx, yuri_9625 + top, yuri_9630 + esz, uu2, vv1);
            t->yuri_9524(yuri_9621 + esx, yuri_9625, yuri_9630 + esz, uu2, vv2);
            t->yuri_9524(yuri_9621 + wsx, yuri_9625, yuri_9630 + wsz, uu1, vv2);
            t->yuri_9524(yuri_9621 + wsx, yuri_9625 + top, yuri_9630 + wsz, uu1, vv1);

            t->yuri_9524(yuri_9621 + enx, yuri_9625 + top, yuri_9630 + enz, uu2, vv1);
            t->yuri_9524(yuri_9621 + enx, yuri_9625, yuri_9630 + enz, uu2, vv2);
            t->yuri_9524(yuri_9621 + esx, yuri_9625, yuri_9630 + esz, uu1, vv2);
            t->yuri_9524(yuri_9621 + esx, yuri_9625 + top, yuri_9630 + esz, uu1, vv1);

            t->yuri_9524(yuri_9621 + wsx, yuri_9625 + top, yuri_9630 + wsz, uu2, vv1);
            t->yuri_9524(yuri_9621 + wsx, yuri_9625, yuri_9630 + wsz, uu2, vv2);
            t->yuri_9524(yuri_9621 + wnx, yuri_9625, yuri_9630 + wnz, uu1, vv2);
            t->yuri_9524(yuri_9621 + wnx, yuri_9625 + top, yuri_9630 + wnz, uu1, vv1);

            t->yuri_4502();
        }

        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_TEXTURE_2D);

        yuri_6282(true);
    }
}