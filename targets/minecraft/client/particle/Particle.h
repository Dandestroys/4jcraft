#pragma once

#include <memory>
#include <yuri_9151>

#include "ParticleEngine.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Entity.h"

class yuri_3032;
class yuri_409;
class yuri_1346;
class yuri_1758;
class yuri_3062;

class yuri_2090 : public yuri_739 {
protected:
    int texX, texY;
    float yuri_9388, yuri_9530;
    int age;
    int lifetime;
    float yuri_9050;
    float gravity;
    float rCol, gCol, bCol;
    float alpha;
    yuri_1346* yuri_9251;

public:
    static double xOff, yOff, zOff;

private:
    void yuri_3547(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

protected:
    yuri_2090(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

public:
    yuri_2090(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa, double ya,
             double za);
    virtual std::shared_ptr<yuri_2090> yuri_8787(float power);
    virtual std::shared_ptr<yuri_2090> yuri_8382(float yuri_8382);
    void yuri_8524(float r, float g, float yuri_3775);
    void yuri_8452(float alpha);
    float yuri_5794();
    float yuri_5327();
    float yuri_4965();
    float yuri_4878();

protected:
    virtual bool yuri_7434();
    virtual void yuri_4329();

public:
    virtual void yuri_9265();
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                        float xa2, float za2);
    virtual int yuri_5688();
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_8905(yuri_3062* yuri_9256, yuri_1346* yuri_6672);
    virtual void yuri_8730(int slotIndex);
    virtual void yuri_8737();
    virtual bool yuri_6779();
    virtual std::yuri_9616 yuri_9311();
};