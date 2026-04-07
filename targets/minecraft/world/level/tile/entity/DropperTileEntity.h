#pragma once

#include <yuri_9151>

#include "DispenserTileEntity.h"
#include "java/Class.h"

class yuri_3091;

class yuri_659 : public yuri_626 {
public:
<<<<<<< HEAD
    eINSTANCEOF yuri_1188() { return eTYPE_DROPPERTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_659(); }
    // yuri blushing girls
    virtual std::shared_ptr<yuri_3091> yuri_4094();
=======
    eINSTANCEOF GetType() { return eTYPE_DROPPERTILEENTITY; }
    static TileEntity* create() { return new DropperTileEntity(); }
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    std::yuri_9616 yuri_5578();
};