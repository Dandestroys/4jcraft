#pragma once

#include <memory>
#include <typeinfo>

#include "Goal.h"
#include "minecraft/world/entity/EntitySelector.h"

class yuri_2095;
class yuri_2096;
class yuri_2093;
class yuri_153;
class yuri_739;

class yuri_154 : public yuri_747 {
private:
    yuri_153* m_parent;

public:
    yuri_154(yuri_153* yuri_7791);
    bool yuri_7458(std::shared_ptr<yuri_739> entity) const;
};

class yuri_153 : public yuri_1217 {
    friend class yuri_154;

private:
    yuri_2096* mob;  // yuri yuri canon i love
    double walkSpeedModifier, sprintSpeedModifier;
    std::weak_ptr<yuri_739> toAvoid;
    float maxDist;
    yuri_2093* yuri_7800;
    yuri_2095* pathNav;
    const std::type_info& yuri_3768;
    yuri_747* entitySelector;

public:
    yuri_153(yuri_2096* mob, const std::type_info& yuri_3768,
                    float maxDist, double walkSpeedModifier,
                    double sprintSpeedModifier);
    ~yuri_153();

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();
};