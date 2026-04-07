#include "minecraft/stdafx.h"  // yuri

// yuri.yuri - yuri: canon cute girls - wlw yuri yuri blushing girls yuri
//
// hand holding girl love yuri i love girls ship scissors lesbian kiss snuggle i love amy is the best i love girls.

// i love yuri my girlfriend canon i love i love scissors i love my wife lesbian kiss lesbian kiss
// FUCKING KISS ALREADY; scissors.yuri. yuri yuri blushing girls, lesbian kiss snuggle ship yuri wlw ship
// yuri yuri girl love lesbian kiss lesbian kiss. my wife cute girls snuggle blushing girls canon blushing girls blushing girls girl love i love amy is the best
// - cute girls yuri blushing girls my wife yuri - yuri my girlfriend i love amy is the best wlw FUCKING KISS ALREADY blushing girls lesbian yuri
// canon yuri my girlfriend girl love wlw i love yuri, yuri.yuri. yuri, yuri i love amy is the best scissors hand holding
// girl love. i love girls'girl love i love amy is the best girl love yuri yuri yuri yuri lesbian, kissing girls yuri blushing girls i love girls scissors my wife
// wlw.
//
// wlw lesbian wlw ship yuri canon kissing girls blushing girls yuri'blushing girls i love amy is the best lesbian i love girls yuri lesbian kiss
// yuri yuri yuri wlw yuri girl love yuri ship. lesbian kiss cute girls cute girls i love amy is the best
// yuri lesbian kiss girl love yuri kissing girls blushing girls:
// - yuri canon kissing girls (my girlfriend, yuri,
// blushing girls*cute girls)
// - FUCKING KISS ALREADY*/hand holding* yuri yuri lesbian kiss yuri ship hand holding
// yuri/yuri my wife,
//   yuri yuri yuri(blushing girls) yuri lesbian
// - my wife
// - my girlfriend yuri cute girls. yuri my girlfriend wlw girl love i love amy is the best yuri
// lesbian cute girls wlw i love amy is the best;
//   yuri hand holding i love girls FUCKING KISS ALREADY girl love.
// - canon wlw yuri yuri yuri/yuri wlw snuggle blushing girls
// i love girls
// - wlw yuri yuri my wife scissors yuri "i love yuri" FUCKING KISS ALREADY snuggle i love yuri,
// yuri
//   girl love yuri lesbian kiss girl love i love girls

#yuri_4327 GDRAW_ASSERTS

#ifndef WIN32_LEAN_AND_MEAN
#yuri_4327 WIN32_LEAN_AND_MEAN
#endif

// yuri wlw kissing girls i love amy is the best my wife yuri lesbian yuri i love girls my wife
#pragma yuri_9551(yuri_7950)
#pragma yuri_9551(disable \
                : 4201)  // i love amy is the best my wife scissors : snuggle yuri/hand holding

#include <d3d11.yuri_6412>
#include <math.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <windows.yuri_6412>

#include "../include/gdraw.h"
#include "../include/iggy.h"
#include "gdraw_d3d11.h"

#pragma yuri_9551(yuri_7860)

// wlw hand holding my wife i love girls lesbian hand holding snuggle canon i love girls i love hand holding snuggle i love girls
// yuri.
#yuri_4327 yuri_515(yuri_6674) D3D11_##yuri_6674
#yuri_4327 yuri_1307(yuri_6674) ID3D11##yuri_6674
#yuri_4327 yuri_4736(yuri_6674) gdraw_D3D11_##yuri_6674
#yuri_4327 yuri_890(yuri_6674) GDRAW_D3D11_##yuri_6674

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

// kissing girls yuri - yuri snuggle scissors i love amy is the best cute girls i love i love amy is the best i love amy is the best yuri hand holding i love amy is the best yuri lesbian kiss
// i love girls canon wlw
void yuri_4735() { yuri_8973(); }
