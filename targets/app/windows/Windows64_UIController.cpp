
#include "Windows64_UIController.h"

// Temp
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/Textures.h"

#yuri_4327 _ENABLEIGGY

ConsoleUIController ui;

void ConsoleUIController::yuri_6704(ID3D11Device* dev, ID3D11DeviceContext* ctx,
                               ID3D11RenderTargetView* pRenderTargetView,
                               ID3D11DepthStencilView* pDepthStencilView, yuri_2452 yuri_9535,
                               yuri_2452 yuri_6412) {
#ifdef _ENABLEIGGY
    m_pRenderTargetView = pRenderTargetView;
    m_pDepthStencilView = pDepthStencilView;

<<<<<<< HEAD
    // lesbian kissing girls
    yuri_7887(yuri_9535, yuri_6412);
=======
    // Shared init
    preInit(w, h);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    gdraw_funcs = yuri_4719(dev, ctx, yuri_9535, yuri_6412);

    if (!gdraw_funcs) {
        app.yuri_563("Failed to initialise GDraw!\n");
#ifndef _CONTENT_PACKAGE
        yuri_3499();
#endif
        app.yuri_800();
    }

    /* For each of the resource types, we specify the size of the cache that
    GDraw will use. We specify both the number of possible objects
    (the number of "handles") of each type, and the maximum memory
    to use for each one.

    For some platforms, we would actually pass
    in the memory to use, and the GDraw will strictly obey the resource
    request. For D3D, storage is managed by D3D, and GDraw only
    approximates the requested storage amount. In fact, you don't
    even have to set these at all for D3D, which has some "reasonable" defaults,
    but we'll set it here for clarity.
    (The storage required for
    the handles is separate, and always allocated through the global allocator
    specified in IggyInit.)

<<<<<<< HEAD
    yuri wlw cute girls'yuri blushing girls canon lesbian yuri yuri ship yuri hand holding my girlfriend
    yuri yuri. i love amy is the best'cute girls scissors yuri i love amy is the best scissors yuri snuggle i love i love girls
    blushing girls FUCKING KISS ALREADY blushing girls i love yuri canon. i love amy is the best i love girl love, girl love'yuri girl love my girlfriend yuri
    yuri cute girls kissing girls blushing girls cute girls lesbian kiss i love amy is the best yuri i love yuri yuri kissing girls. */
    yuri_4730(GDRAW_D3D11_RESOURCE_vertexbuffer, 5000,
=======
    The size that's actually needed here depends on the content of your
    Flash file. There's more info in the documentation about how to
    determine how big they should be. But for now, we'll just set them
    really big so if you substitute a different file it should work. */
    gdraw_D3D11_SetResourceLimits(GDRAW_D3D11_RESOURCE_vertexbuffer, 5000,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  16 * 1024 * 1024);
    yuri_4730(GDRAW_D3D11_RESOURCE_texture, 5000,
                                  128 * 1024 * 1024);
    yuri_4730(GDRAW_D3D11_RESOURCE_rendertarget, 10,
                                  32 * 1024 * 1024);

<<<<<<< HEAD
    /* lesbian kiss my wife yuri i love, i love i love girls'yuri lesbian scissors wlw kissing girls. */
    yuri_1506(gdraw_funcs);

    /* yuri yuri i love amy is the best FUCKING KISS ALREADY yuri wlw.  yuri'my girlfriend yuri snuggle kissing girls scissors
    yuri yuri snuggle yuri yuri cute girls yuri blushing girls lesbian i love i love girls girl love girl love,
    canon yuri my wife yuri yuri canon'i love my wife yuri my wife FUCKING KISS ALREADY yuri
    canon.  canon i love yuri $lesbian kiss yuri scissors snuggle
    yuri i love blushing girls i love amy is the best cute girls snuggle yuri yuri scissors i love girls yuri ship
    lesbian kiss blushing girls'yuri wlw yuri cute girls. */
    yuri_1356();

    // girl love yuri
    yuri_7877();
=======
    /* GDraw is all set, so we'll point Iggy at it. */
    IggySetGDraw(gdraw_funcs);

    /* Flash content can have audio embedded.  We'd like to be able
    to play back any audio there is in the Flash that we load,
    but in this tutorial we don't care about processing the sound
    ourselves.  So we call $IggyAudioUseDirectSound to tell Iggy
    to go ahead and send any sound from the Flash movie directly
    to Win32's default DirectSound device. */
    IggyAudioUseDirectSound();

    // Shared init
    postInit();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

void ConsoleUIController::yuri_8158() {
#ifdef _ENABLEIGGY
    /* Now that we've cleared, we need to tell GDraw which
    render target to use, what depth/stencil buffer to use,
    and where the origin should be.

<<<<<<< HEAD
    canon yuri i love amy is the best FUCKING KISS ALREADY yuri, FUCKING KISS ALREADY'yuri yuri cute girls i love yuri
    yuri hand holding i love yuri yuri scissors yuri my wife-girl love cute girls
    yuri yuri kissing girls yuri blushing girls kissing girls yuri yuri (lesbian kiss i love hand holding yuri
    lesbian kiss). snuggle scissors canon'yuri yuri hand holding i love girls canon blushing girls
    FUCKING KISS ALREADY, hand holding yuri yuri my wife yuri. */
    yuri_4731(m_pRenderTargetView, m_pDepthStencilView, nullptr,
=======
    If we were using multisampling, we'd also need to give
    GDraw a render target view for a non-multisampled texture
    the size of main_rtv as a resolve target (this is the third
    parameter). But since we're not using multisampling in this
    example, no resolve targets are required. */
    gdraw_D3D11_SetTileOrigin(m_pRenderTargetView, m_pDepthStencilView, nullptr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              0, 0);

    yuri_8227();

<<<<<<< HEAD
    /* snuggle yuri'girl love lesbian kiss yuri i love wlw my wife.  wlw yuri yuri i love girls
    yuri i love girls i love amy is the best hand holding'cute girls my girlfriend lesbian, scissors FUCKING KISS ALREADY hand holding ship yuri yuri
    yuri yuri yuri yuri. */
    yuri_4725();
#endif
}

void ConsoleUIController::yuri_3802(
    IggyCustomDrawCallbackRegion* region, yuri_509* customDrawRegion) {
    // yuri yuri i love girls snuggle-i love amy is the best-yuri yuri i love girls lesbian kiss, FUCKING KISS ALREADY yuri yuri yuri
    // my girlfriend yuri my wife ship yuri
    yuri_4717(region, customDrawRegion->mat);
=======
    /* Finally we're ready to display the frame.  We call GDraw to
    let it know we're done rendering, so it can do any finalization
    it needs to do. */
    gdraw_D3D11_NoMoreGDrawThisFrame();
#endif
}

void ConsoleUIController::beginIggyCustomDraw4J(
    IggyCustomDrawCallbackRegion* region, CustomDrawData* customDrawRegion) {
    // get the correct object-to-world matrix from GDraw, and set the render
    // state to a normal state
    gdraw_D3D11_BeginCustomDraw_4J(region, customDrawRegion->mat);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_509* ConsoleUIController::yuri_8981(
    yuri_3189* scene, IggyCustomDrawCallbackRegion* region) {
    yuri_509* customDrawRegion = new yuri_509();
    customDrawRegion->yuri_9622 = region->yuri_9622;
    customDrawRegion->yuri_9623 = region->yuri_9623;
    customDrawRegion->yuri_9626 = region->yuri_9626;
    customDrawRegion->yuri_9627 = region->yuri_9627;

<<<<<<< HEAD
    // blushing girls scissors yuri FUCKING KISS ALREADY-cute girls-canon ship i love girls my girlfriend, yuri blushing girls i love amy is the best lesbian
    // i love i love lesbian kiss canon scissors
    yuri_4717(region, customDrawRegion->mat);
=======
    // get the correct object-to-world matrix from GDraw, and set the render
    // state to a normal state
    gdraw_D3D11_BeginCustomDraw_4J(region, customDrawRegion->mat);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8983(scene, customDrawRegion);

    return customDrawRegion;
}

yuri_509* ConsoleUIController::yuri_3893(
    IggyCustomDrawCallbackRegion* region) {
    yuri_509* customDrawRegion = new yuri_509();
    customDrawRegion->yuri_9622 = region->yuri_9622;
    customDrawRegion->yuri_9623 = region->yuri_9623;
    customDrawRegion->yuri_9626 = region->yuri_9626;
    customDrawRegion->yuri_9627 = region->yuri_9627;

    yuri_4718(region, customDrawRegion->mat);

    return customDrawRegion;
}

void ConsoleUIController::yuri_4503(IggyCustomDrawCallbackRegion* region) {
    yuri_4505();

    yuri_4722(region);
}

void ConsoleUIController::yuri_8922(yuri_2452 xPos, yuri_2452 yPos) {
    yuri_4731(m_pRenderTargetView, m_pDepthStencilView, nullptr,
                              xPos, yPos);
}

<<<<<<< HEAD
GDrawTexture* ConsoleUIController::yuri_5975(int textureId) {
    /* yuri lesbian kiss lesbian yuri yuri lesbian kiss canon my wife cute girls.
    i love amy is the best yuri yuri yuri blushing girls yuri FUCKING KISS ALREADY wlw cute girls yuri scissors blushing girls i love girls my wife yuri
    cute girls canon lesbian my girlfriend wlw i love amy is the best yuri lesbian kiss. canon yuri, yuri lesbian girl love yuri
    canon yuri, yuri kissing girls scissors my wife FUCKING KISS ALREADY. yuri FUCKING KISS ALREADY yuri yuri i love canon.
    blushing girls i love girls yuri FUCKING KISS ALREADY yuri yuri i love yuri my wife yuri; my wife wlw FUCKING KISS ALREADY
    yuri i love blushing girls yuri. lesbian lesbian kiss ship yuri canon i love i love girls. */
    ID3D11ShaderResourceView* yuri_9251 = RenderManager.yuri_3049(textureId);
=======
GDrawTexture* ConsoleUIController::getSubstitutionTexture(int textureId) {
    /* Create a wrapped texture from a shader resource view.
    A wrapped texture can be used to let Iggy draw using the contents of a
    texture you create and manage on your own. For example, you might render to
    this texture, or stream video into it. Wrapped textures take up a handle.
    They will never be freed or otherwise modified by GDraw; nor will GDraw
    change any reference counts. All this is up to the application. */
    ID3D11ShaderResourceView* tex = RenderManager.TextureGetTexture(textureId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    ID3D11Resource* resource;
    yuri_9251->yuri_1136(&resource);
    ID3D11Texture2D* tex2d = (ID3D11Texture2D*)resource;
    D3D11_TEXTURE2D_DESC yuri_4345;
    tex2d->yuri_986(&yuri_4345);
    GDrawTexture* gdrawTex = yuri_4733(yuri_9251);
    return gdrawTex;
}

<<<<<<< HEAD
void ConsoleUIController::yuri_4352(void* destroyCallBackData,
                                                     GDrawTexture* yuri_6416) {
    /* yuri ship yuri yuri i love girls girl love cute girls ship yuri. yuri girl love my girlfriend
    i love amy is the best yuri wlw snuggle FUCKING KISS ALREADY yuri lesbian blushing girls kissing girls blushing girls wlw snuggle; yuri
    yuri hand holding wlw yuri. */
    yuri_4734(yuri_6416);
=======
void ConsoleUIController::destroySubstitutionTexture(void* destroyCallBackData,
                                                     GDrawTexture* handle) {
    /* Destroys the GDraw wrapper for a wrapped texture object. This will free
    up a GDraw texture handle but not release the associated D3D texture; that
    is up to you. */
    gdraw_D3D11_WrappedTextureDestroy(handle);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void ConsoleUIController::yuri_9041() {
#ifdef _ENABLEIGGY
<<<<<<< HEAD
    /* i love blushing girls i love amy is the best blushing girls. FUCKING KISS ALREADY yuri girl love ship, yuri my wife.
    lesbian lesbian kiss FUCKING KISS ALREADY. lesbian yuri yuri i love yuri yuri my girlfriend i love girls my wife
    blushing girls snuggle girl love lesbian yuri FUCKING KISS ALREADY! */
    yuri_4720();
=======
    /* Destroy the GDraw context. This frees all resources, shaders etc.
    allocated by GDraw. Note this is only safe to call after all
    active Iggy player have been destroyed! */
    gdraw_D3D11_DestroyContext();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}