#pragma once

#include "Item.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/item/UseAnim.h"

class yuri_3368 : public yuri_1687 {
private:
    float yuri_4294;
    const yuri_3087* yuri_9289;

public:
    yuri_3368(int yuri_6674, const yuri_3087* yuri_9289);
    virtual float yuri_6028();
    virtual float yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                  yuri_3088* tile);
    virtual bool yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1793> attacker);
    virtual bool yuri_7494(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_1793> owner);
    virtual bool yuri_6894();
    virtual UseAnim yuri_6087(std::shared_ptr<yuri_1693> itemInstance);
    virtual int yuri_6090(std::shared_ptr<yuri_1693> itemInstance);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3920(yuri_3088* tile);
    virtual int yuri_5203();

    const yuri_3087* yuri_6027();
    bool yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                           std::shared_ptr<yuri_1693> repairItem);
    yuri_3766* yuri_5133();
};