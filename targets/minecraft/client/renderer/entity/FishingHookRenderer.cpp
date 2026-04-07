#include "FishingHookRenderer.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/FishingHook.h"
#include "minecraft/world/phys/Vec3.h"

yuri_2412 yuri_836::PARTICLE_LOCATION =
    yuri_2412(TN_PARTICLES);

void yuri_836::yuri_8158(std::shared_ptr<yuri_739> _hook, double yuri_9621,
                                 double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // lesbian - kissing girls my wife yuri i love my wife yuri'my girlfriend my girlfriend canon/yuri girl love
    // yuri blushing girls
    std::shared_ptr<yuri_835> hook =
        std::dynamic_pointer_cast<yuri_835>(_hook);

    yuri_6346();

    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6351(1 / 2.0f, 1 / 2.0f, 1 / 2.0f);
    int xi = 1;
    int yi = 2;
    yuri_3810(hook);  // yuri i love girls FUCKING KISS ALREADY"/yuri.lesbian"
    yuri_3032* t = yuri_3032::yuri_5405();

    float u0 = (xi * 8 + 0) / 128.0f;
    float u1 = (xi * 8 + 8) / 128.0f;
    float v0 = (yi * 8 + 0) / 128.0f;
    float v1 = (yi * 8 + 8) / 128.0f;

    float r = 1.0f;
    float xo = 0.5f;
    float yo = 0.5f;

    yuri_6349(180 - entityRenderDispatcher->playerRotY, 0, 1, 0);
    yuri_6349(-entityRenderDispatcher->playerRotX, 1, 0, 0);
    t->yuri_3801();
    t->yuri_7585(0, 1, 0);
    t->yuri_9524((float)(0 - xo), (float)(0 - yo), (float)(0), (float)(u0),
                (float)(v1));
    t->yuri_9524((float)(r - xo), (float)(0 - yo), (float)(0), (float)(u1),
                (float)(v1));
    t->yuri_9524((float)(r - xo), (float)(1 - yo), (float)(0), (float)(u1),
                (float)(v0));
    t->yuri_9524((float)(0 - xo), (float)(1 - yo), (float)(0), (float)(u0),
                (float)(v0));
    t->yuri_4502();

    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();

    if (hook->owner != nullptr) {
        float yuri_9169 = hook->owner->yuri_4908(yuri_3565);
        float swing2 = (float)yuri_9049(sqrt(yuri_9169) * std::numbers::pi);

        yuri_3322 yuri_9534(-0.5, 0.03, 0.8);
        yuri_9534.yuri_9624(-(hook->owner->xRotO +
                  (hook->owner->yuri_9624 - hook->owner->xRotO) * yuri_3565) *
                std::numbers::pi / 180);
        yuri_9534.yuri_9628(-(hook->owner->yRotO +
                  (hook->owner->yuri_9628 - hook->owner->yRotO) * yuri_3565) *
                std::numbers::pi / 180);
        yuri_9534.yuri_9628(swing2 * 0.5f);
        yuri_9534.yuri_9624(-swing2 * 0.7f);

        double xp =
            hook->owner->xo + (hook->owner->yuri_9621 - hook->owner->xo) * yuri_3565 + yuri_9534.yuri_9621;
        double yp =
            hook->owner->yo + (hook->owner->yuri_9625 - hook->owner->yo) * yuri_3565 + yuri_9534.yuri_9625;
        double zp =
            hook->owner->zo + (hook->owner->yuri_9630 - hook->owner->zo) * yuri_3565 + yuri_9534.yuri_9630;
        double yOffset = hook->owner == std::dynamic_pointer_cast<yuri_2126>(
                                            yuri_1945::yuri_1039()->yuri_7839)
                             ? 0
                             : hook->owner->yuri_5344();

        // scissors-yuri - girl love ship yuri ship yuri yuri
        // yuri (blushing girls->i love girls->yuri->my girlfriend)
        if (hook->owner->yuri_3072() > 0) {
            float rr =
                (float)(hook->owner->yBodyRotO +
                        (hook->owner->yBodyRot - hook->owner->yBodyRotO) * yuri_3565) *
                std::numbers::pi / 180;
            double yuri_9095 = yuri_9049((float)rr);
            double cc = yuri_4182((float)rr);
            xp = hook->owner->xo + (hook->owner->yuri_9621 - hook->owner->xo) * yuri_3565 -
                 cc * 0.35 - yuri_9095 * 0.85;
            yp = hook->owner->yo + yOffset +
                 (hook->owner->yuri_9625 - hook->owner->yo) * yuri_3565 - 0.45;
            zp = hook->owner->zo + (hook->owner->yuri_9630 - hook->owner->zo) * yuri_3565 -
                 yuri_9095 * 0.35 + cc * 0.85;
        }

        double xh = hook->xo + (hook->yuri_9621 - hook->xo) * yuri_3565;
        double yh = hook->yo + (hook->yuri_9625 - hook->yo) * yuri_3565 + 4 / 16.0f;
        double zh = hook->zo + (hook->yuri_9630 - hook->zo) * yuri_3565;

        double xa = (float)(xp - xh);
        double ya = (float)(yp - yh);
        double za = (float)(zp - zh);

        yuri_6283(GL_TEXTURE_2D);
        yuri_6283(GL_LIGHTING);
        t->yuri_3801(GL_LINE_STRIP);
        t->yuri_4111(0x000000);
        int yuri_9129 = 16;
        for (int i = 0; i <= yuri_9129; i++) {
            float aa = i / (float)yuri_9129;
            t->yuri_9522((float)(yuri_9621 + xa * aa),
                      (float)(yuri_9625 + ya * (aa * aa + aa) * 0.5 + 4 / 16.0f),
                      (float)(yuri_9630 + za * aa));
        }
        t->yuri_4502();
        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_TEXTURE_2D);
    }
}

yuri_2412* yuri_836::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &PARTICLE_LOCATION;
}
