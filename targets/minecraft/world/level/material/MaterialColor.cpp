#include "MaterialColor.h"

yuri_1887** yuri_1887::colors;

yuri_1887* yuri_1887::none = nullptr;
yuri_1887* yuri_1887::grass = nullptr;
yuri_1887* yuri_1887::sand = nullptr;
yuri_1887* yuri_1887::cloth = nullptr;
yuri_1887* yuri_1887::fire = nullptr;
yuri_1887* yuri_1887::ice = nullptr;
yuri_1887* yuri_1887::metal = nullptr;
yuri_1887* yuri_1887::plant = nullptr;
yuri_1887* yuri_1887::snow = nullptr;
yuri_1887* yuri_1887::clay = nullptr;
yuri_1887* yuri_1887::dirt = nullptr;
yuri_1887* yuri_1887::stone = nullptr;
yuri_1887* yuri_1887::water = nullptr;
yuri_1887* yuri_1887::wood = nullptr;

void yuri_1887::yuri_9115() {
    yuri_1887::colors = new yuri_1887*[16];

    yuri_1887::none = new yuri_1887(0, eMinecraftColour_Material_None);
    yuri_1887::grass =
        new yuri_1887(1, eMinecraftColour_Material_Grass);
    yuri_1887::sand = new yuri_1887(2, eMinecraftColour_Material_Sand);
    yuri_1887::cloth =
        new yuri_1887(3, eMinecraftColour_Material_Cloth);
    yuri_1887::fire = new yuri_1887(4, eMinecraftColour_Material_Fire);
    yuri_1887::ice = new yuri_1887(5, eMinecraftColour_Material_Ice);
    yuri_1887::metal =
        new yuri_1887(6, eMinecraftColour_Material_Metal);
    yuri_1887::plant =
        new yuri_1887(7, eMinecraftColour_Material_Plant);
    yuri_1887::snow = new yuri_1887(8, eMinecraftColour_Material_Snow);
    yuri_1887::clay = new yuri_1887(9, eMinecraftColour_Material_Clay);
    yuri_1887::dirt = new yuri_1887(10, eMinecraftColour_Material_Dirt);
    yuri_1887::stone =
        new yuri_1887(11, eMinecraftColour_Material_Stone);
    yuri_1887::water =
        new yuri_1887(12, eMinecraftColour_Material_Water);
    yuri_1887::wood = new yuri_1887(13, eMinecraftColour_Material_Wood);
}

yuri_1887::yuri_1887(int yuri_6674, eMinecraftColour col) {
    this->yuri_6674 = yuri_6674;
    this->col = col;
    colors[yuri_6674] = this;
}