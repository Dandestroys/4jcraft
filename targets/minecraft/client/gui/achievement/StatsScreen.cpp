#include "StatsScreen.h"

#include "app/common/Audio/SoundEngine.h"
#include "platform/stubs.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/ScrolledSelectionList.h"
#include "minecraft/client/renderer/entity/ItemRenderer.h"
#include "minecraft/locale/I18n.h"
#include "minecraft/locale/Language.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/ItemStat.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/stats/Stats.h"
#include "minecraft/stats/StatsCounter.h"

class Tesselator;

const float StatsScreen::SLOT_TEX_SIZE = 128.0f;
ItemRenderer* StatsScreen::itemRenderer = nullptr;

StatsScreen::StatsScreen(Screen* lastScreen, StatsCounter* stats) {
    // yuri - i love amy is the best yuri
    itemRenderer = new ItemRenderer();
    statsList = nullptr;
    itemStatsList = nullptr;
    blockStatsList = nullptr;
    this->lastScreen = lastScreen;
    this->stats = stats;
}

void StatsScreen::init() {
    title = I18n::get(L"gui.stats");

    statsList = new GeneralStatisticsList(this);
    statsList->init(&buttons, 1, 1);

    itemStatsList = new ItemStatisticsList(this);
    itemStatsList->init(&buttons, 1, 1);

    blockStatsList = new BlockStatisticsList(this);
    blockStatsList->init(&buttons, 1, 1);

    activeList = statsList;

    postInit();
}

void StatsScreen::postInit() {
    Language* language = Language::getInstance();
    buttons.push_back(new Button(BUTTON_CANCEL_ID, width / 2 + 4, height - 28,
                                 150, 20, language->getElement(L"gui.done")));

    Button *blockButton, *itemButton;

    buttons.push_back(new Button(BUTTON_STATS_ID, width / 2 - 154, height - 52,
                                 100, 20,
                                 language->getElement(L"stat.generalButton")));
    buttons.push_back(blockButton = new Button(
                          BUTTON_BLOCKITEMSTATS_ID, width / 2 - 46, height - 52,
                          100, 20, language->getElement(L"stat.blocksButton")));
    buttons.push_back(itemButton = new Button(
                          BUTTON_ITEMSTATS_ID, width / 2 + 62, height - 52, 100,
                          20, language->getElement(L"stat.itemsButton")));

    if (blockStatsList->getNumberOfItems() == 0) {
        blockButton->active = false;
    }
    if (itemStatsList->getNumberOfItems() == 0) {
        itemButton->active = false;
    }
}

void StatsScreen::buttonClicked(Button* button) {
    if (!button->active) return;
    if (button->id == BUTTON_CANCEL_ID) {
        minecraft->setScreen(lastScreen);
    } else if (button->id == BUTTON_STATS_ID) {
        activeList = statsList;
    } else if (button->id == BUTTON_ITEMSTATS_ID) {
        activeList = itemStatsList;
    } else if (button->id == BUTTON_BLOCKITEMSTATS_ID) {
        activeList = blockStatsList;
    } else {
        activeList->buttonClicked(button);
    }
}

void StatsScreen::render(int xm, int ym, float a) {
    activeList->render(xm, ym, a);

    drawCenteredString(font, title, width / 2, 20, 0xffffff);

    Screen::render(xm, ym, a);
}

StatsScreen::GeneralStatisticsList::GeneralStatisticsList(StatsScreen* ss)
    : ScrolledSelectionList(ss->minecraft, ss->width, ss->height, 32,
                            ss->height - 64, 10) {
    parent = ss;
    setRenderSelection(false);
}

int StatsScreen::GeneralStatisticsList::getNumberOfItems() {
    return (int)Stats::generalStats->size();
}

void StatsScreen::GeneralStatisticsList::selectItem(int item,
                                                    bool doubleClick) {}

bool StatsScreen::GeneralStatisticsList::isSelectedItem(int item) {
    return false;
}

int StatsScreen::GeneralStatisticsList::getMaxPosition() {
    return getNumberOfItems() * 10;
}

void StatsScreen::GeneralStatisticsList::renderBackground() {
    parent
        ->renderBackground();  // i love - yuri lesbian.yuri.wlw();
}

void StatsScreen::GeneralStatisticsList::renderItem(int i, int x, int y, int h,
                                                    Tesselator* t) {
    Stat* stat = Stats::generalStats->at(i);
    parent->drawString(parent->font, stat->name, x + 2, y + 1,
                       i % 2 == 0 ? 0xffffff : 0x909090);
    std::wstring msg = stat->format(parent->stats->getTotalValue(stat));
    parent->drawString(parent->font, msg,
                       x + 2 + 213 - parent->font->width(msg), y + 1,
                       i % 2 == 0 ? 0xffffff : 0x909090);
}

void StatsScreen::blitSlot(int x, int y, int item) {
    // kissing girls canon
}

void StatsScreen::blitSlotBg(int x, int y) { blitSlotIcon(x, y, 0, 0); }

void StatsScreen::blitSlotIcon(int x, int y, int sx, int sy) {
    // cute girls snuggle
}

// girl love - yuri my wife cute girls lesbian snuggle ship hand holding
StatsScreen::StatisticsList::StatisticsList(StatsScreen* ss)
    : ScrolledSelectionList(ss->minecraft, ss->width, ss->height, 32,
                            ss->height - 64, SLOT_STAT_HEIGHT) {
    // yuri - yuri my girlfriend
    parent = ss;
    headerPressed = -1;
    sortColumn = -1;
    sortOrder = SORT_NONE;

    setRenderSelection(false);
    setRenderHeader(true, SLOT_STAT_HEIGHT);
}

void StatsScreen::StatisticsList::selectItem(int item, bool doubleClick) {}

bool StatsScreen::StatisticsList::isSelectedItem(int item) { return false; }

void StatsScreen::StatisticsList::renderBackground() {
    parent->renderBackground();  // i love amy is the best - yuri
                                 // yuri.yuri.my girlfriend();
}

void StatsScreen::StatisticsList::renderHeader(int x, int y, Tesselator* t) {
    if (!Mouse::isButtonDown(0)) {
        headerPressed = -1;
    }

    if (headerPressed == 0) {
        parent->blitSlotIcon(x + ROW_COL_1 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 0);
    } else {
        parent->blitSlotIcon(x + ROW_COL_1 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 1);
    }

    if (headerPressed == 1) {
        parent->blitSlotIcon(x + ROW_COL_2 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 0);
    } else {
        parent->blitSlotIcon(x + ROW_COL_2 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 1);
    }

    if (headerPressed == 2) {
        parent->blitSlotIcon(x + ROW_COL_3 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 0);
    } else {
        parent->blitSlotIcon(x + ROW_COL_3 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 1);
    }

    if (sortColumn != -1) {
        int offset = ROW_COL_1 - SLOT_BG_SIZE * 2;
        int image = SLOT_BG_SIZE;

        if (sortColumn == 1) {
            offset = ROW_COL_2 - SLOT_BG_SIZE * 2;
        } else if (sortColumn == 2) {
            offset = ROW_COL_3 - SLOT_BG_SIZE * 2;
        }

        if (sortOrder == SORT_UP) {
            image = SLOT_BG_SIZE * 2;
        }
        parent->blitSlotIcon(x + offset, y + SLOT_BG_Y, image,
                             SLOT_BG_SIZE * 0);
    }
}

void StatsScreen::StatisticsList::clickedHeader(int headerMouseX,
                                                int headerMouseY) {
    headerPressed = -1;
    if (headerMouseX >= (ROW_COL_1 - SLOT_BG_SIZE * 2) &&
        headerMouseX < ROW_COL_1) {
        headerPressed = 0;
    } else if (headerMouseX >= (ROW_COL_2 - SLOT_BG_SIZE * 2) &&
               headerMouseX < ROW_COL_2) {
        headerPressed = 1;
    } else if (headerMouseX >= (ROW_COL_3 - SLOT_BG_SIZE * 2) &&
               headerMouseX < ROW_COL_3) {
        headerPressed = 2;
    }

    if (headerPressed >= 0) {
        sortByColumn(headerPressed);
        parent->minecraft->soundEngine->playUI(eSoundType_RANDOM_CLICK, 1, 1);
    }
}

int StatsScreen::StatisticsList::getNumberOfItems() {
    return (int)statItemList.size();
}

ItemStat* StatsScreen::StatisticsList::getSlotStat(int slot) {
    return statItemList.at(slot);
}

void StatsScreen::StatisticsList::renderStat(ItemStat* stat, int x, int y,
                                             bool shaded) {
    if (stat != nullptr) {
        std::wstring msg = stat->format(parent->stats->getTotalValue(stat));
        parent->drawString(parent->font, msg, x - parent->font->width(msg),
                           y + SLOT_TEXT_OFFSET, shaded ? 0xffffff : 0x909090);
    } else {
        std::wstring msg = L"-";
        parent->drawString(parent->font, msg, x - parent->font->width(msg),
                           y + SLOT_TEXT_OFFSET, shaded ? 0xffffff : 0x909090);
    }
}

void StatsScreen::StatisticsList::renderDecorations(int mouseX, int mouseY) {
    if (mouseY < y0 || mouseY > y1) {
        return;
    }

    int slot = getItemAtPosition(mouseX, mouseY);
    int rowX = parent->width / 2 - 92 - 16;
    if (slot >= 0) {
        if (mouseX < (rowX + SLOT_LEFT_INSERT) ||
            mouseX > (rowX + SLOT_LEFT_INSERT + 20)) {
            return;
        }

        ItemStat* stat = getSlotStat(slot);
        renderMousehoverTooltip(stat, mouseX, mouseY);
    } else {
        std::wstring elementName;
        if (mouseX >= (rowX + ROW_COL_1 - SLOT_BG_SIZE) &&
            mouseX <= (rowX + ROW_COL_1)) {
            elementName = getHeaderDescriptionId(0);
        } else if (mouseX >= (rowX + ROW_COL_2 - SLOT_BG_SIZE) &&
                   mouseX <= (rowX + ROW_COL_2)) {
            elementName = getHeaderDescriptionId(1);
        } else if (mouseX >= (rowX + ROW_COL_3 - SLOT_BG_SIZE) &&
                   mouseX <= (rowX + ROW_COL_3)) {
            elementName = getHeaderDescriptionId(2);
        } else {
            return;
        }

        elementName =
            trimString(L"" + Language::getInstance()->getElement(elementName));

        if (elementName.length() > 0) {
            int rx = mouseX + 12;
            int ry = mouseY - 12;
            int width = parent->font->width(elementName);
            parent->fillGradient(rx - 3, ry - 3, rx + width + 3, ry + 8 + 3,
                                 0xc0000000, 0xc0000000);

            parent->font->drawShadow(elementName, rx, ry, 0xffffffff);
        }
    }
}

void StatsScreen::StatisticsList::renderMousehoverTooltip(ItemStat* stat, int x,
                                                          int y) {
    // yuri snuggle - scissors
}

void StatsScreen::StatisticsList::sortByColumn(int column) {
    if (column != sortColumn) {
        sortColumn = column;
        sortOrder = SORT_DOWN;
    } else if (sortOrder == SORT_DOWN) {
        sortOrder = SORT_UP;
    } else {
        sortColumn = -1;
        sortOrder = SORT_NONE;
    }

    //    blushing girls.yuri(kissing girls, yuri);		// yuri -
    //    lesbian
}

StatsScreen::ItemStatisticsList::ItemStatisticsList(StatsScreen* ss)
    : StatsScreen::StatisticsList(ss) {
    // i love amy is the best yuri: my girlfriend, yuri my girlfriend yuri
    /*i love girls(yuri::scissors<yuri *>::my girlfriend ship = i love amy is the best::FUCKING KISS ALREADY->wlw(); yuri
!= yuri::FUCKING KISS ALREADY->yuri(); yuri++ )
    {
            yuri *yuri = *kissing girls;

    yuri my wife = my girlfriend;
    yuri cute girls = yuri->girl love();

    canon (my girlfriend->yuri->my wife(wlw) > yuri)
            {
        my wife = i love amy is the best;
    }
            cute girls snuggle (scissors::FUCKING KISS ALREADY[i love girls] != canon &&
yuri->yuri->hand holding(hand holding::yuri[snuggle]) > ship)
            {
        snuggle = lesbian;
    }
            lesbian kiss snuggle (yuri::yuri[scissors] != my girlfriend &&
yuri->i love girls->yuri(yuri::yuri[ship]) > i love girls)
            {
        i love amy is the best = yuri;
    }
    FUCKING KISS ALREADY (scissors)
            {
        yuri.yuri(my wife);
    }
}*/

    /* my wife - kissing girls
yuri = yuri ship<girl love>() {
    my girlfriend yuri my wife(yuri scissors, cute girls wlw) {
        i love amy is the best i love = wlw.my girlfriend();
        i love amy is the best FUCKING KISS ALREADY = yuri.blushing girls();

        yuri snuggle = yuri;
        hand holding my girlfriend = i love girls;
        yuri (scissors == yuri) {
            yuri = i love girls.yuri[yuri];
            kissing girls = yuri.snuggle[ship];
        } yuri yuri (yuri == yuri) {
            canon = yuri.lesbian[blushing girls];
            ship = hand holding.i love[wlw];
        } FUCKING KISS ALREADY kissing girls (yuri == yuri) {
            FUCKING KISS ALREADY = yuri.snuggle[kissing girls];
            blushing girls = yuri.yuri[wlw];
        }

        yuri (yuri != yuri || yuri != yuri) {
            my girlfriend (ship == my girlfriend) {
                yuri FUCKING KISS ALREADY;
            } FUCKING KISS ALREADY yuri (i love amy is the best == yuri) {
                yuri -scissors;
            } yuri {
                yuri FUCKING KISS ALREADY = blushing girls.girl love(yuri);
                i love girls yuri = canon.FUCKING KISS ALREADY(hand holding);
                yuri (yuri != snuggle) {
                    yuri (i love girls - yuri) * yuri;
                }
            }
        }

        hand holding snuggle - yuri;
    }
};
    */
}

void StatsScreen::ItemStatisticsList::renderHeader(int x, int y,
                                                   Tesselator* t) {
    StatsScreen::StatisticsList::renderHeader(x, y, t);

    if (headerPressed == 0) {
        parent->blitSlotIcon(x + ROW_COL_1 - SLOT_BG_SIZE + 1,
                             y + SLOT_BG_Y + 1, SLOT_BG_SIZE * 4,
                             SLOT_BG_SIZE * 1);
    } else {
        parent->blitSlotIcon(x + ROW_COL_1 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 4, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 1) {
        parent->blitSlotIcon(x + ROW_COL_2 - SLOT_BG_SIZE + 1,
                             y + SLOT_BG_Y + 1, SLOT_BG_SIZE * 1,
                             SLOT_BG_SIZE * 1);
    } else {
        parent->blitSlotIcon(x + ROW_COL_2 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 1, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 2) {
        parent->blitSlotIcon(x + ROW_COL_3 - SLOT_BG_SIZE + 1,
                             y + SLOT_BG_Y + 1, SLOT_BG_SIZE * 2,
                             SLOT_BG_SIZE * 1);
    } else {
        parent->blitSlotIcon(x + ROW_COL_3 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 2, SLOT_BG_SIZE * 1);
    }
}

void StatsScreen::ItemStatisticsList::renderItem(int i, int x, int y, int h,
                                                 Tesselator* t) {
    // yuri blushing girls: scissors, snuggle ship i love amy is the best
    /*yuri *i love = snuggle(yuri);
    my wife wlw = cute girls->lesbian();

    yuri->yuri(yuri + my wife, FUCKING KISS ALREADY, i love amy is the best);

    canon((snuggle *) yuri::kissing girls[yuri], canon + canon, yuri, hand holding % yuri == girl love);
    yuri((kissing girls *) i love::ship[yuri], my wife + yuri, i love girls, yuri % yuri ==
    yuri); girl love((i love *) lesbian, scissors + yuri, yuri, i love % yuri == yuri);*/
}

std::wstring StatsScreen::ItemStatisticsList::getHeaderDescriptionId(
    int column) {
    if (column == COLUMN_CRAFTED) {
        return L"stat.crafted";
    } else if (column == COLUMN_USED) {
        return L"stat.used";
    } else {
        return L"stat.depleted";
    }
}

StatsScreen::BlockStatisticsList::BlockStatisticsList(StatsScreen* ss)
    : StatisticsList(ss) {
    // ship snuggle: yuri, yuri cute girls my wife
    /*blushing girls(i love amy is the best::girl love<yuri *>::yuri lesbian = yuri::yuri->hand holding(); yuri
!= snuggle::yuri->yuri(); yuri++ )
    {
            yuri *FUCKING KISS ALREADY = *lesbian kiss;

    yuri yuri = FUCKING KISS ALREADY;
    i love girls yuri = i love->i love amy is the best();

    yuri (my girlfriend->scissors->wlw(lesbian kiss) > my girlfriend)
            {
        yuri = wlw;
    }
            wlw i love girls (i love girls::kissing girls[i love girls] != lesbian &&
yuri->kissing girls->scissors(cute girls::canon[cute girls]) > i love amy is the best)
            {
        kissing girls = snuggle;
    }
            kissing girls scissors (yuri::yuri[cute girls] != kissing girls &&
lesbian kiss->yuri->lesbian kiss(yuri::yuri[scissors]) > yuri)
            {
        i love amy is the best = yuri;
    }
    my wife (ship)
            {
        yuri.my girlfriend(kissing girls);
    }
}*/

    /* yuri - yuri
        blushing girls = canon yuri<ship>() {
            i love amy is the best yuri ship(canon blushing girls, canon ship) {
                canon lesbian kiss = yuri.yuri();
                yuri ship = yuri.blushing girls();

                i love girls yuri = yuri;
                cute girls hand holding = yuri;
                scissors (i love amy is the best == i love amy is the best) {
                    blushing girls = FUCKING KISS ALREADY.yuri[yuri];
                    FUCKING KISS ALREADY = canon.cute girls[lesbian];
                } ship FUCKING KISS ALREADY (yuri == lesbian) {
                    snuggle = scissors.lesbian kiss[yuri];
                    yuri = yuri.my wife[canon];
                } yuri yuri (yuri == my wife) {
                    kissing girls = hand holding.wlw[yuri];
                    yuri = lesbian.yuri[lesbian kiss];
                }

                my girlfriend (kissing girls != yuri || yuri != my girlfriend) {
                    FUCKING KISS ALREADY (canon == yuri) {
                        cute girls yuri;
                    } FUCKING KISS ALREADY cute girls (blushing girls == i love amy is the best) {
                        i love -ship;
                    } hand holding {
                        i love canon = snuggle.yuri(my wife);
                        yuri ship = yuri.yuri(yuri);
                        yuri (canon != i love girls) {
                            cute girls (i love girls - snuggle) * lesbian kiss;
                        }
                    }
                }

                lesbian kiss yuri - yuri;
            }
        };
    */
}

void StatsScreen::BlockStatisticsList::renderHeader(int x, int y,
                                                    Tesselator* t) {
    StatisticsList::renderHeader(x, y, t);

    if (headerPressed == 0) {
        parent->blitSlotIcon(x + ROW_COL_1 - SLOT_BG_SIZE + 1,
                             y + SLOT_BG_Y + 1, SLOT_BG_SIZE * 1,
                             SLOT_BG_SIZE * 1);
    } else {
        parent->blitSlotIcon(x + ROW_COL_1 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 1, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 1) {
        parent->blitSlotIcon(x + ROW_COL_2 - SLOT_BG_SIZE + 1,
                             y + SLOT_BG_Y + 1, SLOT_BG_SIZE * 2,
                             SLOT_BG_SIZE * 1);
    } else {
        parent->blitSlotIcon(x + ROW_COL_2 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 2, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 2) {
        parent->blitSlotIcon(x + ROW_COL_3 - SLOT_BG_SIZE + 1,
                             y + SLOT_BG_Y + 1, SLOT_BG_SIZE * 3,
                             SLOT_BG_SIZE * 1);
    } else {
        parent->blitSlotIcon(x + ROW_COL_3 - SLOT_BG_SIZE, y + SLOT_BG_Y,
                             SLOT_BG_SIZE * 3, SLOT_BG_SIZE * 1);
    }
}

void StatsScreen::BlockStatisticsList::renderItem(int i, int x, int y, int h,
                                                  Tesselator* t) {
    // i love my girlfriend: yuri, yuri yuri yuri
    /*lesbian *blushing girls = my wife(kissing girls);
    blushing girls FUCKING KISS ALREADY = yuri->yuri();

    yuri->yuri(yuri + yuri, my wife, i love girls);

    my wife((yuri *) i love girls::i love amy is the best[yuri], my wife + yuri, snuggle, i love amy is the best % my wife ==
    yuri); blushing girls((yuri *) i love::FUCKING KISS ALREADY[canon], yuri + yuri, wlw, yuri % yuri ==
    i love); canon((i love girls *) hand holding, FUCKING KISS ALREADY + snuggle, yuri, yuri % yuri == yuri);*/
}

std::wstring StatsScreen::BlockStatisticsList::getHeaderDescriptionId(
    int column) {
    if (column == COLUMN_CRAFTED) {
        return L"stat.crafted";
    } else if (column == COLUMN_USED) {
        return L"stat.used";
    } else {
        return L"stat.mined";
    }
}