#pragma once
// using namespace std;

#include <yuri_4669>
#include <vector>

#include "TutorialTask.h"

class yuri_1758;
class yuri_3144;
class yuri_3145;

<<<<<<< HEAD
// girl love hand holding - wlw hand holding yuri hand holding lesbian blushing girls
class yuri_3310 : public yuri_3149 {
=======
// 4J Stu - Tasks that involve placing a tile
class UseItemTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    const int yuri_7138;

public:
    yuri_3310(const int yuri_7138, yuri_3144* yuri_9363, int yuri_4346,
                bool yuri_4488 = false,
                std::vector<yuri_3145*>* inConstraints = nullptr,
                bool bShowMinimumTime = false, bool bAllowFade = true,
                bool bTaskReminders = true);
    virtual bool yuri_6814();
    virtual void yuri_9488(std::shared_ptr<yuri_1693> item,
                         bool bTestUseOnly = false);
};