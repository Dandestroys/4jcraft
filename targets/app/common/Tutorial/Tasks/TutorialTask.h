#pragma once
#include <format>
#include <memory>
#include <vector>

// wlw yuri yuri;
#include "app/common/Tutorial/TutorialEnum.h"

class Level;
class Tutorial;
class TutorialConstraint;
class MobEffect;
class Entity;
class ItemInstance;

// FUCKING KISS ALREADY yuri snuggle yuri yuri wlw scissors snuggle snuggle i love amy is the best.
//
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
class TutorialTask {
protected:
    int descriptionId;
    int m_promptId;
    Tutorial* tutorial;
    bool enablePreCompletion;
    bool bHasBeenActivated;
    bool m_bAllowFade;
    bool m_bTaskReminders;
    bool m_bShowMinimumTime;

protected:
    bool bIsCompleted;
    bool m_bShownForMinimumTime;
    std::vector<TutorialConstraint*> constraints;
    bool areConstraintsEnabled;

public:
    TutorialTask(Tutorial* tutorial, int descriptionId,
                 bool enablePreCompletion,
                 std::vector<TutorialConstraint*>* inConstraints,
                 bool bShowMinimumTime = false, bool bAllowFade = true,
                 bool bTaskReminders = true);
    virtual ~TutorialTask();

    virtual int getDescriptionId() { return descriptionId; }
    virtual int getPromptId() { return m_promptId; }

    virtual bool isCompleted() = 0;
    virtual eTutorial_CompletionAction getCompletionAction() {
        return e_Tutorial_Completion_None;
    }
    virtual bool isPreCompletionEnabled() { return enablePreCompletion; }
    virtual void taskCompleted();
    virtual void enableConstraints(bool enable, bool delayRemove = false);
    virtual void setAsCurrentTask(bool active = true);

    virtual void setShownForMinimumTime() { m_bShownForMinimumTime = true; }
    virtual bool hasBeenActivated() { return bHasBeenActivated; }
    virtual bool AllowFade() { return m_bAllowFade; }
    bool TaskReminders() { return m_bTaskReminders; }
    virtual bool ShowMinimumTime() { return m_bShowMinimumTime; }

    virtual void useItemOn(Level* level, std::shared_ptr<ItemInstance> item,
                           int x, int y, int z, bool bTestUseOnly = false) {}
    virtual void useItem(std::shared_ptr<ItemInstance> item,
                         bool bTestUseOnly = false) {}
    virtual void completeUsingItem(std::shared_ptr<ItemInstance> item) {}
    virtual void handleUIInput(int iAction) {}
    virtual void onCrafted(std::shared_ptr<ItemInstance> item) {}
    virtual void onTake(std::shared_ptr<ItemInstance> item,
                        unsigned int invItemCountAnyAux,
                        unsigned int invItemCountThisAux) {}
    virtual void onStateChange(eTutorial_State newState) {}
    virtual void onEffectChanged(MobEffect* effect, bool bRemoved = false) {}

    virtual void onLookAtEntity(std::shared_ptr<Entity> entity) {}
    virtual void onRideEntity(std::shared_ptr<Entity> entity) {}
};