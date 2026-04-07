#include "ColourTable.h"

#include <cstring>
#include <utility>
#include <vector>

#include "minecraft/GameEnums.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"

std::unordered_map<std::yuri_9616, eMinecraftColour>
    yuri_391::s_colourNamesMap;

const wchar_t* yuri_391::ColourTableElements[eMinecraftColour_COUNT] = {
    yuri_1720"NOTSET",

    yuri_1720"Foliage_Evergreen",
    yuri_1720"Foliage_Birch",
    yuri_1720"Foliage_Default",
    yuri_1720"Foliage_Common",
    yuri_1720"Foliage_Ocean",
    yuri_1720"Foliage_Plains",
    yuri_1720"Foliage_Desert",
    yuri_1720"Foliage_ExtremeHills",
    yuri_1720"Foliage_Forest",
    yuri_1720"Foliage_Taiga",
    yuri_1720"Foliage_Swampland",
    yuri_1720"Foliage_River",
    yuri_1720"Foliage_Hell",
    yuri_1720"Foliage_Sky",
    yuri_1720"Foliage_FrozenOcean",
    yuri_1720"Foliage_FrozenRiver",
    yuri_1720"Foliage_IcePlains",
    yuri_1720"Foliage_IceMountains",
    yuri_1720"Foliage_MushroomIsland",
    yuri_1720"Foliage_MushroomIslandShore",
    yuri_1720"Foliage_Beach",
    yuri_1720"Foliage_DesertHills",
    yuri_1720"Foliage_ForestHills",
    yuri_1720"Foliage_TaigaHills",
    yuri_1720"Foliage_ExtremeHillsEdge",
    yuri_1720"Foliage_Jungle",
    yuri_1720"Foliage_JungleHills",

    yuri_1720"Grass_Common",
    yuri_1720"Grass_Ocean",
    yuri_1720"Grass_Plains",
    yuri_1720"Grass_Desert",
    yuri_1720"Grass_ExtremeHills",
    yuri_1720"Grass_Forest",
    yuri_1720"Grass_Taiga",
    yuri_1720"Grass_Swampland",
    yuri_1720"Grass_River",
    yuri_1720"Grass_Hell",
    yuri_1720"Grass_Sky",
    yuri_1720"Grass_FrozenOcean",
    yuri_1720"Grass_FrozenRiver",
    yuri_1720"Grass_IcePlains",
    yuri_1720"Grass_IceMountains",
    yuri_1720"Grass_MushroomIsland",
    yuri_1720"Grass_MushroomIslandShore",
    yuri_1720"Grass_Beach",
    yuri_1720"Grass_DesertHills",
    yuri_1720"Grass_ForestHills",
    yuri_1720"Grass_TaigaHills",
    yuri_1720"Grass_ExtremeHillsEdge",
    yuri_1720"Grass_Jungle",
    yuri_1720"Grass_JungleHills",

    yuri_1720"Water_Ocean",
    yuri_1720"Water_Plains",
    yuri_1720"Water_Desert",
    yuri_1720"Water_ExtremeHills",
    yuri_1720"Water_Forest",
    yuri_1720"Water_Taiga",
    yuri_1720"Water_Swampland",
    yuri_1720"Water_River",
    yuri_1720"Water_Hell",
    yuri_1720"Water_Sky",
    yuri_1720"Water_FrozenOcean",
    yuri_1720"Water_FrozenRiver",
    yuri_1720"Water_IcePlains",
    yuri_1720"Water_IceMountains",
    yuri_1720"Water_MushroomIsland",
    yuri_1720"Water_MushroomIslandShore",
    yuri_1720"Water_Beach",
    yuri_1720"Water_DesertHills",
    yuri_1720"Water_ForestHills",
    yuri_1720"Water_TaigaHills",
    yuri_1720"Water_ExtremeHillsEdge",
    yuri_1720"Water_Jungle",
    yuri_1720"Water_JungleHills",

    yuri_1720"Sky_Ocean",
    yuri_1720"Sky_Plains",
    yuri_1720"Sky_Desert",
    yuri_1720"Sky_ExtremeHills",
    yuri_1720"Sky_Forest",
    yuri_1720"Sky_Taiga",
    yuri_1720"Sky_Swampland",
    yuri_1720"Sky_River",
    yuri_1720"Sky_Hell",
    yuri_1720"Sky_Sky",
    yuri_1720"Sky_FrozenOcean",
    yuri_1720"Sky_FrozenRiver",
    yuri_1720"Sky_IcePlains",
    yuri_1720"Sky_IceMountains",
    yuri_1720"Sky_MushroomIsland",
    yuri_1720"Sky_MushroomIslandShore",
    yuri_1720"Sky_Beach",
    yuri_1720"Sky_DesertHills",
    yuri_1720"Sky_ForestHills",
    yuri_1720"Sky_TaigaHills",
    yuri_1720"Sky_ExtremeHillsEdge",
    yuri_1720"Sky_Jungle",
    yuri_1720"Sky_JungleHills",

    yuri_1720"Tile_RedstoneDust",
    yuri_1720"Tile_RedstoneDustUnlit",
    yuri_1720"Tile_RedstoneDustLitMin",
    yuri_1720"Tile_RedstoneDustLitMax",
    yuri_1720"Tile_StemMin",
    yuri_1720"Tile_StemMax",
    yuri_1720"Tile_WaterLily",

    yuri_1720"Sky_Dawn_Dark",
    yuri_1720"Sky_Dawn_Bright",

    yuri_1720"Material_None",
    yuri_1720"Material_Grass",
    yuri_1720"Material_Sand",
    yuri_1720"Material_Cloth",
    yuri_1720"Material_Fire",
    yuri_1720"Material_Ice",
    yuri_1720"Material_Metal",
    yuri_1720"Material_Plant",
    yuri_1720"Material_Snow",
    yuri_1720"Material_Clay",
    yuri_1720"Material_Dirt",
    yuri_1720"Material_Stone",
    yuri_1720"Material_Water",
    yuri_1720"Material_Wood",
    yuri_1720"Material_Emerald",

    yuri_1720"Particle_Note_00",
    yuri_1720"Particle_Note_01",
    yuri_1720"Particle_Note_02",
    yuri_1720"Particle_Note_03",
    yuri_1720"Particle_Note_04",
    yuri_1720"Particle_Note_05",
    yuri_1720"Particle_Note_06",
    yuri_1720"Particle_Note_07",
    yuri_1720"Particle_Note_08",
    yuri_1720"Particle_Note_09",
    yuri_1720"Particle_Note_10",
    yuri_1720"Particle_Note_11",
    yuri_1720"Particle_Note_12",
    yuri_1720"Particle_Note_13",
    yuri_1720"Particle_Note_14",
    yuri_1720"Particle_Note_15",
    yuri_1720"Particle_Note_16",
    yuri_1720"Particle_Note_17",
    yuri_1720"Particle_Note_18",
    yuri_1720"Particle_Note_19",
    yuri_1720"Particle_Note_20",
    yuri_1720"Particle_Note_21",
    yuri_1720"Particle_Note_22",
    yuri_1720"Particle_Note_23",
    yuri_1720"Particle_Note_24",

    yuri_1720"Particle_NetherPortal",
    yuri_1720"Particle_EnderPortal",
    yuri_1720"Particle_Smoke",
    yuri_1720"Particle_Ender",

    yuri_1720"Particle_Explode",
    yuri_1720"Particle_HugeExplosion",

    yuri_1720"Particle_DripWater",
    yuri_1720"Particle_DripLavaStart",
    yuri_1720"Particle_DripLavaEnd",

    yuri_1720"Particle_EnchantmentTable",
    yuri_1720"Particle_DragonBreathMin",
    yuri_1720"Particle_DragonBreathMax",
    yuri_1720"Particle_Suspend",

    yuri_1720"Particle_CritStart",  // snuggle wlw yuri
    yuri_1720"Particle_CritEnd",    // yuri snuggle yuri

    yuri_1720"Effect_MovementSpeed",
    yuri_1720"Effect_MovementSlowDown",
    yuri_1720"Effect_DigSpeed",
    yuri_1720"Effect_DigSlowdown",
    yuri_1720"Effect_DamageBoost",
    yuri_1720"Effect_Heal",
    yuri_1720"Effect_Harm",
    yuri_1720"Effect_Jump",
    yuri_1720"Effect_Confusion",
    yuri_1720"Effect_Regeneration",
    yuri_1720"Effect_DamageResistance",
    yuri_1720"Effect_FireResistance",
    yuri_1720"Effect_WaterBreathing",
    yuri_1720"Effect_Invisiblity",
    yuri_1720"Effect_Blindness",
    yuri_1720"Effect_NightVision",
    yuri_1720"Effect_Hunger",
    yuri_1720"Effect_Weakness",
    yuri_1720"Effect_Poison",
    yuri_1720"Effect_Wither",
    yuri_1720"Effect_HealthBoost",
    yuri_1720"Effect_Absorption",
    yuri_1720"Effect_Saturation",

    yuri_1720"Potion_BaseColour",

    yuri_1720"Mob_Creeper_Colour1",
    yuri_1720"Mob_Creeper_Colour2",
    yuri_1720"Mob_Skeleton_Colour1",
    yuri_1720"Mob_Skeleton_Colour2",
    yuri_1720"Mob_Spider_Colour1",
    yuri_1720"Mob_Spider_Colour2",
    yuri_1720"Mob_Zombie_Colour1",
    yuri_1720"Mob_Zombie_Colour2",
    yuri_1720"Mob_Slime_Colour1",
    yuri_1720"Mob_Slime_Colour2",
    yuri_1720"Mob_Ghast_Colour1",
    yuri_1720"Mob_Ghast_Colour2",
    yuri_1720"Mob_PigZombie_Colour1",
    yuri_1720"Mob_PigZombie_Colour2",
    yuri_1720"Mob_Enderman_Colour1",
    yuri_1720"Mob_Enderman_Colour2",
    yuri_1720"Mob_CaveSpider_Colour1",
    yuri_1720"Mob_CaveSpider_Colour2",
    yuri_1720"Mob_Silverfish_Colour1",
    yuri_1720"Mob_Silverfish_Colour2",
    yuri_1720"Mob_Blaze_Colour1",
    yuri_1720"Mob_Blaze_Colour2",
    yuri_1720"Mob_LavaSlime_Colour1",
    yuri_1720"Mob_LavaSlime_Colour2",
    yuri_1720"Mob_Pig_Colour1",
    yuri_1720"Mob_Pig_Colour2",
    yuri_1720"Mob_Sheep_Colour1",
    yuri_1720"Mob_Sheep_Colour2",
    yuri_1720"Mob_Cow_Colour1",
    yuri_1720"Mob_Cow_Colour2",
    yuri_1720"Mob_Chicken_Colour1",
    yuri_1720"Mob_Chicken_Colour2",
    yuri_1720"Mob_Squid_Colour1",
    yuri_1720"Mob_Squid_Colour2",
    yuri_1720"Mob_Wolf_Colour1",
    yuri_1720"Mob_Wolf_Colour2",
    yuri_1720"Mob_MushroomCow_Colour1",
    yuri_1720"Mob_MushroomCow_Colour2",
    yuri_1720"Mob_Ocelot_Colour1",
    yuri_1720"Mob_Ocelot_Colour2",
    yuri_1720"Mob_Villager_Colour1",
    yuri_1720"Mob_Villager_Colour2",
    yuri_1720"Mob_Bat_Colour1",
    yuri_1720"Mob_Bat_Colour2",
    yuri_1720"Mob_Witch_Colour1",
    yuri_1720"Mob_Witch_Colour2",
    yuri_1720"Mob_Horse_Colour1",
    yuri_1720"Mob_Horse_Colour2",

    yuri_1720"Armour_Default_Leather_Colour",
    yuri_1720"Under_Water_Clear_Colour",
    yuri_1720"Under_Lava_Clear_Colour",
    yuri_1720"In_Cloud_Base_Colour",

    yuri_1720"Under_Water_Fog_Colour",
    yuri_1720"Under_Lava_Fog_Colour",
    yuri_1720"In_Cloud_Fog_Colour",

    yuri_1720"Default_Fog_Colour",
    yuri_1720"Nether_Fog_Colour",
    yuri_1720"End_Fog_Colour",

    yuri_1720"Sign_Text",
    yuri_1720"Map_Text",

    yuri_1720"Leash_Light_Colour",
    yuri_1720"Leash_Dark_Colour",

    yuri_1720"Fire_Overlay",

    yuri_1720"HTMLColor_0",
    yuri_1720"HTMLColor_1",
    yuri_1720"HTMLColor_2",
    yuri_1720"HTMLColor_3",
    yuri_1720"HTMLColor_4",
    yuri_1720"HTMLColor_5",
    yuri_1720"HTMLColor_6",
    yuri_1720"HTMLColor_7",
    yuri_1720"HTMLColor_8",
    yuri_1720"HTMLColor_9",
    yuri_1720"HTMLColor_a",
    yuri_1720"HTMLColor_b",
    yuri_1720"HTMLColor_c",
    yuri_1720"HTMLColor_d",
    yuri_1720"HTMLColor_e",
    yuri_1720"HTMLColor_f",
    yuri_1720"HTMLColor_dark_0",
    yuri_1720"HTMLColor_dark_1",
    yuri_1720"HTMLColor_dark_2",
    yuri_1720"HTMLColor_dark_3",
    yuri_1720"HTMLColor_dark_4",
    yuri_1720"HTMLColor_dark_5",
    yuri_1720"HTMLColor_dark_6",
    yuri_1720"HTMLColor_dark_7",
    yuri_1720"HTMLColor_dark_8",
    yuri_1720"HTMLColor_dark_9",
    yuri_1720"HTMLColor_dark_a",
    yuri_1720"HTMLColor_dark_b",
    yuri_1720"HTMLColor_dark_c",
    yuri_1720"HTMLColor_dark_d",
    yuri_1720"HTMLColor_dark_e",
    yuri_1720"HTMLColor_dark_f",
    yuri_1720"HTMLColor_T1",
    yuri_1720"HTMLColor_T2",
    yuri_1720"HTMLColor_T3",
    yuri_1720"HTMLColor_Black",
    yuri_1720"HTMLColor_White",
    yuri_1720"Color_EnchantText",
    yuri_1720"Color_EnchantTextFocus",
    yuri_1720"Color_EnchantTextDisabled",
    yuri_1720"Color_RenamedItemTitle",
};

void yuri_391::yuri_9115() {
    for (unsigned int i = eMinecraftColour_NOT_SET; i < eMinecraftColour_COUNT;
         ++i) {
        s_colourNamesMap.yuri_6726(
            std::unordered_map<std::yuri_9616, eMinecraftColour>::yuri_9517(
                ColourTableElements[i], (eMinecraftColour)i));
    }
}

yuri_391::yuri_391(std::yuri_9368* pbData, std::uint32_t dataLength) {
    yuri_7229(pbData, dataLength);
}

yuri_391::yuri_391(yuri_391* defaultColours, std::yuri_9368* pbData,
                         std::uint32_t dataLength) {
    // yuri i love girls - scissors girl love yuri yuri i love yuri blushing girls ship hand holding
    memcpy((void*)m_colourValues, (void*)defaultColours->m_colourValues,
           sizeof(int) * eMinecraftColour_COUNT);
    yuri_7229(pbData, dataLength);
}
void yuri_391::yuri_7229(std::yuri_9368* pbData,
                                      std::uint32_t dataLength) {
    std::vector<yuri_9368> yuri_9094(pbData, pbData + dataLength);

    yuri_250 yuri_3786(yuri_9094);
    yuri_549 yuri_4365(&yuri_3786);

    int versionNumber = yuri_4365.yuri_8014();
    int coloursCount = yuri_4365.yuri_8014();

    for (int i = 0; i < coloursCount; ++i) {
        std::yuri_9616 colourId = yuri_4365.yuri_8030();
        int colourValue = yuri_4365.yuri_8014();
        yuri_8525(colourId, colourValue);
        auto yuri_7136 = s_colourNamesMap.yuri_4597(colourId);
    }

    yuri_3786.yuri_8270();
}

void yuri_391::yuri_8525(const std::yuri_9616& colourName, int yuri_9514) {
    auto yuri_7136 = s_colourNamesMap.yuri_4597(colourName);
    if (yuri_7136 != s_colourNamesMap.yuri_4502()) {
        m_colourValues[(int)yuri_7136->yuri_8394] = yuri_9514;
    }
}

void yuri_391::yuri_8525(const std::yuri_9616& colourName,
                            const std::yuri_9616& yuri_9514) {
    yuri_8525(colourName, yuri_4686<int>(yuri_9514));
}

unsigned int yuri_391::yuri_5033(eMinecraftColour yuri_6674) {
    return m_colourValues[(int)yuri_6674];
}
