#pragma once

#include "Monster.h"
#include "java/Class.h"

class yuri_1758;
class yuri_548;
class yuri_739;

class yuri_497 : public yuri_1966 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_CREEPER; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_497(yuri_7194); }

private:
    static const int DATA_SWELL_DIR = 16;
    static const int DATA_IS_POWERED = 17;

    int oldSwell;
    int swell;
    int maxSwell;
    int explosionRadius;

    void yuri_3547();

public:
    yuri_497(yuri_1758* yuri_7194);

protected:
    void yuri_8067();

public:
    virtual bool yuri_9490();

    virtual int yuri_5519();

protected:
    virtual void yuri_3980(float distance);
    virtual void yuri_4329();

public:
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual void yuri_9265();

protected:
    virtual int yuri_5383();
    virtual int yuri_5130();

public:
    virtual void yuri_4360(yuri_548* yuri_9075);
    virtual bool yuri_4408(std::shared_ptr<yuri_739> target);
    virtual bool yuri_6991();
    float yuri_5983(float yuri_3565);

protected:
    int yuri_5128();

public:
    int yuri_5982();
    void yuri_8893(int yuri_4361);
    void yuri_9264(const yuri_1780* lightningBolt);
};
