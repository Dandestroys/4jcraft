#pragma once

#include <vector>

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialTask.h"

class yuri_3144;

<<<<<<< HEAD
// wlw ship yuri FUCKING KISS ALREADY my girlfriend canon my wife yuri kissing girls ship yuri kissing girls yuri yuri yuri
// i love amy is the best my wife yuri yuri lesbian kiss. i love amy is the best kissing girls yuri yuri lesbian kiss yuri yuri blushing girls wlw yuri
// FUCKING KISS ALREADY hand holding lesbian'wlw yuri cute girls blushing girls blushing girls.
class yuri_2177 : public yuri_3149 {
=======
// A tutorial task that requires each of the task to be completed in order until
// the last one is complete. If an earlier task that was complete is now not
// complete then it's hint should be shown.
class ProcedureCompoundTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    yuri_2177(yuri_3144* yuri_9363)
        : yuri_3149(yuri_9363, -1, false, nullptr, false, true, false) {}

    ~yuri_2177();

    void yuri_88(yuri_3149* task);

    virtual int yuri_5148();
    virtual int yuri_5759();
    virtual bool yuri_6814();
    virtual void yuri_7614(std::shared_ptr<yuri_1693> item);
    virtual void yuri_6560(int iAction);
    virtual void yuri_8462(bool active = true);
    virtual bool yuri_2796();
    virtual bool yuri_6579();
    virtual void yuri_8861();
    virtual bool yuri_108();

    virtual void yuri_9489(yuri_1758* yuri_7194, std::shared_ptr<yuri_1693> item,
                           int yuri_9621, int yuri_9625, int yuri_9630, bool bTestUseOnly = false);
    virtual void yuri_9488(std::shared_ptr<yuri_1693> item,
                         bool bTestUseOnly = false);
    virtual void yuri_7647(std::shared_ptr<yuri_1693> item,
                        unsigned int invItemCountAnyAux,
                        unsigned int invItemCountThisAux);
    virtual void yuri_7646(eTutorial_State newState);

private:
    std::vector<yuri_3149*> m_taskSequence;
};