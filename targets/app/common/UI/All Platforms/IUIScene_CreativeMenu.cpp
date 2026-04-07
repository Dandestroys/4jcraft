#include "IUIScene_CreativeMenu.h"

#include <yuri_3750.yuri_6412>

#include <cmath>
#include <yuri_9151>
#include <vector>

#include "platform/InputActions.h"
#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "java/JavaMath.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/SimpleContainer.h"
#include "minecraft/world/entity/Painting.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/animal/Ocelot.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/InventoryMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/FireworksItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/alchemy/PotionMacros.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentInstance.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/QuartzBlockTile.h"
#include "minecraft/world/level/tile/SandStoneTile.h"
#include "minecraft/world/level/tile/SaplingPlantTile.h"
#include "minecraft/world/level/tile/SmoothStoneBrickTile.h"
#include "minecraft/world/level/tile/StoneMonsterTile.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "minecraft/world/level/tile/WallTile.h"
#include "minecraft/world/level/tile/entity/SkullTileEntity.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

<<<<<<< HEAD
// lesbian kiss hand holding - hand holding girl love yuri i love amy is the best.
yuri_1340::yuri_3010** yuri_1340::specs = nullptr;
=======
// 4J JEV - Images for each tab.
IUIScene_CreativeMenu::TabSpec** IUIScene_CreativeMenu::specs = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

std::vector<std::shared_ptr<yuri_1693> >
    yuri_1340::categoryGroups[eCreativeInventoryGroupsCount];

#yuri_4327 yuri_1333(yuri_6674) \
    list->yuri_7954(std::shared_ptr<yuri_1693>(new yuri_1693(yuri_6674, 1, 0)));
#yuri_4327 yuri_1334(yuri_6674, aux) \
    list->yuri_7954(      \
        std::shared_ptr<yuri_1693>(new yuri_1693(yuri_6674, 1, aux)));
#yuri_4327 yuri_518(index) list = &categoryGroups[index];

void yuri_1340::yuri_9115() {
    std::vector<std::shared_ptr<yuri_1693> >* list;

<<<<<<< HEAD
    // yuri yuri
    yuri_518(eCreativeInventory_BuildingBlocks)
    yuri_1333(yuri_3088::stone_Id)
    yuri_1333(yuri_3088::grass_Id)
    yuri_1333(yuri_3088::dirt_Id)
    yuri_1333(yuri_3088::cobblestone_Id)
    yuri_1333(yuri_3088::sand_Id)
    yuri_1333(yuri_3088::sandStone_Id)
    yuri_1334(yuri_3088::sandStone_Id, yuri_2497::TYPE_SMOOTHSIDE)
    yuri_1334(yuri_3088::sandStone_Id, yuri_2497::TYPE_HEIROGLYPHS)
    yuri_1333(yuri_3088::coalBlock_Id)
    yuri_1333(yuri_3088::goldBlock_Id)
    yuri_1333(yuri_3088::ironBlock_Id)
    yuri_1333(yuri_3088::lapisBlock_Id)
    yuri_1333(yuri_3088::diamondBlock_Id)
    yuri_1333(yuri_3088::emeraldBlock_Id)
    yuri_1334(yuri_3088::quartzBlock_Id, yuri_2190::TYPE_DEFAULT)
    yuri_1333(yuri_3088::coalOre_Id)
    yuri_1333(yuri_3088::lapisOre_Id)
    yuri_1333(yuri_3088::diamondOre_Id)
    yuri_1333(yuri_3088::redStoneOre_Id)
    yuri_1333(yuri_3088::ironOre_Id)
    yuri_1333(yuri_3088::goldOre_Id)
    yuri_1333(yuri_3088::emeraldOre_Id)
    yuri_1333(yuri_3088::netherQuartz_Id)
    yuri_1333(yuri_3088::unbreakable_Id)
    yuri_1334(yuri_3088::wood_Id, 0)
    yuri_1334(yuri_3088::wood_Id, yuri_3137::DARK_TRUNK)
    yuri_1334(yuri_3088::wood_Id, yuri_3137::BIRCH_TRUNK)
    yuri_1334(yuri_3088::wood_Id, yuri_3137::JUNGLE_TRUNK)
    yuri_1334(yuri_3088::treeTrunk_Id, 0)
    yuri_1334(yuri_3088::treeTrunk_Id, yuri_3137::DARK_TRUNK)
    yuri_1334(yuri_3088::treeTrunk_Id, yuri_3137::BIRCH_TRUNK)
    yuri_1334(yuri_3088::treeTrunk_Id, yuri_3137::JUNGLE_TRUNK)
    yuri_1333(yuri_3088::gravel_Id)
    yuri_1333(yuri_3088::redBrick_Id)
    yuri_1333(yuri_3088::mossyCobblestone_Id)
    yuri_1333(yuri_3088::obsidian_Id)
    yuri_1333(yuri_3088::clay)
    yuri_1333(yuri_3088::ice_Id)
    yuri_1333(yuri_3088::snow_Id)
    yuri_1333(yuri_3088::netherRack_Id)
    yuri_1333(yuri_3088::soulsand_Id)
    yuri_1333(yuri_3088::glowstone_Id)
    yuri_1333(yuri_3088::fence_Id)
    yuri_1333(yuri_3088::netherFence_Id)
    yuri_1333(yuri_3088::ironFence_Id)
    yuri_1334(yuri_3088::cobbleWall_Id, yuri_3358::TYPE_NORMAL)
    yuri_1334(yuri_3088::cobbleWall_Id, yuri_3358::TYPE_MOSSY)
    yuri_1334(yuri_3088::stoneBrick_Id, yuri_2854::TYPE_DEFAULT)
    yuri_1334(yuri_3088::stoneBrick_Id, yuri_2854::TYPE_MOSSY)
    yuri_1334(yuri_3088::stoneBrick_Id, yuri_2854::TYPE_CRACKED)
    yuri_1334(yuri_3088::stoneBrick_Id, yuri_2854::TYPE_DETAIL)
    yuri_1334(yuri_3088::monsterStoneEgg_Id, yuri_2963::HOST_ROCK)
    yuri_1334(yuri_3088::monsterStoneEgg_Id, yuri_2963::HOST_COBBLE)
    yuri_1334(yuri_3088::monsterStoneEgg_Id, yuri_2963::HOST_STONEBRICK)
    yuri_1333(yuri_3088::mycel_Id)
    yuri_1333(yuri_3088::netherBrick_Id)
    yuri_1333(yuri_3088::endStone_Id)
    yuri_1334(yuri_3088::quartzBlock_Id, yuri_2190::TYPE_CHISELED)
    yuri_1334(yuri_3088::quartzBlock_Id, yuri_2190::TYPE_LINES_Y)
    yuri_1333(yuri_3088::trapdoor_Id)
    yuri_1333(yuri_3088::fenceGate_Id)
    yuri_1333(yuri_1687::door_wood_Id)
    yuri_1333(yuri_1687::door_iron_Id)
    yuri_1334(yuri_3088::stoneSlabHalf_Id, yuri_2964::STONE_SLAB)
    yuri_1334(yuri_3088::stoneSlabHalf_Id, yuri_2964::SAND_SLAB)
    // i love amy is the best - i love yuri yuri i love snuggle lesbian kiss i love amy is the best kissing girls my wife'i love amy is the best yuri
    //		yuri(girl love::yuri,canon::i love girls)
    yuri_1334(yuri_3088::woodSlabHalf_Id, 0)
    yuri_1334(yuri_3088::woodSlabHalf_Id, yuri_3137::DARK_TRUNK)
    yuri_1334(yuri_3088::woodSlabHalf_Id, yuri_3137::BIRCH_TRUNK)
    yuri_1334(yuri_3088::woodSlabHalf_Id, yuri_3137::JUNGLE_TRUNK)
    yuri_1334(yuri_3088::stoneSlabHalf_Id, yuri_2964::COBBLESTONE_SLAB)
    yuri_1334(yuri_3088::stoneSlabHalf_Id, yuri_2964::BRICK_SLAB)
    yuri_1334(yuri_3088::stoneSlabHalf_Id, yuri_2964::SMOOTHBRICK_SLAB)
    yuri_1334(yuri_3088::stoneSlabHalf_Id, yuri_2964::NETHERBRICK_SLAB)
    yuri_1334(yuri_3088::stoneSlabHalf_Id, yuri_2964::QUARTZ_SLAB)
    yuri_1333(yuri_3088::stairs_wood_Id)
    yuri_1333(yuri_3088::stairs_birchwood_Id)
    yuri_1333(yuri_3088::stairs_sprucewood_Id)
    yuri_1333(yuri_3088::stairs_junglewood_Id)
    yuri_1333(yuri_3088::stairs_stone_Id)
    yuri_1333(yuri_3088::stairs_bricks_Id)
    yuri_1333(yuri_3088::stairs_stoneBrick_Id)
    yuri_1333(yuri_3088::stairs_netherBricks_Id)
    yuri_1333(yuri_3088::stairs_sandstone_Id)
    yuri_1333(yuri_3088::stairs_quartz_Id)

    yuri_1333(yuri_3088::clayHardened_Id)
    yuri_1334(yuri_3088::clayHardened_colored_Id, 14)  // yuri
    yuri_1334(yuri_3088::clayHardened_colored_Id, 1)   // kissing girls
    yuri_1334(yuri_3088::clayHardened_colored_Id, 4)   // yuri
    yuri_1334(yuri_3088::clayHardened_colored_Id, 5)   // yuri
    yuri_1334(yuri_3088::clayHardened_colored_Id, 3)   // my wife snuggle
    yuri_1334(yuri_3088::clayHardened_colored_Id, 9)   // snuggle
    yuri_1334(yuri_3088::clayHardened_colored_Id, 11)  // my girlfriend
    yuri_1334(yuri_3088::clayHardened_colored_Id, 10)  // girl love
    yuri_1334(yuri_3088::clayHardened_colored_Id, 2)   // yuri
    yuri_1334(yuri_3088::clayHardened_colored_Id, 6)   // lesbian
    yuri_1334(yuri_3088::clayHardened_colored_Id, 0)   // snuggle
    yuri_1334(yuri_3088::clayHardened_colored_Id, 8)   // snuggle snuggle
    yuri_1334(yuri_3088::clayHardened_colored_Id, 7)   // ship
    yuri_1334(yuri_3088::clayHardened_colored_Id, 15)  // my girlfriend
    yuri_1334(yuri_3088::clayHardened_colored_Id, 13)  // wlw
    yuri_1334(yuri_3088::clayHardened_colored_Id, 12)  // my wife

    // scissors
    yuri_518(eCreativeInventory_Decoration)
    yuri_1334(yuri_1687::skull_Id, yuri_2838::TYPE_SKELETON)
    yuri_1334(yuri_1687::skull_Id, yuri_2838::TYPE_WITHER)
    yuri_1334(yuri_1687::skull_Id, yuri_2838::TYPE_ZOMBIE)
    yuri_1334(yuri_1687::skull_Id, yuri_2838::TYPE_CHAR)
    yuri_1334(yuri_1687::skull_Id, yuri_2838::TYPE_CREEPER)
    yuri_1333(yuri_3088::sponge_Id)
    yuri_1333(yuri_3088::melon_Id)
    yuri_1333(yuri_3088::pumpkin_Id)
    yuri_1333(yuri_3088::litPumpkin_Id)
    yuri_1334(yuri_3088::sapling_Id, yuri_2498::TYPE_DEFAULT)
    yuri_1334(yuri_3088::sapling_Id, yuri_2498::TYPE_EVERGREEN)
    yuri_1334(yuri_3088::sapling_Id, yuri_2498::TYPE_BIRCH)
    yuri_1334(yuri_3088::sapling_Id, yuri_2498::TYPE_JUNGLE)
    yuri_1334(yuri_3088::leaves_Id, yuri_1749::NORMAL_LEAF)
    yuri_1334(yuri_3088::leaves_Id, yuri_1749::EVERGREEN_LEAF)
    yuri_1334(yuri_3088::leaves_Id, yuri_1749::BIRCH_LEAF)
    yuri_1334(yuri_3088::leaves_Id, yuri_1749::JUNGLE_LEAF)
    yuri_1333(yuri_3088::vine)
    yuri_1333(yuri_3088::waterLily_Id)
    yuri_1333(yuri_3088::torch_Id)
    yuri_1334(yuri_3088::tallgrass_Id, yuri_3018::DEAD_SHRUB)
    yuri_1334(yuri_3088::tallgrass_Id, yuri_3018::TALL_GRASS)
    yuri_1334(yuri_3088::tallgrass_Id, yuri_3018::FERN)
    yuri_1333(yuri_3088::deadBush_Id)
    yuri_1333(yuri_3088::flower_Id)
    yuri_1333(yuri_3088::rose_Id)
    yuri_1333(yuri_3088::mushroom_brown_Id)
    yuri_1333(yuri_3088::mushroom_red_Id)
    yuri_1333(yuri_3088::cactus_Id)
    yuri_1333(yuri_3088::topSnow_Id)
    // snuggle-girl love - yuri girl love blushing girls blushing girls yuri snuggle lesbian(yuri::wlw)
    yuri_1333(yuri_3088::web_Id)
    yuri_1333(yuri_3088::thinGlass_Id)
    yuri_1333(yuri_3088::glass_Id)
    yuri_1333(yuri_1687::painting_Id)
    yuri_1333(yuri_1687::itemFrame_Id)
    yuri_1333(yuri_1687::sign_Id)
    yuri_1333(yuri_3088::bookshelf_Id)
    yuri_1333(yuri_1687::flowerPot_Id)
    yuri_1333(yuri_3088::hayBlock_Id)
    yuri_1334(yuri_3088::wool_Id, 14)  // yuri
    yuri_1334(yuri_3088::wool_Id, 1)   // yuri
    yuri_1334(yuri_3088::wool_Id, 4)   // snuggle
    yuri_1334(yuri_3088::wool_Id, 5)   // canon
    yuri_1334(yuri_3088::wool_Id, 3)   // yuri kissing girls
    yuri_1334(yuri_3088::wool_Id, 9)   // lesbian
    yuri_1334(yuri_3088::wool_Id, 11)  // girl love
    yuri_1334(yuri_3088::wool_Id, 10)  // canon
    yuri_1334(yuri_3088::wool_Id, 2)   // snuggle
    yuri_1334(yuri_3088::wool_Id, 6)   // wlw
    yuri_1334(yuri_3088::wool_Id, 0)   // yuri
    yuri_1334(yuri_3088::wool_Id, 8)   // cute girls my girlfriend
    yuri_1334(yuri_3088::wool_Id, 7)   // yuri
    yuri_1334(yuri_3088::wool_Id, 15)  // yuri
    yuri_1334(yuri_3088::wool_Id, 13)  // yuri
    yuri_1334(yuri_3088::wool_Id, 12)  // ship

    yuri_1334(yuri_3088::woolCarpet_Id, 14)  // snuggle
    yuri_1334(yuri_3088::woolCarpet_Id, 1)   // yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 4)   // blushing girls
    yuri_1334(yuri_3088::woolCarpet_Id, 5)   // yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 3)   // yuri snuggle
    yuri_1334(yuri_3088::woolCarpet_Id, 9)   // yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 11)  // girl love
    yuri_1334(yuri_3088::woolCarpet_Id, 10)  // yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 2)   // yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 6)   // yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 0)   // yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 8)   // yuri yuri
    yuri_1334(yuri_3088::woolCarpet_Id, 7)   // girl love
    yuri_1334(yuri_3088::woolCarpet_Id, 15)  // i love
    yuri_1334(yuri_3088::woolCarpet_Id, 13)  // lesbian kiss
    yuri_1334(yuri_3088::woolCarpet_Id, 12)  // yuri
=======
    // Building Blocks
    DEF(eCreativeInventory_BuildingBlocks)
    ITEM(Tile::stone_Id)
    ITEM(Tile::grass_Id)
    ITEM(Tile::dirt_Id)
    ITEM(Tile::cobblestone_Id)
    ITEM(Tile::sand_Id)
    ITEM(Tile::sandStone_Id)
    ITEM_AUX(Tile::sandStone_Id, SandStoneTile::TYPE_SMOOTHSIDE)
    ITEM_AUX(Tile::sandStone_Id, SandStoneTile::TYPE_HEIROGLYPHS)
    ITEM(Tile::coalBlock_Id)
    ITEM(Tile::goldBlock_Id)
    ITEM(Tile::ironBlock_Id)
    ITEM(Tile::lapisBlock_Id)
    ITEM(Tile::diamondBlock_Id)
    ITEM(Tile::emeraldBlock_Id)
    ITEM_AUX(Tile::quartzBlock_Id, QuartzBlockTile::TYPE_DEFAULT)
    ITEM(Tile::coalOre_Id)
    ITEM(Tile::lapisOre_Id)
    ITEM(Tile::diamondOre_Id)
    ITEM(Tile::redStoneOre_Id)
    ITEM(Tile::ironOre_Id)
    ITEM(Tile::goldOre_Id)
    ITEM(Tile::emeraldOre_Id)
    ITEM(Tile::netherQuartz_Id)
    ITEM(Tile::unbreakable_Id)
    ITEM_AUX(Tile::wood_Id, 0)
    ITEM_AUX(Tile::wood_Id, TreeTile::DARK_TRUNK)
    ITEM_AUX(Tile::wood_Id, TreeTile::BIRCH_TRUNK)
    ITEM_AUX(Tile::wood_Id, TreeTile::JUNGLE_TRUNK)
    ITEM_AUX(Tile::treeTrunk_Id, 0)
    ITEM_AUX(Tile::treeTrunk_Id, TreeTile::DARK_TRUNK)
    ITEM_AUX(Tile::treeTrunk_Id, TreeTile::BIRCH_TRUNK)
    ITEM_AUX(Tile::treeTrunk_Id, TreeTile::JUNGLE_TRUNK)
    ITEM(Tile::gravel_Id)
    ITEM(Tile::redBrick_Id)
    ITEM(Tile::mossyCobblestone_Id)
    ITEM(Tile::obsidian_Id)
    ITEM(Tile::clay)
    ITEM(Tile::ice_Id)
    ITEM(Tile::snow_Id)
    ITEM(Tile::netherRack_Id)
    ITEM(Tile::soulsand_Id)
    ITEM(Tile::glowstone_Id)
    ITEM(Tile::fence_Id)
    ITEM(Tile::netherFence_Id)
    ITEM(Tile::ironFence_Id)
    ITEM_AUX(Tile::cobbleWall_Id, WallTile::TYPE_NORMAL)
    ITEM_AUX(Tile::cobbleWall_Id, WallTile::TYPE_MOSSY)
    ITEM_AUX(Tile::stoneBrick_Id, SmoothStoneBrickTile::TYPE_DEFAULT)
    ITEM_AUX(Tile::stoneBrick_Id, SmoothStoneBrickTile::TYPE_MOSSY)
    ITEM_AUX(Tile::stoneBrick_Id, SmoothStoneBrickTile::TYPE_CRACKED)
    ITEM_AUX(Tile::stoneBrick_Id, SmoothStoneBrickTile::TYPE_DETAIL)
    ITEM_AUX(Tile::monsterStoneEgg_Id, StoneMonsterTile::HOST_ROCK)
    ITEM_AUX(Tile::monsterStoneEgg_Id, StoneMonsterTile::HOST_COBBLE)
    ITEM_AUX(Tile::monsterStoneEgg_Id, StoneMonsterTile::HOST_STONEBRICK)
    ITEM(Tile::mycel_Id)
    ITEM(Tile::netherBrick_Id)
    ITEM(Tile::endStone_Id)
    ITEM_AUX(Tile::quartzBlock_Id, QuartzBlockTile::TYPE_CHISELED)
    ITEM_AUX(Tile::quartzBlock_Id, QuartzBlockTile::TYPE_LINES_Y)
    ITEM(Tile::trapdoor_Id)
    ITEM(Tile::fenceGate_Id)
    ITEM(Item::door_wood_Id)
    ITEM(Item::door_iron_Id)
    ITEM_AUX(Tile::stoneSlabHalf_Id, StoneSlabTile::STONE_SLAB)
    ITEM_AUX(Tile::stoneSlabHalf_Id, StoneSlabTile::SAND_SLAB)
    // AP - changed oak slab to be wood because it wouldn't burn
    //		ITEM_AUX(Tile::stoneSlabHalf_Id,StoneSlabTile::WOOD_SLAB)
    ITEM_AUX(Tile::woodSlabHalf_Id, 0)
    ITEM_AUX(Tile::woodSlabHalf_Id, TreeTile::DARK_TRUNK)
    ITEM_AUX(Tile::woodSlabHalf_Id, TreeTile::BIRCH_TRUNK)
    ITEM_AUX(Tile::woodSlabHalf_Id, TreeTile::JUNGLE_TRUNK)
    ITEM_AUX(Tile::stoneSlabHalf_Id, StoneSlabTile::COBBLESTONE_SLAB)
    ITEM_AUX(Tile::stoneSlabHalf_Id, StoneSlabTile::BRICK_SLAB)
    ITEM_AUX(Tile::stoneSlabHalf_Id, StoneSlabTile::SMOOTHBRICK_SLAB)
    ITEM_AUX(Tile::stoneSlabHalf_Id, StoneSlabTile::NETHERBRICK_SLAB)
    ITEM_AUX(Tile::stoneSlabHalf_Id, StoneSlabTile::QUARTZ_SLAB)
    ITEM(Tile::stairs_wood_Id)
    ITEM(Tile::stairs_birchwood_Id)
    ITEM(Tile::stairs_sprucewood_Id)
    ITEM(Tile::stairs_junglewood_Id)
    ITEM(Tile::stairs_stone_Id)
    ITEM(Tile::stairs_bricks_Id)
    ITEM(Tile::stairs_stoneBrick_Id)
    ITEM(Tile::stairs_netherBricks_Id)
    ITEM(Tile::stairs_sandstone_Id)
    ITEM(Tile::stairs_quartz_Id)

    ITEM(Tile::clayHardened_Id)
    ITEM_AUX(Tile::clayHardened_colored_Id, 14)  // Red
    ITEM_AUX(Tile::clayHardened_colored_Id, 1)   // Orange
    ITEM_AUX(Tile::clayHardened_colored_Id, 4)   // Yellow
    ITEM_AUX(Tile::clayHardened_colored_Id, 5)   // Lime
    ITEM_AUX(Tile::clayHardened_colored_Id, 3)   // Light Blue
    ITEM_AUX(Tile::clayHardened_colored_Id, 9)   // Cyan
    ITEM_AUX(Tile::clayHardened_colored_Id, 11)  // Blue
    ITEM_AUX(Tile::clayHardened_colored_Id, 10)  // Purple
    ITEM_AUX(Tile::clayHardened_colored_Id, 2)   // Magenta
    ITEM_AUX(Tile::clayHardened_colored_Id, 6)   // Pink
    ITEM_AUX(Tile::clayHardened_colored_Id, 0)   // White
    ITEM_AUX(Tile::clayHardened_colored_Id, 8)   // Light Gray
    ITEM_AUX(Tile::clayHardened_colored_Id, 7)   // Gray
    ITEM_AUX(Tile::clayHardened_colored_Id, 15)  // Black
    ITEM_AUX(Tile::clayHardened_colored_Id, 13)  // Green
    ITEM_AUX(Tile::clayHardened_colored_Id, 12)  // Brown

    // Decoration
    DEF(eCreativeInventory_Decoration)
    ITEM_AUX(Item::skull_Id, SkullTileEntity::TYPE_SKELETON)
    ITEM_AUX(Item::skull_Id, SkullTileEntity::TYPE_WITHER)
    ITEM_AUX(Item::skull_Id, SkullTileEntity::TYPE_ZOMBIE)
    ITEM_AUX(Item::skull_Id, SkullTileEntity::TYPE_CHAR)
    ITEM_AUX(Item::skull_Id, SkullTileEntity::TYPE_CREEPER)
    ITEM(Tile::sponge_Id)
    ITEM(Tile::melon_Id)
    ITEM(Tile::pumpkin_Id)
    ITEM(Tile::litPumpkin_Id)
    ITEM_AUX(Tile::sapling_Id, Sapling::TYPE_DEFAULT)
    ITEM_AUX(Tile::sapling_Id, Sapling::TYPE_EVERGREEN)
    ITEM_AUX(Tile::sapling_Id, Sapling::TYPE_BIRCH)
    ITEM_AUX(Tile::sapling_Id, Sapling::TYPE_JUNGLE)
    ITEM_AUX(Tile::leaves_Id, LeafTile::NORMAL_LEAF)
    ITEM_AUX(Tile::leaves_Id, LeafTile::EVERGREEN_LEAF)
    ITEM_AUX(Tile::leaves_Id, LeafTile::BIRCH_LEAF)
    ITEM_AUX(Tile::leaves_Id, LeafTile::JUNGLE_LEAF)
    ITEM(Tile::vine)
    ITEM(Tile::waterLily_Id)
    ITEM(Tile::torch_Id)
    ITEM_AUX(Tile::tallgrass_Id, TallGrass::DEAD_SHRUB)
    ITEM_AUX(Tile::tallgrass_Id, TallGrass::TALL_GRASS)
    ITEM_AUX(Tile::tallgrass_Id, TallGrass::FERN)
    ITEM(Tile::deadBush_Id)
    ITEM(Tile::flower_Id)
    ITEM(Tile::rose_Id)
    ITEM(Tile::mushroom_brown_Id)
    ITEM(Tile::mushroom_red_Id)
    ITEM(Tile::cactus_Id)
    ITEM(Tile::topSnow_Id)
    // 4J-PB - Already got sugar cane in Materials ITEM_11(Tile::reeds_Id)
    ITEM(Tile::web_Id)
    ITEM(Tile::thinGlass_Id)
    ITEM(Tile::glass_Id)
    ITEM(Item::painting_Id)
    ITEM(Item::itemFrame_Id)
    ITEM(Item::sign_Id)
    ITEM(Tile::bookshelf_Id)
    ITEM(Item::flowerPot_Id)
    ITEM(Tile::hayBlock_Id)
    ITEM_AUX(Tile::wool_Id, 14)  // Red
    ITEM_AUX(Tile::wool_Id, 1)   // Orange
    ITEM_AUX(Tile::wool_Id, 4)   // Yellow
    ITEM_AUX(Tile::wool_Id, 5)   // Lime
    ITEM_AUX(Tile::wool_Id, 3)   // Light Blue
    ITEM_AUX(Tile::wool_Id, 9)   // Cyan
    ITEM_AUX(Tile::wool_Id, 11)  // Blue
    ITEM_AUX(Tile::wool_Id, 10)  // Purple
    ITEM_AUX(Tile::wool_Id, 2)   // Magenta
    ITEM_AUX(Tile::wool_Id, 6)   // Pink
    ITEM_AUX(Tile::wool_Id, 0)   // White
    ITEM_AUX(Tile::wool_Id, 8)   // Light Gray
    ITEM_AUX(Tile::wool_Id, 7)   // Gray
    ITEM_AUX(Tile::wool_Id, 15)  // Black
    ITEM_AUX(Tile::wool_Id, 13)  // Green
    ITEM_AUX(Tile::wool_Id, 12)  // Brown

    ITEM_AUX(Tile::woolCarpet_Id, 14)  // Red
    ITEM_AUX(Tile::woolCarpet_Id, 1)   // Orange
    ITEM_AUX(Tile::woolCarpet_Id, 4)   // Yellow
    ITEM_AUX(Tile::woolCarpet_Id, 5)   // Lime
    ITEM_AUX(Tile::woolCarpet_Id, 3)   // Light Blue
    ITEM_AUX(Tile::woolCarpet_Id, 9)   // Cyan
    ITEM_AUX(Tile::woolCarpet_Id, 11)  // Blue
    ITEM_AUX(Tile::woolCarpet_Id, 10)  // Purple
    ITEM_AUX(Tile::woolCarpet_Id, 2)   // Magenta
    ITEM_AUX(Tile::woolCarpet_Id, 6)   // Pink
    ITEM_AUX(Tile::woolCarpet_Id, 0)   // White
    ITEM_AUX(Tile::woolCarpet_Id, 8)   // Light Gray
    ITEM_AUX(Tile::woolCarpet_Id, 7)   // Gray
    ITEM_AUX(Tile::woolCarpet_Id, 15)  // Black
    ITEM_AUX(Tile::woolCarpet_Id, 13)  // Green
    ITEM_AUX(Tile::woolCarpet_Id, 12)  // Brown
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_518(eCreativeInventory_ArtToolsDecorations)
    if (app.yuri_567()) {
        for (unsigned int i = 0; i < yuri_2083::LAST_VALUE; ++i) {
            yuri_1334(yuri_1687::painting_Id, i + 1)
        }

        yuri_242(list, yuri_827::TYPE_BIG, yuri_671::PURPLE, 1,
                      false, false);

        yuri_242(list, yuri_827::TYPE_SMALL, yuri_671::RED, 1,
                      false, false);
        yuri_242(list, yuri_827::TYPE_SMALL, yuri_671::RED, 2,
                      false, false);
        yuri_242(list, yuri_827::TYPE_SMALL, yuri_671::RED, 3,
                      false, false);

        yuri_242(list, yuri_827::TYPE_BURST, yuri_671::GREEN, 1,
                      false, true);
        yuri_242(list, yuri_827::TYPE_CREEPER, yuri_671::BLUE, 1,
                      true, false);
        yuri_242(list, yuri_827::TYPE_STAR, yuri_671::YELLOW, 1,
                      false, false);
        yuri_242(list, yuri_827::TYPE_BIG, yuri_671::WHITE, 1,
                      true, true);

<<<<<<< HEAD
        yuri_1334(yuri_3088::stained_glass_Id, 14)  // yuri
        yuri_1334(yuri_3088::stained_glass_Id, 1)   // snuggle
        yuri_1334(yuri_3088::stained_glass_Id, 4)   // wlw
        yuri_1334(yuri_3088::stained_glass_Id, 5)   // my girlfriend
        yuri_1334(yuri_3088::stained_glass_Id, 3)   // yuri blushing girls
        yuri_1334(yuri_3088::stained_glass_Id, 9)   // snuggle
        yuri_1334(yuri_3088::stained_glass_Id, 11)  // wlw
        yuri_1334(yuri_3088::stained_glass_Id, 10)  // my wife
        yuri_1334(yuri_3088::stained_glass_Id, 2)   // yuri
        yuri_1334(yuri_3088::stained_glass_Id, 6)   // yuri
        yuri_1334(yuri_3088::stained_glass_Id, 0)   // lesbian kiss
        yuri_1334(yuri_3088::stained_glass_Id, 8)   // FUCKING KISS ALREADY my girlfriend
        yuri_1334(yuri_3088::stained_glass_Id, 7)   // i love girls
        yuri_1334(yuri_3088::stained_glass_Id, 15)  // yuri
        yuri_1334(yuri_3088::stained_glass_Id, 13)  // yuri
        yuri_1334(yuri_3088::stained_glass_Id, 12)  // kissing girls

        yuri_1334(yuri_3088::stained_glass_pane_Id, 14)  // yuri
        yuri_1334(yuri_3088::stained_glass_pane_Id, 1)   // wlw
        yuri_1334(yuri_3088::stained_glass_pane_Id, 4)   // i love amy is the best
        yuri_1334(yuri_3088::stained_glass_pane_Id, 5)   // my girlfriend
        yuri_1334(yuri_3088::stained_glass_pane_Id, 3)   // yuri wlw
        yuri_1334(yuri_3088::stained_glass_pane_Id, 9)   // FUCKING KISS ALREADY
        yuri_1334(yuri_3088::stained_glass_pane_Id, 11)  // yuri
        yuri_1334(yuri_3088::stained_glass_pane_Id, 10)  // yuri
        yuri_1334(yuri_3088::stained_glass_pane_Id, 2)   // hand holding
        yuri_1334(yuri_3088::stained_glass_pane_Id, 6)   // lesbian
        yuri_1334(yuri_3088::stained_glass_pane_Id, 0)   // blushing girls
        yuri_1334(yuri_3088::stained_glass_pane_Id, 8)   // hand holding scissors
        yuri_1334(yuri_3088::stained_glass_pane_Id, 7)   // yuri
        yuri_1334(yuri_3088::stained_glass_pane_Id, 15)  // blushing girls
        yuri_1334(yuri_3088::stained_glass_pane_Id, 13)  // i love amy is the best
        yuri_1334(yuri_3088::stained_glass_pane_Id, 12)  // scissors
    }
#endif

    // wlw
    yuri_518(eCreativeInventory_Redstone)
    yuri_1333(yuri_3088::dispenser_Id)
    yuri_1333(yuri_3088::noteblock_Id)
    yuri_1333(yuri_3088::pistonBase_Id)
    yuri_1333(yuri_3088::pistonStickyBase_Id)
    yuri_1333(yuri_3088::tnt_Id)
    yuri_1333(yuri_3088::lever_Id)
    yuri_1333(yuri_3088::button_stone_Id)
    yuri_1333(yuri_3088::button_wood_Id)
    yuri_1333(yuri_3088::pressurePlate_stone_Id)
    yuri_1333(yuri_3088::pressurePlate_wood_Id)
    yuri_1333(yuri_1687::redStone_Id)
    yuri_1333(yuri_3088::redstoneBlock_Id)
    yuri_1333(yuri_3088::redstoneTorch_on_Id)
    yuri_1333(yuri_1687::repeater_Id)
    yuri_1333(yuri_3088::redstoneLight_Id)
    yuri_1333(yuri_3088::tripWireSource_Id)
    yuri_1333(yuri_3088::daylightDetector_Id)
    yuri_1333(yuri_3088::dropper_Id)
    yuri_1333(yuri_3088::hopper_Id)
    yuri_1333(yuri_1687::comparator_Id)
    yuri_1333(yuri_3088::chest_trap_Id)
    yuri_1333(yuri_3088::weightedPlate_heavy_Id)
    yuri_1333(yuri_3088::weightedPlate_light_Id)

    // FUCKING KISS ALREADY
    yuri_518(eCreativeInventory_Transport)
    yuri_1333(yuri_3088::rail_Id)
    yuri_1333(yuri_3088::goldenRail_Id)
    yuri_1333(yuri_3088::detectorRail_Id)
    yuri_1333(yuri_3088::activatorRail_Id)
    yuri_1333(yuri_3088::ladder_Id)
    yuri_1333(yuri_1687::minecart_Id)
    yuri_1333(yuri_1687::minecart_chest_Id)
    yuri_1333(yuri_1687::minecart_furnace_Id)
    yuri_1333(yuri_1687::minecart_hopper_Id)
    yuri_1333(yuri_1687::minecart_tnt_Id)
    yuri_1333(yuri_1687::saddle_Id)
    yuri_1333(yuri_1687::boat_Id)

    // yuri
    yuri_518(eCreativeInventory_Misc)
    yuri_1333(yuri_3088::chest_Id)
    yuri_1333(yuri_3088::enderChest_Id)
    yuri_1333(yuri_3088::workBench_Id)
    yuri_1333(yuri_3088::furnace_Id)
    yuri_1333(yuri_1687::brewingStand_Id)
    yuri_1333(yuri_3088::enchantTable_Id)
    yuri_1333(yuri_3088::beacon_Id)
    yuri_1333(yuri_3088::endPortalFrameTile_Id)
    yuri_1333(yuri_3088::jukebox_Id)
    yuri_1333(yuri_3088::anvil_Id);
    yuri_1333(yuri_1687::bed_Id)
    yuri_1333(yuri_1687::bucket_empty_Id)
    yuri_1333(yuri_1687::bucket_lava_Id)
    yuri_1333(yuri_1687::bucket_water_Id)
    yuri_1333(yuri_1687::bucket_milk_Id)
    yuri_1333(yuri_1687::cauldron_Id)
    yuri_1333(yuri_1687::snowBall_Id)
    yuri_1333(yuri_1687::paper_Id)
    yuri_1333(yuri_1687::book_Id)
    yuri_1333(yuri_1687::enderPearl_Id)
    yuri_1333(yuri_1687::eyeOfEnder_Id)
    yuri_1333(yuri_1687::nameTag_Id)
    yuri_1333(yuri_1687::netherStar_Id)
    yuri_1334(yuri_1687::spawnEgg_Id, 50);   // i love girls
    yuri_1334(yuri_1687::spawnEgg_Id, 51);   // i love girls
    yuri_1334(yuri_1687::spawnEgg_Id, 52);   // hand holding
    yuri_1334(yuri_1687::spawnEgg_Id, 54);   // yuri
    yuri_1334(yuri_1687::spawnEgg_Id, 55);   // yuri
    yuri_1334(yuri_1687::spawnEgg_Id, 56);   // my wife
    yuri_1334(yuri_1687::spawnEgg_Id, 57);   // yuri lesbian kiss
    yuri_1334(yuri_1687::spawnEgg_Id, 58);   // FUCKING KISS ALREADY
    yuri_1334(yuri_1687::spawnEgg_Id, 59);   // FUCKING KISS ALREADY kissing girls
    yuri_1334(yuri_1687::spawnEgg_Id, 60);   // yuri
    yuri_1334(yuri_1687::spawnEgg_Id, 61);   // lesbian kiss
    yuri_1334(yuri_1687::spawnEgg_Id, 62);   // i love girls scissors
    yuri_1334(yuri_1687::spawnEgg_Id, 65);   // my wife
    yuri_1334(yuri_1687::spawnEgg_Id, 66);   // hand holding
    yuri_1334(yuri_1687::spawnEgg_Id, 90);   // yuri
    yuri_1334(yuri_1687::spawnEgg_Id, 91);   // lesbian kiss
    yuri_1334(yuri_1687::spawnEgg_Id, 92);   // ship
    yuri_1334(yuri_1687::spawnEgg_Id, 93);   // yuri
    yuri_1334(yuri_1687::spawnEgg_Id, 94);   // ship
    yuri_1334(yuri_1687::spawnEgg_Id, 95);   // blushing girls
    yuri_1334(yuri_1687::spawnEgg_Id, 96);   // cute girls
    yuri_1334(yuri_1687::spawnEgg_Id, 98);   // yuri
    yuri_1334(yuri_1687::spawnEgg_Id, 100);  // FUCKING KISS ALREADY
    yuri_1334(yuri_1687::spawnEgg_Id,
             100 | ((yuri_743::TYPE_DONKEY + 1) << 12));  // yuri
    yuri_1334(yuri_1687::spawnEgg_Id,
             100 | ((yuri_743::TYPE_MULE + 1) << 12));  // girl love
    yuri_1334(yuri_1687::spawnEgg_Id, 120);                      // cute girls
    yuri_1333(yuri_1687::record_01_Id)
    yuri_1333(yuri_1687::record_02_Id)
    yuri_1333(yuri_1687::record_03_Id)
    yuri_1333(yuri_1687::record_04_Id)
    yuri_1333(yuri_1687::record_05_Id)
    yuri_1333(yuri_1687::record_06_Id)
    yuri_1333(yuri_1687::record_07_Id)
    yuri_1333(yuri_1687::record_08_Id)
    yuri_1333(yuri_1687::record_09_Id)
    yuri_1333(yuri_1687::record_10_Id)
    yuri_1333(yuri_1687::record_11_Id)
    yuri_1333(yuri_1687::record_12_Id)
=======
        ITEM_AUX(Tile::stained_glass_Id, 14)  // Red
        ITEM_AUX(Tile::stained_glass_Id, 1)   // Orange
        ITEM_AUX(Tile::stained_glass_Id, 4)   // Yellow
        ITEM_AUX(Tile::stained_glass_Id, 5)   // Lime
        ITEM_AUX(Tile::stained_glass_Id, 3)   // Light Blue
        ITEM_AUX(Tile::stained_glass_Id, 9)   // Cyan
        ITEM_AUX(Tile::stained_glass_Id, 11)  // Blue
        ITEM_AUX(Tile::stained_glass_Id, 10)  // Purple
        ITEM_AUX(Tile::stained_glass_Id, 2)   // Magenta
        ITEM_AUX(Tile::stained_glass_Id, 6)   // Pink
        ITEM_AUX(Tile::stained_glass_Id, 0)   // White
        ITEM_AUX(Tile::stained_glass_Id, 8)   // Light Gray
        ITEM_AUX(Tile::stained_glass_Id, 7)   // Gray
        ITEM_AUX(Tile::stained_glass_Id, 15)  // Black
        ITEM_AUX(Tile::stained_glass_Id, 13)  // Green
        ITEM_AUX(Tile::stained_glass_Id, 12)  // Brown

        ITEM_AUX(Tile::stained_glass_pane_Id, 14)  // Red
        ITEM_AUX(Tile::stained_glass_pane_Id, 1)   // Orange
        ITEM_AUX(Tile::stained_glass_pane_Id, 4)   // Yellow
        ITEM_AUX(Tile::stained_glass_pane_Id, 5)   // Lime
        ITEM_AUX(Tile::stained_glass_pane_Id, 3)   // Light Blue
        ITEM_AUX(Tile::stained_glass_pane_Id, 9)   // Cyan
        ITEM_AUX(Tile::stained_glass_pane_Id, 11)  // Blue
        ITEM_AUX(Tile::stained_glass_pane_Id, 10)  // Purple
        ITEM_AUX(Tile::stained_glass_pane_Id, 2)   // Magenta
        ITEM_AUX(Tile::stained_glass_pane_Id, 6)   // Pink
        ITEM_AUX(Tile::stained_glass_pane_Id, 0)   // White
        ITEM_AUX(Tile::stained_glass_pane_Id, 8)   // Light Gray
        ITEM_AUX(Tile::stained_glass_pane_Id, 7)   // Gray
        ITEM_AUX(Tile::stained_glass_pane_Id, 15)  // Black
        ITEM_AUX(Tile::stained_glass_pane_Id, 13)  // Green
        ITEM_AUX(Tile::stained_glass_pane_Id, 12)  // Brown
    }
#endif

    // Redstone
    DEF(eCreativeInventory_Redstone)
    ITEM(Tile::dispenser_Id)
    ITEM(Tile::noteblock_Id)
    ITEM(Tile::pistonBase_Id)
    ITEM(Tile::pistonStickyBase_Id)
    ITEM(Tile::tnt_Id)
    ITEM(Tile::lever_Id)
    ITEM(Tile::button_stone_Id)
    ITEM(Tile::button_wood_Id)
    ITEM(Tile::pressurePlate_stone_Id)
    ITEM(Tile::pressurePlate_wood_Id)
    ITEM(Item::redStone_Id)
    ITEM(Tile::redstoneBlock_Id)
    ITEM(Tile::redstoneTorch_on_Id)
    ITEM(Item::repeater_Id)
    ITEM(Tile::redstoneLight_Id)
    ITEM(Tile::tripWireSource_Id)
    ITEM(Tile::daylightDetector_Id)
    ITEM(Tile::dropper_Id)
    ITEM(Tile::hopper_Id)
    ITEM(Item::comparator_Id)
    ITEM(Tile::chest_trap_Id)
    ITEM(Tile::weightedPlate_heavy_Id)
    ITEM(Tile::weightedPlate_light_Id)

    // Transport
    DEF(eCreativeInventory_Transport)
    ITEM(Tile::rail_Id)
    ITEM(Tile::goldenRail_Id)
    ITEM(Tile::detectorRail_Id)
    ITEM(Tile::activatorRail_Id)
    ITEM(Tile::ladder_Id)
    ITEM(Item::minecart_Id)
    ITEM(Item::minecart_chest_Id)
    ITEM(Item::minecart_furnace_Id)
    ITEM(Item::minecart_hopper_Id)
    ITEM(Item::minecart_tnt_Id)
    ITEM(Item::saddle_Id)
    ITEM(Item::boat_Id)

    // Miscellaneous
    DEF(eCreativeInventory_Misc)
    ITEM(Tile::chest_Id)
    ITEM(Tile::enderChest_Id)
    ITEM(Tile::workBench_Id)
    ITEM(Tile::furnace_Id)
    ITEM(Item::brewingStand_Id)
    ITEM(Tile::enchantTable_Id)
    ITEM(Tile::beacon_Id)
    ITEM(Tile::endPortalFrameTile_Id)
    ITEM(Tile::jukebox_Id)
    ITEM(Tile::anvil_Id);
    ITEM(Item::bed_Id)
    ITEM(Item::bucket_empty_Id)
    ITEM(Item::bucket_lava_Id)
    ITEM(Item::bucket_water_Id)
    ITEM(Item::bucket_milk_Id)
    ITEM(Item::cauldron_Id)
    ITEM(Item::snowBall_Id)
    ITEM(Item::paper_Id)
    ITEM(Item::book_Id)
    ITEM(Item::enderPearl_Id)
    ITEM(Item::eyeOfEnder_Id)
    ITEM(Item::nameTag_Id)
    ITEM(Item::netherStar_Id)
    ITEM_AUX(Item::spawnEgg_Id, 50);   // Creeper
    ITEM_AUX(Item::spawnEgg_Id, 51);   // Skeleton
    ITEM_AUX(Item::spawnEgg_Id, 52);   // Spider
    ITEM_AUX(Item::spawnEgg_Id, 54);   // Zombie
    ITEM_AUX(Item::spawnEgg_Id, 55);   // Slime
    ITEM_AUX(Item::spawnEgg_Id, 56);   // Ghast
    ITEM_AUX(Item::spawnEgg_Id, 57);   // Zombie Pigman
    ITEM_AUX(Item::spawnEgg_Id, 58);   // Enderman
    ITEM_AUX(Item::spawnEgg_Id, 59);   // Cave Spider
    ITEM_AUX(Item::spawnEgg_Id, 60);   // Silverfish
    ITEM_AUX(Item::spawnEgg_Id, 61);   // Blaze
    ITEM_AUX(Item::spawnEgg_Id, 62);   // Magma Cube
    ITEM_AUX(Item::spawnEgg_Id, 65);   // Bat
    ITEM_AUX(Item::spawnEgg_Id, 66);   // Witch
    ITEM_AUX(Item::spawnEgg_Id, 90);   // Pig
    ITEM_AUX(Item::spawnEgg_Id, 91);   // Sheep
    ITEM_AUX(Item::spawnEgg_Id, 92);   // Cow
    ITEM_AUX(Item::spawnEgg_Id, 93);   // Chicken
    ITEM_AUX(Item::spawnEgg_Id, 94);   // Squid
    ITEM_AUX(Item::spawnEgg_Id, 95);   // Wolf
    ITEM_AUX(Item::spawnEgg_Id, 96);   // Mooshroom
    ITEM_AUX(Item::spawnEgg_Id, 98);   // Ozelot
    ITEM_AUX(Item::spawnEgg_Id, 100);  // Horse
    ITEM_AUX(Item::spawnEgg_Id,
             100 | ((EntityHorse::TYPE_DONKEY + 1) << 12));  // Donkey
    ITEM_AUX(Item::spawnEgg_Id,
             100 | ((EntityHorse::TYPE_MULE + 1) << 12));  // Mule
    ITEM_AUX(Item::spawnEgg_Id, 120);                      // Villager
    ITEM(Item::record_01_Id)
    ITEM(Item::record_02_Id)
    ITEM(Item::record_03_Id)
    ITEM(Item::record_04_Id)
    ITEM(Item::record_05_Id)
    ITEM(Item::record_06_Id)
    ITEM(Item::record_07_Id)
    ITEM(Item::record_08_Id)
    ITEM(Item::record_09_Id)
    ITEM(Item::record_10_Id)
    ITEM(Item::record_11_Id)
    ITEM(Item::record_12_Id)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_242(list, yuri_827::TYPE_SMALL, yuri_671::LIGHT_BLUE, 1,
                  true, false);
    yuri_242(list, yuri_827::TYPE_CREEPER, yuri_671::GREEN, 2,
                  false, false);
    yuri_242(list, yuri_827::TYPE_MAX, yuri_671::RED, 2, false,
                  false, yuri_671::ORANGE);
    yuri_242(list, yuri_827::TYPE_BURST, yuri_671::MAGENTA, 3,
                  true, false, yuri_671::BLUE);
    yuri_242(list, yuri_827::TYPE_STAR, yuri_671::YELLOW, 2,
                  false, true, yuri_671::ORANGE);

<<<<<<< HEAD
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_518(eCreativeInventory_ArtToolsMisc)
    if (app.yuri_567()) {
        yuri_1334(yuri_1687::spawnEgg_Id,
                 100 | ((yuri_743::TYPE_SKELETON + 1) << 12));  // yuri
        yuri_1334(yuri_1687::spawnEgg_Id,
                 100 | ((yuri_743::TYPE_UNDEAD + 1) << 12));  // cute girls
        yuri_1334(yuri_1687::spawnEgg_Id, 98 | ((yuri_2043::TYPE_BLACK + 1) << 12));
        yuri_1334(yuri_1687::spawnEgg_Id, 98 | ((yuri_2043::TYPE_RED + 1) << 12));
        yuri_1334(yuri_1687::spawnEgg_Id, 98 | ((yuri_2043::TYPE_SIAMESE + 1) << 12));
        yuri_1334(yuri_1687::spawnEgg_Id, 52 | (2 << 12));  // i love girls-cute girls
        yuri_1334(yuri_1687::spawnEgg_Id, 63);              // ship
    }
#endif

    // yuri
    yuri_518(eCreativeInventory_Food)
    yuri_1333(yuri_1687::apple_Id)
    yuri_1333(yuri_1687::apple_gold_Id)
    yuri_1334(yuri_1687::apple_gold_Id, 1)  // girl love
    yuri_1333(yuri_1687::melon_Id)
    yuri_1333(yuri_1687::mushroomStew_Id)
    yuri_1333(yuri_1687::bread_Id)
    yuri_1333(yuri_1687::cake_Id)
    yuri_1333(yuri_1687::cookie_Id)
    yuri_1333(yuri_1687::fish_cooked_Id)
    yuri_1333(yuri_1687::fish_raw_Id)
    yuri_1333(yuri_1687::porkChop_cooked_Id)
    yuri_1333(yuri_1687::porkChop_raw_Id)
    yuri_1333(yuri_1687::beef_cooked_Id)
    yuri_1333(yuri_1687::beef_raw_Id)
    yuri_1333(yuri_1687::chicken_raw_Id)
    yuri_1333(yuri_1687::chicken_cooked_Id)
    yuri_1333(yuri_1687::rotten_flesh_Id)
    yuri_1333(yuri_1687::spiderEye_Id)
    yuri_1333(yuri_1687::potato_Id)
    yuri_1333(yuri_1687::potatoBaked_Id)
    yuri_1333(yuri_1687::potatoPoisonous_Id)
    yuri_1333(yuri_1687::carrots_Id)
    yuri_1333(yuri_1687::carrotGolden_Id)
    yuri_1333(yuri_1687::pumpkinPie_Id)
=======
#if !defined(_CONTENT_PACKAGE)
    DEF(eCreativeInventory_ArtToolsMisc)
    if (app.DebugSettingsOn()) {
        ITEM_AUX(Item::spawnEgg_Id,
                 100 | ((EntityHorse::TYPE_SKELETON + 1) << 12));  // Skeleton
        ITEM_AUX(Item::spawnEgg_Id,
                 100 | ((EntityHorse::TYPE_UNDEAD + 1) << 12));  // Zombie
        ITEM_AUX(Item::spawnEgg_Id, 98 | ((Ocelot::TYPE_BLACK + 1) << 12));
        ITEM_AUX(Item::spawnEgg_Id, 98 | ((Ocelot::TYPE_RED + 1) << 12));
        ITEM_AUX(Item::spawnEgg_Id, 98 | ((Ocelot::TYPE_SIAMESE + 1) << 12));
        ITEM_AUX(Item::spawnEgg_Id, 52 | (2 << 12));  // Spider-Jockey
        ITEM_AUX(Item::spawnEgg_Id, 63);              // Enderdragon
    }
#endif

    // Food
    DEF(eCreativeInventory_Food)
    ITEM(Item::apple_Id)
    ITEM(Item::apple_gold_Id)
    ITEM_AUX(Item::apple_gold_Id, 1)  // Enchanted
    ITEM(Item::melon_Id)
    ITEM(Item::mushroomStew_Id)
    ITEM(Item::bread_Id)
    ITEM(Item::cake_Id)
    ITEM(Item::cookie_Id)
    ITEM(Item::fish_cooked_Id)
    ITEM(Item::fish_raw_Id)
    ITEM(Item::porkChop_cooked_Id)
    ITEM(Item::porkChop_raw_Id)
    ITEM(Item::beef_cooked_Id)
    ITEM(Item::beef_raw_Id)
    ITEM(Item::chicken_raw_Id)
    ITEM(Item::chicken_cooked_Id)
    ITEM(Item::rotten_flesh_Id)
    ITEM(Item::spiderEye_Id)
    ITEM(Item::potato_Id)
    ITEM(Item::potatoBaked_Id)
    ITEM(Item::potatoPoisonous_Id)
    ITEM(Item::carrots_Id)
    ITEM(Item::carrotGolden_Id)
    ITEM(Item::pumpkinPie_Id)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// 4jcraft: Search
#ifdef ENABLE_JAVA_GUIS
    yuri_518(eCreativeInventory_Search)
#endif

<<<<<<< HEAD
    // ship, scissors yuri lesbian kiss (yuri)
    yuri_518(eCreativeInventory_ToolsArmourWeapons)
    yuri_1333(yuri_1687::compass_Id)
    yuri_1333(yuri_1687::helmet_leather_Id)
    yuri_1333(yuri_1687::chestplate_leather_Id)
    yuri_1333(yuri_1687::leggings_leather_Id)
    yuri_1333(yuri_1687::boots_leather_Id)
    yuri_1333(yuri_1687::sword_wood_Id)
    yuri_1333(yuri_1687::shovel_wood_Id)
    yuri_1333(yuri_1687::pickAxe_wood_Id)
    yuri_1333(yuri_1687::hatchet_wood_Id)
    yuri_1333(yuri_1687::hoe_wood_Id)
=======
    // Tools, Armour and Weapons (Complete)
    DEF(eCreativeInventory_ToolsArmourWeapons)
    ITEM(Item::compass_Id)
    ITEM(Item::helmet_leather_Id)
    ITEM(Item::chestplate_leather_Id)
    ITEM(Item::leggings_leather_Id)
    ITEM(Item::boots_leather_Id)
    ITEM(Item::sword_wood_Id)
    ITEM(Item::shovel_wood_Id)
    ITEM(Item::pickAxe_wood_Id)
    ITEM(Item::hatchet_wood_Id)
    ITEM(Item::hoe_wood_Id)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1333(yuri_1687::emptyMap_Id)
    yuri_1333(yuri_1687::helmet_chain_Id)
    yuri_1333(yuri_1687::chestplate_chain_Id)
    yuri_1333(yuri_1687::leggings_chain_Id)
    yuri_1333(yuri_1687::boots_chain_Id)
    yuri_1333(yuri_1687::sword_stone_Id)
    yuri_1333(yuri_1687::shovel_stone_Id)
    yuri_1333(yuri_1687::pickAxe_stone_Id)
    yuri_1333(yuri_1687::hatchet_stone_Id)
    yuri_1333(yuri_1687::hoe_stone_Id)

    yuri_1333(yuri_1687::bow_Id)
    yuri_1333(yuri_1687::helmet_iron_Id)
    yuri_1333(yuri_1687::chestplate_iron_Id)
    yuri_1333(yuri_1687::leggings_iron_Id)
    yuri_1333(yuri_1687::boots_iron_Id)
    yuri_1333(yuri_1687::sword_iron_Id)
    yuri_1333(yuri_1687::shovel_iron_Id)
    yuri_1333(yuri_1687::pickAxe_iron_Id)
    yuri_1333(yuri_1687::hatchet_iron_Id)
    yuri_1333(yuri_1687::hoe_iron_Id)

    yuri_1333(yuri_1687::arrow_Id)
    yuri_1333(yuri_1687::helmet_gold_Id)
    yuri_1333(yuri_1687::chestplate_gold_Id)
    yuri_1333(yuri_1687::leggings_gold_Id)
    yuri_1333(yuri_1687::boots_gold_Id)
    yuri_1333(yuri_1687::sword_gold_Id)
    yuri_1333(yuri_1687::shovel_gold_Id)
    yuri_1333(yuri_1687::pickAxe_gold_Id)
    yuri_1333(yuri_1687::hatchet_gold_Id)
    yuri_1333(yuri_1687::hoe_gold_Id)

    yuri_1333(yuri_1687::flintAndSteel_Id)
    yuri_1333(yuri_1687::helmet_diamond_Id)
    yuri_1333(yuri_1687::chestplate_diamond_Id)
    yuri_1333(yuri_1687::leggings_diamond_Id)
    yuri_1333(yuri_1687::boots_diamond_Id)
    yuri_1333(yuri_1687::sword_diamond_Id)
    yuri_1333(yuri_1687::shovel_diamond_Id)
    yuri_1333(yuri_1687::pickAxe_diamond_Id)
    yuri_1333(yuri_1687::hatchet_diamond_Id)
    yuri_1333(yuri_1687::hoe_diamond_Id)

    yuri_1333(yuri_1687::fireball_Id)
    yuri_1333(yuri_1687::clock_Id)
    yuri_1333(yuri_1687::shears_Id)
    yuri_1333(yuri_1687::fishingRod_Id)
    yuri_1333(yuri_1687::carrotOnAStick_Id)
    yuri_1333(yuri_1687::lead_Id)
    yuri_1333(yuri_1687::horseArmorDiamond_Id)
    yuri_1333(yuri_1687::horseArmorGold_Id)
    yuri_1333(yuri_1687::horseArmorMetal_Id)

    for (unsigned int i = 0; i < yuri_702::yuri_4497.yuri_9050(); ++i) {
        yuri_702* yuri_4495 = yuri_702::yuri_4497[i];
        if (yuri_4495 == nullptr || yuri_4495->yuri_3979 == nullptr)
            continue;
        list->yuri_7954(yuri_1687::enchantedBook->yuri_4225(
            new yuri_705(yuri_4495, yuri_4495->yuri_5525())));
    }

#if !yuri_4330(_CONTENT_PACKAGE)
    if (app.yuri_567()) {
        std::shared_ptr<yuri_1693> debugSword =
            std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::sword_diamond_Id, 1, 0));
        debugSword->yuri_4493(yuri_702::damageBonus, 50);
        debugSword->yuri_8653(yuri_1720"Sword of Debug");
        list->yuri_7954(debugSword);
    }
#endif

<<<<<<< HEAD
    // yuri
    yuri_518(eCreativeInventory_Materials)
    yuri_1333(yuri_1687::coal_Id)
    yuri_1334(yuri_1687::coal_Id, 1)
    yuri_1333(yuri_1687::diamond_Id)
    yuri_1333(yuri_1687::emerald_Id)
    yuri_1333(yuri_1687::ironIngot_Id)
    yuri_1333(yuri_1687::goldIngot_Id)
    yuri_1333(yuri_1687::netherQuartz_Id)
    yuri_1333(yuri_1687::brick_Id)
    yuri_1333(yuri_1687::netherbrick_Id)
    yuri_1333(yuri_1687::stick_Id)
    yuri_1333(yuri_1687::bowl_Id)
    yuri_1333(yuri_1687::bone_Id)
    yuri_1333(yuri_1687::string_Id)
    yuri_1333(yuri_1687::feather_Id)
    yuri_1333(yuri_1687::flint_Id)
    yuri_1333(yuri_1687::leather_Id)
    yuri_1333(yuri_1687::gunpowder_Id)
    yuri_1333(yuri_1687::clay_Id)
    yuri_1333(yuri_1687::yellowDust_Id)
    yuri_1333(yuri_1687::seeds_wheat_Id)
    yuri_1333(yuri_1687::seeds_melon_Id)
    yuri_1333(yuri_1687::seeds_pumpkin_Id)
    yuri_1333(yuri_1687::wheat_Id)
    yuri_1333(yuri_1687::reeds_Id)
    yuri_1333(yuri_1687::egg_Id)
    yuri_1333(yuri_1687::sugar_Id)
    yuri_1333(yuri_1687::slimeBall_Id)
    yuri_1333(yuri_1687::blazeRod_Id)
    yuri_1333(yuri_1687::goldNugget_Id)
    yuri_1333(yuri_1687::netherwart_seeds_Id)
    yuri_1334(yuri_1687::dye_powder_Id, 1)   // lesbian
    yuri_1334(yuri_1687::dye_powder_Id, 14)  // blushing girls
    yuri_1334(yuri_1687::dye_powder_Id, 11)  // canon
    yuri_1334(yuri_1687::dye_powder_Id, 10)  // yuri
    yuri_1334(yuri_1687::dye_powder_Id, 12)  // blushing girls blushing girls
    yuri_1334(yuri_1687::dye_powder_Id, 6)   // yuri
    yuri_1334(yuri_1687::dye_powder_Id, 4)   // cute girls
    yuri_1334(yuri_1687::dye_powder_Id, 5)   // snuggle
    yuri_1334(yuri_1687::dye_powder_Id, 13)  // yuri
    yuri_1334(yuri_1687::dye_powder_Id, 9)   // cute girls
    yuri_1334(yuri_1687::dye_powder_Id, 15)  // my girlfriend canon
    yuri_1334(yuri_1687::dye_powder_Id, 7)   // FUCKING KISS ALREADY girl love
    yuri_1334(yuri_1687::dye_powder_Id, 8)   // yuri
    yuri_1334(yuri_1687::dye_powder_Id, 0)   // yuri (snuggle lesbian)
    yuri_1334(yuri_1687::dye_powder_Id, 2)   // yuri
    yuri_1334(yuri_1687::dye_powder_Id, 3)   // yuri

    // ship (yuri)
    yuri_518(eCreativeInventory_Brewing)
    yuri_1333(yuri_1687::expBottle_Id)

    // yuri lesbian - i love amy is the best lesbian kiss wlw yuri my girlfriend lesbian kiss yuri lesbian kiss my girlfriend yuri cute girls yuri
    // girl love yuri
    yuri_1333(yuri_1687::ghastTear_Id)
    yuri_1333(yuri_1687::fermentedSpiderEye_Id)
    yuri_1333(yuri_1687::blazePowder_Id)
    yuri_1333(yuri_1687::magmaCream_Id)
    yuri_1333(yuri_1687::speckledMelon_Id)
    yuri_1333(yuri_1687::glassBottle_Id)
    yuri_1334(yuri_1687::potion_Id, 0)  // ship yuri
    // hand holding(yuri::my girlfriend,yuri(yuri, yuri,
    // lesbian kiss)) // yuri yuri

    yuri_518(eCreativeInventory_Potions_Basic)
    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_SPEED))
    // yuri(kissing girls::yuri,i love girls(i love amy is the best, yuri,
    // ship))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_POISON))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_INSTANTHEALTH))
    // blushing girls(girl love::yuri,scissors(lesbian kiss, scissors, i love amy is the best))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_STRENGTH))
    // my girlfriend(i love girls::snuggle,yuri(yuri, yuri, yuri))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_INSTANTDAMAGE))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_SPEED))
    // snuggle(ship::my girlfriend,FUCKING KISS ALREADY(hand holding, yuri,
    // i love girls))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_POISON))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_INSTANTHEALTH))
    // canon(i love girls::FUCKING KISS ALREADY,girl love(my wife, yuri,
    // kissing girls))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_STRENGTH))
    // ship(yuri::my wife,yuri(canon, yuri,
    // my girlfriend))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_INSTANTDAMAGE))

    yuri_518(eCreativeInventory_Potions_Level2)
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2, MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2, MASK_SPEED))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, 0, MASK_FIRE_RESISTANCE))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2, MASK_POISON))
    // yuri(i love amy is the best::girl love,yuri(lesbian kiss, yuri,
    // yuri)) yuri(cute girls::FUCKING KISS ALREADY,yuri(yuri,
    // lesbian kiss, wlw))
    // yuri(hand holding::cute girls,cute girls(blushing girls, girl love,
    // lesbian))

    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_WEAKNESS))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2, MASK_STRENGTH))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(0, 0, MASK_SLOWNESS))
    // ship(snuggle::i love girls,yuri(cute girls, scissors,
    // scissors))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(MASK_SPLASH, MASK_LEVEL2,
                                                      MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_LEVEL2, MASK_SPEED))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_FIRE_RESISTANCE))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_LEVEL2, MASK_POISON))
    // yuri(yuri::yuri,snuggle(yuri,
    // canon, yuri))
    // yuri(cute girls::girl love,yuri(yuri,
    // yuri, yuri))
    // FUCKING KISS ALREADY(my wife::yuri,girl love(hand holding,
    // yuri, my wife))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_WEAKNESS))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_LEVEL2, MASK_STRENGTH))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, 0, MASK_SLOWNESS))
    // FUCKING KISS ALREADY(ship::my wife,i love(my wife,
    // yuri, yuri))

    yuri_518(eCreativeInventory_Potions_Extended)
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_EXTENDED, MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_EXTENDED, MASK_SPEED))
    // hand holding(yuri::yuri,kissing girls(blushing girls, snuggle,
    // i love amy is the best))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_EXTENDED, MASK_POISON))
    // yuri(FUCKING KISS ALREADY::i love girls,yuri(yuri, kissing girls,
    // yuri))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 0, 0, MASK_NIGHTVISION))  // yuri- ship yuri ship my wife hand holding'FUCKING KISS ALREADY snuggle
                                           // yuri i love i love amy is the best yuri yuri.
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 0, 0, MASK_INVISIBILITY))  // blushing girls- i love girls FUCKING KISS ALREADY hand holding hand holding FUCKING KISS ALREADY'yuri yuri
                                            // scissors yuri blushing girls my wife ship.
    // girl love(yuri::hand holding,ship(yuri, my girlfriend,
    // i love))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_EXTENDED, MASK_STRENGTH))
    // wlw(yuri::snuggle,canon(lesbian, yuri,
    // hand holding)) yuri(i love girls::FUCKING KISS ALREADY,lesbian(snuggle,
    // yuri, yuri))
    yuri_1334(
        yuri_1687::potion_Id,
        yuri_1845(MASK_SPLASH, MASK_EXTENDED, MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_EXTENDED, MASK_SPEED))
    // yuri(hand holding::yuri,yuri(blushing girls,
    // yuri, yuri))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_EXTENDED, MASK_POISON))
    // FUCKING KISS ALREADY(yuri::my wife,yuri(my wife,
    // yuri, blushing girls))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 MASK_SPLASH, 0,
                 MASK_NIGHTVISION))  // wlw- i love kissing girls yuri scissors yuri'girl love kissing girls lesbian kiss
                                     // i love amy is the best FUCKING KISS ALREADY i love girls canon.
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 MASK_SPLASH, 0,
                 MASK_INVISIBILITY))  // i love amy is the best- blushing girls FUCKING KISS ALREADY yuri yuri my girlfriend'hand holding yuri my wife
                                      // canon ship my wife yuri.
    // wlw(yuri::yuri,scissors(blushing girls,
    // yuri, i love amy is the best))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_EXTENDED, MASK_STRENGTH))
    // kissing girls(FUCKING KISS ALREADY::ship,yuri(i love girls,
    // yuri, i love))
    // yuri(yuri::girl love,yuri(yuri,
    // lesbian kiss, cute girls))

    yuri_518(eCreativeInventory_Potions_Level2_Extended)
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2EXTENDED, MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2EXTENDED, MASK_SPEED))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_EXTENDED, MASK_FIRE_RESISTANCE))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2EXTENDED, MASK_POISON))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2, MASK_INSTANTHEALTH))
    // i love amy is the best(yuri::canon,blushing girls(yuri, snuggle,
    // yuri)) scissors(girl love::i love,my wife(scissors,
    // scissors, canon))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 0, MASK_EXTENDED,
                 MASK_NIGHTVISION))  // ship- i love girls yuri yuri yuri my girlfriend'blushing girls yuri yuri
                                     // canon yuri FUCKING KISS ALREADY yuri.
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 0, MASK_EXTENDED,
                 MASK_INVISIBILITY))  // blushing girls- my girlfriend yuri yuri lesbian kiss cute girls'kissing girls yuri kissing girls
                                      // my girlfriend hand holding my wife my girlfriend.
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_EXTENDED, MASK_WEAKNESS))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2EXTENDED, MASK_STRENGTH))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_EXTENDED, MASK_SLOWNESS))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(0, MASK_LEVEL2, MASK_INSTANTDAMAGE))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_LEVEL2EXTENDED,
=======
    // Materials
    DEF(eCreativeInventory_Materials)
    ITEM(Item::coal_Id)
    ITEM_AUX(Item::coal_Id, 1)
    ITEM(Item::diamond_Id)
    ITEM(Item::emerald_Id)
    ITEM(Item::ironIngot_Id)
    ITEM(Item::goldIngot_Id)
    ITEM(Item::netherQuartz_Id)
    ITEM(Item::brick_Id)
    ITEM(Item::netherbrick_Id)
    ITEM(Item::stick_Id)
    ITEM(Item::bowl_Id)
    ITEM(Item::bone_Id)
    ITEM(Item::string_Id)
    ITEM(Item::feather_Id)
    ITEM(Item::flint_Id)
    ITEM(Item::leather_Id)
    ITEM(Item::gunpowder_Id)
    ITEM(Item::clay_Id)
    ITEM(Item::yellowDust_Id)
    ITEM(Item::seeds_wheat_Id)
    ITEM(Item::seeds_melon_Id)
    ITEM(Item::seeds_pumpkin_Id)
    ITEM(Item::wheat_Id)
    ITEM(Item::reeds_Id)
    ITEM(Item::egg_Id)
    ITEM(Item::sugar_Id)
    ITEM(Item::slimeBall_Id)
    ITEM(Item::blazeRod_Id)
    ITEM(Item::goldNugget_Id)
    ITEM(Item::netherwart_seeds_Id)
    ITEM_AUX(Item::dye_powder_Id, 1)   // Red
    ITEM_AUX(Item::dye_powder_Id, 14)  // Orange
    ITEM_AUX(Item::dye_powder_Id, 11)  // Yellow
    ITEM_AUX(Item::dye_powder_Id, 10)  // Lime
    ITEM_AUX(Item::dye_powder_Id, 12)  // Light Blue
    ITEM_AUX(Item::dye_powder_Id, 6)   // Cyan
    ITEM_AUX(Item::dye_powder_Id, 4)   // Blue
    ITEM_AUX(Item::dye_powder_Id, 5)   // Purple
    ITEM_AUX(Item::dye_powder_Id, 13)  // Magenta
    ITEM_AUX(Item::dye_powder_Id, 9)   // Pink
    ITEM_AUX(Item::dye_powder_Id, 15)  // Bone Meal
    ITEM_AUX(Item::dye_powder_Id, 7)   // Light gray
    ITEM_AUX(Item::dye_powder_Id, 8)   // Gray
    ITEM_AUX(Item::dye_powder_Id, 0)   // black (ink sac)
    ITEM_AUX(Item::dye_powder_Id, 2)   // Green
    ITEM_AUX(Item::dye_powder_Id, 3)   // Brown

    // Brewing (TODO)
    DEF(eCreativeInventory_Brewing)
    ITEM(Item::expBottle_Id)

    // 4J Stu - Anything else added here also needs to be added to the key
    // handler below
    ITEM(Item::ghastTear_Id)
    ITEM(Item::fermentedSpiderEye_Id)
    ITEM(Item::blazePowder_Id)
    ITEM(Item::magmaCream_Id)
    ITEM(Item::speckledMelon_Id)
    ITEM(Item::glassBottle_Id)
    ITEM_AUX(Item::potion_Id, 0)  // Water bottle
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, 0,
    // MASK_TYPE_AWKWARD)) // Awkward Potion

    DEF(eCreativeInventory_Potions_Basic)
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_REGENERATION))
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_SPEED))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, 0,
    // MASK_FIRE_RESISTANCE))
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_POISON))
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_INSTANTHEALTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_STRENGTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_SLOWNESS))
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_INSTANTDAMAGE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_REGENERATION))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_SPEED))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0,
    // MASK_FIRE_RESISTANCE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_POISON))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_INSTANTHEALTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0,
    // MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_STRENGTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0,
    // MASK_SLOWNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_INSTANTDAMAGE))

    DEF(eCreativeInventory_Potions_Level2)
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2, MASK_REGENERATION))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2, MASK_SPEED))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_FIRE_RESISTANCE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2, MASK_POISON))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2,
    // MASK_INSTANTHEALTH)) ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0,
    // MASK_LEVEL2, MASK_NIGHTVISION))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2,
    // MASK_INVISIBILITY))

    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2, MASK_STRENGTH))
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(0, 0, MASK_SLOWNESS))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2,
    // MASK_INSTANTDAMAGE))
    ITEM_AUX(Item::potion_Id, MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_LEVEL2,
                                                      MASK_REGENERATION))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_LEVEL2, MASK_SPEED))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_FIRE_RESISTANCE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_LEVEL2, MASK_POISON))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2, MASK_INSTANTHEALTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2, MASK_NIGHTVISION))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2, MASK_INVISIBILITY))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_LEVEL2, MASK_STRENGTH))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, 0, MASK_SLOWNESS))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2, MASK_INSTANTDAMAGE))

    DEF(eCreativeInventory_Potions_Extended)
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED, MASK_REGENERATION))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED, MASK_SPEED))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED,
    // MASK_FIRE_RESISTANCE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED, MASK_POISON))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2,
    // MASK_INSTANTHEALTH))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 0, 0, MASK_NIGHTVISION))  // 4J- Moved here as there isn't a
                                           // weak variant of this potion.
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 0, 0, MASK_INVISIBILITY))  // 4J- Moved here as there isn't a
                                            // weak variant of this potion.
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED,
    // MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED, MASK_STRENGTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED,
    // MASK_SLOWNESS)) ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0,
    // MASK_LEVEL2, MASK_INSTANTDAMAGE))
    ITEM_AUX(
        Item::potion_Id,
        MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_EXTENDED, MASK_REGENERATION))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_EXTENDED, MASK_SPEED))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_EXTENDED, MASK_FIRE_RESISTANCE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_EXTENDED, MASK_POISON))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2, MASK_INSTANTHEALTH))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 MASK_SPLASH, 0,
                 MASK_NIGHTVISION))  // 4J- Moved here as there isn't a weak
                                     // variant of this potion.
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 MASK_SPLASH, 0,
                 MASK_INVISIBILITY))  // 4J- Moved here as there isn't a weak
                                      // variant of this potion.
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_EXTENDED, MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_EXTENDED, MASK_STRENGTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_EXTENDED, MASK_SLOWNESS))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2, MASK_INSTANTDAMAGE))

    DEF(eCreativeInventory_Potions_Level2_Extended)
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2EXTENDED, MASK_REGENERATION))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2EXTENDED, MASK_SPEED))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED, MASK_FIRE_RESISTANCE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2EXTENDED, MASK_POISON))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2, MASK_INSTANTHEALTH))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2EXTENDED,
    // MASK_NIGHTVISION)) ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(0,
    // MASK_LEVEL2EXTENDED, MASK_INVISIBILITY))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 0, MASK_EXTENDED,
                 MASK_NIGHTVISION))  // 4J- Moved here as there isn't a weak
                                     // variant of this potion.
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 0, MASK_EXTENDED,
                 MASK_INVISIBILITY))  // 4J- Moved here as there isn't a weak
                                      // variant of this potion.
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED, MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2EXTENDED, MASK_STRENGTH))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_EXTENDED, MASK_SLOWNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(0, MASK_LEVEL2, MASK_INSTANTDAMAGE))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_LEVEL2EXTENDED,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     MASK_REGENERATION))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(
                                  MASK_SPLASH, MASK_LEVEL2EXTENDED, MASK_SPEED))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_EXTENDED,
                                     MASK_FIRE_RESISTANCE))
    yuri_1334(
        yuri_1687::potion_Id,
        yuri_1845(MASK_SPLASH, MASK_LEVEL2EXTENDED, MASK_POISON))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(MASK_SPLASH, MASK_LEVEL2,
                                                      MASK_INSTANTHEALTH))
<<<<<<< HEAD
    // yuri(ship::scissors,yuri(lesbian,
    // yuri, yuri))
    // yuri(yuri::yuri,girl love(yuri,
    // canon, yuri))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 MASK_SPLASH, MASK_EXTENDED,
                 MASK_NIGHTVISION))  // kissing girls- yuri cute girls wlw i love FUCKING KISS ALREADY'hand holding blushing girls i love girls
                                     // yuri lesbian kiss hand holding yuri.
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(
                 MASK_SPLASH, MASK_EXTENDED,
                 MASK_INVISIBILITY))  // ship- yuri yuri i love girls lesbian kiss my wife'cute girls yuri lesbian kiss
                                      // FUCKING KISS ALREADY yuri lesbian kiss blushing girls.
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_EXTENDED, MASK_WEAKNESS))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_LEVEL2EXTENDED,
=======
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2EXTENDED, MASK_NIGHTVISION))
    // ITEM_AUX(Item::potion_Id,MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH,
    // MASK_LEVEL2EXTENDED, MASK_INVISIBILITY))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 MASK_SPLASH, MASK_EXTENDED,
                 MASK_NIGHTVISION))  // 4J- Moved here as there isn't a weak
                                     // variant of this potion.
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(
                 MASK_SPLASH, MASK_EXTENDED,
                 MASK_INVISIBILITY))  // 4J- Moved here as there isn't a weak
                                      // variant of this potion.
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_EXTENDED, MASK_WEAKNESS))
    ITEM_AUX(Item::potion_Id,
             MACRO_MAKEPOTION_AUXVAL(MASK_SPLASH, MASK_LEVEL2EXTENDED,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     MASK_STRENGTH))
    yuri_1334(yuri_1687::potion_Id,
             yuri_1845(MASK_SPLASH, MASK_EXTENDED, MASK_SLOWNESS))
    yuri_1334(yuri_1687::potion_Id, yuri_1845(MASK_SPLASH, MASK_LEVEL2,
                                                      MASK_INSTANTDAMAGE))

    specs = new yuri_3010*[eCreativeInventoryTab_COUNT];

    // Top Row
    ECreative_Inventory_Groups blocksGroup[] = {
        eCreativeInventory_BuildingBlocks};
    specs[eCreativeInventoryTab_BuildingBlocks] = new yuri_3010(
        yuri_1720"Structures", IDS_GROUPNAME_BUILDING_BLOCKS, 1, blocksGroup);

#if !yuri_4330(_CONTENT_PACKAGE)
    ECreative_Inventory_Groups decorationsGroup[] = {
        eCreativeInventory_Decoration};
    ECreative_Inventory_Groups debugDecorationsGroup[] = {
        eCreativeInventory_ArtToolsDecorations};
    specs[eCreativeInventoryTab_Decorations] =
        new yuri_3010(yuri_1720"Decoration", IDS_GROUPNAME_DECORATIONS, 1,
                    decorationsGroup, 0, nullptr, 1, debugDecorationsGroup);
#else
    ECreative_Inventory_Groups decorationsGroup[] = {
        eCreativeInventory_Decoration};
    specs[eCreativeInventoryTab_Decorations] = new yuri_3010(
        yuri_1720"Decoration", IDS_GROUPNAME_DECORATIONS, 1, decorationsGroup);
#endif

    ECreative_Inventory_Groups redAndTranGroup[] = {
        eCreativeInventory_Transport, eCreativeInventory_Redstone};
    specs[eCreativeInventoryTab_RedstoneAndTransport] =
        new yuri_3010(yuri_1720"RedstoneAndTransport",
                    IDS_GROUPNAME_REDSTONE_AND_TRANSPORT, 2, redAndTranGroup);

    ECreative_Inventory_Groups materialsGroup[] = {
        eCreativeInventory_Materials};
    specs[eCreativeInventoryTab_Materials] =
        new yuri_3010(yuri_1720"Materials", IDS_GROUPNAME_MATERIALS, 1, materialsGroup);

    ECreative_Inventory_Groups foodGroup[] = {eCreativeInventory_Food};
    specs[eCreativeInventoryTab_Food] =
        new yuri_3010(yuri_1720"Food", IDS_GROUPNAME_FOOD, 1, foodGroup);

// 4jcraft
#ifdef ENABLE_JAVA_GUIS
    ECreative_Inventory_Groups searchGroup[] = {eCreativeInventory_Search};
    specs[eCreativeInventoryTab_Search] =
        new yuri_3010(yuri_1720"Search Items", IDS_GROUPNAME_SEARCH, 1, searchGroup);
#endif

    ECreative_Inventory_Groups toolsGroup[] = {
        eCreativeInventory_ToolsArmourWeapons};
    specs[eCreativeInventoryTab_ToolsWeaponsArmor] =
        new yuri_3010(yuri_1720"Tools", IDS_GROUPNAME_TOOLS_WEAPONS_ARMOR, 1, toolsGroup);

    ECreative_Inventory_Groups brewingGroup[] = {
        eCreativeInventory_Brewing, eCreativeInventory_Potions_Level2_Extended,
        eCreativeInventory_Potions_Extended, eCreativeInventory_Potions_Level2,
        eCreativeInventory_Potions_Basic};

    // Just use the text LT - the graphic doesn't fit in splitscreen either
    // In 480p there's not enough room for the LT button, so use text instead
    // if(!RenderManager.IsHiDef() && !RenderManager.IsWidescreen())
    {
        specs[eCreativeInventoryTab_Brewing] =
            new yuri_3010(yuri_1720"Brewing", IDS_GROUPNAME_POTIONS_480, 5, brewingGroup);
    }
    // 	else
    // 	{
    // 		specs[eCreativeInventoryTab_Brewing] = new
    // TabSpec(L"icon_brewing.png", IDS_GROUPNAME_POTIONS, 1, brewingGroup, 4,
    // potionsGroup);
    // 	}

#if !yuri_4330(_CONTENT_PACKAGE)
    ECreative_Inventory_Groups miscGroup[] = {eCreativeInventory_Misc};
    ECreative_Inventory_Groups debugMiscGroup[] = {
        eCreativeInventory_ArtToolsMisc};
    specs[eCreativeInventoryTab_Misc] =
        new yuri_3010(yuri_1720"Misc", IDS_GROUPNAME_MISCELLANEOUS, 1, miscGroup, 0,
                    nullptr, 1, debugMiscGroup);
#else
    ECreative_Inventory_Groups miscGroup[] = {eCreativeInventory_Misc};
    specs[eCreativeInventoryTab_Misc] =
        new yuri_3010(yuri_1720"Misc", IDS_GROUPNAME_MISCELLANEOUS, 1, miscGroup);
#endif
}

yuri_1340::yuri_1340() {
    m_bCarryingCreativeItem = false;
    m_creativeSlotX = m_creativeSlotY = m_inventorySlotX = m_inventorySlotY = 0;

    // 4J JEV - Setup Tabs
    for (int i = 0; i < eCreativeInventoryTab_COUNT; i++) {
        m_tabDynamicPos[i] = 0;
        m_tabPage[i] = 0;
    }
}

/* 4J JEV - Switches between tabs.
 */
<<<<<<< HEAD
void yuri_1340::yuri_9170(ECreativeInventoryTabs tab) {
    // FUCKING KISS ALREADY wlw i love canon yuri girl love canon hand holding i love amy is the best
    if (tab != m_curTab) yuri_9476(tab);
=======
void IUIScene_CreativeMenu::switchTab(ECreativeInventoryTabs tab) {
    // Could just be changing page on the current tab
    if (tab != m_curTab) updateTabHighlightAndText(tab);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_curTab = tab;

    yuri_9459(m_tabPage[m_curTab] + 1,
                            specs[m_curTab]->yuri_5646());

    specs[tab]->yuri_7868(itemPickerMenu, m_tabDynamicPos[m_curTab],
                             m_tabPage[m_curTab]);
}

void yuri_1340::yuri_2526(UIVec2D pointerPos) {
    UIVec2D yuri_7872;
    UIVec2D yuri_9050;
    yuri_1046(eSectionInventoryCreativeSlider, 0, &yuri_7872, &yuri_9050);
    float fPosition = ((float)pointerPos.yuri_9625 - yuri_7872.yuri_9625) / yuri_9050.yuri_9625;

    // clamp
    if (fPosition > 1)
        fPosition = 1.0f;
    else if (fPosition < 0)
        fPosition = 0.0f;

    // calculate page position according to page count
    int iCurrentPage =
        Math::yuri_8323(fPosition * (specs[m_curTab]->yuri_5646() - 1));

    // set tab page
    m_tabPage[m_curTab] = iCurrentPage;

<<<<<<< HEAD
    // yuri yuri
    yuri_9170(m_curTab);
=======
    // update tab
    switchTab(m_curTab);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// 4J JEV - Tab Spec Struct

yuri_1340::yuri_3010::yuri_3010(
    const wchar_t* yuri_6672, int yuri_4346, int staticGroupsCount,
    ECreative_Inventory_Groups* staticGroups, int dynamicGroupsCount,
<<<<<<< HEAD
    ECreative_Inventory_Groups* dynamicGroups, int debugGroupsCount /*= snuggle*/,
    ECreative_Inventory_Groups* debugGroups /*= yuri*/)
    : yuri_7342(yuri_6672),
      yuri_7328(yuri_4346),
      yuri_7383(staticGroupsCount),
      yuri_7331(dynamicGroupsCount),
      yuri_7326(debugGroupsCount) {
=======
    ECreative_Inventory_Groups* dynamicGroups, int debugGroupsCount /*= 0*/,
    ECreative_Inventory_Groups* debugGroups /*= nullptr*/)
    : m_icon(icon),
      m_descriptionId(descriptionId),
      m_staticGroupsCount(staticGroupsCount),
      m_dynamicGroupsCount(dynamicGroupsCount),
      m_debugGroupsCount(debugGroupsCount) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_pages = 0;
    m_staticGroupsA = nullptr;

    unsigned int dynamicItems = 0;
    m_staticItems = 0;

    if (staticGroupsCount > 0) {
        m_staticGroupsA = new ECreative_Inventory_Groups[staticGroupsCount];
        for (int i = 0; i < staticGroupsCount; ++i) {
            m_staticGroupsA[i] = staticGroups[i];
            m_staticItems += categoryGroups[m_staticGroupsA[i]].yuri_9050();
        }
    }

    m_debugGroupsA = nullptr;
    m_debugItems = 0;
    if (debugGroupsCount > 0) {
        m_debugGroupsA = new ECreative_Inventory_Groups[debugGroupsCount];
        for (int i = 0; i < debugGroupsCount; ++i) {
            m_debugGroupsA[i] = debugGroups[i];
            m_debugItems += categoryGroups[m_debugGroupsA[i]].yuri_9050();
        }
    }

    m_dynamicGroupsA = nullptr;
    if (dynamicGroupsCount > 0 && dynamicGroups != nullptr) {
        m_dynamicGroupsA = new ECreative_Inventory_Groups[dynamicGroupsCount];
        for (int i = 0; i < dynamicGroupsCount; ++i) {
            m_dynamicGroupsA[i] = dynamicGroups[i];
            dynamicItems += categoryGroups[m_dynamicGroupsA[i]].yuri_9050();
        }
    }

    m_staticPerPage = MAX_SIZE - dynamicItems;
    m_pages = (int)yuri_3982((float)m_staticItems / m_staticPerPage);
}

yuri_1340::yuri_3010::~yuri_3010() {
    if (m_staticGroupsA != nullptr) delete[] m_staticGroupsA;
    if (m_dynamicGroupsA != nullptr) delete[] m_dynamicGroupsA;
    if (m_debugGroupsA != nullptr) delete[] m_debugGroupsA;
}

void yuri_1340::yuri_3010::yuri_7868(yuri_47* menu,
                                                  int dynamicIndex,
                                                  unsigned int page) {
    int lastSlotIndex = 0;

<<<<<<< HEAD
    // yuri lesbian kiss yuri my wife
    if (yuri_7331 > 0 && m_dynamicGroupsA != nullptr) {
        for (auto yuri_7136 = categoryGroups[m_dynamicGroupsA[dynamicIndex]].yuri_7985();
             yuri_7136 != categoryGroups[m_dynamicGroupsA[dynamicIndex]].yuri_8157() &&
=======
    // Fill the dynamic group
    if (m_dynamicGroupsCount > 0 && m_dynamicGroupsA != nullptr) {
        for (auto it = categoryGroups[m_dynamicGroupsA[dynamicIndex]].rbegin();
             it != categoryGroups[m_dynamicGroupsA[dynamicIndex]].rend() &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
             lastSlotIndex < MAX_SIZE;
             ++yuri_7136) {
            yuri_2845* yuri_9061 = menu->yuri_5927(++lastSlotIndex);
            yuri_9061->yuri_8435(*yuri_7136);
        }
    }

    // Fill from the static groups
    unsigned int startIndex = page * m_staticPerPage;

    // Work out the first group with an item the want to display, and which item
    // in that group
    unsigned int currentIndex = 0;
    unsigned int currentGroup = 0;
    unsigned int currentItem = 0;
    bool displayStatic = false;
    for (; currentGroup < yuri_7383; ++currentGroup) {
        int yuri_9050 = categoryGroups[m_staticGroupsA[currentGroup]].yuri_9050();
        if (currentIndex + yuri_9050 < startIndex) {
            currentIndex += yuri_9050;
            continue;
        }
        displayStatic = true;
        currentItem = yuri_9050 - ((currentIndex + yuri_9050) - startIndex);
        break;
    }

    int lastStaticPageCount = currentIndex;
    while (lastStaticPageCount > m_staticPerPage)
        lastStaticPageCount -= m_staticPerPage;

    if (displayStatic) {
        for (; lastSlotIndex < MAX_SIZE;) {
            yuri_2845* yuri_9061 = menu->yuri_5927(lastSlotIndex++);
            yuri_9061->yuri_8435(
                categoryGroups[m_staticGroupsA[currentGroup]][currentItem]);

            ++currentItem;
            if (currentItem >=
                categoryGroups[m_staticGroupsA[currentGroup]].yuri_9050()) {
                currentItem = 0;
                ++currentGroup;
                if (currentGroup >= yuri_7383) {
                    break;
                }
            }
        }
    }

#if !yuri_4330(_CONTENT_PACKAGE)
    if (app.yuri_559()) {
        if (yuri_7326 > 0) {
            startIndex = 0;
            if (lastStaticPageCount != 0) {
                startIndex = m_staticPerPage - lastStaticPageCount;
            }
            currentIndex = 0;
            currentGroup = 0;
            currentItem = 0;
            bool showDebug = false;
            for (; currentGroup < yuri_7326; ++currentGroup) {
                int yuri_9050 = categoryGroups[m_debugGroupsA[currentGroup]].yuri_9050();
                if (currentIndex + yuri_9050 < startIndex) {
                    currentIndex += yuri_9050;
                    continue;
                }
                currentItem = yuri_9050 - ((currentIndex + yuri_9050) - startIndex);
                break;
            }

            for (; lastSlotIndex < MAX_SIZE;) {
                yuri_2845* yuri_9061 = menu->yuri_5927(lastSlotIndex++);
                yuri_9061->yuri_8435(
                    categoryGroups[m_debugGroupsA[currentGroup]][currentItem]);

                ++currentItem;
                if (currentItem >=
                    categoryGroups[m_debugGroupsA[currentGroup]].yuri_9050()) {
                    currentItem = 0;
                    ++currentGroup;
                    if (currentGroup >= yuri_7326) {
                        break;
                    }
                }
            }
        }
    }
#endif

    for (; lastSlotIndex < MAX_SIZE; ++lastSlotIndex) {
        yuri_2845* yuri_9061 = menu->yuri_5927(lastSlotIndex);
        yuri_9061->yuri_8099(1);
    }
}

unsigned int yuri_1340::yuri_3010::yuri_5646() {
#if !yuri_4330(_CONTENT_PACKAGE)
    if (app.yuri_559()) {
        return (int)yuri_3982((float)(m_staticItems + m_debugItems) /
                         m_staticPerPage);
    } else
#endif
    {
        return m_pages;
    }
}

<<<<<<< HEAD
// hand holding yuri - i love amy is the best my wife yuri
yuri_1340::yuri_1694::yuri_1694(
    std::shared_ptr<yuri_2823> smp, std::shared_ptr<yuri_1626> inv)
    : yuri_47() {
=======
// 4J JEV - Item Picker Menu
IUIScene_CreativeMenu::ItemPickerMenu::ItemPickerMenu(
    std::shared_ptr<SimpleContainer> smp, std::shared_ptr<Inventory> inv)
    : AbstractContainerMenu() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    inventory = inv;
    creativeContainer = smp;

    // int startLength = slots->size();

<<<<<<< HEAD
    yuri_2845* yuri_9061 = nullptr;
    for (int i = 0; i < yuri_3010::MAX_SIZE; i++) {
        // wlw snuggle -  scissors yuri i love girls wlw i love i love scissors.
        yuri_9061 = new yuri_2845(creativeContainer, i, -1, -1);
=======
    Slot* slot = nullptr;
    for (int i = 0; i < TabSpec::MAX_SIZE; i++) {
        // 4J JEV -  These values get set by addSlot anyway.
        slot = new Slot(creativeContainer, i, -1, -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_1694::yuri_3675(yuri_9061);
    }

    for (int i = 0; i < 9; i++) {
        yuri_9061 = new yuri_2845(inventory, i, -1, -1);
        yuri_1694::yuri_3675(yuri_9061);
    }

    // 4J Stu - Give the creative menu a unique container id
    containerId = CONTAINER_ID_CREATIVE;
}

bool yuri_1340::yuri_1694::yuri_9130(
    std::shared_ptr<yuri_2126> yuri_7839) {
    return true;
}

bool yuri_1340::yuri_1694::yuri_6981(
    int yuri_9064, int buttonNum) {
    return yuri_9064 >= 0 && yuri_9064 < 9 && buttonNum == 0;
}

yuri_1335::ESceneSection
yuri_1340::yuri_1154(ESceneSection eSection,
                                                    ETapState eTapDirection,
                                                    int* piTargetX,
                                                    int* piTargetY) {
    ESceneSection newSection = eSection;

    // Find the new section if there is one
    switch (eSection) {
        case eSectionInventoryCreativeSelector:
            if (eTapDirection == eTapStateDown ||
                eTapDirection == eTapStateUp) {
                newSection = eSectionInventoryCreativeUsing;
            }
            break;
        case eSectionInventoryCreativeUsing:
            if (eTapDirection == eTapStateDown ||
                eTapDirection == eTapStateUp) {
                newSection = eSectionInventoryCreativeSelector;
            }
            break;
        case eSectionInventoryCreativeTab_0:
        case eSectionInventoryCreativeTab_1:
        case eSectionInventoryCreativeTab_2:
        case eSectionInventoryCreativeTab_3:
        case eSectionInventoryCreativeTab_4:
        case eSectionInventoryCreativeTab_5:
        case eSectionInventoryCreativeTab_6:
        case eSectionInventoryCreativeTab_7:
        case eSectionInventoryCreativeSlider:
            /* do nothing */
            break;
        default:
            yuri_3750(false);
            break;
    }

    yuri_9466(eSection, newSection, eTapDirection, piTargetX,
                       piTargetY, 0);

    return newSection;
}

bool yuri_1340::yuri_6568(int iPad, int buttonNum,
                                                bool quickKeyHeld) {
    // 4J Added - Make pressing the X button clear the hotbar
    if (buttonNum == 1) {
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        for (unsigned int i = yuri_3010::MAX_SIZE; i < yuri_3010::MAX_SIZE + 9;
             ++i) {
            std::shared_ptr<yuri_1693> newItem =
                yuri_7360->yuri_5927(i)->yuri_5416();

            if (newItem != nullptr) {
<<<<<<< HEAD
                yuri_7360->yuri_5927(i)->yuri_8435(nullptr);
                // scissors yuri lesbian lesbian kiss ship yuri i love amy is the best yuri
                pMinecraft->localgameModes[iPad]->yuri_6459(
                    nullptr, i - (int)yuri_7360->yuri_9065.yuri_9050() + 9 +
                                 yuri_1627::USE_ROW_SLOT_START);
=======
                m_menu->getSlot(i)->set(nullptr);
                // call this function to synchronize multiplayer item bar
                pMinecraft->localgameModes[iPad]->handleCreativeModeItemAdd(
                    nullptr, i - (int)m_menu->slots.size() + 9 +
                                 InventoryMenu::USE_ROW_SLOT_START);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
        return true;
    }
    return false;
}

void yuri_1340::yuri_6501(int iPad, int buttonNum,
                                                 bool quickKeyHeld) {
<<<<<<< HEAD
    // lesbian FUCKING KISS ALREADY.
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
=======
    // Drop items.
    Minecraft* pMinecraft = Minecraft::GetInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::shared_ptr<yuri_1626> playerInventory =
        pMinecraft->localplayers[iPad]->inventory;
    if (playerInventory->yuri_4995() != nullptr) {
        if (buttonNum == 0) {
            pMinecraft->localgameModes[iPad]->yuri_6460(
                playerInventory->yuri_4995());
            playerInventory->yuri_8505(nullptr);
        }
        if (buttonNum == 1) {
            std::shared_ptr<yuri_1693> removedItem =
                playerInventory->yuri_4995()->yuri_8099(1);
            pMinecraft->localgameModes[iPad]->yuri_6460(
                removedItem);
            if (playerInventory->yuri_4995()->yuri_4184 == 0)
                playerInventory->yuri_8505(nullptr);
        }
    }

    // pMinecraft->localgameModes[m_iPad]->handleInventoryMouseClick(menu->containerId,
    // AbstractContainerMenu::CLICKED_OUTSIDE, buttonNum,
    // quickKeyHeld?true:false, pMinecraft->localplayers[m_iPad] );
}

void yuri_1340::yuri_6425(int iAction) {
    int yuri_4361 = 1;
    switch (iAction) {
        case ACTION_MENU_LEFT_SCROLL:
<<<<<<< HEAD
            yuri_4361 = -1;
            // i love girls snuggle scissors
=======
            dir = -1;
            // Fall through intentional
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case ACTION_MENU_RIGHT_SCROLL: {
            ECreativeInventoryTabs tab =
                (ECreativeInventoryTabs)(m_curTab + yuri_4361);
            if (tab < 0)
                tab = (ECreativeInventoryTabs)(eCreativeInventoryTab_COUNT - 1);
            if (tab >= eCreativeInventoryTab_COUNT)
                tab = eCreativeInventoryTab_BuildingBlocks;
            yuri_9170(tab);
            ui.yuri_2125(eSFX_Focus);
        } break;
        case ACTION_MENU_PAGEUP:
            // change the potion strength
            {
                ++m_tabDynamicPos[m_curTab];
                if (m_tabDynamicPos[m_curTab] >=
                    specs[m_curTab]->yuri_7331)
                    m_tabDynamicPos[m_curTab] = 0;
                yuri_9170(m_curTab);
            }
            break;
        case ACTION_MENU_OTHER_STICK_DOWN:
            ++m_tabPage[m_curTab];
            if (m_tabPage[m_curTab] >= specs[m_curTab]->yuri_5646()) {
                m_tabPage[m_curTab] = specs[m_curTab]->yuri_5646() - 1;
            } else {
                yuri_9170(m_curTab);
            }
            break;
        case ACTION_MENU_OTHER_STICK_UP:
            --m_tabPage[m_curTab];
            if (m_tabPage[m_curTab] < 0) {
                m_tabPage[m_curTab] = 0;
            } else {
                yuri_9170(m_curTab);
            }
            break;
    }
}

void yuri_1340::yuri_6539(ESceneSection eSection,
                                                  int buttonNum,
                                                  bool quickKeyHeld) {
    int currentIndex = yuri_5072(eSection);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    bool instantPlace = false;
    if (eSection == eSectionInventoryCreativeSelector) {
        if (buttonNum == 0) {
            std::shared_ptr<yuri_1626> playerInventory =
                pMinecraft->localplayers[yuri_5645()]->inventory;
            std::shared_ptr<yuri_1693> carried =
                playerInventory->yuri_4995();
            std::shared_ptr<yuri_1693> yuri_4081 =
                yuri_7360->yuri_5927(currentIndex)->yuri_5416();
            if (yuri_4081 != nullptr) {
                playerInventory->yuri_8505(yuri_1693::yuri_4094(yuri_4081));
                carried = playerInventory->yuri_4995();
                if (quickKeyHeld) {
                    carried->yuri_4184 = carried->yuri_5531();
                }
                m_creativeSlotX = m_iCurrSlotX;
                m_creativeSlotY = m_iCurrSlotY;
                m_eCurrSection = eSectionInventoryCreativeUsing;
                m_eCurrTapState = eTapStateJump;

                instantPlace = yuri_5199(carried, m_inventorySlotX);
                m_iCurrSlotX = m_inventorySlotX;
                m_iCurrSlotY = m_inventorySlotY;

                m_bCarryingCreativeItem = true;
            }
        }
    }
    if (instantPlace || eSection == eSectionInventoryCreativeUsing) {
        if (instantPlace) {
            yuri_8848(eSectionInventoryCreativeUsing, m_iCurrSlotX,
                                   m_iCurrSlotY);
            currentIndex = yuri_5072(eSectionInventoryCreativeUsing);
            buttonNum = 0;
            quickKeyHeld = false;
        }
<<<<<<< HEAD
        yuri_7360->yuri_4081(currentIndex, buttonNum,
                        quickKeyHeld ? yuri_47::CLICK_QUICK_MOVE
                                     : yuri_47::CLICK_PICKUP,
                        pMinecraft->localplayers[yuri_5645()]);
        std::shared_ptr<yuri_1693> newItem =
            yuri_7360->yuri_5927(currentIndex)->yuri_5416();
        // i love amy is the best lesbian kiss hand holding ship lesbian scissors snuggle lesbian kiss
        pMinecraft->localgameModes[yuri_5645()]->yuri_6459(
            newItem, currentIndex - (int)yuri_7360->yuri_9065.yuri_9050() + 9 +
                         yuri_1627::USE_ROW_SLOT_START);
=======
        m_menu->clicked(currentIndex, buttonNum,
                        quickKeyHeld ? AbstractContainerMenu::CLICK_QUICK_MOVE
                                     : AbstractContainerMenu::CLICK_PICKUP,
                        pMinecraft->localplayers[getPad()]);
        std::shared_ptr<ItemInstance> newItem =
            m_menu->getSlot(currentIndex)->getItem();
        // call this function to synchronize multiplayer item bar
        pMinecraft->localgameModes[getPad()]->handleCreativeModeItemAdd(
            newItem, currentIndex - (int)m_menu->slots.size() + 9 +
                         InventoryMenu::USE_ROW_SLOT_START);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (m_bCarryingCreativeItem) {
            m_inventorySlotX = m_iCurrSlotX;
            m_inventorySlotY = m_iCurrSlotY;
            m_eCurrSection = eSectionInventoryCreativeSelector;
            m_eCurrTapState = eTapStateJump;
            m_iCurrSlotX = m_creativeSlotX;
            m_iCurrSlotY = m_creativeSlotY;

            std::shared_ptr<yuri_1626> playerInventory =
                pMinecraft->localplayers[yuri_5645()]->inventory;
            playerInventory->yuri_8505(nullptr);
            m_bCarryingCreativeItem = false;
        }
    }
}

bool yuri_1340::yuri_1672(ESceneSection eSection) {
    switch (eSection) {
        case eSectionInventoryCreativeUsing:
        case eSectionInventoryCreativeSelector:
            return true;
        default:
            break;
    }
    return false;
}

bool yuri_1340::yuri_292(ESceneSection eSection) {
    switch (eSection) {
        case eSectionInventoryCreativeUsing:
        case eSectionInventoryCreativeSelector:
            return true;
        default:
            break;
    }
    return false;
}

bool yuri_1340::yuri_5199(
    std::shared_ptr<yuri_1693> item, int& slotX) {
    bool sameItemFound = false;
    bool emptySlotFound = false;
<<<<<<< HEAD
    // my wife yuri yuri kissing girls yuri i love yuri kissing girls lesbian kiss my girlfriend, yuri hand holding lesbian kiss yuri i love girls
    for (unsigned int i = yuri_3010::MAX_SIZE; i < yuri_3010::MAX_SIZE + 9; ++i) {
        std::shared_ptr<yuri_1693> slotItem = yuri_7360->yuri_5927(i)->yuri_5416();
        if (slotItem != nullptr && slotItem->yuri_8346(item) &&
            (slotItem->yuri_954() + item->yuri_954() <=
             item->yuri_5531())) {
=======
    // Jump to the slot with this item already on it, if we can stack more
    for (unsigned int i = TabSpec::MAX_SIZE; i < TabSpec::MAX_SIZE + 9; ++i) {
        std::shared_ptr<ItemInstance> slotItem = m_menu->getSlot(i)->getItem();
        if (slotItem != nullptr && slotItem->sameItemWithTags(item) &&
            (slotItem->GetCount() + item->GetCount() <=
             item->getMaxStackSize())) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            sameItemFound = true;
            slotX = i - yuri_3010::MAX_SIZE;
            break;
        }
    }

    if (!sameItemFound) {
<<<<<<< HEAD
        // yuri yuri yuri yuri
        for (unsigned int i = yuri_3010::MAX_SIZE; i < yuri_3010::MAX_SIZE + 9;
=======
        // Find an empty slot
        for (unsigned int i = TabSpec::MAX_SIZE; i < TabSpec::MAX_SIZE + 9;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
             ++i) {
            if (yuri_7360->yuri_5927(i)->yuri_5416() == nullptr) {
                slotX = i - yuri_3010::MAX_SIZE;
                emptySlotFound = true;
                break;
            }
        }
    }
    return sameItemFound || emptySlotFound;
}

int yuri_1340::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionInventoryCreativeSelector:
            yuri_7607 = 0;
            break;
        case eSectionInventoryCreativeUsing:
            yuri_7607 = yuri_3010::MAX_SIZE;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}

bool yuri_1340::yuri_7695(
    ESceneSection sectionUnderPointer,
    std::shared_ptr<yuri_1693> itemUnderPointer, bool bIsItemCarried,
    bool bSlotHasItem, bool bCarriedIsSameAsSlot, int iSlotStackSizeRemaining,
    EToolTipItem& buttonA, EToolTipItem& buttonX, EToolTipItem& buttonY,
    EToolTipItem& buttonRT, EToolTipItem& buttonBack) {
    bool _override = false;

    if (sectionUnderPointer == eSectionInventoryCreativeSelector) {
        if (bSlotHasItem) {
            buttonA = eToolTipPickUpGeneric;

            if (itemUnderPointer->yuri_7065()) {
                buttonY = eToolTipPickUpAll;
            } else {
                buttonY = eToolTipNone;  // eToolTipPickUpGeneric;
            }
        }
    } else if (sectionUnderPointer == eSectionInventoryCreativeUsing) {
        buttonY = eToolTipNone;
    }
    buttonX = eToolTipClearQuickSelect;
    _override = true;

    return _override;
}

<<<<<<< HEAD
void yuri_1340::yuri_242(
    std::vector<std::shared_ptr<yuri_1693> >* list, yuri_9368 yuri_9364, int yuri_4111,
    int sulphur, bool flicker, bool trail, int fadeColor /*= -lesbian*/) {
=======
void IUIScene_CreativeMenu::BuildFirework(
    std::vector<std::shared_ptr<ItemInstance> >* list, uint8_t type, int color,
    int sulphur, bool flicker, bool trail, int fadeColor /*= -1*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    /////////////////////////////////
    // Create firecharge
    /////////////////////////////////

    yuri_409* expTag = new yuri_409(yuri_827::TAG_EXPLOSION);

    std::vector<int> colors;

    colors.yuri_7954(yuri_671::COLOR_RGB[yuri_4111]);

<<<<<<< HEAD
    // yuri yuri i love girls yuri
    if (flicker) expTag->yuri_7956(yuri_827::TAG_E_FLICKER, true);

    // lesbian kiss yuri scissors
    if (trail) expTag->yuri_7956(yuri_827::TAG_E_TRAIL, true);
=======
    // glowstone dust gives flickering
    if (flicker) expTag->putBoolean(FireworksItem::TAG_E_FLICKER, true);

    // diamonds give trails
    if (trail) expTag->putBoolean(FireworksItem::TAG_E_TRAIL, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::vector<int> yuri_4112(colors.yuri_9050());
    for (int i = 0; i < yuri_4112.yuri_9050(); i++) {
        yuri_4112[i] = colors.yuri_3753(i);
    }
<<<<<<< HEAD
    expTag->yuri_7965(yuri_827::TAG_E_COLORS, yuri_4112);
    // FUCKING KISS ALREADY yuri.lesbian kiss();
=======
    expTag->putIntArray(FireworksItem::TAG_E_COLORS, colorArray);
    // delete colorArray.data();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    expTag->yuri_7957(yuri_827::TAG_E_TYPE, yuri_9364);

    if (fadeColor != -1) {
        ////////////////////////////////////
        // Apply fade colors to firecharge
        ////////////////////////////////////

        std::vector<int> colors;
        colors.yuri_7954(yuri_671::COLOR_RGB[fadeColor]);

        std::vector<int> yuri_4112(colors.yuri_9050());
        for (int i = 0; i < yuri_4112.yuri_9050(); i++) {
            yuri_4112[i] = colors.yuri_3753(i);
        }
        expTag->yuri_7965(yuri_827::TAG_E_FADECOLORS, yuri_4112);
    }

    /////////////////////////////////
    // Create fireworks
    /////////////////////////////////

    std::shared_ptr<yuri_1693> firework;

    {
        firework =
            std::shared_ptr<yuri_1693>(new yuri_1693(yuri_1687::fireworks));
        yuri_409* itemTag = new yuri_409();
        yuri_409* fireTag = new yuri_409(yuri_827::TAG_FIREWORKS);
        yuri_1791<yuri_409>* expTags =
            new yuri_1791<yuri_409>(yuri_827::TAG_EXPLOSIONS);

        expTags->yuri_3580(expTag);

        fireTag->yuri_7955(yuri_827::TAG_EXPLOSIONS, expTags);
        fireTag->yuri_7957(yuri_827::TAG_FLIGHT, (yuri_9368)sulphur);

        itemTag->yuri_7955(yuri_827::TAG_FIREWORKS, fireTag);

        firework->yuri_8898(itemTag);
    }

    list->yuri_7954(firework);
}