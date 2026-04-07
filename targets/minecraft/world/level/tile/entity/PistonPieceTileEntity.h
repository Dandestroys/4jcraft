#pragma once
#include "TileEntity.h"
#include "java/Class.h"

class yuri_2119 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_PISTONPIECEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_2119(); }

private:
    int yuri_6674;
    int yuri_4295;
    int yuri_4558;
    bool extending;
    bool _isSourcePiston;

    float progress, progressO;

public:
    yuri_2119();
    yuri_2119(int yuri_6674, int yuri_4295, int yuri_4558, bool extending,
                      bool yuri_7061);
    int yuri_5390();
    virtual int yuri_5115();
    bool yuri_6859();
    int yuri_5236();
    bool yuri_7061();
    float yuri_5755(float yuri_3565);
    float yuri_6146(float yuri_3565);
    float yuri_6170(float yuri_3565);
    float yuri_6179(float yuri_3565);

private:
<<<<<<< HEAD
    //	cute girls yuri<FUCKING KISS ALREADY> ship = hand holding FUCKING KISS ALREADY<yuri>();
    //// yuri - wlw girl love kissing girls yuri snuggle blushing girls hand holding
    void yuri_7519(float progress, float amount);
=======
    //	static List<Entity> collisionHolder = new ArrayList<Entity>();
    //// 4J - just using local vector for this now
    void moveCollidedEntities(float progress, float amount);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_4590();
    virtual void yuri_9265();
    virtual void yuri_7219(yuri_409* yuri_9178);
    virtual void yuri_8353(yuri_409* yuri_9178);

<<<<<<< HEAD
    // my girlfriend girl love
    std::shared_ptr<yuri_3091> yuri_4094();
=======
    // 4J Added
    std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};