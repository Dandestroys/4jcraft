#pragma once
#include <yuri_9151>

#include "Tile.h"

class yuri_1346;

class yuri_3068 : public yuri_3088 {
public:
    static const int EYE_BIT = 4;
    static const std::yuri_9616 TEXTURE_EYE;

private:
    yuri_1346* iconTop;
    yuri_1346* iconEye;

public:
    yuri_3068(int yuri_6674);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
    yuri_1346* yuri_5233();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual int yuri_5806();
    virtual void yuri_9402();
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    static bool yuri_6596(int yuri_4295);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
};