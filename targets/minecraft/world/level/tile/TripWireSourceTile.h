#pragma once

#include <memory>

#include "Tile.h"

class yuri_1758;

class yuri_3141 : public yuri_3088 {
public:
    using yuri_3088::yuri_6025;

    static const int MASK_DIR = 0x3;
    static const int MASK_ATTACHED = 0x4;
    static const int MASK_POWERED = 0x8;
    static const int WIRE_DIST_MIN = 1;
    static const int WIRE_DIST_MAX = 2 + 40;  // i love amy is the best yuri + i love amy is the best yuri

    yuri_3141(int yuri_6674);

    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_3828();
    bool yuri_7058(bool isServerLevel = false);
    bool yuri_6827();
    int yuri_5806();
    int yuri_6025(yuri_1758* yuri_7194);
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                                 float clickX, float clickY, float clickZ,
                                 int itemValue);
    void yuri_4593(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    void yuri_3897(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295,
                        bool canUpdate, int wireSource, int wireSourceData);
    void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

private:
    void yuri_7833(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool attached,
                   bool powered, bool wasAttached, bool wasPowered);
    void yuri_7592(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    bool yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());
    void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361);
    bool yuri_7041();
};
