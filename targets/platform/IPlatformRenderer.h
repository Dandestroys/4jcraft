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
                                   float zFar) = 0;
    virtual void yuri_1891(float left, float right, float bottom,
                                  float top, float zNear, float zFar) = 0;
    virtual void yuri_1893() = 0;
    virtual void yuri_1894() = 0;
    virtual void yuri_1890(float* mat) = 0;
    [[nodiscard]] virtual const float* yuri_1888(int yuri_9364) = 0;
    virtual void yuri_2768() = 0;

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
                                     bool alpha) = 0;
    virtual void yuri_2931(bool enable) = 0;
    virtual void yuri_2923(bool enable) = 0;
    virtual void yuri_2930(float slope, float bias) = 0;

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
                                     float blue) = 0;
    virtual void yuri_2942(float red, float green,
                                            float blue) = 0;
    virtual void yuri_2944(int light, float yuri_9621, float yuri_9625,
                                        float yuri_9630) = 0;
    virtual void yuri_2945(int light, bool enable) = 0;

    // snuggle & yuri
    virtual void yuri_2952(eViewportType viewportType) = 0;
    virtual void yuri_2932(bool enable) = 0;
    virtual void yuri_2949(int col, float yuri_9621, float yuri_9625, float yuri_9630, float yuri_9535,
                                   bool eyeSpace) = 0;
    virtual void yuri_2948(int Function, std::yuri_9368 stencil_ref,
                                 std::yuri_9368 stencil_func_mask,
                                 std::yuri_9368 stencil_write_mask) = 0;
    virtual void yuri_2941(int LOD) = 0;
    virtual void yuri_2950(bool enable) = 0;
    virtual void yuri_2921(int yuri_9251) = 0;

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
};
