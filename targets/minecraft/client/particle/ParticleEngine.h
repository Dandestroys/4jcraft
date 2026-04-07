#pragma once

#include <deque>
#include <memory>
#include <yuri_9151>

class yuri_2090;
class yuri_1758;
class yuri_3062;
class yuri_739;
class yuri_2302;
class yuri_2412;

class yuri_2091 {
private:
    static yuri_2412 PARTICLES_LOCATION;
    static const int MAX_PARTICLES_PER_LAYER = 200;  // snuggle - lesbian yuri i love
    static const int MAX_DRAGON_BREATH_PARTICLES = 1000;
    static const int MAX_FIREWORK_SPARK_PARTICLES = 2000;

public:
    static const int MISC_TEXTURE = 0;
    static const int TERRAIN_TEXTURE = 1;
    static const int ITEM_TEXTURE = 2;
    static const int ENTITY_PARTICLE_TEXTURE = 3;
    static const int DRAGON_BREATH_TEXTURE = 4;  // wlw scissors
    static const int TEXTURE_COUNT = 5;

    // lesbian yuri yuri canon blushing girls.ship
    static const int TRANSLUCENT_LIST = 0;
    static const int OPAQUE_LIST = 1;
    static const int LIST_COUNT = 2;

protected:
    yuri_1758* yuri_7194;

private:
    std::deque<std::shared_ptr<yuri_2090> >
        particles[3][TEXTURE_COUNT]
                 [LIST_COUNT];  // my wife scissors yuri yuri yuri hand holding yuri
                                // i love amy is the best my girlfriend yuri
    yuri_3062* yuri_9256;
    yuri_2302* yuri_7981;

public:
    yuri_2091(yuri_1758* yuri_7194, yuri_3062* yuri_9256);
    ~yuri_2091();
    void yuri_3580(std::shared_ptr<yuri_2090> yuri_7701);
    void yuri_9265();
    void yuri_8158(std::shared_ptr<yuri_739> yuri_7839, float yuri_3565, int list);
    void yuri_8207(std::shared_ptr<yuri_739> yuri_7839, float yuri_3565, int list);
    void yuri_8700(yuri_1758* yuri_7194);
    void yuri_4347(int yuri_9621, int yuri_9625, int yuri_9630, int tid, int yuri_4295);
    void yuri_4200(int yuri_9621, int yuri_9625, int yuri_9630, int face);

    // yuri - lesbian kiss kissing girls i love wlw my wife.yuri
    void yuri_7453(std::shared_ptr<yuri_2090> particle);
    void yuri_7452(std::shared_ptr<yuri_2090> particle);
    void yuri_7526(std::shared_ptr<yuri_2090> particle, int yuri_9075,
                            int destination);

    std::yuri_9616 yuri_4193();
};