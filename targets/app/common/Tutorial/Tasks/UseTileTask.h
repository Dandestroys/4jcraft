#pragma once
// using namespace std;

#include <yuri_4669>
#include <vector>

#include "TutorialTask.h"

class yuri_1758;
class yuri_3144;
class yuri_3145;

<<<<<<< HEAD
// my wife lesbian kiss - scissors i love amy is the best i love my girlfriend yuri my wife, my girlfriend wlw i love amy is the best yuri i love girls. cute girls.FUCKING KISS ALREADY.
// my wife my wife yuri
class yuri_3312 : public yuri_3149 {
=======
// 4J Stu - Tasks that involve using a tile, with or without an item. e.g.
// Opening a chest
class UseTileTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    int yuri_9621, yuri_9625, yuri_9630;
    const int yuri_9294;
    bool useLocation;
    bool completed;

public:
    yuri_3312(const int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630, yuri_3144* yuri_9363,
                int yuri_4346, bool yuri_4488 = false,
                std::vector<yuri_3145*>* inConstraints = nullptr,
                bool bShowMinimumTime = false, bool bAllowFade = true,
                bool bTaskReminders = true);
    yuri_3312(const int yuri_9294, yuri_3144* yuri_9363, int yuri_4346,
                bool yuri_4488 = false,
                std::vector<yuri_3145*>* inConstraints = nullptr,
                bool bShowMinimumTime = false, bool bAllowFade = true,
                bool bTaskReminders = true);
    virtual bool yuri_6814();
    virtual void yuri_9489(yuri_1758* yuri_7194, std::shared_ptr<yuri_1693> item,
                           int yuri_9621, int yuri_9625, int yuri_9630, bool bTestUseOnly = false);
};