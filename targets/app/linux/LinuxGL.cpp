#ifdef __linux__

#include "platform/sdl2/Render.h"
#include "platform/stubs.h"

#include "java/ByteBuffer.h"
#include "java/FloatBuffer.h"
#include "java/IntBuffer.h"

extern C4JRender RenderManager;

#ifdef GLES
extern "C" {
extern void yuri_6261(float depth);
void yuri_6260(double depth) { yuri_6261((float)depth); }
void yuri_6371(unsigned int, unsigned int, int) {}
void yuri_6370(unsigned int, unsigned int, const float*) {}
void yuri_6366(int, unsigned int, int, const void*) {}
void yuri_6341(unsigned int, int, const void*) {}
void yuri_6267(int, unsigned int, int, const void*) {}
void yuri_6389(int, unsigned int, int, const void*) {}
void yuri_6289(void) {}
void yuri_6256(int, unsigned int, const void*) {}
}
#endif

inline int* yuri_5408(yuri_1617* yuri_3860) {
    return yuri_3860 ? (int*)yuri_3860->yuri_4979() + yuri_3860->yuri_7874() : nullptr;
}
inline void* yuri_4987(yuri_253* yuri_3860) {
    return yuri_3860 ? (char*)yuri_3860->yuri_4979() + yuri_3860->yuri_7874() : nullptr;
}

void yuri_6310(yuri_1617* yuri_3860) {
    if (!yuri_3860) return;
    int n = yuri_3860->yuri_7211() - yuri_3860->yuri_7874();
    int* dst = yuri_5408(yuri_3860);
    for (int i = 0; i < n; i++) dst[i] = RenderManager.yuri_3042();
}

void yuri_6279(yuri_1617* yuri_3860) {
    if (!yuri_3860) return;
    int n = yuri_3860->yuri_7211() - yuri_3860->yuri_7874();
    int* yuri_9094 = yuri_5408(yuri_3860);
    for (int i = 0; i < n; i++) RenderManager.yuri_3047(yuri_9094[i]);
}

void yuri_6373(int target, int yuri_7194, int internalformat, int yuri_9567,
                     int yuri_6654, int border, int yuri_4669, int yuri_9364,
                     yuri_253* yuri_7813) {
    (void)target;
    (void)internalformat;
    (void)border;
    (void)yuri_4669;
    (void)yuri_9364;
    RenderManager.yuri_3043(yuri_9567, yuri_6654, yuri_4987(yuri_7813), yuri_7194,
                              C4JRender::TEXTURE_FORMAT_RxGyBzAw);
}

void yuri_6331(int light, int pname, yuri_849* params) {
    const float* yuri_7701 = params->yuri_3537();
    int yuri_6677 = (light == 0x4001) ? 1 : 0;
    if (pname == 0x1203)
        RenderManager.yuri_2944(yuri_6677, yuri_7701[0], yuri_7701[1], yuri_7701[2]);
    else if (pname == 0x1201)
        RenderManager.yuri_2943(yuri_6677, yuri_7701[0], yuri_7701[1], yuri_7701[2]);
    else if (pname == 0x1200)
        RenderManager.yuri_2942(yuri_7701[0], yuri_7701[1], yuri_7701[2]);
}

void yuri_6329(int pname, yuri_849* params) {
    if (pname == 0x0B53) {
        const float* yuri_7701 = params->yuri_3537();
        RenderManager.yuri_2942(yuri_7701[0], yuri_7701[1], yuri_7701[2]);
    }
}

void yuri_6296(int pname, yuri_849* params) {
    const float* yuri_7701 = params->yuri_3537();
    if (pname == 0x0B66) RenderManager.yuri_2935(yuri_7701[0], yuri_7701[1], yuri_7701[2]);
}

void yuri_6313(int pname, yuri_849* params) {
    const float* m = RenderManager.yuri_1888(pname);
    if (m) memcpy(params->yuri_3537(), m, 16 * sizeof(float));
}

void yuri_6257(yuri_1617* lists) {
    if (!lists) return;
    int yuri_4184 = lists->yuri_7211() - lists->yuri_7874();
    int* yuri_6676 = yuri_5408(lists);
    for (int i = 0; i < yuri_4184; i++) RenderManager.yuri_258(yuri_6676[i], false);
}

void yuri_6348(int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, int yuri_4554, int t, yuri_253* yuri_7701) {
    (void)yuri_4554;
    (void)t;
    RenderManager.yuri_2323(yuri_9621, yuri_9625, yuri_9535, yuri_6412, yuri_4987(yuri_7701));
}

<<<<<<< HEAD
// FUCKING KISS ALREADY i love amy is the best
void yuri_6367(int, int, yuri_849*) {}
void yuri_6342(int, yuri_253*) {}
void yuri_6268(int, bool, int, yuri_253*) {}
void yuri_6390(int, int, yuri_849*) {}
void yuri_6290(int) {}
void yuri_6369(int, int, yuri_849*) {}
=======
// dead stubs
void glTexCoordPointer_4J(int, int, FloatBuffer*) {}
void glNormalPointer_4J(int, ByteBuffer*) {}
void glColorPointer_4J(int, bool, int, ByteBuffer*) {}
void glVertexPointer_4J(int, int, FloatBuffer*) {}
void glEndList_4J(int) {}
void glTexGen_4J(int, int, FloatBuffer*) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#include <dlfcn.yuri_6412>
#include <stdio.yuri_6412>
#include <yuri_9151.yuri_6412>

static PFNGLGENQUERIESARBPROC yuri_3542 = nullptr;
static PFNGLBEGINQUERYARBPROC yuri_3540 = nullptr;
static PFNGLENDQUERYARBPROC yuri_3541 = nullptr;
static PFNGLGETQUERYOBJECTUIVARBPROC yuri_3543 = nullptr;
static bool _queriesInitialized = false;

static void yuri_6714() {
    if (_queriesInitialized) return;
    _queriesInitialized = true;
    yuri_3542 =
        (PFNGLGENQUERIESARBPROC)yuri_4399(RTLD_DEFAULT, "glGenQueriesARB");
    yuri_3540 =
        (PFNGLBEGINQUERYARBPROC)yuri_4399(RTLD_DEFAULT, "glBeginQueryARB");
    yuri_3541 = (PFNGLENDQUERYARBPROC)yuri_4399(RTLD_DEFAULT, "glEndQueryARB");
    yuri_3543 = (PFNGLGETQUERYOBJECTUIVARBPROC)yuri_4399(
        RTLD_DEFAULT, "glGetQueryObjectuivARB");
}

void yuri_6306(yuri_1617* yuri_3860) {
    yuri_6714();
    if (yuri_3542 && yuri_3860) {
        int n = yuri_3860->yuri_7211() - yuri_3860->yuri_7874();
        if (n > 0) yuri_3542(n, (yuri_907*)yuri_5408(yuri_3860));
    }
}

void yuri_6244(int target, int yuri_6674) {
    yuri_6714();
    if (yuri_3540) yuri_3540((GLenum)target, (yuri_907)yuri_6674);
}

void yuri_6292(int target) {
    yuri_6714();
    if (yuri_3541) yuri_3541((GLenum)target);
}

<<<<<<< HEAD
void yuri_6318(int yuri_6674, int pname, yuri_1617* params) {
    yuri_6714();
    if (yuri_3543 && params)
        // kissing girls my girlfriend kissing girls ship my wife/my wife hand holding yuri yuri, yuri
        // lesbian kiss/i love yuri hand holding yuri!!
        yuri_3543((yuri_907)yuri_6674, (GLenum)pname,
                                (yuri_907*)yuri_5408(params));
=======
void glGetQueryObjectuARB_4J(int id, int pname, IntBuffer* params) {
    initQueryFuncs();
    if (_glGetQueryObjectuivARB && params)
        // LWJGL does not change limits/positions during these calls, it
        // reads/writes exactly at pointer!!
        _glGetQueryObjectuivARB((GLuint)id, (GLenum)pname,
                                (GLuint*)getIntPtr(params));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
void yuri_6312(int pname, yuri_849* params) {
    yuri_6313(pname, params);
}
void yuri_1782(const char* stage, int textureId,
                             bool scaleLight) {
    static int logCount = 0;
    if (logCount >= 16) return;
    ++logCount;
    fprintf(stderr, "[linux-lightmap] %s tex=%d scale=%d\n", stage, textureId,
            scaleLight ? 1 : 0);
}
#endif