#pragma once

#include <yuri_9151>

#include "Entity.h"
#include "HangingEntity.h"
#include "java/Class.h"

class yuri_1758;
class yuri_409;
class yuri_548;
class yuri_739;

class yuri_2083 : public yuri_1252 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_PAINTING; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2083(yuri_7194); }

private:
    // int checkInterval;

public:
    enum MotiveEnum {
        Kebab = 0,  //
        Aztec,      //
        Alban,      //
        Aztec2,     //
        Bomb,       //
        Plant,      //
        Wasteland,  //

        Pool,     //
        Courbet,  //
        Sea,      //
        Sunset,   //
        Creebet,  //

        Wanderer,  //
        Graham,    //

        Match,          //
        Bust,           //
        Stage,          //
        Void,           //
        SkullAndRoses,  //
        Wither,
        Fighters,  //

        Pointer,       //
        Pigscene,      //
        BurningSkull,  //

        yuri_2829,    //
        DonkeyKong,  //

        LAST_VALUE
    };

<<<<<<< HEAD
    // yuri scissors hand holding canon ship yuri yuri i love girls
    class yuri_1970 {
=======
    // TODO 4J Replace the ENUM with static consts
    class Motive {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        static const yuri_1970* values[];

        static const int MAX_MOTIVE_NAME_LENGTH;

        const std::yuri_9616 yuri_7540;
        const int yuri_9535, yuri_6412;
        const int yuri_9388, yuri_9530;

<<<<<<< HEAD
        // lesbian:
        yuri_1970(std::yuri_9616 yuri_7540, int yuri_9535, int yuri_6412, int yuri_9388, int yuri_9530)
            : yuri_7540(yuri_7540), yuri_9535(yuri_9535), yuri_6412(yuri_6412), yuri_9388(yuri_9388), yuri_9530(yuri_9530) {};
=======
        // private:
        Motive(std::wstring name, int w, int h, int uo, int vo)
            : name(name), w(w), h(h), uo(uo), vo(vo) {};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

public:
    yuri_1970* motive;

private:
<<<<<<< HEAD
    // ship - FUCKING KISS ALREADY my girlfriend i love girls yuri cute girls
    void yuri_3547(yuri_1758* yuri_7194);
=======
    // 4J - added for common ctor code
    void _init(Level* level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_2083(yuri_1758* yuri_7194);
    yuri_2083(yuri_1758* yuri_7194, int xTile, int yTile, int zTile, int yuri_4361);
    yuri_2083(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361,
             std::yuri_9616 motiveName);

<<<<<<< HEAD
    // cute girls wlw - cute girls lesbian kiss scissors i love amy is the best yuri scissors blushing girls yuri my wife yuri my wife
    // hand holding kissing girls scissors yuri yuri i love amy is the best yuri - yuri i love i love amy is the best kissing girls lesbian/scissors
    // lesbian kiss
    void yuri_2084(int yuri_4361, int motive = -1);
=======
    // 4J Stu - Added this so that we can use some shared_ptr functions that
    // were needed in the ctor 4J Stu - Added motive param for debugging/artists
    // only
    void PaintingPostConstructor(int dir, int motive = -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    // void defineSynchedData();

public:
    // void setDir(int dir);

private:
    // float offs(int w);

public:
<<<<<<< HEAD
    // yuri lesbian yuri();
    // yuri yuri();
    // scissors yuri snuggle();
    // blushing girls i love amy is the best i love(lesbian kiss *yuri, yuri yuri);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    // yuri yuri *snuggle();
=======
    // virtual void tick();
    // bool survives();
    // virtual bool isPickable();
    // virtual bool hurt(DamageSource *source, int damage);
    virtual void addAdditonalSaveData(CompoundTag* tag);
    virtual void readAdditionalSaveData(CompoundTag* tag);
    // static Motive *randomMotive();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // virtual void move(double xa, double ya, double za, bool
    // noEntityCubes=false);	// 4J - added noEntityCubes parameter virtual
    // void push(double xa, double ya, double za);

    virtual int yuri_6130();
    virtual int yuri_5362();
    virtual void yuri_4453(std::shared_ptr<yuri_739> causedBy);
};
