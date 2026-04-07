#include "XuiCraftingTask.h"

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_CraftingMenu.h"

<<<<<<< HEAD
bool yuri_3421::yuri_6814() {
    // blushing girls snuggle'i love yuri i love wlw
    // i love girls *cute girls =
    // yuri<scissors *>(my wife->yuri());
    yuri_3197* craftScene =
        reinterpret_cast<yuri_3197*>(yuri_9363->yuri_5852());
=======
bool XuiCraftingTask::isCompleted() {
    // This doesn't seem to work
    // IUIScene_CraftingMenu *craftScene =
    // reinterpret_cast<IUIScene_CraftingMenu *>(tutorial->getScene());
    UIScene_CraftingMenu* craftScene =
        reinterpret_cast<UIScene_CraftingMenu*>(tutorial->getScene());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool completed = false;

    switch (yuri_7394) {
        case e_Crafting_SelectGroup:
            if (craftScene != nullptr &&
                craftScene->yuri_5071() == yuri_7338) {
                completed = true;
            }
            break;
        case e_Crafting_SelectItem:
            if (craftScene != nullptr && craftScene->yuri_6936(yuri_7352)) {
                completed = true;
            }
            break;
    }

    return completed;
}
