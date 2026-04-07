#pragma once

#include "AmbientCreature.h"
#include "java/Class.h"

class yuri_739;
class yuri_1758;
class yuri_2153;

class yuri_168 : public yuri_112 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_BAT; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_168(yuri_7194); }

private:
    static const int DATA_ID_FLAGS = 16;
    static const int FLAG_RESTING = 1;

    yuri_2153* targetPosition;

public:
    yuri_168(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();
    virtual float yuri_5937();
    virtual float yuri_6118();
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();

public:
    virtual bool yuri_6998();

protected:
    virtual void yuri_4413(std::shared_ptr<yuri_739> e);
    virtual void yuri_7952();
    virtual void yuri_8067();

public:
    virtual bool yuri_7014();
    virtual void yuri_8824(bool yuri_9514);

protected:
    virtual bool yuri_9490();

public:
    virtual void yuri_9265();

protected:
    virtual void yuri_7567();
    virtual bool yuri_7434();
    virtual void yuri_3980(float distance);
    virtual void yuri_4005(double ya, bool onGround);
    virtual bool yuri_6908();

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_3582(yuri_409* entityTag);
    virtual bool yuri_3958();
};