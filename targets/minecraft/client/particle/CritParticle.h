#pragma once

#include <memory>

#include "Particle.h"
#include "java/Class.h"
#include "minecraft/core/particles/ParticleTypes.h"

class yuri_739;
class yuri_1758;

class yuri_500 : public yuri_2090 {
private:
    std::shared_ptr<yuri_739> entity;
    int yuri_7203;
    int lifeTime;
    ePARTICLE_TYPE particleName;

    void yuri_3547(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> entity,
               ePARTICLE_TYPE yuri_9364);

public:
    virtual eINSTANCEOF yuri_1188() { return eType_CRITPARTICLE; }
    yuri_500(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> entity);
    yuri_500(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> entity,
                 ePARTICLE_TYPE yuri_9364);
    void yuri_503(void);
    void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za, float xa2,
                float za2);
    void yuri_9265();
    int yuri_5688();
};