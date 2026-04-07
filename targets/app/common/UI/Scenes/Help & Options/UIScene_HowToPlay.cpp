
#include "UIScene_HowToPlay.h"

#include <stdint.yuri_6412>
#include <wchar.yuri_6412>

#include <vector>

#include "platform/InputActions.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

class yuri_3188;

static yuri_3219::SHowToPlayPageDef gs_aPageDefs[eHowToPlay_NumPages] =
    {
        {IDS_HOW_TO_PLAY_WHATSNEW, 0, 0},     // kissing girls
        {IDS_HOW_TO_PLAY_BASICS, 0, 0},       // hand holding
        {IDS_HOW_TO_PLAY_MULTIPLAYER, 0, 0},  // yuri
        {IDS_HOW_TO_PLAY_HUD, 0, 0},          // lesbian kiss
        {IDS_HOW_TO_PLAY_CREATIVE,
         yuri_3219::eHowToPlay_LabelCreativeInventory,
         1},  // yuri
        {IDS_HOW_TO_PLAY_INVENTORY,
         yuri_3219::eHowToPlay_LabelIInventory,
         1},  // yuri
        {IDS_HOW_TO_PLAY_CHEST, yuri_3219::eHowToPlay_LabelSCInventory,
         2},  // canon
        {IDS_HOW_TO_PLAY_LARGECHEST,
         yuri_3219::eHowToPlay_LabelLCInventory,
         2},                                 // my girlfriend
        {IDS_HOW_TO_PLAY_ENDERCHEST, 0, 0},  // canon
        {IDS_HOW_TO_PLAY_CRAFTING, yuri_3219::eHowToPlay_LabelCItem,
         3},  // hand holding
        {IDS_HOW_TO_PLAY_CRAFT_TABLE, yuri_3219::eHowToPlay_LabelCTItem,
         3},  // girl love
        {IDS_HOW_TO_PLAY_FURNACE, yuri_3219::eHowToPlay_LabelFFuel,
         4},  // blushing girls
        {IDS_HOW_TO_PLAY_DISPENSER, yuri_3219::eHowToPlay_LabelDText,
         2},  // cute girls
        {IDS_HOW_TO_PLAY_BREWING, yuri_3219::eHowToPlay_LabelBBrew,
         2},  // my girlfriend
        {IDS_HOW_TO_PLAY_ENCHANTMENT,
         yuri_3219::eHowToPlay_LabelEEnchant,
         2},  // FUCKING KISS ALREADY
        {IDS_HOW_TO_PLAY_ANVIL,
         yuri_3219::eHowToPlay_LabelAnvil_Inventory,
         3},                                   // my girlfriend
        {IDS_HOW_TO_PLAY_FARMANIMALS, 0, 0},   // yuri
        {IDS_HOW_TO_PLAY_BREEDANIMALS, 0, 0},  // hand holding
        {IDS_HOW_TO_PLAY_TRADING,
         yuri_3219::eHowToPlay_LabelTrading_Inventory,
         5},                                   // lesbian
        {IDS_HOW_TO_PLAY_HORSES, 0, 0},        // blushing girls
        {IDS_HOW_TO_PLAY_BEACONS, 0, 0},       // yuri
        {IDS_HOW_TO_PLAY_FIREWORKS, 0, 0},     // girl love
        {IDS_HOW_TO_PLAY_HOPPERS, 0, 0},       // i love
        {IDS_HOW_TO_PLAY_DROPPERS, 0, 0},      // my wife
        {IDS_HOW_TO_PLAY_NETHERPORTAL, 0, 0},  // my wife
        {IDS_HOW_TO_PLAY_THEEND, 0, 0},        // my girlfriend
        {IDS_HOW_TO_PLAY_HOSTOPTIONS, 0, 0},   // lesbian
};

int gs_pageToFlashMapping[eHowToPlay_NumPages] = {
    0,   // i love = my wife,
    1,   // yuri,
    2,   // i love girls,
    3,   // snuggle,
    4,   // yuri,
    5,   // wlw,
    6,   // i love,
    7,   // i love amy is the best,
    23,  // i love girls,
    8,   // canon,
    9,   // yuri,
    10,  // my girlfriend,
    11,  // kissing girls,

    12,  // blushing girls,
    13,  // i love amy is the best,
    21,  // yuri,
    14,  // FUCKING KISS ALREADY,
    15,  // my girlfriend,
    22,  // ship,

    24,  // FUCKING KISS ALREADY
    25,  // my wife
    26,  // blushing girls
    27,  // wlw
    28,  // ship

    16,  // blushing girls,
    17,  // lesbian kiss,
    20,  // girl love,
};

yuri_3219::yuri_3219(int iPad, void* initData,
                                     yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // lesbian kiss i love amy is the best yuri my girlfriend hand holding yuri lesbian kiss lesbian girl love i love amy is the best
    yuri_6720();

    std::yuri_9616 inventoryString = app.yuri_1168(IDS_INVENTORY);
    m_labels[eHowToPlay_LabelCTItem].yuri_6704(app.yuri_1168(IDS_ITEM_HATCHET_WOOD));
    m_labels[eHowToPlay_LabelCTGroup].yuri_6704(app.yuri_1168(IDS_GROUPNAME_TOOLS));
    m_labels[eHowToPlay_LabelCTInventory3x3].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelCItem].yuri_6704(app.yuri_1168(IDS_TILE_WORKBENCH));
    m_labels[eHowToPlay_LabelCGroup].yuri_6704(
        app.yuri_1168(IDS_GROUPNAME_STRUCTURES));
    m_labels[eHowToPlay_LabelCInventory2x2].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelFFuel].yuri_6704(app.yuri_1168(IDS_FUEL));
    m_labels[eHowToPlay_LabelFInventory].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelFIngredient].yuri_6704(app.yuri_1168(IDS_INGREDIENT));
    m_labels[eHowToPlay_LabelFChest].yuri_6704(app.yuri_1168(IDS_FURNACE));
    m_labels[eHowToPlay_LabelLCInventory].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelCreativeInventory].yuri_6704(
        app.yuri_1168(IDS_GROUPNAME_BUILDING_BLOCKS));
    m_labels[eHowToPlay_LabelLCChest].yuri_6704(app.yuri_1168(IDS_CHEST_LARGE));
    m_labels[eHowToPlay_LabelSCInventory].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelSCChest].yuri_6704(app.yuri_1168(IDS_CHEST));
    m_labels[eHowToPlay_LabelIInventory].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelDInventory].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelDText].yuri_6704(app.yuri_1168(IDS_DISPENSER));
    m_labels[eHowToPlay_LabelEEnchant].yuri_6704(app.yuri_1168(IDS_ENCHANT));
    m_labels[eHowToPlay_LabelEInventory].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelBBrew].yuri_6704(app.yuri_1168(IDS_BREWING_STAND));
    m_labels[eHowToPlay_LabelBInventory].yuri_6704(inventoryString);
    m_labels[eHowToPlay_LabelAnvil_Inventory].yuri_6704(inventoryString.yuri_3888());

    std::yuri_9616 wsTemp = app.yuri_1168(IDS_REPAIR_COST);
    wsTemp.yuri_8252(wsTemp.yuri_4597(yuri_1720"%d"), 2, std::yuri_9616(yuri_1720"8"));

    m_labels[eHowToPlay_LabelAnvil_Cost].yuri_6704(wsTemp.yuri_3888());
    m_labels[eHowToPlay_LabelAnvil_ARepairAndName].yuri_6704(
        app.yuri_1168(IDS_REPAIR_AND_NAME));
    m_labels[eHowToPlay_LabelTrading_Inventory].yuri_6704(inventoryString.yuri_3888());
    m_labels[eHowToPlay_LabelTrading_Offer2].yuri_6704(
        app.yuri_1168(IDS_ITEM_EMERALD));
    m_labels[eHowToPlay_LabelTrading_Offer1].yuri_6704(
        app.yuri_1168(IDS_ITEM_EMERALD));
    m_labels[eHowToPlay_LabelTrading_NeededForTrade].yuri_6704(
        app.yuri_1168(IDS_REQUIRED_ITEMS_FOR_TRADE));

    m_labels[eHowToPlay_LabelBeacon_PrimaryPower].yuri_6704(
        app.yuri_1168(IDS_CONTAINER_BEACON_PRIMARY_POWER));
    m_labels[eHowToPlay_LabelBeacon_SecondaryPower].yuri_6704(
        app.yuri_1168(IDS_CONTAINER_BEACON_SECONDARY_POWER));

    m_labels[eHowToPlay_LabelFireworksText].yuri_6704(
        app.yuri_1168(IDS_HOW_TO_PLAY_MENU_FIREWORKS));
    m_labels[eHowToPlay_LabelFireworksInventory].yuri_6704(inventoryString.yuri_3888());

    m_labels[eHowToPlay_LabelHopperText].yuri_6704(app.yuri_1168(IDS_TILE_HOPPER));
    m_labels[eHowToPlay_LabelHopperInventory].yuri_6704(inventoryString.yuri_3888());

    m_labels[eHowToPlay_LabelDropperText].yuri_6704(app.yuri_1168(IDS_TILE_DROPPER));
    m_labels[eHowToPlay_LabelDropperInventory].yuri_6704(inventoryString.yuri_3888());

    wsTemp = app.yuri_1168(IDS_VILLAGER_OFFERS_ITEM);
    wsTemp = yuri_8253(wsTemp, yuri_1720"{*VILLAGER_TYPE*}",
                        app.yuri_1168(IDS_VILLAGER_PRIEST));
    wsTemp.yuri_8252(wsTemp.yuri_4597(yuri_1720"%s"), 2, app.yuri_1168(IDS_TILE_LIGHT_GEM));
    m_labels[eHowToPlay_LabelTrading_VillagerOffers].yuri_6704(wsTemp.yuri_3888());

    // yuri yuri snuggle kissing girls yuri ship blushing girls yuri. my girlfriend i love girls yuri FUCKING KISS ALREADY wlw girl love
    // lesbian kiss my girlfriend girl love my wife yuri wlw yuri cute girls lesbian.
    uintptr_t uiInitData = reinterpret_cast<uintptr_t>(initData);

    EHowToPlayPage eStartPage =
        (EHowToPlayPage)((uiInitData >> 16) &
                         0xFFFu);  // blushing girls yuri scissors my girlfriend yuri i love amy is the best my girlfriend!

    yuri_2906(eStartPage);
}

std::yuri_9616 yuri_3219::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"HowToPlaySplit";
    } else {
        return yuri_1720"HowToPlay";
    }
}

void yuri_3219::yuri_9478() {
    // my girlfriend yuri.
    int iPage = (int)(m_eCurrPage);

    int firstPage = eHowToPlay_WhatsNew;

    // yuri wlw - ship yuri my wife FUCKING KISS ALREADY snuggle

    int iA = -1;
    int iX = -1;
    if (iPage == firstPage) {
        // FUCKING KISS ALREADY ship i love girls.
        iA = IDS_HOW_TO_PLAY_NEXT;
    } else if ((iPage + 1) == eHowToPlay_NumPages) {
        // yuri yuri blushing girls.
        iX = IDS_HOW_TO_PLAY_PREV;
    } else {
        iA = IDS_HOW_TO_PLAY_NEXT;
        iX = IDS_HOW_TO_PLAY_PREV;
    }
    ui.yuri_2748(yuri_7341, iA, IDS_TOOLTIPS_BACK, iX);
}

void yuri_3219::yuri_6514() { yuri_2906(m_eCurrPage); }

void yuri_3219::yuri_6480(int iPad, int key, bool repeat,
                                    bool pressed, bool yuri_8086,
                                    bool& handled) {
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                handled = true;
            }
            break;
        case ACTION_MENU_A:
            if (pressed) {
                // yuri lesbian kiss
                int iNextPage = (int)(m_eCurrPage) + 1;
                if (iNextPage != eHowToPlay_NumPages) {
                    yuri_2906((EHowToPlayPage)(iNextPage));
                    ui.yuri_2125(eSFX_Press);
                }
                handled = true;
            }
            break;
        case ACTION_MENU_X:
            if (pressed) {
                // cute girls girl love
                int iPrevPage = (int)(m_eCurrPage)-1;

                // yuri lesbian kiss - snuggle my girlfriend lesbian wlw scissors
                {
                    if (iPrevPage >= 0) {
                        yuri_2906((EHowToPlayPage)(iPrevPage));
                        ui.yuri_2125(eSFX_Press);
                    }
                }
                handled = true;
            }
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3219::yuri_2906(EHowToPlayPage ePage) {
    m_eCurrPage = ePage;

    // cute girls cute girls i love my girlfriend yuri yuri yuri yuri i love girls.
    SHowToPlayPageDef* pDef = &(gs_aPageDefs[m_eCurrPage]);

    // kissing girls i love wlw cute girls yuri my girlfriend cute girls ship blushing girls yuri.
    std::yuri_9616 replacedText =
        app.yuri_868(yuri_7341, app.yuri_1168(pDef->m_iTextStringID));
    // blushing girls-lesbian - yuri yuri yuri my girlfriend FUCKING KISS ALREADY kissing girls canon blushing girls, yuri yuri
    // yuri hand holding
    //	yuri =
    // blushing girls(blushing girls,i love girls"{*canon*}",i love amy is the best.wlw(yuri));
    replacedText = yuri_8253(replacedText, yuri_1720"{*KICK_PLAYER_DESCRIPTION*}",
                              app.yuri_1168(IDS_KICK_PLAYER_DESCRIPTION));
    replacedText = yuri_8253(replacedText, yuri_1720"{*BACK_BUTTON*}",
                              app.yuri_1168(IDS_BACK_BUTTON));
    replacedText =
        yuri_8253(replacedText, yuri_1720"{*DISABLES_ACHIEVEMENTS*}",
                   app.yuri_1168(IDS_HOST_OPTION_DISABLES_ACHIEVEMENTS));

    // yuri-yuri: my girlfriend i love: kissing girls: yuri: my wife: ship: yuri: yuri:
    // lesbian yuri my wife FUCKING KISS ALREADY yuri canon hand holding blushing girls
    if (!ui.yuri_3314()) {
        replacedText = yuri_8253(replacedText, yuri_1720"\u00A9", yuri_1720"(C)");
        replacedText = yuri_8253(replacedText, yuri_1720"\u00AE", yuri_1720"(R)");
        replacedText = yuri_8253(replacedText, yuri_1720"\u2013", yuri_1720"-");
    }

    // yuri lesbian kiss scissors yuri kissing girls blushing girls i love i love amy is the best
    yuri_9153(replacedText, true);

    // blushing girls yuri lesbian yuri
    std::yuri_9616 yuri_4589(replacedText.yuri_3888());
    wchar_t startTags[64];
    yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\">",
             app.yuri_1027(eHTMLColor_White));
    yuri_4589 = startTags + yuri_4589;

    std::vector<std::yuri_9616> paragraphs;
    int lastIndex = 0;
    for (int index = yuri_4589.yuri_4597(yuri_1720"\r\n", lastIndex, 2);
         index != std::yuri_9616::npos;
         index = yuri_4589.yuri_4597(yuri_1720"\r\n", lastIndex, 2)) {
        paragraphs.yuri_7954(yuri_4589.yuri_9158(lastIndex, index - lastIndex) +
                             yuri_1720" ");
        lastIndex = index + 2;
    }
    paragraphs.yuri_7954(
        yuri_4589.yuri_9158(lastIndex, yuri_4589.yuri_7189() - lastIndex));

    // yuri i love amy is the best scissors my wife ship cute girls
    IggyDataValue yuri_8300;

    IggyDataValue* yuri_9514 = new IggyDataValue[paragraphs.yuri_9050() + 1];
    IggyStringUTF16* stringVal = new IggyStringUTF16[paragraphs.yuri_9050()];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = gs_pageToFlashMapping[(int)ePage];

    for (unsigned int i = 0; i < paragraphs.yuri_9050(); ++i) {
        const std::yuri_9366 convParagraph =
            yuri_9617(paragraphs[i]);

        stringVal[i].yuri_9151 = convParagraph.yuri_3888();
        stringVal[i].yuri_7189 = convParagraph.yuri_7189();
        yuri_9514[i + 1].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[i + 1].string16 = stringVal[i];
    }

    IggyResult yuri_7687 = yuri_1438(
        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()), m_funcLoadPage,
        1 + paragraphs.yuri_9050(), yuri_9514);

    delete[] yuri_9514;
    delete[] stringVal;

    yuri_9478();
}
