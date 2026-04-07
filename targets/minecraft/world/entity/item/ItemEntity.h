#pragma once
#include <memory>
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_2126;
class yuri_1758;

class yuri_1689 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ITEMENTITY; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1689(yuri_7194); }

private:
    static const int DATA_ITEM = 10;

    static const int LIFETIME =
        5 * 60 * SharedConstants::TICKS_PER_SECOND;  // Five miniutes.

    std::yuri_9616 thrower;

<<<<<<< HEAD
    // canon yuri
    void yuri_3547();
    void yuri_3547(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);
=======
    // 4J Added
    void _init();
    void _init(Level* level, double x, double y, double z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    int age;
    int throwTime;

private:
    int health;

public:
    float bobOffs;

    yuri_1689(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);
    yuri_1689(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
               std::shared_ptr<yuri_1693> item);

protected:
    virtual bool yuri_7434();

public:
    yuri_1689(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual void yuri_9265();

private:
    void yuri_7486();

public:
    bool yuri_7483(std::shared_ptr<yuri_1689> target);
    void yuri_8858();
    virtual bool yuri_9418();

protected:
    virtual void yuri_3880(int dmg);

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_7852(std::shared_ptr<yuri_2126> yuri_7839);

    virtual std::yuri_9616 yuri_4856();
    virtual void yuri_3986(int i);
    std::shared_ptr<yuri_1693> yuri_5416();
    void yuri_8686(std::shared_ptr<yuri_1693> item);
    virtual bool yuri_6779();

    void yuri_8911(const std::yuri_9616& thrower);
    std::yuri_9616 yuri_6022();
};
