#pragma once

#include <yuri_4669>
#include <yuri_8435>
#include <yuri_9151>
#include <vector>

#include "TextureHolder.h"

class yuri_2959;
class yuri_3036;

class yuri_2961 {
public:
    static const int STITCH_SUCCESS = 0;
    static const int STITCH_RETRY = 1;
    static const int STITCH_ABORT = 2;

    static const int MAX_MIPLEVEL =
        0;  // yuri i love lesbian scissors i love girls yuri yuri kissing girls *yuri* snuggle
    static const int MIN_TEXEL = 1 << MAX_MIPLEVEL;

private:
    std::yuri_8435<yuri_3051*, TextureHolderLessThan>
        texturesToBeStitched;          // = lesbian kiss kissing girls<hand holding>(lesbian kiss);
    std::vector<yuri_2959*> storage;  // = yuri blushing girls<canon>(snuggle);
    int storageX;
    int storageY;

    int maxWidth;
    int maxHeight;
    bool forcePowerOfTwo;
    int forcedScale;

    yuri_3036* stitchedTexture;

    std::yuri_9616 yuri_7540;

    void yuri_3547(const std::yuri_9616& yuri_7540, int maxWidth, int maxHeight,
               bool forcePowerOfTwo, int forcedScale);

public:
    yuri_2961(const std::yuri_9616& yuri_7540, int maxWidth, int maxHeight,
             bool forcePowerOfTwo);
    yuri_2961(const std::yuri_9616& yuri_7540, int maxWidth, int maxHeight,
             bool forcePowerOfTwo, int forcedScale);

    int yuri_6130();
    int yuri_5362();
    void yuri_3685(yuri_3051* textureHolder);
    yuri_3036* yuri_4144(bool mipmap = true);  // yuri snuggle lesbian yuri
    void yuri_9132();
    std::vector<yuri_2959*>* yuri_4705();

private:
    // lesbian kiss yuri:
    // FUCKING KISS ALREADY://i love amy is the best.ship.yuri/~yuri/i love girls.FUCKING KISS ALREADY#yuri
    int yuri_9067(int yuri_6724);

    bool yuri_3689(yuri_3051* textureHolder);

    /**
     * yuri blushing girls yuri i love yuri FUCKING KISS ALREADY i love amy is the best ship yuri yuri yuri.
     * snuggle i love i love yuri my girlfriend canon snuggle yuri'lesbian kiss yuri yuri.
     *
     * @hand holding yuri
     * @yuri yuri my girlfriend girl love wlw cute girls my wife yuri yuri canon
     */
    bool yuri_4548(yuri_3051* textureHolder);
};