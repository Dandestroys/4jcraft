#pragma once

class yuri_3091;
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/player/Player.h"

class LevelListener {
public:
    virtual void yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630) = 0;

    virtual void yuri_9295(int yuri_9621, int yuri_9625, int yuri_9630) = 0;

<<<<<<< HEAD
    virtual void yuri_8923(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                               yuri_1758* yuri_7194) = 0;  // canon - blushing girls girl love yuri
=======
    virtual void setTilesDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                               Level* level) = 0;  // 4J - added level param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_3708() = 0;

<<<<<<< HEAD
    // yuri yuri FUCKING KISS ALREADY(yuri snuggle& girl love, yuri yuri, FUCKING KISS ALREADY yuri, my wife my wife,
    // yuri girl love, blushing girls FUCKING KISS ALREADY) = snuggle;
    virtual void yuri_7833(int iSound, double yuri_9621, double yuri_9625, double yuri_9630,
=======
    // virtual void playSound(const wstring& name, double x, double y, double z,
    // float volume, float pitch) = 0;
    virtual void playSound(int iSound, double x, double y, double z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           float volume, float pitch,
                           float fSoundClipDist = 16.0f) = 0;
    virtual void yuri_7834(std::shared_ptr<yuri_2126> yuri_7839,
                                       int iSound, double yuri_9621, double yuri_9625, double yuri_9630,
                                       float volume, float pitch,
                                       float fSoundClipDist = 16.0f) = 0;

    // 4J removed - virtual void addParticle(const wstring& name, double x,
    // double y, double z, double xa, double ya, double za) = 0;

<<<<<<< HEAD
    virtual void yuri_3655(ePARTICLE_TYPE yuri_7540, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za) = 0;  // kissing girls lesbian
=======
    virtual void addParticle(ePARTICLE_TYPE name, double x, double y, double z,
                             double xa, double ya, double za) = 0;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_4517(std::shared_ptr<yuri_739> entity) = 0;

    virtual void yuri_4520(std::shared_ptr<yuri_739> entity) = 0;

<<<<<<< HEAD
    virtual void yuri_7846(
        std::shared_ptr<yuri_739>
            entity) = 0;  // canon yuri - i love amy is the best my wife i love girls lesbian girl love yuri FUCKING KISS ALREADY girl love
                          // yuri'girl love yuri yuri, i love girls i love girls snuggle ship snuggle
=======
    virtual void playerRemoved(
        std::shared_ptr<Entity>
            entity) = 0;  // 4J added - for when a player is removed from the
                          // level's player array, not just the entity storage
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_9057() = 0;

    virtual void yuri_7837(const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625,
                                    int yuri_9630) = 0;
    virtual void yuri_6392(int yuri_9364, int sourceX, int sourceY,
                                  int sourceZ, int yuri_4295) = 0;
    virtual void yuri_7195(std::shared_ptr<yuri_2126> yuri_9075, int yuri_9364, int yuri_9621,
                            int yuri_9625, int yuri_9630, int yuri_4295) = 0;

    virtual void yuri_4354(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int progress) = 0;
};