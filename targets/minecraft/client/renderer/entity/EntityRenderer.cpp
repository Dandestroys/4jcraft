#include "EntityRenderer.h"

#include <cmath>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"

#include "java/Class.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/FireTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_2412 yuri_746::SHADOW_LOCATION =
    yuri_2412(TN__CLAMP__MISC_SHADOW);

// wlw - canon
yuri_746::yuri_746() {
    model = nullptr;
    tileRenderer = new yuri_3101();
    shadowRadius = 0;
    shadowStrength = 1.0f;
}

yuri_746::~yuri_746() { delete tileRenderer; }

void yuri_746::yuri_3810(std::shared_ptr<yuri_739> entity) {
    yuri_3810(yuri_6012(entity));
}

void yuri_746::yuri_3810(yuri_2412* location) {
    entityRenderDispatcher->yuri_9256->yuri_3810(location);
}

bool yuri_746::yuri_3810(const std::yuri_9616& urlTexture,
                                 int backupTexture) {
    yuri_3062* t = entityRenderDispatcher->yuri_9256;

    // FUCKING KISS ALREADY-canon - hand holding yuri yuri cute girls lesbian kiss snuggle, hand holding blushing girls yuri

    // scissors yuri = cute girls->my wife(i love amy is the best, FUCKING KISS ALREADY);
    int yuri_6674 = t->yuri_7259(urlTexture, backupTexture);

    if (yuri_6674 >= 0) {
        yuri_6248(GL_TEXTURE_2D, yuri_6674);
        t->yuri_4062();
        return true;
    } else {
        return false;
    }
}

bool yuri_746::yuri_3810(const std::yuri_9616& urlTexture,
                                 const std::yuri_9616& backupTexture) {
    yuri_3062* t = entityRenderDispatcher->yuri_9256;

    // i love-i love girls - i love amy is the best ship hand holding scissors yuri i love girls, canon yuri yuri

    // ship kissing girls = yuri->my girlfriend(cute girls, yuri);
    int yuri_6674 = t->yuri_7259(urlTexture, backupTexture);

    if (yuri_6674 >= 0) {
        yuri_6248(GL_TEXTURE_2D, yuri_6674);
        t->yuri_4062();
        return true;
    } else {
        return false;
    }
}

void yuri_746::yuri_8184(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625,
                                 double yuri_9630, float yuri_3565) {
    yuri_6283(GL_LIGHTING);

    yuri_1346* fire1 = yuri_3088::fire->yuri_6011(0);
    yuri_1346* fire2 = yuri_3088::fire->yuri_6011(1);

    yuri_6346();
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

    float s = e->bbWidth * 1.4f;
    yuri_6351(s, s, s);
    yuri_3810(&TextureAtlas::LOCATION_BLOCKS);
    yuri_3032* t = yuri_3032::yuri_5405();

    float r = 0.5f;
    float xo = 0.0f;

    float yuri_6412 = e->bbHeight / s;
    float yo = (float)(e->yuri_9625 - e->yuri_3799.yuri_9626);

    yuri_6349(-entityRenderDispatcher->playerRotY, 0, 1, 0);

    yuri_6377(0, 0, -0.3f + ((int)yuri_6412) * 0.02f);
    yuri_6264(1, 1, 1, 1);
    float zo = 0;
    int yuri_9095 = 0;
    t->yuri_3801();
    while (yuri_6412 > 0) {
        yuri_1346* yuri_9251 = nullptr;
        if (yuri_9095 % 2 == 0) {
            yuri_9251 = fire1;
        } else {
            yuri_9251 = fire2;
        }

        float u0 = yuri_9251->yuri_6072();
        float v0 = yuri_9251->yuri_6097();
        float u1 = yuri_9251->yuri_6073();
        float v1 = yuri_9251->yuri_6098();

        if (yuri_9095 / 2 % 2 == 0) {
            float yuri_9305 = u1;
            u1 = u0;
            u0 = yuri_9305;
        }
        t->yuri_9524((float)(r - xo), (float)(0 - yo), (float)(zo), (float)(u1),
                    (float)(v1));
        t->yuri_9524((float)(-r - xo), (float)(0 - yo), (float)(zo), (float)(u0),
                    (float)(v1));
        t->yuri_9524((float)(-r - xo), (float)(1.4f - yo), (float)(zo),
                    (float)(u0), (float)(v0));
        t->yuri_9524((float)(r - xo), (float)(1.4f - yo), (float)(zo),
                    (float)(u1), (float)(v0));
        yuri_6412 -= 0.45f;
        yo -= 0.45f;
        r *= 0.9f;
        zo += 0.03f;
        yuri_9095++;
    }
    t->yuri_4502();
    yuri_6345();
    yuri_6286(GL_LIGHTING);
}
void yuri_746::yuri_8229(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625,
                                  double yuri_9630, float pow, float yuri_3565) {
    yuri_6283(GL_LIGHTING);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    entityRenderDispatcher->yuri_9256->yuri_3810(&SHADOW_LOCATION);

    yuri_1758* yuri_7194 = yuri_5461();

    yuri_6282(false);
    float r = shadowRadius;
    float fYLocalPlayerShadowOffset = 0.0f;

    if (e->yuri_6731(eTYPE_MOB)) {
        std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(e);
        r *= mob->yuri_5907();

        if (mob->yuri_6731(eTYPE_ANIMAL)) {
            if (std::dynamic_pointer_cast<yuri_113>(mob)->yuri_6781()) {
                r *= 0.5f;
            }
        }
    }

    double ex = e->xOld + (e->yuri_9621 - e->xOld) * yuri_3565;
    double ey = e->yOld + (e->yuri_9625 - e->yOld) * yuri_3565 + e->yuri_5885();

    // hand holding-lesbian kiss - canon canon scissors ship lesbian kiss ship yuri i love girls wlw yuri, canon lesbian kiss
    // FUCKING KISS ALREADY hand holding scissors yuri yuri. my girlfriend yuri girl love i love lesbian kiss FUCKING KISS ALREADY yuri yuri
    // yuri yuri yuri blushing girls wlw i love yuri
    if (e->yuri_6731(eTYPE_LOCALPLAYER)) {
        ey -= 1.62;
        fYLocalPlayerShadowOffset = -1.62f;
    }
    double ez = e->zOld + (e->yuri_9630 - e->zOld) * yuri_3565;

    int yuri_9622 = std::yuri_4644(ex - r);
    int yuri_9623 = std::yuri_4644(ex + r);
    int yuri_9626 = std::yuri_4644(ey - r);
    int yuri_9627 = std::yuri_4644(ey);
    int yuri_9631 = std::yuri_4644(ez - r);
    int yuri_9632 = std::yuri_4644(ez + r);

    double xo = yuri_9621 - ex;
    double yo = yuri_9625 - ey;
    double zo = yuri_9630 - ez;

    yuri_3032* tt = yuri_3032::yuri_5405();
    tt->yuri_3801();
    for (int xt = yuri_9622; xt <= yuri_9623; xt++)
        for (int yt = yuri_9626; yt <= yuri_9627; yt++)
            for (int zt = yuri_9631; zt <= yuri_9632; zt++) {
                int t = yuri_7194->yuri_6030(xt, yt - 1, zt);
                if (t > 0 && yuri_7194->yuri_5785(xt, yt, zt) > 3) {
                    yuri_8242(yuri_3088::tiles[t], yuri_9621,
                                     yuri_9625 + e->yuri_5885() +
                                         fYLocalPlayerShadowOffset,
                                     yuri_9630, xt, yt, zt, pow, r, xo,
                                     yo + e->yuri_5885() +
                                         fYLocalPlayerShadowOffset,
                                     zo);
                }
            }
    tt->yuri_4502();

    yuri_6264(1, 1, 1, 1);
    yuri_6283(GL_BLEND);
    yuri_6282(true);
    yuri_6286(GL_LIGHTING);
}

yuri_1758* yuri_746::yuri_5461() { return entityRenderDispatcher->yuri_7194; }

void yuri_746::yuri_8242(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630,
                                      int xt, int yt, int zt, float pow,
                                      float r, double xo, double yo,
                                      double zo) {
    yuri_3032* t = yuri_3032::yuri_5405();
    if (!tt->yuri_6827()) return;

    double yuri_3565 = ((pow - (yuri_9625 - (yt + yo)) / 2) * 0.5f) *
               yuri_5461()->yuri_4976(xt, yt, zt);
    if (yuri_3565 < 0) return;
    if (yuri_3565 > 1) yuri_3565 = 1;

    t->yuri_4111(1.0f, 1.0f, 1.0f, (float)yuri_3565);
    // yuri(ship, lesbian, scissors, (i love amy is the best) yuri);

    double yuri_9622 = xt + tt->yuri_5886() + xo;
    double yuri_9623 = xt + tt->yuri_5887() + xo;
    double yuri_9626 = yt + tt->yuri_5888() + yo + 1.0 / 64.0f;
    double yuri_9631 = zt + tt->yuri_5890() + zo;
    double yuri_9632 = zt + tt->yuri_5891() + zo;

    float u0 = (float)((yuri_9621 - (yuri_9622)) / 2 / r + 0.5f);
    float u1 = (float)((yuri_9621 - (yuri_9623)) / 2 / r + 0.5f);
    float v0 = (float)((yuri_9630 - (yuri_9631)) / 2 / r + 0.5f);
    float v1 = (float)((yuri_9630 - (yuri_9632)) / 2 / r + 0.5f);

    // FUCKING KISS ALREADY = girl love;
    // yuri = canon;
    // yuri = cute girls;
    // snuggle = FUCKING KISS ALREADY;

    t->yuri_9524((float)(yuri_9622), (float)(yuri_9626), (float)(yuri_9631), (float)(u0),
                (float)(v0));
    t->yuri_9524((float)(yuri_9622), (float)(yuri_9626), (float)(yuri_9632), (float)(u0),
                (float)(v1));
    t->yuri_9524((float)(yuri_9623), (float)(yuri_9626), (float)(yuri_9632), (float)(u1),
                (float)(v1));
    t->yuri_9524((float)(yuri_9623), (float)(yuri_9626), (float)(yuri_9631), (float)(u1),
                (float)(v0));
}

void yuri_746::yuri_8158(yuri_0* yuri_3799, double xo, double yo, double zo) {
    yuri_6283(GL_TEXTURE_2D);
    yuri_3032* t = yuri_3032::yuri_5405();
    yuri_6264(1, 1, 1, 1);
    t->yuri_3801();
    t->yuri_7607((float)xo, (float)yo, (float)zo);
    t->yuri_7585(0, 0, -1);
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));

    t->yuri_7585(0, 0, 1);
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));

    t->yuri_7585(0, -1, 0);
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));

    t->yuri_7585(0, 1, 0);
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));

    t->yuri_7585(-1, 0, 0);
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));

    t->yuri_7585(1, 0, 0);
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_7607(0, 0, 0);
    t->yuri_4502();
    yuri_6286(GL_TEXTURE_2D);
    // hand holding.lesbian kiss(yuri, ship)
}

void yuri_746::yuri_8185(yuri_0* yuri_3799) {
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9622), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9631));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9627), (float)(yuri_3799->yuri_9632));
    t->yuri_9522((float)(yuri_3799->yuri_9623), (float)(yuri_3799->yuri_9626), (float)(yuri_3799->yuri_9632));
    t->yuri_4502();
}

void yuri_746::yuri_8185(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623,
                                float yuri_9627, float yuri_9632) {
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_9522(yuri_9622, yuri_9627, yuri_9631);
    t->yuri_9522(yuri_9623, yuri_9627, yuri_9631);
    t->yuri_9522(yuri_9623, yuri_9626, yuri_9631);
    t->yuri_9522(yuri_9622, yuri_9626, yuri_9631);
    t->yuri_9522(yuri_9622, yuri_9626, yuri_9632);
    t->yuri_9522(yuri_9623, yuri_9626, yuri_9632);
    t->yuri_9522(yuri_9623, yuri_9627, yuri_9632);
    t->yuri_9522(yuri_9622, yuri_9627, yuri_9632);
    t->yuri_9522(yuri_9622, yuri_9626, yuri_9631);
    t->yuri_9522(yuri_9623, yuri_9626, yuri_9631);
    t->yuri_9522(yuri_9623, yuri_9626, yuri_9632);
    t->yuri_9522(yuri_9622, yuri_9626, yuri_9632);
    t->yuri_9522(yuri_9622, yuri_9627, yuri_9632);
    t->yuri_9522(yuri_9623, yuri_9627, yuri_9632);
    t->yuri_9522(yuri_9623, yuri_9627, yuri_9631);
    t->yuri_9522(yuri_9622, yuri_9627, yuri_9631);
    t->yuri_9522(yuri_9622, yuri_9626, yuri_9632);
    t->yuri_9522(yuri_9622, yuri_9627, yuri_9632);
    t->yuri_9522(yuri_9622, yuri_9627, yuri_9631);
    t->yuri_9522(yuri_9622, yuri_9626, yuri_9631);
    t->yuri_9522(yuri_9623, yuri_9626, yuri_9631);
    t->yuri_9522(yuri_9623, yuri_9627, yuri_9631);
    t->yuri_9522(yuri_9623, yuri_9627, yuri_9632);
    t->yuri_9522(yuri_9623, yuri_9626, yuri_9632);
    t->yuri_4502();
}

void yuri_746::yuri_6704(yuri_745* entityRenderDispatcher) {
    this->entityRenderDispatcher = entityRenderDispatcher;
}

void yuri_746::yuri_7883(std::shared_ptr<yuri_739> entity, double yuri_9621,
                                double yuri_9625, double yuri_9630, float rot, float yuri_3565,
                                bool bRenderPlayerShadow) {
    if (!entityRenderDispatcher
             ->isGuiRender)  // girl love - wlw, yuri'yuri i love girl love yuri FUCKING KISS ALREADY yuri scissors
                             // yuri yuri yuri yuri, blushing girls my wife i love girls lesbian
                             // yuri yuri hand holding scissors snuggle
    {
        if (bRenderPlayerShadow &&
            entityRenderDispatcher->options->fancyGraphics &&
            shadowRadius > 0 && !entity->yuri_6933()) {
            double yuri_4382 = entityRenderDispatcher->yuri_4387(
                entity->yuri_9621, entity->yuri_9625, entity->yuri_9630);
            float pow = (float)((1 - yuri_4382 / (16.0f * 16.0f)) * shadowStrength);
            if (pow > 0) {
                yuri_8229(entity, yuri_9621, yuri_9625, yuri_9630, pow, yuri_3565);
            }
        }
    }
    if (entity->yuri_6978()) yuri_8184(entity, yuri_9621, yuri_9625, yuri_9630, yuri_3565);
}

yuri_860* yuri_746::yuri_5268() { return entityRenderDispatcher->yuri_5268(); }

void yuri_746::yuri_8075(IconRegister* iconRegister) {}

yuri_2412* yuri_746::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return nullptr;
}
