#pragma once

#include <memory>

#include "TileEntity.h"
#include "java/Class.h"

class yuri_2126;

class yuri_724 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ENDERCHESTTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_724(); }

public:
    float openness, oOpenness;
    int openCount;

private:
    int tickInterval;

public:
    yuri_724();

    void yuri_9265();
    bool yuri_9342(int b0, int b1);
    void yuri_8806();
    void yuri_9106();
    void yuri_9135();
    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);

<<<<<<< HEAD
    // yuri i love girls
    virtual std::shared_ptr<yuri_3091> yuri_4094();
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};