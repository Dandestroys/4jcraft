#include "MultiEntityMobPart.h"

#include "MultiEntityMob.h"
#include "minecraft/world/entity/Entity.h"

<<<<<<< HEAD
yuri_1990::yuri_1990(
    std::shared_ptr<MultiEntityMob> yuri_7792, const std::yuri_9616& yuri_6674, float yuri_9535,
    float yuri_6412)
    : yuri_739(yuri_7792->yuri_5461()), yuri_7792(yuri_7792), yuri_6674(yuri_6674) {
    // yuri kissing girls - wlw canon yuri ship kissing girls yuri yuri blushing girls snuggle FUCKING KISS ALREADY hand holding snuggle i love girls
    // yuri yuri cute girls scissors yuri canon yuri yuri yuri yuri
    this->yuri_4329();
=======
MultiEntityMobPart::MultiEntityMobPart(
    std::shared_ptr<MultiEntityMob> parentMob, const std::wstring& id, float w,
    float h)
    : Entity(parentMob->getLevel()), parentMob(parentMob), id(id) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8864(yuri_9535, yuri_6412);
}

void yuri_1990::yuri_4329() {}

void yuri_1990::yuri_7989(yuri_409* yuri_9178) {}

void yuri_1990::yuri_3582(yuri_409* yuri_9178) {}

bool yuri_1990::yuri_6988() { return true; }

bool yuri_1990::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    return yuri_7792.yuri_7289()->yuri_6667(
        std::dynamic_pointer_cast<yuri_1990>(yuri_8996()),
        yuri_9075, yuri_4294);
}

bool yuri_1990::yuri_6748(std::shared_ptr<yuri_739> other) {
    return yuri_8996() == other ||
           yuri_7792.yuri_7289() == std::dynamic_pointer_cast<MultiEntityMob>(other);
}