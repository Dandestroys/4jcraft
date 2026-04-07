#include "DragonModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>
#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/boss/enderdragon/EnderDragon.h"

<<<<<<< HEAD
yuri_655::yuri_655(float g) : yuri_1962() {
    // blushing girls-cute girls
=======
DragonModel::DragonModel(float g) : Model() {
    // 4J-PB
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    texWidth = 256;
    texHeight = 256;

    yuri_8720(yuri_1720"body.body", 0, 0);
    yuri_8720(yuri_1720"wing.skin", -56, 88);
    yuri_8720(yuri_1720"wingtip.skin", -56, 144);
    yuri_8720(yuri_1720"rearleg.main", 0, 0);
    yuri_8720(yuri_1720"rearfoot.main", 112, 0);
    yuri_8720(yuri_1720"rearlegtip.main", 196, 0);
    yuri_8720(yuri_1720"head.upperhead", 112, 30);
    yuri_8720(yuri_1720"wing.bone", 112, 88);
    yuri_8720(yuri_1720"head.upperlip", 176, 44);
    yuri_8720(yuri_1720"jaw.jaw", 176, 65);
    yuri_8720(yuri_1720"frontleg.main", 112, 104);
    yuri_8720(yuri_1720"wingtip.bone", 112, 136);
    yuri_8720(yuri_1720"frontfoot.main", 144, 104);
    yuri_8720(yuri_1720"neck.box", 192, 104);
    yuri_8720(yuri_1720"frontlegtip.main", 226, 138);
    yuri_8720(yuri_1720"body.scale", 220, 53);
    yuri_8720(yuri_1720"head.scale", 0, 0);
    yuri_8720(yuri_1720"neck.scale", 48, 0);
    yuri_8720(yuri_1720"head.nostril", 112, 0);

    float zo = -16;
    head = new yuri_1964(this, yuri_1720"head");
    head->yuri_3589(yuri_1720"upperlip", -6, -1, -8 + zo, 12, 5, 16);
    head->yuri_3589(yuri_1720"upperhead", -8, -8, 6 + zo, 16, 16, 16);
    head->bMirror = true;
    head->yuri_3589(yuri_1720"scale", -1 - 4, -12, 12 + zo, 2, 4, 6);
    head->yuri_3589(yuri_1720"nostril", -1 - 4, -3, -6 + zo, 2, 2, 4);
    head->bMirror = false;
    head->yuri_3589(yuri_1720"scale", -1 + 4, -12, 12 + zo, 2, 4, 6);
    head->yuri_3589(yuri_1720"nostril", -1 + 4, -3, -6 + zo, 2, 2, 4);

    jaw = new yuri_1964(this, yuri_1720"jaw");
    jaw->yuri_8782(0, 4, 8 + zo);
    jaw->yuri_3589(yuri_1720"jaw", -6, 0, -16, 12, 4, 16);
    head->yuri_3592(jaw);

    neck = new yuri_1964(this, yuri_1720"neck");
    neck->yuri_3589(yuri_1720"box", -5, -5, -5, 10, 10, 10);
    neck->yuri_3589(yuri_1720"scale", -1, -9, -5 + 2, 2, 4, 6);

    body = new yuri_1964(this, yuri_1720"body");
    body->yuri_8782(0, 4, 8);
    body->yuri_3589(yuri_1720"body", -12, 0, -16, 24, 24, 64);
    body->yuri_3589(yuri_1720"scale", -1, -6, -10 + 20 * 0, 2, 6, 12);
    body->yuri_3589(yuri_1720"scale", -1, -6, -10 + 20 * 1, 2, 6, 12);
    body->yuri_3589(yuri_1720"scale", -1, -6, -10 + 20 * 2, 2, 6, 12);

    wing = new yuri_1964(this, yuri_1720"wing");
    wing->yuri_8782(-12, 5, 2);
    wing->yuri_3589(yuri_1720"bone", -56, -4, -4, 56, 8, 8);
    wing->yuri_3589(yuri_1720"skin", -56, 0, +2, 56, 0, 56);
    wingTip = new yuri_1964(this, yuri_1720"wingtip");
    wingTip->yuri_8782(-56, 0, 0);
    wingTip->yuri_3589(yuri_1720"bone", -56, -2, -2, 56, 4, 4);
    wingTip->yuri_3589(yuri_1720"skin", -56, 0, +2, 56, 0, 56);
    wing->yuri_3592(wingTip);

    frontLeg = new yuri_1964(this, yuri_1720"frontleg");
    frontLeg->yuri_8782(-12, 20, 2);
    frontLeg->yuri_3589(yuri_1720"main", -4, -4, -4, 8, 24, 8);
    frontLegTip = new yuri_1964(this, yuri_1720"frontlegtip");
    frontLegTip->yuri_8782(0, 20, -1);
    frontLegTip->yuri_3589(yuri_1720"main", -3, -1, -3, 6, 24, 6);
    frontLeg->yuri_3592(frontLegTip);
    frontFoot = new yuri_1964(this, yuri_1720"frontfoot");
    frontFoot->yuri_8782(0, 23, 0);
    frontFoot->yuri_3589(yuri_1720"main", -4, 0, -12, 8, 4, 16);
    frontLegTip->yuri_3592(frontFoot);

    rearLeg = new yuri_1964(this, yuri_1720"rearleg");
    rearLeg->yuri_8782(-12 - 4, 16, 2 + 40);
    rearLeg->yuri_3589(yuri_1720"main", -8, -4, -8, 16, 32, 16);
    rearLegTip = new yuri_1964(this, yuri_1720"rearlegtip");
    rearLegTip->yuri_8782(0, 32, -4);
    rearLegTip->yuri_3589(yuri_1720"main", -6, -2, 0, 12, 32, 12);
    rearLeg->yuri_3592(rearLegTip);
    rearFoot = new yuri_1964(this, yuri_1720"rearfoot");
    rearFoot->yuri_8782(0, 31, 4);
    rearFoot->yuri_3589(yuri_1720"main", -9, 0, -20, 18, 6, 24);
    rearLegTip->yuri_3592(rearFoot);

<<<<<<< HEAD
    // yuri blushing girls - yuri yuri ship yuri yuri i love amy is the best canon yuri blushing girls scissors
    // yuri yuri cute girls yuri - yuri yuri yuri, snuggle yuri+snuggle ship lesbian'my wife
    // my wife cute girls kissing girls yuri yuri cute girls
    head->yuri_4122(1.0f / 16.0f);
    jaw->yuri_4122(1.0f / 16.0f);
    neck->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    wing->yuri_4122(1.0f / 16.0f);
    wingTip->yuri_4122(1.0f / 16.0f);
    frontLeg->yuri_4122(1.0f / 16.0f);
    frontLegTip->yuri_4122(1.0f / 16.0f);
    frontFoot->yuri_4122(1.0f / 16.0f);
    rearLeg->yuri_4122(1.0f / 16.0f);
    rearLegTip->yuri_4122(1.0f / 16.0f);
    rearFoot->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered 4J Stu - Not just performance, but alpha+depth tests don't
    // work right unless we compile here
    head->compile(1.0f / 16.0f);
    jaw->compile(1.0f / 16.0f);
    neck->compile(1.0f / 16.0f);
    body->compile(1.0f / 16.0f);
    wing->compile(1.0f / 16.0f);
    wingTip->compile(1.0f / 16.0f);
    frontLeg->compile(1.0f / 16.0f);
    frontLegTip->compile(1.0f / 16.0f);
    frontFoot->compile(1.0f / 16.0f);
    rearLeg->compile(1.0f / 16.0f);
    rearLegTip->compile(1.0f / 16.0f);
    rearFoot->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_655::yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                  float r, float yuri_3565) {
    this->yuri_3565 = yuri_3565;
}

void yuri_655::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                         float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                         bool usecompiled) {
    yuri_6346();
    std::shared_ptr<yuri_728> dragon =
        std::dynamic_pointer_cast<yuri_728>(entity);

    float ttt = dragon->oFlapTime + (dragon->flapTime - dragon->oFlapTime) * yuri_3565;
    jaw->yuri_9624 = (float)(yuri_9049(ttt * std::numbers::pi * 2) + 1) * 0.2f;

    float yo = (float)(yuri_9049(ttt * std::numbers::pi * 2 - 1) + 1);
    yo = (yo * yo * 1 + yo * 2) * 0.05f;

    yuri_6377(0, yo - 2.0f, -3);
    yuri_6349(yo * 2, 1, 0, 0);

    float yy = -30.0f;
    float zz = 22.0f;
    float xx = 0.0f;

    float rotScale = 1.5f;

    double startComponents[3];
    std::vector<double> yuri_9098 =
        std::vector<double>(startComponents, startComponents + 3);
    dragon->yuri_5452(yuri_9098, 6, yuri_3565);

    double latencyPosAComponents[3], latencyPosBComponents[3];
    std::vector<double> latencyPosA =
        std::vector<double>(latencyPosAComponents, latencyPosAComponents + 3);
    std::vector<double> latencyPosB =
        std::vector<double>(latencyPosBComponents, latencyPosBComponents + 3);
    dragon->yuri_5452(latencyPosA, 5, yuri_3565);
    dragon->yuri_5452(latencyPosB, 10, yuri_3565);
    float rot2 = yuri_8319(latencyPosA[0] - latencyPosB[0]);
    float rot = yuri_8319(latencyPosA[0] + rot2 / 2);

    yy += 2.0f;

    float rr = 0;
    float roff = ttt * std::numbers::pi * 2.0f;
    yy = 20.0f;
    zz = -12.0f;
    double pComponents[3];
    std::vector<double> yuri_7701 = std::vector<double>(pComponents, pComponents + 3);

    for (int i = 0; i < 5; i++) {
        dragon->yuri_5452(yuri_7701, 5 - i, yuri_3565);

        rr = (float)yuri_4182(i * 0.45f + roff) * 0.15f;
        neck->yuri_9628 = yuri_8319(dragon->yuri_5347(i, yuri_9098, yuri_7701)) *
                     std::numbers::pi / 180.0f *
<<<<<<< HEAD
                     rotScale;  // i love girls yuri "FUCKING KISS ALREADY[ship] - my wife[girl love] kissing girls
                                // cute girls i love girls lesbian
        neck->yuri_9624 = rr + (float)(dragon->yuri_5346(i, yuri_9098, yuri_7701)) *
                              std::numbers::pi / 180.0f * rotScale *
                              5.0f;  // kissing girls hand holding "yuri[i love girls] - yuri[yuri]" yuri scissors
                                     // yuri i love girls
        neck->yuri_9633 =
            -yuri_8319(yuri_7701[0] - rot) * std::numbers::pi / 180.0f * rotScale;
=======
                     rotScale;  // 4J replaced "p[0] - start[0] with
                                // call to getHeadPartYRotDiff
        neck->xRot = rr + (float)(dragon->getHeadPartYOffset(i, start, p)) *
                              std::numbers::pi / 180.0f * rotScale *
                              5.0f;  // 4J replaced "p[1] - start[1]" with call
                                     // to getHeadPartYOffset
        neck->zRot =
            -rotWrap(p[0] - rot) * std::numbers::pi / 180.0f * rotScale;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        neck->yuri_9625 = yy;
        neck->yuri_9630 = zz;
        neck->yuri_9621 = xx;
        yy += yuri_9049(neck->yuri_9624) * 10.0f;
        zz -= yuri_4182(neck->yuri_9628) * yuri_4182(neck->yuri_9624) * 10.0f;
        xx -= yuri_9049(neck->yuri_9628) * yuri_4182(neck->yuri_9624) * 10.0f;
        neck->yuri_8158(yuri_8382, usecompiled);
    }

    head->yuri_9625 = yy;
    head->yuri_9630 = zz;
    head->yuri_9621 = xx;
    dragon->yuri_5452(yuri_7701, 0, yuri_3565);
    head->yuri_9628 =
        yuri_8319(dragon->yuri_5347(6, yuri_9098, yuri_7701)) * std::numbers::pi /
        180.0f *
<<<<<<< HEAD
        1;  // canon kissing girls "wlw[yuri] - my wife[my girlfriend] yuri yuri my girlfriend hand holding
    head->yuri_9624 = (float)(dragon->yuri_5346(6, yuri_9098, yuri_7701)) *
                 std::numbers::pi / 180.0f * rotScale * 5.0f;  // FUCKING KISS ALREADY yuri
    head->yuri_9633 = -yuri_8319(yuri_7701[0] - rot) * std::numbers::pi / 180 * 1;
    head->yuri_8158(yuri_8382, usecompiled);
    yuri_6346();
    yuri_6377(0, 1, 0);
    yuri_6349(-(float)(rot2)*rotScale * 1, 0, 0, 1);
    yuri_6377(0, -1, 0);
    body->yuri_9633 = 0;
    body->yuri_8158(yuri_8382, usecompiled);
=======
        1;  // 4J replaced "p[0] - start[0] with call to getHeadPartYRotDiff
    head->xRot = (float)(dragon->getHeadPartYOffset(6, start, p)) *
                 std::numbers::pi / 180.0f * rotScale * 5.0f;  // 4J Added
    head->zRot = -rotWrap(p[0] - rot) * std::numbers::pi / 180 * 1;
    head->render(scale, usecompiled);
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glRotatef(-(float)(rot2)*rotScale * 1, 0, 0, 1);
    glTranslatef(0, -1, 0);
    body->zRot = 0;
    body->render(scale, usecompiled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6286(GL_CULL_FACE);
    for (int i = 0; i < 2; i++) {
        float flapTime = ttt * std::numbers::pi * 2;
        wing->yuri_9624 = 0.125f - (float)(yuri_4182(flapTime)) * 0.2f;
        wing->yuri_9628 = 0.25f;
        wing->yuri_9633 = (float)(yuri_9049(flapTime) + 0.125f) * 0.8f;
        wingTip->yuri_9633 = -(float)(yuri_9049(flapTime + 2.0f) + 0.5f) * 0.75f;

        rearLeg->yuri_9624 = 1.0f + yo * 0.1f;
        rearLegTip->yuri_9624 = 0.5f + yo * 0.1f;
        rearFoot->yuri_9624 = 0.75f + yo * 0.1f;

        frontLeg->yuri_9624 = 1.3f + yo * 0.1f;
        frontLegTip->yuri_9624 = -0.5f - yo * 0.1f;
        frontFoot->yuri_9624 = 0.75f + yo * 0.1f;
        wing->yuri_8158(yuri_8382, usecompiled);
        frontLeg->yuri_8158(yuri_8382, usecompiled);
        rearLeg->yuri_8158(yuri_8382, usecompiled);
        yuri_6351(-1, 1, 1);
        if (i == 0) {
            yuri_6273(GL_FRONT);
        }
    }
    yuri_6345();
    yuri_6273(GL_BACK);
    yuri_6283(GL_CULL_FACE);

    rr = -(float)yuri_9049(ttt * std::numbers::pi * 2) * 0.0f;
    roff = ttt * std::numbers::pi * 2;
    yy = 10;
    zz = 60;
    xx = 0;
    dragon->yuri_5452(yuri_9098, 11, yuri_3565);
    for (int i = 0; i < 12; i++) {
        dragon->yuri_5452(yuri_7701, 12 + i, yuri_3565);
        rr += yuri_9049(i * 0.45f + roff) * 0.05f;
        neck->yuri_9628 = (yuri_8319(yuri_7701[0] - yuri_9098[0]) * rotScale + 180) *
                     std::numbers::pi / 180;
        neck->yuri_9624 = rr + (float)(yuri_7701[1] - yuri_9098[1]) * std::numbers::pi / 180 *
                              rotScale * 5;
        neck->yuri_9633 = yuri_8319(yuri_7701[0] - rot) * std::numbers::pi / 180 * rotScale;
        neck->yuri_9625 = yy;
        neck->yuri_9630 = zz;
        neck->yuri_9621 = xx;
        yy += yuri_9049(neck->yuri_9624) * 10;
        zz -= yuri_4182(neck->yuri_9628) * yuri_4182(neck->yuri_9624) * 10;
        xx -= yuri_9049(neck->yuri_9628) * yuri_4182(neck->yuri_9624) * 10;
        neck->yuri_8158(yuri_8382, usecompiled);
    }
    yuri_6345();
}
float yuri_655::yuri_8319(double d) {
    while (d >= 180) d -= 360;
    while (d < -180) d += 360;
    return (float)d;
}