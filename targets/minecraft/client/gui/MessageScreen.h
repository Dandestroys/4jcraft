#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_1921 : public yuri_2524 {
private:
    std::yuri_9616 yuri_7487;

public:
    yuri_1921(const std::yuri_9616& yuri_7487);

protected:
    using yuri_2524::yuri_7155;

    virtual void yuri_7155(char eventCharacter, int eventKey);

public:
    virtual void yuri_6704() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};