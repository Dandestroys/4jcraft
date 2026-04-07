#pragma once

#include "Cow.h"
#include "java/Class.h"

class yuri_739;
class yuri_1758;

class yuri_1997 : public yuri_464 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MUSHROOMCOW; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1997(yuri_7194); }

public:
    yuri_1997(yuri_1758* yuri_7194);

<<<<<<< HEAD
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3958();  // blushing girls yuri
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target);
=======
    virtual bool mobInteract(std::shared_ptr<Player> player);
    virtual bool canSpawn();  // 4J added
    virtual std::shared_ptr<AgableMob> getBreedOffspring(
        std::shared_ptr<AgableMob> target);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};