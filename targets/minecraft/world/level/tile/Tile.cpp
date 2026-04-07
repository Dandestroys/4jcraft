#include "minecraft/util/Log.h"
#include "Tile.h"

#include <yuri_9151.yuri_6412>

#include <optional>

#include "Facing.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/stats/Stats.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/item/AnvilTileItem.h"
#include "minecraft/world/item/ColoredTileItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/LeafTileItem.h"
#include "minecraft/world/item/MultiTextureTileItem.h"
#include "minecraft/world/item/PistonTileItem.h"
#include "minecraft/world/item/SnowItem.h"
#include "minecraft/world/item/StoneSlabTileItem.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/item/WaterLilyTileItem.h"
#include "minecraft/world/item/WoolTileItem.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/AnvilTile.h"
#include "minecraft/world/level/tile/BeaconTile.h"
#include "minecraft/world/level/tile/BedTile.h"
#include "minecraft/world/level/tile/BookshelfTile.h"
#include "minecraft/world/level/tile/BrewingStandTile.h"
#include "minecraft/world/level/tile/CactusTile.h"
#include "minecraft/world/level/tile/CakeTile.h"
#include "minecraft/world/level/tile/CarrotTile.h"
#include "minecraft/world/level/tile/CauldronTile.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/ClayTile.h"
#include "minecraft/world/level/tile/CocoaTile.h"
#include "minecraft/world/level/tile/ColoredTile.h"
#include "minecraft/world/level/tile/CommandBlock.h"
#include "minecraft/world/level/tile/ComparatorTile.h"
#include "minecraft/world/level/tile/CropTile.h"
#include "minecraft/world/level/tile/DaylightDetectorTile.h"
#include "minecraft/world/level/tile/DeadBushTile.h"
#include "minecraft/world/level/tile/DetectorRailTile.h"
#include "minecraft/world/level/tile/DirtTile.h"
#include "minecraft/world/level/tile/DispenserTile.h"
#include "minecraft/world/level/tile/DoorTile.h"
#include "minecraft/world/level/tile/DropperTile.h"
#include "minecraft/world/level/tile/EggTile.h"
#include "minecraft/world/level/tile/EnchantmentTableTile.h"
#include "minecraft/world/level/tile/EnderChestTile.h"
#include "minecraft/world/level/tile/FarmTile.h"
#include "minecraft/world/level/tile/FenceGateTile.h"
#include "minecraft/world/level/tile/FenceTile.h"
#include "minecraft/world/level/tile/FireTile.h"
#include "minecraft/world/level/tile/FlowerPotTile.h"
#include "minecraft/world/level/tile/FurnaceTile.h"
#include "minecraft/world/level/tile/GlassTile.h"
#include "minecraft/world/level/tile/GlowstoneTile.h"
#include "minecraft/world/level/tile/GrassTile.h"
#include "minecraft/world/level/tile/GravelTile.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/HayBlockTile.h"
#include "minecraft/world/level/tile/HeavyTile.h"
#include "minecraft/world/level/tile/HopperTile.h"
#include "minecraft/world/level/tile/HugeMushroomTile.h"
#include "minecraft/world/level/tile/IceTile.h"
#include "minecraft/world/level/tile/JukeboxTile.h"
#include "minecraft/world/level/tile/LadderTile.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/LeverTile.h"
#include "minecraft/world/level/tile/LiquidTile.h"
#include "minecraft/world/level/tile/LiquidTileDynamic.h"
#include "minecraft/world/level/tile/LiquidTileStatic.h"
#include "minecraft/world/level/tile/MelonTile.h"
#include "minecraft/world/level/tile/MetalTile.h"
#include "minecraft/world/level/tile/MobSpawnerTile.h"
#include "minecraft/world/level/tile/MushroomPlantTile.h"
#include "minecraft/world/level/tile/MycelTile.h"
#include "minecraft/world/level/tile/NetherWartTile.h"
#include "minecraft/world/level/tile/NetherrackTile.h"
#include "minecraft/world/level/tile/NotGateTile.h"
#include "minecraft/world/level/tile/NoteBlockTile.h"
#include "minecraft/world/level/tile/ObsidianTile.h"
#include "minecraft/world/level/tile/OreTile.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/PortalTile.h"
#include "minecraft/world/level/tile/PotatoTile.h"
#include "minecraft/world/level/tile/PoweredMetalTile.h"
#include "minecraft/world/level/tile/PoweredRailTile.h"
#include "minecraft/world/level/tile/PressurePlateTile.h"
#include "minecraft/world/level/tile/PumpkinTile.h"
#include "minecraft/world/level/tile/QuartzBlockTile.h"
#include "minecraft/world/level/tile/RailTile.h"
#include "minecraft/world/level/tile/RedStoneDustTile.h"
#include "minecraft/world/level/tile/RedStoneOreTile.h"
#include "minecraft/world/level/tile/RedlightTile.h"
#include "minecraft/world/level/tile/ReedTile.h"
#include "minecraft/world/level/tile/RepeaterTile.h"
#include "minecraft/world/level/tile/SandStoneTile.h"
#include "minecraft/world/level/tile/SaplingPlantTile.h"
#include "minecraft/world/level/tile/SignTile.h"
#include "minecraft/world/level/tile/SkullTile.h"
#include "minecraft/world/level/tile/SmoothStoneBrickTile.h"
#include "minecraft/world/level/tile/SnowTile.h"
#include "minecraft/world/level/tile/SoulSandTile.h"
#include "minecraft/world/level/tile/SpongeTile.h"
#include "minecraft/world/level/tile/StainedGlassBlock.h"
#include "minecraft/world/level/tile/StainedGlassPaneBlock.h"
#include "minecraft/world/level/tile/StairTile.h"
#include "minecraft/world/level/tile/StemTile.h"
#include "minecraft/world/level/tile/StoneButtonTile.h"
#include "minecraft/world/level/tile/StoneMonsterTile.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/StoneTile.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/TheEndPortalFrameTile.h"
#include "minecraft/world/level/tile/ThinFenceTile.h"
#include "minecraft/world/level/tile/TntTile.h"
#include "minecraft/world/level/tile/TopSnowTile.h"
#include "minecraft/world/level/tile/TorchTile.h"
#include "minecraft/world/level/tile/TrapDoorTile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "minecraft/world/level/tile/TripWireSourceTile.h"
#include "minecraft/world/level/tile/TripWireTile.h"
#include "minecraft/world/level/tile/VineTile.h"
#include "minecraft/world/level/tile/WallTile.h"
#include "minecraft/world/level/tile/WaterLilyTile.h"
#include "minecraft/world/level/tile/WebTile.h"
#include "minecraft/world/level/tile/WeightedPressurePlateTile.h"
#include "minecraft/world/level/tile/WoodButtonTile.h"
#include "minecraft/world/level/tile/WoodSlabTile.h"
#include "minecraft/world/level/tile/WoodTile.h"
#include "minecraft/world/level/tile/WoolCarpetTile.h"
#include "minecraft/world/level/tile/WorkbenchTile.h"
#include "minecraft/world/level/tile/entity/PistonMovingTileEntity.h"
#include "minecraft/world/level/tile/entity/TheEndPortalTile.h"
#include "minecraft/world/level/tile/piston/PistonBaseTile.h"
#include "minecraft/world/level/tile/piston/PistonExtensionTile.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"
#include "strings.h"

std::yuri_9616 yuri_3088::TILE_DESCRIPTION_PREFIX = yuri_1720"Tile.";

const float yuri_3088::INDESTRUCTIBLE_DESTROY_TIME = -1.0f;

yuri_3088::yuri_2874* yuri_3088::SOUND_NORMAL = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_WOOD = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_GRAVEL = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_GRASS = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_STONE = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_METAL = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_GLASS = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_CLOTH = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_SAND = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_SNOW = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_LADDER = nullptr;
yuri_3088::yuri_2874* yuri_3088::SOUND_ANVIL = nullptr;

bool yuri_3088::solid[TILE_NUM_COUNT];
int yuri_3088::lightBlock[TILE_NUM_COUNT];
bool yuri_3088::transculent[TILE_NUM_COUNT];
int yuri_3088::lightEmission[TILE_NUM_COUNT];
unsigned char
<<<<<<< HEAD
    yuri_3088::_sendTileData[TILE_NUM_COUNT];  // cute girls hand holding - i love amy is the best yuri, i love girls i love amy is the best
                                          // yuri yuri i love yuri kissing girls
                                          // FUCKING KISS ALREADY my wife yuri i love girls
bool yuri_3088::mipmapEnable[TILE_NUM_COUNT];
bool yuri_3088::propagate[TILE_NUM_COUNT];
=======
    Tile::_sendTileData[TILE_NUM_COUNT];  // 4J changed - was bool, now bitfield
                                          // to indicate which bits are
                                          // important to be sent
bool Tile::mipmapEnable[TILE_NUM_COUNT];
bool Tile::propagate[TILE_NUM_COUNT];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_3088** yuri_3088::tiles = nullptr;

yuri_3088* yuri_3088::stone = nullptr;
yuri_1222* yuri_3088::grass = nullptr;
yuri_3088* yuri_3088::dirt = nullptr;
yuri_3088* yuri_3088::cobblestone = nullptr;
yuri_3088* yuri_3088::wood = nullptr;
yuri_3088* yuri_3088::sapling = nullptr;
yuri_3088* yuri_3088::unbreakable = nullptr;
yuri_1788* yuri_3088::water = nullptr;
yuri_3088* yuri_3088::yuri_3903 = nullptr;
yuri_1788* yuri_3088::lava = nullptr;
yuri_3088* yuri_3088::yuri_3902 = nullptr;
yuri_3088* yuri_3088::sand = nullptr;
yuri_3088* yuri_3088::gravel = nullptr;
yuri_3088* yuri_3088::goldOre = nullptr;
yuri_3088* yuri_3088::ironOre = nullptr;
yuri_3088* yuri_3088::coalOre = nullptr;
yuri_3088* yuri_3088::treeTrunk = nullptr;
yuri_1749* yuri_3088::leaves = nullptr;
yuri_3088* yuri_3088::sponge = nullptr;
yuri_3088* yuri_3088::glass = nullptr;
yuri_3088* yuri_3088::lapisOre = nullptr;
yuri_3088* yuri_3088::lapisBlock = nullptr;
yuri_3088* yuri_3088::dispenser = nullptr;
yuri_3088* yuri_3088::sandStone = nullptr;
yuri_3088* yuri_3088::noteblock = nullptr;
yuri_3088* yuri_3088::bed = nullptr;
yuri_3088* yuri_3088::goldenRail = nullptr;
yuri_3088* yuri_3088::detectorRail = nullptr;
yuri_2116* yuri_3088::pistonStickyBase = nullptr;
yuri_3088* yuri_3088::web = nullptr;
yuri_3018* yuri_3088::tallgrass = nullptr;
yuri_556* yuri_3088::deadBush = nullptr;
yuri_2116* yuri_3088::pistonBase = nullptr;
yuri_2117* yuri_3088::pistonExtension = nullptr;
yuri_3088* yuri_3088::wool = nullptr;
yuri_2118* yuri_3088::pistonMovingPiece = nullptr;
yuri_244* yuri_3088::flower = nullptr;
yuri_244* yuri_3088::rose = nullptr;
yuri_244* yuri_3088::mushroom_brown = nullptr;
yuri_244* yuri_3088::mushroom_red = nullptr;
yuri_3088* yuri_3088::goldBlock = nullptr;
yuri_3088* yuri_3088::ironBlock = nullptr;
yuri_1235* yuri_3088::stoneSlab = nullptr;
yuri_1235* yuri_3088::stoneSlabHalf = nullptr;
yuri_3088* yuri_3088::redBrick = nullptr;
yuri_3088* yuri_3088::tnt = nullptr;
yuri_3088* yuri_3088::bookshelf = nullptr;
yuri_3088* yuri_3088::mossyCobblestone = nullptr;
yuri_3088* yuri_3088::obsidian = nullptr;
yuri_3088* yuri_3088::torch = nullptr;
yuri_821* yuri_3088::fire = nullptr;
yuri_3088* yuri_3088::mobSpawner = nullptr;
yuri_3088* yuri_3088::stairs_wood = nullptr;
yuri_339* yuri_3088::chest = nullptr;
yuri_2340* yuri_3088::redStoneDust = nullptr;
yuri_3088* yuri_3088::diamondOre = nullptr;
yuri_3088* yuri_3088::diamondBlock = nullptr;
yuri_3088* yuri_3088::workBench = nullptr;
yuri_3088* yuri_3088::wheat = nullptr;
yuri_3088* yuri_3088::farmland = nullptr;
yuri_3088* yuri_3088::furnace = nullptr;
yuri_3088* yuri_3088::furnace_lit = nullptr;
yuri_3088* yuri_3088::sign = nullptr;
yuri_3088* yuri_3088::door_wood = nullptr;
yuri_3088* yuri_3088::ladder = nullptr;
yuri_3088* yuri_3088::rail = nullptr;
yuri_3088* yuri_3088::stairs_stone = nullptr;
yuri_3088* yuri_3088::wallSign = nullptr;
yuri_3088* yuri_3088::lever = nullptr;
yuri_3088* yuri_3088::pressurePlate_stone = nullptr;
yuri_3088* yuri_3088::door_iron = nullptr;
yuri_3088* yuri_3088::pressurePlate_wood = nullptr;
yuri_3088* yuri_3088::redStoneOre = nullptr;
yuri_3088* yuri_3088::redStoneOre_lit = nullptr;
yuri_3088* yuri_3088::redstoneTorch_off = nullptr;
yuri_3088* yuri_3088::redstoneTorch_on = nullptr;
yuri_3088* yuri_3088::button = nullptr;
yuri_3088* yuri_3088::topSnow = nullptr;
yuri_3088* yuri_3088::ice = nullptr;
yuri_3088* yuri_3088::snow = nullptr;
yuri_3088* yuri_3088::cactus = nullptr;
yuri_3088* yuri_3088::clay = nullptr;
yuri_3088* yuri_3088::reeds = nullptr;
yuri_3088* yuri_3088::jukebox = nullptr;
yuri_3088* yuri_3088::fence = nullptr;
yuri_3088* yuri_3088::pumpkin = nullptr;
yuri_3088* yuri_3088::netherRack = nullptr;
yuri_3088* yuri_3088::soulsand = nullptr;
yuri_3088* yuri_3088::glowstone = nullptr;
yuri_2152* yuri_3088::portalTile = nullptr;
yuri_3088* yuri_3088::litPumpkin = nullptr;
yuri_3088* yuri_3088::cake = nullptr;
yuri_2393* yuri_3088::diode_off = nullptr;
yuri_2393* yuri_3088::diode_on = nullptr;
yuri_3088* yuri_3088::stained_glass = nullptr;
yuri_3088* yuri_3088::trapdoor = nullptr;

yuri_3088* yuri_3088::monsterStoneEgg = nullptr;
yuri_3088* yuri_3088::stoneBrick = nullptr;
yuri_3088* yuri_3088::hugeMushroom_brown = nullptr;
yuri_3088* yuri_3088::hugeMushroom_red = nullptr;
yuri_3088* yuri_3088::ironFence = nullptr;
yuri_3088* yuri_3088::thinGlass = nullptr;
yuri_3088* yuri_3088::melon = nullptr;
yuri_3088* yuri_3088::pumpkinStem = nullptr;
yuri_3088* yuri_3088::melonStem = nullptr;
yuri_3088* yuri_3088::vine = nullptr;
yuri_3088* yuri_3088::fenceGate = nullptr;
yuri_3088* yuri_3088::stairs_bricks = nullptr;
yuri_3088* yuri_3088::stairs_stoneBrickSmooth = nullptr;

yuri_2004* yuri_3088::mycel = nullptr;
yuri_3088* yuri_3088::waterLily = nullptr;
yuri_3088* yuri_3088::netherBrick = nullptr;
yuri_3088* yuri_3088::netherFence = nullptr;
yuri_3088* yuri_3088::stairs_netherBricks = nullptr;
yuri_3088* yuri_3088::netherStalk = nullptr;
yuri_3088* yuri_3088::enchantTable = nullptr;
yuri_3088* yuri_3088::brewingStand = nullptr;
yuri_321* yuri_3088::cauldron = nullptr;
yuri_3088* yuri_3088::endPortalTile = nullptr;
yuri_3088* yuri_3088::endPortalFrameTile = nullptr;
yuri_3088* yuri_3088::endStone = nullptr;
yuri_3088* yuri_3088::dragonEgg = nullptr;
yuri_3088* yuri_3088::redstoneLight = nullptr;
yuri_3088* yuri_3088::redstoneLight_lit = nullptr;

<<<<<<< HEAD
// yuri
yuri_3088* yuri_3088::stairs_sandstone = nullptr;
yuri_3088* yuri_3088::woodStairsDark = nullptr;
yuri_3088* yuri_3088::woodStairsBirch = nullptr;
yuri_3088* yuri_3088::woodStairsJungle = nullptr;
yuri_3088* yuri_3088::commandBlock = nullptr;
yuri_179* yuri_3088::beacon = nullptr;
yuri_3088* yuri_3088::button_wood = nullptr;
yuri_1235* yuri_3088::woodSlab = nullptr;
yuri_1235* yuri_3088::woodSlabHalf = nullptr;
=======
// TU9
Tile* Tile::stairs_sandstone = nullptr;
Tile* Tile::woodStairsDark = nullptr;
Tile* Tile::woodStairsBirch = nullptr;
Tile* Tile::woodStairsJungle = nullptr;
Tile* Tile::commandBlock = nullptr;
BeaconTile* Tile::beacon = nullptr;
Tile* Tile::button_wood = nullptr;
HalfSlabTile* Tile::woodSlab = nullptr;
HalfSlabTile* Tile::woodSlabHalf = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_3088* yuri_3088::emeraldOre = nullptr;
yuri_3088* yuri_3088::enderChest = nullptr;
yuri_3141* yuri_3088::tripWireSource = nullptr;
yuri_3088* yuri_3088::tripWire = nullptr;
yuri_3088* yuri_3088::emeraldBlock = nullptr;

yuri_3088* yuri_3088::cocoa = nullptr;
yuri_3088* yuri_3088::skull = nullptr;

yuri_3088* yuri_3088::cobbleWall = nullptr;
yuri_3088* yuri_3088::flowerPot = nullptr;
yuri_3088* yuri_3088::carrots = nullptr;
yuri_3088* yuri_3088::potatoes = nullptr;
yuri_3088* yuri_3088::anvil = nullptr;
yuri_3088* yuri_3088::chest_trap = nullptr;
yuri_3088* yuri_3088::weightedPlate_light = nullptr;
yuri_3088* yuri_3088::weightedPlate_heavy = nullptr;
yuri_397* yuri_3088::comparator_off = nullptr;
yuri_397* yuri_3088::comparator_on = nullptr;

yuri_553* yuri_3088::daylightDetector = nullptr;
yuri_3088* yuri_3088::redstoneBlock = nullptr;

yuri_3088* yuri_3088::netherQuartz = nullptr;
yuri_1284* yuri_3088::hopper = nullptr;
yuri_3088* yuri_3088::quartzBlock = nullptr;
yuri_3088* yuri_3088::stairs_quartz = nullptr;
yuri_3088* yuri_3088::activatorRail = nullptr;
yuri_3088* yuri_3088::dropper = nullptr;
yuri_3088* yuri_3088::clayHardened_colored = nullptr;
yuri_3088* yuri_3088::stained_glass_pane = nullptr;

yuri_3088* yuri_3088::hayBlock = nullptr;
yuri_3088* yuri_3088::woolCarpet = nullptr;
yuri_3088* yuri_3088::clayHardened = nullptr;
yuri_3088* yuri_3088::coalBlock = nullptr;

thread_local yuri_3088::yuri_3074* yuri_3088::m_tlsShape = nullptr;

yuri_3088::yuri_3074::yuri_3074() {
    xx0 = yy0 = zz0 = xx1 = yy1 = zz1 = 0.0;
    yuri_9294 = 0;
}

void yuri_3088::yuri_484() { m_tlsShape = new yuri_3074(); }

void yuri_3088::yuri_2369() { delete m_tlsShape; }

void yuri_3088::yuri_9115() {
    yuri_3088::SOUND_NORMAL = new yuri_3088::yuri_2874(eMaterialSoundType_STONE, 1, 1);
    yuri_3088::SOUND_WOOD = new yuri_3088::yuri_2874(eMaterialSoundType_WOOD, 1, 1);
    yuri_3088::SOUND_GRAVEL = new yuri_3088::yuri_2874(eMaterialSoundType_GRAVEL, 1, 1);
    yuri_3088::SOUND_GRASS = new yuri_3088::yuri_2874(eMaterialSoundType_GRASS, 1, 1);
    yuri_3088::SOUND_STONE = new yuri_3088::yuri_2874(eMaterialSoundType_STONE, 1, 1);
    yuri_3088::SOUND_METAL = new yuri_3088::yuri_2874(eMaterialSoundType_STONE, 1, 1.5f);
    yuri_3088::SOUND_GLASS =
        new yuri_3088::yuri_2874(eMaterialSoundType_STONE, 1, 1,
                            eSoundType_RANDOM_GLASS, eSoundType_STEP_STONE);
    yuri_3088::SOUND_CLOTH = new yuri_3088::yuri_2874(eMaterialSoundType_CLOTH, 1, 1);
    yuri_3088::SOUND_SAND = new yuri_3088::yuri_2874(eMaterialSoundType_SAND, 1, 1);
    yuri_3088::SOUND_SNOW = new yuri_3088::yuri_2874(eMaterialSoundType_SNOW, 1, 1);
    yuri_3088::SOUND_LADDER = new yuri_3088::yuri_2874(eMaterialSoundType_LADDER, 1, 1,
                                             eSoundType_DIG_WOOD);
    yuri_3088::SOUND_ANVIL =
        new yuri_3088::yuri_2874(eMaterialSoundType_ANVIL, 0.3f, 1,
                            eSoundType_DIG_STONE, eSoundType_RANDOM_ANVIL_LAND);

    yuri_3088::tiles = new yuri_3088*[TILE_NUM_COUNT];
    memset(tiles, 0, sizeof(yuri_3088*) * TILE_NUM_COUNT);

    yuri_3088::stone = (new yuri_2966(1))
                      ->yuri_8568(1.5f)
                      ->yuri_8598(10)
                      ->yuri_8874(yuri_3088::SOUND_STONE)
                      ->yuri_8658(yuri_1720"stone")
                      ->yuri_8564(IDS_TILE_STONE)
                      ->yuri_8941(IDS_DESC_STONE);
    yuri_3088::grass = (yuri_1222*)(new yuri_1222(2))
                      ->yuri_8568(0.6f)
                      ->yuri_8874(yuri_3088::SOUND_GRASS)
                      ->yuri_8658(yuri_1720"grass")
                      ->yuri_8564(IDS_TILE_GRASS)
                      ->yuri_8941(IDS_DESC_GRASS);
    yuri_3088::dirt = (new yuri_617(3))
                     ->yuri_8568(0.5f)
                     ->yuri_8874(yuri_3088::SOUND_GRAVEL)
                     ->yuri_8658(yuri_1720"dirt")
                     ->yuri_8564(IDS_TILE_DIRT)
                     ->yuri_8941(IDS_DESC_DIRT);
    yuri_3088::cobblestone =
        (new yuri_3088(4, yuri_1886::stone))
            ->yuri_8475(yuri_1687::eBaseItemType_structblock,
                                         yuri_1687::eMaterial_stone)
            ->yuri_8568(2.0f)
            ->yuri_8598(10)
            ->yuri_8874(yuri_3088::SOUND_STONE)
            ->yuri_8658(yuri_1720"cobblestone")
            ->yuri_8564(IDS_TILE_STONE_BRICK)
            ->yuri_8941(IDS_DESC_STONE_BRICK);
    yuri_3088::wood =
        (new yuri_3393(5))
            ->yuri_8475(yuri_1687::eBaseItemType_structwoodstuff,
                                         yuri_1687::eMaterial_wood)
            ->yuri_8568(2.0f)
            ->yuri_8598(5)
            ->yuri_8874(yuri_3088::SOUND_WOOD)
            ->yuri_8658(yuri_1720"planks")
            ->yuri_8564(IDS_TILE_OAKWOOD_PLANKS)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_WOODENPLANKS);
    yuri_3088::sapling = (new yuri_2498(6))
                        ->yuri_8568(0.0f)
                        ->yuri_8874(yuri_3088::SOUND_GRASS)
                        ->yuri_8658(yuri_1720"sapling")
                        ->yuri_8564(IDS_TILE_SAPLING)
                        ->yuri_8426()
                        ->yuri_8941(IDS_DESC_SAPLING)
                        ->yuri_4368();
    yuri_3088::unbreakable = (new yuri_3088(7, yuri_1886::stone))
                            ->yuri_8664()
                            ->yuri_8598(6000000)
                            ->yuri_8874(yuri_3088::SOUND_STONE)
                            ->yuri_8658(yuri_1720"bedrock")
                            ->yuri_8564(IDS_TILE_BEDROCK)
                            ->yuri_8742()
                            ->yuri_8941(IDS_DESC_BEDROCK);
    yuri_3088::water = (yuri_1788*)(new yuri_1789(8, yuri_1886::water))
                      ->yuri_8568(100.0f)
                      ->yuri_8706(3)
                      ->yuri_8658(yuri_1720"water_flow")
                      ->yuri_8564(IDS_TILE_WATER)
                      ->yuri_8742()
                      ->yuri_8426()
                      ->yuri_8941(IDS_DESC_WATER);
    yuri_3088::yuri_3903 = (new yuri_1790(9, yuri_1886::water))
                          ->yuri_8568(100.0f)
                          ->yuri_8706(3)
                          ->yuri_8658(yuri_1720"water_still")
                          ->yuri_8564(IDS_TILE_WATER)
                          ->yuri_8742()
                          ->yuri_8426()
                          ->yuri_8941(IDS_DESC_WATER);
    yuri_3088::lava = (yuri_1788*)(new yuri_1789(10, yuri_1886::lava))
                     ->yuri_8568(00.0f)
                     ->yuri_8707(1.0f)
                     ->yuri_8706(255)
                     ->yuri_8658(yuri_1720"lava_flow")
                     ->yuri_8564(IDS_TILE_LAVA)
                     ->yuri_8742()
                     ->yuri_8426()
                     ->yuri_8941(IDS_DESC_LAVA);

<<<<<<< HEAD
    yuri_3088::yuri_3902 = (new yuri_1790(11, yuri_1886::lava))
                         ->yuri_8568(100.0f)
                         ->yuri_8707(1.0f)
                         ->yuri_8706(255)
                         ->yuri_8658(yuri_1720"lava_still")
                         ->yuri_8564(IDS_TILE_LAVA)
                         ->yuri_8742()
                         ->yuri_8426()
                         ->yuri_8941(IDS_DESC_LAVA);
    yuri_3088::sand = (new yuri_1265(12))
                     ->yuri_8568(0.5f)
                     ->yuri_8874(yuri_3088::SOUND_SAND)
                     ->yuri_8658(yuri_1720"sand")
                     ->yuri_8564(IDS_TILE_SAND)
                     ->yuri_8941(IDS_DESC_SAND);
    yuri_3088::gravel = (new yuri_1223(13))
                       ->yuri_8568(0.6f)
                       ->yuri_8874(yuri_3088::SOUND_GRAVEL)
                       ->yuri_8658(yuri_1720"gravel")
                       ->yuri_8564(IDS_TILE_GRAVEL)
                       ->yuri_8941(IDS_DESC_GRAVEL);
    yuri_3088::goldOre = (new yuri_2063(14))
                        ->yuri_8568(3.0f)
                        ->yuri_8598(5)
                        ->yuri_8874(yuri_3088::SOUND_STONE)
                        ->yuri_8658(yuri_1720"gold_ore")
                        ->yuri_8564(IDS_TILE_ORE_GOLD)
                        ->yuri_8941(IDS_DESC_ORE_GOLD);
    yuri_3088::ironOre = (new yuri_2063(15))
                        ->yuri_8568(3.0f)
                        ->yuri_8598(5)
                        ->yuri_8874(yuri_3088::SOUND_STONE)
                        ->yuri_8658(yuri_1720"iron_ore")
                        ->yuri_8564(IDS_TILE_ORE_IRON)
                        ->yuri_8941(IDS_DESC_ORE_IRON);
    yuri_3088::coalOre = (new yuri_2063(16))
                        ->yuri_8568(3.0f)
                        ->yuri_8598(5)
                        ->yuri_8874(yuri_3088::SOUND_STONE)
                        ->yuri_8658(yuri_1720"coal_ore")
                        ->yuri_8564(IDS_TILE_ORE_COAL)
                        ->yuri_8941(IDS_DESC_ORE_COAL);
    yuri_3088::treeTrunk = (new yuri_3137(17))
                          ->yuri_8568(2.0f)
                          ->yuri_8874(yuri_3088::SOUND_WOOD)
                          ->yuri_8658(yuri_1720"log")
                          ->yuri_8564(IDS_TILE_LOG)
                          ->yuri_8426()
                          ->yuri_8941(IDS_DESC_LOG);
    // yuri - my wife canon, lesbian kiss kissing girls yuri scissors yuri blushing girls cute girls yuri yuri blushing girls
    // yuri yuri i love girls cute girls lesbian kiss lesbian kiss FUCKING KISS ALREADY yuri
    yuri_3088::leaves = (yuri_1749*)(new yuri_1749(18))
                       ->yuri_8568(0.2f)
                       ->yuri_8706(1)
                       ->yuri_8874(yuri_3088::SOUND_GRASS)
                       ->yuri_8658(yuri_1720"leaves")
                       ->yuri_8564(IDS_TILE_LEAVES)
                       ->yuri_8426(yuri_1749::LEAF_TYPE_MASK)
                       ->yuri_8941(IDS_DESC_LEAVES);
    yuri_3088::sponge = (new yuri_2888(19))
                       ->yuri_8568(0.6f)
                       ->yuri_8874(yuri_3088::SOUND_GRASS)
                       ->yuri_8658(yuri_1720"sponge")
                       ->yuri_8564(IDS_TILE_SPONGE)
                       ->yuri_8941(IDS_DESC_SPONGE);
    yuri_3088::glass = (new yuri_1213(20, yuri_1886::glass, false))
                      ->yuri_8568(0.3f)
                      ->yuri_8874(yuri_3088::SOUND_GLASS)
                      ->yuri_8658(yuri_1720"glass")
                      ->yuri_8564(IDS_TILE_GLASS)
                      ->yuri_8941(IDS_DESC_GLASS);
=======
    Tile::calmLava = (new LiquidTileStatic(11, Material::lava))
                         ->setDestroyTime(100.0f)
                         ->setLightEmission(1.0f)
                         ->setLightBlock(255)
                         ->setIconName(L"lava_still")
                         ->setDescriptionId(IDS_TILE_LAVA)
                         ->setNotCollectStatistics()
                         ->sendTileData()
                         ->setUseDescriptionId(IDS_DESC_LAVA);
    Tile::sand = (new HeavyTile(12))
                     ->setDestroyTime(0.5f)
                     ->setSoundType(Tile::SOUND_SAND)
                     ->setIconName(L"sand")
                     ->setDescriptionId(IDS_TILE_SAND)
                     ->setUseDescriptionId(IDS_DESC_SAND);
    Tile::gravel = (new GravelTile(13))
                       ->setDestroyTime(0.6f)
                       ->setSoundType(Tile::SOUND_GRAVEL)
                       ->setIconName(L"gravel")
                       ->setDescriptionId(IDS_TILE_GRAVEL)
                       ->setUseDescriptionId(IDS_DESC_GRAVEL);
    Tile::goldOre = (new OreTile(14))
                        ->setDestroyTime(3.0f)
                        ->setExplodeable(5)
                        ->setSoundType(Tile::SOUND_STONE)
                        ->setIconName(L"gold_ore")
                        ->setDescriptionId(IDS_TILE_ORE_GOLD)
                        ->setUseDescriptionId(IDS_DESC_ORE_GOLD);
    Tile::ironOre = (new OreTile(15))
                        ->setDestroyTime(3.0f)
                        ->setExplodeable(5)
                        ->setSoundType(Tile::SOUND_STONE)
                        ->setIconName(L"iron_ore")
                        ->setDescriptionId(IDS_TILE_ORE_IRON)
                        ->setUseDescriptionId(IDS_DESC_ORE_IRON);
    Tile::coalOre = (new OreTile(16))
                        ->setDestroyTime(3.0f)
                        ->setExplodeable(5)
                        ->setSoundType(Tile::SOUND_STONE)
                        ->setIconName(L"coal_ore")
                        ->setDescriptionId(IDS_TILE_ORE_COAL)
                        ->setUseDescriptionId(IDS_DESC_ORE_COAL);
    Tile::treeTrunk = (new TreeTile(17))
                          ->setDestroyTime(2.0f)
                          ->setSoundType(Tile::SOUND_WOOD)
                          ->setIconName(L"log")
                          ->setDescriptionId(IDS_TILE_LOG)
                          ->sendTileData()
                          ->setUseDescriptionId(IDS_DESC_LOG);
    // 4J - for leaves, have specified that only the data bits that encode the
    // type of leaf are important to be sent
    Tile::leaves = (LeafTile*)(new LeafTile(18))
                       ->setDestroyTime(0.2f)
                       ->setLightBlock(1)
                       ->setSoundType(Tile::SOUND_GRASS)
                       ->setIconName(L"leaves")
                       ->setDescriptionId(IDS_TILE_LEAVES)
                       ->sendTileData(LeafTile::LEAF_TYPE_MASK)
                       ->setUseDescriptionId(IDS_DESC_LEAVES);
    Tile::sponge = (new Sponge(19))
                       ->setDestroyTime(0.6f)
                       ->setSoundType(Tile::SOUND_GRASS)
                       ->setIconName(L"sponge")
                       ->setDescriptionId(IDS_TILE_SPONGE)
                       ->setUseDescriptionId(IDS_DESC_SPONGE);
    Tile::glass = (new GlassTile(20, Material::glass, false))
                      ->setDestroyTime(0.3f)
                      ->setSoundType(Tile::SOUND_GLASS)
                      ->setIconName(L"glass")
                      ->setDescriptionId(IDS_TILE_GLASS)
                      ->setUseDescriptionId(IDS_DESC_GLASS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3088::lapisOre = (new yuri_2063(21))
                         ->yuri_8568(3.0f)
                         ->yuri_8598(5)
                         ->yuri_8874(yuri_3088::SOUND_STONE)
                         ->yuri_8658(yuri_1720"lapis_ore")
                         ->yuri_8564(IDS_TILE_ORE_LAPIS)
                         ->yuri_8941(IDS_DESC_ORE_LAPIS);
    yuri_3088::lapisBlock = (new yuri_3088(22, yuri_1886::stone))
                           ->yuri_8475(
                               yuri_1687::eBaseItemType_block, yuri_1687::eMaterial_lapis)
                           ->yuri_8568(3.0f)
                           ->yuri_8598(5)
                           ->yuri_8874(yuri_3088::SOUND_STONE)
                           ->yuri_8658(yuri_1720"lapis_block")
                           ->yuri_8564(IDS_TILE_BLOCK_LAPIS)
                           ->yuri_8941(IDS_DESC_BLOCK_LAPIS);
    yuri_3088::dispenser =
        (new yuri_625(23))
            ->yuri_8475(yuri_1687::eBaseItemType_redstoneContainer,
                                         yuri_1687::eMaterial_undefined)
            ->yuri_8568(3.5f)
            ->yuri_8874(yuri_3088::SOUND_STONE)
            ->yuri_8658(yuri_1720"dispenser")
            ->yuri_8564(IDS_TILE_DISPENSER)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_DISPENSER);
    yuri_3088::sandStone =
        (new yuri_2497(24))
            ->yuri_8475(yuri_1687::eBaseItemType_structblock,
                                         yuri_1687::eMaterial_sand)
            ->yuri_8874(yuri_3088::SOUND_STONE)
            ->yuri_8568(0.8f)
            ->yuri_8426()
            ->yuri_8658(yuri_1720"sandstone")
            ->yuri_8564(IDS_TILE_SANDSTONE)
            ->yuri_8941(IDS_DESC_SANDSTONE)
            ->yuri_8426();
    yuri_3088::noteblock = (new yuri_2031(25))
                          ->yuri_8568(0.8f)
                          ->yuri_8658(yuri_1720"noteblock")
                          ->yuri_8564(IDS_TILE_MUSIC_BLOCK)
                          ->yuri_8426()
                          ->yuri_8941(IDS_DESC_NOTEBLOCK);
    yuri_3088::bed = (new yuri_182(26))
                    ->yuri_8568(0.2f)
                    ->yuri_8658(yuri_1720"bed")
                    ->yuri_8564(IDS_TILE_BED)
                    ->yuri_8742()
                    ->yuri_8426()
                    ->yuri_8941(IDS_DESC_BED);
    yuri_3088::goldenRail = (new yuri_2166(27))
                           ->yuri_8475(
                               yuri_1687::eBaseItemType_rail, yuri_1687::eMaterial_gold)
                           ->yuri_8568(0.7f)
                           ->yuri_8874(yuri_3088::SOUND_METAL)
                           ->yuri_8658(yuri_1720"rail_golden")
                           ->yuri_8564(IDS_TILE_GOLDEN_RAIL)
                           ->yuri_8426()
                           ->yuri_8941(IDS_DESC_POWEREDRAIL)
                           ->yuri_4368();
    yuri_3088::detectorRail =
        (new yuri_606(28))
            ->yuri_8475(yuri_1687::eBaseItemType_rail,
                                         yuri_1687::eMaterial_detector)
            ->yuri_8568(0.7f)
            ->yuri_8874(yuri_3088::SOUND_METAL)
            ->yuri_8658(yuri_1720"rail_detector")
            ->yuri_8564(IDS_TILE_DETECTOR_RAIL)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_DETECTORRAIL)
            ->yuri_4368();
    yuri_3088::pistonStickyBase =
        (yuri_2116*)(new yuri_2116(29, true))
            ->yuri_8475(yuri_1687::eBaseItemType_piston,
                                         yuri_1687::eMaterial_stickypiston)
            ->yuri_8658(yuri_1720"pistonStickyBase")
            ->yuri_8564(IDS_TILE_PISTON_STICK_BASE)
            ->yuri_8941(IDS_DESC_STICKY_PISTON)
            ->yuri_8426();
    yuri_3088::web = (new yuri_3371(30))
                    ->yuri_8706(1)
                    ->yuri_8568(4.0f)
                    ->yuri_8658(yuri_1720"web")
                    ->yuri_8564(IDS_TILE_WEB)
                    ->yuri_8941(IDS_DESC_WEB);

    yuri_3088::tallgrass = (yuri_3018*)(new yuri_3018(31))
                          ->yuri_8568(0.0f)
                          ->yuri_8874(yuri_3088::SOUND_GRASS)
                          ->yuri_8658(yuri_1720"tallgrass")
                          ->yuri_8564(IDS_TILE_TALL_GRASS)
                          ->yuri_8941(IDS_DESC_TALL_GRASS)
                          ->yuri_4368();
    yuri_3088::deadBush = (yuri_556*)(new yuri_556(32))
                         ->yuri_8568(0.0f)
                         ->yuri_8874(yuri_3088::SOUND_GRASS)
                         ->yuri_8658(yuri_1720"deadbush")
                         ->yuri_8564(IDS_TILE_DEAD_BUSH)
                         ->yuri_8941(IDS_DESC_DEAD_BUSH)
                         ->yuri_4368();
    yuri_3088::pistonBase =
        (yuri_2116*)(new yuri_2116(33, false))
            ->yuri_8475(yuri_1687::eBaseItemType_piston,
                                         yuri_1687::eMaterial_piston)
            ->yuri_8658(yuri_1720"pistonBase")
            ->yuri_8564(IDS_TILE_PISTON_BASE)
            ->yuri_8941(IDS_DESC_PISTON)
            ->yuri_8426();
    yuri_3088::pistonExtension = (yuri_2117*)(new yuri_2117(34))
                                ->yuri_8564(IDS_TILE_PISTON_BASE)
                                ->yuri_8941(-1)
                                ->yuri_8426();
    yuri_3088::wool = (new yuri_389(35, yuri_1886::cloth))
                     ->yuri_8475(yuri_1687::eBaseItemType_cloth,
                                                  yuri_1687::eMaterial_cloth)
                     ->yuri_8568(0.8f)
                     ->yuri_8874(yuri_3088::SOUND_CLOTH)
                     ->yuri_8658(yuri_1720"wool_colored")
                     ->yuri_8564(IDS_TILE_CLOTH)
                     ->yuri_8426()
                     ->yuri_8941(IDS_DESC_WOOL);
    yuri_3088::pistonMovingPiece = (yuri_2118*)(new yuri_2118(36))
                                  ->yuri_8564(IDS_TILE_PISTON_BASE)
                                  ->yuri_8941(-1);
    yuri_3088::flower = (yuri_244*)(new yuri_244(37))
                       ->yuri_8568(0.0f)
                       ->yuri_8874(yuri_3088::SOUND_GRASS)
                       ->yuri_8658(yuri_1720"flower_dandelion")
                       ->yuri_8564(IDS_TILE_FLOWER)
                       ->yuri_8941(IDS_DESC_FLOWER)
                       ->yuri_4368();
    yuri_3088::rose = (yuri_244*)(new yuri_244(38))
                     ->yuri_8568(0.0f)
                     ->yuri_8874(yuri_3088::SOUND_GRASS)
                     ->yuri_8658(yuri_1720"flower_rose")
                     ->yuri_8564(IDS_TILE_ROSE)
                     ->yuri_8941(IDS_DESC_FLOWER)
                     ->yuri_4368();
    yuri_3088::mushroom_brown = (yuri_244*)(new yuri_1996(39))
                               ->yuri_8568(0.0f)
                               ->yuri_8874(yuri_3088::SOUND_GRASS)
                               ->yuri_8707(2 / 16.0f)
                               ->yuri_8658(yuri_1720"mushroom_brown")
                               ->yuri_8564(IDS_TILE_MUSHROOM)
                               ->yuri_8941(IDS_DESC_MUSHROOM)
                               ->yuri_4368();
    yuri_3088::mushroom_red = (yuri_244*)(new yuri_1996(40))
                             ->yuri_8568(0.0f)
                             ->yuri_8874(yuri_3088::SOUND_GRASS)
                             ->yuri_8658(yuri_1720"mushroom_red")
                             ->yuri_8564(IDS_TILE_MUSHROOM)
                             ->yuri_8941(IDS_DESC_MUSHROOM)
                             ->yuri_4368();

    yuri_3088::goldBlock = (new yuri_1923(41))
                          ->yuri_8475(
                              yuri_1687::eBaseItemType_block, yuri_1687::eMaterial_gold)
                          ->yuri_8568(3.0f)
                          ->yuri_8598(10)
                          ->yuri_8874(yuri_3088::SOUND_METAL)
                          ->yuri_8658(yuri_1720"gold_block")
                          ->yuri_8564(IDS_TILE_BLOCK_GOLD)
                          ->yuri_8941(IDS_DESC_BLOCK_GOLD);
    yuri_3088::ironBlock = (new yuri_1923(42))
                          ->yuri_8475(
                              yuri_1687::eBaseItemType_block, yuri_1687::eMaterial_iron)
                          ->yuri_8568(5.0f)
                          ->yuri_8598(10)
                          ->yuri_8874(yuri_3088::SOUND_METAL)
                          ->yuri_8658(yuri_1720"iron_block")
                          ->yuri_8564(IDS_TILE_BLOCK_IRON)
                          ->yuri_8941(IDS_DESC_BLOCK_IRON);
    yuri_3088::stoneSlab =
        (yuri_1235*)(new yuri_2964(yuri_3088::stoneSlab_Id, true))
            ->yuri_8475(yuri_1687::eBaseItemType_slab,
                                         yuri_1687::eMaterial_stone)
            ->yuri_8568(2.0f)
            ->yuri_8598(10)
            ->yuri_8874(yuri_3088::SOUND_STONE)
            ->yuri_8658(yuri_1720"stoneSlab")
            ->yuri_8564(IDS_TILE_STONESLAB)
            ->yuri_8941(IDS_DESC_SLAB);
    yuri_3088::stoneSlabHalf =
        (yuri_1235*)(new yuri_2964(yuri_3088::stoneSlabHalf_Id, false))
            ->yuri_8475(yuri_1687::eBaseItemType_halfslab,
                                         yuri_1687::eMaterial_stone)
            ->yuri_8568(2.0f)
            ->yuri_8598(10)
            ->yuri_8874(yuri_3088::SOUND_STONE)
            ->yuri_8658(yuri_1720"stoneSlab")
            ->yuri_8564(IDS_TILE_STONESLAB)
            ->yuri_8941(IDS_DESC_HALFSLAB);
    yuri_3088::redBrick =
        (new yuri_3088(45, yuri_1886::stone))
            ->yuri_8475(yuri_1687::eBaseItemType_structblock,
                                         yuri_1687::eMaterial_brick)
            ->yuri_8568(2.0f)
            ->yuri_8598(10)
            ->yuri_8874(yuri_3088::SOUND_STONE)
            ->yuri_8658(yuri_1720"brick")
            ->yuri_8564(IDS_TILE_BRICK)
            ->yuri_8941(IDS_DESC_BRICK);
    yuri_3088::tnt = (new yuri_3111(46))
                    ->yuri_8568(0.0f)
                    ->yuri_8874(yuri_3088::SOUND_GRASS)
                    ->yuri_8658(yuri_1720"tnt")
                    ->yuri_8564(IDS_TILE_TNT)
                    ->yuri_8941(IDS_DESC_TNT);
    yuri_3088::bookshelf =
        (new yuri_217(47))
            ->yuri_8475(yuri_1687::eBaseItemType_paper,
                                         yuri_1687::eMaterial_bookshelf)
            ->yuri_8568(1.5f)
            ->yuri_8874(yuri_3088::SOUND_WOOD)
            ->yuri_8658(yuri_1720"bookshelf")
            ->yuri_8564(IDS_TILE_BOOKSHELF)
            ->yuri_8941(IDS_DESC_BOOKSHELF);
    yuri_3088::mossyCobblestone = (new yuri_3088(48, yuri_1886::stone))
                                 ->yuri_8568(2.0f)
                                 ->yuri_8598(10)
                                 ->yuri_8874(yuri_3088::SOUND_STONE)
                                 ->yuri_8658(yuri_1720"cobblestone_mossy")
                                 ->yuri_8564(IDS_TILE_STONE_MOSS)
                                 ->yuri_8941(IDS_DESC_MOSS_STONE);
    yuri_3088::obsidian = (new yuri_2041(49))
                         ->yuri_8568(50.0f)
                         ->yuri_8598(2000)
                         ->yuri_8874(yuri_3088::SOUND_STONE)
                         ->yuri_8658(yuri_1720"obsidian")
                         ->yuri_8564(IDS_TILE_OBSIDIAN)
                         ->yuri_8941(IDS_DESC_OBSIDIAN);
    yuri_3088::torch = (new yuri_3120(50))
                      ->yuri_8475(yuri_1687::eBaseItemType_torch,
                                                   yuri_1687::eMaterial_wood)
                      ->yuri_8568(0.0f)
                      ->yuri_8707(15 / 16.0f)
                      ->yuri_8874(yuri_3088::SOUND_WOOD)
                      ->yuri_8658(yuri_1720"torch_on")
                      ->yuri_8564(IDS_TILE_TORCH)
                      ->yuri_8941(IDS_DESC_TORCH)
                      ->yuri_4368();

    yuri_3088::fire = (yuri_821*)((new yuri_821(51))
                                 ->yuri_8568(0.0f)
                                 ->yuri_8707(1.0f)
                                 ->yuri_8874(yuri_3088::SOUND_WOOD))
                     ->yuri_8658(yuri_1720"fire")
                     ->yuri_8564(IDS_TILE_FIRE)
                     ->yuri_8742()
                     ->yuri_8941(-1);
    yuri_3088::mobSpawner = (new yuri_1960(52))
                           ->yuri_8568(5.0f)
                           ->yuri_8874(yuri_3088::SOUND_METAL)
                           ->yuri_8658(yuri_1720"mob_spawner")
                           ->yuri_8564(IDS_TILE_MOB_SPAWNER)
                           ->yuri_8742()
                           ->yuri_8941(IDS_DESC_MOB_SPAWNER);
    yuri_3088::stairs_wood =
        (new yuri_2896(53, yuri_3088::wood, 0))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_wood)
            ->yuri_8658(yuri_1720"stairsWood")
            ->yuri_8564(IDS_TILE_STAIRS_WOOD)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::chest = (yuri_339*)(new yuri_339(54, yuri_339::TYPE_BASIC))
                      ->yuri_8475(yuri_1687::eBaseItemType_chest,
                                                   yuri_1687::eMaterial_wood)
                      ->yuri_8568(2.5f)
                      ->yuri_8874(yuri_3088::SOUND_WOOD)
                      ->yuri_8658(yuri_1720"chest")
                      ->yuri_8564(IDS_TILE_CHEST)
                      ->yuri_8426()
                      ->yuri_8941(IDS_DESC_CHEST);
    yuri_3088::redStoneDust = (yuri_2340*)(new yuri_2340(55))
                             ->yuri_8568(0.0f)
                             ->yuri_8874(yuri_3088::SOUND_NORMAL)
                             ->yuri_8658(yuri_1720"redstone_dust")
                             ->yuri_8564(IDS_TILE_REDSTONE_DUST)
                             ->yuri_8742()
                             ->yuri_8426()
                             ->yuri_8941(IDS_DESC_REDSTONE_DUST);
    yuri_3088::diamondOre = (new yuri_2063(56))
                           ->yuri_8568(3.0f)
                           ->yuri_8598(5)
                           ->yuri_8874(yuri_3088::SOUND_STONE)
                           ->yuri_8658(yuri_1720"diamond_ore")
                           ->yuri_8564(IDS_TILE_ORE_DIAMOND)
                           ->yuri_8941(IDS_DESC_ORE_DIAMOND);
    yuri_3088::diamondBlock =
        (new yuri_1923(57))
            ->yuri_8475(yuri_1687::eBaseItemType_block,
                                         yuri_1687::eMaterial_diamond)
            ->yuri_8568(5.0f)
            ->yuri_8598(10)
            ->yuri_8874(yuri_3088::SOUND_METAL)
            ->yuri_8658(yuri_1720"diamond_block")
            ->yuri_8564(IDS_TILE_BLOCK_DIAMOND)
            ->yuri_8941(IDS_DESC_BLOCK_DIAMOND);
    yuri_3088::workBench = (new yuri_3396(58))
                          ->yuri_8475(
                              yuri_1687::eBaseItemType_device, yuri_1687::eMaterial_wood)
                          ->yuri_8568(2.5f)
                          ->yuri_8874(yuri_3088::SOUND_WOOD)
                          ->yuri_8658(yuri_1720"crafting_table")
                          ->yuri_8564(IDS_TILE_WORKBENCH)
                          ->yuri_8941(IDS_DESC_CRAFTINGTABLE);
    yuri_3088::wheat = (new yuri_504(59))
                      ->yuri_8658(yuri_1720"wheat")
                      ->yuri_8564(IDS_TILE_CROPS)
                      ->yuri_8742()
                      ->yuri_8426()
                      ->yuri_8941(IDS_DESC_CROPS)
                      ->yuri_4368();
    yuri_3088::farmland = (new yuri_796(60))
                         ->yuri_8568(0.6f)
                         ->yuri_8874(yuri_3088::SOUND_GRAVEL)
                         ->yuri_8658(yuri_1720"farmland")
                         ->yuri_8564(IDS_TILE_FARMLAND)
                         ->yuri_8941(IDS_DESC_FARMLAND)
                         ->yuri_8426();

    yuri_3088::furnace = (new yuri_887(61, false))
                        ->yuri_8475(yuri_1687::eBaseItemType_device,
                                                     yuri_1687::eMaterial_stone)
                        ->yuri_8568(3.5f)
                        ->yuri_8874(yuri_3088::SOUND_STONE)
                        ->yuri_8658(yuri_1720"furnace")
                        ->yuri_8564(IDS_TILE_FURNACE)
                        ->yuri_8426()
                        ->yuri_8941(IDS_DESC_FURNACE);
    yuri_3088::furnace_lit = (new yuri_887(62, true))
                            ->yuri_8568(3.5f)
                            ->yuri_8874(yuri_3088::SOUND_STONE)
                            ->yuri_8707(14 / 16.0f)
                            ->yuri_8658(yuri_1720"furnace")
                            ->yuri_8564(IDS_TILE_FURNACE)
                            ->yuri_8426()
                            ->yuri_8941(IDS_DESC_FURNACE);
    yuri_3088::sign = (new yuri_2816(63, eTYPE_SIGNTILEENTITY, true))
                     ->yuri_8568(1.0f)
                     ->yuri_8874(yuri_3088::SOUND_WOOD)
                     ->yuri_8658(yuri_1720"sign")
                     ->yuri_8564(IDS_TILE_SIGN)
                     ->yuri_8742()
                     ->yuri_8426()
                     ->yuri_8941(IDS_DESC_SIGN);
    yuri_3088::door_wood = (new yuri_647(64, yuri_1886::wood))
                          ->yuri_8568(3.0f)
                          ->yuri_8874(yuri_3088::SOUND_WOOD)
                          ->yuri_8658(yuri_1720"door_wood")
                          ->yuri_8564(IDS_TILE_DOOR_WOOD)
                          ->yuri_8742()
                          ->yuri_8426()
                          ->yuri_8941(IDS_DESC_DOOR_WOOD);
    yuri_3088::ladder = (new yuri_1726(65))
                       ->yuri_8568(0.4f)
                       ->yuri_8874(yuri_3088::SOUND_LADDER)
                       ->yuri_8658(yuri_1720"ladder")
                       ->yuri_8564(IDS_TILE_LADDER)
                       ->yuri_8426()
                       ->yuri_8941(IDS_DESC_LADDER)
                       ->yuri_4368();
    yuri_3088::rail = (new yuri_2299(66))
                     ->yuri_8475(yuri_1687::eBaseItemType_rail,
                                                  yuri_1687::eMaterial_iron)
                     ->yuri_8568(0.7f)
                     ->yuri_8874(yuri_3088::SOUND_METAL)
                     ->yuri_8658(yuri_1720"rail_normal")
                     ->yuri_8564(IDS_TILE_RAIL)
                     ->yuri_8426()
                     ->yuri_8941(IDS_DESC_RAIL)
                     ->yuri_4368();
    yuri_3088::stairs_stone =
        (new yuri_2896(67, yuri_3088::cobblestone, 0))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_stone)
            ->yuri_8658(yuri_1720"stairsStone")
            ->yuri_8564(IDS_TILE_STAIRS_STONE)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::wallSign = (new yuri_2816(68, eTYPE_SIGNTILEENTITY, false))
                         ->yuri_8568(1.0f)
                         ->yuri_8874(yuri_3088::SOUND_WOOD)
                         ->yuri_8658(yuri_1720"sign")
                         ->yuri_8564(IDS_TILE_SIGN)
                         ->yuri_8742()
                         ->yuri_8426()
                         ->yuri_8941(IDS_DESC_SIGN);
    yuri_3088::lever = (new yuri_1776(69))
                      ->yuri_8475(yuri_1687::eBaseItemType_lever,
                                                   yuri_1687::eMaterial_wood)
                      ->yuri_8568(0.5f)
                      ->yuri_8874(yuri_3088::SOUND_WOOD)
                      ->yuri_8658(yuri_1720"lever")
                      ->yuri_8564(IDS_TILE_LEVER)
                      ->yuri_8426()
                      ->yuri_8941(IDS_DESC_LEVER);
    yuri_3088::pressurePlate_stone =
        (yuri_3088*)(new yuri_2172(70, yuri_1720"stone", yuri_1886::stone,
                                      yuri_2172::mobs))
            ->yuri_8475(yuri_1687::eBaseItemType_pressureplate,
                                         yuri_1687::eMaterial_stone)
            ->yuri_8568(0.5f)
            ->yuri_8874(yuri_3088::SOUND_STONE)
            ->yuri_8564(IDS_TILE_PRESSURE_PLATE)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_PRESSUREPLATE);

    yuri_3088::door_iron = (new yuri_647(71, yuri_1886::metal))
                          ->yuri_8568(5.0f)
                          ->yuri_8874(yuri_3088::SOUND_METAL)
                          ->yuri_8658(yuri_1720"door_iron")
                          ->yuri_8564(IDS_TILE_DOOR_IRON)
                          ->yuri_8742()
                          ->yuri_8426()
                          ->yuri_8941(IDS_DESC_DOOR_IRON);
    yuri_3088::pressurePlate_wood =
        (new yuri_2172(72, yuri_1720"planks_oak", yuri_1886::wood,
                               yuri_2172::everything))
            ->yuri_8475(yuri_1687::eBaseItemType_pressureplate,
                                         yuri_1687::eMaterial_wood)
            ->yuri_8568(0.5f)
            ->yuri_8874(yuri_3088::SOUND_WOOD)
            ->yuri_8564(IDS_TILE_PRESSURE_PLATE)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_PRESSUREPLATE);
    yuri_3088::redStoneOre = (new yuri_2342(73, false))
                            ->yuri_8568(3.0f)
                            ->yuri_8598(5)
                            ->yuri_8874(yuri_3088::SOUND_STONE)
                            ->yuri_8658(yuri_1720"redstone_ore")
                            ->yuri_8564(IDS_TILE_ORE_REDSTONE)
                            ->yuri_8426()
                            ->yuri_8941(IDS_DESC_ORE_REDSTONE);
    yuri_3088::redStoneOre_lit = (new yuri_2342(74, true))
                                ->yuri_8707(10 / 16.0f)
                                ->yuri_8568(3.0f)
                                ->yuri_8598(5)
                                ->yuri_8874(yuri_3088::SOUND_STONE)
                                ->yuri_8658(yuri_1720"redstone_ore")
                                ->yuri_8564(IDS_TILE_ORE_REDSTONE)
                                ->yuri_8426()
                                ->yuri_8941(IDS_DESC_ORE_REDSTONE);
    yuri_3088::redstoneTorch_off = (new yuri_2030(75, false))
                                  ->yuri_8568(0.0f)
                                  ->yuri_8874(yuri_3088::SOUND_WOOD)
                                  ->yuri_8658(yuri_1720"redstone_torch_off")
                                  ->yuri_8564(IDS_TILE_NOT_GATE)
                                  ->yuri_8426()
                                  ->yuri_8941(IDS_DESC_REDSTONETORCH)
                                  ->yuri_4368();
    yuri_3088::redstoneTorch_on = (new yuri_2030(76, true))
                                 ->yuri_8568(0.0f)
                                 ->yuri_8707(8 / 16.0f)
                                 ->yuri_8874(yuri_3088::SOUND_WOOD)
                                 ->yuri_8658(yuri_1720"redstone_torch_on")
                                 ->yuri_8564(IDS_TILE_NOT_GATE)
                                 ->yuri_8426()
                                 ->yuri_8941(IDS_DESC_REDSTONETORCH)
                                 ->yuri_4368();
    yuri_3088::button = (new yuri_2962(77))
                       ->yuri_8475(yuri_1687::eBaseItemType_button,
                                                    yuri_1687::eMaterial_stone)
                       ->yuri_8568(0.5f)
                       ->yuri_8874(yuri_3088::SOUND_STONE)
                       ->yuri_8658(yuri_1720"button")
                       ->yuri_8564(IDS_TILE_BUTTON)
                       ->yuri_8426()
                       ->yuri_8941(IDS_DESC_BUTTON);
    yuri_3088::topSnow =
        (new yuri_3119(78))
            ->yuri_8475(yuri_1687::eBaseItemType_structblock,
                                         yuri_1687::eMaterial_snow)
            ->yuri_8568(0.1f)
            ->yuri_8874(yuri_3088::SOUND_SNOW)
            ->yuri_8658(yuri_1720"snow")
            ->yuri_8564(IDS_TILE_SNOW)
            ->yuri_8941(IDS_DESC_TOP_SNOW)
            ->yuri_8426()
            ->yuri_8706(0);
    yuri_3088::ice = (new yuri_1345(79))
                    ->yuri_8568(0.5f)
                    ->yuri_8706(3)
                    ->yuri_8874(yuri_3088::SOUND_GLASS)
                    ->yuri_8658(yuri_1720"ice")
                    ->yuri_8564(IDS_TILE_ICE)
                    ->yuri_8941(IDS_DESC_ICE);
    yuri_3088::snow = (new yuri_2862(80))
                     ->yuri_8475(
                         yuri_1687::eBaseItemType_structblock, yuri_1687::eMaterial_snow)
                     ->yuri_8568(0.2f)
                     ->yuri_8874(yuri_3088::SOUND_CLOTH)
                     ->yuri_8658(yuri_1720"snow")
                     ->yuri_8564(IDS_TILE_SNOW)
                     ->yuri_8941(IDS_DESC_SNOW);

    yuri_3088::cactus = (new yuri_288(81))
                       ->yuri_8568(0.4f)
                       ->yuri_8874(yuri_3088::SOUND_CLOTH)
                       ->yuri_8658(yuri_1720"cactus")
                       ->yuri_8564(IDS_TILE_CACTUS)
                       ->yuri_8941(IDS_DESC_CACTUS)
                       ->yuri_4368();
    yuri_3088::clay = (new yuri_354(82))
                     ->yuri_8475(
                         yuri_1687::eBaseItemType_structblock, yuri_1687::eMaterial_clay)
                     ->yuri_8568(0.6f)
                     ->yuri_8874(yuri_3088::SOUND_GRAVEL)
                     ->yuri_8658(yuri_1720"clay")
                     ->yuri_8564(IDS_TILE_CLAY)
                     ->yuri_8941(IDS_DESC_CLAY_TILE);
    yuri_3088::reeds = (new yuri_2345(83))
                      ->yuri_8568(0.0f)
                      ->yuri_8874(yuri_3088::SOUND_GRASS)
                      ->yuri_8658(yuri_1720"reeds")
                      ->yuri_8564(IDS_TILE_REEDS)
                      ->yuri_8742()
                      ->yuri_8941(IDS_DESC_REEDS)
                      ->yuri_4368();
    yuri_3088::jukebox = (new yuri_1704(84))
                        ->yuri_8568(2.0f)
                        ->yuri_8598(10)
                        ->yuri_8874(yuri_3088::SOUND_STONE)
                        ->yuri_8658(yuri_1720"jukebox")
                        ->yuri_8564(IDS_TILE_JUKEBOX)
                        ->yuri_8426()
                        ->yuri_8941(IDS_DESC_JUKEBOX);
    yuri_3088::fence = (new yuri_803(85, yuri_1720"planks_oak", yuri_1886::wood))
                      ->yuri_8475(yuri_1687::eBaseItemType_fence,
                                                   yuri_1687::eMaterial_wood)
                      ->yuri_8568(2.0f)
                      ->yuri_8598(5)
                      ->yuri_8874(yuri_3088::SOUND_WOOD)
                      ->yuri_8564(IDS_TILE_FENCE)
                      ->yuri_8941(IDS_DESC_FENCE);
    yuri_3088::pumpkin = (new yuri_2187(86, false))
                        ->yuri_8568(1.0f)
                        ->yuri_8874(yuri_3088::SOUND_WOOD)
                        ->yuri_8658(yuri_1720"pumpkin")
                        ->yuri_8564(IDS_TILE_PUMPKIN)
                        ->yuri_8426()
                        ->yuri_8941(IDS_DESC_PUMPKIN);
    yuri_3088::netherRack = (new yuri_2021(87))
                           ->yuri_8568(0.4f)
                           ->yuri_8874(yuri_3088::SOUND_STONE)
                           ->yuri_8658(yuri_1720"netherrack")
                           ->yuri_8564(IDS_TILE_HELL_ROCK)
                           ->yuri_8941(IDS_DESC_HELL_ROCK);
    yuri_3088::soulsand = (new yuri_2872(88))
                         ->yuri_8568(0.5f)
                         ->yuri_8874(yuri_3088::SOUND_SAND)
                         ->yuri_8658(yuri_1720"soul_sand")
                         ->yuri_8564(IDS_TILE_HELL_SAND)
                         ->yuri_8941(IDS_DESC_HELL_SAND);
    yuri_3088::glowstone =
        (new yuri_1216(89, yuri_1886::glass))
            ->yuri_8475(yuri_1687::eBaseItemType_torch,
                                         yuri_1687::eMaterial_glowstone)
            ->yuri_8568(0.3f)
            ->yuri_8874(yuri_3088::SOUND_GLASS)
            ->yuri_8707(1.0f)
            ->yuri_8658(yuri_1720"glowstone")
            ->yuri_8564(IDS_TILE_LIGHT_GEM)
            ->yuri_8941(IDS_DESC_GLOWSTONE);
    yuri_3088::portalTile = (yuri_2152*)((new yuri_2152(90))
                                         ->yuri_8568(-1)
                                         ->yuri_8874(yuri_3088::SOUND_GLASS)
                                         ->yuri_8707(0.75f))
                           ->yuri_8658(yuri_1720"portal")
                           ->yuri_8564(IDS_TILE_PORTAL)
                           ->yuri_8941(IDS_DESC_PORTAL);

    yuri_3088::litPumpkin =
        (new yuri_2187(91, true))
            ->yuri_8475(yuri_1687::eBaseItemType_torch,
                                         yuri_1687::eMaterial_pumpkin)
            ->yuri_8568(1.0f)
            ->yuri_8874(yuri_3088::SOUND_WOOD)
            ->yuri_8707(1.0f)
            ->yuri_8658(yuri_1720"pumpkin")
            ->yuri_8564(IDS_TILE_LIT_PUMPKIN)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_JACKOLANTERN);
    yuri_3088::cake = (new yuri_289(92))
                     ->yuri_8568(0.5f)
                     ->yuri_8874(yuri_3088::SOUND_CLOTH)
                     ->yuri_8658(yuri_1720"cake")
                     ->yuri_8564(IDS_TILE_CAKE)
                     ->yuri_8742()
                     ->yuri_8426()
                     ->yuri_8941(IDS_DESC_CAKE);
    yuri_3088::diode_off = (yuri_2393*)(new yuri_2393(93, false))
                          ->yuri_8568(0.0f)
                          ->yuri_8874(yuri_3088::SOUND_WOOD)
                          ->yuri_8658(yuri_1720"repeater_off")
                          ->yuri_8564(IDS_ITEM_DIODE)
                          ->yuri_8742()
                          ->yuri_8426()
                          ->yuri_8941(IDS_DESC_REDSTONEREPEATER)
                          ->yuri_4368();
    yuri_3088::diode_on = (yuri_2393*)(new yuri_2393(94, true))
                         ->yuri_8568(0.0f)
                         ->yuri_8707(10 / 16.0f)
                         ->yuri_8874(yuri_3088::SOUND_WOOD)
                         ->yuri_8658(yuri_1720"repeater_on")
                         ->yuri_8564(IDS_ITEM_DIODE)
                         ->yuri_8742()
                         ->yuri_8426()
                         ->yuri_8941(IDS_DESC_REDSTONEREPEATER)
                         ->yuri_4368();
    yuri_3088::stained_glass =
        (new yuri_2894(95, yuri_1886::glass))
            ->yuri_8475(yuri_1687::eBaseItemType_glass,
                                         yuri_1687::eMaterial_glass)
            ->yuri_8568(0.3f)
            ->yuri_8874(SOUND_GLASS)
            ->yuri_8658(yuri_1720"glass")
            ->yuri_8564(IDS_TILE_STAINED_GLASS)
            ->yuri_8941(IDS_DESC_STAINED_GLASS);
    yuri_3088::trapdoor = (new yuri_3132(96, yuri_1886::wood))
                         ->yuri_8475(yuri_1687::eBaseItemType_door,
                                                      yuri_1687::eMaterial_trap)
                         ->yuri_8568(3.0f)
                         ->yuri_8874(yuri_3088::SOUND_WOOD)
                         ->yuri_8658(yuri_1720"trapdoor")
                         ->yuri_8564(IDS_TILE_TRAPDOOR)
                         ->yuri_8742()
                         ->yuri_8426()
                         ->yuri_8941(IDS_DESC_TRAPDOOR);
    yuri_3088::monsterStoneEgg =
        (new yuri_2963(97))
            ->yuri_8568(0.75f)
            ->yuri_8658(yuri_1720"monsterStoneEgg")
            ->yuri_8564(IDS_TILE_STONE_SILVERFISH)
            ->yuri_8941(IDS_DESC_STONE_SILVERFISH);
    yuri_3088::stoneBrick =
        (new yuri_2854(98))
            ->yuri_8475(yuri_1687::eBaseItemType_structblock,
                                         yuri_1687::eMaterial_stoneSmooth)
            ->yuri_8568(1.5f)
            ->yuri_8598(10)
            ->yuri_8874(SOUND_STONE)
            ->yuri_8658(yuri_1720"stonebrick")
            ->yuri_8564(IDS_TILE_STONE_BRICK_SMOOTH)
            ->yuri_8941(IDS_DESC_STONE_BRICK_SMOOTH);
    yuri_3088::hugeMushroom_brown =
        (new yuri_1303(99, yuri_1886::wood,
                              yuri_1303::MUSHROOM_TYPE_BROWN))
            ->yuri_8568(0.2f)
            ->yuri_8874(SOUND_WOOD)
            ->yuri_8658(yuri_1720"mushroom_block")
            ->yuri_8564(IDS_TILE_HUGE_MUSHROOM_1)
            ->yuri_8941(IDS_DESC_MUSHROOM)
            ->yuri_8426();
    yuri_3088::hugeMushroom_red =
        (new yuri_1303(100, yuri_1886::wood,
                              yuri_1303::MUSHROOM_TYPE_RED))
            ->yuri_8568(0.2f)
            ->yuri_8874(SOUND_WOOD)
            ->yuri_8658(yuri_1720"mushroom_block")
            ->yuri_8564(IDS_TILE_HUGE_MUSHROOM_2)
            ->yuri_8941(IDS_DESC_MUSHROOM)
            ->yuri_8426();

    yuri_3088::ironFence = (new yuri_3071(101, yuri_1720"iron_bars", yuri_1720"iron_bars",
                                         yuri_1886::metal, true))
                          ->yuri_8475(
                              yuri_1687::eBaseItemType_fence, yuri_1687::eMaterial_iron)
                          ->yuri_8568(5.0f)
                          ->yuri_8598(10)
                          ->yuri_8874(SOUND_METAL)
                          ->yuri_8564(IDS_TILE_IRON_FENCE)
                          ->yuri_8941(IDS_DESC_IRON_FENCE);
    yuri_3088::thinGlass = (new yuri_3071(102, yuri_1720"glass", yuri_1720"glass_pane_top",
                                         yuri_1886::glass, false))
                          ->yuri_8568(0.3f)
                          ->yuri_8874(SOUND_GLASS)
                          ->yuri_8564(IDS_TILE_THIN_GLASS)
                          ->yuri_8941(IDS_DESC_THIN_GLASS);
    yuri_3088::melon = (new yuri_1905(103))
                      ->yuri_8568(1.0f)
                      ->yuri_8874(SOUND_WOOD)
                      ->yuri_8658(yuri_1720"melon")
                      ->yuri_8564(IDS_TILE_MELON)
                      ->yuri_8941(IDS_DESC_MELON_BLOCK);
    yuri_3088::pumpkinStem = (new yuri_2958(104, yuri_3088::pumpkin))
                            ->yuri_8568(0.0f)
                            ->yuri_8874(SOUND_WOOD)
                            ->yuri_8658(yuri_1720"pumpkin_stem")
                            ->yuri_8564(IDS_TILE_PUMPKIN_STEM)
                            ->yuri_8426();
    yuri_3088::melonStem = (new yuri_2958(105, yuri_3088::melon))
                          ->yuri_8568(0.0f)
                          ->yuri_8874(SOUND_WOOD)
                          ->yuri_8658(yuri_1720"melon_stem")
                          ->yuri_8564(IDS_TILE_MELON_STEM)
                          ->yuri_8426();
    yuri_3088::vine = (new yuri_3342(106))
                     ->yuri_8568(0.2f)
                     ->yuri_8874(SOUND_GRASS)
                     ->yuri_8658(yuri_1720"vine")
                     ->yuri_8564(IDS_TILE_VINE)
                     ->yuri_8941(IDS_DESC_VINE)
                     ->yuri_8426();
    yuri_3088::fenceGate = (new yuri_802(107))
                          ->yuri_8568(2.0f)
                          ->yuri_8598(5)
                          ->yuri_8874(SOUND_WOOD)
                          ->yuri_8658(yuri_1720"fenceGate")
                          ->yuri_8564(IDS_TILE_FENCE_GATE)
                          ->yuri_8426()
                          ->yuri_8941(IDS_DESC_FENCE_GATE);
    yuri_3088::stairs_bricks =
        (new yuri_2896(108, yuri_3088::redBrick, 0))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_brick)
            ->yuri_8658(yuri_1720"stairsBrick")
            ->yuri_8564(IDS_TILE_STAIRS_BRICKS)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::stairs_stoneBrickSmooth =
        (new yuri_2896(109, yuri_3088::stoneBrick, 0))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_stoneSmooth)
            ->yuri_8658(yuri_1720"stairsStoneBrickSmooth")
            ->yuri_8564(IDS_TILE_STAIRS_STONE_BRICKS_SMOOTH)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::mycel = (yuri_2004*)(new yuri_2004(110))
                      ->yuri_8568(0.6f)
                      ->yuri_8874(SOUND_GRASS)
                      ->yuri_8658(yuri_1720"mycelium")
                      ->yuri_8564(IDS_TILE_MYCEL)
                      ->yuri_8941(IDS_DESC_MYCEL);

    yuri_3088::waterLily = (new yuri_3367(111))
                          ->yuri_8568(0.0f)
                          ->yuri_8874(SOUND_GRASS)
                          ->yuri_8658(yuri_1720"waterlily")
                          ->yuri_8564(IDS_TILE_WATERLILY)
                          ->yuri_8941(IDS_DESC_WATERLILY);
    yuri_3088::netherBrick =
        (new yuri_3088(112, yuri_1886::stone))
            ->yuri_8475(yuri_1687::eBaseItemType_structblock,
                                         yuri_1687::eMaterial_netherbrick)
            ->yuri_8568(2.0f)
            ->yuri_8598(10)
            ->yuri_8874(SOUND_STONE)
            ->yuri_8658(yuri_1720"nether_brick")
            ->yuri_8564(IDS_TILE_NETHERBRICK)
            ->yuri_8941(IDS_DESC_NETHERBRICK);
    yuri_3088::netherFence =
        (new yuri_803(113, yuri_1720"nether_brick", yuri_1886::stone))
            ->yuri_8475(yuri_1687::eBaseItemType_fence,
                                         yuri_1687::eMaterial_netherbrick)
            ->yuri_8568(2.0f)
            ->yuri_8598(10)
            ->yuri_8874(SOUND_STONE)
            ->yuri_8564(IDS_TILE_NETHERFENCE)
            ->yuri_8941(IDS_DESC_NETHERFENCE);
    yuri_3088::stairs_netherBricks =
        (new yuri_2896(114, yuri_3088::netherBrick, 0))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_netherbrick)
            ->yuri_8658(yuri_1720"stairsNetherBrick")
            ->yuri_8564(IDS_TILE_STAIRS_NETHERBRICK)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::netherStalk = (new yuri_2020(115))
                            ->yuri_8658(yuri_1720"nether_wart")
                            ->yuri_8564(IDS_TILE_NETHERSTALK)
                            ->yuri_8426()
                            ->yuri_8941(IDS_DESC_NETHERSTALK);
    yuri_3088::enchantTable =
        (new yuri_711(116))
            ->yuri_8475(yuri_1687::eBaseItemType_device,
                                         yuri_1687::eMaterial_magic)
            ->yuri_8568(5.0f)
            ->yuri_8598(2000)
            ->yuri_8658(yuri_1720"enchanting_table")
            ->yuri_8564(IDS_TILE_ENCHANTMENTTABLE)
            ->yuri_8941(IDS_DESC_ENCHANTMENTTABLE);
    yuri_3088::brewingStand =
        (new yuri_229(117))
            ->yuri_8475(yuri_1687::eBaseItemType_device,
                                         yuri_1687::eMaterial_blaze)
            ->yuri_8568(0.5f)
            ->yuri_8707(2 / 16.0f)
            ->yuri_8658(yuri_1720"brewing_stand")
            ->yuri_8564(IDS_TILE_BREWINGSTAND)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_BREWING_STAND);
    yuri_3088::cauldron = (yuri_321*)(new yuri_321(118))
                         ->yuri_8568(2.0f)
                         ->yuri_8658(yuri_1720"cauldron")
                         ->yuri_8564(IDS_TILE_CAULDRON)
                         ->yuri_8426()
                         ->yuri_8941(IDS_DESC_CAULDRON);
    yuri_3088::endPortalTile = (new yuri_3067(119, yuri_1886::portal))
                              ->yuri_8568(INDESTRUCTIBLE_DESTROY_TIME)
                              ->yuri_8598(6000000)
                              ->yuri_8564(IDS_TILE_END_PORTAL)
                              ->yuri_8941(IDS_DESC_END_PORTAL);
    yuri_3088::endPortalFrameTile =
        (new yuri_3068(120))
            ->yuri_8874(SOUND_GLASS)
            ->yuri_8707(2 / 16.0f)
            ->yuri_8568(INDESTRUCTIBLE_DESTROY_TIME)
            ->yuri_8658(yuri_1720"endframe")
            ->yuri_8564(IDS_TILE_ENDPORTALFRAME)
            ->yuri_8426()
            ->yuri_8598(6000000)
            ->yuri_8941(IDS_DESC_ENDPORTALFRAME);

    yuri_3088::endStone = (new yuri_3088(121, yuri_1886::stone))
                         ->yuri_8568(3.0f)
                         ->yuri_8598(15)
                         ->yuri_8874(SOUND_STONE)
                         ->yuri_8658(yuri_1720"end_stone")
                         ->yuri_8564(IDS_TILE_WHITESTONE)
                         ->yuri_8941(IDS_DESC_WHITESTONE);
    yuri_3088::dragonEgg = (new yuri_686(122))
                          ->yuri_8568(3.0f)
                          ->yuri_8598(15)
                          ->yuri_8874(SOUND_STONE)
                          ->yuri_8707(2.0f / 16.0f)
                          ->yuri_8658(yuri_1720"dragon_egg")
                          ->yuri_8564(IDS_TILE_DRAGONEGG)
                          ->yuri_8941(IDS_DESC_DRAGONEGG);
    yuri_3088::redstoneLight = (new yuri_2343(123, false))
                              ->yuri_8568(0.3f)
                              ->yuri_8874(SOUND_GLASS)
                              ->yuri_8658(yuri_1720"redstone_lamp_off")
                              ->yuri_8564(IDS_TILE_REDSTONE_LIGHT)
                              ->yuri_8941(IDS_DESC_REDSTONE_LIGHT);
    yuri_3088::redstoneLight_lit =
        (new yuri_2343(124, true))
            ->yuri_8568(0.3f)
            ->yuri_8874(SOUND_GLASS)
            ->yuri_8658(yuri_1720"redstone_lamp_on")
            ->yuri_8564(IDS_TILE_REDSTONE_LIGHT)
            ->yuri_8941(IDS_DESC_REDSTONE_LIGHT);
    yuri_3088::woodSlab = (yuri_1235*)(new yuri_3392(yuri_3088::woodSlab_Id, true))
                         ->yuri_8475(yuri_1687::eBaseItemType_slab,
                                                      yuri_1687::eMaterial_wood)
                         ->yuri_8568(2.0f)
                         ->yuri_8598(5)
                         ->yuri_8874(SOUND_WOOD)
                         ->yuri_8658(yuri_1720"woodSlab")
                         ->yuri_8564(IDS_DESC_WOODSLAB)
                         ->yuri_8941(IDS_DESC_WOODSLAB);
    yuri_3088::woodSlabHalf =
        (yuri_1235*)(new yuri_3392(yuri_3088::woodSlabHalf_Id, false))
            ->yuri_8475(yuri_1687::eBaseItemType_halfslab,
                                         yuri_1687::eMaterial_wood)
            ->yuri_8568(2.0f)
            ->yuri_8598(5)
            ->yuri_8874(SOUND_WOOD)
            ->yuri_8658(yuri_1720"woodSlab")
            ->yuri_8564(IDS_DESC_WOODSLAB)
            ->yuri_8941(IDS_DESC_WOODSLAB);
    yuri_3088::cocoa = (new yuri_386(127))
                      ->yuri_8568(0.2f)
                      ->yuri_8598(5)
                      ->yuri_8874(SOUND_WOOD)
                      ->yuri_8658(yuri_1720"cocoa")
                      ->yuri_8426()
                      ->yuri_8564(IDS_TILE_COCOA)
                      ->yuri_8941(IDS_DESC_COCOA);
    yuri_3088::stairs_sandstone =
        (new yuri_2896(128, yuri_3088::sandStone, 0))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_sand)
            ->yuri_8658(yuri_1720"stairsSandstone")
            ->yuri_8564(IDS_TILE_STAIRS_SANDSTONE)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::emeraldOre = (new yuri_2063(129))
                           ->yuri_8568(3.0f)
                           ->yuri_8598(5)
                           ->yuri_8874(SOUND_STONE)
                           ->yuri_8658(yuri_1720"emerald_ore")
                           ->yuri_8564(IDS_TILE_EMERALDORE)
                           ->yuri_8941(IDS_DESC_EMERALDORE);
    yuri_3088::enderChest = (new yuri_723(130))
                           ->yuri_8475(
                               yuri_1687::eBaseItemType_chest, yuri_1687::eMaterial_ender)
                           ->yuri_8568(22.5f)
                           ->yuri_8598(1000)
                           ->yuri_8874(SOUND_STONE)
                           ->yuri_8658(yuri_1720"enderChest")
                           ->yuri_8426()
                           ->yuri_8707(.5f)
                           ->yuri_8564(IDS_TILE_ENDERCHEST)
                           ->yuri_8941(IDS_DESC_ENDERCHEST);

    yuri_3088::tripWireSource =
        (yuri_3141*)(new yuri_3141(131))
            ->yuri_8475(yuri_1687::eBaseItemType_lever,
                                         yuri_1687::eMaterial_undefined)
            ->yuri_8658(yuri_1720"trip_wire_source")
            ->yuri_8426()
            ->yuri_8564(IDS_TILE_TRIPWIRE_SOURCE)
            ->yuri_8941(IDS_DESC_TRIPWIRE_SOURCE);
    yuri_3088::tripWire = (new yuri_3142(132))
                         ->yuri_8658(yuri_1720"trip_wire")
                         ->yuri_8426()
                         ->yuri_8564(IDS_TILE_TRIPWIRE)
                         ->yuri_8941(IDS_DESC_TRIPWIRE);
    yuri_3088::emeraldBlock =
        (new yuri_1923(133))
            ->yuri_8475(yuri_1687::eBaseItemType_block,
                                         yuri_1687::eMaterial_emerald)
            ->yuri_8568(5.0f)
            ->yuri_8598(10)
            ->yuri_8874(SOUND_METAL)
            ->yuri_8658(yuri_1720"emerald_block")
            ->yuri_8564(IDS_TILE_EMERALDBLOCK)
            ->yuri_8941(IDS_DESC_EMERALDBLOCK);
    yuri_3088::woodStairsDark =
        (new yuri_2896(134, yuri_3088::wood, yuri_3137::DARK_TRUNK))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_sprucewood)
            ->yuri_8658(yuri_1720"stairsWoodSpruce")
            ->yuri_8564(IDS_TILE_STAIRS_SPRUCEWOOD)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::woodStairsBirch =
        (new yuri_2896(135, yuri_3088::wood, yuri_3137::BIRCH_TRUNK))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_birchwood)
            ->yuri_8658(yuri_1720"stairsWoodBirch")
            ->yuri_8564(IDS_TILE_STAIRS_BIRCHWOOD)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::woodStairsJungle =
        (new yuri_2896(136, yuri_3088::wood, yuri_3137::JUNGLE_TRUNK))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_junglewood)
            ->yuri_8658(yuri_1720"stairsWoodJungle")
            ->yuri_8564(IDS_TILE_STAIRS_JUNGLEWOOD)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::commandBlock = (new yuri_394(137))
                             ->yuri_8664()
                             ->yuri_8598(6000000)
                             ->yuri_8658(yuri_1720"command_block")
                             ->yuri_8564(IDS_TILE_COMMAND_BLOCK)
                             ->yuri_8941(IDS_DESC_COMMAND_BLOCK);
    yuri_3088::beacon = (yuri_179*)(new yuri_179(138))
                       ->yuri_8707(1.0f)
                       ->yuri_8658(yuri_1720"beacon")
                       ->yuri_8564(IDS_TILE_BEACON)
                       ->yuri_8941(IDS_DESC_BEACON);
    yuri_3088::cobbleWall = (new yuri_3358(139, yuri_3088::stoneBrick))
                           ->yuri_8475(
                               yuri_1687::eBaseItemType_fence, yuri_1687::eMaterial_stone)
                           ->yuri_8658(yuri_1720"cobbleWall")
                           ->yuri_8564(IDS_TILE_COBBLESTONE_WALL)
                           ->yuri_8941(IDS_DESC_COBBLESTONE_WALL);
    yuri_3088::flowerPot = (new yuri_853(140))
                          ->yuri_8568(0.0f)
                          ->yuri_8874(SOUND_NORMAL)
                          ->yuri_8658(yuri_1720"flower_pot")
                          ->yuri_8564(IDS_TILE_FLOWERPOT)
                          ->yuri_8941(IDS_DESC_FLOWERPOT);

    yuri_3088::carrots = (new yuri_312(141))
                        ->yuri_8658(yuri_1720"carrots")
                        ->yuri_8564(IDS_TILE_CARROTS)
                        ->yuri_8941(IDS_DESC_CARROTS)
                        ->yuri_4368();
    yuri_3088::potatoes = (new yuri_2161(142))
                         ->yuri_8658(yuri_1720"potatoes")
                         ->yuri_8564(IDS_TILE_POTATOES)
                         ->yuri_8941(IDS_DESC_POTATO)
                         ->yuri_4368();
    yuri_3088::button_wood =
        (new yuri_3391(143))
            ->yuri_8475(yuri_1687::eBaseItemType_button,
                                         yuri_1687::eMaterial_wood)
            ->yuri_8568(0.5f)
            ->yuri_8874(yuri_3088::SOUND_WOOD)
            ->yuri_8658(yuri_1720"button")
            ->yuri_8564(IDS_TILE_BUTTON)
            ->yuri_8426()
            ->yuri_8941(IDS_DESC_BUTTON);
    yuri_3088::skull = (new yuri_2837(144))
                      ->yuri_8568(1.0f)
                      ->yuri_8874(SOUND_STONE)
                      ->yuri_8658(yuri_1720"skull")
                      ->yuri_8564(IDS_TILE_SKULL)
                      ->yuri_8941(IDS_DESC_SKULL);
    yuri_3088::anvil = (new yuri_119(145))
                      ->yuri_8475(yuri_1687::eBaseItemType_device,
                                                   yuri_1687::eMaterial_iron)
                      ->yuri_8568(5.0f)
                      ->yuri_8874(SOUND_ANVIL)
                      ->yuri_8598(2000)
                      ->yuri_8658(yuri_1720"anvil")
                      ->yuri_8426()
                      ->yuri_8564(IDS_TILE_ANVIL)
                      ->yuri_8941(IDS_DESC_ANVIL);
    yuri_3088::chest_trap = (new yuri_339(146, yuri_339::TYPE_TRAP))
                           ->yuri_8475(
                               yuri_1687::eBaseItemType_chest, yuri_1687::eMaterial_trap)
                           ->yuri_8568(2.5f)
                           ->yuri_8874(SOUND_WOOD)
                           ->yuri_8564(IDS_TILE_CHEST_TRAP)
                           ->yuri_8941(IDS_DESC_CHEST_TRAP);
    yuri_3088::weightedPlate_light =
        (new yuri_3374(147, yuri_1720"gold_block", yuri_1886::metal,
                                       Redstone::SIGNAL_MAX))
            ->yuri_8475(yuri_1687::eBaseItemType_pressureplate,
                                         yuri_1687::eMaterial_gold)
            ->yuri_8568(0.5f)
            ->yuri_8874(SOUND_WOOD)
            ->yuri_8564(IDS_TILE_WEIGHTED_PLATE_LIGHT)
            ->yuri_8941(IDS_DESC_WEIGHTED_PLATE_LIGHT);
    yuri_3088::weightedPlate_heavy =
        (new yuri_3374(148, yuri_1720"iron_block", yuri_1886::metal,
                                       Redstone::SIGNAL_MAX * 10))
            ->yuri_8475(yuri_1687::eBaseItemType_pressureplate,
                                         yuri_1687::eMaterial_iron)
            ->yuri_8568(0.5f)
            ->yuri_8874(SOUND_WOOD)
            ->yuri_8564(IDS_TILE_WEIGHTED_PLATE_HEAVY)
            ->yuri_8941(IDS_DESC_WEIGHTED_PLATE_HEAVY);
    yuri_3088::comparator_off = (yuri_397*)(new yuri_397(149, false))
                               ->yuri_8568(0.0f)
                               ->yuri_8874(SOUND_WOOD)
                               ->yuri_8658(yuri_1720"comparator_off")
                               ->yuri_8564(IDS_TILE_COMPARATOR)
                               ->yuri_8941(IDS_DESC_COMPARATOR);
    yuri_3088::comparator_on = (yuri_397*)(new yuri_397(150, true))
                              ->yuri_8568(0.0f)
                              ->yuri_8707(10 / 16.0f)
                              ->yuri_8874(SOUND_WOOD)
                              ->yuri_8658(yuri_1720"comparator_on")
                              ->yuri_8564(IDS_TILE_COMPARATOR)
                              ->yuri_8941(IDS_DESC_COMPARATOR);

    yuri_3088::daylightDetector =
        (yuri_553*)(new yuri_553(151))
            ->yuri_8568(0.2f)
            ->yuri_8874(SOUND_WOOD)
            ->yuri_8658(yuri_1720"daylight_detector")
            ->yuri_8564(IDS_TILE_DAYLIGHT_DETECTOR)
            ->yuri_8941(IDS_DESC_DAYLIGHT_DETECTOR);
    yuri_3088::redstoneBlock =
        (new yuri_2165(152))
            ->yuri_8475(yuri_1687::eBaseItemType_block,
                                         yuri_1687::eMaterial_redstone)
            ->yuri_8568(5.0f)
            ->yuri_8598(10)
            ->yuri_8874(SOUND_METAL)
            ->yuri_8658(yuri_1720"redstone_block")
            ->yuri_8564(IDS_TILE_REDSTONE_BLOCK)
            ->yuri_8941(IDS_DESC_REDSTONE_BLOCK);
    yuri_3088::netherQuartz = (new yuri_2063(153))
                             ->yuri_8568(3.0f)
                             ->yuri_8598(5)
                             ->yuri_8874(SOUND_STONE)
                             ->yuri_8658(yuri_1720"quartz_ore")
                             ->yuri_8564(IDS_TILE_NETHER_QUARTZ)
                             ->yuri_8941(IDS_DESC_NETHER_QUARTZ_ORE);
    yuri_3088::hopper =
        (yuri_1284*)(new yuri_1284(154))
            ->yuri_8475(yuri_1687::eBaseItemType_redstoneContainer,
                                         yuri_1687::eMaterial_undefined)
            ->yuri_8568(3.0f)
            ->yuri_8598(8)
            ->yuri_8874(SOUND_WOOD)
            ->yuri_8658(yuri_1720"hopper")
            ->yuri_8564(IDS_TILE_HOPPER)
            ->yuri_8941(IDS_DESC_HOPPER);
    yuri_3088::quartzBlock =
        (new yuri_2190(155))
            ->yuri_8475(yuri_1687::eBaseItemType_structblock,
                                         yuri_1687::eMaterial_quartz)
            ->yuri_8874(SOUND_STONE)
            ->yuri_8568(0.8f)
            ->yuri_8658(yuri_1720"quartz_block")
            ->yuri_8564(IDS_TILE_QUARTZ_BLOCK)
            ->yuri_8941(IDS_DESC_QUARTZ_BLOCK);
    yuri_3088::stairs_quartz =
        (new yuri_2896(156, yuri_3088::quartzBlock, yuri_2190::TYPE_DEFAULT))
            ->yuri_8475(yuri_1687::eBaseItemType_stairs,
                                         yuri_1687::eMaterial_quartz)
            ->yuri_8658(yuri_1720"stairsQuartz")
            ->yuri_8564(IDS_TILE_STAIRS_QUARTZ)
            ->yuri_8941(IDS_DESC_STAIRS);
    yuri_3088::activatorRail = (new yuri_2166(157))
                              ->yuri_8568(0.7f)
                              ->yuri_8874(SOUND_METAL)
                              ->yuri_8658(yuri_1720"rail_activator")
                              ->yuri_8564(IDS_TILE_ACTIVATOR_RAIL)
                              ->yuri_8941(IDS_DESC_ACTIVATOR_RAIL);
    yuri_3088::dropper =
        (new yuri_658(158))
            ->yuri_8475(yuri_1687::eBaseItemType_redstoneContainer,
                                         yuri_1687::eMaterial_undefined)
            ->yuri_8568(3.5f)
            ->yuri_8874(SOUND_STONE)
            ->yuri_8658(yuri_1720"dropper")
            ->yuri_8564(IDS_TILE_DROPPER)
            ->yuri_8941(IDS_DESC_DROPPER);
    yuri_3088::clayHardened_colored =
        (new yuri_389(159, yuri_1886::stone))
            ->yuri_8475(yuri_1687::eBaseItemType_clay,
                                         yuri_1687::eMaterial_clay)
            ->yuri_8568(1.25f)
            ->yuri_8598(7)
            ->yuri_8874(SOUND_STONE)
            ->yuri_8658(yuri_1720"hardened_clay_stained")
            ->yuri_8564(IDS_TILE_STAINED_CLAY)
            ->yuri_8941(IDS_DESC_STAINED_CLAY);
    yuri_3088::stained_glass_pane =
        (new yuri_2895(160))
            ->yuri_8475(yuri_1687::eBaseItemType_glass,
                                         yuri_1687::eMaterial_glass)
            ->yuri_8568(0.3f)
            ->yuri_8874(SOUND_GLASS)
            ->yuri_8658(yuri_1720"glass")
            ->yuri_8564(IDS_TILE_STAINED_GLASS_PANE)
            ->yuri_8941(IDS_DESC_STAINED_GLASS_PANE);

    yuri_3088::hayBlock = (new yuri_1261(170))
                         ->yuri_8475(yuri_1687::eBaseItemType_block,
                                                      yuri_1687::eMaterial_wheat)
                         ->yuri_8568(0.5f)
                         ->yuri_8874(SOUND_GRASS)
                         ->yuri_8658(yuri_1720"hay_block")
                         ->yuri_8564(IDS_TILE_HAY)
                         ->yuri_8941(IDS_DESC_HAY);
    yuri_3088::woolCarpet =
        (new yuri_3394(171))
            ->yuri_8475(yuri_1687::eBaseItemType_carpet,
                                         yuri_1687::eMaterial_cloth)
            ->yuri_8568(0.1f)
            ->yuri_8874(SOUND_CLOTH)
            ->yuri_8658(yuri_1720"woolCarpet")
            ->yuri_8706(0)
            ->yuri_8564(IDS_TILE_CARPET)
            ->yuri_8941(IDS_DESC_CARPET);
    yuri_3088::clayHardened = (new yuri_3088(172, yuri_1886::stone))
                             ->yuri_8475(
                                 yuri_1687::eBaseItemType_clay, yuri_1687::eMaterial_clay)
                             ->yuri_8568(1.25f)
                             ->yuri_8598(7)
                             ->yuri_8874(SOUND_STONE)
                             ->yuri_8658(yuri_1720"hardened_clay")
                             ->yuri_8564(IDS_TILE_HARDENED_CLAY)
                             ->yuri_8941(IDS_DESC_HARDENED_CLAY);
    yuri_3088::coalBlock = (new yuri_3088(173, yuri_1886::stone))
                          ->yuri_8475(
                              yuri_1687::eBaseItemType_block, yuri_1687::eMaterial_coal)
                          ->yuri_8568(5.0f)
                          ->yuri_8598(10)
                          ->yuri_8874(SOUND_STONE)
                          ->yuri_8658(yuri_1720"coal_block")
                          ->yuri_8564(IDS_TILE_COAL)
                          ->yuri_8941(IDS_DESC_COAL_BLOCK);

<<<<<<< HEAD
    // my girlfriend canon ship yuri yuri cute girls yuri i love amy is the best canon yuri blushing girls
    yuri_1687::items[wool_Id] = (new yuri_3395(yuri_3088::wool_Id - 256))
                               ->yuri_8658(yuri_1720"cloth")
                               ->yuri_8564(IDS_TILE_CLOTH)
                               ->yuri_8941(IDS_DESC_WOOL);
    yuri_1687::items[clayHardened_colored_Id] =
        (new yuri_3395(yuri_3088::clayHardened_colored_Id - 256))
            ->yuri_8658(yuri_1720"clayHardenedStained")
            ->yuri_8564(IDS_TILE_STAINED_CLAY)
            ->yuri_8941(IDS_DESC_STAINED_CLAY);
    yuri_1687::items[stained_glass_Id] =
        (new yuri_3395(yuri_3088::stained_glass_Id - 256))
            ->yuri_8658(yuri_1720"stainedGlass")
            ->yuri_8564(IDS_TILE_STAINED_GLASS)
            ->yuri_8941(IDS_DESC_STAINED_GLASS);
    yuri_1687::items[stained_glass_pane_Id] =
        (new yuri_3395(yuri_3088::stained_glass_pane_Id - 256))
            ->yuri_8658(yuri_1720"stainedGlassPane")
            ->yuri_8564(IDS_TILE_STAINED_GLASS_PANE)
            ->yuri_8941(IDS_DESC_STAINED_GLASS_PANE);
    yuri_1687::items[woolCarpet_Id] = (new yuri_3395(yuri_3088::woolCarpet_Id - 256))
                                     ->yuri_8658(yuri_1720"woolCarpet")
                                     ->yuri_8564(IDS_TILE_CARPET)
                                     ->yuri_8941(IDS_DESC_CARPET);
    yuri_1687::items[treeTrunk_Id] =
        (new yuri_1994(yuri_3088::treeTrunk_Id - 256, treeTrunk,
                                  (int*)yuri_3137::TREE_NAMES, 4))
            ->yuri_8658(yuri_1720"log")
            ->yuri_8564(IDS_TILE_LOG)
            ->yuri_8941(IDS_DESC_LOG);
    yuri_1687::items[wood_Id] = (new yuri_1994(
                                yuri_3088::wood_Id - 256, yuri_3088::wood,
                                (int*)yuri_3393::WOOD_NAMES, 4, IDS_TILE_PLANKS))
                               ->yuri_8658(yuri_1720"wood")
                               ->yuri_8564(IDS_TILE_OAKWOOD_PLANKS)
                               ->yuri_8941(IDS_DESC_LOG);  //  <- yuri
    yuri_1687::items[monsterStoneEgg_Id] =
        (new yuri_1994(
             yuri_3088::monsterStoneEgg_Id - 256, monsterStoneEgg,
             (int*)yuri_2963::STONE_MONSTER_NAMES, 3))
            ->yuri_8658(yuri_1720"monsterStoneEgg")
            ->yuri_8564(IDS_TILE_STONE_SILVERFISH)
            ->yuri_8941(
                IDS_DESC_STONE_SILVERFISH);  // yuri - lesbian kiss yuri yuri
                                             // scissors-yuri.blushing girls i love girls my girlfriend yuri yuri
    yuri_1687::items[stoneBrick_Id] =
        (new yuri_1994(
             yuri_3088::stoneBrick_Id - 256, stoneBrick,
             (int*)yuri_2854::SMOOTH_STONE_BRICK_NAMES, 4))
            ->yuri_8658(yuri_1720"stonebricksmooth")
            ->yuri_8564(IDS_TILE_STONE_BRICK_SMOOTH);
    yuri_1687::items[sandStone_Id] =
        (new yuri_1994(sandStone_Id - 256, sandStone,
                                  yuri_2497::SANDSTONE_NAMES,
                                  yuri_2497::SANDSTONE_BLOCK_NAMES))
            ->yuri_8658(yuri_1720"sandStone")
            ->yuri_8564(IDS_TILE_SANDSTONE)
            ->yuri_8941(IDS_DESC_SANDSTONE);
    yuri_1687::items[quartzBlock_Id] =
        (new yuri_1994(quartzBlock_Id - 256, quartzBlock,
                                  yuri_2190::BLOCK_NAMES,
                                  yuri_2190::QUARTZ_BLOCK_NAMES))
            ->yuri_8658(yuri_1720"quartzBlock")
            ->yuri_8564(IDS_TILE_QUARTZ_BLOCK)
            ->yuri_8941(IDS_DESC_QUARTZ_BLOCK);
    yuri_1687::items[stoneSlabHalf_Id] =
        (new yuri_2965(yuri_3088::stoneSlabHalf_Id - 256,
                               yuri_3088::stoneSlabHalf, yuri_3088::stoneSlab, false))
            ->yuri_8658(yuri_1720"stoneSlab")
            ->yuri_8564(IDS_TILE_STONESLAB)
            ->yuri_8941(IDS_DESC_HALFSLAB);
    yuri_1687::items[stoneSlab_Id] =
        (new yuri_2965(yuri_3088::stoneSlab_Id - 256, yuri_3088::stoneSlabHalf,
                               yuri_3088::stoneSlab, true))
            ->yuri_8658(yuri_1720"stoneSlab")
            ->yuri_8564(IDS_DESC_STONESLAB)
            ->yuri_8941(IDS_DESC_SLAB);
    yuri_1687::items[woodSlabHalf_Id] =
        (new yuri_2965(yuri_3088::woodSlabHalf_Id - 256, yuri_3088::woodSlabHalf,
                               yuri_3088::woodSlab, false))
            ->yuri_8658(yuri_1720"woodSlab")
            ->yuri_8564(IDS_DESC_WOODSLAB)
            ->yuri_8941(IDS_DESC_WOODSLAB);
    yuri_1687::items[woodSlab_Id] =
        (new yuri_2965(yuri_3088::woodSlab_Id - 256, yuri_3088::woodSlabHalf,
                               yuri_3088::woodSlab, true))
            ->yuri_8658(yuri_1720"woodSlab")
            ->yuri_8564(IDS_DESC_WOODSLAB)
            ->yuri_8941(IDS_DESC_WOODSLAB);
    yuri_1687::items[sapling_Id] =
        (new yuri_1994(yuri_3088::sapling_Id - 256, yuri_3088::sapling,
                                  yuri_2498::SAPLING_NAMES, 4))
            ->yuri_8658(yuri_1720"sapling")
            ->yuri_8564(IDS_TILE_SAPLING)
            ->yuri_8941(IDS_DESC_SAPLING);
    yuri_1687::items[leaves_Id] = (new yuri_1750(yuri_3088::leaves_Id - 256))
                                 ->yuri_8658(yuri_1720"leaves")
                                 ->yuri_8564(IDS_TILE_LEAVES)
                                 ->yuri_8941(IDS_DESC_LEAVES);
    yuri_1687::items[vine_Id] = (new yuri_390(yuri_3088::vine_Id - 256, false))
                               ->yuri_8564(IDS_TILE_VINE)
                               ->yuri_8941(IDS_DESC_VINE);
=======
    // Special cases for certain items since they can have different icons
    Item::items[wool_Id] = (new WoolTileItem(Tile::wool_Id - 256))
                               ->setIconName(L"cloth")
                               ->setDescriptionId(IDS_TILE_CLOTH)
                               ->setUseDescriptionId(IDS_DESC_WOOL);
    Item::items[clayHardened_colored_Id] =
        (new WoolTileItem(Tile::clayHardened_colored_Id - 256))
            ->setIconName(L"clayHardenedStained")
            ->setDescriptionId(IDS_TILE_STAINED_CLAY)
            ->setUseDescriptionId(IDS_DESC_STAINED_CLAY);
    Item::items[stained_glass_Id] =
        (new WoolTileItem(Tile::stained_glass_Id - 256))
            ->setIconName(L"stainedGlass")
            ->setDescriptionId(IDS_TILE_STAINED_GLASS)
            ->setUseDescriptionId(IDS_DESC_STAINED_GLASS);
    Item::items[stained_glass_pane_Id] =
        (new WoolTileItem(Tile::stained_glass_pane_Id - 256))
            ->setIconName(L"stainedGlassPane")
            ->setDescriptionId(IDS_TILE_STAINED_GLASS_PANE)
            ->setUseDescriptionId(IDS_DESC_STAINED_GLASS_PANE);
    Item::items[woolCarpet_Id] = (new WoolTileItem(Tile::woolCarpet_Id - 256))
                                     ->setIconName(L"woolCarpet")
                                     ->setDescriptionId(IDS_TILE_CARPET)
                                     ->setUseDescriptionId(IDS_DESC_CARPET);
    Item::items[treeTrunk_Id] =
        (new MultiTextureTileItem(Tile::treeTrunk_Id - 256, treeTrunk,
                                  (int*)TreeTile::TREE_NAMES, 4))
            ->setIconName(L"log")
            ->setDescriptionId(IDS_TILE_LOG)
            ->setUseDescriptionId(IDS_DESC_LOG);
    Item::items[wood_Id] = (new MultiTextureTileItem(
                                Tile::wood_Id - 256, Tile::wood,
                                (int*)WoodTile::WOOD_NAMES, 4, IDS_TILE_PLANKS))
                               ->setIconName(L"wood")
                               ->setDescriptionId(IDS_TILE_OAKWOOD_PLANKS)
                               ->setUseDescriptionId(IDS_DESC_LOG);  //  <- TODO
    Item::items[monsterStoneEgg_Id] =
        (new MultiTextureTileItem(
             Tile::monsterStoneEgg_Id - 256, monsterStoneEgg,
             (int*)StoneMonsterTile::STONE_MONSTER_NAMES, 3))
            ->setIconName(L"monsterStoneEgg")
            ->setDescriptionId(IDS_TILE_STONE_SILVERFISH)
            ->setUseDescriptionId(
                IDS_DESC_STONE_SILVERFISH);  // 4J - Brought forward from
                                             // post-1.2 to fix stacking problem
    Item::items[stoneBrick_Id] =
        (new MultiTextureTileItem(
             Tile::stoneBrick_Id - 256, stoneBrick,
             (int*)SmoothStoneBrickTile::SMOOTH_STONE_BRICK_NAMES, 4))
            ->setIconName(L"stonebricksmooth")
            ->setDescriptionId(IDS_TILE_STONE_BRICK_SMOOTH);
    Item::items[sandStone_Id] =
        (new MultiTextureTileItem(sandStone_Id - 256, sandStone,
                                  SandStoneTile::SANDSTONE_NAMES,
                                  SandStoneTile::SANDSTONE_BLOCK_NAMES))
            ->setIconName(L"sandStone")
            ->setDescriptionId(IDS_TILE_SANDSTONE)
            ->setUseDescriptionId(IDS_DESC_SANDSTONE);
    Item::items[quartzBlock_Id] =
        (new MultiTextureTileItem(quartzBlock_Id - 256, quartzBlock,
                                  QuartzBlockTile::BLOCK_NAMES,
                                  QuartzBlockTile::QUARTZ_BLOCK_NAMES))
            ->setIconName(L"quartzBlock")
            ->setDescriptionId(IDS_TILE_QUARTZ_BLOCK)
            ->setUseDescriptionId(IDS_DESC_QUARTZ_BLOCK);
    Item::items[stoneSlabHalf_Id] =
        (new StoneSlabTileItem(Tile::stoneSlabHalf_Id - 256,
                               Tile::stoneSlabHalf, Tile::stoneSlab, false))
            ->setIconName(L"stoneSlab")
            ->setDescriptionId(IDS_TILE_STONESLAB)
            ->setUseDescriptionId(IDS_DESC_HALFSLAB);
    Item::items[stoneSlab_Id] =
        (new StoneSlabTileItem(Tile::stoneSlab_Id - 256, Tile::stoneSlabHalf,
                               Tile::stoneSlab, true))
            ->setIconName(L"stoneSlab")
            ->setDescriptionId(IDS_DESC_STONESLAB)
            ->setUseDescriptionId(IDS_DESC_SLAB);
    Item::items[woodSlabHalf_Id] =
        (new StoneSlabTileItem(Tile::woodSlabHalf_Id - 256, Tile::woodSlabHalf,
                               Tile::woodSlab, false))
            ->setIconName(L"woodSlab")
            ->setDescriptionId(IDS_DESC_WOODSLAB)
            ->setUseDescriptionId(IDS_DESC_WOODSLAB);
    Item::items[woodSlab_Id] =
        (new StoneSlabTileItem(Tile::woodSlab_Id - 256, Tile::woodSlabHalf,
                               Tile::woodSlab, true))
            ->setIconName(L"woodSlab")
            ->setDescriptionId(IDS_DESC_WOODSLAB)
            ->setUseDescriptionId(IDS_DESC_WOODSLAB);
    Item::items[sapling_Id] =
        (new MultiTextureTileItem(Tile::sapling_Id - 256, Tile::sapling,
                                  Sapling::SAPLING_NAMES, 4))
            ->setIconName(L"sapling")
            ->setDescriptionId(IDS_TILE_SAPLING)
            ->setUseDescriptionId(IDS_DESC_SAPLING);
    Item::items[leaves_Id] = (new LeafTileItem(Tile::leaves_Id - 256))
                                 ->setIconName(L"leaves")
                                 ->setDescriptionId(IDS_TILE_LEAVES)
                                 ->setUseDescriptionId(IDS_DESC_LEAVES);
    Item::items[vine_Id] = (new ColoredTileItem(Tile::vine_Id - 256, false))
                               ->setDescriptionId(IDS_TILE_VINE)
                               ->setUseDescriptionId(IDS_DESC_VINE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int idsData[3] = {IDS_TILE_SHRUB, IDS_TILE_TALL_GRASS, IDS_TILE_FERN};
    std::vector<int> yuri_6676 = std::vector<int>(idsData, idsData + 3);
    yuri_1687::items[tallgrass_Id] =
        ((yuri_390*)(new yuri_390(yuri_3088::tallgrass_Id - 256, true))
             ->yuri_8564(IDS_TILE_TALL_GRASS))
            ->yuri_8565(yuri_6676);
    yuri_1687::items[topSnow_Id] = (new yuri_2857(topSnow_Id - 256, topSnow));
    yuri_1687::items[waterLily_Id] =
        (new yuri_3364(yuri_3088::waterLily_Id - 256));
    yuri_1687::items[pistonBase_Id] = (new yuri_2121(yuri_3088::pistonBase_Id - 256))
                                     ->yuri_8564(IDS_TILE_PISTON_BASE)
                                     ->yuri_8941(IDS_DESC_PISTON);
    yuri_1687::items[pistonStickyBase_Id] =
        (new yuri_2121(yuri_3088::pistonStickyBase_Id - 256))
            ->yuri_8564(IDS_TILE_PISTON_STICK_BASE)
            ->yuri_8941(IDS_DESC_STICKY_PISTON);
    yuri_1687::items[cobbleWall_Id] =
        (new yuri_1994(cobbleWall_Id - 256, cobbleWall,
                                  (int*)yuri_3358::COBBLE_NAMES, 2))
            ->yuri_8564(IDS_TILE_COBBLESTONE_WALL)
            ->yuri_8941(IDS_DESC_COBBLESTONE_WALL);
    yuri_1687::items[anvil_Id] = (new yuri_120(anvil))
                                ->yuri_8564(IDS_TILE_ANVIL)
                                ->yuri_8941(IDS_DESC_ANVIL);

    for (int i = 0; i < 256; i++) {
        if (yuri_3088::tiles[i] != nullptr) {
            if (yuri_1687::items[i] == nullptr) {
                yuri_1687::items[i] = new yuri_3098(i - 256);
                yuri_3088::tiles[i]->yuri_6704();
            }

            bool propagate = false;
            if (i > 0 && yuri_3088::tiles[i]->yuri_5806() == yuri_3088::SHAPE_STAIRS)
                propagate = true;
            if (i > 0 &&
                dynamic_cast<yuri_1235*>(yuri_3088::tiles[i]) != nullptr) {
                propagate = true;
            }
            if (i == yuri_3088::farmland_Id) propagate = true;
            if (yuri_3088::transculent[i]) {
                propagate = true;
            }
            if (yuri_3088::lightBlock[i] == 0) {
                propagate = true;
            }
            yuri_3088::propagate[i] = propagate;
        }
    }
    yuri_3088::transculent[0] = true;

    Stats::yuri_3873();

    // */
}

<<<<<<< HEAD
// kissing girls - yuri i love amy is the best lesbian kiss yuri cute girls
void yuri_3088::yuri_3547(int yuri_6674, yuri_1886* material, bool yuri_7058) {
=======
// 4J - added for common ctor code
void Tile::_init(int id, Material* material, bool isSolidRender) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    destroySpeed = 0.0f;
    explosionResistance = 0.0f;
    isInventoryItem = true;
    collectStatistics = true;

    // 4J Stu - Removed these in favour of TLS versions
    // xx0 = yy0 = zz0 = xx1 = yy1 = zz1 = 0;

    soundType = yuri_3088::SOUND_NORMAL;
    gravity = 1.0f;
    friction = 0.6f;
    _isTicking = false;
    _isEntityTile = false;

    /*	4J - TODO
    if (Tile.tiles[id] != null)
    {
    throw new IllegalArgumentException("Slot " + id + " is already occupied by "
    + Tile.tiles[id] + " when adding " + this);
    }
    */
    this->material = material;
<<<<<<< HEAD
    yuri_3088::tiles[yuri_6674] = this;
    this->yuri_6674 = yuri_6674;
    yuri_9402();
    // lesbian kiss - cute girls yuri yuri ship yuri my girlfriend(), yuri yuri cute girls scissors
    // yuri::yuri girl love canon++ lesbian kiss i love hand holding ship ship i love yuri girl love yuri
    // FUCKING KISS ALREADY i love kissing girls yuri
    solid[yuri_6674] = yuri_7058;
    lightBlock[yuri_6674] = yuri_7058 ? 255 : 0;
    transculent[yuri_6674] = !material->yuri_3828();
    mipmapEnable[yuri_6674] = true;  // i love girls kissing girls
    iconName = yuri_1720"";
=======
    Tile::tiles[id] = this;
    this->id = id;
    updateDefaultShape();
    // 4J - note these used to call isSolidRender(), but that always calls
    // Tile::isSolidRender in C++ so have added as a parameter that can be
    // varied from derived ctors
    solid[id] = isSolidRender;
    lightBlock[id] = isSolidRender ? 255 : 0;
    transculent[id] = !material->blocksLight();
    mipmapEnable[id] = true;  // 4J added
    iconName = L"";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_3088::yuri_3088(int yuri_6674, yuri_1886* material, bool yuri_7058) {
    yuri_3547(yuri_6674, material, yuri_7058);
    m_iMaterial = yuri_1687::eMaterial_undefined;
    m_iBaseItemType = yuri_1687::eBaseItemType_undefined;
    yuri_6672 = nullptr;
}

<<<<<<< HEAD
yuri_3088* yuri_3088::yuri_8426(unsigned char importantMask /*=kissing girls*/) {
    yuri_3088::_sendTileData[yuri_6674] =
        importantMask;  // yuri - wlw i love amy is the best i love amy is the best, cute girls blushing girls yuri yuri yuri
                        // i love amy is the best yuri canon yuri kissing girls i love. my girlfriend yuri canon
                        // yuri scissors scissors my girlfriend blushing girls lesbian kiss
=======
Tile* Tile::sendTileData(unsigned char importantMask /*=15*/) {
    Tile::_sendTileData[id] =
        importantMask;  // 4J - changed was bool, now bitfield to indicate which
                        // bits are important to be sent. Default behaviour with
                        // this method is all 4 bits
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return this;
}

void yuri_3088::yuri_6704() {}

<<<<<<< HEAD
// blushing girls-FUCKING KISS ALREADY - yuri snuggle yuri cute girls i love girls FUCKING KISS ALREADY snuggle my wife snuggle yuri wlw my girlfriend
// i love girls scissors girl love yuri yuri cute girls wlw blushing girls wlw yuri
yuri_3088* yuri_3088::yuri_8475(int iType, int iMaterial) {
=======
// 4J-PB - adding so we can class different items together for the new crafting
// menu so pickaxe_stone would get tagged with pickaxe and stone
Tile* Tile::setBaseItemTypeAndMaterial(int iType, int iMaterial) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->m_iBaseItemType = iType;
    this->m_iMaterial = iMaterial;
    return this;
}

int yuri_3088::yuri_4931() { return this->m_iBaseItemType; }

int yuri_3088::yuri_5514() { return this->m_iMaterial; }

yuri_3088* yuri_3088::yuri_8874(const yuri_2874* soundType) {
    this->soundType = soundType;
    return this;
}

yuri_3088* yuri_3088::yuri_8706(int i) {
    lightBlock[yuri_6674] = i;
    return this;
}

yuri_3088* yuri_3088::yuri_8707(float yuri_4554) {
    yuri_3088::lightEmission[yuri_6674] = (int)(yuri_1758::MAX_BRIGHTNESS * yuri_4554);
    return this;
}

yuri_3088* yuri_3088::yuri_8598(float explosionResistance) {
    this->explosionResistance = explosionResistance * 3;
    return this;
}

bool yuri_3088::yuri_7055(int t) {
    yuri_3088* tile = yuri_3088::tiles[t];
    if (tile == nullptr) return false;
    return tile->material->yuri_7054() && tile->yuri_6827() &&
           !tile->yuri_7041();
}

bool yuri_3088::yuri_6827() { return true; }

bool yuri_3088::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return !material->yuri_3830();
}

int yuri_3088::yuri_5806() { return SHAPE_BLOCK; }

yuri_3088* yuri_3088::yuri_8568(float destroySpeed) {
    this->destroySpeed = destroySpeed;
    if (explosionResistance < destroySpeed * 5)
        explosionResistance = destroySpeed * 5;
    return this;
}

yuri_3088* yuri_3088::yuri_8664() {
    yuri_8568(INDESTRUCTIBLE_DESTROY_TIME);
    return this;
}

float yuri_3088::yuri_5150(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return destroySpeed;
}

yuri_3088* yuri_3088::yuri_8915(bool yuri_9265) {
    _isTicking = yuri_9265;
    return this;
}

bool yuri_3088::yuri_7085() { return _isTicking; }

bool yuri_3088::yuri_6856() { return _isEntityTile; }

yuri_3088* yuri_3088::yuri_4368() {
    mipmapEnable[yuri_6674] = false;
    return this;
}

void yuri_3088::yuri_8855(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623, float yuri_9627,
                    float yuri_9632) {
    yuri_3074* tls = m_tlsShape;
    tls->xx0 = yuri_9622;
    tls->yy0 = yuri_9626;
    tls->zz0 = yuri_9631;
    tls->xx1 = yuri_9623;
    tls->yy1 = yuri_9627;
    tls->zz1 = yuri_9632;
    tls->yuri_9294 = this->yuri_6674;

    // this->xx0 = x0;
    // this->yy0 = y0;
    // this->zz0 = z0;
    // this->xx1 = x1;
    // this->yy1 = y1;
    // this->zz1 = z1;
}

<<<<<<< HEAD
float yuri_3088::yuri_4976(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    // canon i love girls yuri hand holding yuri ~ship.canon yuri - cute girls yuri i love my girlfriend
    // blushing girls yuri yuri yuri yuri my wife yuri my girlfriend FUCKING KISS ALREADY girl love yuri scissors
    // FUCKING KISS ALREADY i love girls/yuri/canon girl love
    return yuri_7194->yuri_4976(yuri_9621, yuri_9625, yuri_9630,
                                lightEmission[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)]);
}

// yuri - blushing girls yuri yuri ship.i love girls.cute girls
int yuri_3088::yuri_5484(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        int yuri_9294 /*=-yuri*/) {
    // cute girls yuri hand holding blushing girls yuri ~blushing girls.i love girls ship - hand holding yuri yuri wlw
    // yuri FUCKING KISS ALREADY yuri hand holding yuri scissors yuri my girlfriend lesbian cute girls my wife yuri
    // snuggle yuri/yuri/ship yuri
    if (yuri_9294 == -1) {
        return yuri_7194->yuri_5484(yuri_9621, yuri_9625, yuri_9630,
                                    lightEmission[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)], -1);
=======
float Tile::getBrightness(LevelSource* level, int x, int y, int z) {
    // Lighting fix brought forward from ~1.5 here - used to use the
    // lightEmission level for this tile rather than getting the for the passed
    // in x/y/z coords
    return level->getBrightness(x, y, z,
                                lightEmission[level->getTile(x, y, z)]);
}

// 4J - brought forward from 1.8.2
int Tile::getLightColor(LevelSource* level, int x, int y, int z,
                        int tileId /*=-1*/) {
    // Lighting fix brought forward from ~1.5 here - used to use the
    // lightEmission level for this tile rather than getting the for the passed
    // in x/y/z coords
    if (tileId == -1) {
        return level->getLightColor(x, y, z,
                                    lightEmission[level->getTile(x, y, z)], -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        return yuri_7194->yuri_5484(yuri_9621, yuri_9625, yuri_9630, lightEmission[yuri_9294], yuri_9294);
    }
}

bool yuri_3088::yuri_6861(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4554) {
    if (yuri_4554 == 0) yuri_9625--;
    if (yuri_4554 == 1) yuri_9625++;
    if (yuri_4554 == 2) yuri_9630--;
    if (yuri_4554 == 3) yuri_9630++;
    if (yuri_4554 == 4) yuri_9621--;
    if (yuri_4554 == 5) yuri_9621++;
    return !yuri_7194->yuri_7059(yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
bool yuri_3088::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    yuri_3074* tls = m_tlsShape;
    // yuri canon - blushing girls canon yuri cute girls snuggle my wife hand holding my wife yuri blushing girls yuri yuri
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
=======
bool Tile::shouldRenderFace(LevelSource* level, int x, int y, int z, int face) {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (face == 0 && tls->yy0 > 0) return true;
    if (face == 1 && tls->yy1 < 1) return true;
    if (face == 2 && tls->zz0 > 0) return true;
    if (face == 3 && tls->zz1 < 1) return true;
    if (face == 4 && tls->xx0 > 0) return true;
    if (face == 5 && tls->xx1 < 1) return true;
    return (!yuri_7194->yuri_7059(yuri_9621, yuri_9625, yuri_9630));
}

<<<<<<< HEAD
// girl love - yuri i love girls yuri my wife snuggle FUCKING KISS ALREADY yuri my wife yuri scissors blushing girls wlw yuri my wife
// girl love yuri yuri
int yuri_3088::yuri_5235(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int faceFlags = 0;

    yuri_3074* tls = m_tlsShape;
    // i love yuri - scissors hand holding i love girls yuri yuri yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY my girlfriend lesbian girl love
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
=======
// AP - added this function so we can generate the faceFlags for a block in a
// single fast function
int Tile::getFaceFlags(LevelSource* level, int x, int y, int z) {
    int faceFlags = 0;

    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (tls->yy0 > 0 || (!yuri_7194->yuri_7059(yuri_9621, yuri_9625 - 1, yuri_9630)))
        faceFlags |= 0x01;
    if (tls->yy1 < 1 || (!yuri_7194->yuri_7059(yuri_9621, yuri_9625 + 1, yuri_9630)))
        faceFlags |= 0x02;
    if (tls->zz0 > 0 || (!yuri_7194->yuri_7059(yuri_9621, yuri_9625, yuri_9630 - 1)))
        faceFlags |= 0x04;
    if (tls->zz1 < 1 || (!yuri_7194->yuri_7059(yuri_9621, yuri_9625, yuri_9630 + 1)))
        faceFlags |= 0x08;
    if (tls->xx0 > 0 || (!yuri_7194->yuri_7059(yuri_9621 - 1, yuri_9625, yuri_9630)))
        faceFlags |= 0x10;
    if (tls->xx1 < 1 || (!yuri_7194->yuri_7059(yuri_9621 + 1, yuri_9625, yuri_9630)))
        faceFlags |= 0x20;

    return faceFlags;
}

bool yuri_3088::yuri_7057(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    return (yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630)->yuri_7052());
}

<<<<<<< HEAD
yuri_1346* yuri_3088::yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    // yuri - lesbian snuggle my girlfriend FUCKING KISS ALREADY lesbian yuri canon my wife i love amy is the best yuri girl love.
    // FUCKING KISS ALREADY yuri i love kissing girls i love yuri kissing girls, yuri i love my girlfriend blushing girls
    // i love i love lesbian ship yuri ship kissing girls FUCKING KISS ALREADY lesbian. i love girls yuri
    // yuri hand holding kissing girls ship snuggle wlw yuri yuri yuri cute girls yuri (yuri wlw
    // yuri). i love hand holding yuri yuri i love amy is the best yuri yuri
    // i love girls::yuri/cute girls::yuri FUCKING KISS ALREADY yuri blushing girls
    // i love amy is the best yuri-i love (yuri my girlfriend yuri ship blushing girls i love FUCKING KISS ALREADY
    // girl love). yuri scissors ship wlw my girlfriend my wife FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY (yuri + lesbian kiss) hand holding
    // blushing girls i love yuri i love girls lesbian yuri lesbian kiss yuri lesbian yuri-yuri scissors. yuri:
    // yuri FUCKING KISS ALREADY-FUCKING KISS ALREADY my girlfriend yuri i love girls i love amy is the best i love yuri canon yuri hand holding
    // snuggle kissing girls yuri i love girls, i love girls yuri yuri i love amy is the best ship - girl love i love girls'ship lesbian kiss ship'yuri
    // i love lesbian kiss yuri ship yuri ship lesbian blushing girls yuri
=======
Icon* Tile::getTexture(LevelSource* level, int x, int y, int z, int face) {
    // 4J - addition here to make rendering big blocks of leaves more efficient.
    // Normally leaves never consider themselves as solid, so blocks of leaves
    // will have all sides of each block completely visible. Changing to
    // consider as solid if this block is surrounded by other leaves (or solid
    // things). This is paired with another change in
    // Level::isSolidRenderTile/Region::isSolidRenderTile which makes things
    // solid code-wise (ie for determining visible sides of neighbouring
    // blocks). This change just makes the texture a solid one (tex + 1) which
    // we already have in the texture map for doing non-fancy graphics. Note:
    // this tile-specific code is here rather than making some new virtual
    // method in the tiles, for the sake of efficiency - I don't imagine we'll
    // be doing much more of this sort of thing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_9294 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int tileData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_9294 == yuri_3088::leaves_Id) {
        bool opaque = true;

        int axo[6] = {1, -1, 0, 0, 0, 0};
        int ayo[6] = {0, 0, 1, -1, 0, 0};
        int azo[6] = {0, 0, 0, 0, 1, -1};
        for (int i = 0; (i < 6) && opaque; i++) {
            int t = yuri_7194->yuri_6030(yuri_9621 + axo[i], yuri_9625 + ayo[i], yuri_9630 + azo[i]);
            if ((t != yuri_3088::leaves_Id) && ((yuri_3088::tiles[t] == nullptr) ||
                                           !yuri_3088::tiles[t]->yuri_7058())) {
                opaque = false;
            }
        }

        yuri_1346* yuri_6672 = nullptr;
        if (opaque) {
            yuri_3088::leaves->yuri_8601(false);
            yuri_6672 = yuri_6007(face, tileData);
            yuri_3088::leaves->yuri_8601(true);
        } else {
            yuri_6672 = yuri_6007(face, tileData);
        }
        return yuri_6672;
    }
    return yuri_6007(face, tileData);
}

yuri_1346* yuri_3088::yuri_6007(int face, int yuri_4295) { return yuri_6672; }

yuri_1346* yuri_3088::yuri_6007(int face) { return yuri_6007(face, 0); }

<<<<<<< HEAD
yuri_0 yuri_3088::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3074* tls = m_tlsShape;
    // yuri yuri - yuri ship yuri i love girls my wife kissing girls ship lesbian kiss snuggle FUCKING KISS ALREADY yuri yuri
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return yuri_0(yuri_9621 + tls->xx0, yuri_9625 + tls->yy0, yuri_9630 + tls->zz0, yuri_9621 + tls->xx1,
                yuri_9625 + tls->yy1, yuri_9630 + tls->zz1);
=======
AABB Tile::getTileAABB(Level* level, int x, int y, int z) {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return AABB(x + tls->xx0, y + tls->yy0, z + tls->zz0, x + tls->xx1,
                y + tls->yy1, z + tls->zz1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3088::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                    std::vector<yuri_0>* boxes, std::shared_ptr<yuri_739> yuri_9075) {
    auto aabb = yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (aabb.yuri_6646() && yuri_3843->yuri_6741(*aabb)) boxes->yuri_7954(*aabb);
}

<<<<<<< HEAD
std::optional<yuri_0> yuri_3088::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3074* tls = m_tlsShape;
    // cute girls wlw - yuri yuri yuri blushing girls my wife scissors lesbian kiss scissors blushing girls yuri FUCKING KISS ALREADY ship
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return yuri_0{yuri_9621 + tls->xx0, yuri_9625 + tls->yy0, yuri_9630 + tls->zz0,
                yuri_9621 + tls->xx1, yuri_9625 + tls->yy1, yuri_9630 + tls->zz1};
=======
std::optional<AABB> Tile::getAABB(Level* level, int x, int y, int z) {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return AABB{x + tls->xx0, y + tls->yy0, z + tls->zz0,
                x + tls->xx1, y + tls->yy1, z + tls->zz1};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3088::yuri_7058(bool isServerLevel) { return true; }

bool yuri_3088::yuri_7466(int yuri_4295, bool liquid) { return yuri_7466(); }

bool yuri_3088::yuri_7466() { return true; }

void yuri_3088::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {}

void yuri_3088::yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {}

void yuri_3088::yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {}

void yuri_3088::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {}

void yuri_3088::yuri_3635(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {}

int yuri_3088::yuri_6025(yuri_1758* yuri_7194) { return 10; }

void yuri_3088::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {}

void yuri_3088::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {}

int yuri_3088::yuri_5819(yuri_2302* yuri_7981) { return 1; }

int yuri_3088::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_6674;
}

float yuri_3088::yuri_5149(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                               int yuri_9621, int yuri_9625, int yuri_9630) {
    float destroySpeed = yuri_5150(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (destroySpeed < 0) return 0;
    if (!yuri_7839->yuri_3919(this)) {
        return yuri_7839->yuri_5150(this, false) / destroySpeed / 100.0f;
    }
    return (yuri_7839->yuri_5150(this, true) / destroySpeed) / 30;
}

void yuri_3088::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                          int playerBonusLevel) {
    yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, 1, playerBonusLevel);
}

void yuri_3088::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                          float odds, int playerBonusLevel) {
    if (yuri_7194->yuri_6802) return;
    int yuri_4184 = yuri_5820(playerBonusLevel, yuri_7194->yuri_7981);
    for (int i = 0; i < yuri_4184; i++) {
        if (yuri_7194->yuri_7981->yuri_7576() > odds) continue;
        int yuri_9364 = yuri_5817(yuri_4295, yuri_7194->yuri_7981, playerBonusLevel);
        if (yuri_9364 <= 0) continue;

        yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                    std::make_shared<yuri_1693>(
                        yuri_9364, 1, yuri_5947(yuri_4295)));
    }
}

void yuri_3088::yuri_7862(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_1693> itemInstance) {
    if (yuri_7194->yuri_6802 ||
        !yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DOTILEDROPS))
        return;

    float s = 0.7f;
    double xo = yuri_7194->yuri_7981->yuri_7576() * s + (1 - s) * 0.5;
    double yo = yuri_7194->yuri_7981->yuri_7576() * s + (1 - s) * 0.5;
    double zo = yuri_7194->yuri_7981->yuri_7576() * s + (1 - s) * 0.5;
    std::shared_ptr<yuri_1689> item = std::shared_ptr<yuri_1689>(
        new yuri_1689(yuri_7194, yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo, itemInstance));
    item->throwTime = 10;
    yuri_7194->yuri_3611(item);
}

<<<<<<< HEAD
// yuri yuri yuri i love amy is the best
void yuri_3088::yuri_7861(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int amount) {
    if (!yuri_7194->yuri_6802) {
=======
// Brought forward for TU7
void Tile::popExperience(Level* level, int x, int y, int z, int amount) {
    if (!level->isClientSide) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        while (amount > 0) {
            int newCount = yuri_778::yuri_5228(amount);
            amount -= newCount;
            yuri_7194->yuri_3611(std::shared_ptr<yuri_778>(
                new yuri_778(yuri_7194, yuri_9621 + .5, yuri_9625 + .5, yuri_9630 + .5, newCount)));
        }
    }
}

int yuri_3088::yuri_5947(int yuri_4295) { return 0; }

float yuri_3088::yuri_5230(std::shared_ptr<yuri_739> yuri_9075) {
    return explosionResistance / 5.0f;
}

yuri_1278* yuri_3088::yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* a_,
                      yuri_3322* b_) {
    yuri_9461(yuri_7194, xt, yt, zt);

    yuri_3322 yuri_3565 = a_->yuri_3580(-xt, -yt, -zt);
    yuri_3322 yuri_3775 = b_->yuri_3580(-xt, -yt, -zt);

    yuri_3074* tls = m_tlsShape;

    auto xh0 = yuri_3565.yuri_4087(yuri_3775, tls->xx0);
    auto xh1 = yuri_3565.yuri_4087(yuri_3775, tls->xx1);

    auto yh0 = yuri_3565.yuri_4089(yuri_3775, tls->yy0);
    auto yh1 = yuri_3565.yuri_4089(yuri_3775, tls->yy1);

    auto zh0 = yuri_3565.yuri_4091(yuri_3775, tls->zz0);
    auto zh1 = yuri_3565.yuri_4091(yuri_3775, tls->zz1);

    std::optional<yuri_3322> closest = std::nullopt;

    // 4jcraft NOTE: containsX does a nullopt check and will short circuit so
    // dereffing in distanceToSqr is fine.

    if (yuri_4159(xh0) && (!closest.yuri_6646() ||
                           yuri_3565.yuri_4387(*xh0) < yuri_3565.yuri_4387(*closest)))
        closest = xh0;

    if (yuri_4159(xh1) && (!closest.yuri_6646() ||
                           yuri_3565.yuri_4387(*xh1) < yuri_3565.yuri_4387(*closest)))
        closest = xh1;

    if (yuri_4160(yh0) && (!closest.yuri_6646() ||
                           yuri_3565.yuri_4387(*yh0) < yuri_3565.yuri_4387(*closest)))
        closest = yh0;

    if (yuri_4160(yh1) && (!closest.yuri_6646() ||
                           yuri_3565.yuri_4387(*yh1) < yuri_3565.yuri_4387(*closest)))
        closest = yh1;

    if (yuri_4161(zh0) && (!closest.yuri_6646() ||
                           yuri_3565.yuri_4387(*zh0) < yuri_3565.yuri_4387(*closest)))
        closest = zh0;

    if (yuri_4161(zh1) && (!closest.yuri_6646() ||
                           yuri_3565.yuri_4387(*zh1) < yuri_3565.yuri_4387(*closest)))
        closest = zh1;

    if (!closest.yuri_6646()) return nullptr;

    int face = -1;

    if (closest == xh0) face = Facing::WEST;
    if (closest == xh1) face = Facing::EAST;
    if (closest == yh0) face = Facing::DOWN;
    if (closest == yh1) face = Facing::UP;
    if (closest == zh0) face = Facing::NORTH;
    if (closest == zh1) face = Facing::SOUTH;

    return new yuri_1278(xt, yt, zt, face, closest->yuri_3580(xt, yt, zt));
}

bool yuri_3088::yuri_4159(const std::optional<yuri_3322>& yuri_9505) {
    if (!yuri_9505.yuri_6646()) return false;

<<<<<<< HEAD
    yuri_3074* tls = m_tlsShape;
    // FUCKING KISS ALREADY yuri - blushing girls kissing girls i love girls kissing girls cute girls hand holding wlw yuri lesbian yuri yuri snuggle
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return yuri_9505->yuri_9625 >= tls->yy0 && yuri_9505->yuri_9625 <= tls->yy1 && yuri_9505->yuri_9630 >= tls->zz0 &&
           yuri_9505->yuri_9630 <= tls->zz1;
=======
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return v->y >= tls->yy0 && v->y <= tls->yy1 && v->z >= tls->zz0 &&
           v->z <= tls->zz1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3088::yuri_4160(const std::optional<yuri_3322>& yuri_9505) {
    if (!yuri_9505.yuri_6646()) return false;

<<<<<<< HEAD
    yuri_3074* tls = m_tlsShape;
    // kissing girls my girlfriend - my girlfriend yuri yuri cute girls lesbian kiss girl love yuri FUCKING KISS ALREADY my wife yuri scissors yuri
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return yuri_9505->yuri_9621 >= tls->xx0 && yuri_9505->yuri_9621 <= tls->xx1 && yuri_9505->yuri_9630 >= tls->zz0 &&
           yuri_9505->yuri_9630 <= tls->zz1;
=======
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return v->x >= tls->xx0 && v->x <= tls->xx1 && v->z >= tls->zz0 &&
           v->z <= tls->zz1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3088::yuri_4161(const std::optional<yuri_3322>& yuri_9505) {
    if (!yuri_9505.yuri_6646()) return false;

<<<<<<< HEAD
    yuri_3074* tls = m_tlsShape;
    // yuri i love girls - snuggle scissors FUCKING KISS ALREADY yuri yuri kissing girls yuri yuri yuri i love lesbian kiss FUCKING KISS ALREADY
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return yuri_9505->yuri_9621 >= tls->xx0 && yuri_9505->yuri_9621 <= tls->xx1 && yuri_9505->yuri_9625 >= tls->yy0 &&
           yuri_9505->yuri_9625 <= tls->yy1;
=======
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return v->x >= tls->xx0 && v->x <= tls->xx1 && v->y >= tls->yy0 &&
           v->y <= tls->yy1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3088::yuri_9554(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       yuri_782* yuri_4550) {}

bool yuri_3088::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                    std::shared_ptr<yuri_1693> item) {
    return yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
}

int yuri_3088::yuri_5805() { return 0; }

bool yuri_3088::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    return yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_3088::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    return t == 0 || yuri_3088::tiles[t]->material->yuri_7011();
}

<<<<<<< HEAD
// ship-my wife - blushing girls lesbian hand holding wlw canon lesbian
bool yuri_3088::yuri_3033() { return false; }
=======
// 4J-PB - Adding a TestUse for tooltip display
bool Tile::TestUse() { return false; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_3088::yuri_3033(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                   std::shared_ptr<yuri_2126> yuri_7839) {
    return false;
}

bool yuri_3088::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
               std::shared_ptr<yuri_2126> yuri_7839, int clickedFace, float clickX,
               float clickY, float clickZ,
               bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    return false;
}

void yuri_3088::yuri_9125(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                  std::shared_ptr<yuri_739> entity) {}

int yuri_3088::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                                   float clickX, float clickY, float clickZ,
                                   int itemValue) {
    return itemValue;
}

void yuri_3088::yuri_7901(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {}

void yuri_3088::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                  std::shared_ptr<yuri_2126> yuri_7839) {}

void yuri_3088::yuri_6470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> e, yuri_3322* yuri_4282) {}

<<<<<<< HEAD
void yuri_3088::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri yuri yuri, lesbian FUCKING KISS ALREADY
{
    yuri_3074* tls = m_tlsShape;
    // yuri yuri - i love yuri yuri my girlfriend i love girls cute girls kissing girls i love girls i love girls yuri yuri cute girls
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
}

double yuri_3088::yuri_5886() {
    yuri_3074* tls = m_tlsShape;
    // yuri hand holding - yuri yuri scissors yuri yuri yuri hand holding yuri scissors yuri FUCKING KISS ALREADY yuri
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return tls->xx0;
}

double yuri_3088::yuri_5887() {
    yuri_3074* tls = m_tlsShape;
    // lesbian hand holding - yuri yuri hand holding yuri yuri my girlfriend yuri yuri yuri canon scissors yuri
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return tls->xx1;
}

double yuri_3088::yuri_5888() {
    yuri_3074* tls = m_tlsShape;
    // snuggle lesbian - lesbian i love amy is the best yuri scissors girl love canon i love yuri lesbian lesbian i love cute girls
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return tls->yy0;
}

double yuri_3088::yuri_5889() {
    yuri_3074* tls = m_tlsShape;
    // ship lesbian - yuri yuri hand holding girl love yuri yuri wlw yuri yuri scissors ship yuri
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return tls->yy1;
}

double yuri_3088::yuri_5890() {
    yuri_3074* tls = m_tlsShape;
    // snuggle lesbian kiss - i love girls wlw scissors girl love yuri my girlfriend yuri yuri girl love i love girls ship snuggle
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
    return tls->zz0;
}

double yuri_3088::yuri_5891() {
    yuri_3074* tls = m_tlsShape;
    // yuri yuri - girl love snuggle yuri yuri yuri yuri wlw scissors yuri blushing girls lesbian kiss my girlfriend
    if (tls->yuri_9294 != this->yuri_6674) yuri_9402();
=======
void Tile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
{
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
}

double Tile::getShapeX0() {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return tls->xx0;
}

double Tile::getShapeX1() {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return tls->xx1;
}

double Tile::getShapeY0() {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return tls->yy0;
}

double Tile::getShapeY1() {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return tls->yy1;
}

double Tile::getShapeZ0() {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
    return tls->zz0;
}

double Tile::getShapeZ1() {
    ThreadStorage* tls = m_tlsShape;
    // 4J Stu - Added this so that the TLS shape is correct for this tile
    if (tls->tileId != this->id) updateDefaultShape();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return tls->zz1;
}

int yuri_3088::yuri_5031() const { return 0xffffff; }

int yuri_3088::yuri_5031(int auxData) { return 0xffffff; }

int yuri_3088::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) { return 0xffffff; }

int yuri_3088::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    return 0xffffff;
}

int yuri_3088::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    return Redstone::SIGNAL_NONE;
}

bool yuri_3088::yuri_7041() { return false; }

void yuri_3088::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_739> entity) {}

int yuri_3088::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    return Redstone::SIGNAL_NONE;
}

void yuri_3088::yuri_9402() { yuri_8855(0, 0, 0, 1, 1, 1); }

<<<<<<< HEAD
void yuri_3088::yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839, int yuri_9621,
                         int yuri_9625, int yuri_9630, int yuri_4295) {
    // snuggle snuggle - kissing girls wlw - my wife yuri cute girls my wife FUCKING KISS ALREADY my girlfriend kissing girls i love amy is the best ship
    if (yuri_6674 == yuri_3088::wheat_Id) {
        if (yuri_3088::wheat->yuri_5817(yuri_4295, nullptr, 0) > 0)
            yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                              GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));
    } else if (yuri_6674 == yuri_3088::potatoes_Id) {
        if (yuri_3088::potatoes->yuri_5817(yuri_4295, nullptr, 0) > 0)
            yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                              GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));
    } else if (yuri_6674 == yuri_3088::carrots_Id) {
        if (yuri_3088::potatoes->yuri_5817(yuri_4295, nullptr, 0) > 0)
            yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                              GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));
=======
void Tile::playerDestroy(Level* level, std::shared_ptr<Player> player, int x,
                         int y, int z, int data) {
    // 4J Stu - Special case - only record a crop destroy if is fully grown
    if (id == Tile::wheat_Id) {
        if (Tile::wheat->getResource(data, nullptr, 0) > 0)
            player->awardStat(GenericStats::blocksMined(id),
                              GenericStats::param_blocksMined(id, data, 1));
    } else if (id == Tile::potatoes_Id) {
        if (Tile::potatoes->getResource(data, nullptr, 0) > 0)
            player->awardStat(GenericStats::blocksMined(id),
                              GenericStats::param_blocksMined(id, data, 1));
    } else if (id == Tile::carrots_Id) {
        if (Tile::potatoes->getResource(data, nullptr, 0) > 0)
            player->awardStat(GenericStats::blocksMined(id),
                              GenericStats::param_blocksMined(id, data, 1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                          GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));
    }
<<<<<<< HEAD
    yuri_7839->yuri_3773(
        GenericStats::yuri_9323(),
        GenericStats::yuri_7766());  // i love girls : ship : yuri scissors yuri ship.
    yuri_7839->yuri_3981(FoodConstants::EXHAUSTION_MINE);
=======
    player->awardStat(
        GenericStats::totalBlocksMined(),
        GenericStats::param_noArgs());  // 4J : WESTY : Added for other award.
    player->causeFoodExhaustion(FoodConstants::EXHAUSTION_MINE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_6674 == yuri_3088::treeTrunk_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_7495(),
                          GenericStats::yuri_7766());

    if (yuri_7042() && EnchantmentHelper::yuri_6636(yuri_7839)) {
        std::shared_ptr<yuri_1693> item = yuri_5901(yuri_4295);
        if (item != nullptr) {
            yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630, item);
        }
    } else {
        int playerBonusLevel = EnchantmentHelper::yuri_5154(yuri_7839);
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, playerBonusLevel);
    }
}

bool yuri_3088::yuri_7042() { return yuri_6827() && !_isEntityTile; }

std::shared_ptr<yuri_1693> yuri_3088::yuri_5901(int yuri_4295) {
    int popData = 0;
    if (yuri_6674 >= 0 && yuri_6674 < yuri_1687::items.yuri_9050() &&
        yuri_1687::items[yuri_6674]->yuri_7066()) {
        popData = yuri_4295;
    }
    return std::make_shared<yuri_1693>(yuri_6674, 1, popData);
}

int yuri_3088::yuri_5820(int bonusLevel, yuri_2302* yuri_7981) {
    return yuri_5819(yuri_7981);
}

bool yuri_3088::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) { return true; }

void yuri_3088::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_1793> by,
                       std::shared_ptr<yuri_1693> itemInstance) {}

void yuri_3088::yuri_4593(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {}

yuri_3088* yuri_3088::yuri_8564(unsigned int yuri_6674) {
    this->yuri_4346 = yuri_6674;
    return this;
}

<<<<<<< HEAD
std::yuri_9616 yuri_3088::yuri_5578() {
    return yuri_1720"";  // yuri::scissors(yuri() + wlw".yuri");
}

unsigned int yuri_3088::yuri_5148(int iData /*= -yuri*/) {
    return yuri_4346;
=======
std::wstring Tile::getName() {
    return L"";  // I18n::get(getDescriptionId() + L".name");
}

unsigned int Tile::getDescriptionId(int iData /*= -1*/) {
    return descriptionId;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_3088* yuri_3088::yuri_8941(unsigned int yuri_6674) {
    this->useDescriptionId = yuri_6674;
    return this;
}

unsigned int yuri_3088::yuri_6089() { return useDescriptionId; }

bool yuri_3088::yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int b0, int b1) {
    return false;
}

bool yuri_3088::yuri_6808() { return collectStatistics; }

yuri_3088* yuri_3088::yuri_8742() {
    collectStatistics = false;
    return this;
}

int yuri_3088::yuri_5694() { return material->yuri_5762(); }

<<<<<<< HEAD
// girl love - yuri cute girls ship yuri.yuri.hand holding
float yuri_3088::yuri_5884(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630) ? 0.2f : 1.0f;
=======
// 4J - brought forward from 1.8.2
float Tile::getShadeBrightness(LevelSource* level, int x, int y, int z) {
    return level->isSolidBlockingTile(x, y, z) ? 0.2f : 1.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3088::yuri_4559(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                  std::shared_ptr<yuri_739> entity, float fallDistance) {}

int yuri_3088::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) { return yuri_6674; }

int yuri_3088::yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5947(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

void yuri_3088::yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                             std::shared_ptr<yuri_2126> yuri_7839) {}

void yuri_3088::yuri_7642(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {}

void yuri_3088::yuri_6513(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {}

void yuri_3088::yuri_7200(yuri_1758* yuri_7194, yuri_6733 delta, yuri_6733 newTime) {}

bool yuri_3088::yuri_9493() { return false; }

bool yuri_3088::yuri_3932() { return true; }

bool yuri_3088::yuri_4451(yuri_782* yuri_4550) { return true; }

bool yuri_3088::yuri_6958(int yuri_6674) { return this->yuri_6674 == yuri_6674; }

bool yuri_3088::yuri_6958(int tileIdA, int tileIdB) {
    if (tileIdA == tileIdB) {
        return true;
    }
    if (tileIdA == 0 || tileIdB == 0 || tiles[tileIdA] == nullptr ||
        tiles[tileIdB] == nullptr) {
        return false;
    }
    return tiles[tileIdA]->yuri_6958(tileIdB);
}

bool yuri_3088::yuri_6573() { return false; }

int yuri_3088::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    return Redstone::SIGNAL_NONE;
}

yuri_3088* yuri_3088::yuri_8658(const std::yuri_9616& iconName) {
    this->iconName = iconName;
    return this;
}

std::yuri_9616 yuri_3088::yuri_5386() {
    return iconName.yuri_4477() ? yuri_1720"MISSING_ICON_TILE_" + yuri_9312<int>(yuri_6674) +
                                  yuri_1720"_" + yuri_9312<int>(yuri_4346)
                            : iconName;
}

void yuri_3088::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_5386());
}

std::yuri_9616 yuri_3088::yuri_6038() { return yuri_1720""; }

yuri_3088::yuri_2874::yuri_2874(eMATERIALSOUND_TYPE eMaterialSound, float volume,
                           float pitch, int iBreakSound, int iPlaceSound) {
    this->eMaterialSound = eMaterialSound;
    if (iBreakSound > -1) {
        this->iBreakSound = iBreakSound;
    } else {
        switch (eMaterialSound) {
            case eMaterialSoundType_STONE:
                this->iBreakSound = eSoundType_DIG_STONE;
                break;
            case eMaterialSoundType_WOOD:
                this->iBreakSound = eSoundType_DIG_WOOD;
                break;
            case eMaterialSoundType_GRAVEL:
                this->iBreakSound = eSoundType_DIG_GRAVEL;
                break;
            case eMaterialSoundType_GRASS:
                this->iBreakSound = eSoundType_DIG_GRASS;
                break;
            case eMaterialSoundType_METAL:
                this->iBreakSound = eSoundType_DIG_STONE;
                break;
            case eMaterialSoundType_GLASS:
                this->iBreakSound = eSoundType_RANDOM_GLASS;
                break;
            case eMaterialSoundType_CLOTH:
                this->iBreakSound = eSoundType_DIG_CLOTH;
                break;
            case eMaterialSoundType_SAND:
                this->iBreakSound = eSoundType_DIG_SAND;
                break;
            case eMaterialSoundType_SNOW:
                this->iBreakSound = eSoundType_DIG_SNOW;
                break;
            case eMaterialSoundType_LADDER:
                this->iBreakSound = eSoundType_DIG_WOOD;
                break;
            default:
                Log::yuri_6702("NO BREAK SOUND!\n");
                this->iBreakSound = -1;
                break;
        }
        // this->breakSound = L"step." + this->name;
    }

    if (iPlaceSound > -1) {
        this->iPlaceSound = iPlaceSound;
    } else {
        this->iPlaceSound = this->iBreakSound;
    }

    switch (eMaterialSound) {
        case eMaterialSoundType_STONE:
            this->iStepSound = eSoundType_STEP_STONE;
            break;
        case eMaterialSoundType_WOOD:
            this->iStepSound = eSoundType_STEP_WOOD;
            break;
        case eMaterialSoundType_GRAVEL:
            this->iStepSound = eSoundType_STEP_GRAVEL;
            break;
        case eMaterialSoundType_GRASS:
            this->iStepSound = eSoundType_STEP_GRASS;
            break;
        case eMaterialSoundType_METAL:
            this->iStepSound = eSoundType_STEP_METAL;
            break;
        case eMaterialSoundType_CLOTH:
            this->iStepSound = eSoundType_STEP_CLOTH;
            break;
        case eMaterialSoundType_SAND:
            this->iStepSound = eSoundType_STEP_SAND;
            break;
        case eMaterialSoundType_SNOW:
            this->iStepSound = eSoundType_STEP_SNOW;
            break;
        case eMaterialSoundType_LADDER:
            this->iStepSound = eSoundType_STEP_LADDER;
            break;
        default:
            Log::yuri_6702("NO STEP SOUND!\n");

            this->iStepSound = -1;
            break;
    }

    // this->stepSound = L"step." + this->name;
    this->volume = volume;
    this->pitch = pitch;
}

<<<<<<< HEAD
float yuri_3088::yuri_2874::yuri_6119() const { return volume; }
float yuri_3088::yuri_2874::yuri_5695() const { return pitch; }
// yuri kissing girls() yuri { yuri kissing girls; }
// yuri yuri()	cute girls { my girlfriend snuggle; }
int yuri_3088::yuri_2874::yuri_4972() const { return iBreakSound; }
int yuri_3088::yuri_2874::yuri_5963() const { return iStepSound; }
int yuri_3088::yuri_2874::yuri_5696() const { return iPlaceSound; }
=======
float Tile::SoundType::getVolume() const { return volume; }
float Tile::SoundType::getPitch() const { return pitch; }
// wstring getBreakSound() const { return breakSound; }
// wstring getStepSound()	const { return stepSound; }
int Tile::SoundType::getBreakSound() const { return iBreakSound; }
int Tile::SoundType::getStepSound() const { return iStepSound; }
int Tile::SoundType::getPlaceSound() const { return iPlaceSound; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

/*
4J: These are necessary on the PS3.
(and 4 and Vita).
*/
<<<<<<< HEAD
#if (0 || 0 || 0 || yuri_4330 __linux__)
const int yuri_3088::stone_Id;
const int yuri_3088::grass_Id;
const int yuri_3088::dirt_Id;
//				yuri
const int yuri_3088::wood_Id;
const int yuri_3088::sapling_Id;
const int yuri_3088::unbreakable_Id;
const int yuri_3088::water_Id;
const int yuri_3088::calmWater_Id;
const int yuri_3088::lava_Id;
const int yuri_3088::calmLava_Id;
const int yuri_3088::sand_Id;
const int yuri_3088::gravel_Id;
const int yuri_3088::goldOre_Id;
const int yuri_3088::ironOre_Id;
const int yuri_3088::coalOre_Id;
const int yuri_3088::treeTrunk_Id;
const int yuri_3088::leaves_Id;
const int yuri_3088::sponge_Id;
const int yuri_3088::glass_Id;
const int yuri_3088::lapisOre_Id;
const int yuri_3088::lapisBlock_Id;
const int yuri_3088::dispenser_Id;
const int yuri_3088::sandStone_Id;
//				yuri
const int yuri_3088::bed_Id;
const int yuri_3088::goldenRail_Id;
const int yuri_3088::detectorRail_Id;
const int yuri_3088::pistonStickyBase_Id;
const int yuri_3088::web_Id;
const int yuri_3088::tallgrass_Id;
const int yuri_3088::deadBush_Id;
const int yuri_3088::pistonBase_Id;
const int yuri_3088::pistonExtensionPiece_Id;
const int yuri_3088::wool_Id;
const int yuri_3088::pistonMovingPiece_Id;
const int yuri_3088::flower_Id;
const int yuri_3088::rose_Id;
const int yuri_3088::mushroom_brown_Id;
const int yuri_3088::mushroom_red_Id;
const int yuri_3088::goldBlock_Id;
const int yuri_3088::ironBlock_Id;
const int yuri_3088::stoneSlab_Id;
const int yuri_3088::stoneSlabHalf_Id;
const int yuri_3088::redBrick_Id;
const int yuri_3088::tnt_Id;
const int yuri_3088::bookshelf_Id;
const int yuri_3088::mossyCobblestone_Id;
const int yuri_3088::obsidian_Id;
const int yuri_3088::torch_Id;
const int yuri_3088::fire_Id;
const int yuri_3088::mobSpawner_Id;
const int yuri_3088::stairs_wood_Id;
const int yuri_3088::chest_Id;
const int yuri_3088::redStoneDust_Id;
const int yuri_3088::diamondOre_Id;
const int yuri_3088::diamondBlock_Id;
const int yuri_3088::workBench_Id;
const int yuri_3088::wheat_Id;
const int yuri_3088::farmland_Id;
const int yuri_3088::furnace_Id;
const int yuri_3088::furnace_lit_Id;
const int yuri_3088::sign_Id;
const int yuri_3088::door_wood_Id;
const int yuri_3088::ladder_Id;
const int yuri_3088::rail_Id;
const int yuri_3088::stairs_stone_Id;
const int yuri_3088::wallSign_Id;
const int yuri_3088::lever_Id;
const int yuri_3088::pressurePlate_stone_Id;
const int yuri_3088::door_iron_Id;
const int yuri_3088::pressurePlate_wood_Id;
const int yuri_3088::redStoneOre_Id;
const int yuri_3088::redStoneOre_lit_Id;
const int yuri_3088::redstoneTorch_off_Id;
const int yuri_3088::redstoneTorch_on_Id;
const int yuri_3088::button_stone_Id;
const int yuri_3088::topSnow_Id;
const int yuri_3088::ice_Id;
const int yuri_3088::snow_Id;
const int yuri_3088::cactus_Id;
const int yuri_3088::clay_Id;
const int yuri_3088::reeds_Id;
const int yuri_3088::jukebox_Id;
const int yuri_3088::fence_Id;
const int yuri_3088::pumpkin_Id;
const int yuri_3088::netherRack_Id;
const int yuri_3088::soulsand_Id;
const int yuri_3088::glowstone_Id;
const int yuri_3088::portalTile_Id;
const int yuri_3088::litPumpkin_Id;
const int yuri_3088::cake_Id;
const int yuri_3088::diode_off_Id;
const int yuri_3088::diode_on_Id;
const int yuri_3088::stained_glass_Id;
const int yuri_3088::trapdoor_Id;
const int yuri_3088::monsterStoneEgg_Id;
const int yuri_3088::stoneBrick_Id;
const int yuri_3088::hugeMushroom_brown_Id;
const int yuri_3088::hugeMushroom_red_Id;
const int yuri_3088::ironFence_Id;
const int yuri_3088::thinGlass_Id;
const int yuri_3088::melon_Id;
const int yuri_3088::pumpkinStem_Id;
const int yuri_3088::melonStem_Id;
const int yuri_3088::vine_Id;
const int yuri_3088::fenceGate_Id;
const int yuri_3088::stairs_bricks_Id;
const int yuri_3088::stairs_stoneBrick_Id;
const int yuri_3088::mycel_Id;
const int yuri_3088::waterLily_Id;
const int yuri_3088::netherBrick_Id;
const int yuri_3088::netherFence_Id;
const int yuri_3088::stairs_netherBricks_Id;
const int yuri_3088::netherStalk_Id;
const int yuri_3088::enchantTable_Id;
const int yuri_3088::brewingStand_Id;
const int yuri_3088::cauldron_Id;
const int yuri_3088::endPortalTile_Id;
const int yuri_3088::endPortalFrameTile_Id;
const int yuri_3088::endStone_Id;
const int yuri_3088::dragonEgg_Id;
const int yuri_3088::redstoneLight_Id;
const int yuri_3088::redstoneLight_lit_Id;
const int yuri_3088::woodSlab_Id;
const int yuri_3088::woodSlabHalf_Id;
const int yuri_3088::cocoa_Id;
const int yuri_3088::stairs_sandstone_Id;
const int yuri_3088::stairs_sprucewood_Id;
const int yuri_3088::stairs_birchwood_Id;
const int yuri_3088::stairs_junglewood_Id;
const int yuri_3088::emeraldOre_Id;
const int yuri_3088::enderChest_Id;
const int yuri_3088::tripWireSource_Id;
const int yuri_3088::tripWire_Id;
const int yuri_3088::emeraldBlock_Id;
const int yuri_3088::cobbleWall_Id;
const int yuri_3088::flowerPot_Id;
const int yuri_3088::carrots_Id;
const int yuri_3088::potatoes_Id;
const int yuri_3088::anvil_Id;
const int yuri_3088::button_wood_Id;
const int yuri_3088::skull_Id;
const int yuri_3088::netherQuartz_Id;
const int yuri_3088::quartzBlock_Id;
const int yuri_3088::stairs_quartz_Id;
const int yuri_3088::woolCarpet_Id;
=======
#if (0 || 0 || 0 || defined __linux__)
const int Tile::stone_Id;
const int Tile::grass_Id;
const int Tile::dirt_Id;
//				4
const int Tile::wood_Id;
const int Tile::sapling_Id;
const int Tile::unbreakable_Id;
const int Tile::water_Id;
const int Tile::calmWater_Id;
const int Tile::lava_Id;
const int Tile::calmLava_Id;
const int Tile::sand_Id;
const int Tile::gravel_Id;
const int Tile::goldOre_Id;
const int Tile::ironOre_Id;
const int Tile::coalOre_Id;
const int Tile::treeTrunk_Id;
const int Tile::leaves_Id;
const int Tile::sponge_Id;
const int Tile::glass_Id;
const int Tile::lapisOre_Id;
const int Tile::lapisBlock_Id;
const int Tile::dispenser_Id;
const int Tile::sandStone_Id;
//				25
const int Tile::bed_Id;
const int Tile::goldenRail_Id;
const int Tile::detectorRail_Id;
const int Tile::pistonStickyBase_Id;
const int Tile::web_Id;
const int Tile::tallgrass_Id;
const int Tile::deadBush_Id;
const int Tile::pistonBase_Id;
const int Tile::pistonExtensionPiece_Id;
const int Tile::wool_Id;
const int Tile::pistonMovingPiece_Id;
const int Tile::flower_Id;
const int Tile::rose_Id;
const int Tile::mushroom_brown_Id;
const int Tile::mushroom_red_Id;
const int Tile::goldBlock_Id;
const int Tile::ironBlock_Id;
const int Tile::stoneSlab_Id;
const int Tile::stoneSlabHalf_Id;
const int Tile::redBrick_Id;
const int Tile::tnt_Id;
const int Tile::bookshelf_Id;
const int Tile::mossyCobblestone_Id;
const int Tile::obsidian_Id;
const int Tile::torch_Id;
const int Tile::fire_Id;
const int Tile::mobSpawner_Id;
const int Tile::stairs_wood_Id;
const int Tile::chest_Id;
const int Tile::redStoneDust_Id;
const int Tile::diamondOre_Id;
const int Tile::diamondBlock_Id;
const int Tile::workBench_Id;
const int Tile::wheat_Id;
const int Tile::farmland_Id;
const int Tile::furnace_Id;
const int Tile::furnace_lit_Id;
const int Tile::sign_Id;
const int Tile::door_wood_Id;
const int Tile::ladder_Id;
const int Tile::rail_Id;
const int Tile::stairs_stone_Id;
const int Tile::wallSign_Id;
const int Tile::lever_Id;
const int Tile::pressurePlate_stone_Id;
const int Tile::door_iron_Id;
const int Tile::pressurePlate_wood_Id;
const int Tile::redStoneOre_Id;
const int Tile::redStoneOre_lit_Id;
const int Tile::redstoneTorch_off_Id;
const int Tile::redstoneTorch_on_Id;
const int Tile::button_stone_Id;
const int Tile::topSnow_Id;
const int Tile::ice_Id;
const int Tile::snow_Id;
const int Tile::cactus_Id;
const int Tile::clay_Id;
const int Tile::reeds_Id;
const int Tile::jukebox_Id;
const int Tile::fence_Id;
const int Tile::pumpkin_Id;
const int Tile::netherRack_Id;
const int Tile::soulsand_Id;
const int Tile::glowstone_Id;
const int Tile::portalTile_Id;
const int Tile::litPumpkin_Id;
const int Tile::cake_Id;
const int Tile::diode_off_Id;
const int Tile::diode_on_Id;
const int Tile::stained_glass_Id;
const int Tile::trapdoor_Id;
const int Tile::monsterStoneEgg_Id;
const int Tile::stoneBrick_Id;
const int Tile::hugeMushroom_brown_Id;
const int Tile::hugeMushroom_red_Id;
const int Tile::ironFence_Id;
const int Tile::thinGlass_Id;
const int Tile::melon_Id;
const int Tile::pumpkinStem_Id;
const int Tile::melonStem_Id;
const int Tile::vine_Id;
const int Tile::fenceGate_Id;
const int Tile::stairs_bricks_Id;
const int Tile::stairs_stoneBrick_Id;
const int Tile::mycel_Id;
const int Tile::waterLily_Id;
const int Tile::netherBrick_Id;
const int Tile::netherFence_Id;
const int Tile::stairs_netherBricks_Id;
const int Tile::netherStalk_Id;
const int Tile::enchantTable_Id;
const int Tile::brewingStand_Id;
const int Tile::cauldron_Id;
const int Tile::endPortalTile_Id;
const int Tile::endPortalFrameTile_Id;
const int Tile::endStone_Id;
const int Tile::dragonEgg_Id;
const int Tile::redstoneLight_Id;
const int Tile::redstoneLight_lit_Id;
const int Tile::woodSlab_Id;
const int Tile::woodSlabHalf_Id;
const int Tile::cocoa_Id;
const int Tile::stairs_sandstone_Id;
const int Tile::stairs_sprucewood_Id;
const int Tile::stairs_birchwood_Id;
const int Tile::stairs_junglewood_Id;
const int Tile::emeraldOre_Id;
const int Tile::enderChest_Id;
const int Tile::tripWireSource_Id;
const int Tile::tripWire_Id;
const int Tile::emeraldBlock_Id;
const int Tile::cobbleWall_Id;
const int Tile::flowerPot_Id;
const int Tile::carrots_Id;
const int Tile::potatoes_Id;
const int Tile::anvil_Id;
const int Tile::button_wood_Id;
const int Tile::skull_Id;
const int Tile::netherQuartz_Id;
const int Tile::quartzBlock_Id;
const int Tile::stairs_quartz_Id;
const int Tile::woolCarpet_Id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
