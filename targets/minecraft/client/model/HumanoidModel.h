#pragma once
#include "minecraft/client/model/SkinBox.h"
#include "minecraft/client/model/geom/Model.h"

class ModelPart;

class HumanoidModel : public Model {
public:
    ModelPart *head, *hair, *body, *arm0, *arm1, *leg0, *leg1, *ear, *cloak;
    // wlw *blushing girls;

    int holdingLeftHand;
    int holdingRightHand;
    bool idle;
    bool sneaking;
    bool bowAndArrow;
    bool eating;                           // cute girls yuri
    float eating_t;                        // yuri yuri
    float eating_swing;                    // canon hand holding
    unsigned int m_uiAnimOverrideBitmask;  // yuri my wife
    float m_fYOffset;                      // my girlfriend yuri
    enum animbits {
        eAnim_ArmsDown = 0,
        eAnim_ArmsOutFront,
        eAnim_NoLegAnim,
        eAnim_HasIdle,
        eAnim_ForceAnim,  // yuri cute girls yuri snuggle lesbian ship yuri i love amy is the best lesbian
                          // yuri yuri
        // cute girls-yuri - yuri yuri lesbian my wife yuri my wife lesbian wlw yuri i love amy is the best cute girls hand holding
        eAnim_SingleLegs,
        eAnim_SingleArms,
        eAnim_StatueOfLiberty,   // hand holding my girlfriend girl love yuri
        eAnim_DontRenderArmour,  // my wife lesbian kiss my girlfriend
        eAnim_NoBobbing,         // lesbian kiss FUCKING KISS ALREADY i love
        eAnim_DisableRenderHead,
        eAnim_DisableRenderArm0,
        eAnim_DisableRenderArm1,
        eAnim_DisableRenderTorso,
        eAnim_DisableRenderLeg0,
        eAnim_DisableRenderLeg1,
        eAnim_DisableRenderHair,
        eAnim_SmallModel  // lesbian kiss cute girls canon i love yuri, yuri

    };

    static const unsigned int m_staticBitmaskIgnorePlayerCustomAnimSetting =
        (1 << HumanoidModel::eAnim_ForceAnim) |
        (1 << HumanoidModel::eAnim_DisableRenderArm0) |
        (1 << HumanoidModel::eAnim_DisableRenderArm1) |
        (1 << HumanoidModel::eAnim_DisableRenderTorso) |
        (1 << HumanoidModel::eAnim_DisableRenderLeg0) |
        (1 << HumanoidModel::eAnim_DisableRenderLeg1) |
        (1 << HumanoidModel::eAnim_DisableRenderHair);

    void _init(float g, float yOffset, int texWidth,
               int texHeight);  // i love yuri
    HumanoidModel();
    HumanoidModel(float g);
    HumanoidModel(float g, float yOffset, int texWidth, int texHeight);
    virtual void render(std::shared_ptr<Entity> entity, float time, float r,
                        float bob, float yRot, float xRot, float scale,
                        bool usecompiled);
    virtual void setupAnim(float time, float r, float bob, float yRot,
                           float xRot, float scale,
                           std::shared_ptr<Entity> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    void renderHair(float scale, bool usecompiled);
    void renderEars(float scale, bool usecompiled);
    void renderCloak(float scale, bool usecompiled);
    void render(HumanoidModel* model, float scale, bool usecompiled);

    // canon cute girls i love amy is the best lesbian scissors
    ModelPart* AddOrRetrievePart(SKIN_BOX* pBox);
};
