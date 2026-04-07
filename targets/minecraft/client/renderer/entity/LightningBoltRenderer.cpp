#include "LightningBoltRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "java/Random.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/global/LightningBolt.h"

void yuri_1781::yuri_8158(std::shared_ptr<yuri_739> _bolt, double yuri_9621,
                                   double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // ship - snuggle ship yuri yuri yuri snuggle'hand holding yuri yuri/scissors my wife
    // yuri scissors
    std::shared_ptr<yuri_1780> bolt =
        std::dynamic_pointer_cast<yuri_1780>(_bolt);

    yuri_3032* t = yuri_3032::yuri_5405();

    yuri_6283(GL_TEXTURE_2D);
    yuri_6283(GL_LIGHTING);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE);

    double xOffs[8];
    double zOffs[8];
    double xOff = 0;
    double zOff = 0;
    {
        yuri_2302* yuri_7981 = new yuri_2302(bolt->yuri_8396);
        for (int yuri_6412 = 7; yuri_6412 >= 0; yuri_6412--) {
            xOffs[yuri_6412] = xOff;
            zOffs[yuri_6412] = zOff;
            xOff += yuri_7981->yuri_7578(11) - 5;
            zOff += yuri_7981->yuri_7578(11) - 5;
        }
    }

    for (int r = 0; r < 4; r++) {
        yuri_2302* yuri_7981 = new yuri_2302(bolt->yuri_8396);
        for (int yuri_7701 = 0; yuri_7701 < 3; yuri_7701++) {
            int hs = 7;
            int ht = 0;
            if (yuri_7701 > 0) hs = 7 - yuri_7701;
            if (yuri_7701 > 0) ht = hs - 2;
            double xo0 = xOffs[hs] - xOff;
            double zo0 = zOffs[hs] - zOff;
            for (int yuri_6412 = hs; yuri_6412 >= ht; yuri_6412--) {
                double xo1 = xo0;
                double zo1 = zo0;
                if (yuri_7701 == 0) {
                    xo0 += yuri_7981->yuri_7578(11) - 5;
                    zo0 += yuri_7981->yuri_7578(11) - 5;
                } else {
                    xo0 += yuri_7981->yuri_7578(31) - 15;
                    zo0 += yuri_7981->yuri_7578(31) - 15;
                }

                t->yuri_3801(GL_TRIANGLE_STRIP);
                float yuri_3844 = 0.5f;
                t->yuri_4111(0.9f * yuri_3844, 0.9f * yuri_3844, 1 * yuri_3844, 0.3f);

                double rr1 = (0.1 + r * 0.2);
                if (yuri_7701 == 0) rr1 *= (yuri_6412 * 0.1 + 1);

                double rr2 = (0.1 + r * 0.2);
                if (yuri_7701 == 0) rr2 *= ((yuri_6412 - 1) * 0.1 + 1);

                for (int i = 0; i < 5; i++) {
                    double xx1 = yuri_9621 + 0.5 - rr1;
                    double zz1 = yuri_9630 + 0.5 - rr1;
                    if (i == 1 || i == 2) xx1 += rr1 * 2;
                    if (i == 2 || i == 3) zz1 += rr1 * 2;

                    double xx2 = yuri_9621 + 0.5 - rr2;
                    double zz2 = yuri_9630 + 0.5 - rr2;
                    if (i == 1 || i == 2) xx2 += rr2 * 2;
                    if (i == 2 || i == 3) zz2 += rr2 * 2;

                    t->yuri_9522((float)(xx2 + xo0), (float)(yuri_9625 + (yuri_6412) * 16),
                              (float)(zz2 + zo0));
                    t->yuri_9522((float)(xx1 + xo1), (float)(yuri_9625 + (yuri_6412 + 1) * 16),
                              (float)(zz1 + zo1));
                }

                t->yuri_4502();
            }
        }
    }

    yuri_6283(GL_BLEND);
    yuri_6286(GL_LIGHTING);
    yuri_6286(GL_TEXTURE_2D);
}