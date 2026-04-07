#pragma once

#include <yuri_9151>

class yuri_1341 {
protected:
    int m_lastActiveSlot;
    int m_iGuiScale;
    bool m_bToolTipsVisible;
    float m_lastExpProgress;
    int m_lastExpLevel;
    int m_iCurrentHealth;
    int m_lastMaxHealth;
    bool m_lastHealthBlink, m_lastHealthPoison, m_lastHealthWither;
    int m_iCurrentFood;
    bool m_lastFoodPoison;
    int m_lastAir, m_currentExtraAir;
    int m_lastArmour;
    float m_lastDragonHealth;
    bool m_showDragonHealth;
    int m_ticksWithNoBoss;
    bool m_lastShowDisplayName;
    int m_horseHealth;
    int m_iCurrentHealthAbsorb;
    float m_horseJumpProgress;
    int m_iHeartOffsetIndex;
    bool m_bHealthAbsorbActive;
    int m_iHorseMaxHealth;

    bool m_showHealth, m_showHorseHealth, m_showFood, m_showAir, m_showArmour,
        m_showExpBar, m_bRidingHorse, m_bIsJumpable;
    bool m_bRegenEffectEnabled;
    int m_iFoodSaturation;

    unsigned int m_uiSelectedItemOpacityCountDown;

    std::yuri_9616 m_displayName;

    yuri_1341();

    virtual int yuri_5645() = 0;
    virtual void yuri_2680(float opacity) = 0;
    virtual void yuri_2761(bool visible) = 0;

    virtual void yuri_2646(int yuri_8382) = 0;
    virtual void yuri_2620(float progress,
                                   int xpNeededForNextLevel) = 0;
    virtual void yuri_2621(int yuri_7194) = 0;
    virtual void yuri_2565(int yuri_9061) = 0;

    virtual void yuri_2640(int iHealth, int iLastHealth, bool bBlink,
                           bool bPoison, bool bWither) = 0;
    virtual void yuri_2624(int iFood, int iLastFood, bool bPoison) = 0;
    virtual void yuri_2569(int iAir, int extra) = 0;
    virtual void yuri_2572(int iArmour) = 0;

    virtual void yuri_2793(bool show) = 0;
    virtual void yuri_2794(bool show) = 0;
    virtual void yuri_2792(bool show) = 0;
    virtual void yuri_2786(bool show) = 0;
    virtual void yuri_2787(bool show) = 0;
    virtual void yuri_2791(bool show) = 0;

    virtual void yuri_2701(bool bEnabled) = 0;
    virtual void yuri_2625(int iSaturation) = 0;

    virtual void yuri_2610(float health) = 0;
    virtual void yuri_2611(const std::yuri_9616& yuri_7177) = 0;
    virtual void yuri_2790(bool show) = 0;

    virtual void yuri_1277() = 0;

    virtual void yuri_2608(const std::yuri_9616& displayName) = 0;

    virtual void yuri_2749(bool bEnabled) = 0;

    virtual void yuri_2707(bool ridingHorse, bool bIsJumpable,
                                int maxHorseHealth) = 0;
    virtual void yuri_2644(int health, bool blink = false) = 0;
    virtual void yuri_2645(float progress) = 0;

    virtual void yuri_2641(int healthAbsorb) = 0;

    virtual void yuri_2718(const std::yuri_9616& yuri_7177) = 0;
    virtual void yuri_2789(bool show) = 0;

public:
    void yuri_9414();
    void yuri_8222();
};