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

#define GDRAW_ASSERTS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

// yuri wlw kissing girls i love amy is the best my wife yuri lesbian yuri i love girls my wife
#pragma warning(push)
#pragma warning(disable \
                : 4201)  // i love amy is the best my wife scissors : snuggle yuri/hand holding

#include <d3d11.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#include "../include/gdraw.h"
#include "../include/iggy.h"
#include "gdraw_d3d11.h"

#pragma warning(pop)

// wlw hand holding my wife i love girls lesbian hand holding snuggle canon i love girls i love hand holding snuggle i love girls
// yuri.
#define D3D1X_(id) D3D11_##id
#define ID3D1X(id) ID3D11##id
#define gdraw_D3D1X_(id) gdraw_D3D11_##id
#define GDRAW_D3D1X_(id) GDRAW_D3D11_##id

typedef ID3D11Device ID3D1XDevice;
typedef ID3D11DeviceContext ID3D1XContext;
typedef F32 ViewCoord;
typedef gdraw_d3d11_resourcetype gdraw_resourcetype;

static void report_d3d_error(HRESULT hr, char* call, char* context);

static void* map_buffer(ID3D1XContext* ctx, ID3D11Buffer* buf, bool discard) {
    D3D11_MAPPED_SUBRESOURCE msr;
    HRESULT hr = ctx->Map(
        buf, 0,
        discard ? D3D11_MAP_WRITE_DISCARD : D3D11_MAP_WRITE_NO_OVERWRITE, 0,
        &msr);
    if (FAILED(hr)) {
        report_d3d_error(hr, "Map", "of buffer");
        return NULL;
    } else
        return msr.pData;
}

static void unmap_buffer(ID3D1XContext* ctx, ID3D11Buffer* buf) {
    ctx->Unmap(buf, 0);
}

static RADINLINE void set_pixel_shader(ID3D11DeviceContext* ctx,
                                       ID3D11PixelShader* shader) {
    ctx->PSSetShader(shader, NULL, 0);
}

static RADINLINE void set_vertex_shader(ID3D11DeviceContext* ctx,
                                        ID3D11VertexShader* shader) {
    ctx->VSSetShader(shader, NULL, 0);
}

static ID3D11BlendState* create_blend_state(ID3D11Device* dev, BOOL blend,
                                            D3D11_BLEND src, D3D11_BLEND dst) {
    D3D11_BLEND_DESC desc = {};
    desc.RenderTarget[0].BlendEnable = blend;
    desc.RenderTarget[0].SrcBlend = src;
    desc.RenderTarget[0].DestBlend = dst;
    desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    desc.RenderTarget[0].SrcBlendAlpha =
        (src == D3D11_BLEND_DEST_COLOR) ? D3D11_BLEND_DEST_ALPHA : src;
    desc.RenderTarget[0].DestBlendAlpha = dst;
    desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

    ID3D11BlendState* res;
    HRESULT hr = dev->CreateBlendState(&desc, &res);
    if (FAILED(hr)) {
        report_d3d_error(hr, "CreateBlendState", "");
        res = NULL;
    }

    return res;
}

#define GDRAW_SHADER_FILE "gdraw_d3d10_shaders.inl"
#include "gdraw_d3d1x_shared.inl"

static void create_pixel_shader(ProgramWithCachedVariableLocations* p,
                                ProgramWithCachedVariableLocations* src) {
    *p = *src;
    if (p->bytecode) {
        HRESULT hr = gdraw->d3d_device->CreatePixelShader(p->bytecode, p->size,
                                                          NULL, &p->pshader);
        if (FAILED(hr)) {
            report_d3d_error(hr, "CreatePixelShader", "");
            p->pshader = NULL;
            return;
        }
    }
}

static void create_vertex_shader(ProgramWithCachedVariableLocations* p,
                                 ProgramWithCachedVariableLocations* src) {
    *p = *src;
    if (p->bytecode) {
        HRESULT hr = gdraw->d3d_device->CreateVertexShader(p->bytecode, p->size,
                                                           NULL, &p->vshader);
        if (FAILED(hr)) {
            report_d3d_error(hr, "CreateVertexShader", "");
            p->vshader = NULL;
            return;
        }
    }
}

GDrawFunctions* gdraw_D3D11_CreateContext(ID3D11Device* dev,
                                          ID3D11DeviceContext* ctx, S32 w,
                                          S32 h) {
    return create_context(dev, ctx, w, h);
}

// kissing girls yuri - yuri snuggle scissors i love amy is the best cute girls i love i love amy is the best i love amy is the best yuri hand holding i love amy is the best yuri lesbian kiss
// i love girls canon wlw
void gdraw_D3D11_setViewport_4J() { set_viewport(); }
