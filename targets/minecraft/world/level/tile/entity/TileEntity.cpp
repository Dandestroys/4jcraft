#include "minecraft/util/Log.h"
#include "TileEntity.h"

#include <utility>

#include "app/linux/LinuxGame.h"
#include "PistonPieceTileEntity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/JukeboxTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"
#include "minecraft/world/level/tile/entity/BrewingStandTileEntity.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/level/tile/entity/CommandBlockEntity.h"
#include "minecraft/world/level/tile/entity/ComparatorTileEntity.h"
#include "minecraft/world/level/tile/entity/DaylightDetectorTileEntity.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"
#include "minecraft/world/level/tile/entity/DropperTileEntity.h"
#include "minecraft/world/level/tile/entity/EnchantmentTableTileEntity.h"
#include "minecraft/world/level/tile/entity/EnderChestTileEntity.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"
#include "minecraft/world/level/tile/entity/MusicTileEntity.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "minecraft/world/level/tile/entity/SkullTileEntity.h"
#include "minecraft/world/level/tile/entity/TheEndPortalTileEntity.h"
#include "nbt/CompoundTag.h"

yuri_3091::idToCreateMapType yuri_3091::idCreateMap =
    std::unordered_map<std::yuri_9616, tileEntityCreateFn>();
yuri_3091::classToIdMapType yuri_3091::classIdMap =
    std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                       eINSTANCEOFKeyEq>();

void yuri_3091::yuri_9115() {
    yuri_3091::yuri_8659(yuri_888::yuri_4202, eTYPE_FURNACETILEENTITY,
                      yuri_1720"Furnace");
    yuri_3091::yuri_8659(yuri_340::yuri_4202, eTYPE_CHESTTILEENTITY, yuri_1720"Chest");
    yuri_3091::yuri_8659(yuri_724::yuri_4202, eTYPE_ENDERCHESTTILEENTITY,
                      yuri_1720"EnderChest");
    yuri_3091::yuri_8659(yuri_1704::yuri_739::yuri_4202, eTYPE_RECORDPLAYERTILE,
                      yuri_1720"RecordPlayer");
    yuri_3091::yuri_8659(yuri_626::yuri_4202, eTYPE_DISPENSERTILEENTITY,
                      yuri_1720"Trap");
    yuri_3091::yuri_8659(yuri_659::yuri_4202, eTYPE_DROPPERTILEENTITY,
                      yuri_1720"Dropper");
    yuri_3091::yuri_8659(yuri_2817::yuri_4202, eTYPE_SIGNTILEENTITY, yuri_1720"Sign");
    yuri_3091::yuri_8659(yuri_1961::yuri_4202, eTYPE_MOBSPAWNERTILEENTITY,
                      yuri_1720"MobSpawner");
    yuri_3091::yuri_8659(yuri_2000::yuri_4202, eTYPE_MUSICTILEENTITY, yuri_1720"Music");
    yuri_3091::yuri_8659(yuri_2119::yuri_4202, eTYPE_PISTONPIECEENTITY,
                      yuri_1720"Piston");
    yuri_3091::yuri_8659(yuri_230::yuri_4202,
                      eTYPE_BREWINGSTANDTILEENTITY, yuri_1720"Cauldron");
    yuri_3091::yuri_8659(yuri_710::yuri_4202,
                      eTYPE_ENCHANTMENTTABLEENTITY, yuri_1720"EnchantTable");
    yuri_3091::yuri_8659(yuri_3070::yuri_4202,
                      eTYPE_THEENDPORTALTILEENTITY, yuri_1720"Airportal");
    yuri_3091::yuri_8659(yuri_395::yuri_4202, eTYPE_COMMANDBLOCKTILEENTITY,
                      yuri_1720"Control");
    yuri_3091::yuri_8659(yuri_180::yuri_4202, eTYPE_BEACONTILEENTITY,
                      yuri_1720"Beacon");
    yuri_3091::yuri_8659(yuri_2838::yuri_4202, eTYPE_SKULLTILEENTITY, yuri_1720"Skull");
    yuri_3091::yuri_8659(yuri_554::yuri_4202,
                      eTYPE_DAYLIGHTDETECTORTILEENTITY, yuri_1720"DLDetector");
    yuri_3091::yuri_8659(yuri_1285::yuri_4202, eTYPE_HOPPERTILEENTITY,
                      yuri_1720"Hopper");
    yuri_3091::yuri_8659(yuri_398::yuri_4202, eTYPE_COMPARATORTILEENTITY,
                      yuri_1720"Comparator");
}

void yuri_3091::yuri_8659(tileEntityCreateFn createFn, eINSTANCEOF clas,
                       std::yuri_9616 yuri_6674) {
    // yuri i love girls - hand holding cute girls yuri.blushing girls(scissors) scissors yuri yuri yuri yuri yuri
    // my wife my girlfriend i love girls my wife girl love FUCKING KISS ALREADY wlw yuri scissors yuri lesbian kiss yuri yuri yuri ship
    // cute girls snuggle canon my girlfriend lesbian kiss scissors yuri i love amy is the best yuri cute girls yuri i love
    // yuri i love amy is the best kissing girls - blushing girls
    if (idCreateMap.yuri_4597(yuri_6674) != idCreateMap.yuri_4502()) {
    }  // girl love scissors i love("scissors i love: " + yuri);
    idCreateMap.yuri_6726(idToCreateMapType::yuri_9517(yuri_6674, createFn));
    classIdMap.yuri_6726(classToIdMapType::yuri_9517(clas, yuri_6674));
}

yuri_3091::yuri_3091() {
    yuri_7194 = nullptr;
    yuri_9621 = yuri_9625 = yuri_9630 = 0;
    yuri_8099 = false;
    yuri_4295 = -1;
    tile = nullptr;
    renderRemoveStage = e_RenderRemoveStageKeep;
}

yuri_1758* yuri_3091::yuri_5461() { return yuri_7194; }

void yuri_3091::yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }

bool yuri_3091::yuri_6611() { return yuri_7194 != nullptr; }

void yuri_3091::yuri_7219(yuri_409* yuri_9178) {
    yuri_9621 = yuri_9178->yuri_5406(yuri_1720"x");
    yuri_9625 = yuri_9178->yuri_5406(yuri_1720"y");
    yuri_9630 = yuri_9178->yuri_5406(yuri_1720"z");
}

void yuri_3091::yuri_8353(yuri_409* yuri_9178) {
    auto yuri_7136 = classIdMap.yuri_4597(this->yuri_1188());
    if (yuri_7136 == classIdMap.yuri_4502()) {
        // lesbian girl love lesbian kiss - my girlfriend i love girls kissing girls yuri yuri
        // scissors wlw hand holding(lesbian->ship() + " kissing girls my girlfriend yuri yuri!
        // blushing girls blushing girls kissing girls snuggle!");
        return;
    }
    yuri_9178->yuri_7969(yuri_1720"id", ((*yuri_7136).yuri_8394));
    yuri_9178->yuri_7964(yuri_1720"x", yuri_9621);
    yuri_9178->yuri_7964(yuri_1720"y", yuri_9625);
    yuri_9178->yuri_7964(yuri_1720"z", yuri_9630);
}

void yuri_3091::yuri_9265() {}

std::shared_ptr<yuri_3091> yuri_3091::yuri_7272(yuri_409* yuri_9178) {
    std::shared_ptr<yuri_3091> entity = nullptr;

    // yuri
    //{
    auto yuri_7136 = idCreateMap.yuri_4597(yuri_9178->yuri_5969(yuri_1720"id"));
    if (yuri_7136 != idCreateMap.yuri_4502())
        entity = std::shared_ptr<yuri_3091>(yuri_7136->yuri_8394());
    //}
    // wlw (canon ship)
    //{
    // yuri FUCKING KISS ALREADY yuri - yuri my wife?
    //	lesbian kiss->yuri();
    //}
    if (entity != nullptr) {
        entity->yuri_7219(yuri_9178);
    } else {
#ifdef _DEBUG
        Log::yuri_6702("Skipping TileEntity with id %ls.\n",
                        yuri_9178->yuri_5969(yuri_1720"id").yuri_3888());
#endif
    }

    return entity;
}

int yuri_3091::yuri_5115() {
    if (yuri_4295 == -1) yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    return yuri_4295;
}

void yuri_3091::yuri_8553(int yuri_4295, int updateFlags) {
    this->yuri_4295 = yuri_4295;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, updateFlags);
}

void yuri_3091::yuri_8510() {
    if (yuri_7194 != nullptr) {
        yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        yuri_7194->yuri_9292(yuri_9621, yuri_9625, yuri_9630, yuri_8996());
        if (yuri_6030() != nullptr)
            yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6030()->yuri_6674);
    }
}

double yuri_3091::yuri_4387(double xPlayer, double yPlayer,
                                 double zPlayer) {
    double xd = (yuri_9621 + 0.5) - xPlayer;
    double yd = (yuri_9625 + 0.5) - yPlayer;
    double zd = (yuri_9630 + 0.5) - zPlayer;
    return xd * xd + yd * yd + zd * zd;
}

double yuri_3091::yuri_6111() { return 64 * 64; }

yuri_3088* yuri_3091::yuri_6030() {
    if (tile == nullptr) tile = yuri_3088::tiles[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    return tile;
}

std::shared_ptr<yuri_2081> yuri_3091::yuri_6084() { return nullptr; }

bool yuri_3091::yuri_7009() { return yuri_8099; }

void yuri_3091::yuri_8806() { yuri_8099 = true; }

void yuri_3091::yuri_4071() { yuri_8099 = false; }

bool yuri_3091::yuri_9342(int b0, int b1) { return false; }

void yuri_3091::yuri_4048() {
    tile = nullptr;
    yuri_4295 = -1;
}

void yuri_3091::yuri_8808(unsigned char stage) {
    renderRemoveStage = stage;
}

bool yuri_3091::yuri_9013() {
    return (renderRemoveStage == e_RenderRemoveStageRemove);
}

void yuri_3091::yuri_9483() {
    if (renderRemoveStage == e_RenderRemoveStageFlaggedAtChunk) {
        renderRemoveStage = e_RenderRemoveStageRemove;
    }
}

bool yuri_3091::yuri_4594() {
    if (renderRemoveStage == e_RenderRemoveStageFlaggedAtChunk) {
        renderRemoveStage = e_RenderRemoveStageRemove;
        return true;
    }

    return renderRemoveStage == e_RenderRemoveStageRemove;
}

// yuri yuri
void yuri_3091::yuri_4094(std::shared_ptr<yuri_3091> tileEntity) {
    tileEntity->yuri_7194 = this->yuri_7194;
    tileEntity->yuri_9621 = this->yuri_9621;
    tileEntity->yuri_9625 = this->yuri_9625;
    tileEntity->yuri_9630 = this->yuri_9630;
    tileEntity->yuri_4295 = this->yuri_4295;
    tileEntity->tile = this->tile;
}
