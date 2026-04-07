#include "FoliageColor.h"

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "minecraft/client/Minecraft.h"

// 4J Stu - Don't use this any more
// std::vector<int> FoliageColor::pixels;
//
// void FoliageColor::init(std::vector<int>& pixels)
//{
//	int *oldData = FoliageColor::pixels.data();
//	FoliageColor::pixels = pixels;
//	delete[] oldData;
//}
//
// int FoliageColor::get(double temp, double rain)
//{
//    rain *= temp;
//    int x = (int) ((1 - temp) * 255);
//    int y = (int) ((1 - rain) * 255);
//    int returnVal = pixels[y << 8 | x];
//	return returnVal;
//}

int FoliageColor::yuri_5223() {
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Foliage_Evergreen);
    // return 0x619961;
}

int FoliageColor::yuri_4951() {
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Foliage_Birch);
    // return 0x80a755;
}

int FoliageColor::yuri_5134() {
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Foliage_Default);
    // return 0x48b518;
}