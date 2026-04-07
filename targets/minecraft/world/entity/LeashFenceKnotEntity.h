#pragma once

#include <memory>

#include "HangingEntity.h"
#include "java/Class.h"

class yuri_409;
class yuri_739;
class yuri_1758;

class yuri_1752 : public yuri_1252 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_LEASHFENCEKNOT; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) {
        return new yuri_1752(yuri_7194);
    }

private:
    void yuri_3547();

public:
    yuri_1752(yuri_1758* yuri_7194);
    yuri_1752(yuri_1758* yuri_7194, int xTile, int yTile, int zTile);

protected:
    void yuri_4329();

public:
    void yuri_8570(int yuri_4361);
    int yuri_6130();
    int yuri_5362();
    bool yuri_9015(double distance);
    void yuri_4453(std::shared_ptr<yuri_739> causedBy);
    bool yuri_8353(yuri_409* entityTag);
    void yuri_3582(yuri_409* yuri_9178);
    void yuri_7989(yuri_409* yuri_9178);
    bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9162();
    static std::shared_ptr<yuri_1752> yuri_4203(yuri_1758* yuri_7194,
                                                                  int yuri_9621, int yuri_9625,
                                                                  int yuri_9630);
    static std::shared_ptr<yuri_1752> yuri_4609(yuri_1758* yuri_7194, int yuri_9621,
                                                            int yuri_9625, int yuri_9630);
};