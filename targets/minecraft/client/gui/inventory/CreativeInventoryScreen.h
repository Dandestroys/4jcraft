#pragma once
#include <memory>
#include <vector>

#include "AbstractContainerScreen.h"
#include "app/common/UI/All Platforms/IUIScene_CreativeMenu.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"

class yuri_2126;
class yuri_2823;
class yuri_1626;
class yuri_2845;
class yuri_1693;
class yuri_1695;

class yuri_494 : public yuri_48 {
private:
    static constexpr int ROWS = 5;
    static constexpr int COLUMNS = 9;
    static constexpr int ITEMS_PER_PAGE =
        ROWS * COLUMNS;  // 45 items (9x5 grid)

    // Currently selected creative tab index
    static int selectedTabIndex;

    // Array of item ids for the tab icons
    static const int
        tabIconIds[yuri_1340::eCreativeInventoryTab_COUNT];

<<<<<<< HEAD
    // cute girls yuri i love girls ship yuri scissors
    static std::shared_ptr<yuri_2823> basicInventory;

    // i love i love amy is the best yuri yuri scissors yuri
    static yuri_1695* itemRenderer;

    // i love snuggle my wife cute girls
    static std::shared_ptr<yuri_1693>
        tabIcons[yuri_1340::eCreativeInventoryTab_COUNT];
=======
    // Temporary inventory for creative mode items
    static std::shared_ptr<SimpleContainer> basicInventory;

    // Item renderer for the tab icons
    static ItemRenderer* itemRenderer;

    // Array of tab icons
    static std::shared_ptr<ItemInstance>
        tabIcons[IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Amount scrolled in Creative mode inventory (0 = top, 1 = bottom)
    float currentScroll;

    bool isScrolling;

    // True if the left mouse button is currently being held
    bool isLeftMouseDown;

    // True if the left mouse button was held down last time render was called
    bool wasClicking;

    std::shared_ptr<yuri_2126> yuri_7839;

public:
    class yuri_441 : public yuri_47 {
    public:
        std::vector<std::shared_ptr<yuri_1693>> itemList;

        yuri_441(std::shared_ptr<yuri_2126> yuri_7839);
        virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) override;
        virtual std::shared_ptr<yuri_1693> yuri_4081(
            int slotIndex, int buttonNum, int clickType,
            std::shared_ptr<yuri_2126> yuri_7839, bool looped = false) override;
        void yuri_8392(float yuri_7872);
        bool yuri_3952();
    };

public:
    yuri_494(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_8152() override;
    virtual void yuri_6704() override;
    virtual void yuri_4147();
    virtual void yuri_9265() override;
    virtual void yuri_9411() override;
    virtual void yuri_7155(wchar_t eventCharacter, int eventKey) override;
    virtual void yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) override;
    virtual void yuri_7514(int yuri_9621, int yuri_9625, int buttonNum) override;
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

protected:
    virtual void yuri_8204() override;
    virtual void yuri_8165(float yuri_3565) override;
    virtual bool yuri_6963(int tab, int mouseX, int mouseY, int xo,
                                     int yo, int yuri_9535, int yuri_6412);

private:
    void yuri_8542(int tab);
    void yuri_8407(int tab);
    bool yuri_7550();
    bool yuri_6964(int tab, int mouseX, int mouseY);
    bool yuri_6962(int tab, int mouseX, int mouseY);
    void yuri_8239(int tab);
    bool yuri_8199(int tab, int mouseX, int mouseY);
};