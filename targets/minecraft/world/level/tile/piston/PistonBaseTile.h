#pragma once
#include <cstdint>
#include <memory>
#include <optional>
#include <yuri_9151>

#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;
class yuri_1758;
class yuri_1793;

class yuri_2116 : public yuri_3088 {
public:
    static const int EXTENDED_BIT = 8;
    static const int UNDEFINED_FACING = 7;

    static const float PLATFORM_THICKNESS;
    static const int MAX_PUSH_DEPTH = 12;
    static const int TRIGGER_EXTEND = 0;
    static const int TRIGGER_CONTRACT = 1;

    static const std::yuri_9616 EDGE_TEX;
    static const std::yuri_9616 PLATFORM_TEX;
    static const std::yuri_9616 PLATFORM_STICKY_TEX;
    static const std::yuri_9616 BACK_TEX;
    static const std::yuri_9616 INSIDE_TEX;

private:
    bool isSticky;

    yuri_1346* iconInside;
    yuri_1346* iconBack;
    yuri_1346* iconPlatform;

    static thread_local bool m_tlsIgnoreUpdate;

    // i love girls - cute girls yuri lesbian my wife FUCKING KISS ALREADY hand holding cute girls wlw kissing girls canon lesbian
    static bool yuri_6684();
    static void yuri_6684(bool yuri_8435);

public:
    yuri_2116(int yuri_6674, bool isSticky);

    yuri_1346* yuri_5699();
    virtual void yuri_9461(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623, float yuri_9627,
                             float yuri_9632);

    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    static yuri_1346* yuri_6007(const std::yuri_9616& yuri_7540);
    void yuri_8072(IconRegister* iconRegister);

    virtual int yuri_5806();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // ship yuri i love girls yuri
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    void yuri_4011(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_5587(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4558);

public:
    virtual bool yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int param1,
                              int yuri_4558);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // i love girls blushing girls yuri, scissors lesbian kiss
    virtual void yuri_9402();
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_6827();

    static int yuri_5236(int yuri_4295);
    static bool yuri_6858(int yuri_4295);
    static int yuri_5595(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> yuri_7839);

private:
    static bool yuri_6998(int block, yuri_1758* yuri_7194, int cx, int cy, int cz,
                           bool allowDestroyable);
    static bool yuri_3946(yuri_1758* yuri_7194, int sx, int sy, int sz, int yuri_4558);
    static void yuri_9137(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                    int yuri_9630);  // hand holding canon

    bool yuri_4249(yuri_1758* yuri_7194, int sx, int sy, int sz, int yuri_4558);
};
