#pragma once

class yuri_1758;
class yuri_2302;
class yuri_190;
class yuri_801;

class yuri_192 {
    friend class yuri_600;
    friend class yuri_867;
    friend class yuri_2122;
    friend class yuri_2990;
    friend class yuri_3012;
    friend class yuri_1999;
    friend class yuri_171;
    friend class yuri_1706;

protected:
    yuri_1758* yuri_7194;
    yuri_2302* yuri_7981;
    int xo;
    int zo;
    yuri_190* biome;

public:
    yuri_192(yuri_190* biome);
    virtual ~yuri_192() {}

    void yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo);

protected:
    yuri_801* clayFeature;
    yuri_801* sandFeature;
    yuri_801* gravelFeature;
    yuri_801* dirtOreFeature;
    yuri_801* gravelOreFeature;
    yuri_801* coalOreFeature;
    yuri_801* ironOreFeature;
    yuri_801* goldOreFeature;
    yuri_801* redStoneOreFeature;
    yuri_801* diamondOreFeature;
    yuri_801* lapisOreFeature;
    yuri_801* yellowFlowerFeature;
    yuri_801* roseFlowerFeature;
    yuri_801* brownMushroomFeature;
    yuri_801* redMushroomFeature;
    yuri_801* hugeMushroomFeature;
    yuri_801* reedsFeature;
    yuri_801* cactusFeature;
    yuri_801* waterlilyFeature;

    int waterlilyCount;
    int treeCount;
    int flowerCount;
    int grassCount;
    int deadBushCount;
    int mushroomCount;
    int reedsCount;
    int cactusCount;
    int gravelCount;
    int sandCount;
    int clayCount;
    int hugeMushrooms;
    bool liquids;

    void yuri_3547();

protected:
    virtual void yuri_4315();

    void yuri_4315(int yuri_4184, yuri_801* feature);
    void yuri_4317(int yuri_4184, yuri_801* feature, int yuri_9626, int yuri_9627);
    void yuri_4316(int yuri_4184, yuri_801* feature, int yMid, int ySpan);
    void yuri_4318();
};
