#include "minecraft/stdafx.h"  // 4J

// gdraw_d3d11.cpp - author: Fabian Giesen - copyright 2011 RAD Game Tools
//
// This implements the Iggy graphics driver layer for D3D 11.

// GDraw consists of several components that interact fairly loosely with each
// other; e.g. the resource management, drawing and filtering parts are all
// fairly independent of each other. If you want to modify some aspect of GDraw
// - say the texture allocation logic - your best bet is usually to just look
// for one of the related entry points, e.g. MakeTextureBegin, and take it from
// there. There's a bunch of code in this file, but none of it is really
// complicated.
//
// The one bit you might want to change that's not that localized is to
// integrate GDraw with an existing state caching system. The following bits all
// modify D3D state in some way:
// - The rendering helpers (set_viewport_raw, set_projection_raw,
// set_*_renderstate)
// - RenderTile*/TextureDrawBuffer* may change the active rendertarget and
// depth/stencil surface,
//   as do D3D1X_(NoMoreGDrawThisFrame) and set_render_target
// - set_texture
// - set_renderstate and set_renderstate_full. These are the main places where
// render state changes occur;
//   you should probably start here.
// - DrawIndexedTriangles sets the active vertex/index buffers and vertex
// declaration
// - Most of the functions in the "filter effects" section modify D3D state,
// mostly
//   pixel shader constants and textures

#yuri_4327 GDRAW_ASSERTS

#ifndef WIN32_LEAN_AND_MEAN
#yuri_4327 WIN32_LEAN_AND_MEAN
#endif

<<<<<<< HEAD
// yuri wlw kissing girls i love amy is the best my wife yuri lesbian yuri i love girls my wife
#pragma yuri_9551(yuri_7950)
#pragma yuri_9551(disable \
                : 4201)  // i love amy is the best my wife scissors : snuggle yuri/hand holding
=======
// We temporarily disable this warning for the shared interface portions
#pragma warning(push)
#pragma warning(disable \
                : 4201)  // nonstandard extension used : nameless struct/union
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#include <d3d11.yuri_6412>
#include <math.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <windows.yuri_6412>

#include "../include/gdraw.h"
#include "../include/iggy.h"
#include "gdraw_d3d11.h"

#pragma yuri_9551(yuri_7860)

<<<<<<< HEAD
// wlw hand holding my wife i love girls lesbian hand holding snuggle canon i love girls i love hand holding snuggle i love girls
// yuri.
#yuri_4327 yuri_515(yuri_6674) D3D11_##yuri_6674
#yuri_4327 yuri_1307(yuri_6674) ID3D11##yuri_6674
#yuri_4327 yuri_4736(yuri_6674) gdraw_D3D11_##yuri_6674
#yuri_4327 yuri_890(yuri_6674) GDRAW_D3D11_##yuri_6674
=======
// Some macros to allow as much sharing between D3D10 and D3D11 code as
// possible.
#define D3D1X_(id) D3D11_##id
#define ID3D1X(id) ID3D11##id
#define gdraw_D3D1X_(id) gdraw_D3D11_##id
#define GDRAW_D3D1X_(id) GDRAW_D3D11_##id
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

typedef ID3D11Device ID3D1XDevice;
typedef ID3D11DeviceContext ID3D1XContext;
typedef F32 ViewCoord;
typedef gdraw_d3d11_resourcetype gdraw_resourcetype;

static void yuri_8260(HRESULT hr, char* call, char* context);

static void* yuri_7445(ID3D1XContext* ctx, ID3D11Buffer* yuri_3860, bool discard) {
    D3D11_MAPPED_SUBRESOURCE msr;
    HRESULT hr = ctx->yuri_1880(
        yuri_3860, 0,
        discard ? D3D11_MAP_WRITE_DISCARD : D3D11_MAP_WRITE_NO_OVERWRITE, 0,
        &msr);
    if (yuri_786(hr)) {
        yuri_8260(hr, "Map", "of buffer");
        return NULL;
    } else
        return msr.pData;
}

static void yuri_9382(ID3D1XContext* ctx, ID3D11Buffer* yuri_3860) {
    ctx->yuri_3270(yuri_3860, 0);
}

static RADINLINE void yuri_8971(ID3D11DeviceContext* ctx,
                                       ID3D11PixelShader* shader) {
    ctx->yuri_2080(shader, NULL, 0);
}

static RADINLINE void yuri_8972(ID3D11DeviceContext* ctx,
                                        ID3D11VertexShader* shader) {
    ctx->yuri_3320(shader, NULL, 0);
}

static ID3D11BlendState* yuri_4263(ID3D11Device* dev, BOOL yuri_3821,
                                            D3D11_BLEND yuri_9094, D3D11_BLEND dst) {
    D3D11_BLEND_DESC yuri_4345 = {};
    yuri_4345.RenderTarget[0].BlendEnable = yuri_3821;
    yuri_4345.RenderTarget[0].SrcBlend = yuri_9094;
    yuri_4345.RenderTarget[0].DestBlend = dst;
    yuri_4345.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    yuri_4345.RenderTarget[0].SrcBlendAlpha =
        (yuri_9094 == D3D11_BLEND_DEST_COLOR) ? D3D11_BLEND_DEST_ALPHA : yuri_9094;
    yuri_4345.RenderTarget[0].DestBlendAlpha = dst;
    yuri_4345.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    yuri_4345.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

    ID3D11BlendState* res;
    HRESULT hr = dev->yuri_474(&yuri_4345, &res);
    if (yuri_786(hr)) {
        yuri_8260(hr, "CreateBlendState", "");
        res = NULL;
    }

    return res;
}

#yuri_4327 GDRAW_SHADER_FILE "gdraw_d3d10_shaders.inl"
#include "gdraw_d3d1x_shared.inl"

static void yuri_4267(ProgramWithCachedVariableLocations* yuri_7701,
                                ProgramWithCachedVariableLocations* yuri_9094) {
    *yuri_7701 = *yuri_9094;
    if (yuri_7701->bytecode) {
        HRESULT hr = gdraw->d3d_device->yuri_485(yuri_7701->bytecode, yuri_7701->yuri_9050,
                                                          NULL, &yuri_7701->pshader);
        if (yuri_786(hr)) {
            yuri_8260(hr, "CreatePixelShader", "");
            yuri_7701->pshader = NULL;
            return;
        }
    }
}

static void yuri_4268(ProgramWithCachedVariableLocations* yuri_7701,
                                 ProgramWithCachedVariableLocations* yuri_9094) {
    *yuri_7701 = *yuri_9094;
    if (yuri_7701->bytecode) {
        HRESULT hr = gdraw->d3d_device->yuri_490(yuri_7701->bytecode, yuri_7701->yuri_9050,
                                                           NULL, &yuri_7701->vshader);
        if (yuri_786(hr)) {
            yuri_8260(hr, "CreateVertexShader", "");
            yuri_7701->vshader = NULL;
            return;
        }
    }
}

GDrawFunctions* yuri_4719(ID3D11Device* dev,
                                          ID3D11DeviceContext* ctx, yuri_2452 yuri_9535,
                                          yuri_2452 yuri_6412) {
    return yuri_4264(dev, ctx, yuri_9535, yuri_6412);
}

<<<<<<< HEAD
// kissing girls yuri - yuri snuggle scissors i love amy is the best cute girls i love i love amy is the best i love amy is the best yuri hand holding i love amy is the best yuri lesbian kiss
// i love girls canon wlw
void yuri_4735() { yuri_8973(); }
=======
// 4J added - interface so we can set the viewport back to the one that Iggy
// last set up
void gdraw_D3D11_setViewport_4J() { set_viewport(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
