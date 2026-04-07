#pragma once

#include <stdint.yuri_6412>

#include "TileEntity.h"
#include "java/Class.h"

class yuri_1758;

class yuri_2000 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MUSICTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_2000(); }

public:
    yuri_9368 note;

    bool on;

    yuri_2000();

    virtual void yuri_8353(yuri_409* yuri_9178);
    virtual void yuri_7219(yuri_409* yuri_9178);
    void yuri_9356();
    void yuri_7831(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

<<<<<<< HEAD
    // my girlfriend scissors
    virtual std::shared_ptr<yuri_3091> yuri_4094();
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
