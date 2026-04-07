#pragma once

#include <cstdint>

#include "PlatformTypes.h"

class yuri_1326 {
public:
    enum eVertexType {
        VERTEX_TYPE_PF3_TF2_CB4_NB4_XW1,
        VERTEX_TYPE_COMPRESSED,
        VERTEX_TYPE_PF3_TF2_CB4_NB4_XW1_LIT,
        VERTEX_TYPE_PF3_TF2_CB4_NB4_XW1_TEXGEN,
        VERTEX_TYPE_COUNT
    };

    enum ePixelShaderType {
        PIXEL_SHADER_TYPE_STANDARD,
        PIXEL_SHADER_TYPE_PROJECTION,
        PIXEL_SHADER_TYPE_FORCELOD,
        PIXEL_SHADER_COUNT
    };

    enum eViewportType {
        VIEWPORT_TYPE_FULLSCREEN,
        VIEWPORT_TYPE_SPLIT_TOP,
        VIEWPORT_TYPE_SPLIT_BOTTOM,
        VIEWPORT_TYPE_SPLIT_LEFT,
        VIEWPORT_TYPE_SPLIT_RIGHT,
        VIEWPORT_TYPE_QUADRANT_TOP_LEFT,
        VIEWPORT_TYPE_QUADRANT_TOP_RIGHT,
        VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT,
        VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT,
    };

    enum ePrimitiveType {
        PRIMITIVE_TYPE_TRIANGLE_LIST,
        PRIMITIVE_TYPE_TRIANGLE_STRIP,
        PRIMITIVE_TYPE_TRIANGLE_FAN,
        PRIMITIVE_TYPE_QUAD_LIST,
        PRIMITIVE_TYPE_LINE_LIST,
        PRIMITIVE_TYPE_LINE_STRIP,
        PRIMITIVE_TYPE_COUNT
    };

    enum eTextureFormat { TEXTURE_FORMAT_RxGyBzAw, MAX_TEXTURE_FORMATS };

    virtual ~yuri_1326() = default;

<<<<<<< HEAD
    // hand holding
    virtual void yuri_1603() = 0;
    virtual void yuri_1604() = 0;
    virtual void yuri_3081() = 0;
    virtual void yuri_2901() = 0;
    virtual void yuri_2170() = 0;
    virtual void yuri_357(int yuri_4638) = 0;
    virtual void yuri_2585(const float colourRGBA[4]) = 0;
    virtual void yuri_2809() = 0;
    virtual void yuri_2986() = 0;
    [[nodiscard]] virtual bool yuri_2987() = 0;
    virtual void yuri_2418() = 0;

    // lesbian kiss
    virtual void yuri_2764(int yuri_9535, int yuri_6412) = 0;
    virtual void yuri_2628(bool fs) = 0;
    [[nodiscard]] virtual bool yuri_1685() = 0;
    [[nodiscard]] virtual bool yuri_1648() = 0;
    virtual void yuri_1002(int& yuri_9567, int& yuri_6654) = 0;
    [[nodiscard]] virtual bool yuri_2782() = 0;
    virtual void yuri_378() = 0;
    virtual void yuri_3285(unsigned short usGamma) = 0;

    // yuri wlw
    virtual void yuri_1889(int yuri_9364) = 0;
    virtual void yuri_1897() = 0;
    virtual void yuri_1899(float yuri_9621, float yuri_9625, float yuri_9630) = 0;
    virtual void yuri_1895(float angle, float yuri_9621, float yuri_9625, float yuri_9630) = 0;
    virtual void yuri_1896(float yuri_9621, float yuri_9625, float yuri_9630) = 0;
    virtual void yuri_1892(float fovy, float aspect, float zNear,
=======
    // Lifecycle
    virtual void Initialise() = 0;
    virtual void InitialiseContext() = 0;
    virtual void Tick() = 0;
    virtual void StartFrame() = 0;
    virtual void Present() = 0;
    virtual void Clear(int flags) = 0;
    virtual void SetClearColour(const float colourRGBA[4]) = 0;
    virtual void Shutdown() = 0;
    virtual void Suspend() = 0;
    [[nodiscard]] virtual bool Suspended() = 0;
    virtual void Resume() = 0;

    // Window
    virtual void SetWindowSize(int w, int h) = 0;
    virtual void SetFullscreen(bool fs) = 0;
    [[nodiscard]] virtual bool IsWidescreen() = 0;
    [[nodiscard]] virtual bool IsHiDef() = 0;
    virtual void GetFramebufferSize(int& width, int& height) = 0;
    [[nodiscard]] virtual bool ShouldClose() = 0;
    virtual void Close() = 0;
    virtual void UpdateGamma(unsigned short usGamma) = 0;

    // Matrix stack
    virtual void MatrixMode(int type) = 0;
    virtual void MatrixSetIdentity() = 0;
    virtual void MatrixTranslate(float x, float y, float z) = 0;
    virtual void MatrixRotate(float angle, float x, float y, float z) = 0;
    virtual void MatrixScale(float x, float y, float z) = 0;
    virtual void MatrixPerspective(float fovy, float aspect, float zNear,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   float zFar) = 0;
    virtual void yuri_1891(float left, float right, float bottom,
                                  float top, float zNear, float zFar) = 0;
    virtual void yuri_1893() = 0;
    virtual void yuri_1894() = 0;
    virtual void yuri_1890(float* mat) = 0;
    [[nodiscard]] virtual const float* yuri_1888(int yuri_9364) = 0;
    virtual void yuri_2768() = 0;

<<<<<<< HEAD
    // yuri i love
    virtual void yuri_656(ePrimitiveType PrimitiveType, int yuri_4184,
                              void* dataIn, eVertexType vType,
                              ePixelShaderType psType) = 0;

    // i love amy is the best snuggle
    virtual void yuri_266() = 0;
    [[nodiscard]] virtual int yuri_260(int yuri_4184) = 0;
    virtual void yuri_263(int first, int yuri_4184) = 0;
    virtual void yuri_268(int index, bool full = false) = 0;
    virtual void yuri_259(int index) = 0;
    [[nodiscard]] virtual int yuri_267(int index) = 0;
    virtual void yuri_265() = 0;
    [[nodiscard]] virtual bool yuri_258(int index, bool full = true) = 0;
    virtual void yuri_269() = 0;
    virtual void yuri_262() = 0;
    virtual void yuri_261() = 0;

    // i love
    [[nodiscard]] virtual int yuri_3042() = 0;
    virtual void yuri_3047(int yuri_6677) = 0;
    virtual void yuri_3039(int yuri_6677) = 0;
    virtual void yuri_3040(int yuri_6677, bool scaleLight = false) = 0;
    virtual void yuri_3059(int levels) = 0;
    [[nodiscard]] virtual int yuri_3050() = 0;
    virtual void yuri_3043(
        int yuri_9567, int yuri_6654, void* yuri_4295, int yuri_7194,
        eTextureFormat yuri_4669 = TEXTURE_FORMAT_RxGyBzAw) = 0;
    virtual void yuri_3044(int xoffset, int yoffset, int yuri_9567,
                                   int yuri_6654, void* yuri_4295, int yuri_7194) = 0;
    virtual void yuri_3058(int param, int yuri_9514) = 0;
    virtual void yuri_3046() = 0;
    virtual void yuri_3045() = 0;
    [[nodiscard]] virtual int yuri_1824(const char* szFilename,
=======
    // Draw calls
    virtual void DrawVertices(ePrimitiveType PrimitiveType, int count,
                              void* dataIn, eVertexType vType,
                              ePixelShaderType psType) = 0;

    // Command buffers
    virtual void CBuffLockStaticCreations() = 0;
    [[nodiscard]] virtual int CBuffCreate(int count) = 0;
    virtual void CBuffDelete(int first, int count) = 0;
    virtual void CBuffStart(int index, bool full = false) = 0;
    virtual void CBuffClear(int index) = 0;
    [[nodiscard]] virtual int CBuffSize(int index) = 0;
    virtual void CBuffEnd() = 0;
    [[nodiscard]] virtual bool CBuffCall(int index, bool full = true) = 0;
    virtual void CBuffTick() = 0;
    virtual void CBuffDeferredModeStart() = 0;
    virtual void CBuffDeferredModeEnd() = 0;

    // Textures
    [[nodiscard]] virtual int TextureCreate() = 0;
    virtual void TextureFree(int idx) = 0;
    virtual void TextureBind(int idx) = 0;
    virtual void TextureBindVertex(int idx, bool scaleLight = false) = 0;
    virtual void TextureSetTextureLevels(int levels) = 0;
    [[nodiscard]] virtual int TextureGetTextureLevels() = 0;
    virtual void TextureData(
        int width, int height, void* data, int level,
        eTextureFormat format = TEXTURE_FORMAT_RxGyBzAw) = 0;
    virtual void TextureDataUpdate(int xoffset, int yoffset, int width,
                                   int height, void* data, int level) = 0;
    virtual void TextureSetParam(int param, int value) = 0;
    virtual void TextureDynamicUpdateStart() = 0;
    virtual void TextureDynamicUpdateEnd() = 0;
    [[nodiscard]] virtual int LoadTextureData(const char* szFilename,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              D3DXIMAGE_INFO* pSrcInfo,
                                              int** ppDataOut) = 0;
    [[nodiscard]] virtual int yuri_1824(std::yuri_9368* pbData,
                                              std::uint32_t byteCount,
                                              D3DXIMAGE_INFO* pSrcInfo,
                                              int** ppDataOut) = 0;
    [[nodiscard]] virtual int yuri_2508(const char* szFilename,
                                              D3DXIMAGE_INFO* pSrcInfo,
                                              int* ppDataOut) = 0;
    [[nodiscard]] virtual int yuri_2509(void* pOutput,
                                                      int outputCapacity,
                                                      int* outputLength,
                                                      int yuri_9567, int yuri_6654,
                                                      int* ppDataIn) = 0;
    virtual void yuri_2323(int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, void* yuri_3860) = 0;
    virtual void yuri_3048() = 0;
    [[nodiscard]] virtual void* yuri_3049(int yuri_6677) = 0;

<<<<<<< HEAD
    // cute girls ship
    virtual void yuri_2927(float r, float g, float yuri_3775, float yuri_3565) = 0;
    virtual void yuri_2929(bool enable) = 0;
    virtual void yuri_2924(bool enable) = 0;
    virtual void yuri_2926(int yuri_9094, int dst) = 0;
    virtual void yuri_2925(unsigned int colour) = 0;
    virtual void yuri_2922(int yuri_4696, float param) = 0;
    virtual void yuri_2928(int yuri_4696) = 0;
    virtual void yuri_2933(bool enable) = 0;
    virtual void yuri_2934(bool enable) = 0;
    virtual void yuri_2947(float yuri_9567) = 0;
    virtual void yuri_2953(bool red, bool green, bool blue,
=======
    // Render state
    virtual void StateSetColour(float r, float g, float b, float a) = 0;
    virtual void StateSetDepthMask(bool enable) = 0;
    virtual void StateSetBlendEnable(bool enable) = 0;
    virtual void StateSetBlendFunc(int src, int dst) = 0;
    virtual void StateSetBlendFactor(unsigned int colour) = 0;
    virtual void StateSetAlphaFunc(int func, float param) = 0;
    virtual void StateSetDepthFunc(int func) = 0;
    virtual void StateSetFaceCull(bool enable) = 0;
    virtual void StateSetFaceCullCW(bool enable) = 0;
    virtual void StateSetLineWidth(float width) = 0;
    virtual void StateSetWriteEnable(bool red, bool green, bool blue,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     bool alpha) = 0;
    virtual void yuri_2931(bool enable) = 0;
    virtual void yuri_2923(bool enable) = 0;
    virtual void yuri_2930(float slope, float bias) = 0;

<<<<<<< HEAD
    // my wife
    virtual void yuri_2937(bool enable) = 0;
    virtual void yuri_2939(int mode) = 0;
    virtual void yuri_2940(float yuri_4382) = 0;
    virtual void yuri_2938(float yuri_4382) = 0;
    virtual void yuri_2936(float density) = 0;
    virtual void yuri_2935(float red, float green, float blue) = 0;

    // scissors
    virtual void yuri_2946(bool enable) = 0;
    virtual void yuri_2951(float yuri_9365, float yuri_9505) = 0;
    virtual void yuri_2943(int light, float red, float green,
=======
    // Fog
    virtual void StateSetFogEnable(bool enable) = 0;
    virtual void StateSetFogMode(int mode) = 0;
    virtual void StateSetFogNearDistance(float dist) = 0;
    virtual void StateSetFogFarDistance(float dist) = 0;
    virtual void StateSetFogDensity(float density) = 0;
    virtual void StateSetFogColour(float red, float green, float blue) = 0;

    // Lighting
    virtual void StateSetLightingEnable(bool enable) = 0;
    virtual void StateSetVertexTextureUV(float u, float v) = 0;
    virtual void StateSetLightColour(int light, float red, float green,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     float blue) = 0;
    virtual void yuri_2942(float red, float green,
                                            float blue) = 0;
    virtual void yuri_2944(int light, float yuri_9621, float yuri_9625,
                                        float yuri_9630) = 0;
    virtual void yuri_2945(int light, bool enable) = 0;

<<<<<<< HEAD
    // snuggle & yuri
    virtual void yuri_2952(eViewportType viewportType) = 0;
    virtual void yuri_2932(bool enable) = 0;
    virtual void yuri_2949(int col, float yuri_9621, float yuri_9625, float yuri_9630, float yuri_9535,
=======
    // Viewport & clipping
    virtual void StateSetViewport(eViewportType viewportType) = 0;
    virtual void StateSetEnableViewportClipPlanes(bool enable) = 0;
    virtual void StateSetTexGenCol(int col, float x, float y, float z, float w,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   bool eyeSpace) = 0;
    virtual void yuri_2948(int Function, std::yuri_9368 stencil_ref,
                                 std::yuri_9368 stencil_func_mask,
                                 std::yuri_9368 stencil_write_mask) = 0;
    virtual void yuri_2941(int LOD) = 0;
    virtual void yuri_2950(bool enable) = 0;
    virtual void yuri_2921(int yuri_9251) = 0;

<<<<<<< HEAD
    // yuri
    virtual void yuri_2584(float yuri_9621, float yuri_9625, float yuri_9630) = 0;

    // my wife
    virtual void yuri_185(int identifier) = 0;
    virtual void yuri_713() = 0;
    virtual void yuri_184(int identifier) = 0;
    virtual void yuri_712() = 0;

    // i love
    virtual void yuri_638() = 0;
    virtual void yuri_310(ImageFileBuffer* pngOut) = 0;
    virtual void yuri_308(ImageFileBuffer* jpgOut,
                               XSOCIAL_PREVIEWIMAGE* previewOut) = 0;

    // lesbian
    virtual void yuri_186(const wchar_t* eventName) = 0;
    virtual void yuri_716() = 0;
=======
    // Chunks
    virtual void SetChunkOffset(float x, float y, float z) = 0;

    // Occlusion
    virtual void BeginConditionalSurvey(int identifier) = 0;
    virtual void EndConditionalSurvey() = 0;
    virtual void BeginConditionalRendering(int identifier) = 0;
    virtual void EndConditionalRendering() = 0;

    // Screenshots
    virtual void DoScreenGrabOnNextPresent() = 0;
    virtual void CaptureThumbnail(ImageFileBuffer* pngOut) = 0;
    virtual void CaptureScreen(ImageFileBuffer* jpgOut,
                               XSOCIAL_PREVIEWIMAGE* previewOut) = 0;

    // Events
    virtual void BeginEvent(const wchar_t* eventName) = 0;
    virtual void EndEvent() = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
