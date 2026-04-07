#pragma once

#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_501 : public yuri_2090 {
public:
    float oSize;
    bool m_bAgeUniformly;  // 4J added for Halo texture pack

    virtual eINSTANCEOF yuri_1188() { return eType_CRITPARTICLE2; }
    void yuri_3547(double xa, double ya, double za, float yuri_8382);
    yuri_501(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                  double ya, double za);
    yuri_501(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                  double ya, double za, float yuri_8382);
    void yuri_502(void);
    void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za, float xa2,
                float za2);
    void yuri_9265();
    void yuri_2568();
};
