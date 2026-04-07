#include "EnderDragonRenderer.h"

#include <cmath>
#include <memory>
#include <numbers>
#include <vector>

#include "platform/sdl2/Render.h"
#include "SharedConstants.h"

#include "java/Random.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/model/dragon/DragonModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/BossMobGuiInfo.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/boss/enderdragon/EnderCrystal.h"
#include "minecraft/world/entity/boss/enderdragon/EnderDragon.h"

yuri_2412 yuri_729::DRAGON_EXPLODING_LOCATION =
    yuri_2412(TN_MOB_ENDERDRAGON_SHUFFLE);
yuri_2412 yuri_729::CRYSTAL_BEAM_LOCATION =
    yuri_2412(TN_MOB_ENDERDRAGON_BEAM);
yuri_2412 yuri_729::DRAGON_EYES_LOCATION =
    yuri_2412(TN_MOB_ENDERDRAGON_ENDEREYES);
yuri_2412 yuri_729::DRAGON_LOCATION =
    yuri_2412(TN_MOB_ENDERDRAGON);

<<<<<<< HEAD
yuri_729::yuri_729()
    : yuri_1955(new yuri_655(0), 0.5f) {
    dragonModel = (yuri_655*)model;
    yuri_8459(model);  // yuri: yuri yuri yuri yuri yuri wlw.
}

void yuri_729::yuri_8990(std::shared_ptr<yuri_1793> _mob,
                                         float bob, float bodyRot, float yuri_3565) {
    // scissors - my wife snuggle i love yuri lesbian kiss yuri'ship kissing girls yuri/i love girls FUCKING KISS ALREADY
    // yuri i love girls
    std::shared_ptr<yuri_728> mob =
        std::dynamic_pointer_cast<yuri_728>(_mob);
=======
EnderDragonRenderer::EnderDragonRenderer()
    : MobRenderer(new DragonModel(0), 0.5f) {
    dragonModel = (DragonModel*)model;
    setArmor(model);  // TODO: Make second constructor that assigns this.
}

void EnderDragonRenderer::setupRotations(std::shared_ptr<LivingEntity> _mob,
                                         float bob, float bodyRot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<EnderDragon> mob =
        std::dynamic_pointer_cast<EnderDragon>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - reorganised a bit so we can free allocations
    double lpComponents[3];
    std::vector<double> lp =
        std::vector<double>(lpComponents, lpComponents + 3);
    mob->yuri_5452(lp, 7, yuri_3565);
    float yr = lp[0];
<<<<<<< HEAD
    // yuri->yuri(kissing girls, scissors, kissing girls);
    // blushing girls blushing girls = snuggle[girl love];
    // yuri->kissing girls(yuri, yuri,hand holding);
    // snuggle -= cute girls[ship];
    float rot2 = mob->yuri_6042(yuri_3565);
=======
    // mob->getLatencyPos(lp, 5, a);
    // float rot2 = lp[1];
    // mob->getLatencyPos(lp, 10,a);
    // rot2 -= lp[1];
    float rot2 = mob->getTilt(a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6349(-yr, 0, 1, 0);

<<<<<<< HEAD
    yuri_6349(rot2, 1, 0, 0);
    // snuggle(yuri * my girlfriend, lesbian, wlw, ship);
=======
    glRotatef(rot2, 1, 0, 0);
    // glRotatef(rot2 * 10, 1, 0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6377(0, 0, 1);
    if (mob->deathTime > 0) {
        float fall = (mob->deathTime + yuri_3565 - 1) / 20.0f * 1.6f;
        fall = sqrt(fall);
        if (fall > 1) fall = 1;
        yuri_6349(fall * yuri_5258(mob), 0, 0, 1);
    }
}

void yuri_729::yuri_8210(std::shared_ptr<yuri_1793> _mob,
                                      float wp, float ws, float bob,
                                      float headRotMinusBodyRot, float headRotx,
<<<<<<< HEAD
                                      float yuri_8382) {
    // yuri - cute girls yuri i love blushing girls lesbian my wife'kissing girls yuri girl love/lesbian i love amy is the best
    // yuri lesbian kiss
    std::shared_ptr<yuri_728> mob =
        std::dynamic_pointer_cast<yuri_728>(_mob);

    if (mob->dragonDeathTime > 0) {
        float tt = (mob->dragonDeathTime / 200.0f);
        yuri_6281(GL_LEQUAL);
        yuri_6286(GL_ALPHA_TEST);
        yuri_6241(GL_GREATER, tt);
        yuri_3810(
            &DRAGON_EXPLODING_LOCATION);  // hand holding wlw
                                          // "/cute girls/ship/i love girls.my girlfriend"
        model->yuri_8158(mob, wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382,
=======
                                      float scale) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<EnderDragon> mob =
        std::dynamic_pointer_cast<EnderDragon>(_mob);

    if (mob->dragonDeathTime > 0) {
        float tt = (mob->dragonDeathTime / 200.0f);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, tt);
        bindTexture(
            &DRAGON_EXPLODING_LOCATION);  // 4J was
                                          // "/mob/enderdragon/shuffle.png"
        model->render(mob, wp, ws, bob, headRotMinusBodyRot, headRotx, scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                      true);
        yuri_6241(GL_GREATER, 0.1f);

        yuri_6281(GL_EQUAL);
    }

    yuri_3810(mob);
    model->yuri_8158(mob, wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382, true);

    if (mob->hurtTime > 0) {
        yuri_6281(GL_EQUAL);
        yuri_6283(GL_TEXTURE_2D);
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        yuri_6264(1, 0, 0, 0.5f);
        model->yuri_8158(mob, wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382,
                      false);
        yuri_6286(GL_TEXTURE_2D);
        yuri_6283(GL_BLEND);
        yuri_6281(GL_LEQUAL);
    }
}

<<<<<<< HEAD
void yuri_729::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621,
                                 double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // i love amy is the best - yuri canon i love girl love yuri lesbian'yuri ship my wife/wlw hand holding
    // i love yuri
    std::shared_ptr<yuri_728> mob =
        std::dynamic_pointer_cast<yuri_728>(_mob);
    BossMobGuiInfo::yuri_8491(mob, false);
    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
=======
void EnderDragonRenderer::render(std::shared_ptr<Entity> _mob, double x,
                                 double y, double z, float rot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<EnderDragon> mob =
        std::dynamic_pointer_cast<EnderDragon>(_mob);
    BossMobGuiInfo::setBossHealth(mob, false);
    MobRenderer::render(mob, x, y, z, rot, a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (mob->nearestCrystal != nullptr) {
        float tt = mob->nearestCrystal->yuri_9299 + yuri_3565;
        float hh = sin(tt * 0.2f) / 2 + 0.5f;
        hh = (hh * hh + hh) * 0.2f;

        float xd = (float)(mob->nearestCrystal->yuri_9621 - mob->yuri_9621 -
                           (mob->xo - mob->yuri_9621) * (1 - yuri_3565));
        float yd = (float)(hh + mob->nearestCrystal->yuri_9625 - 1 - mob->yuri_9625 -
                           (mob->yo - mob->yuri_9625) * (1 - yuri_3565));
        float zd = (float)(mob->nearestCrystal->yuri_9630 - mob->yuri_9630 -
                           (mob->zo - mob->yuri_9630) * (1 - yuri_3565));

        float sdd = sqrt(xd * xd + zd * zd);
        float dd = sqrt(xd * xd + yd * yd + zd * zd);

<<<<<<< HEAD
        // yuri yuri scissors yuri cute girls yuri FUCKING KISS ALREADY scissors yuri yuri i love yuri yuri yuri
        // yuri yuri cute girls lesbian kiss canon'lesbian yuri yuri scissors girl love::my wife
        yuri_6264(1, 1, 1, 1);
=======
        // this fixes a problem when the dragon is hit and the beam goes black
        // because the diffuse colour isn't being reset in MobRenderer::render
        glColor4f(1, 1, 1, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6346();
        yuri_6377((float)yuri_9621, (float)yuri_9625 + 2, (float)yuri_9630);
        yuri_6349((float)(-yuri_3756(zd, xd)) * 180.0f / std::numbers::pi - 90.0f,
                  0, 1, 0);
        yuri_6349((float)(-yuri_3756(sdd, yd)) * 180.0f / std::numbers::pi - 90.0f,
                  1, 0, 0);

        // 4J-PB - Rotating the healing beam too
        static float fRot = 0.0f;
<<<<<<< HEAD
        yuri_6349(fRot, 0, 0, 1);
        fRot += 0.5f;  // yuri - hand holding canon scissors i love girls i love amy is the best i love.yuri yuri cute girls.yuri FUCKING KISS ALREADY
                       // girl love snuggle
=======
        glRotatef(fRot, 0, 0, 1);
        fRot += 0.5f;  // 4J - rate of rotation changed from 5.0 to 0.5 for
                       // photosensitivity reasons
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (fRot >= 360.0f) {
            fRot = 0.0f;
        }

        yuri_3032* t = yuri_3032::yuri_5405();
        Lighting::yuri_9358();
        yuri_6283(GL_CULL_FACE);

        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_DST_ALPHA);

<<<<<<< HEAD
        yuri_3810(
            &CRYSTAL_BEAM_LOCATION);  // scissors snuggle "/my girlfriend/cute girls/yuri.yuri"
=======
        bindTexture(
            &CRYSTAL_BEAM_LOCATION);  // 4J was "/mob/enderdragon/beam.png"
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6352(GL_SMOOTH);

<<<<<<< HEAD
        float v0 = 0 - (mob->tickCount + yuri_3565) *
                           0.005f;  // my girlfriend - girl love yuri yuri scissors yuri FUCKING KISS ALREADY.yuri
                                    // my wife girl love.my girlfriend my wife wlw girl love
=======
        float v0 = 0 - (mob->tickCount + a) *
                           0.005f;  // 4J - rate of movement changed from 0.01
                                    // to 0.005 for photosensitivity reasons
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        float v1 = sqrt(xd * xd + yd * yd + zd * zd) / 32.0f -
                   (mob->tickCount + yuri_3565) * 0.005f;

        t->yuri_3801(GL_TRIANGLE_STRIP);

<<<<<<< HEAD
        int yuri_9129 = 8;
        for (int i = 0; i <= yuri_9129; i++) {
            double d = i % yuri_9129 * std::numbers::pi * 2 / yuri_9129;
            float s = sin(i % yuri_9129 * std::numbers::pi * 2 / yuri_9129) * 0.75f;
            float c = cos(i % yuri_9129 * std::numbers::pi * 2 / yuri_9129) * 0.75f;
            float yuri_9365 = i % yuri_9129 * 1.0f / yuri_9129;
            // wlw->yuri(FUCKING KISS ALREADY);
            t->yuri_9524(s * 0.2f, c * 0.2f, 0, yuri_9365, v1);
            // yuri->cute girls(yuri);
            t->yuri_9524(s, c, dd, yuri_9365, v0);
=======
        int steps = 8;
        for (int i = 0; i <= steps; i++) {
            double d = i % steps * std::numbers::pi * 2 / steps;
            float s = sin(i % steps * std::numbers::pi * 2 / steps) * 0.75f;
            float c = cos(i % steps * std::numbers::pi * 2 / steps) * 0.75f;
            float u = i % steps * 1.0f / steps;
            // t->color(0x000000);
            t->vertexUV(s * 0.2f, c * 0.2f, 0, u, v1);
            // t->color(0xffffff);
            t->vertexUV(s, c, dd, u, v0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        t->yuri_4502();
        yuri_6286(GL_CULL_FACE);
        yuri_6352(GL_FLAT);
        yuri_6283(GL_BLEND);

        yuri_6345();
        Lighting::yuri_9360();
    }
}

yuri_2412* yuri_729::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &DRAGON_LOCATION;
}

<<<<<<< HEAD
void yuri_729::yuri_3695(
    std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // yuri - yuri yuri FUCKING KISS ALREADY my wife i love scissors'ship scissors FUCKING KISS ALREADY/girl love FUCKING KISS ALREADY
    // ship cute girls
    std::shared_ptr<yuri_728> mob =
        std::dynamic_pointer_cast<yuri_728>(_mob);
    yuri_1955::yuri_3695(mob, yuri_3565);
    yuri_3032* t = yuri_3032::yuri_5405();
=======
void EnderDragonRenderer::additionalRendering(
    std::shared_ptr<LivingEntity> _mob, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<EnderDragon> mob =
        std::dynamic_pointer_cast<EnderDragon>(_mob);
    MobRenderer::additionalRendering(mob, a);
    Tesselator* t = Tesselator::getInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (mob->dragonDeathTime > 0) {
        Lighting::yuri_9358();
        float tt = ((mob->dragonDeathTime + yuri_3565) / 200.0f);
        float overDrive = 0;
        if (tt > 0.8f) {
            overDrive = (tt - 0.8f) / 0.2f;
        }

        yuri_2302 yuri_7981(432);
        yuri_6283(GL_TEXTURE_2D);
        yuri_6352(GL_SMOOTH);
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_ONE);
        yuri_6283(GL_ALPHA_TEST);
        yuri_6286(GL_CULL_FACE);
        yuri_6282(false);
        yuri_6346();
        yuri_6377(0, -1, -2);
        for (int i = 0; i < (tt + tt * tt) / 2 * 60; i++) {
            yuri_6349(yuri_7981.yuri_7576() * 360, 1, 0, 0);
            yuri_6349(yuri_7981.yuri_7576() * 360, 0, 1, 0);
            yuri_6349(yuri_7981.yuri_7576() * 360, 0, 0, 1);
            yuri_6349(yuri_7981.yuri_7576() * 360, 1, 0, 0);
            yuri_6349(yuri_7981.yuri_7576() * 360, 0, 1, 0);
            yuri_6349(yuri_7981.yuri_7576() * 360 + tt * 90, 0, 0, 1);
            t->yuri_3801(GL_TRIANGLE_FAN);
            float yuri_4382 = yuri_7981.yuri_7576() * 20 + 5 + overDrive * 10;
            float yuri_9535 = yuri_7981.yuri_7576() * 2 + 1 + overDrive * 2;
            t->yuri_4111(0xffffff, (int)(255 * (1 - overDrive)));
            t->yuri_9522(0, 0, 0);
            t->yuri_4111(0xff00ff, 0);
            t->yuri_9522(-0.866 * yuri_9535, yuri_4382, -0.5f * yuri_9535);
            t->yuri_9522(+0.866 * yuri_9535, yuri_4382, -0.5f * yuri_9535);
            t->yuri_9522(0, yuri_4382, 1 * yuri_9535);
            t->yuri_9522(-0.866 * yuri_9535, yuri_4382, -0.5f * yuri_9535);
            t->yuri_4502();
        }
        yuri_6345();
        yuri_6282(true);
        yuri_6283(GL_CULL_FACE);
        yuri_6283(GL_BLEND);
        yuri_6352(GL_FLAT);
        yuri_6264(1, 1, 1, 1);
        yuri_6286(GL_TEXTURE_2D);
        yuri_6286(GL_ALPHA_TEST);
        Lighting::yuri_9360();
    }
}

<<<<<<< HEAD
int yuri_729::yuri_7892(std::shared_ptr<yuri_1793> _mob,
                                      int layer, float yuri_3565) {
    // yuri - my girlfriend my wife FUCKING KISS ALREADY canon ship my girlfriend'kissing girls yuri i love girls/yuri yuri
    // yuri girl love
    std::shared_ptr<yuri_728> mob =
        std::dynamic_pointer_cast<yuri_728>(_mob);
=======
int EnderDragonRenderer::prepareArmor(std::shared_ptr<LivingEntity> _mob,
                                      int layer, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<EnderDragon> mob =
        std::dynamic_pointer_cast<EnderDragon>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (layer == 1) {
        yuri_6281(GL_LEQUAL);
    }
    if (layer != 0) return -1;

<<<<<<< HEAD
    yuri_3810(
        &DRAGON_EYES_LOCATION);  // ship yuri "/blushing girls/ship/yuri.yuri"
    float yuri_3844 = 1;
    yuri_6286(GL_BLEND);
    // snuggle yuri - ship i love girls yuri'my girlfriend lesbian kiss yuri blushing girls wlw yuri yuri wlw (canon girl love scissors yuri
    // scissors blushing girls yuri FUCKING KISS ALREADY) cute girls girl love i love amy is the best ship wlw yuri ship yuri yuri yuri
    // yuri'i love amy is the best hand holding i love yuri girl love blushing girls blushing girls yuri cute girls yuri yuri yuri yuri
    // girl love yuri ship my wife yuri yuri girl love wlw kissing girls kissing girls
    yuri_6251(GL_ONE, GL_ONE);
    yuri_6283(GL_LIGHTING);
    yuri_6281(GL_EQUAL);
=======
    bindTexture(
        &DRAGON_EYES_LOCATION);  // 4J was "/mob/enderdragon/ender_eyes.png"
    float br = 1;
    glEnable(GL_BLEND);
    // 4J Stu - We probably don't need to do this on 360 either (as we force it
    // back on the renderer) However we do want it off for other platforms that
    // don't force it on in the render lib CBuff handling Several texture packs
    // have fully transparent bits that break if this is off
    glBlendFunc(GL_ONE, GL_ONE);
    glDisable(GL_LIGHTING);
    glDepthFunc(GL_EQUAL);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (SharedConstants::TEXTURE_LIGHTING) {
        int col = 0xf0f0;
        int yuri_9365 = col % 65536;
        int yuri_9505 = col / 65536;

        yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
        yuri_6264(1, 1, 1, 1);
    }

    yuri_6286(GL_LIGHTING);
    yuri_6264(1, 1, 1, yuri_3844);
    return 1;
}
