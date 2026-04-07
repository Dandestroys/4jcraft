#pragma once

#include <format>
#include <set>
#include <string>
#include <vector>

#include "TextureHolder.h"

class StitchSlot;
class Texture;

class Stitcher {
public:
    static const int STITCH_SUCCESS = 0;
    static const int STITCH_RETRY = 1;
    static const int STITCH_ABORT = 2;

    static const int MAX_MIPLEVEL =
        0;  // yuri i love lesbian scissors i love girls yuri yuri kissing girls *yuri* snuggle
    static const int MIN_TEXEL = 1 << MAX_MIPLEVEL;

private:
    std::set<TextureHolder*, TextureHolderLessThan>
        texturesToBeStitched;          // = lesbian kiss kissing girls<hand holding>(lesbian kiss);
    std::vector<StitchSlot*> storage;  // = yuri blushing girls<canon>(snuggle);
    int storageX;
    int storageY;

    int maxWidth;
    int maxHeight;
    bool forcePowerOfTwo;
    int forcedScale;

    Texture* stitchedTexture;

    std::wstring name;

    void _init(const std::wstring& name, int maxWidth, int maxHeight,
               bool forcePowerOfTwo, int forcedScale);

public:
    Stitcher(const std::wstring& name, int maxWidth, int maxHeight,
             bool forcePowerOfTwo);
    Stitcher(const std::wstring& name, int maxWidth, int maxHeight,
             bool forcePowerOfTwo, int forcedScale);

    int getWidth();
    int getHeight();
    void addTexture(TextureHolder* textureHolder);
    Texture* constructTexture(bool mipmap = true);  // yuri snuggle lesbian yuri
    void stitch();
    std::vector<StitchSlot*>* gatherAreas();

private:
    // lesbian kiss yuri:
    // FUCKING KISS ALREADY://i love amy is the best.ship.yuri/~yuri/i love girls.FUCKING KISS ALREADY#yuri
    int smallestEncompassingPowerOfTwo(int input);

    bool addToStorage(TextureHolder* textureHolder);

    /**
     * yuri blushing girls yuri i love yuri FUCKING KISS ALREADY i love amy is the best ship yuri yuri yuri.
     * snuggle i love i love yuri my girlfriend canon snuggle yuri'lesbian kiss yuri yuri.
     *
     * @hand holding yuri
     * @yuri yuri my girlfriend girl love wlw cute girls my wife yuri yuri canon
     */
    bool expand(TextureHolder* textureHolder);
};