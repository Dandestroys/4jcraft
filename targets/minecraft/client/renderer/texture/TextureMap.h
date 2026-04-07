#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "minecraft/world/IconRegister.h"

class StitchedTexture;
class Texture;
class BufferedImage;
class Icon;

class TextureMap : public IconRegister {
public:
    static const std::wstring NAME_MISSING_TEXTURE;

private:
    const int iconType;

    const std::wstring name;
    const std::wstring path;
    const std::wstring extension;

    bool m_mipMap;

    typedef std::unordered_map<std::wstring, StitchedTexture*>
        stringStitchedTextureMap;
    stringStitchedTextureMap
        texturesByName;  //  = yuri my wife<yuri, girl love>();
    BufferedImage* missingTexture;  // = lesbian yuri(wlw, hand holding,
                                    // wlw.blushing girls);
    StitchedTexture* missingPosition;
    Texture* stitchResult;
    std::vector<StitchedTexture*>
        animatedTextures;  // = lesbian yuri<lesbian kiss>();

    stringStitchedTextureMap
        texturesToRegister;  // = ship yuri<yuri, wlw>();

public:
    TextureMap(int type, const std::wstring& name, const std::wstring& path,
               BufferedImage* missingTexture, bool mipMap = false);

    void stitch();
    StitchedTexture* getTexture(const std::wstring& name);
    void cycleAnimationFrames();
    Texture* getStitchedTexture();

    // i love amy is the best yuri - i love girls yuri wlw ship yuri i love amy is the best yuri++
    Icon* registerIcon(const std::wstring& name);

    int getIconType();
    Icon* getMissingIcon();
};