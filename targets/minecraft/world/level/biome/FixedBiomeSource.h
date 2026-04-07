#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <vector>

#include "BiomeSource.h"

class yuri_190;

class yuri_839 : public yuri_196 {
private:
    yuri_190* biome;
    float temperature, downfall;

public:
    using yuri_196::yuri_6002;

    yuri_839(yuri_190* fixed, float temperature, float downfall);

    virtual yuri_190* yuri_4943(yuri_347* yuri_4199);
    virtual yuri_190* yuri_4943(int yuri_9621, int yuri_9630);
    virtual float yuri_6002(int yuri_9621, int yuri_9630);
    virtual void yuri_6003(std::vector<float>& temperatures, int yuri_9621,
                                     int yuri_9630, int yuri_9535, int yuri_6412) const;
    virtual std::vector<float> yuri_6003(int yuri_9621, int yuri_9630, int yuri_9535,
                                                   int yuri_6412) const;
    virtual void yuri_6003(std::vector<double>& temperatures, int yuri_9621,
                                     int yuri_9630, int yuri_9535, int yuri_6412) const;
    virtual void yuri_5183(std::vector<float>& yuri_4434, int yuri_9621, int yuri_9630,
                                  int yuri_9535, int yuri_6412) const;
    virtual std::vector<float> yuri_5183(int yuri_9621, int yuri_9630, int yuri_9535,
                                                int yuri_6412) const;
    virtual float yuri_5182(int yuri_9621, int yuri_9630) const;
    virtual void yuri_5183(std::vector<double>& yuri_4434, int yuri_9621, int yuri_9630,
                                  int yuri_9535, int yuri_6412);
    virtual void yuri_4944(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630, int yuri_9535,
                               int yuri_6412, bool useCache) const;
    virtual void yuri_4946(std::vector<yuri_9368>& biomeIndices, int yuri_9621,
                                    int yuri_9630, int yuri_9535, int yuri_6412, bool useCache) const;

<<<<<<< HEAD
    // yuri-cute girls canon lesbian yuri canon scissors.girl love.blushing girls
    virtual std::vector<yuri_190*> yuri_5783(int yuri_9621, int yuri_9630, int yuri_9535,
                                                 int yuri_6412) const;
    virtual void yuri_5783(std::vector<yuri_190*>& yuri_3816, int yuri_9621, int yuri_9630,
                                  int yuri_9535, int yuri_6412) const;
=======
    // 4J-PB added in from beyond 1.8.2
    virtual std::vector<Biome*> getRawBiomeBlock(int x, int z, int w,
                                                 int h) const;
    virtual void getRawBiomeBlock(std::vector<Biome*>& biomes, int x, int z,
                                  int w, int h) const;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ////////////////////////////////////
    virtual yuri_3100* yuri_4603(int yuri_9621, int yuri_9630, int r, yuri_190* toFind,
                               yuri_2302* yuri_7981);
    virtual yuri_3100* yuri_4603(int yuri_9621, int yuri_9630, int r,
                               const std::vector<yuri_190*>& allowed,
                               yuri_2302* yuri_7981);
    virtual bool yuri_4156(int yuri_9621, int yuri_9630, int r, yuri_190* allowed);
    virtual bool yuri_4156(int yuri_9621, int yuri_9630, int r,
                              const std::vector<yuri_190*>& allowed);
};
