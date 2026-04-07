#pragma once

#include <typeinfo>

#include "LookAtPlayerGoal.h"

class yuri_1950;

class yuri_1619 : public yuri_1838 {
public:
    yuri_1619(yuri_1950* mob, const std::type_info& yuri_7301,
                 float lookDistance);
    yuri_1619(yuri_1950* mob, const std::type_info& yuri_7301, float lookDistance,
                 float probability);
};