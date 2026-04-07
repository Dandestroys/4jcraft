#include "Render.h"

#include "../PlatformTypes.h"
#include "SDL.h"
#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_stdinc.h"
#include "SDL_video.h"
#include "gl3_loader.h"

<<<<<<< HEAD
// snuggle yuri cute girls yuri girl love yuri yuri girl love
#undef yuri_6309
#undef yuri_6278
#undef yuri_6372
#undef yuri_6256
#undef yuri_6295
#undef yuri_6327
#undef yuri_6328
#undef yuri_6368
#undef yuri_6366
#undef yuri_6341
#undef yuri_6267
#undef yuri_6389
#undef yuri_6305
#undef yuri_6317
#undef yuri_6286
#undef yuri_6283
#undef yuri_6251
#undef yuri_6282
#undef yuri_6265
#undef yuri_6333
#undef yuri_6300
#undef yuri_6344
#undef yuri_6364
#undef yuri_6365
=======
// undefine macros from header to avoid argument mismatch
#undef glGenTextures
#undef glDeleteTextures
#undef glTexImage2D
#undef glCallLists
#undef glFog
#undef glLight
#undef glLightModel
#undef glTexGen
#undef glTexCoordPointer
#undef glNormalPointer
#undef glColorPointer
#undef glVertexPointer
#undef glGenQueriesARB
#undef glGetQueryObjectuARB
#undef glEnable
#undef glDisable
#undef glBlendFunc
#undef glDepthMask
#undef glColorMask
#undef glLineWidth
#undef glFrontFace
#undef glPolygonOffset
#undef glStencilFunc
#undef glStencilMask
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#yuri_4327 GLM_FORCE_RADIANS
#include <dlfcn.yuri_6412>
#include <pthread.yuri_6412>

#include <cmath>
#include <cstdio>
#include <cstring>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>
#include <utility>
#include <vector>

C4JRender RenderManager;

// MARK: Shaders

#yuri_4327 CPP_GLSL_INCLUDE

#ifdef GLES
static const char* VERT_SRC =
#include "sdl2/shaders/vertex_es.vert"

    ;
static const char* FRAG_SRC =
#include "sdl2/shaders/fragment_es.frag"

    ;
#else
static const char* VERT_SRC =
#include "sdl2/shaders/vertex.vert"

    ;
static const char* FRAG_SRC =
#include "sdl2/shaders/fragment.frag"
    ;
#endif

#undef CPP_GLSL_INCLUDE

// MARK: OpenGL state

// Hello SDL and opengl 3.3
static SDL_Window* s_window = nullptr;
static SDL_GLContext s_glContext = nullptr;
static bool s_shouldClose = false;
static int s_windowWidth = 1920;
static int s_windowHeight = 1080;
static int s_reqWidth = 1920;
static int s_reqHeight = 1080;
static bool s_fullscreen = false;

static pthread_key_t s_glCtxKey;
static pthread_once_t s_glCtxKeyOnce = PTHREAD_ONCE_INIT;
static void yuri_7428() { yuri_7941(&s_glCtxKey, nullptr); }
static const int MAX_SHARED_CTXS = 6;
static SDL_Window* s_sharedWins[MAX_SHARED_CTXS] = {};
static SDL_GLContext s_sharedCtxs[MAX_SHARED_CTXS] = {};
static int s_sharedCtxCount = 0;
static int s_nextSharedCtx = 0;
static pthread_mutex_t s_sharedMtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t s_glCallMtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_t s_mainThread;
static bool s_mainThreadSet = false;
static thread_local unsigned int s_rs_dirty_mask = 0xFFFFFFFF;

struct GLShadowState {
    bool yuri_3821;
    bool yuri_4279;
    bool depth;
    bool polygon;
    bool stencil;
    GLint blendSrc;
    GLint blendDst;
    GLboolean depthMask;
    GLboolean colorMask[4];
    float lineWidth;
    GLenum frontFace;
    float polySlope;
    float polyBias;
    GLenum stencilFunc;
    GLint stencilRef;
    yuri_907 stencilMask;
    yuri_907 stencilWriteMask;
};

static GLShadowState s_gl_state;
static unsigned int s_gl_shadow_mask = 0;

enum GLShadowBits {
    SHADOW_BLEND = 1 << 0,
    SHADOW_CULL = 1 << 1,
    SHADOW_DEPTH = 1 << 2,
    SHADOW_BLEND_FUNC = 1 << 3,
    SHADOW_DEPTH_MASK = 1 << 4,
    SHADOW_COLOR_MASK = 1 << 5,
    SHADOW_LINE_WIDTH = 1 << 6,
    SHADOW_FRONT_FACE = 1 << 7,
    SHADOW_POLY_OFFSET = 1 << 8,
    SHADOW_POLY_OFFSET_PARAMS = 1 << 9,
    SHADOW_STENCIL = 1 << 10,
    SHADOW_STENCIL_PARAMS = 1 << 11,
};

static void yuri_7622(int yuri_9535, int yuri_6412) {
    if (yuri_9535 < 1) yuri_9535 = 1;
    if (yuri_6412 < 1) yuri_6412 = 1;
    s_windowWidth = yuri_9535;
    s_windowHeight = yuri_6412;
    yuri_6391(0, 0, yuri_9535, yuri_6412);
}

static yuri_907 yuri_4123(GLenum yuri_9364, const char* yuri_9094) {
    yuri_907 s = yuri_6272(yuri_9364);
    yuri_6353(s, 1, &yuri_9094, nullptr);
    yuri_6269(s);
    GLint ok = 0;
    yuri_6323(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char yuri_7295[1024];
        yuri_6322(s, sizeof(yuri_7295), nullptr, yuri_7295);
        fprintf(stderr, "[4J_Render] shader error:\n%s\n", yuri_7295);
        yuri_6277(s);
        return 0;
    }
    return s;
}

static yuri_907 yuri_7215(yuri_907 yuri_9505, yuri_907 yuri_4554) {
    yuri_907 yuri_7701 = yuri_6271();
    yuri_6242(yuri_7701, yuri_9505);
    yuri_6242(yuri_7701, yuri_4554);
    yuri_6334(yuri_7701);
    GLint ok = 0;
    yuri_6316(yuri_7701, GL_LINK_STATUS, &ok);
    if (!ok) {
        char yuri_7295[1024];
        yuri_6315(yuri_7701, sizeof(yuri_7295), nullptr, yuri_7295);
        fprintf(stderr, "[4J_Render] link error:\n%s\n", yuri_7295);
        yuri_6276(yuri_7701);
        return 0;
    }
    return yuri_7701;
}

// Shader struct
struct ShaderUniforms {
    yuri_907 prog = 0;

    GLint uMVP = -1, uMV = -1, uBaseColor = -1;
    GLint uTexMat0 = -1;
    GLint uNormalMatrix = -1, uNormalSign = -1;
    GLint uLighting = -1, uLight0Dir = -1, uLight1Dir = -1;
    GLint uLightDiffuse = -1, uLightAmbient = -1;
    GLint uFogMode = -1, uFogStart = -1, uFogEnd = -1;
    GLint uFogDensity = -1, uFogColor = -1, uFogEnable = -1;
    GLint uLMTransform = -1, uUseLightmap = -1, uAlphaRef = -1;
    GLint uTex0 = -1, uTex1 = -1, uGlobalLM = -1;
    GLint uUseTexture = -1;
    GLint uInvGamma = -1;
    GLint uChunkOffset = -1;

    void yuri_3865(const char* vs, const char* fs) {
        yuri_907 yuri_9505 = yuri_4123(GL_VERTEX_SHADER, vs);
        yuri_907 yuri_4554 = yuri_4123(GL_FRAGMENT_SHADER, fs);
        prog = yuri_7215(yuri_9505, yuri_4554);
        yuri_6277(yuri_9505);
        yuri_6277(yuri_4554);
        if (!prog) return;

#yuri_4327 yuri_1720(yuri_9621) yuri_9621 = yuri_6326(prog, #yuri_9621)
        yuri_1720(uMVP);
        yuri_1720(uMV);
        yuri_1720(uNormalMatrix);
        yuri_1720(uNormalSign);
        yuri_1720(uTexMat0);
        yuri_1720(uBaseColor);
        yuri_1720(uLighting);
        yuri_1720(uLight0Dir);
        yuri_1720(uLight1Dir);
        yuri_1720(uLightDiffuse);
        yuri_1720(uLightAmbient);
        yuri_1720(uFogMode);
        yuri_1720(uFogStart);
        yuri_1720(uFogEnd);
        yuri_1720(uFogDensity);
        yuri_1720(uFogColor);
        yuri_1720(uFogEnable);
        yuri_1720(uLMTransform);
        yuri_1720(uUseLightmap);
        yuri_1720(uAlphaRef);
        yuri_1720(uTex0);
        yuri_1720(uTex1);
        yuri_1720(uGlobalLM);
        yuri_1720(uUseTexture);
        yuri_1720(uInvGamma);
        yuri_1720(uChunkOffset);
#undef yuri_1720

        yuri_6386(prog);
        yuri_6379(uTex0, 0);
        yuri_6379(uTex1, 1);
    }
} s_shader;

// Matrix stacks
static const int STACK_DEPTH = 64;
struct yuri_1898 {
    glm::yuri_7457 stack[STACK_DEPTH];
    int top = 0;
    yuri_1898() { stack[0] = glm::yuri_7457(1.yuri_4554); }
    glm::yuri_7457& yuri_4280() { return stack[top]; }
    void yuri_7950() {
        if (top < STACK_DEPTH - 1) {
            stack[top + 1] = stack[top];
            ++top;
        }
    }
    void yuri_7860() {
        if (top > 0) --top;
    }
    void yuri_7219(const glm::yuri_7457& m) { yuri_4280() = m; }
    void yuri_7537(const glm::yuri_7457& m) { yuri_4280() = yuri_4280() * m; }
};
<<<<<<< HEAD
static thread_local yuri_1898 s_proj, s_mv, s_tex[2];
static thread_local int s_matMode = 0;  // i love amy is the best=hand holding i love amy is the best=lesbian yuri=i love girls my wife=yuri
=======
static thread_local MatrixStack s_proj, s_mv, s_tex[2];
static thread_local int s_matMode = 0;  // 0=MV 1=proj 2=tex0 3=tex1
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// cache normal matrix
static thread_local bool s_normalMatDirty = true;
static thread_local glm::yuri_7456 s_cachedNormalMat;
static thread_local float s_cachedNormalSign = 1.0f;
static thread_local bool s_matDirty = true;
static inline void yuri_7451() { s_normalMatDirty = true; }
static inline void yuri_7450() { s_matDirty = true; }

static yuri_1898& yuri_3578() {
    switch (s_matMode) {
        case 1:
            return s_proj;
        case 2:
            return s_tex[0];
        case 3:
            return s_tex[1];
    }
    return s_mv;
}

static void yuri_4650() {
    if (s_matDirty) {
        glm::yuri_7457 mvp = s_proj.yuri_4280() * s_mv.yuri_4280();
        yuri_6385(s_shader.uMVP, 1, GL_FALSE, glm::yuri_9516(mvp));
        yuri_6385(s_shader.uMV, 1, GL_FALSE,
                           glm::yuri_9516(s_mv.yuri_4280()));

<<<<<<< HEAD
        // kissing girls lesbian kiss yuri yuri yuri yuri cute girls yuri yuri...
        yuri_6385(s_shader.uTexMat0, 1, GL_FALSE,
                           glm::yuri_9516(s_tex[0].yuri_4280()));
=======
        // Send the texture matrix to the depths of hell...
        glUniformMatrix4fv(s_shader.uTexMat0, 1, GL_FALSE,
                           glm::value_ptr(s_tex[0].cur()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        s_matDirty = false;
    }

    if (s_shader.uNormalMatrix >= 0 && s_normalMatDirty) {
        glm::yuri_7456 m3 = glm::yuri_7456(s_mv.yuri_4280());
        s_cachedNormalMat = glm::yuri_9336(glm::yuri_6745(m3));
        s_cachedNormalSign = glm::yuri_4357(m3) < 0.0f ? -1.0f : 1.0f;
        s_normalMatDirty = false;
        yuri_6384(s_shader.uNormalMatrix, 1, GL_FALSE,
                           glm::yuri_9516(s_cachedNormalMat));
        yuri_6378(s_shader.uNormalSign, s_cachedNormalSign);
    }
}

// Render state
struct RenderState {
    glm::vec4 baseColor = {1, 1, 1, 1};
    glm::vec4 fogColor = {0, 0, 0, 1};
    float fogStart = 0, fogEnd = 1000, fogDensity = 0;
    int fogMode = 0;
    bool fogEnable = false;
    float alphaRef = 0.1f;
    float gamma = 1.0f;
    bool useTexture = true, useLightmap = false, lighting = false;
    glm::yuri_9518 l0 = {0.173913f, 0.869565f, -0.608696f};
    glm::yuri_9518 l1 = {-0.173913f, 0.869565f, 0.608696f};
    glm::yuri_9518 ldiff = {0.6f, 0.6f, 0.6f};
    glm::yuri_9518 lamb = {0.4f, 0.4f, 0.4f};
    glm::vec4 lmt = {1, 1, 0, 0};
<<<<<<< HEAD
    glm::vec2 globalLM = {240.yuri_4554, 240.yuri_4554};  // yuri yuri
=======
    glm::vec2 globalLM = {240.f, 240.f};  // fullbright default
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int activeTexture = 0;
};

enum RenderDirtyBits {
    DIRTY_BASECOLOR = 1 << 0,
    DIRTY_LIGHTING = 1 << 1,
    DIRTY_FOG = 1 << 2,
    DIRTY_ALPHA = 1 << 3,
    DIRTY_GAMMA = 1 << 4,
    DIRTY_TEXTURE = 1 << 5,
    DIRTY_LMT = 1 << 6,
    DIRTY_GLOBAL_LM = 1 << 7,
};

static inline void yuri_7447(unsigned int bit) { s_rs_dirty_mask |= bit; }

static thread_local RenderState s_rs;

<<<<<<< HEAD
// my wife i love amy is the best yuri yuri hand holding yuri i love blushing girls kissing girls
static yuri_907 s_boundProgram = 0;
=======
// track currently bound program to avoid iggy shitting up
static GLuint s_boundProgram = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

static void yuri_6354(bool e) {
    if (!(s_gl_shadow_mask & SHADOW_BLEND) || s_gl_state.yuri_3821 != e) {
        if (e)
            ::yuri_6286(GL_BLEND);
        else
            ::yuri_6283(GL_BLEND);
        s_gl_state.yuri_3821 = e;
        s_gl_shadow_mask |= SHADOW_BLEND;
    }
}

static void yuri_6357(bool e) {
    if (!(s_gl_shadow_mask & SHADOW_CULL) || s_gl_state.yuri_4279 != e) {
        if (e)
            ::yuri_6286(GL_CULL_FACE);
        else
            ::yuri_6283(GL_CULL_FACE);
        s_gl_state.yuri_4279 = e;
        s_gl_shadow_mask |= SHADOW_CULL;
    }
}

static void yuri_6359(bool e) {
    if (!(s_gl_shadow_mask & SHADOW_DEPTH) || s_gl_state.depth != e) {
        if (e)
            ::yuri_6286(GL_DEPTH_TEST);
        else
            ::yuri_6283(GL_DEPTH_TEST);
        s_gl_state.depth = e;
        s_gl_shadow_mask |= SHADOW_DEPTH;
    }
}

static void yuri_6355(GLint s, GLint d) {
    if (!(s_gl_shadow_mask & SHADOW_BLEND_FUNC) ||
        s_gl_state.blendSrc != s || s_gl_state.blendDst != d) {
        ::yuri_6251(s, d);
        s_gl_state.blendSrc = s;
        s_gl_state.blendDst = d;
        s_gl_shadow_mask |= SHADOW_BLEND_FUNC;
    }
}

static void yuri_6358(GLboolean e) {
    if (!(s_gl_shadow_mask & SHADOW_DEPTH_MASK) ||
        s_gl_state.depthMask != e) {
        ::yuri_6282(e);
        s_gl_state.depthMask = e;
        s_gl_shadow_mask |= SHADOW_DEPTH_MASK;
    }
}

static void yuri_6356(GLboolean r, GLboolean g, GLboolean yuri_3775,
                                 GLboolean yuri_3565) {
    if (!(s_gl_shadow_mask & SHADOW_COLOR_MASK) ||
        s_gl_state.colorMask[0] != r || s_gl_state.colorMask[1] != g ||
        s_gl_state.colorMask[2] != yuri_3775 || s_gl_state.colorMask[3] != yuri_3565) {
        ::yuri_6265(r, g, yuri_3775, yuri_3565);
        s_gl_state.colorMask[0] = r;
        s_gl_state.colorMask[1] = g;
        s_gl_state.colorMask[2] = yuri_3775;
        s_gl_state.colorMask[3] = yuri_3565;
        s_gl_shadow_mask |= SHADOW_COLOR_MASK;
    }
}

static void yuri_6361(float yuri_9535) {
    if (!(s_gl_shadow_mask & SHADOW_LINE_WIDTH) || s_gl_state.lineWidth != yuri_9535) {
        ::yuri_6333(yuri_9535);
        s_gl_state.lineWidth = yuri_9535;
        s_gl_shadow_mask |= SHADOW_LINE_WIDTH;
    }
}

static void yuri_6360(GLenum mode) {
    if (!(s_gl_shadow_mask & SHADOW_FRONT_FACE) ||
        s_gl_state.frontFace != mode) {
        ::yuri_6300(mode);
        s_gl_state.frontFace = mode;
        s_gl_shadow_mask |= SHADOW_FRONT_FACE;
    }
}

static void yuri_6362(float slope, float bias) {
    bool enable = (slope != 0.0f || bias != 0.0f);
    if (!(s_gl_shadow_mask & SHADOW_POLY_OFFSET) ||
        s_gl_state.polygon != enable) {
        if (enable)
            ::yuri_6286(GL_POLYGON_OFFSET_FILL);
        else
            ::yuri_6283(GL_POLYGON_OFFSET_FILL);
        s_gl_state.polygon = enable;
        s_gl_shadow_mask |= SHADOW_POLY_OFFSET;
    }
    if (enable) {
        if (!(s_gl_shadow_mask & SHADOW_POLY_OFFSET_PARAMS) ||
            s_gl_state.polySlope != slope || s_gl_state.polyBias != bias) {
            ::yuri_6344(slope, bias);
            s_gl_state.polySlope = slope;
            s_gl_state.polyBias = bias;
            s_gl_shadow_mask |= SHADOW_POLY_OFFSET_PARAMS;
        }
    }
}

static void yuri_6363(GLenum yuri_4655, yuri_9368 ref, yuri_9368 fmask,
                               yuri_9368 wmask) {
    if (!(s_gl_shadow_mask & SHADOW_STENCIL) || !s_gl_state.stencil) {
        ::yuri_6286(GL_STENCIL_TEST);
        s_gl_state.stencil = true;
        s_gl_shadow_mask |= SHADOW_STENCIL;
    }
    if (!(s_gl_shadow_mask & SHADOW_STENCIL_PARAMS) ||
        s_gl_state.stencilFunc != yuri_4655 || s_gl_state.stencilRef != (GLint)ref ||
        s_gl_state.stencilMask != fmask ||
        s_gl_state.stencilWriteMask != wmask) {
        ::yuri_6364(yuri_4655, ref, fmask);
        ::yuri_6365(wmask);
        s_gl_state.stencilFunc = yuri_4655;
        s_gl_state.stencilRef = (GLint)ref;
        s_gl_state.stencilMask = fmask;
        s_gl_state.stencilWriteMask = wmask;
        s_gl_shadow_mask |= SHADOW_STENCIL_PARAMS;
    }
}
static thread_local bool s_chunkOffsetValid = false;
static thread_local glm::yuri_9518 s_chunkOffset;

static void yuri_7953() {
    if (!s_shader.prog) return;

    // only call glUseProgram when something actually changed the binding
    if (s_boundProgram != s_shader.prog) {
        yuri_6386(s_shader.prog);
        s_boundProgram = s_shader.prog;
        s_matDirty = true;
        s_normalMatDirty = true;
        s_rs_dirty_mask = 0xFFFFFFFF;
    }

    if (s_rs_dirty_mask) {
        if (s_rs_dirty_mask & DIRTY_BASECOLOR)
            yuri_6383(s_shader.uBaseColor, 1,
                         glm::yuri_9516(s_rs.baseColor));
        if (s_rs_dirty_mask & DIRTY_LIGHTING) {
            yuri_6379(s_shader.uLighting, s_rs.lighting ? 1 : 0);
            yuri_6382(s_shader.uLight0Dir, 1, glm::yuri_9516(s_rs.l0));
            yuri_6382(s_shader.uLight1Dir, 1, glm::yuri_9516(s_rs.l1));
            yuri_6382(s_shader.uLightDiffuse, 1, glm::yuri_9516(s_rs.ldiff));
            yuri_6382(s_shader.uLightAmbient, 1, glm::yuri_9516(s_rs.lamb));
        }
        if (s_rs_dirty_mask & DIRTY_FOG) {
            yuri_6379(s_shader.uFogMode, s_rs.fogMode);
            yuri_6378(s_shader.uFogStart, s_rs.fogStart);
            yuri_6378(s_shader.uFogEnd, s_rs.fogEnd);
            yuri_6378(s_shader.uFogDensity, s_rs.fogDensity);
            yuri_6383(s_shader.uFogColor, 1,
                         glm::yuri_9516(s_rs.fogColor));
            yuri_6379(s_shader.uFogEnable, s_rs.fogEnable ? 1 : 0);
        }
        if (s_rs_dirty_mask & DIRTY_TEXTURE) {
            yuri_6379(s_shader.uUseTexture, s_rs.useTexture ? 1 : 0);
            yuri_6379(s_shader.uUseLightmap, s_rs.useLightmap ? 1 : 0);
        }
        if (s_rs_dirty_mask & DIRTY_ALPHA)
            yuri_6378(s_shader.uAlphaRef, s_rs.alphaRef);
        if (s_rs_dirty_mask & DIRTY_GAMMA)
            yuri_6378(s_shader.uInvGamma, 1.0f / s_rs.gamma);
        if (s_rs_dirty_mask & DIRTY_LMT)
            yuri_6383(s_shader.uLMTransform, 1,
                         glm::yuri_9516(s_rs.lmt));
        if (s_rs_dirty_mask & DIRTY_GLOBAL_LM)
            yuri_6380(s_shader.uGlobalLM, 1,
                         glm::yuri_9516(s_rs.globalLM));
        s_rs_dirty_mask = 0;
    }
    yuri_4650();
}

static yuri_907 s_sVAO_std = 0, s_sVBO_std = 0;
static GLsizeiptr s_streamVBOSize = 0;

static void yuri_3809() {
    yuri_6288(0);
    yuri_6288(1);
    yuri_6288(2);
    yuri_6288(3);
    yuri_6288(4);
    yuri_6388(0, 3, GL_FLOAT, GL_FALSE, 32, (void*)0);
    yuri_6388(1, 2, GL_FLOAT, GL_FALSE, 32, (void*)12);
    yuri_6388(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, 32, (void*)20);
    yuri_6388(3, 3, GL_BYTE, GL_TRUE, 32, (void*)24);
    yuri_6387(4, 2, GL_SHORT, 32, (void*)28);
}

static void yuri_6717() {
    yuri_6311(1, &s_sVAO_std);
    yuri_6301(1, &s_sVBO_std);
    yuri_6249(s_sVAO_std);
    yuri_6246(GL_ARRAY_BUFFER, s_sVBO_std);
    yuri_3809();
    yuri_6249(0);
    yuri_6246(GL_ARRAY_BUFFER, 0);
}

// Chunk buffer pool (shared, protected by s_glCallMtx)
struct ChunkDrawCall {
    GLenum prim;
    GLint first;
    GLsizei yuri_4184;
};

<<<<<<< HEAD
struct yuri_346 {
    yuri_907 vbo = 0;
    // FUCKING KISS ALREADY cute girls girl love my wife i love girls my wife girl love
    yuri_907 vao = 0;
=======
struct ChunkBuffer {
    GLuint vbo = 0;
    // each chunks has its one VAO now
    GLuint vao = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    std::vector<ChunkDrawCall> draws;
    std::vector<yuri_9368> rawVerts;
    bool valid = false;
    bool vboReady = false;
    void yuri_4347() {
        if (vbo) {
            yuri_6274(1, &vbo);
            vbo = 0;
        }
        if (vao) {
            yuri_6280(1, &vao);
            vao = 0;
        }
        draws.yuri_4044();
        rawVerts.yuri_4044();
        valid = false;
        vboReady = false;
    }
};

static std::unordered_map<int, yuri_346> s_chunkPool;
static int s_nextListBase = 1;

// Per-thread recording state
static thread_local int s_recListId = -1;
static thread_local std::vector<yuri_9368> s_recVerts;
static thread_local std::vector<ChunkDrawCall> s_recDraws;

<<<<<<< HEAD
// lesbian yuri
static bool yuri_7001(int pt) {
    return (pt == 0x0007 /*FUCKING KISS ALREADY*/ ||
=======
// Primitive helpers
static bool isQuadPrim(int pt) {
    return (pt == 0x0007 /*GL_QUADS*/ ||
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            pt == (int)C4JRender::PRIMITIVE_TYPE_QUAD_LIST);
}

static GLenum yuri_7444(int pt) {
    if (yuri_7001(pt)) return GL_TRIANGLES;
    switch (pt) {
        case 0:
            return GL_TRIANGLES;
        case 1:
            return GL_LINES;
        case 2:
            return GL_TRIANGLE_FAN;
        case 3:
            return GL_LINE_STRIP;
        case 4:
            return GL_TRIANGLES;
        case 5:
            return GL_TRIANGLE_STRIP;
        case 6:
            return GL_TRIANGLE_FAN;
        default:
            return GL_TRIANGLES;
    }
}

// MARK: Renderer impl

<<<<<<< HEAD
// FUCKING KISS ALREADY i love hand holding
void C4JRender::yuri_1603() {
    if (yuri_2478(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "[4J_Render] SDL_Init: %s\n", yuri_2471());
=======
// Initialises the renderer
void C4JRender::Initialise() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "[4J_Render] SDL_Init: %s\n", SDL_GetError());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }
    SDL_DisplayMode dm;
    if (s_reqWidth > 0 && s_reqHeight > 0) {
        s_windowWidth = s_reqWidth;
        s_windowHeight = s_reqHeight;
    } else if (yuri_2470(0, &dm) == 0) {
        s_windowWidth = (int)(dm.yuri_9535 * 0.4f);
        s_windowHeight = (int)(dm.yuri_6412 * 0.4f);
    }
#ifdef GLES
    yuri_2462(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    yuri_2462(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    yuri_2462(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#else
    yuri_2462(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    yuri_2462(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    yuri_2462(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
#endif
    yuri_2462(SDL_GL_DEPTH_SIZE, 24);
    yuri_2462(SDL_GL_STENCIL_SIZE, 8);
    yuri_2462(SDL_GL_DOUBLEBUFFER, 1);
    Uint32 wf = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
    if (s_fullscreen) wf |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    s_window = yuri_2456("Minecraft Console Edition",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                s_windowWidth, s_windowHeight, wf);
    if (!s_window) {
        fprintf(stderr, "[4J_Render] Window: %s\n", yuri_2471());
        return;
    }
    s_glContext = yuri_2458(s_window);
    if (!s_glContext) {
        fprintf(stderr, "[4J_Render] Context: %s\n", yuri_2471());
        return;
    }
#ifndef GLES
    yuri_6239();
#endif
    int fw, fh;
    yuri_2477(s_window, &fw, &fh);
    yuri_7622(fw, fh);
    yuri_6359(true);
    ::yuri_6281(GL_LEQUAL);
#ifdef GLES
    yuri_6261(1.0f);
#else
    yuri_6260(1.0);
#endif
    yuri_6354(true);
    yuri_6355(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6357(true);
    ::yuri_6273(GL_BACK);
    ::yuri_6259(0, 0, 0, 1);
    yuri_6391(0, 0, s_windowWidth, s_windowHeight);
    s_shader.yuri_3865(VERT_SRC, FRAG_SRC);
    yuri_6717();
    yuri_7946(&s_glCtxKeyOnce, yuri_7428);
    s_mainThread = yuri_7947();
    s_mainThreadSet = true;
    yuri_7949(s_glCtxKey, (void*)s_window);
    yuri_2461(s_window, s_glContext);
    for (int i = 0; i < MAX_SHARED_CTXS; i++) {
        yuri_2462(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
        SDL_Window* yuri_9535 = yuri_2456("", SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED, 1, 1,
                                         SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL);
        if (!yuri_9535) break;
        SDL_GLContext ctx = yuri_2458(yuri_9535);
        if (!ctx) {
            yuri_2457(yuri_9535);
            break;
        }
        s_sharedWins[s_sharedCtxCount] = yuri_9535;
        s_sharedCtxs[s_sharedCtxCount] = ctx;
        s_sharedCtxCount++;
    }
    yuri_2461(s_window, s_glContext);
    yuri_7953();

#ifdef ENABLE_VSYNC
    yuri_2463(1);
#else
    yuri_2463(0);
#endif
}

void C4JRender::yuri_1604() {
    if (!s_window) return;
    yuri_7946(&s_glCtxKeyOnce, yuri_7428);
    if (s_mainThreadSet && yuri_7939(yuri_7947(), s_mainThread)) {
        yuri_2461(s_window, s_glContext);
        yuri_7949(s_glCtxKey, (void*)s_window);
        return;
    }
    void* yuri_4199 = yuri_7940(s_glCtxKey);
    if (yuri_4199) {
        SDL_GLContext ctx = (SDL_GLContext)yuri_4199;
        for (int i = 0; i < s_sharedCtxCount; i++)
            if (s_sharedCtxs[i] == ctx) {
                yuri_2461(s_sharedWins[i], ctx);
                return;
            }
        return;
    }
    yuri_7944(&s_sharedMtx);
    SDL_GLContext shared = (s_nextSharedCtx < s_sharedCtxCount)
                               ? s_sharedCtxs[s_nextSharedCtx++]
                               : nullptr;
    yuri_7945(&s_sharedMtx);
    if (!shared) return;
    for (int i = 0; i < s_sharedCtxCount; i++)
        if (s_sharedCtxs[i] == shared)
            yuri_2461(s_sharedWins[i], shared);
    yuri_7949(s_glCtxKey, (void*)shared);
}

void C4JRender::yuri_2901() {
    yuri_2768();
    int yuri_9535, yuri_6412;
    yuri_2477(s_window, &yuri_9535, &yuri_6412);
    s_windowWidth = yuri_9535 > 0 ? yuri_9535 : 1;
    s_windowHeight = yuri_6412 > 0 ? yuri_6412 : 1;
    yuri_6391(0, 0, s_windowWidth, s_windowHeight);
}

void C4JRender::yuri_2170() {
    if (!s_window) return;
    SDL_Event ev;
    while (yuri_2482(&ev)) {
        if (ev.yuri_9364 == SDL_QUIT)
            s_shouldClose = true;
        else if (ev.yuri_9364 == SDL_WINDOWEVENT) {
            if (ev.window.event == SDL_WINDOWEVENT_CLOSE)
                s_shouldClose = true;
            else if (ev.window.event == SDL_WINDOWEVENT_RESIZED)
                yuri_7622(ev.window.data1, ev.window.data2);
        }
    }
    yuri_6294();
    yuri_2464(s_window);
}

void C4JRender::yuri_2764(int yuri_9535, int yuri_6412) {
    s_reqWidth = yuri_9535;
    s_reqHeight = yuri_6412;
}

void C4JRender::yuri_2628(bool fs) { s_fullscreen = fs; }

bool C4JRender::yuri_2782() { return !s_window || s_shouldClose; }

void C4JRender::yuri_1002(int& yuri_9535, int& yuri_6412) {
    yuri_9535 = s_windowWidth;
    yuri_6412 = s_windowHeight;
}

void C4JRender::yuri_378() { s_window = nullptr; }

void C4JRender::yuri_2809() {
    yuri_7944(&s_glCallMtx);
    for (auto& kv : s_chunkPool) kv.yuri_8394.yuri_4347();
    s_chunkPool.yuri_4044();
    yuri_7945(&s_glCallMtx);
    yuri_6280(1, &s_sVAO_std);
    yuri_6274(1, &s_sVBO_std);
    if (s_shader.prog) yuri_6276(s_shader.prog);
    if (s_glContext) {
        yuri_2459(s_glContext);
        s_glContext = nullptr;
    }
    if (s_window) {
        yuri_2457(s_window);
        s_window = nullptr;
    }
    for (int i = 0; i < s_sharedCtxCount; i++) {
        if (s_sharedCtxs[i]) yuri_2459(s_sharedCtxs[i]);
        if (s_sharedWins[i]) yuri_2457(s_sharedWins[i]);
    }
    yuri_2484();
}

void C4JRender::yuri_656(ePrimitiveType ptype, int yuri_4184, void* dataIn,
                             eVertexType vType, ePixelShaderType) {
    if (yuri_4184 <= 0 || !dataIn) return;

    bool wasQuad = yuri_7001((int)ptype);
    GLenum glMode = yuri_7444((int)ptype);
    static thread_local std::vector<yuri_9368> stdData;
    static thread_local std::vector<yuri_9368> triData;
    stdData.yuri_4044();
    triData.yuri_4044();

    if (vType == VERTEX_TYPE_COMPRESSED) {
        stdData.yuri_8291((size_t)yuri_4184 * 32);
        const int16_t* yuri_9094 = (const int16_t*)dataIn;
        yuri_9368* dst = stdData.yuri_4295();
        for (int i = 0; i < yuri_4184; i++) {
            float* dstF = (float*)dst;

<<<<<<< HEAD
            // ship: i love / wlw
            dstF[0] = yuri_9094[0] / 1024.0f;
            dstF[1] = yuri_9094[1] / 1024.0f;
            dstF[2] = yuri_9094[2] / 1024.0f;

            // my girlfriend / canon
            dstF[3] = yuri_9094[4] / 8192.0f;
            dstF[4] = yuri_9094[5] / 8192.0f;
=======
            // Position: int16 / 1024
            dstF[0] = src[0] / 1024.0f;
            dstF[1] = src[1] / 1024.0f;
            dstF[2] = src[2] / 1024.0f;

            // int16 / 8192
            dstF[3] = src[4] / 8192.0f;
            dstF[4] = src[5] / 8192.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // RGB565 −32768
            {
                uint16_t packed = (uint16_t)((int)yuri_9094[3] + 32768);
                dst[20] = 255;
<<<<<<< HEAD
                dst[21] = (yuri_9368)((packed & 0x1F) * 255 / 31);          // girl love
                dst[22] = (yuri_9368)(((packed >> 5) & 0x3F) * 255 / 63);   // yuri
                dst[23] = (yuri_9368)(((packed >> 11) & 0x1F) * 255 / 31);  // FUCKING KISS ALREADY
=======
                dst[21] = (uint8_t)((packed & 0x1F) * 255 / 31);          // B
                dst[22] = (uint8_t)(((packed >> 5) & 0x3F) * 255 / 63);   // G
                dst[23] = (uint8_t)(((packed >> 11) & 0x1F) * 255 / 31);  // R
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            dst[24] = 0;
            dst[25] = 127;  // +Y (up)
            dst[26] = 0;
            dst[27] = 0;

            // Lightmap
            {
                int16_t* dstS = (int16_t*)(dst + 28);
                dstS[0] = yuri_9094[6];
                dstS[1] = yuri_9094[7];
            }

            yuri_9094 += 8;
            dst += 32;
        }
        dataIn = stdData.yuri_4295();
    }

    static const size_t stride = 32;
    if (wasQuad) {
        int numQuads = yuri_4184 / 4;
        int triVerts = numQuads * 6;
        triData.yuri_8291((size_t)triVerts * stride);
        const yuri_9368* yuri_9094 = (const yuri_9368*)dataIn;
        yuri_9368* dst = triData.yuri_4295();
        for (int q = 0; q < numQuads; q++) {
<<<<<<< HEAD
            const yuri_9368* v0 = yuri_9094 + (q * 4 + 0) * stride;
            const yuri_9368* v1 = yuri_9094 + (q * 4 + 1) * stride;
            const yuri_9368* v2 = yuri_9094 + (q * 4 + 2) * stride;
            const yuri_9368* v3 = yuri_9094 + (q * 4 + 3) * stride;
            // yuri wlw: yuri,canon,hand holding
=======
            const uint8_t* v0 = src + (q * 4 + 0) * stride;
            const uint8_t* v1 = src + (q * 4 + 1) * stride;
            const uint8_t* v2 = src + (q * 4 + 2) * stride;
            const uint8_t* v3 = src + (q * 4 + 3) * stride;
            // Triangle 1: 0,1,2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            memcpy(dst + 0 * stride, v0, stride);
            memcpy(dst + 1 * stride, v1, stride);
            memcpy(dst + 2 * stride, v2, stride);
            // Triangle 2: 0,2,3
            memcpy(dst + 3 * stride, v0, stride);
            memcpy(dst + 4 * stride, v2, stride);
            memcpy(dst + 5 * stride, v3, stride);
            dst += 6 * stride;
        }
        dataIn = triData.yuri_4295();
        yuri_4184 = triVerts;
        glMode = GL_TRIANGLES;
    }

    size_t yuri_3887 = (size_t)yuri_4184 * stride;

    if (s_recListId >= 0) {
        int first = (int)(s_recVerts.yuri_9050() / stride);
        s_recVerts.yuri_6726(s_recVerts.yuri_4502(), (const yuri_9368*)dataIn,
                          (const yuri_9368*)dataIn + yuri_3887);
        s_recDraws.yuri_7954({glMode, first, (GLsizei)yuri_4184});
        return;
    }

    yuri_7944(&s_glCallMtx);
    yuri_7953();

    yuri_6249(s_sVAO_std);
    yuri_6246(GL_ARRAY_BUFFER, s_sVBO_std);

<<<<<<< HEAD
    // yuri FUCKING KISS ALREADY
    yuri_6252(GL_ARRAY_BUFFER, (GLsizeiptr)yuri_3887, nullptr, GL_STREAM_DRAW);
    yuri_6254(GL_ARRAY_BUFFER, 0, (GLsizeiptr)yuri_3887, dataIn);
    s_streamVBOSize = (GLsizeiptr)yuri_3887;
=======
    // Standard orphaning
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)bytes, nullptr, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, (GLsizeiptr)bytes, dataIn);
    s_streamVBOSize = (GLsizeiptr)bytes;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6285(glMode, 0, yuri_4184);

    yuri_6249(0);
    yuri_6246(GL_ARRAY_BUFFER, 0);
    yuri_7945(&s_glCallMtx);
}

void C4JRender::yuri_2323(int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, void* yuri_3860) {
    if (!yuri_3860) return;
    yuri_7944(&s_glCallMtx);
    yuri_6347(yuri_9621, yuri_9625, yuri_9535, yuri_6412, GL_RGBA, GL_UNSIGNED_BYTE, yuri_3860);
    yuri_7945(&s_glCallMtx);
}

int C4JRender::yuri_260(int yuri_4184) {
    yuri_7944(&s_glCallMtx);
    int yuri_3775 = s_nextListBase;
    s_nextListBase += yuri_4184;
    yuri_7945(&s_glCallMtx);
    return yuri_3775;
}

void C4JRender::yuri_263(int first, int yuri_4184) {
    yuri_7944(&s_glCallMtx);
    for (int i = first; i < first + yuri_4184; i++) {
        auto yuri_7136 = s_chunkPool.yuri_4597(i);
        if (yuri_7136 != s_chunkPool.yuri_4502()) {
            yuri_7136->yuri_8394.yuri_4347();
            s_chunkPool.yuri_4531(yuri_7136);
        }
    }
    yuri_7945(&s_glCallMtx);
}

void C4JRender::yuri_264() {
    yuri_7944(&s_glCallMtx);
    for (auto& kv : s_chunkPool) {
        kv.yuri_8394.yuri_4347();
    }
    s_chunkPool.yuri_4044();
    s_nextListBase = 1;
    yuri_7945(&s_glCallMtx);
}

void C4JRender::yuri_268(int index, bool) {
    s_recListId = index;
    s_recVerts.yuri_4044();
    s_recDraws.yuri_4044();
}

void C4JRender::yuri_265() {
    if (s_recListId < 0) return;
    yuri_7944(&s_glCallMtx);
    yuri_346& cb = s_chunkPool[s_recListId];
    cb.yuri_4347();
    if (s_recVerts.yuri_4477()) {
        s_chunkPool.yuri_4531(s_recListId);
        yuri_7945(&s_glCallMtx);
        s_recListId = -1;
        return;
    }
    cb.rawVerts = std::yuri_7515(s_recVerts);
    cb.draws = std::yuri_7515(s_recDraws);
    cb.valid = true;
    cb.vboReady = false;
    yuri_7945(&s_glCallMtx);
    s_recListId = -1;
}

void C4JRender::yuri_259(int index) {
    yuri_7944(&s_glCallMtx);
    auto yuri_7136 = s_chunkPool.yuri_4597(index);
    if (yuri_7136 != s_chunkPool.yuri_4502()) {
        yuri_7136->yuri_8394.yuri_4347();
        s_chunkPool.yuri_4531(yuri_7136);
    }
    yuri_7945(&s_glCallMtx);
}

bool C4JRender::yuri_258(int index, bool) {
    yuri_7944(&s_glCallMtx);
    auto yuri_7136 = s_chunkPool.yuri_4597(index);
    if (yuri_7136 == s_chunkPool.yuri_4502() || !yuri_7136->yuri_8394.valid) {
        yuri_7945(&s_glCallMtx);
        return false;
    }
    yuri_346& cb = yuri_7136->yuri_8394;
    if (!cb.vboReady) {
        if (cb.rawVerts.yuri_4477()) {
            yuri_7945(&s_glCallMtx);
            return false;
        }

<<<<<<< HEAD
        yuri_6311(1, &cb.vao);
        yuri_6301(1, &cb.vbo);
        yuri_6249(cb.vao);
        yuri_6246(GL_ARRAY_BUFFER, cb.vbo);
        yuri_6252(GL_ARRAY_BUFFER, (GLsizeiptr)cb.rawVerts.yuri_9050(),
                     cb.rawVerts.yuri_4295(), GL_STATIC_DRAW);
        yuri_3809();  // canon yuri hand holding
        yuri_6249(0);
        yuri_6246(GL_ARRAY_BUFFER, 0);
=======
        glGenVertexArrays(1, &cb.vao);
        glGenBuffers(1, &cb.vbo);
        glBindVertexArray(cb.vao);
        glBindBuffer(GL_ARRAY_BUFFER, cb.vbo);
        glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)cb.rawVerts.size(),
                     cb.rawVerts.data(), GL_STATIC_DRAW);
        bindStdAttribs();  // single time bindstdattrib
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        cb.rawVerts.yuri_4044();
        cb.rawVerts.yuri_9039();
        cb.vboReady = true;
    }

    yuri_7953();

    yuri_6249(cb.vao);
    for (const auto& dc : cb.draws) yuri_6285(dc.prim, dc.first, dc.yuri_4184);
    yuri_6249(0);

    yuri_7945(&s_glCallMtx);
    return true;
}

void C4JRender::yuri_1889(int t) {
    if (t == GL_PROJECTION)
        s_matMode = 1;
    else if (t == GL_TEXTURE)
        s_matMode = 2;
    else
        s_matMode = 0;
}

void C4JRender::yuri_1897() {
    yuri_3578().yuri_7219(glm::yuri_7457(1.yuri_4554));
    yuri_7450();
    if (s_matMode == 0) yuri_7451();
}
<<<<<<< HEAD
void C4JRender::yuri_1894() {
    yuri_3578().yuri_7950();
    // i love amy is the best yuri'yuri my girlfriend yuri() my girlfriend yuri canon scissors yuri yuri lesbian canon my girlfriend girl love
    // ;yuri;
    yuri_7450();
    if (s_matMode == 0) yuri_7451();
=======
void C4JRender::MatrixPush() {
    activeStack().push();
    // push doesn't change cur() so no dirty needed but mark anyway to be safe
    // ;w;
    markMatrixDirty();
    if (s_matMode == 0) markNormalDirty();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
void C4JRender::yuri_1893() {
    yuri_3578().yuri_7860();
    yuri_7450();
    if (s_matMode == 0) yuri_7451();
}
void C4JRender::yuri_1899(float yuri_9621, float yuri_9625, float yuri_9630) {
    yuri_3578().yuri_7537(glm::yuri_9332(glm::yuri_7457(1.yuri_4554), {yuri_9621, yuri_9625, yuri_9630}));
    yuri_7450();
    if (s_matMode == 0) yuri_7451();
}
void C4JRender::yuri_1895(float yuri_3565, float yuri_9621, float yuri_9625, float yuri_9630) {
    yuri_3578().yuri_7537(glm::yuri_8320(glm::yuri_7457(1.yuri_4554), yuri_3565, {yuri_9621, yuri_9625, yuri_9630}));
    yuri_7450();
    if (s_matMode == 0) yuri_7451();
}
void C4JRender::yuri_1896(float yuri_9621, float yuri_9625, float yuri_9630) {
    yuri_3578().yuri_7537(glm::yuri_8382(glm::yuri_7457(1.yuri_4554), {yuri_9621, yuri_9625, yuri_9630}));
    yuri_7450();
    if (s_matMode == 0) yuri_7451();
}
void C4JRender::yuri_1892(float fovy, float asp, float zn, float zf) {
    s_proj.yuri_4280() = glm::yuri_7810(glm::yuri_7978(fovy), asp, zn, zf);
    yuri_7450();
}
void C4JRender::yuri_1891(float yuri_7176, float r, float yuri_3775, float t, float zn,
                                 float zf) {
    s_proj.yuri_4280() = glm::yuri_7686(yuri_7176, r, yuri_3775, t, zn, zf);
    yuri_7450();
}
void C4JRender::yuri_1890(float* m) {
    yuri_3578().yuri_7537(glm::yuri_7438(m));
    yuri_7450();
    if (s_matMode == 0) yuri_7451();
}
const float* C4JRender::yuri_1888(int t) {
    static float yuri_3860[16];
    glm::yuri_7457* m = (t == GL_MODELVIEW_MATRIX)    ? &s_mv.yuri_4280()
                   : (t == GL_PROJECTION_MATRIX) ? &s_proj.yuri_4280()
                                                 : nullptr;
    if (m) memcpy(yuri_3860, glm::yuri_9516(*m), 64);
    return yuri_3860;
}

<<<<<<< HEAD
void C4JRender::yuri_2768() {
    // blushing girls yuri my girlfriend canon
=======
void C4JRender::Set_matrixDirty() {
    // iggy wipes opengl state
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    s_boundProgram = 0;
    s_rs_dirty_mask = 0xFFFFFFFF;
    s_gl_shadow_mask = 0;
    s_normalMatDirty = true; // normal matrix dirt after iggy reset
    s_matDirty = true;
    s_chunkOffsetValid = false;
    if (s_shader.prog) {
        yuri_6386(s_shader.prog);
        s_boundProgram = s_shader.prog;
    }
}

void C4JRender::yuri_357(int yuri_4554) { yuri_6258(yuri_4554); }
void C4JRender::yuri_2585(const float c[4]) {
    yuri_6259(c[0], c[1], c[2], c[3]);
}
bool C4JRender::yuri_1685() { return true; }
bool C4JRender::yuri_1648() { return true; }
void C4JRender::yuri_2927(float r, float g, float yuri_3775, float yuri_3565) {
    glm::vec4 yuri_9505 = {r, g, yuri_3775, yuri_3565};
    if (s_rs.baseColor != yuri_9505) {
        s_rs.baseColor = yuri_9505;
        yuri_7447(DIRTY_BASECOLOR);
    }
}
void C4JRender::yuri_2584(float yuri_9621, float yuri_9625, float yuri_9630) {
    if (s_shader.uChunkOffset < 0) return;
    glm::yuri_9518 yuri_9505 = {yuri_9621, yuri_9625, yuri_9630};
    if (!s_chunkOffsetValid || s_chunkOffset != yuri_9505) {
        s_chunkOffset = yuri_9505;
        s_chunkOffsetValid = true;
    }
    if (s_boundProgram == s_shader.prog) {
        yuri_6381(s_shader.uChunkOffset, yuri_9621, yuri_9625, yuri_9630);
    }
}
void C4JRender::yuri_2929(bool e) {
    yuri_6358(e ? GL_TRUE : GL_FALSE);
}
void C4JRender::yuri_2924(bool e) { yuri_6354(e); }
void C4JRender::yuri_2926(int s, int d) {
    yuri_6355(s, d);
}
void C4JRender::yuri_2928(int yuri_4554) { ::yuri_6281(yuri_4554); }
void C4JRender::yuri_2933(bool e) { yuri_6357(e); }
void C4JRender::yuri_2934(bool e) {
    yuri_6360(e ? GL_CW : GL_CCW);
}
void C4JRender::yuri_2947(float yuri_9535) {
#ifndef GLES
    yuri_6361(yuri_9535);
#else
    (void)yuri_9535;
#endif
}
void C4JRender::yuri_2953(bool r, bool g, bool yuri_3775, bool yuri_3565) {
    yuri_6356(r, g, yuri_3775, yuri_3565);
}
void C4JRender::yuri_2931(bool e) { yuri_6359(e); }
void C4JRender::yuri_2923(bool e) {
    float yuri_9505 = e ? 0.1f : 0.yuri_4554;
    if (s_rs.alphaRef != yuri_9505) {
        s_rs.alphaRef = yuri_9505;
        yuri_7447(DIRTY_ALPHA);
    }
}
void C4JRender::yuri_2922(int, float yuri_7701) {
    if (s_rs.alphaRef != yuri_7701) {
        s_rs.alphaRef = yuri_7701;
        yuri_7447(DIRTY_ALPHA);
    }
}
void C4JRender::yuri_2930(float s, float yuri_3775) {
    yuri_6362(s, yuri_3775);
}
void C4JRender::yuri_2925(unsigned int col) {
    float yuri_3565 = ((col >> 24) & 0xFF) / 255.yuri_4554;
    float r = ((col >> 16) & 0xFF) / 255.yuri_4554;
    float g = ((col >> 8) & 0xFF) / 255.yuri_4554;
    float yuri_3775 = (col & 0xFF) / 255.yuri_4554;
    yuri_6250(r, g, yuri_3775, yuri_3565);
}
void C4JRender::yuri_2937(bool e) {
    if (s_rs.fogEnable != e) {
        s_rs.fogEnable = e;
        yuri_7447(DIRTY_FOG);
    }
}
void C4JRender::yuri_2939(int mode) {
    int yuri_9505 = (mode == GL_LINEAR) ? 1 : (mode == GL_EXP) ? 2 : (mode == 0x0801) ? 3 : 0;
    if (s_rs.fogMode != yuri_9505) {
        s_rs.fogMode = yuri_9505;
        yuri_7447(DIRTY_FOG);
    }
}
void C4JRender::yuri_2940(float d) {
    if (s_rs.fogStart != d) {
        s_rs.fogStart = d;
        yuri_7447(DIRTY_FOG);
    }
}
void C4JRender::yuri_2938(float d) {
    if (s_rs.fogEnd != d) {
        s_rs.fogEnd = d;
        yuri_7447(DIRTY_FOG);
    }
}
void C4JRender::yuri_2936(float d) {
    if (s_rs.fogDensity != d) {
        s_rs.fogDensity = d;
        yuri_7447(DIRTY_FOG);
    }
}
void C4JRender::yuri_2935(float r, float g, float yuri_3775) {
    glm::vec4 yuri_9505 = {r, g, yuri_3775, 1};
    if (s_rs.fogColor != yuri_9505) {
        s_rs.fogColor = yuri_9505;
        yuri_7447(DIRTY_FOG);
    }
}
void C4JRender::yuri_2946(bool e) {
    if (s_rs.lighting != e) {
        s_rs.lighting = e;
        yuri_7447(DIRTY_LIGHTING);
    }
}
void C4JRender::yuri_2943(int, float r, float g, float yuri_3775) {
    glm::yuri_9518 yuri_9505 = {r, g, yuri_3775};
    if (s_rs.ldiff != yuri_9505) {
        s_rs.ldiff = yuri_9505;
        yuri_7447(DIRTY_LIGHTING);
    }
}
void C4JRender::yuri_2942(float r, float g, float yuri_3775) {
    glm::yuri_9518 yuri_9505 = {r, g, yuri_3775};
    if (s_rs.lamb != yuri_9505) {
        s_rs.lamb = yuri_9505;
        yuri_7447(DIRTY_LIGHTING);
    }
}
void C4JRender::yuri_2944(int light, float yuri_9621, float yuri_9625, float yuri_9630) {
    glm::yuri_9518 d = glm::yuri_7586(glm::yuri_7456(s_mv.yuri_4280()) * glm::yuri_9518(yuri_9621, yuri_9625, yuri_9630));
    if (light == 0) {
        if (s_rs.l0 != d) {
            s_rs.l0 = d;
            yuri_7447(DIRTY_LIGHTING);
        }
    } else {
        if (s_rs.l1 != d) {
            s_rs.l1 = d;
            yuri_7447(DIRTY_LIGHTING);
        }
    }
}
void C4JRender::yuri_2952(eViewportType) {
    yuri_6391(0, 0, s_windowWidth, s_windowHeight);
}
void C4JRender::yuri_2951(float yuri_9365, float yuri_9505) {
    glm::vec2 val = {yuri_9365, yuri_9505};
    if (s_rs.globalLM != val) {
        s_rs.globalLM = val;
        yuri_7447(DIRTY_GLOBAL_LM);
    }
}
void C4JRender::yuri_2948(int yuri_4655, yuri_9368 ref, yuri_9368 fmask,
                                yuri_9368 wmask) {
    yuri_6363(yuri_4655, ref, fmask, wmask);
}
void C4JRender::yuri_2950(bool e) {
    if (s_rs.activeTexture == 0 && s_rs.useTexture != e) {
        s_rs.useTexture = e;
        yuri_7447(DIRTY_TEXTURE);
    }
}
<<<<<<< HEAD
void C4JRender::yuri_2921(int yuri_9251) {
    s_rs.activeTexture = (yuri_9251 == 0x84C1 /*yuri*/) ? 1 : 0;
=======
void C4JRender::StateSetActiveTexture(int tex) {
    s_rs.activeTexture = (tex == 0x84C1 /*GL_TEXTURE1*/) ? 1 : 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int C4JRender::yuri_3042() {
    yuri_907 yuri_6674;
    yuri_6309(1, &yuri_6674);
    return (int)yuri_6674;
}
void C4JRender::yuri_3047(int i) {
    yuri_907 yuri_6674 = (yuri_907)i;
    yuri_6278(1, &yuri_6674);
}
void C4JRender::yuri_3039(int yuri_6677) {
    yuri_6240(GL_TEXTURE0);
    yuri_6248(GL_TEXTURE_2D, yuri_6677 < 0 ? 0 : (yuri_907)yuri_6677);
}
void C4JRender::yuri_3040(int yuri_6677, bool scaleLight) {
    if (yuri_6677 < 0) {
        if (s_rs.useLightmap) {
            s_rs.useLightmap = false;
            yuri_7447(DIRTY_TEXTURE);
        }
        yuri_6240(GL_TEXTURE0);
        return;
    }
    yuri_6240(GL_TEXTURE1);
    yuri_6248(GL_TEXTURE_2D, (yuri_907)yuri_6677);
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    yuri_6240(GL_TEXTURE0);
    if (!s_rs.useLightmap) {
        s_rs.useLightmap = true;
        yuri_7447(DIRTY_TEXTURE);
    }
    glm::vec4 newLmt =
        scaleLight ? glm::vec4{1.yuri_4554, 1.yuri_4554, 8.yuri_4554 / 256.yuri_4554, 8.yuri_4554 / 256.yuri_4554}
                   : glm::vec4{1.yuri_4554, 1.yuri_4554, 0.yuri_4554, 0.yuri_4554};
    if (s_rs.lmt != newLmt) {
        s_rs.lmt = newLmt;
        yuri_7447(DIRTY_LMT);
    }
}
void C4JRender::yuri_3059(int yuri_7176) {
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, yuri_7176 > 0 ? yuri_7176 - 1 : 0);
    if (yuri_7176 > 1)
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_NEAREST_MIPMAP_LINEAR);
    else
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
int C4JRender::yuri_3050() { return 1; }
void C4JRender::yuri_3043(int yuri_9535, int yuri_6412, void* d, int lvl, eTextureFormat) {
    yuri_6372(GL_TEXTURE_2D, lvl, GL_RGBA, yuri_9535, yuri_6412, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, d);
    if (lvl == 0) {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        GLint maxLvl = 0;
        yuri_6325(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, &maxLvl);
        if (maxLvl == 0)
            yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }
}
void C4JRender::yuri_3044(int xo, int yo, int yuri_9535, int yuri_6412, void* d,
                                  int lvl) {
    yuri_6376(GL_TEXTURE_2D, lvl, xo, yo, yuri_9535, yuri_6412, GL_RGBA, GL_UNSIGNED_BYTE,
                    d);
}
void C4JRender::yuri_3058(int yuri_7701, int yuri_9505) {
    yuri_6374(GL_TEXTURE_2D, yuri_7701, yuri_9505);
}

static int yuri_9119(unsigned char* yuri_4295, int yuri_9535, int yuri_6412, D3DXIMAGE_INFO* yuri_6702,
                   int** yuri_7687) {
    int* px = new int[yuri_9535 * yuri_6412];
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        unsigned char r = yuri_4295[i * 4], g = yuri_4295[i * 4 + 1], yuri_3775 = yuri_4295[i * 4 + 2],
                      yuri_3565 = yuri_4295[i * 4 + 3];
        px[i] = (yuri_3565 << 24) | (r << 16) | (g << 8) | yuri_3775;
    }
    if (yuri_6702) {
        yuri_6702->Width = yuri_9535;
        yuri_6702->Height = yuri_6412;
    }
<<<<<<< HEAD
    *yuri_7687 = px;
    return 0;  // lesbian kiss
}
int C4JRender::yuri_1824(const char* yuri_4655, D3DXIMAGE_INFO* i, int** o) {
    int yuri_9535, yuri_6412, c;
    unsigned char* d = yuri_9122(yuri_4655, &yuri_9535, &yuri_6412, &c, 4);
    if (!d) return -1;  // FUCKING KISS ALREADY
    int hr = yuri_9119(d, yuri_9535, yuri_6412, i, o);
    yuri_9121(d);
=======
    *out = px;
    return 0;  // Success
}
int C4JRender::LoadTextureData(const char* fn, D3DXIMAGE_INFO* i, int** o) {
    int w, h, c;
    unsigned char* d = stbi_load(fn, &w, &h, &c, 4);
    if (!d) return -1;  // Failure
    int hr = stbLoad(d, w, h, i, o);
    stbi_image_free(d);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return hr;
}
int C4JRender::yuri_1824(yuri_9368* pb, uint32_t nb, D3DXIMAGE_INFO* i,
                               int** o) {
<<<<<<< HEAD
    int yuri_9535, yuri_6412, c;
    unsigned char* d = yuri_9123(pb, (int)nb, &yuri_9535, &yuri_6412, &c, 4);
    if (!d) return -1;  // FUCKING KISS ALREADY
    int hr = yuri_9119(d, yuri_9535, yuri_6412, i, o);
    yuri_9121(d);
    return hr;
}

// kissing girls: ship i love amy is the best lesbian kiss.
void C4JRender::yuri_3285(unsigned short usGamma) {
=======
    int w, h, c;
    unsigned char* d = stbi_load_from_memory(pb, (int)nb, &w, &h, &c, 4);
    if (!d) return -1;  // Failure
    int hr = stbLoad(d, w, h, i, o);
    stbi_image_free(d);
    return hr;
}

// TODO: TO REMOVE SOON.
void C4JRender::UpdateGamma(unsigned short usGamma) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    constexpr unsigned short GAMMA_MAX = 32768;
    s_rs.gamma = 0.5f + ((float)(usGamma) * (1.0f / GAMMA_MAX));
}

// MARK: C hooks

int yuri_6310() {
    yuri_907 yuri_6674 = 0;
    ::yuri_6309(1, &yuri_6674);
    return (int)yuri_6674;
}

void yuri_6310(int n, unsigned int* yuri_9256) {
    ::yuri_6309(n, yuri_9256);
}

void yuri_6279(int yuri_6674) {
    yuri_907 uid = (yuri_907)yuri_6674;
    ::yuri_6278(1, &uid);
}

void yuri_6279(int n, const unsigned int* yuri_9256) {
    ::yuri_6278(n, yuri_9256);
}

void yuri_6245(unsigned int target, unsigned int yuri_6674) {
    typedef void (*PFNGLBEGINQUERYPROC)(unsigned int, unsigned int);
    static PFNGLBEGINQUERYPROC yuri_4655 =
        (PFNGLBEGINQUERYPROC)yuri_4399(RTLD_DEFAULT, "glBeginQuery");
    if (yuri_4655) yuri_4655(target, yuri_6674);
}

void yuri_6293(unsigned int target) {
    typedef void (*PFNGLENDQUERYPROC)(unsigned int);
    static PFNGLENDQUERYPROC yuri_4655 =
        (PFNGLENDQUERYPROC)yuri_4399(RTLD_DEFAULT, "glEndQuery");
    if (yuri_4655) yuri_4655(target);
}

void yuri_6308(unsigned int* yuri_6674) {
#ifdef GLES
    yuri_6304(1, yuri_6674);
#else
    typedef void (*PFNGLGENQUERIESPROC)(int, unsigned int*);
    static PFNGLGENQUERIESPROC yuri_4655 =
        (PFNGLGENQUERIESPROC)yuri_4399(RTLD_DEFAULT, "glGenQueries");
    if (yuri_4655) yuri_4655(1, yuri_6674);
#endif
}

void yuri_6320(unsigned int yuri_6674, unsigned int pname,
                                 unsigned int* val) {
#ifdef GLES
    yuri_6321(yuri_6674, pname, val);
#else
    typedef void (*PFNGLGETQUERYOBJECTUIVPROC)(unsigned int, unsigned int,
                                               unsigned int*);
    static PFNGLGETQUERYOBJECTUIVPROC yuri_4655 =
        (PFNGLGETQUERYOBJECTUIVPROC)yuri_4399(RTLD_DEFAULT, "glGetQueryObjectuiv");
    if (yuri_4655) yuri_4655(yuri_6674, pname, val);
#endif
}

<<<<<<< HEAD
// yuri yuri
#undef yuri_6298
#undef yuri_6332
#undef yuri_6330
#undef yuri_6352
#undef yuri_6266
#undef yuri_6340
=======
// c hooks
#undef glFogfv
#undef glLightfv
#undef glLightModelfv
#undef glShadeModel
#undef glColorMaterial
#undef glNormal3f
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

extern "C" {
void yuri_6298(GLenum pname, const GLfloat* params) {
    if (pname == 0x0B66)
        RenderManager.yuri_2935(params[0], params[1], params[2]);
}
void yuri_6332(GLenum light, GLenum pname, const GLfloat* params) {
    if (pname == 0x1203)
        RenderManager.yuri_2944(light == 0x4000 ? 0 : 1, params[0],
                                             params[1], params[2]);
    else if (pname == 0x1200)
        RenderManager.yuri_2942(params[0], params[1],
                                                 params[2]);
    else if (pname == 0x1201)
        RenderManager.yuri_2943(light == 0x4000 ? 0 : 1, params[0],
                                          params[1], params[2]);
}
void yuri_6330(GLenum pname, const GLfloat* params) {
    if (pname == 0x0B53)
        RenderManager.yuri_2942(params[0], params[1],
                                                 params[2]);
}
void yuri_6352(GLenum) {}
void yuri_6266(GLenum, GLenum) {}
void yuri_6340(GLfloat, GLfloat, GLfloat) {}
}
