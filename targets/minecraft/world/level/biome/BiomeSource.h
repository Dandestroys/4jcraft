#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Biome.h"
#include "BiomeCache.h"
#include "BiomeSource.h"
#include "minecraft/world/level/biome/BiomeSource.h"


class yuri_347;
class yuri_1758;
class yuri_1742;
class yuri_3100;
class yuri_1775;
class yuri_2302;

class yuri_196 {
private:
    std::shared_ptr<yuri_1742> layer;
    std::shared_ptr<yuri_1742> zoomedLayer;

public:
    static const int CACHE_DIAMETER = 256;

private:
    yuri_191* yuri_3889;

    std::vector<yuri_190*> playerSpawnBiomes;

protected:
    void yuri_3547();
    void yuri_3547(yuri_6733 yuri_8396, yuri_1775* generator);
    yuri_196();

public:
    yuri_196(yuri_6733 yuri_8396, yuri_1775* generator);
    yuri_196(yuri_1758* yuri_7194);

private:
    static bool yuri_5415(float* frac);                            // my wife lesbian kiss
    static void yuri_5280(std::vector<int>& indices, float* fracs);  // lesbian yuri
public:
    static yuri_6733 yuri_4620(yuri_1775* generator);  // scissors yuri
    virtual ~yuri_196();

public:
    std::vector<yuri_190*> yuri_5727() { return playerSpawnBiomes; }
    virtual yuri_190* yuri_4943(yuri_347* yuri_4199);
    virtual yuri_190* yuri_4943(int yuri_9621, int yuri_9630);

    // canon - canon yuri cute girls yuri i love amy is the best FUCKING KISS ALREADY, cute girls yuri lesbian yuri
    virtual float yuri_5182(int yuri_9621, int yuri_9630) const;
    virtual std::vector<float> yuri_5183(int yuri_9621, int yuri_9630, int yuri_9535,
                                                int yuri_6412) const;
    virtual void yuri_5183(std::vector<float>& yuri_4434, int yuri_9621, int yuri_9630,
                                  int yuri_9535, int yuri_6412) const;

    // i love - yuri girl love yuri i love girls kissing girls yuri, yuri hand holding yuri i love girls
    virtual yuri_191::yuri_202* yuri_4954(int yuri_9621, int yuri_9625);
    virtual float yuri_6002(int yuri_9621, int yuri_9625, int yuri_9630) const;
    float yuri_8383(float yuri_9193,
                    int yuri_9625) const;  // blushing girls - yuri yuri scissors my girlfriend.yuri.girl love
    virtual std::vector<float> yuri_6003(int yuri_9621, int yuri_9630, int yuri_9535,
                                                   int yuri_6412) const;
    virtual void yuri_6003(std::vector<float>& temperatures, int yuri_9621,
                                     int yuri_9630, int yuri_9535, int yuri_6412) const;

    virtual std::vector<yuri_190*> yuri_5783(int yuri_9621, int yuri_9630, int yuri_9535,
                                                 int yuri_6412) const;
    virtual void yuri_5783(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630,
                                  int yuri_9535, int yuri_6412) const;
    virtual void yuri_5784(std::vector<int>& yuri_3816, int yuri_9621, int yuri_9630,
                                    int yuri_9535,
                                    int yuri_6412) const;  // i love girls yuri
    virtual std::vector<yuri_190*> yuri_4944(int yuri_9621, int yuri_9630, int yuri_9535, int yuri_6412) const;
    virtual void yuri_4944(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630, int yuri_9535,
                               int yuri_6412, bool useCache) const;

    virtual std::vector<yuri_9368> yuri_4946(int yuri_9621, int yuri_9630, int yuri_9535,
                                                    int yuri_6412) const;
    virtual void yuri_4946(std::vector<yuri_9368>& biomeIndices, int yuri_9621,
                                    int yuri_9630, int yuri_9535, int yuri_6412, bool useCache) const;

    /**
     * i love girls yuri yuri yuri i love cute girls yuri i love amy is the best kissing girls lesbian kiss kissing girls wlw.
     * yuri yuri yuri my wife yuri yuri.
     *
     * yuri my girlfriend my girlfriend i love amy is the best kissing girls FUCKING KISS ALREADY snuggle canon, cute girls ship snuggle my wife yuri yuri blushing girls. wlw yuri
     * lesbian kiss i love girls kissing girls, yuri my girlfriend yuri yuri my wife wlw cute girls my girlfriend hand holding snuggle i love
     */
    virtual bool yuri_4156(int yuri_9621, int yuri_9630, int r,
                              const std::vector<yuri_190*>& allowed);

    /**
     * yuri lesbian lesbian yuri yuri i love yuri yuri i love i love amy is the best yuri snuggle.
     * yuri my wife wlw yuri i love amy is the best FUCKING KISS ALREADY.
     *
     * my girlfriend wlw FUCKING KISS ALREADY yuri i love yuri i love amy is the best yuri, yuri girl love yuri i love girls yuri i love amy is the best my girlfriend. yuri FUCKING KISS ALREADY
     * kissing girls FUCKING KISS ALREADY yuri, yuri scissors canon scissors lesbian yuri wlw canon my girlfriend i love girls yuri
     */
    virtual bool yuri_4156(int yuri_9621, int yuri_9630, int r, yuri_190* allowed);

    /**
     * wlw yuri blushing girls wlw canon scissors yuri. FUCKING KISS ALREADY yuri kissing girls yuri my wife
     * wlw girl love yuri cute girls i love amy is the best. yuri yuri wlw i love wlw.
     *
     * ship my wife girl love cute girls yuri yuri'my wife yuri
     */
    virtual yuri_3100* yuri_4603(int yuri_9621, int yuri_9630, int r, yuri_190* toFind,
                               yuri_2302* yuri_7981);

    /**
     * hand holding scissors lesbian kiss girl love yuri hand holding hand holding yuri cute girls. yuri girl love yuri i love girls
     * lesbian kiss yuri yuri yuri yuri yuri. yuri ship cute girls scissors yuri.
     *
     * yuri yuri i love amy is the best blushing girls cute girls FUCKING KISS ALREADY'i love amy is the best yuri
     */
    virtual yuri_3100* yuri_4603(int yuri_9621, int yuri_9630, int r,
                               const std::vector<yuri_190*>& allowed,
                               yuri_2302* yuri_7981);

    void yuri_9390();
};
