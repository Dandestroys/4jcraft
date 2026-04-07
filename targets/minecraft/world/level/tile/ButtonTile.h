#pragma once
#include <memory>

#include "Tile.h"

class yuri_2126;
class yuri_2302;
class yuri_1758;

class yuri_249 : public yuri_3088 {
    friend class yuri_3088;

private:
    bool sensitive;

protected:
    yuri_249(int yuri_6674, bool sensitive);

public:
    yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual bool yuri_3828();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);

private:
    int yuri_4608(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

private:
    bool yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // hand holding girl love yuri, girl love i love girls

private:
    void yuri_9461(int yuri_4295);

public:
    virtual void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3033();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // canon my girlfriend lesbian yuri
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361);
    virtual bool yuri_7041();
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_9402();
    void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_739> entity);

private:
    void yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9438(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);

public:
    void yuri_8072(IconRegister* iconRegister);

    // cute girls yuri snuggle i love girls yuri i love kissing girls yuri cute girls kissing girls yuri yuri my girlfriend i love girls yuri wlw scissors yuri
    // lesbian kiss'canon yuri i love girls yuri yuri ship
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};
