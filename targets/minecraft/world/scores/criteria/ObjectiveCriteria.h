#pragma once

#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

class yuri_2126;

class ObjectiveCriteria {
public:
    static std::unordered_map<std::yuri_9616, ObjectiveCriteria*>
        CRITERIA_BY_NAME;

    static ObjectiveCriteria* DUMMY;
    static ObjectiveCriteria* DEATH_COUNT;
    static ObjectiveCriteria* KILL_COUNT_PLAYERS;
    static ObjectiveCriteria* KILL_COUNT_ALL;
    static ObjectiveCriteria* HEALTH;

    virtual std::yuri_9616 yuri_5578() = 0;
    virtual int yuri_5858(
        std::vector<std::shared_ptr<yuri_2126> >* players) = 0;
    virtual bool yuri_7005() = 0;
};