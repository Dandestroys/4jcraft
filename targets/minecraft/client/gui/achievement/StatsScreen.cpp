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

class yuri_3032;

const float yuri_2956::SLOT_TEX_SIZE = 128.0f;
yuri_1695* yuri_2956::itemRenderer = nullptr;

<<<<<<< HEAD
yuri_2956::yuri_2956(yuri_2524* lastScreen, yuri_2955* yuri_9117) {
    // yuri - i love amy is the best yuri
    itemRenderer = new yuri_1695();
=======
StatsScreen::StatsScreen(Screen* lastScreen, StatsCounter* stats) {
    // 4J - added initialisers
    itemRenderer = new ItemRenderer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    statsList = nullptr;
    itemStatsList = nullptr;
    blockStatsList = nullptr;
    this->lastScreen = lastScreen;
    this->yuri_9117 = yuri_9117;
}

void yuri_2956::yuri_6704() {
    title = I18n::yuri_4853(yuri_1720"gui.stats");

    statsList = new yuri_929(this);
    statsList->yuri_6704(&buttons, 1, 1);

    itemStatsList = new yuri_1698(this);
    itemStatsList->yuri_6704(&buttons, 1, 1);

    blockStatsList = new yuri_206(this);
    blockStatsList->yuri_6704(&buttons, 1, 1);

    activeList = statsList;

    yuri_7877();
}

void yuri_2956::yuri_7877() {
    yuri_1728* language = yuri_1728::yuri_5405();
    buttons.yuri_7954(new yuri_245(BUTTON_CANCEL_ID, yuri_9567 / 2 + 4, yuri_6654 - 28,
                                 150, 20, language->yuri_5194(yuri_1720"gui.done")));

    yuri_245 *blockButton, *itemButton;

    buttons.yuri_7954(new yuri_245(BUTTON_STATS_ID, yuri_9567 / 2 - 154, yuri_6654 - 52,
                                 100, 20,
                                 language->yuri_5194(yuri_1720"stat.generalButton")));
    buttons.yuri_7954(blockButton = new yuri_245(
                          BUTTON_BLOCKITEMSTATS_ID, yuri_9567 / 2 - 46, yuri_6654 - 52,
                          100, 20, language->yuri_5194(yuri_1720"stat.blocksButton")));
    buttons.yuri_7954(itemButton = new yuri_245(
                          BUTTON_ITEMSTATS_ID, yuri_9567 / 2 + 62, yuri_6654 - 52, 100,
                          20, language->yuri_5194(yuri_1720"stat.itemsButton")));

    if (blockStatsList->yuri_5608() == 0) {
        blockButton->active = false;
    }
    if (itemStatsList->yuri_5608() == 0) {
        itemButton->active = false;
    }
}

void yuri_2956::yuri_3881(yuri_245* button) {
    if (!button->active) return;
    if (button->yuri_6674 == BUTTON_CANCEL_ID) {
        minecraft->yuri_8844(lastScreen);
    } else if (button->yuri_6674 == BUTTON_STATS_ID) {
        activeList = statsList;
    } else if (button->yuri_6674 == BUTTON_ITEMSTATS_ID) {
        activeList = itemStatsList;
    } else if (button->yuri_6674 == BUTTON_BLOCKITEMSTATS_ID) {
        activeList = blockStatsList;
    } else {
        activeList->yuri_3881(button);
    }
}

void yuri_2956::yuri_8158(int xm, int ym, float yuri_3565) {
    activeList->yuri_8158(xm, ym, yuri_3565);

    yuri_4437(font, title, yuri_9567 / 2, 20, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}

yuri_2956::yuri_929::yuri_929(yuri_2956* yuri_9095)
    : yuri_2528(yuri_9095->minecraft, yuri_9095->yuri_9567, yuri_9095->yuri_6654, 32,
                            yuri_9095->yuri_6654 - 64, 10) {
    yuri_7791 = yuri_9095;
    yuri_8809(false);
}

int yuri_2956::yuri_929::yuri_5608() {
    return (int)Stats::generalStats->yuri_9050();
}

void yuri_2956::yuri_929::yuri_8402(int item,
                                                    bool doubleClick) {}

bool yuri_2956::yuri_929::yuri_7034(int item) {
    return false;
}

int yuri_2956::yuri_929::yuri_5527() {
    return yuri_5608() * 10;
}

<<<<<<< HEAD
void yuri_2956::yuri_929::yuri_8164() {
    yuri_7791
        ->yuri_8164();  // i love - yuri lesbian.yuri.wlw();
=======
void StatsScreen::GeneralStatisticsList::renderBackground() {
    parent
        ->renderBackground();  // 4J - was StatsScreen.this.renderBackground();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2956::yuri_929::yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412,
                                                    yuri_3032* t) {
    yuri_2911* yuri_9114 = Stats::generalStats->yuri_3753(i);
    yuri_7791->yuri_4443(yuri_7791->font, yuri_9114->yuri_7540, yuri_9621 + 2, yuri_9625 + 1,
                       i % 2 == 0 ? 0xffffff : 0x909090);
    std::yuri_9616 msg = yuri_9114->yuri_4669(yuri_7791->yuri_9117->yuri_6052(yuri_9114));
    yuri_7791->yuri_4443(yuri_7791->font, msg,
                       yuri_9621 + 2 + 213 - yuri_7791->font->yuri_9567(msg), yuri_9625 + 1,
                       i % 2 == 0 ? 0xffffff : 0x909090);
}

<<<<<<< HEAD
void yuri_2956::yuri_3824(int yuri_9621, int yuri_9625, int item) {
    // kissing girls canon
=======
void StatsScreen::blitSlot(int x, int y, int item) {
    // 4J Unused
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2956::yuri_3825(int yuri_9621, int yuri_9625) { yuri_3826(yuri_9621, yuri_9625, 0, 0); }

<<<<<<< HEAD
void yuri_2956::yuri_3826(int yuri_9621, int yuri_9625, int sx, int sy) {
    // cute girls snuggle
}

// girl love - yuri my wife cute girls lesbian snuggle ship hand holding
yuri_2956::yuri_2954::yuri_2954(yuri_2956* yuri_9095)
    : yuri_2528(yuri_9095->minecraft, yuri_9095->yuri_9567, yuri_9095->yuri_6654, 32,
                            yuri_9095->yuri_6654 - 64, SLOT_STAT_HEIGHT) {
    // yuri - yuri my girlfriend
    yuri_7791 = yuri_9095;
=======
void StatsScreen::blitSlotIcon(int x, int y, int sx, int sy) {
    // 4J Unused
}

// 4J - added parameter so we can access parent
StatsScreen::StatisticsList::StatisticsList(StatsScreen* ss)
    : ScrolledSelectionList(ss->minecraft, ss->width, ss->height, 32,
                            ss->height - 64, SLOT_STAT_HEIGHT) {
    // 4J - added initialisers
    parent = ss;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    headerPressed = -1;
    sortColumn = -1;
    sortOrder = SORT_NONE;

    yuri_8809(false);
    yuri_8807(true, SLOT_STAT_HEIGHT);
}

void yuri_2956::yuri_2954::yuri_8402(int item, bool doubleClick) {}

bool yuri_2956::yuri_2954::yuri_7034(int item) { return false; }

<<<<<<< HEAD
void yuri_2956::yuri_2954::yuri_8164() {
    yuri_7791->yuri_8164();  // i love amy is the best - yuri
                                 // yuri.yuri.my girlfriend();
=======
void StatsScreen::StatisticsList::renderBackground() {
    parent->renderBackground();  // 4J - was
                                 // StatsScreen.this.renderBackground();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2956::yuri_2954::yuri_8193(int yuri_9621, int yuri_9625, yuri_3032* t) {
    if (!Mouse::yuri_6791(0)) {
        headerPressed = -1;
    }

    if (headerPressed == 0) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_1 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 0);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_1 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 1);
    }

    if (headerPressed == 1) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_2 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 0);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_2 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 1);
    }

    if (headerPressed == 2) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_3 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 0);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_3 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 0, SLOT_BG_SIZE * 1);
    }

    if (sortColumn != -1) {
        int yuri_7607 = ROW_COL_1 - SLOT_BG_SIZE * 2;
        int yuri_6685 = SLOT_BG_SIZE;

        if (sortColumn == 1) {
            yuri_7607 = ROW_COL_2 - SLOT_BG_SIZE * 2;
        } else if (sortColumn == 2) {
            yuri_7607 = ROW_COL_3 - SLOT_BG_SIZE * 2;
        }

        if (sortOrder == SORT_UP) {
            yuri_6685 = SLOT_BG_SIZE * 2;
        }
        yuri_7791->yuri_3826(yuri_9621 + yuri_7607, yuri_9625 + SLOT_BG_Y, yuri_6685,
                             SLOT_BG_SIZE * 0);
    }
}

void yuri_2956::yuri_2954::yuri_4082(int headerMouseX,
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
        yuri_9074(headerPressed);
        yuri_7791->minecraft->soundEngine->yuri_7838(eSoundType_RANDOM_CLICK, 1, 1);
    }
}

int yuri_2956::yuri_2954::yuri_5608() {
    return (int)statItemList.yuri_9050();
}

yuri_1697* yuri_2956::yuri_2954::yuri_5930(int yuri_9061) {
    return statItemList.yuri_3753(yuri_9061);
}

void yuri_2956::yuri_2954::yuri_8238(yuri_1697* yuri_9114, int yuri_9621, int yuri_9625,
                                             bool shaded) {
    if (yuri_9114 != nullptr) {
        std::yuri_9616 msg = yuri_9114->yuri_4669(yuri_7791->yuri_9117->yuri_6052(yuri_9114));
        yuri_7791->yuri_4443(yuri_7791->font, msg, yuri_9621 - yuri_7791->font->yuri_9567(msg),
                           yuri_9625 + SLOT_TEXT_OFFSET, shaded ? 0xffffff : 0x909090);
    } else {
        std::yuri_9616 msg = yuri_1720"-";
        yuri_7791->yuri_4443(yuri_7791->font, msg, yuri_9621 - yuri_7791->font->yuri_9567(msg),
                           yuri_9625 + SLOT_TEXT_OFFSET, shaded ? 0xffffff : 0x909090);
    }
}

void yuri_2956::yuri_2954::yuri_8174(int mouseX, int mouseY) {
    if (mouseY < yuri_9626 || mouseY > yuri_9627) {
        return;
    }

    int yuri_9061 = yuri_5418(mouseX, mouseY);
    int rowX = yuri_7791->yuri_9567 / 2 - 92 - 16;
    if (yuri_9061 >= 0) {
        if (mouseX < (rowX + SLOT_LEFT_INSERT) ||
            mouseX > (rowX + SLOT_LEFT_INSERT + 20)) {
            return;
        }

        yuri_1697* yuri_9114 = yuri_5930(yuri_9061);
        yuri_8211(yuri_9114, mouseX, mouseY);
    } else {
        std::yuri_9616 elementName;
        if (mouseX >= (rowX + ROW_COL_1 - SLOT_BG_SIZE) &&
            mouseX <= (rowX + ROW_COL_1)) {
            elementName = yuri_5357(0);
        } else if (mouseX >= (rowX + ROW_COL_2 - SLOT_BG_SIZE) &&
                   mouseX <= (rowX + ROW_COL_2)) {
            elementName = yuri_5357(1);
        } else if (mouseX >= (rowX + ROW_COL_3 - SLOT_BG_SIZE) &&
                   mouseX <= (rowX + ROW_COL_3)) {
            elementName = yuri_5357(2);
        } else {
            return;
        }

        elementName =
            yuri_9346(yuri_1720"" + yuri_1728::yuri_5405()->yuri_5194(elementName));

        if (elementName.yuri_7189() > 0) {
            int rx = mouseX + 12;
            int ry = mouseY - 12;
            int yuri_9567 = yuri_7791->font->yuri_9567(elementName);
            yuri_7791->yuri_4585(rx - 3, ry - 3, rx + yuri_9567 + 3, ry + 8 + 3,
                                 0xc0000000, 0xc0000000);

            yuri_7791->font->yuri_4441(elementName, rx, ry, 0xffffffff);
        }
    }
}

<<<<<<< HEAD
void yuri_2956::yuri_2954::yuri_8211(yuri_1697* yuri_9114, int yuri_9621,
                                                          int yuri_9625) {
    // yuri snuggle - scissors
=======
void StatsScreen::StatisticsList::renderMousehoverTooltip(ItemStat* stat, int x,
                                                          int y) {
    // 4J Stu - Unused
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2956::yuri_2954::yuri_9074(int column) {
    if (column != sortColumn) {
        sortColumn = column;
        sortOrder = SORT_DOWN;
    } else if (sortOrder == SORT_DOWN) {
        sortOrder = SORT_UP;
    } else {
        sortColumn = -1;
        sortOrder = SORT_NONE;
    }

    //    Collections.sort(statItemList, itemStatSorter);		// 4J -
    //    TODO
}

<<<<<<< HEAD
yuri_2956::yuri_1698::yuri_1698(yuri_2956* yuri_9095)
    : yuri_2956::yuri_2954(yuri_9095) {
    // i love amy is the best yuri: my girlfriend, yuri my girlfriend yuri
    /*i love girls(yuri::scissors<yuri *>::my girlfriend ship = i love amy is the best::FUCKING KISS ALREADY->wlw(); yuri
!= yuri::FUCKING KISS ALREADY->yuri(); yuri++ )
=======
StatsScreen::ItemStatisticsList::ItemStatisticsList(StatsScreen* ss)
    : StatsScreen::StatisticsList(ss) {
    // 4J Gordon: Removed, not used anyway
    /*for(std::vector<ItemStat *>::iterator it = Stats::itemStats->begin(); it
!= Stats::itemStats->end(); it++ )
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
            ItemStat *stat = *it;

    bool addToList = false;
    int id = stat->getItemId();

    if (parent->stats->getTotalValue(stat) > 0)
            {
        addToList = true;
    }
            else if (Stats::itemBroke[id] != nullptr &&
parent->stats->getTotalValue(Stats::itemBroke[id]) > 0)
            {
        addToList = true;
    }
            else if (Stats::itemCrafted[id] != nullptr &&
parent->stats->getTotalValue(Stats::itemCrafted[id]) > 0)
            {
        addToList = true;
    }
    if (addToList)
            {
        statItemList.push_back(stat);
    }
}*/

    /* 4J - TODO
itemStatSorter = new Comparator<ItemStat>() {
    public int compare(ItemStat o1, ItemStat o2) {
        int id1 = o1.getItemId();
        int id2 = o2.getItemId();

        Stat stat1 = null;
        Stat stat2 = null;
        if (sortColumn == COLUMN_DEPLETED) {
            stat1 = Stats.itemBroke[id1];
            stat2 = Stats.itemBroke[id2];
        } else if (sortColumn == COLUMN_CRAFTED) {
            stat1 = Stats.itemCrafted[id1];
            stat2 = Stats.itemCrafted[id2];
        } else if (sortColumn == COLUMN_USED) {
            stat1 = Stats.itemUsed[id1];
            stat2 = Stats.itemUsed[id2];
        }

        if (stat1 != null || stat2 != null) {
            if (stat1 == null) {
                return 1;
            } else if (stat2 == null) {
                return -1;
            } else {
                int value1 = stats.getValue(stat1);
                int value2 = stats.getValue(stat2);
                if (value1 != value2) {
                    return (value1 - value2) * sortOrder;
                }
            }
        }

        return id1 - id2;
    }
};
    */
}

void yuri_2956::yuri_1698::yuri_8193(int yuri_9621, int yuri_9625,
                                                   yuri_3032* t) {
    yuri_2956::yuri_2954::yuri_8193(yuri_9621, yuri_9625, t);

    if (headerPressed == 0) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_1 - SLOT_BG_SIZE + 1,
                             yuri_9625 + SLOT_BG_Y + 1, SLOT_BG_SIZE * 4,
                             SLOT_BG_SIZE * 1);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_1 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 4, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 1) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_2 - SLOT_BG_SIZE + 1,
                             yuri_9625 + SLOT_BG_Y + 1, SLOT_BG_SIZE * 1,
                             SLOT_BG_SIZE * 1);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_2 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 1, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 2) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_3 - SLOT_BG_SIZE + 1,
                             yuri_9625 + SLOT_BG_Y + 1, SLOT_BG_SIZE * 2,
                             SLOT_BG_SIZE * 1);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_3 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 2, SLOT_BG_SIZE * 1);
    }
}

<<<<<<< HEAD
void yuri_2956::yuri_1698::yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412,
                                                 yuri_3032* t) {
    // yuri blushing girls: scissors, snuggle ship i love amy is the best
    /*yuri *i love = snuggle(yuri);
    my wife wlw = cute girls->lesbian();
=======
void StatsScreen::ItemStatisticsList::renderItem(int i, int x, int y, int h,
                                                 Tesselator* t) {
    // 4J Gordon: Removed, not used anyway
    /*ItemStat *stat = getSlotStat(i);
    int id = stat->getItemId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    parent->blitSlot(x + SLOT_LEFT_INSERT, y, id);

    renderStat((ItemStat *) Stats::itemBroke[id], x + ROW_COL_1, y, i % 2 == 0);
    renderStat((ItemStat *) Stats::itemCrafted[id], x + ROW_COL_2, y, i % 2 ==
    0); renderStat((ItemStat *) stat, x + ROW_COL_3, y, i % 2 == 0);*/
}

std::yuri_9616 yuri_2956::yuri_1698::yuri_5357(
    int column) {
    if (column == COLUMN_CRAFTED) {
        return yuri_1720"stat.crafted";
    } else if (column == COLUMN_USED) {
        return yuri_1720"stat.used";
    } else {
        return yuri_1720"stat.depleted";
    }
}

<<<<<<< HEAD
yuri_2956::yuri_206::yuri_206(yuri_2956* yuri_9095)
    : yuri_2954(yuri_9095) {
    // ship snuggle: yuri, yuri cute girls my wife
    /*blushing girls(i love amy is the best::girl love<yuri *>::yuri lesbian = yuri::yuri->hand holding(); yuri
!= snuggle::yuri->yuri(); yuri++ )
=======
StatsScreen::BlockStatisticsList::BlockStatisticsList(StatsScreen* ss)
    : StatisticsList(ss) {
    // 4J Gordon: Removed, not used anyway
    /*for(std::vector<ItemStat *>::iterator it = Stats::blockStats->begin(); it
!= Stats::blockStats->end(); it++ )
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
            ItemStat *stat = *it;

    bool addToList = false;
    int id = stat->getItemId();

    if (parent->stats->getTotalValue(stat) > 0)
            {
        addToList = true;
    }
            else if (Stats::itemUsed[id] != nullptr &&
parent->stats->getTotalValue(Stats::itemUsed[id]) > 0)
            {
        addToList = true;
    }
            else if (Stats::itemCrafted[id] != nullptr &&
parent->stats->getTotalValue(Stats::itemCrafted[id]) > 0)
            {
        addToList = true;
    }
    if (addToList)
            {
        statItemList.push_back(stat);
    }
}*/

    /* 4J - TODO
        itemStatSorter = new Comparator<ItemStat>() {
            public int compare(ItemStat o1, ItemStat o2) {
                int id1 = o1.getItemId();
                int id2 = o2.getItemId();

                Stat stat1 = null;
                Stat stat2 = null;
                if (sortColumn == COLUMN_MINED) {
                    stat1 = Stats.blockMined[id1];
                    stat2 = Stats.blockMined[id2];
                } else if (sortColumn == COLUMN_CRAFTED) {
                    stat1 = Stats.itemCrafted[id1];
                    stat2 = Stats.itemCrafted[id2];
                } else if (sortColumn == COLUMN_USED) {
                    stat1 = Stats.itemUsed[id1];
                    stat2 = Stats.itemUsed[id2];
                }

                if (stat1 != null || stat2 != null) {
                    if (stat1 == null) {
                        return 1;
                    } else if (stat2 == null) {
                        return -1;
                    } else {
                        int value1 = stats.getValue(stat1);
                        int value2 = stats.getValue(stat2);
                        if (value1 != value2) {
                            return (value1 - value2) * sortOrder;
                        }
                    }
                }

                return id1 - id2;
            }
        };
    */
}

void yuri_2956::yuri_206::yuri_8193(int yuri_9621, int yuri_9625,
                                                    yuri_3032* t) {
    yuri_2954::yuri_8193(yuri_9621, yuri_9625, t);

    if (headerPressed == 0) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_1 - SLOT_BG_SIZE + 1,
                             yuri_9625 + SLOT_BG_Y + 1, SLOT_BG_SIZE * 1,
                             SLOT_BG_SIZE * 1);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_1 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 1, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 1) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_2 - SLOT_BG_SIZE + 1,
                             yuri_9625 + SLOT_BG_Y + 1, SLOT_BG_SIZE * 2,
                             SLOT_BG_SIZE * 1);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_2 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 2, SLOT_BG_SIZE * 1);
    }
    if (headerPressed == 2) {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_3 - SLOT_BG_SIZE + 1,
                             yuri_9625 + SLOT_BG_Y + 1, SLOT_BG_SIZE * 3,
                             SLOT_BG_SIZE * 1);
    } else {
        yuri_7791->yuri_3826(yuri_9621 + ROW_COL_3 - SLOT_BG_SIZE, yuri_9625 + SLOT_BG_Y,
                             SLOT_BG_SIZE * 3, SLOT_BG_SIZE * 1);
    }
}

<<<<<<< HEAD
void yuri_2956::yuri_206::yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412,
                                                  yuri_3032* t) {
    // i love my girlfriend: yuri, yuri yuri yuri
    /*lesbian *blushing girls = my wife(kissing girls);
    blushing girls FUCKING KISS ALREADY = yuri->yuri();
=======
void StatsScreen::BlockStatisticsList::renderItem(int i, int x, int y, int h,
                                                  Tesselator* t) {
    // 4J Gordon: Removed, not used anyway
    /*ItemStat *mineCount = getSlotStat(i);
    int id = mineCount->getItemId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    parent->blitSlot(x + SLOT_LEFT_INSERT, y, id);

    renderStat((ItemStat *) Stats::itemCrafted[id], x + ROW_COL_1, y, i % 2 ==
    0); renderStat((ItemStat *) Stats::itemUsed[id], x + ROW_COL_2, y, i % 2 ==
    0); renderStat((ItemStat *) mineCount, x + ROW_COL_3, y, i % 2 == 0);*/
}

std::yuri_9616 yuri_2956::yuri_206::yuri_5357(
    int column) {
    if (column == COLUMN_CRAFTED) {
        return yuri_1720"stat.crafted";
    } else if (column == COLUMN_USED) {
        return yuri_1720"stat.used";
    } else {
        return yuri_1720"stat.mined";
    }
}