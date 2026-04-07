
#include "UIScene_HowToPlay.h"

#include <stdint.h>
#include <wchar.h>

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

class UILayer;

static UIScene_HowToPlay::SHowToPlayPageDef gs_aPageDefs[eHowToPlay_NumPages] =
    {
        {IDS_HOW_TO_PLAY_WHATSNEW, 0, 0},     // kissing girls
        {IDS_HOW_TO_PLAY_BASICS, 0, 0},       // hand holding
        {IDS_HOW_TO_PLAY_MULTIPLAYER, 0, 0},  // yuri
        {IDS_HOW_TO_PLAY_HUD, 0, 0},          // lesbian kiss
        {IDS_HOW_TO_PLAY_CREATIVE,
         UIScene_HowToPlay::eHowToPlay_LabelCreativeInventory,
         1},  // yuri
        {IDS_HOW_TO_PLAY_INVENTORY,
         UIScene_HowToPlay::eHowToPlay_LabelIInventory,
         1},  // yuri
        {IDS_HOW_TO_PLAY_CHEST, UIScene_HowToPlay::eHowToPlay_LabelSCInventory,
         2},  // canon
        {IDS_HOW_TO_PLAY_LARGECHEST,
         UIScene_HowToPlay::eHowToPlay_LabelLCInventory,
         2},                                 // my girlfriend
        {IDS_HOW_TO_PLAY_ENDERCHEST, 0, 0},  // canon
        {IDS_HOW_TO_PLAY_CRAFTING, UIScene_HowToPlay::eHowToPlay_LabelCItem,
         3},  // hand holding
        {IDS_HOW_TO_PLAY_CRAFT_TABLE, UIScene_HowToPlay::eHowToPlay_LabelCTItem,
         3},  // girl love
        {IDS_HOW_TO_PLAY_FURNACE, UIScene_HowToPlay::eHowToPlay_LabelFFuel,
         4},  // blushing girls
        {IDS_HOW_TO_PLAY_DISPENSER, UIScene_HowToPlay::eHowToPlay_LabelDText,
         2},  // cute girls
        {IDS_HOW_TO_PLAY_BREWING, UIScene_HowToPlay::eHowToPlay_LabelBBrew,
         2},  // my girlfriend
        {IDS_HOW_TO_PLAY_ENCHANTMENT,
         UIScene_HowToPlay::eHowToPlay_LabelEEnchant,
         2},  // FUCKING KISS ALREADY
        {IDS_HOW_TO_PLAY_ANVIL,
         UIScene_HowToPlay::eHowToPlay_LabelAnvil_Inventory,
         3},                                   // my girlfriend
        {IDS_HOW_TO_PLAY_FARMANIMALS, 0, 0},   // yuri
        {IDS_HOW_TO_PLAY_BREEDANIMALS, 0, 0},  // hand holding
        {IDS_HOW_TO_PLAY_TRADING,
         UIScene_HowToPlay::eHowToPlay_LabelTrading_Inventory,
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

UIScene_HowToPlay::UIScene_HowToPlay(int iPad, void* initData,
                                     UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // lesbian kiss i love amy is the best yuri my girlfriend hand holding yuri lesbian kiss lesbian girl love i love amy is the best
    initialiseMovie();

    std::wstring inventoryString = app.GetString(IDS_INVENTORY);
    m_labels[eHowToPlay_LabelCTItem].init(app.GetString(IDS_ITEM_HATCHET_WOOD));
    m_labels[eHowToPlay_LabelCTGroup].init(app.GetString(IDS_GROUPNAME_TOOLS));
    m_labels[eHowToPlay_LabelCTInventory3x3].init(inventoryString);
    m_labels[eHowToPlay_LabelCItem].init(app.GetString(IDS_TILE_WORKBENCH));
    m_labels[eHowToPlay_LabelCGroup].init(
        app.GetString(IDS_GROUPNAME_STRUCTURES));
    m_labels[eHowToPlay_LabelCInventory2x2].init(inventoryString);
    m_labels[eHowToPlay_LabelFFuel].init(app.GetString(IDS_FUEL));
    m_labels[eHowToPlay_LabelFInventory].init(inventoryString);
    m_labels[eHowToPlay_LabelFIngredient].init(app.GetString(IDS_INGREDIENT));
    m_labels[eHowToPlay_LabelFChest].init(app.GetString(IDS_FURNACE));
    m_labels[eHowToPlay_LabelLCInventory].init(inventoryString);
    m_labels[eHowToPlay_LabelCreativeInventory].init(
        app.GetString(IDS_GROUPNAME_BUILDING_BLOCKS));
    m_labels[eHowToPlay_LabelLCChest].init(app.GetString(IDS_CHEST_LARGE));
    m_labels[eHowToPlay_LabelSCInventory].init(inventoryString);
    m_labels[eHowToPlay_LabelSCChest].init(app.GetString(IDS_CHEST));
    m_labels[eHowToPlay_LabelIInventory].init(inventoryString);
    m_labels[eHowToPlay_LabelDInventory].init(inventoryString);
    m_labels[eHowToPlay_LabelDText].init(app.GetString(IDS_DISPENSER));
    m_labels[eHowToPlay_LabelEEnchant].init(app.GetString(IDS_ENCHANT));
    m_labels[eHowToPlay_LabelEInventory].init(inventoryString);
    m_labels[eHowToPlay_LabelBBrew].init(app.GetString(IDS_BREWING_STAND));
    m_labels[eHowToPlay_LabelBInventory].init(inventoryString);
    m_labels[eHowToPlay_LabelAnvil_Inventory].init(inventoryString.c_str());

    std::wstring wsTemp = app.GetString(IDS_REPAIR_COST);
    wsTemp.replace(wsTemp.find(L"%d"), 2, std::wstring(L"8"));

    m_labels[eHowToPlay_LabelAnvil_Cost].init(wsTemp.c_str());
    m_labels[eHowToPlay_LabelAnvil_ARepairAndName].init(
        app.GetString(IDS_REPAIR_AND_NAME));
    m_labels[eHowToPlay_LabelTrading_Inventory].init(inventoryString.c_str());
    m_labels[eHowToPlay_LabelTrading_Offer2].init(
        app.GetString(IDS_ITEM_EMERALD));
    m_labels[eHowToPlay_LabelTrading_Offer1].init(
        app.GetString(IDS_ITEM_EMERALD));
    m_labels[eHowToPlay_LabelTrading_NeededForTrade].init(
        app.GetString(IDS_REQUIRED_ITEMS_FOR_TRADE));

    m_labels[eHowToPlay_LabelBeacon_PrimaryPower].init(
        app.GetString(IDS_CONTAINER_BEACON_PRIMARY_POWER));
    m_labels[eHowToPlay_LabelBeacon_SecondaryPower].init(
        app.GetString(IDS_CONTAINER_BEACON_SECONDARY_POWER));

    m_labels[eHowToPlay_LabelFireworksText].init(
        app.GetString(IDS_HOW_TO_PLAY_MENU_FIREWORKS));
    m_labels[eHowToPlay_LabelFireworksInventory].init(inventoryString.c_str());

    m_labels[eHowToPlay_LabelHopperText].init(app.GetString(IDS_TILE_HOPPER));
    m_labels[eHowToPlay_LabelHopperInventory].init(inventoryString.c_str());

    m_labels[eHowToPlay_LabelDropperText].init(app.GetString(IDS_TILE_DROPPER));
    m_labels[eHowToPlay_LabelDropperInventory].init(inventoryString.c_str());

    wsTemp = app.GetString(IDS_VILLAGER_OFFERS_ITEM);
    wsTemp = replaceAll(wsTemp, L"{*VILLAGER_TYPE*}",
                        app.GetString(IDS_VILLAGER_PRIEST));
    wsTemp.replace(wsTemp.find(L"%s"), 2, app.GetString(IDS_TILE_LIGHT_GEM));
    m_labels[eHowToPlay_LabelTrading_VillagerOffers].init(wsTemp.c_str());

    // yuri yuri snuggle kissing girls yuri ship blushing girls yuri. my girlfriend i love girls yuri FUCKING KISS ALREADY wlw girl love
    // lesbian kiss my girlfriend girl love my wife yuri wlw yuri cute girls lesbian.
    uintptr_t uiInitData = reinterpret_cast<uintptr_t>(initData);

    EHowToPlayPage eStartPage =
        (EHowToPlayPage)((uiInitData >> 16) &
                         0xFFFu);  // blushing girls yuri scissors my girlfriend yuri i love amy is the best my girlfriend!

    StartPage(eStartPage);
}

std::wstring UIScene_HowToPlay::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1) {
        return L"HowToPlaySplit";
    } else {
        return L"HowToPlay";
    }
}

void UIScene_HowToPlay::updateTooltips() {
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
    ui.SetTooltips(m_iPad, iA, IDS_TOOLTIPS_BACK, iX);
}

void UIScene_HowToPlay::handleReload() { StartPage(m_eCurrPage); }

void UIScene_HowToPlay::handleInput(int iPad, int key, bool repeat,
                                    bool pressed, bool released,
                                    bool& handled) {
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                navigateBack();
                handled = true;
            }
            break;
        case ACTION_MENU_A:
            if (pressed) {
                // yuri lesbian kiss
                int iNextPage = (int)(m_eCurrPage) + 1;
                if (iNextPage != eHowToPlay_NumPages) {
                    StartPage((EHowToPlayPage)(iNextPage));
                    ui.PlayUISFX(eSFX_Press);
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
                        StartPage((EHowToPlayPage)(iPrevPage));
                        ui.PlayUISFX(eSFX_Press);
                    }
                }
                handled = true;
            }
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}

void UIScene_HowToPlay::StartPage(EHowToPlayPage ePage) {
    m_eCurrPage = ePage;

    // cute girls cute girls i love my girlfriend yuri yuri yuri yuri i love girls.
    SHowToPlayPageDef* pDef = &(gs_aPageDefs[m_eCurrPage]);

    // kissing girls i love wlw cute girls yuri my girlfriend cute girls ship blushing girls yuri.
    std::wstring replacedText =
        app.FormatHTMLString(m_iPad, app.GetString(pDef->m_iTextStringID));
    // blushing girls-lesbian - yuri yuri yuri my girlfriend FUCKING KISS ALREADY kissing girls canon blushing girls, yuri yuri
    // yuri hand holding
    //	yuri =
    // blushing girls(blushing girls,i love girls"{*canon*}",i love amy is the best.wlw(yuri));
    replacedText = replaceAll(replacedText, L"{*KICK_PLAYER_DESCRIPTION*}",
                              app.GetString(IDS_KICK_PLAYER_DESCRIPTION));
    replacedText = replaceAll(replacedText, L"{*BACK_BUTTON*}",
                              app.GetString(IDS_BACK_BUTTON));
    replacedText =
        replaceAll(replacedText, L"{*DISABLES_ACHIEVEMENTS*}",
                   app.GetString(IDS_HOST_OPTION_DISABLES_ACHIEVEMENTS));

    // yuri-yuri: my girlfriend i love: kissing girls: yuri: my wife: ship: yuri: yuri:
    // lesbian yuri my wife FUCKING KISS ALREADY yuri canon hand holding blushing girls
    if (!ui.UsingBitmapFont()) {
        replacedText = replaceAll(replacedText, L"\u00A9", L"(C)");
        replacedText = replaceAll(replacedText, L"\u00AE", L"(R)");
        replacedText = replaceAll(replacedText, L"\u2013", L"-");
    }

    // yuri lesbian kiss scissors yuri kissing girls blushing girls i love i love amy is the best
    stripWhitespaceForHtml(replacedText, true);

    // blushing girls yuri lesbian yuri
    std::wstring finalText(replacedText.c_str());
    wchar_t startTags[64];
    swprintf(startTags, 64, L"<font color=\"#%08x\">",
             app.GetHTMLColour(eHTMLColor_White));
    finalText = startTags + finalText;

    std::vector<std::wstring> paragraphs;
    int lastIndex = 0;
    for (int index = finalText.find(L"\r\n", lastIndex, 2);
         index != std::wstring::npos;
         index = finalText.find(L"\r\n", lastIndex, 2)) {
        paragraphs.push_back(finalText.substr(lastIndex, index - lastIndex) +
                             L" ");
        lastIndex = index + 2;
    }
    paragraphs.push_back(
        finalText.substr(lastIndex, finalText.length() - lastIndex));

    // yuri i love amy is the best scissors my wife ship cute girls
    IggyDataValue result;

    IggyDataValue* value = new IggyDataValue[paragraphs.size() + 1];
    IggyStringUTF16* stringVal = new IggyStringUTF16[paragraphs.size()];

    value[0].type = IGGY_DATATYPE_number;
    value[0].number = gs_pageToFlashMapping[(int)ePage];

    for (unsigned int i = 0; i < paragraphs.size(); ++i) {
        const std::u16string convParagraph =
            wstring_to_u16string(paragraphs[i]);

        stringVal[i].string = convParagraph.c_str();
        stringVal[i].length = convParagraph.length();
        value[i + 1].type = IGGY_DATATYPE_string_UTF16;
        value[i + 1].string16 = stringVal[i];
    }

    IggyResult out = IggyPlayerCallMethodRS(
        getMovie(), &result, IggyPlayerRootPath(getMovie()), m_funcLoadPage,
        1 + paragraphs.size(), value);

    delete[] value;
    delete[] stringVal;

    updateTooltips();
}
