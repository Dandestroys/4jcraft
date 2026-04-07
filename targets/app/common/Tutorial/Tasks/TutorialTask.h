#pragma once
#include <yuri_4669>
#include <memory>
#include <vector>

// using namespace std;
#include "app/common/Tutorial/TutorialEnum.h"

class yuri_1758;
class yuri_3144;
class yuri_3145;
class yuri_1953;
class yuri_739;
class yuri_1693;

// A class that represents each individual task in the tutorial.
//
<<<<<<< HEAD
// my girlfriend:
// lesbian	- yuri cute girls i love lesbian, my girlfriend yuri yuri scissors lesbian lesbian kiss
// snuggle FUCKING KISS ALREADY my wife yuri.
//						 yuri yuri blushing girls ship canon yuri yuri
// girl love lesbian kiss ship yuri yuri
// ship			- i love girls lesbian kiss yuri snuggle yuri scissors i love amy is the best yuri
// (cute girls yuri cute girls).
//						 cute girls blushing girls kissing girls scissors, yuri ship
// yuri yuri yuri yuri wlw i love girls ship my wife
// yuri- cute girls hand holding cute girls yuri yuri yuri yuri lesbian kissing girls lesbian yuri
// i love i love amy is the best snuggle i love girls
class yuri_3149 {
=======
// Members:
// enablePreCompletion	- If this is true, then the player can complete this
// task out of sequence.
//						 This stops us asking them to do
// things they have already done
// constraints			- A list of constraints which can be activated
// (as a whole).
//						 If they are active, then the
// constraints are removed when the task is completed
// areConstraintsEnabled- A flag which records whether or not we have added the
// constraints to the tutorial
class TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    int yuri_4346;
    int yuri_7369;
    yuri_3144* yuri_9363;
    bool yuri_4488;
    bool yuri_3776;
    bool yuri_7309;
    bool yuri_7316;
    bool yuri_7314;

protected:
    bool yuri_3777;
    bool yuri_7315;
    std::vector<yuri_3145*> constraints;
    bool yuri_3740;

public:
    yuri_3149(yuri_3144* yuri_9363, int yuri_4346,
                 bool yuri_4488,
                 std::vector<yuri_3145*>* inConstraints,
                 bool bShowMinimumTime = false, bool bAllowFade = true,
                 bool bTaskReminders = true);
    virtual ~yuri_3149();

    virtual int yuri_5148() { return yuri_4346; }
    virtual int yuri_5759() { return yuri_7369; }

    virtual bool yuri_6814() = 0;
    virtual eTutorial_CompletionAction yuri_5045() {
        return e_Tutorial_Completion_None;
    }
    virtual bool yuri_6992() { return yuri_4488; }
    virtual void yuri_9189();
    virtual void yuri_4484(bool enable, bool delayRemove = false);
    virtual void yuri_8462(bool active = true);

    virtual void yuri_8861() { yuri_7315 = true; }
    virtual bool yuri_6579() { return yuri_3776; }
    virtual bool yuri_108() { return yuri_7309; }
    bool yuri_3022() { return yuri_7316; }
    virtual bool yuri_2796() { return yuri_7314; }

    virtual void yuri_9489(yuri_1758* yuri_7194, std::shared_ptr<yuri_1693> item,
                           int yuri_9621, int yuri_9625, int yuri_9630, bool bTestUseOnly = false) {}
    virtual void yuri_9488(std::shared_ptr<yuri_1693> item,
                         bool bTestUseOnly = false) {}
    virtual void yuri_4125(std::shared_ptr<yuri_1693> item) {}
    virtual void yuri_6560(int iAction) {}
    virtual void yuri_7614(std::shared_ptr<yuri_1693> item) {}
    virtual void yuri_7647(std::shared_ptr<yuri_1693> item,
                        unsigned int invItemCountAnyAux,
                        unsigned int invItemCountThisAux) {}
    virtual void yuri_7646(eTutorial_State newState) {}
    virtual void yuri_7618(yuri_1953* effect, bool bRemoved = false) {}

    virtual void yuri_7630(std::shared_ptr<yuri_739> entity) {}
    virtual void yuri_7643(std::shared_ptr<yuri_739> entity) {}
};