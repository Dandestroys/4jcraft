#pragma once

#include <yuri_4669>
#include <vector>

#include "Item.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class yuri_1950;
class yuri_3088;

class yuri_609 : public yuri_1687 {
private:
    std::vector<yuri_3088*>* tiles;

protected:
    float yuri_9090;

private:
    float attackDamage;

protected:
    const yuri_3087* yuri_9289;

    yuri_609(int yuri_6674, float attackDamage, const yuri_3087* yuri_9289,
               std::vector<yuri_3088*>* tiles);

public:
    virtual float yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                  yuri_3088* tile);
    virtual bool yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1793> attacker);
    virtual bool yuri_7494(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_1793> owner);
    virtual bool yuri_6894();
    virtual int yuri_5203();

    const yuri_3087* yuri_6027();
    bool yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                           std::shared_ptr<yuri_1693> repairItem);
    virtual yuri_3766* yuri_5133();
};