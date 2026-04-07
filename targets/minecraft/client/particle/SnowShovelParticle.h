#pragma once
#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_2861 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_SNOWSHOVELPARTICLE; }

private:
<<<<<<< HEAD
    void yuri_6704(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa, double ya,
              double za, float yuri_8382);  // lesbian kiss - lesbian kiss
=======
    void init(Level* level, double x, double y, double z, double xa, double ya,
              double za, float scale);  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    yuri_2861(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                       double ya, double za);
    float oSize;

    yuri_2861(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                       double ya, double za, float yuri_8382);
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                        float xa2, float za2);
    virtual void yuri_9265();
};