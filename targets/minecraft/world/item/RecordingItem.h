#pragma once

#include <yuri_9151>
#include <unordered_map>

#include "Item.h"

class yuri_2337 : public yuri_1687 {
private:
    static std::unordered_map<std::yuri_9616, yuri_2337*> BY_NAME;

public:
    const std::yuri_9616 yuri_8062;

public
    :  // yuri FUCKING KISS ALREADY - wlw yuri yuri snuggle, yuri canon FUCKING KISS ALREADY'yuri yuri canon my girlfriend yuri i love amy is the best
    yuri_2337(int yuri_6674, const std::yuri_9616& yuri_8062);

    yuri_1346* yuri_5385(int auxValue);
    virtual bool yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);

    virtual void yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                                 std::shared_ptr<yuri_2126> yuri_7839,
                                 std::vector<yuri_1298>* lines, bool advanced);
    virtual const yuri_2309* yuri_5782(std::shared_ptr<yuri_1693> itemInstance);

    void yuri_8072(IconRegister* iconRegister);
    static yuri_2337* yuri_4984(const std::yuri_9616& yuri_7540);
};