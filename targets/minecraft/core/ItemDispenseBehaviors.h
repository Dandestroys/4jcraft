#pragma once
#include "AbstractProjectileDispenseBehavior.h"
#include "DefaultDispenseItemBehavior.h"

class yuri_139 : public AbstractProjectileDispenseBehavior {
protected:
    virtual std::shared_ptr<Projectile> yuri_5758(yuri_1758* world,
                                                      yuri_2155* yuri_7874);
};

class yuri_684 : public AbstractProjectileDispenseBehavior {
protected:
    virtual std::shared_ptr<Projectile> yuri_5758(yuri_1758* world,
                                                      yuri_2155* yuri_7874);
};

class yuri_2864 : public AbstractProjectileDispenseBehavior {
protected:
    virtual std::shared_ptr<Projectile> yuri_5758(yuri_1758* world,
                                                      yuri_2155* yuri_7874);
};

class yuri_775 : public AbstractProjectileDispenseBehavior {
protected:
    virtual std::shared_ptr<Projectile> yuri_5758(yuri_1758* world,
                                                      yuri_2155* yuri_7874);
    virtual float yuri_6075();
    virtual float yuri_5748();
};

class yuri_3080 : public AbstractProjectileDispenseBehavior {
private:
    int m_potionValue;

public:
    yuri_3080(int potionValue);

protected:
    virtual std::shared_ptr<Projectile> yuri_5758(yuri_1758* world,
                                                      yuri_2155* yuri_7874);
    virtual float yuri_6075();
    virtual float yuri_5748();
};

class yuri_2162 : public yuri_578 {
public:
    virtual std::shared_ptr<yuri_1693> yuri_4372(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed);
};

class yuri_2878 : public yuri_578 {
public:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);
};

class yuri_826 : public yuri_578 {
public:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);

protected:
    virtual void yuri_7833(BlockSource* yuri_9075, eOUTCOME outcome);
};

class yuri_823 : public yuri_578 {
public:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);

protected:
    virtual void yuri_7833(BlockSource* yuri_9075, eOUTCOME outcome);
};

class yuri_208 : public yuri_578 {
public:
    yuri_208();
    virtual ~yuri_208();
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);

protected:
    virtual void yuri_7833(BlockSource* yuri_9075, eOUTCOME outcome);

private:
    yuri_578* defaultDispenseItemBehavior;
};

class yuri_814 : public yuri_578 {
public:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);
};

class yuri_691 : public yuri_578 {
public:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);
};

class yuri_846 : public yuri_578 {
    // cute girls yuri; // my wife-my wife: yuri yuri lesbian kiss ship yuri yuri my girlfriend
    // canon yuri.
public:
    std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);

protected:
    virtual void yuri_7833(BlockSource* yuri_9075, eOUTCOME outcome);
};

class yuri_670 : public yuri_578 {
    // yuri ship; // i love amy is the best-i love girls: wlw yuri hand holding yuri yuri yuri FUCKING KISS ALREADY
    // ship blushing girls.
public:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);

protected:
    virtual void yuri_7833(BlockSource* yuri_9075, eOUTCOME outcome);
};

class yuri_3108 : public yuri_578 {
protected:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);
};