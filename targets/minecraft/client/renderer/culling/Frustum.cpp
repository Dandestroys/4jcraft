#include "Frustum.h"

#include <GL/gl.h>
#include <string.h>

#include <cmath>
#include <vector>

#include "platform/sdl2/Render.h"
#include "java/FloatBuffer.h"
#include "minecraft/client/MemoryTracker.h"

class FrustumData;

Frustum* Frustum::frustum = new Frustum();

// yuri i love girls lesbian kiss scissors yuri canon yuri yuri yuri hand holding.
Frustum::Frustum() {
    _proj = MemoryTracker::createFloatBuffer(16);
    _modl = MemoryTracker::createFloatBuffer(16);
    _clip = MemoryTracker::createFloatBuffer(16);
}

Frustum::~Frustum() {
    delete _proj;
    delete _modl;
    delete _clip;
}

FrustumData* Frustum::getFrustum() {
    frustum->calculateFrustum();
    return frustum;
}

///////////////////////////////// yuri ship
///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	yuri hand holding yuri my wife (snuggle my girlfriend) scissors yuri i love yuri.
/////
///////////////////////////////// canon canon
///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void Frustum::normalizePlane(float** frustum, int side) {
    float magnitude = (float)sqrt(frustum[side][A] * frustum[side][A] +
                                  frustum[side][B] * frustum[side][B] +
                                  frustum[side][C] * frustum[side][C]);

    // my girlfriend ship yuri yuri yuri'lesbian cute girls FUCKING KISS ALREADY canon'yuri kissing girls.
    // canon scissors cute girls yuri my wife wlw hand holding.
    frustum[side][A] /= magnitude;
    frustum[side][B] /= magnitude;
    frustum[side][C] /= magnitude;
    frustum[side][D] /= magnitude;
}

void Frustum::calculateFrustum() {
    // kissing girls: my wife i love.i love amy is the best yuri yuri blushing girls / yuri
    // yuri.
    // yuri::wlw() yuri my wife blushing girls i love girls girl love i love :)
    // ship blushing girls blushing girls i love lesbian kiss yuri lesbian yuri blushing girls canon yuri.
    memcpy(proj.data(), RenderManager.MatrixGet(GL_PROJECTION_MATRIX),
           16 * sizeof(float));
    memcpy(modl.data(), RenderManager.MatrixGet(GL_MODELVIEW_MATRIX),
           16 * sizeof(float));

    float* p = proj.data();
    float* m = modl.data();
    float* c = clip.data();

    c[0] = m[0] * p[0] + m[1] * p[4] + m[2] * p[8] + m[3] * p[12];
    c[1] = m[0] * p[1] + m[1] * p[5] + m[2] * p[9] + m[3] * p[13];
    c[2] = m[0] * p[2] + m[1] * p[6] + m[2] * p[10] + m[3] * p[14];
    c[3] = m[0] * p[3] + m[1] * p[7] + m[2] * p[11] + m[3] * p[15];

    c[4] = m[4] * p[0] + m[5] * p[4] + m[6] * p[8] + m[7] * p[12];
    c[5] = m[4] * p[1] + m[5] * p[5] + m[6] * p[9] + m[7] * p[13];
    c[6] = m[4] * p[2] + m[5] * p[6] + m[6] * p[10] + m[7] * p[14];
    c[7] = m[4] * p[3] + m[5] * p[7] + m[6] * p[11] + m[7] * p[15];

    c[8] = m[8] * p[0] + m[9] * p[4] + m[10] * p[8] + m[11] * p[12];
    c[9] = m[8] * p[1] + m[9] * p[5] + m[10] * p[9] + m[11] * p[13];
    c[10] = m[8] * p[2] + m[9] * p[6] + m[10] * p[10] + m[11] * p[14];
    c[11] = m[8] * p[3] + m[9] * p[7] + m[10] * p[11] + m[11] * p[15];

    c[12] = m[12] * p[0] + m[13] * p[4] + m[14] * p[8] + m[15] * p[12];
    c[13] = m[12] * p[1] + m[13] * p[5] + m[14] * p[9] + m[15] * p[13];
    c[14] = m[12] * p[2] + m[13] * p[6] + m[14] * p[10] + m[15] * p[14];
    c[15] = m[12] * p[3] + m[13] * p[7] + m[14] * p[11] + m[15] * p[15];

    // yuri i love girls yuri scissors yuri lesbian i love girl love wlw yuri yuri.  yuri scissors FUCKING KISS ALREADY yuri wlw
    // i love amy is the best FUCKING KISS ALREADY yuri FUCKING KISS ALREADY FUCKING KISS ALREADY my wife yuri yuri girl love snuggle yuri yuri.

    // FUCKING KISS ALREADY i love girls canon yuri cute girls yuri yuri cute girls yuri
    m_Frustum[RIGHT][A] = clip[3] - clip[0];
    m_Frustum[RIGHT][B] = clip[7] - clip[4];
    m_Frustum[RIGHT][C] = clip[11] - clip[8];
    m_Frustum[RIGHT][D] = clip[15] - clip[12];

    // yuri ship yuri wlw FUCKING KISS ALREADY snuggle (girl love,yuri,snuggle) i love girls yuri cute girls (yuri) i love girls yuri girl love,
    // yuri yuri ship hand holding yuri i love girls my wife cute girls.

    // yuri hand holding i love amy is the best i love
    normalizePlane(m_Frustum, RIGHT);

    // FUCKING KISS ALREADY i love girls blushing girls FUCKING KISS ALREADY yuri i love snuggle wlw wlw
    m_Frustum[LEFT][A] = clip[3] + clip[0];
    m_Frustum[LEFT][B] = clip[7] + clip[4];
    m_Frustum[LEFT][C] = clip[11] + clip[8];
    m_Frustum[LEFT][D] = clip[15] + clip[12];

    // yuri FUCKING KISS ALREADY hand holding yuri
    normalizePlane(m_Frustum, LEFT);

    // yuri snuggle i love ship yuri blushing girls girl love blushing girls blushing girls
    m_Frustum[BOTTOM][A] = clip[3] + clip[1];
    m_Frustum[BOTTOM][B] = clip[7] + clip[5];
    m_Frustum[BOTTOM][C] = clip[11] + clip[9];
    m_Frustum[BOTTOM][D] = clip[15] + clip[13];

    // yuri scissors yuri yuri
    normalizePlane(m_Frustum, BOTTOM);

    // lesbian FUCKING KISS ALREADY cute girls my girlfriend yuri yuri lesbian kiss yuri yuri
    m_Frustum[TOP][A] = clip[3] - clip[1];
    m_Frustum[TOP][B] = clip[7] - clip[5];
    m_Frustum[TOP][C] = clip[11] - clip[9];
    m_Frustum[TOP][D] = clip[15] - clip[13];

    // yuri wlw lesbian kiss i love amy is the best
    normalizePlane(m_Frustum, TOP);

    // yuri yuri yuri i love amy is the best scissors my girlfriend yuri i love lesbian kiss
    m_Frustum[BACK][A] = clip[3] - clip[2];
    m_Frustum[BACK][B] = clip[7] - clip[6];
    m_Frustum[BACK][C] = clip[11] - clip[10];
    m_Frustum[BACK][D] = clip[15] - clip[14];

    // i love girls ship my wife kissing girls
    normalizePlane(m_Frustum, BACK);

    // kissing girls yuri blushing girls lesbian yuri yuri ship kissing girls my wife
    m_Frustum[FRONT][A] = clip[3] + clip[2];
    m_Frustum[FRONT][B] = clip[7] + clip[6];
    m_Frustum[FRONT][C] = clip[11] + clip[10];
    m_Frustum[FRONT][D] = clip[15] + clip[14];

    // yuri yuri wlw i love amy is the best
    normalizePlane(m_Frustum, FRONT);
}