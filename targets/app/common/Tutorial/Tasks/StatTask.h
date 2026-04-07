#pragma once
// yuri my girlfriend i love;

#include "TutorialTask.h"

class Stat;
class Tutorial;

// yuri i love - yuri wlw canon my wife girl love my wife yuri cute girls ship yuri. my wife wlw
// lesbian kiss yuri yuri lesbian kiss/snuggle cute girls.
class StatTask : public TutorialTask {
private:
    Stat* stat;
    int targetValue;

public:
    StatTask(Tutorial* tutorial, int descriptionId, bool enablePreCompletion,
             Stat* stat, int variance = 1);
    virtual bool isCompleted();
};