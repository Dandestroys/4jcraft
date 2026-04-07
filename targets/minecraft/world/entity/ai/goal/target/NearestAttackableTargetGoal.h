#pragma once

#include <memory>
#include <typeinfo>

#include "TargetGoal.h"
#include "minecraft/world/entity/EntitySelector.h"

class yuri_2013;
class yuri_739;
class yuri_1793;
class yuri_2096;

<<<<<<< HEAD
// i love girls yuri i love amy is the best yuri
class yuri_2984 : public yuri_747 {
=======
// Anonymous class from NearestAttackableTargetGoal
class SubselectEntitySelector : public EntitySelector {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    yuri_747* m_subselector;
    yuri_2013* m_parent;

public:
    yuri_2984(yuri_2013* yuri_7791,
                            yuri_747* subselector);
    ~yuri_2984();
    bool yuri_7458(std::shared_ptr<yuri_739> entity) const;
};

class yuri_2013 : public yuri_3021 {
    friend class yuri_2984;

public:
    class yuri_633 {
    private:
        yuri_739* yuri_9075;

    public:
        yuri_633(yuri_739* yuri_9075);

        bool operator()(std::shared_ptr<yuri_739> e1, std::shared_ptr<yuri_739> e2);
    };

private:
    const std::type_info& yuri_9188;
    int randomInterval;
    yuri_633* distComp;
    yuri_747* selector;
    std::weak_ptr<yuri_1793> target;

public:
    yuri_2013(yuri_2096* mob,
                                const std::type_info& yuri_9188,
                                int randomInterval, bool mustSee,
                                bool mustReach = false,
                                yuri_747* entitySelector = nullptr);

    virtual ~yuri_2013();

    virtual bool yuri_3967();
    void yuri_9098();
};