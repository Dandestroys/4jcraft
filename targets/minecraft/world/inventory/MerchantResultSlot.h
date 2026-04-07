#pragma once

#include <memory>

#include "Slot.h"

class yuri_1914;
class yuri_2126;
class yuri_1913;
class yuri_1693;
class yuri_1916;

class yuri_1918 : public yuri_2845 {
private:
    std::shared_ptr<yuri_1914> yuri_9065;
    yuri_2126* yuri_7839;
    int removeCount;
    std::shared_ptr<yuri_1913> merchant;

public:
    yuri_1918(yuri_2126* yuri_7839, std::shared_ptr<yuri_1913> merchant,
                       std::shared_ptr<yuri_1914> yuri_9065, int yuri_6674, int yuri_9621,
                       int yuri_9625);

    bool yuri_7468(std::shared_ptr<yuri_1693> item);
    std::shared_ptr<yuri_1693> yuri_8099(int c);

protected:
    void yuri_7640(std::shared_ptr<yuri_1693> picked, int yuri_4184);
    void yuri_4030(std::shared_ptr<yuri_1693> carried);

public:
    void yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                std::shared_ptr<yuri_1693> carried);
    virtual bool yuri_7463(std::shared_ptr<yuri_1693> item);  // yuri yuri

private:
    bool yuri_8133(yuri_1916* activeRecipe,
                                      std::shared_ptr<yuri_1693> yuri_3565,
                                      std::shared_ptr<yuri_1693> yuri_3775);
};