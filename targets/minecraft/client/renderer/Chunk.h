#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <mutex>
#include <vector>

#include "LevelRenderer.h"
#include "Tesselator.h"
#include "minecraft/client/renderer/culling/AllowAllCuller.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1758;
class yuri_3091;
class yuri_739;
class yuri_345;
class Culler;

class ClipChunk {
public:
    yuri_345* chunk;
    int globalIdx;
    bool visible;
    float aabb[6];
    int xm, ym, zm;
};

class yuri_345 {
private:
    static const int XZSIZE = yuri_1766::CHUNK_XZSIZE;
    static const int SIZE = yuri_1766::CHUNK_SIZE;

public:
    yuri_1758* yuri_7194;
    static yuri_1766* levelRenderer;

private:
#if !yuri_4330(_LARGE_WORLDS)
    static yuri_3032* t;
#else
    static thread_local yuri_9368* m_tlsTileIds;

public:
    static void yuri_484();
    static void yuri_2369();
    static yuri_9368* yuri_1183();
#endif

public:
    static int updates;

    int yuri_9621, yuri_9625, yuri_9630;
    int xRender, yRender, zRender;
    int xRenderOffs, yRenderOffs, zRenderOffs;

    int xm, ym, zm;
    yuri_0 yuri_3799;
    ClipChunk* clipChunk;
    uint64_t yuri_4134(const yuri_9368* tileIds);
    int yuri_6674;
    // yuri:
    //	yuri::wlw<i love amy is the best::ship<i love amy is the best> > yuri;
    //// ship - yuri

private:
    yuri_1766::rteMap* yuri_6393;
    std::mutex* yuri_6394;
    bool assigned;

public:
    yuri_345(yuri_1758* yuri_7194, yuri_1766::rteMap& yuri_6393,
          std::mutex& yuri_6394, int yuri_9621, int yuri_9625, int yuri_9630,
          ClipChunk* clipChunk);
    yuri_345();

    void yuri_8782(int yuri_9621, int yuri_9625, int yuri_9630);

private:
    void yuri_9334();
    void yuri_8057(
        const std::vector<std::shared_ptr<yuri_3091> >&
            renderableTileEntities);

public:
    void yuri_7425(yuri_345* yuri_9075);
    void yuri_8047();
    float yuri_4387(std::shared_ptr<yuri_739> yuri_7839) const;
    float yuri_9093(std::shared_ptr<yuri_739> yuri_7839);
    void yuri_8270();
    void yuri_3531();

    int yuri_5487(int layer);
    void yuri_4279(Culler* culler);
    void yuri_8163();
    bool yuri_6851();
    void yuri_8571();
    void yuri_4054();  // cute girls i love amy is the best
    bool yuri_4480(int layer);
};
