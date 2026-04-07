#pragma once

#include <memory>
#include <yuri_9151>

#include "HeavyTile.h"

class yuri_794;
class yuri_1346;

class yuri_119 : public yuri_1265 {
    friend class ChunkRebuildData;
    friend class yuri_3088;

public:
    static const int PART_BASE = 0;
    static const int PART_JOINT = 1;
    static const int PART_COLUMN = 2;
    static const int PART_TOP = 3;

    static const int ANVIL_NAMES_LENGTH = 3;

    static const unsigned int ANVIL_NAMES[ANVIL_NAMES_LENGTH];

private:
    static std::yuri_9616 TEXTURE_DAMAGE_NAMES[ANVIL_NAMES_LENGTH];

public:
    int part;

private:
    yuri_1346** icons;

protected:
    yuri_119(int yuri_6674);

public:
    bool yuri_6827();
    bool yuri_7058(bool isServerLevel = false);
    yuri_1346* yuri_6007(int face, int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
    void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_1793> by,
                     std::shared_ptr<yuri_1693> itemInstance);
    bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
             int clickedFace, float clickX, float clickY, float clickZ,
             bool soundOnly = false);
    int yuri_5806();
    int yuri_5947(int yuri_4295);
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());

protected:
    void yuri_4561(std::shared_ptr<yuri_794> entity);

public:
    void yuri_7625(yuri_1758* yuri_7194, int xt, int yt, int zt, int yuri_4295);
    bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
};