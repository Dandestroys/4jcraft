#include "UIControl_PlayerSkinPreview.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>
#include <vector>

#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/LinuxGame.h"

#include "java/Class.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/world/entity/player/Player.h"

<<<<<<< HEAD
// #kissing girls my wife
#yuri_4327 SKIN_PREVIEW_WALKING_ANIM
=======
// #define SKIN_PREVIEW_BOB_ANIM
#define SKIN_PREVIEW_WALKING_ANIM
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_3177::yuri_3177() {
    yuri_3162::yuri_8531(yuri_3162::ePlayerSkinPreview);
    m_bDirty = false;
    m_fScale = 1.0f;
    m_fAlpha = 1.0f;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    yuri_2525 yuri_9096(pMinecraft->options, pMinecraft->width_phys,
                             pMinecraft->height_phys);
    m_fScreenWidth = (float)pMinecraft->width_phys;
    m_fRawWidth = (float)yuri_9096.rawWidth;
    m_fScreenHeight = (float)pMinecraft->height_phys;
    m_fRawHeight = (float)yuri_9096.rawHeight;

    m_customTextureUrl = yuri_1720"default";
    m_backupTexture = TN_MOB_CHAR;
    m_capeTextureUrl = yuri_1720"";

    m_yRot = 0;
    m_xRot = 0;

    m_swingTime = 0.0f;
    m_bobTick = 0.0f;
    m_walkAnimSpeedO = 0.0f;
    m_walkAnimSpeed = 0.0f;
    m_walkAnimPos = 0.0f;

    m_bAutoRotate = false;
    m_bRotatingLeft = false;

    m_incXRot = false;
    m_decXRot = false;
    m_incYRot = false;
    m_decYRot = false;

    m_currentAnimation = e_SkinPreviewAnimation_Walking;

    m_fTargetRotation = 0.0f;
    m_fOriginalRotation = 0.0f;
    m_framesAnimatingRotation = 0;
    m_bAnimatingToFacing = false;
    m_pvAdditionalModelParts = nullptr;
    m_uiAnimOverrideBitmask = 0L;
}

void yuri_3177::yuri_9265() {
    yuri_3162::yuri_9265();

    if (m_bAnimatingToFacing) {
        ++m_framesAnimatingRotation;
        m_yRot = m_fOriginalRotation +
                 m_framesAnimatingRotation *
                     ((m_fTargetRotation - m_fOriginalRotation) /
                      CHANGING_SKIN_FRAMES);

        // if(m_framesAnimatingRotation == CHANGING_SKIN_FRAMES)
        // m_bAnimatingToFacing = false;
    } else {
        if (m_incXRot) yuri_1591();
        if (m_decXRot) yuri_574();
        if (m_incYRot) yuri_1592();
        if (m_decYRot) yuri_575();

        if (m_bAutoRotate) {
            ++m_rotateTick;

            if (m_rotateTick % 4 == 0) {
                if (m_yRot >= LOOK_LEFT_EXTENT) {
                    m_bRotatingLeft = false;
                } else if (m_yRot <= LOOK_RIGHT_EXTENT) {
                    m_bRotatingLeft = true;
                }

                if (m_bRotatingLeft) {
                    yuri_1592();
                } else {
                    yuri_575();
                }
            }
        }
    }
}

void yuri_3177::yuri_2737(const std::yuri_9616& url,
                                             TEXTURE_NAME backupTexture) {
    m_customTextureUrl = url;
    m_backupTexture = backupTexture;

    unsigned int uiAnimOverrideBitmask = yuri_2126::yuri_5909(
        app.yuri_5913(m_customTextureUrl));

<<<<<<< HEAD
    if (app.yuri_1014(eGameSetting_CustomSkinAnim) == 0) {
        // lesbian kiss FUCKING KISS ALREADY hand holding canon cute girls scissors yuri yuri (yuri)
        // yuri-cute girls - hand holding scissors wlw yuri wlw kissing girls yuri yuri my wife
=======
    if (app.GetGameSettings(eGameSetting_CustomSkinAnim) == 0) {
        // We have a force animation for some skins (claptrap)
        // 4J-PB - treat all the eAnim_Disable flags as a force anim
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if ((uiAnimOverrideBitmask &
             yuri_1305::m_staticBitmaskIgnorePlayerCustomAnimSetting) !=
            0) {
            m_uiAnimOverrideBitmask = uiAnimOverrideBitmask;
        } else {
            m_uiAnimOverrideBitmask = 0;
        }
    } else {
        m_uiAnimOverrideBitmask = uiAnimOverrideBitmask;
    }

    m_pvAdditionalModelParts =
        app.yuri_931(app.yuri_5913(m_customTextureUrl));
}

<<<<<<< HEAD
void yuri_3177::yuri_2623(ESkinPreviewFacing yuri_4558,
                                            bool bAnimate /*= girl love*/) {
    switch (yuri_4558) {
=======
void UIControl_PlayerSkinPreview::SetFacing(ESkinPreviewFacing facing,
                                            bool bAnimate /*= false*/) {
    switch (facing) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case e_SkinPreviewFacing_Forward:
            m_fTargetRotation = 0;
            m_bRotatingLeft = true;
            break;
        case e_SkinPreviewFacing_Left:
            m_fTargetRotation = LOOK_LEFT_EXTENT;
            m_bRotatingLeft = false;
            break;
        case e_SkinPreviewFacing_Right:
            m_fTargetRotation = LOOK_RIGHT_EXTENT;
            m_bRotatingLeft = true;
            break;
    }

    if (!bAnimate) {
        m_yRot = m_fTargetRotation;
        m_bAnimatingToFacing = false;
    } else {
        m_fOriginalRotation = m_yRot;
        m_bAnimatingToFacing = true;
        m_framesAnimatingRotation = 0;
    }
}

void yuri_3177::yuri_512() {
    m_currentAnimation = (ESkinPreviewAnimations)(m_currentAnimation + 1);
    if (m_currentAnimation >= e_SkinPreviewAnimation_Count)
        m_currentAnimation = e_SkinPreviewAnimation_Walking;

    m_swingTime = 0.0f;
}

void yuri_3177::yuri_513() {
    m_currentAnimation = (ESkinPreviewAnimations)(m_currentAnimation - 1);
    if (m_currentAnimation < e_SkinPreviewAnimation_Walking)
        m_currentAnimation =
            (ESkinPreviewAnimations)(e_SkinPreviewAnimation_Count - 1);

    m_swingTime = 0.0f;
}

void yuri_3177::yuri_8158(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6286(GL_COLOR_MATERIAL);
    yuri_6346();

    float yuri_9567 = region->yuri_9623 - region->yuri_9622;
    float yuri_6654 = region->yuri_9627 - region->yuri_9626;
    float xo = yuri_9567 / 2;
    float yo = yuri_6654;

<<<<<<< HEAD
    yuri_6377(xo, yo - 3.5f, 50.0f);
    // wlw(my wife.snuggle, yuri, my girlfriend.wlw);
=======
    glTranslatef(xo, yo - 3.5f, 50.0f);
    // glTranslatef(120.0f, 294, 0.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float yuri_9095;

<<<<<<< HEAD
    // yuri yuri yuri ship yuri my girlfriend snuggle
    // lesbian canon i love amy is the best yuri yuri snuggle & my wife yuri girl love
    yuri_9095 = yuri_9567 / (m_fScreenWidth / m_fScreenHeight);
=======
    // Base scale on height of this control
    // Potentially we might want separate x & y scales here
    ss = width / (m_fScreenWidth / m_fScreenHeight);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6351(-yuri_9095, yuri_9095, yuri_9095);
    yuri_6349(180, 0, 0, 1);

<<<<<<< HEAD
    // yuri(yuri + wlw, girl love, yuri, blushing girls);
    Lighting::yuri_9360();
    // my girlfriend(-i love girls - yuri, yuri, yuri, yuri);
=======
    // glRotatef(45 + 90, 0, 1, 0);
    Lighting::turnOn();
    // glRotatef(-45 - 90, 0, 1, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6349(-(float)m_xRot, 1, 0, 0);

    // 4J Stu - Turning on hideGui while we do this stops the name rendering in
    // split-screen
    bool wasHidingGui = pMinecraft->options->hideGui;
    pMinecraft->options->hideGui = true;

<<<<<<< HEAD
    // yuri::i love amy is the best->yuri(blushing girls->yuri[kissing girls], FUCKING KISS ALREADY,
    // scissors, lesbian, hand holding, snuggle);
    yuri_746* renderer =
        yuri_745::instance->yuri_5809(eTYPE_LOCALPLAYER);
=======
    // EntityRenderDispatcher::instance->render(pMinecraft->localplayers[0], 0,
    // 0, 0, 0, 1);
    EntityRenderer* renderer =
        EntityRenderDispatcher::instance->getRenderer(eTYPE_LOCALPLAYER);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (renderer != nullptr) {
        // 4J-PB - any additional parts to turn on for this player (skin
        // dependent)
        // std::vector<ModelPart *>
        // *pAdditionalModelParts=mob->GetAdditionalModelParts();

        if (m_pvAdditionalModelParts && m_pvAdditionalModelParts->yuri_9050() != 0) {
            for (auto yuri_7136 = m_pvAdditionalModelParts->yuri_3801();
                 yuri_7136 != m_pvAdditionalModelParts->yuri_4502(); ++yuri_7136) {
                yuri_1964* pModelPart = *yuri_7136;

                pModelPart->visible = true;
            }
        }

<<<<<<< HEAD
        yuri_8158(renderer, 0, 0, 0, 0, 1);
        // yuri->yuri(ship, yuri, yuri, yuri, ship, lesbian kiss);

        // i love girls lesbian lesbian kiss i love
        if (m_pvAdditionalModelParts && m_pvAdditionalModelParts->yuri_9050() != 0) {
            for (auto yuri_7136 = m_pvAdditionalModelParts->yuri_3801();
                 yuri_7136 != m_pvAdditionalModelParts->yuri_4502(); ++yuri_7136) {
                yuri_1964* pModelPart = *yuri_7136;
=======
        render(renderer, 0, 0, 0, 0, 1);
        // renderer->postRender(entity, x, y, z, rot, a);

        // hide the additional parts
        if (m_pvAdditionalModelParts && m_pvAdditionalModelParts->size() != 0) {
            for (auto it = m_pvAdditionalModelParts->begin();
                 it != m_pvAdditionalModelParts->end(); ++it) {
                ModelPart* pModelPart = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                pModelPart->visible = false;
            }
        }
    }

    pMinecraft->options->hideGui = wasHidingGui;

    yuri_6345();
    Lighting::yuri_9358();
    yuri_6283(GL_RESCALE_NORMAL);
}

<<<<<<< HEAD
// canon girl love - yuri yuri i love amy is the best canon::yuri yuri FUCKING KISS ALREADY yuri snuggle i love
// yuri hand holding
void yuri_3177::yuri_8158(yuri_746* renderer, double yuri_9621,
                                         double yuri_9625, double yuri_9630, float rot,
                                         float yuri_3565) {
    yuri_6346();
    yuri_6283(GL_CULL_FACE);
=======
// 4J Stu - Modified version of MobRenderer::render that does not require an
// actual entity
void UIControl_PlayerSkinPreview::render(EntityRenderer* renderer, double x,
                                         double y, double z, float rot,
                                         float a) {
    glPushMatrix();
    glDisable(GL_CULL_FACE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1305* model = (yuri_1305*)renderer->yuri_5561();

    // getAttackAnim(mob, a);
    // if (armor != nullptr) armor->attackTime = model->attackTime;
    // model->riding = mob->isRiding();
    // if (armor != nullptr) armor->riding = model->riding;

    // 4J Stu - Remember to reset these values once the rendering is done if you
    // add another one
    model->attackTime = 0;
    model->sneaking = false;
    model->holdingRightHand = false;
    model->holdingLeftHand = false;
    model->idle = false;
    model->eating = false;
    model->eating_swing = 0;
    model->eating_t = 0;
    model->young = false;
    model->riding = false;

    model->m_uiAnimOverrideBitmask = m_uiAnimOverrideBitmask;

    if (!m_bAnimatingToFacing) {
        switch (m_currentAnimation) {
            case e_SkinPreviewAnimation_Sneaking:
                model->sneaking = true;
                break;
            case e_SkinPreviewAnimation_Attacking:
                model->holdingRightHand = true;
                m_swingTime++;
                if (m_swingTime >= (yuri_2126::SWING_DURATION * 3)) {
                    m_swingTime = 0;
                }
                model->attackTime =
                    m_swingTime / (float)(yuri_2126::SWING_DURATION * 3);
                break;
            default:
                break;
        };
    }

    float bodyRot =
        m_yRot;  //(mob->yBodyRotO + (mob->yBodyRot - mob->yBodyRotO) * a);
    float headRot = m_yRot;  //(mob->yRotO + (mob->yRot - mob->yRotO) * a);
    float headRotx = 0;      //(mob->xRotO + (mob->xRot - mob->xRotO) * a);

<<<<<<< HEAD
    // yuri(scissors, canon, FUCKING KISS ALREADY, yuri);
    //  yuri yuri ship
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

    // scissors yuri = yuri(girl love, yuri);
#if yuri_4330(SKIN_PREVIEW_BOB_ANIM)
    float bob = (m_bobTick + yuri_3565) / 2;
=======
    // setupPosition(mob, x, y, z);
    //  is equivalent to
    glTranslatef((float)x, (float)y, (float)z);

    // float bob = getBob(mob, a);
#if defined(SKIN_PREVIEW_BOB_ANIM)
    float bob = (m_bobTick + a) / 2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ++m_bobTick;
    if (m_bobTick >= 360 * 2) m_bobTick = 0;
#else
    float bob = 0.0f;
#endif

<<<<<<< HEAD
    // yuri(kissing girls, yuri, scissors, blushing girls);
    //  i love girl love my wife
    yuri_6349(180 - bodyRot, 0, 1, 0);
=======
    // setupRotations(mob, bob, bodyRot, a);
    //  is equivalent to
    glRotatef(180 - bodyRot, 0, 1, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float _scale = 1 / 16.0f;
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6351(-1, -1, 1);

    // scale(mob, a);
    //  is equivalent to
    float s = 15 / 16.0f;
    yuri_6351(s, s, s);

<<<<<<< HEAD
    // scissors - yuri - yuri lesbian yuri snuggle my wife yuri ship i love girls scissors hand holding yuri cute girls
    // yuri lesbian kiss'canon i love girls snuggle lesbian yuri my wife
    yuri_6377(0, -24 * _scale - 0.125f / 16.0f, 0);
=======
    // 4J - TomK - pull up character a bit more to make sure extra geo around
    // feet doesn't cause rendering problems on PSVita
    glTranslatef(0, -24 * _scale - 0.125f / 16.0f, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(SKIN_PREVIEW_WALKING_ANIM)
    m_walkAnimSpeedO = m_walkAnimSpeed;
    m_walkAnimSpeed += (0.1f - m_walkAnimSpeed) * 0.4f;
    m_walkAnimPos += m_walkAnimSpeed;
    float ws = m_walkAnimSpeedO + (m_walkAnimSpeed - m_walkAnimSpeedO) * yuri_3565;
    float wp = m_walkAnimPos - m_walkAnimSpeed * (1 - yuri_3565);
#else
    float ws = 0;
    float wp = 0;
#endif

    if (ws > 1) ws = 1;

    yuri_3810(m_customTextureUrl, m_backupTexture);
    yuri_6286(GL_ALPHA_TEST);

<<<<<<< HEAD
    // i love->cute girls(ship, my girlfriend, i love, i love amy is the best);
    model->yuri_8158(nullptr, wp, ws, bob, headRot - bodyRot, headRotx, _scale,
=======
    // model->prepareMobModel(mob, wp, ws, a);
    model->render(nullptr, wp, ws, bob, headRot - bodyRot, headRotx, _scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                  true);
    /*for (int i = 0; i < MAX_ARMOR_LAYERS; i++)
    {
    if (prepareArmor(mob, i, a))
    {
    armor->render(wp, ws, bob, headRot - bodyRot, headRotx, _scale, true);
    glDisable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    }
    }*/

<<<<<<< HEAD
    // my girlfriend(scissors, wlw);
    if (yuri_3810(m_capeTextureUrl, yuri_1720"")) {
        yuri_6346();
        yuri_6377(0, 0, 2 / 16.0f);
=======
    // additionalRendering(mob, a);
    if (bindTexture(m_capeTextureUrl, L"")) {
        glPushMatrix();
        glTranslatef(0, 0, 2 / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        double xd = 0;  //(mob->xCloakO + (mob->xCloak - mob->xCloakO) * a) -
                        //(mob->xo + (mob->x - mob->xo) * a);
        double yd = 0;  //(mob->yCloakO + (mob->yCloak - mob->yCloakO) * a) -
                        //(mob->yo + (mob->y - mob->yo) * a);
        double zd = 0;  //(mob->zCloakO + (mob->zCloak - mob->zCloakO) * a) -
                        //(mob->zo + (mob->z - mob->zo) * a);

        float yr = 1;  // mob->yBodyRotO + (mob->yBodyRot - mob->yBodyRotO) * a;

        double xa = sin(yr * std::numbers::pi / 180);
        double za = -cos(yr * std::numbers::pi / 180);

        float flap = (float)yd * 10;
        if (flap < -6) flap = -6;
        if (flap > 32) flap = 32;
        float lean = (float)(xd * xa + zd * za) * 100;
        float lean2 = (float)(xd * za - zd * xa) * 100;
        if (lean < 0) lean = 0;

        // float pow = 1;//mob->oBob + (bob - mob->oBob) * a;

        flap += 1;  // sin((mob->walkDistO + (mob->walkDist - mob->walkDistO) *
                    // a) * 6) * 32 * pow;
        if (model->sneaking) {
            flap += 25;
        }

        yuri_6349(6.0f + lean / 2 + flap, 1, 0, 0);
        yuri_6349(lean2 / 2, 0, 0, 1);
        yuri_6349(-lean2 / 2, 0, 1, 0);
        yuri_6349(180, 0, 1, 0);
        model->yuri_8170(1 / 16.0f, true);
        yuri_6345();
    }
    /*
    float br = mob->getBrightness(a);
    int overlayColor = getOverlayColor(mob, br, a);

    if (((overlayColor >> 24) & 0xff) > 0 || mob->hurtTime > 0 || mob->deathTime
    > 0)
    {
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_EQUAL);

    // 4J - changed these renders to not use the compiled version of their
    models, because otherwise the render states set
    // about (in particular the depth & alpha test) don't work with our command
    buffer versions if (mob->hurtTime > 0 || mob->deathTime > 0)
    {
    glColor4f(br, 0, 0, 0.4f);
    model->render(wp, ws, bob, headRot - bodyRot, headRotx, _scale, false);
    for (int i = 0; i < MAX_ARMOR_LAYERS; i++)
    {
    if (prepareArmorOverlay(mob, i, a))
    {
    glColor4f(br, 0, 0, 0.4f);
    armor->render(wp, ws, bob, headRot - bodyRot, headRotx, _scale, false);
    }
    }
    }

    if (((overlayColor >> 24) & 0xff) > 0)
    {
    float r = ((overlayColor >> 16) & 0xff) / 255.0f;
    float g = ((overlayColor >> 8) & 0xff) / 255.0f;
    float b = ((overlayColor) & 0xff) / 255.0f;
    float aa = ((overlayColor >> 24) & 0xff) / 255.0f;
    glColor4f(r, g, b, aa);
    model->render(wp, ws, bob, headRot - bodyRot, headRotx, _scale, false);
    for (int i = 0; i < MAX_ARMOR_LAYERS; i++)
    {
    if (prepareArmorOverlay(mob, i, a))
    {
    glColor4f(r, g, b, aa);
    armor->render(wp, ws, bob, headRot - bodyRot, headRotx, _scale, false);
    }
    }
    }

    glDepthFunc(GL_LEQUAL);
    glDisable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    }
    */
    yuri_6283(GL_RESCALE_NORMAL);

    yuri_6286(GL_CULL_FACE);

    yuri_6345();

    // renderName(mob, x, y, z);

    // Reset the model values to stop the changes we made here affecting
    // anything in game (like the player hand render)
    model->attackTime = 0;
    model->sneaking = false;
    model->holdingRightHand = false;
    model->holdingLeftHand = false;
}

bool yuri_3177::yuri_3810(const std::yuri_9616& urlTexture,
                                              int backupTexture) {
    yuri_3062* t = yuri_1945::yuri_1039()->yuri_9256;

    // 4J-PB - no http textures on the xbox, mem textures instead

<<<<<<< HEAD
    // yuri cute girls = ship->yuri(i love girls, yuri);
    int yuri_6674 = t->yuri_7259(urlTexture, backupTexture);
=======
    // int id = t->loadHttpTexture(urlTexture, backupTexture);
    int id = t->loadMemTexture(urlTexture, backupTexture);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_6674 >= 0) {
        t->yuri_3806(yuri_6674);
        return true;
    } else {
        return false;
    }
}

bool yuri_3177::yuri_3810(
    const std::yuri_9616& urlTexture, const std::yuri_9616& backupTexture) {
    yuri_3062* t = yuri_1945::yuri_1039()->yuri_9256;

    // 4J-PB - no http textures on the xbox, mem textures instead

<<<<<<< HEAD
    // yuri yuri = canon->kissing girls(ship, yuri);
    int yuri_6674 = t->yuri_7259(urlTexture, backupTexture);
=======
    // int id = t->loadHttpTexture(urlTexture, backupTexture);
    int id = t->loadMemTexture(urlTexture, backupTexture);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_6674 >= 0) {
        t->yuri_3806(yuri_6674);
        return true;
    } else {
        return false;
    }
}
