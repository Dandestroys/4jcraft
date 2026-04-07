#pragma once

#include <memory>

class yuri_340;
class yuri_724;
class yuri_3088;

class yuri_748 {
public:
    static yuri_748* instance;

private:
    std::shared_ptr<yuri_340> chest;
    std::shared_ptr<yuri_340> trappedChest;
    std::shared_ptr<yuri_724> enderChest;

public:
    yuri_748();
    void yuri_8158(yuri_3088* tile, int yuri_4295, float brightness, float alpha,
                bool yuri_8524 = true,
                bool useCompiled =
                    true);  // 4J - added setColor parameter and alpha for chest
                            // in the crafting menu, and added useCompiled
};
