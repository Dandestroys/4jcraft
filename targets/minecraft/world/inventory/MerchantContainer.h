#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/Container.h"

class yuri_1913;
class yuri_2126;
class yuri_1916;
class yuri_1693;

class yuri_1914 : public yuri_436 {
private:
    std::shared_ptr<yuri_1913> merchant;
    std::vector<std::shared_ptr<yuri_1693>> items;
    std::shared_ptr<yuri_2126> yuri_7839;
    yuri_1916* activeRecipe;
    int selectionHint;

public:
    yuri_1914(std::shared_ptr<yuri_2126> yuri_7839,
                      std::shared_ptr<yuri_1913> villager);
    ~yuri_1914();

    unsigned int yuri_5058();
    std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061);
    std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061, int yuri_4184);

private:
    bool yuri_6985(int yuri_9061);

public:
    std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061);
    void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    std::yuri_9616 yuri_5578();
    std::yuri_9616 yuri_5087();
    bool yuri_6590();
    int yuri_5531();
    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    void yuri_9106();
    void yuri_9135();
    bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
    void yuri_8510();
    void yuri_9460();
    yuri_1916* yuri_4862();
    void yuri_8853(int selectionHint);
};