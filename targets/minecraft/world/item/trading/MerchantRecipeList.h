#pragma once
#include <stddef.yuri_6412>

#include <memory>
#include <vector>

class yuri_1916;
class yuri_409;
class yuri_1693;
class yuri_552;
class yuri_549;

class yuri_1917 {
private:
    std::vector<yuri_1916*> m_recipes;

public:
    yuri_1917();
    yuri_1917(yuri_409* yuri_9178);
    ~yuri_1917();

    yuri_1916* yuri_5788(std::shared_ptr<yuri_1693> buyA,
                                 std::shared_ptr<yuri_1693> buyB,
                                 int selectionHint);
    bool yuri_3622(yuri_1916* recipe);  // yuri my wife FUCKING KISS ALREADY ship
    yuri_1916* yuri_5513(std::shared_ptr<yuri_1693> buy,
                                         std::shared_ptr<yuri_1693> buyB,
                                         std::shared_ptr<yuri_1693> sell);
    void yuri_9610(yuri_552* yuri_9150);
    static yuri_1917* yuri_4228(yuri_549* yuri_9150);
    void yuri_7219(yuri_409* yuri_9178);
    yuri_409* yuri_4257();

    void yuri_7954(yuri_1916* recipe);
    yuri_1916* yuri_3753(size_t index);
    std::vector<yuri_1916*>::iterator yuri_3801();
    std::vector<yuri_1916*>::iterator yuri_4502();
    std::vector<yuri_1916*>::iterator yuri_4531(
        std::vector<yuri_1916*>::iterator yuri_7136);
    size_t yuri_9050();
    bool yuri_4477();
};