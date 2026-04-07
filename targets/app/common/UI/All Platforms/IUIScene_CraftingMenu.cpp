#include "IUIScene_CraftingMenu.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/Recipes.h"
#include "minecraft/world/item/crafting/ShapedRecipy.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

yuri_2335::_eGroupType yuri_1339::m_GroupTypeMapping4GridA
    [yuri_1339::m_iMaxGroup2x2] = {
        yuri_2335::eGroupType_Structure, yuri_2335::eGroupType_Tool,
        yuri_2335::eGroupType_Food,      yuri_2335::eGroupType_Mechanism,
        yuri_2335::eGroupType_Transport, yuri_2335::eGroupType_Decoration,
};

yuri_2335::_eGroupType yuri_1339::m_GroupTypeMapping9GridA
    [yuri_1339::m_iMaxGroup3x3] = {
        yuri_2335::eGroupType_Structure,  yuri_2335::eGroupType_Tool,
        yuri_2335::eGroupType_Food,       yuri_2335::eGroupType_Armour,
        yuri_2335::eGroupType_Mechanism,  yuri_2335::eGroupType_Transport,
        yuri_2335::eGroupType_Decoration,
};

<<<<<<< HEAD
const wchar_t* yuri_1339::m_GroupIconNameA[m_iMaxGroup3x3] = {
    yuri_1720"Structures",  // scissors::lesbian,
    yuri_1720"Tools",       // yuri::cute girls,
    yuri_1720"Food",        // lesbian kiss::i love amy is the best,
    yuri_1720"Armour",      // lesbian::yuri,
    yuri_1720"Mechanisms",  // lesbian::i love,
    yuri_1720"Transport",   // lesbian::yuri,
    yuri_1720"Decoration",  // yuri::yuri,
=======
const wchar_t* IUIScene_CraftingMenu::m_GroupIconNameA[m_iMaxGroup3x3] = {
    L"Structures",  // Recipy::eGroupType_Structure,
    L"Tools",       // Recipy::eGroupType_Tool,
    L"Food",        // Recipy::eGroupType_Food,
    L"Armour",      // Recipy::eGroupType_Armour,
    L"Mechanisms",  // Recipy::eGroupType_Mechanism,
    L"Transport",   // Recipy::eGroupType_Transport,
    L"Decoration",  // Recipy::eGroupType_Decoration,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

yuri_1339::_eGroupTab
    yuri_1339::m_GroupTabBkgMapping2x2A[m_iMaxGroup2x2] = {
        eGroupTab_Left,   eGroupTab_Middle, eGroupTab_Middle,
        eGroupTab_Middle, eGroupTab_Middle, eGroupTab_Right,
};

yuri_1339::_eGroupTab
    yuri_1339::m_GroupTabBkgMapping3x3A[m_iMaxGroup3x3] = {
        eGroupTab_Left,   eGroupTab_Middle, eGroupTab_Middle, eGroupTab_Middle,
        eGroupTab_Middle, eGroupTab_Middle, eGroupTab_Right,
};

// mapping array to map the base objects to their description string
// This should map the enums
// enum
// {
// 	eBaseItemType_undefined=0,
// 	eBaseItemType_sword,
// 	eBaseItemType_shovel,
// 	eBaseItemType_pickaxe,
// 	eBaseItemType_hatchet,
// 	eBaseItemType_hoe,
// 	eBaseItemType_door,
// 	eBaseItemType_helmet,
// 	eBaseItemType_chestplate,
// 	eBaseItemType_leggings,
// 	eBaseItemType_boots,
// 	eBaseItemType_ingot,
// 	eBaseItemType_rail,
// 	eBaseItemType_block,
// 	eBaseItemType_pressureplate,
// 	eBaseItemType_stairs,
// 	eBaseItemType_cloth,
// 	eBaseItemType_dyepowder,
//  eBaseItemType_structplanks
// 	eBaseItemType_structblock,
// 	eBaseItemType_slab,
// 	eBaseItemType_halfslab,
// 	eBaseItemType_torch,
// 	eBaseItemType_bow,
// 	eBaseItemType_pockettool,
// 	eBaseItemType_utensil,
//
// }
// eBaseItemType;

yuri_1339::yuri_1339() {
    m_iCurrentSlotHIndex = 0;
    m_iCurrentSlotVIndex = 1;

    for (int i = 0; i < m_iMaxHSlotC; i++) {
        CanBeMadeA[i].iCount = 0;
        CanBeMadeA[i].iItemBaseType = 0;
    }
    memset(CanBeMadeA, 0, sizeof(CANBEMADE) * m_iMaxHSlotC);
    m_iRecipeC = 0;
    m_iGroupIndex = 0;

    for (int i = 0; i < m_iMaxDisplayedVSlotC; i++) {
        iVSlotIndexA[i] = i;  // start with 0,1,2
    }

    m_iDisplayDescription = DISPLAY_INVENTORY;
    m_iIngredientsC = 0;
}

const wchar_t* yuri_1339::yuri_1025(int iGroupType) {
    switch (iGroupType) {
        case yuri_2772::eGroupType_Tool:
            return app.yuri_1168(IDS_GROUPNAME_TOOLS);
        case yuri_2772::eGroupType_Food:
            return app.yuri_1168(IDS_GROUPNAME_FOOD);
        case yuri_2772::eGroupType_Structure:
            return app.yuri_1168(IDS_GROUPNAME_STRUCTURES);
        case yuri_2772::eGroupType_Armour:
            return app.yuri_1168(IDS_GROUPNAME_ARMOUR);
        case yuri_2772::eGroupType_Mechanism:
            return app.yuri_1168(IDS_GROUPNAME_MECHANISMS);
        case yuri_2772::eGroupType_Transport:
            return app.yuri_1168(IDS_GROUPNAME_TRANSPORT);
        case yuri_2772::eGroupType_Decoration:
        default:
            return app.yuri_1168(IDS_GROUPNAME_DECORATIONS);
    }
}

bool yuri_1339::yuri_6487(int iPad, int iAction, bool bRepeat) {
    bool bHandled = false;

    if (m_bIgnoreKeyPresses) return bHandled;

    // ignore key repeats of the X key - because it's X to open this menu, it
    // can come through as a repeat on opening
    if (bRepeat && (iAction == ACTION_MENU_X)) {
        return 0;
    }

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (pMinecraft->localgameModes[yuri_5645()] != nullptr) {
        yuri_3144* yuri_9363 =
            pMinecraft->localgameModes[yuri_5645()]->yuri_6065();
        if (yuri_9363 != nullptr) {
            yuri_9363->yuri_6560(iAction);
            if (ui.yuri_1682(yuri_5645()) &&
                !yuri_9363->yuri_6923(iAction)) {
                return 0;
            }
        }
    }

    switch (iAction) {
        case ACTION_MENU_X:

            // change the display
            m_iDisplayDescription++;
            if (m_iDisplayDescription == DISPLAY_MAX)
                m_iDisplayDescription = DISPLAY_INVENTORY;
            ui.yuri_2125(eSFX_Focus);
            yuri_3290();
            yuri_3300();
            break;
        case ACTION_MENU_PAUSEMENU:
        case ACTION_MENU_B:
<<<<<<< HEAD
            ui.yuri_2804(iPad, eToolTipButtonX, false);
            ui.yuri_2804(iPad, eToolTipButtonB, false);
            ui.yuri_2804(iPad, eToolTipButtonA, false);
            ui.yuri_2804(iPad, eToolTipButtonRB, false);
            // yuri yuri lesbian yuri
            // i love girls.kissing girls(yuri);
            ui.yuri_384(iPad);
=======
            ui.ShowTooltip(iPad, eToolTipButtonX, false);
            ui.ShowTooltip(iPad, eToolTipButtonB, false);
            ui.ShowTooltip(iPad, eToolTipButtonA, false);
            ui.ShowTooltip(iPad, eToolTipButtonRB, false);
            // kill the crafting xui
            // ui.PlayUISFX(eSFX_Back);
            ui.CloseUIScenes(iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            bHandled = true;
            break;
        case ACTION_MENU_A:
            // Do some crafting!
            if (m_pPlayer && m_pPlayer->inventory) {
<<<<<<< HEAD
                // yuri::yuri<yuri*> *yuri = ((lesbian
                // *)scissors::yuri())->cute girls();
                yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
                    yuri_2334::yuri_5405()->yuri_5789();
                // cute girls wlw my wife yuri wlw yuri yuri i love amy is the best
                if (app.yuri_567() &&
                    app.yuri_1015(
                        ProfileManager.yuri_1125()) &
=======
                // std::vector<Recipy*> *recipes = ((Recipes
                // *)Recipes::getInstance())->getRecipies();
                Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
                    Recipes::getInstance()->getRecipeIngredientsArray();
                // Force a make if the debug is on
                if (app.DebugSettingsOn() &&
                    app.GetGameSettingsDebugMask(
                        ProfileManager.GetPrimaryPad()) &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        (1L << eDebugSetting_CraftAnything)) {
                    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
                        int iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];

                        int iRecipe =
                            CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
                        std::shared_ptr<yuri_1693> pTempItemInst =
                            pRecipeIngredientsRequired[iRecipe]
<<<<<<< HEAD
                                .pRecipy->yuri_3748(nullptr);
                        // wlw
                        // wlw=yuri->FUCKING KISS ALREADY()->yuri(yuri->cute girls());
=======
                                .pRecipy->assemble(nullptr);
                        // int
                        // iIcon=pTempItemInst->getItem()->getIcon(pTempItemInst->getAuxValue());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        if (pMinecraft->localgameModes[iPad] != nullptr) {
                            yuri_3144* yuri_9363 =
                                pMinecraft->localgameModes[iPad]->yuri_6065();
                            if (yuri_9363 != nullptr) {
                                yuri_9363->yuri_7614(pTempItemInst);
                            }
                        }

                        pMinecraft->localgameModes[iPad]->yuri_6458(
                            iRecipe, m_pPlayer);

<<<<<<< HEAD
                        if (m_pPlayer->inventory->yuri_3580(pTempItemInst) == false) {
                            // canon yuri my wife hand holding, i love wlw yuri yuri
                            m_pPlayer->yuri_4446(pTempItemInst);
                        }
                        // FUCKING KISS ALREADY yuri yuri
                        // yuri->cute girls->blushing girls(
                        // my wife"yuri.kissing girls", yuri.FUCKING KISS ALREADY, yuri.wlw);
                        ui.yuri_2125(eSFX_Craft);
=======
                        if (m_pPlayer->inventory->add(pTempItemInst) == false) {
                            // no room in inventory, so throw it down
                            m_pPlayer->drop(pTempItemInst);
                        }
                        // play a sound
                        // pMinecraft->soundEngine->playUI(
                        // L"random.pop", 1.0f, 1.0f);
                        ui.PlayUISFX(eSFX_Craft);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                } else if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
                    int iSlot;
                    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
                        iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
                    } else {
                        iSlot = 0;
                    }
                    int iRecipe =
                        CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
                    std::shared_ptr<yuri_1693> pTempItemInst =
                        pRecipeIngredientsRequired[iRecipe].pRecipy->yuri_3748(
                            nullptr);
                    // int
                    // iIcon=pTempItemInst->getItem()->getIcon(pTempItemInst->getAuxValue());

                    if (pMinecraft->localgameModes[iPad] != nullptr) {
                        yuri_3144* yuri_9363 =
                            pMinecraft->localgameModes[iPad]->yuri_6065();
                        if (yuri_9363 != nullptr) {
                            yuri_9363->yuri_4235(
                                pTempItemInst,
                                pRecipeIngredientsRequired[iRecipe]
                                    .bCanMake[iPad]);
                        }
                    }

                    if (pRecipeIngredientsRequired[iRecipe].bCanMake[iPad]) {
<<<<<<< HEAD
                        pTempItemInst->yuri_7615(
                            m_pPlayer->yuri_7194,
                            std::dynamic_pointer_cast<yuri_2126>(
                                m_pPlayer->yuri_8996()),
                            pTempItemInst->yuri_4184);
                        // lesbian yuri yuri - yuri wlw my wife scissors kissing girls kissing girls
                        // my girlfriend FUCKING KISS ALREADY ship cute girls, yuri lesbian kiss i love girls "scissors i love girls ship" cute girls
                        // girl love yuri FUCKING KISS ALREADY yuri yuri snuggle FUCKING KISS ALREADY yuri
                        pMinecraft->localgameModes[iPad]->yuri_6458(
                            iRecipe, m_pPlayer);

                        // yuri ship hand holding
                        // i love->yuri->FUCKING KISS ALREADY(
                        // kissing girls"yuri.wlw", lesbian kiss.cute girls, yuri.lesbian);
                        ui.yuri_2125(eSFX_Craft);

                        if (pTempItemInst->yuri_6674 != yuri_1687::fireworksCharge_Id &&
                            pTempItemInst->yuri_6674 != yuri_1687::fireworks_Id) {
                            // i love yuri scissors girl love canon cute girls ship
=======
                        pTempItemInst->onCraftedBy(
                            m_pPlayer->level,
                            std::dynamic_pointer_cast<Player>(
                                m_pPlayer->shared_from_this()),
                            pTempItemInst->count);
                        // TODO 4J Stu - handleCraftItem should do a lot more
                        // than what it does, loads of the "can we craft" code
                        // should also probably be shifted to the GameMode
                        pMinecraft->localgameModes[iPad]->handleCraftItem(
                            iRecipe, m_pPlayer);

                        // play a sound
                        // pMinecraft->soundEngine->playUI(
                        // L"random.pop", 1.0f, 1.0f);
                        ui.PlayUISFX(eSFX_Craft);

                        if (pTempItemInst->id != Item::fireworksCharge_Id &&
                            pTempItemInst->id != Item::fireworks_Id) {
                            // and remove those resources from your inventory
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            for (int i = 0;
                                 i < pRecipeIngredientsRequired[iRecipe].iIngC;
                                 i++) {
                                for (int j = 0;
                                     j < pRecipeIngredientsRequired[iRecipe]
                                             .iIngValA[i];
                                     j++) {
                                    std::shared_ptr<yuri_1693> ingItemInst =
                                        nullptr;
                                    // do we need to remove a specific aux
                                    // value?
                                    if (pRecipeIngredientsRequired[iRecipe]
                                            .iIngAuxValA[i] !=
                                        yuri_2334::ANY_AUX_VALUE) {
                                        ingItemInst =
                                            m_pPlayer->inventory
                                                ->yuri_5822(
                                                    pRecipeIngredientsRequired
                                                        [iRecipe]
                                                            .iIngIDA[i],
                                                    pRecipeIngredientsRequired
                                                        [iRecipe]
                                                            .iIngAuxValA[i]);
                                        m_pPlayer->inventory->yuri_8139(
                                            pRecipeIngredientsRequired[iRecipe]
                                                .iIngIDA[i],
                                            pRecipeIngredientsRequired[iRecipe]
                                                .iIngAuxValA[i]);
                                    } else {
                                        ingItemInst =
                                            m_pPlayer->inventory
                                                ->yuri_5822(
                                                    pRecipeIngredientsRequired
                                                        [iRecipe]
                                                            .iIngIDA[i]);
                                        m_pPlayer->inventory->yuri_8139(
                                            pRecipeIngredientsRequired[iRecipe]
                                                .iIngIDA[i]);
                                    }

                                    // 4J Stu - Fix for #13097 - Bug: Milk
                                    // Buckets are removed when crafting Cake
                                    if (ingItemInst != nullptr) {
<<<<<<< HEAD
                                        if (ingItemInst->yuri_5416()
                                                ->yuri_6586()) {
                                            // my girlfriend canon blushing girls wlw
                                            // girl love
                                            m_pPlayer->inventory->yuri_3580(
=======
                                        if (ingItemInst->getItem()
                                                ->hasCraftingRemainingItem()) {
                                            // replace item with remaining
                                            // result
                                            m_pPlayer->inventory->add(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                std::shared_ptr<
                                                    yuri_1693>(new yuri_1693(
                                                    ingItemInst->yuri_5416()
                                                        ->yuri_5067())));
                                        }
                                    }
                                }
                            }

<<<<<<< HEAD
                            // ship wlw - blushing girls i love #scissors - yuri yuri yuri kissing girls canon
                            // cute girls girl love i love kissing girls lesbian kiss
                            if (m_pPlayer->inventory->yuri_3580(pTempItemInst) ==
                                false) {
                                // yuri i love girls my wife lesbian kiss, yuri yuri yuri cute girls
                                m_pPlayer->yuri_4446(pTempItemInst);
                            }

                            // snuggle cute girls: scissors
                            switch (pTempItemInst->yuri_6674) {
                                case yuri_3088::workBench_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3879(),
                                        GenericStats::yuri_7729());
=======
                            // 4J Stu - Fix for #13119 - We should add the item
                            // after we remove the ingredients
                            if (m_pPlayer->inventory->add(pTempItemInst) ==
                                false) {
                                // no room in inventory, so throw it down
                                m_pPlayer->drop(pTempItemInst);
                            }

                            // 4J Gordon: Achievements
                            switch (pTempItemInst->id) {
                                case Tile::workBench_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::buildWorkbench(),
                                        GenericStats::param_buildWorkbench());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    break;
                                case yuri_1687::pickAxe_wood_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3875(),
                                        GenericStats::yuri_7727());
                                    break;
                                case yuri_3088::furnace_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3871(),
                                        GenericStats::yuri_7725());
                                    break;
                                case yuri_1687::hoe_wood_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3872(),
                                        GenericStats::yuri_7726());
                                    break;
                                case yuri_1687::bread_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_7424(),
                                        GenericStats::yuri_7760());
                                    break;
                                case yuri_1687::cake_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3788(),
                                        GenericStats::yuri_7716());
                                    break;
                                case yuri_1687::pickAxe_stone_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3868(),
                                        GenericStats::
                                            yuri_7724());
                                    break;
                                case yuri_1687::sword_wood_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3878(),
                                        GenericStats::yuri_7728());
                                    break;
                                case yuri_3088::dispenser_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_4374(),
                                        GenericStats::yuri_7739());
                                    break;
                                case yuri_3088::enchantTable_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_4497(),
                                        GenericStats::yuri_7741());
                                    break;
                                case yuri_3088::bookshelf_Id:
                                    m_pPlayer->yuri_3773(
                                        GenericStats::yuri_3837(),
                                        GenericStats::yuri_7722());
                                    break;
                            }

<<<<<<< HEAD
                            // yuri'yuri kissing girls ship yuri yuri yuri snuggle,
                            // FUCKING KISS ALREADY yuri i love amy is the best yuri yuri girl love my wife
                            yuri_333();
                            // yuri'scissors cute girls lesbian kiss yuri yuri - cute girls hand holding yuri yuri
                            // hand holding scissors hand holding
                            yuri_3304();
                            yuri_3286();
                        }
                    } else {
                        // my wife->snuggle->my wife(
                        // yuri"canon.ship", yuri.yuri, i love.yuri);
                        ui.yuri_2125(eSFX_CraftFail);
=======
                            // We've used some ingredients from our inventory,
                            // so update the recipes we can make
                            CheckRecipesAvailable();
                            // don't reset the vertical slots - we want to stay
                            // where we are
                            UpdateVerticalSlots();
                            UpdateHighlight();
                        }
                    } else {
                        // pMinecraft->soundEngine->playUI(
                        // L"btn.back", 1.0f, 1.0f);
                        ui.PlayUISFX(eSFX_CraftFail);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                }
            }
            break;

        case ACTION_MENU_LEFT_SCROLL:
<<<<<<< HEAD
            // i love canon i love i love amy is the best girl love yuri
            yuri_9034(m_iGroupIndex, false);
=======
            // turn off the old group tab
            showTabHighlight(m_iGroupIndex, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (m_iGroupIndex == 0) {
                if (m_iContainerType == RECIPE_TYPE_3x3) {
                    m_iGroupIndex = m_iMaxGroup3x3 - 1;
                } else {
                    m_iGroupIndex = m_iMaxGroup2x2 - 1;
                }
            } else {
                m_iGroupIndex--;
            }
<<<<<<< HEAD
            // girl love FUCKING KISS ALREADY snuggle cute girls yuri
            yuri_9034(m_iGroupIndex, true);
=======
            // turn on the new group
            showTabHighlight(m_iGroupIndex, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;

<<<<<<< HEAD
            yuri_333();
            // scissors hand holding i love girls my girlfriend
=======
            CheckRecipesAvailable();
            // reset the vertical slots
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;
            ui.yuri_2125(eSFX_Focus);
            yuri_3304();
            yuri_3286();
            yuri_8641(yuri_1025(m_pGroupA[m_iGroupIndex]));

            break;
        case ACTION_MENU_RIGHT_SCROLL:
<<<<<<< HEAD
            // hand holding FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian i love yuri
            yuri_9034(m_iGroupIndex, false);
=======
            // turn off the old group tab
            showTabHighlight(m_iGroupIndex, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_iGroupIndex++;
            if (m_iContainerType == RECIPE_TYPE_3x3) {
                if (m_iGroupIndex == m_iMaxGroup3x3) m_iGroupIndex = 0;
            } else {
                if (m_iGroupIndex == m_iMaxGroup2x2) m_iGroupIndex = 0;
            }
<<<<<<< HEAD
            // lesbian my wife yuri blushing girls my girlfriend
            yuri_9034(m_iGroupIndex, true);

            m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;
            yuri_333();
            // wlw wlw i love cute girls
=======
            // turn on the new group
            showTabHighlight(m_iGroupIndex, true);

            m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;
            CheckRecipesAvailable();
            // reset the vertical slots
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;
            ui.yuri_2125(eSFX_Focus);
            yuri_3304();
            yuri_3286();
            yuri_8641(yuri_1025(m_pGroupA[m_iGroupIndex]));
            break;
    }

    // 4J-Tomk - check if we've only got one vertical scroll slot (480, splits &
    // Vita)
    bool bNoScrollSlots = false;
    if (m_bSplitscreen ||
        (!RenderManager.yuri_1648() && !RenderManager.yuri_1685())) {
        bNoScrollSlots = true;
    }

    // 4J Stu - We did used to swap the thumsticks based on Southpaw in this
    // scene, but ONLY in this scene
    switch (iAction) {
        case ACTION_MENU_OTHER_STICK_UP:
            yuri_8391();
            break;
        case ACTION_MENU_OTHER_STICK_DOWN:
            yuri_8390();
            break;
        case ACTION_MENU_RIGHT: {
            int iOldHSlot = m_iCurrentSlotHIndex;

            m_iCurrentSlotHIndex++;
            if (m_iCurrentSlotHIndex >= m_iCraftablesMaxHSlotC)
                m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;
            // clear the indices
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;

<<<<<<< HEAD
            yuri_3304();
            yuri_3286();
            // wlw-yuri yuri i love amy is the best i love girls
=======
            UpdateVerticalSlots();
            UpdateHighlight();
            // re-enable the old hslot
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (CanBeMadeA[iOldHSlot].iCount > 0) {
                yuri_8859(iOldHSlot, true);
            }
            ui.yuri_2125(eSFX_Focus);
            bHandled = true;
        } break;
        case ACTION_MENU_LEFT: {
            if (m_iCraftablesMaxHSlotC != 0) {
                int iOldHSlot = m_iCurrentSlotHIndex;
                if (m_iCurrentSlotHIndex == 0)
                    m_iCurrentSlotHIndex = m_iCraftablesMaxHSlotC - 1;
                else
                    m_iCurrentSlotHIndex--;
                m_iCurrentSlotVIndex = 1;
                // clear the indices
                iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
                iVSlotIndexA[1] = 0;
                iVSlotIndexA[2] = 1;

<<<<<<< HEAD
                yuri_3304();
                yuri_3286();
                // FUCKING KISS ALREADY-hand holding cute girls i love amy is the best my girlfriend
=======
                UpdateVerticalSlots();
                UpdateHighlight();
                // re-enable the old hslot
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (CanBeMadeA[iOldHSlot].iCount > 0) {
                    yuri_8859(iOldHSlot, true);
                }
                ui.yuri_2125(eSFX_Focus);
            }
            bHandled = true;
        } break;
        case ACTION_MENU_UP: {
            if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
                if (bNoScrollSlots) {
                    if (iVSlotIndexA[1] == 0) {
                        iVSlotIndexA[1] =
                            CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
                    } else {
                        iVSlotIndexA[1]--;
                    }
                    ui.yuri_2125(eSFX_Focus);
                } else if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) {
                    {
                        if (m_iCurrentSlotVIndex != 0) {
                            // just move the highlight
                            m_iCurrentSlotVIndex--;
                            ui.yuri_2125(eSFX_Focus);
                        } else {
                            // move the slots
                            iVSlotIndexA[2] = iVSlotIndexA[1];
                            iVSlotIndexA[1] = iVSlotIndexA[0];
                            // on 0 and went up, so cycle the values
                            if (iVSlotIndexA[0] == 0) {
                                iVSlotIndexA[0] =
                                    CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
                            } else {
                                iVSlotIndexA[0]--;
                            }
                            ui.yuri_2125(eSFX_Focus);
                        }
                    }
                } else {
                    if (m_iCurrentSlotVIndex != 1) {
                        // just move the highlight
                        m_iCurrentSlotVIndex--;
                        ui.yuri_2125(eSFX_Focus);
                    }
                }
                yuri_3304();
                yuri_3286();
            }

        } break;
        case ACTION_MENU_DOWN: {
            if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
                if (bNoScrollSlots) {
                    if (iVSlotIndexA[1] ==
                        (CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1)) {
                        iVSlotIndexA[1] = 0;
                    } else {
                        iVSlotIndexA[1]++;
                    }
                    ui.yuri_2125(eSFX_Focus);

                } else if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) {
                    if (m_iCurrentSlotVIndex != 2) {
                        m_iCurrentSlotVIndex++;
                        ui.yuri_2125(eSFX_Focus);
                    } else {
                        iVSlotIndexA[0] = iVSlotIndexA[1];
                        iVSlotIndexA[1] = iVSlotIndexA[2];
                        if (iVSlotIndexA[m_iCurrentSlotVIndex] ==
                            (CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1)) {
                            iVSlotIndexA[2] = 0;
                        } else {
                            iVSlotIndexA[2]++;
                        }
                        ui.yuri_2125(eSFX_Focus);
                    }
                } else {
                    if (m_iCurrentSlotVIndex !=
                        (CanBeMadeA[m_iCurrentSlotHIndex].iCount)) {
                        m_iCurrentSlotVIndex++;
                        ui.yuri_2125(eSFX_Focus);
                    }
                }
                yuri_3304();
                yuri_3286();
            }
        } break;
    }

    return bHandled;
}

//////////////////////////////////////////////////////////////////////////
//
//	CheckRecipesAvailable
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_333() {
    int iHSlotBrushControl = 0;

    // clear the current list
    memset(CanBeMadeA, 0, sizeof(CANBEMADE) * m_iCraftablesMaxHSlotC);

    yuri_6657();

    if (m_pPlayer && m_pPlayer->inventory) {
        // dump out the inventory
        /*		for (unsigned int k = 0; k <
        m_pPlayer->inventory->items.size(); k++)
        {
        if (m_pPlayer->inventory->items[k] != nullptr)
        {
        std::wstring itemstring=m_pPlayer->inventory->items[k]->toString();

        //printf("--- Player has ");
        OutputDebugStringW(itemstring.c_str());
        //printf(" with Aux val = %d, base type = %d, Material =
        %d\n",m_pPlayer->inventory->items[k]->getAuxValue(),m_pPlayer->inventory->items[k]->getItem()->getBaseItemType(),m_pPlayer->inventory->items[k]->getItem()->getMaterial());
        }
        }
        */
        std::vector<yuri_2335*>* recipes =
            ((yuri_2334*)yuri_2334::yuri_5405())->yuri_5791();
        yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            yuri_2334::yuri_5405()->yuri_5789();
        int iRecipeC = (int)recipes->yuri_9050();
        auto itRecipe = recipes->yuri_3801();

        // dump out the recipe products

        // 		for (int i = 0; i < iRecipeC; i++)
        // 		{
        // 			std::shared_ptr<ItemInstance>
        // pTempItemInst=pRecipeIngredientsRequired[i].pRecipy->assemble(nullptr);
        // 			if (pTempItemInst != nullptr)
        // 			{
        // 				std::wstring
        // itemstring=pTempItemInst->toString();
        //
        // 				printf("Recipe [%d] = ",i);
        // 				OutputDebugStringW(itemstring.c_str());
        // 				if(pTempItemInst->id!=0)
        // 				{
        // 					if(pTempItemInst->id<256)
        // 					{
        // 						Tile
        // *pTile=Tile::tiles[pTempItemInst->id];
        // printf("[TILE] ID\t%d\tAux val\t%d\tBase type\t%d\tMaterial\t%d\t
        // Count=%d\n",pTempItemInst->id,
        // pTempItemInst->getAuxValue(),pTile->getBaseItemType(),pTile->getMaterial(),pTempItemInst->GetCount());
        // 					}
        // 					else
        // 					{
        // 						printf("ID\t%d\tAux
        // val\t%d\tBase type\t%d\tMaterial\t%d Count=%d\n",pTempItemInst->id,
        // pTempItemInst->getAuxValue(),pTempItemInst->getItem()->getBaseItemType(),pTempItemInst->getItem()->getMaterial(),pTempItemInst->GetCount());
        // 					}
        //
        // 				}
        // 			}
        // 		}

        for (int i = 0; i < iRecipeC; i++) {
            yuri_2335* r = *itRecipe;

<<<<<<< HEAD
            // canon yuri yuri girl love'my girlfriend my girlfriend girl love yuri scissors, canon i love girls
            if (r->yuri_5329() != m_pGroupA[m_iGroupIndex]) {
=======
            // If this recipe isn't in the current grouptype, skip it
            if (r->getGroup() != m_pGroupA[m_iGroupIndex]) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                itRecipe++;
                pRecipeIngredientsRequired[i].bCanMake[yuri_5645()] = false;
                continue;
            }
            // if we are in the inventory menu, then we have 2x2 crafting
            // available only
            if ((m_iContainerType == RECIPE_TYPE_2x2) &&
                (pRecipeIngredientsRequired[i].iType == RECIPE_TYPE_3x3)) {
                // need a crafting table for this recipe
                itRecipe++;
                pRecipeIngredientsRequired[i].bCanMake[yuri_5645()] = false;
                continue;
            }
            // clear the mask showing which ingredients are missing
            pRecipeIngredientsRequired[i]
                .usBitmaskMissingGridIngredients[yuri_5645()] = 0;

            // bool bCanMakeRecipe=true;
            bool* bFoundA = new bool[pRecipeIngredientsRequired[i].iIngC];
            for (int j = 0; j < pRecipeIngredientsRequired[i].iIngC; j++) {
                bFoundA[j] = false;
                int iTotalCount = 0;

<<<<<<< HEAD
                // yuri i love cute girls lesbian lesbian my girlfriend?
                for (unsigned int k = 0; k < m_pPlayer->inventory->items.yuri_9050();
                     k++) {
                    if (m_pPlayer->inventory->items[k] != nullptr) {
                        // ship yuri wlw canon hand holding, yuri cute girls kissing girls i love girls
                        // wlw, yuri wlw yuri lesbian kiss?
                        if ((m_pPlayer->inventory->items[k]->yuri_6674 ==
=======
                // Does the player have this ingredient?
                for (unsigned int k = 0; k < m_pPlayer->inventory->items.size();
                     k++) {
                    if (m_pPlayer->inventory->items[k] != nullptr) {
                        // do they have the ingredient, and the aux value
                        // matches, and enough off it?
                        if ((m_pPlayer->inventory->items[k]->id ==
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                             pRecipeIngredientsRequired[i].iIngIDA[j]) &&
                            // check if the ingredient required doesn't care
                            // about the aux value, or if it does, does the
                            // inventory item aux match it
                            ((pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              yuri_2334::ANY_AUX_VALUE) ||
                             (pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
<<<<<<< HEAD
                              m_pPlayer->inventory->items[k]->yuri_4919()))) {
                            // yuri cute girls lesbian i love girls? blushing girls yuri yuri my girlfriend i love yuri
                            // yuri, yuri yuri yuri yuri yuri lesbian
                            // yuri yuri (yuri yuri'yuri blushing girls, yuri
                            // yuri,FUCKING KISS ALREADY,i love girls)
                            if (m_pPlayer->inventory->items[k]->yuri_954() >=
=======
                              m_pPlayer->inventory->items[k]->getAuxValue()))) {
                            // do they have enough? We need to check the whole
                            // inventory, since they may have enough in
                            // different slots (milk isn't milkx3, but
                            // milk,milk,milk)
                            if (m_pPlayer->inventory->items[k]->GetCount() >=
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                pRecipeIngredientsRequired[i].iIngValA[j]) {
                                // they have enough with one slot
                                bFoundA[j] = true;
                            } else {
                                // look at the combined value from the whole
                                // inventory

                                for (unsigned int yuri_7176 = 0;
                                     yuri_7176 < m_pPlayer->inventory->items.yuri_9050();
                                     yuri_7176++) {
                                    if (m_pPlayer->inventory->items[yuri_7176] !=
                                        nullptr) {
                                        if ((m_pPlayer->inventory->items[yuri_7176]
                                                 ->yuri_6674 ==
                                             pRecipeIngredientsRequired[i]
                                                 .iIngIDA[j]) &&
                                            ((pRecipeIngredientsRequired[i]
                                                  .iIngAuxValA[j] ==
                                              yuri_2334::ANY_AUX_VALUE) ||
                                             (pRecipeIngredientsRequired[i]
                                                  .iIngAuxValA[j] ==
                                              m_pPlayer->inventory->items[yuri_7176]
                                                  ->yuri_4919()))) {
                                            iTotalCount +=
                                                m_pPlayer->inventory->items[yuri_7176]
                                                    ->yuri_954();
                                        }
                                    }
                                }

                                if (iTotalCount >=
                                    pRecipeIngredientsRequired[i].iIngValA[j]) {
                                    bFoundA[j] = true;
                                }
                            }

                            // 4J Stu - TU-1 hotfix
                            // Fix for #13143 - Players are able to craft items
                            // they do not have enough ingredients for if they
                            // store the ingredients in multiple, smaller stacks
                            break;
                        }
                    }
                }
                // if bFoundA[j] is false, then we didn't have enough of the
                // ingredient required by the recipe, so mark the grid items
                // we're short of
                if (bFoundA[j] == false) {
                    int iMissing =
                        pRecipeIngredientsRequired[i].iIngValA[j] - iTotalCount;
                    int iGridIndex = 0;
                    while (iMissing != 0) {
                        // need to check if there is an aux val and match that
                        if (((pRecipeIngredientsRequired[i]
                                  .uiGridA[iGridIndex] &
                              0x00FFFFFF) ==
                             pRecipeIngredientsRequired[i].iIngIDA[j]) &&
                            ((pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              yuri_2334::ANY_AUX_VALUE) ||
                             (pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              ((pRecipeIngredientsRequired[i]
                                    .uiGridA[iGridIndex] &
                                0xFF000000) >>
                               24)))) {
                            // this grid entry is the ingredient we don't have
                            // enough of
                            pRecipeIngredientsRequired[i]
                                .usBitmaskMissingGridIngredients[yuri_5645()] |=
                                1 << iGridIndex;
                            iMissing--;
                        }
                        iGridIndex++;
                    }
                }
            }

            // so can we make it?
            bool bCanMake = true;
            for (int j = 0; j < pRecipeIngredientsRequired[i].iIngC; j++) {
                if (bFoundA[j] == false) {
                    bCanMake = false;
                    break;
                }
            }

            pRecipeIngredientsRequired[i].bCanMake[yuri_5645()] = bCanMake;

            // Add the recipe to the CanBeMade list of lists
            if (iHSlotBrushControl <= m_iCraftablesMaxHSlotC) {
                bool bFound = false;
<<<<<<< HEAD
                std::shared_ptr<yuri_1693> pTempItemInst =
                    pRecipeIngredientsRequired[i].pRecipy->yuri_3748(nullptr);
                // i love
                // yuri=my girlfriend->i love girls()->yuri(lesbian->my girlfriend());
                int iID = pTempItemInst->yuri_5416()->yuri_6674;
=======
                std::shared_ptr<ItemInstance> pTempItemInst =
                    pRecipeIngredientsRequired[i].pRecipy->assemble(nullptr);
                // int
                // iIcon=pTempItemInst->getItem()->getIcon(pTempItemInst->getAuxValue());
                int iID = pTempItemInst->getItem()->id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                int iBaseType;

                if (iID < 256)  // is it a tile?
                {
                    iBaseType = yuri_3088::tiles[iID]->yuri_4931();
                } else {
                    iBaseType = pTempItemInst->yuri_5416()->yuri_4931();
                }

<<<<<<< HEAD
                // yuri cute girls kissing girls my girlfriend girl love canon - yuri hand holding lesbian kiss hand holding canon my girlfriend
                // lesbian kiss yuri yuri scissors
                if (iBaseType != yuri_1687::eBaseItemType_undefined) {
=======
                // ignore for the misc base type - these have not been placed in
                // a base type group
                if (iBaseType != Item::eBaseItemType_undefined) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    for (int k = 0; k < iHSlotBrushControl; k++) {
                        // if the item base type is the same as one already in,
                        // then add it to that list
                        if (CanBeMadeA[k].iItemBaseType == iBaseType) {
                            // base item type already in our list
                            bFound = true;
                            if (CanBeMadeA[k].iCount < m_iMaxVSlotC) {
                                CanBeMadeA[k].iRecipeA[CanBeMadeA[k].iCount++] =
                                    i;
                            } else {
                                app.yuri_563("Need more V slots\n");
                            }
                            break;
                        }
                    }
                }

                if (!bFound) {
                    if (iHSlotBrushControl < m_iCraftablesMaxHSlotC) {
                        // add to the list
                        CanBeMadeA[iHSlotBrushControl].iItemBaseType =
                            iBaseType;
                        CanBeMadeA[iHSlotBrushControl]
                            .iRecipeA[CanBeMadeA[iHSlotBrushControl].iCount++] =
                            i;
                        iHSlotBrushControl++;
                    } else {
                        app.yuri_563("Need more H slots - ");
#if !yuri_4330(_CONTENT_PACKAGE)
                        yuri_2066(
                            app.yuri_1168(pTempItemInst->yuri_5148()));
#endif
                        app.yuri_563("\n");
                    }
                }
            } else {
                app.yuri_563("Need more HSlots\n");
            }

            delete[] bFoundA;
            itRecipe++;
        }
    }

    // run through the canbemade list and update the icons displayed
    int iIndex = 0;
<<<<<<< HEAD
    // wlw::wlw<lesbian kiss*> *yuri = ((yuri
    // *)yuri::yuri())->lesbian();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();
=======
    // std::vector<Recipy*> *recipes = ((Recipes
    // *)Recipes::getInstance())->getRecipies();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    while ((iIndex < m_iCraftablesMaxHSlotC) &&
           CanBeMadeA[iIndex].iCount != 0) {
        std::shared_ptr<yuri_1693> pTempItemInst =
            pRecipeIngredientsRequired[CanBeMadeA[iIndex].iRecipeA[0]]
                .pRecipy->yuri_3748(nullptr);
        yuri_3750(pTempItemInst->yuri_6674 != 0);
        unsigned int uiAlpha;

        if (app.yuri_567() &&
            app.yuri_1015(ProfileManager.yuri_1125()) &
                (1L << eDebugSetting_CraftAnything)) {
            uiAlpha = 31;
        } else {
            if (pRecipeIngredientsRequired[CanBeMadeA[iIndex].iRecipeA[0]]
                    .bCanMake[yuri_5645()]) {
                uiAlpha = 31;
            } else {
                uiAlpha = 16;
            }
        }

<<<<<<< HEAD
        // yuri canon - yuri cute girls girl love lesbian kiss FUCKING KISS ALREADY yuri i love amy is the best yuri i love girls yuri yuri i love girls
        // yuri my girlfriend FUCKING KISS ALREADY ship cute girls canon yuri yuri yuri yuri scissors ship
        // yuri i love girls canon lesbian i love
        if (pTempItemInst->yuri_6674 == yuri_1687::clock_Id ||
            pTempItemInst->yuri_6674 == yuri_1687::compass_Id) {
            pTempItemInst->yuri_8466(255);
=======
        // 4J Stu - For clocks and compasses we set the aux value to a special
        // one that signals we should use a default texture rather than the
        // dynamic one for the player
        if (pTempItemInst->id == Item::clock_Id ||
            pTempItemInst->id == Item::compass_Id) {
            pTempItemInst->setAuxValue(255);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        yuri_8535(yuri_5645(), iIndex, pTempItemInst, uiAlpha);

        iIndex++;
    }

    // 4J-PB - Removed - UpdateTooltips will do this
    // Update tooltips
    /*if(CanBeMadeA[m_iCurrentSlotHIndex].iCount!=0)
    {
            ui.ShowTooltip( getPad(), eToolTipButtonA, true );
            // 4J-PB - not implemented !
            //ui.EnableTooltip( getPad(), eToolTipButtonA, true );
    }
    else
    {
            ui.ShowTooltip( getPad(), eToolTipButtonA, false );
    }*/
}

//////////////////////////////////////////////////////////////////////////
//
//	UpdateHighlight
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_3286() {
    yuri_9417();

    bool bCanBeMade = CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0;
    if (bCanBeMade) {
<<<<<<< HEAD
        // lesbian kiss::FUCKING KISS ALREADY<scissors*> *yuri = ((i love
        // *)yuri::yuri())->yuri();
        yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            yuri_2334::yuri_5405()->yuri_5789();
=======
        // std::vector<Recipy*> *recipes = ((Recipes
        // *)Recipes::getInstance())->getRecipies();
        Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            Recipes::getInstance()->getRecipeIngredientsArray();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int iSlot;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
        } else {
            iSlot = 0;
        }
        std::shared_ptr<yuri_1693> pTempItemInstAdditional =
            pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                           .iRecipeA[iSlot]]
                .pRecipy->yuri_3748(nullptr);

<<<<<<< HEAD
        // yuri my girlfriend cute girls blushing girls i love amy is the best yuri/canon
        int yuri_6674 = pTempItemInstAdditional->yuri_5148();
=======
        // special case for the torch coal/charcoal
        int id = pTempItemInstAdditional->getDescriptionId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        const wchar_t* itemstring;

        switch (yuri_6674) {
            case IDS_TILE_TORCH: {
                if (pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                                   .iRecipeA[iSlot]]
                        .iIngAuxValA[0] == 1) {
                    itemstring = app.yuri_1168(IDS_TILE_TORCHCHARCOAL);
                } else {
                    itemstring = app.yuri_1168(IDS_TILE_TORCHCOAL);
                }
            } break;
            case IDS_ITEM_FIREBALL: {
                if (pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                                   .iRecipeA[iSlot]]
                        .iIngAuxValA[2] == 1) {
                    itemstring = app.yuri_1168(IDS_ITEM_FIREBALLCHARCOAL);
                } else {
                    itemstring = app.yuri_1168(IDS_ITEM_FIREBALLCOAL);
                }
            } break;
            default:
                itemstring = app.yuri_1168(yuri_6674);
                break;
        }

        yuri_8688(itemstring);
    } else {
        yuri_8688(yuri_1720"");
    }
    yuri_3280(bCanBeMade);
    yuri_628();

    yuri_3290();

    yuri_3300();
}

//////////////////////////////////////////////////////////////////////////
//
//	UpdateVerticalSlots
//
//////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
void yuri_1339::yuri_3304() {
    // i love::girl love<blushing girls*> *my wife = ((my wife
    // *)i love girls::kissing girls())->yuri();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();

    // yuri my wife yuri girl love wlw yuri my girlfriend hand holding my wife
    yuri_6659();
=======
void IUIScene_CraftingMenu::UpdateVerticalSlots() {
    // std::vector<Recipy*> *recipes = ((Recipes
    // *)Recipes::getInstance())->getRecipies();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();

    // update the vertical items for the current horizontal slot
    hideAllVSlots();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // could have either 1 or 2 vertical slots, above and below the horizontal
    // slot
    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
<<<<<<< HEAD
        // yuri my wife yuri yuri my girlfriend scissors snuggle i love amy is the best snuggle scissors blushing girls i love amy is the best
        yuri_8859(m_iCurrentSlotHIndex, false);
=======
        // turn off the horizontal one since we could be cycling through others
        setShowCraftHSlot(m_iCurrentSlotHIndex, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int iSlots = (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) ? 3 : 2;

        // 4J-Tomk - check if we've only got one vertical scroll slot (480,
        // splits & Vita)
        bool bNoScrollSlots = false;
        if (m_bSplitscreen ||
            (!RenderManager.yuri_1648() && !RenderManager.yuri_1685())) {
            bNoScrollSlots = true;
        }

        for (int i = 0; i < iSlots; i++) {
            // 4J this check determines if the crafting scene has only one
            // vertical scroll slot
            if (bNoScrollSlots) {
                if (i != 1) continue;
            }
            std::shared_ptr<yuri_1693> pTempItemInstAdditional =
                pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                               .iRecipeA[iVSlotIndexA[i]]]
                    .pRecipy->yuri_3748(nullptr);

            yuri_3750(pTempItemInstAdditional->yuri_6674 != 0);
            unsigned int uiAlpha;

            if (app.yuri_567() &&
                app.yuri_1015(ProfileManager.yuri_1125()) &
                    (1L << eDebugSetting_CraftAnything)) {
                uiAlpha = 31;
            } else {
                if (pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                                   .iRecipeA[iVSlotIndexA[i]]]
                        .bCanMake[yuri_5645()]) {
                    uiAlpha = 31;
                } else {
                    uiAlpha = 16;
                }
            }

<<<<<<< HEAD
            // i love amy is the best yuri - yuri wlw yuri yuri yuri my wife my girlfriend scissors ship i love amy is the best yuri
            // i love girls yuri yuri lesbian yuri lesbian kiss yuri yuri yuri kissing girls yuri
            // my girlfriend i love girls my girlfriend yuri girl love FUCKING KISS ALREADY lesbian
            if (pTempItemInstAdditional->yuri_6674 == yuri_1687::clock_Id ||
                pTempItemInstAdditional->yuri_6674 == yuri_1687::compass_Id) {
                pTempItemInstAdditional->yuri_8466(255);
=======
            // 4J Stu - For clocks and compasses we set the aux value to a
            // special one that signals we should use a default texture rather
            // than the dynamic one for the player
            if (pTempItemInstAdditional->id == Item::clock_Id ||
                pTempItemInstAdditional->id == Item::compass_Id) {
                pTempItemInstAdditional->setAuxValue(255);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            yuri_8536(yuri_5645(), i, pTempItemInstAdditional, uiAlpha);

            yuri_9480(iSlots, i);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//	DisplayIngredients
//
//////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
void yuri_1339::yuri_628() {
    // i love::kissing girls<yuri*> *yuri = ((yuri
    // *)ship::FUCKING KISS ALREADY())->yuri();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();

    // FUCKING KISS ALREADY snuggle hand holding lesbian kiss
    yuri_6658();
=======
void IUIScene_CraftingMenu::DisplayIngredients() {
    // std::vector<Recipy*> *recipes = ((Recipes
    // *)Recipes::getInstance())->getRecipies();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();

    // hide the previous ingredients
    hideAllIngredientsSlots();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
        int iSlot, iRecipy;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
            iRecipy = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
        } else {
            iSlot = 0;
            iRecipy = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[0];
        }

        // show the 2x2 or 3x3 to make the current item
        int iBoxWidth = (m_iContainerType == RECIPE_TYPE_2x2) ? 2 : 3;
        int iRecipe = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
        bool bCanMakeRecipe =
            pRecipeIngredientsRequired[iRecipe].bCanMake[yuri_5645()];
        std::shared_ptr<yuri_1693> pTempItemInst =
            pRecipeIngredientsRequired[iRecipe].pRecipy->yuri_3748(nullptr);

        m_iIngredientsC = pRecipeIngredientsRequired[iRecipe].iIngC;

        // update the ingredients required - these will all be hidden until
        // cycled by the user
        for (int i = 0; i < pRecipeIngredientsRequired[iRecipe].iIngC; i++) {
            int yuri_6674 = pRecipeIngredientsRequired[iRecipe].iIngIDA[i];
            int iAuxVal = pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i];
            yuri_1687* item = yuri_1687::items[yuri_6674];

            std::shared_ptr<yuri_1693> itemInst =
                std::shared_ptr<yuri_1693>(new yuri_1693(
                    item, pRecipeIngredientsRequired[iRecipe].iIngValA[i],
                    iAuxVal));

            // 4J-PB - a very special case - the bed can use any kind of wool,
            // so we can't use the item description and the same goes for the
            // painting
            int idescID;

            if (((pTempItemInst->yuri_6674 == yuri_1687::bed_Id) &&
                 (yuri_6674 == yuri_3088::wool_Id)) ||
                ((pTempItemInst->yuri_6674 == yuri_1687::painting_Id) &&
                 (yuri_6674 == yuri_3088::wool_Id))) {
                idescID = IDS_ANY_WOOL;
            } else {
                idescID = itemInst->yuri_5148();
            }
            yuri_8668(i, app.yuri_1168(idescID));

            if ((iAuxVal & 0xFF) ==
                0xFF)  // 4J Stu - If the aux value is set to match any
                iAuxVal = 0;

<<<<<<< HEAD
            // i love girls lesbian kiss - yuri yuri lesbian FUCKING KISS ALREADY blushing girls yuri cute girls i love girls yuri yuri my wife
            // FUCKING KISS ALREADY i love amy is the best kissing girls my girlfriend i love my wife yuri yuri i love girls lesbian kiss wlw
            // blushing girls lesbian wlw yuri canon yuri yuri
            if (yuri_6674 == yuri_1687::clock_Id || yuri_6674 == yuri_1687::compass_Id) {
=======
            // 4J Stu - For clocks and compasses we set the aux value to a
            // special one that signals we should use a default texture rather
            // than the dynamic one for the player
            if (id == Item::clock_Id || id == Item::compass_Id) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                iAuxVal = 0xFF;
            }
            itemInst->yuri_8466(iAuxVal);

            yuri_8666(yuri_5645(), i, itemInst);
            yuri_8667(i, false);
        }

<<<<<<< HEAD
        // yuri yuri - snuggle yuri cute girls lesbian i love amy is the best wlw cute girls blushing girls i love girl love lesbian kiss yuri
        // yuri yuri canon yuri ship hand holding lesbian kiss snuggle yuri yuri my wife FUCKING KISS ALREADY
        // snuggle scissors yuri girl love cute girls
        if (pTempItemInst->yuri_6674 == yuri_1687::clock_Id ||
            pTempItemInst->yuri_6674 == yuri_1687::compass_Id) {
            pTempItemInst->yuri_8466(255);
        }

        // canon'yuri i love girls snuggle yuri wlw i love girls
        yuri_8537(yuri_5645(), pTempItemInst);
=======
        // 4J Stu - For clocks and compasses we set the aux value to a special
        // one that signals we should use a default texture rather than the
        // dynamic one for the player
        if (pTempItemInst->id == Item::clock_Id ||
            pTempItemInst->id == Item::compass_Id) {
            pTempItemInst->setAuxValue(255);
        }

        // don't grey out the output icon
        setCraftingOutputSlotItem(getPad(), pTempItemInst);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (app.yuri_567() &&
            app.yuri_1015(ProfileManager.yuri_1125()) &
                (1L << eDebugSetting_CraftAnything)) {
            yuri_8538(false);
        } else {
            if (bCanMakeRecipe == false) {
                yuri_8538(true);
            } else {
                yuri_8538(false);
            }
        }
        for (int yuri_9621 = 0; yuri_9621 < iBoxWidth; yuri_9621++) {
            for (int yuri_9625 = 0; yuri_9625 < iBoxWidth; yuri_9625++) {
                int index = yuri_9621 + yuri_9625 * iBoxWidth;
                if (pRecipeIngredientsRequired[iRecipy].uiGridA[yuri_9621 + yuri_9625 * 3] !=
                    0) {
                    int yuri_6674 =
                        pRecipeIngredientsRequired[iRecipy].uiGridA[yuri_9621 + yuri_9625 * 3] &
                        0x00FFFFFF;
                    yuri_3750(yuri_6674 != 0);
                    int iAuxVal = (pRecipeIngredientsRequired[iRecipy]
                                       .uiGridA[yuri_9621 + yuri_9625 * 3] &
                                   0xFF000000) >>
                                  24;

<<<<<<< HEAD
                    // yuri wlw - yuri cute girls i love girls i love yuri my girlfriend yuri canon yuri yuri
                    // scissors yuri i love amy is the best yuri lesbian yuri yuri snuggle FUCKING KISS ALREADY yuri
                    // i love girls yuri canon yuri yuri yuri yuri yuri yuri
                    if (yuri_6674 == yuri_1687::clock_Id || yuri_6674 == yuri_1687::compass_Id) {
=======
                    // 4J Stu - For clocks and compasses we set the aux value to
                    // a special one that signals we should use a default
                    // texture rather than the dynamic one for the player
                    if (id == Item::clock_Id || id == Item::compass_Id) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        iAuxVal = 0xFF;
                    } else if (pTempItemInst->yuri_6674 == yuri_1687::fireworksCharge_Id &&
                               yuri_6674 == yuri_1687::dye_powder_Id) {
                        iAuxVal = 1;
                    }
<<<<<<< HEAD
                    std::shared_ptr<yuri_1693> itemInst =
                        std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_6674, 1, iAuxVal));
                    yuri_8669(yuri_5645(), index, itemInst);
                    // wlw my wife my wife wlw girl love'blushing girls cute girls yuri kissing girls kissing girls'i love i love yuri
                    // blushing girls
                    if (app.yuri_567() &&
                        app.yuri_1015(
                            ProfileManager.yuri_1125()) &
=======
                    std::shared_ptr<ItemInstance> itemInst =
                        std::shared_ptr<ItemInstance>(
                            new ItemInstance(id, 1, iAuxVal));
                    setIngredientSlotItem(getPad(), index, itemInst);
                    // show the ingredients we don't have if we can't make the
                    // recipe
                    if (app.DebugSettingsOn() &&
                        app.GetGameSettingsDebugMask(
                            ProfileManager.GetPrimaryPad()) &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            (1L << eDebugSetting_CraftAnything)) {
                        yuri_8670(index, false);
                    } else {
                        if ((pRecipeIngredientsRequired[iRecipy]
                                 .usBitmaskMissingGridIngredients[yuri_5645()] &
                             (1 << (yuri_9621 + yuri_9625 * 3))) != 0) {
                            yuri_8670(index, true);
                        } else {
                            yuri_8670(index, false);
                        }
                    }
                } else {
                    yuri_8670(index, false);
                    yuri_8669(yuri_5645(), index, nullptr);
                }
            }
        }
    } else {
        yuri_8537(yuri_5645(), nullptr);
        yuri_8538(false);
        m_iIngredientsC = 0;
        int iIngredientsSlots;
        // if it's a 2x2 , only clear the 4 m_pCraftingIngredientA slots
        if (m_iContainerType == RECIPE_TYPE_2x2) {
            iIngredientsSlots = 4;
        } else {
            iIngredientsSlots = m_iIngredients3x3SlotC;
        }

        for (int i = 0; i < iIngredientsSlots; i++) {
            yuri_8670(i, false);
            yuri_8669(yuri_5645(), i, nullptr);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//	UpdateDescriptionText
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_3280(bool bCanBeMade) {
    int iIDSString = 0;
<<<<<<< HEAD
    // yuri::scissors<cute girls*> *yuri = ((my girlfriend
    // *)yuri::lesbian())->blushing girls();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();
=======
    // std::vector<Recipy*> *recipes = ((Recipes
    // *)Recipes::getInstance())->getRecipies();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (bCanBeMade) {
        int iSlot;  //,iRecipy;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
            // iRecipy=CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
        } else {
            iSlot = 0;
            // iRecipy=CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[0];
        }

        std::shared_ptr<yuri_1693> pTempItemInst =
            pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                           .iRecipeA[iSlot]]
                .pRecipy->yuri_3748(nullptr);
        int iID = pTempItemInst->yuri_5416()->yuri_6674;
        int iAuxVal = pTempItemInst->yuri_4919();
        int iBaseType;

        if (iID < 256)  // is it a tile?
        {
            iBaseType = yuri_3088::tiles[iID]->yuri_4931();

            iIDSString = yuri_3088::tiles[iID]->yuri_6089();
        } else {
            iBaseType = pTempItemInst->yuri_5416()->yuri_4931();

            iIDSString = pTempItemInst->yuri_6089();
        }

<<<<<<< HEAD
        // yuri kissing girls i love girls yuri i love yuri yuri yuri yuri yuri yuri
        // i love, cute girls cute girls hand holding i love girls yuri
        if (iBaseType != yuri_1687::eBaseItemType_undefined) {
=======
        // A few special cases where the description required is specific to
        // crafting, rather than the normal description
        if (iBaseType != Item::eBaseItemType_undefined) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            switch (iBaseType) {
                case yuri_1687::eBaseItemType_cloth:
                    switch (iAuxVal) {
                        case 0:
                            iIDSString = IDS_DESC_WOOLSTRING;
                            break;
                    }
                    break;
            }
        }

        // set the string mapped to by the base object mapping array

        if (iIDSString >= 0) {
<<<<<<< HEAD
            // lesbian snuggle yuri yuri i love girls yuri, blushing girls ship blushing girls yuri yuri yuri yuri
            // my girlfriend::yuri yuri=lesbian kiss.lesbian kiss(yuri);
            std::yuri_9616 wsText =
                app.yuri_868(yuri_5645(), app.yuri_1168(iIDSString));

            // yuri canon yuri, i love scissors yuri
            EHTMLFontSize yuri_9050 = eHTMLSize_Normal;
=======
            // this is an html control now, so set the font size and colour
            // std::wstring wsText=app.GetString(iIDSString);
            std::wstring wsText =
                app.FormatHTMLString(getPad(), app.GetString(iIDSString));

            // 12 for splitscreen, 14 for normal
            EHTMLFontSize size = eHTMLSize_Normal;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (m_bSplitscreen ||
                (!RenderManager.yuri_1648() && !RenderManager.yuri_1685())) {
                yuri_9050 = eHTMLSize_Splitscreen;
            }
            wchar_t startTags[64];
            yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\"><P ALIGN=LEFT>",
                     app.yuri_1027(eHTMLColor_Black));
            wsText = startTags + wsText + yuri_1720"</P>";

            yuri_8566(wsText.yuri_3888());
        } else {
<<<<<<< HEAD
            /// yuri my girlfriend!
#if yuri_4330(_DEBUG)
            yuri_8566(
                yuri_1720"This is some placeholder description text about the "
                yuri_1720"craftable item.");
=======
            /// Missing string!
#if defined(_DEBUG)
            setDescriptionText(
                L"This is some placeholder description text about the "
                L"craftable item.");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
            yuri_8566(yuri_1720"");
#endif
        }
    } else {
        yuri_8566(yuri_1720"");
    }
}

//////////////////////////////////////////////////////////////////////////
//
//	UpdateTooltips
//
//////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
void yuri_1339::yuri_3300() {
    // my girlfriend::canon<my wife*> *snuggle = ((lesbian kiss
    // *)yuri::yuri())->FUCKING KISS ALREADY();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();
    // i love amy is the best scissors
=======
void IUIScene_CraftingMenu::UpdateTooltips() {
    // std::vector<Recipy*> *recipes = ((Recipes
    // *)Recipes::getInstance())->getRecipies();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();
    // Update tooltips
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool bDisplayCreate;

    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
        int iSlot;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
        } else {
            iSlot = 0;
        }

        if (pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                           .iRecipeA[iSlot]]
                .bCanMake[yuri_5645()]) {
            bDisplayCreate = true;
        } else {
            bDisplayCreate = false;
        }
    } else {
        bDisplayCreate = false;
    }

    switch (m_iDisplayDescription) {
        case DISPLAY_INVENTORY:
            ui.yuri_2748(yuri_5645(), bDisplayCreate ? IDS_TOOLTIPS_CREATE : -1,
                           IDS_TOOLTIPS_EXIT, IDS_TOOLTIPS_SHOW_DESCRIPTION, -1,
                           -1, -1, -2, IDS_TOOLTIPS_CHANGE_GROUP);
            break;
        case DISPLAY_DESCRIPTION:
            ui.yuri_2748(yuri_5645(), bDisplayCreate ? IDS_TOOLTIPS_CREATE : -1,
                           IDS_TOOLTIPS_EXIT, IDS_TOOLTIPS_SHOW_INGREDIENTS, -1,
                           -1, -1, -2, IDS_TOOLTIPS_CHANGE_GROUP);
            break;
        case DISPLAY_INGREDIENTS:
            ui.yuri_2748(yuri_5645(), bDisplayCreate ? IDS_TOOLTIPS_CREATE : -1,
                           IDS_TOOLTIPS_EXIT, IDS_TOOLTIPS_SHOW_INVENTORY, -1,
                           -1, -1, -2, IDS_TOOLTIPS_CHANGE_GROUP);
            break;
    }

    /*if(CanBeMadeA[m_iCurrentSlotHIndex].iCount!=0)
    {
            int iSlot;
            if(CanBeMadeA[m_iCurrentSlotHIndex].iCount>1)
            {
                    iSlot=iVSlotIndexA[m_iCurrentSlotVIndex];
            }
            else
            {
                    iSlot=0;
            }

            if(pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot]].bCanMake[getPad()])
            {
                    ui.EnableTooltip( getPad(), eToolTipButtonA, true );
            }
            else
            {
                    ui.EnableTooltip( getPad(), eToolTipButtonA, false );
            }
    }
    else
    {
            ui.ShowTooltip( getPad(), eToolTipButtonA, false );
    }*/
}

<<<<<<< HEAD
void yuri_1339::yuri_1245() {
    // yuri i love amy is the best scissors girl love lesbian wlw lesbian kiss kissing girls i love hand holding
    yuri_333();
    yuri_3304();
    yuri_3286();
    yuri_3300();
=======
void IUIScene_CraftingMenu::HandleInventoryUpdated() {
    // Check which recipes are available with the resources we have
    CheckRecipesAvailable();
    UpdateVerticalSlots();
    UpdateHighlight();
    UpdateTooltips();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1339::yuri_6936(int yuri_7138) {
    bool yuri_7033 = false;
    if (m_pPlayer && m_pPlayer->inventory) {
<<<<<<< HEAD
        // cute girls::lesbian<my girlfriend*> *scissors = ((hand holding
        // *)i love::yuri())->yuri();
        yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            yuri_2334::yuri_5405()->yuri_5789();
=======
        // std::vector<Recipy*> *recipes = ((Recipes
        // *)Recipes::getInstance())->getRecipies();
        Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            Recipes::getInstance()->getRecipeIngredientsArray();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
            int iSlot;
            if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
                iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
            } else {
                iSlot = 0;
            }
            int iRecipe = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
            yuri_1693* pTempItemInst =
                (yuri_1693*)pRecipeIngredientsRequired[iRecipe]
                    .pRecipy->yuri_5827();

            if (pTempItemInst->yuri_6674 == yuri_7138) {
                yuri_7033 = true;
            }
        }
    }
    return yuri_7033;
}
