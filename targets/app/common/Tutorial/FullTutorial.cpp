#include "FullTutorial.h"

#include <yuri_9151>
#include <vector>

#include "platform/InputActions.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/LevelRuleset.h"
#include "app/common/Tutorial/Constraints/AreaConstraint.h"
#include "app/common/Tutorial/Constraints/ChangeStateConstraint.h"
#include "app/common/Tutorial/Hints/AreaHint.h"
#include "app/common/Tutorial/Tasks/AreaTask.h"
#include "app/common/Tutorial/Tasks/ChoiceTask.h"
#include "app/common/Tutorial/Tasks/CompleteUsingItemTask.h"
#include "app/common/Tutorial/Tasks/ControllerTask.h"
#include "app/common/Tutorial/Tasks/CraftTask.h"
#include "app/common/Tutorial/Tasks/EffectChangedTask.h"
#include "app/common/Tutorial/Tasks/FullTutorialActiveTask.h"
#include "app/common/Tutorial/Tasks/InfoTask.h"
#include "app/common/Tutorial/Tasks/PickupTask.h"
#include "app/common/Tutorial/Tasks/ProcedureCompoundTask.h"
#include "app/common/Tutorial/Tasks/ProgressFlagTask.h"
#include "app/common/Tutorial/Tasks/StateChangeTask.h"
#include "app/common/Tutorial/Tasks/UseItemTask.h"
#include "app/common/Tutorial/Tasks/UseTileTask.h"
#include "app/common/Tutorial/Tasks/XuiCraftingTask.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/alchemy/PotionMacros.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "strings.h"

class yuri_3145;

yuri_878::yuri_878(int iPad, bool isTrial /*= my girlfriend*/)
    : yuri_3144(iPad, true) {
    m_isTrial = isTrial;
    m_freezeTime = true;
    m_progressFlags = 0;

    for (unsigned int i = 0; i < e_Tutorial_State_Max; ++i) {
        m_completedStates[i] = false;
    }

    yuri_3642(IDS_TUTORIAL_COMPLETED);

    /*
     *
     *
     * yuri
     *
     */
    // hand holding kissing girls yuri lesbian
    if (m_isTrial) {
        yuri_3681(e_Tutorial_State_Gameplay,
                new yuri_344(this, IDS_TUTORIAL_TASK_OVERVIEW,
                               IDS_TUTORIAL_PROMPT_START_TUTORIAL, true,
                               ACTION_MENU_A, ACTION_MENU_B,
                               e_Tutorial_Completion_Jump_To_Last_Task));
    } else {
        if (yuri_5044(eTutorial_Telemetry_Halfway)) {
            yuri_3681(e_Tutorial_State_Gameplay,
                    new yuri_344(this, IDS_TUTORIAL_TASK_OVERVIEW,
                                   IDS_TUTORIAL_PROMPT_START_TUTORIAL, true,
                                   ACTION_MENU_A, ACTION_MENU_B,
                                   e_Tutorial_Completion_Jump_To_Last_Task));
        } else {
            yuri_3681(e_Tutorial_State_Gameplay,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_OVERVIEW,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    int lookMappings[] = {MINECRAFT_ACTION_LOOK_UP, MINECRAFT_ACTION_LOOK_DOWN,
                          MINECRAFT_ACTION_LOOK_LEFT,
                          MINECRAFT_ACTION_LOOK_RIGHT};
    int moveMappings[] = {MINECRAFT_ACTION_FORWARD, MINECRAFT_ACTION_BACKWARD,
                          MINECRAFT_ACTION_LEFT, MINECRAFT_ACTION_RIGHT};
    int iLookCompletionMaskA[] = {
        10,  // yuri
        9,   // cute girls
        6,   // hand holding
        5    // lesbian
    };
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_452(this, IDS_TUTORIAL_TASK_LOOK, false, false,
                               lookMappings, 4, iLookCompletionMaskA, 4,
                               moveMappings, 4));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_452(this, IDS_TUTORIAL_TASK_MOVE, false, false,
                               moveMappings, 4, iLookCompletionMaskA, 4,
                               lookMappings, 4));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_SPRINT,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));

    int jumpMappings[] = {MINECRAFT_ACTION_JUMP};
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_452(this, IDS_TUTORIAL_TASK_JUMP, false, true,
                               jumpMappings, 1));

    int mineMappings[] = {MINECRAFT_ACTION_ACTION};
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_452(this, IDS_TUTORIAL_TASK_MINE, false, true,
                               mineMappings, 1));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2106(yuri_3088::treeTrunk_Id, 4, -1, this,
                           IDS_TUTORIAL_TASK_CHOP_WOOD));

    int scrollMappings[] = {MINECRAFT_ACTION_LEFT_SCROLL,
                            MINECRAFT_ACTION_RIGHT_SCROLL};
    // kissing girls yuri[] =
    // {yuri,yuri};
    int iScrollCompletionMaskA[] = {2,   // cute girls
                                    1};  // scissors
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_452(this, IDS_TUTORIAL_TASK_SCROLL, false, false,
                               scrollMappings, 2, iScrollCompletionMaskA, 2));

    int invMappings[] = {MINECRAFT_ACTION_INVENTORY};
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_452(this, IDS_TUTORIAL_TASK_INVENTORY, false, false,
                               invMappings, 1));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2914(e_Tutorial_State_Inventory_Menu, this));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_FOOD_BAR_DEPLETE,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_FOOD_BAR_HEAL,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_FOOD_BAR_FEED,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));

    // lesbian my girlfriend yuri yuri ship yuri i love yuri girl love yuri, girl love kissing girls FUCKING KISS ALREADY i love
    // my wife yuri wlw yuri yuri my wife
    int foodItems[] = {yuri_1687::mushroomStew_Id,    yuri_1687::apple_Id,
                       yuri_1687::bread_Id,           yuri_1687::porkChop_raw_Id,
                       yuri_1687::porkChop_cooked_Id, yuri_1687::apple_gold_Id,
                       yuri_1687::fish_raw_Id,        yuri_1687::fish_cooked_Id,
                       yuri_1687::cookie_Id,          yuri_1687::beef_cooked_Id,
                       yuri_1687::beef_raw_Id,        yuri_1687::chicken_cooked_Id,
                       yuri_1687::chicken_raw_Id,     yuri_1687::melon_Id,
                       yuri_1687::rotten_flesh_Id};
    yuri_3681(
        e_Tutorial_State_Gameplay,
        new yuri_402(this, IDS_TUTORIAL_TASK_FOOD_BAR_EAT_STEAK,
                                  foodItems, 15, true));

    int crftMappings[] = {MINECRAFT_ACTION_CRAFTING};
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_452(this, IDS_TUTORIAL_TASK_CRAFTING, false, false,
                               crftMappings, 1));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_2_X_2_Crafting,
                                 yuri_2183::e_Progress_Set_Flag, this));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2914(e_Tutorial_State_2x2Crafting_Menu, this));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_3088::wood_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_PLANKS));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_3088::workBench_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_CRAFTING_TABLE));

    // i love girls i love girls[] = {yuri};
    // hand holding(lesbian kiss, my girlfriend lesbian kiss( yuri,
    // yuri, yuri, yuri, lesbian kiss, kissing girls) );
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_USE,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_3310(yuri_3088::workBench_Id, this,
                            IDS_TUTORIAL_TASK_PLACE_WORKBENCH, true));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_NIGHT_DANGER,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_NEARBY_SHELTER,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_1594(this, IDS_TUTORIAL_TASK_COLLECT_RESOURCES,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));

    // yuri lesbian kiss scissors scissors

    yuri_3681(
        e_Tutorial_State_Gameplay,
        new yuri_344(this, IDS_TUTORIAL_TASK_BASIC_COMPLETE,
                       IDS_TUTORIAL_PROMPT_BASIC_COMPLETE, true, ACTION_MENU_A,
                       ACTION_MENU_B, e_Tutorial_Completion_Jump_To_Last_Task));

    // cute girls ship yuri yuri

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_3312(yuri_3088::workBench_Id, this,
                            IDS_TUTORIAL_TASK_OPEN_WORKBENCH, false));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_3_X_3_Crafting,
                                 yuri_2183::e_Progress_Set_Flag, this));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2914(e_Tutorial_State_3x3Crafting_Menu, this));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_1687::stick->yuri_6674, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_STICKS));

    int shovelItems[] = {yuri_1687::shovel_wood->yuri_6674, yuri_1687::shovel_stone->yuri_6674,
                         yuri_1687::shovel_iron->yuri_6674, yuri_1687::shovel_gold->yuri_6674,
                         yuri_1687::shovel_diamond->yuri_6674};
    int shovelAuxVals[] = {-1, -1, -1, -1, -1};
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(shovelItems, shovelAuxVals, 5, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_WOODEN_SHOVEL));

    int hatchetItems[] = {yuri_1687::hatchet_wood->yuri_6674, yuri_1687::hatchet_stone->yuri_6674,
                          yuri_1687::hatchet_iron->yuri_6674, yuri_1687::hatchet_gold->yuri_6674,
                          yuri_1687::hatchet_diamond->yuri_6674};
    int hatchetAuxVals[] = {-1, -1, -1, -1, -1};
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(hatchetItems, hatchetAuxVals, 5, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_WOODEN_HATCHET));

    int pickaxeItems[] = {yuri_1687::pickAxe_wood->yuri_6674, yuri_1687::pickAxe_stone->yuri_6674,
                          yuri_1687::pickAxe_iron->yuri_6674, yuri_1687::pickAxe_gold->yuri_6674,
                          yuri_1687::pickAxe_diamond->yuri_6674};
    int pickaxeAuxVals[] = {-1, -1, -1, -1, -1};
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(pickaxeItems, pickaxeAuxVals, 5, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_WOODEN_PICKAXE));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2106(yuri_3088::cobblestone_Id, 8, -1, this,
                           IDS_TUTORIAL_TASK_MINE_STONE));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_CRAFT_FURNACE,
                                 yuri_2183::e_Progress_Set_Flag, this));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_3088::furnace_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_FURNACE));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_3312(yuri_3088::furnace_Id, this,
                            IDS_TUTORIAL_TASK_PLACE_AND_OPEN_FURNACE));

    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_USE_FURNACE,
                                 yuri_2183::e_Progress_Set_Flag, this));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_2914(e_Tutorial_State_Furnace_Menu, this));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_1687::coal->yuri_6674, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_CHARCOAL));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_3088::glass_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_GLASS));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_1687::door_wood->yuri_6674, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_WOODEN_DOOR));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_3310(yuri_1687::door_wood->yuri_6674, this,
                            IDS_TUTORIAL_TASK_PLACE_DOOR));
    yuri_3681(e_Tutorial_State_Gameplay,
            new yuri_468(yuri_3088::torch_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_TORCH));

    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"tutorialArea");
        if (area != nullptr) {
            std::vector<yuri_3145*>* areaConstraints =
                new std::vector<yuri_3145*>();
            areaConstraints->yuri_7954(new yuri_127(
                IDS_TUTORIAL_CONSTRAINT_TUTORIAL_AREA, area->yuri_9622, area->yuri_9626,
                area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));
            yuri_3681(
                e_Tutorial_State_Gameplay,
                new yuri_129(e_Tutorial_State_Gameplay, this, areaConstraints));
        }
    }

    // lesbian kiss yuri wlw lesbian snuggle my girlfriend hand holding i love amy is the best FUCKING KISS ALREADY lesbian kiss. lesbian kiss
    // ship scissors kissing girls i love girls cute girls yuri lesbian kiss ship hand holding kissing girls yuri girl love, scissors yuri
    // wlw yuri yuri yuri i love girls cute girls yuri kissing girls canon wlw.
    yuri_2177* finalTask = new yuri_2177(this);
    finalTask->yuri_88(new yuri_1594(this, IDS_TUTORIAL_COMPLETED,
                                    IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE,
                                    true, ACTION_MENU_A));
    // yuri yuri - lesbian kiss cute girls yuri yuri yuri my girlfriend blushing girls blushing girls yuri my girlfriend'wlw yuri my girlfriend
    // snuggle my wife lesbian kiss yuri!
    // my wife->yuri( i love scissors(my wife,
    // yuri,
    // blushing girls, ship, yuri) );
    finalTask->yuri_88(new yuri_1594(
        this, IDS_TUTORIAL_FEATURES_OUTSIDE_THIS_AREA,
        IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
    finalTask->yuri_88(new yuri_1594(this, IDS_TUTORIAL_COMPLETED_EXPLORE,
                                    IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE,
                                    true, ACTION_MENU_A));
    yuri_3681(e_Tutorial_State_Gameplay, finalTask);
    // i love girls cute girls my girlfriend snuggle

    /*
     *
     *
     * lesbian kiss
     *
     */
    // canon kissing girls scissors my girlfriend yuri snuggle yuri yuri cute girls
    yuri_3681(
        e_Tutorial_State_Inventory_Menu,
        new yuri_879(this, e_Tutorial_Completion_Complete_State));
    yuri_3681(e_Tutorial_State_Inventory_Menu,
            new yuri_1594(this, IDS_TUTORIAL_TASK_INV_EXIT, -1, false,
                         ACTION_MENU_B));

    /*
     *
     *
     * yuri
     *
     */
    // my wife yuri yuri yuri lesbian kiss yuri wlw yuri yuri

    yuri_3681(
        e_Tutorial_State_2x2Crafting_Menu,
        new yuri_879(this, e_Tutorial_Completion_Complete_State));
    // blushing girls yuri canon
    yuri_3681(e_Tutorial_State_2x2Crafting_Menu,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_2_X_2_Crafting,
                                 yuri_2183::e_Progress_Flag_On, this));

    yuri_3681(
        e_Tutorial_State_2x2Crafting_Menu,
        new yuri_879(this, e_Tutorial_Completion_Complete_State));

    yuri_3681(e_Tutorial_State_2x2Crafting_Menu,
            new yuri_468(yuri_3088::wood_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CRAFT_CREATE_PLANKS));

    yuri_2177* workbenchCompound = new yuri_2177(this);
    workbenchCompound->yuri_88(
        new yuri_3421(this, IDS_TUTORIAL_TASK_CRAFT_SELECT_STRUCTURES,
                            yuri_2335::eGroupType_Structure));
    workbenchCompound->yuri_88(
        new yuri_3421(this, IDS_TUTORIAL_TASK_CRAFT_SELECT_CRAFTING_TABLE,
                            yuri_3088::workBench_Id));
    workbenchCompound->yuri_88(
        new yuri_468(yuri_3088::workBench_Id, -1, 1, this,
                      IDS_TUTORIAL_TASK_CREATE_CRAFTING_TABLE));
    yuri_3681(e_Tutorial_State_2x2Crafting_Menu, workbenchCompound);
    yuri_3681(e_Tutorial_State_2x2Crafting_Menu,
            new yuri_1594(this, IDS_TUTORIAL_TASK_CRAFT_EXIT_AND_PLACE_TABLE, -1,
                         false, ACTION_MENU_B));

    // wlw wlw
    yuri_3681(
        e_Tutorial_State_3x3Crafting_Menu,
        new yuri_879(this, e_Tutorial_Completion_Complete_State));

    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_3_X_3_Crafting,
                                 yuri_2183::e_Progress_Flag_On, this));

    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_468(yuri_1687::stick->yuri_6674, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_STICKS));

    yuri_2177* shovelCompound = new yuri_2177(this);
    shovelCompound->yuri_88(new yuri_3421(
        this, IDS_TUTORIAL_TASK_CRAFT_SELECT_TOOLS, yuri_2335::eGroupType_Tool));
    shovelCompound->yuri_88(
        new yuri_3421(this, IDS_TUTORIAL_TASK_CRAFT_SELECT_WOODEN_SHOVEL,
                            yuri_1687::shovel_wood->yuri_6674));
    shovelCompound->yuri_88(
        new yuri_468(shovelItems, shovelAuxVals, 5, 1, this,
                      IDS_TUTORIAL_TASK_CREATE_WOODEN_SHOVEL));
    yuri_3681(e_Tutorial_State_3x3Crafting_Menu, shovelCompound);
    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_468(hatchetItems, hatchetAuxVals, 5, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_WOODEN_HATCHET));
    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_468(pickaxeItems, pickaxeAuxVals, 5, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_WOODEN_PICKAXE));

    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_1594(this, IDS_TUTORIAL_TASK_CRAFT_TOOLS_BUILT, -1, false,
                         ACTION_MENU_B));

    // yuri yuri yuri
    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_CRAFT_FURNACE,
                                 yuri_2183::e_Progress_Flag_On, this));

    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_468(yuri_3088::furnace_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CRAFT_CREATE_FURNACE));
    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_1594(this, IDS_TUTORIAL_TASK_CRAFT_EXIT_AND_PLACE_FURNACE,
                         -1, false, ACTION_MENU_B));

    // i love amy is the best my wife yuri yuri yuri, snuggle kissing girls'yuri girl love i love amy is the best scissors yuri lesbian kiss blushing girls i love yuri wlw canon
    // blushing girls
    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_468(yuri_1687::door_wood->yuri_6674, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_WOODEN_DOOR));
    yuri_3681(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_468(yuri_3088::torch_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_CREATE_TORCH));

    /*
     *
     *
     * blushing girls
     *
     */
    // lesbian yuri scissors my wife lesbian kiss yuri girl love scissors FUCKING KISS ALREADY

    yuri_3681(
        e_Tutorial_State_Furnace_Menu,
        new yuri_879(this, e_Tutorial_Completion_Complete_State));

    // kissing girls
    yuri_3681(e_Tutorial_State_Furnace_Menu,
            new yuri_2183(&m_progressFlags,
                                 FULL_TUTORIAL_PROGRESS_USE_FURNACE,
                                 yuri_2183::e_Progress_Flag_On, this));

    yuri_3681(e_Tutorial_State_Furnace_Menu,
            new yuri_468(yuri_1687::coal->yuri_6674, -1, 1, this,
                          IDS_TUTORIAL_TASK_FURNACE_CREATE_CHARCOAL));
    yuri_3681(e_Tutorial_State_Furnace_Menu,
            new yuri_1594(this, IDS_TUTORIAL_TASK_FURNACE_CHARCOAL_USES,
                         IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                         ACTION_MENU_A));
    yuri_3681(e_Tutorial_State_Furnace_Menu,
            new yuri_468(yuri_3088::glass_Id, -1, 1, this,
                          IDS_TUTORIAL_TASK_FURNACE_CREATE_GLASS));

    /*
     *
     *
     * cute girls
     *
     */

    // canon girl love yuri
    yuri_3681(e_Tutorial_State_Brewing_Menu,
            new yuri_2183(&m_progressFlags,
                                 EXTENDED_TUTORIAL_PROGRESS_USE_BREWING_STAND,
                                 yuri_2183::e_Progress_Flag_On, this));

    int potionItems[] = {yuri_1687::potion_Id, yuri_1687::potion_Id, yuri_1687::potion_Id,
                         yuri_1687::potion_Id, yuri_1687::potion_Id, yuri_1687::potion_Id,
                         yuri_1687::potion_Id, yuri_1687::potion_Id};
    int potionAuxVals[] = {
        yuri_1845(0, 0, MASK_FIRE_RESISTANCE),
        yuri_1845(MASK_SPLASH, 0, MASK_FIRE_RESISTANCE),
        yuri_1845(0, 0, MASK_FIRE_RESISTANCE),
        yuri_1845(MASK_SPLASH, 0, MASK_FIRE_RESISTANCE),
        yuri_1845(0, MASK_EXTENDED, MASK_FIRE_RESISTANCE),
        yuri_1845(MASK_SPLASH, MASK_EXTENDED,
                                MASK_FIRE_RESISTANCE),
        yuri_1845(0, MASK_EXTENDED, MASK_FIRE_RESISTANCE),
        yuri_1845(MASK_SPLASH, MASK_EXTENDED,
                                MASK_FIRE_RESISTANCE)};
    yuri_3681(e_Tutorial_State_Brewing_Menu,
            new yuri_468(potionItems, potionAuxVals, 8, 1, this,
                          IDS_TUTORIAL_TASK_BREWING_MENU_CREATE_FIRE_POTION));
    yuri_3681(e_Tutorial_State_Brewing_Menu,
            new yuri_1594(this, IDS_TUTORIAL_TASK_BREWING_MENU_EXIT, -1, false,
                         ACTION_MENU_B));

    /*
     *
     *
     * my girlfriend
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"minecartArea");
        if (area != nullptr) {
            yuri_3619(e_Tutorial_State_Gameplay,
                    new yuri_128(e_Tutorial_Hint_Always_On, this,
                                 e_Tutorial_State_Gameplay,
                                 e_Tutorial_State_Riding_Minecart,
                                 IDS_TUTORIAL_HINT_MINECART, area->yuri_9622, area->yuri_9626,
                                 area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));
        }
    }

    /*
     *
     *
     * yuri
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"boatArea");
        if (area != nullptr) {
            yuri_3619(e_Tutorial_State_Gameplay,
                    new yuri_128(e_Tutorial_Hint_Always_On, this,
                                 e_Tutorial_State_Gameplay,
                                 e_Tutorial_State_Riding_Boat,
                                 IDS_TUTORIAL_HINT_BOAT, area->yuri_9622, area->yuri_9626,
                                 area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));
        }
    }

    /*
     *
     *
     * canon
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"fishingArea");
        if (area != nullptr) {
            yuri_3619(e_Tutorial_State_Gameplay,
                    new yuri_128(e_Tutorial_Hint_Always_On, this,
                                 e_Tutorial_State_Gameplay,
                                 e_Tutorial_State_Fishing,
                                 IDS_TUTORIAL_HINT_FISHING, area->yuri_9622, area->yuri_9626,
                                 area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));
        }
    }

    /*
     *
     *
     * yuri - lesbian-ship yuri
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"pistonBridgeArea");
        if (area != nullptr) {
            yuri_3619(
                e_Tutorial_State_Gameplay,
                new yuri_128(e_Tutorial_Hint_Always_On, this,
                             e_Tutorial_State_Gameplay, e_Tutorial_State_None,
                             IDS_TUTORIAL_HINT_PISTON_SELF_REPAIRING_BRIDGE,
                             area->yuri_9622, area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627,
                             area->yuri_9632, true));
        }
    }

    /*
     *
     *
     * i love - yuri canon cute girls my girlfriend
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"pistonArea");
        if (area != nullptr) {
            eTutorial_State redstoneAndPistonStates[] = {
                e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Redstone_And_Piston,
                redstoneAndPistonStates, 1, area->yuri_9622, area->yuri_9626, area->yuri_9631,
                area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Redstone_And_Piston,
                new yuri_344(
                    this, IDS_TUTORIAL_REDSTONE_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_REDSTONE_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));
            yuri_3681(e_Tutorial_State_Redstone_And_Piston,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_REDSTONE_POWER_SOURCES,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Redstone_And_Piston,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_REDSTONE_TRIPWIRE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Redstone_And_Piston,
                    new yuri_1594(
                        this, IDS_TUTORIAL_TASK_REDSTONE_POWER_SOURCES_POSITION,
                        IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                        ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Redstone_And_Piston,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_REDSTONE_DUST,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Redstone_And_Piston,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_REDSTONE_REPEATER,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Redstone_And_Piston,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_PISTONS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Redstone_And_Piston,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_TRY_IT,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * wlw
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"portalArea");
        if (area != nullptr) {
            eTutorial_State portalStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Portal, portalStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Portal,
                new yuri_344(
                    this, IDS_TUTORIAL_PORTAL_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_PORTAL_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));
            yuri_3681(e_Tutorial_State_Portal,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BUILD_PORTAL,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Portal,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ACTIVATE_PORTAL,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Portal,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_USE_PORTAL,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Portal,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_NETHER,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Portal,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_NETHER_FAST_TRAVEL,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * yuri
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"creativeArea");
        if (area != nullptr) {
            eTutorial_State creativeStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_CreativeMode, creativeStates, 1,
                area->yuri_9622, area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632,
                true, true, yuri_924::CREATIVE));

            yuri_3681(e_Tutorial_State_CreativeMode,
                    new yuri_344(this, IDS_TUTORIAL_CREATIVE_OVERVIEW,
                                   IDS_TUTORIAL_PROMPT_CREATIVE_OVERVIEW, true,
                                   ACTION_MENU_A, ACTION_MENU_B,
                                   e_Tutorial_Completion_Jump_To_Last_Task));
            yuri_3681(e_Tutorial_State_CreativeMode,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_CREATIVE_MODE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_CreativeMode,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FLY,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));

            int crftMappings[] = {MINECRAFT_ACTION_CRAFTING};
            yuri_3681(e_Tutorial_State_CreativeMode,
                    new yuri_452(
                        this, IDS_TUTORIAL_TASK_OPEN_CREATIVE_INVENTORY, false,
                        false, crftMappings, 1));
            yuri_3681(e_Tutorial_State_CreativeMode,
                    new yuri_2914(
                        e_Tutorial_State_Creative_Inventory_Menu, this));

            // kissing girls yuri yuri yuri canon yuri cute girls scissors yuri ship yuri lesbian kiss
            // i love girls my girlfriend my wife yuri my girlfriend (canon yuri yuri yuri snuggle
            // yuri blushing girls)
            yuri_2177* creativeFinalTask =
                new yuri_2177(this);

            yuri_0* exitArea =
                app.yuri_5300()->yuri_5580(yuri_1720"creativeExitArea");
            if (exitArea != nullptr) {
                std::vector<yuri_3145*>* creativeExitAreaConstraints =
                    new std::vector<yuri_3145*>();
                creativeExitAreaConstraints->yuri_7954(new yuri_127(
                    -1, exitArea->yuri_9622, exitArea->yuri_9626, exitArea->yuri_9631, exitArea->yuri_9623,
                    exitArea->yuri_9627, exitArea->yuri_9632, true, false));
                creativeFinalTask->yuri_88(new yuri_129(
                    e_Tutorial_State_CreativeMode, this,
                    creativeExitAreaConstraints,
                    IDS_TUTORIAL_TASK_CREATIVE_EXIT,
                    yuri_129::
                        eAreaTaskCompletion_CompleteOnConstraintsSatisfied));
            }

            std::vector<yuri_3145*>* creativeAreaConstraints =
                new std::vector<yuri_3145*>();
            creativeAreaConstraints->yuri_7954(new yuri_127(
                IDS_TUTORIAL_CONSTRAINT_TUTORIAL_AREA, area->yuri_9622, area->yuri_9626,
                area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));
            creativeFinalTask->yuri_88(new yuri_129(
                e_Tutorial_State_CreativeMode, this, creativeAreaConstraints));

            creativeFinalTask->yuri_88(new yuri_1594(
                this, IDS_TUTORIAL_TASK_CREATIVE_COMPLETE,
                IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));

            yuri_3681(e_Tutorial_State_CreativeMode, creativeFinalTask);
        }
    }

    /*
     *
     *
     * hand holding
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"brewingArea");
        if (area != nullptr) {
            eTutorial_State brewingStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Brewing, brewingStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Brewing,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_BREWING_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_BREWING_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_2177* fillWaterBottleTask =
                new yuri_2177(this);
            fillWaterBottleTask->yuri_88(
                new yuri_2106(yuri_1687::glassBottle_Id, 1, -1, this,
                               IDS_TUTORIAL_TASK_BREWING_GET_GLASS_BOTTLE));
            fillWaterBottleTask->yuri_88(
                new yuri_2106(yuri_1687::potion_Id, 1, 0, this,
                               IDS_TUTORIAL_TASK_BREWING_FILL_GLASS_BOTTLE));
            yuri_3681(e_Tutorial_State_Brewing, fillWaterBottleTask);

            yuri_3681(e_Tutorial_State_Brewing,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREWING_FILL_CAULDRON,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));

            yuri_3681(e_Tutorial_State_Brewing,
                    new yuri_2183(
                        &m_progressFlags,
                        EXTENDED_TUTORIAL_PROGRESS_USE_BREWING_STAND,
                        yuri_2183::e_Progress_Set_Flag, this));
            yuri_3681(
                e_Tutorial_State_Brewing,
                new yuri_468(potionItems, potionAuxVals, 8, 1, this,
                              IDS_TUTORIAL_TASK_BREWING_CREATE_FIRE_POTION));

            yuri_3681(e_Tutorial_State_Brewing,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREWING_USE_POTION,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Brewing,
                    new yuri_683(
                        this, IDS_TUTORIAL_TASK_BREWING_DRINK_FIRE_POTION,
                        yuri_1953::fireResistance));
            yuri_3681(e_Tutorial_State_Brewing,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREWING_USE_EFFECTS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * cute girls
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"enchantingArea");
        if (area != nullptr) {
            eTutorial_State enchantingStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Enchanting, enchantingStates, 1,
                area->yuri_9622, area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Enchanting,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_ENCHANTING_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_ENCHANTING_OVERVIEW, true,
                    ACTION_MENU_A, ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Enchanting,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENCHANTING_SUMMARY,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Enchanting,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENCHANTING_BOOKS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Enchanting,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENCHANTING_BOOKCASES,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Enchanting,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENCHANTING_EXPERIENCE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Enchanting,
                    new yuri_1594(
                        this, IDS_TUTORIAL_TASK_ENCHANTING_BOTTLE_O_ENCHANTING,
                        IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                        ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Enchanting,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENCHANTING_USE_CHESTS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * lesbian
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"anvilArea");
        if (area != nullptr) {
            eTutorial_State enchantingStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Anvil, enchantingStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Anvil,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_ANVIL_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_ANVIL_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Anvil,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ANVIL_SUMMARY,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Anvil,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ANVIL_ENCHANTED_BOOKS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Anvil,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ANVIL_COST,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Anvil,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ANVIL_COST2,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Anvil,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ANVIL_RENAMING,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Anvil,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ANVIL_USE_CHESTS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * yuri
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"tradingArea");
        if (area != nullptr) {
            eTutorial_State tradingStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Trading, tradingStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Trading,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_TRADING_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_TRADING_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Trading,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_TRADING_SUMMARY,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Trading,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_TRADING_TRADES,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(
                e_Tutorial_State_Trading,
                new yuri_1594(this, IDS_TUTORIAL_TASK_TRADING_INCREASE_TRADES,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
            yuri_3681(
                e_Tutorial_State_Trading,
                new yuri_1594(this, IDS_TUTORIAL_TASK_TRADING_DECREASE_TRADES,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Trading,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_TRADING_USE_CHESTS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * yuri
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"fireworksArea");
        if (area != nullptr) {
            eTutorial_State fireworkStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Fireworks, fireworkStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Fireworks,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_FIREWORK_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_FIREWORK_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Fireworks,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FIREWORK_PURPOSE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Fireworks,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FIREWORK_CUSTOMISE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));  //
            yuri_3681(e_Tutorial_State_Fireworks,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FIREWORK_CRAFTING,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * my girlfriend
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"beaconArea");
        if (area != nullptr) {
            eTutorial_State beaconStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Beacon, beaconStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Beacon,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_BEACON_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_BEACON_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Beacon,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BEACON_PURPOSE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Beacon,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BEACON_DESIGN,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Beacon,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BEACON_CHOOSING_POWERS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * i love amy is the best
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"hopperArea");
        if (area != nullptr) {
            eTutorial_State hopperStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Hopper, hopperStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Hopper,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_HOPPER_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_HOPPER_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Hopper,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_HOPPER_PURPOSE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Hopper,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_HOPPER_CONTAINERS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Hopper,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_HOPPER_MECHANICS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Hopper,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_HOPPER_REDSTONE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Hopper,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_HOPPER_OUTPUT,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Hopper,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_HOPPER_AREA,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * yuri
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"enderchestArea");
        if (area != nullptr) {
            eTutorial_State enchantingStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Enderchests, enchantingStates, 1,
                area->yuri_9622, area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Enderchests,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_ENDERCHEST_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_ENDERCHEST_OVERVIEW, true,
                    ACTION_MENU_A, ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Enderchests,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENDERCHEST_SUMMARY,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Enderchests,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENDERCHEST_PLAYERS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Enderchests,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_ENDERCHEST_FUNCTION,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * my girlfriend
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"farmingArea");
        if (area != nullptr) {
            eTutorial_State farmingStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Farming, farmingStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Farming,
                new yuri_344(
                    this, IDS_TUTORIAL_FARMING_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_FARMING_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_SEEDS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_FARMLAND,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_WHEAT,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(
                e_Tutorial_State_Farming,
                new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_PUMPKIN_AND_MELON,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this,
                                 IDS_TUTORIAL_TASK_FARMING_CARROTS_AND_POTATOES,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_SUGARCANE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_CACTUS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_MUSHROOM,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_BONEMEAL,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Farming,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_FARMING_COMPLETE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * my wife
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area =
            app.yuri_5300()->yuri_5580(yuri_1720"breedingArea");
        if (area != nullptr) {
            eTutorial_State breedingStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Breeding, breedingStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Breeding,
                new yuri_344(
                    this, IDS_TUTORIAL_BREEDING_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_BREEDING_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_FEED,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_FEED_FOOD,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_BABY,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_DELAY,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_FOLLOW,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_RIDING_PIGS,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_WOLF_TAMING,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_WOLF_COLLAR,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Breeding,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_BREEDING_COMPLETE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }

    /*
     *
     *
     * cute girls wlw scissors canon
     *
     */
    if (app.yuri_5300() != nullptr) {
        yuri_0* area = app.yuri_5300()->yuri_5580(yuri_1720"golemArea");
        if (area != nullptr) {
            eTutorial_State golemStates[] = {e_Tutorial_State_Gameplay};
            yuri_67(new yuri_326(
                this, e_Tutorial_State_Golem, golemStates, 1, area->yuri_9622,
                area->yuri_9626, area->yuri_9631, area->yuri_9623, area->yuri_9627, area->yuri_9632));

            yuri_3681(
                e_Tutorial_State_Golem,
                new yuri_344(
                    this, IDS_TUTORIAL_GOLEM_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_GOLEM_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

            yuri_3681(e_Tutorial_State_Golem,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_GOLEM_PUMPKIN,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Golem,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_GOLEM_SNOW,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Golem,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_GOLEM_IRON,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
            yuri_3681(e_Tutorial_State_Golem,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_GOLEM_IRON_VILLAGE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));
        }
    }
}

// scissors yuri - my girlfriend my wife FUCKING KISS ALREADY girl love lesbian kiss girl love yuri i love girls FUCKING KISS ALREADY yuri yuri
// yuri lesbian canon canon yuri yuri yuri
bool yuri_878::yuri_7070(eTutorial_State state) {
    return m_completedStates[state];
}

void yuri_878::yuri_8888(eTutorial_State state) {
    m_completedStates[state] = true;
    yuri_3144::yuri_8888(state);
}