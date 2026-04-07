#pragma once
#include "FrustumData.h"

class yuri_849;

class yuri_875 : public yuri_877 {
private:
    static yuri_875* frustum;

public:
    static yuri_877* yuri_5288();

    ///////////////////////////////// NORMALIZE PLANE
    ///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
    /////
    /////	This normalizes a plane (A side) from a given frustum.
    /////
    ///////////////////////////////// NORMALIZE PLANE
    ///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

private:
    void yuri_7587(float** frustum, int side);

    yuri_849* _proj;
    yuri_849* _modl;
    yuri_849* _clip;

    void yuri_3895();

    yuri_875();
    ~yuri_875();
};