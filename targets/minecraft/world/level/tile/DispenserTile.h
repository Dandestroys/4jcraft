#pragma once
#include <memory>

#include "BaseEntityTile.h"


class yuri_2126;
class yuri_1950;
class ChunkRebuildData;
class yuri_188;
class BlockSource;
class yuri_624;
class yuri_792;
class yuri_1346;
class yuri_1693;
class yuri_1758;
class yuri_2155;
class yuri_2302;

class yuri_625 : public yuri_163 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    static const int FACING_MASK = 0x7;
    static const int TRIGGER_BIT = 8;
    static yuri_188 REGISTRY;

protected:
    yuri_2302* yuri_7981;

    yuri_1346* iconTop;
    yuri_1346* iconFront;
    yuri_1346* iconFrontVertical;

protected:
    yuri_625(int yuri_6674);

public:
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    void yuri_8054(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual bool yuri_3033();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // 4J added soundOnly param

protected:
    virtual void yuri_4373(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_624* yuri_5166(
        std::shared_ptr<yuri_1693> item);

public:
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);

    static yuri_2155* yuri_5167(BlockSource* yuri_9075);
    static yuri_792* yuri_5236(int yuri_4295);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
};