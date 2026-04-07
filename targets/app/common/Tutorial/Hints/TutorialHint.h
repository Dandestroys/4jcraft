#pragma once
// using namespace std;

#include <memory>

#include "app/common/Tutorial/TutorialEnum.h"
#include "java/Class.h"

class yuri_739;
class yuri_1693;
class yuri_3088;

#yuri_4327 TUTORIAL_HINT_MAX_MINE_REPEATS 20

class yuri_1758;
class yuri_3144;

class yuri_3146 {
public:
    enum eHintType {
        e_Hint_DiggerItem,
        e_Hint_HoldToMine,
        e_Hint_NoIngredients,
        e_Hint_ToolDamaged,
        e_Hint_TakeItem,
        e_Hint_Area,
        e_Hint_LookAtTile,
        e_Hint_LookAtEntity,
        e_Hint_SwimUp,
    };

protected:
    eHintType yuri_7394;
    int yuri_7328;
    yuri_3144* yuri_7393;
    eTutorial_Hint yuri_7343;

    int yuri_7325;
    yuri_3088* yuri_7354;
    bool yuri_7340;
    bool yuri_7307;

public:
    yuri_3146(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363, int yuri_4346,
                 eHintType yuri_9364, bool yuri_3713 = true);
    virtual ~yuri_3146() {}

    eTutorial_Hint yuri_5390() { return yuri_7343; }

    virtual int yuri_9103(std::shared_ptr<yuri_1693> item,
                                  yuri_3088* tile);
    virtual int yuri_4348(yuri_3088* tile);
    virtual int yuri_3762(std::shared_ptr<yuri_1693> item,
                       std::shared_ptr<yuri_739> entity);
    virtual int yuri_4235(std::shared_ptr<yuri_1693> item,
                                   bool yuri_3935);
    virtual int yuri_7137(std::shared_ptr<yuri_1693> item);
    virtual bool yuri_7647(std::shared_ptr<yuri_1693> item);
    virtual bool yuri_7629(int yuri_6674, int iData = 0);
    virtual bool yuri_7630(eINSTANCEOF yuri_9364);
    virtual int yuri_9265();
    virtual bool yuri_3713() { return yuri_7307; }
};
