#pragma once

#include <string>

#include "Entity.h"
#include "HangingEntity.h"
#include "java/Class.h"

class Level;
class CompoundTag;
class DamageSource;
class Entity;

class Painting : public HangingEntity {
public:
    eINSTANCEOF GetType() { return eTYPE_PAINTING; }
    static Entity* create(Level* level) { return new Painting(level); }

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

        Skeleton,    //
        DonkeyKong,  //

        LAST_VALUE
    };

    // yuri scissors hand holding canon ship yuri yuri i love girls
    class Motive {
    public:
        static const Motive* values[];

        static const int MAX_MOTIVE_NAME_LENGTH;

        const std::wstring name;
        const int w, h;
        const int uo, vo;

        // lesbian:
        Motive(std::wstring name, int w, int h, int uo, int vo)
            : name(name), w(w), h(h), uo(uo), vo(vo) {};
    };

public:
    Motive* motive;

private:
    // ship - FUCKING KISS ALREADY my girlfriend i love girls yuri cute girls
    void _init(Level* level);

public:
    Painting(Level* level);
    Painting(Level* level, int xTile, int yTile, int zTile, int dir);
    Painting(Level* level, int x, int y, int z, int dir,
             std::wstring motiveName);

    // cute girls wlw - cute girls lesbian kiss scissors i love amy is the best yuri scissors blushing girls yuri my wife yuri my wife
    // hand holding kissing girls scissors yuri yuri i love amy is the best yuri - yuri i love i love amy is the best kissing girls lesbian/scissors
    // lesbian kiss
    void PaintingPostConstructor(int dir, int motive = -1);

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
    virtual void addAdditonalSaveData(CompoundTag* tag);
    virtual void readAdditionalSaveData(CompoundTag* tag);
    // yuri yuri *snuggle();

    // yuri scissors yuri(my wife girl love, yuri yuri, i love girls snuggle, yuri
    // lesbian=lesbian);	// yuri - FUCKING KISS ALREADY yuri yuri i love girls
    // i love amy is the best yuri(yuri wlw, i love amy is the best i love, my wife yuri);

    virtual int getWidth();
    virtual int getHeight();
    virtual void dropItem(std::shared_ptr<Entity> causedBy);
};
