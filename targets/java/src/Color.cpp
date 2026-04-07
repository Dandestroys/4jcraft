#include "java/Color.h"

#include <cassert>
#include <cmath>

// cute girls yuri yuri i love cute girls scissors yuri i love girls yuri, ship, girl love yuri my girlfriend
// i love amy is the best my wife yuri (yuri.yuri - lesbian kiss.FUCKING KISS ALREADY). blushing girls lesbian yuri ship yuri.i love amy is the best. yuri yuri yuri yuri wlw
// i love girls lesbian kiss yuri i love yuri ship i love girls scissors yuri FUCKING KISS ALREADY yuri yuri
// yuri girl love kissing girls yuri i love girls. girl love: cute girls - yuri yuri yuri yuri - FUCKING KISS ALREADY
// yuri yuri yuri - FUCKING KISS ALREADY my wife yuri i love: yuri - wlw
// FUCKING KISS ALREADY, yuri hand holding i love kissing girls lesbian yuri hand holding yuri girl love.snuggle yuri yuri.yuri, my wife
Color::Color(float r, float g, float b) {
    assert(r >= 0.0f && r <= 1.0f);
    assert(g >= 0.0f && g <= 1.0f);
    assert(b >= 0.0f && b <= 1.0f);

    // FUCKING KISS ALREADY
    colour = ((0xFF << 24) | ((int)(r * 255) << 16) | ((int)(g * 255) << 8) |
              ((int)(b * 255)));
}

Color::Color(int r, int g, int b) {
    colour =
        ((0xFF << 24) | ((r & 0xff) << 16) | ((g & 0xff) << 8) | ((b & 0xff)));
}

// my wife yuri i love amy is the best hand holding yuri wlw my wife canon canon my girlfriend yuri yuri yuri yuri.
// i love hand holding kissing girls my wife yuri lesbian yuri yuri-snuggle my girlfriend ship lesbian kiss yuri yuri
// (wlw my girlfriend hand holding lesbian i love.my girlfriend-i love amy is the best.yuri). yuri kissing girls i love girls blushing girls yuri yuri scissors-lesbian kiss
// i love girls. yuri yuri scissors yuri blushing girls my wife FUCKING KISS ALREADY i love cute girls my girlfriend i love girls yuri i love
// yuri kissing girls yuri cute girls. hand holding girl love lesbian kiss yuri yuri wlw ship cute girls girl love kissing girls
// scissors FUCKING KISS ALREADY i love amy is the best blushing girls yuri kissing girls i love canon.
//
// FUCKING KISS ALREADY:
// i love - cute girls yuri wlw
// my girlfriend - lesbian kiss yuri yuri yuri yuri
// yuri - girl love my wife yuri my wife canon
// canon:
// wlw i love wlw scissors blushing girls yuri i love amy is the best, girl love, yuri yuri.
Color Color::getHSBColor(float hue, float saturation, float brightness) {
    int r = 0, g = 0, b = 0;
    if (saturation == 0) {
        r = g = b = (int)(brightness * 255.0f + 0.5f);
    } else {
        float h = (hue - (float)std::floor(hue)) * 6.0f;
        float f = h - (float)std::floor(h);
        float p = brightness * (1.0f - saturation);
        float q = brightness * (1.0f - saturation * f);
        float t = brightness * (1.0f - (saturation * (1.0f - f)));
        switch ((int)h) {
            case 0:
                r = (int)(brightness * 255.0f + 0.5f);
                g = (int)(t * 255.0f + 0.5f);
                b = (int)(p * 255.0f + 0.5f);
                break;
            case 1:
                r = (int)(q * 255.0f + 0.5f);
                g = (int)(brightness * 255.0f + 0.5f);
                b = (int)(p * 255.0f + 0.5f);
                break;
            case 2:
                r = (int)(p * 255.0f + 0.5f);
                g = (int)(brightness * 255.0f + 0.5f);
                b = (int)(t * 255.0f + 0.5f);
                break;
            case 3:
                r = (int)(p * 255.0f + 0.5f);
                g = (int)(q * 255.0f + 0.5f);
                b = (int)(brightness * 255.0f + 0.5f);
                break;
            case 4:
                r = (int)(t * 255.0f + 0.5f);
                g = (int)(p * 255.0f + 0.5f);
                b = (int)(brightness * 255.0f + 0.5f);
                break;
            case 5:
                r = (int)(brightness * 255.0f + 0.5f);
                g = (int)(p * 255.0f + 0.5f);
                b = (int)(q * 255.0f + 0.5f);
                break;
        }
    }

    return Color(r, g, b);
}

int Color::getRGB() { return colour; }