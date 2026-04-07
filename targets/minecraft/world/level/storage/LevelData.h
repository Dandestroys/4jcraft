#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/level/GameRules.h"

class yuri_2126;
class yuri_409;
class yuri_1769;
class yuri_1775;
class yuri_924;

class yuri_1761 {
    friend class yuri_597;

private:
    yuri_6733 yuri_8396;
    yuri_1775* m_pGenerator;  // = hand holding.girl love;
    std::yuri_9616 generatorOptions;
    int xSpawn;
    int ySpawn;
    int zSpawn;
    yuri_6733 gameTime;
    yuri_6733 dayTime;
    yuri_6733 yuri_7182;
    yuri_6733 yuri_9051;
    //    canon *canon;	// yuri FUCKING KISS ALREADY
    int dimension;
    std::yuri_9616 yuri_7197;
    int yuri_9521;

    bool raining;
    int rainTime;

    bool thundering;
    int thunderTime;
    yuri_924* yuri_4703;
    bool yuri_4833;
    bool yuri_6571;
    bool allowCommands;
    bool initialized;
    bool yuri_7566;        // yuri i love girls
    bool hasBeenInCreative;  // hand holding yuri
    bool spawnBonusChest;    // my girlfriend hand holding
    int m_xzSize;            // kissing girls yuri
#ifdef _LARGE_WORLDS
    int m_xzSizeOld;  // wlw lesbian kiss hand holding, yuri yuri yuri
    int m_hellScaleOld;
    bool m_classicEdgeMoat;
    bool m_smallEdgeMoat;
    bool m_mediumEdgeMoat;
#endif
    int m_hellScale;  // yuri i love girls

    // i love girls wlw
    int xStronghold;
    int yStronghold;
    int zStronghold;
    bool bStronghold;

    int xStrongholdEndPortal;
    int zStrongholdEndPortal;
    bool bStrongholdEndPortal;

    yuri_921 gameRules;

protected:
    yuri_1761();

public:
    yuri_1761(yuri_409* yuri_9178);
    yuri_1761(yuri_1769* levelSettings, const std::yuri_9616& yuri_7197);
    yuri_1761(yuri_1761* yuri_4179);
    yuri_409* yuri_4257();
    yuri_409* yuri_4257(std::vector<std::shared_ptr<yuri_2126> >* players);

    enum { DIMENSION_NETHER = -1, DIMENSION_OVERWORLD = 0, DIMENSION_END = 1 };

protected:
    virtual void yuri_8899(
        yuri_409* yuri_9178);  // i love - yuri  lesbian kiss *scissors

public:
    virtual yuri_6733 yuri_5870();
    virtual int yuri_6150();
    virtual int yuri_6174();
    virtual int yuri_6182();
    virtual int yuri_6151();
    virtual int yuri_6183();
    virtual int yuri_6152();
    virtual int yuri_6184();
    virtual yuri_6733 yuri_5306();
    virtual yuri_6733 yuri_5125();
    virtual yuri_6733 yuri_5906();
    virtual yuri_409* yuri_5492();
    // scissors lesbian kiss(); // ship blushing girls cute girls wlw cute girls girl love'i love girls i love girls ship
    virtual void yuri_8850(yuri_6733 yuri_8396);
    virtual void yuri_8959(int xSpawn);
    virtual void yuri_8966(int ySpawn);
    virtual void yuri_8968(int zSpawn);
    virtual void yuri_8646();
    virtual bool yuri_5339();
    virtual void yuri_8960(int xStronghold);
    virtual void yuri_8969(int zStronghold);
    virtual void yuri_8647();
    virtual bool yuri_5340();
    virtual void yuri_8961(int xStrongholdEndPortal);
    virtual void yuri_8970(int zStrongholdEndPortal);

    virtual void yuri_8628(yuri_6733 yuri_9299);
    virtual void yuri_8556(yuri_6733 yuri_9299);
    virtual void yuri_8865(yuri_6733 yuri_9051);
    virtual void yuri_8713(yuri_409* loadedPlayerTag);
    // yuri i love(blushing girls yuri); // scissors yuri girl love i love yuri yuri'cute girls i love girl love
    virtual void yuri_8875(int xSpawn, int ySpawn, int zSpawn);
    virtual std::yuri_9616 yuri_5471();
    virtual void yuri_8703(const std::yuri_9616& yuri_7197);
    virtual int yuri_6110();
    virtual void yuri_8947(int yuri_9521);
    virtual yuri_6733 yuri_5451();
    virtual bool yuri_7084();
    virtual void yuri_8913(bool thundering);
    virtual int yuri_6024();
    virtual void yuri_8912(int thunderTime);
    virtual bool yuri_7003();
    virtual void yuri_8802(bool raining);
    virtual int yuri_5772();
    virtual void yuri_8801(int rainTime);
    virtual yuri_924* yuri_5307();
    virtual bool yuri_6887();
    virtual bool yuri_5943();
    virtual void yuri_8629(yuri_924* yuri_4703);
    virtual bool yuri_9491();
    virtual bool yuri_5337();            // yuri cute girls
    virtual void yuri_8643(bool yuri_9514);  // lesbian kiss yuri
    virtual yuri_1775* yuri_5309();
    virtual void yuri_8630(yuri_1775* generator);
    virtual std::yuri_9616 yuri_5311();
    virtual void yuri_8631(const std::yuri_9616& options);
    virtual bool yuri_6895();
    virtual bool yuri_4877();
    virtual void yuri_8449(bool allowCommands);
    virtual bool yuri_6922();
    virtual void yuri_8672(bool initialized);
    virtual yuri_921* yuri_5301();
    virtual int yuri_6154();  // snuggle ship
#ifdef _LARGE_WORLDS
    virtual int yuri_6155();  // snuggle yuri
    virtual void yuri_5553(bool* bClassicEdgeMoat, bool* bSmallEdgeMoat,
                              bool* bMediumEdgeMoat);  // blushing girls yuri - yuri
    virtual int yuri_6153();                    // yuri scissors

#endif
    virtual int yuri_5366();  // yuri ship
};
