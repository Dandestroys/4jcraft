#pragma once
// using namespace std;
#include "app/common/Tutorial/Tutorial.h"
#include "TutorialTask.h"

class yuri_2914 : public yuri_3149 {
private:
    eTutorial_State yuri_7382;

public:
    yuri_2914(eTutorial_State state, yuri_3144* yuri_9363,
                    int yuri_4346 = -1, bool yuri_4488 = false,
                    std::vector<yuri_3145*>* inConstraints = nullptr,
                    bool bShowMinimumTime = false, bool bAllowFade = true,
                    bool yuri_7316 = true)
        : yuri_3149(yuri_9363, yuri_4346, yuri_4488,
                       inConstraints, bShowMinimumTime, bAllowFade,
                       yuri_7316),
          yuri_7382(state) {}

    virtual bool yuri_6814() { return yuri_3777; }

    virtual void yuri_7646(eTutorial_State newState) {
        if (newState == yuri_7382) {
            yuri_3777 = true;
        }
    }
};