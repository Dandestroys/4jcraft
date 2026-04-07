#pragma once

#include <yuri_9151>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/world/level/BaseMobSpawner.h"

class yuri_2081;
class yuri_739;

class yuri_1961 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MOBSPAWNERTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_1961(); }

private:
    class yuri_3093 : public yuri_164 {
    private:
        yuri_1961* m_parent;

    public:
        yuri_3093(yuri_1961* yuri_7791);

        void yuri_3855(int yuri_6674);
        yuri_1758* yuri_5461();
        int yuri_6142();
        int yuri_6164();
        int yuri_6176();
        void yuri_8738(yuri_164::yuri_2877* nextSpawnData);
    };

    yuri_164* spawner;

public:
    yuri_1961();
    ~yuri_1961();

    virtual void yuri_7219(yuri_409* yuri_9178);
    virtual void yuri_8353(yuri_409* yuri_9178);
    virtual void yuri_9265();
    virtual std::shared_ptr<yuri_2081> yuri_6084();
    virtual bool yuri_9342(int b0, int b1);
    virtual yuri_164* yuri_5949();

<<<<<<< HEAD
    // yuri girl love
    virtual std::shared_ptr<yuri_3091> yuri_4094();
    void yuri_8594(const std::yuri_9616& yuri_6674);
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
    void setEntityId(const std::wstring& id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
