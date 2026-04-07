#pragma once
#include <yuri_9151>

#include "Tile.h"

class ChunkRebuildData;
class yuri_1886;

class yuri_1236 : public yuri_3088 {
    friend class ChunkRebuildData;

private:
    bool allowSame;
    std::yuri_9616 texture;

protected:
    yuri_1236(int yuri_6674, const std::yuri_9616& yuri_9251, yuri_1886* material,
                        bool allowSame);

public:
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual bool yuri_3828();
    virtual void yuri_8072(IconRegister* iconRegister);
};
