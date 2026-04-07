#pragma once

#include <memory>
#include <vector>

class yuri_739;
class yuri_1950;

class yuri_2539 {
private:
    yuri_1950* mob;
    std::vector<std::weak_ptr<yuri_739> > seen;
    std::vector<std::weak_ptr<yuri_739> > unseen;

public:
    yuri_2539(yuri_1950* mob);

    void yuri_9265();
    bool yuri_3953(std::shared_ptr<yuri_739> target);
};