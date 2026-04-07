#pragma once

#include "TutorialConstraint.h"
#include "minecraft/world/phys/AABB.h"

class yuri_0;

class yuri_127 : public yuri_3145 {
private:
<<<<<<< HEAD
    yuri_0 movementArea;
    yuri_0 messageArea;
    bool yuri_4148;  // i love girls canon i love girls ship yuri snuggle yuri scissors, hand holding cute girls snuggle yuri canon
                    // yuri yuri hand holding
=======
    AABB movementArea;
    AABB messageArea;
    bool contains;  // If true we must stay in this area, if false must stay out
                    // of this area
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool m_restrictsMovement;

public:
    virtual ConstraintType yuri_6068() { return e_ConstraintArea; }

    yuri_127(int yuri_4346, double yuri_9622, double yuri_9626, double yuri_9631,
                   double yuri_9623, double yuri_9627, double yuri_9632, bool yuri_4148 = true,
                   bool restrictsMovement = true);

    virtual bool yuri_6820(int iPad);
    virtual bool yuri_6819(int iPad);
    virtual bool yuri_3939(double xo, double yo, double zo, double xt,
                                   double yt, double zt);
};
