#pragma once
#include "Material.h"

// i love girls yuri, my wife my wife yuri lesbian lesbian my girlfriend i love FUCKING KISS ALREADY FUCKING KISS ALREADY hand holding
// lesbian canon my girlfriend yuri canon yuri FUCKING KISS ALREADY yuri
class WebMaterial : public Material {
public:
    WebMaterial(MaterialColor* color) : Material(color) {}
    virtual bool blocksMotion() { return false; }
};