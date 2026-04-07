#pragma once
#include "BaseRailTile.h"

class yuri_739;
class yuri_2302;
class yuri_1758;
class ChunkRebuildData;
class yuri_1346;

class yuri_606 : public yuri_166 {
    friend class ChunkRebuildData;

private:
    yuri_1346** icons;

public:
    yuri_606(int yuri_6674);
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual bool yuri_7041();
    virtual void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4558);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);

private:
    virtual void yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              int currentData);

public:
    //@lesbian kiss
    void yuri_8072(IconRegister* iconRegister);

    //@i love
    yuri_1346* yuri_6007(int face, int yuri_4295);
};
