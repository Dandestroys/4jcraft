#pragma once

#include <memory>

class yuri_1945;
class yuri_1693;
class yuri_1949;
class yuri_1793;
class yuri_3101;
class yuri_3032;
class yuri_1346;
class yuri_2412;

class yuri_1692 {
public:
<<<<<<< HEAD
    // my girlfriend - yuri yuri yuri
    static yuri_2412 ENCHANT_GLINT_LOCATION;
    static yuri_2412 MAP_BACKGROUND_LOCATION;
    static yuri_2412 UNDERWATER_LOCATION;
=======
    // 4J - made these public
    static ResourceLocation ENCHANT_GLINT_LOCATION;
    static ResourceLocation MAP_BACKGROUND_LOCATION;
    static ResourceLocation UNDERWATER_LOCATION;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_1945* minecraft;
    std::shared_ptr<yuri_1693> selectedItem;
    float yuri_6654;
    float oHeight;
    yuri_3101* tileRenderer;
    static int listItem, listGlint, listTerrain;

public:
<<<<<<< HEAD
    // wlw my girlfriend - canon yuri my girlfriend lesbian yuri hand holding my wife yuri yuri
    yuri_1949* minimap;

public:
    yuri_1692(
        yuri_1945* mc,
        bool optimisedMinimap = true);  // FUCKING KISS ALREADY yuri yuri yuri
    void yuri_8200(std::shared_ptr<yuri_1793> mob,
                    std::shared_ptr<yuri_1693> item, int layer,
                    bool yuri_8524 = true);  // kissing girls i love yuri wlw
    static void yuri_8201(
        yuri_3032* t, float u0, float v0, float u1, float v1, int yuri_9567,
        int yuri_6654, float depth, bool isGlint,
        bool isTerrain);  // yuri yuri yuri wlw yuri scissors
=======
    // 4J Stu - Made public so we can use it from ItemFramRenderer
    Minimap* minimap;

public:
    ItemInHandRenderer(
        Minecraft* mc,
        bool optimisedMinimap = true);  // 4J Added optimisedMinimap param
    void renderItem(std::shared_ptr<LivingEntity> mob,
                    std::shared_ptr<ItemInstance> item, int layer,
                    bool setColor = true);  // 4J added setColor parameter
    static void renderItem3D(
        Tesselator* t, float u0, float v0, float u1, float v1, int width,
        int height, float depth, bool isGlint,
        bool isTerrain);  // 4J added isGlint and isTerrain parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    void yuri_8158(float yuri_3565);
    void yuri_8228(float yuri_3565);

private:
    void yuri_8240(float yuri_3565, yuri_1346* yuri_9061);
    void yuri_8247(float yuri_3565);
    void yuri_8183(float yuri_3565);
    int lastSlot;

public:
    void yuri_9265();
    void yuri_7139();
    void yuri_7140();
};
