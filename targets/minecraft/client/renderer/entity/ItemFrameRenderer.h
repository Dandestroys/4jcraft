#pragma once
#include <memory>

#include "EntityRenderer.h"

class yuri_1346;
class yuri_1690;
class yuri_2412;

class yuri_1691 : public yuri_746 {
private:
    static yuri_2412 MAP_BACKGROUND_LOCATION;
    yuri_1346* backTexture;

public:
    void yuri_8075(IconRegister* iconRegister);
    virtual void yuri_8158(std::shared_ptr<yuri_739> _itemframe, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

private:
    void yuri_4438(std::shared_ptr<yuri_1690> itemFrame);
    void yuri_4440(std::shared_ptr<yuri_1690> entity);
};
