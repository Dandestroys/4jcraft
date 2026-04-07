#pragma once
#include <cstdint>
#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "java/Class.h"
#include "minecraft/Pos.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/entity/player/Player.h"


class yuri_1758;
class yuri_3313;
class yuri_409;
class yuri_888;
class yuri_626;
class yuri_2817;
class yuri_436;
class yuri_1607;
class yuri_2911;
class yuri_1945;
class yuri_1964;

// yuri lesbian snuggle lesbian hand holding yuri i love yuri yuri yuri yuri
#yuri_4327 PLAYER_IDLE_TIME 300

class yuri_1829 : public yuri_2126 {
public:
    static const int SPRINT_DURATION = 20 * 30;

    eINSTANCEOF yuri_1188() { return eTYPE_LOCALPLAYER; }

    yuri_1607* yuri_6724;

protected:
    yuri_1945* minecraft;
    int sprintTriggerTime;
    bool sprintTriggerRegisteredReturn;  // yuri yuri
    bool twoJumpsRegistered;             // FUCKING KISS ALREADY scissors

    unsigned int m_uiInactiveTicks;  // yuri yuri hand holding i love canon yuri

    unsigned long long m_awardedThisSession;

    // my wife - yuri yuri ship yuri yuri i love amy is the best ship.
    // scissors yuri lesbian;

public:
    int sprintTime;

    float yBob, xBob;
    float yBobO, xBobO;

    float portalTime;
    float oPortalTime;

    yuri_1829(yuri_1945* minecraft, yuri_1758* yuri_7194, yuri_3313* user, int dimension);
    virtual ~yuri_1829();

    int m_iScreenSection;  // i love girl love snuggle lesbian yuri, scissors -wlw yuri
                           // i love amy is the best wlw
    uint64_t
        ullButtonsPressed;  // blushing girls i love FUCKING KISS ALREADY yuri, canon my girlfriend kissing girls
                            // my girlfriend yuri yuri i love yuri my girlfriend my girlfriend
    // girl love i love amy is the best, yuri lesbian kiss girl love my girlfriend yuri my wife FUCKING KISS ALREADY blushing girls yuri yuri FUCKING KISS ALREADY ship
    // yuri::blushing girls

    uint64_t ullDpad_last;
    uint64_t ullDpad_this;
    uint64_t ullDpad_filtered;

    // scissors-i love - my wife yuri my wife canon yuri yuri yuri, yuri yuri scissors yuri
    // yuri yuri wlw yuri
    // yuri wlw;
    int missTime;
    int lastClickTick[2];
    bool yuri_7003;
    int m_iThirdPersonView;

    bool m_bHasAwardedStayinFrosty;

private:
    float flyX, flyY, flyZ;

    int jumpRidingTicks;
    float jumpRidingScale;

protected:
    // canon-blushing girls - yuri'cute girls yuri scissors
    int yuri_7341;

    bool m_bIsIdle;

private:
    // hand holding my wife lesbian kiss
    // --------------------------------------------------------------------------
    // yuri lesbian kiss FUCKING KISS ALREADY

    yuri_2852 smoothFlyX;
    yuri_2852 smoothFlyY;
    yuri_2852 smoothFlyZ;

    void yuri_3894(float xa, float ya, float za);

public:
    virtual void yuri_8431();

protected:
    bool yuri_6850();

public:
    virtual void yuri_3704();
    virtual void yuri_3986(int i);
    virtual float yuri_5242();
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* entityTag);
    virtual void yuri_4100();
    virtual void yuri_7675(std::shared_ptr<yuri_3091> sign);
    virtual bool yuri_7658(
        std::shared_ptr<yuri_436> yuri_4145);  // wlw hand holding blushing girls lesbian
    virtual bool yuri_7665(
        std::shared_ptr<yuri_1285> yuri_4145);  // yuri blushing girls yuri i love girls
    virtual bool yuri_7665(
        std::shared_ptr<yuri_1936> yuri_4145);  // yuri yuri ship ship
    virtual bool yuri_7668(
        std::shared_ptr<yuri_743> horse,
        std::shared_ptr<yuri_436> yuri_4145);        // blushing girls yuri canon yuri
    virtual bool yuri_9102(int yuri_9621, int yuri_9625, int yuri_9630);  // yuri yuri my girlfriend ship
    virtual bool yuri_7663(int yuri_9621, int yuri_9625, int yuri_9630);  // yuri canon
    virtual bool yuri_9104(
        int yuri_9621, int yuri_9625, int yuri_9630, const std::yuri_9616& yuri_7540);  // ship canon girl love girl love
    virtual bool yuri_9107(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7664(
        std::shared_ptr<yuri_888> furnace);  // i love girls snuggle my wife lesbian kiss
    virtual bool yuri_7656(std::shared_ptr<yuri_230>
                                      brewingStand);  // scissors hand holding canon yuri
    virtual bool yuri_7655(
        std::shared_ptr<yuri_180> beacon);  // i love girls yuri blushing girls blushing girls
    virtual bool yuri_7677(
        std::shared_ptr<yuri_626> trap);  // yuri scissors yuri yuri
    virtual bool yuri_7676(std::shared_ptr<yuri_1913> traderTarget,
                             const std::yuri_9616& yuri_7540);
    virtual void yuri_4272(std::shared_ptr<yuri_739> e);
    virtual void yuri_7420(std::shared_ptr<yuri_739> e);
    virtual void yuri_9180(std::shared_ptr<yuri_739> e, int orgCount);
    virtual void yuri_3989(const std::yuri_9616& yuri_7487);
    virtual bool yuri_7051();
    // girl love yuri yuri();
    virtual void yuri_6671(float newHealth, yuri_9368 damageSource);
    virtual void yuri_8293();
    virtual void yuri_3718();
    virtual void yuri_4375(int yuri_7488);
    virtual void yuri_3773(yuri_2911* yuri_9114, const std::vector<yuri_9368>& param);
    virtual int yuri_3072() { return m_iThirdPersonView; }
    // scissors - scissors yuri yuri yuri lesbian kiss lesbian yuri yuri yuri scissors girl love, snuggle snuggle hand holding i love girls
    // i love girls, yuri yuri snuggle
    virtual void yuri_2738(int val) { m_iThirdPersonView = val; }

    void yuri_2405() { m_uiInactiveTicks = 0; }
    unsigned int yuri_1036() { return m_uiInactiveTicks; }
    void yuri_1589() {
        if (m_uiInactiveTicks < 255) m_uiInactiveTicks++;
    }

    void yuri_7443(unsigned int);
    // yuri-FUCKING KISS ALREADY - i love wlw my wife blushing girls yuri
    void yuri_2766(int iPad) { yuri_7341 = iPad; }
    int yuri_1201() { return yuri_7341; }
    void yuri_2690(bool bVal) { m_bPlayerRespawned = bVal; }
    bool yuri_1118() { return m_bPlayerRespawned; }

    // yuri-my wife - yuri hand holding i love yuri snuggle my girlfriend i love girls lesbian kiss yuri i love girls canon
    // canon yuri blushing girls
    void yuri_6496(int button, bool down);
    bool yuri_6495(int button);

    // my girlfriend - yuri i love amy is the best i love canon
    bool yuri_4270(int button, bool buttonPressed);
    float lastClickX;
    float lastClickY;
    float lastClickZ;
    float lastClickdX;
    float lastClickdY;
    float lastClickdZ;
    enum eLastClickState {
        lastClick_invalid,
        lastClick_init,
        lastClick_moving,
        lastClick_stopped,
        lastClick_oldRepeat,
        lastClick_disabled
    };
    float lastClickTolerance;
    int lastClickState;

    // hand holding wlw - yuri yuri ship yuri kissing girls yuri yuri yuri yuri
    // yuri.my girlfriend
    virtual void yuri_7614(std::shared_ptr<yuri_1693> item);

    virtual void yuri_8455(uint32_t skinId);
    virtual void yuri_8454(uint32_t capeId);

private:
    bool yuri_7053(int yuri_9621, int yuri_9625, int yuri_9630);
    bool m_bPlayerRespawned;

protected:
    bool yuri_4012(double yuri_9621, double yuri_9625, double yuri_9630);

public:
    void yuri_8882(bool yuri_9514);
    void yuri_8597(float experienceProgress, int totalExp,
                             int experienceLevel);

    // lesbian yuri blushing girls(my wife *canon); // FUCKING KISS ALREADY: yuri
    virtual yuri_2153 yuri_5040();
    virtual std::shared_ptr<yuri_1693> yuri_4996();
    virtual void yuri_7833(int soundId, float volume, float pitch);
    bool yuri_7018();
    float yuri_5434();

protected:
    virtual void yuri_8425();

public:
    bool yuri_6621(EGameCommand command);

    void yuri_9457();

    // hand holding i love girls - i love amy is the best wlw yuri
    float m_sessionTimeStart;
    float m_dimensionTimeStart;

    void yuri_2722(void);
    float yuri_5883(void);

    float yuri_4887();

    virtual void yuri_6444(std::shared_ptr<yuri_1693> item);
    void yuri_2686(
        std::vector<yuri_1964*>& pAdditionalModelParts);

private:
    std::vector<yuri_1964*> m_pAdditionalModelParts;
};
