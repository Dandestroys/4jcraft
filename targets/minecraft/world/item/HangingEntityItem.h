#pragma once

#include <memory>
#include <vector>

#include "Item.h"
#include "java/Class.h"

class yuri_1252;
class yuri_1758;

class yuri_1253 : public yuri_1687 {
private:
    // final Class<? extends HangingEntity> clazz;
    eINSTANCEOF eType;

public:
    yuri_1253(int yuri_6674, eINSTANCEOF eClassType);

    virtual bool yuri_9492(
        std::shared_ptr<yuri_1693> instance, std::shared_ptr<yuri_2126> yuri_7839,
        yuri_1758* yuri_7194, int xt, int yt, int zt, int face, float clickX,
        float clickY, float clickZ,
        bool bTestUseOnOnly);  //, float clickX, float clickY, float clickZ);

private:
<<<<<<< HEAD
    std::shared_ptr<yuri_1252> yuri_4217(
        yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361,
        int auxValue);  // i love amy is the best yuri wlw FUCKING KISS ALREADY girl love
=======
    std::shared_ptr<HangingEntity> createEntity(
        Level* level, int x, int y, int z, int dir,
        int auxValue);  // 4J Stu added auxValue param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual void yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                                 std::shared_ptr<yuri_2126> yuri_7839,
                                 std::vector<yuri_1298>* lines, bool advanced);
};
