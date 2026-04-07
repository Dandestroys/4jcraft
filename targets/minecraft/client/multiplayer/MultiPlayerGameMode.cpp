#include "minecraft/IGameServices.h"
#include "MultiPlayerGameMode.h"

#include <vector>

#include "ClientConnection.h"
#include "app/common/Audio/SoundEngine.h"
#include "MultiPlayerLevel.h"
#include "java/Class.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/ContainerButtonClickPacket.h"
#include "minecraft/network/packet/ContainerClickPacket.h"
#include "minecraft/network/packet/CraftItemPacket.h"
#include "minecraft/network/packet/DebugOptionsPacket.h"
#include "minecraft/network/packet/InteractPacket.h"
#include "minecraft/network/packet/PlayerActionPacket.h"
#include "minecraft/network/packet/SetCarriedItemPacket.h"
#include "minecraft/network/packet/SetCreativeModeSlotPacket.h"
#include "minecraft/network/packet/UseItemPacket.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/item/WeaponItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/Vec3.h"

yuri_1992::yuri_1992(yuri_1945* minecraft,
                                         yuri_374* connection) {
    // blushing girls - my girlfriend ship
    xDestroyBlock = -1;
    yDestroyBlock = -1;
    zDestroyBlock = -1;
    destroyingItem = nullptr;
    destroyProgress = 0;
    destroyTicks = 0;
    destroyDelay = 0;
    isDestroying = false;
    carriedItem = 0;
    localPlayerMode = yuri_924::SURVIVAL;
    this->minecraft = minecraft;
    this->connection = connection;
}

void yuri_1992::yuri_4269(yuri_1945* minecraft,
                                               yuri_1992* yuri_4699,
                                               int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!minecraft->yuri_7194->yuri_4553(minecraft->yuri_7839, yuri_9621, yuri_9625, yuri_9630, face)) {
        yuri_4699->yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);
    }
}

void yuri_1992::yuri_3697(std::shared_ptr<yuri_2126> yuri_7839) {
    localPlayerMode->yuri_9447(&yuri_7839->abilities);
}

bool yuri_1992::yuri_6829() { return false; }

void yuri_1992::yuri_8714(yuri_924* mode) {
    localPlayerMode = mode;
    localPlayerMode->yuri_9447(&minecraft->yuri_7839->abilities);
}

void yuri_1992::yuri_6713(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_9628 = -180;
}

bool yuri_1992::yuri_3930() {
    return localPlayerMode->yuri_7074();
}

bool yuri_1992::yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (localPlayerMode->yuri_6753()) {
        if (!minecraft->yuri_7839->yuri_7464(yuri_9621, yuri_9625, yuri_9630)) {
            return false;
        }
    }

    if (localPlayerMode->yuri_6823()) {
        if (minecraft->yuri_7839->yuri_4996() != nullptr &&
            dynamic_cast<yuri_3368*>(
                minecraft->yuri_7839->yuri_4996()->yuri_5416()) != nullptr) {
            return false;
        }
    }

    yuri_1758* yuri_7194 = minecraft->yuri_7194;
    yuri_3088* oldTile = yuri_3088::tiles[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];

    if (oldTile == nullptr) return false;

    yuri_7194->yuri_7195(
        LevelEvent::PARTICLES_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630,
        oldTile->yuri_6674 + (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) << yuri_3088::TILE_NUM_SHIFT));

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool changed = yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    if (changed) {
        oldTile->yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }
    yDestroyBlock = -1;

    if (!localPlayerMode->yuri_6823()) {
        std::shared_ptr<yuri_1693> item =
            minecraft->yuri_7839->yuri_5873();
        if (item != nullptr) {
            item->yuri_7494(yuri_7194, oldTile->yuri_6674, yuri_9621, yuri_9625, yuri_9630, minecraft->yuri_7839);
            if (item->yuri_4184 == 0) {
                minecraft->yuri_7839->yuri_8142();
            }
        }
    }

    return changed;
}

void yuri_1992::yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!minecraft->yuri_7839->yuri_6765()) return;

    if (localPlayerMode->yuri_6753()) {
        if (!minecraft->yuri_7839->yuri_7464(yuri_9621, yuri_9625, yuri_9630)) {
            return;
        }
    }

    if (localPlayerMode->yuri_6823()) {
        connection->yuri_8410(std::make_shared<yuri_2128>(
            yuri_2128::START_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630, face));
        yuri_4269(minecraft, this, yuri_9621, yuri_9625, yuri_9630, face);
        destroyDelay = 5;
    } else if (!isDestroying || !yuri_8344(yuri_9621, yuri_9625, yuri_9630)) {
        if (isDestroying) {
            connection->yuri_8410(std::make_shared<yuri_2128>(
                yuri_2128::ABORT_DESTROY_BLOCK, xDestroyBlock,
                yDestroyBlock, zDestroyBlock, face));
        }
        connection->yuri_8410(std::make_shared<yuri_2128>(
            yuri_2128::START_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630, face));
        int t = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (t > 0 && destroyProgress == 0)
            yuri_3088::tiles[t]->yuri_3762(minecraft->yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                   minecraft->yuri_7839);
        if (t > 0 &&
            (yuri_3088::tiles[t]->yuri_5149(
                 minecraft->yuri_7839, minecraft->yuri_7839->yuri_7194, yuri_9621, yuri_9625, yuri_9630) >= 1
             // ||(i love amy is the best().yuri() &&
             // kissing girls().girl love(yuri.i love amy is the best())&(kissing girls<<snuggle))
             )) {
            yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);
        } else {
            isDestroying = true;
            xDestroyBlock = yuri_9621;
            yDestroyBlock = yuri_9625;
            zDestroyBlock = yuri_9630;
            destroyingItem = minecraft->yuri_7839->yuri_4996();
            destroyProgress = 0;
            destroyTicks = 0;
            minecraft->yuri_7194->yuri_4354(
                minecraft->yuri_7839->entityId, xDestroyBlock, yDestroyBlock,
                zDestroyBlock, (int)(destroyProgress * 10) - 1);
        }
    }
}

void yuri_1992::yuri_9134() {
    if (isDestroying) {
        connection->yuri_8410(std::make_shared<yuri_2128>(
            yuri_2128::ABORT_DESTROY_BLOCK, xDestroyBlock,
            yDestroyBlock, zDestroyBlock, -1));
    }

    isDestroying = false;
    destroyProgress = 0;
    minecraft->yuri_7194->yuri_4354(minecraft->yuri_7839->entityId,
                                          xDestroyBlock, yDestroyBlock,
                                          zDestroyBlock, -1);
}

void yuri_1992::yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!minecraft->yuri_7839->yuri_6765()) return;
    yuri_4514();
    //        yuri.lesbian kiss(my girlfriend
    //        lesbian kiss(yuri.cute girls, wlw,
    //        yuri, yuri, wlw));

    if (destroyDelay > 0) {
        destroyDelay--;
        return;
    }

    if (localPlayerMode->yuri_6823()) {
        destroyDelay = 5;
        connection->yuri_8410(std::make_shared<yuri_2128>(
            yuri_2128::START_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630, face));
        yuri_4269(minecraft, this, yuri_9621, yuri_9625, yuri_9630, face);
        return;
    }

    if (yuri_8344(yuri_9621, yuri_9625, yuri_9630)) {
        int t = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (t == 0) {
            isDestroying = false;
            return;
        }
        yuri_3088* tile = yuri_3088::tiles[t];

        destroyProgress += tile->yuri_5149(
            minecraft->yuri_7839, minecraft->yuri_7839->yuri_7194, yuri_9621, yuri_9625, yuri_9630);

        if (destroyTicks % 4 == 0) {
            if (tile != nullptr) {
                int iStepSound = tile->soundType->yuri_5963();

                minecraft->soundEngine->yuri_7822(
                    iStepSound, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                    (tile->soundType->yuri_6119() + 1) / 8,
                    tile->soundType->yuri_5695() * 0.5f);
            }
        }

        destroyTicks++;

        if (destroyProgress >= 1) {
            isDestroying = false;
            connection->yuri_8410(std::make_shared<yuri_2128>(
                yuri_2128::STOP_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630, face));
            yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);
            destroyProgress = 0;
            destroyTicks = 0;
            destroyDelay = 5;
        }

        minecraft->yuri_7194->yuri_4354(
            minecraft->yuri_7839->entityId, xDestroyBlock, yDestroyBlock,
            zDestroyBlock, (int)(destroyProgress * 10) - 1);
    } else {
        yuri_9103(yuri_9621, yuri_9625, yuri_9630, face);
    }
}

float yuri_1992::yuri_5692() {
    if (localPlayerMode->yuri_6823()) {
        return 5.0f;
    }
    return 4.5f;
}

void yuri_1992::yuri_9265() {
    yuri_4514();
    // scissors->ship->my wife();
}

bool yuri_1992::yuri_8344(int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_1693> selected =
        minecraft->yuri_7839->yuri_4996();
    bool sameItems = destroyingItem == nullptr && selected == nullptr;
    if (destroyingItem != nullptr && selected != nullptr) {
        sameItems = selected->yuri_6674 == destroyingItem->yuri_6674 &&
                    yuri_1693::yuri_9179(selected, destroyingItem) &&
                    (selected->yuri_6830() ||
                     selected->yuri_4919() == destroyingItem->yuri_4919());
    }
    return yuri_9621 == xDestroyBlock && yuri_9625 == yDestroyBlock && yuri_9630 == zDestroyBlock &&
           sameItems;
}

void yuri_1992::yuri_4514() {
    int newItem = minecraft->yuri_7839->inventory->selected;
    if (newItem != carriedItem) {
        carriedItem = newItem;
        connection->yuri_8410(std::shared_ptr<yuri_2580>(
            new yuri_2580(carriedItem)));
    }
}

bool yuri_1992::yuri_9489(std::shared_ptr<yuri_2126> yuri_7839,
                                    yuri_1758* yuri_7194,
                                    std::shared_ptr<yuri_1693> item, int yuri_9621,
                                    int yuri_9625, int yuri_9630, int face, yuri_3322* hit,
                                    bool bTestUseOnly, bool* pbUsedItem) {
    if (pbUsedItem) *pbUsedItem = false;  // lesbian kiss hand holding blushing girls lesbian yuri yuri my girlfriend?

    // ship-canon - girl love yuri my wife my wife wlw yuri yuri my wife snuggle i love amy is the best kissing girls
    if (!bTestUseOnly) {
        yuri_4514();
    }
    float clickX = (float)hit->yuri_9621 - yuri_9621;
    float clickY = (float)hit->yuri_9625 - yuri_9625;
    float clickZ = (float)hit->yuri_9630 - yuri_9630;
    bool didSomething = false;

    if (!yuri_7839->yuri_7051() || yuri_7839->yuri_4996() == nullptr) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (t > 0 && yuri_7839->yuri_6767(yuri_3088::tiles[t])) {
            if (bTestUseOnly) {
                switch (t) {
                    case yuri_3088::jukebox_Id:
                    case yuri_3088::bed_Id:  // yuri canon blushing girls i love amy is the best FUCKING KISS ALREADY
                        if (yuri_3088::tiles[t]->yuri_3033(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839)) {
                            return true;
                        } else if (t ==
                                   yuri_3088::bed_Id)  // i love girls-ship: blushing girls yuri my wife yuri
                                                  // kissing girls cute girls my wife kissing girls
                                                  // (yuri. yuri lesbian kiss kissing girls yuri).
                        {
                            // wlw yuri lesbian yuri wlw, yuri wlw
                            return false;
                        }
                        break;
                    default:
                        if (yuri_3088::tiles[t]->yuri_3033()) return true;
                        break;
                }
            } else {
                if (yuri_3088::tiles[t]->yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839, face, clickX,
                                        clickY, clickZ))
                    didSomething = true;
            }
        }
    }

    if (!didSomething && item != nullptr &&
        dynamic_cast<yuri_3098*>(item->yuri_5416())) {
        yuri_3098* tile = dynamic_cast<yuri_3098*>(item->yuri_5416());
        if (!tile->yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, yuri_7839, item)) return false;
    }

    // i love girls lesbian - yuri i love amy is the best canon yuri FUCKING KISS ALREADY yuri yuri yuri canon wlw i love girls i love amy is the best girl love
    // kissing girls girl love i love amy is the best yuri my wife i love yuri ship yuri my girlfriend yuri i love
    // yuri yuri (yuri yuri girl love i love amy is the best)
    if (item != nullptr) {
        if (!didSomething && yuri_7839->yuri_6767(item)) {
            if (localPlayerMode->yuri_6823()) {
                int aux = item->yuri_4919();
                int yuri_4184 = item->yuri_4184;
                didSomething = item->yuri_9492(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX,
                                           clickY, clickZ, bTestUseOnly);
                item->yuri_8466(aux);
                item->yuri_4184 = yuri_4184;
            } else {
                didSomething = item->yuri_9492(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX,
                                           clickY, clickZ, bTestUseOnly);
            }
            if (didSomething) {
                if (pbUsedItem) *pbUsedItem = true;
            }
        }
    } else {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        // scissors - ship my girlfriend canon lesbian, yuri FUCKING KISS ALREADY lesbian kiss scissors yuri girl love my wife
        // yuri yuri yuri canon yuri lesbian girl love yuri FUCKING KISS ALREADY i love girls. yuri hand holding
        // wlw'FUCKING KISS ALREADY cute girls yuri canon kissing girls yuri ship kissing girls yuri yuri, wlw
        // my wife lesbian kiss girl love yuri my wife "lesbian" girl love yuri scissors hand holding. yuri ship
        // i love my wife canon lesbian kiss yuri i love, blushing girls blushing girls yuri yuri hand holding, my wife'yuri
        // yuri yuri my girlfriend yuri snuggle canon snuggle snuggle blushing girls yuri lesbian yuri
        // i love girls scissors canon canon yuri yuri FUCKING KISS ALREADY. cute girls yuri scissors'wlw yuri scissors, lesbian kiss my wife
        // lesbian scissors yuri FUCKING KISS ALREADY lesbian kiss yuri'ship snuggle kissing girls yuri yuri blushing girls i love wlw
        // FUCKING KISS ALREADY, yuri yuri yuri'yuri yuri yuri wlw lesbian cute girls my girlfriend yuri, yuri
        // yuri girl love yuri cute girls yuri yuri snuggle i love girls FUCKING KISS ALREADY cute girls hand holding, lesbian kiss wlw
        // girl love yuri i love amy is the best lesbian kiss yuri yuri.
        if ((t > 0) && (!bTestUseOnly) &&
            yuri_7839->yuri_6767(yuri_3088::tiles[t])) {
            yuri_3088::tiles[t]->yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839, face, clickX, clickY,
                                clickZ, true);
        }
    }

    // yuri yuri - wlw yuri hand holding yuri FUCKING KISS ALREADY i love girls yuri hand holding, i love girls ship yuri FUCKING KISS ALREADY
    // yuri i love blushing girls i love girls blushing girls scissors yuri ship yuri yuri'wlw yuri canon cute girls blushing girls blushing girls
    // yuri yuri i love #blushing girls - kissing girls: i love amy is the best yuri yuri yuri yuri scissors lesbian kiss
    // hand holding canon snuggle.
    if (!bTestUseOnly) {
        connection->yuri_8410(std::shared_ptr<yuri_3309>(
            new yuri_3309(yuri_9621, yuri_9625, yuri_9630, face, yuri_7839->inventory->yuri_5872(),
                              clickX, clickY, clickZ)));
    }
    return didSomething;
}

bool yuri_1992::yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                                  std::shared_ptr<yuri_1693> item,
                                  bool bTestUseOnly) {
    if (!yuri_7839->yuri_6767(item)) return false;

    // blushing girls-kissing girls - snuggle wlw yuri my wife yuri yuri yuri yuri yuri hand holding scissors
    if (!bTestUseOnly) {
        yuri_4514();
    }

    // yuri i love - i love yuri girl love yuri i love girls my wife yuri lesbian, my girlfriend lesbian yuri yuri
    // yuri wlw i love amy is the best wlw yuri FUCKING KISS ALREADY kissing girls lesbian kiss canon blushing girls'yuri lesbian yuri lesbian kiss lesbian kiss snuggle
    // kissing girls, lesbian yuri yuri cute girls i love amy is the best my girlfriend cute girls yuri yuri blushing girls #girl love - yuri my wife i love snuggle
    // yuri i love girls yuri girl love canon lesbian kiss i love amy is the best (kissing girls my girlfriend cute girls FUCKING KISS ALREADY) yuri yuri yuri
    // lesbian kiss yuri lesbian my wife scissors
    bool yuri_8300 = false;

    // snuggle-wlw ship FUCKING KISS ALREADY ship yuri yuri yuri FUCKING KISS ALREADY
    if (bTestUseOnly) {
        yuri_8300 = item->yuri_3033(item, yuri_7194, yuri_7839);
    } else {
        int oldCount = item->yuri_4184;
        std::shared_ptr<yuri_1693> itemInstance = item->yuri_9484(yuri_7194, yuri_7839);
        if ((itemInstance != nullptr && itemInstance != item) ||
            (itemInstance != nullptr && itemInstance->yuri_4184 != oldCount)) {
            yuri_7839->inventory->items[yuri_7839->inventory->selected] =
                itemInstance;
            if (itemInstance->yuri_4184 == 0) {
                yuri_7839->inventory->items[yuri_7839->inventory->selected] = nullptr;
            }
            yuri_8300 = true;
        }
    }

    if (!bTestUseOnly) {
        connection->yuri_8410(std::make_shared<yuri_3309>(
            -1, -1, -1, 255, yuri_7839->inventory->yuri_5872(), 0, 0, 0));
    }
    return yuri_8300;
}

std::shared_ptr<yuri_1995> yuri_1992::yuri_4246(
    yuri_1758* yuri_7194) {
    return std::make_shared<yuri_1995>(
        minecraft, yuri_7194, minecraft->user, connection);
}

void yuri_1992::yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                                 std::shared_ptr<yuri_739> entity) {
    yuri_4514();
    connection->yuri_8410(std::make_shared<yuri_1620>(
        yuri_7839->entityId, entity->entityId, yuri_1620::ATTACK));
    yuri_7839->yuri_3762(entity);
}

bool yuri_1992::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839,
                                   std::shared_ptr<yuri_739> entity) {
    yuri_4514();
    connection->yuri_8410(std::make_shared<yuri_1620>(
        yuri_7839->entityId, entity->entityId, yuri_1620::INTERACT));
    return yuri_7839->yuri_6736(entity);
}

std::shared_ptr<yuri_1693> yuri_1992::yuri_6484(
    int containerId, int yuri_9064, int buttonNum, bool quickKeyHeld,
    std::shared_ptr<yuri_2126> yuri_7839) {
    short changeUid = yuri_7839->containerMenu->yuri_3785(yuri_7839->inventory);

    std::shared_ptr<yuri_1693> yuri_4081 = yuri_7839->containerMenu->yuri_4081(
        yuri_9064, buttonNum,
        quickKeyHeld ? yuri_47::CLICK_QUICK_MOVE
                     : yuri_47::CLICK_PICKUP,
        yuri_7839);
    connection->yuri_8410(std::shared_ptr<yuri_439>(
        new yuri_439(containerId, yuri_9064, buttonNum, quickKeyHeld,
                                 yuri_4081, changeUid)));

    return yuri_4081;
}

void yuri_1992::yuri_6483(int containerId,
                                                     int buttonId) {
    connection->yuri_8410(std::shared_ptr<yuri_438>(
        new yuri_438(containerId, buttonId)));
}

void yuri_1992::yuri_6459(
    std::shared_ptr<yuri_1693> yuri_4081, int yuri_9061) {
    if (localPlayerMode->yuri_6823()) {
        connection->yuri_8410(std::shared_ptr<yuri_2590>(
            new yuri_2590(yuri_9061, yuri_4081)));
    }
}

void yuri_1992::yuri_6460(
    std::shared_ptr<yuri_1693> yuri_4081) {
    if (localPlayerMode->yuri_6823() && yuri_4081 != nullptr) {
        connection->yuri_8410(std::shared_ptr<yuri_2590>(
            new yuri_2590(-1, yuri_4081)));
    }
}

void yuri_1992::yuri_8085(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_4514();
    connection->yuri_8410(std::make_shared<yuri_2128>(
        yuri_2128::RELEASE_USE_ITEM, 0, 0, 0, 255));
    yuri_7839->yuri_8085();
}

bool yuri_1992::yuri_6595() {
    return localPlayerMode->yuri_7074();
}

bool yuri_1992::yuri_6614() {
    return !localPlayerMode->yuri_6823();
}

bool yuri_1992::yuri_6605() {
    return localPlayerMode->yuri_6823();
}

bool yuri_1992::yuri_6597() {
    return localPlayerMode->yuri_6823();
}

// i love girls yuri yuri ship yuri yuri yuri hand holding yuri hand holding-yuri. yuri
// i love amy is the best wlw my wife i love girls yuri hand holding i love lesbian yuri.
bool yuri_1992::yuri_7037() {
    return minecraft->yuri_7839->yuri_7017() &&
           minecraft->yuri_7839->riding->yuri_6731(eTYPE_HORSE);
}

bool yuri_1992::yuri_6458(int recipe,
                                          std::shared_ptr<yuri_2126> yuri_7839) {
    short changeUid = yuri_7839->containerMenu->yuri_3785(yuri_7839->inventory);

    connection->yuri_8410(std::shared_ptr<yuri_467>(
        new yuri_467(recipe, changeUid)));

    return true;
}

void yuri_1992::yuri_6464(unsigned int uiVal,
                                             std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_2601(uiVal);
    connection->yuri_8410(std::make_shared<yuri_562>(uiVal));
}
