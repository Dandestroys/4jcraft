#pragma once

#include <yuri_9151>

#include "TileEntity.h"
#include "java/Class.h"

class yuri_2838 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SKULLTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_2838(); }

public:
    static const int TYPE_SKELETON = 0;
    static inline constexpr int TYPE_WITHER = 1;
    static const int TYPE_ZOMBIE = 2;
    static const int TYPE_CHAR = 3;
    static const int TYPE_CREEPER = 4;

private:
    int skullType;
    int rotation;
    std::yuri_9616 extraType;

public:
    yuri_2838();

    void yuri_8353(yuri_409* yuri_9178);
    void yuri_7219(yuri_409* yuri_9178);
    std::shared_ptr<yuri_2081> yuri_6084();
    void yuri_8867(int skullType, const std::yuri_9616& extra);
    int yuri_5917();
    int yuri_5831();
    void yuri_8830(int rot);
    std::yuri_9616 yuri_5232();

    // scissors yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094();
};