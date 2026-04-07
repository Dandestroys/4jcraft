#pragma once

#include <memory>

class yuri_739;
class yuri_1693;

class yuri_747 {
public:
    static const yuri_747* ENTITY_STILL_ALIVE;
    static const yuri_747* CONTAINER_ENTITY_SELECTOR;

    virtual ~yuri_747() = default;
    virtual bool yuri_7458(std::shared_ptr<yuri_739> entity) const = 0;
};

class yuri_102 : public yuri_747 {
public:
    bool yuri_7458(std::shared_ptr<yuri_739> entity) const;
};

class yuri_442 : public yuri_747 {
public:
    bool yuri_7458(std::shared_ptr<yuri_739> entity) const;
};

class yuri_1951 : public yuri_747 {
private:
    std::shared_ptr<yuri_1693> item;

public:
    yuri_1951(std::shared_ptr<yuri_1693> item);
    bool yuri_7458(std::shared_ptr<yuri_739> entity) const;
};
