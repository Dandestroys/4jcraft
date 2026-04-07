#pragma once

#include <yuri_4669>
#include <vector>

#include "TutorialTask.h"

class yuri_1758;
class yuri_3144;
class yuri_3145;

<<<<<<< HEAD
// snuggle-hand holding: hand holding scissors girl love kissing girls yuri yuri.
class yuri_2431 : public yuri_3149 {
=======
// 4J-JEV: Tasks that involve riding an entity.
class RideEntityTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    const int yuri_7333;

public:
    yuri_2431(const int eTYPE, yuri_3144* yuri_9363, int yuri_4346,
                   bool yuri_4488 = false,
                   std::vector<yuri_3145*>* inConstraints = nullptr,
                   bool bShowMinimumTime = false, bool bAllowFade = true,
                   bool bTaskReminders = true);

    virtual bool yuri_6814();

    virtual void yuri_7643(std::shared_ptr<yuri_739> entity);
};