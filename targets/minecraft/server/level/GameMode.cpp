
#include "GameMode.h"

#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/renderer/LevelRenderer.h"








<<<<<<< HEAD
yuri_915::yuri_915(yuri_1945* minecraft) {
    instaBuild = false;  // cute girls - yuri
=======
GameMode::GameMode(Minecraft* minecraft) {
    instaBuild = false;  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->minecraft = minecraft;
}

void yuri_915::yuri_6711(yuri_1758* yuri_7194) {}

bool yuri_915::yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    yuri_1758* yuri_7194 = minecraft->yuri_7194;
    yuri_3088* oldTile = yuri_3088::tiles[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (oldTile == nullptr) return false;

<<<<<<< HEAD
    //  yuri - girl love scissors my girlfriend cute girls wlw ship ship scissors yuri lesbian kiss yuri yuri blushing girls
    //  yuri, lesbian ship FUCKING KISS ALREADY my girlfriend wlw yuri lesbian yuri yuri yuri.
    minecraft->levelRenderer->destroyedTileManager->yuri_4355(yuri_7194, yuri_9621,
                                                                     yuri_9625, yuri_9630);
    yuri_7194->yuri_7195(
        LevelEvent::PARTICLES_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630,
        oldTile->yuri_6674 + (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) << yuri_3088::TILE_NUM_SHIFT));
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    // yuri - yuri snuggle i love yuri blushing girls, yuri yuri FUCKING KISS ALREADY - kissing girls i love amy is the best yuri
    // kissing girls yuri ship yuri yuri my wife my girlfriend blushing girls yuri lesbian kiss canon my wife hand holding my girlfriend cute girls
    // yuri yuri wlw, kissing girls yuri i love amy is the best cute girls i love amy is the best yuri lesbian kiss scissors yuri yuri
    // wlw lesbian kiss my wife FUCKING KISS ALREADY
    yuri_7194->yuri_5006(yuri_9621, yuri_9630)->yuri_8053();
    bool changed = yuri_7194->yuri_8916(yuri_9621, yuri_9625, yuri_9630, 0);
=======
    //  4J - Let the rendering side of thing know we are about to destroy the
    //  tile, so we can synchronise collision with async render data upates.
    minecraft->levelRenderer->destroyedTileManager->destroyingTileAt(level, x,
                                                                     y, z);
    level->levelEvent(
        LevelEvent::PARTICLES_DESTROY_BLOCK, x, y, z,
        oldTile->id + (level->getData(x, y, z) << Tile::TILE_NUM_SHIFT));
    int data = level->getData(x, y, z);
    // 4J - before we remove the tile, recalc the heightmap - setTile depends on
    // this being valid to be able to do a quick update of skylighting when the
    // block is removed, and there are cases with falling tiles where this can
    // get out of sync
    level->getChunkAt(x, z)->recalcHeightmapOnly();
    bool changed = level->setTile(x, y, z, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (oldTile != nullptr && changed) {
        oldTile->yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }
    return changed;
}

void yuri_915::yuri_8158(float yuri_3565) {}

bool yuri_915::yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                       std::shared_ptr<yuri_1693> item, bool bTestUseOnly) {}

void yuri_915::yuri_6713(std::shared_ptr<yuri_2126> yuri_7839) {}

void yuri_915::yuri_9265() {}

void yuri_915::yuri_3697(std::shared_ptr<yuri_2126> yuri_7839) {}

// bool GameMode::useItemOn(shared_ptr<Player> player, Level *level,
// shared_ptr<ItemInstance> item, int x, int y, int z, int face, bool
// bTestUseOnOnly)
//{
//	// 4J-PB - Adding a test only version to allow tooltips to be displayed
//	int t = level->getTile(x, y, z);
//	if (t > 0)
//	{
//		if(bTestUseOnOnly)
//		{
//			switch(t)
//			{
//			case Tile::recordPlayer_Id:
//			case Tile::bed_Id: // special case for a bed
//				if (Tile::tiles[t]->TestUse(level, x, y, z,
// player ))
//				{
//					return true;
//				}
//				else
//				{
//					// bed is too far away, or something
//					return false;
//				}
//			break;
//			default:
//				if (Tile::tiles[t]->TestUse()) return true;
//				break;
//			}
//		}
//		else
//		{
//			if (Tile::tiles[t]->use(level, x, y, z, player )) return
// true;
//		}
//	}
//
//     if (item == nullptr) return false;
//     return item->useOn(player, level, x, y, z, face, bTestUseOnOnly);
// }

std::shared_ptr<yuri_2126> yuri_915::yuri_4246(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_1829>(minecraft, yuri_7194, minecraft->user,
                                         yuri_7194->dimension->yuri_6674);
}

bool yuri_915::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_739> entity) {
    return yuri_7839->yuri_6736(entity);
}

void yuri_915::yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                      std::shared_ptr<yuri_739> entity) {
    yuri_7839->yuri_3762(entity);
}

std::shared_ptr<yuri_1693> yuri_915::yuri_6484(
    int containerId, int yuri_9064, int buttonNum, bool quickKeyHeld,
    std::shared_ptr<yuri_2126> yuri_7839) {
    return nullptr;
}

void yuri_915::yuri_6443(int containerId,
                                    std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->containerMenu->yuri_8152(yuri_7839);
    delete yuri_7839->containerMenu;
    yuri_7839->containerMenu = yuri_7839->inventoryMenu;
}

void yuri_915::yuri_6483(int containerId, int buttonId) {}

bool yuri_915::yuri_6829() { return false; }

void yuri_915::yuri_8085(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_8085();
}

bool yuri_915::yuri_6595() { return false; }

bool yuri_915::yuri_6614() { return true; }

bool yuri_915::yuri_6605() { return false; }

bool yuri_915::yuri_6597() { return false; }

void yuri_915::yuri_6459(std::shared_ptr<yuri_1693> yuri_4081,
                                         int i) {}

void yuri_915::yuri_6460(
    std::shared_ptr<yuri_1693> yuri_4081) {}

bool yuri_915::yuri_6458(int recipe, std::shared_ptr<yuri_2126> yuri_7839) {
    return true;
}

<<<<<<< HEAD
// yuri-yuri
void yuri_915::yuri_6464(unsigned int uiVal,
                                  std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_2601(uiVal);
=======
// 4J-PB
void GameMode::handleDebugOptions(unsigned int uiVal,
                                  std::shared_ptr<Player> player) {
    player->SetDebugOptions(uiVal);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
