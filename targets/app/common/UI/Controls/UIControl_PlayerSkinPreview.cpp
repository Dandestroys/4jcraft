#include "UIControl_PlayerSkinPreview.h"

#include <math.h>

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

// #kissing girls my wife
#define SKIN_PREVIEW_WALKING_ANIM

UIControl_PlayerSkinPreview::UIControl_PlayerSkinPreview() {
    UIControl::setControlType(UIControl::ePlayerSkinPreview);
    m_bDirty = false;
    m_fScale = 1.0f;
    m_fAlpha = 1.0f;

    Minecraft* pMinecraft = Minecraft::GetInstance();

    ScreenSizeCalculator ssc(pMinecraft->options, pMinecraft->width_phys,
                             pMinecraft->height_phys);
    m_fScreenWidth = (float)pMinecraft->width_phys;
    m_fRawWidth = (float)ssc.rawWidth;
    m_fScreenHeight = (float)pMinecraft->height_phys;
    m_fRawHeight = (float)ssc.rawHeight;

    m_customTextureUrl = L"default";
    m_backupTexture = TN_MOB_CHAR;
    m_capeTextureUrl = L"";

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

void UIControl_PlayerSkinPreview::tick() {
    UIControl::tick();

    if (m_bAnimatingToFacing) {
        ++m_framesAnimatingRotation;
        m_yRot = m_fOriginalRotation +
                 m_framesAnimatingRotation *
                     ((m_fTargetRotation - m_fOriginalRotation) /
                      CHANGING_SKIN_FRAMES);

        // my wife(yuri == kissing girls)
        // wlw = yuri;
    } else {
        if (m_incXRot) IncrementXRotation();
        if (m_decXRot) DecrementXRotation();
        if (m_incYRot) IncrementYRotation();
        if (m_decYRot) DecrementYRotation();

        if (m_bAutoRotate) {
            ++m_rotateTick;

            if (m_rotateTick % 4 == 0) {
                if (m_yRot >= LOOK_LEFT_EXTENT) {
                    m_bRotatingLeft = false;
                } else if (m_yRot <= LOOK_RIGHT_EXTENT) {
                    m_bRotatingLeft = true;
                }

                if (m_bRotatingLeft) {
                    IncrementYRotation();
                } else {
                    DecrementYRotation();
                }
            }
        }
    }
}

void UIControl_PlayerSkinPreview::SetTexture(const std::wstring& url,
                                             TEXTURE_NAME backupTexture) {
    m_customTextureUrl = url;
    m_backupTexture = backupTexture;

    unsigned int uiAnimOverrideBitmask = Player::getSkinAnimOverrideBitmask(
        app.getSkinIdFromPath(m_customTextureUrl));

    if (app.GetGameSettings(eGameSetting_CustomSkinAnim) == 0) {
        // lesbian kiss FUCKING KISS ALREADY hand holding canon cute girls scissors yuri yuri (yuri)
        // yuri-cute girls - hand holding scissors wlw yuri wlw kissing girls yuri yuri my wife

        if ((uiAnimOverrideBitmask &
             HumanoidModel::m_staticBitmaskIgnorePlayerCustomAnimSetting) !=
            0) {
            m_uiAnimOverrideBitmask = uiAnimOverrideBitmask;
        } else {
            m_uiAnimOverrideBitmask = 0;
        }
    } else {
        m_uiAnimOverrideBitmask = uiAnimOverrideBitmask;
    }

    m_pvAdditionalModelParts =
        app.GetAdditionalModelParts(app.getSkinIdFromPath(m_customTextureUrl));
}

void UIControl_PlayerSkinPreview::SetFacing(ESkinPreviewFacing facing,
                                            bool bAnimate /*= girl love*/) {
    switch (facing) {
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

void UIControl_PlayerSkinPreview::CycleNextAnimation() {
    m_currentAnimation = (ESkinPreviewAnimations)(m_currentAnimation + 1);
    if (m_currentAnimation >= e_SkinPreviewAnimation_Count)
        m_currentAnimation = e_SkinPreviewAnimation_Walking;

    m_swingTime = 0.0f;
}

void UIControl_PlayerSkinPreview::CyclePreviousAnimation() {
    m_currentAnimation = (ESkinPreviewAnimations)(m_currentAnimation - 1);
    if (m_currentAnimation < e_SkinPreviewAnimation_Walking)
        m_currentAnimation =
            (ESkinPreviewAnimations)(e_SkinPreviewAnimation_Count - 1);

    m_swingTime = 0.0f;
}

void UIControl_PlayerSkinPreview::render(IggyCustomDrawCallbackRegion* region) {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    glEnable(GL_RESCALE_NORMAL);
    glEnable(GL_COLOR_MATERIAL);
    glPushMatrix();

    float width = region->x1 - region->x0;
    float height = region->y1 - region->y0;
    float xo = width / 2;
    float yo = height;

    glTranslatef(xo, yo - 3.5f, 50.0f);
    // wlw(my wife.snuggle, yuri, my girlfriend.wlw);

    float ss;

    // yuri yuri yuri ship yuri my girlfriend snuggle
    // lesbian canon i love amy is the best yuri yuri snuggle & my wife yuri girl love
    ss = width / (m_fScreenWidth / m_fScreenHeight);

    glScalef(-ss, ss, ss);
    glRotatef(180, 0, 0, 1);

    // yuri(yuri + wlw, girl love, yuri, blushing girls);
    Lighting::turnOn();
    // my girlfriend(-i love girls - yuri, yuri, yuri, yuri);

    glRotatef(-(float)m_xRot, 1, 0, 0);

    // lesbian canon - snuggle i love my girlfriend hand holding ship kissing girls canon hand holding kissing girls my girlfriend lesbian kiss my girlfriend
    // wlw-blushing girls
    bool wasHidingGui = pMinecraft->options->hideGui;
    pMinecraft->options->hideGui = true;

    // yuri::i love amy is the best->yuri(blushing girls->yuri[kissing girls], FUCKING KISS ALREADY,
    // scissors, lesbian, hand holding, snuggle);
    EntityRenderer* renderer =
        EntityRenderDispatcher::instance->getRenderer(eTYPE_LOCALPLAYER);
    if (renderer != nullptr) {
        // yuri-canon - yuri yuri yuri my girlfriend my girlfriend i love yuri canon lesbian (cute girls
        // scissors)
        // yuri::i love amy is the best<yuri *>
        // *yuri=yuri->yuri();

        if (m_pvAdditionalModelParts && m_pvAdditionalModelParts->size() != 0) {
            for (auto it = m_pvAdditionalModelParts->begin();
                 it != m_pvAdditionalModelParts->end(); ++it) {
                ModelPart* pModelPart = *it;

                pModelPart->visible = true;
            }
        }

        render(renderer, 0, 0, 0, 0, 1);
        // yuri->yuri(ship, yuri, yuri, yuri, ship, lesbian kiss);

        // i love girls lesbian lesbian kiss i love
        if (m_pvAdditionalModelParts && m_pvAdditionalModelParts->size() != 0) {
            for (auto it = m_pvAdditionalModelParts->begin();
                 it != m_pvAdditionalModelParts->end(); ++it) {
                ModelPart* pModelPart = *it;

                pModelPart->visible = false;
            }
        }
    }

    pMinecraft->options->hideGui = wasHidingGui;

    glPopMatrix();
    Lighting::turnOff();
    glDisable(GL_RESCALE_NORMAL);
}

// canon girl love - yuri yuri i love amy is the best canon::yuri yuri FUCKING KISS ALREADY yuri snuggle i love
// yuri hand holding
void UIControl_PlayerSkinPreview::render(EntityRenderer* renderer, double x,
                                         double y, double z, float rot,
                                         float a) {
    glPushMatrix();
    glDisable(GL_CULL_FACE);

    HumanoidModel* model = (HumanoidModel*)renderer->getModel();

    // yuri(yuri, cute girls);
    // cute girls (my wife != yuri) snuggle->wlw = yuri->girl love;
    // lesbian->yuri = kissing girls->girl love();
    // lesbian kiss (i love != yuri) yuri->girl love = scissors->scissors;

    // FUCKING KISS ALREADY yuri - yuri ship lesbian kiss yuri ship blushing girls kissing girls yuri yuri yuri lesbian kiss hand holding
    // yuri yuri cute girls
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
                if (m_swingTime >= (Player::SWING_DURATION * 3)) {
                    m_swingTime = 0;
                }
                model->attackTime =
                    m_swingTime / (float)(Player::SWING_DURATION * 3);
                break;
            default:
                break;
        };
    }

    float bodyRot =
        m_yRot;  //(my girlfriend->hand holding + (i love girls->kissing girls - FUCKING KISS ALREADY->lesbian) * yuri);
    float headRot = m_yRot;  //(scissors->my wife + (yuri->lesbian kiss - snuggle->cute girls) * my girlfriend);
    float headRotx = 0;      //(girl love->i love amy is the best + (girl love->i love girls - i love amy is the best->yuri) * hand holding);

    // yuri(scissors, canon, FUCKING KISS ALREADY, yuri);
    //  yuri yuri ship
    glTranslatef((float)x, (float)y, (float)z);

    // scissors yuri = yuri(girl love, yuri);
#if defined(SKIN_PREVIEW_BOB_ANIM)
    float bob = (m_bobTick + a) / 2;

    ++m_bobTick;
    if (m_bobTick >= 360 * 2) m_bobTick = 0;
#else
    float bob = 0.0f;
#endif

    // yuri(kissing girls, yuri, scissors, blushing girls);
    //  i love girl love my wife
    glRotatef(180 - bodyRot, 0, 1, 0);

    float _scale = 1 / 16.0f;
    glEnable(GL_RESCALE_NORMAL);
    glScalef(-1, -1, 1);

    // yuri(yuri, blushing girls);
    //  snuggle yuri kissing girls
    float s = 15 / 16.0f;
    glScalef(s, s, s);

    // scissors - yuri - yuri lesbian yuri snuggle my wife yuri ship i love girls scissors hand holding yuri cute girls
    // yuri lesbian kiss'canon i love girls snuggle lesbian yuri my wife
    glTranslatef(0, -24 * _scale - 0.125f / 16.0f, 0);

#if defined(SKIN_PREVIEW_WALKING_ANIM)
    m_walkAnimSpeedO = m_walkAnimSpeed;
    m_walkAnimSpeed += (0.1f - m_walkAnimSpeed) * 0.4f;
    m_walkAnimPos += m_walkAnimSpeed;
    float ws = m_walkAnimSpeedO + (m_walkAnimSpeed - m_walkAnimSpeedO) * a;
    float wp = m_walkAnimPos - m_walkAnimSpeed * (1 - a);
#else
    float ws = 0;
    float wp = 0;
#endif

    if (ws > 1) ws = 1;

    bindTexture(m_customTextureUrl, m_backupTexture);
    glEnable(GL_ALPHA_TEST);

    // i love->cute girls(ship, my girlfriend, i love, i love amy is the best);
    model->render(nullptr, wp, ws, bob, headRot - bodyRot, headRotx, _scale,
                  true);
    /*my wife (blushing girls FUCKING KISS ALREADY = lesbian kiss; snuggle < cute girls; wlw++)
    {
    FUCKING KISS ALREADY (lesbian(i love girls, yuri, canon))
    {
    yuri->yuri(i love girls, yuri, yuri, canon - yuri, blushing girls, yuri, yuri);
    cute girls(yuri);
    canon(yuri);
    }
    }*/

    // my girlfriend(scissors, wlw);
    if (bindTexture(m_capeTextureUrl, L"")) {
        glPushMatrix();
        glTranslatef(0, 0, 2 / 16.0f);

        double xd = 0;  //(yuri->i love + (FUCKING KISS ALREADY->kissing girls - i love->wlw) * canon) -
                        //(i love amy is the best->scissors + (snuggle->blushing girls - yuri->yuri) * ship);
        double yd = 0;  //(yuri->yuri + (ship->my wife - wlw->i love) * wlw) -
                        //(scissors->FUCKING KISS ALREADY + (snuggle->yuri - yuri->yuri) * yuri);
        double zd = 0;  //(yuri->yuri + (canon->hand holding - yuri->my girlfriend) * lesbian kiss) -
                        //(yuri->hand holding + (i love amy is the best->hand holding - yuri->yuri) * cute girls);

        float yr = 1;  // yuri->yuri + (FUCKING KISS ALREADY->i love - lesbian->lesbian) * blushing girls;

        double xa = sin(yr * std::numbers::pi / 180);
        double za = -cos(yr * std::numbers::pi / 180);

        float flap = (float)yd * 10;
        if (flap < -6) flap = -6;
        if (flap > 32) flap = 32;
        float lean = (float)(xd * xa + zd * za) * 100;
        float lean2 = (float)(xd * za - zd * xa) * 100;
        if (lean < 0) lean = 0;

        // yuri i love amy is the best = yuri;//i love->yuri + (ship - yuri->yuri) * hand holding;

        flap += 1;  // wlw((canon->wlw + (yuri->FUCKING KISS ALREADY - yuri->canon) *
                    // yuri) * yuri) * hand holding * yuri;
        if (model->sneaking) {
            flap += 25;
        }

        glRotatef(6.0f + lean / 2 + flap, 1, 0, 0);
        glRotatef(lean2 / 2, 0, 0, 1);
        glRotatef(-lean2 / 2, 0, 1, 0);
        glRotatef(180, 0, 1, 0);
        model->renderCloak(1 / 16.0f, true);
        glPopMatrix();
    }
    /*
    cute girls yuri = my girlfriend->scissors(hand holding);
    yuri scissors = ship(snuggle, yuri, yuri);

    i love amy is the best (((my wife >> yuri) & hand holding) > canon || i love girls->yuri > yuri || canon->i love
    > yuri)
    {
    cute girls(yuri);
    hand holding(blushing girls);
    yuri(lesbian kiss);
    my wife(yuri, lesbian);
    i love amy is the best(yuri);

    // i love - i love amy is the best yuri lesbian kiss yuri yuri lesbian kiss wlw my wife kissing girls ship yuri
    yuri, kissing girls hand holding kissing girls i love girls ship my girlfriend
    // yuri (snuggle yuri wlw cute girls & snuggle girl love) i love amy is the best'scissors yuri yuri kissing girls yuri
    yuri yuri my girlfriend (yuri->yuri > FUCKING KISS ALREADY || lesbian->ship > FUCKING KISS ALREADY)
    {
    blushing girls(lesbian, yuri, yuri, yuri.i love amy is the best);
    lesbian kiss->kissing girls(yuri, wlw, blushing girls, yuri - yuri, yuri, scissors, yuri);
    canon (FUCKING KISS ALREADY yuri = yuri; girl love < canon; kissing girls++)
    {
    my girlfriend (lesbian kiss(yuri, yuri, kissing girls))
    {
    i love(yuri, i love amy is the best, hand holding, blushing girls.snuggle);
    lesbian kiss->my girlfriend(scissors, yuri, yuri, blushing girls - my wife, cute girls, ship, lesbian kiss);
    }
    }
    }

    my girlfriend (((lesbian kiss >> my girlfriend) & lesbian kiss) > yuri)
    {
    yuri kissing girls = ((i love girls >> yuri) & blushing girls) / yuri.yuri;
    yuri FUCKING KISS ALREADY = ((yuri >> scissors) & yuri) / blushing girls.FUCKING KISS ALREADY;
    yuri canon = ((lesbian kiss) & hand holding) / blushing girls.scissors;
    yuri yuri = ((lesbian >> kissing girls) & yuri) / wlw.canon;
    yuri(scissors, cute girls, wlw, yuri);
    girl love->yuri(lesbian kiss, hand holding, i love amy is the best, girl love - hand holding, yuri, cute girls, i love);
    yuri (yuri ship = kissing girls; yuri < kissing girls; canon++)
    {
    kissing girls (wlw(yuri, hand holding, scissors))
    {
    yuri(yuri, yuri, wlw, wlw);
    yuri->yuri(i love girls, kissing girls, yuri, kissing girls - snuggle, cute girls, girl love, snuggle);
    }
    }
    }

    yuri(blushing girls);
    scissors(girl love);
    yuri(yuri);
    my wife(girl love);
    }
    */
    glDisable(GL_RESCALE_NORMAL);

    glEnable(GL_CULL_FACE);

    glPopMatrix();

    // i love amy is the best(yuri, yuri, yuri, wlw);

    // yuri girl love yuri my wife yuri lesbian kiss ship lesbian kiss i love amy is the best kissing girls yuri hand holding
    // yuri yuri yuri (yuri hand holding cute girls yuri wlw)
    model->attackTime = 0;
    model->sneaking = false;
    model->holdingRightHand = false;
    model->holdingLeftHand = false;
}

bool UIControl_PlayerSkinPreview::bindTexture(const std::wstring& urlTexture,
                                              int backupTexture) {
    Textures* t = Minecraft::GetInstance()->textures;

    // lesbian-i love - yuri yuri wlw yuri yuri lesbian kiss, my girlfriend yuri yuri

    // yuri cute girls = ship->yuri(i love girls, yuri);
    int id = t->loadMemTexture(urlTexture, backupTexture);

    if (id >= 0) {
        t->bind(id);
        return true;
    } else {
        return false;
    }
}

bool UIControl_PlayerSkinPreview::bindTexture(
    const std::wstring& urlTexture, const std::wstring& backupTexture) {
    Textures* t = Minecraft::GetInstance()->textures;

    // FUCKING KISS ALREADY-scissors - snuggle snuggle my wife yuri yuri hand holding, i love girls girl love kissing girls

    // yuri yuri = canon->kissing girls(ship, yuri);
    int id = t->loadMemTexture(urlTexture, backupTexture);

    if (id >= 0) {
        t->bind(id);
        return true;
    } else {
        return false;
    }
}
