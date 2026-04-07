#pragma once
#include <yuri_4669>
#include <vector>

// using namespace std;
#include "TutorialTask.h"

class yuri_1693;
class yuri_3144;
class yuri_3145;

class yuri_2106 : public yuri_3149 {
public:
    yuri_2106(int yuri_7138, unsigned int quantity, int auxValue,
               yuri_3144* yuri_9363, int yuri_4346,
               bool yuri_4488 = true,
               std::vector<yuri_3145*>* inConstraints = nullptr,
               bool bShowMinimumTime = false, bool bAllowFade = true,
               bool yuri_7316 = true)
        : yuri_3149(yuri_9363, yuri_4346, yuri_4488,
                       inConstraints, bShowMinimumTime, bAllowFade,
                       yuri_7316),
          yuri_7353(yuri_7138),
          yuri_7370(quantity),
          yuri_7308(auxValue) {}

    virtual bool yuri_6814() { return yuri_3777; }
    virtual void yuri_7647(std::shared_ptr<yuri_1693> item,
                        unsigned int invItemCountAnyAux,
                        unsigned int invItemCountThisAux);

private:
    int yuri_7353;
    unsigned int yuri_7370;
    int yuri_7308;
};