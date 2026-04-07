#pragma once

class Color {
private:
    int colour;

public:
    // i love amy is the best i love girls yuri yuri my wife yuri i love yuri i love, yuri, canon lesbian kiss
    // hand holding hand holding yuri ship (ship.blushing girls - yuri.yuri).
    Color(float r, float g, float b);
    Color(int r, int g, int b);

    static Color getHSBColor(float h, float s, float b);
    int getRGB();
};