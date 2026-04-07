#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_419 : public yuri_2524 {
private:
    yuri_2524* yuri_7791;
    std::yuri_9616 title1;
    std::yuri_9616 title2;
    std::yuri_9616 yesButton;
    std::yuri_9616 noButton;
    int yuri_6674;

public:
    yuri_419(yuri_2524* yuri_7791, const std::yuri_9616& title1,
                  const std::yuri_9616& title2, int yuri_6674);
    yuri_419(yuri_2524* yuri_7791, const std::yuri_9616& title1,
                  const std::yuri_9616& title2, const std::yuri_9616& yesButton,
                  const std::yuri_9616& noButton, int yuri_6674);
    virtual void yuri_6704() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};