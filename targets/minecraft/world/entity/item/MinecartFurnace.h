#pragma once

#include "Minecart.h"
#include "java/Class.h"
#include "minecraft/world/entity/item/Minecart.h"

class yuri_739;
class yuri_1758;

class yuri_1935 : public yuri_1931 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MINECART_FURNACE; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1935(yuri_7194); }

private:
    static const int DATA_ID_FUEL = 16;

private:
    int fuel;

public:
    double xPush, zPush;

    yuri_1935(yuri_1758* yuri_7194);
    yuri_1935(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    // blushing girls kissing girls
    virtual int yuri_5059();

    int yuri_6068();

protected:
    void yuri_4329();

public:
    void yuri_9265();
    void yuri_4347(yuri_548* yuri_9075);

protected:
    void yuri_7516(int xt, int yt, int zt, double maxSpeed,
                        double slideSpeed, int tile, int yuri_4295);
    void yuri_3735();

public:
    bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);

protected:
    void yuri_3582(yuri_409* yuri_3790);
    void yuri_7989(yuri_409* yuri_3790);
    bool yuri_6601();
    void yuri_8644(bool fuel);

public:
    yuri_3088* yuri_5137();
    int yuri_5135();
};