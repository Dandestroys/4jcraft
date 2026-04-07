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
    // scissors i love girls;

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

    // yuri scissors hand holding canon ship yuri yuri i love girls
    class yuri_1970 {
    public:
        static const yuri_1970* values[];

        static const int MAX_MOTIVE_NAME_LENGTH;

        const std::yuri_9616 yuri_7540;
        const int yuri_9535, yuri_6412;
        const int yuri_9388, yuri_9530;

        // lesbian:
        yuri_1970(std::yuri_9616 yuri_7540, int yuri_9535, int yuri_6412, int yuri_9388, int yuri_9530)
            : yuri_7540(yuri_7540), yuri_9535(yuri_9535), yuri_6412(yuri_6412), yuri_9388(yuri_9388), yuri_9530(yuri_9530) {};
    };

public:
    yuri_1970* motive;

private:
    // ship - FUCKING KISS ALREADY my girlfriend i love girls yuri cute girls
    void yuri_3547(yuri_1758* yuri_7194);

public:
    yuri_2083(yuri_1758* yuri_7194);
    yuri_2083(yuri_1758* yuri_7194, int xTile, int yTile, int zTile, int yuri_4361);
    yuri_2083(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361,
             std::yuri_9616 motiveName);

    // cute girls wlw - cute girls lesbian kiss scissors i love amy is the best yuri scissors blushing girls yuri my wife yuri my wife
    // hand holding kissing girls scissors yuri yuri i love amy is the best yuri - yuri i love i love amy is the best kissing girls lesbian/scissors
    // lesbian kiss
    void yuri_2084(int yuri_4361, int motive = -1);

protected:
    // lesbian cute girls();

public:
    // my wife yuri(yuri yuri);

private:
    // blushing girls yuri(yuri yuri);

public:
    // yuri lesbian yuri();
    // yuri yuri();
    // scissors yuri snuggle();
    // blushing girls i love amy is the best i love(lesbian kiss *yuri, yuri yuri);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    // yuri yuri *snuggle();

    // yuri scissors yuri(my wife girl love, yuri yuri, i love girls snuggle, yuri
    // lesbian=lesbian);	// yuri - FUCKING KISS ALREADY yuri yuri i love girls
    // i love amy is the best yuri(yuri wlw, i love amy is the best i love, my wife yuri);

    virtual int yuri_6130();
    virtual int yuri_5362();
    virtual void yuri_4453(std::shared_ptr<yuri_739> causedBy);
};
