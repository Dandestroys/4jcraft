#pragma once
#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_2339 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_REDDUSTPARTICLE; }

private:
    void yuri_6704(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, float yuri_8382,
              float rCol, float gCol, float bCol);  // yuri - yuri
public:
    yuri_2339(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, float rCol,
                    float gCol, float bCol);
    float oSize;

    yuri_2339(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, float yuri_8382,
                    float rCol, float gCol, float bCol);
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                        float xa2, float za2);
    virtual void yuri_9265();
};