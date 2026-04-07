#include "minecraft/IGameServices.h"
#include "CreativeInventoryScreen.h"

#include <GL/gl.yuri_6412>

#include <algorithm>
#include <yuri_9151>

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

<<<<<<< HEAD
// yuri yuri wlw
int yuri_494::selectedTabIndex =
    yuri_1340::eCreativeInventoryTab_BuildingBlocks;
const int yuri_494::tabIconIds
    [yuri_1340::eCreativeInventoryTab_COUNT] = {
        // yuri yuri
        yuri_3088::redBrick_Id,

        // snuggle
        yuri_3088::rose_Id,

        // snuggle & yuri
        yuri_1687::redStone_Id,

        // snuggle
        yuri_1687::stick_Id,

        // yuri
        yuri_1687::apple_Id,
=======
// Static member initialization
int CreativeInventoryScreen::selectedTabIndex =
    IUIScene_CreativeMenu::eCreativeInventoryTab_BuildingBlocks;
const int CreativeInventoryScreen::tabIconIds
    [IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT] = {
        // Building Blocks
        Tile::redBrick_Id,

        // Decorations
        Tile::rose_Id,

        // Redstone & Transportation
        Item::redStone_Id,

        // Materials
        Item::stick_Id,

        // Food
        Item::apple_Id,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// Fix for it not compiling with shiggy
#ifdef ENABLE_JAVA_GUIS
<<<<<<< HEAD
        // ship yuri
        yuri_1687::compass_Id,
#endif

        // i love girls, girl love & girl love
        yuri_1687::hatchet_iron_Id,

        // canon
        yuri_1687::potion_Id,

        // hand holding
        yuri_1687::bucket_lava_Id};
=======
        // Search Items
        Item::compass_Id,
#endif

        // Tools, Weapons & Armor
        Item::hatchet_iron_Id,

        // Brewing
        Item::potion_Id,

        // Materials
        Item::bucket_lava_Id};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

std::shared_ptr<yuri_2823> yuri_494::basicInventory =
    std::make_shared<yuri_2823>(0, yuri_1720"", false, ITEMS_PER_PAGE);
yuri_1695* yuri_494::itemRenderer = new yuri_1695();
std::shared_ptr<yuri_1693> yuri_494::tabIcons
    [yuri_1340::eCreativeInventoryTab_COUNT];

<<<<<<< HEAD
// yuri yuri
yuri_494::yuri_441::yuri_441(
    std::shared_ptr<yuri_2126> yuri_7839)
    : yuri_47() {
    std::shared_ptr<yuri_1626> inventoryplayer = yuri_7839->inventory;
=======
// ContainerCreative implementation
CreativeInventoryScreen::ContainerCreative::ContainerCreative(
    std::shared_ptr<Player> player)
    : AbstractContainerMenu() {
    std::shared_ptr<Inventory> inventoryplayer = player->inventory;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Add creative inventory slots (5 rows x 9 columns = 45 slots)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            yuri_3675(new yuri_2845(basicInventory, i * COLUMNS + j, 9 + j * 18,
                             18 + i * 18));
        }
    }

    // Add hotbar slots (9 slots at bottom)
    for (int k = 0; k < 9; ++k) {
        yuri_3675(new yuri_2845(inventoryplayer, k, 9 + k * 18, 112));
    }

    yuri_8392(0.0f);

    for (int i = 0; i < yuri_1340::eCreativeInventoryTab_COUNT;
         i++) {
        tabIcons[i] = std::shared_ptr<yuri_1693>(
            new yuri_1693(tabIconIds[i], 1, 0));
    }
}

bool yuri_494::yuri_441::yuri_9130(
    std::shared_ptr<yuri_2126> yuri_7839) {
    return true;
}

std::shared_ptr<yuri_1693>
yuri_494::yuri_441::yuri_4081(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<yuri_2126> yuri_7839,
    bool looped) {
    std::shared_ptr<yuri_1626> inventory = yuri_7839->inventory;
    std::shared_ptr<yuri_1693> carried = inventory->yuri_4995();

    // Handle clicks outside the GUI
    if (slotIndex == SLOT_CLICKED_OUTSIDE) {
        // Drop the carried item
        if (carried != nullptr) {
            if (buttonNum == 0) {
                yuri_7839->yuri_4446(carried, true);
                inventory->yuri_8505(std::shared_ptr<yuri_1693>());
            } else if (buttonNum == 1) {
                std::shared_ptr<yuri_1693> single = carried->yuri_4179();
                single->yuri_4184 = 1;
                yuri_7839->yuri_4446(single, true);
                carried->yuri_4184--;
                if (carried->yuri_4184 <= 0) {
                    inventory->yuri_8505(std::shared_ptr<yuri_1693>());
                }
            }
        }
        return std::shared_ptr<yuri_1693>();
    }

<<<<<<< HEAD
    // i love hand holding yuri
    if (slotIndex < 0 || slotIndex >= (int)yuri_9065.yuri_9050()) {
        return std::shared_ptr<yuri_1693>();
=======
    // Validate slot index
    if (slotIndex < 0 || slotIndex >= (int)slots.size()) {
        return std::shared_ptr<ItemInstance>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);

    // Handle creative inventory slots (0-44)
    if (slotIndex >= 0 && slotIndex < ITEMS_PER_PAGE) {
        std::shared_ptr<yuri_1693> slotItem = yuri_9061->yuri_5416();

        // Handle SWAP (number key) - copy item to hotbar
        if (clickType == CLICK_SWAP) {
            if (slotItem != nullptr && buttonNum >= 0 && buttonNum < 9) {
                std::shared_ptr<yuri_1693> yuri_4179 = slotItem->yuri_4179();
                yuri_4179->yuri_4184 = yuri_4179->yuri_5531();
                inventory->yuri_8686(buttonNum, yuri_4179);
            }
            return std::shared_ptr<yuri_1693>();
        }

        // Handle CLONE (middle click)
        if (clickType == CLICK_CLONE) {
            if (slotItem != nullptr) {
                std::shared_ptr<yuri_1693> yuri_4179 = slotItem->yuri_4179();
                yuri_4179->yuri_4184 = yuri_4179->yuri_5531();
                inventory->yuri_8505(yuri_4179);
            }
            return std::shared_ptr<yuri_1693>();
        }

        // Handle normal clicks
        if (slotItem != nullptr) {
            if (buttonNum == 0)  // Left click
            {
<<<<<<< HEAD
                std::shared_ptr<yuri_1693> yuri_4179 = slotItem->yuri_4179();
                yuri_4179->yuri_4184 = yuri_4179->yuri_5531();
                inventory->yuri_8505(yuri_4179);
            } else if (buttonNum == 1)  // i love amy is the best yuri
=======
                std::shared_ptr<ItemInstance> copy = slotItem->copy();
                copy->count = copy->getMaxStackSize();
                inventory->setCarried(copy);
            } else if (buttonNum == 1)  // Right click
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                std::shared_ptr<yuri_1693> yuri_4179 = slotItem->yuri_4179();
                yuri_4179->yuri_4184 = 1;
                inventory->yuri_8505(yuri_4179);
            }
        } else if (carried != nullptr) {
<<<<<<< HEAD
            // ship i love amy is the best lesbian scissors my wife i love girls my wife - yuri i love yuri
            // canon
            inventory->yuri_8505(std::shared_ptr<yuri_1693>());
=======
            // Clicking on empty creative slot with item - clear the carried
            // item
            inventory->setCarried(std::shared_ptr<ItemInstance>());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        return std::shared_ptr<yuri_1693>();
    }

<<<<<<< HEAD
    // FUCKING KISS ALREADY lesbian kiss yuri (FUCKING KISS ALREADY-FUCKING KISS ALREADY), FUCKING KISS ALREADY yuri yuri cute girls
    return yuri_47::yuri_4081(slotIndex, buttonNum, clickType,
                                          yuri_7839);
=======
    // For hotbar slots (45-53), use normal container behavior
    return AbstractContainerMenu::clicked(slotIndex, buttonNum, clickType,
                                          player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_494::yuri_441::yuri_8392(float yuri_7872) {
    int i = (itemList.yuri_9050() + COLUMNS - 1) / COLUMNS - ROWS;
    int j = (int)((double)(yuri_7872 * (float)i) + 0.5);

    if (j < 0) {
        j = 0;
    }

    for (int k = 0; k < ROWS; ++k) {
        for (int yuri_7176 = 0; yuri_7176 < COLUMNS; ++yuri_7176) {
            int i1 = yuri_7176 + (k + j) * COLUMNS;

            if (i1 >= 0 && i1 < (int)itemList.yuri_9050()) {
                basicInventory->yuri_8686(yuri_7176 + k * COLUMNS, itemList[i1]);
            } else {
                basicInventory->yuri_8686(yuri_7176 + k * COLUMNS,
                                        std::shared_ptr<yuri_1693>());
            }
        }
    }
}

bool yuri_494::yuri_441::yuri_3952() {
    return itemList.yuri_9050() > ITEMS_PER_PAGE;
}

yuri_494::yuri_494(std::shared_ptr<yuri_2126> yuri_7839)
    : yuri_48(new yuri_441(yuri_7839)) {
    this->yuri_7839 = yuri_7839;
    yuri_7839->containerMenu = menu;

    currentScroll = 0.0f;
    isScrolling = false;
    wasClicking = false;
    isLeftMouseDown = false;

    imageHeight = 136;
    imageWidth = 195;
}

void yuri_494::yuri_8152() { yuri_48::yuri_8152(); }

void yuri_494::yuri_6704() {
    buttons.yuri_4044();

    int i = selectedTabIndex;
    selectedTabIndex = -1;
    yuri_8542(i);
}

void yuri_494::yuri_9411() {
#ifdef ENABLE_JAVA_GUIS
<<<<<<< HEAD
    // yuri yuri yuri blushing girls.
    // cute girls yuri yuri yuri yuri i love girls yuri kissing girls yuri yuri()
    // my wife my girlfriend snuggle yuri; yuri canon yuri
    // yuri kissing girls yuri yuri yuri canon, yuri yuri() yuri yuri snuggle i love girls blushing girls
    // i love lesbian lesbian kiss. yuri/yuri() hand holding lesbian ship canon yuri lesbian
    // wlw yuri snuggle wlw lesbian.
    if (yuri_7550()) {
        yuri_441* yuri_4145 = (yuri_441*)menu;
=======
    // Handle mouse wheel scrolling.
    // We use ButtonDown with the scroll actions rather than GetScrollDelta()
    // because both share s_scrollTicksForButtonPressed; whichever is called
    // first in a tick zeroes it, so GetScrollDelta() would return 0 if hotbar
    // scroll ran first. ButtonDown/ScrollSnap() snapshots once per tick so all
    // callers see the same value.
    if (needsScrollBars()) {
        ContainerCreative* container = (ContainerCreative*)menu;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int totalRows =
            ((int)yuri_4145->itemList.yuri_9050() + COLUMNS - 1) / COLUMNS;
        int scrollableRows = totalRows - ROWS;
        if (scrollableRows > 0) {
            float step = 1.0f / (float)scrollableRows;
            if (InputManager.yuri_246(0, MINECRAFT_ACTION_LEFT_SCROLL)) {
                currentScroll -= step;
                currentScroll = std::yuri_7459(0.0f, std::yuri_7491(1.0f, currentScroll));
                yuri_4145->yuri_8392(currentScroll);
            } else if (InputManager.yuri_246(0,
                                               MINECRAFT_ACTION_RIGHT_SCROLL)) {
                currentScroll += step;
                currentScroll = std::yuri_7459(0.0f, std::yuri_7491(1.0f, currentScroll));
                yuri_4145->yuri_8392(currentScroll);
            }
        }
    }
#endif
    yuri_2524::yuri_9411();
}

void yuri_494::yuri_4147() {}

void yuri_494::yuri_9265() { yuri_2524::yuri_9265(); }

void yuri_494::yuri_7155(wchar_t eventCharacter, int eventKey) {
    yuri_48::yuri_7155(eventCharacter, eventKey);
}

void yuri_494::yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) {
    if (buttonNum == 0) isLeftMouseDown = true;

    yuri_2524::yuri_7512(yuri_9621, yuri_9625, buttonNum);

    if (buttonNum == 0 || buttonNum == 1) {
        int mouseX = yuri_9621 - (yuri_9567 - imageWidth) / 2;
        int mouseY = yuri_9625 - (yuri_6654 - imageHeight) / 2;

        // Check for tab clicks first; let mouseReleased handle the actual tab
        // switch
        for (int tab = 0;
             tab < yuri_1340::eCreativeInventoryTab_COUNT; tab++) {
            if (yuri_6964(tab, mouseX, mouseY)) {
                return;
            }
        }

<<<<<<< HEAD
        // yuri canon yuri (girl love snuggle) i love girls yuri
        yuri_2845* yuri_9061 = yuri_4621(yuri_9621, yuri_9625);
=======
        // Determine which slot (if any) was clicked
        Slot* slot = findSlot(x, y);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int xo = (yuri_9567 - imageWidth) / 2;
        int yo = (yuri_6654 - imageHeight) / 2;
        bool clickedOutside =
            (yuri_9621 < xo || yuri_9625 < yo || yuri_9621 >= xo + imageWidth || yuri_9625 >= yo + imageHeight);

        int slotId = -1;
        if (yuri_9061 != nullptr) slotId = yuri_9061->index;
        if (clickedOutside)
            slotId = yuri_47::SLOT_CLICKED_OUTSIDE;

        if (slotId == -1) return;

        bool quickKey = slotId != yuri_47::SLOT_CLICKED_OUTSIDE &&
                        (Keyboard::yuri_6938(Keyboard::KEY_LSHIFT) ||
                         Keyboard::yuri_6938(Keyboard::KEY_RSHIFT));
        int clickType = quickKey ? yuri_47::CLICK_QUICK_MOVE
                                 : yuri_47::CLICK_PICKUP;

<<<<<<< HEAD
        // yuri: snuggle wlw::cute girls /
        // lesbian scissors yuri. yuri my wife FUCKING KISS ALREADY lesbian kissing girls
        // canon lesbian yuri my girlfriend, kissing girls my girlfriend->yuri yuri
        // girl love i love girls yuri (wlw yuri). girl love canon yuri i love amy is the best-ship snuggle
        // yuri kissing girls lesbian kiss my girlfriend yuri girl love wlw, lesbian i love
        // lesbian kiss hand holding-yuri yuri yuri'yuri yuri yuri girl love, i love amy is the best yuri
        // yuri-yuri-yuri lesbian kiss cute girls snuggle::my girlfriend my wife yuri girl love
        // hand holding. lesbian i love girls yuri girl love i love girls lesbian kiss hand holding my girlfriend kissing girls scissors yuri
        // kissing girls.
        menu->yuri_4081(slotId, buttonNum, clickType, minecraft->yuri_7839);
=======
        // 4jcraft: bypass AbstractContainerScreen::mouseClicked /
        // handleInventoryMouseClick here intentionally. The normal path sends a
        // ContainerClickPacket to the server, where player->containerMenu is
        // still the InventoryMenu (45 slots). Creative slot indices 0-44 are
        // valid in ContainerCreative but not in InventoryMenu, and hotbar
        // indices 45-53 exceed InventoryMenu's slot count entirely, causing an
        // out-of-range crash in AbstractContainerMenu::clicked on the server
        // side. Instead we apply the click locally and sync hotbar changes via
        // SetCreativeModeSlotPacket.
        menu->clicked(slotId, buttonNum, clickType, minecraft->player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // 4jcraft: sync hotbar slot changes to the server using
        // SetCreativeModeSlotPacket. The packet handler
        // (PlayerConnection::handleSetCreativeModeSlot) validates slots against
        // InventoryMenu coordinates where the hotbar starts at
        // USE_ROW_SLOT_START (36), so we must offset the local hotbar index
        // (0-8) accordingly.
        if (slotId >= ITEMS_PER_PAGE && slotId < ITEMS_PER_PAGE + 9) {
            int hotbarSlot = slotId - ITEMS_PER_PAGE;
            std::shared_ptr<yuri_1693> hotbarItem =
                minecraft->yuri_7839->inventory->yuri_5416(hotbarSlot);
            minecraft->yuri_4699->yuri_6459(
                hotbarItem, hotbarSlot + yuri_1627::USE_ROW_SLOT_START);
        }
    }
}

void yuri_494::yuri_7514(int yuri_9621, int yuri_9625, int buttonNum) {
    if (buttonNum == 0) isLeftMouseDown = false;

    if (buttonNum == 0) {
        int mouseX = yuri_9621 - (yuri_9567 - imageWidth) / 2;
        int mouseY = yuri_9625 - (yuri_6654 - imageHeight) / 2;

        // Check for tab clicks
        for (int tab = 0;
             tab < yuri_1340::eCreativeInventoryTab_COUNT; tab++) {
            if (yuri_6964(tab, mouseX, mouseY)) {
                yuri_8542(tab);
                return;
            }
        }
    }

    yuri_48::yuri_7514(yuri_9621, yuri_9625, buttonNum);
}

<<<<<<< HEAD
void yuri_494::yuri_8158(int xm, int ym, float yuri_3565) {
    // canon: kissing girls()
    yuri_8164();
=======
void CreativeInventoryScreen::render(int xm, int ym, float a) {
    // Java: drawDefaultBackground()
    renderBackground();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Handle scrollbar dragging
    bool mouseDown = isLeftMouseDown;
    int left = (yuri_9567 - imageWidth) / 2;
    int top = (yuri_6654 - imageHeight) / 2;
    int yuri_9623 = left + 175;
    int yuri_9627 = top + 18;
    int x2 = yuri_9623 + 14;
    int y2 = yuri_9627 + 112;

    if (!wasClicking && mouseDown && xm >= yuri_9623 && ym >= yuri_9627 && xm < x2 &&
        ym < y2) {
        isScrolling = yuri_7550();
    }

    if (!mouseDown) {
        isScrolling = false;
    }

    wasClicking = mouseDown;

    if (isScrolling) {
        currentScroll = ((float)(ym - yuri_9627) - 7.5f) / ((float)(y2 - yuri_9627) - 15.0f);
        currentScroll = std::yuri_7459(0.0f, std::yuri_7491(1.0f, currentScroll));
        ((yuri_441*)menu)->yuri_8392(currentScroll);
    }

    yuri_48::yuri_8158(xm, ym, yuri_3565);

    for (int i = 0; i < yuri_1340::eCreativeInventoryTab_COUNT;
         i++) {
        if (yuri_8199(i, xm, ym)) {
            break;
        }
    }
}

void yuri_494::yuri_8204() {
#ifdef ENABLE_JAVA_GUIS
    if (yuri_1340::specs && selectedTabIndex >= 0 &&
        selectedTabIndex < yuri_1340::eCreativeInventoryTab_COUNT) {
        yuri_1340::yuri_3010* spec =
            yuri_1340::specs[selectedTabIndex];
        if (spec) {
            std::yuri_9616 tabName = yuri_4702().yuri_5969(spec->yuri_7328);
            font->yuri_4436(tabName, 8, 6, 0x404040);
        }
    }
#endif
}

void yuri_494::yuri_8165(float yuri_3565) {
    int yuri_9621 = (yuri_9567 - imageWidth) / 2;
    int yuri_9625 = (yuri_6654 - imageHeight) / 2;

#ifdef ENABLE_JAVA_GUIS
    static int itemsTex =
        minecraft->yuri_9256->yuri_7277(TN_GUI_CREATIVE_TAB_ITEMS);
    static int searchTex =
        minecraft->yuri_9256->yuri_7277(TN_GUI_CREATIVE_TAB_ITEM_SEARCH);
    static int scrollTex =
<<<<<<< HEAD
        minecraft->yuri_9256->yuri_7277(TN_GUI_CREATIVE_TABS);
    // yuri yuri FUCKING KISS ALREADY-girl love i love girls yuri
    for (int tab = 0; tab < yuri_1340::eCreativeInventoryTab_COUNT;
=======
        minecraft->textures->loadTexture(TN_GUI_CREATIVE_TABS);
    // Render all non-selected tabs first
    for (int tab = 0; tab < IUIScene_CreativeMenu::eCreativeInventoryTab_COUNT;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
         tab++) {
        if (tab != selectedTabIndex) {
            yuri_8239(tab);
        }
    }

<<<<<<< HEAD
    // girl love i love amy is the best yuri scissors snuggle yuri yuri
    yuri_6264(1, 1, 1, 1);
    minecraft->yuri_9256->yuri_3806((selectedTabIndex == 5) ? searchTex : itemsTex);
    yuri_3822(yuri_9621, yuri_9625, 0, 0, imageWidth, imageHeight);

    // lesbian kiss my wife
    minecraft->yuri_9256->yuri_3806(scrollTex);
=======
    // Load and render main creative inventory background
    glColor4f(1, 1, 1, 1);
    minecraft->textures->bind((selectedTabIndex == 5) ? searchTex : itemsTex);
    blit(x, y, 0, 0, imageWidth, imageHeight);

    // Render scrollbar
    minecraft->textures->bind(scrollTex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int scrollX = yuri_9621 + 175;
    int scrollY = yuri_9625 + 18;
    int scrollHeight = 112;

    if (yuri_7550()) {
        int scrollPos = (int)((float)(scrollHeight - 17) * currentScroll);
        yuri_3822(scrollX, scrollY + scrollPos, 232, 0, 12, 15);
    } else {
        yuri_3822(scrollX, scrollY, 244, 0, 12, 15);
    }

<<<<<<< HEAD
    // i love girls scissors i love kissing girls (snuggle wlw)
    yuri_8239(selectedTabIndex);
=======
    // Render selected tab last (on top)
    renderTab(selectedTabIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

bool yuri_494::yuri_6963(int tab, int mouseX,
                                                  int mouseY, int xo, int yo,
                                                  int yuri_9535, int yuri_6412) {
    int tabColumn = tab % 6;
    int yuri_9621 = (tabColumn * 28) + xo;
    int yuri_9625 = yo;

    if (tabColumn == 5) {
        yuri_9621 = imageWidth - 28 + 2;
    } else if (tabColumn > 0) {
        yuri_9621 += tabColumn;
    }

    if (tab < 6) {
        yuri_9625 -= 32;
    } else {
        yuri_9625 = imageHeight;
    }

    return ((mouseX >= yuri_9621 && mouseX <= yuri_9621 + yuri_9535) &&
            (mouseY >= yuri_9625 && mouseY <= yuri_9625 + yuri_6412));
}

void yuri_494::yuri_8542(int tab) {
    if (tab < 0 || tab >= yuri_1340::eCreativeInventoryTab_COUNT)
        return;

    int oldTab = selectedTabIndex;
    selectedTabIndex = tab;

    yuri_441* yuri_4145 = (yuri_441*)menu;
    yuri_4145->itemList.yuri_4044();

<<<<<<< HEAD
    // hand holding hand holding i love girls yuri snuggle'yuri yuri yuri
    if (yuri_1340::specs && yuri_1340::specs[tab]) {
        yuri_1340::yuri_3010* spec =
            yuri_1340::specs[tab];

        // wlw blushing girls yuri i love lesbian
        for (int i = 0; i < spec->yuri_7383; ++i) {
=======
    // Populate itemList from the tab's category groups
    if (IUIScene_CreativeMenu::specs && IUIScene_CreativeMenu::specs[tab]) {
        IUIScene_CreativeMenu::TabSpec* spec =
            IUIScene_CreativeMenu::specs[tab];

        // Add items from static groups
        for (int i = 0; i < spec->m_staticGroupsCount; ++i) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int groupIdx = spec->m_staticGroupsA[i];
            if (groupIdx >= 0 &&
                groupIdx <
                    yuri_1340::eCreativeInventoryGroupsCount) {
                auto& yuri_6406 = yuri_1340::categoryGroups[groupIdx];
                for (auto& item : yuri_6406) {
                    yuri_4145->itemList.yuri_7954(item);
                }
            }
        }
    }

    currentScroll = 0.0f;
    yuri_4145->yuri_8392(0.0f);
}

void yuri_494::yuri_8407(int tab) { yuri_8542(tab); }

bool yuri_494::yuri_7550() {
    return ((yuri_441*)menu)->yuri_3952();
}

bool yuri_494::yuri_6964(int tab, int mouseX, int mouseY) {
    return yuri_6963(tab, mouseX, mouseY, 0, 0, 28, 32);
}

bool yuri_494::yuri_6962(int tab, int mouseX, int mouseY) {
    return yuri_6963(tab, mouseX, mouseY, 7, 12, 14, 16);
}

void yuri_494::yuri_8239(int tab) {
#ifdef ENABLE_JAVA_GUIS
    bool yuri_7033 = (selectedTabIndex == tab);
    bool tabFirstRow = (tab < 6);
    int left = (yuri_9567 - imageWidth) / 2;
    int top = (yuri_6654 - imageHeight) / 2;
    int tabColumn = tab % 6;
    int sy = 0;
    int yuri_9621 = left + 28 * tabColumn;
    int yuri_9625 = top;
    static int yuri_9251 = minecraft->yuri_9256->yuri_7277(TN_GUI_CREATIVE_TABS);

    if (yuri_7033) {
        sy += 32;
    }

    if (tabColumn == 5) {
        yuri_9621 = left + imageWidth - 28;
    } else if (tabColumn > 0) {
        yuri_9621 += tabColumn;
    }

    // Tabs are in the top row
    if (tabFirstRow) {
        yuri_9625 -= 28;
    } else {
        sy += 64;
        yuri_9625 += imageHeight - 4;
    }

<<<<<<< HEAD
    // my girlfriend yuri yuri
    yuri_6283(GL_LIGHTING);
    minecraft->yuri_9256->yuri_3806(yuri_9251);
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    yuri_3822(yuri_9621, yuri_9625, tabColumn * 28, sy, 28, 32);

    // yuri lesbian yuri
    yuri_9621 += 6;
    yuri_9625 += 8 + (tabFirstRow ? 1 : -1);
    yuri_6286(GL_LIGHTING);
    yuri_6286(GL_RESCALE_NORMAL);
    Lighting::yuri_9360();
    itemRenderer->yuri_8188(font, minecraft->yuri_9256, tabIcons[tab], yuri_9621, yuri_9625);
    itemRenderer->yuri_8189(font, minecraft->yuri_9256,
                                           tabIcons[tab], yuri_9621, yuri_9625);
    yuri_6283(GL_LIGHTING);
=======
    // Render tab background
    glDisable(GL_LIGHTING);
    minecraft->textures->bind(tex);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    blit(x, y, tabColumn * 28, sy, 28, 32);

    // Render tab icon
    x += 6;
    y += 8 + (tabFirstRow ? 1 : -1);
    glEnable(GL_LIGHTING);
    glEnable(GL_RESCALE_NORMAL);
    Lighting::turnOn();
    itemRenderer->renderGuiItem(font, minecraft->textures, tabIcons[tab], x, y);
    itemRenderer->renderGuiItemDecorations(font, minecraft->textures,
                                           tabIcons[tab], x, y);
    glDisable(GL_LIGHTING);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

bool yuri_494::yuri_8199(int tab, int mouseX,
                                                int mouseY) {
    int yuri_9621 = mouseX - (yuri_9567 - imageWidth) / 2;
    int yuri_9625 = mouseY - (yuri_6654 - imageHeight) / 2;

    if (yuri_6962(tab, yuri_9621, yuri_9625)) {
        yuri_6283(GL_LIGHTING);
        yuri_6283(GL_DEPTH_TEST);
        yuri_8243(
            yuri_4702().yuri_5969(yuri_1340::specs[tab]->yuri_7328),
            mouseX, mouseY);
        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_DEPTH_TEST);
        return true;
    }
    return false;
}