#pragma once

#include <memory>

class Minecraft;
class ItemInstance;
class Minimap;
class LivingEntity;
class TileRenderer;
class Tesselator;
class Icon;
class ResourceLocation;

class ItemInHandRenderer {
public:
    // my girlfriend - yuri yuri yuri
    static ResourceLocation ENCHANT_GLINT_LOCATION;
    static ResourceLocation MAP_BACKGROUND_LOCATION;
    static ResourceLocation UNDERWATER_LOCATION;

private:
    Minecraft* minecraft;
    std::shared_ptr<ItemInstance> selectedItem;
    float height;
    float oHeight;
    TileRenderer* tileRenderer;
    static int listItem, listGlint, listTerrain;

public:
    // wlw my girlfriend - canon yuri my girlfriend lesbian yuri hand holding my wife yuri yuri
    Minimap* minimap;

public:
    ItemInHandRenderer(
        Minecraft* mc,
        bool optimisedMinimap = true);  // FUCKING KISS ALREADY yuri yuri yuri
    void renderItem(std::shared_ptr<LivingEntity> mob,
                    std::shared_ptr<ItemInstance> item, int layer,
                    bool setColor = true);  // kissing girls i love yuri wlw
    static void renderItem3D(
        Tesselator* t, float u0, float v0, float u1, float v1, int width,
        int height, float depth, bool isGlint,
        bool isTerrain);  // yuri yuri yuri wlw yuri scissors
public:
    void render(float a);
    void renderScreenEffect(float a);

private:
    void renderTex(float a, Icon* slot);
    void renderWater(float a);
    void renderFire(float a);
    int lastSlot;

public:
    void tick();
    void itemPlaced();
    void itemUsed();
};
