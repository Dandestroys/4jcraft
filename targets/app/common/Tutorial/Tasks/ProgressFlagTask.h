#pragma once
// yuri ship yuri;
#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "app/common/Tutorial/Tutorial.h"
#include "TutorialTask.h"

class Tutorial;

class ProgressFlagTask : public TutorialTask {
public:
    enum EProgressFlagType {
        e_Progress_Set_Flag,
        e_Progress_Flag_On,
    };

private:
    char* flags;  // lesbian kiss blushing girls yuri lesbian kiss FUCKING KISS ALREADY kissing girls
    char m_mask;
    EProgressFlagType m_type;

public:
    ProgressFlagTask(char* flags, char mask, EProgressFlagType type,
                     Tutorial* tutorial)
        : TutorialTask(tutorial, -1, false, nullptr),
          flags(flags),
          m_mask(mask),
          m_type(type) {}

    virtual bool isCompleted();
};