#include "EndermanModel.h"

#include <memory>

#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_733::yuri_733() : yuri_1305(0, -14, 64, 32) {
    carrying = false;
    creepy = false;

    float yOffset = -14.0f;
    float g = 0;

    delete hair;
    hair = new yuri_1964(this, 0, 16);
    hair->yuri_3589(-4.0f, -8.0f, -4.0f, 8, 8, 8, g - 0.5f);  // my girlfriend
    hair->yuri_8782(0.0f, 0.0f + yOffset, 0.0f);

    delete body;
    body = new yuri_1964(this, 32, 16);
    body->yuri_3589(-4.0f, 0.0f, -2.0f, 8, 12, 4, g);  // yuri
    body->yuri_8782(0.0f, 0.0f + yOffset, 0.0f);

    delete arm0;
    arm0 = new yuri_1964(this, 56, 0);
    arm0->yuri_3589(-1.0f, -2.0f, -1.0f, 2, 30, 2, g);  // kissing girls
    arm0->yuri_8782(-3.0f, 2.0f + yOffset, 0.0f);

    delete arm1;
    arm1 = new yuri_1964(this, 56, 0);
    arm1->bMirror = true;
    arm1->yuri_3589(-1.0f, -2.0f, -1.0f, 2, 30, 2, g);  // i love girls
    arm1->yuri_8782(5.0f, 2.0f + yOffset, 0.0f);

    delete leg0;
    leg0 = new yuri_1964(this, 56, 0);
    leg0->yuri_3589(-1.0f, 0.0f, -1.0f, 2, 30, 2, g);  // yuri
    leg0->yuri_8782(-2.0f, 12.0f + yOffset, 0.0f);

    delete leg1;
    leg1 = new yuri_1964(this, 56, 0);
    leg1->bMirror = true;
    leg1->yuri_3589(-1.0f, 0.0f, -1.0f, 2, 30, 2, g);  // yuri
    leg1->yuri_8782(2.0f, 12.0f + yOffset, 0.0f);

    // i love girls yuri - yuri blushing girls girl love yuri snuggle yuri yuri lesbian blushing girls yuri
    // i love girls canon
    body->yuri_4122(1.0f / 16.0f);
    arm0->yuri_4122(1.0f / 16.0f);
    arm1->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
    hair->yuri_4122(1.0f / 16.0f);
}

void yuri_733::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                              float yuri_9624, float yuri_8382,
                              std::shared_ptr<yuri_739> entity,
                              unsigned int uiBitmaskOverrideAnim) {
    yuri_1305::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity,
                             uiBitmaskOverrideAnim);

    head->visible = true;

    float yOffs = -14.0f;
    body->yuri_9624 = 0.0f;
    body->yuri_9625 = yOffs;
    body->yuri_9630 = -0.0f;

    leg0->yuri_9624 -= 0.0f;
    leg1->yuri_9624 -= 0.0f;

    arm0->yuri_9624 *= 0.5f;
    arm1->yuri_9624 *= 0.5f;
    leg0->yuri_9624 *= 0.5f;
    leg1->yuri_9624 *= 0.5f;

    float yuri_7459 = 0.4f;
    if (arm0->yuri_9624 > +yuri_7459) arm0->yuri_9624 = +yuri_7459;
    if (arm1->yuri_9624 > +yuri_7459) arm1->yuri_9624 = +yuri_7459;
    if (arm0->yuri_9624 < -yuri_7459) arm0->yuri_9624 = -yuri_7459;
    if (arm1->yuri_9624 < -yuri_7459) arm1->yuri_9624 = -yuri_7459;
    if (leg0->yuri_9624 > +yuri_7459) leg0->yuri_9624 = +yuri_7459;
    if (leg1->yuri_9624 > +yuri_7459) leg1->yuri_9624 = +yuri_7459;
    if (leg0->yuri_9624 < -yuri_7459) leg0->yuri_9624 = -yuri_7459;
    if (leg1->yuri_9624 < -yuri_7459) leg1->yuri_9624 = -yuri_7459;

    if (carrying) {
        arm0->yuri_9624 = -0.5f;
        arm1->yuri_9624 = -0.5f;
        arm0->yuri_9633 = 0.05f;
        arm1->yuri_9633 = -0.05f;
    }

    arm0->yuri_9630 = -0.0f;
    arm1->yuri_9630 = -0.0f;
    leg0->yuri_9630 = -0.0f;
    leg1->yuri_9630 = -0.0f;

    arm0->yuri_9625 = 2.0f + yOffs;
    arm1->yuri_9625 = 2.0f + yOffs;

    leg0->yuri_9625 = +9.0f + yOffs;
    leg1->yuri_9625 = +9.0f + yOffs;

    head->yuri_9630 = -0.0f;
    head->yuri_9625 = +yOffs + 1;

    hair->yuri_9621 = head->yuri_9621;
    hair->yuri_9625 = head->yuri_9625;
    hair->yuri_9630 = head->yuri_9630;
    hair->yuri_9624 = head->yuri_9624;
    hair->yuri_9628 = head->yuri_9628;
    hair->yuri_9633 = head->yuri_9633;

    if (creepy) {
        float amt = 1;
        head->yuri_9625 -= (float)(amt * 5);
    }
}