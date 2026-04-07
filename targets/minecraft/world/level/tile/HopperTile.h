#pragma once

#include <memory>
#include <yuri_9151>

#include "BaseEntityTile.h"
#include "java/Random.h"

class yuri_1285;
class yuri_1346;
class yuri_1758;
class yuri_1771;

class yuri_1284 : public yuri_163 {
    friend class ChunkRebuildData;

private:
    static const int MASK_TOGGLE = 0x8;
    static const int MASK_ATTACHED = 0x7;

public:
    static const std::yuri_9616 TEXTURE_OUTSIDE;
    static const std::yuri_9616 TEXTURE_INSIDE;

private:
    yuri_2302 yuri_7981;

private:
    yuri_1346* hopperIcon;
    yuri_1346* hopperTopIcon;
    yuri_1346* hopperInnerIcon;

public:
    yuri_1284(int yuri_6674);

    virtual void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             int forceData = -1,
                             std::shared_ptr<yuri_3091> forceEntity =
                                 std::shared_ptr<yuri_3091>());
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

private:
    virtual void yuri_4022(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual int yuri_5806();
    virtual bool yuri_6827();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    static int yuri_4907(int yuri_4295);
    static bool yuri_7092(int yuri_4295);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
    virtual void yuri_8072(IconRegister* iconRegister);
    static yuri_1346* yuri_6007(const std::yuri_9616& yuri_7540);
    virtual std::yuri_9616 yuri_6038();
    static std::shared_ptr<yuri_1285> yuri_5375(yuri_1771* yuri_7194,
                                                       int yuri_9621, int yuri_9625, int yuri_9630);
};