#include "Tutorial.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <yuri_4117>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"
#include "app/common/Tutorial/Constraints/TutorialConstraint.h"
#include "app/common/Tutorial/Hints/DiggerItemHint.h"
#include "app/common/Tutorial/Hints/LookAtEntityHint.h"
#include "app/common/Tutorial/Hints/LookAtTileHint.h"
#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tasks/ChoiceTask.h"
#include "app/common/Tutorial/Tasks/HorseChoiceTask.h"
#include "app/common/Tutorial/Tasks/InfoTask.h"
#include "app/common/Tutorial/Tasks/ProcedureCompoundTask.h"
#include "app/common/Tutorial/Tasks/RideEntityTask.h"
#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "TutorialMessage.h"
#include "util/Timer.h"
#include "util/StringHelpers.h"
#include "java/Class.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/QuartzBlockTile.h"
#include "minecraft/world/level/tile/SandStoneTile.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "minecraft/world/level/tile/WallTile.h"
#include "strings.h"

class yuri_1953;

std::vector<int> yuri_3144::s_completableTasks;

int yuri_3144::m_iTutorialHintDelayTime = 14000;
int yuri_3144::m_iTutorialDisplayMessageTime = 7000;
int yuri_3144::m_iTutorialMinimumDisplayMessageTime = 2000;
int yuri_3144::m_iTutorialExtraReminderTime = 13000;
int yuri_3144::m_iTutorialReminderTime =
    m_iTutorialDisplayMessageTime + m_iTutorialExtraReminderTime;
int yuri_3144::m_iTutorialConstraintDelayRemoveTicks = 15;
int yuri_3144::m_iTutorialFreezeTimeValue = 8000;

bool yuri_3144::yuri_2147::yuri_7025(yuri_2147* other) {
    if (other == nullptr) return false;

    bool textTheSame = (m_messageId == other->m_messageId) &&
                       (m_messageString.yuri_4117(other->m_messageString) == 0);
    bool titleTheSame = (m_titleId == other->m_titleId) &&
                        (m_titleString.yuri_4117(other->m_titleString) == 0);
    bool promptTheSame = (yuri_7369 == other->yuri_7369) &&
                         (m_promptString.yuri_4117(other->m_promptString) == 0);
    return textTheSame && titleTheSame && promptTheSame;
}

void yuri_3144::yuri_9115() {
    //
    /*
    *****
    *****
    THE ORDERING OF THESE SHOULD NOT CHANGE - Although the ordering may not be
    totally logical due to the order tasks were added, these map to bits in the
    profile data in this order. New tasks/hints should be added at the end.
    *****
    *****
    */
    s_completableTasks.yuri_7954(e_Tutorial_State_Inventory_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_2x2Crafting_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_3x3Crafting_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Furnace_Menu);

    s_completableTasks.yuri_7954(e_Tutorial_State_Riding_Minecart);
    s_completableTasks.yuri_7954(e_Tutorial_State_Riding_Boat);
    s_completableTasks.yuri_7954(e_Tutorial_State_Fishing);
    s_completableTasks.yuri_7954(e_Tutorial_State_Bed);

    s_completableTasks.yuri_7954(e_Tutorial_State_Container_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Trap_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Redstone_And_Piston);
    s_completableTasks.yuri_7954(e_Tutorial_State_Portal);
    s_completableTasks.yuri_7954(e_Tutorial_State_Creative_Inventory_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Food_Bar);
    s_completableTasks.yuri_7954(e_Tutorial_State_CreativeMode);
    s_completableTasks.yuri_7954(e_Tutorial_State_Brewing);
    s_completableTasks.yuri_7954(e_Tutorial_State_Brewing_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Enchanting);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Hold_To_Mine);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Tool_Damaged);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Swim_Up);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_2);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_3);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_4);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_5);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_6);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_7);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_8);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_9);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unused_10);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Rock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Stone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Planks);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Sapling);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Unbreakable);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Water);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Lava);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Sand);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Gravel);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Gold_Ore);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Iron_Ore);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Coal_Ore);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Tree_Trunk);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Glass);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Leaves);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Lapis_Ore);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Lapis_Block);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Dispenser);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Sandstone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Note_Block);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Powered_Rail);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Detector_Rail);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Tall_Grass);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Wool);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Flower);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Mushroom);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Gold_Block);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Iron_Block);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Stone_Slab);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Red_Brick);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Tnt);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Bookshelf);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Moss_Stone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Obsidian);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Torch);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_MobSpawner);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Chest);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Redstone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Diamond_Ore);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Diamond_Block);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Crafting_Table);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Crops);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Farmland);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Furnace);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Sign);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Door_Wood);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Ladder);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Rail);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Stairs_Stone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Lever);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_PressurePlate);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Door_Iron);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Redstone_Ore);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Redstone_Torch);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Button);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Snow);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Ice);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Cactus);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Clay);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Sugarcane);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Record_Player);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Pumpkin);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Hell_Rock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Hell_Sand);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Glowstone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Portal);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Pumpkin_Lit);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Cake);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Redstone_Repeater);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Trapdoor);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Piston);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Sticky_Piston);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Monster_Stone_Egg);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Stone_Brick_Smooth);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Huge_Mushroom);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Iron_Fence);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Thin_Glass);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Melon);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Vine);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Fence_Gate);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Mycel);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Water_Lily);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Nether_Brick);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Nether_Fence);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Nether_Stalk);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Enchant_Table);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Brewing_Stand);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Cauldron);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_End_Portal);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_End_Portal_Frame);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Squid);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Cow);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Sheep);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Chicken);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Pig);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Wolf);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Creeper);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Skeleton);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Spider);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Zombie);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Pig_Zombie);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Ghast);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Slime);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Enderman);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Silverfish);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Cave_Spider);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_MushroomCow);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_SnowMan);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_IronGolem);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_EnderDragon);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Blaze);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Lava_Slime);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Ozelot);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Villager);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Shovel);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Hatchet);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Pickaxe);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Flint_And_Steel);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Apple);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Bow);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Arrow);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Coal);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Diamond);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Iron_Ingot);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Gold_Ingot);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Sword);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Stick);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Bowl);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Mushroom_Stew);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_String);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Feather);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Sulphur);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Hoe);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Seeds);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Wheat);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Bread);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Helmet);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Chestplate);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Leggings);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Boots);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Flint);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Porkchop_Raw);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Porkchop_Cooked);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Painting);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Apple_Gold);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Sign);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Door_Wood);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Bucket_Empty);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Bucket_Water);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Bucket_Lava);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Minecart);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Saddle);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Door_Iron);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Redstone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Snowball);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Boat);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Leather);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Milk);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Brick);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Clay);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Reeds);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Paper);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Book);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Slimeball);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Minecart_Chest);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Minecart_Furnace);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Egg);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Compass);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Clock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Yellow_Dust);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Fish_Raw);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Fish_Cooked);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Dye_Powder);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Bone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Sugar);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Cake);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Diode);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Cookie);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Map);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Item_Record);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_White_Stone);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Dragon_Egg);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_RedstoneLamp);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Cocoa);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_EmeraldOre);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_EmeraldBlock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_EnderChest);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_TripwireSource);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Tripwire);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_CobblestoneWall);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Flowerpot);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Anvil);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_QuartzOre);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_QuartzBlock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_WoolCarpet);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Potato);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Carrot);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_CommandBlock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Beacon);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Activator_Rail);

    s_completableTasks.yuri_7954(eTutorial_Telemetry_TrialStart);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Halfway);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Complete);

    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_1);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_2);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_3);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_4);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_5);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_6);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_7);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_8);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_9);
    s_completableTasks.yuri_7954(eTutorial_Telemetry_Unused_10);

    s_completableTasks.yuri_7954(e_Tutorial_State_Enchanting_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Farming);
    s_completableTasks.yuri_7954(e_Tutorial_State_Breeding);
    s_completableTasks.yuri_7954(e_Tutorial_State_Golem);
    s_completableTasks.yuri_7954(e_Tutorial_State_Trading);
    s_completableTasks.yuri_7954(e_Tutorial_State_Trading_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Anvil);
    s_completableTasks.yuri_7954(e_Tutorial_State_Anvil_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Enderchests);
    s_completableTasks.yuri_7954(e_Tutorial_State_Horse_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Hopper_Menu);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_Wither);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Witch);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Bat);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Horse);

    s_completableTasks.yuri_7954(e_Tutorial_Hint_RedstoneBlock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_DaylightDetector);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Dropper);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Hopper);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_Comparator);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_ChestTrap);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_HayBlock);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_ClayHardened);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_ClayHardenedColored);
    s_completableTasks.yuri_7954(e_Tutorial_Hint_CoalBlock);

    s_completableTasks.yuri_7954(e_Tutorial_State_Beacon_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Fireworks_Menu);
    s_completableTasks.yuri_7954(e_Tutorial_State_Horse);
    s_completableTasks.yuri_7954(e_Tutorial_State_Hopper);
    s_completableTasks.yuri_7954(e_Tutorial_State_Beacon);
    s_completableTasks.yuri_7954(e_Tutorial_State_Fireworks);

    if (s_completableTasks.yuri_9050() > TUTORIAL_PROFILE_STORAGE_BITS) {
        app.yuri_563(
            "Warning: Too many tutorial completable tasks added, not enough "
            "bits allocated to stored them in the profile data");
        yuri_3750(false);
    }
}

<<<<<<< HEAD
yuri_3144::yuri_3144(int iPad, bool isFullTutorial /*= canon*/) : yuri_7341(iPad) {
=======
Tutorial::Tutorial(int iPad, bool isFullTutorial /*= false*/) : m_iPad(iPad) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_isFullTutorial = isFullTutorial;
    m_fullTutorialComplete = false;
    m_allTutorialsComplete = false;
    hasRequestedUI = false;
    uiTempDisabled = false;
    m_hintDisplayed = false;
    m_freezeTime = false;
    m_timeFrozen = false;
    m_UIScene = nullptr;
    m_allowShow = true;
    m_bHasTickedOnce = false;
    m_firstTickTime = {};

    // 4jcraft added, not initialized
    m_bSceneIsSplitscreen = false;

    m_lastMessage = nullptr;

    lastMessageTime = {};
    m_iTaskReminders = 0;
    m_lastMessageState = e_Tutorial_State_Gameplay;

    m_CurrentState = e_Tutorial_State_Gameplay;
    m_hasStateChanged = false;

    for (unsigned int i = 0; i < e_Tutorial_State_Max; ++i) {
        currentTask[i] = nullptr;
        currentFailedConstraint[i] = nullptr;
    }

    // DEFAULT TASKS THAT ALL TUTORIALS SHARE
    /*
     *
     *
     * GAMEPLAY
     *
     */

    if (!yuri_6899(e_Tutorial_Hint_Hold_To_Mine))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_3146(e_Tutorial_Hint_Hold_To_Mine, this,
                                 IDS_TUTORIAL_HINT_HOLD_TO_MINE,
                                 yuri_3146::e_Hint_HoldToMine));
    if (!yuri_6899(e_Tutorial_Hint_Tool_Damaged))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_3146(e_Tutorial_Hint_Tool_Damaged, this,
                                 IDS_TUTORIAL_HINT_TOOL_DAMAGED,
                                 yuri_3146::e_Hint_ToolDamaged));
    if (!yuri_6899(e_Tutorial_Hint_Swim_Up))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_3146(e_Tutorial_Hint_Swim_Up, this,
                                 IDS_TUTORIAL_HINT_SWIM_UP,
                                 yuri_3146::e_Hint_SwimUp));

    /*
     * TILE HINTS
     */
    int rockItems[] = {yuri_3088::stone_Id};
    if (!yuri_6899(e_Tutorial_Hint_Rock))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Rock, this, rockItems, 1));

    int stoneItems[] = {yuri_3088::cobblestone_Id};
    if (!yuri_6899(e_Tutorial_Hint_Stone))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Stone, this, stoneItems, 1));

    int plankItems[] = {yuri_3088::wood_Id};
    if (!yuri_6899(e_Tutorial_Hint_Planks))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Planks, this, plankItems, 1));

    int saplingItems[] = {yuri_3088::sapling_Id};
    if (!yuri_6899(e_Tutorial_Hint_Sapling))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Sapling, this, saplingItems, 1));

    int unbreakableItems[] = {yuri_3088::unbreakable_Id};
    if (!yuri_6899(e_Tutorial_Hint_Unbreakable))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Unbreakable, this,
                                   unbreakableItems, 1));

    int waterItems[] = {yuri_3088::water_Id, yuri_3088::calmWater_Id};
    if (!yuri_6899(e_Tutorial_Hint_Water))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Water, this, waterItems, 2));

    int lavaItems[] = {yuri_3088::lava_Id, yuri_3088::calmLava_Id};
    if (!yuri_6899(e_Tutorial_Hint_Lava))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Lava, this, lavaItems, 2));

    int sandItems[] = {yuri_3088::sand_Id};
    if (!yuri_6899(e_Tutorial_Hint_Sand))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Sand, this, sandItems, 1));

    int gravelItems[] = {yuri_3088::gravel_Id};
    if (!yuri_6899(e_Tutorial_Hint_Gravel))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Gravel, this, gravelItems, 1));

    int goldOreItems[] = {yuri_3088::goldOre_Id};
    if (!yuri_6899(e_Tutorial_Hint_Gold_Ore))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Gold_Ore, this, goldOreItems,
                                   1));

    int ironOreItems[] = {yuri_3088::ironOre_Id};
    if (!yuri_6899(e_Tutorial_Hint_Iron_Ore))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Iron_Ore, this, ironOreItems,
                                   1));

    int coalOreItems[] = {yuri_3088::coalOre_Id};
    if (!yuri_6899(e_Tutorial_Hint_Coal_Ore))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Coal_Ore, this, coalOreItems,
                                   1));

    int treeTrunkItems[] = {yuri_3088::treeTrunk_Id};
    if (!yuri_6899(e_Tutorial_Hint_Tree_Trunk))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Tree_Trunk, this,
                                   treeTrunkItems, 1));

    int leavesItems[] = {yuri_3088::leaves_Id};
    if (!yuri_6899(e_Tutorial_Hint_Leaves))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Leaves, this, leavesItems, 1));

    int glassItems[] = {yuri_3088::glass_Id};
    if (!yuri_6899(e_Tutorial_Hint_Glass))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Glass, this, glassItems, 1));

    int lapisOreItems[] = {yuri_3088::lapisOre_Id};
    if (!yuri_6899(e_Tutorial_Hint_Lapis_Ore))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Lapis_Ore, this,
                                   lapisOreItems, 1));

    int lapisBlockItems[] = {yuri_3088::lapisBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_Lapis_Block))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Lapis_Block, this,
                                   lapisBlockItems, 1));

    int dispenserItems[] = {yuri_3088::dispenser_Id};
    if (!yuri_6899(e_Tutorial_Hint_Dispenser))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Dispenser, this,
                                   dispenserItems, 1));

    int sandstoneItems[] = {yuri_3088::sandStone_Id};
    if (!yuri_6899(e_Tutorial_Hint_Sandstone)) {
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Sandstone, this, sandstoneItems,
                               1, -1, yuri_2497::TYPE_DEFAULT));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Sandstone, this, sandstoneItems,
                               1, -1, yuri_2497::TYPE_HEIROGLYPHS));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Sandstone, this, sandstoneItems,
                               1, -1, yuri_2497::TYPE_SMOOTHSIDE));
    }

    int noteBlockItems[] = {yuri_3088::noteblock_Id};
    if (!yuri_6899(e_Tutorial_Hint_Note_Block))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Note_Block, this,
                                   noteBlockItems, 1));

    int poweredRailItems[] = {yuri_3088::goldenRail_Id};
    if (!yuri_6899(e_Tutorial_Hint_Powered_Rail))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Powered_Rail, this,
                                   poweredRailItems, 1));

    int detectorRailItems[] = {yuri_3088::detectorRail_Id};
    if (!yuri_6899(e_Tutorial_Hint_Detector_Rail))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Detector_Rail, this,
                                   detectorRailItems, 1));

    int tallGrassItems[] = {yuri_3088::tallgrass_Id};
    if (!yuri_6899(e_Tutorial_Hint_Tall_Grass)) {
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Tall_Grass, this, tallGrassItems,
                               1, -1, yuri_3018::DEAD_SHRUB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Tall_Grass, this, tallGrassItems,
                               1, -1, yuri_3018::TALL_GRASS));
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Tall_Grass, this,
                                   tallGrassItems, 1, -1, yuri_3018::FERN));
    }

    int woolItems[] = {yuri_3088::wool_Id};
    if (!yuri_6899(e_Tutorial_Hint_Wool))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Wool, this, woolItems, 1));

    int flowerItems[] = {yuri_3088::flower_Id, yuri_3088::rose_Id};
    if (!yuri_6899(e_Tutorial_Hint_Flower))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Flower, this, flowerItems, 2));

    int mushroomItems[] = {yuri_3088::mushroom_brown_Id, yuri_3088::mushroom_red_Id};
    if (!yuri_6899(e_Tutorial_Hint_Mushroom))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Mushroom, this,
                                   mushroomItems, 2));

    int goldBlockItems[] = {yuri_3088::goldBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_Gold_Block))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Gold_Block, this,
                                   goldBlockItems, 1));

    int ironBlockItems[] = {yuri_3088::ironBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_Iron_Block))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Iron_Block, this,
                                   ironBlockItems, 1));

    int stoneSlabItems[] = {yuri_3088::stoneSlabHalf_Id, yuri_3088::stoneSlab_Id};
    if (!yuri_6899(e_Tutorial_Hint_Stone_Slab)) {
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::STONE_SLAB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::SAND_SLAB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::WOOD_SLAB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::COBBLESTONE_SLAB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::BRICK_SLAB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::SMOOTHBRICK_SLAB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::NETHERBRICK_SLAB));
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, stoneSlabItems,
                               2, -1, yuri_2964::QUARTZ_SLAB));
    }

    int woodSlabItems[] = {yuri_3088::woodSlabHalf_Id, yuri_3088::woodSlab_Id};
    if (!yuri_6899(e_Tutorial_Hint_Stone_Slab)) {
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Stone_Slab, this, woodSlabItems,
                               2, -1, yuri_3137::BIRCH_TRUNK));
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Stone_Slab, this,
                                   woodSlabItems, 2, -1, yuri_3137::DARK_TRUNK));
    }

    int redBrickItems[] = {yuri_3088::redBrick_Id};
    if (!yuri_6899(e_Tutorial_Hint_Red_Brick))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Red_Brick, this,
                                   redBrickItems, 1));

    int tntItems[] = {yuri_3088::tnt_Id};
    if (!yuri_6899(e_Tutorial_Hint_Tnt))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Tnt, this, tntItems, 1));

    int bookshelfItems[] = {yuri_3088::bookshelf_Id};
    if (!yuri_6899(e_Tutorial_Hint_Bookshelf))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Bookshelf, this,
                                   bookshelfItems, 1));

    int mossStoneItems[] = {yuri_3088::mossyCobblestone_Id};
    if (!yuri_6899(e_Tutorial_Hint_Moss_Stone))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Moss_Stone, this,
                                   mossStoneItems, 1));

    int obsidianItems[] = {yuri_3088::obsidian_Id};
    if (!yuri_6899(e_Tutorial_Hint_Obsidian))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Obsidian, this,
                                   obsidianItems, 1));

    int torchItems[] = {yuri_3088::torch_Id};
    if (!yuri_6899(e_Tutorial_Hint_Torch))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Torch, this, torchItems, 1));

    int mobSpawnerItems[] = {yuri_3088::mobSpawner_Id};
    if (!yuri_6899(e_Tutorial_Hint_MobSpawner))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_MobSpawner, this,
                                   mobSpawnerItems, 1));

    int chestItems[] = {yuri_3088::chest_Id};
    if (!yuri_6899(e_Tutorial_Hint_Chest))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Chest, this, chestItems, 1));

    int redstoneItems[] = {yuri_3088::redStoneDust_Id};
    if (!yuri_6899(e_Tutorial_Hint_Redstone))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Redstone, this,
                                   redstoneItems, 1, yuri_1687::redStone_Id));

    int diamondOreItems[] = {yuri_3088::diamondOre_Id};
    if (!yuri_6899(e_Tutorial_Hint_Diamond_Ore))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Diamond_Ore, this,
                                   diamondOreItems, 1));

    int diamondBlockItems[] = {yuri_3088::diamondBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_Diamond_Block))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Diamond_Block, this,
                                   diamondBlockItems, 1));

    int craftingTableItems[] = {yuri_3088::workBench_Id};
    if (!yuri_6899(e_Tutorial_Hint_Crafting_Table))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Crafting_Table, this,
                                   craftingTableItems, 1));

    int cropsItems[] = {yuri_3088::wheat_Id};
    if (!yuri_6899(e_Tutorial_Hint_Crops))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Crops, this, cropsItems, 1,
                                   -1, -1, 7));

    int farmlandItems[] = {yuri_3088::farmland_Id};
    if (!yuri_6899(e_Tutorial_Hint_Farmland))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Farmland, this,
                                   farmlandItems, 1));

    int furnaceItems[] = {yuri_3088::furnace_Id, yuri_3088::furnace_lit_Id};
    if (!yuri_6899(e_Tutorial_Hint_Furnace))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Furnace, this, furnaceItems, 2));

    int signItems[] = {yuri_3088::sign_Id, yuri_3088::wallSign_Id};
    if (!yuri_6899(e_Tutorial_Hint_Sign))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Sign, this, signItems, 2,
                                   yuri_1687::sign_Id));

    int doorWoodItems[] = {yuri_3088::door_wood_Id};
    if (!yuri_6899(e_Tutorial_Hint_Door_Wood))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Door_Wood, this,
                                   doorWoodItems, 1, yuri_1687::door_wood->yuri_6674));

    int ladderItems[] = {yuri_3088::ladder_Id};
    if (!yuri_6899(e_Tutorial_Hint_Ladder))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Ladder, this, ladderItems, 1));

    int stairsStoneItems[] = {
        yuri_3088::stairs_stone_Id,        yuri_3088::stairs_bricks_Id,
        yuri_3088::stairs_stoneBrick_Id,   yuri_3088::stairs_wood_Id,
        yuri_3088::stairs_sprucewood_Id,   yuri_3088::stairs_birchwood_Id,
        yuri_3088::stairs_netherBricks_Id, yuri_3088::stairs_sandstone_Id,
        yuri_3088::stairs_quartz_Id};
    if (!yuri_6899(e_Tutorial_Hint_Stairs_Stone))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Stairs_Stone, this,
                                   stairsStoneItems, 9));

    int railItems[] = {yuri_3088::rail_Id};
    if (!yuri_6899(e_Tutorial_Hint_Rail))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Rail, this, railItems, 1));

    int leverItems[] = {yuri_3088::lever_Id};
    if (!yuri_6899(e_Tutorial_Hint_Lever))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Lever, this, leverItems, 1));

    int pressurePlateItems[] = {yuri_3088::pressurePlate_stone_Id,
                                yuri_3088::pressurePlate_wood_Id};
    if (!yuri_6899(e_Tutorial_Hint_PressurePlate))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_PressurePlate, this,
                                   pressurePlateItems, 2));

    int doorIronItems[] = {yuri_3088::door_iron_Id};
    if (!yuri_6899(e_Tutorial_Hint_Door_Iron))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Door_Iron, this,
                                   doorIronItems, 1, yuri_1687::door_iron->yuri_6674));

    int redstoneOreItems[] = {yuri_3088::redStoneOre_Id, yuri_3088::redStoneOre_lit_Id};
    if (!yuri_6899(e_Tutorial_Hint_Redstone_Ore))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Redstone_Ore, this,
                                   redstoneOreItems, 2));

    int redstoneTorchItems[] = {yuri_3088::redstoneTorch_off_Id,
                                yuri_3088::redstoneTorch_on_Id};
    if (!yuri_6899(e_Tutorial_Hint_Redstone_Torch))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Redstone_Torch, this,
                                   redstoneTorchItems, 2));

    int buttonItems[] = {yuri_3088::button_stone_Id, yuri_3088::button_wood_Id};
    if (!yuri_6899(e_Tutorial_Hint_Button))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Button, this, buttonItems, 2));

    int snowItems[] = {yuri_3088::snow_Id};
    if (!yuri_6899(e_Tutorial_Hint_Snow))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Snow, this, snowItems, 1));

    int iceItems[] = {yuri_3088::ice_Id};
    if (!yuri_6899(e_Tutorial_Hint_Ice))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Ice, this, iceItems, 1));

    int cactusItems[] = {yuri_3088::cactus_Id};
    if (!yuri_6899(e_Tutorial_Hint_Cactus))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Cactus, this, cactusItems, 1));

    int clayItems[] = {yuri_3088::clay_Id};
    if (!yuri_6899(e_Tutorial_Hint_Clay))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Clay, this, clayItems, 1));

    int sugarCaneItems[] = {yuri_3088::reeds_Id};
    if (!yuri_6899(e_Tutorial_Hint_Sugarcane))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Sugarcane, this,
                                   sugarCaneItems, 1));

    int recordPlayerItems[] = {yuri_3088::jukebox_Id};
    if (!yuri_6899(e_Tutorial_Hint_Record_Player))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Record_Player, this,
                                   recordPlayerItems, 1));

    int pumpkinItems[] = {yuri_3088::pumpkin_Id};
    if (!yuri_6899(e_Tutorial_Hint_Pumpkin))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Pumpkin, this, pumpkinItems,
                                   1, -1, -1, 0));

    int hellRockItems[] = {yuri_3088::netherRack_Id};
    if (!yuri_6899(e_Tutorial_Hint_Hell_Rock))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Hell_Rock, this,
                                   hellRockItems, 1));

    int hellSandItems[] = {yuri_3088::soulsand_Id};
    if (!yuri_6899(e_Tutorial_Hint_Hell_Sand))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Hell_Sand, this,
                                   hellSandItems, 1));

    int glowstoneItems[] = {yuri_3088::glowstone_Id};
    if (!yuri_6899(e_Tutorial_Hint_Glowstone))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Glowstone, this,
                                   glowstoneItems, 1));

    int portalItems[] = {yuri_3088::portalTile_Id};
    if (!yuri_6899(e_Tutorial_Hint_Portal))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Portal, this, portalItems, 1));

    int pumpkinLitItems[] = {yuri_3088::litPumpkin_Id};
    if (!yuri_6899(e_Tutorial_Hint_Pumpkin_Lit))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Pumpkin_Lit, this,
                                   pumpkinLitItems, 1, -1, -1, 0));

    int cakeItems[] = {yuri_3088::cake_Id};
    if (!yuri_6899(e_Tutorial_Hint_Cake))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Cake, this, cakeItems, 1));

    int redstoneRepeaterItems[] = {yuri_3088::diode_on_Id, yuri_3088::diode_off_Id};
    if (!yuri_6899(e_Tutorial_Hint_Redstone_Repeater))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Redstone_Repeater, this,
                               redstoneRepeaterItems, 2, yuri_1687::repeater_Id));

    int trapdoorItems[] = {yuri_3088::trapdoor_Id};
    if (!yuri_6899(e_Tutorial_Hint_Trapdoor))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Trapdoor, this,
                                   trapdoorItems, 1));

    int pistonItems[] = {yuri_3088::pistonBase_Id};
    if (!yuri_6899(e_Tutorial_Hint_Piston))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Piston, this, pistonItems, 1));

    int stickyPistonItems[] = {yuri_3088::pistonStickyBase_Id};
    if (!yuri_6899(e_Tutorial_Hint_Sticky_Piston))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Sticky_Piston, this,
                                   stickyPistonItems, 1));

    int monsterStoneEggItems[] = {yuri_3088::monsterStoneEgg_Id};
    if (!yuri_6899(e_Tutorial_Hint_Monster_Stone_Egg))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Monster_Stone_Egg, this,
                                   monsterStoneEggItems, 1));

    int stoneBrickSmoothItems[] = {yuri_3088::stoneBrick_Id};
    if (!yuri_6899(e_Tutorial_Hint_Stone_Brick_Smooth))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Stone_Brick_Smooth, this,
                                   stoneBrickSmoothItems, 1));

    int hugeMushroomItems[] = {yuri_3088::hugeMushroom_brown_Id,
                               yuri_3088::hugeMushroom_red_Id};
    if (!yuri_6899(e_Tutorial_Hint_Huge_Mushroom))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Huge_Mushroom, this,
                                   hugeMushroomItems, 2));

    int ironFenceItems[] = {yuri_3088::ironFence_Id};
    if (!yuri_6899(e_Tutorial_Hint_Iron_Fence))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Iron_Fence, this,
                                   ironFenceItems, 1));

    int thisGlassItems[] = {yuri_3088::thinGlass_Id};
    if (!yuri_6899(e_Tutorial_Hint_Thin_Glass))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Thin_Glass, this,
                                   thisGlassItems, 1));

    int melonItems[] = {yuri_3088::melon_Id};
    if (!yuri_6899(e_Tutorial_Hint_Melon))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Melon, this, melonItems, 1));

    int vineItems[] = {yuri_3088::vine_Id};
    if (!yuri_6899(e_Tutorial_Hint_Vine))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Vine, this, vineItems, 1));

    int fenceGateItems[] = {yuri_3088::fenceGate_Id};
    if (!yuri_6899(e_Tutorial_Hint_Fence_Gate))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Fence_Gate, this,
                                   fenceGateItems, 1));

    int mycelItems[] = {yuri_3088::mycel_Id};
    if (!yuri_6899(e_Tutorial_Hint_Mycel))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Mycel, this, mycelItems, 1));

    int waterLilyItems[] = {yuri_3088::waterLily_Id};
    if (!yuri_6899(e_Tutorial_Hint_Water_Lily))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Water_Lily, this,
                                   waterLilyItems, 1));

    int netherBrickItems[] = {yuri_3088::netherBrick_Id};
    if (!yuri_6899(e_Tutorial_Hint_Nether_Brick))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Nether_Brick, this,
                                   netherBrickItems, 1));

    int netherFenceItems[] = {yuri_3088::netherFence_Id};
    if (!yuri_6899(e_Tutorial_Hint_Nether_Fence))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Nether_Fence, this,
                                   netherFenceItems, 1));

    int netherStalkItems[] = {yuri_3088::netherStalk_Id};
    if (!yuri_6899(e_Tutorial_Hint_Nether_Stalk))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Nether_Stalk, this,
                                   netherStalkItems, 1));

    int enchantTableItems[] = {yuri_3088::enchantTable_Id};
    if (!yuri_6899(e_Tutorial_Hint_Enchant_Table))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Enchant_Table, this,
                                   enchantTableItems, 1));

    int brewingStandItems[] = {yuri_3088::brewingStand_Id};
    if (!yuri_6899(e_Tutorial_Hint_Brewing_Stand))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Brewing_Stand, this,
                               brewingStandItems, 1, yuri_1687::brewingStand_Id));

    int cauldronItems[] = {yuri_3088::cauldron_Id};
    if (!yuri_6899(e_Tutorial_Hint_Cauldron))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Cauldron, this,
                                   cauldronItems, 1, yuri_1687::cauldron_Id));

    int endPortalItems[] = {yuri_3088::endPortalTile_Id};
    if (!yuri_6899(e_Tutorial_Hint_End_Portal))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_End_Portal, this,
                                   endPortalItems, 1, -2));

    int endPortalFrameItems[] = {yuri_3088::endPortalFrameTile_Id};
    if (!yuri_6899(e_Tutorial_Hint_End_Portal_Frame))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_End_Portal_Frame, this,
                                   endPortalFrameItems, 1));

    int whiteStoneItems[] = {yuri_3088::endStone_Id};
    if (!yuri_6899(e_Tutorial_Hint_White_Stone))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_White_Stone, this,
                                   whiteStoneItems, 1));

    int dragonEggItems[] = {yuri_3088::dragonEgg_Id};
    if (!yuri_6899(e_Tutorial_Hint_Dragon_Egg))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Dragon_Egg, this,
                                   dragonEggItems, 1));

    int redstoneLampItems[] = {yuri_3088::redstoneLight_Id,
                               yuri_3088::redstoneLight_lit_Id};
    if (!yuri_6899(e_Tutorial_Hint_RedstoneLamp))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_RedstoneLamp, this,
                                   redstoneLampItems, 2));

    int cocoaItems[] = {yuri_3088::cocoa_Id};
    if (!yuri_6899(e_Tutorial_Hint_Cocoa))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Cocoa, this, cocoaItems, 1,
                               yuri_1687::dye_powder_Id, -1, yuri_671::BROWN));

    int emeraldOreItems[] = {yuri_3088::emeraldOre_Id};
    if (!yuri_6899(e_Tutorial_Hint_EmeraldOre))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_EmeraldOre, this,
                                   emeraldOreItems, 1));

    int emeraldBlockItems[] = {yuri_3088::emeraldBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_EmeraldBlock))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_EmeraldBlock, this,
                                   emeraldBlockItems, 1));

    int enderChestItems[] = {yuri_3088::enderChest_Id};
    if (!yuri_6899(e_Tutorial_Hint_EnderChest))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_EnderChest, this,
                                   enderChestItems, 1));

    int tripwireSourceItems[] = {yuri_3088::tripWireSource_Id};
    if (!yuri_6899(e_Tutorial_Hint_TripwireSource))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_TripwireSource, this,
                                   tripwireSourceItems, 1));

    int tripwireItems[] = {yuri_3088::tripWire_Id};
    if (!yuri_6899(e_Tutorial_Hint_Tripwire))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Tripwire, this,
                                   tripwireItems, 1, yuri_1687::string_Id));

    int cobblestoneWallItems[] = {yuri_3088::cobbleWall_Id};
    if (!yuri_6899(e_Tutorial_Hint_CobblestoneWall)) {
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_CobblestoneWall, this,
                                   cobblestoneWallItems, 1, -1,
                                   yuri_3358::TYPE_NORMAL));
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_CobblestoneWall, this,
                                   cobblestoneWallItems, 1, -1,
                                   yuri_3358::TYPE_MOSSY));
    }

    int flowerpotItems[] = {yuri_3088::flowerPot_Id};
    if (!yuri_6899(e_Tutorial_Hint_Flowerpot))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Flowerpot, this,
                                   flowerpotItems, 1, yuri_1687::flowerPot_Id));

    int anvilItems[] = {yuri_3088::anvil_Id};
    if (!yuri_6899(e_Tutorial_Hint_Anvil))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Anvil, this, anvilItems, 1));

    int quartzOreItems[] = {yuri_3088::netherQuartz_Id};
    if (!yuri_6899(e_Tutorial_Hint_QuartzOre))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_QuartzOre, this,
                                   quartzOreItems, 1));

    int quartzBlockItems[] = {yuri_3088::quartzBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_QuartzBlock)) {
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_QuartzBlock, this,
                                   quartzBlockItems, 1, -1,
                                   yuri_2190::TYPE_DEFAULT));
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_QuartzBlock, this,
                                   quartzBlockItems, 1, -1,
                                   yuri_2190::TYPE_CHISELED));
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_QuartzBlock, this,
                                   quartzBlockItems, 1, -1,
                                   yuri_2190::TYPE_LINES_Y));
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_QuartzBlock, this,
                                   quartzBlockItems, 1, -1,
                                   yuri_2190::TYPE_LINES_X));
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_QuartzBlock, this,
                                   quartzBlockItems, 1, -1,
                                   yuri_2190::TYPE_LINES_Z));
    }

    int carpetItems[] = {yuri_3088::woolCarpet_Id};
    if (!yuri_6899(e_Tutorial_Hint_WoolCarpet))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_WoolCarpet, this,
                                   carpetItems, 1));

    int potatoItems[] = {yuri_3088::potatoes_Id};
    if (!yuri_6899(e_Tutorial_Hint_Potato))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Potato, this, potatoItems, 1,
                                   -1, -1, 7));

    int carrotItems[] = {yuri_3088::carrots_Id};
    if (!yuri_6899(e_Tutorial_Hint_Carrot))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Carrot, this, carrotItems, 1,
                                   -1, -1, 7));

    int commandBlockItems[] = {yuri_3088::commandBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_CommandBlock))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_CommandBlock, this,
                                   commandBlockItems, 1));

    int beaconItems[] = {yuri_3088::beacon_Id};
    if (!yuri_6899(e_Tutorial_Hint_Beacon))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Beacon, this, beaconItems, 1));

    int activatorRailItems[] = {yuri_3088::activatorRail_Id};
    if (!yuri_6899(e_Tutorial_Hint_Activator_Rail))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Activator_Rail, this,
                                   activatorRailItems, 1));

    int redstoneBlockItems[] = {yuri_3088::redstoneBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_RedstoneBlock))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_RedstoneBlock, this,
                                   redstoneBlockItems, 1));

    int daylightDetectorItems[] = {yuri_3088::daylightDetector_Id};
    if (!yuri_6899(e_Tutorial_Hint_DaylightDetector))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_DaylightDetector, this,
                                   daylightDetectorItems, 1));

    int dropperItems[] = {yuri_3088::dropper_Id};
    if (!yuri_6899(e_Tutorial_Hint_Dropper))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Dropper, this, dropperItems, 1));

    int hopperItems[] = {yuri_3088::hopper_Id};
    if (!yuri_6899(e_Tutorial_Hint_Hopper))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1839(e_Tutorial_Hint_Hopper, this, hopperItems, 1));

    int comparatorItems[] = {yuri_3088::comparator_off_Id, yuri_3088::comparator_on_Id};
    if (!yuri_6899(e_Tutorial_Hint_Comparator))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_Comparator, this,
                                   comparatorItems, 2, yuri_1687::comparator_Id));

    int trappedChestItems[] = {yuri_3088::chest_trap_Id};
    if (!yuri_6899(e_Tutorial_Hint_ChestTrap))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_ChestTrap, this,
                                   trappedChestItems, 1));

    int hayBlockItems[] = {yuri_3088::hayBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_HayBlock))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_HayBlock, this,
                                   hayBlockItems, 1));

    int clayHardenedItems[] = {yuri_3088::clayHardened_Id};
    if (!yuri_6899(e_Tutorial_Hint_ClayHardened))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_ClayHardened, this,
                                   clayHardenedItems, 1));

    int clayHardenedColoredItems[] = {yuri_3088::clayHardened_colored_Id};
    if (!yuri_6899(e_Tutorial_Hint_ClayHardenedColored))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_ClayHardenedColored, this,
                                   clayHardenedColoredItems, 1));

    int coalBlockItems[] = {yuri_3088::coalBlock_Id};
    if (!yuri_6899(e_Tutorial_Hint_CoalBlock))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1839(e_Tutorial_Hint_CoalBlock, this,
                                   coalBlockItems, 1));

    /*
     * ENTITY HINTS
     */
    if (!yuri_6899(e_Tutorial_Hint_Squid))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Squid, this,
                                     IDS_DESC_SQUID, IDS_SQUID, eTYPE_SQUID));
    if (!yuri_6899(e_Tutorial_Hint_Cow))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Cow, this, IDS_DESC_COW,
                                     IDS_COW, eTYPE_COW));
    if (!yuri_6899(e_Tutorial_Hint_Sheep))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Sheep, this,
                                     IDS_DESC_SHEEP, IDS_SHEEP, eTYPE_SHEEP));
    if (!yuri_6899(e_Tutorial_Hint_Chicken))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1837(e_Tutorial_Hint_Chicken, this,
                                 IDS_DESC_CHICKEN, IDS_CHICKEN, eTYPE_CHICKEN));
    if (!yuri_6899(e_Tutorial_Hint_Pig))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Pig, this, IDS_DESC_PIG,
                                     IDS_PIG, eTYPE_PIG));
    if (!yuri_6899(e_Tutorial_Hint_Wolf))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Wolf, this, IDS_DESC_WOLF,
                                     IDS_WOLF, eTYPE_WOLF));
    if (!yuri_6899(e_Tutorial_Hint_Creeper))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1837(e_Tutorial_Hint_Creeper, this,
                                 IDS_DESC_CREEPER, IDS_CREEPER, eTYPE_CREEPER));
    if (!yuri_6899(e_Tutorial_Hint_Skeleton))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Skeleton, this,
                                     IDS_DESC_SKELETON, IDS_SKELETON,
                                     eTYPE_SKELETON));
    if (!yuri_6899(e_Tutorial_Hint_Spider))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1837(e_Tutorial_Hint_Spider, this, IDS_DESC_SPIDER,
                                 IDS_SPIDER, eTYPE_SPIDER));
    if (!yuri_6899(e_Tutorial_Hint_Zombie))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1837(e_Tutorial_Hint_Zombie, this, IDS_DESC_ZOMBIE,
                                 IDS_ZOMBIE, eTYPE_ZOMBIE));
    if (!yuri_6899(e_Tutorial_Hint_Pig_Zombie))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Pig_Zombie, this,
                                     IDS_DESC_PIGZOMBIE, IDS_PIGZOMBIE,
                                     eTYPE_PIGZOMBIE));
    if (!yuri_6899(e_Tutorial_Hint_Ghast))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Ghast, this,
                                     IDS_DESC_GHAST, IDS_GHAST, eTYPE_GHAST));
    if (!yuri_6899(e_Tutorial_Hint_Slime))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Slime, this,
                                     IDS_DESC_SLIME, IDS_SLIME, eTYPE_SLIME));
    if (!yuri_6899(e_Tutorial_Hint_Enderman))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Enderman, this,
                                     IDS_DESC_ENDERMAN, IDS_ENDERMAN,
                                     eTYPE_ENDERMAN));
    if (!yuri_6899(e_Tutorial_Hint_Silverfish))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Silverfish, this,
                                     IDS_DESC_SILVERFISH, IDS_SILVERFISH,
                                     eTYPE_SILVERFISH));
    if (!yuri_6899(e_Tutorial_Hint_Cave_Spider))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Cave_Spider, this,
                                     IDS_DESC_CAVE_SPIDER, IDS_CAVE_SPIDER,
                                     eTYPE_CAVESPIDER));
    if (!yuri_6899(e_Tutorial_Hint_MushroomCow))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_MushroomCow, this,
                                     IDS_DESC_MUSHROOM_COW, IDS_MUSHROOM_COW,
                                     eTYPE_MUSHROOMCOW));
    if (!yuri_6899(e_Tutorial_Hint_SnowMan))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1837(e_Tutorial_Hint_SnowMan, this,
                                 IDS_DESC_SNOWMAN, IDS_SNOWMAN, eTYPE_SNOWMAN));
    if (!yuri_6899(e_Tutorial_Hint_IronGolem))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_IronGolem, this,
                                     IDS_DESC_IRONGOLEM, IDS_IRONGOLEM,
                                     eTYPE_VILLAGERGOLEM));
    if (!yuri_6899(e_Tutorial_Hint_EnderDragon))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_EnderDragon, this,
                                     IDS_DESC_ENDERDRAGON, IDS_ENDERDRAGON,
                                     eTYPE_ENDERDRAGON));
    if (!yuri_6899(e_Tutorial_Hint_Blaze))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Blaze, this,
                                     IDS_DESC_BLAZE, IDS_BLAZE, eTYPE_BLAZE));
    if (!yuri_6899(e_Tutorial_Hint_Lava_Slime))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Lava_Slime, this,
                                     IDS_DESC_LAVA_SLIME, IDS_LAVA_SLIME,
                                     eTYPE_LAVASLIME));
    if (!yuri_6899(e_Tutorial_Hint_Ozelot))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1837(e_Tutorial_Hint_Ozelot, this, IDS_DESC_OZELOT,
                                 IDS_OZELOT, eTYPE_OCELOT));
    if (!yuri_6899(e_Tutorial_Hint_Villager))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Villager, this,
                                     IDS_DESC_VILLAGER, IDS_VILLAGER,
                                     eTYPE_VILLAGER));
    if (!yuri_6899(e_Tutorial_Hint_Wither))
        yuri_3619(
            e_Tutorial_State_Gameplay,
            new yuri_1837(e_Tutorial_Hint_Wither, this, IDS_DESC_WITHER,
                                 IDS_WITHER, eTYPE_WITHERBOSS));
    if (!yuri_6899(e_Tutorial_Hint_Witch))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Witch, this,
                                     IDS_DESC_WITCH, IDS_WITCH, eTYPE_WITCH));
    if (!yuri_6899(e_Tutorial_Hint_Bat))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Bat, this, IDS_DESC_BAT,
                                     IDS_BAT, eTYPE_BAT));
    if (!yuri_6899(e_Tutorial_Hint_Horse))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_1837(e_Tutorial_Hint_Horse, this,
                                     IDS_DESC_HORSE, IDS_HORSE, eTYPE_HORSE));

    /*
     * ITEM HINTS
     */
    int shovelItems[] = {yuri_1687::shovel_wood->yuri_6674, yuri_1687::shovel_stone->yuri_6674,
                         yuri_1687::shovel_iron->yuri_6674, yuri_1687::shovel_gold->yuri_6674,
                         yuri_1687::shovel_diamond->yuri_6674};
    if (!yuri_6899(e_Tutorial_Hint_Item_Shovel))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_610(e_Tutorial_Hint_Item_Shovel, this,
                                   IDS_TUTORIAL_HINT_DIGGER_ITEM_SHOVEL,
                                   shovelItems, 5));

    int hatchetItems[] = {yuri_1687::hatchet_wood->yuri_6674, yuri_1687::hatchet_stone->yuri_6674,
                          yuri_1687::hatchet_iron->yuri_6674, yuri_1687::hatchet_gold->yuri_6674,
                          yuri_1687::hatchet_diamond->yuri_6674};
    if (!yuri_6899(e_Tutorial_Hint_Item_Hatchet))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_610(e_Tutorial_Hint_Item_Hatchet, this,
                                   IDS_TUTORIAL_HINT_DIGGER_ITEM_HATCHET,
                                   hatchetItems, 5));

    int pickaxeItems[] = {yuri_1687::pickAxe_wood->yuri_6674, yuri_1687::pickAxe_stone->yuri_6674,
                          yuri_1687::pickAxe_iron->yuri_6674, yuri_1687::pickAxe_gold->yuri_6674,
                          yuri_1687::pickAxe_diamond->yuri_6674};
    if (!yuri_6899(e_Tutorial_Hint_Item_Pickaxe))
        yuri_3619(e_Tutorial_State_Gameplay,
                new yuri_610(e_Tutorial_Hint_Item_Pickaxe, this,
                                   IDS_TUTORIAL_HINT_DIGGER_ITEM_PICKAXE,
                                   pickaxeItems, 5));

    /*
     *
     *
     * INVENTORY
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Inventory_Menu)) {
        yuri_2177* inventoryOverviewTask =
            new yuri_2177(this);
        inventoryOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_INV_OVERVIEW,
            IDS_TUTORIAL_PROMPT_INV_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        inventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_INV_PICK_UP,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        inventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_INV_MOVE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        inventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_INV_DROP,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        inventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_INV_INFO,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Inventory_Menu, inventoryOverviewTask);
    }

    /*
     *
     *
     * CREATIVE INVENTORY
     *
     */
    if (isFullTutorial ||
        !yuri_7070(e_Tutorial_State_Creative_Inventory_Menu)) {
        yuri_2177* creativeInventoryOverviewTask =
            new yuri_2177(this);
        creativeInventoryOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_CREATIVE_INV_OVERVIEW,
            IDS_TUTORIAL_PROMPT_CREATIVE_INV_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        creativeInventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CREATIVE_INV_PICK_UP,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        creativeInventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CREATIVE_INV_MOVE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        creativeInventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CREATIVE_INV_DROP,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        creativeInventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CREATIVE_INV_NAV,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        creativeInventoryOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CREATIVE_INV_INFO,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Creative_Inventory_Menu,
                creativeInventoryOverviewTask);
    }

    /*
     *
     *
     * CRAFTING
     *
     */
    if (isFullTutorial ||
        !yuri_7070(e_Tutorial_State_2x2Crafting_Menu)) {
        yuri_2177* craftingOverviewTask =
            new yuri_2177(this);
        craftingOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_CRAFT_OVERVIEW,
            IDS_TUTORIAL_PROMPT_CRAFT_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        craftingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CRAFT_NAV,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        craftingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CRAFT_CREATE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        craftingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_CRAFT_CRAFT_TABLE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        craftingOverviewTask->yuri_88(
            new yuri_1594(this, IDS_TUTORIAL_TASK_CRAFT_INVENTORY,
                         IDS_TUTORIAL_PROMPT_PRESS_X_TO_TOGGLE_DESCRIPTION,
                         false, ACTION_MENU_X));
        craftingOverviewTask->yuri_88(
            new yuri_1594(this, IDS_TUTORIAL_TASK_CRAFT_DESCRIPTION,
                         IDS_TUTORIAL_PROMPT_PRESS_X_TO_TOGGLE_INGREDIENTS,
                         false, ACTION_MENU_X));
        craftingOverviewTask->yuri_88(
            new yuri_1594(this, IDS_TUTORIAL_TASK_CRAFT_INGREDIENTS,
                         IDS_TUTORIAL_PROMPT_PRESS_X_TO_TOGGLE_INVENTORY, false,
                         ACTION_MENU_X));
        yuri_3681(e_Tutorial_State_2x2Crafting_Menu, craftingOverviewTask);
    }
    // Other tasks can be added in the derived classes

    yuri_3619(e_Tutorial_State_2x2Crafting_Menu,
            new yuri_3146(e_Tutorial_Hint_Always_On, this,
                             IDS_TUTORIAL_HINT_CRAFT_NO_INGREDIENTS,
                             yuri_3146::e_Hint_NoIngredients));

    yuri_3619(e_Tutorial_State_3x3Crafting_Menu,
            new yuri_3146(e_Tutorial_Hint_Always_On, this,
                             IDS_TUTORIAL_HINT_CRAFT_NO_INGREDIENTS,
                             yuri_3146::e_Hint_NoIngredients));

    /*
     *
     *
     * FURNACE
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Furnace_Menu)) {
        yuri_2177* furnaceOverviewTask =
            new yuri_2177(this);
        furnaceOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_FURNACE_OVERVIEW,
            IDS_TUTORIAL_PROMPT_FURNACE_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        furnaceOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FURNACE_METHOD,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        furnaceOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FURNACE_FUELS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        furnaceOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FURNACE_INGREDIENTS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Furnace_Menu, furnaceOverviewTask);
    }
    // Other tasks can be added in the derived classes

    /*
     *
     *
     * BREWING MENU
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Brewing_Menu)) {
        yuri_2177* brewingOverviewTask =
            new yuri_2177(this);
        brewingOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_BREWING_MENU_OVERVIEW,
            IDS_TUTORIAL_PROMPT_BREWING_MENU_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        brewingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_BREWING_MENU_METHOD,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        brewingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_BREWING_MENU_BASIC_INGREDIENTS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        brewingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_BREWING_MENU_EXTENDED_INGREDIENTS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        brewingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_BREWING_MENU_EXTENDED_INGREDIENTS_2,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Brewing_Menu, brewingOverviewTask);
    }
    // Other tasks can be added in the derived classes

    /*
     *
     *
     * ENCHANTING MENU
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Enchanting_Menu)) {
        yuri_2177* enchantingOverviewTask =
            new yuri_2177(this);
        enchantingOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_ENCHANTING_MENU_OVERVIEW,
            IDS_TUTORIAL_PROMPT_ENCHANTING_MENU_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        enchantingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ENCHANTING_MENU_START,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        enchantingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ENCHANTING_MENU_ENCHANTMENTS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        enchantingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ENCHANTING_MENU_COST,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        enchantingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ENCHANTING_MENU_ENCHANT,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        enchantingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ENCHANTING_MENU_BETTER_ENCHANTMENTS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Enchanting_Menu, enchantingOverviewTask);
    }
    // Other tasks can be added in the derived classes

    /*
     *
     *
     * ANVIL MENU
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Anvil_Menu)) {
        yuri_2177* anvilOverviewTask =
            new yuri_2177(this);
        anvilOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_OVERVIEW,
            IDS_TUTORIAL_PROMPT_ANVIL_MENU_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        anvilOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_START,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        anvilOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_REPAIR,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        anvilOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_SACRIFICE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        anvilOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_ENCHANT,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        anvilOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_COST,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        anvilOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_RENAMING,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        anvilOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_ANVIL_MENU_SMITH,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Anvil_Menu, anvilOverviewTask);
    }
    // Other tasks can be added in the derived classes

    /*
     *
     *
     * TRADING MENU
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Trading_Menu)) {
        yuri_2177* tradingOverviewTask =
            new yuri_2177(this);
        tradingOverviewTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_TRADING_MENU_OVERVIEW,
            IDS_TUTORIAL_PROMPT_TRADING_MENU_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        tradingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_TRADING_MENU_START,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        tradingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_TRADING_MENU_UNAVAILABLE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        tradingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_TRADING_MENU_DETAILS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        tradingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_TRADING_MENU_INVENTORY,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        tradingOverviewTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_TRADING_MENU_TRADE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Trading_Menu, tradingOverviewTask);
    }
    // Other tasks can be added in the derived classes

    /*
     *
     *
     * HORSE ENCOUNTER
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Horse)) {
        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1287(
                    this, IDS_TUTORIAL_TASK_HORSE_OVERVIEW,
                    IDS_TUTORIAL_TASK_DONKEY_OVERVIEW,
                    IDS_TUTORIAL_TASK_MULE_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_HORSE_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));

        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_INTRO,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_PURPOSE,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_TAMING,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_TAMING2,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));

        // 4J-JEV: Only force the RideEntityTask if we're on the full-tutorial.
        if (isFullTutorial)
            yuri_3681(e_Tutorial_State_Horse,
                    new yuri_2431(eTYPE_HORSE, this,
                                       IDS_TUTORIAL_TASK_HORSE_RIDE, true,
                                       nullptr, false, false, false));
        else
            yuri_3681(e_Tutorial_State_Horse,
                    new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_RIDE,
                                 IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                                 ACTION_MENU_A));

        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_SADDLES,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_SADDLEBAGS,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Horse,
                new yuri_1594(this, IDS_TUTORIAL_TASK_HORSE_BREEDING,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
    }

    /*
     *
     *
     * HORSE MENU
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Horse_Menu)) {
        yuri_2177* horseMenuTask = new yuri_2177(this);
        horseMenuTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_HORSE_MENU_OVERVIEW,
            IDS_TUTORIAL_PROMPT_HORSE_MENU_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        horseMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_HORSE_MENU_LAYOUT,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        horseMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_HORSE_MENU_EQUIPMENT,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        horseMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_HORSE_MENU_SADDLEBAGS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Horse_Menu, horseMenuTask);
    }

    /*
     *
     *
     * FIREWORKS MENU
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Fireworks_Menu)) {
        yuri_2177* fireworksMenuTask =
            new yuri_2177(this);
        fireworksMenuTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_OVERVIEW,
            IDS_TUTORIAL_PROMPT_FIREWORK_MENU_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_BASIC_START,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_BASIC_STARS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_BASIC_HEIGHT,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_BASIC_CRAFT,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_ADV_START,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_ADV_COLOUR,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_ADV_SHAPE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_ADV_EFFECT,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        fireworksMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_FIREWORK_MENU_ADV_FADE,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Fireworks_Menu, fireworksMenuTask);
    }

    /*
     *
     *
     * BEACON MENU
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Beacon_Menu)) {
        yuri_2177* beaconMenuTask = new yuri_2177(this);
        beaconMenuTask->yuri_88(new yuri_344(
            this, IDS_TUTORIAL_TASK_BEACON_MENU_OVERVIEW,
            IDS_TUTORIAL_PROMPT_BEACON_MENU_OVERVIEW, true, ACTION_MENU_A,
            ACTION_MENU_B, e_Tutorial_Completion_Complete_State));
        beaconMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_BEACON_MENU_PRIMARY_POWERS,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        beaconMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_BEACON_MENU_SECONDARY_POWER,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        beaconMenuTask->yuri_88(new yuri_1594(
            this, IDS_TUTORIAL_TASK_BEACON_MENU_ACTIVATION,
            IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true, ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Beacon_Menu, beaconMenuTask);
    }

    /*
     *
     *
     * MINECART
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Riding_Minecart)) {
        yuri_3681(e_Tutorial_State_Riding_Minecart,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_MINECART_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_MINECART_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));
        yuri_3681(e_Tutorial_State_Riding_Minecart,
                new yuri_1594(this, IDS_TUTORIAL_TASK_MINECART_RAILS,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Riding_Minecart,
                new yuri_1594(this, IDS_TUTORIAL_TASK_MINECART_POWERED_RAILS,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Riding_Minecart,
                new yuri_1594(this, IDS_TUTORIAL_TASK_MINECART_PUSHING,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
    }

    /*
     *
     *
     * BOAT
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Riding_Boat)) {
        yuri_3681(e_Tutorial_State_Riding_Boat,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_BOAT_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_BOAT_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));
        yuri_3681(e_Tutorial_State_Riding_Boat,
                new yuri_1594(this, IDS_TUTORIAL_TASK_BOAT_STEER,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
    }

    /*
     *
     *
     * FISHING
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Fishing)) {
        yuri_3681(e_Tutorial_State_Fishing,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_FISHING_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_FISHING_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));
        yuri_3681(e_Tutorial_State_Fishing,
                new yuri_1594(this, IDS_TUTORIAL_TASK_FISHING_CAST,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Fishing,
                new yuri_1594(this, IDS_TUTORIAL_TASK_FISHING_FISH,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Fishing,
                new yuri_1594(this, IDS_TUTORIAL_TASK_FISHING_USES,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
    }

    /*
     *
     *
     * BED
     *
     */
    if (isFullTutorial || !yuri_7070(e_Tutorial_State_Bed)) {
        yuri_3681(e_Tutorial_State_Bed,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_BED_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_BED_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));
        yuri_3681(e_Tutorial_State_Bed,
                new yuri_1594(this, IDS_TUTORIAL_TASK_BED_PLACEMENT,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Bed,
                new yuri_1594(this, IDS_TUTORIAL_TASK_BED_MULTIPLAYER,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
    }

    /*
     *
     *
     * FOOD BAR
     *
     */
    if (!isFullTutorial && !yuri_7070(e_Tutorial_State_Food_Bar)) {
        yuri_3681(e_Tutorial_State_Food_Bar,
                new yuri_344(
                    this, IDS_TUTORIAL_TASK_FOOD_BAR_OVERVIEW,
                    IDS_TUTORIAL_PROMPT_FOOD_BAR_OVERVIEW, true, ACTION_MENU_A,
                    ACTION_MENU_B,
                    e_Tutorial_Completion_Complete_State_Gameplay_Constraints));
        yuri_3681(e_Tutorial_State_Food_Bar,
                new yuri_1594(this, IDS_TUTORIAL_TASK_FOOD_BAR_DEPLETE,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Food_Bar,
                new yuri_1594(this, IDS_TUTORIAL_TASK_FOOD_BAR_HEAL,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
        yuri_3681(e_Tutorial_State_Food_Bar,
                new yuri_1594(this, IDS_TUTORIAL_TASK_FOOD_BAR_FEED,
                             IDS_TUTORIAL_PROMPT_PRESS_A_TO_CONTINUE, true,
                             ACTION_MENU_A));
    }
}

yuri_3144::~yuri_3144() {
    for (auto yuri_7136 = m_globalConstraints.yuri_3801(); yuri_7136 != m_globalConstraints.yuri_4502();
         ++yuri_7136) {
        delete (*yuri_7136);
    }
    for (std::unordered_map<int, yuri_3147*>::iterator yuri_7136 =
             messages.yuri_3801();
         yuri_7136 != messages.yuri_4502(); ++yuri_7136) {
        delete (*yuri_7136).yuri_8394;
    }
    for (unsigned int i = 0; i < e_Tutorial_State_Max; ++i) {
        for (auto yuri_7136 = activeTasks[i].yuri_3801(); yuri_7136 < activeTasks[i].yuri_4502();
             ++yuri_7136) {
            delete (*yuri_7136);
        }
        for (auto yuri_7136 = hints[i].yuri_3801(); yuri_7136 < hints[i].yuri_4502(); ++yuri_7136) {
            delete (*yuri_7136);
        }

        currentTask[i] = nullptr;
        currentFailedConstraint[i] = nullptr;
    }
}

void yuri_3144::yuri_4308(int iPad) {
    GAME_SETTINGS* pGameSettings =
        (GAME_SETTINGS*)ProfileManager.yuri_1005(iPad);
    memset(pGameSettings->ucTutorialCompletion, 0,
           yuri_3009);
    pGameSettings->uiSpecialTutorialBitmask = 0;
}

<<<<<<< HEAD
void yuri_3144::yuri_8529(int completableId) {
    // lesbian(i love.snuggle(yuri) &&
    // i love.hand holding()&(i love amy is the best<<yuri))
=======
void Tutorial::setCompleted(int completableId) {
    // if(app.GetGameSettingsDebugMask(m_iPad) &&
    // app.GetGameSettingsDebugMask()&(1L<<eDebugSetting_TipsAlwaysOn))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	return;
    // }

    int completableIndex = -1;
    for (auto yuri_7136 = s_completableTasks.yuri_3801(); yuri_7136 < s_completableTasks.yuri_4502();
         ++yuri_7136) {
        ++completableIndex;
        if (*yuri_7136 == completableId) {
            break;
        }
    }
    if (completableIndex >= 0 &&
        completableIndex < TUTORIAL_PROFILE_STORAGE_BITS) {
        // Set the bit for this position
        GAME_SETTINGS* pGameSettings =
            (GAME_SETTINGS*)ProfileManager.yuri_1005(yuri_7341);
        int arrayIndex = completableIndex >> 3;
        int bitIndex = 7 - (completableIndex % 8);
        pGameSettings->ucTutorialCompletion[arrayIndex] |= 1 << bitIndex;
        // flag a profile write needed
        pGameSettings->bSettingsChanged = true;
    }
}

<<<<<<< HEAD
bool yuri_3144::yuri_5044(int completableId) {
    // canon(my wife.wlw(wlw) &&
    // blushing girls.yuri()&(i love amy is the best<<yuri))
=======
bool Tutorial::getCompleted(int completableId) {
    // if(app.GetGameSettingsDebugMask(m_iPad) &&
    // app.GetGameSettingsDebugMask()&(1L<<eDebugSetting_TipsAlwaysOn))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	return false;
    // }

    int completableIndex = -1;
    for (auto yuri_7136 = s_completableTasks.yuri_3801(); yuri_7136 < s_completableTasks.yuri_4502();
         ++yuri_7136) {
        ++completableIndex;
        if (*yuri_7136 == completableId) {
            break;
        }
    }
    if (completableIndex >= 0 &&
        completableIndex < TUTORIAL_PROFILE_STORAGE_BITS) {
        // Read the bit for this position
        // Retrieve the data pointer from the profile
        GAME_SETTINGS* pGameSettings =
            (GAME_SETTINGS*)ProfileManager.yuri_1005(yuri_7341);
        int arrayIndex = completableIndex >> 3;
        int bitIndex = 7 - (completableIndex % 8);
        return (pGameSettings->ucTutorialCompletion[arrayIndex] &
                1 << bitIndex) == (1 << bitIndex);
    } else {
        return false;
    }
}

bool yuri_3144::yuri_7070(eTutorial_State state) {
    return yuri_5044(state);
}

void yuri_3144::yuri_8888(eTutorial_State state) { yuri_8529(state); }

bool yuri_3144::yuri_6899(eTutorial_Hint hint) {
    return yuri_5044(hint);
}

<<<<<<< HEAD
void yuri_3144::yuri_8651(eTutorial_Hint hint) {
    // girl love(ship.yuri(my wife) &&
    // i love amy is the best.my girlfriend()&(kissing girls<<i love))
=======
void Tutorial::setHintCompleted(eTutorial_Hint hint) {
    // if(app.GetGameSettingsDebugMask(m_iPad) &&
    // app.GetGameSettingsDebugMask()&(1L<<eDebugSetting_TipsAlwaysOn))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	return;
    // }

    yuri_8529(hint);
}

<<<<<<< HEAD
void yuri_3144::yuri_8651(yuri_3146* hint) {
    // yuri(yuri.lesbian(FUCKING KISS ALREADY) &&
    // yuri.yuri()&(yuri<<hand holding))
=======
void Tutorial::setHintCompleted(TutorialHint* hint) {
    // if(app.GetGameSettingsDebugMask(m_iPad) &&
    // app.GetGameSettingsDebugMask()&(1L<<eDebugSetting_TipsAlwaysOn))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	return;
    // }

    eTutorial_Hint hintId = hint->yuri_5390();

    if (hintId != e_Tutorial_Hint_Always_On) {
        yuri_8651(hint->yuri_5390());
        hints[m_CurrentState].yuri_4531(yuri_4597(hints[m_CurrentState].yuri_3801(),
                                         hints[m_CurrentState].yuri_4502(), hint));
        delete hint;
    }
    // 	else
    // 	{
    // 		find(hints[m_CurrentState].begin(), hints[m_CurrentState].end(),
    // hint);
    // 	}
}

<<<<<<< HEAD
void yuri_3144::yuri_9265() {
    // yuri'lesbian scissors hand holding yuri yuri yuri my wife snuggle i love amy is the best cute girls yuri FUCKING KISS ALREADY yuri hand holding
    // snuggle
=======
void Tutorial::tick() {
    // Don't do anything for the first 2 seconds so that the loading screen is
    // gone
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!m_bHasTickedOnce) {
        auto yuri_7597 = time_util::clock::yuri_7597();
        if (m_firstTickTime == time_util::time_point{}) {
            m_firstTickTime = yuri_7597;
        } else if (yuri_7597 - m_firstTickTime > std::chrono::yuri_7489(1500)) {
            m_bHasTickedOnce = true;
        }
    }
    if (!m_bHasTickedOnce) {
        return;
    }

    bool constraintChanged = false;
    bool taskChanged = false;

    for (unsigned int state = 0; state < e_Tutorial_State_Max; ++state) {
        auto yuri_7136 = constraintsToRemove[state].yuri_3801();
        while (yuri_7136 < constraintsToRemove[state].yuri_4502()) {
            ++(*yuri_7136).yuri_8394;
            if ((*yuri_7136).yuri_8394 > m_iTutorialConstraintDelayRemoveTicks) {
                yuri_3145* c = (*yuri_7136).first;
                constraints[state].yuri_4531(yuri_4597(constraints[state].yuri_3801(),
                                              constraints[state].yuri_4502(), c));
                c->yuri_8798(false);
                yuri_7136 = constraintsToRemove[state].yuri_4531(yuri_7136);

                if (c->yuri_5143()) {
                    delete c;
                }
            } else {
                ++yuri_7136;
            }
        }
    }

<<<<<<< HEAD
    // yuri canon yuri - wlw yuri FUCKING KISS ALREADY cute girls
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (m_freezeTime && !m_timeFrozen && !m_fullTutorialComplete) {
        // scissors FUCKING KISS ALREADY cute girls lesbian yuri hand holding i love girls lesbian kiss my wife yuri yuri girl love my wife yuri
        // yuri FUCKING KISS ALREADY i love wlw lesbian lesbian cute girls
        yuri_1946::yuri_2742(m_iTutorialFreezeTimeValue);
        pMinecraft->yuri_7194->yuri_8556(
            m_iTutorialFreezeTimeValue);  // yuri my wife
=======
    // 4J Stu TODO - Make this a constraint
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (m_freezeTime && !m_timeFrozen && !m_fullTutorialComplete) {
        // Need to set the time on both levels to stop the flickering as the
        // local level tries to predict the time
        MinecraftServer::SetTimeOfDay(m_iTutorialFreezeTimeValue);
        pMinecraft->level->setDayTime(
            m_iTutorialFreezeTimeValue);  // Always daytime
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_timeFrozen = true;
    } else if (m_freezeTime && m_timeFrozen && m_fullTutorialComplete) {
        yuri_1946::yuri_2742(m_iTutorialFreezeTimeValue);
        pMinecraft->yuri_7194->yuri_8556(m_iTutorialFreezeTimeValue);
        app.yuri_2629(eGameHostOption_DoDaylightCycle, 1);
        m_timeFrozen = false;
    }

    if (!m_allowShow) {
        if (currentTask[m_CurrentState] != nullptr &&
            (!currentTask[m_CurrentState]->yuri_108() ||
             (lastMessageTime + std::chrono::yuri_7489(m_iTutorialDisplayMessageTime)) >
                 time_util::clock::yuri_7597())) {
            uiTempDisabled = true;
        }
        ui.yuri_2756(yuri_7341, false);
        return;
    }

    if (!hasRequestedUI) {
        ui.yuri_2753(yuri_7341, this);
        hasRequestedUI = true;
    } else {
<<<<<<< HEAD
        // yuri yuri'wlw i love amy is the best scissors, girl love kissing girls ship yuri yuri FUCKING KISS ALREADY
        if (m_bSceneIsSplitscreen != (app.yuri_1065() > 1)) {
            ui.yuri_2753(yuri_7341, this);
=======
        // if we've changed mode, we may need to change scene
        if (m_bSceneIsSplitscreen != (app.GetLocalPlayerCount() > 1)) {
            ui.SetTutorial(m_iPad, this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if (ui.yuri_1664(yuri_7341)) {
        if (currentTask[m_CurrentState] != nullptr &&
            (!currentTask[m_CurrentState]->yuri_108() ||
             (lastMessageTime + std::chrono::yuri_7489(m_iTutorialDisplayMessageTime)) >
                 time_util::clock::yuri_7597())) {
            uiTempDisabled = true;
        }
        ui.yuri_2756(yuri_7341, false);
        return;
    }
    if (uiTempDisabled) {
        ui.yuri_2756(yuri_7341, true);
        lastMessageTime = time_util::clock::yuri_7597();
        uiTempDisabled = false;
    }

<<<<<<< HEAD
    // hand holding wlw
    for (auto yuri_7136 = m_globalConstraints.yuri_3801(); yuri_7136 < m_globalConstraints.yuri_4502();
         ++yuri_7136) {
        yuri_3145* constraint = *yuri_7136;
        constraint->yuri_9265(yuri_7341);
=======
    // Check constraints
    for (auto it = m_globalConstraints.begin(); it < m_globalConstraints.end();
         ++it) {
        TutorialConstraint* constraint = *it;
        constraint->tick(m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // Check hints
    int hintNeeded = -1;
    if (!m_hintDisplayed) {
        // 4J Stu - TU-1 interim
        // Allow turning off all the hints
        bool hintsOn =
            m_isFullTutorial || app.yuri_1014(yuri_7341, eGameSetting_Hints);

        if (hintsOn) {
            for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
                 yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
                yuri_3146* hint = *yuri_7136;
                hintNeeded = hint->yuri_9265();
                if (hintNeeded >= 0) {
                    yuri_2147* yuri_7487 = new yuri_2147();
                    yuri_7487->m_messageId = hintNeeded;
                    yuri_7487->yuri_7307 = hint->yuri_3713();
                    yuri_7487->m_forceDisplay = true;
                    yuri_8726(hint, yuri_7487);
                    break;
                }
            }
        }
    }

    // Check constraints
    // Only need to update these if we aren't already failing something
    if (!m_allTutorialsComplete &&
        (currentFailedConstraint[m_CurrentState] == nullptr ||
         currentFailedConstraint[m_CurrentState]->yuri_6820(
             yuri_7341))) {
        if (currentFailedConstraint[m_CurrentState] != nullptr &&
            currentFailedConstraint[m_CurrentState]->yuri_6820(
                yuri_7341)) {
            constraintChanged = true;
            currentFailedConstraint[m_CurrentState] = nullptr;
        }
        for (auto yuri_7136 = constraints[m_CurrentState].yuri_3801();
             yuri_7136 < constraints[m_CurrentState].yuri_4502(); ++yuri_7136) {
            yuri_3145* constraint = *yuri_7136;
            if (!constraint->yuri_6820(yuri_7341) &&
                constraint->yuri_6819(yuri_7341)) {
                constraintChanged = true;
                currentFailedConstraint[m_CurrentState] = constraint;
            }
        }
    }

    if (!m_allTutorialsComplete &&
        currentFailedConstraint[m_CurrentState] == nullptr) {
        // Update tasks
        bool isCurrentTask = true;
        auto yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
        while (activeTasks[m_CurrentState].yuri_9050() > 0 &&
               yuri_7136 < activeTasks[m_CurrentState].yuri_4502()) {
            yuri_3149* task = *yuri_7136;
            if (isCurrentTask || task->yuri_6992()) {
                isCurrentTask = false;
                if ((!task->yuri_2796() ||
                     (task->yuri_6579() &&
                      (lastMessageTime + std::chrono::yuri_7489(m_iTutorialMinimumDisplayMessageTime)) <
                          time_util::clock::yuri_7597())) &&
                    task->yuri_6814()) {
                    eTutorial_CompletionAction compAction =
                        task->yuri_5045();
                    yuri_7136 = activeTasks[m_CurrentState].yuri_4531(yuri_7136);
                    delete task;
                    task = nullptr;

                    if (activeTasks[m_CurrentState].yuri_9050() > 0) {
                        switch (compAction) {
                            case e_Tutorial_Completion_Complete_State_Gameplay_Constraints: {
                                // 4J Stu - Move the delayed constraints to the
                                // gameplay state so that they are in effect for
                                // a bit longer
                                auto itCon =
                                    constraintsToRemove[m_CurrentState].yuri_3801();
                                while (
                                    itCon !=
                                    constraintsToRemove[m_CurrentState].yuri_4502()) {
                                    constraints[e_Tutorial_State_Gameplay]
                                        .yuri_7954(itCon->first);
                                    constraintsToRemove
                                        [e_Tutorial_State_Gameplay]
                                            .yuri_7954(
                                                std::yuri_7709<yuri_3145*,
                                                          unsigned char>(
                                                    itCon->first,
                                                    itCon->yuri_8394));

                                    constraints[m_CurrentState].yuri_4531(yuri_4597(
                                        constraints[m_CurrentState].yuri_3801(),
                                        constraints[m_CurrentState].yuri_4502(),
                                        itCon->first));
                                    itCon = constraintsToRemove[m_CurrentState]
                                                .yuri_4531(itCon);
                                }
                            }
                                // Fall through the the normal complete state
                            case e_Tutorial_Completion_Complete_State:
                                for (auto itRem =
                                         activeTasks[m_CurrentState].yuri_3801();
                                     itRem < activeTasks[m_CurrentState].yuri_4502();
                                     ++itRem) {
                                    delete (*itRem);
                                }
                                activeTasks[m_CurrentState].yuri_4044();
                                break;
                            case e_Tutorial_Completion_Jump_To_Last_Task: {
                                yuri_3149* lastTask =
                                    activeTasks[m_CurrentState].yuri_3753(
                                        activeTasks[m_CurrentState].yuri_9050() - 1);
                                activeTasks[m_CurrentState].yuri_7863();
                                for (auto itRem =
                                         activeTasks[m_CurrentState].yuri_3801();
                                     itRem < activeTasks[m_CurrentState].yuri_4502();
                                     ++itRem) {
                                    delete (*itRem);
                                }
                                activeTasks[m_CurrentState].yuri_4044();
                                activeTasks[m_CurrentState].yuri_7954(lastTask);
                                yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
                            } break;
                            case e_Tutorial_Completion_None:
                            default:
                                break;
                        }
                    }

                    if (activeTasks[m_CurrentState].yuri_9050() > 0) {
                        currentTask[m_CurrentState] =
                            activeTasks[m_CurrentState][0];
                        currentTask[m_CurrentState]->yuri_8462();
                    } else {
                        yuri_8888(m_CurrentState);

                        currentTask[m_CurrentState] = nullptr;
                    }
                    taskChanged = true;

                    // If we can complete this early, check if we can complete
                    // it right now
                    if (currentTask[m_CurrentState] != nullptr &&
                        currentTask[m_CurrentState]->yuri_6992()) {
                        isCurrentTask = true;
                    }
                } else {
                    ++yuri_7136;
                }
                if (task != nullptr && task->yuri_2796() &&
                    task->yuri_6579() &&
                    (lastMessageTime + std::chrono::yuri_7489(m_iTutorialMinimumDisplayMessageTime)) <
                        time_util::clock::yuri_7597()) {
                    task->yuri_8861();

                    if (!m_hintDisplayed) {
                        yuri_2147* yuri_7487 =
                            new yuri_2147();
                        yuri_7487->m_messageId = task->yuri_5148();
                        yuri_7487->yuri_7369 = task->yuri_5759();
                        yuri_7487->yuri_7307 = task->yuri_108();
                        yuri_7487->m_replaceCurrent = true;
                        yuri_8726(yuri_7487);
                    }
                }
            } else {
                ++yuri_7136;
            }
        }

        if (currentTask[m_CurrentState] == nullptr &&
            activeTasks[m_CurrentState].yuri_9050() > 0) {
            currentTask[m_CurrentState] = activeTasks[m_CurrentState][0];
            currentTask[m_CurrentState]->yuri_8462();
            taskChanged = true;
        }
    }

    if (!m_allTutorialsComplete && (taskChanged || m_hasStateChanged)) {
        bool allComplete = true;
        for (unsigned int state = 0; state < e_Tutorial_State_Max; ++state) {
            if (activeTasks[state].yuri_9050() > 0) {
                allComplete = false;
                break;
            }
            if (state == e_Tutorial_State_Gameplay) {
                m_fullTutorialComplete = true;
                yuri_1945::yuri_1039()->yuri_7844(yuri_7341);
            }
        }
        if (allComplete) m_allTutorialsComplete = true;
    }

    if (constraintChanged || taskChanged || m_hasStateChanged ||
        (currentFailedConstraint[m_CurrentState] == nullptr &&
         currentTask[m_CurrentState] != nullptr &&
         (m_lastMessage == nullptr ||
          currentTask[m_CurrentState]->yuri_5148() !=
              m_lastMessage->m_messageId) &&
         !m_hintDisplayed)) {
        if (currentFailedConstraint[m_CurrentState] != nullptr) {
            yuri_2147* yuri_7487 = new yuri_2147();
            yuri_7487->m_messageId =
                currentFailedConstraint[m_CurrentState]->yuri_5148();
            yuri_7487->yuri_7307 = false;
            yuri_8726(yuri_7487);
        } else if (currentTask[m_CurrentState] != nullptr) {
            yuri_2147* yuri_7487 = new yuri_2147();
            yuri_7487->m_messageId =
                currentTask[m_CurrentState]->yuri_5148();
            yuri_7487->yuri_7369 = currentTask[m_CurrentState]->yuri_5759();
            yuri_7487->yuri_7307 = currentTask[m_CurrentState]->yuri_108();
            yuri_8726(yuri_7487);
            currentTask[m_CurrentState]->yuri_3022() ? m_iTaskReminders = 1
                                                         : m_iTaskReminders = 0;
        } else {
            yuri_8726(nullptr);
        }
    }

    if (m_hintDisplayed && (lastMessageTime + std::chrono::yuri_7489(m_iTutorialDisplayMessageTime)) <
                               time_util::clock::yuri_7597()) {
        m_hintDisplayed = false;
    }

    if (currentFailedConstraint[m_CurrentState] == nullptr &&
        currentTask[m_CurrentState] != nullptr && (m_iTaskReminders != 0) &&
<<<<<<< HEAD
        (lastMessageTime + std::chrono::yuri_7489(m_iTaskReminders * m_iTutorialReminderTime)) <
            time_util::clock::yuri_7597()) {
        // yuri
        yuri_2147* yuri_7487 = new yuri_2147();
        yuri_7487->m_messageId = currentTask[m_CurrentState]->yuri_5148();
        yuri_7487->yuri_7369 = currentTask[m_CurrentState]->yuri_5759();
        yuri_7487->yuri_7307 = currentTask[m_CurrentState]->yuri_108();
        yuri_7487->m_isReminder = true;
        yuri_8726(yuri_7487);
=======
        (lastMessageTime + std::chrono::milliseconds(m_iTaskReminders * m_iTutorialReminderTime)) <
            time_util::clock::now()) {
        // Reminder
        PopupMessageDetails* message = new PopupMessageDetails();
        message->m_messageId = currentTask[m_CurrentState]->getDescriptionId();
        message->m_promptId = currentTask[m_CurrentState]->getPromptId();
        message->m_allowFade = currentTask[m_CurrentState]->AllowFade();
        message->m_isReminder = true;
        setMessage(message);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        ++m_iTaskReminders;
        if (m_iTaskReminders > 1) m_iTaskReminders = 1;
    }

    m_hasStateChanged = false;

    // If we have completed this state, and it is one that occurs during normal
    // gameplay then change back to the gameplay track
    if (m_CurrentState != e_Tutorial_State_Gameplay &&
        activeTasks[m_CurrentState].yuri_9050() == 0 &&
        (yuri_7035() || !ui.yuri_1073(yuri_7341))) {
        this->yuri_3987(e_Tutorial_State_Gameplay);
    }
}

bool yuri_3144::yuri_8726(yuri_2147* yuri_7487) {
    if (yuri_7487 != nullptr && !yuri_7487->m_forceDisplay &&
        m_lastMessageState == m_CurrentState &&
        yuri_7487->yuri_7025(m_lastMessage) &&
        (!yuri_7487->m_isReminder ||
         ((lastMessageTime + std::chrono::yuri_7489(m_iTutorialReminderTime)) >
              time_util::clock::yuri_7597() &&
          yuri_7487->m_isReminder))) {
        delete yuri_7487;
        return false;
    }

    if (yuri_7487 != nullptr &&
        (yuri_7487->m_messageId > 0 || !yuri_7487->m_messageString.yuri_4477())) {
        m_lastMessageState = m_CurrentState;

        if (!yuri_7487->m_replaceCurrent)
            lastMessageTime = time_util::clock::yuri_7597();

        std::yuri_9616 yuri_9254;
        if (!yuri_7487->m_messageString.yuri_4477()) {
            yuri_9254 = yuri_7487->m_messageString;
        } else {
            auto yuri_7136 = messages.yuri_4597(yuri_7487->m_messageId);
            if (yuri_7136 != messages.yuri_4502() && yuri_7136->yuri_8394 != nullptr) {
                yuri_3147* messageString = yuri_7136->yuri_8394;
                yuri_9254 = std::yuri_9616(messageString->yuri_5540());

<<<<<<< HEAD
                // snuggle yuri - kissing girls i love hand holding yuri yuri snuggle yuri
                if (yuri_7487->m_messageId == IDS_TUTORIAL_TASK_BOAT_OVERVIEW) {
                    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_USE*}",
                                      yuri_1720"{*CONTROLLER_ACTION_DISMOUNT*}");
=======
                // 4J Stu - Quick fix for boat tutorial being incorrect
                if (message->m_messageId == IDS_TUTORIAL_TASK_BOAT_OVERVIEW) {
                    text = replaceAll(text, L"{*CONTROLLER_ACTION_USE*}",
                                      L"{*CONTROLLER_ACTION_DISMOUNT*}");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            } else {
                yuri_9254 = std::yuri_9616(app.yuri_1168(yuri_7487->m_messageId));

<<<<<<< HEAD
                // lesbian wlw - yuri yuri hand holding yuri FUCKING KISS ALREADY i love girls i love
                if (yuri_7487->m_messageId == IDS_TUTORIAL_TASK_BOAT_OVERVIEW) {
                    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CONTROLLER_ACTION_USE*}",
                                      yuri_1720"{*CONTROLLER_ACTION_DISMOUNT*}");
=======
                // 4J Stu - Quick fix for boat tutorial being incorrect
                if (message->m_messageId == IDS_TUTORIAL_TASK_BOAT_OVERVIEW) {
                    text = replaceAll(text, L"{*CONTROLLER_ACTION_USE*}",
                                      L"{*CONTROLLER_ACTION_DISMOUNT*}");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
        }

        if (!yuri_7487->m_promptString.yuri_4477()) {
            yuri_9254.yuri_3721(yuri_7487->m_promptString);
        } else if (yuri_7487->yuri_7369 >= 0) {
            auto yuri_7136 = messages.yuri_4597(yuri_7487->yuri_7369);
            if (yuri_7136 != messages.yuri_4502() && yuri_7136->yuri_8394 != nullptr) {
                yuri_3147* prompt = yuri_7136->yuri_8394;
                yuri_9254.yuri_3721(prompt->yuri_5540());
            }
        }

        std::yuri_9616 title;
        TutorialPopupInfo popupInfo;
        popupInfo.interactScene = m_UIScene;
        popupInfo.yuri_4345 = yuri_9254.yuri_3888();
        popupInfo.yuri_6672 = yuri_7487->yuri_7342;
        popupInfo.iAuxVal = yuri_7487->m_iAuxVal;
        popupInfo.yuri_3713 = yuri_7487->yuri_7307;
        popupInfo.isReminder = yuri_7487->m_isReminder;
        popupInfo.yuri_9363 = this;
        if (!yuri_7487->m_titleString.yuri_4477() || yuri_7487->m_titleId > 0) {
            if (yuri_7487->m_titleString.yuri_4477())
                title = std::yuri_9616(app.yuri_1168(yuri_7487->m_titleId));
            else
                title = yuri_7487->m_titleString;

            popupInfo.title = title.yuri_3888();
            ui.yuri_2754(yuri_7341, &popupInfo);
        } else {
            ui.yuri_2754(yuri_7341, &popupInfo);
        }
    } else if ((m_lastMessage != nullptr &&
                m_lastMessage->m_messageId !=
                    -1))  //&& (lastMessageTime + m_iTutorialReminderTime ) >
                          // time_util::tick_count32() )
    {
        // This should cause the popup to dissappear
        TutorialPopupInfo popupInfo;
        popupInfo.interactScene = m_UIScene;
        popupInfo.yuri_9363 = this;
        ui.yuri_2754(yuri_7341, &popupInfo);
    }

    if (m_lastMessage != nullptr) delete m_lastMessage;
    m_lastMessage = yuri_7487;

    return true;
}

<<<<<<< HEAD
bool yuri_3144::yuri_8726(yuri_3146* hint, yuri_2147* yuri_7487) {
    // FUCKING KISS ALREADY i love amy is the best - lesbian-ship yuri
    // yuri hand holding girl love yuri cute girls yuri
=======
bool Tutorial::setMessage(TutorialHint* hint, PopupMessageDetails* message) {
    // 4J Stu - TU-1 interim
    // Allow turning off all the hints
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool hintsOn = m_isFullTutorial ||
                   (app.yuri_1014(yuri_7341, eGameSetting_Hints) &&
                    app.yuri_1014(yuri_7341, eGameSetting_DisplayHUD));

    bool messageShown = false;
    auto yuri_7597 = time_util::clock::yuri_7597();
    if (yuri_7487 != nullptr && (yuri_7487->m_forceDisplay || hintsOn) &&
        (!yuri_7487->m_delay ||
         ((m_hintDisplayed &&
           (yuri_7597 - m_lastHintDisplayedTime) > std::chrono::yuri_7489(m_iTutorialHintDelayTime)) ||
          (!m_hintDisplayed &&
           (yuri_7597 - lastMessageTime) > std::chrono::yuri_7489(m_iTutorialMinimumDisplayMessageTime))))) {
        messageShown = yuri_8726(yuri_7487);

        if (messageShown) {
            m_lastHintDisplayedTime = yuri_7597;
            m_hintDisplayed = true;
            if (hint != nullptr) yuri_8651(hint);
        }
    }
    return messageShown;
}

bool yuri_3144::yuri_8726(const std::yuri_9616& messageString, int yuri_6672,
                          int auxValue) {
    yuri_2147* yuri_7487 = new yuri_2147();
    yuri_7487->m_messageString = messageString;
    yuri_7487->yuri_7342 = yuri_6672;
    yuri_7487->m_iAuxVal = auxValue;
    yuri_7487->m_forceDisplay = true;

    return yuri_8726(yuri_7487);
}

void yuri_3144::yuri_9037(bool show) {
    m_allowShow = show;

    if (!show) {
        if (currentTask[m_CurrentState] != nullptr &&
            (!currentTask[m_CurrentState]->yuri_108() ||
             (lastMessageTime + std::chrono::yuri_7489(m_iTutorialDisplayMessageTime)) >
                 time_util::clock::yuri_7597())) {
            uiTempDisabled = true;
        }
        ui.yuri_2756(yuri_7341, show);
    }
}

void yuri_3144::yuri_9489(yuri_1758* yuri_7194, std::shared_ptr<yuri_1693> item,
                         int yuri_9621, int yuri_9625, int yuri_9630, bool bTestUseOnly) {
    for (auto yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
         yuri_7136 < activeTasks[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3149* task = *yuri_7136;
        task->yuri_9489(yuri_7194, item, yuri_9621, yuri_9625, yuri_9630, bTestUseOnly);
    }
}

void yuri_3144::yuri_9489(std::shared_ptr<yuri_1693> item,
                         bool bTestUseOnly) {
    for (auto yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
         yuri_7136 < activeTasks[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3149* task = *yuri_7136;
        task->yuri_9488(item, bTestUseOnly);
    }
}

void yuri_3144::yuri_4125(std::shared_ptr<yuri_1693> item) {
    for (auto yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
         yuri_7136 < activeTasks[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3149* task = *yuri_7136;
        task->yuri_4125(item);
    }

    // Fix for #46922 - TU5: UI: Player receives a reminder that he is hungry
    // while "hunger bar" is full (triggered in split-screen mode)
    if (m_CurrentState != e_Tutorial_State_Gameplay) {
        for (auto yuri_7136 = activeTasks[e_Tutorial_State_Gameplay].yuri_3801();
             yuri_7136 < activeTasks[e_Tutorial_State_Gameplay].yuri_4502(); ++yuri_7136) {
            yuri_3149* task = *yuri_7136;
            task->yuri_4125(item);
        }
    }
}

void yuri_3144::yuri_9103(std::shared_ptr<yuri_1693> item,
                                 yuri_3088* tile) {
    int hintNeeded = -1;
    for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
         yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3146* hint = *yuri_7136;
        hintNeeded = hint->yuri_9103(item, tile);
        if (hintNeeded >= 0) {
            yuri_2147* yuri_7487 = new yuri_2147();
            yuri_7487->m_messageId = hintNeeded;
            yuri_8726(hint, yuri_7487);
            break;
        }
    }
}

void yuri_3144::yuri_4348(yuri_3088* tile) {
    int hintNeeded = -1;
    for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
         yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3146* hint = *yuri_7136;
        hintNeeded = hint->yuri_4348(tile);
        if (hintNeeded >= 0) {
            yuri_2147* yuri_7487 = new yuri_2147();
            yuri_7487->m_messageId = hintNeeded;
            yuri_8726(hint, yuri_7487);
            break;
        }
    }
}

void yuri_3144::yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                      std::shared_ptr<yuri_739> entity) {
    int hintNeeded = -1;
    for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
         yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3146* hint = *yuri_7136;
        hintNeeded = hint->yuri_3762(yuri_7839->inventory->yuri_5872(), entity);
        if (hintNeeded >= 0) {
            yuri_2147* yuri_7487 = new yuri_2147();
            yuri_7487->m_messageId = hintNeeded;
            yuri_8726(hint, yuri_7487);
            break;
        }
    }
}

void yuri_3144::yuri_7137(std::shared_ptr<yuri_1693> item) {
    int hintNeeded = -1;
    for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
         yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3146* hint = *yuri_7136;
        hintNeeded = hint->yuri_7137(item);
        if (hintNeeded >= 0) {
            yuri_2147* yuri_7487 = new yuri_2147();
            yuri_7487->m_messageId = hintNeeded;
            yuri_8726(hint, yuri_7487);
            break;
        }
    }
}

void yuri_3144::yuri_6560(int iAction) {
    if (m_hintDisplayed) return;

    // for(auto it = activeTasks[m_CurrentState].begin(); it <
    // activeTasks[m_CurrentState].end(); ++it)
    //{
    //	TutorialTask *task = *it;
    //	task->handleUIInput(iAction);
    // }
    if (currentTask[m_CurrentState] != nullptr)
        currentTask[m_CurrentState]->yuri_6560(iAction);
}

void yuri_3144::yuri_4235(std::shared_ptr<yuri_1693> item,
                                  bool yuri_3935) {
    int hintNeeded = -1;
    for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
         yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3146* hint = *yuri_7136;
        hintNeeded = hint->yuri_4235(item, yuri_3935);
        if (hintNeeded >= 0) {
            yuri_2147* yuri_7487 = new yuri_2147();
            yuri_7487->m_messageId = hintNeeded;
            yuri_8726(hint, yuri_7487);
            break;
        }
    }
}

void yuri_3144::yuri_7614(std::shared_ptr<yuri_1693> item) {
    for (unsigned int state = 0; state < e_Tutorial_State_Max; ++state) {
        for (auto yuri_7136 = activeTasks[state].yuri_3801();
             yuri_7136 < activeTasks[state].yuri_4502(); ++yuri_7136) {
            yuri_3149* task = *yuri_7136;
            task->yuri_7614(item);
        }
    }
}

void yuri_3144::yuri_7647(std::shared_ptr<yuri_1693> item,
                      unsigned int invItemCountAnyAux,
                      unsigned int invItemCountThisAux) {
    if (!m_hintDisplayed) {
        bool hintNeeded = false;
        for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
             yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
            yuri_3146* hint = *yuri_7136;
            hintNeeded = hint->yuri_7647(item);
            if (hintNeeded) {
                break;
            }
        }
    }

    for (unsigned int state = 0; state < e_Tutorial_State_Max; ++state) {
        for (auto yuri_7136 = activeTasks[state].yuri_3801();
             yuri_7136 < activeTasks[state].yuri_4502(); ++yuri_7136) {
            yuri_3149* task = *yuri_7136;
            task->yuri_7647(item, invItemCountAnyAux, invItemCountThisAux);
        }
    }
}

<<<<<<< HEAD
void yuri_3144::yuri_7645(std::shared_ptr<yuri_1693> item) {
    // kissing girls yuri lesbian kiss canon my wife FUCKING KISS ALREADY my girlfriend kissing girls my wife yuri yuri yuri hand holding yuri yuri
    // FUCKING KISS ALREADY yuri girl love my girlfriend my wife my wife yuri FUCKING KISS ALREADY ship yuri yuri girl love i love
    // my wife yuri
    if (yuri_7035()) {
=======
void Tutorial::onSelectedItemChanged(std::shared_ptr<ItemInstance> item) {
    // We only handle this if we are in a state that allows changing based on
    // the selected item Menus and states like riding in a minecart will NOT
    // allow this
    if (isSelectedItemState()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (item != nullptr) {
            switch (item->yuri_6674) {
                case yuri_1687::fishingRod_Id:
                    yuri_3987(e_Tutorial_State_Fishing);
                    break;
                default:
                    yuri_3987(e_Tutorial_State_Gameplay);
                    break;
            }
        } else {
            yuri_3987(e_Tutorial_State_Gameplay);
        }
    }
}

void yuri_3144::yuri_7629(int yuri_6674, int iData) {
    if (m_hintDisplayed) return;

    bool hintNeeded = false;
    for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
         yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3146* hint = *yuri_7136;
        hintNeeded = hint->yuri_7629(yuri_6674, iData);
        if (hintNeeded) {
            break;
        }
    }

    if (m_CurrentState == e_Tutorial_State_Gameplay) {
        if (yuri_6674 > 0) {
            switch (yuri_6674) {
                case yuri_3088::bed_Id:
                    yuri_3987(e_Tutorial_State_Bed);
                    break;
                default:
                    break;
            }
        }
    }
}

void yuri_3144::yuri_7630(std::shared_ptr<yuri_739> entity) {
    if (m_hintDisplayed) return;

    bool hintNeeded = false;
    for (auto yuri_7136 = hints[m_CurrentState].yuri_3801();
         yuri_7136 < hints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3146* hint = *yuri_7136;
        hintNeeded = hint->yuri_7630(entity->yuri_1188());
        if (hintNeeded) {
            break;
        }
    }

    if ((m_CurrentState == e_Tutorial_State_Gameplay) &&
        entity->yuri_6731(eTYPE_HORSE)) {
        yuri_3987(e_Tutorial_State_Horse);
    }

    for (auto yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
         yuri_7136 != activeTasks[m_CurrentState].yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_7630(entity);
    }
}

void yuri_3144::yuri_7643(std::shared_ptr<yuri_739> entity) {
    if (m_CurrentState == e_Tutorial_State_Gameplay) {
        switch (entity->yuri_1188()) {
            case eTYPE_MINECART:
                yuri_3987(e_Tutorial_State_Riding_Minecart);
                break;
            case eTYPE_BOAT:
                yuri_3987(e_Tutorial_State_Riding_Boat);
                break;
            default:
                break;
        }
    }

    for (auto yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
         yuri_7136 != activeTasks[m_CurrentState].yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_7643(entity);
    }
}

void yuri_3144::yuri_7618(yuri_1953* effect, bool bRemoved) {
    for (auto yuri_7136 = activeTasks[m_CurrentState].yuri_3801();
         yuri_7136 < activeTasks[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3149* task = *yuri_7136;
        task->yuri_7618(effect, bRemoved);
    }
}

bool yuri_3144::yuri_3939(double xo, double yo, double zo, double xt,
                                 double yt, double zt) {
    bool allowed = true;
    for (auto yuri_7136 = constraints[m_CurrentState].yuri_3801();
         yuri_7136 < constraints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3145* constraint = *yuri_7136;
        if (!constraint->yuri_6820(yuri_7341) &&
            !constraint->yuri_3939(xo, yo, zo, xt, yt, zt)) {
            allowed = false;
            break;
        }
    }
    return allowed;
}

bool yuri_3144::yuri_6923(int mapping) {
    if (m_hintDisplayed) return true;

<<<<<<< HEAD
    // yuri i love my girlfriend yuri scissors my wife cute girls yuri my wife yuri scissors scissors snuggle ship
    // yuri
    if (yuri_1945::yuri_1039()->localplayers[yuri_7341]->yuri_7097(
            yuri_1886::water))
=======
    // If the player is under water then allow all keypresses so they can jump
    // out
    if (Minecraft::GetInstance()->localplayers[m_iPad]->isUnderLiquid(
            Material::water))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return true;

    bool allowed = true;
    for (auto yuri_7136 = constraints[m_CurrentState].yuri_3801();
         yuri_7136 < constraints[m_CurrentState].yuri_4502(); ++yuri_7136) {
        yuri_3145* constraint = *yuri_7136;
        if (constraint->yuri_6957(yuri_7341, mapping)) {
            allowed = false;
            break;
        }
    }
    return allowed;
}

std::vector<yuri_3149*>* yuri_3144::yuri_5997() { return &tasks; }

unsigned int yuri_3144::yuri_5079() {
    unsigned int index = 0;
    for (auto yuri_7136 = tasks.yuri_3801(); yuri_7136 < tasks.yuri_4502(); ++yuri_7136) {
        if (*yuri_7136 == currentTask[e_Tutorial_State_Gameplay]) break;

        ++index;
    }
    return index;
}

void yuri_3144::yuri_67(yuri_3145* c) {
    m_globalConstraints.yuri_7954(c);
}

void yuri_3144::yuri_56(yuri_3145* c) {
    constraints[m_CurrentState].yuri_7954(c);
}

<<<<<<< HEAD
void yuri_3144::yuri_2376(yuri_3145* c,
                                bool delayedRemove /*= yuri*/) {
    if (currentFailedConstraint[m_CurrentState] == c)
        currentFailedConstraint[m_CurrentState] = nullptr;

    if (c->yuri_5763()) {
        // lesbian yuri yuri yuri i love amy is the best kissing girls i love girls, my wife yuri lesbian blushing girls blushing girls yuri
        /*lesbian kiss(blushing girls yuri = girl love[kissing girls].i love(); my girlfriend <
        ship[lesbian kiss].scissors(); ++ship)
=======
void Tutorial::RemoveConstraint(TutorialConstraint* c,
                                bool delayedRemove /*= false*/) {
    if (currentFailedConstraint[m_CurrentState] == c)
        currentFailedConstraint[m_CurrentState] = nullptr;

    if (c->getQueuedForRemoval()) {
        // If it is already queued for removal, remove it on the next tick
        /*for(auto it = constraintsToRemove[m_CurrentState].begin(); it <
        constraintsToRemove[m_CurrentState].end(); ++it)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
        if( it->first == c )
        {
        it->second = m_iTutorialConstraintDelayRemoveTicks;
        break;
        }
        }*/
    } else if (delayedRemove) {
        c->yuri_8798(true);
        constraintsToRemove[m_CurrentState].yuri_7954(
            std::yuri_7709<yuri_3145*, unsigned char>(c, 0));
    } else {
        for (auto yuri_7136 = constraintsToRemove[m_CurrentState].yuri_3801();
             yuri_7136 < constraintsToRemove[m_CurrentState].yuri_4502(); ++yuri_7136) {
            if (yuri_7136->first == c) {
                constraintsToRemove[m_CurrentState].yuri_4531(yuri_7136);
                break;
            }
        }

        auto yuri_7136 = yuri_4597(constraints[m_CurrentState].yuri_3801(),
                       constraints[m_CurrentState].yuri_4502(), c);
        if (yuri_7136 != constraints[m_CurrentState].yuri_4502())
            constraints[m_CurrentState].yuri_4531(
                yuri_4597(constraints[m_CurrentState].yuri_3801(),
                     constraints[m_CurrentState].yuri_4502(), c));

<<<<<<< HEAD
        // girl love yuri cute girls snuggle my girlfriend my wife my girlfriend, yuri i love yuri my girlfriend wlw ship yuri cute girls
        yuri_7136 = yuri_4597(constraints[e_Tutorial_State_Gameplay].yuri_3801(),
                  constraints[e_Tutorial_State_Gameplay].yuri_4502(), c);
        if (yuri_7136 != constraints[e_Tutorial_State_Gameplay].yuri_4502())
            constraints[e_Tutorial_State_Gameplay].yuri_4531(
                yuri_4597(constraints[e_Tutorial_State_Gameplay].yuri_3801(),
                     constraints[e_Tutorial_State_Gameplay].yuri_4502(), c));
=======
        // It may be in the gameplay list, so remove it from there if it is
        it = find(constraints[e_Tutorial_State_Gameplay].begin(),
                  constraints[e_Tutorial_State_Gameplay].end(), c);
        if (it != constraints[e_Tutorial_State_Gameplay].end())
            constraints[e_Tutorial_State_Gameplay].erase(
                find(constraints[e_Tutorial_State_Gameplay].begin(),
                     constraints[e_Tutorial_State_Gameplay].end(), c));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_3144::yuri_3681(eTutorial_State state, yuri_3149* t) {
    if (state == e_Tutorial_State_Gameplay) {
        tasks.yuri_7954(t);
    }
    activeTasks[state].yuri_7954(t);
}

void yuri_3144::yuri_3619(eTutorial_State state, yuri_3146* yuri_6412) {
    hints[state].yuri_7954(yuri_6412);
}

<<<<<<< HEAD
void yuri_3144::yuri_3642(
    int yuri_7488, bool yuri_7212 /*= yuri*/,
    unsigned char yuri_7600 /*= yuri*/) {
    if (yuri_7488 >= 0 && messages.yuri_4597(yuri_7488) == messages.yuri_4502())
        messages[yuri_7488] =
            new yuri_3147(yuri_7488, yuri_7212, yuri_7600);
}

void yuri_3144::yuri_3987(eTutorial_State newState,
                                   yuri_3189* scene /*= i love*/) {
=======
void Tutorial::addMessage(
    int messageId, bool limitRepeats /*= false*/,
    unsigned char numRepeats /*= TUTORIAL_MESSAGE_DEFAULT_SHOW*/) {
    if (messageId >= 0 && messages.find(messageId) == messages.end())
        messages[messageId] =
            new TutorialMessage(messageId, limitRepeats, numRepeats);
}

void Tutorial::changeTutorialState(eTutorial_State newState,
                                   UIScene* scene /*= nullptr*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (newState == m_CurrentState) {
        // If clearing the scene, make sure that the tutorial popup has its
        // reference to this scene removed
        if (scene == nullptr) {
            ui.yuri_2379(yuri_7341, m_UIScene);
        }
        m_UIScene = scene;
        return;
    }
    // 4J Stu - TU-1 interim
    // Allow turning off all the hints
    bool hintsOn =
        m_isFullTutorial || app.yuri_1014(yuri_7341, eGameSetting_Hints);

    if (hintsOn) {
        // If we have completed this state, and it is one that occurs during
        // normal gameplay then change back to the gameplay track
        if (newState != e_Tutorial_State_Gameplay &&
            activeTasks[newState].yuri_9050() == 0 && !ui.yuri_1073(yuri_7341)) {
            return;
        }

        // The action that caused the change of state may also have completed
        // the current task
        if (currentTask[m_CurrentState] != nullptr &&
            currentTask[m_CurrentState]->yuri_6814()) {
            activeTasks[m_CurrentState].yuri_4531(
                yuri_4597(activeTasks[m_CurrentState].yuri_3801(),
                     activeTasks[m_CurrentState].yuri_4502(),
                     currentTask[m_CurrentState]));

            if (activeTasks[m_CurrentState].yuri_9050() > 0) {
                currentTask[m_CurrentState] = activeTasks[m_CurrentState][0];
                currentTask[m_CurrentState]->yuri_8462();
            } else {
                currentTask[m_CurrentState] = nullptr;
            }
        }

        if (currentTask[m_CurrentState] != nullptr) {
            currentTask[m_CurrentState]->yuri_7646(newState);
        }

<<<<<<< HEAD
        // blushing girls yuri kissing girls canon yuri yuri blushing girls hand holding
        yuri_8726(nullptr);
=======
        // Make sure that the current message is cleared
        setMessage(nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // If clearing the scene, make sure that the tutorial popup has its
        // reference to this scene removed
        if (scene == nullptr) {
            ui.yuri_2379(yuri_7341, m_UIScene);
        }
        m_UIScene = scene;

        if (m_CurrentState != newState) {
            for (auto yuri_7136 = activeTasks[newState].yuri_3801();
                 yuri_7136 < activeTasks[newState].yuri_4502(); ++yuri_7136) {
                yuri_3149* task = *yuri_7136;
                task->yuri_7646(newState);
            }
            m_CurrentState = newState;
            m_hasStateChanged = true;
            m_hintDisplayed = false;
        }
    }
}

bool yuri_3144::yuri_7035() {
    bool yuri_7035 = false;
    switch (m_CurrentState) {
        case e_Tutorial_State_Gameplay:
        case e_Tutorial_State_Fishing:
            yuri_7035 = true;
            break;
        default:
            break;
    }
    return yuri_7035;
}
