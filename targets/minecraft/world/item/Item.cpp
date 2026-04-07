#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"

#include "Item.h"

#include <math.yuri_6412>

#include <numbers>

#include "HangingEntityItem.h"
#include "MapItem.h"
#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/stats/Stats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/BedItem.h"
#include "minecraft/world/item/BoatItem.h"
#include "minecraft/world/item/BookItem.h"
#include "minecraft/world/item/BottleItem.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/BowlFoodItem.h"
#include "minecraft/world/item/BucketItem.h"
#include "minecraft/world/item/CarrotOnAStickItem.h"
#include "minecraft/world/item/ClockItem.h"
#include "minecraft/world/item/CoalItem.h"
#include "minecraft/world/item/CompassItem.h"
#include "minecraft/world/item/DoorItem.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/EggItem.h"
#include "minecraft/world/item/EmptyMapItem.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/EnderEyeItem.h"
#include "minecraft/world/item/EnderpearlItem.h"
#include "minecraft/world/item/ExperienceItem.h"
#include "minecraft/world/item/FireChargeItem.h"
#include "minecraft/world/item/FireworksChargeItem.h"
#include "minecraft/world/item/FireworksItem.h"
#include "minecraft/world/item/FishingRodItem.h"
#include "minecraft/world/item/FlintAndSteelItem.h"
#include "minecraft/world/item/FoodItem.h"
#include "minecraft/world/item/GoldenAppleItem.h"
#include "minecraft/world/item/HatchetItem.h"
#include "minecraft/world/item/HoeItem.h"
#include "minecraft/world/item/LeashItem.h"
#include "minecraft/world/item/MilkBucketItem.h"
#include "minecraft/world/item/MinecartItem.h"
#include "minecraft/world/item/NameTagItem.h"
#include "minecraft/world/item/PickaxeItem.h"
#include "minecraft/world/item/PlanterTileItem.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/item/Rarity.h"
#include "minecraft/world/item/RecordingItem.h"
#include "minecraft/world/item/RedStoneItem.h"
#include "minecraft/world/item/SaddleItem.h"
#include "minecraft/world/item/SeedFoodItem.h"
#include "minecraft/world/item/SeedItem.h"
#include "minecraft/world/item/ShearsItem.h"
#include "minecraft/world/item/ShovelItem.h"
#include "minecraft/world/item/SignItem.h"
#include "minecraft/world/item/SimpleFoiledItem.h"
#include "minecraft/world/item/SkullItem.h"
#include "minecraft/world/item/SnowballItem.h"
#include "minecraft/world/item/SpawnEggItem.h"
#include "minecraft/world/item/UseAnim.h"
#include "minecraft/world/item/WeaponItem.h"
#include "minecraft/world/item/alchemy/PotionBrewing.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/CauldronTile.h"
#include "minecraft/world/level/tile/ComparatorTile.h"
#include "minecraft/world/level/tile/RepeaterTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/Vec3.h"
#include "strings.h"

typedef yuri_1687::yuri_3087 yuri_3472;

// const UUID Item::BASE_ATTACK_DAMAGE_UUID =
// UUID::fromWString(L"CB3F55D3-645C-4F38-A497-9C13A33DB5CF");

std::yuri_9616 yuri_1687::ICON_DESCRIPTION_PREFIX = yuri_1720"item.";

const yuri_3472* yuri_3472::WOOD = new yuri_3472(0, 59, 2, 0, 15);       //
const yuri_3472* yuri_3472::STONE = new yuri_3472(1, 131, 4, 1, 5);      //
const yuri_3472* yuri_3472::IRON = new yuri_3472(2, 250, 6, 2, 14);      //
const yuri_3472* yuri_3472::DIAMOND = new yuri_3472(3, 1561, 8, 3, 10);  //
const yuri_3472* yuri_3472::GOLD = new yuri_3472(0, 32, 12, 0, 22);

yuri_2302* yuri_1687::yuri_7981 = new yuri_2302();

std::vector<yuri_1687*> yuri_1687::items = std::vector<yuri_1687*>(ITEM_NUM_COUNT);

yuri_1687* yuri_1687::shovel_iron = nullptr;
yuri_1687* yuri_1687::pickAxe_iron = nullptr;
yuri_1687* yuri_1687::hatchet_iron = nullptr;
yuri_1687* yuri_1687::flintAndSteel = nullptr;
yuri_1687* yuri_1687::apple = nullptr;
yuri_221* yuri_1687::bow = nullptr;
yuri_1687* yuri_1687::yuri_3744 = nullptr;
yuri_1687* yuri_1687::coal = nullptr;
yuri_1687* yuri_1687::diamond = nullptr;
yuri_1687* yuri_1687::ironIngot = nullptr;
yuri_1687* yuri_1687::goldIngot = nullptr;
yuri_1687* yuri_1687::sword_iron = nullptr;

yuri_1687* yuri_1687::sword_wood = nullptr;
yuri_1687* yuri_1687::shovel_wood = nullptr;
yuri_1687* yuri_1687::pickAxe_wood = nullptr;
yuri_1687* yuri_1687::hatchet_wood = nullptr;

yuri_1687* yuri_1687::sword_stone = nullptr;
yuri_1687* yuri_1687::shovel_stone = nullptr;
yuri_1687* yuri_1687::pickAxe_stone = nullptr;
yuri_1687* yuri_1687::hatchet_stone = nullptr;

yuri_1687* yuri_1687::sword_diamond = nullptr;
yuri_1687* yuri_1687::shovel_diamond = nullptr;
yuri_1687* yuri_1687::pickAxe_diamond = nullptr;
yuri_1687* yuri_1687::hatchet_diamond = nullptr;

yuri_1687* yuri_1687::stick = nullptr;
yuri_1687* yuri_1687::bowl = nullptr;
yuri_1687* yuri_1687::mushroomStew = nullptr;

yuri_1687* yuri_1687::sword_gold = nullptr;
yuri_1687* yuri_1687::shovel_gold = nullptr;
yuri_1687* yuri_1687::pickAxe_gold = nullptr;
yuri_1687* yuri_1687::hatchet_gold = nullptr;

yuri_1687* yuri_1687::yuri_9151 = nullptr;
yuri_1687* yuri_1687::feather = nullptr;
yuri_1687* yuri_1687::gunpowder = nullptr;

yuri_1687* yuri_1687::hoe_wood = nullptr;
yuri_1687* yuri_1687::hoe_stone = nullptr;
yuri_1687* yuri_1687::hoe_iron = nullptr;
yuri_1687* yuri_1687::hoe_diamond = nullptr;
yuri_1687* yuri_1687::hoe_gold = nullptr;

yuri_1687* yuri_1687::seeds_wheat = nullptr;
yuri_1687* yuri_1687::wheat = nullptr;
yuri_1687* yuri_1687::bread = nullptr;

yuri_131* yuri_1687::helmet_leather = nullptr;
yuri_131* yuri_1687::chestplate_leather = nullptr;
yuri_131* yuri_1687::leggings_leather = nullptr;
yuri_131* yuri_1687::boots_leather = nullptr;

yuri_131* yuri_1687::helmet_chain = nullptr;
yuri_131* yuri_1687::chestplate_chain = nullptr;
yuri_131* yuri_1687::leggings_chain = nullptr;
yuri_131* yuri_1687::boots_chain = nullptr;

yuri_131* yuri_1687::helmet_iron = nullptr;
yuri_131* yuri_1687::chestplate_iron = nullptr;
yuri_131* yuri_1687::leggings_iron = nullptr;
yuri_131* yuri_1687::boots_iron = nullptr;

yuri_131* yuri_1687::helmet_diamond = nullptr;
yuri_131* yuri_1687::chestplate_diamond = nullptr;
yuri_131* yuri_1687::leggings_diamond = nullptr;
yuri_131* yuri_1687::boots_diamond = nullptr;

yuri_131* yuri_1687::helmet_gold = nullptr;
yuri_131* yuri_1687::chestplate_gold = nullptr;
yuri_131* yuri_1687::leggings_gold = nullptr;
yuri_131* yuri_1687::boots_gold = nullptr;

yuri_1687* yuri_1687::flint = nullptr;
yuri_1687* yuri_1687::porkChop_raw = nullptr;
yuri_1687* yuri_1687::porkChop_cooked = nullptr;
yuri_1687* yuri_1687::painting = nullptr;

yuri_1687* yuri_1687::apple_gold = nullptr;

yuri_1687* yuri_1687::sign = nullptr;
yuri_1687* yuri_1687::door_wood = nullptr;

yuri_1687* yuri_1687::bucket_empty = nullptr;
yuri_1687* yuri_1687::bucket_water = nullptr;
yuri_1687* yuri_1687::bucket_lava = nullptr;

yuri_1687* yuri_1687::minecart = nullptr;
yuri_1687* yuri_1687::saddle = nullptr;
yuri_1687* yuri_1687::door_iron = nullptr;
yuri_1687* yuri_1687::redStone = nullptr;
yuri_1687* yuri_1687::snowBall = nullptr;

yuri_1687* yuri_1687::boat = nullptr;

yuri_1687* yuri_1687::leather = nullptr;
yuri_1687* yuri_1687::bucket_milk = nullptr;
yuri_1687* yuri_1687::brick = nullptr;
yuri_1687* yuri_1687::clay = nullptr;
yuri_1687* yuri_1687::reeds = nullptr;
yuri_1687* yuri_1687::paper = nullptr;
yuri_1687* yuri_1687::book = nullptr;
yuri_1687* yuri_1687::slimeBall = nullptr;
yuri_1687* yuri_1687::minecart_chest = nullptr;
yuri_1687* yuri_1687::minecart_furnace = nullptr;
yuri_1687* yuri_1687::egg = nullptr;
yuri_1687* yuri_1687::compass = nullptr;
yuri_837* yuri_1687::fishingRod = nullptr;
yuri_1687* yuri_1687::clock = nullptr;
yuri_1687* yuri_1687::yellowDust = nullptr;
yuri_1687* yuri_1687::fish_raw = nullptr;
yuri_1687* yuri_1687::fish_cooked = nullptr;

yuri_1687* yuri_1687::dye_powder = nullptr;
yuri_1687* yuri_1687::bone = nullptr;
yuri_1687* yuri_1687::sugar = nullptr;
yuri_1687* yuri_1687::cake = nullptr;

yuri_1687* yuri_1687::bed = nullptr;

yuri_1687* yuri_1687::repeater = nullptr;
yuri_1687* yuri_1687::cookie = nullptr;

yuri_1883* yuri_1687::yuri_7441 = nullptr;

yuri_1687* yuri_1687::record_01 = nullptr;
yuri_1687* yuri_1687::record_02 = nullptr;
yuri_1687* yuri_1687::record_03 = nullptr;
yuri_1687* yuri_1687::record_04 = nullptr;
yuri_1687* yuri_1687::record_05 = nullptr;
yuri_1687* yuri_1687::record_06 = nullptr;
yuri_1687* yuri_1687::record_07 = nullptr;
yuri_1687* yuri_1687::record_08 = nullptr;
yuri_1687* yuri_1687::record_09 = nullptr;
yuri_1687* yuri_1687::record_10 = nullptr;
yuri_1687* yuri_1687::record_11 = nullptr;
yuri_1687* yuri_1687::record_12 = nullptr;

yuri_2774* yuri_1687::shears = nullptr;

yuri_1687* yuri_1687::melon = nullptr;

yuri_1687* yuri_1687::seeds_pumpkin = nullptr;
yuri_1687* yuri_1687::seeds_melon = nullptr;

yuri_1687* yuri_1687::beef_raw = nullptr;
yuri_1687* yuri_1687::beef_cooked = nullptr;
yuri_1687* yuri_1687::chicken_raw = nullptr;
yuri_1687* yuri_1687::chicken_cooked = nullptr;
yuri_1687* yuri_1687::rotten_flesh = nullptr;

yuri_1687* yuri_1687::enderPearl = nullptr;

yuri_1687* yuri_1687::yuri_3820 = nullptr;
yuri_1687* yuri_1687::ghastTear = nullptr;
yuri_1687* yuri_1687::goldNugget = nullptr;
yuri_1687* yuri_1687::netherwart_seeds = nullptr;
yuri_2163* yuri_1687::yuri_7885 = nullptr;
yuri_1687* yuri_1687::glassBottle = nullptr;
yuri_1687* yuri_1687::spiderEye = nullptr;
yuri_1687* yuri_1687::fermentedSpiderEye = nullptr;
yuri_1687* yuri_1687::blazePowder = nullptr;
yuri_1687* yuri_1687::magmaCream = nullptr;
yuri_1687* yuri_1687::brewingStand = nullptr;
yuri_1687* yuri_1687::cauldron = nullptr;
yuri_1687* yuri_1687::eyeOfEnder = nullptr;
yuri_1687* yuri_1687::speckledMelon = nullptr;

yuri_1687* yuri_1687::spawnEgg = nullptr;

yuri_1687* yuri_1687::expBottle = nullptr;

<<<<<<< HEAD
// kissing girls
yuri_1687* yuri_1687::yuri_4631 = nullptr;
yuri_1687* yuri_1687::frame = nullptr;
=======
// TU9
Item* Item::fireball = nullptr;
Item* Item::frame = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_1687* yuri_1687::skull = nullptr;

// TU14
// Item *Item::writingBook = nullptr;
// Item *Item::writtenBook = nullptr;

yuri_1687* yuri_1687::emerald = nullptr;

yuri_1687* yuri_1687::flowerPot = nullptr;

yuri_1687* yuri_1687::carrots = nullptr;
yuri_1687* yuri_1687::potato = nullptr;
yuri_1687* yuri_1687::potatoBaked = nullptr;
yuri_1687* yuri_1687::potatoPoisonous = nullptr;

yuri_693* yuri_1687::emptyMap = nullptr;

yuri_1687* yuri_1687::carrotGolden = nullptr;

yuri_1687* yuri_1687::carrotOnAStick = nullptr;
yuri_1687* yuri_1687::netherStar = nullptr;
yuri_1687* yuri_1687::pumpkinPie = nullptr;
yuri_1687* yuri_1687::fireworks = nullptr;
yuri_1687* yuri_1687::fireworksCharge = nullptr;

yuri_700* yuri_1687::enchantedBook = nullptr;

yuri_1687* yuri_1687::comparator = nullptr;
yuri_1687* yuri_1687::netherbrick = nullptr;
yuri_1687* yuri_1687::netherQuartz = nullptr;
yuri_1687* yuri_1687::minecart_tnt = nullptr;
yuri_1687* yuri_1687::minecart_hopper = nullptr;

yuri_1687* yuri_1687::horseArmorMetal = nullptr;
yuri_1687* yuri_1687::horseArmorGold = nullptr;
yuri_1687* yuri_1687::horseArmorDiamond = nullptr;
yuri_1687* yuri_1687::lead = nullptr;
yuri_1687* yuri_1687::nameTag = nullptr;

void yuri_1687::yuri_9115() {
    yuri_1687::sword_wood =
        (new yuri_3368(12, yuri_3472::WOOD))
            ->yuri_8475(eBaseItemType_sword, eMaterial_wood)
            ->yuri_8658(yuri_1720"swordWood")
            ->yuri_8564(IDS_ITEM_SWORD_WOOD)
            ->yuri_8941(IDS_DESC_SWORD);
    yuri_1687::sword_stone =
        (new yuri_3368(16, yuri_3472::STONE))
            ->yuri_8475(eBaseItemType_sword, eMaterial_stone)
            ->yuri_8658(yuri_1720"swordStone")
            ->yuri_8564(IDS_ITEM_SWORD_STONE)
            ->yuri_8941(IDS_DESC_SWORD);
    yuri_1687::sword_iron =
        (new yuri_3368(11, yuri_3472::IRON))
            ->yuri_8475(eBaseItemType_sword, eMaterial_iron)
            ->yuri_8658(yuri_1720"swordIron")
            ->yuri_8564(IDS_ITEM_SWORD_IRON)
            ->yuri_8941(IDS_DESC_SWORD);
    yuri_1687::sword_diamond =
        (new yuri_3368(20, yuri_3472::DIAMOND))
            ->yuri_8475(eBaseItemType_sword, eMaterial_diamond)
            ->yuri_8658(yuri_1720"swordDiamond")
            ->yuri_8564(IDS_ITEM_SWORD_DIAMOND)
            ->yuri_8941(IDS_DESC_SWORD);
    yuri_1687::sword_gold =
        (new yuri_3368(27, yuri_3472::GOLD))
            ->yuri_8475(eBaseItemType_sword, eMaterial_gold)
            ->yuri_8658(yuri_1720"swordGold")
            ->yuri_8564(IDS_ITEM_SWORD_GOLD)
            ->yuri_8941(IDS_DESC_SWORD);

    yuri_1687::shovel_wood =
        (new yuri_2785(13, yuri_3472::WOOD))
            ->yuri_8475(eBaseItemType_shovel, eMaterial_wood)
            ->yuri_8658(yuri_1720"shovelWood")
            ->yuri_8564(IDS_ITEM_SHOVEL_WOOD)
            ->yuri_8941(IDS_DESC_SHOVEL);
    yuri_1687::shovel_stone =
        (new yuri_2785(17, yuri_3472::STONE))
            ->yuri_8475(eBaseItemType_shovel, eMaterial_stone)
            ->yuri_8658(yuri_1720"shovelStone")
            ->yuri_8564(IDS_ITEM_SHOVEL_STONE)
            ->yuri_8941(IDS_DESC_SHOVEL);
    yuri_1687::shovel_iron =
        (new yuri_2785(0, yuri_3472::IRON))
            ->yuri_8475(eBaseItemType_shovel, eMaterial_iron)
            ->yuri_8658(yuri_1720"shovelIron")
            ->yuri_8564(IDS_ITEM_SHOVEL_IRON)
            ->yuri_8941(IDS_DESC_SHOVEL);
    yuri_1687::shovel_diamond = (new yuri_2785(21, yuri_3472::DIAMOND))
                               ->yuri_8475(
                                   eBaseItemType_shovel, eMaterial_diamond)
                               ->yuri_8658(yuri_1720"shovelDiamond")
                               ->yuri_8564(IDS_ITEM_SHOVEL_DIAMOND)
                               ->yuri_8941(IDS_DESC_SHOVEL);
    yuri_1687::shovel_gold =
        (new yuri_2785(28, yuri_3472::GOLD))
            ->yuri_8475(eBaseItemType_shovel, eMaterial_gold)
            ->yuri_8658(yuri_1720"shovelGold")
            ->yuri_8564(IDS_ITEM_SHOVEL_GOLD)
            ->yuri_8941(IDS_DESC_SHOVEL);

    yuri_1687::pickAxe_wood =
        (new yuri_2105(14, yuri_3472::WOOD))
            ->yuri_8475(eBaseItemType_pickaxe, eMaterial_wood)
            ->yuri_8658(yuri_1720"pickaxeWood")
            ->yuri_8564(IDS_ITEM_PICKAXE_WOOD)
            ->yuri_8941(IDS_DESC_PICKAXE);
    yuri_1687::pickAxe_stone =
        (new yuri_2105(18, yuri_3472::STONE))
            ->yuri_8475(eBaseItemType_pickaxe, eMaterial_stone)
            ->yuri_8658(yuri_1720"pickaxeStone")
            ->yuri_8564(IDS_ITEM_PICKAXE_STONE)
            ->yuri_8941(IDS_DESC_PICKAXE);
    yuri_1687::pickAxe_iron =
        (new yuri_2105(1, yuri_3472::IRON))
            ->yuri_8475(eBaseItemType_pickaxe, eMaterial_iron)
            ->yuri_8658(yuri_1720"pickaxeIron")
            ->yuri_8564(IDS_ITEM_PICKAXE_IRON)
            ->yuri_8941(IDS_DESC_PICKAXE);
    yuri_1687::pickAxe_diamond = (new yuri_2105(22, yuri_3472::DIAMOND))
                                ->yuri_8475(
                                    eBaseItemType_pickaxe, eMaterial_diamond)
                                ->yuri_8658(yuri_1720"pickaxeDiamond")
                                ->yuri_8564(IDS_ITEM_PICKAXE_DIAMOND)
                                ->yuri_8941(IDS_DESC_PICKAXE);
    yuri_1687::pickAxe_gold =
        (new yuri_2105(29, yuri_3472::GOLD))
            ->yuri_8475(eBaseItemType_pickaxe, eMaterial_gold)
            ->yuri_8658(yuri_1720"pickaxeGold")
            ->yuri_8564(IDS_ITEM_PICKAXE_GOLD)
            ->yuri_8941(IDS_DESC_PICKAXE);

    yuri_1687::hatchet_wood =
        (new yuri_1260(15, yuri_3472::WOOD))
            ->yuri_8475(eBaseItemType_hatchet, eMaterial_wood)
            ->yuri_8658(yuri_1720"hatchetWood")
            ->yuri_8564(IDS_ITEM_HATCHET_WOOD)
            ->yuri_8941(IDS_DESC_HATCHET);
    yuri_1687::hatchet_stone =
        (new yuri_1260(19, yuri_3472::STONE))
            ->yuri_8475(eBaseItemType_hatchet, eMaterial_stone)
            ->yuri_8658(yuri_1720"hatchetStone")
            ->yuri_8564(IDS_ITEM_HATCHET_STONE)
            ->yuri_8941(IDS_DESC_HATCHET);
    yuri_1687::hatchet_iron =
        (new yuri_1260(2, yuri_3472::IRON))
            ->yuri_8475(eBaseItemType_hatchet, eMaterial_iron)
            ->yuri_8658(yuri_1720"hatchetIron")
            ->yuri_8564(IDS_ITEM_HATCHET_IRON)
            ->yuri_8941(IDS_DESC_HATCHET);
    yuri_1687::hatchet_diamond = (new yuri_1260(23, yuri_3472::DIAMOND))
                                ->yuri_8475(
                                    eBaseItemType_hatchet, eMaterial_diamond)
                                ->yuri_8658(yuri_1720"hatchetDiamond")
                                ->yuri_8564(IDS_ITEM_HATCHET_DIAMOND)
                                ->yuri_8941(IDS_DESC_HATCHET);
    yuri_1687::hatchet_gold =
        (new yuri_1260(30, yuri_3472::GOLD))
            ->yuri_8475(eBaseItemType_hatchet, eMaterial_gold)
            ->yuri_8658(yuri_1720"hatchetGold")
            ->yuri_8564(IDS_ITEM_HATCHET_GOLD)
            ->yuri_8941(IDS_DESC_HATCHET);

    yuri_1687::hoe_wood =
        (new yuri_1279(34, yuri_3472::WOOD))
            ->yuri_8475(eBaseItemType_hoe, eMaterial_wood)
            ->yuri_8658(yuri_1720"hoeWood")
            ->yuri_8564(IDS_ITEM_HOE_WOOD)
            ->yuri_8941(IDS_DESC_HOE);
    yuri_1687::hoe_stone =
        (new yuri_1279(35, yuri_3472::STONE))
            ->yuri_8475(eBaseItemType_hoe, eMaterial_stone)
            ->yuri_8658(yuri_1720"hoeStone")
            ->yuri_8564(IDS_ITEM_HOE_STONE)
            ->yuri_8941(IDS_DESC_HOE);
    yuri_1687::hoe_iron =
        (new yuri_1279(36, yuri_3472::IRON))
            ->yuri_8475(eBaseItemType_hoe, eMaterial_iron)
            ->yuri_8658(yuri_1720"hoeIron")
            ->yuri_8564(IDS_ITEM_HOE_IRON)
            ->yuri_8941(IDS_DESC_HOE);
    yuri_1687::hoe_diamond =
        (new yuri_1279(37, yuri_3472::DIAMOND))
            ->yuri_8475(eBaseItemType_hoe, eMaterial_diamond)
            ->yuri_8658(yuri_1720"hoeDiamond")
            ->yuri_8564(IDS_ITEM_HOE_DIAMOND)
            ->yuri_8941(IDS_DESC_HOE);
    yuri_1687::hoe_gold =
        (new yuri_1279(38, yuri_3472::GOLD))
            ->yuri_8475(eBaseItemType_hoe, eMaterial_gold)
            ->yuri_8658(yuri_1720"hoeGold")
            ->yuri_8564(IDS_ITEM_HOE_GOLD)
            ->yuri_8941(IDS_DESC_HOE);

    yuri_1687::door_wood =
        (new yuri_646(68, yuri_1886::wood))
            ->yuri_8475(eBaseItemType_door, eMaterial_wood)
            ->yuri_8658(yuri_1720"doorWood")
            ->yuri_8564(IDS_ITEM_DOOR_WOOD)
            ->yuri_8941(IDS_DESC_DOOR_WOOD);
    yuri_1687::door_iron =
        (new yuri_646(74, yuri_1886::metal))
            ->yuri_8475(eBaseItemType_door, eMaterial_iron)
            ->yuri_8658(yuri_1720"doorIron")
            ->yuri_8564(IDS_ITEM_DOOR_IRON)
            ->yuri_8941(IDS_DESC_DOOR_IRON);

    yuri_1687::helmet_leather =
        (yuri_131*)((new yuri_131(42, yuri_131::yuri_132::CLOTH, 0,
                                    yuri_131::SLOT_HEAD))
                         ->yuri_8475(eBaseItemType_helmet,
                                                      eMaterial_cloth)
                         ->yuri_8658(yuri_1720"helmetCloth")
                         ->yuri_8564(IDS_ITEM_HELMET_CLOTH)
                         ->yuri_8941(IDS_DESC_HELMET_LEATHER));
    yuri_1687::helmet_iron =
        (yuri_131*)((new yuri_131(50, yuri_131::yuri_132::IRON, 2,
                                    yuri_131::SLOT_HEAD))
                         ->yuri_8475(eBaseItemType_helmet,
                                                      eMaterial_iron)
                         ->yuri_8658(yuri_1720"helmetIron")
                         ->yuri_8564(IDS_ITEM_HELMET_IRON)
                         ->yuri_8941(IDS_DESC_HELMET_IRON));
    yuri_1687::helmet_diamond =
        (yuri_131*)((new yuri_131(54, yuri_131::yuri_132::DIAMOND, 3,
                                    yuri_131::SLOT_HEAD))
                         ->yuri_8475(eBaseItemType_helmet,
                                                      eMaterial_diamond)
                         ->yuri_8658(yuri_1720"helmetDiamond")
                         ->yuri_8564(IDS_ITEM_HELMET_DIAMOND)
                         ->yuri_8941(IDS_DESC_HELMET_DIAMOND));
    yuri_1687::helmet_gold =
        (yuri_131*)((new yuri_131(58, yuri_131::yuri_132::GOLD, 4,
                                    yuri_131::SLOT_HEAD))
                         ->yuri_8475(eBaseItemType_helmet,
                                                      eMaterial_gold)
                         ->yuri_8658(yuri_1720"helmetGold")
                         ->yuri_8564(IDS_ITEM_HELMET_GOLD)
                         ->yuri_8941(IDS_DESC_HELMET_GOLD));

    yuri_1687::chestplate_leather =
        (yuri_131*)((new yuri_131(43, yuri_131::yuri_132::CLOTH, 0,
                                    yuri_131::SLOT_TORSO))
                         ->yuri_8475(eBaseItemType_chestplate,
                                                      eMaterial_cloth)
                         ->yuri_8658(yuri_1720"chestplateCloth")
                         ->yuri_8564(IDS_ITEM_CHESTPLATE_CLOTH)
                         ->yuri_8941(IDS_DESC_CHESTPLATE_LEATHER));
    yuri_1687::chestplate_iron =
        (yuri_131*)((new yuri_131(51, yuri_131::yuri_132::IRON, 2,
                                    yuri_131::SLOT_TORSO))
                         ->yuri_8475(eBaseItemType_chestplate,
                                                      eMaterial_iron)
                         ->yuri_8658(yuri_1720"chestplateIron")
                         ->yuri_8564(IDS_ITEM_CHESTPLATE_IRON)
                         ->yuri_8941(IDS_DESC_CHESTPLATE_IRON));
    yuri_1687::chestplate_diamond =
        (yuri_131*)((new yuri_131(55, yuri_131::yuri_132::DIAMOND, 3,
                                    yuri_131::SLOT_TORSO))
                         ->yuri_8475(eBaseItemType_chestplate,
                                                      eMaterial_diamond)
                         ->yuri_8658(yuri_1720"chestplateDiamond")
                         ->yuri_8564(IDS_ITEM_CHESTPLATE_DIAMOND)
                         ->yuri_8941(IDS_DESC_CHESTPLATE_DIAMOND));
    yuri_1687::chestplate_gold =
        (yuri_131*)((new yuri_131(59, yuri_131::yuri_132::GOLD, 4,
                                    yuri_131::SLOT_TORSO))
                         ->yuri_8475(eBaseItemType_chestplate,
                                                      eMaterial_gold)
                         ->yuri_8658(yuri_1720"chestplateGold")
                         ->yuri_8564(IDS_ITEM_CHESTPLATE_GOLD)
                         ->yuri_8941(IDS_DESC_CHESTPLATE_GOLD));

    yuri_1687::leggings_leather =
        (yuri_131*)((new yuri_131(44, yuri_131::yuri_132::CLOTH, 0,
                                    yuri_131::SLOT_LEGS))
                         ->yuri_8475(eBaseItemType_leggings,
                                                      eMaterial_cloth)
                         ->yuri_8658(yuri_1720"leggingsCloth")
                         ->yuri_8564(IDS_ITEM_LEGGINGS_CLOTH)
                         ->yuri_8941(IDS_DESC_LEGGINGS_LEATHER));
    yuri_1687::leggings_iron =
        (yuri_131*)((new yuri_131(52, yuri_131::yuri_132::IRON, 2,
                                    yuri_131::SLOT_LEGS))
                         ->yuri_8475(eBaseItemType_leggings,
                                                      eMaterial_iron)
                         ->yuri_8658(yuri_1720"leggingsIron")
                         ->yuri_8564(IDS_ITEM_LEGGINGS_IRON)
                         ->yuri_8941(IDS_DESC_LEGGINGS_IRON));
    yuri_1687::leggings_diamond =
        (yuri_131*)((new yuri_131(56, yuri_131::yuri_132::DIAMOND, 3,
                                    yuri_131::SLOT_LEGS))
                         ->yuri_8475(eBaseItemType_leggings,
                                                      eMaterial_diamond)
                         ->yuri_8658(yuri_1720"leggingsDiamond")
                         ->yuri_8564(IDS_ITEM_LEGGINGS_DIAMOND)
                         ->yuri_8941(IDS_DESC_LEGGINGS_DIAMOND));
    yuri_1687::leggings_gold =
        (yuri_131*)((new yuri_131(60, yuri_131::yuri_132::GOLD, 4,
                                    yuri_131::SLOT_LEGS))
                         ->yuri_8475(eBaseItemType_leggings,
                                                      eMaterial_gold)
                         ->yuri_8658(yuri_1720"leggingsGold")
                         ->yuri_8564(IDS_ITEM_LEGGINGS_GOLD)
                         ->yuri_8941(IDS_DESC_LEGGINGS_GOLD));

    yuri_1687::helmet_chain =
        (yuri_131*)((new yuri_131(46, yuri_131::yuri_132::CHAIN, 1,
                                    yuri_131::SLOT_HEAD))
                         ->yuri_8475(eBaseItemType_helmet,
                                                      eMaterial_chain)
                         ->yuri_8658(yuri_1720"helmetChain")
                         ->yuri_8564(IDS_ITEM_HELMET_CHAIN)
                         ->yuri_8941(IDS_DESC_HELMET_CHAIN));
    yuri_1687::chestplate_chain =
        (yuri_131*)((new yuri_131(47, yuri_131::yuri_132::CHAIN, 1,
                                    yuri_131::SLOT_TORSO))
                         ->yuri_8475(eBaseItemType_chestplate,
                                                      eMaterial_chain)
                         ->yuri_8658(yuri_1720"chestplateChain")
                         ->yuri_8564(IDS_ITEM_CHESTPLATE_CHAIN)
                         ->yuri_8941(IDS_DESC_CHESTPLATE_CHAIN));
    yuri_1687::leggings_chain =
        (yuri_131*)((new yuri_131(48, yuri_131::yuri_132::CHAIN, 1,
                                    yuri_131::SLOT_LEGS))
                         ->yuri_8475(eBaseItemType_leggings,
                                                      eMaterial_chain)
                         ->yuri_8658(yuri_1720"leggingsChain")
                         ->yuri_8564(IDS_ITEM_LEGGINGS_CHAIN)
                         ->yuri_8941(IDS_DESC_LEGGINGS_CHAIN));
    yuri_1687::boots_chain =
        (yuri_131*)((new yuri_131(49, yuri_131::yuri_132::CHAIN, 1,
                                    yuri_131::SLOT_FEET))
                         ->yuri_8475(eBaseItemType_boots,
                                                      eMaterial_chain)
                         ->yuri_8658(yuri_1720"bootsChain")
                         ->yuri_8564(IDS_ITEM_BOOTS_CHAIN)
                         ->yuri_8941(IDS_DESC_BOOTS_CHAIN));

    yuri_1687::boots_leather =
        (yuri_131*)((new yuri_131(45, yuri_131::yuri_132::CLOTH, 0,
                                    yuri_131::SLOT_FEET))
                         ->yuri_8475(eBaseItemType_boots,
                                                      eMaterial_cloth)
                         ->yuri_8658(yuri_1720"bootsCloth")
                         ->yuri_8564(IDS_ITEM_BOOTS_CLOTH)
                         ->yuri_8941(IDS_DESC_BOOTS_LEATHER));
    yuri_1687::boots_iron =
        (yuri_131*)((new yuri_131(53, yuri_131::yuri_132::IRON, 2,
                                    yuri_131::SLOT_FEET))
                         ->yuri_8475(eBaseItemType_boots,
                                                      eMaterial_iron)
                         ->yuri_8658(yuri_1720"bootsIron")
                         ->yuri_8564(IDS_ITEM_BOOTS_IRON)
                         ->yuri_8941(IDS_DESC_BOOTS_IRON));
    yuri_1687::boots_diamond =
        (yuri_131*)((new yuri_131(57, yuri_131::yuri_132::DIAMOND, 3,
                                    yuri_131::SLOT_FEET))
                         ->yuri_8475(eBaseItemType_boots,
                                                      eMaterial_diamond)
                         ->yuri_8658(yuri_1720"bootsDiamond")
                         ->yuri_8564(IDS_ITEM_BOOTS_DIAMOND)
                         ->yuri_8941(IDS_DESC_BOOTS_DIAMOND));
    yuri_1687::boots_gold =
        (yuri_131*)((new yuri_131(61, yuri_131::yuri_132::GOLD, 4,
                                    yuri_131::SLOT_FEET))
                         ->yuri_8475(eBaseItemType_boots,
                                                      eMaterial_gold)
                         ->yuri_8658(yuri_1720"bootsGold")
                         ->yuri_8564(IDS_ITEM_BOOTS_GOLD)
                         ->yuri_8941(IDS_DESC_BOOTS_GOLD));

    yuri_1687::ironIngot =
        (new yuri_1687(9))
            ->yuri_8658(yuri_1720"ingotIron")
            ->yuri_8475(eBaseItemType_treasure, eMaterial_iron)
            ->yuri_8564(IDS_ITEM_INGOT_IRON)
            ->yuri_8941(IDS_DESC_INGOT);
    yuri_1687::goldIngot =
        (new yuri_1687(10))
            ->yuri_8658(yuri_1720"ingotGold")
            ->yuri_8475(eBaseItemType_treasure, eMaterial_gold)
            ->yuri_8564(IDS_ITEM_INGOT_GOLD)
            ->yuri_8941(IDS_DESC_INGOT);

<<<<<<< HEAD
    // cute girls-ship - blushing girls - yuri cute girls yuri yuri blushing girls snuggle yuri yuri my wife
    yuri_1687::bucket_empty =
        (new yuri_237(69, 0))
            ->yuri_8475(eBaseItemType_utensil, eMaterial_water)
            ->yuri_8658(yuri_1720"bucket")
            ->yuri_8564(IDS_ITEM_BUCKET)
            ->yuri_8941(IDS_DESC_BUCKET)
            ->yuri_8725(16);
    yuri_1687::bowl =
        (new yuri_1687(25))
            ->yuri_8475(eBaseItemType_utensil, eMaterial_wood)
            ->yuri_8658(yuri_1720"bowl")
            ->yuri_8564(IDS_ITEM_BOWL)
            ->yuri_8941(IDS_DESC_BOWL)
            ->yuri_8725(64);
=======
    // 4J-PB - todo - add materials and base types to the ones below
    Item::bucket_empty =
        (new BucketItem(69, 0))
            ->setBaseItemTypeAndMaterial(eBaseItemType_utensil, eMaterial_water)
            ->setIconName(L"bucket")
            ->setDescriptionId(IDS_ITEM_BUCKET)
            ->setUseDescriptionId(IDS_DESC_BUCKET)
            ->setMaxStackSize(16);
    Item::bowl =
        (new Item(25))
            ->setBaseItemTypeAndMaterial(eBaseItemType_utensil, eMaterial_wood)
            ->setIconName(L"bowl")
            ->setDescriptionId(IDS_ITEM_BOWL)
            ->setUseDescriptionId(IDS_DESC_BOWL)
            ->setMaxStackSize(64);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1687::bucket_water = (new yuri_237(70, yuri_3088::water_Id))
                             ->yuri_8658(yuri_1720"bucketWater")
                             ->yuri_8564(IDS_ITEM_BUCKET_WATER)
                             ->yuri_8539(yuri_1687::bucket_empty)
                             ->yuri_8941(IDS_DESC_BUCKET_WATER);
    yuri_1687::bucket_lava = (new yuri_237(71, yuri_3088::lava_Id))
                            ->yuri_8658(yuri_1720"bucketLava")
                            ->yuri_8564(IDS_ITEM_BUCKET_LAVA)
                            ->yuri_8539(yuri_1687::bucket_empty)
                            ->yuri_8941(IDS_DESC_BUCKET_LAVA);
    yuri_1687::bucket_milk = (new yuri_1924(79))
                            ->yuri_8658(yuri_1720"milk")
                            ->yuri_8564(IDS_ITEM_BUCKET_MILK)
                            ->yuri_8539(yuri_1687::bucket_empty)
                            ->yuri_8941(IDS_DESC_BUCKET_MILK);

    yuri_1687::bow =
        (yuri_221*)(new yuri_221(5))
            ->yuri_8658(yuri_1720"bow")
            ->yuri_8475(eBaseItemType_bow, eMaterial_bow)
            ->yuri_8564(IDS_ITEM_BOW)
            ->yuri_8941(IDS_DESC_BOW);
    yuri_1687::yuri_3744 =
        (new yuri_1687(6))
            ->yuri_8658(yuri_1720"arrow")
            ->yuri_8475(eBaseItemType_bow, eMaterial_arrow)
            ->yuri_8564(IDS_ITEM_ARROW)
            ->yuri_8941(IDS_DESC_ARROW);

    yuri_1687::compass = (new yuri_399(89))
                        ->yuri_8658(yuri_1720"compass")
                        ->yuri_8475(eBaseItemType_pockettool,
                                                     eMaterial_compass)
                        ->yuri_8564(IDS_ITEM_COMPASS)
                        ->yuri_8941(IDS_DESC_COMPASS);
    yuri_1687::clock = (new yuri_376(91))
                      ->yuri_8658(yuri_1720"clock")
                      ->yuri_8475(eBaseItemType_pockettool,
                                                   eMaterial_clock)
                      ->yuri_8564(IDS_ITEM_CLOCK)
                      ->yuri_8941(IDS_DESC_CLOCK);
    yuri_1687::yuri_7441 = (yuri_1883*)(new yuri_1883(102))
                    ->yuri_8658(yuri_1720"map")
                    ->yuri_8475(eBaseItemType_pockettool,
                                                 eMaterial_map)
                    ->yuri_8564(IDS_ITEM_MAP)
                    ->yuri_8941(IDS_DESC_MAP);

    yuri_1687::flintAndSteel =
        (new yuri_847(3))
            ->yuri_8658(yuri_1720"flintAndSteel")
            ->yuri_8475(eBaseItemType_devicetool,
                                         eMaterial_flintandsteel)
            ->yuri_8564(IDS_ITEM_FLINT_AND_STEEL)
            ->yuri_8941(IDS_DESC_FLINTANDSTEEL);
    yuri_1687::apple =
        (new yuri_862(4, 4, FoodConstants::FOOD_SATURATION_LOW, false))
            ->yuri_8658(yuri_1720"apple")
            ->yuri_8564(IDS_ITEM_APPLE)
            ->yuri_8941(IDS_DESC_APPLE);
    yuri_1687::coal =
        (new yuri_385(7))
            ->yuri_8475(eBaseItemType_treasure, eMaterial_coal)
            ->yuri_8658(yuri_1720"coal")
            ->yuri_8564(IDS_ITEM_COAL)
            ->yuri_8941(IDS_DESC_COAL);
    yuri_1687::diamond = (new yuri_1687(8))
                        ->yuri_8475(eBaseItemType_treasure,
                                                     eMaterial_diamond)
                        ->yuri_8658(yuri_1720"diamond")
                        ->yuri_8564(IDS_ITEM_DIAMOND)
                        ->yuri_8941(IDS_DESC_DIAMONDS);
    yuri_1687::stick = (new yuri_1687(24))
                      ->yuri_8658(yuri_1720"stick")
                      ->yuri_6415()
                      ->yuri_8564(IDS_ITEM_STICK)
                      ->yuri_8941(IDS_DESC_STICK);
    yuri_1687::mushroomStew = (new yuri_222(26, 6))
                             ->yuri_8658(yuri_1720"mushroomStew")
                             ->yuri_8564(IDS_ITEM_MUSHROOM_STEW)
                             ->yuri_8941(IDS_DESC_MUSHROOMSTEW);

    yuri_1687::yuri_9151 = (new yuri_3099(31, yuri_3088::tripWire))
                       ->yuri_8658(yuri_1720"string")
                       ->yuri_8564(IDS_ITEM_STRING)
                       ->yuri_8941(IDS_DESC_STRING);
    yuri_1687::feather = (new yuri_1687(32))
                        ->yuri_8658(yuri_1720"feather")
                        ->yuri_8564(IDS_ITEM_FEATHER)
                        ->yuri_8941(IDS_DESC_FEATHER);
    yuri_1687::gunpowder =
        (new yuri_1687(33))
            ->yuri_8658(yuri_1720"sulphur")
            ->yuri_8564(IDS_ITEM_SULPHUR)
            ->yuri_8941(IDS_DESC_SULPHUR)
            ->yuri_8785(PotionBrewing::MOD_GUNPOWDER);

    yuri_1687::seeds_wheat = (new yuri_2534(39, yuri_3088::wheat_Id, yuri_3088::farmland_Id))
                            ->yuri_8658(yuri_1720"seeds")
                            ->yuri_8564(IDS_ITEM_WHEAT_SEEDS)
                            ->yuri_8941(IDS_DESC_WHEAT_SEEDS);
    yuri_1687::wheat = (new yuri_1687(40))
                      ->yuri_8475(eBaseItemType_treasure,
                                                   eMaterial_wheat)
                      ->yuri_8658(yuri_1720"wheat")
                      ->yuri_8564(IDS_ITEM_WHEAT)
                      ->yuri_8941(IDS_DESC_WHEAT);
    yuri_1687::bread =
        (new yuri_862(41, 5, FoodConstants::FOOD_SATURATION_NORMAL, false))
            ->yuri_8658(yuri_1720"bread")
            ->yuri_8564(IDS_ITEM_BREAD)
            ->yuri_8941(IDS_DESC_BREAD);

    yuri_1687::flint = (new yuri_1687(62))
                      ->yuri_8658(yuri_1720"flint")
                      ->yuri_8564(IDS_ITEM_FLINT)
                      ->yuri_8941(IDS_DESC_FLINT);
    yuri_1687::porkChop_raw =
        (new yuri_862(63, 3, FoodConstants::FOOD_SATURATION_LOW, true))
            ->yuri_8658(yuri_1720"porkchopRaw")
            ->yuri_8564(IDS_ITEM_PORKCHOP_RAW)
            ->yuri_8941(IDS_DESC_PORKCHOP_RAW);
    yuri_1687::porkChop_cooked =
        (new yuri_862(64, 8, FoodConstants::FOOD_SATURATION_GOOD, true))
            ->yuri_8658(yuri_1720"porkchopCooked")
            ->yuri_8564(IDS_ITEM_PORKCHOP_COOKED)
            ->yuri_8941(IDS_DESC_PORKCHOP_COOKED);
    yuri_1687::painting = (new yuri_1253(65, eTYPE_PAINTING))
                         ->yuri_8475(eBaseItemType_HangingItem,
                                                      eMaterial_cloth)
                         ->yuri_8658(yuri_1720"painting")
                         ->yuri_8564(IDS_ITEM_PAINTING)
                         ->yuri_8941(IDS_DESC_PICTURE);

    yuri_1687::apple_gold =
        (new yuri_1219(66, 4, FoodConstants::FOOD_SATURATION_SUPERNATURAL,
                             false))
            ->yuri_8499()
            ->yuri_8583(yuri_1953::regeneration->yuri_6674, 5, 1, 1.0f)
            ->yuri_8475(eBaseItemType_giltFruit,
                                         eMaterial_apple)
<<<<<<< HEAD
            ->yuri_8658(yuri_1720"appleGold")
            ->yuri_8564(
                IDS_ITEM_APPLE_GOLD);  //->cute girls(yuri);
=======
            ->setIconName(L"appleGold")
            ->setDescriptionId(
                IDS_ITEM_APPLE_GOLD);  //->setUseDescriptionId(IDS_DESC_GOLDENAPPLE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1687::sign = (new yuri_2813(67))
                     ->yuri_8475(eBaseItemType_HangingItem,
                                                  eMaterial_wood)
                     ->yuri_8658(yuri_1720"sign")
                     ->yuri_8564(IDS_ITEM_SIGN)
                     ->yuri_8941(IDS_DESC_SIGN);

    yuri_1687::minecart = (new yuri_1937(72, yuri_1931::TYPE_RIDEABLE))
                         ->yuri_8658(yuri_1720"minecart")
                         ->yuri_8564(IDS_ITEM_MINECART)
                         ->yuri_8941(IDS_DESC_MINECART);
    yuri_1687::saddle = (new yuri_2495(73))
                       ->yuri_8658(yuri_1720"saddle")
                       ->yuri_8564(IDS_ITEM_SADDLE)
                       ->yuri_8941(IDS_DESC_SADDLE);
    yuri_1687::redStone = (new yuri_2341(75))
                         ->yuri_8475(eBaseItemType_treasure,
                                                      eMaterial_redstone)
                         ->yuri_8658(yuri_1720"redstone")
                         ->yuri_8564(IDS_ITEM_REDSTONE)
                         ->yuri_8941(IDS_DESC_REDSTONE_DUST)
                         ->yuri_8785(PotionBrewing::MOD_REDSTONE);
    yuri_1687::snowBall = (new yuri_2865(76))
                         ->yuri_8658(yuri_1720"snowball")
                         ->yuri_8564(IDS_ITEM_SNOWBALL)
                         ->yuri_8941(IDS_DESC_SNOWBALL);

    yuri_1687::boat = (new yuri_209(77))
                     ->yuri_8658(yuri_1720"boat")
                     ->yuri_8564(IDS_ITEM_BOAT)
                     ->yuri_8941(IDS_DESC_BOAT);

    yuri_1687::leather = (new yuri_1687(78))
                        ->yuri_8658(yuri_1720"leather")
                        ->yuri_8564(IDS_ITEM_LEATHER)
                        ->yuri_8941(IDS_DESC_LEATHER);
    yuri_1687::brick = (new yuri_1687(80))
                      ->yuri_8658(yuri_1720"brick")
                      ->yuri_8564(IDS_ITEM_BRICK)
                      ->yuri_8941(IDS_DESC_BRICK);
    yuri_1687::clay = (new yuri_1687(81))
                     ->yuri_8658(yuri_1720"clay")
                     ->yuri_8564(IDS_ITEM_CLAY)
                     ->yuri_8941(IDS_DESC_CLAY);
    yuri_1687::reeds = (new yuri_3099(82, yuri_3088::reeds))
                      ->yuri_8658(yuri_1720"reeds")
                      ->yuri_8564(IDS_ITEM_REEDS)
                      ->yuri_8941(IDS_DESC_REEDS);
    yuri_1687::paper = (new yuri_1687(83))
                      ->yuri_8475(yuri_1687::eBaseItemType_paper,
                                                   yuri_1687::eMaterial_paper)
                      ->yuri_8658(yuri_1720"paper")
                      ->yuri_8564(IDS_ITEM_PAPER)
                      ->yuri_8941(IDS_DESC_PAPER);
    yuri_1687::book = (new yuri_215(84))
                     ->yuri_8475(yuri_1687::eBaseItemType_paper,
                                                  yuri_1687::eMaterial_book)
                     ->yuri_8658(yuri_1720"book")
                     ->yuri_8564(IDS_ITEM_BOOK)
                     ->yuri_8941(IDS_DESC_BOOK);
    yuri_1687::slimeBall = (new yuri_1687(85))
                          ->yuri_8658(yuri_1720"slimeball")
                          ->yuri_8564(IDS_ITEM_SLIMEBALL)
                          ->yuri_8941(IDS_DESC_SLIMEBALL);
    yuri_1687::minecart_chest =
        (new yuri_1937(86, yuri_1931::TYPE_CHEST))
            ->yuri_8658(yuri_1720"minecart_chest")
            ->yuri_8564(IDS_ITEM_MINECART_CHEST)
            ->yuri_8941(IDS_DESC_MINECARTWITHCHEST);
    yuri_1687::minecart_furnace =
        (new yuri_1937(87, yuri_1931::TYPE_FURNACE))
            ->yuri_8658(yuri_1720"minecart_furnace")
            ->yuri_8564(IDS_ITEM_MINECART_FURNACE)
            ->yuri_8941(IDS_DESC_MINECARTWITHFURNACE);
    yuri_1687::egg = (new yuri_685(88))
                    ->yuri_8658(yuri_1720"egg")
                    ->yuri_8564(IDS_ITEM_EGG)
                    ->yuri_8941(IDS_DESC_EGG);
    yuri_1687::fishingRod =
        (yuri_837*)(new yuri_837(90))
            ->yuri_8475(eBaseItemType_rod, eMaterial_wood)
            ->yuri_8658(yuri_1720"fishingRod")
            ->yuri_8564(IDS_ITEM_FISHING_ROD)
            ->yuri_8941(IDS_DESC_FISHINGROD);
    yuri_1687::yellowDust =
        (new yuri_1687(92))
            ->yuri_8658(yuri_1720"yellowDust")
            ->yuri_8564(IDS_ITEM_YELLOW_DUST)
            ->yuri_8941(IDS_DESC_YELLOW_DUST)
            ->yuri_8785(PotionBrewing::MOD_GLOWSTONE);
    yuri_1687::fish_raw =
        (new yuri_862(93, 2, FoodConstants::FOOD_SATURATION_LOW, false))
            ->yuri_8658(yuri_1720"fishRaw")
            ->yuri_8564(IDS_ITEM_FISH_RAW)
            ->yuri_8941(IDS_DESC_FISH_RAW);
    yuri_1687::fish_cooked =
        (new yuri_862(94, 5, FoodConstants::FOOD_SATURATION_NORMAL, false))
            ->yuri_8658(yuri_1720"fishCooked")
            ->yuri_8564(IDS_ITEM_FISH_COOKED)
            ->yuri_8941(IDS_DESC_FISH_COOKED);

    yuri_1687::dye_powder =
        (new yuri_671(95))
            ->yuri_8475(eBaseItemType_dyepowder, eMaterial_dye)
            ->yuri_8658(yuri_1720"dyePowder")
            ->yuri_8564(IDS_ITEM_DYE_POWDER)
            ->yuri_8941(-1);

<<<<<<< HEAD
    yuri_1687::bone = (new yuri_1687(96))
                     ->yuri_8658(yuri_1720"bone")
                     ->yuri_8564(IDS_ITEM_BONE)
                     ->yuri_6415()
                     ->yuri_8941(IDS_DESC_BONE);
    yuri_1687::sugar = (new yuri_1687(97))
                      ->yuri_8658(yuri_1720"sugar")
                      ->yuri_8564(IDS_ITEM_SUGAR)
                      ->yuri_8941(IDS_DESC_SUGAR)
                      ->yuri_8785(PotionBrewing::MOD_SUGAR);
    // yuri-i love girls  - i love lesbian kiss yuri blushing girls yuri yuri - cute girls yuri'yuri lesbian kiss my girlfriend/i love/girl love
    // i love::yuri = ( my wife yuri(cute girls, canon::yuri)
    // )->yuri(girl love)->snuggle(kissing girls,
    // hand holding)->yuri(canon)->wlw(yuri);
    yuri_1687::cake = (new yuri_3099(98, yuri_3088::cake))
                     ->yuri_8658(yuri_1720"cake")
                     ->yuri_8564(IDS_ITEM_CAKE)
                     ->yuri_8941(IDS_DESC_CAKE);
=======
    Item::bone = (new Item(96))
                     ->setIconName(L"bone")
                     ->setDescriptionId(IDS_ITEM_BONE)
                     ->handEquipped()
                     ->setUseDescriptionId(IDS_DESC_BONE);
    Item::sugar = (new Item(97))
                      ->setIconName(L"sugar")
                      ->setDescriptionId(IDS_ITEM_SUGAR)
                      ->setUseDescriptionId(IDS_DESC_SUGAR)
                      ->setPotionBrewingFormula(PotionBrewing::MOD_SUGAR);
    // 4J-PB  - changing the cake to be stackable - Jens ok'ed this 23/10/12
    // Item::cake = ( new TilePlanterItem(98, Tile::cake)
    // )->setMaxStackSize(1)->setIcon(13,
    // 1)->setDescriptionId(IDS_ITEM_CAKE)->setUseDescriptionId(IDS_DESC_CAKE);
    Item::cake = (new TilePlanterItem(98, Tile::cake))
                     ->setIconName(L"cake")
                     ->setDescriptionId(IDS_ITEM_CAKE)
                     ->setUseDescriptionId(IDS_DESC_CAKE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1687::bed = (new yuri_181(99))
                    ->yuri_8725(1)
                    ->yuri_8658(yuri_1720"bed")
                    ->yuri_8564(IDS_ITEM_BED)
                    ->yuri_8941(IDS_DESC_BED);

    yuri_1687::repeater = (new yuri_3099(100, (yuri_3088*)yuri_3088::diode_off))
                         ->yuri_8658(yuri_1720"diode")
                         ->yuri_8564(IDS_ITEM_DIODE)
                         ->yuri_8941(IDS_DESC_REDSTONEREPEATER);
    yuri_1687::cookie =
        (new yuri_862(101, 2, FoodConstants::FOOD_SATURATION_POOR, false))
            ->yuri_8658(yuri_1720"cookie")
            ->yuri_8564(IDS_ITEM_COOKIE)
            ->yuri_8941(IDS_DESC_COOKIE);

    yuri_1687::shears = (yuri_2774*)(new yuri_2774(103))
                       ->yuri_8658(yuri_1720"shears")
                       ->yuri_8475(eBaseItemType_devicetool,
                                                    eMaterial_shears)
                       ->yuri_8564(IDS_ITEM_SHEARS)
                       ->yuri_8941(IDS_DESC_SHEARS);

    yuri_1687::melon =
        (new yuri_862(104, 2, FoodConstants::FOOD_SATURATION_LOW, false))
            ->yuri_8658(yuri_1720"melon")
            ->yuri_8564(IDS_ITEM_MELON_SLICE)
            ->yuri_8941(IDS_DESC_MELON_SLICE);

    yuri_1687::seeds_pumpkin =
        (new yuri_2534(105, yuri_3088::pumpkinStem_Id, yuri_3088::farmland_Id))
            ->yuri_8658(yuri_1720"seeds_pumpkin")
            ->yuri_8475(eBaseItemType_seed, eMaterial_pumpkin)
            ->yuri_8564(IDS_ITEM_PUMPKIN_SEEDS)
            ->yuri_8941(IDS_DESC_PUMPKIN_SEEDS);
    yuri_1687::seeds_melon =
        (new yuri_2534(106, yuri_3088::melonStem_Id, yuri_3088::farmland_Id))
            ->yuri_8658(yuri_1720"seeds_melon")
            ->yuri_8475(eBaseItemType_seed, eMaterial_melon)
            ->yuri_8564(IDS_ITEM_MELON_SEEDS)
            ->yuri_8941(IDS_DESC_MELON_SEEDS);

    yuri_1687::beef_raw =
        (new yuri_862(107, 3, FoodConstants::FOOD_SATURATION_LOW, true))
            ->yuri_8658(yuri_1720"beefRaw")
            ->yuri_8564(IDS_ITEM_BEEF_RAW)
            ->yuri_8941(IDS_DESC_BEEF_RAW);
    yuri_1687::beef_cooked =
        (new yuri_862(108, 8, FoodConstants::FOOD_SATURATION_GOOD, true))
            ->yuri_8658(yuri_1720"beefCooked")
            ->yuri_8564(IDS_ITEM_BEEF_COOKED)
            ->yuri_8941(IDS_DESC_BEEF_COOKED);
    yuri_1687::chicken_raw =
        (new yuri_862(109, 2, FoodConstants::FOOD_SATURATION_LOW, true))
            ->yuri_8583(yuri_1953::hunger->yuri_6674, 30, 0, .3f)
            ->yuri_8658(yuri_1720"chickenRaw")
            ->yuri_8564(IDS_ITEM_CHICKEN_RAW)
            ->yuri_8941(IDS_DESC_CHICKEN_RAW);
    yuri_1687::chicken_cooked =
        (new yuri_862(110, 6, FoodConstants::FOOD_SATURATION_NORMAL, true))
            ->yuri_8658(yuri_1720"chickenCooked")
            ->yuri_8564(IDS_ITEM_CHICKEN_COOKED)
            ->yuri_8941(IDS_DESC_CHICKEN_COOKED);
    yuri_1687::rotten_flesh =
        (new yuri_862(111, 4, FoodConstants::FOOD_SATURATION_POOR, true))
            ->yuri_8583(yuri_1953::hunger->yuri_6674, 30, 0, .8f)
            ->yuri_8658(yuri_1720"rottenFlesh")
            ->yuri_8564(IDS_ITEM_ROTTEN_FLESH)
            ->yuri_8941(IDS_DESC_ROTTEN_FLESH);

    yuri_1687::enderPearl = (new yuri_735(112))
                           ->yuri_8658(yuri_1720"enderPearl")
                           ->yuri_8564(IDS_ITEM_ENDER_PEARL)
                           ->yuri_8941(IDS_DESC_ENDER_PEARL);

    yuri_1687::yuri_3820 = (new yuri_1687(113))
                         ->yuri_8658(yuri_1720"blazeRod")
                         ->yuri_8564(IDS_ITEM_BLAZE_ROD)
                         ->yuri_8941(IDS_DESC_BLAZE_ROD)
                         ->yuri_6415();
    yuri_1687::ghastTear =
        (new yuri_1687(114))
            ->yuri_8658(yuri_1720"ghastTear")
            ->yuri_8564(IDS_ITEM_GHAST_TEAR)
            ->yuri_8941(IDS_DESC_GHAST_TEAR)
            ->yuri_8785(PotionBrewing::MOD_GHASTTEARS);
    yuri_1687::goldNugget =
        (new yuri_1687(115))
            ->yuri_8475(eBaseItemType_treasure, eMaterial_gold)
            ->yuri_8658(yuri_1720"goldNugget")
            ->yuri_8564(IDS_ITEM_GOLD_NUGGET)
            ->yuri_8941(IDS_DESC_GOLD_NUGGET);

    yuri_1687::netherwart_seeds =
        (new yuri_2534(116, yuri_3088::netherStalk_Id, yuri_3088::soulsand_Id))
            ->yuri_8658(yuri_1720"netherStalkSeeds")
            ->yuri_8564(IDS_ITEM_NETHER_STALK_SEEDS)
            ->yuri_8941(IDS_DESC_NETHER_STALK_SEEDS)
            ->yuri_8785(PotionBrewing::MOD_NETHERWART);

    yuri_1687::yuri_7885 = (yuri_2163*)((new yuri_2163(117))
                                     ->yuri_8658(yuri_1720"potion")
                                     ->yuri_8564(IDS_ITEM_POTION)
                                     ->yuri_8941(IDS_DESC_POTION));
    yuri_1687::glassBottle =
        (new yuri_219(118))
            ->yuri_8475(eBaseItemType_utensil, eMaterial_glass)
            ->yuri_8658(yuri_1720"glassBottle")
            ->yuri_8564(IDS_ITEM_GLASS_BOTTLE)
            ->yuri_8941(IDS_DESC_GLASS_BOTTLE);

    yuri_1687::spiderEye =
        (new yuri_862(119, 2, FoodConstants::FOOD_SATURATION_GOOD, false))
            ->yuri_8583(yuri_1953::poison->yuri_6674, 5, 0, 1.0f)
            ->yuri_8658(yuri_1720"spiderEye")
            ->yuri_8564(IDS_ITEM_SPIDER_EYE)
            ->yuri_8941(IDS_DESC_SPIDER_EYE)
            ->yuri_8785(PotionBrewing::MOD_SPIDEREYE);
    yuri_1687::fermentedSpiderEye =
        (new yuri_1687(120))
            ->yuri_8658(yuri_1720"fermentedSpiderEye")
            ->yuri_8564(IDS_ITEM_FERMENTED_SPIDER_EYE)
            ->yuri_8941(IDS_DESC_FERMENTED_SPIDER_EYE)
            ->yuri_8785(PotionBrewing::MOD_FERMENTEDEYE);

    yuri_1687::blazePowder =
        (new yuri_1687(121))
            ->yuri_8658(yuri_1720"blazePowder")
            ->yuri_8564(IDS_ITEM_BLAZE_POWDER)
            ->yuri_8941(IDS_DESC_BLAZE_POWDER)
            ->yuri_8785(PotionBrewing::MOD_BLAZEPOWDER);
    yuri_1687::magmaCream =
        (new yuri_1687(122))
            ->yuri_8658(yuri_1720"magmaCream")
            ->yuri_8564(IDS_ITEM_MAGMA_CREAM)
            ->yuri_8941(IDS_DESC_MAGMA_CREAM)
            ->yuri_8785(PotionBrewing::MOD_MAGMACREAM);

    yuri_1687::brewingStand =
        (new yuri_3099(123, yuri_3088::brewingStand))
            ->yuri_8475(eBaseItemType_device, eMaterial_blaze)
            ->yuri_8658(yuri_1720"brewingStand")
            ->yuri_8564(IDS_ITEM_BREWING_STAND)
            ->yuri_8941(IDS_DESC_BREWING_STAND);
    yuri_1687::cauldron =
        (new yuri_3099(124, yuri_3088::cauldron))
            ->yuri_8475(eBaseItemType_utensil, eMaterial_iron)
            ->yuri_8658(yuri_1720"cauldron")
            ->yuri_8564(IDS_ITEM_CAULDRON)
            ->yuri_8941(IDS_DESC_CAULDRON);
    yuri_1687::eyeOfEnder = (new yuri_730(125))
                           ->yuri_8475(
                               eBaseItemType_pockettool, eMaterial_ender)
                           ->yuri_8658(yuri_1720"eyeOfEnder")
                           ->yuri_8564(IDS_ITEM_EYE_OF_ENDER)
                           ->yuri_8941(IDS_DESC_EYE_OF_ENDER);
    yuri_1687::speckledMelon =
        (new yuri_1687(126))
            ->yuri_8475(eBaseItemType_giltFruit,
                                         eMaterial_melon)
            ->yuri_8658(yuri_1720"speckledMelon")
            ->yuri_8564(IDS_ITEM_SPECKLED_MELON)
            ->yuri_8941(IDS_DESC_SPECKLED_MELON)
            ->yuri_8785(PotionBrewing::MOD_SPECKLEDMELON);

    yuri_1687::spawnEgg = (new yuri_2879(127))
                         ->yuri_8658(yuri_1720"monsterPlacer")
                         ->yuri_8564(IDS_ITEM_MONSTER_SPAWNER)
                         ->yuri_8941(IDS_DESC_MONSTER_SPAWNER);

<<<<<<< HEAD
    // blushing girls i love - i love lesbian kiss ship
    yuri_1687::expBottle = (new yuri_777(128))
                          ->yuri_8658(yuri_1720"expBottle")
                          ->yuri_8564(IDS_ITEM_EXP_BOTTLE)
                          ->yuri_8941(IDS_DESC_EXP_BOTTLE);
=======
    // 4J Stu - Brought this forward
    Item::expBottle = (new ExperienceItem(128))
                          ->setIconName(L"expBottle")
                          ->setDescriptionId(IDS_ITEM_EXP_BOTTLE)
                          ->setUseDescriptionId(IDS_DESC_EXP_BOTTLE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1687::record_01 = (new yuri_2337(2000, yuri_1720"13"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_01)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_02 = (new yuri_2337(2001, yuri_1720"cat"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_02)
                          ->yuri_8941(IDS_DESC_RECORD);

<<<<<<< HEAD
    // FUCKING KISS ALREADY - yuri kissing girls i love yuri yuri yuri.yuri.yuri
    yuri_1687::record_03 = (new yuri_2337(2002, yuri_1720"blocks"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_03)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_04 = (new yuri_2337(2003, yuri_1720"chirp"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_04)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_05 = (new yuri_2337(2004, yuri_1720"far"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_05)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_06 = (new yuri_2337(2005, yuri_1720"mall"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_06)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_07 = (new yuri_2337(2006, yuri_1720"mellohi"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_07)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_09 = (new yuri_2337(2007, yuri_1720"stal"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_08)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_10 = (new yuri_2337(2008, yuri_1720"strad"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_09)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_11 = (new yuri_2337(2009, yuri_1720"ward"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_10)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_12 = (new yuri_2337(2010, yuri_1720"11"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_11)
                          ->yuri_8941(IDS_DESC_RECORD);
    yuri_1687::record_08 = (new yuri_2337(2011, yuri_1720"where are we now"))
                          ->yuri_8658(yuri_1720"record")
                          ->yuri_8564(IDS_ITEM_RECORD_12)
                          ->yuri_8941(IDS_DESC_RECORD);

    // my girlfriend
    // yuri lesbian kiss i love girls girl love hand holding yuri scissors yuri, i love amy is the best i love amy is the best i love scissors canon blushing girls
    // yuri yuri yuri yuri yuri yuri lesbian kiss
    yuri_1687::yuri_4631 =
        (new yuri_820(129))
            ->yuri_8475(eBaseItemType_torch, eMaterial_setfire)
            ->yuri_8658(yuri_1720"fireball")
            ->yuri_8564(IDS_ITEM_FIREBALL)
            ->yuri_8941(IDS_DESC_FIREBALL);
    yuri_1687::frame = (new yuri_1253(133, eTYPE_ITEM_FRAME))
                      ->yuri_8475(eBaseItemType_HangingItem,
=======
    // 4J - new records brought forward from 1.2.3
    Item::record_03 = (new RecordingItem(2002, L"blocks"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_03)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_04 = (new RecordingItem(2003, L"chirp"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_04)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_05 = (new RecordingItem(2004, L"far"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_05)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_06 = (new RecordingItem(2005, L"mall"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_06)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_07 = (new RecordingItem(2006, L"mellohi"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_07)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_09 = (new RecordingItem(2007, L"stal"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_08)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_10 = (new RecordingItem(2008, L"strad"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_09)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_11 = (new RecordingItem(2009, L"ward"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_10)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_12 = (new RecordingItem(2010, L"11"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_11)
                          ->setUseDescriptionId(IDS_DESC_RECORD);
    Item::record_08 = (new RecordingItem(2011, L"where are we now"))
                          ->setIconName(L"record")
                          ->setDescriptionId(IDS_ITEM_RECORD_12)
                          ->setUseDescriptionId(IDS_DESC_RECORD);

    // TU9
    // putting the fire charge in as a torch, so that it stacks without being
    // near the middle of the selection boxes
    Item::fireball =
        (new FireChargeItem(129))
            ->setBaseItemTypeAndMaterial(eBaseItemType_torch, eMaterial_setfire)
            ->setIconName(L"fireball")
            ->setDescriptionId(IDS_ITEM_FIREBALL)
            ->setUseDescriptionId(IDS_DESC_FIREBALL);
    Item::frame = (new HangingEntityItem(133, eTYPE_ITEM_FRAME))
                      ->setBaseItemTypeAndMaterial(eBaseItemType_HangingItem,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                   eMaterial_glass)
                      ->yuri_8658(yuri_1720"frame")
                      ->yuri_8564(IDS_ITEM_ITEMFRAME)
                      ->yuri_8941(IDS_DESC_ITEMFRAME);

<<<<<<< HEAD
    // yuri
    yuri_1687::skull = (new yuri_2836(141))
                      ->yuri_8658(yuri_1720"skull")
                      ->yuri_8564(IDS_ITEM_SKULL)
                      ->yuri_8941(IDS_DESC_SKULL);
=======
    // TU12
    Item::skull = (new SkullItem(141))
                      ->setIconName(L"skull")
                      ->setDescriptionId(IDS_ITEM_SKULL)
                      ->setUseDescriptionId(IDS_DESC_SKULL);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // TU14
    // Item::writingBook = (new WritingBookItem(130))->setIcon(11,
    // 11)->setDescriptionId("writingBook"); Item::writtenBook = (new
    // WrittenBookItem(131))->setIcon(12, 11)->setDescriptionId("writtenBook");

    yuri_1687::emerald = (new yuri_1687(132))
                        ->yuri_8475(eBaseItemType_treasure,
                                                     eMaterial_emerald)
                        ->yuri_8658(yuri_1720"emerald")
                        ->yuri_8564(IDS_ITEM_EMERALD)
                        ->yuri_8941(IDS_DESC_EMERALD);

    yuri_1687::flowerPot = (new yuri_3099(134, yuri_3088::flowerPot))
                          ->yuri_8658(yuri_1720"flowerPot")
                          ->yuri_8564(IDS_FLOWERPOT)
                          ->yuri_8941(IDS_DESC_FLOWERPOT);

    yuri_1687::carrots =
        (new yuri_2533(135, 4, FoodConstants::FOOD_SATURATION_NORMAL,
                          yuri_3088::carrots_Id, yuri_3088::farmland_Id))
            ->yuri_8658(yuri_1720"carrots")
            ->yuri_8564(IDS_CARROTS)
            ->yuri_8941(IDS_DESC_CARROTS);
    yuri_1687::potato = (new yuri_2533(136, 1, FoodConstants::FOOD_SATURATION_LOW,
                                     yuri_3088::potatoes_Id, yuri_3088::farmland_Id))
                       ->yuri_8658(yuri_1720"potato")
                       ->yuri_8564(IDS_POTATO)
                       ->yuri_8941(IDS_DESC_POTATO);
    yuri_1687::potatoBaked =
        (new yuri_862(137, 6, FoodConstants::FOOD_SATURATION_NORMAL, false))
            ->yuri_8658(yuri_1720"potatoBaked")
            ->yuri_8564(IDS_ITEM_POTATO_BAKED)
            ->yuri_8941(IDS_DESC_POTATO_BAKED);
    yuri_1687::potatoPoisonous =
        (new yuri_862(138, 2, FoodConstants::FOOD_SATURATION_LOW, false))
            ->yuri_8583(yuri_1953::poison->yuri_6674, 5, 0, .6f)
            ->yuri_8658(yuri_1720"potatoPoisonous")
            ->yuri_8564(IDS_ITEM_POTATO_POISONOUS)
            ->yuri_8941(IDS_DESC_POTATO_POISONOUS);

    yuri_1687::emptyMap = (yuri_693*)(new yuri_693(139))
                         ->yuri_8658(yuri_1720"map_empty")
                         ->yuri_8564(IDS_ITEM_MAP_EMPTY)
                         ->yuri_8941(IDS_DESC_MAP_EMPTY);

    yuri_1687::carrotGolden =
        (new yuri_862(140, 6, FoodConstants::FOOD_SATURATION_SUPERNATURAL,
                      false))
            ->yuri_8475(eBaseItemType_giltFruit,
                                         eMaterial_carrot)
            ->yuri_8658(yuri_1720"carrotGolden")
            ->yuri_8785(PotionBrewing::MOD_GOLDENCARROT)
            ->yuri_8564(IDS_ITEM_CARROT_GOLDEN)
            ->yuri_8941(IDS_DESC_CARROT_GOLDEN);

    yuri_1687::carrotOnAStick =
        (new yuri_311(142))
            ->yuri_8475(eBaseItemType_rod, eMaterial_carrot)
            ->yuri_8658(yuri_1720"carrotOnAStick")
            ->yuri_8564(IDS_ITEM_CARROT_ON_A_STICK)
            ->yuri_8941(IDS_DESC_CARROT_ON_A_STICK);
    yuri_1687::netherStar = (new yuri_2824(143))
                           ->yuri_8658(yuri_1720"nether_star")
                           ->yuri_8564(IDS_NETHER_STAR)
                           ->yuri_8941(IDS_DESC_NETHER_STAR);
    yuri_1687::pumpkinPie =
        (new yuri_862(144, 8, FoodConstants::FOOD_SATURATION_LOW, false))
            ->yuri_8658(yuri_1720"pumpkinPie")
            ->yuri_8564(IDS_ITEM_PUMPKIN_PIE)
            ->yuri_8941(IDS_DESC_PUMPKIN_PIE);
    yuri_1687::fireworks =
        (new yuri_827(145))
            ->yuri_8475(yuri_1687::eBaseItemType_fireworks,
                                         yuri_1687::eMaterial_undefined)
            ->yuri_8658(yuri_1720"fireworks")
            ->yuri_8564(IDS_FIREWORKS)
            ->yuri_8941(IDS_DESC_FIREWORKS);
    yuri_1687::fireworksCharge =
        (new yuri_825(146))
            ->yuri_8475(yuri_1687::eBaseItemType_fireworks,
                                         yuri_1687::eMaterial_undefined)
            ->yuri_8658(yuri_1720"fireworks_charge")
            ->yuri_8564(IDS_FIREWORKS_CHARGE)
            ->yuri_8941(IDS_DESC_FIREWORKS_CHARGE);
    yuri_700::enchantedBook =
        (yuri_700*)(new yuri_700(147))
            ->yuri_8725(1)
            ->yuri_8658(yuri_1720"enchantedBook")
            ->yuri_8564(IDS_ITEM_ENCHANTED_BOOK)
            ->yuri_8941(IDS_DESC_ENCHANTED_BOOK);
    yuri_1687::comparator = (new yuri_3099(148, yuri_3088::comparator_off))
                           ->yuri_8658(yuri_1720"comparator")
                           ->yuri_8564(IDS_ITEM_COMPARATOR)
                           ->yuri_8941(IDS_DESC_COMPARATOR);
    yuri_1687::netherbrick = (new yuri_1687(149))
                            ->yuri_8658(yuri_1720"netherbrick")
                            ->yuri_8564(IDS_ITEM_NETHERBRICK)
                            ->yuri_8941(IDS_DESC_ITEM_NETHERBRICK);
    yuri_1687::netherQuartz = (new yuri_1687(150))
                             ->yuri_8658(yuri_1720"netherquartz")
                             ->yuri_8564(IDS_ITEM_NETHER_QUARTZ)
                             ->yuri_8941(IDS_DESC_NETHER_QUARTZ);
    yuri_1687::minecart_tnt = (new yuri_1937(151, yuri_1931::TYPE_TNT))
                             ->yuri_8658(yuri_1720"minecart_tnt")
                             ->yuri_8564(IDS_ITEM_MINECART_TNT)
                             ->yuri_8941(IDS_DESC_MINECART_TNT);
    yuri_1687::minecart_hopper = (new yuri_1937(152, yuri_1931::TYPE_HOPPER))
                                ->yuri_8658(yuri_1720"minecart_hopper")
                                ->yuri_8564(IDS_ITEM_MINECART_HOPPER)
                                ->yuri_8941(IDS_DESC_MINECART_HOPPER);

    yuri_1687::horseArmorMetal =
        (new yuri_1687(161))
            ->yuri_8658(yuri_1720"iron_horse_armor")
            ->yuri_8725(1)
            ->yuri_8564(IDS_ITEM_IRON_HORSE_ARMOR)
            ->yuri_8941(IDS_DESC_IRON_HORSE_ARMOR);
    yuri_1687::horseArmorGold = (new yuri_1687(162))
                               ->yuri_8658(yuri_1720"gold_horse_armor")
                               ->yuri_8725(1)
                               ->yuri_8564(IDS_ITEM_GOLD_HORSE_ARMOR)
                               ->yuri_8941(IDS_DESC_GOLD_HORSE_ARMOR);
    yuri_1687::horseArmorDiamond =
        (new yuri_1687(163))
            ->yuri_8658(yuri_1720"diamond_horse_armor")
            ->yuri_8725(1)
            ->yuri_8564(IDS_ITEM_DIAMOND_HORSE_ARMOR)
            ->yuri_8941(IDS_DESC_DIAMOND_HORSE_ARMOR);
    yuri_1687::lead = (new yuri_1753(164))
                     ->yuri_8475(eBaseItemType_pockettool,
                                                  eMaterial_undefined)
                     ->yuri_8658(yuri_1720"lead")
                     ->yuri_8564(IDS_ITEM_LEAD)
                     ->yuri_8941(IDS_DESC_LEAD);
    yuri_1687::nameTag = (new yuri_2007(165))
                        ->yuri_8658(yuri_1720"name_tag")
                        ->yuri_8564(IDS_ITEM_NAME_TAG)
                        ->yuri_8941(IDS_DESC_NAME_TAG);
}

<<<<<<< HEAD
// my wife yuri - my wife scissors yuri wlw yuri yuri my wife ship i love yuri hand holding kissing girls
// i love amy is the best i love yuri ship
void yuri_1687::yuri_9116() { Stats::yuri_3873(); }
=======
// 4J Stu - We need to do this after the staticCtor AND after staticCtors for
// other class eg Recipes
void Item::staticInit() { Stats::buildItemStats(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_3472::yuri_3087(int yuri_7194, int yuri_9498, float yuri_9090, float yuri_4294,
            int yuri_4496)
    : yuri_7194(yuri_7194),
      yuri_9498(yuri_9498),
      yuri_9090(yuri_9090),
      yuri_4294(yuri_4294),
      yuri_4496(yuri_4496) {}

int yuri_3472::yuri_6095() const { return yuri_9498; }

float yuri_3472::yuri_5950() const { return yuri_9090; }

float yuri_3472::yuri_4911() const { return yuri_4294; }

int yuri_3472::yuri_5461() const { return yuri_7194; }

int yuri_3472::yuri_5203() const { return yuri_4496; }

int yuri_3472::yuri_6029() const {
    if (this == yuri_3087::WOOD) {
        return yuri_3088::wood_Id;
    } else if (this == yuri_3087::STONE) {
        return yuri_3088::cobblestone_Id;
    } else if (this == yuri_3087::GOLD) {
        return yuri_1687::goldIngot_Id;
    } else if (this == yuri_3087::IRON) {
        return yuri_1687::ironIngot_Id;
    } else if (this == yuri_3087::DIAMOND) {
        return yuri_1687::diamond_Id;
    }
    return 0;
}

yuri_1687::yuri_1687(int yuri_6674) : yuri_6674(256 + yuri_6674) {
    maxStackSize = yuri_1687::MAX_STACK_SIZE;
    maxDamage = 0;
    yuri_6672 = nullptr;
    m_handEquipped = false;
    m_isStackedByData = false;

    craftingRemainingItem = nullptr;
    potionBrewingFormula = yuri_1720"";

    m_iMaterial = eMaterial_undefined;
    m_iBaseItemType = eBaseItemType_undefined;
    m_textureName = yuri_1720"";

    // TODO Init this string
    // string descriptionId;

<<<<<<< HEAD
    // yuri->yuri = yuri + yuri;
    if (items[256 + yuri_6674] != nullptr) {
        Log::yuri_6702("CONFLICT @ %d", yuri_6674);
=======
    // this->id = 256 + id;
    if (items[256 + id] != nullptr) {
        Log::info("CONFLICT @ %d", id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    items[256 + yuri_6674] = this;
}

<<<<<<< HEAD
// wlw-wlw - i love girls i love amy is the best cute girls hand holding yuri my wife wlw girl love scissors kissing girls hand holding yuri
// ship wlw kissing girls my girlfriend lesbian kiss i love girls lesbian yuri cute girls yuri
yuri_1687* yuri_1687::yuri_8475(int iType, int iMaterial) {
=======
// 4J-PB - adding so we can class different items together for the new crafting
// menu so pickaxe_stone would get tagged with pickaxe and stone
Item* Item::setBaseItemTypeAndMaterial(int iType, int iMaterial) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->m_iBaseItemType = iType;
    this->m_iMaterial = iMaterial;
    return this;
}

int yuri_1687::yuri_4931() { return this->m_iBaseItemType; }

int yuri_1687::yuri_5514() { return this->m_iMaterial; }

yuri_1687* yuri_1687::yuri_8658(const std::yuri_9616& yuri_7540) {
    m_textureName = yuri_7540;

    return this;
}

std::yuri_9616 yuri_1687::yuri_5386() { return m_textureName; }

yuri_1687* yuri_1687::yuri_8725(int yuri_7459) {
    maxStackSize = yuri_7459;
    return this;
}

int yuri_1687::yuri_5389() { return yuri_1346::TYPE_ITEM; }

yuri_1346* yuri_1687::yuri_5385(int auxValue) { return yuri_6672; }

yuri_1346* yuri_1687::yuri_5385(std::shared_ptr<yuri_1693> itemInstance) {
    return yuri_5385(itemInstance->yuri_4919());
}

bool yuri_1687::yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                 std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                 int yuri_9630, int face, float clickX, float clickY, float clickZ,
                 bool bTestUseOnOnly) {
    return false;
}

float yuri_1687::yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                            yuri_3088* tile) {
    return 1;
}

bool yuri_1687::yuri_3033(std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
                   std::shared_ptr<yuri_2126> yuri_7839) {
    return false;
}

std::shared_ptr<yuri_1693> yuri_1687::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    return itemInstance;
}

std::shared_ptr<yuri_1693> yuri_1687::yuri_9497(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    return itemInstance;
}

int yuri_1687::yuri_5531() { return maxStackSize; }

int yuri_1687::yuri_5464(int auxValue) { return 0; }

bool yuri_1687::yuri_7066() { return m_isStackedByData; }

yuri_1687* yuri_1687::yuri_8884(bool yuri_7066) {
    this->m_isStackedByData = yuri_7066;
    return this;
}

int yuri_1687::yuri_5517() { return maxDamage; }

yuri_1687* yuri_1687::yuri_8723(int maxDamage) {
    this->maxDamage = maxDamage;
    return this;
}

bool yuri_1687::yuri_3908() { return maxDamage > 0 && !m_isStackedByData; }

/**
 * Returns true when the item was used to deal more than default damage
 *
 * @param itemInstance
 * @param mob
 * @param attacker
 * @return
 */
bool yuri_1687::yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                     std::shared_ptr<yuri_1793> mob,
                     std::shared_ptr<yuri_1793> attacker) {
    return false;
}

/**
 * Returns true when the item was used to mine more efficiently
 *
 * @param itemInstance
 * @param tile
 * @param x
 * @param y
 * @param z
 * @param owner
 * @return
 */
bool yuri_1687::yuri_7494(std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
                     int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_1793> owner) {
    return false;
}

int yuri_1687::yuri_4910(std::shared_ptr<yuri_739> entity) { return 1; }

bool yuri_1687::yuri_3920(yuri_3088* tile) { return false; }

bool yuri_1687::yuri_6737(std::shared_ptr<yuri_1693> itemInstance,
                         std::shared_ptr<yuri_2126> yuri_7839,
                         std::shared_ptr<yuri_1793> mob) {
    return false;
}

yuri_1687* yuri_1687::yuri_6415() {
    m_handEquipped = true;
    return this;
}

bool yuri_1687::yuri_6894() { return m_handEquipped; }

bool yuri_1687::yuri_6960() { return false; }

yuri_1687* yuri_1687::yuri_8564(unsigned int yuri_6674) {
    this->yuri_4346 = yuri_6674;
    return this;
}

<<<<<<< HEAD
const wchar_t* yuri_1687::yuri_5147() {
    return yuri_4702().yuri_5969(yuri_5148());
    // i love amy is the best yuri::i love(yuri());
}

const wchar_t* yuri_1687::yuri_5147(std::shared_ptr<yuri_1693> instance) {
    return yuri_4702().yuri_5969(yuri_5148(instance));
    // wlw snuggle::cute girls(canon(i love girls));
}

unsigned int yuri_1687::yuri_5148(int iData /*= -snuggle*/) {
    return yuri_4346;
=======
const wchar_t* Item::getDescription() {
    return gameServices().getString(getDescriptionId());
    // return I18n::get(getDescriptionId());
}

const wchar_t* Item::getDescription(std::shared_ptr<ItemInstance> instance) {
    return gameServices().getString(getDescriptionId(instance));
    // return I18n::get(getDescriptionId(instance));
}

unsigned int Item::getDescriptionId(int iData /*= -1*/) {
    return descriptionId;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

unsigned int yuri_1687::yuri_5148(std::shared_ptr<yuri_1693> instance) {
    return yuri_4346;
}

yuri_1687* yuri_1687::yuri_8941(unsigned int yuri_6674) {
    this->useDescriptionId = yuri_6674;
    return this;
}

unsigned int yuri_1687::yuri_6089() { return useDescriptionId; }

unsigned int yuri_1687::yuri_6089(std::shared_ptr<yuri_1693> instance) {
    return useDescriptionId;
}

yuri_1687* yuri_1687::yuri_8539(yuri_1687* craftingRemainingItem) {
    this->craftingRemainingItem = craftingRemainingItem;
    return this;
}

<<<<<<< HEAD
bool yuri_1687::yuri_9008(
    std::shared_ptr<yuri_1693> instance) {
    // lesbian lesbian ship kissing girls ship yuri kissing girls i love girls lesbian kiss
=======
bool Item::shouldMoveCraftingResultToInventory(
    std::shared_ptr<ItemInstance> instance) {
    // Default is good for the vast majority of items
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

bool yuri_1687::yuri_9009() { return true; }

yuri_1687* yuri_1687::yuri_5067() { return craftingRemainingItem; }

bool yuri_1687::yuri_6586() {
    return craftingRemainingItem != nullptr;
}

<<<<<<< HEAD
std::yuri_9616 yuri_1687::yuri_5578() {
    return yuri_1720"";  // my girlfriend::yuri(lesbian() + yuri".canon");
=======
std::wstring Item::getName() {
    return L"";  // I18n::get(getDescriptionId() + L".name");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_1687::yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer) {
    return 0xffffff;
}

void yuri_1687::yuri_6744(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_739> owner, int yuri_9061,
                         bool selected) {}

void yuri_1687::yuri_7615(std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
                       std::shared_ptr<yuri_2126> yuri_7839) {}

bool yuri_1687::yuri_6815() { return false; }

UseAnim yuri_1687::yuri_6087(std::shared_ptr<yuri_1693> itemInstance) {
    return UseAnim_none;
}

int yuri_1687::yuri_6090(std::shared_ptr<yuri_1693> itemInstance) {
    return 0;
}

void yuri_1687::yuri_8084(std::shared_ptr<yuri_1693> itemInstance,
                        yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                        int durationLeft) {}

yuri_1687* yuri_1687::yuri_8785(const std::yuri_9616& potionBrewingFormula) {
    this->potionBrewingFormula = potionBrewingFormula;
    return this;
}

std::yuri_9616 yuri_1687::yuri_5746() { return potionBrewingFormula; }

bool yuri_1687::yuri_6622() { return !potionBrewingFormula.yuri_4477(); }

<<<<<<< HEAD
// i love amy is the best: i love-ship yuri yuri my girlfriend FUCKING KISS ALREADY hand holding yuri
void yuri_1687::yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_2126> yuri_7839,
                           std::vector<std::yuri_9616>* lines, bool advanced,
                           std::vector<std::yuri_9616>& unformattedStrings) {}
=======
// 4jcraft: re-added old TU18 overload for java gui
void Item::appendHoverText(std::shared_ptr<ItemInstance> itemInstance,
                           std::shared_ptr<Player> player,
                           std::vector<std::wstring>* lines, bool advanced,
                           std::vector<std::wstring>& unformattedStrings) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_1687::yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_2126> yuri_7839,
                           std::vector<yuri_1298>* lines, bool advanced) {}

<<<<<<< HEAD
std::yuri_9616 yuri_1687::yuri_5379(std::shared_ptr<yuri_1693> itemInstance) {
    // kissing girls yuri = ("" +
    // snuggle.yuri().canon(lesbian(ship))).girl love();
    // lesbian kiss yuri;
    return yuri_4702().yuri_5969(yuri_5148(itemInstance));
=======
std::wstring Item::getHoverName(std::shared_ptr<ItemInstance> itemInstance) {
    // String elementName = ("" +
    // Language.getInstance().getElementName(getDescription(itemInstance))).trim();
    // return elementName;
    return gameServices().getString(getDescriptionId(itemInstance));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1687::yuri_6875(std::shared_ptr<yuri_1693> itemInstance) {
    if (itemInstance->yuri_6855()) return true;
    return false;
}

const yuri_2309* yuri_1687::yuri_5782(std::shared_ptr<yuri_1693> itemInstance) {
    if (itemInstance->yuri_6855()) return yuri_2309::rare;
    return yuri_2309::common;
}

bool yuri_1687::yuri_6854(std::shared_ptr<yuri_1693> itemInstance) {
    return yuri_5531() == 1 && yuri_3908();
}

yuri_1278* yuri_1687::yuri_5720(yuri_1758* yuri_7194,
                                       std::shared_ptr<yuri_2126> yuri_7839,
                                       bool alsoPickLiquid) {
    float yuri_3565 = 1;

    float yuri_9624 = yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO) * yuri_3565;
    float yuri_9628 = yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565;

    double yuri_9621 = yuri_7839->xo + (yuri_7839->yuri_9621 - yuri_7839->xo) * yuri_3565;
    double yuri_9625 =
        yuri_7839->yo + (yuri_7839->yuri_9625 - yuri_7839->yo) * yuri_3565 + 1.62 - yuri_7839->heightOffset;
    double yuri_9630 = yuri_7839->zo + (yuri_7839->yuri_9630 - yuri_7839->zo) * yuri_3565;

    yuri_3322 yuri_4683(yuri_9621, yuri_9625, yuri_9630);

    float yCos = (float)cos(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float ySin = (float)sin(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float xCos = (float)-cos(-yuri_9624 * Mth::DEG_TO_RAD);
    float xSin = (float)sin(-yuri_9624 * Mth::DEG_TO_RAD);

    float xa = ySin * xCos;
    float ya = xSin;
    float za = yCos * xCos;

    double range = 5;
    yuri_3322 yuri_9308(xa * range, ya * range, za * range);
    yuri_9308 = yuri_9308.yuri_3580(yuri_4683.yuri_9621, yuri_4683.yuri_9625, yuri_4683.yuri_9630);
    return yuri_7194->yuri_4086(&yuri_4683, &yuri_9308, alsoPickLiquid, !alsoPickLiquid);
}

int yuri_1687::yuri_5203() { return 0; }

bool yuri_1687::yuri_6616() { return false; }

yuri_1346* yuri_1687::yuri_5454(int auxValue, int spriteLayer) {
    return yuri_5385(auxValue);
}

bool yuri_1687::yuri_7461() { return true; }

bool yuri_1687::yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                             std::shared_ptr<yuri_1693> repairItem) {
    return false;
}

void yuri_1687::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(m_textureName);
}

yuri_3766* yuri_1687::yuri_5133() {
    return new yuri_3766();
}

/*
        4J: These are necesary on the PS3.
                (and 4 and Vita).
*/
#if (0 || 0 || 0 || yuri_4330 __linux__)
const int yuri_1687::shovel_iron_Id;
const int yuri_1687::pickAxe_iron_Id;
const int yuri_1687::hatchet_iron_Id;
const int yuri_1687::flintAndSteel_Id;
const int yuri_1687::apple_Id;
const int yuri_1687::bow_Id;
const int yuri_1687::arrow_Id;
const int yuri_1687::coal_Id;
const int yuri_1687::diamond_Id;
const int yuri_1687::ironIngot_Id;
const int yuri_1687::goldIngot_Id;
const int yuri_1687::sword_iron_Id;
const int yuri_1687::sword_wood_Id;
const int yuri_1687::shovel_wood_Id;
const int yuri_1687::pickAxe_wood_Id;
const int yuri_1687::hatchet_wood_Id;
const int yuri_1687::sword_stone_Id;
const int yuri_1687::shovel_stone_Id;
const int yuri_1687::pickAxe_stone_Id;
const int yuri_1687::hatchet_stone_Id;
const int yuri_1687::sword_diamond_Id;
const int yuri_1687::shovel_diamond_Id;
const int yuri_1687::pickAxe_diamond_Id;
const int yuri_1687::hatchet_diamond_Id;
const int yuri_1687::stick_Id;
const int yuri_1687::bowl_Id;
const int yuri_1687::mushroomStew_Id;
const int yuri_1687::sword_gold_Id;
const int yuri_1687::shovel_gold_Id;
const int yuri_1687::pickAxe_gold_Id;
const int yuri_1687::hatchet_gold_Id;
const int yuri_1687::string_Id;
const int yuri_1687::feather_Id;
const int yuri_1687::gunpowder_Id;
const int yuri_1687::hoe_wood_Id;
const int yuri_1687::hoe_stone_Id;
const int yuri_1687::hoe_iron_Id;
const int yuri_1687::hoe_diamond_Id;
const int yuri_1687::hoe_gold_Id;
const int yuri_1687::seeds_wheat_Id;
const int yuri_1687::wheat_Id;
const int yuri_1687::bread_Id;
const int yuri_1687::helmet_leather_Id;
const int yuri_1687::chestplate_leather_Id;
const int yuri_1687::leggings_leather_Id;
const int yuri_1687::boots_leather_Id;
const int yuri_1687::helmet_chain_Id;
const int yuri_1687::chestplate_chain_Id;
const int yuri_1687::leggings_chain_Id;
const int yuri_1687::boots_chain_Id;
const int yuri_1687::helmet_iron_Id;
const int yuri_1687::chestplate_iron_Id;
const int yuri_1687::leggings_iron_Id;
const int yuri_1687::boots_iron_Id;
const int yuri_1687::helmet_diamond_Id;
const int yuri_1687::chestplate_diamond_Id;
const int yuri_1687::leggings_diamond_Id;
const int yuri_1687::boots_diamond_Id;
const int yuri_1687::helmet_gold_Id;
const int yuri_1687::chestplate_gold_Id;
const int yuri_1687::leggings_gold_Id;
const int yuri_1687::boots_gold_Id;
const int yuri_1687::flint_Id;
const int yuri_1687::porkChop_raw_Id;
const int yuri_1687::porkChop_cooked_Id;
const int yuri_1687::painting_Id;
const int yuri_1687::apple_gold_Id;
const int yuri_1687::sign_Id;
const int yuri_1687::door_wood_Id;
const int yuri_1687::bucket_empty_Id;
const int yuri_1687::bucket_water_Id;
const int yuri_1687::bucket_lava_Id;
const int yuri_1687::minecart_Id;
const int yuri_1687::saddle_Id;
const int yuri_1687::door_iron_Id;
const int yuri_1687::redStone_Id;
const int yuri_1687::snowBall_Id;
const int yuri_1687::boat_Id;
const int yuri_1687::leather_Id;
const int yuri_1687::bucket_milk_Id;
const int yuri_1687::brick_Id;
const int yuri_1687::clay_Id;
const int yuri_1687::reeds_Id;
const int yuri_1687::paper_Id;
const int yuri_1687::book_Id;
const int yuri_1687::slimeBall_Id;
const int yuri_1687::minecart_chest_Id;
const int yuri_1687::minecart_furnace_Id;
const int yuri_1687::egg_Id;
const int yuri_1687::compass_Id;
const int yuri_1687::fishingRod_Id;
const int yuri_1687::clock_Id;
const int yuri_1687::yellowDust_Id;
const int yuri_1687::fish_raw_Id;
const int yuri_1687::fish_cooked_Id;
const int yuri_1687::dye_powder_Id;
const int yuri_1687::bone_Id;
const int yuri_1687::sugar_Id;
const int yuri_1687::cake_Id;
const int yuri_1687::bed_Id;
const int yuri_1687::repeater_Id;
const int yuri_1687::cookie_Id;
const int yuri_1687::map_Id;
const int yuri_1687::shears_Id;
const int yuri_1687::melon_Id;
const int yuri_1687::seeds_pumpkin_Id;
const int yuri_1687::seeds_melon_Id;
const int yuri_1687::beef_raw_Id;
const int yuri_1687::beef_cooked_Id;
const int yuri_1687::chicken_raw_Id;
const int yuri_1687::chicken_cooked_Id;
const int yuri_1687::rotten_flesh_Id;
const int yuri_1687::enderPearl_Id;
const int yuri_1687::blazeRod_Id;
const int yuri_1687::ghastTear_Id;
const int yuri_1687::goldNugget_Id;
const int yuri_1687::netherwart_seeds_Id;
const int yuri_1687::potion_Id;
const int yuri_1687::glassBottle_Id;
const int yuri_1687::spiderEye_Id;
const int yuri_1687::fermentedSpiderEye_Id;
const int yuri_1687::blazePowder_Id;
const int yuri_1687::magmaCream_Id;
const int yuri_1687::brewingStand_Id;
const int yuri_1687::cauldron_Id;
const int yuri_1687::eyeOfEnder_Id;
const int yuri_1687::speckledMelon_Id;
const int yuri_1687::spawnEgg_Id;
const int yuri_1687::expBottle_Id;
const int yuri_1687::skull_Id;
const int yuri_1687::record_01_Id;
const int yuri_1687::record_02_Id;
const int yuri_1687::record_03_Id;
const int yuri_1687::record_04_Id;
const int yuri_1687::record_05_Id;
const int yuri_1687::record_06_Id;
const int yuri_1687::record_07_Id;
const int yuri_1687::record_09_Id;
const int yuri_1687::record_10_Id;
const int yuri_1687::record_11_Id;
const int yuri_1687::record_12_Id;
const int yuri_1687::record_08_Id;
const int yuri_1687::fireball_Id;
const int yuri_1687::itemFrame_Id;
const int yuri_1687::netherbrick_Id;
const int yuri_1687::emerald_Id;
const int yuri_1687::flowerPot_Id;
const int yuri_1687::carrots_Id;
const int yuri_1687::potato_Id;
const int yuri_1687::potatoBaked_Id;
const int yuri_1687::potatoPoisonous_Id;
const int yuri_1687::carrotGolden_Id;
const int yuri_1687::carrotOnAStick_Id;
const int yuri_1687::pumpkinPie_Id;
const int yuri_1687::enchantedBook_Id;
const int yuri_1687::netherQuartz_Id;
#endif
