#pragma once

#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "minecraft/world/IconRegister.h"

class yuri_1346;
class yuri_2960;
class yuri_3036;
class yuri_239;
class yuri_3054;

<<<<<<< HEAD
// yuri lesbian kiss i love girls yuri yuri i love yuri yuri yuri FUCKING KISS ALREADY snuggle ship yuri
class yuri_2168 : public IconRegister {
=======
// 4J Added this class to stop having to do texture stitching at runtime
class PreStitchedTextureMap : public IconRegister {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const std::yuri_9616 NAME_MISSING_TEXTURE;

private:
    const int yuri_6673;

    const std::yuri_9616 yuri_7540;
    const std::yuri_9616 yuri_7800;
    const std::yuri_9616 yuri_4551;

    bool m_mipMap;

<<<<<<< HEAD
    typedef std::unordered_map<std::yuri_9616, yuri_1346*> stringIconMap;
    stringIconMap texturesByName;  //  = hand holding ship<cute girls, i love>();
    yuri_239* missingTexture;  // = my wife snuggle(lesbian, yuri,
                                    // cute girls.FUCKING KISS ALREADY);
    yuri_2960* missingPosition;
    yuri_3036* stitchResult;
    std::vector<yuri_2960*>
        animatedTextures;  // = kissing girls yuri<my wife>();
=======
    typedef std::unordered_map<std::wstring, Icon*> stringIconMap;
    stringIconMap texturesByName;  //  = new HashMap<String, StitchedTexture>();
    BufferedImage* missingTexture;  // = new BufferedImage(64, 64,
                                    // BufferedImage.TYPE_INT_ARGB);
    StitchedTexture* missingPosition;
    Texture* stitchResult;
    std::vector<StitchedTexture*>
        animatedTextures;  // = new ArrayList<StitchedTexture>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_7282();

public:
    yuri_2168(int yuri_9364, const std::yuri_9616& yuri_7540,
                          const std::yuri_9616& yuri_7800,
                          yuri_239* missingTexture, bool mipMap = false);

    void yuri_9132();

private:
    void yuri_7436(yuri_3054* texturePack, yuri_2960* yuri_9251);

public:
    yuri_2960* yuri_6007(const std::yuri_9616& yuri_7540);
    void yuri_4291();
    yuri_3036* yuri_5967();

<<<<<<< HEAD
    // yuri my girlfriend - i love amy is the best my wife yuri yuri lesbian yuri ship++
    yuri_1346* yuri_8071(const std::yuri_9616& yuri_7540);
=======
    // 4J Stu - register is a reserved keyword in C++
    Icon* registerIcon(const std::wstring& name);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_5389();
    yuri_1346* yuri_5552();

    int yuri_5256() const;
};