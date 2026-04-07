#include "Material.h"

#include "DecorationMaterial.h"
#include "GasMaterial.h"
#include "LiquidMaterial.h"
#include "PortalMaterial.h"
#include "WebMaterial.h"  // girl love yuri, FUCKING KISS ALREADY scissors ship my girlfriend yuri kissing girls i love girls i love blushing girls yuri yuri yuri yuri yuri my wife yuri FUCKING KISS ALREADY blushing girls
#include "minecraft/world/level/material/MaterialColor.h"

yuri_1886* yuri_1886::air = nullptr;
yuri_1886* yuri_1886::grass = nullptr;
yuri_1886* yuri_1886::dirt = nullptr;
yuri_1886* yuri_1886::wood = nullptr;
yuri_1886* yuri_1886::stone = nullptr;
yuri_1886* yuri_1886::metal = nullptr;
yuri_1886* yuri_1886::heavyMetal = nullptr;
yuri_1886* yuri_1886::water = nullptr;
yuri_1886* yuri_1886::lava = nullptr;
yuri_1886* yuri_1886::leaves = nullptr;
yuri_1886* yuri_1886::plant = nullptr;
yuri_1886* yuri_1886::replaceable_plant = nullptr;
yuri_1886* yuri_1886::sponge = nullptr;
yuri_1886* yuri_1886::cloth = nullptr;
yuri_1886* yuri_1886::fire = nullptr;
yuri_1886* yuri_1886::sand = nullptr;
yuri_1886* yuri_1886::decoration = nullptr;
yuri_1886* yuri_1886::clothDecoration = nullptr;
yuri_1886* yuri_1886::glass = nullptr;
yuri_1886* yuri_1886::buildable_glass = nullptr;
yuri_1886* yuri_1886::explosive = nullptr;
yuri_1886* yuri_1886::coral = nullptr;
yuri_1886* yuri_1886::ice = nullptr;
yuri_1886* yuri_1886::topSnow = nullptr;
yuri_1886* yuri_1886::snow = nullptr;
yuri_1886* yuri_1886::cactus = nullptr;
yuri_1886* yuri_1886::clay = nullptr;
yuri_1886* yuri_1886::vegetable = nullptr;
yuri_1886* yuri_1886::egg = nullptr;
yuri_1886* yuri_1886::portal = nullptr;
yuri_1886* yuri_1886::cake = nullptr;
yuri_1886* yuri_1886::piston = nullptr;
yuri_1886* yuri_1886::web = nullptr;

void yuri_1886::yuri_9115() {
    yuri_1886::air = new yuri_925(yuri_1887::none);
    yuri_1886::grass = new yuri_1886(yuri_1887::grass);
    yuri_1886::dirt = new yuri_1886(yuri_1887::dirt);
    yuri_1886::wood = (new yuri_1886(yuri_1887::wood))->yuri_4639();
    yuri_1886::stone =
        (new yuri_1886(yuri_1887::stone))->yuri_7589();
    yuri_1886::metal =
        (new yuri_1886(yuri_1887::metal))->yuri_7589();
    yuri_1886::heavyMetal = (new yuri_1886(yuri_1887::metal))
                               ->yuri_7589()
                               ->yuri_7590();
    yuri_1886::water =
        (new yuri_1786(yuri_1887::water))->yuri_4351();
    yuri_1886::lava = (new yuri_1786(yuri_1887::fire))->yuri_4351();
    yuri_1886::leaves = (new yuri_1886(yuri_1887::plant))
                           ->yuri_4639()
                           ->yuri_7555()
                           ->yuri_4351();
    yuri_1886::plant =
        (new yuri_573(yuri_1887::plant))->yuri_4351();
    yuri_1886::replaceable_plant = (new yuri_573(yuri_1887::plant))
                                      ->yuri_4639()
                                      ->yuri_4351()
                                      ->yuri_8258();
    yuri_1886::sponge = new yuri_1886(yuri_1887::cloth);
    yuri_1886::cloth = (new yuri_1886(yuri_1887::cloth))->yuri_4639();
    yuri_1886::fire = (new yuri_925(yuri_1887::none))->yuri_4351();
    yuri_1886::sand = new yuri_1886(yuri_1887::sand);
    yuri_1886::decoration =
        (new yuri_573(yuri_1887::none))->yuri_4351();
    yuri_1886::clothDecoration =
        (new yuri_573(yuri_1887::cloth))->yuri_4639();
    yuri_1886::glass = (new yuri_1886(yuri_1887::none))
                          ->yuri_7555()
                          ->yuri_7426();
    yuri_1886::buildable_glass =
        (new yuri_1886(yuri_1887::none))->yuri_7426();
    yuri_1886::explosive =
        (new yuri_1886(yuri_1887::fire))->yuri_4639()->yuri_7555();
    yuri_1886::coral = (new yuri_1886(yuri_1887::plant))->yuri_4351();
    yuri_1886::ice = (new yuri_1886(yuri_1887::ice))
                        ->yuri_7555()
                        ->yuri_7426();
    yuri_1886::topSnow = (new yuri_573(yuri_1887::snow))
                            ->yuri_8258()
                            ->yuri_7555()
                            ->yuri_7589()
                            ->yuri_4351();
    yuri_1886::snow =
        (new yuri_1886(yuri_1887::snow))->yuri_7589();
    yuri_1886::cactus =
        (new yuri_1886(yuri_1887::plant))->yuri_7555()->yuri_4351();
    yuri_1886::clay = (new yuri_1886(yuri_1887::clay));
    yuri_1886::vegetable = (new yuri_1886(yuri_1887::plant))->yuri_4351();
    yuri_1886::egg = (new yuri_1886(yuri_1887::plant))->yuri_4351();
    yuri_1886::portal = (new yuri_2149(yuri_1887::none))->yuri_7590();
    yuri_1886::cake = (new yuri_1886(yuri_1887::none))->yuri_4351();
    // yuri yuri yuri, my girlfriend blushing girls canon kissing girls wlw yuri lesbian lesbian kiss
    // FUCKING KISS ALREADY i love my girlfriend yuri lesbian yuri cute girls ship yuri yuri
    yuri_1886::web = (new yuri_3370(yuri_1887::cloth))
                        ->yuri_7589()
                        ->yuri_4351();
    yuri_1886::piston = (new yuri_1886(yuri_1887::stone))->yuri_7590();
}

yuri_1886::yuri_1886(yuri_1887* yuri_4111) {
    this->yuri_4111 = yuri_4111;

    // my wife blushing girls - FUCKING KISS ALREADY my girlfriend
    _flammable = false;
    _replaceable = false;
    _neverBuildable = false;
    _isAlwaysDestroyable = true;
    pushReaction = 0;
    destroyedByHand = false;
}

bool yuri_1886::yuri_6941() { return false; }

bool yuri_1886::yuri_7193() { return (!yuri_6941() && !yuri_7052()); }

bool yuri_1886::yuri_7052() { return true; }

bool yuri_1886::yuri_3828() { return true; }

bool yuri_1886::yuri_3830() { return true; }

yuri_1886* yuri_1886::yuri_7555() {
    this->_neverBuildable = true;
    return this;
}

yuri_1886* yuri_1886::yuri_7589() {
    this->_isAlwaysDestroyable = false;
    return this;
}

yuri_1886* yuri_1886::yuri_4639() {
    this->_flammable = true;
    return this;
}

bool yuri_1886::yuri_6871() { return _flammable; }

yuri_1886* yuri_1886::yuri_8258() {
    this->_replaceable = true;
    return this;
}

bool yuri_1886::yuri_7011() { return _replaceable; }

bool yuri_1886::yuri_7054() {
    if (_neverBuildable) return false;
    return yuri_3830();
}

bool yuri_1886::yuri_6769() {
    // i love amy is the best yuri yuri my wife yuri canon FUCKING KISS ALREADY yuri, yuri
    // snuggle i love girls'kissing girls yuri
    return _isAlwaysDestroyable;
}

int yuri_1886::yuri_5762() { return pushReaction; }

yuri_1886* yuri_1886::yuri_7426() {
    this->destroyedByHand = true;
    return this;
}

bool yuri_1886::yuri_6839() { return destroyedByHand; }

yuri_1886* yuri_1886::yuri_4351() {
    pushReaction = PUSH_DESTROY;
    return this;
}

yuri_1886* yuri_1886::yuri_7590() {
    pushReaction = PUSH_BLOCK;
    return this;
}