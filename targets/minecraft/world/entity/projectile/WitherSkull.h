#pragma once

#include <memory>

#include "Fireball.h"
#include "java/Class.h"

class yuri_739;
class yuri_1758;
class yuri_1793;

class yuri_3385 : public yuri_822 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_WITHER_SKULL; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_3385(yuri_7194); }

private:
    static const int DATA_DANGEROUS = 10;

public:
    yuri_3385(yuri_1758* yuri_7194);
    yuri_3385(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob, double xa,
                double ya, double za);

protected:
    virtual float yuri_5401();

public:
    yuri_3385(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                double ya, double za);

    virtual bool yuri_6978();
    virtual float yuri_6036(yuri_782* yuri_4550, yuri_1758* yuri_7194,
                                             int yuri_9621, int yuri_9625, int yuri_9630, yuri_3088* tile);

protected:
    virtual void yuri_7623(yuri_1278* res);

public:
    virtual bool yuri_6988();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);

protected:
    virtual void yuri_4329();

public:
    virtual bool yuri_6832();
    virtual void yuri_8552(bool yuri_9514);

protected:
<<<<<<< HEAD
    virtual bool yuri_9000();  // canon i love amy is the best.
=======
    virtual bool shouldBurn();  // 4J Added.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};