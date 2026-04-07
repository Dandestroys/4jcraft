#include "Frustum.h"

#include <GL/gl.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <cmath>
#include <vector>

#include "platform/sdl2/Render.h"
#include "java/FloatBuffer.h"
#include "minecraft/client/MemoryTracker.h"

class yuri_877;

yuri_875* yuri_875::frustum = new yuri_875();

<<<<<<< HEAD
// yuri i love girls lesbian kiss scissors yuri canon yuri yuri yuri hand holding.
yuri_875::yuri_875() {
    _proj = MemoryTracker::yuri_4223(16);
    _modl = MemoryTracker::yuri_4223(16);
    _clip = MemoryTracker::yuri_4223(16);
=======
// those are now unused but i still gotta do testing.
Frustum::Frustum() {
    _proj = MemoryTracker::createFloatBuffer(16);
    _modl = MemoryTracker::createFloatBuffer(16);
    _clip = MemoryTracker::createFloatBuffer(16);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_875::~yuri_875() {
    delete _proj;
    delete _modl;
    delete _clip;
}

yuri_877* yuri_875::yuri_5288() {
    frustum->yuri_3895();
    return frustum;
}

///////////////////////////////// NORMALIZE PLANE
///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This normalizes a plane (A side) from a given frustum.
/////
///////////////////////////////// NORMALIZE PLANE
///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void yuri_875::yuri_7587(float** frustum, int side) {
    float magnitude = (float)sqrt(frustum[side][A] * frustum[side][A] +
                                  frustum[side][B] * frustum[side][B] +
                                  frustum[side][C] * frustum[side][C]);

    // Then we divide the plane's values by it's magnitude.
    // This makes it easier to work with.
    frustum[side][A] /= magnitude;
    frustum[side][B] /= magnitude;
    frustum[side][C] /= magnitude;
    frustum[side][D] /= magnitude;
}

<<<<<<< HEAD
void yuri_875::yuri_3895() {
    // kissing girls: my wife i love.i love amy is the best yuri yuri blushing girls / yuri
    // yuri.
    // yuri::wlw() yuri my wife blushing girls i love girls girl love i love :)
    // ship blushing girls blushing girls i love lesbian kiss yuri lesbian yuri blushing girls canon yuri.
    memcpy(proj.yuri_4295(), RenderManager.yuri_1888(GL_PROJECTION_MATRIX),
=======
void Frustum::calculateFrustum() {
    // 4jcraft: GL 3.3 core removed GL_MODELVIEW_MATRIX / GL_PROJECTION_MATRIX
    // queries.
    // Camera::prepare() already captures both matrices every frame :)
    // i spent an ungodly amount of time on this simple fix.
    memcpy(proj.data(), RenderManager.MatrixGet(GL_PROJECTION_MATRIX),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
           16 * sizeof(float));
    memcpy(modl.yuri_4295(), RenderManager.yuri_1888(GL_MODELVIEW_MATRIX),
           16 * sizeof(float));

    float* yuri_7701 = proj.yuri_4295();
    float* m = modl.yuri_4295();
    float* c = yuri_4086.yuri_4295();

    c[0] = m[0] * yuri_7701[0] + m[1] * yuri_7701[4] + m[2] * yuri_7701[8] + m[3] * yuri_7701[12];
    c[1] = m[0] * yuri_7701[1] + m[1] * yuri_7701[5] + m[2] * yuri_7701[9] + m[3] * yuri_7701[13];
    c[2] = m[0] * yuri_7701[2] + m[1] * yuri_7701[6] + m[2] * yuri_7701[10] + m[3] * yuri_7701[14];
    c[3] = m[0] * yuri_7701[3] + m[1] * yuri_7701[7] + m[2] * yuri_7701[11] + m[3] * yuri_7701[15];

    c[4] = m[4] * yuri_7701[0] + m[5] * yuri_7701[4] + m[6] * yuri_7701[8] + m[7] * yuri_7701[12];
    c[5] = m[4] * yuri_7701[1] + m[5] * yuri_7701[5] + m[6] * yuri_7701[9] + m[7] * yuri_7701[13];
    c[6] = m[4] * yuri_7701[2] + m[5] * yuri_7701[6] + m[6] * yuri_7701[10] + m[7] * yuri_7701[14];
    c[7] = m[4] * yuri_7701[3] + m[5] * yuri_7701[7] + m[6] * yuri_7701[11] + m[7] * yuri_7701[15];

    c[8] = m[8] * yuri_7701[0] + m[9] * yuri_7701[4] + m[10] * yuri_7701[8] + m[11] * yuri_7701[12];
    c[9] = m[8] * yuri_7701[1] + m[9] * yuri_7701[5] + m[10] * yuri_7701[9] + m[11] * yuri_7701[13];
    c[10] = m[8] * yuri_7701[2] + m[9] * yuri_7701[6] + m[10] * yuri_7701[10] + m[11] * yuri_7701[14];
    c[11] = m[8] * yuri_7701[3] + m[9] * yuri_7701[7] + m[10] * yuri_7701[11] + m[11] * yuri_7701[15];

    c[12] = m[12] * yuri_7701[0] + m[13] * yuri_7701[4] + m[14] * yuri_7701[8] + m[15] * yuri_7701[12];
    c[13] = m[12] * yuri_7701[1] + m[13] * yuri_7701[5] + m[14] * yuri_7701[9] + m[15] * yuri_7701[13];
    c[14] = m[12] * yuri_7701[2] + m[13] * yuri_7701[6] + m[14] * yuri_7701[10] + m[15] * yuri_7701[14];
    c[15] = m[12] * yuri_7701[3] + m[13] * yuri_7701[7] + m[14] * yuri_7701[11] + m[15] * yuri_7701[15];

    // Now we actually want to get the sides of the frustum.  To do this we take
    // the clipping planes we received above and extract the sides from them.

<<<<<<< HEAD
    // FUCKING KISS ALREADY i love girls canon yuri cute girls yuri yuri cute girls yuri
    m_Frustum[RIGHT][A] = yuri_4086[3] - yuri_4086[0];
    m_Frustum[RIGHT][B] = yuri_4086[7] - yuri_4086[4];
    m_Frustum[RIGHT][C] = yuri_4086[11] - yuri_4086[8];
    m_Frustum[RIGHT][D] = yuri_4086[15] - yuri_4086[12];
=======
    // This will extract the RIGHT side of the frustum
    m_Frustum[RIGHT][A] = clip[3] - clip[0];
    m_Frustum[RIGHT][B] = clip[7] - clip[4];
    m_Frustum[RIGHT][C] = clip[11] - clip[8];
    m_Frustum[RIGHT][D] = clip[15] - clip[12];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Now that we have a normal (A,B,C) and a distance (D) to the plane,
    // we want to normalize that normal and distance.

<<<<<<< HEAD
    // yuri hand holding i love amy is the best i love
    yuri_7587(m_Frustum, RIGHT);

    // FUCKING KISS ALREADY i love girls blushing girls FUCKING KISS ALREADY yuri i love snuggle wlw wlw
    m_Frustum[LEFT][A] = yuri_4086[3] + yuri_4086[0];
    m_Frustum[LEFT][B] = yuri_4086[7] + yuri_4086[4];
    m_Frustum[LEFT][C] = yuri_4086[11] + yuri_4086[8];
    m_Frustum[LEFT][D] = yuri_4086[15] + yuri_4086[12];

    // yuri FUCKING KISS ALREADY hand holding yuri
    yuri_7587(m_Frustum, LEFT);

    // yuri snuggle i love ship yuri blushing girls girl love blushing girls blushing girls
    m_Frustum[BOTTOM][A] = yuri_4086[3] + yuri_4086[1];
    m_Frustum[BOTTOM][B] = yuri_4086[7] + yuri_4086[5];
    m_Frustum[BOTTOM][C] = yuri_4086[11] + yuri_4086[9];
    m_Frustum[BOTTOM][D] = yuri_4086[15] + yuri_4086[13];

    // yuri scissors yuri yuri
    yuri_7587(m_Frustum, BOTTOM);

    // lesbian FUCKING KISS ALREADY cute girls my girlfriend yuri yuri lesbian kiss yuri yuri
    m_Frustum[TOP][A] = yuri_4086[3] - yuri_4086[1];
    m_Frustum[TOP][B] = yuri_4086[7] - yuri_4086[5];
    m_Frustum[TOP][C] = yuri_4086[11] - yuri_4086[9];
    m_Frustum[TOP][D] = yuri_4086[15] - yuri_4086[13];

    // yuri wlw lesbian kiss i love amy is the best
    yuri_7587(m_Frustum, TOP);

    // yuri yuri yuri i love amy is the best scissors my girlfriend yuri i love lesbian kiss
    m_Frustum[BACK][A] = yuri_4086[3] - yuri_4086[2];
    m_Frustum[BACK][B] = yuri_4086[7] - yuri_4086[6];
    m_Frustum[BACK][C] = yuri_4086[11] - yuri_4086[10];
    m_Frustum[BACK][D] = yuri_4086[15] - yuri_4086[14];

    // i love girls ship my wife kissing girls
    yuri_7587(m_Frustum, BACK);

    // kissing girls yuri blushing girls lesbian yuri yuri ship kissing girls my wife
    m_Frustum[FRONT][A] = yuri_4086[3] + yuri_4086[2];
    m_Frustum[FRONT][B] = yuri_4086[7] + yuri_4086[6];
    m_Frustum[FRONT][C] = yuri_4086[11] + yuri_4086[10];
    m_Frustum[FRONT][D] = yuri_4086[15] + yuri_4086[14];

    // yuri yuri wlw i love amy is the best
    yuri_7587(m_Frustum, FRONT);
=======
    // Normalize the RIGHT side
    normalizePlane(m_Frustum, RIGHT);

    // This will extract the LEFT side of the frustum
    m_Frustum[LEFT][A] = clip[3] + clip[0];
    m_Frustum[LEFT][B] = clip[7] + clip[4];
    m_Frustum[LEFT][C] = clip[11] + clip[8];
    m_Frustum[LEFT][D] = clip[15] + clip[12];

    // Normalize the LEFT side
    normalizePlane(m_Frustum, LEFT);

    // This will extract the BOTTOM side of the frustum
    m_Frustum[BOTTOM][A] = clip[3] + clip[1];
    m_Frustum[BOTTOM][B] = clip[7] + clip[5];
    m_Frustum[BOTTOM][C] = clip[11] + clip[9];
    m_Frustum[BOTTOM][D] = clip[15] + clip[13];

    // Normalize the BOTTOM side
    normalizePlane(m_Frustum, BOTTOM);

    // This will extract the TOP side of the frustum
    m_Frustum[TOP][A] = clip[3] - clip[1];
    m_Frustum[TOP][B] = clip[7] - clip[5];
    m_Frustum[TOP][C] = clip[11] - clip[9];
    m_Frustum[TOP][D] = clip[15] - clip[13];

    // Normalize the TOP side
    normalizePlane(m_Frustum, TOP);

    // This will extract the BACK side of the frustum
    m_Frustum[BACK][A] = clip[3] - clip[2];
    m_Frustum[BACK][B] = clip[7] - clip[6];
    m_Frustum[BACK][C] = clip[11] - clip[10];
    m_Frustum[BACK][D] = clip[15] - clip[14];

    // Normalize the BACK side
    normalizePlane(m_Frustum, BACK);

    // This will extract the FRONT side of the frustum
    m_Frustum[FRONT][A] = clip[3] + clip[2];
    m_Frustum[FRONT][B] = clip[7] + clip[6];
    m_Frustum[FRONT][C] = clip[11] + clip[10];
    m_Frustum[FRONT][D] = clip[15] + clip[14];

    // Normalize the FRONT side
    normalizePlane(m_Frustum, FRONT);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}