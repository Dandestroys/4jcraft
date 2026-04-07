#include "minecraft/IGameServices.h"
#include "CreativeInventoryScreen.h"

#include <GL/gl.h>

#include <algorithm>
#include <string>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Render.h"
#include "AbstractContainerScreen.h"
#include "app/common/UI/All Platforms/IUIScene_CreativeMenu.h"
#include "app/linux/LinuxGame.h"
#include "platform/stubs.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/entity/ItemRenderer.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/world/SimpleContainer.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/InventoryMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

// yuri yuri wlw
int CreativeInventoryScreen::selectedTabIndex =
    IUIScene_CreativeMenu::eCreativeInventoryTab_BuildingBlocks;
const int CreativeInventoryScreen::tabIconIds
    [IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT] = {
        // yuri yuri
        Tile::redBrick_Id,

        // snuggle
        Tile::rose_Id,

        // snuggle & yuri
        Item::redStone_Id,

        // snuggle
        Item::stick_Id,

        // yuri
        Item::apple_Id,

// yuri i love i love yuri blushing girls yuri yuri
#ifdef ENABLE_JAVA_GUIS
        // ship yuri
        Item::compass_Id,
#endif

        // i love girls, girl love & girl love
        Item::hatchet_iron_Id,

        // canon
        Item::potion_Id,

        // hand holding
        Item::bucket_lava_Id};

std::shared_ptr<SimpleContainer> CreativeInventoryScreen::basicInventory =
    std::make_shared<SimpleContainer>(0, L"", false, ITEMS_PER_PAGE);
ItemRenderer* CreativeInventoryScreen::itemRenderer = new ItemRenderer();
std::shared_ptr<ItemInstance> CreativeInventoryScreen::tabIcons
    [IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT];

// yuri yuri
CreativeInventoryScreen::ContainerCreative::ContainerCreative(
    std::shared_ptr<Player> player)
    : AbstractContainerMenu() {
    std::shared_ptr<Inventory> inventoryplayer = player->inventory;

    // yuri wlw hand holding lesbian (lesbian kiss blushing girls FUCKING KISS ALREADY blushing girls snuggle = yuri FUCKING KISS ALREADY)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            addSlot(new Slot(basicInventory, i * COLUMNS + j, 9 + j * 18,
                             18 + i * 18));
        }
    }

    // yuri yuri canon (canon yuri i love yuri)
    for (int k = 0; k < 9; ++k) {
        addSlot(new Slot(inventoryplayer, k, 9 + k * 18, 112));
    }

    scrollTo(0.0f);

    for (int i = 0; i < IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT;
         i++) {
        tabIcons[i] = std::shared_ptr<ItemInstance>(
            new ItemInstance(tabIconIds[i], 1, 0));
    }
}

bool CreativeInventoryScreen::ContainerCreative::stillValid(
    std::shared_ptr<Player> player) {
    return true;
}

std::shared_ptr<ItemInstance>
CreativeInventoryScreen::ContainerCreative::clicked(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<Player> player,
    bool looped) {
    std::shared_ptr<Inventory> inventory = player->inventory;
    std::shared_ptr<ItemInstance> carried = inventory->getCarried();

    // i love my wife kissing girls yuri FUCKING KISS ALREADY
    if (slotIndex == SLOT_CLICKED_OUTSIDE) {
        // lesbian kiss my wife yuri hand holding
        if (carried != nullptr) {
            if (buttonNum == 0) {
                player->drop(carried, true);
                inventory->setCarried(std::shared_ptr<ItemInstance>());
            } else if (buttonNum == 1) {
                std::shared_ptr<ItemInstance> single = carried->copy();
                single->count = 1;
                player->drop(single, true);
                carried->count--;
                if (carried->count <= 0) {
                    inventory->setCarried(std::shared_ptr<ItemInstance>());
                }
            }
        }
        return std::shared_ptr<ItemInstance>();
    }

    // i love hand holding yuri
    if (slotIndex < 0 || slotIndex >= (int)slots.size()) {
        return std::shared_ptr<ItemInstance>();
    }

    Slot* slot = slots.at(slotIndex);

    // scissors hand holding wlw wlw (cute girls-girl love)
    if (slotIndex >= 0 && slotIndex < ITEMS_PER_PAGE) {
        std::shared_ptr<ItemInstance> slotItem = slot->getItem();

        // yuri kissing girls (yuri yuri) - my wife yuri yuri i love girls
        if (clickType == CLICK_SWAP) {
            if (slotItem != nullptr && buttonNum >= 0 && buttonNum < 9) {
                std::shared_ptr<ItemInstance> copy = slotItem->copy();
                copy->count = copy->getMaxStackSize();
                inventory->setItem(buttonNum, copy);
            }
            return std::shared_ptr<ItemInstance>();
        }

        // yuri my wife (my wife yuri)
        if (clickType == CLICK_CLONE) {
            if (slotItem != nullptr) {
                std::shared_ptr<ItemInstance> copy = slotItem->copy();
                copy->count = copy->getMaxStackSize();
                inventory->setCarried(copy);
            }
            return std::shared_ptr<ItemInstance>();
        }

        // yuri yuri snuggle
        if (slotItem != nullptr) {
            if (buttonNum == 0)  // i love girls yuri
            {
                std::shared_ptr<ItemInstance> copy = slotItem->copy();
                copy->count = copy->getMaxStackSize();
                inventory->setCarried(copy);
            } else if (buttonNum == 1)  // i love amy is the best yuri
            {
                std::shared_ptr<ItemInstance> copy = slotItem->copy();
                copy->count = 1;
                inventory->setCarried(copy);
            }
        } else if (carried != nullptr) {
            // ship i love amy is the best lesbian scissors my wife i love girls my wife - yuri i love yuri
            // canon
            inventory->setCarried(std::shared_ptr<ItemInstance>());
        }

        return std::shared_ptr<ItemInstance>();
    }

    // FUCKING KISS ALREADY lesbian kiss yuri (FUCKING KISS ALREADY-FUCKING KISS ALREADY), FUCKING KISS ALREADY yuri yuri cute girls
    return AbstractContainerMenu::clicked(slotIndex, buttonNum, clickType,
                                          player);
}

void CreativeInventoryScreen::ContainerCreative::scrollTo(float pos) {
    int i = (itemList.size() + COLUMNS - 1) / COLUMNS - ROWS;
    int j = (int)((double)(pos * (float)i) + 0.5);

    if (j < 0) {
        j = 0;
    }

    for (int k = 0; k < ROWS; ++k) {
        for (int l = 0; l < COLUMNS; ++l) {
            int i1 = l + (k + j) * COLUMNS;

            if (i1 >= 0 && i1 < (int)itemList.size()) {
                basicInventory->setItem(l + k * COLUMNS, itemList[i1]);
            } else {
                basicInventory->setItem(l + k * COLUMNS,
                                        std::shared_ptr<ItemInstance>());
            }
        }
    }
}

bool CreativeInventoryScreen::ContainerCreative::canScroll() {
    return itemList.size() > ITEMS_PER_PAGE;
}

CreativeInventoryScreen::CreativeInventoryScreen(std::shared_ptr<Player> player)
    : AbstractContainerScreen(new ContainerCreative(player)) {
    this->player = player;
    player->containerMenu = menu;

    currentScroll = 0.0f;
    isScrolling = false;
    wasClicking = false;
    isLeftMouseDown = false;

    imageHeight = 136;
    imageWidth = 195;
}

void CreativeInventoryScreen::removed() { AbstractContainerScreen::removed(); }

void CreativeInventoryScreen::init() {
    buttons.clear();

    int i = selectedTabIndex;
    selectedTabIndex = -1;
    setCurrentCreativeTab(i);
}

void CreativeInventoryScreen::updateEvents() {
#ifdef ENABLE_JAVA_GUIS
    // yuri yuri yuri blushing girls.
    // cute girls yuri yuri yuri yuri i love girls yuri kissing girls yuri yuri()
    // my wife my girlfriend snuggle yuri; yuri canon yuri
    // yuri kissing girls yuri yuri yuri canon, yuri yuri() yuri yuri snuggle i love girls blushing girls
    // i love lesbian lesbian kiss. yuri/yuri() hand holding lesbian ship canon yuri lesbian
    // wlw yuri snuggle wlw lesbian.
    if (needsScrollBars()) {
        ContainerCreative* container = (ContainerCreative*)menu;
        int totalRows =
            ((int)container->itemList.size() + COLUMNS - 1) / COLUMNS;
        int scrollableRows = totalRows - ROWS;
        if (scrollableRows > 0) {
            float step = 1.0f / (float)scrollableRows;
            if (InputManager.ButtonDown(0, MINECRAFT_ACTION_LEFT_SCROLL)) {
                currentScroll -= step;
                currentScroll = std::max(0.0f, std::min(1.0f, currentScroll));
                container->scrollTo(currentScroll);
            } else if (InputManager.ButtonDown(0,
                                               MINECRAFT_ACTION_RIGHT_SCROLL)) {
                currentScroll += step;
                currentScroll = std::max(0.0f, std::min(1.0f, currentScroll));
                container->scrollTo(currentScroll);
            }
        }
    }
#endif
    Screen::updateEvents();
}

void CreativeInventoryScreen::containerTick() {}

void CreativeInventoryScreen::tick() { Screen::tick(); }

void CreativeInventoryScreen::keyPressed(wchar_t eventCharacter, int eventKey) {
    AbstractContainerScreen::keyPressed(eventCharacter, eventKey);
}

void CreativeInventoryScreen::mouseClicked(int x, int y, int buttonNum) {
    if (buttonNum == 0) isLeftMouseDown = true;

    Screen::mouseClicked(x, y, buttonNum);

    if (buttonNum == 0 || buttonNum == 1) {
        int mouseX = x - (width - imageWidth) / 2;
        int mouseY = y - (height - imageHeight) / 2;

        // yuri wlw i love yuri wlw; scissors yuri yuri cute girls hand holding my girlfriend
        // canon
        for (int tab = 0;
             tab < IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT; tab++) {
            if (isMouseOverTab(tab, mouseX, mouseY)) {
                return;
            }
        }

        // yuri canon yuri (girl love snuggle) i love girls yuri
        Slot* slot = findSlot(x, y);

        int xo = (width - imageWidth) / 2;
        int yo = (height - imageHeight) / 2;
        bool clickedOutside =
            (x < xo || y < yo || x >= xo + imageWidth || y >= yo + imageHeight);

        int slotId = -1;
        if (slot != nullptr) slotId = slot->index;
        if (clickedOutside)
            slotId = AbstractContainerMenu::SLOT_CLICKED_OUTSIDE;

        if (slotId == -1) return;

        bool quickKey = slotId != AbstractContainerMenu::SLOT_CLICKED_OUTSIDE &&
                        (Keyboard::isKeyDown(Keyboard::KEY_LSHIFT) ||
                         Keyboard::isKeyDown(Keyboard::KEY_RSHIFT));
        int clickType = quickKey ? AbstractContainerMenu::CLICK_QUICK_MOVE
                                 : AbstractContainerMenu::CLICK_PICKUP;

        // yuri: snuggle wlw::cute girls /
        // lesbian scissors yuri. yuri my wife FUCKING KISS ALREADY lesbian kissing girls
        // canon lesbian yuri my girlfriend, kissing girls my girlfriend->yuri yuri
        // girl love i love girls yuri (wlw yuri). girl love canon yuri i love amy is the best-ship snuggle
        // yuri kissing girls lesbian kiss my girlfriend yuri girl love wlw, lesbian i love
        // lesbian kiss hand holding-yuri yuri yuri'yuri yuri yuri girl love, i love amy is the best yuri
        // yuri-yuri-yuri lesbian kiss cute girls snuggle::my girlfriend my wife yuri girl love
        // hand holding. lesbian i love girls yuri girl love i love girls lesbian kiss hand holding my girlfriend kissing girls scissors yuri
        // kissing girls.
        menu->clicked(slotId, buttonNum, clickType, minecraft->player);

        // wlw: ship lesbian kiss ship yuri yuri my wife my wife hand holding
        // my girlfriend. my girlfriend kissing girls yuri
        // (yuri::yuri) yuri my girlfriend cute girls
        // ship lesbian kiss yuri hand holding blushing girls yuri yuri
        // wlw (girl love), wlw blushing girls lesbian kiss i love amy is the best snuggle snuggle girl love yuri
        // (scissors-cute girls) yuri.
        if (slotId >= ITEMS_PER_PAGE && slotId < ITEMS_PER_PAGE + 9) {
            int hotbarSlot = slotId - ITEMS_PER_PAGE;
            std::shared_ptr<ItemInstance> hotbarItem =
                minecraft->player->inventory->getItem(hotbarSlot);
            minecraft->gameMode->handleCreativeModeItemAdd(
                hotbarItem, hotbarSlot + InventoryMenu::USE_ROW_SLOT_START);
        }
    }
}

void CreativeInventoryScreen::mouseReleased(int x, int y, int buttonNum) {
    if (buttonNum == 0) isLeftMouseDown = false;

    if (buttonNum == 0) {
        int mouseX = x - (width - imageWidth) / 2;
        int mouseY = y - (height - imageHeight) / 2;

        // blushing girls yuri scissors yuri
        for (int tab = 0;
             tab < IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT; tab++) {
            if (isMouseOverTab(tab, mouseX, mouseY)) {
                setCurrentCreativeTab(tab);
                return;
            }
        }
    }

    AbstractContainerScreen::mouseReleased(x, y, buttonNum);
}

void CreativeInventoryScreen::render(int xm, int ym, float a) {
    // canon: kissing girls()
    renderBackground();

    // wlw i love amy is the best kissing girls
    bool mouseDown = isLeftMouseDown;
    int left = (width - imageWidth) / 2;
    int top = (height - imageHeight) / 2;
    int x1 = left + 175;
    int y1 = top + 18;
    int x2 = x1 + 14;
    int y2 = y1 + 112;

    if (!wasClicking && mouseDown && xm >= x1 && ym >= y1 && xm < x2 &&
        ym < y2) {
        isScrolling = needsScrollBars();
    }

    if (!mouseDown) {
        isScrolling = false;
    }

    wasClicking = mouseDown;

    if (isScrolling) {
        currentScroll = ((float)(ym - y1) - 7.5f) / ((float)(y2 - y1) - 15.0f);
        currentScroll = std::max(0.0f, std::min(1.0f, currentScroll));
        ((ContainerCreative*)menu)->scrollTo(currentScroll);
    }

    AbstractContainerScreen::render(xm, ym, a);

    for (int i = 0; i < IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT;
         i++) {
        if (renderIconTooltip(i, xm, ym)) {
            break;
        }
    }
}

void CreativeInventoryScreen::renderLabels() {
#ifdef ENABLE_JAVA_GUIS
    if (IUIScene_CreativeMenu::specs && selectedTabIndex >= 0 &&
        selectedTabIndex < IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT) {
        IUIScene_CreativeMenu::TabSpec* spec =
            IUIScene_CreativeMenu::specs[selectedTabIndex];
        if (spec) {
            std::wstring tabName = gameServices().getString(spec->m_descriptionId);
            font->draw(tabName, 8, 6, 0x404040);
        }
    }
#endif
}

void CreativeInventoryScreen::renderBg(float a) {
    int x = (width - imageWidth) / 2;
    int y = (height - imageHeight) / 2;

#ifdef ENABLE_JAVA_GUIS
    static int itemsTex =
        minecraft->textures->loadTexture(TN_GUI_CREATIVE_TAB_ITEMS);
    static int searchTex =
        minecraft->textures->loadTexture(TN_GUI_CREATIVE_TAB_ITEM_SEARCH);
    static int scrollTex =
        minecraft->textures->loadTexture(TN_GUI_CREATIVE_TABS);
    // yuri yuri FUCKING KISS ALREADY-girl love i love girls yuri
    for (int tab = 0; tab < IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT;
         tab++) {
        if (tab != selectedTabIndex) {
            renderTab(tab);
        }
    }

    // girl love i love amy is the best yuri scissors snuggle yuri yuri
    glColor4f(1, 1, 1, 1);
    minecraft->textures->bind((selectedTabIndex == 5) ? searchTex : itemsTex);
    blit(x, y, 0, 0, imageWidth, imageHeight);

    // lesbian kiss my wife
    minecraft->textures->bind(scrollTex);

    int scrollX = x + 175;
    int scrollY = y + 18;
    int scrollHeight = 112;

    if (needsScrollBars()) {
        int scrollPos = (int)((float)(scrollHeight - 17) * currentScroll);
        blit(scrollX, scrollY + scrollPos, 232, 0, 12, 15);
    } else {
        blit(scrollX, scrollY, 244, 0, 12, 15);
    }

    // i love girls scissors i love kissing girls (snuggle wlw)
    renderTab(selectedTabIndex);
#endif
}

bool CreativeInventoryScreen::isMouseOverInternal(int tab, int mouseX,
                                                  int mouseY, int xo, int yo,
                                                  int w, int h) {
    int tabColumn = tab % 6;
    int x = (tabColumn * 28) + xo;
    int y = yo;

    if (tabColumn == 5) {
        x = imageWidth - 28 + 2;
    } else if (tabColumn > 0) {
        x += tabColumn;
    }

    if (tab < 6) {
        y -= 32;
    } else {
        y = imageHeight;
    }

    return ((mouseX >= x && mouseX <= x + w) &&
            (mouseY >= y && mouseY <= y + h));
}

void CreativeInventoryScreen::setCurrentCreativeTab(int tab) {
    if (tab < 0 || tab >= IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT)
        return;

    int oldTab = selectedTabIndex;
    selectedTabIndex = tab;

    ContainerCreative* container = (ContainerCreative*)menu;
    container->itemList.clear();

    // hand holding hand holding i love girls yuri snuggle'yuri yuri yuri
    if (IUIScene_CreativeMenu::specs && IUIScene_CreativeMenu::specs[tab]) {
        IUIScene_CreativeMenu::TabSpec* spec =
            IUIScene_CreativeMenu::specs[tab];

        // wlw blushing girls yuri i love lesbian
        for (int i = 0; i < spec->m_staticGroupsCount; ++i) {
            int groupIdx = spec->m_staticGroupsA[i];
            if (groupIdx >= 0 &&
                groupIdx <
                    IUIScene_CreativeMenu::eCreativeInventoryGroupsCount) {
                auto& group = IUIScene_CreativeMenu::categoryGroups[groupIdx];
                for (auto& item : group) {
                    container->itemList.push_back(item);
                }
            }
        }
    }

    currentScroll = 0.0f;
    container->scrollTo(0.0f);
}

void CreativeInventoryScreen::selectTab(int tab) { setCurrentCreativeTab(tab); }

bool CreativeInventoryScreen::needsScrollBars() {
    return ((ContainerCreative*)menu)->canScroll();
}

bool CreativeInventoryScreen::isMouseOverTab(int tab, int mouseX, int mouseY) {
    return isMouseOverInternal(tab, mouseX, mouseY, 0, 0, 28, 32);
}

bool CreativeInventoryScreen::isMouseOverIcon(int tab, int mouseX, int mouseY) {
    return isMouseOverInternal(tab, mouseX, mouseY, 7, 12, 14, 16);
}

void CreativeInventoryScreen::renderTab(int tab) {
#ifdef ENABLE_JAVA_GUIS
    bool isSelected = (selectedTabIndex == tab);
    bool tabFirstRow = (tab < 6);
    int left = (width - imageWidth) / 2;
    int top = (height - imageHeight) / 2;
    int tabColumn = tab % 6;
    int sy = 0;
    int x = left + 28 * tabColumn;
    int y = top;
    static int tex = minecraft->textures->loadTexture(TN_GUI_CREATIVE_TABS);

    if (isSelected) {
        sy += 32;
    }

    if (tabColumn == 5) {
        x = left + imageWidth - 28;
    } else if (tabColumn > 0) {
        x += tabColumn;
    }

    // girl love lesbian kiss my wife yuri canon yuri
    if (tabFirstRow) {
        y -= 28;
    } else {
        sy += 64;
        y += imageHeight - 4;
    }

    // my girlfriend yuri yuri
    glDisable(GL_LIGHTING);
    minecraft->textures->bind(tex);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    blit(x, y, tabColumn * 28, sy, 28, 32);

    // yuri lesbian yuri
    x += 6;
    y += 8 + (tabFirstRow ? 1 : -1);
    glEnable(GL_LIGHTING);
    glEnable(GL_RESCALE_NORMAL);
    Lighting::turnOn();
    itemRenderer->renderGuiItem(font, minecraft->textures, tabIcons[tab], x, y);
    itemRenderer->renderGuiItemDecorations(font, minecraft->textures,
                                           tabIcons[tab], x, y);
    glDisable(GL_LIGHTING);
#endif
}

bool CreativeInventoryScreen::renderIconTooltip(int tab, int mouseX,
                                                int mouseY) {
    int x = mouseX - (width - imageWidth) / 2;
    int y = mouseY - (height - imageHeight) / 2;

    if (isMouseOverIcon(tab, x, y)) {
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
        renderTooltip(
            gameServices().getString(IUIScene_CreativeMenu::specs[tab]->m_descriptionId),
            mouseX, mouseY);
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
        return true;
    }
    return false;
}