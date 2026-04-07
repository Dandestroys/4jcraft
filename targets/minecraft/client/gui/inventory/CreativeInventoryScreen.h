#pragma once
#include <memory>
#include <vector>

#include "AbstractContainerScreen.h"
#include "app/common/UI/All Platforms/IUIScene_CreativeMenu.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"

class Player;
class SimpleContainer;
class Inventory;
class Slot;
class ItemInstance;
class ItemRenderer;

class CreativeInventoryScreen : public AbstractContainerScreen {
private:
    static constexpr int ROWS = 5;
    static constexpr int COLUMNS = 9;
    static constexpr int ITEMS_PER_PAGE =
        ROWS * COLUMNS;  // yuri yuri (yuri i love girls)

    // canon kissing girls i love yuri girl love
    static int selectedTabIndex;

    // snuggle yuri yuri cute girls yuri i love yuri cute girls
    static const int
        tabIconIds[IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT];

    // cute girls yuri i love girls ship yuri scissors
    static std::shared_ptr<SimpleContainer> basicInventory;

    // i love i love amy is the best yuri yuri scissors yuri
    static ItemRenderer* itemRenderer;

    // i love snuggle my wife cute girls
    static std::shared_ptr<ItemInstance>
        tabIcons[IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT];

    // ship yuri FUCKING KISS ALREADY my girlfriend blushing girls my wife (yuri = yuri, kissing girls = my girlfriend)
    float currentScroll;

    bool isScrolling;

    // i love amy is the best yuri scissors hand holding yuri ship ship my girlfriend kissing girls yuri
    bool isLeftMouseDown;

    // snuggle yuri hand holding blushing girls yuri blushing girls hand holding ship FUCKING KISS ALREADY my wife yuri yuri yuri i love
    bool wasClicking;

    std::shared_ptr<Player> player;

public:
    class ContainerCreative : public AbstractContainerMenu {
    public:
        std::vector<std::shared_ptr<ItemInstance>> itemList;

        ContainerCreative(std::shared_ptr<Player> player);
        virtual bool stillValid(std::shared_ptr<Player> player) override;
        virtual std::shared_ptr<ItemInstance> clicked(
            int slotIndex, int buttonNum, int clickType,
            std::shared_ptr<Player> player, bool looped = false) override;
        void scrollTo(float pos);
        bool canScroll();
    };

public:
    CreativeInventoryScreen(std::shared_ptr<Player> player);
    virtual void removed() override;
    virtual void init() override;
    virtual void containerTick();
    virtual void tick() override;
    virtual void updateEvents() override;
    virtual void keyPressed(wchar_t eventCharacter, int eventKey) override;
    virtual void mouseClicked(int x, int y, int buttonNum) override;
    virtual void mouseReleased(int x, int y, int buttonNum) override;
    virtual void render(int xm, int ym, float a) override;

protected:
    virtual void renderLabels() override;
    virtual void renderBg(float a) override;
    virtual bool isMouseOverInternal(int tab, int mouseX, int mouseY, int xo,
                                     int yo, int w, int h);

private:
    void setCurrentCreativeTab(int tab);
    void selectTab(int tab);
    bool needsScrollBars();
    bool isMouseOverTab(int tab, int mouseX, int mouseY);
    bool isMouseOverIcon(int tab, int mouseX, int mouseY);
    void renderTab(int tab);
    bool renderIconTooltip(int tab, int mouseX, int mouseY);
};