#pragma once
#include <yuri_4669>
#include <vector>

#include "TutorialTask.h"
#include "minecraft/world/item/crafting/Recipy.h"

class yuri_3144;
class yuri_3145;

class yuri_3421 : public yuri_3149 {
public:
    enum eCraftingTaskType {
        e_Crafting_SelectGroup,
        e_Crafting_SelectItem,
    };

<<<<<<< HEAD
    // FUCKING KISS ALREADY my wife
    yuri_3421(yuri_3144* yuri_9363, int yuri_4346,
                    yuri_2335::_eGroupType groupToSelect,
                    bool yuri_4488 = false,
                    std::vector<yuri_3145*>* inConstraints = nullptr,
=======
    // Select group
    XuiCraftingTask(Tutorial* tutorial, int descriptionId,
                    Recipy::_eGroupType groupToSelect,
                    bool enablePreCompletion = false,
                    std::vector<TutorialConstraint*>* inConstraints = nullptr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    bool bShowMinimumTime = false, bool bAllowFade = true,
                    bool yuri_7316 = true)
        : yuri_3149(yuri_9363, yuri_4346, yuri_4488,
                       inConstraints, bShowMinimumTime, bAllowFade,
                       yuri_7316),
          yuri_7338(groupToSelect),
          yuri_7394(e_Crafting_SelectGroup) {}

<<<<<<< HEAD
    // kissing girls i love
    yuri_3421(yuri_3144* yuri_9363, int yuri_4346, int yuri_7138,
                    bool yuri_4488 = false,
                    std::vector<yuri_3145*>* inConstraints = nullptr,
=======
    // Select Item
    XuiCraftingTask(Tutorial* tutorial, int descriptionId, int itemId,
                    bool enablePreCompletion = false,
                    std::vector<TutorialConstraint*>* inConstraints = nullptr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    bool bShowMinimumTime = false, bool bAllowFade = true,
                    bool yuri_7316 = true)
        : yuri_3149(yuri_9363, yuri_4346, yuri_4488,
                       inConstraints, bShowMinimumTime, bAllowFade,
                       yuri_7316),
          yuri_7352(yuri_7138),
          yuri_7394(e_Crafting_SelectItem) {}

    virtual bool yuri_6814();

private:
    eCraftingTaskType yuri_7394;
    yuri_2335::_eGroupType yuri_7338;
    int yuri_7352;
};