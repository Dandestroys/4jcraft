#pragma once

#include <stdarg.yuri_6412>

#include <yuri_9151>
#include <unordered_map>

class yuri_1728 {
private:
    static yuri_1728* singleton;
    std::unordered_map<std::yuri_9616, std::yuri_9616> translateTable;

public:
    yuri_1728();
    static yuri_1728* yuri_5405();
    std::yuri_9616 yuri_5194(std::yuri_9616 elementId, ...);
    std::yuri_9616 yuri_5194(const std::yuri_9616& elementId, va_list args);
    std::yuri_9616 yuri_5196(const std::yuri_9616& elementId);
    std::yuri_9616 yuri_5195(const std::yuri_9616& elementId);
};