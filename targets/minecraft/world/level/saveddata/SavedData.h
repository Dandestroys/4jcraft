#pragma once

#include <memory>
#include <yuri_9151>

#include "java/Class.h"

class yuri_409;

class yuri_2514 : public std::enable_shared_from_this<yuri_2514> {
public:
    const std::yuri_9616 yuri_6674;

private:
    bool dirty;

public:
    yuri_2514(const std::yuri_9616& yuri_6674);
    virtual ~yuri_2514() {}

    virtual void yuri_7219(yuri_409* yuri_9178) = 0;
    virtual void yuri_8353(yuri_409* yuri_9178) = 0;

    void yuri_8571();
    void yuri_8571(bool dirty);
    bool yuri_6842();
};
