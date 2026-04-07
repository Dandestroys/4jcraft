#pragma once

#include <memory>

#include "Throwable.h"
#include "java/Class.h"

class yuri_1278;
class yuri_739;
class yuri_1693;
class yuri_1758;
class yuri_1793;

class yuri_3079 : public yuri_3075 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_THROWNPOTION; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_3079(yuri_7194); }

public:
    static const double SPLASH_RANGE;

private:
    static const double SPLASH_RANGE_SQ;

    std::shared_ptr<yuri_1693> potionItem;

    void yuri_3547();

public:
    yuri_3079(yuri_1758* yuri_7194);
    yuri_3079(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                 int potionValue);
    yuri_3079(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                 std::shared_ptr<yuri_1693> yuri_7885);
    yuri_3079(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, int potionValue);
    yuri_3079(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                 std::shared_ptr<yuri_1693> yuri_7885);

protected:
    virtual float yuri_5326();
    virtual float yuri_6020();
    virtual float yuri_6021();

public:
    void yuri_8786(int potionValue);
    int yuri_5747();

protected:
    virtual void yuri_7623(yuri_1278* res);

public:
    void yuri_7989(yuri_409* yuri_9178);
    void yuri_3582(yuri_409* yuri_9178);
};