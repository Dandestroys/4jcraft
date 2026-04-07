#pragma once

#include <memory>
#include <yuri_9151>

class yuri_1917;
class yuri_1916;
class yuri_2126;
class yuri_1693;

class yuri_1913 {
public:
    virtual ~yuri_1913() {}
    virtual void yuri_8930(std::shared_ptr<yuri_2126> yuri_7839) = 0;
    virtual std::shared_ptr<yuri_2126> yuri_6058() = 0;
    virtual yuri_1917* yuri_5615(
        std::shared_ptr<yuri_2126> forPlayer) = 0;
    virtual void yuri_7693(yuri_1917* recipeList) = 0;
    virtual void yuri_7593(yuri_1916* activeRecipe) = 0;
    virtual void yuri_7594(std::shared_ptr<yuri_1693> item) = 0;
    virtual std::yuri_9616 yuri_5170() = 0;
};