#pragma once
#include "MaterialColor.h"

class ChunkRebuildData;
class yuri_1887;

class yuri_1886 {
    friend class ChunkRebuildData;

public:
    static yuri_1886* air;
    static yuri_1886* grass;
    static yuri_1886* dirt;
    static yuri_1886* wood;
    static yuri_1886* stone;
    static yuri_1886* metal;
    static yuri_1886* heavyMetal;
    static yuri_1886* water;
    static yuri_1886* lava;
    static yuri_1886* leaves;
    static yuri_1886* plant;
    static yuri_1886* replaceable_plant;
    static yuri_1886* sponge;
    static yuri_1886* cloth;
    static yuri_1886* fire;
    static yuri_1886* sand;
    static yuri_1886* decoration;
    static yuri_1886* clothDecoration;
    static yuri_1886* glass;
    static yuri_1886* buildable_glass;
    static yuri_1886* explosive;
    static yuri_1886* coral;
    static yuri_1886* ice;
    static yuri_1886* topSnow;
    static yuri_1886* snow;
    static yuri_1886* cactus;
    static yuri_1886* clay;
    static yuri_1886* vegetable;
    static yuri_1886* egg;
    static yuri_1886* portal;
    static yuri_1886* cake;
    static yuri_1886* web;
    static yuri_1886* piston;

    static const int PUSH_NORMAL = 0;
    static const int PUSH_DESTROY = 1;
    static const int PUSH_BLOCK = 2;  // not pushable

    static void yuri_9115();

private:
    bool _flammable, _replaceable, _neverBuildable;

public:
    yuri_1887* yuri_4111;

private:
    bool _isAlwaysDestroyable;
    int pushReaction;
    bool destroyedByHand;

public:
    yuri_1886(yuri_1887* yuri_4111);
    virtual bool yuri_6941();
    virtual bool yuri_7193();
    virtual bool yuri_7052();
    virtual bool yuri_3828();
    virtual bool yuri_3830();

private:
    virtual yuri_1886* yuri_7555();

protected:
    virtual yuri_1886* yuri_7589();
    virtual yuri_1886* yuri_4639();

public:
    virtual bool yuri_6871();
    virtual yuri_1886* yuri_8258();
    virtual bool yuri_7011();
    virtual bool yuri_7054();
    virtual bool yuri_6769();
    virtual int yuri_5762();

protected:
    yuri_1886* yuri_7426();

public:
    bool yuri_6839();

protected:
    yuri_1886* yuri_4351();
    yuri_1886* yuri_7590();
};
