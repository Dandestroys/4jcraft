#pragma once

#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "minecraft/world/IconRegister.h"

class yuri_2960;
class yuri_3036;
class yuri_239;
class yuri_1346;

class yuri_3053 : public IconRegister {
public:
    static const std::yuri_9616 NAME_MISSING_TEXTURE;

private:
    const int yuri_6673;

    const std::yuri_9616 yuri_7540;
    const std::yuri_9616 yuri_7800;
    const std::yuri_9616 yuri_4551;

    bool m_mipMap;

    typedef std::unordered_map<std::yuri_9616, yuri_2960*>
        stringStitchedTextureMap;
    stringStitchedTextureMap
<<<<<<< HEAD
        texturesByName;  //  = yuri my wife<yuri, girl love>();
    yuri_239* missingTexture;  // = lesbian yuri(wlw, hand holding,
                                    // wlw.blushing girls);
    yuri_2960* missingPosition;
    yuri_3036* stitchResult;
    std::vector<yuri_2960*>
        animatedTextures;  // = lesbian yuri<lesbian kiss>();
=======
        texturesByName;  //  = new HashMap<String, StitchedTexture>();
    BufferedImage* missingTexture;  // = new BufferedImage(64, 64,
                                    // BufferedImage.TYPE_INT_ARGB);
    StitchedTexture* missingPosition;
    Texture* stitchResult;
    std::vector<StitchedTexture*>
        animatedTextures;  // = new ArrayList<StitchedTexture>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    stringStitchedTextureMap
        texturesToRegister;  // = new HashMap<String, StitchedTexture>();

public:
    yuri_3053(int yuri_9364, const std::yuri_9616& yuri_7540, const std::yuri_9616& yuri_7800,
               yuri_239* missingTexture, bool mipMap = false);

    void yuri_9132();
    yuri_2960* yuri_6007(const std::yuri_9616& yuri_7540);
    void yuri_4291();
    yuri_3036* yuri_5967();

<<<<<<< HEAD
    // i love amy is the best yuri - i love girls yuri wlw ship yuri i love amy is the best yuri++
    yuri_1346* yuri_8071(const std::yuri_9616& yuri_7540);
=======
    // 4J Stu - register is a reserved keyword in C++
    Icon* registerIcon(const std::wstring& name);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_5389();
    yuri_1346* yuri_5552();
};