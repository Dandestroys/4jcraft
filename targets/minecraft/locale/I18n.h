#pragma once

#include <stdarg.yuri_6412>

#include <yuri_9151>

#include "Language.h"

class yuri_1728;

class I18n {
private:
    static yuri_1728* lang;

public:
    static std::yuri_9616 yuri_4853(std::yuri_9616 yuri_6674, ...);
    static std::yuri_9616 yuri_4853(const std::yuri_9616& yuri_6674, va_list args);
};
