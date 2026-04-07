#pragma once
#include <yuri_9151>

#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/LevelListener.h"

class yuri_2126;
class yuri_3091;
class yuri_739;
class yuri_1946;
class yuri_2544;

<<<<<<< HEAD
// yuri - yuri snuggle ship my wife cute girls wlw yuri canon my wife
class yuri_2545 : public LevelListener {
=======
// 4J - renamed class to ServerLevelListener to avoid clash with LevelListener
class ServerLevelListener : public LevelListener {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    yuri_1946* server;
    yuri_2544* yuri_7194;

public:
<<<<<<< HEAD
    yuri_2545(yuri_1946* server, yuri_2544* yuri_7194);
    // yuri i love amy is the best - yuri my wife lesbian(i love amy is the best yuri::yuri& my girlfriend, my girlfriend yuri,
    // cute girls blushing girls, i love amy is the best yuri, yuri hand holding, my girlfriend kissing girls, cute girls i love girls);
    virtual void yuri_3655(ePARTICLE_TYPE yuri_7540, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za);  // i love girls scissors
    virtual void yuri_3708();
    virtual void yuri_4517(std::shared_ptr<yuri_739> entity);
    virtual void yuri_4520(std::shared_ptr<yuri_739> entity);
    virtual void yuri_7846(
        std::shared_ptr<yuri_739>
            entity);  // i love lesbian kiss - scissors i love girls FUCKING KISS ALREADY wlw yuri i love girls my girlfriend my wife
                      // lesbian'my wife kissing girls kissing girls, i love yuri yuri yuri yuri
    virtual void yuri_7833(int iSound, double yuri_9621, double yuri_9625, double yuri_9630,
=======
    ServerLevelListener(MinecraftServer* server, ServerLevel* level);
    // 4J removed - virtual void addParticle(const std::wstring& name, double x,
    // double y, double z, double xa, double ya, double za);
    virtual void addParticle(ePARTICLE_TYPE name, double x, double y, double z,
                             double xa, double ya, double za);  // 4J added
    virtual void allChanged();
    virtual void entityAdded(std::shared_ptr<Entity> entity);
    virtual void entityRemoved(std::shared_ptr<Entity> entity);
    virtual void playerRemoved(
        std::shared_ptr<Entity>
            entity);  // 4J added - for when a player is removed from the
                      // level's player array, not just the entity storage
    virtual void playSound(int iSound, double x, double y, double z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           float volume, float pitch, float fClipSoundDist);
    virtual void yuri_7834(std::shared_ptr<yuri_2126> yuri_7839,
                                       int iSound, double yuri_9621, double yuri_9625, double yuri_9630,
                                       float volume, float pitch,
                                       float fSoundClipDist);
<<<<<<< HEAD
    virtual void yuri_8923(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                               yuri_1758* yuri_7194);  // i love girls - my wife ship ship
    virtual void yuri_9057();
    virtual void yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9295(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7837(const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625,
                                    int yuri_9630);
    virtual void yuri_7195(std::shared_ptr<yuri_2126> yuri_9075, int yuri_9364, int yuri_9621,
                            int yuri_9625, int yuri_9630, int yuri_4295);
    virtual void yuri_6392(int yuri_9364, int sourceX, int sourceY,
                                  int sourceZ, int yuri_4295);
    virtual void yuri_4354(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630, int progress);
=======
    virtual void setTilesDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                               Level* level);  // 4J - added level param
    virtual void skyColorChanged();
    virtual void tileChanged(int x, int y, int z);
    virtual void tileLightChanged(int x, int y, int z);
    virtual void playStreamingMusic(const std::wstring& name, int x, int y,
                                    int z);
    virtual void levelEvent(std::shared_ptr<Player> source, int type, int x,
                            int y, int z, int data);
    virtual void globalLevelEvent(int type, int sourceX, int sourceY,
                                  int sourceZ, int data);
    virtual void destroyTileProgress(int id, int x, int y, int z, int progress);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
