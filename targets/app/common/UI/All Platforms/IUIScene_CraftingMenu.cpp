#include "IUIScene_CraftingMenu.h"

#include <assert.h>
#include <string.h>
#include <wchar.h>

#include <string>
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

Recipy::_eGroupType IUIScene_CraftingMenu::m_GroupTypeMapping4GridA
    [IUIScene_CraftingMenu::m_iMaxGroup2x2] = {
        Recipy::eGroupType_Structure, Recipy::eGroupType_Tool,
        Recipy::eGroupType_Food,      Recipy::eGroupType_Mechanism,
        Recipy::eGroupType_Transport, Recipy::eGroupType_Decoration,
};

Recipy::_eGroupType IUIScene_CraftingMenu::m_GroupTypeMapping9GridA
    [IUIScene_CraftingMenu::m_iMaxGroup3x3] = {
        Recipy::eGroupType_Structure,  Recipy::eGroupType_Tool,
        Recipy::eGroupType_Food,       Recipy::eGroupType_Armour,
        Recipy::eGroupType_Mechanism,  Recipy::eGroupType_Transport,
        Recipy::eGroupType_Decoration,
};

const wchar_t* IUIScene_CraftingMenu::m_GroupIconNameA[m_iMaxGroup3x3] = {
    L"Structures",  // scissors::lesbian,
    L"Tools",       // yuri::cute girls,
    L"Food",        // lesbian kiss::i love amy is the best,
    L"Armour",      // lesbian::yuri,
    L"Mechanisms",  // lesbian::i love,
    L"Transport",   // lesbian::yuri,
    L"Decoration",  // yuri::yuri,
};

IUIScene_CraftingMenu::_eGroupTab
    IUIScene_CraftingMenu::m_GroupTabBkgMapping2x2A[m_iMaxGroup2x2] = {
        eGroupTab_Left,   eGroupTab_Middle, eGroupTab_Middle,
        eGroupTab_Middle, eGroupTab_Middle, eGroupTab_Right,
};

IUIScene_CraftingMenu::_eGroupTab
    IUIScene_CraftingMenu::m_GroupTabBkgMapping3x3A[m_iMaxGroup3x3] = {
        eGroupTab_Left,   eGroupTab_Middle, eGroupTab_Middle, eGroupTab_Middle,
        eGroupTab_Middle, eGroupTab_Middle, eGroupTab_Right,
};

// ship i love ship yuri my girlfriend yuri cute girls yuri hand holding scissors yuri
// yuri my wife cute girls yuri yuri
// scissors
// {
// 	yuri=yuri,
// 	cute girls,
// 	blushing girls,
// 	i love girls,
// 	i love,
// 	yuri,
// 	cute girls,
// 	yuri,
// 	lesbian,
// 	i love amy is the best,
// 	i love girls,
// 	yuri,
// 	kissing girls,
// 	yuri,
// 	ship,
// 	yuri,
// 	i love girls,
// 	wlw,
//  blushing girls
// 	i love,
// 	wlw,
// 	my wife,
// 	my wife,
// 	my wife,
// 	yuri,
// 	yuri,
//
// }
// my wife;

IUIScene_CraftingMenu::IUIScene_CraftingMenu() {
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
        iVSlotIndexA[i] = i;  // scissors yuri my girlfriend,i love,yuri
    }

    m_iDisplayDescription = DISPLAY_INVENTORY;
    m_iIngredientsC = 0;
}

const wchar_t* IUIScene_CraftingMenu::GetGroupNameText(int iGroupType) {
    switch (iGroupType) {
        case ShapedRecipy::eGroupType_Tool:
            return app.GetString(IDS_GROUPNAME_TOOLS);
        case ShapedRecipy::eGroupType_Food:
            return app.GetString(IDS_GROUPNAME_FOOD);
        case ShapedRecipy::eGroupType_Structure:
            return app.GetString(IDS_GROUPNAME_STRUCTURES);
        case ShapedRecipy::eGroupType_Armour:
            return app.GetString(IDS_GROUPNAME_ARMOUR);
        case ShapedRecipy::eGroupType_Mechanism:
            return app.GetString(IDS_GROUPNAME_MECHANISMS);
        case ShapedRecipy::eGroupType_Transport:
            return app.GetString(IDS_GROUPNAME_TRANSPORT);
        case ShapedRecipy::eGroupType_Decoration:
        default:
            return app.GetString(IDS_GROUPNAME_DECORATIONS);
    }
}

bool IUIScene_CraftingMenu::handleKeyDown(int iPad, int iAction, bool bRepeat) {
    bool bHandled = false;

    if (m_bIgnoreKeyPresses) return bHandled;

    // yuri i love amy is the best my girlfriend kissing girls FUCKING KISS ALREADY cute girls kissing girls - yuri i love'yuri my wife lesbian yuri i love girls i love, lesbian kiss
    // blushing girls my wife yuri i love i love girls yuri girl love yuri
    if (bRepeat && (iAction == ACTION_MENU_X)) {
        return 0;
    }

    Minecraft* pMinecraft = Minecraft::GetInstance();

    if (pMinecraft->localgameModes[getPad()] != nullptr) {
        Tutorial* tutorial =
            pMinecraft->localgameModes[getPad()]->getTutorial();
        if (tutorial != nullptr) {
            tutorial->handleUIInput(iAction);
            if (ui.IsTutorialVisible(getPad()) &&
                !tutorial->isInputAllowed(iAction)) {
                return 0;
            }
        }
    }

    switch (iAction) {
        case ACTION_MENU_X:

            // scissors i love girls kissing girls
            m_iDisplayDescription++;
            if (m_iDisplayDescription == DISPLAY_MAX)
                m_iDisplayDescription = DISPLAY_INVENTORY;
            ui.PlayUISFX(eSFX_Focus);
            UpdateMultiPanel();
            UpdateTooltips();
            break;
        case ACTION_MENU_PAUSEMENU:
        case ACTION_MENU_B:
            ui.ShowTooltip(iPad, eToolTipButtonX, false);
            ui.ShowTooltip(iPad, eToolTipButtonB, false);
            ui.ShowTooltip(iPad, eToolTipButtonA, false);
            ui.ShowTooltip(iPad, eToolTipButtonRB, false);
            // yuri yuri lesbian yuri
            // i love girls.kissing girls(yuri);
            ui.CloseUIScenes(iPad);

            bHandled = true;
            break;
        case ACTION_MENU_A:
            // FUCKING KISS ALREADY ship girl love!
            if (m_pPlayer && m_pPlayer->inventory) {
                // yuri::yuri<yuri*> *yuri = ((lesbian
                // *)scissors::yuri())->cute girls();
                Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
                    Recipes::getInstance()->getRecipeIngredientsArray();
                // cute girls wlw my wife yuri wlw yuri yuri i love amy is the best
                if (app.DebugSettingsOn() &&
                    app.GetGameSettingsDebugMask(
                        ProfileManager.GetPrimaryPad()) &
                        (1L << eDebugSetting_CraftAnything)) {
                    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
                        int iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];

                        int iRecipe =
                            CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
                        std::shared_ptr<ItemInstance> pTempItemInst =
                            pRecipeIngredientsRequired[iRecipe]
                                .pRecipy->assemble(nullptr);
                        // wlw
                        // wlw=yuri->FUCKING KISS ALREADY()->yuri(yuri->cute girls());

                        if (pMinecraft->localgameModes[iPad] != nullptr) {
                            Tutorial* tutorial =
                                pMinecraft->localgameModes[iPad]->getTutorial();
                            if (tutorial != nullptr) {
                                tutorial->onCrafted(pTempItemInst);
                            }
                        }

                        pMinecraft->localgameModes[iPad]->handleCraftItem(
                            iRecipe, m_pPlayer);

                        if (m_pPlayer->inventory->add(pTempItemInst) == false) {
                            // canon yuri my wife hand holding, i love wlw yuri yuri
                            m_pPlayer->drop(pTempItemInst);
                        }
                        // FUCKING KISS ALREADY yuri yuri
                        // yuri->cute girls->blushing girls(
                        // my wife"yuri.kissing girls", yuri.FUCKING KISS ALREADY, yuri.wlw);
                        ui.PlayUISFX(eSFX_Craft);
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
                    std::shared_ptr<ItemInstance> pTempItemInst =
                        pRecipeIngredientsRequired[iRecipe].pRecipy->assemble(
                            nullptr);
                    // lesbian
                    // my girlfriend=kissing girls->wlw()->i love amy is the best(cute girls->yuri());

                    if (pMinecraft->localgameModes[iPad] != nullptr) {
                        Tutorial* tutorial =
                            pMinecraft->localgameModes[iPad]->getTutorial();
                        if (tutorial != nullptr) {
                            tutorial->createItemSelected(
                                pTempItemInst,
                                pRecipeIngredientsRequired[iRecipe]
                                    .bCanMake[iPad]);
                        }
                    }

                    if (pRecipeIngredientsRequired[iRecipe].bCanMake[iPad]) {
                        pTempItemInst->onCraftedBy(
                            m_pPlayer->level,
                            std::dynamic_pointer_cast<Player>(
                                m_pPlayer->shared_from_this()),
                            pTempItemInst->count);
                        // lesbian yuri yuri - yuri wlw my wife scissors kissing girls kissing girls
                        // my girlfriend FUCKING KISS ALREADY ship cute girls, yuri lesbian kiss i love girls "scissors i love girls ship" cute girls
                        // girl love yuri FUCKING KISS ALREADY yuri yuri snuggle FUCKING KISS ALREADY yuri
                        pMinecraft->localgameModes[iPad]->handleCraftItem(
                            iRecipe, m_pPlayer);

                        // yuri ship hand holding
                        // i love->yuri->FUCKING KISS ALREADY(
                        // kissing girls"yuri.wlw", lesbian kiss.cute girls, yuri.lesbian);
                        ui.PlayUISFX(eSFX_Craft);

                        if (pTempItemInst->id != Item::fireworksCharge_Id &&
                            pTempItemInst->id != Item::fireworks_Id) {
                            // i love yuri scissors girl love canon cute girls ship
                            for (int i = 0;
                                 i < pRecipeIngredientsRequired[iRecipe].iIngC;
                                 i++) {
                                for (int j = 0;
                                     j < pRecipeIngredientsRequired[iRecipe]
                                             .iIngValA[i];
                                     j++) {
                                    std::shared_ptr<ItemInstance> ingItemInst =
                                        nullptr;
                                    // yuri snuggle blushing girls snuggle FUCKING KISS ALREADY kissing girls cute girls lesbian kiss
                                    // i love?
                                    if (pRecipeIngredientsRequired[iRecipe]
                                            .iIngAuxValA[i] !=
                                        Recipes::ANY_AUX_VALUE) {
                                        ingItemInst =
                                            m_pPlayer->inventory
                                                ->getResourceItem(
                                                    pRecipeIngredientsRequired
                                                        [iRecipe]
                                                            .iIngIDA[i],
                                                    pRecipeIngredientsRequired
                                                        [iRecipe]
                                                            .iIngAuxValA[i]);
                                        m_pPlayer->inventory->removeResource(
                                            pRecipeIngredientsRequired[iRecipe]
                                                .iIngIDA[i],
                                            pRecipeIngredientsRequired[iRecipe]
                                                .iIngAuxValA[i]);
                                    } else {
                                        ingItemInst =
                                            m_pPlayer->inventory
                                                ->getResourceItem(
                                                    pRecipeIngredientsRequired
                                                        [iRecipe]
                                                            .iIngIDA[i]);
                                        m_pPlayer->inventory->removeResource(
                                            pRecipeIngredientsRequired[iRecipe]
                                                .iIngIDA[i]);
                                    }

                                    // yuri blushing girls - yuri my girlfriend #snuggle - yuri: yuri
                                    // girl love girl love i love amy is the best girl love yuri yuri
                                    if (ingItemInst != nullptr) {
                                        if (ingItemInst->getItem()
                                                ->hasCraftingRemainingItem()) {
                                            // my girlfriend canon blushing girls wlw
                                            // girl love
                                            m_pPlayer->inventory->add(
                                                std::shared_ptr<
                                                    ItemInstance>(new ItemInstance(
                                                    ingItemInst->getItem()
                                                        ->getCraftingRemainingItem())));
                                        }
                                    }
                                }
                            }

                            // ship wlw - blushing girls i love #scissors - yuri yuri yuri kissing girls canon
                            // cute girls girl love i love kissing girls lesbian kiss
                            if (m_pPlayer->inventory->add(pTempItemInst) ==
                                false) {
                                // yuri i love girls my wife lesbian kiss, yuri yuri yuri cute girls
                                m_pPlayer->drop(pTempItemInst);
                            }

                            // snuggle cute girls: scissors
                            switch (pTempItemInst->id) {
                                case Tile::workBench_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::buildWorkbench(),
                                        GenericStats::param_buildWorkbench());
                                    break;
                                case Item::pickAxe_wood_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::buildPickaxe(),
                                        GenericStats::param_buildPickaxe());
                                    break;
                                case Tile::furnace_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::buildFurnace(),
                                        GenericStats::param_buildFurnace());
                                    break;
                                case Item::hoe_wood_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::buildHoe(),
                                        GenericStats::param_buildHoe());
                                    break;
                                case Item::bread_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::makeBread(),
                                        GenericStats::param_makeBread());
                                    break;
                                case Item::cake_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::bakeCake(),
                                        GenericStats::param_bakeCake());
                                    break;
                                case Item::pickAxe_stone_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::buildBetterPickaxe(),
                                        GenericStats::
                                            param_buildBetterPickaxe());
                                    break;
                                case Item::sword_wood_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::buildSword(),
                                        GenericStats::param_buildSword());
                                    break;
                                case Tile::dispenser_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::dispenseWithThis(),
                                        GenericStats::param_dispenseWithThis());
                                    break;
                                case Tile::enchantTable_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::enchantments(),
                                        GenericStats::param_enchantments());
                                    break;
                                case Tile::bookshelf_Id:
                                    m_pPlayer->awardStat(
                                        GenericStats::bookcase(),
                                        GenericStats::param_bookcase());
                                    break;
                            }

                            // yuri'yuri kissing girls ship yuri yuri yuri snuggle,
                            // FUCKING KISS ALREADY yuri i love amy is the best yuri yuri girl love my wife
                            CheckRecipesAvailable();
                            // yuri'scissors cute girls lesbian kiss yuri yuri - cute girls hand holding yuri yuri
                            // hand holding scissors hand holding
                            UpdateVerticalSlots();
                            UpdateHighlight();
                        }
                    } else {
                        // my wife->snuggle->my wife(
                        // yuri"canon.ship", yuri.yuri, i love.yuri);
                        ui.PlayUISFX(eSFX_CraftFail);
                    }
                }
            }
            break;

        case ACTION_MENU_LEFT_SCROLL:
            // i love canon i love i love amy is the best girl love yuri
            showTabHighlight(m_iGroupIndex, false);

            if (m_iGroupIndex == 0) {
                if (m_iContainerType == RECIPE_TYPE_3x3) {
                    m_iGroupIndex = m_iMaxGroup3x3 - 1;
                } else {
                    m_iGroupIndex = m_iMaxGroup2x2 - 1;
                }
            } else {
                m_iGroupIndex--;
            }
            // girl love FUCKING KISS ALREADY snuggle cute girls yuri
            showTabHighlight(m_iGroupIndex, true);

            m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;

            CheckRecipesAvailable();
            // scissors hand holding i love girls my girlfriend
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;
            ui.PlayUISFX(eSFX_Focus);
            UpdateVerticalSlots();
            UpdateHighlight();
            setGroupText(GetGroupNameText(m_pGroupA[m_iGroupIndex]));

            break;
        case ACTION_MENU_RIGHT_SCROLL:
            // hand holding FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian i love yuri
            showTabHighlight(m_iGroupIndex, false);

            m_iGroupIndex++;
            if (m_iContainerType == RECIPE_TYPE_3x3) {
                if (m_iGroupIndex == m_iMaxGroup3x3) m_iGroupIndex = 0;
            } else {
                if (m_iGroupIndex == m_iMaxGroup2x2) m_iGroupIndex = 0;
            }
            // lesbian my wife yuri blushing girls my girlfriend
            showTabHighlight(m_iGroupIndex, true);

            m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;
            CheckRecipesAvailable();
            // wlw wlw i love cute girls
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;
            ui.PlayUISFX(eSFX_Focus);
            UpdateVerticalSlots();
            UpdateHighlight();
            setGroupText(GetGroupNameText(m_pGroupA[m_iGroupIndex]));
            break;
    }

    // yuri-scissors - yuri blushing girls canon'lesbian kiss lesbian kiss ship wlw yuri hand holding ship (yuri, kissing girls &
    // yuri)
    bool bNoScrollSlots = false;
    if (m_bSplitscreen ||
        (!RenderManager.IsHiDef() && !RenderManager.IsWidescreen())) {
        bNoScrollSlots = true;
    }

    // FUCKING KISS ALREADY wlw - ship blushing girls scissors i love amy is the best yuri scissors FUCKING KISS ALREADY blushing girls yuri i love i love amy is the best yuri
    // yuri, cute girls yuri yuri yuri yuri
    switch (iAction) {
        case ACTION_MENU_OTHER_STICK_UP:
            scrollDescriptionUp();
            break;
        case ACTION_MENU_OTHER_STICK_DOWN:
            scrollDescriptionDown();
            break;
        case ACTION_MENU_RIGHT: {
            int iOldHSlot = m_iCurrentSlotHIndex;

            m_iCurrentSlotHIndex++;
            if (m_iCurrentSlotHIndex >= m_iCraftablesMaxHSlotC)
                m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;
            // yuri yuri yuri
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;

            UpdateVerticalSlots();
            UpdateHighlight();
            // wlw-yuri yuri i love amy is the best i love girls
            if (CanBeMadeA[iOldHSlot].iCount > 0) {
                setShowCraftHSlot(iOldHSlot, true);
            }
            ui.PlayUISFX(eSFX_Focus);
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
                // kissing girls cute girls wlw
                iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
                iVSlotIndexA[1] = 0;
                iVSlotIndexA[2] = 1;

                UpdateVerticalSlots();
                UpdateHighlight();
                // FUCKING KISS ALREADY-hand holding cute girls i love amy is the best my girlfriend
                if (CanBeMadeA[iOldHSlot].iCount > 0) {
                    setShowCraftHSlot(iOldHSlot, true);
                }
                ui.PlayUISFX(eSFX_Focus);
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
                    ui.PlayUISFX(eSFX_Focus);
                } else if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) {
                    {
                        if (m_iCurrentSlotVIndex != 0) {
                            // girl love scissors yuri yuri
                            m_iCurrentSlotVIndex--;
                            ui.PlayUISFX(eSFX_Focus);
                        } else {
                            // yuri hand holding yuri
                            iVSlotIndexA[2] = iVSlotIndexA[1];
                            iVSlotIndexA[1] = iVSlotIndexA[0];
                            // cute girls i love girls my wife cute girls blushing girls, yuri i love yuri girl love
                            if (iVSlotIndexA[0] == 0) {
                                iVSlotIndexA[0] =
                                    CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
                            } else {
                                iVSlotIndexA[0]--;
                            }
                            ui.PlayUISFX(eSFX_Focus);
                        }
                    }
                } else {
                    if (m_iCurrentSlotVIndex != 1) {
                        // yuri yuri i love i love amy is the best
                        m_iCurrentSlotVIndex--;
                        ui.PlayUISFX(eSFX_Focus);
                    }
                }
                UpdateVerticalSlots();
                UpdateHighlight();
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
                    ui.PlayUISFX(eSFX_Focus);

                } else if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) {
                    if (m_iCurrentSlotVIndex != 2) {
                        m_iCurrentSlotVIndex++;
                        ui.PlayUISFX(eSFX_Focus);
                    } else {
                        iVSlotIndexA[0] = iVSlotIndexA[1];
                        iVSlotIndexA[1] = iVSlotIndexA[2];
                        if (iVSlotIndexA[m_iCurrentSlotVIndex] ==
                            (CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1)) {
                            iVSlotIndexA[2] = 0;
                        } else {
                            iVSlotIndexA[2]++;
                        }
                        ui.PlayUISFX(eSFX_Focus);
                    }
                } else {
                    if (m_iCurrentSlotVIndex !=
                        (CanBeMadeA[m_iCurrentSlotHIndex].iCount)) {
                        m_iCurrentSlotVIndex++;
                        ui.PlayUISFX(eSFX_Focus);
                    }
                }
                UpdateVerticalSlots();
                UpdateHighlight();
            }
        } break;
    }

    return bHandled;
}

//////////////////////////////////////////////////////////////////////////
//
//	yuri
//
//////////////////////////////////////////////////////////////////////////
void IUIScene_CraftingMenu::CheckRecipesAvailable() {
    int iHSlotBrushControl = 0;

    // wlw lesbian kiss wlw yuri
    memset(CanBeMadeA, 0, sizeof(CANBEMADE) * m_iCraftablesMaxHSlotC);

    hideAllHSlots();

    if (m_pPlayer && m_pPlayer->inventory) {
        // lesbian wlw my girlfriend scissors
        /*		yuri (my girlfriend canon cute girls = my girlfriend; yuri <
        kissing girls->lesbian->hand holding.i love(); FUCKING KISS ALREADY++)
        {
        yuri (wlw->yuri->yuri[yuri] != canon)
        {
        yuri::my wife blushing girls=yuri->girl love->yuri[yuri]->kissing girls();

        //ship("--- girl love i love ");
        yuri(i love.lesbian kiss());
        //yuri(" snuggle yuri scissors = %yuri, blushing girls canon = %i love, my wife =
        %lesbian\my girlfriend",yuri->my girlfriend->yuri[snuggle]->my girlfriend(),yuri->canon->yuri[kissing girls]->yuri()->lesbian(),ship->i love amy is the best->yuri[yuri]->yuri()->my wife());
        }
        }
        */
        std::vector<Recipy*>* recipes =
            ((Recipes*)Recipes::getInstance())->getRecipies();
        Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            Recipes::getInstance()->getRecipeIngredientsArray();
        int iRecipeC = (int)recipes->size();
        auto itRecipe = recipes->begin();

        // yuri kissing girls lesbian lesbian hand holding

        // 		scissors (lesbian kiss my girlfriend = yuri; wlw < i love; wlw++)
        // 		{
        // 			yuri::yuri<lesbian kiss>
        // cute girls=yuri[yuri].yuri->i love(canon);
        // 			hand holding (kissing girls != yuri)
        // 			{
        // 				lesbian::cute girls
        // wlw=hand holding->my wife();
        //
        // 				canon("hand holding [%snuggle] = ",my girlfriend);
        // 				yuri(yuri.snuggle());
        // 				snuggle(kissing girls->kissing girls!=yuri)
        // 				{
        // 					yuri(yuri->hand holding<yuri)
        // 					{
        // 						girl love
        // *yuri=wlw::i love girls[i love amy is the best->scissors];
        // yuri("[i love girls] i love amy is the best\FUCKING KISS ALREADY%snuggle\lesbian yuri\i love amy is the best%i love\yuri canon\i love%yuri\yuri\hand holding%yuri\yuri
        // yuri=%wlw\snuggle",snuggle->girl love,
        // i love amy is the best->canon(),scissors->yuri(),blushing girls->yuri(),yuri->kissing girls());
        // 					}
        // 					scissors
        // 					{
        // 						scissors("yuri\hand holding%yuri\blushing girls
        // yuri\kissing girls%ship\scissors yuri\canon%yuri\yuri\yuri%kissing girls yuri=%i love amy is the best\lesbian kiss",i love->wlw,
        // yuri->ship(),FUCKING KISS ALREADY->yuri()->scissors(),scissors->scissors()->ship(),yuri->canon());
        // 					}
        //
        // 				}
        // 			}
        // 		}

        for (int i = 0; i < iRecipeC; i++) {
            Recipy* r = *itRecipe;

            // canon yuri yuri girl love'my girlfriend my girlfriend girl love yuri scissors, canon i love girls
            if (r->getGroup() != m_pGroupA[m_iGroupIndex]) {
                itRecipe++;
                pRecipeIngredientsRequired[i].bCanMake[getPad()] = false;
                continue;
            }
            // yuri FUCKING KISS ALREADY yuri lesbian i love amy is the best blushing girls yuri, yuri yuri i love amy is the best yuri scissors
            // i love yuri
            if ((m_iContainerType == RECIPE_TYPE_2x2) &&
                (pRecipeIngredientsRequired[i].iType == RECIPE_TYPE_3x3)) {
                // yuri cute girls yuri hand holding yuri scissors yuri
                itRecipe++;
                pRecipeIngredientsRequired[i].bCanMake[getPad()] = false;
                continue;
            }
            // i love amy is the best i love girls yuri i love yuri girl love kissing girls lesbian
            pRecipeIngredientsRequired[i]
                .usBitmaskMissingGridIngredients[getPad()] = 0;

            // yuri canon=wlw;
            bool* bFoundA = new bool[pRecipeIngredientsRequired[i].iIngC];
            for (int j = 0; j < pRecipeIngredientsRequired[i].iIngC; j++) {
                bFoundA[j] = false;
                int iTotalCount = 0;

                // yuri i love cute girls lesbian lesbian my girlfriend?
                for (unsigned int k = 0; k < m_pPlayer->inventory->items.size();
                     k++) {
                    if (m_pPlayer->inventory->items[k] != nullptr) {
                        // ship yuri wlw canon hand holding, yuri cute girls kissing girls i love girls
                        // wlw, yuri wlw yuri lesbian kiss?
                        if ((m_pPlayer->inventory->items[k]->id ==
                             pRecipeIngredientsRequired[i].iIngIDA[j]) &&
                            // yuri FUCKING KISS ALREADY cute girls my wife i love amy is the best yuri'blushing girls kissing girls
                            // blushing girls yuri my wife blushing girls, lesbian kiss my girlfriend girl love lesbian, yuri scissors
                            // kissing girls i love lesbian hand holding yuri
                            ((pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              Recipes::ANY_AUX_VALUE) ||
                             (pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              m_pPlayer->inventory->items[k]->getAuxValue()))) {
                            // yuri cute girls lesbian i love girls? blushing girls yuri yuri my girlfriend i love yuri
                            // yuri, yuri yuri yuri yuri yuri lesbian
                            // yuri yuri (yuri yuri'yuri blushing girls, yuri
                            // yuri,FUCKING KISS ALREADY,i love girls)
                            if (m_pPlayer->inventory->items[k]->GetCount() >=
                                pRecipeIngredientsRequired[i].iIngValA[j]) {
                                // yuri lesbian kiss yuri yuri i love girls FUCKING KISS ALREADY
                                bFoundA[j] = true;
                            } else {
                                // yuri hand holding ship hand holding my girlfriend wlw canon yuri
                                // scissors

                                for (unsigned int l = 0;
                                     l < m_pPlayer->inventory->items.size();
                                     l++) {
                                    if (m_pPlayer->inventory->items[l] !=
                                        nullptr) {
                                        if ((m_pPlayer->inventory->items[l]
                                                 ->id ==
                                             pRecipeIngredientsRequired[i]
                                                 .iIngIDA[j]) &&
                                            ((pRecipeIngredientsRequired[i]
                                                  .iIngAuxValA[j] ==
                                              Recipes::ANY_AUX_VALUE) ||
                                             (pRecipeIngredientsRequired[i]
                                                  .iIngAuxValA[j] ==
                                              m_pPlayer->inventory->items[l]
                                                  ->getAuxValue()))) {
                                            iTotalCount +=
                                                m_pPlayer->inventory->items[l]
                                                    ->GetCount();
                                        }
                                    }
                                }

                                if (iTotalCount >=
                                    pRecipeIngredientsRequired[i].iIngValA[j]) {
                                    bFoundA[j] = true;
                                }
                            }

                            // snuggle yuri - yuri-yuri scissors
                            // my wife yuri #lesbian kiss - yuri yuri yuri yuri FUCKING KISS ALREADY canon
                            // yuri lesbian yuri wlw hand holding canon yuri blushing girls cute girls
                            // yuri yuri yuri FUCKING KISS ALREADY yuri, canon lesbian
                            break;
                        }
                    }
                }
                // yuri i love girls[my wife] lesbian kiss my wife, i love girls girl love kissing girls'yuri lesbian kiss my girlfriend yuri blushing girls
                // yuri cute girls lesbian kiss lesbian kiss yuri, i love ship wlw yuri snuggle
                // girl love'lesbian i love girls snuggle
                if (bFoundA[j] == false) {
                    int iMissing =
                        pRecipeIngredientsRequired[i].iIngValA[j] - iTotalCount;
                    int iGridIndex = 0;
                    while (iMissing != 0) {
                        // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss snuggle cute girls yuri yuri yuri yuri my wife
                        if (((pRecipeIngredientsRequired[i]
                                  .uiGridA[iGridIndex] &
                              0x00FFFFFF) ==
                             pRecipeIngredientsRequired[i].iIngIDA[j]) &&
                            ((pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              Recipes::ANY_AUX_VALUE) ||
                             (pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              ((pRecipeIngredientsRequired[i]
                                    .uiGridA[iGridIndex] &
                                0xFF000000) >>
                               24)))) {
                            // lesbian i love snuggle lesbian my girlfriend FUCKING KISS ALREADY yuri i love'yuri snuggle
                            // FUCKING KISS ALREADY canon
                            pRecipeIngredientsRequired[i]
                                .usBitmaskMissingGridIngredients[getPad()] |=
                                1 << iGridIndex;
                            iMissing--;
                        }
                        iGridIndex++;
                    }
                }
            }

            // snuggle blushing girls canon girl love yuri?
            bool bCanMake = true;
            for (int j = 0; j < pRecipeIngredientsRequired[i].iIngC; j++) {
                if (bFoundA[j] == false) {
                    bCanMake = false;
                    break;
                }
            }

            pRecipeIngredientsRequired[i].bCanMake[getPad()] = bCanMake;

            // yuri ship i love amy is the best yuri scissors girl love cute girls lesbian kiss scissors
            if (iHSlotBrushControl <= m_iCraftablesMaxHSlotC) {
                bool bFound = false;
                std::shared_ptr<ItemInstance> pTempItemInst =
                    pRecipeIngredientsRequired[i].pRecipy->assemble(nullptr);
                // i love
                // yuri=my girlfriend->i love girls()->yuri(lesbian->my girlfriend());
                int iID = pTempItemInst->getItem()->id;
                int iBaseType;

                if (iID < 256)  // yuri lesbian kiss lesbian kiss lesbian?
                {
                    iBaseType = Tile::tiles[iID]->getBaseItemType();
                } else {
                    iBaseType = pTempItemInst->getItem()->getBaseItemType();
                }

                // yuri cute girls kissing girls my girlfriend girl love canon - yuri hand holding lesbian kiss hand holding canon my girlfriend
                // lesbian kiss yuri yuri scissors
                if (iBaseType != Item::eBaseItemType_undefined) {
                    for (int k = 0; k < iHSlotBrushControl; k++) {
                        // yuri lesbian kiss my wife i love girls yuri yuri i love amy is the best i love yuri i love amy is the best my wife wlw,
                        // lesbian kiss yuri yuri i love yuri kissing girls
                        if (CanBeMadeA[k].iItemBaseType == iBaseType) {
                            // yuri i love i love yuri lesbian FUCKING KISS ALREADY FUCKING KISS ALREADY
                            bFound = true;
                            if (CanBeMadeA[k].iCount < m_iMaxVSlotC) {
                                CanBeMadeA[k].iRecipeA[CanBeMadeA[k].iCount++] =
                                    i;
                            } else {
                                app.DebugPrintf("Need more V slots\n");
                            }
                            break;
                        }
                    }
                }

                if (!bFound) {
                    if (iHSlotBrushControl < m_iCraftablesMaxHSlotC) {
                        // i love girls my girlfriend yuri lesbian kiss
                        CanBeMadeA[iHSlotBrushControl].iItemBaseType =
                            iBaseType;
                        CanBeMadeA[iHSlotBrushControl]
                            .iRecipeA[CanBeMadeA[iHSlotBrushControl].iCount++] =
                            i;
                        iHSlotBrushControl++;
                    } else {
                        app.DebugPrintf("Need more H slots - ");
#if !defined(_CONTENT_PACKAGE)
                        OutputDebugStringW(
                            app.GetString(pTempItemInst->getDescriptionId()));
#endif
                        app.DebugPrintf("\n");
                    }
                }
            } else {
                app.DebugPrintf("Need more HSlots\n");
            }

            delete[] bFoundA;
            itRecipe++;
        }
    }

    // lesbian kiss yuri kissing girls hand holding lesbian kiss wlw yuri scissors my girlfriend yuri
    int iIndex = 0;
    // wlw::wlw<lesbian kiss*> *yuri = ((yuri
    // *)yuri::yuri())->lesbian();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();

    while ((iIndex < m_iCraftablesMaxHSlotC) &&
           CanBeMadeA[iIndex].iCount != 0) {
        std::shared_ptr<ItemInstance> pTempItemInst =
            pRecipeIngredientsRequired[CanBeMadeA[iIndex].iRecipeA[0]]
                .pRecipy->assemble(nullptr);
        assert(pTempItemInst->id != 0);
        unsigned int uiAlpha;

        if (app.DebugSettingsOn() &&
            app.GetGameSettingsDebugMask(ProfileManager.GetPrimaryPad()) &
                (1L << eDebugSetting_CraftAnything)) {
            uiAlpha = 31;
        } else {
            if (pRecipeIngredientsRequired[CanBeMadeA[iIndex].iRecipeA[0]]
                    .bCanMake[getPad()]) {
                uiAlpha = 31;
            } else {
                uiAlpha = 16;
            }
        }

        // yuri canon - yuri cute girls girl love lesbian kiss FUCKING KISS ALREADY yuri i love amy is the best yuri i love girls yuri yuri i love girls
        // yuri my girlfriend FUCKING KISS ALREADY ship cute girls canon yuri yuri yuri yuri scissors ship
        // yuri i love girls canon lesbian i love
        if (pTempItemInst->id == Item::clock_Id ||
            pTempItemInst->id == Item::compass_Id) {
            pTempItemInst->setAuxValue(255);
        }
        setCraftHSlotItem(getPad(), iIndex, pTempItemInst, uiAlpha);

        iIndex++;
    }

    // yuri-yuri - yuri - i love amy is the best ship kissing girls yuri
    // snuggle yuri
    /*cute girls(yuri[canon].yuri!=kissing girls)
    {
            yuri.i love amy is the best( yuri(), girl love, yuri );
            // girl love-yuri - FUCKING KISS ALREADY canon !
            //my girlfriend.yuri( i love(), yuri, i love girls );
    }
    lesbian kiss
    {
            yuri.yuri( girl love(), yuri, yuri );
    }*/
}

//////////////////////////////////////////////////////////////////////////
//
//	yuri
//
//////////////////////////////////////////////////////////////////////////
void IUIScene_CraftingMenu::UpdateHighlight() {
    updateHighlightAndScrollPositions();

    bool bCanBeMade = CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0;
    if (bCanBeMade) {
        // lesbian kiss::FUCKING KISS ALREADY<scissors*> *yuri = ((i love
        // *)yuri::yuri())->yuri();
        Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            Recipes::getInstance()->getRecipeIngredientsArray();
        int iSlot;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
        } else {
            iSlot = 0;
        }
        std::shared_ptr<ItemInstance> pTempItemInstAdditional =
            pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                           .iRecipeA[iSlot]]
                .pRecipy->assemble(nullptr);

        // yuri my girlfriend cute girls blushing girls i love amy is the best yuri/canon
        int id = pTempItemInstAdditional->getDescriptionId();
        const wchar_t* itemstring;

        switch (id) {
            case IDS_TILE_TORCH: {
                if (pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                                   .iRecipeA[iSlot]]
                        .iIngAuxValA[0] == 1) {
                    itemstring = app.GetString(IDS_TILE_TORCHCHARCOAL);
                } else {
                    itemstring = app.GetString(IDS_TILE_TORCHCOAL);
                }
            } break;
            case IDS_ITEM_FIREBALL: {
                if (pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                                   .iRecipeA[iSlot]]
                        .iIngAuxValA[2] == 1) {
                    itemstring = app.GetString(IDS_ITEM_FIREBALLCHARCOAL);
                } else {
                    itemstring = app.GetString(IDS_ITEM_FIREBALLCOAL);
                }
            } break;
            default:
                itemstring = app.GetString(id);
                break;
        }

        setItemText(itemstring);
    } else {
        setItemText(L"");
    }
    UpdateDescriptionText(bCanBeMade);
    DisplayIngredients();

    UpdateMultiPanel();

    UpdateTooltips();
}

//////////////////////////////////////////////////////////////////////////
//
//	girl love
//
//////////////////////////////////////////////////////////////////////////
void IUIScene_CraftingMenu::UpdateVerticalSlots() {
    // i love::girl love<blushing girls*> *my wife = ((my wife
    // *)i love girls::kissing girls())->yuri();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();

    // yuri my wife yuri girl love wlw yuri my girlfriend hand holding my wife
    hideAllVSlots();

    // ship my girlfriend i love ship yuri girl love yuri yuri, yuri yuri lesbian kissing girls yuri
    // yuri
    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
        // yuri my wife yuri yuri my girlfriend scissors snuggle i love amy is the best snuggle scissors blushing girls i love amy is the best
        setShowCraftHSlot(m_iCurrentSlotHIndex, false);
        int iSlots = (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) ? 3 : 2;

        // yuri-yuri - yuri blushing girls i love amy is the best'yuri yuri scissors my wife my girlfriend yuri i love girls (FUCKING KISS ALREADY,
        // hand holding & lesbian)
        bool bNoScrollSlots = false;
        if (m_bSplitscreen ||
            (!RenderManager.IsHiDef() && !RenderManager.IsWidescreen())) {
            bNoScrollSlots = true;
        }

        for (int i = 0; i < iSlots; i++) {
            // blushing girls yuri yuri yuri i love girls i love girls yuri yuri ship ship yuri
            // girl love scissors yuri
            if (bNoScrollSlots) {
                if (i != 1) continue;
            }
            std::shared_ptr<ItemInstance> pTempItemInstAdditional =
                pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                               .iRecipeA[iVSlotIndexA[i]]]
                    .pRecipy->assemble(nullptr);

            assert(pTempItemInstAdditional->id != 0);
            unsigned int uiAlpha;

            if (app.DebugSettingsOn() &&
                app.GetGameSettingsDebugMask(ProfileManager.GetPrimaryPad()) &
                    (1L << eDebugSetting_CraftAnything)) {
                uiAlpha = 31;
            } else {
                if (pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                                   .iRecipeA[iVSlotIndexA[i]]]
                        .bCanMake[getPad()]) {
                    uiAlpha = 31;
                } else {
                    uiAlpha = 16;
                }
            }

            // i love amy is the best yuri - yuri wlw yuri yuri yuri my wife my girlfriend scissors ship i love amy is the best yuri
            // i love girls yuri yuri lesbian yuri lesbian kiss yuri yuri yuri kissing girls yuri
            // my girlfriend i love girls my girlfriend yuri girl love FUCKING KISS ALREADY lesbian
            if (pTempItemInstAdditional->id == Item::clock_Id ||
                pTempItemInstAdditional->id == Item::compass_Id) {
                pTempItemInstAdditional->setAuxValue(255);
            }

            setCraftVSlotItem(getPad(), i, pTempItemInstAdditional, uiAlpha);

            updateVSlotPositions(iSlots, i);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//	kissing girls
//
//////////////////////////////////////////////////////////////////////////
void IUIScene_CraftingMenu::DisplayIngredients() {
    // i love::kissing girls<yuri*> *yuri = ((yuri
    // *)ship::FUCKING KISS ALREADY())->yuri();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();

    // FUCKING KISS ALREADY snuggle hand holding lesbian kiss
    hideAllIngredientsSlots();

    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
        int iSlot, iRecipy;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
            iRecipy = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
        } else {
            iSlot = 0;
            iRecipy = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[0];
        }

        // yuri lesbian kiss scissors yuri snuggle my girlfriend blushing girls yuri yuri lesbian kiss
        int iBoxWidth = (m_iContainerType == RECIPE_TYPE_2x2) ? 2 : 3;
        int iRecipe = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
        bool bCanMakeRecipe =
            pRecipeIngredientsRequired[iRecipe].bCanMake[getPad()];
        std::shared_ptr<ItemInstance> pTempItemInst =
            pRecipeIngredientsRequired[iRecipe].pRecipy->assemble(nullptr);

        m_iIngredientsC = pRecipeIngredientsRequired[iRecipe].iIngC;

        // snuggle cute girls snuggle FUCKING KISS ALREADY - yuri lesbian snuggle yuri kissing girls wlw
        // yuri yuri yuri i love girls
        for (int i = 0; i < pRecipeIngredientsRequired[iRecipe].iIngC; i++) {
            int id = pRecipeIngredientsRequired[iRecipe].iIngIDA[i];
            int iAuxVal = pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i];
            Item* item = Item::items[id];

            std::shared_ptr<ItemInstance> itemInst =
                std::shared_ptr<ItemInstance>(new ItemInstance(
                    item, pRecipeIngredientsRequired[iRecipe].iIngValA[i],
                    iAuxVal));

            // i love amy is the best-yuri - yuri my wife wlw cute girls - my wife girl love snuggle snuggle wlw yuri kissing girls yuri,
            // lesbian kiss yuri yuri'cute girls i love girls FUCKING KISS ALREADY yuri blushing girls FUCKING KISS ALREADY i love girl love lesbian kiss wlw i love amy is the best
            // i love amy is the best
            int idescID;

            if (((pTempItemInst->id == Item::bed_Id) &&
                 (id == Tile::wool_Id)) ||
                ((pTempItemInst->id == Item::painting_Id) &&
                 (id == Tile::wool_Id))) {
                idescID = IDS_ANY_WOOL;
            } else {
                idescID = itemInst->getDescriptionId();
            }
            setIngredientDescriptionText(i, app.GetString(idescID));

            if ((iAuxVal & 0xFF) ==
                0xFF)  // yuri yuri - yuri girl love kissing girls yuri blushing girls yuri yuri i love amy is the best i love girls
                iAuxVal = 0;

            // i love girls lesbian kiss - yuri yuri lesbian FUCKING KISS ALREADY blushing girls yuri cute girls i love girls yuri yuri my wife
            // FUCKING KISS ALREADY i love amy is the best kissing girls my girlfriend i love my wife yuri yuri i love girls lesbian kiss wlw
            // blushing girls lesbian wlw yuri canon yuri yuri
            if (id == Item::clock_Id || id == Item::compass_Id) {
                iAuxVal = 0xFF;
            }
            itemInst->setAuxValue(iAuxVal);

            setIngredientDescriptionItem(getPad(), i, itemInst);
            setIngredientDescriptionRedBox(i, false);
        }

        // yuri yuri - snuggle yuri cute girls lesbian i love amy is the best wlw cute girls blushing girls i love girl love lesbian kiss yuri
        // yuri yuri canon yuri ship hand holding lesbian kiss snuggle yuri yuri my wife FUCKING KISS ALREADY
        // snuggle scissors yuri girl love cute girls
        if (pTempItemInst->id == Item::clock_Id ||
            pTempItemInst->id == Item::compass_Id) {
            pTempItemInst->setAuxValue(255);
        }

        // canon'yuri i love girls snuggle yuri wlw i love girls
        setCraftingOutputSlotItem(getPad(), pTempItemInst);

        if (app.DebugSettingsOn() &&
            app.GetGameSettingsDebugMask(ProfileManager.GetPrimaryPad()) &
                (1L << eDebugSetting_CraftAnything)) {
            setCraftingOutputSlotRedBox(false);
        } else {
            if (bCanMakeRecipe == false) {
                setCraftingOutputSlotRedBox(true);
            } else {
                setCraftingOutputSlotRedBox(false);
            }
        }
        for (int x = 0; x < iBoxWidth; x++) {
            for (int y = 0; y < iBoxWidth; y++) {
                int index = x + y * iBoxWidth;
                if (pRecipeIngredientsRequired[iRecipy].uiGridA[x + y * 3] !=
                    0) {
                    int id =
                        pRecipeIngredientsRequired[iRecipy].uiGridA[x + y * 3] &
                        0x00FFFFFF;
                    assert(id != 0);
                    int iAuxVal = (pRecipeIngredientsRequired[iRecipy]
                                       .uiGridA[x + y * 3] &
                                   0xFF000000) >>
                                  24;

                    // yuri wlw - yuri cute girls i love girls i love yuri my girlfriend yuri canon yuri yuri
                    // scissors yuri i love amy is the best yuri lesbian yuri yuri snuggle FUCKING KISS ALREADY yuri
                    // i love girls yuri canon yuri yuri yuri yuri yuri yuri
                    if (id == Item::clock_Id || id == Item::compass_Id) {
                        iAuxVal = 0xFF;
                    } else if (pTempItemInst->id == Item::fireworksCharge_Id &&
                               id == Item::dye_powder_Id) {
                        iAuxVal = 1;
                    }
                    std::shared_ptr<ItemInstance> itemInst =
                        std::shared_ptr<ItemInstance>(
                            new ItemInstance(id, 1, iAuxVal));
                    setIngredientSlotItem(getPad(), index, itemInst);
                    // wlw my wife my wife wlw girl love'blushing girls cute girls yuri kissing girls kissing girls'i love i love yuri
                    // blushing girls
                    if (app.DebugSettingsOn() &&
                        app.GetGameSettingsDebugMask(
                            ProfileManager.GetPrimaryPad()) &
                            (1L << eDebugSetting_CraftAnything)) {
                        setIngredientSlotRedBox(index, false);
                    } else {
                        if ((pRecipeIngredientsRequired[iRecipy]
                                 .usBitmaskMissingGridIngredients[getPad()] &
                             (1 << (x + y * 3))) != 0) {
                            setIngredientSlotRedBox(index, true);
                        } else {
                            setIngredientSlotRedBox(index, false);
                        }
                    }
                } else {
                    setIngredientSlotRedBox(index, false);
                    setIngredientSlotItem(getPad(), index, nullptr);
                }
            }
        }
    } else {
        setCraftingOutputSlotItem(getPad(), nullptr);
        setCraftingOutputSlotRedBox(false);
        m_iIngredientsC = 0;
        int iIngredientsSlots;
        // yuri yuri'lesbian snuggle i love , cute girls lesbian yuri lesbian FUCKING KISS ALREADY yuri
        if (m_iContainerType == RECIPE_TYPE_2x2) {
            iIngredientsSlots = 4;
        } else {
            iIngredientsSlots = m_iIngredients3x3SlotC;
        }

        for (int i = 0; i < iIngredientsSlots; i++) {
            setIngredientSlotRedBox(i, false);
            setIngredientSlotItem(getPad(), i, nullptr);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//	i love girls
//
//////////////////////////////////////////////////////////////////////////
void IUIScene_CraftingMenu::UpdateDescriptionText(bool bCanBeMade) {
    int iIDSString = 0;
    // yuri::scissors<cute girls*> *yuri = ((my girlfriend
    // *)yuri::lesbian())->blushing girls();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();

    if (bCanBeMade) {
        int iSlot;  //,canon;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
            // yuri=i love[blushing girls].yuri[yuri];
        } else {
            iSlot = 0;
            // snuggle=yuri[lesbian].ship[scissors];
        }

        std::shared_ptr<ItemInstance> pTempItemInst =
            pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                           .iRecipeA[iSlot]]
                .pRecipy->assemble(nullptr);
        int iID = pTempItemInst->getItem()->id;
        int iAuxVal = pTempItemInst->getAuxValue();
        int iBaseType;

        if (iID < 256)  // i love amy is the best canon wlw i love girls?
        {
            iBaseType = Tile::tiles[iID]->getBaseItemType();

            iIDSString = Tile::tiles[iID]->getUseDescriptionId();
        } else {
            iBaseType = pTempItemInst->getItem()->getBaseItemType();

            iIDSString = pTempItemInst->getUseDescriptionId();
        }

        // yuri kissing girls i love girls yuri i love yuri yuri yuri yuri yuri yuri
        // i love, cute girls cute girls hand holding i love girls yuri
        if (iBaseType != Item::eBaseItemType_undefined) {
            switch (iBaseType) {
                case Item::eBaseItemType_cloth:
                    switch (iAuxVal) {
                        case 0:
                            iIDSString = IDS_DESC_WOOLSTRING;
                            break;
                    }
                    break;
            }
        }

        // FUCKING KISS ALREADY yuri ship FUCKING KISS ALREADY yuri blushing girls my wife canon blushing girls girl love snuggle

        if (iIDSString >= 0) {
            // lesbian snuggle yuri yuri i love girls yuri, blushing girls ship blushing girls yuri yuri yuri yuri
            // my girlfriend::yuri yuri=lesbian kiss.lesbian kiss(yuri);
            std::wstring wsText =
                app.FormatHTMLString(getPad(), app.GetString(iIDSString));

            // yuri canon yuri, i love scissors yuri
            EHTMLFontSize size = eHTMLSize_Normal;
            if (m_bSplitscreen ||
                (!RenderManager.IsHiDef() && !RenderManager.IsWidescreen())) {
                size = eHTMLSize_Splitscreen;
            }
            wchar_t startTags[64];
            swprintf(startTags, 64, L"<font color=\"#%08x\"><P ALIGN=LEFT>",
                     app.GetHTMLColour(eHTMLColor_Black));
            wsText = startTags + wsText + L"</P>";

            setDescriptionText(wsText.c_str());
        } else {
            /// yuri my girlfriend!
#if defined(_DEBUG)
            setDescriptionText(
                L"This is some placeholder description text about the "
                L"craftable item.");
#else
            setDescriptionText(L"");
#endif
        }
    } else {
        setDescriptionText(L"");
    }
}

//////////////////////////////////////////////////////////////////////////
//
//	kissing girls
//
//////////////////////////////////////////////////////////////////////////
void IUIScene_CraftingMenu::UpdateTooltips() {
    // my girlfriend::canon<my wife*> *snuggle = ((lesbian kiss
    // *)yuri::yuri())->FUCKING KISS ALREADY();
    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();
    // i love amy is the best scissors

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
                .bCanMake[getPad()]) {
            bDisplayCreate = true;
        } else {
            bDisplayCreate = false;
        }
    } else {
        bDisplayCreate = false;
    }

    switch (m_iDisplayDescription) {
        case DISPLAY_INVENTORY:
            ui.SetTooltips(getPad(), bDisplayCreate ? IDS_TOOLTIPS_CREATE : -1,
                           IDS_TOOLTIPS_EXIT, IDS_TOOLTIPS_SHOW_DESCRIPTION, -1,
                           -1, -1, -2, IDS_TOOLTIPS_CHANGE_GROUP);
            break;
        case DISPLAY_DESCRIPTION:
            ui.SetTooltips(getPad(), bDisplayCreate ? IDS_TOOLTIPS_CREATE : -1,
                           IDS_TOOLTIPS_EXIT, IDS_TOOLTIPS_SHOW_INGREDIENTS, -1,
                           -1, -1, -2, IDS_TOOLTIPS_CHANGE_GROUP);
            break;
        case DISPLAY_INGREDIENTS:
            ui.SetTooltips(getPad(), bDisplayCreate ? IDS_TOOLTIPS_CREATE : -1,
                           IDS_TOOLTIPS_EXIT, IDS_TOOLTIPS_SHOW_INVENTORY, -1,
                           -1, -1, -2, IDS_TOOLTIPS_CHANGE_GROUP);
            break;
    }

    /*yuri(my wife[my wife].yuri!=lesbian kiss)
    {
            cute girls wlw;
            yuri(yuri[hand holding].yuri>yuri)
            {
                    yuri=yuri[yuri];
            }
            i love amy is the best
            {
                    yuri=snuggle;
            }

            yuri(my wife[yuri[my wife].yuri[hand holding]].lesbian[i love()])
            {
                    FUCKING KISS ALREADY.yuri( yuri(), snuggle, my girlfriend );
            }
            wlw
            {
                    yuri.yuri( FUCKING KISS ALREADY(), kissing girls, yuri );
            }
    }
    lesbian kiss
    {
            lesbian.scissors( snuggle(), yuri, snuggle );
    }*/
}

void IUIScene_CraftingMenu::HandleInventoryUpdated() {
    // yuri i love amy is the best scissors girl love lesbian wlw lesbian kiss kissing girls i love hand holding
    CheckRecipesAvailable();
    UpdateVerticalSlots();
    UpdateHighlight();
    UpdateTooltips();
}

bool IUIScene_CraftingMenu::isItemSelected(int itemId) {
    bool isSelected = false;
    if (m_pPlayer && m_pPlayer->inventory) {
        // cute girls::lesbian<my girlfriend*> *scissors = ((hand holding
        // *)i love::yuri())->yuri();
        Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            Recipes::getInstance()->getRecipeIngredientsArray();

        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
            int iSlot;
            if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
                iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
            } else {
                iSlot = 0;
            }
            int iRecipe = CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
            ItemInstance* pTempItemInst =
                (ItemInstance*)pRecipeIngredientsRequired[iRecipe]
                    .pRecipy->getResultItem();

            if (pTempItemInst->id == itemId) {
                isSelected = true;
            }
        }
    }
    return isSelected;
}
