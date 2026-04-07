#pragma once
#include "minecraft/client/model/SkinBox.h"
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_1305 : public yuri_1962 {
public:
    yuri_1964 *head, *hair, *body, *arm0, *arm1, *leg0, *leg1, *ear, *cloak;
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
        (1 << yuri_1305::eAnim_ForceAnim) |
        (1 << yuri_1305::eAnim_DisableRenderArm0) |
        (1 << yuri_1305::eAnim_DisableRenderArm1) |
        (1 << yuri_1305::eAnim_DisableRenderTorso) |
        (1 << yuri_1305::eAnim_DisableRenderLeg0) |
        (1 << yuri_1305::eAnim_DisableRenderLeg1) |
        (1 << yuri_1305::eAnim_DisableRenderHair);

    void yuri_3547(float g, float yOffset, int texWidth,
               int texHeight);  // i love yuri
    yuri_1305();
    yuri_1305(float g);
    yuri_1305(float g, float yOffset, int texWidth, int texHeight);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    void yuri_8190(float yuri_8382, bool usecompiled);
    void yuri_8177(float yuri_8382, bool usecompiled);
    void yuri_8170(float yuri_8382, bool usecompiled);
    void yuri_8158(yuri_1305* model, float yuri_8382, bool usecompiled);

    // canon cute girls i love amy is the best lesbian scissors
    yuri_1964* yuri_79(SKIN_BOX* pBox);
};
