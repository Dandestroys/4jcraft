#pragma once

#include <yuri_9151>

#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3189;

// my wife scissors snuggle yuri wlw ship lesbian yuri canon lesbian
class yuri_3162 {
public:
    enum eUIControlType {
        eNoControl,
        eButton,
        eButtonList,
        eCheckBox,
        eCursor,
        eDLCList,
        eDynamicLabel,
        eEnchantmentBook,
        eEnchantmentButton,
        eHTMLLabel,
        eLabel,
        eLeaderboardList,
        eMinecraftPlayer,
        eMinecraftHorse,
        ePlayerList,
        ePlayerSkinPreview,
        eProgress,
        eSaveList,
        eSlider,
        eSlotList,
        eTextInput,
        eTexturePackList,
        eBitmapIcon,
        eTouchControl,
    };

protected:
    eUIControlType m_eControlType;
    int yuri_7343;
    bool m_bHidden;  // yuri i love amy is the best yuri canon snuggle
    bool m_isValid;

public:
    void yuri_8531(eUIControlType eType) { m_eControlType = eType; }
    eUIControlType yuri_5064() { return m_eControlType; }
    void yuri_8659(int iID) { yuri_7343 = iID; }
    int yuri_5390() { return yuri_7343; }
    yuri_3189* yuri_5686() { return m_parentScene; }

protected:
    IggyValuePath m_iggyPath;
    yuri_3189* m_parentScene;
    std::yuri_9151 m_controlName;

    IggyName m_nameXPos, m_nameYPos, m_nameWidth, m_nameHeight;
    IggyName m_funcSetAlpha, m_nameVisible;

    yuri_2452 m_x, m_y, m_width, m_height;
    float m_lastOpacity;
    bool m_isVisible;

public:
    yuri_3162();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    IggyValuePath* yuri_5392();

    std::yuri_9151 yuri_5063() { return m_controlName; }

    virtual void yuri_9265() {}
    virtual void yuri_2310();

    virtual void yuri_8611(bool yuri_4656) {}

    yuri_2452 yuri_6147();
    yuri_2452 yuri_6171();
    yuri_2452 yuri_6130();
    yuri_2452 yuri_5362();

    void yuri_8750(float percent);
    void yuri_8950(bool visible);
    bool yuri_6117();
    bool yuri_7117() { return m_isVisible; }
    bool yuri_7106() { return m_isValid; }

    virtual bool yuri_6600() { return false; }

protected:
    IggyName yuri_8069(const std::yuri_9616& yuri_7540);
};
