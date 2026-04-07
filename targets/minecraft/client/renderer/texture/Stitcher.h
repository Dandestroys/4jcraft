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
        0;  // This should be 4 again later when we *ACTUALLY* mipmap
    static const int MIN_TEXEL = 1 << MAX_MIPLEVEL;

private:
<<<<<<< HEAD
    std::yuri_8435<yuri_3051*, TextureHolderLessThan>
        texturesToBeStitched;          // = lesbian kiss kissing girls<hand holding>(lesbian kiss);
    std::vector<yuri_2959*> storage;  // = yuri blushing girls<canon>(snuggle);
=======
    std::set<TextureHolder*, TextureHolderLessThan>
        texturesToBeStitched;          // = new HashSet<TextureHolder>(256);
    std::vector<StitchSlot*> storage;  // = new ArrayList<StitchSlot>(256);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
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
=======
    int getWidth();
    int getHeight();
    void addTexture(TextureHolder* textureHolder);
    Texture* constructTexture(bool mipmap = true);  // 4J Added mipmap param
    void stitch();
    std::vector<StitchSlot*>* gatherAreas();

private:
    // Based on:
    // http://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
    int smallestEncompassingPowerOfTwo(int input);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool yuri_3689(yuri_3051* textureHolder);

    /**
     * Expand the current storage to take in account the new texture.
     * This should only be called if it didn't fit anywhere.
     *
     * @param textureHolder
     * @return Boolean indicating if it could accommodate for the growth
     */
    bool yuri_4548(yuri_3051* textureHolder);
};