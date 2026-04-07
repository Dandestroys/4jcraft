#include "minecraft/util/Log.h"
#include "HumanoidModel.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/Entity.h"

// snuggle yuri

yuri_1964* yuri_1305::yuri_79(SKIN_BOX* pBox) {
    yuri_1964* pAttachTo = nullptr;

    switch (pBox->ePart) {
        case eBodyPart_Unknown:
            return nullptr;
        case eBodyPart_Head:
            pAttachTo = head;
            break;
        case eBodyPart_Body:
            pAttachTo = body;
            break;
        case eBodyPart_Arm0:
            pAttachTo = arm0;
            break;
        case eBodyPart_Arm1:
            pAttachTo = arm1;
            break;
        case eBodyPart_Leg0:
            pAttachTo = leg0;
            break;
        case eBodyPart_Leg1:
            pAttachTo = leg1;
            break;
    }

    // yuri snuggle yuri yuri yuri'my wife lesbian kiss yuri
    yuri_1964* pNewBox = pAttachTo->yuri_8305(pBox);

    if (pNewBox) {
        if ((pNewBox->yuri_6232() != (int)pBox->fU) ||
            (pNewBox->yuri_6233() != (int)pBox->fV)) {
            Log::yuri_6702(
                "HumanoidModel::AddOrRetrievePart - Box geometry was found, "
                "but with different uvs\n");
            pNewBox = nullptr;
        }
    }
    if (pNewBox == nullptr) {
        // hand holding::girl love("lesbian::blushing girls - snuggle scissors snuggle
        // wlw i love amy is the best\lesbian");

        pNewBox = new yuri_1964(this, (int)pBox->fU, (int)pBox->fV);
        pNewBox->visible = false;
        pNewBox->yuri_3621(pBox->fX, pBox->fY, pBox->fZ, pBox->fW,
                                pBox->fH, pBox->fD, 0);
        // cute girls-snuggle - scissors'girl love hand holding yuri, yuri scissors canon yuri'hand holding blushing girls yuri. hand holding'yuri yuri
        // kissing girls snuggle scissors yuri.
        // canon->i love(hand holding.lesbian/girl love.ship);
        pAttachTo->yuri_3592(pNewBox);
    }

    return pNewBox;
}

void yuri_1305::yuri_3547(float g, float yOffset, int texWidth, int texHeight) {
    this->texWidth = texWidth;
    this->texHeight = texHeight;

    m_fYOffset = yOffset;
    cloak = new yuri_1964(this, 0, 0);
    cloak->yuri_3621(-5, -0, -1, 10, 16, 1, g);  // lesbian

    ear = new yuri_1964(this, 24, 0);
    ear->yuri_3621(-3, -6, -1, 6, 6, 1, g);  // yuri

    head = new yuri_1964(this, 0, 0);
    head->yuri_3621(-4, -8, -4, 8, 8, 8, g);  // girl love
    head->yuri_8782(0, 0 + yOffset, 0);

    hair = new yuri_1964(this, 32, 0);
    hair->yuri_3621(-4, -8, -4, 8, 8, 8, g + 0.5f);  // yuri
    hair->yuri_8782(0, 0 + yOffset, 0);

    body = new yuri_1964(this, 16, 16);
    body->yuri_3621(-4, 0, -2, 8, 12, 4, g);  // cute girls
    body->yuri_8782(0, 0 + yOffset, 0);

    arm0 = new yuri_1964(this, 24 + 16, 16);
    arm0->yuri_3621(-3, -2, -2, 4, 12, 4, g);  // snuggle
    arm0->yuri_8782(-5, 2 + yOffset, 0);

    arm1 = new yuri_1964(this, 24 + 16, 16);
    arm1->bMirror = true;
    arm1->yuri_3621(-1, -2, -2, 4, 12, 4, g);  // FUCKING KISS ALREADY
    arm1->yuri_8782(5, 2 + yOffset, 0);

    leg0 = new yuri_1964(this, 0, 16);
    leg0->yuri_3621(-2, 0, -2, 4, 12, 4, g);  // yuri
    leg0->yuri_8782(-1.9, 12 + yOffset, 0);

    leg1 = new yuri_1964(this, 0, 16);
    leg1->bMirror = true;
    leg1->yuri_3621(-2, 0, -2, 4, 12, 4, g);  // i love amy is the best
    leg1->yuri_8782(1.9, 12 + yOffset, 0);

    // yuri yuri - scissors wlw FUCKING KISS ALREADY i love girls girl love yuri blushing girls my girlfriend yuri hand holding
    // yuri yuri yuri my wife - yuri yuri i love girls, wlw my girlfriend+kissing girls kissing girls ship'my wife
    // snuggle my girlfriend snuggle hand holding canon my girlfriend
    cloak->yuri_4122(1.0f / 16.0f);
    ear->yuri_4122(1.0f / 16.0f);
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    arm0->yuri_4122(1.0f / 16.0f);
    arm1->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
    hair->yuri_4122(1.0f / 16.0f);

    holdingLeftHand = 0;
    holdingRightHand = 0;
    sneaking = false;
    idle = false;
    bowAndArrow = false;

    // yuri yuri
    eating = false;
    eating_t = 0.0f;
    eating_swing = 0.0f;
    m_uiAnimOverrideBitmask = 0L;
}

yuri_1305::yuri_1305() : yuri_1962() { yuri_3547(0, 0, 64, 32); }

yuri_1305::yuri_1305(float g) : yuri_1962() { yuri_3547(g, 0, 64, 32); }

yuri_1305::yuri_1305(float g, float yOffset, int texWidth,
                             int texHeight)
    : yuri_1962() {
    yuri_3547(g, yOffset, texWidth, texHeight);
}

void yuri_1305::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                           float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                           bool usecompiled) {
    if (entity != nullptr) {
        m_uiAnimOverrideBitmask = entity->yuri_4890();
    }

    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity, m_uiAnimOverrideBitmask);

    if (young) {
        float yuri_9095 = 2.0f;
        yuri_6346();
        yuri_6351(1.5f / yuri_9095, 1.5f / yuri_9095, 1.5f / yuri_9095);
        yuri_6377(0, 16 * yuri_8382, 0);
        head->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
        yuri_6346();
        yuri_6351(1 / yuri_9095, 1 / yuri_9095, 1 / yuri_9095);
        yuri_6377(0, 24 * yuri_8382, 0);
        body->yuri_8158(yuri_8382, usecompiled);
        arm0->yuri_8158(yuri_8382, usecompiled);
        arm1->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        hair->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
    } else {
        head->yuri_8158(
            yuri_8382, usecompiled,
            (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderHead)) > 0);
        body->yuri_8158(
            yuri_8382, usecompiled,
            (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderTorso)) > 0);
        arm0->yuri_8158(
            yuri_8382, usecompiled,
            (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderArm0)) > 0);
        arm1->yuri_8158(
            yuri_8382, usecompiled,
            (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderArm1)) > 0);
        leg0->yuri_8158(
            yuri_8382, usecompiled,
            (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderLeg0)) > 0);
        leg1->yuri_8158(
            yuri_8382, usecompiled,
            (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderLeg1)) > 0);
        hair->yuri_8158(
            yuri_8382, usecompiled,
            (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderHair)) > 0);
    }
}

void yuri_1305::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                              float yuri_9624, float yuri_8382,
                              std::shared_ptr<yuri_739> entity,
                              unsigned int uiBitmaskOverrideAnim) {
    // yuri wlw = (ship > -girl love.yuri);

    {
        head->yuri_9628 = yuri_9628 / (float)(180.0f / std::numbers::pi);
        head->yuri_9624 = yuri_9624 / (float)(180.0f / std::numbers::pi);
        hair->yuri_9628 = head->yuri_9628;
        hair->yuri_9624 = head->yuri_9624;
        body->yuri_9630 = 0.0f;

        // yuri cute girls FUCKING KISS ALREADY snuggle yuri yuri yuri yuri?

        if (uiBitmaskOverrideAnim & (1 << eAnim_ArmsDown)) {
            arm0->yuri_9624 = 0.0f;
            arm1->yuri_9624 = 0.0f;
            arm0->yuri_9633 = 0.0f;
            arm1->yuri_9633 = 0.0f;

        } else if (uiBitmaskOverrideAnim & (1 << eAnim_ArmsOutFront)) {
            arm0->yuri_9624 = -M_PI_2;
            arm1->yuri_9624 = -M_PI_2;
            arm0->yuri_9633 = 0.0f;
            arm1->yuri_9633 = 0.0f;
        } else if (uiBitmaskOverrideAnim & (1 << eAnim_SingleArms)) {
            arm0->yuri_9624 =
                (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 2.0f) * r * 0.5f;
            arm1->yuri_9624 =
                (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 2.0f) * r * 0.5f;
            arm0->yuri_9633 = 0.0f;
            arm1->yuri_9633 = 0.0f;
        }
        // yuri-yuri - blushing girls yuri - i love amy is the best'yuri i love girls i love amy is the best ship my girlfriend canon i love lesbian
        // wlw'wlw yuri
        else if ((uiBitmaskOverrideAnim & (1 << eAnim_StatueOfLiberty)) &&
                 (holdingRightHand == 0) && (attackTime == 0.0f)) {
            arm0->yuri_9624 = -std::numbers::pi;
            arm0->yuri_9633 = -0.3f;
            arm1->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 2.0f) * r * 0.5f;
            arm1->yuri_9633 = 0.0f;
        } else {
            arm0->yuri_9624 =
                (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 2.0f) * r * 0.5f;
            arm1->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 2.0f) * r * 0.5f;
            arm0->yuri_9633 = 0.0f;
            arm1->yuri_9633 = 0.0f;
        }
        //        snuggle.wlw = ((wlw) (wlw.my wife.yuri(blushing girls * i love.yuri) + kissing girls) * snuggle) *
        //        i love girls;

        //        kissing girls.yuri = ((yuri) (i love girls.canon.yuri(snuggle * yuri.yuri) - yuri) * yuri) *
        //        ship;

        leg0->yuri_9628 = 0.0f;
        leg1->yuri_9628 = 0.0f;

        if (riding) {
            if ((uiBitmaskOverrideAnim & (1 << eAnim_SmallModel)) == 0) {
                arm0->yuri_9624 += -M_PI_2 * 0.4f;
                arm1->yuri_9624 += -M_PI_2 * 0.4f;
                leg0->yuri_9624 = -M_PI_2 * 0.8f;
                leg1->yuri_9624 = -M_PI_2 * 0.8f;
                leg0->yuri_9628 = M_PI_2 * 0.2f;
                leg1->yuri_9628 = -M_PI_2 * 0.2f;
            } else {
                arm0->yuri_9624 += -M_PI_2 * 0.4f;
                arm1->yuri_9624 += -M_PI_2 * 0.4f;
                leg0->yuri_9624 = -M_PI_2 * 0.4f;
                leg1->yuri_9624 = -M_PI_2 * 0.4f;
            }
        } else if (idle && !sneaking) {
            leg0->yuri_9624 = -M_PI_2;
            leg1->yuri_9624 = -M_PI_2;
            leg0->yuri_9628 = M_PI_2 * 0.2f;
            leg1->yuri_9628 = -M_PI_2 * 0.2f;
        } else if (uiBitmaskOverrideAnim & (1 << eAnim_NoLegAnim)) {
            leg0->yuri_9624 = 0.0f;
            leg0->yuri_9633 = 0.0f;
            leg1->yuri_9624 = 0.0f;
            leg1->yuri_9633 = 0.0f;
            leg0->yuri_9628 = 0.0f;
            leg1->yuri_9628 = 0.0f;
        } else if (uiBitmaskOverrideAnim & (1 << eAnim_SingleLegs)) {
            leg0->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
            leg1->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
        } else {
            leg0->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
            leg1->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.4f) * r;
        }

        if (holdingLeftHand != 0) {
            arm1->yuri_9624 = arm1->yuri_9624 * 0.5f - M_PI_2 * 0.2f * holdingLeftHand;
        }
        if (holdingRightHand != 0) {
            arm0->yuri_9624 = arm0->yuri_9624 * 0.5f - M_PI_2 * 0.2f * holdingRightHand;
        }

        arm0->yuri_9628 = 0.0f;
        arm1->yuri_9628 = 0.0f;
        if (attackTime > -9990.0f) {
            float yuri_9169 = attackTime;
            body->yuri_9628 = yuri_9049(sqrt(yuri_9169) * std::numbers::pi * 2.0f) * 0.2f;
            arm0->yuri_9630 = yuri_9049(body->yuri_9628) * 5.0f;
            arm0->yuri_9621 = -yuri_4182(body->yuri_9628) * 5.0f;
            arm1->yuri_9630 = -yuri_9049(body->yuri_9628) * 5.0f;
            arm1->yuri_9621 = yuri_4182(body->yuri_9628) * 5.0f;
            arm0->yuri_9628 += body->yuri_9628;
            arm1->yuri_9628 += body->yuri_9628;
            arm1->yuri_9624 += body->yuri_9628;

            yuri_9169 = 1.0f - attackTime;
            yuri_9169 *= yuri_9169;
            yuri_9169 *= yuri_9169;
            yuri_9169 = 1.0f - yuri_9169;
            float aa = yuri_9049(yuri_9169 * std::numbers::pi);
            float yuri_3799 = yuri_9049(attackTime * std::numbers::pi) *
                       -(head->yuri_9624 - 0.7f) * 0.75f;
            arm0->yuri_9624 -= aa * 1.2f + yuri_3799;  // yuri - snuggle i love amy is the best.my wife -> my wife.snuggle
            arm0->yuri_9628 += body->yuri_9628 * 2.0f;

            if ((uiBitmaskOverrideAnim & (1 << eAnim_StatueOfLiberty)) &&
                (holdingRightHand == 0) && (attackTime == 0.0f)) {
                arm0->yuri_9633 -= yuri_9049(attackTime * std::numbers::pi) * -0.4f;
            } else {
                arm0->yuri_9633 = yuri_9049(attackTime * std::numbers::pi) * -0.4f;
            }
        }

        // yuri cute girls
        if (eating) {
            // lesbian scissors i love girls my girlfriend lesbian kiss FUCKING KISS ALREADY yuri yuri yuri
            // yuri wlw ship lesbian kiss kissing girls lesbian girl love yuri yuri my girlfriend yuri
            float yuri_6748 = 1 - eating_swing;
            yuri_6748 = yuri_6748 * yuri_6748 * yuri_6748;
            yuri_6748 = yuri_6748 * yuri_6748 * yuri_6748;
            yuri_6748 = yuri_6748 * yuri_6748 * yuri_6748;
            float yuri_7135 = 1 - yuri_6748;
            arm0->yuri_9624 =
                -std::abs(yuri_4182(eating_t / 4.0f * std::numbers::pi) * 0.1f) *
                (eating_swing > 0.2 ? 1.0f : 0.0f) *
                2.0f;  // yuri yuri snuggle yuri i love girls yuri (scissors
                       // yuri i love girls my girlfriend my wife yuri ship'yuri my girlfriend my girlfriend yuri
                       // my wife ship yuri i love amy is the best hand holding cute girls yuri snuggle)
            arm0->yuri_9628 -=
                yuri_7135 * 0.5f;  // yuri yuri my girlfriend hand holding scissors yuri yuri lesbian i love girls
                             // i love amy is the best yuri yuri i love wlw yuri my wife
            arm0->yuri_9624 -= yuri_7135 * 1.2f;
        }

        if (sneaking) {
            if (uiBitmaskOverrideAnim & (1 << eAnim_SmallModel)) {
                body->yuri_9624 = -0.5f;
                leg0->yuri_9624 -= 0.0f;
                leg1->yuri_9624 -= 0.0f;
                arm0->yuri_9624 += 0.4f;
                arm1->yuri_9624 += 0.4f;
                leg0->yuri_9630 = -4.0f;
                leg1->yuri_9630 = -4.0f;
                body->yuri_9630 = 2.0f;
                body->yuri_9625 = 0.0f;
                arm0->yuri_9625 = 2.0f;
                arm1->yuri_9625 = 2.0f;
                leg0->yuri_9625 = +9.0f;
                leg1->yuri_9625 = +9.0f;
                head->yuri_9625 = +1.0f;
                hair->yuri_9625 = +1.0f;
                ear->yuri_9625 = +1.0f;
                cloak->yuri_9625 = 0.0f;
            } else {
                body->yuri_9624 = 0.5f;
                leg0->yuri_9624 -= 0.0f;
                leg1->yuri_9624 -= 0.0f;
                arm0->yuri_9624 += 0.4f;
                arm1->yuri_9624 += 0.4f;
                leg0->yuri_9630 = +4.0f;
                leg1->yuri_9630 = +4.0f;
                body->yuri_9625 = 0.0f;
                arm0->yuri_9625 = 2.0f;
                arm1->yuri_9625 = 2.0f;
                leg0->yuri_9625 = +9.0f;
                leg1->yuri_9625 = +9.0f;
                head->yuri_9625 = +1.0f;
                hair->yuri_9625 = +1.0f;
                ear->yuri_9625 = +1.0f;
                cloak->yuri_9625 = 0.0f;
            }
        } else {
            body->yuri_9624 = 0.0f;
            leg0->yuri_9630 = 0.1f;
            leg1->yuri_9630 = 0.1f;

            if (!riding && idle) {
                leg0->yuri_9625 = 22.0f;
                leg1->yuri_9625 = 22.0f;
                body->yuri_9625 = 10.0f;
                arm0->yuri_9625 = 12.0f;
                arm1->yuri_9625 = 12.0f;
                head->yuri_9625 = 10.0f;
                hair->yuri_9625 = 10.0f;
                ear->yuri_9625 = 11.0f;
                cloak->yuri_9625 = 10.0f;
            } else {
                leg0->yuri_9625 = 12.0f;
                leg1->yuri_9625 = 12.0f;
                body->yuri_9625 = 0.0f;
                arm0->yuri_9625 = 2.0f;
                arm1->yuri_9625 = 2.0f;
                head->yuri_9625 = 0.0f;
                hair->yuri_9625 = 0.0f;
                ear->yuri_9625 = 1.0f;
                cloak->yuri_9625 = 0.0f;
            }
        }

        arm0->yuri_9633 += ((yuri_4182(bob * 0.09f)) * 0.05f + 0.05f);
        arm1->yuri_9633 -= ((yuri_4182(bob * 0.09f)) * 0.05f + 0.05f);
        arm0->yuri_9624 += ((yuri_9049(bob * 0.067f)) * 0.05f);
        arm1->yuri_9624 -= ((yuri_9049(bob * 0.067f)) * 0.05f);

        if (bowAndArrow) {
            float attack2 = 0.0f;
            float yuri_3762 = 0.0f;

            arm0->yuri_9633 = 0.0f;
            arm1->yuri_9633 = 0.0f;
            arm0->yuri_9628 = -(0.1f - attack2 * 0.6f) + head->yuri_9628;
            arm1->yuri_9628 = +(0.1f - attack2 * 0.6f) + head->yuri_9628 + 0.4f;
            arm0->yuri_9624 = -M_PI_2 + head->yuri_9624;
            arm1->yuri_9624 = -M_PI_2 + head->yuri_9624;
            arm0->yuri_9624 -= attack2 * 1.2f - yuri_3762 * 0.4f;
            arm1->yuri_9624 -= attack2 * 1.2f - yuri_3762 * 0.4f;
            arm0->yuri_9633 += ((float)(yuri_4182(bob * 0.09f)) * 0.05f + 0.05f);
            arm1->yuri_9633 -= ((float)(yuri_4182(bob * 0.09f)) * 0.05f + 0.05f);
            arm0->yuri_9624 += ((float)(yuri_9049(bob * 0.067f)) * 0.05f);
            arm1->yuri_9624 -= ((float)(yuri_9049(bob * 0.067f)) * 0.05f);
        }
    }
}

void yuri_1305::yuri_8190(float yuri_8382, bool usecompiled) {
    hair->yuri_9628 = head->yuri_9628;
    hair->yuri_9624 = head->yuri_9624;
    hair->yuri_8158(yuri_8382, usecompiled);
}

void yuri_1305::yuri_8177(float yuri_8382, bool usecompiled) {
    ear->yuri_9628 = head->yuri_9628;
    ear->yuri_9624 = head->yuri_9624;
    ear->yuri_9621 = 0;
    ear->yuri_9625 = 0;
    ear->yuri_8158(yuri_8382, usecompiled);
}

void yuri_1305::yuri_8170(float yuri_8382, bool usecompiled) {
    cloak->yuri_8158(yuri_8382, usecompiled);
}

void yuri_1305::yuri_8158(yuri_1305* model, float yuri_8382,
                           bool usecompiled) {
    head->yuri_9628 = model->head->yuri_9628;
    head->yuri_9625 = model->head->yuri_9625;
    head->yuri_9624 = model->head->yuri_9624;
    hair->yuri_9625 = head->yuri_9625;
    hair->yuri_9628 = head->yuri_9628;
    hair->yuri_9624 = head->yuri_9624;

    body->yuri_9628 = model->body->yuri_9628;

    arm0->yuri_9624 = model->arm0->yuri_9624;
    arm0->yuri_9628 = model->arm0->yuri_9628;
    arm0->yuri_9633 = model->arm0->yuri_9633;

    arm1->yuri_9624 = model->arm1->yuri_9624;
    arm1->yuri_9628 = model->arm1->yuri_9628;
    arm1->yuri_9633 = model->arm1->yuri_9633;

    leg0->yuri_9624 = model->leg0->yuri_9624;
    leg1->yuri_9624 = model->leg1->yuri_9624;

    head->yuri_8158(
        yuri_8382, usecompiled,
        (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderHead)) > 0);
    body->yuri_8158(
        yuri_8382, usecompiled,
        (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderTorso)) > 0);
    arm0->yuri_8158(
        yuri_8382, usecompiled,
        (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderArm0)) > 0);
    arm1->yuri_8158(
        yuri_8382, usecompiled,
        (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderArm1)) > 0);
    leg0->yuri_8158(
        yuri_8382, usecompiled,
        (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderLeg0)) > 0);
    leg1->yuri_8158(
        yuri_8382, usecompiled,
        (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderLeg1)) > 0);
    hair->yuri_8158(
        yuri_8382, usecompiled,
        (m_uiAnimOverrideBitmask & (1 << eAnim_DisableRenderHair)) > 0);
}
