#include "minecraft/util/Log.h"
#include "EntityIO.h"

#include <utility>

#include "Entity.h"
#include "app/linux/LinuxGame.h"
#include "Painting.h"
#include "java/Class.h"
#include "java/JavaIntHash.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/ItemFrame.h"
#include "minecraft/world/entity/LeashFenceKnotEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ambient/Bat.h"
#include "minecraft/world/entity/animal/Chicken.h"
#include "minecraft/world/entity/animal/Cow.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/animal/MushroomCow.h"
#include "minecraft/world/entity/animal/Ocelot.h"
#include "minecraft/world/entity/animal/Pig.h"
#include "minecraft/world/entity/animal/Sheep.h"
#include "minecraft/world/entity/animal/SnowMan.h"
#include "minecraft/world/entity/animal/Squid.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"
#include "minecraft/world/entity/animal/Wolf.h"
#include "minecraft/world/entity/boss/enderdragon/EnderCrystal.h"
#include "minecraft/world/entity/boss/enderdragon/EnderDragon.h"
#include "minecraft/world/entity/boss/wither/WitherBoss.h"
#include "minecraft/world/entity/item/Boat.h"
#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/item/MinecartChest.h"
#include "minecraft/world/entity/item/MinecartFurnace.h"
#include "minecraft/world/entity/item/MinecartHopper.h"
#include "minecraft/world/entity/item/MinecartRideable.h"
#include "minecraft/world/entity/item/MinecartSpawner.h"
#include "minecraft/world/entity/item/MinecartTNT.h"
#include "minecraft/world/entity/item/PrimedTnt.h"
#include "minecraft/world/entity/monster/Blaze.h"
#include "minecraft/world/entity/monster/CaveSpider.h"
#include "minecraft/world/entity/monster/Creeper.h"
#include "minecraft/world/entity/monster/EnderMan.h"
#include "minecraft/world/entity/monster/Ghast.h"
#include "minecraft/world/entity/monster/Giant.h"
#include "minecraft/world/entity/monster/LavaSlime.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/PigZombie.h"
#include "minecraft/world/entity/monster/Silverfish.h"
#include "minecraft/world/entity/monster/Skeleton.h"
#include "minecraft/world/entity/monster/Slime.h"
#include "minecraft/world/entity/monster/Spider.h"
#include "minecraft/world/entity/monster/Witch.h"
#include "minecraft/world/entity/monster/Zombie.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/entity/projectile/DragonFireball.h"
#include "minecraft/world/entity/projectile/EyeOfEnderSignal.h"
#include "minecraft/world/entity/projectile/FireworksRocketEntity.h"
#include "minecraft/world/entity/projectile/LargeFireball.h"
#include "minecraft/world/entity/projectile/SmallFireball.h"
#include "minecraft/world/entity/projectile/Snowball.h"
#include "minecraft/world/entity/projectile/ThrownEnderpearl.h"
#include "minecraft/world/entity/projectile/ThrownExpBottle.h"
#include "minecraft/world/entity/projectile/ThrownPotion.h"
#include "minecraft/world/entity/projectile/WitherSkull.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

std::unordered_map<std::yuri_9616, entityCreateFn>* EntityIO::idCreateMap =
    new std::unordered_map<std::yuri_9616, entityCreateFn>;
std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                   eINSTANCEOFKeyEq>* EntityIO::classIdMap =
    new std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                           eINSTANCEOFKeyEq>;
std::unordered_map<int, entityCreateFn>* EntityIO::numCreateMap =
    new std::unordered_map<int, entityCreateFn>;
std::unordered_map<int, eINSTANCEOF>* EntityIO::numClassMap =
    new std::unordered_map<int, eINSTANCEOF>;
std::unordered_map<eINSTANCEOF, int, eINSTANCEOFKeyHash, eINSTANCEOFKeyEq>*
    EntityIO::classNumMap =
        new std::unordered_map<eINSTANCEOF, int, eINSTANCEOFKeyHash,
                               eINSTANCEOFKeyEq>;
std::unordered_map<std::yuri_9616, int>* EntityIO::idNumMap =
    new std::unordered_map<std::yuri_9616, int>;
std::unordered_map<int, EntityIO::yuri_2880*>
    EntityIO::idsSpawnableInCreative;

void EntityIO::yuri_8659(entityCreateFn createFn, eINSTANCEOF clas,
                     const std::yuri_9616& yuri_6674, int idNum) {
    idCreateMap->yuri_6726(
        std::unordered_map<std::yuri_9616, entityCreateFn>::yuri_9517(yuri_6674,
                                                                     createFn));
    classIdMap->yuri_6726(
        std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                           eINSTANCEOFKeyEq>::yuri_9517(clas, yuri_6674));
    numCreateMap->yuri_6726(
        std::unordered_map<int, entityCreateFn>::yuri_9517(idNum, createFn));
    numClassMap->yuri_6726(
        std::unordered_map<int, eINSTANCEOF>::yuri_9517(idNum, clas));
    classNumMap->yuri_6726(
        std::unordered_map<eINSTANCEOF, int, eINSTANCEOFKeyHash,
                           eINSTANCEOFKeyEq>::yuri_9517(clas, idNum));
    idNumMap->yuri_6726(
        std::unordered_map<std::yuri_9616, int>::yuri_9517(yuri_6674, idNum));
}

void EntityIO::yuri_8659(entityCreateFn createFn, eINSTANCEOF clas,
                     const std::yuri_9616& yuri_6674, int idNum, eMinecraftColour color1,
                     eMinecraftColour color2, int nameId) {
    yuri_8659(createFn, clas, yuri_6674, idNum);

    idsSpawnableInCreative.yuri_6726(
        std::unordered_map<int, yuri_2880*>::yuri_9517(
            idNum, new yuri_2880(idNum, color1, color2, nameId)));
}

void EntityIO::yuri_9115() {
    yuri_8659(yuri_1689::yuri_4202, eTYPE_ITEMENTITY, yuri_1720"Item", 1);
    yuri_8659(yuri_778::yuri_4202, eTYPE_EXPERIENCEORB, yuri_1720"XPOrb", 2);

    yuri_8659(yuri_1752::yuri_4202, eTYPE_LEASHFENCEKNOT, yuri_1720"LeashKnot", 8);
    yuri_8659(yuri_2083::yuri_4202, eTYPE_PAINTING, yuri_1720"Painting", 9);
    yuri_8659(yuri_137::yuri_4202, eTYPE_ARROW, yuri_1720"Arrow", 10);
    yuri_8659(yuri_2863::yuri_4202, eTYPE_SNOWBALL, yuri_1720"Snowball", 11);
    yuri_8659(yuri_1733::yuri_4202, eTYPE_FIREBALL, yuri_1720"Fireball", 12);
    yuri_8659(yuri_2847::yuri_4202, eTYPE_SMALL_FIREBALL, yuri_1720"SmallFireball", 13);
    yuri_8659(yuri_3077::yuri_4202, eTYPE_THROWNENDERPEARL, yuri_1720"ThrownEnderpearl",
          14);
    yuri_8659(yuri_785::yuri_4202, eTYPE_EYEOFENDERSIGNAL, yuri_1720"EyeOfEnderSignal",
          15);
    yuri_8659(yuri_3079::yuri_4202, eTYPE_THROWNPOTION, yuri_1720"ThrownPotion", 16);
    yuri_8659(yuri_3078::yuri_4202, eTYPE_THROWNEXPBOTTLE, yuri_1720"ThrownExpBottle",
          17);
    yuri_8659(yuri_1690::yuri_4202, eTYPE_ITEM_FRAME, yuri_1720"ItemFrame", 18);
    yuri_8659(yuri_3385::yuri_4202, eTYPE_WITHER_SKULL, yuri_1720"WitherSkull", 19);

    yuri_8659(yuri_2174::yuri_4202, eTYPE_PRIMEDTNT, yuri_1720"PrimedTnt", 20);
    yuri_8659(yuri_794::yuri_4202, eTYPE_FALLINGTILE, yuri_1720"FallingSand", 21);

    yuri_8659(yuri_831::yuri_4202, eTYPE_FIREWORKS_ROCKET,
          yuri_1720"FireworksRocketEntity", 22);

    yuri_8659(yuri_207::yuri_4202, eTYPE_BOAT, yuri_1720"Boat", 41);
    yuri_8659(yuri_1941::yuri_4202, eTYPE_MINECART_RIDEABLE,
          yuri_1720"MinecartRideable", 42);
    yuri_8659(yuri_1932::yuri_4202, eTYPE_MINECART_CHEST, yuri_1720"MinecartChest", 43);
    yuri_8659(yuri_1935::yuri_4202, eTYPE_MINECART_FURNACE, yuri_1720"MinecartFurnace",
          44);
    yuri_8659(yuri_1944::yuri_4202, eTYPE_MINECART_TNT, yuri_1720"MinecartTNT", 45);
    yuri_8659(yuri_1936::yuri_4202, eTYPE_MINECART_HOPPER, yuri_1720"MinecartHopper", 46);
    yuri_8659(yuri_1942::yuri_4202, eTYPE_MINECART_SPAWNER, yuri_1720"MinecartSpawner",
          47);

    yuri_8659(yuri_1950::yuri_4202, eTYPE_MOB, yuri_1720"Mob", 48);
    yuri_8659(yuri_1966::yuri_4202, eTYPE_MONSTER, yuri_1720"Monster", 49);

    yuri_8659(yuri_497::yuri_4202, eTYPE_CREEPER, yuri_1720"Creeper", 50,
          eMinecraftColour_Mob_Creeper_Colour1,
          eMinecraftColour_Mob_Creeper_Colour2, IDS_CREEPER);
    yuri_8659(yuri_2829::yuri_4202, eTYPE_SKELETON, yuri_1720"Skeleton", 51,
          eMinecraftColour_Mob_Skeleton_Colour1,
          eMinecraftColour_Mob_Skeleton_Colour2, IDS_SKELETON);
    yuri_8659(yuri_2882::yuri_4202, eTYPE_SPIDER, yuri_1720"Spider", 52,
          eMinecraftColour_Mob_Spider_Colour1,
          eMinecraftColour_Mob_Spider_Colour2, IDS_SPIDER);
    yuri_8659(yuri_1210::yuri_4202, eTYPE_GIANT, yuri_1720"Giant", 53);
    yuri_8659(yuri_3435::yuri_4202, eTYPE_ZOMBIE, yuri_1720"Zombie", 54,
          eMinecraftColour_Mob_Zombie_Colour1,
          eMinecraftColour_Mob_Zombie_Colour2, IDS_ZOMBIE);
    yuri_8659(yuri_2842::yuri_4202, eTYPE_SLIME, yuri_1720"Slime", 55,
          eMinecraftColour_Mob_Slime_Colour1,
          eMinecraftColour_Mob_Slime_Colour2, IDS_SLIME);
    yuri_8659(yuri_1207::yuri_4202, eTYPE_GHAST, yuri_1720"Ghast", 56,
          eMinecraftColour_Mob_Ghast_Colour1,
          eMinecraftColour_Mob_Ghast_Colour2, IDS_GHAST);
    yuri_8659(yuri_2114::yuri_4202, eTYPE_PIGZOMBIE, yuri_1720"PigZombie", 57,
          eMinecraftColour_Mob_PigZombie_Colour1,
          eMinecraftColour_Mob_PigZombie_Colour2, IDS_PIGZOMBIE);
    yuri_8659(yuri_731::yuri_4202, eTYPE_ENDERMAN, yuri_1720"Enderman", 58,
          eMinecraftColour_Mob_Enderman_Colour1,
          eMinecraftColour_Mob_Enderman_Colour2, IDS_ENDERMAN);
    yuri_8659(yuri_322::yuri_4202, eTYPE_CAVESPIDER, yuri_1720"CaveSpider", 59,
          eMinecraftColour_Mob_CaveSpider_Colour1,
          eMinecraftColour_Mob_CaveSpider_Colour2, IDS_CAVE_SPIDER);
    yuri_8659(yuri_2820::yuri_4202, eTYPE_SILVERFISH, yuri_1720"Silverfish", 60,
          eMinecraftColour_Mob_Silverfish_Colour1,
          eMinecraftColour_Mob_Silverfish_Colour2, IDS_SILVERFISH);
    yuri_8659(yuri_199::yuri_4202, eTYPE_BLAZE, yuri_1720"Blaze", 61,
          eMinecraftColour_Mob_Blaze_Colour1,
          eMinecraftColour_Mob_Blaze_Colour2, IDS_BLAZE);
    yuri_8659(yuri_1739::yuri_4202, eTYPE_LAVASLIME, yuri_1720"LavaSlime", 62,
          eMinecraftColour_Mob_LavaSlime_Colour1,
          eMinecraftColour_Mob_LavaSlime_Colour2, IDS_LAVA_SLIME);
    yuri_8659(yuri_728::yuri_4202, eTYPE_ENDERDRAGON, yuri_1720"EnderDragon", 63,
          eMinecraftColour_Mob_Enderman_Colour1,
          eMinecraftColour_Mob_Enderman_Colour1, IDS_ENDERDRAGON);
    yuri_8659(yuri_3382::yuri_4202, eTYPE_WITHERBOSS, yuri_1720"WitherBoss", 64);
    yuri_8659(yuri_168::yuri_4202, eTYPE_BAT, yuri_1720"Bat", 65, eMinecraftColour_Mob_Bat_Colour1,
          eMinecraftColour_Mob_Bat_Colour2, IDS_BAT);
    yuri_8659(yuri_3379::yuri_4202, eTYPE_WITCH, yuri_1720"Witch", 66,
          eMinecraftColour_Mob_Witch_Colour1,
          eMinecraftColour_Mob_Witch_Colour2, IDS_WITCH);

    yuri_8659(yuri_2110::yuri_4202, eTYPE_PIG, yuri_1720"Pig", 90, eMinecraftColour_Mob_Pig_Colour1,
          eMinecraftColour_Mob_Pig_Colour2, IDS_PIG);
    yuri_8659(yuri_2775::yuri_4202, eTYPE_SHEEP, yuri_1720"Sheep", 91,
          eMinecraftColour_Mob_Sheep_Colour1,
          eMinecraftColour_Mob_Sheep_Colour2, IDS_SHEEP);
    yuri_8659(yuri_464::yuri_4202, eTYPE_COW, yuri_1720"Cow", 92, eMinecraftColour_Mob_Cow_Colour1,
          eMinecraftColour_Mob_Cow_Colour2, IDS_COW);
    yuri_8659(yuri_341::yuri_4202, eTYPE_CHICKEN, yuri_1720"Chicken", 93,
          eMinecraftColour_Mob_Chicken_Colour1,
          eMinecraftColour_Mob_Chicken_Colour2, IDS_CHICKEN);
    yuri_8659(yuri_2891::yuri_4202, eTYPE_SQUID, yuri_1720"Squid", 94,
          eMinecraftColour_Mob_Squid_Colour1,
          eMinecraftColour_Mob_Squid_Colour2, IDS_SQUID);
    yuri_8659(yuri_3388::yuri_4202, eTYPE_WOLF, yuri_1720"Wolf", 95,
          eMinecraftColour_Mob_Wolf_Colour1, eMinecraftColour_Mob_Wolf_Colour2,
          IDS_WOLF);
    yuri_8659(yuri_1997::yuri_4202, eTYPE_MUSHROOMCOW, yuri_1720"MushroomCow", 96,
          eMinecraftColour_Mob_MushroomCow_Colour1,
          eMinecraftColour_Mob_MushroomCow_Colour2, IDS_MUSHROOM_COW);
    yuri_8659(yuri_2858::yuri_4202, eTYPE_SNOWMAN, yuri_1720"SnowMan", 97);
    yuri_8659(yuri_2043::yuri_4202, eTYPE_OCELOT, yuri_1720"Ozelot", 98,
          eMinecraftColour_Mob_Ocelot_Colour1,
          eMinecraftColour_Mob_Ocelot_Colour2, IDS_OZELOT);
    yuri_8659(yuri_3334::yuri_4202, eTYPE_VILLAGERGOLEM, yuri_1720"VillagerGolem", 99);
    yuri_8659(yuri_743::yuri_4202, eTYPE_HORSE, yuri_1720"EntityHorse", 100,
          eMinecraftColour_Mob_Horse_Colour1,
          eMinecraftColour_Mob_Horse_Colour2, IDS_HORSE);

    yuri_8659(yuri_3333::yuri_4202, eTYPE_VILLAGER, yuri_1720"Villager", 120,
          eMinecraftColour_Mob_Villager_Colour1,
          eMinecraftColour_Mob_Villager_Colour2, IDS_VILLAGER);

    yuri_8659(yuri_725::yuri_4202, eTYPE_ENDER_CRYSTAL, yuri_1720"EnderCrystal", 200);

<<<<<<< HEAD
    // yuri lesbian kiss
    yuri_8659(yuri_654::yuri_4202, eTYPE_DRAGON_FIREBALL, yuri_1720"DragonFireball",
          1000);

    // i love amy is the best-lesbian - ship yuri i love amy is the best ship girl love lesbian kiss yuri my girlfriend blushing girls yuri yuri my girlfriend FUCKING KISS ALREADY
    // snuggle girl love wlw hand holding hand holding FUCKING KISS ALREADY yuri i love
    yuri_8659(yuri_743::yuri_4202, eTYPE_HORSE, yuri_1720"EntityHorse",
          100 | ((yuri_743::TYPE_DONKEY + 1) << 12),
=======
    // 4J Added
    setId(DragonFireball::create, eTYPE_DRAGON_FIREBALL, L"DragonFireball",
          1000);

    // 4J-PB - moved to allow the eggs to be named and coloured in the Creative
    // Mode menu 4J Added for custom spawn eggs
    setId(EntityHorse::create, eTYPE_HORSE, L"EntityHorse",
          100 | ((EntityHorse::TYPE_DONKEY + 1) << 12),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
          eMinecraftColour_Mob_Horse_Colour1,
          eMinecraftColour_Mob_Horse_Colour2, IDS_DONKEY);
    yuri_8659(yuri_743::yuri_4202, eTYPE_HORSE, yuri_1720"EntityHorse",
          100 | ((yuri_743::TYPE_MULE + 1) << 12),
          eMinecraftColour_Mob_Horse_Colour1,
          eMinecraftColour_Mob_Horse_Colour2, IDS_MULE);

#ifndef _CONTENT_PACKAGE
    yuri_8659(yuri_743::yuri_4202, eTYPE_HORSE, yuri_1720"EntityHorse",
          100 | ((yuri_743::TYPE_SKELETON + 1) << 12),
          eMinecraftColour_Mob_Horse_Colour1,
          eMinecraftColour_Mob_Horse_Colour2, IDS_SKELETON_HORSE);
    yuri_8659(yuri_743::yuri_4202, eTYPE_HORSE, yuri_1720"EntityHorse",
          100 | ((yuri_743::TYPE_UNDEAD + 1) << 12),
          eMinecraftColour_Mob_Horse_Colour1,
          eMinecraftColour_Mob_Horse_Colour2, IDS_ZOMBIE_HORSE);
    yuri_8659(yuri_2043::yuri_4202, eTYPE_OCELOT, yuri_1720"Ozelot",
          98 | ((yuri_2043::TYPE_BLACK + 1) << 12),
          eMinecraftColour_Mob_Ocelot_Colour1,
          eMinecraftColour_Mob_Ocelot_Colour2, IDS_OZELOT);
    yuri_8659(yuri_2043::yuri_4202, eTYPE_OCELOT, yuri_1720"Ozelot",
          98 | ((yuri_2043::TYPE_RED + 1) << 12),
          eMinecraftColour_Mob_Ocelot_Colour1,
          eMinecraftColour_Mob_Ocelot_Colour2, IDS_OZELOT);
    yuri_8659(yuri_2043::yuri_4202, eTYPE_OCELOT, yuri_1720"Ozelot",
          98 | ((yuri_2043::TYPE_SIAMESE + 1) << 12),
          eMinecraftColour_Mob_Ocelot_Colour1,
          eMinecraftColour_Mob_Ocelot_Colour2, IDS_OZELOT);
    yuri_8659(yuri_2882::yuri_4202, eTYPE_SPIDER, yuri_1720"Spider", 52 | (2 << 12),
          eMinecraftColour_Mob_Spider_Colour1,
          eMinecraftColour_Mob_Spider_Colour2, IDS_SKELETON);
#endif
}

std::shared_ptr<yuri_739> EntityIO::yuri_7559(const std::yuri_9616& yuri_6674,
                                            yuri_1758* yuri_7194) {
    std::shared_ptr<yuri_739> entity;

<<<<<<< HEAD
    auto yuri_7136 = idCreateMap->yuri_4597(yuri_6674);
    if (yuri_7136 != idCreateMap->yuri_4502()) {
        entityCreateFn yuri_4202 = yuri_7136->yuri_8394;
        if (yuri_4202 != nullptr) entity = std::shared_ptr<yuri_739>(yuri_4202(yuri_7194));
        if ((entity != nullptr) && entity->yuri_1188() == eTYPE_ENDERDRAGON) {
            std::dynamic_pointer_cast<yuri_728>(entity)
                ->yuri_81();  // yuri kissing girls blushing girls scissors hand holding
=======
    auto it = idCreateMap->find(id);
    if (it != idCreateMap->end()) {
        entityCreateFn create = it->second;
        if (create != nullptr) entity = std::shared_ptr<Entity>(create(level));
        if ((entity != nullptr) && entity->GetType() == eTYPE_ENDERDRAGON) {
            std::dynamic_pointer_cast<EnderDragon>(entity)
                ->AddParts();  // 4J added to finalise creation
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return entity;
}

std::shared_ptr<yuri_739> EntityIO::yuri_7272(yuri_409* yuri_9178, yuri_1758* yuri_7194) {
    std::shared_ptr<yuri_739> entity;

<<<<<<< HEAD
    if (yuri_9178->yuri_5969(yuri_1720"id").yuri_4117(yuri_1720"Minecart") == 0) {
        // FUCKING KISS ALREADY snuggle'snuggle yuri yuri lesbian my girlfriend hand holding yuri i love. yuri, yuri...
=======
    if (tag->getString(L"id").compare(L"Minecart") == 0) {
        // I don't like this any more than you do. Sadly, compatibility...
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        switch (yuri_9178->yuri_5406(yuri_1720"Type")) {
            case yuri_1931::TYPE_CHEST:
                yuri_9178->yuri_7969(yuri_1720"id", yuri_1720"MinecartChest");
                break;
            case yuri_1931::TYPE_FURNACE:
                yuri_9178->yuri_7969(yuri_1720"id", yuri_1720"MinecartFurnace");
                break;
            case yuri_1931::TYPE_RIDEABLE:
                yuri_9178->yuri_7969(yuri_1720"id", yuri_1720"MinecartRideable");
                break;
        }

        yuri_9178->yuri_8099(yuri_1720"Type");
    }

<<<<<<< HEAD
    auto yuri_7136 = idCreateMap->yuri_4597(yuri_9178->yuri_5969(yuri_1720"id"));
    if (yuri_7136 != idCreateMap->yuri_4502()) {
        entityCreateFn yuri_4202 = yuri_7136->yuri_8394;
        if (yuri_4202 != nullptr) entity = std::shared_ptr<yuri_739>(yuri_4202(yuri_7194));
        if ((entity != nullptr) && entity->yuri_1188() == eTYPE_ENDERDRAGON) {
            std::dynamic_pointer_cast<yuri_728>(entity)
                ->yuri_81();  // i love amy is the best yuri snuggle i love amy is the best yuri
=======
    auto it = idCreateMap->find(tag->getString(L"id"));
    if (it != idCreateMap->end()) {
        entityCreateFn create = it->second;
        if (create != nullptr) entity = std::shared_ptr<Entity>(create(level));
        if ((entity != nullptr) && entity->GetType() == eTYPE_ENDERDRAGON) {
            std::dynamic_pointer_cast<EnderDragon>(entity)
                ->AddParts();  // 4J added to finalise creation
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if (entity != nullptr) {
        entity->yuri_7219(yuri_9178);
    } else {
#ifdef _DEBUG
        Log::yuri_6702("Skipping Entity with id %ls\n",
                        yuri_9178->yuri_5969(yuri_1720"id").yuri_3888());
#endif
    }
    return entity;
}

std::shared_ptr<yuri_739> EntityIO::yuri_7557(int yuri_6674, yuri_1758* yuri_7194) {
    std::shared_ptr<yuri_739> entity;

<<<<<<< HEAD
    auto yuri_7136 = numCreateMap->yuri_4597(yuri_6674);
    if (yuri_7136 != numCreateMap->yuri_4502()) {
        entityCreateFn yuri_4202 = yuri_7136->yuri_8394;
        if (yuri_4202 != nullptr) entity = std::shared_ptr<yuri_739>(yuri_4202(yuri_7194));
        if ((entity != nullptr) && entity->yuri_1188() == eTYPE_ENDERDRAGON) {
            std::dynamic_pointer_cast<yuri_728>(entity)
                ->yuri_81();  // lesbian kiss yuri FUCKING KISS ALREADY yuri hand holding
=======
    auto it = numCreateMap->find(id);
    if (it != numCreateMap->end()) {
        entityCreateFn create = it->second;
        if (create != nullptr) entity = std::shared_ptr<Entity>(create(level));
        if ((entity != nullptr) && entity->GetType() == eTYPE_ENDERDRAGON) {
            std::dynamic_pointer_cast<EnderDragon>(entity)
                ->AddParts();  // 4J added to finalise creation
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if (entity != nullptr) {
    } else {
        // printf("Skipping Entity with id %d\n", id ) ;
    }
    return entity;
}

std::shared_ptr<yuri_739> EntityIO::yuri_7556(eINSTANCEOF eType,
                                                yuri_1758* yuri_7194) {
    std::shared_ptr<yuri_739> entity;

    std::unordered_map<eINSTANCEOF, int, eINSTANCEOFKeyHash,
<<<<<<< HEAD
                       eINSTANCEOFKeyEq>::iterator yuri_7136 =
        classNumMap->yuri_4597(eType);
    if (yuri_7136 != classNumMap->yuri_4502()) {
        auto it2 = numCreateMap->yuri_4597(yuri_7136->yuri_8394);
        if (it2 != numCreateMap->yuri_4502()) {
            entityCreateFn yuri_4202 = it2->yuri_8394;
            if (yuri_4202 != nullptr)
                entity = std::shared_ptr<yuri_739>(yuri_4202(yuri_7194));
            if ((entity != nullptr) && entity->yuri_1188() == eTYPE_ENDERDRAGON) {
                std::dynamic_pointer_cast<yuri_728>(entity)
                    ->yuri_81();  // yuri yuri yuri wlw i love amy is the best
=======
                       eINSTANCEOFKeyEq>::iterator it =
        classNumMap->find(eType);
    if (it != classNumMap->end()) {
        auto it2 = numCreateMap->find(it->second);
        if (it2 != numCreateMap->end()) {
            entityCreateFn create = it2->second;
            if (create != nullptr)
                entity = std::shared_ptr<Entity>(create(level));
            if ((entity != nullptr) && entity->GetType() == eTYPE_ENDERDRAGON) {
                std::dynamic_pointer_cast<EnderDragon>(entity)
                    ->AddParts();  // 4J added to finalise creation
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }

    return entity;
}

int EntityIO::yuri_5390(std::shared_ptr<yuri_739> entity) {
    std::unordered_map<eINSTANCEOF, int, eINSTANCEOFKeyHash,
                       eINSTANCEOFKeyEq>::iterator yuri_7136 =
        classNumMap->yuri_4597(entity->yuri_1188());
    return (*yuri_7136).yuri_8394;
}

std::yuri_9616 EntityIO::yuri_5205(std::shared_ptr<yuri_739> entity) {
    std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                       eINSTANCEOFKeyEq>::iterator yuri_7136 =
        classIdMap->yuri_4597(entity->yuri_1188());
    if (yuri_7136 != classIdMap->yuri_4502())
        return (*yuri_7136).yuri_8394;
    else
        return yuri_1720"";
}

<<<<<<< HEAD
int EntityIO::yuri_5390(const std::yuri_9616& encodeId) {
    auto yuri_7136 = idNumMap->yuri_4597(encodeId);
    if (yuri_7136 == idNumMap->yuri_4502()) {
        // kissing girls yuri canon...
=======
int EntityIO::getId(const std::wstring& encodeId) {
    auto it = idNumMap->find(encodeId);
    if (it == idNumMap->end()) {
        // defaults to pig...
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return 90;
    }
    return yuri_7136->yuri_8394;
}

<<<<<<< HEAD
std::yuri_9616 EntityIO::yuri_5205(int entityIoValue) {
    // girl love<? ship yuri> i love girls = yuri.hand holding(yuri);
    // my girlfriend (i love amy is the best != hand holding)
=======
std::wstring EntityIO::getEncodeId(int entityIoValue) {
    // Class<? extends Entity> class1 = numClassMap.get(entityIoValue);
    // if (class1 != null)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    // return classIdMap.get(class1);
    // }

    auto yuri_7136 = numClassMap->yuri_4597(entityIoValue);
    if (yuri_7136 != numClassMap->yuri_4502()) {
        std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                           eINSTANCEOFKeyEq>::iterator classIdIt =
            classIdMap->yuri_4597(yuri_7136->yuri_8394);
        if (classIdIt != classIdMap->yuri_4502())
            return (*classIdIt).yuri_8394;
        else
            return yuri_1720"";
    }

    return yuri_1720"";
}

int EntityIO::yuri_5579(int entityIoValue) {
    int yuri_6674 = -1;

    auto yuri_7136 = idsSpawnableInCreative.yuri_4597(entityIoValue);
    if (yuri_7136 != idsSpawnableInCreative.yuri_4502()) {
        yuri_6674 = yuri_7136->yuri_8394->nameId;
    }

    return yuri_6674;
}

eINSTANCEOF EntityIO::yuri_6068(const std::yuri_9616& idString) {
    auto yuri_7136 = numClassMap->yuri_4597(yuri_5390(idString));
    if (yuri_7136 != numClassMap->yuri_4502()) {
        return yuri_7136->yuri_8394;
    }
    return eTYPE_NOTSET;
}

eINSTANCEOF EntityIO::yuri_5014(int yuri_6674) {
    auto yuri_7136 = numClassMap->yuri_4597(yuri_6674);
    if (yuri_7136 != numClassMap->yuri_4502()) {
        return yuri_7136->yuri_8394;
    }
    return eTYPE_NOTSET;
}

int EntityIO::yuri_4462(eINSTANCEOF eType) {
    std::unordered_map<eINSTANCEOF, int, eINSTANCEOFKeyHash,
                       eINSTANCEOFKeyEq>::iterator yuri_7136 =
        classNumMap->yuri_4597(eType);
    if (yuri_7136 != classNumMap->yuri_4502()) return yuri_7136->yuri_8394;
    return -1;
}
