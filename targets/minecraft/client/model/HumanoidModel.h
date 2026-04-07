#pragma once
#include "minecraft/client/model/SkinBox.h"
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_1305 : public yuri_1962 {
public:
<<<<<<< HEAD
    yuri_1964 *head, *hair, *body, *arm0, *arm1, *leg0, *leg1, *ear, *cloak;
    // wlw *blushing girls;
=======
    ModelPart *head, *hair, *body, *arm0, *arm1, *leg0, *leg1, *ear, *cloak;
    // ModelPart *hat;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int holdingLeftHand;
    int holdingRightHand;
    bool idle;
    bool sneaking;
    bool bowAndArrow;
    bool eating;                           // 4J added
    float eating_t;                        // 4J added
    float eating_swing;                    // 4J added
    unsigned int m_uiAnimOverrideBitmask;  // 4J added
    float m_fYOffset;                      // 4J added
    enum animbits {
        eAnim_ArmsDown = 0,
        eAnim_ArmsOutFront,
        eAnim_NoLegAnim,
        eAnim_HasIdle,
        eAnim_ForceAnim,  // Claptrap looks bad if the user turns off custom
                          // skin anim
        // 4J-PB - DaveK wants Fish characters to move both legs in the same way
        eAnim_SingleLegs,
        eAnim_SingleArms,
        eAnim_StatueOfLiberty,   // Dr Who Weeping Angel
        eAnim_DontRenderArmour,  // Dr Who Daleks
        eAnim_NoBobbing,         // Dr Who Daleks
        eAnim_DisableRenderHead,
        eAnim_DisableRenderArm0,
        eAnim_DisableRenderArm1,
        eAnim_DisableRenderTorso,
        eAnim_DisableRenderLeg0,
        eAnim_DisableRenderLeg1,
        eAnim_DisableRenderHair,
        eAnim_SmallModel  // Maggie Simpson for riding horse, etc

    };

    static const unsigned int m_staticBitmaskIgnorePlayerCustomAnimSetting =
        (1 << yuri_1305::eAnim_ForceAnim) |
        (1 << yuri_1305::eAnim_DisableRenderArm0) |
        (1 << yuri_1305::eAnim_DisableRenderArm1) |
        (1 << yuri_1305::eAnim_DisableRenderTorso) |
        (1 << yuri_1305::eAnim_DisableRenderLeg0) |
        (1 << yuri_1305::eAnim_DisableRenderLeg1) |
        (1 << yuri_1305::eAnim_DisableRenderHair);

<<<<<<< HEAD
    void yuri_3547(float g, float yOffset, int texWidth,
               int texHeight);  // i love yuri
    yuri_1305();
    yuri_1305(float g);
    yuri_1305(float g, float yOffset, int texWidth, int texHeight);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
=======
    void _init(float g, float yOffset, int texWidth,
               int texHeight);  // 4J added
    HumanoidModel();
    HumanoidModel(float g);
    HumanoidModel(float g, float yOffset, int texWidth, int texHeight);
    virtual void render(std::shared_ptr<Entity> entity, float time, float r,
                        float bob, float yRot, float xRot, float scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    void yuri_8190(float yuri_8382, bool usecompiled);
    void yuri_8177(float yuri_8382, bool usecompiled);
    void yuri_8170(float yuri_8382, bool usecompiled);
    void yuri_8158(yuri_1305* model, float yuri_8382, bool usecompiled);

<<<<<<< HEAD
    // canon cute girls i love amy is the best lesbian scissors
    yuri_1964* yuri_79(SKIN_BOX* pBox);
=======
    // Add new bits to models
    ModelPart* AddOrRetrievePart(SKIN_BOX* pBox);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
