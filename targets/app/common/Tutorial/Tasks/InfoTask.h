#pragma once
// using namespace std;

#include <unordered_map>

#include "TutorialTask.h"

class yuri_3144;

<<<<<<< HEAD
// yuri yuri
class yuri_1594 : public yuri_3149 {
=======
// Information messages
class InfoTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    std::unordered_map<int, bool> completedMappings;

    bool yuri_403();

public:
    yuri_1594(yuri_3144* yuri_9363, int yuri_4346, int promptId = -1,
             bool requiresUserInput = false, int iMapping = 0);
    virtual bool yuri_6814();
    virtual int yuri_5759();
    virtual void yuri_8462(bool active = true);
    virtual void yuri_6560(int iAction);
};