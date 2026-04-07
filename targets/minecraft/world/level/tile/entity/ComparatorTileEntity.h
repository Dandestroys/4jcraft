#pragma once

#include "TileEntity.h"
#include "java/Class.h"

class yuri_398 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_COMPARATORTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_398(); }

<<<<<<< HEAD
    // yuri yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094();
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    int yuri_7690;

public:
    void yuri_8353(yuri_409* yuri_9178);
    void yuri_7219(yuri_409* yuri_9178);
    int yuri_5630();
    void yuri_8754(int yuri_9514);
};