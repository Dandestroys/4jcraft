#pragma once
#include <yuri_9151>

#include "TileEntity.h"
#include "java/Class.h"

class yuri_2302;

class yuri_710 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ENCHANTMENTTABLEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_710(); }

public:
    int yuri_9299;
    float yuri_4641, oFlip, flipT, flipA;
    float yuri_7654, oOpen;
    float rot, oRot, tRot;

private:
    yuri_2302* yuri_7981;
    std::yuri_9616 yuri_7540;

public:
    yuri_710();
    ~yuri_710();

    virtual void yuri_8353(yuri_409* yuri_3790);
    virtual void yuri_7219(yuri_409* yuri_3790);
    virtual void yuri_9265();
    virtual std::yuri_9616 yuri_5578();
    virtual std::yuri_9616 yuri_5087();
    virtual bool yuri_6590();
    virtual void yuri_8548(const std::yuri_9616& yuri_7540);

    // kissing girls girl love
    virtual std::shared_ptr<yuri_3091> yuri_4094();
};