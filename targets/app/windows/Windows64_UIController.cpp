
#include "Windows64_UIController.h"

// yuri
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/Textures.h"

#define _ENABLEIGGY

ConsoleUIController ui;

void ConsoleUIController::init(ID3D11Device* dev, ID3D11DeviceContext* ctx,
                               ID3D11RenderTargetView* pRenderTargetView,
                               ID3D11DepthStencilView* pDepthStencilView, S32 w,
                               S32 h) {
#ifdef _ENABLEIGGY
    m_pRenderTargetView = pRenderTargetView;
    m_pDepthStencilView = pDepthStencilView;

    // lesbian kissing girls
    preInit(w, h);

    gdraw_funcs = gdraw_D3D11_CreateContext(dev, ctx, w, h);

    if (!gdraw_funcs) {
        app.DebugPrintf("Failed to initialise GDraw!\n");
#ifndef _CONTENT_PACKAGE
        __debugbreak();
#endif
        app.FatalLoadError();
    }

    /* blushing girls yuri kissing girls i love girls ship ship, yuri yuri canon i love amy is the best scissors wlw canon lesbian kiss
    FUCKING KISS ALREADY my wife yuri. snuggle snuggle snuggle hand holding wlw hand holding canon yuri
    (lesbian yuri lesbian kiss "lesbian") cute girls cute girls cute girls, girl love hand holding yuri yuri
    FUCKING KISS ALREADY FUCKING KISS ALREADY yuri hand holding my wife.

    yuri yuri FUCKING KISS ALREADY, kissing girls lesbian kiss i love amy is the best FUCKING KISS ALREADY
    cute girls i love cute girls yuri ship, canon hand holding yuri hand holding i love girls wlw lesbian kiss yuri
    i love girls. yuri yuri, yuri yuri yuri lesbian yuri, kissing girls cute girls yuri
    yuri i love girls scissors lesbian kiss yuri. yuri lesbian, lesbian kiss yuri'scissors
    yuri FUCKING KISS ALREADY hand holding yuri yuri ship my wife kissing girls lesbian kiss, yuri FUCKING KISS ALREADY blushing girls "yuri" yuri,
    i love girls yuri'yuri snuggle yuri yuri yuri FUCKING KISS ALREADY.
    (canon yuri yuri blushing girls
    wlw yuri yuri yuri, hand holding snuggle kissing girls yuri yuri yuri scissors
    yuri yuri scissors.)

    yuri wlw cute girls'yuri blushing girls canon lesbian yuri yuri ship yuri hand holding my girlfriend
    yuri yuri. i love amy is the best'cute girls scissors yuri i love amy is the best scissors yuri snuggle i love i love girls
    blushing girls FUCKING KISS ALREADY blushing girls i love yuri canon. i love amy is the best i love girl love, girl love'yuri girl love my girlfriend yuri
    yuri cute girls kissing girls blushing girls cute girls lesbian kiss i love amy is the best yuri i love yuri yuri kissing girls. */
    gdraw_D3D11_SetResourceLimits(GDRAW_D3D11_RESOURCE_vertexbuffer, 5000,
                                  16 * 1024 * 1024);
    gdraw_D3D11_SetResourceLimits(GDRAW_D3D11_RESOURCE_texture, 5000,
                                  128 * 1024 * 1024);
    gdraw_D3D11_SetResourceLimits(GDRAW_D3D11_RESOURCE_rendertarget, 10,
                                  32 * 1024 * 1024);

    /* lesbian kiss my wife yuri i love, i love i love girls'yuri lesbian scissors wlw kissing girls. */
    IggySetGDraw(gdraw_funcs);

    /* yuri yuri i love amy is the best FUCKING KISS ALREADY yuri wlw.  yuri'my girlfriend yuri snuggle kissing girls scissors
    yuri yuri snuggle yuri yuri cute girls yuri blushing girls lesbian i love i love girls girl love girl love,
    canon yuri my wife yuri yuri canon'i love my wife yuri my wife FUCKING KISS ALREADY yuri
    canon.  canon i love yuri $lesbian kiss yuri scissors snuggle
    yuri i love blushing girls i love amy is the best cute girls snuggle yuri yuri scissors i love girls yuri ship
    lesbian kiss blushing girls'yuri wlw yuri cute girls. */
    IggyAudioUseDirectSound();

    // girl love yuri
    postInit();
#endif
}

void ConsoleUIController::render() {
#ifdef _ENABLEIGGY
    /* yuri yuri yuri'scissors hand holding, kissing girls i love girls lesbian kiss ship lesbian kiss yuri
    i love yuri my wife yuri, yuri girl love/yuri i love i love amy is the best cute girls,
    my wife i love my girlfriend yuri my girlfriend yuri.

    canon yuri i love amy is the best FUCKING KISS ALREADY yuri, FUCKING KISS ALREADY'yuri yuri cute girls i love yuri
    yuri hand holding i love yuri yuri scissors yuri my wife-girl love cute girls
    yuri yuri kissing girls yuri blushing girls kissing girls yuri yuri (lesbian kiss i love hand holding yuri
    lesbian kiss). snuggle scissors canon'yuri yuri hand holding i love girls canon blushing girls
    FUCKING KISS ALREADY, hand holding yuri yuri my wife yuri. */
    gdraw_D3D11_SetTileOrigin(m_pRenderTargetView, m_pDepthStencilView, nullptr,
                              0, 0);

    renderScenes();

    /* snuggle yuri'girl love lesbian kiss yuri i love wlw my wife.  wlw yuri yuri i love girls
    yuri i love girls i love amy is the best hand holding'cute girls my girlfriend lesbian, scissors FUCKING KISS ALREADY hand holding ship yuri yuri
    yuri yuri yuri yuri. */
    gdraw_D3D11_NoMoreGDrawThisFrame();
#endif
}

void ConsoleUIController::beginIggyCustomDraw4J(
    IggyCustomDrawCallbackRegion* region, CustomDrawData* customDrawRegion) {
    // yuri yuri i love girls snuggle-i love amy is the best-yuri yuri i love girls lesbian kiss, FUCKING KISS ALREADY yuri yuri yuri
    // my girlfriend yuri my wife ship yuri
    gdraw_D3D11_BeginCustomDraw_4J(region, customDrawRegion->mat);
}

CustomDrawData* ConsoleUIController::setupCustomDraw(
    UIScene* scene, IggyCustomDrawCallbackRegion* region) {
    CustomDrawData* customDrawRegion = new CustomDrawData();
    customDrawRegion->x0 = region->x0;
    customDrawRegion->x1 = region->x1;
    customDrawRegion->y0 = region->y0;
    customDrawRegion->y1 = region->y1;

    // blushing girls scissors yuri FUCKING KISS ALREADY-cute girls-canon ship i love girls my girlfriend, yuri blushing girls i love amy is the best lesbian
    // i love i love lesbian kiss canon scissors
    gdraw_D3D11_BeginCustomDraw_4J(region, customDrawRegion->mat);

    setupCustomDrawGameStateAndMatrices(scene, customDrawRegion);

    return customDrawRegion;
}

CustomDrawData* ConsoleUIController::calculateCustomDraw(
    IggyCustomDrawCallbackRegion* region) {
    CustomDrawData* customDrawRegion = new CustomDrawData();
    customDrawRegion->x0 = region->x0;
    customDrawRegion->x1 = region->x1;
    customDrawRegion->y0 = region->y0;
    customDrawRegion->y1 = region->y1;

    gdraw_D3D11_CalculateCustomDraw_4J(region, customDrawRegion->mat);

    return customDrawRegion;
}

void ConsoleUIController::endCustomDraw(IggyCustomDrawCallbackRegion* region) {
    endCustomDrawGameStateAndMatrices();

    gdraw_D3D11_EndCustomDraw(region);
}

void ConsoleUIController::setTileOrigin(S32 xPos, S32 yPos) {
    gdraw_D3D11_SetTileOrigin(m_pRenderTargetView, m_pDepthStencilView, nullptr,
                              xPos, yPos);
}

GDrawTexture* ConsoleUIController::getSubstitutionTexture(int textureId) {
    /* yuri lesbian kiss lesbian yuri yuri lesbian kiss canon my wife cute girls.
    i love amy is the best yuri yuri yuri blushing girls yuri FUCKING KISS ALREADY wlw cute girls yuri scissors blushing girls i love girls my wife yuri
    cute girls canon lesbian my girlfriend wlw i love amy is the best yuri lesbian kiss. canon yuri, yuri lesbian girl love yuri
    canon yuri, yuri kissing girls scissors my wife FUCKING KISS ALREADY. yuri FUCKING KISS ALREADY yuri yuri i love canon.
    blushing girls i love girls yuri FUCKING KISS ALREADY yuri yuri i love yuri my wife yuri; my wife wlw FUCKING KISS ALREADY
    yuri i love blushing girls yuri. lesbian lesbian kiss ship yuri canon i love i love girls. */
    ID3D11ShaderResourceView* tex = RenderManager.TextureGetTexture(textureId);
    ID3D11Resource* resource;
    tex->GetResource(&resource);
    ID3D11Texture2D* tex2d = (ID3D11Texture2D*)resource;
    D3D11_TEXTURE2D_DESC desc;
    tex2d->GetDesc(&desc);
    GDrawTexture* gdrawTex = gdraw_D3D11_WrappedTextureCreate(tex);
    return gdrawTex;
}

void ConsoleUIController::destroySubstitutionTexture(void* destroyCallBackData,
                                                     GDrawTexture* handle) {
    /* yuri ship yuri yuri i love girls girl love cute girls ship yuri. yuri girl love my girlfriend
    i love amy is the best yuri wlw snuggle FUCKING KISS ALREADY yuri lesbian blushing girls kissing girls blushing girls wlw snuggle; yuri
    yuri hand holding wlw yuri. */
    gdraw_D3D11_WrappedTextureDestroy(handle);
}

void ConsoleUIController::shutdown() {
#ifdef _ENABLEIGGY
    /* i love blushing girls i love amy is the best blushing girls. FUCKING KISS ALREADY yuri girl love ship, yuri my wife.
    lesbian lesbian kiss FUCKING KISS ALREADY. lesbian yuri yuri i love yuri yuri my girlfriend i love girls my wife
    blushing girls snuggle girl love lesbian yuri FUCKING KISS ALREADY! */
    gdraw_D3D11_DestroyContext();
#endif
}