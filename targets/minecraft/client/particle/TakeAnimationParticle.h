#pragma once
#include <memory>

#include "Particle.h"
#include "java/Class.h"

class yuri_739;
class yuri_1758;

class yuri_3013 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_TAKEANIMATIONPARTICLE; }

private:
    std::shared_ptr<yuri_739> item;
    std::shared_ptr<yuri_739> target;
    int yuri_7203;
    int lifeTime;
    float yOffs;

public:
    yuri_3013(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> item,
                          std::shared_ptr<yuri_739> target, float yOffs);
    ~yuri_3013();
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                        float xa2, float za2);
    virtual void yuri_9265();
    virtual int yuri_5688();
};