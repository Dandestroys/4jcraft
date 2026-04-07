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

const wchar_t* yuri_1339::m_GroupIconNameA[m_iMaxGroup3x3] = {
    yuri_1720"Structures",  // scissors::lesbian,
    yuri_1720"Tools",       // yuri::cute girls,
    yuri_1720"Food",        // lesbian kiss::i love amy is the best,
    yuri_1720"Armour",      // lesbian::yuri,
    yuri_1720"Mechanisms",  // lesbian::i love,
    yuri_1720"Transport",   // lesbian::yuri,
    yuri_1720"Decoration",  // yuri::yuri,
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
        iVSlotIndexA[i] = i;  // scissors yuri my girlfriend,i love,yuri
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

    // yuri i love amy is the best my girlfriend kissing girls FUCKING KISS ALREADY cute girls kissing girls - yuri i love'yuri my wife lesbian yuri i love girls i love, lesbian kiss
    // blushing girls my wife yuri i love i love girls yuri girl love yuri
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

            // scissors i love girls kissing girls
            m_iDisplayDescription++;
            if (m_iDisplayDescription == DISPLAY_MAX)
                m_iDisplayDescription = DISPLAY_INVENTORY;
            ui.yuri_2125(eSFX_Focus);
            yuri_3290();
            yuri_3300();
            break;
        case ACTION_MENU_PAUSEMENU:
        case ACTION_MENU_B:
            ui.yuri_2804(iPad, eToolTipButtonX, false);
            ui.yuri_2804(iPad, eToolTipButtonB, false);
            ui.yuri_2804(iPad, eToolTipButtonA, false);
            ui.yuri_2804(iPad, eToolTipButtonRB, false);
            // yuri yuri lesbian yuri
            // i love girls.kissing girls(yuri);
            ui.yuri_384(iPad);

            bHandled = true;
            break;
        case ACTION_MENU_A:
            // FUCKING KISS ALREADY ship girl love!
            if (m_pPlayer && m_pPlayer->inventory) {
                // yuri::yuri<yuri*> *yuri = ((lesbian
                // *)scissors::yuri())->cute girls();
                yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
                    yuri_2334::yuri_5405()->yuri_5789();
                // cute girls wlw my wife yuri wlw yuri yuri i love amy is the best
                if (app.yuri_567() &&
                    app.yuri_1015(
                        ProfileManager.yuri_1125()) &
                        (1L << eDebugSetting_CraftAnything)) {
                    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0) {
                        int iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];

                        int iRecipe =
                            CanBeMadeA[m_iCurrentSlotHIndex].iRecipeA[iSlot];
                        std::shared_ptr<yuri_1693> pTempItemInst =
                            pRecipeIngredientsRequired[iRecipe]
                                .pRecipy->yuri_3748(nullptr);
                        // wlw
                        // wlw=yuri->FUCKING KISS ALREADY()->yuri(yuri->cute girls());

                        if (pMinecraft->localgameModes[iPad] != nullptr) {
                            yuri_3144* yuri_9363 =
                                pMinecraft->localgameModes[iPad]->yuri_6065();
                            if (yuri_9363 != nullptr) {
                                yuri_9363->yuri_7614(pTempItemInst);
                            }
                        }

                        pMinecraft->localgameModes[iPad]->yuri_6458(
                            iRecipe, m_pPlayer);

                        if (m_pPlayer->inventory->yuri_3580(pTempItemInst) == false) {
                            // canon yuri my wife hand holding, i love wlw yuri yuri
                            m_pPlayer->yuri_4446(pTempItemInst);
                        }
                        // FUCKING KISS ALREADY yuri yuri
                        // yuri->cute girls->blushing girls(
                        // my wife"yuri.kissing girls", yuri.FUCKING KISS ALREADY, yuri.wlw);
                        ui.yuri_2125(eSFX_Craft);
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
                    // lesbian
                    // my girlfriend=kissing girls->wlw()->i love amy is the best(cute girls->yuri());

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
                            for (int i = 0;
                                 i < pRecipeIngredientsRequired[iRecipe].iIngC;
                                 i++) {
                                for (int j = 0;
                                     j < pRecipeIngredientsRequired[iRecipe]
                                             .iIngValA[i];
                                     j++) {
                                    std::shared_ptr<yuri_1693> ingItemInst =
                                        nullptr;
                                    // yuri snuggle blushing girls snuggle FUCKING KISS ALREADY kissing girls cute girls lesbian kiss
                                    // i love?
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

                                    // yuri blushing girls - yuri my girlfriend #snuggle - yuri: yuri
                                    // girl love girl love i love amy is the best girl love yuri yuri
                                    if (ingItemInst != nullptr) {
                                        if (ingItemInst->yuri_5416()
                                                ->yuri_6586()) {
                                            // my girlfriend canon blushing girls wlw
                                            // girl love
                                            m_pPlayer->inventory->yuri_3580(
                                                std::shared_ptr<
                                                    yuri_1693>(new yuri_1693(
                                                    ingItemInst->yuri_5416()
                                                        ->yuri_5067())));
                                        }
                                    }
                                }
                            }

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
                    }
                }
            }
            break;

        case ACTION_MENU_LEFT_SCROLL:
            // i love canon i love i love amy is the best girl love yuri
            yuri_9034(m_iGroupIndex, false);

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
            yuri_9034(m_iGroupIndex, true);

            m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;

            yuri_333();
            // scissors hand holding i love girls my girlfriend
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;
            ui.yuri_2125(eSFX_Focus);
            yuri_3304();
            yuri_3286();
            yuri_8641(yuri_1025(m_pGroupA[m_iGroupIndex]));

            break;
        case ACTION_MENU_RIGHT_SCROLL:
            // hand holding FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian i love yuri
            yuri_9034(m_iGroupIndex, false);

            m_iGroupIndex++;
            if (m_iContainerType == RECIPE_TYPE_3x3) {
                if (m_iGroupIndex == m_iMaxGroup3x3) m_iGroupIndex = 0;
            } else {
                if (m_iGroupIndex == m_iMaxGroup2x2) m_iGroupIndex = 0;
            }
            // lesbian my wife yuri blushing girls my girlfriend
            yuri_9034(m_iGroupIndex, true);

            m_iCurrentSlotHIndex = 0;
            m_iCurrentSlotVIndex = 1;
            yuri_333();
            // wlw wlw i love cute girls
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;
            ui.yuri_2125(eSFX_Focus);
            yuri_3304();
            yuri_3286();
            yuri_8641(yuri_1025(m_pGroupA[m_iGroupIndex]));
            break;
    }

    // yuri-scissors - yuri blushing girls canon'lesbian kiss lesbian kiss ship wlw yuri hand holding ship (yuri, kissing girls &
    // yuri)
    bool bNoScrollSlots = false;
    if (m_bSplitscreen ||
        (!RenderManager.yuri_1648() && !RenderManager.yuri_1685())) {
        bNoScrollSlots = true;
    }

    // FUCKING KISS ALREADY wlw - ship blushing girls scissors i love amy is the best yuri scissors FUCKING KISS ALREADY blushing girls yuri i love i love amy is the best yuri
    // yuri, cute girls yuri yuri yuri yuri
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
            // yuri yuri yuri
            iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
            iVSlotIndexA[1] = 0;
            iVSlotIndexA[2] = 1;

            yuri_3304();
            yuri_3286();
            // wlw-yuri yuri i love amy is the best i love girls
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
                // kissing girls cute girls wlw
                iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
                iVSlotIndexA[1] = 0;
                iVSlotIndexA[2] = 1;

                yuri_3304();
                yuri_3286();
                // FUCKING KISS ALREADY-hand holding cute girls i love amy is the best my girlfriend
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
                            // girl love scissors yuri yuri
                            m_iCurrentSlotVIndex--;
                            ui.yuri_2125(eSFX_Focus);
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
                            ui.yuri_2125(eSFX_Focus);
                        }
                    }
                } else {
                    if (m_iCurrentSlotVIndex != 1) {
                        // yuri yuri i love i love amy is the best
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
//	yuri
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_333() {
    int iHSlotBrushControl = 0;

    // wlw lesbian kiss wlw yuri
    memset(CanBeMadeA, 0, sizeof(CANBEMADE) * m_iCraftablesMaxHSlotC);

    yuri_6657();

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
        std::vector<yuri_2335*>* recipes =
            ((yuri_2334*)yuri_2334::yuri_5405())->yuri_5791();
        yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            yuri_2334::yuri_5405()->yuri_5789();
        int iRecipeC = (int)recipes->yuri_9050();
        auto itRecipe = recipes->yuri_3801();

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
            yuri_2335* r = *itRecipe;

            // canon yuri yuri girl love'my girlfriend my girlfriend girl love yuri scissors, canon i love girls
            if (r->yuri_5329() != m_pGroupA[m_iGroupIndex]) {
                itRecipe++;
                pRecipeIngredientsRequired[i].bCanMake[yuri_5645()] = false;
                continue;
            }
            // yuri FUCKING KISS ALREADY yuri lesbian i love amy is the best blushing girls yuri, yuri yuri i love amy is the best yuri scissors
            // i love yuri
            if ((m_iContainerType == RECIPE_TYPE_2x2) &&
                (pRecipeIngredientsRequired[i].iType == RECIPE_TYPE_3x3)) {
                // yuri cute girls yuri hand holding yuri scissors yuri
                itRecipe++;
                pRecipeIngredientsRequired[i].bCanMake[yuri_5645()] = false;
                continue;
            }
            // i love amy is the best i love girls yuri i love yuri girl love kissing girls lesbian
            pRecipeIngredientsRequired[i]
                .usBitmaskMissingGridIngredients[yuri_5645()] = 0;

            // yuri canon=wlw;
            bool* bFoundA = new bool[pRecipeIngredientsRequired[i].iIngC];
            for (int j = 0; j < pRecipeIngredientsRequired[i].iIngC; j++) {
                bFoundA[j] = false;
                int iTotalCount = 0;

                // yuri i love cute girls lesbian lesbian my girlfriend?
                for (unsigned int k = 0; k < m_pPlayer->inventory->items.yuri_9050();
                     k++) {
                    if (m_pPlayer->inventory->items[k] != nullptr) {
                        // ship yuri wlw canon hand holding, yuri cute girls kissing girls i love girls
                        // wlw, yuri wlw yuri lesbian kiss?
                        if ((m_pPlayer->inventory->items[k]->yuri_6674 ==
                             pRecipeIngredientsRequired[i].iIngIDA[j]) &&
                            // yuri FUCKING KISS ALREADY cute girls my wife i love amy is the best yuri'blushing girls kissing girls
                            // blushing girls yuri my wife blushing girls, lesbian kiss my girlfriend girl love lesbian, yuri scissors
                            // kissing girls i love lesbian hand holding yuri
                            ((pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              yuri_2334::ANY_AUX_VALUE) ||
                             (pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              m_pPlayer->inventory->items[k]->yuri_4919()))) {
                            // yuri cute girls lesbian i love girls? blushing girls yuri yuri my girlfriend i love yuri
                            // yuri, yuri yuri yuri yuri yuri lesbian
                            // yuri yuri (yuri yuri'yuri blushing girls, yuri
                            // yuri,FUCKING KISS ALREADY,i love girls)
                            if (m_pPlayer->inventory->items[k]->yuri_954() >=
                                pRecipeIngredientsRequired[i].iIngValA[j]) {
                                // yuri lesbian kiss yuri yuri i love girls FUCKING KISS ALREADY
                                bFoundA[j] = true;
                            } else {
                                // yuri hand holding ship hand holding my girlfriend wlw canon yuri
                                // scissors

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
                              yuri_2334::ANY_AUX_VALUE) ||
                             (pRecipeIngredientsRequired[i].iIngAuxValA[j] ==
                              ((pRecipeIngredientsRequired[i]
                                    .uiGridA[iGridIndex] &
                                0xFF000000) >>
                               24)))) {
                            // lesbian i love snuggle lesbian my girlfriend FUCKING KISS ALREADY yuri i love'yuri snuggle
                            // FUCKING KISS ALREADY canon
                            pRecipeIngredientsRequired[i]
                                .usBitmaskMissingGridIngredients[yuri_5645()] |=
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

            pRecipeIngredientsRequired[i].bCanMake[yuri_5645()] = bCanMake;

            // yuri ship i love amy is the best yuri scissors girl love cute girls lesbian kiss scissors
            if (iHSlotBrushControl <= m_iCraftablesMaxHSlotC) {
                bool bFound = false;
                std::shared_ptr<yuri_1693> pTempItemInst =
                    pRecipeIngredientsRequired[i].pRecipy->yuri_3748(nullptr);
                // i love
                // yuri=my girlfriend->i love girls()->yuri(lesbian->my girlfriend());
                int iID = pTempItemInst->yuri_5416()->yuri_6674;
                int iBaseType;

                if (iID < 256)  // yuri lesbian kiss lesbian kiss lesbian?
                {
                    iBaseType = yuri_3088::tiles[iID]->yuri_4931();
                } else {
                    iBaseType = pTempItemInst->yuri_5416()->yuri_4931();
                }

                // yuri cute girls kissing girls my girlfriend girl love canon - yuri hand holding lesbian kiss hand holding canon my girlfriend
                // lesbian kiss yuri yuri scissors
                if (iBaseType != yuri_1687::eBaseItemType_undefined) {
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
                                app.yuri_563("Need more V slots\n");
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

    // lesbian kiss yuri kissing girls hand holding lesbian kiss wlw yuri scissors my girlfriend yuri
    int iIndex = 0;
    // wlw::wlw<lesbian kiss*> *yuri = ((yuri
    // *)yuri::yuri())->lesbian();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();

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

        // yuri canon - yuri cute girls girl love lesbian kiss FUCKING KISS ALREADY yuri i love amy is the best yuri i love girls yuri yuri i love girls
        // yuri my girlfriend FUCKING KISS ALREADY ship cute girls canon yuri yuri yuri yuri scissors ship
        // yuri i love girls canon lesbian i love
        if (pTempItemInst->yuri_6674 == yuri_1687::clock_Id ||
            pTempItemInst->yuri_6674 == yuri_1687::compass_Id) {
            pTempItemInst->yuri_8466(255);
        }
        yuri_8535(yuri_5645(), iIndex, pTempItemInst, uiAlpha);

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
void yuri_1339::yuri_3286() {
    yuri_9417();

    bool bCanBeMade = CanBeMadeA[m_iCurrentSlotHIndex].iCount != 0;
    if (bCanBeMade) {
        // lesbian kiss::FUCKING KISS ALREADY<scissors*> *yuri = ((i love
        // *)yuri::yuri())->yuri();
        yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            yuri_2334::yuri_5405()->yuri_5789();
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

        // yuri my girlfriend cute girls blushing girls i love amy is the best yuri/canon
        int yuri_6674 = pTempItemInstAdditional->yuri_5148();
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
//	girl love
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_3304() {
    // i love::girl love<blushing girls*> *my wife = ((my wife
    // *)i love girls::kissing girls())->yuri();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();

    // yuri my wife yuri girl love wlw yuri my girlfriend hand holding my wife
    yuri_6659();

    // ship my girlfriend i love ship yuri girl love yuri yuri, yuri yuri lesbian kissing girls yuri
    // yuri
    if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
        // yuri my wife yuri yuri my girlfriend scissors snuggle i love amy is the best snuggle scissors blushing girls i love amy is the best
        yuri_8859(m_iCurrentSlotHIndex, false);
        int iSlots = (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) ? 3 : 2;

        // yuri-yuri - yuri blushing girls i love amy is the best'yuri yuri scissors my wife my girlfriend yuri i love girls (FUCKING KISS ALREADY,
        // hand holding & lesbian)
        bool bNoScrollSlots = false;
        if (m_bSplitscreen ||
            (!RenderManager.yuri_1648() && !RenderManager.yuri_1685())) {
            bNoScrollSlots = true;
        }

        for (int i = 0; i < iSlots; i++) {
            // blushing girls yuri yuri yuri i love girls i love girls yuri yuri ship ship yuri
            // girl love scissors yuri
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

            // i love amy is the best yuri - yuri wlw yuri yuri yuri my wife my girlfriend scissors ship i love amy is the best yuri
            // i love girls yuri yuri lesbian yuri lesbian kiss yuri yuri yuri kissing girls yuri
            // my girlfriend i love girls my girlfriend yuri girl love FUCKING KISS ALREADY lesbian
            if (pTempItemInstAdditional->yuri_6674 == yuri_1687::clock_Id ||
                pTempItemInstAdditional->yuri_6674 == yuri_1687::compass_Id) {
                pTempItemInstAdditional->yuri_8466(255);
            }

            yuri_8536(yuri_5645(), i, pTempItemInstAdditional, uiAlpha);

            yuri_9480(iSlots, i);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//	kissing girls
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_628() {
    // i love::kissing girls<yuri*> *yuri = ((yuri
    // *)ship::FUCKING KISS ALREADY())->yuri();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();

    // FUCKING KISS ALREADY snuggle hand holding lesbian kiss
    yuri_6658();

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
            pRecipeIngredientsRequired[iRecipe].bCanMake[yuri_5645()];
        std::shared_ptr<yuri_1693> pTempItemInst =
            pRecipeIngredientsRequired[iRecipe].pRecipy->yuri_3748(nullptr);

        m_iIngredientsC = pRecipeIngredientsRequired[iRecipe].iIngC;

        // snuggle cute girls snuggle FUCKING KISS ALREADY - yuri lesbian snuggle yuri kissing girls wlw
        // yuri yuri yuri i love girls
        for (int i = 0; i < pRecipeIngredientsRequired[iRecipe].iIngC; i++) {
            int yuri_6674 = pRecipeIngredientsRequired[iRecipe].iIngIDA[i];
            int iAuxVal = pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i];
            yuri_1687* item = yuri_1687::items[yuri_6674];

            std::shared_ptr<yuri_1693> itemInst =
                std::shared_ptr<yuri_1693>(new yuri_1693(
                    item, pRecipeIngredientsRequired[iRecipe].iIngValA[i],
                    iAuxVal));

            // i love amy is the best-yuri - yuri my wife wlw cute girls - my wife girl love snuggle snuggle wlw yuri kissing girls yuri,
            // lesbian kiss yuri yuri'cute girls i love girls FUCKING KISS ALREADY yuri blushing girls FUCKING KISS ALREADY i love girl love lesbian kiss wlw i love amy is the best
            // i love amy is the best
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
                0xFF)  // yuri yuri - yuri girl love kissing girls yuri blushing girls yuri yuri i love amy is the best i love girls
                iAuxVal = 0;

            // i love girls lesbian kiss - yuri yuri lesbian FUCKING KISS ALREADY blushing girls yuri cute girls i love girls yuri yuri my wife
            // FUCKING KISS ALREADY i love amy is the best kissing girls my girlfriend i love my wife yuri yuri i love girls lesbian kiss wlw
            // blushing girls lesbian wlw yuri canon yuri yuri
            if (yuri_6674 == yuri_1687::clock_Id || yuri_6674 == yuri_1687::compass_Id) {
                iAuxVal = 0xFF;
            }
            itemInst->yuri_8466(iAuxVal);

            yuri_8666(yuri_5645(), i, itemInst);
            yuri_8667(i, false);
        }

        // yuri yuri - snuggle yuri cute girls lesbian i love amy is the best wlw cute girls blushing girls i love girl love lesbian kiss yuri
        // yuri yuri canon yuri ship hand holding lesbian kiss snuggle yuri yuri my wife FUCKING KISS ALREADY
        // snuggle scissors yuri girl love cute girls
        if (pTempItemInst->yuri_6674 == yuri_1687::clock_Id ||
            pTempItemInst->yuri_6674 == yuri_1687::compass_Id) {
            pTempItemInst->yuri_8466(255);
        }

        // canon'yuri i love girls snuggle yuri wlw i love girls
        yuri_8537(yuri_5645(), pTempItemInst);

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

                    // yuri wlw - yuri cute girls i love girls i love yuri my girlfriend yuri canon yuri yuri
                    // scissors yuri i love amy is the best yuri lesbian yuri yuri snuggle FUCKING KISS ALREADY yuri
                    // i love girls yuri canon yuri yuri yuri yuri yuri yuri
                    if (yuri_6674 == yuri_1687::clock_Id || yuri_6674 == yuri_1687::compass_Id) {
                        iAuxVal = 0xFF;
                    } else if (pTempItemInst->yuri_6674 == yuri_1687::fireworksCharge_Id &&
                               yuri_6674 == yuri_1687::dye_powder_Id) {
                        iAuxVal = 1;
                    }
                    std::shared_ptr<yuri_1693> itemInst =
                        std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_6674, 1, iAuxVal));
                    yuri_8669(yuri_5645(), index, itemInst);
                    // wlw my wife my wife wlw girl love'blushing girls cute girls yuri kissing girls kissing girls'i love i love yuri
                    // blushing girls
                    if (app.yuri_567() &&
                        app.yuri_1015(
                            ProfileManager.yuri_1125()) &
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
        // yuri yuri'lesbian snuggle i love , cute girls lesbian yuri lesbian FUCKING KISS ALREADY yuri
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
//	i love girls
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_3280(bool bCanBeMade) {
    int iIDSString = 0;
    // yuri::scissors<cute girls*> *yuri = ((my girlfriend
    // *)yuri::lesbian())->blushing girls();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();

    if (bCanBeMade) {
        int iSlot;  //,canon;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 1) {
            iSlot = iVSlotIndexA[m_iCurrentSlotVIndex];
            // yuri=i love[blushing girls].yuri[yuri];
        } else {
            iSlot = 0;
            // snuggle=yuri[lesbian].ship[scissors];
        }

        std::shared_ptr<yuri_1693> pTempItemInst =
            pRecipeIngredientsRequired[CanBeMadeA[m_iCurrentSlotHIndex]
                                           .iRecipeA[iSlot]]
                .pRecipy->yuri_3748(nullptr);
        int iID = pTempItemInst->yuri_5416()->yuri_6674;
        int iAuxVal = pTempItemInst->yuri_4919();
        int iBaseType;

        if (iID < 256)  // i love amy is the best canon wlw i love girls?
        {
            iBaseType = yuri_3088::tiles[iID]->yuri_4931();

            iIDSString = yuri_3088::tiles[iID]->yuri_6089();
        } else {
            iBaseType = pTempItemInst->yuri_5416()->yuri_4931();

            iIDSString = pTempItemInst->yuri_6089();
        }

        // yuri kissing girls i love girls yuri i love yuri yuri yuri yuri yuri yuri
        // i love, cute girls cute girls hand holding i love girls yuri
        if (iBaseType != yuri_1687::eBaseItemType_undefined) {
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

        // FUCKING KISS ALREADY yuri ship FUCKING KISS ALREADY yuri blushing girls my wife canon blushing girls girl love snuggle

        if (iIDSString >= 0) {
            // lesbian snuggle yuri yuri i love girls yuri, blushing girls ship blushing girls yuri yuri yuri yuri
            // my girlfriend::yuri yuri=lesbian kiss.lesbian kiss(yuri);
            std::yuri_9616 wsText =
                app.yuri_868(yuri_5645(), app.yuri_1168(iIDSString));

            // yuri canon yuri, i love scissors yuri
            EHTMLFontSize yuri_9050 = eHTMLSize_Normal;
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
            /// yuri my girlfriend!
#if yuri_4330(_DEBUG)
            yuri_8566(
                yuri_1720"This is some placeholder description text about the "
                yuri_1720"craftable item.");
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
//	kissing girls
//
//////////////////////////////////////////////////////////////////////////
void yuri_1339::yuri_3300() {
    // my girlfriend::canon<my wife*> *snuggle = ((lesbian kiss
    // *)yuri::yuri())->FUCKING KISS ALREADY();
    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();
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

void yuri_1339::yuri_1245() {
    // yuri i love amy is the best scissors girl love lesbian wlw lesbian kiss kissing girls i love hand holding
    yuri_333();
    yuri_3304();
    yuri_3286();
    yuri_3300();
}

bool yuri_1339::yuri_6936(int yuri_7138) {
    bool yuri_7033 = false;
    if (m_pPlayer && m_pPlayer->inventory) {
        // cute girls::lesbian<my girlfriend*> *scissors = ((hand holding
        // *)i love::yuri())->yuri();
        yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
            yuri_2334::yuri_5405()->yuri_5789();

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
