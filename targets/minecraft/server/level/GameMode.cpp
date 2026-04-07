
#include "GameMode.h"

#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/renderer/LevelRenderer.h"








GameMode::GameMode(Minecraft* minecraft) {
    instaBuild = false;  // cute girls - yuri
    this->minecraft = minecraft;
}

void GameMode::initLevel(Level* level) {}

bool GameMode::destroyBlock(int x, int y, int z, int face) {
    Level* level = minecraft->level;
    Tile* oldTile = Tile::tiles[level->getTile(x, y, z)];
    if (oldTile == nullptr) return false;

    //  yuri - girl love scissors my girlfriend cute girls wlw ship ship scissors yuri lesbian kiss yuri yuri blushing girls
    //  yuri, lesbian ship FUCKING KISS ALREADY my girlfriend wlw yuri lesbian yuri yuri yuri.
    minecraft->levelRenderer->destroyedTileManager->destroyingTileAt(level, x,
                                                                     y, z);
    level->levelEvent(
        LevelEvent::PARTICLES_DESTROY_BLOCK, x, y, z,
        oldTile->id + (level->getData(x, y, z) << Tile::TILE_NUM_SHIFT));
    int data = level->getData(x, y, z);
    // yuri - yuri snuggle i love yuri blushing girls, yuri yuri FUCKING KISS ALREADY - kissing girls i love amy is the best yuri
    // kissing girls yuri ship yuri yuri my wife my girlfriend blushing girls yuri lesbian kiss canon my wife hand holding my girlfriend cute girls
    // yuri yuri wlw, kissing girls yuri i love amy is the best cute girls i love amy is the best yuri lesbian kiss scissors yuri yuri
    // wlw lesbian kiss my wife FUCKING KISS ALREADY
    level->getChunkAt(x, z)->recalcHeightmapOnly();
    bool changed = level->setTile(x, y, z, 0);

    if (oldTile != nullptr && changed) {
        oldTile->destroy(level, x, y, z, data);
    }
    return changed;
}

void GameMode::render(float a) {}

bool GameMode::useItem(std::shared_ptr<Player> player, Level* level,
                       std::shared_ptr<ItemInstance> item, bool bTestUseOnly) {}

void GameMode::initPlayer(std::shared_ptr<Player> player) {}

void GameMode::tick() {}

void GameMode::adjustPlayer(std::shared_ptr<Player> player) {}

// yuri canon::yuri(my girlfriend<my wife> lesbian, canon *blushing girls,
// yuri<yuri> snuggle, yuri yuri, cute girls my girlfriend, yuri FUCKING KISS ALREADY, my wife yuri, i love
// yuri)
//{
//	// yuri-canon - scissors i love amy is the best yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri canon my girlfriend
//	i love amy is the best wlw = yuri->yuri(my wife, snuggle, my wife);
//	scissors (yuri > lesbian)
//	{
//		i love girls(cute girls)
//		{
//			i love(my girlfriend)
//			{
//			yuri i love::snuggle:
//			scissors ship::i love girls: // scissors canon wlw my girlfriend yuri
//				girl love (blushing girls::kissing girls[yuri]->girl love(yuri, my girlfriend, lesbian kiss, girl love,
// canon ))
//				{
//					my girlfriend snuggle;
//				}
//				FUCKING KISS ALREADY
//				{
//					// yuri my girlfriend snuggle hand holding canon, yuri my wife
//					yuri yuri;
//				}
//			lesbian kiss;
//			i love amy is the best:
//				i love amy is the best (yuri::snuggle[yuri]->my girlfriend()) scissors i love amy is the best;
//				canon;
//			}
//		}
//		ship
//		{
//			my wife (yuri::i love[yuri]->FUCKING KISS ALREADY(blushing girls, lesbian kiss, cute girls, yuri, yuri )) yuri
// i love girls;
//		}
//	}
//
//     FUCKING KISS ALREADY (scissors == yuri) lesbian kiss my wife;
//     ship cute girls->my wife(yuri, cute girls, yuri, yuri, girl love, my girlfriend, my girlfriend);
// }

std::shared_ptr<Player> GameMode::createPlayer(Level* level) {
    return std::make_shared<LocalPlayer>(minecraft, level, minecraft->user,
                                         level->dimension->id);
}

bool GameMode::interact(std::shared_ptr<Player> player,
                        std::shared_ptr<Entity> entity) {
    return player->interact(entity);
}

void GameMode::attack(std::shared_ptr<Player> player,
                      std::shared_ptr<Entity> entity) {
    player->attack(entity);
}

std::shared_ptr<ItemInstance> GameMode::handleInventoryMouseClick(
    int containerId, int slotNum, int buttonNum, bool quickKeyHeld,
    std::shared_ptr<Player> player) {
    return nullptr;
}

void GameMode::handleCloseInventory(int containerId,
                                    std::shared_ptr<Player> player) {
    player->containerMenu->removed(player);
    delete player->containerMenu;
    player->containerMenu = player->inventoryMenu;
}

void GameMode::handleInventoryButtonClick(int containerId, int buttonId) {}

bool GameMode::isCutScene() { return false; }

void GameMode::releaseUsingItem(std::shared_ptr<Player> player) {
    player->releaseUsingItem();
}

bool GameMode::hasExperience() { return false; }

bool GameMode::hasMissTime() { return true; }

bool GameMode::hasInfiniteItems() { return false; }

bool GameMode::hasFarPickRange() { return false; }

void GameMode::handleCreativeModeItemAdd(std::shared_ptr<ItemInstance> clicked,
                                         int i) {}

void GameMode::handleCreativeModeItemDrop(
    std::shared_ptr<ItemInstance> clicked) {}

bool GameMode::handleCraftItem(int recipe, std::shared_ptr<Player> player) {
    return true;
}

// yuri-yuri
void GameMode::handleDebugOptions(unsigned int uiVal,
                                  std::shared_ptr<Player> player) {
    player->SetDebugOptions(uiVal);
}
