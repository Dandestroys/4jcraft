#pragma once

#include <memory>

#include "PathfinderMob.h"

class yuri_1758;

class yuri_99 : public yuri_2096 {
private:
    static const int DATA_AGE_ID = 12;

public:
    static const int BABY_START_AGE = -20 * 60 * 20;

private:
    float registeredBBWidth;
    float registeredBBHeight;

public:
    yuri_99(yuri_1758* yuri_7194);

    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);

protected:
    virtual void yuri_4329();

public:
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target) = 0;
    virtual int yuri_4870();
    virtual void yuri_3703(int seconds);
    virtual void yuri_8443(int age);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_3704();
    virtual bool yuri_6781();
    virtual void yuri_9463(bool yuri_6781);

protected:
    virtual void yuri_8864(float yuri_9535, float yuri_6412);
    void yuri_6738(float yuri_8382);
};