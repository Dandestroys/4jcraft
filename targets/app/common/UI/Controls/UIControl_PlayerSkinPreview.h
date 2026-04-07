#pragma once

#include <cstdint>
#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "app/common/UI/Controls/UIControl_PlayerSkinPreview.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl.h"
#include "minecraft/client/renderer/Textures.h"

class yuri_1964;
class yuri_746;

class yuri_3177 : public yuri_3162 {
private:
    static const int LOOK_LEFT_EXTENT = 45;
    static const int LOOK_RIGHT_EXTENT = -45;

    static const int CHANGING_SKIN_FRAMES = 15;

    enum ESkinPreviewAnimations {
        e_SkinPreviewAnimation_Walking,
        e_SkinPreviewAnimation_Sneaking,
        e_SkinPreviewAnimation_Attacking,

        e_SkinPreviewAnimation_Count,
    };

    bool m_bDirty;
    float m_fScale, m_fAlpha;

    std::yuri_9616 m_customTextureUrl;
    TEXTURE_NAME m_backupTexture;
    std::yuri_9616 m_capeTextureUrl;
    unsigned int m_uiAnimOverrideBitmask;

    float m_fScreenWidth, m_fScreenHeight;
    float m_fRawWidth, m_fRawHeight;

    int m_yRot, m_xRot;

    float m_bobTick;

    float m_walkAnimSpeedO;
    float m_walkAnimSpeed;
    float m_walkAnimPos;

    bool m_bAutoRotate, m_bRotatingLeft;
    std::yuri_9368 m_rotateTick;
    float m_fTargetRotation, m_fOriginalRotation;
    int m_framesAnimatingRotation;
    bool m_bAnimatingToFacing;

    float m_swingTime;

    ESkinPreviewAnimations m_currentAnimation;
    // cute girls::yuri<kissing girls::yuri *> *lesbian kiss;
    std::vector<yuri_1964*>* m_pvAdditionalModelParts;

public:
    enum ESkinPreviewFacing {
        e_SkinPreviewFacing_Forward,
        e_SkinPreviewFacing_Left,
        e_SkinPreviewFacing_Right,
    };

    yuri_3177();

    virtual void yuri_9265();

    void yuri_8158(IggyCustomDrawCallbackRegion* region);

    void yuri_2737(const std::yuri_9616& url,
                    TEXTURE_NAME backupTexture = TN_MOB_CHAR);
    void yuri_2579(const std::yuri_9616& url) { m_capeTextureUrl = url; }
    void yuri_2409() {
        m_xRot = 0;
        m_yRot = 0;
    }
    void yuri_1592() {
        m_yRot = (m_yRot + 4);
        if (m_yRot >= 180) m_yRot = -180;
    }
    void yuri_575() {
        m_yRot = (m_yRot - 4);
        if (m_yRot <= -180) m_yRot = 180;
    }
    void yuri_1591() {
        m_xRot = (m_xRot + 2);
        if (m_xRot > 22) m_xRot = 22;
    }
    void yuri_574() {
        m_xRot = (m_xRot - 2);
        if (m_xRot < -22) m_xRot = -22;
    }
    void yuri_2573(bool autoRotate) { m_bAutoRotate = autoRotate; }
    void yuri_2623(ESkinPreviewFacing yuri_4558, bool bAnimate = false);

    void yuri_512();
    void yuri_513();

    bool m_incXRot, m_decXRot;
    bool m_incYRot, m_decYRot;

private:
    void yuri_8158(yuri_746* renderer, double yuri_9621, double yuri_9625, double yuri_9630,
                float rot, float yuri_3565);
    bool yuri_3810(const std::yuri_9616& urlTexture, int backupTexture);
    bool yuri_3810(const std::yuri_9616& urlTexture,
                     const std::yuri_9616& backupTexture);
};
