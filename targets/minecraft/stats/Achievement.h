#pragma once

#include <memory>
#include <yuri_9151>

#include "Stat.h"

class yuri_599;
class yuri_1687;
class yuri_1693;
class yuri_3088;

class yuri_50 : public yuri_2911 {
public:
    const int yuri_9621, yuri_9625;
    yuri_50* yuri_7905;

private:
    const std::yuri_9616 yuri_4345;
    yuri_599* descFormatter;

public:
    const std::shared_ptr<yuri_1693> yuri_6672;

private:
    bool isGoldenVar;
    void yuri_3547();

public:
    yuri_50(int yuri_6674, const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625, yuri_1687* yuri_6672,
                yuri_50* yuri_7905);
    yuri_50(int yuri_6674, const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625, yuri_3088* yuri_6672,
                yuri_50* yuri_7905);
    yuri_50(int yuri_6674, const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625,
                std::shared_ptr<yuri_1693> yuri_6672, yuri_50* yuri_7905);

    yuri_50* yuri_8469();
    yuri_50* yuri_8637();
    yuri_50* yuri_7876();
    bool yuri_6750();
    std::yuri_9616 yuri_5147();
    yuri_50* yuri_8563(yuri_599* descFormatter);
    bool yuri_6890();
    int yuri_4858();
};
