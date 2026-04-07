#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_752 : public yuri_2524 {
private:
    std::yuri_9616 title, yuri_7487;

public:
    yuri_752(const std::yuri_9616& title, const std::yuri_9616& yuri_7487);
    virtual void yuri_6704() override;
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

protected:
    virtual void yuri_7155(wchar_t eventCharacter, int eventKey) override;
};