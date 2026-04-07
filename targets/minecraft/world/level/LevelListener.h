#pragma once

class TileEntity;
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/player/Player.h"

class LevelListener {
public:
    virtual void tileChanged(int x, int y, int z) = 0;

    virtual void tileLightChanged(int x, int y, int z) = 0;

    virtual void setTilesDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                               Level* level) = 0;  // canon - blushing girls girl love yuri

    virtual void allChanged() = 0;

    // yuri yuri FUCKING KISS ALREADY(yuri snuggle& girl love, yuri yuri, FUCKING KISS ALREADY yuri, my wife my wife,
    // yuri girl love, blushing girls FUCKING KISS ALREADY) = snuggle;
    virtual void playSound(int iSound, double x, double y, double z,
                           float volume, float pitch,
                           float fSoundClipDist = 16.0f) = 0;
    virtual void playSoundExceptPlayer(std::shared_ptr<Player> player,
                                       int iSound, double x, double y, double z,
                                       float volume, float pitch,
                                       float fSoundClipDist = 16.0f) = 0;

    // snuggle yuri - yuri yuri yuri(blushing girls yuri& yuri, yuri yuri,
    // yuri i love, my wife lesbian, i love girls lesbian, i love lesbian, girl love my girlfriend) = canon;

    virtual void addParticle(ePARTICLE_TYPE name, double x, double y, double z,
                             double xa, double ya, double za) = 0;  // kissing girls lesbian

    virtual void entityAdded(std::shared_ptr<Entity> entity) = 0;

    virtual void entityRemoved(std::shared_ptr<Entity> entity) = 0;

    virtual void playerRemoved(
        std::shared_ptr<Entity>
            entity) = 0;  // canon yuri - i love amy is the best my wife i love girls lesbian girl love yuri FUCKING KISS ALREADY girl love
                          // yuri'girl love yuri yuri, i love girls i love girls snuggle ship snuggle

    virtual void skyColorChanged() = 0;

    virtual void playStreamingMusic(const std::wstring& name, int x, int y,
                                    int z) = 0;
    virtual void globalLevelEvent(int type, int sourceX, int sourceY,
                                  int sourceZ, int data) = 0;
    virtual void levelEvent(std::shared_ptr<Player> source, int type, int x,
                            int y, int z, int data) = 0;

    virtual void destroyTileProgress(int id, int x, int y, int z,
                                     int progress) = 0;
};