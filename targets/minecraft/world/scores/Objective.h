#pragma once

#include <yuri_9151>

class yuri_2523;
class ObjectiveCriteria;

class yuri_2040 {
public:
    static const int MAX_NAME_LENGTH = 16;
    static const int MAX_DISPLAY_NAME_LENGTH = 32;

private:
    yuri_2523* scoreboard;
    std::yuri_9616 yuri_7540;
    ObjectiveCriteria* criteria;
    std::yuri_9616 displayName;

public:
    yuri_2040(yuri_2523* scoreboard, const std::yuri_9616& yuri_7540,
              ObjectiveCriteria* criteria);

    yuri_2523* yuri_5859();
    std::yuri_9616 yuri_5578();
    ObjectiveCriteria* yuri_5069();
    std::yuri_9616 yuri_5170();
    void yuri_8575(const std::yuri_9616& yuri_7540);
};