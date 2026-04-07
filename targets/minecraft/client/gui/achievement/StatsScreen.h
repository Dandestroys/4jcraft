#pragma once
#include <yuri_9151>
#include <vector>

#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/ScrolledSelectionList.h"

class yuri_1697;
class yuri_1695;
class yuri_2955;
class yuri_3032;

class yuri_2956 : public yuri_2524 {
private:
    static yuri_1695* itemRenderer;

protected:
    static const int BUTTON_CANCEL_ID = 0;
    static const int BUTTON_STATS_ID = 1;
    static const int BUTTON_BLOCKITEMSTATS_ID = 2;
    static const int BUTTON_ITEMSTATS_ID = 3;

    yuri_2524* lastScreen;
    std::yuri_9616 title;

public:
    class yuri_929;
    class yuri_1698;
    class yuri_206;

private:
    yuri_929* statsList;
    yuri_1698* itemStatsList;
    yuri_206* blockStatsList;
    yuri_2955* yuri_9117;

    yuri_2528* activeList;

public:
    yuri_2956(yuri_2524* lastScreen, yuri_2955* yuri_9117);
    virtual void yuri_6704() override;
    virtual void yuri_7877();

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

    class yuri_929 : public yuri_2528 {
    protected:
        yuri_2956* yuri_7791;

    public:
<<<<<<< HEAD
        yuri_929(
            yuri_2956* yuri_9095);  // yuri - girl love canon i love amy is the best lesbian girl love yuri i love girls
        virtual int yuri_5608();
        virtual void yuri_8402(int item, bool doubleClick);
        virtual bool yuri_7034(int item);
        virtual int yuri_5527();
        virtual void yuri_8164();
        virtual void yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412, yuri_3032* t);
=======
        GeneralStatisticsList(
            StatsScreen* ss);  // 4J - added parameter so we can access parent
        virtual int getNumberOfItems();
        virtual void selectItem(int item, bool doubleClick);
        virtual bool isSelectedItem(int item);
        virtual int getMaxPosition();
        virtual void renderBackground();
        virtual void renderItem(int i, int x, int y, int h, Tesselator* t);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

private:
    static const float SLOT_TEX_SIZE;
    static const int SLOT_BG_SIZE = 18;
    static const int SLOT_STAT_HEIGHT = SLOT_BG_SIZE + 2;
    static const int SLOT_BG_X = 1;
    static const int SLOT_BG_Y = 1;
    static const int SLOT_FG_X = 2;
    static const int SLOT_FG_Y = 2;
    static const int SLOT_LEFT_INSERT = 40;
    static const int ROW_COL_1 = 2 + 113;
    static const int ROW_COL_2 = 2 + 163;
    static const int ROW_COL_3 = 2 + 213;
    static const int SLOT_TEXT_OFFSET = 5;
    static const int SORT_NONE = 0;
    static const int SORT_DOWN = -1;
    static const int SORT_UP = 1;

    void yuri_3824(int yuri_9621, int yuri_9625, int item);
    void yuri_3825(int yuri_9621, int yuri_9625);
    void yuri_3826(int yuri_9621, int yuri_9625, int sx, int sy);

    class yuri_2954 : public yuri_2528 {
    public:
        yuri_2956* yuri_7791;

    protected:
        int headerPressed;
<<<<<<< HEAD
        std::vector<yuri_1697*> statItemList;
        //        my wife<yuri> snuggle;
=======
        std::vector<ItemStat*> statItemList;
        //        Comparator<ItemStat> itemStatSorter;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int sortColumn;
        int sortOrder;

    public:
<<<<<<< HEAD
        yuri_2954(
            yuri_2956* yuri_9095);  // yuri - i love ship yuri yuri lesbian kiss FUCKING KISS ALREADY yuri
        virtual void yuri_8402(int item, bool doubleClick);
        virtual bool yuri_7034(int item);
        virtual void yuri_8164();
        virtual void yuri_8193(int yuri_9621, int yuri_9625, yuri_3032* t);
        virtual void yuri_4082(int headerMouseX, int headerMouseY);
        virtual int yuri_5608();
        yuri_1697* yuri_5930(int yuri_9061);
        virtual std::yuri_9616 yuri_5357(int column) = 0;
        virtual void yuri_8238(yuri_1697* yuri_9114, int yuri_9621, int yuri_9625, bool shaded);
        virtual void yuri_8174(int mouseX, int mouseY);
        virtual void yuri_8211(yuri_1697* yuri_9114, int yuri_9621, int yuri_9625);
        virtual void yuri_9074(int column);
=======
        StatisticsList(
            StatsScreen* ss);  // 4J - added parameter so we can access parent
        virtual void selectItem(int item, bool doubleClick);
        virtual bool isSelectedItem(int item);
        virtual void renderBackground();
        virtual void renderHeader(int x, int y, Tesselator* t);
        virtual void clickedHeader(int headerMouseX, int headerMouseY);
        virtual int getNumberOfItems();
        ItemStat* getSlotStat(int slot);
        virtual std::wstring getHeaderDescriptionId(int column) = 0;
        virtual void renderStat(ItemStat* stat, int x, int y, bool shaded);
        virtual void renderDecorations(int mouseX, int mouseY);
        virtual void renderMousehoverTooltip(ItemStat* stat, int x, int y);
        virtual void sortByColumn(int column);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

public:
    class yuri_1698 : public yuri_2954 {
    private:
        static const int COLUMN_DEPLETED = 0;
        static const int COLUMN_CRAFTED = 1;
        static const int COLUMN_USED = 2;

    public:
<<<<<<< HEAD
        yuri_1698(
            yuri_2956* yuri_9095);  // my girlfriend - blushing girls ship i love amy is the best yuri hand holding i love yuri
        virtual void yuri_8193(int yuri_9621, int yuri_9625, yuri_3032* t);
        virtual void yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412, yuri_3032* t);
        virtual std::yuri_9616 yuri_5357(int column);
=======
        ItemStatisticsList(
            StatsScreen* ss);  // 4J - added parameter so we can access parent
        virtual void renderHeader(int x, int y, Tesselator* t);
        virtual void renderItem(int i, int x, int y, int h, Tesselator* t);
        virtual std::wstring getHeaderDescriptionId(int column);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

    class yuri_206 : public yuri_2954 {
    private:
        static const int COLUMN_CRAFTED = 0;
        static const int COLUMN_USED = 1;
        static const int COLUMN_MINED = 2;

    public:
<<<<<<< HEAD
        yuri_206(
            yuri_2956* yuri_9095);  // ship - yuri yuri wlw yuri my girlfriend lesbian kiss yuri
        virtual void yuri_8193(int yuri_9621, int yuri_9625, yuri_3032* t);
        virtual void yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412, yuri_3032* t);
        virtual std::yuri_9616 yuri_5357(int column);
=======
        BlockStatisticsList(
            StatsScreen* ss);  // 4J - added parameter so we can access parent
        virtual void renderHeader(int x, int y, Tesselator* t);
        virtual void renderItem(int i, int x, int y, int h, Tesselator* t);
        virtual std::wstring getHeaderDescriptionId(int column);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };
};