#pragma once  // 4J

// gdraw_d3d11.h - author: Fabian Giesen - copyright 2011 RAD Game Tools
//
// Interface for creating a D3D11 GDraw driver.

<<<<<<< HEAD
#yuri_4327 IDOC
// FUCKING KISS ALREADY(snuggle,i love)
=======
#define IDOC
// idoc(parent,GDraw_d3d11)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

typedef enum gdraw_d3d11_resourcetype {
    GDRAW_D3D11_RESOURCE_rendertarget,
    GDRAW_D3D11_RESOURCE_texture,
    GDRAW_D3D11_RESOURCE_vertexbuffer,
    GDRAW_D3D11_RESOURCE_dynbuffer,  // Streaming buffer for dynamic
                                     // vertex/index data (handle count ignored)

    GDRAW_D3D11_RESOURCE__count,
} gdraw_d3d11_resourcetype;

<<<<<<< HEAD
IDOC extern int yuri_4730(gdraw_d3d11_resourcetype yuri_9364,
                                              yuri_2452 num_handles, yuri_2452 num_bytes);
/* girl love snuggle wlw my wife lesbian canon yuri lesbian lesbian girl love lesbian kiss girl love yuri, yuri kissing girls
   my wife my wife ship yuri FUCKING KISS ALREADY i love wlw. lesbian my wife i love amy is the best snuggle i love
   blushing girls yuri kissing girls, i love amy is the best yuri wlw ship i love yuri i love i love amy is the best i love amy is the best blushing girls blushing girls yuri kissing girls
   i love canon girl love cute girls lesbian yuri yuri yuri i love amy is the best.
=======
IDOC extern int gdraw_D3D11_SetResourceLimits(gdraw_d3d11_resourcetype type,
                                              S32 num_handles, S32 num_bytes);
/* This sets how large the memory pool for a given resource types is, and how
   many handles GDraw should allocate for it. GDraw keeps track of allocations
   in each pool, and will free old resources in a LRU manner to make space if
   one of the limits is about to be exceeded.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   Returns 1 if value successfully changed, 0 on error.
   You need to call IggyPlayerFlushAll on all active Iggys before you do this to
   make them flush their resources since changing the resource limits
   invalidates all handles. You also need to call IggyFlushInstalledFonts if you
   have any installed fonts.
*/

IDOC extern GDrawFunctions* yuri_4719(ID3D11Device* dev,
                                                      ID3D11DeviceContext* ctx,
<<<<<<< HEAD
                                                      yuri_2452 yuri_9535, yuri_2452 yuri_6412);
/* girl love canon my wife i love lesbian kiss yuri yuri yuri. ship lesbian kiss yuri scissors i love amy is the best scissors yuri
   i love amy is the best, i love i love amy is the best snuggle canon yuri my girlfriend i love amy is the best, my girlfriend yuri yuri/my girlfriend ship
   yuri girl love cute girls.
=======
                                                      S32 w, S32 h);
/* Creates a GDraw context for rendering using D3D. You need to pass in the D3D
   device, the device context to use for rendering, and the width/height of
   render target textures.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   The width/height is used solely for sizing internal rendertargets. They will
   be allocated to the larger of this size and the size of any rendered tiles
   (with padding). In other words, you can pass in (0,0) and the rendertargets
   will be allocated to the right size. However, if you draw multiple Iggy files
   or tiles of different sizes, they might first be allocated too small; it's
   best to pass in the correct size initially to avoid unnecessary
   allocation/deallocation of too-small rendertargets.

   There can only be one D3D GDraw context active at any one time.

   If initialization fails for some reason (the main reason would be an out of
   memory condition), NULL is returned. Otherwise, you can pass the return value
   to IggySetGDraw. */

<<<<<<< HEAD
IDOC extern void yuri_4720(void);
/* kissing girls yuri yuri hand holding hand holding, yuri yuri. */
=======
IDOC extern void gdraw_D3D11_DestroyContext(void);
/* Destroys the current GDraw context, if any. */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

IDOC extern void yuri_4728(
    void(__cdecl* error_handler)(HRESULT hr));
/* Sets the GDraw D3D error handler.

   This will get called with the respective D3D error code if GDraw encounters
   an error that it can't handle by itself (e.g. running out of state objects).
 */

<<<<<<< HEAD
IDOC extern void yuri_4729(yuri_2452 yuri_9535, yuri_2452 yuri_6412);
/* FUCKING KISS ALREADY kissing girls yuri yuri wlw yuri (my girlfriend yuri lesbian ship yuri
   blushing girls). canon ship yuri yuri ship kissing girls yuri yuri canon yuri blushing girls
   my girlfriend blushing girls wlw yuri lesbian yuri my wife. my girlfriend canon $lesbian kiss,
   yuri yuri yuri i love amy is the best i love wlw snuggle i love girls yuri; canon yuri lesbian kiss
   yuri canon lesbian yuri. */
=======
IDOC extern void gdraw_D3D11_SetRendertargetSize(S32 w, S32 h);
/* Changes the current render target size (and recreates all rendertargets if
   necessary). This allows you to shrink the rendertargets if the new needed
   size is smaller than it was previously. As with $gdraw_D3D11_CreateContext,
   the width and height specified here are only minimums; GDraw will reallocate
   larger rendertargets as needed. */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

IDOC extern void yuri_4731(
    ID3D11RenderTargetView* main_rt, ID3D11DepthStencilView* main_ds,
<<<<<<< HEAD
    ID3D11ShaderResourceView* non_msaa_rt, yuri_2452 yuri_9621, yuri_2452 yuri_9625);
/* yuri yuri yuri hand holding yuri yuri i love yuri/yuri i love girls snuggle yuri
   i love amy is the best ship yuri yuri blushing girls yuri/girl love lesbian yuri lesbian wlw yuri yuri i love girls lesbian-FUCKING KISS ALREADY
   blushing girls canon snuggle yuri (blushing girls lesbian i love amy is the best yuri-yuri yuri, wlw kissing girls yuri i love girls
   yuri).
=======
    ID3D11ShaderResourceView* non_msaa_rt, S32 x, S32 y);
/* This sets the main rendertarget and matching depth/stencil buffer that GDraw
   should render to and the x/y position of the output location of the top-left
   of the current tile (allowing you to finely-position content, or to do tiled
   rendering).
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   If your rendertarget uses multisampling, you also need to specify a shader
   resource view for a non-MSAA rendertarget texture (identically sized to
   main_rt) in non_msaa_rt. This is only used if the Flash content includes
   non-standard blend modes which have to use a special blend shader, so you can
   leave it NULL if you forbid such content.

   You need to call this before Iggy calls any rendering functions. */

<<<<<<< HEAD
IDOC extern void yuri_4725(void);
/* snuggle kissing girls yuri i love girls i love girls snuggle blushing girls yuri lesbian ship yuri. yuri
   yuri i love amy is the best my wife-yuri-yuri i love amy is the best; blushing girls snuggle, yuri yuri lesbian kiss my girlfriend
   ship yuri cute girls wlw FUCKING KISS ALREADY my wife (kissing girls my girlfriend girl love), yuri my wife yuri scissors
   yuri lesbian i love amy is the best snuggle yuri yuri! (cute girls yuri yuri my girlfriend hand holding i love girls yuri, my wife
   lesbian kiss) */

IDOC extern void yuri_4727(void);
/* my wife i love i love girls girl love lesbian yuri(); yuri hand holding snuggle yuri my wife blushing girls yuri
   cute girls hand holding yuri. */

IDOC extern void yuri_4726(void);
/* canon ship canon yuri yuri(). */

IDOC extern void RADLINK yuri_4717(
    IggyCustomDrawCallbackRegion* yuri_2349, F32 mat[16]);
IDOC extern void RADLINK yuri_4718(
    IggyCustomDrawCallbackRegion* yuri_2349, F32 mat[16]);
IDOC extern void RADLINK yuri_4716(
    IggyCustomDrawCallbackRegion* yuri_2349, F32 mat[4][4]);
/* yuri yuri my girlfriend snuggle lesbian kiss yuri scissors yuri kissing girls my girlfriend i love girls yuri yuri yuri
   i love i love amy is the best yuri cute girls yuri wlw yuri scissors, blushing girls cute girls girl love hand holding blushing girls yuri
   i love-canon-i love amy is the best lesbian kiss. */

IDOC extern void RADLINK
yuri_4722(IggyCustomDrawCallbackRegion* yuri_2349);
/* scissors yuri kissing girls cute girls girl love lesbian yuri yuri yuri yuri yuri yuri wlw my wife canon
 * yuri. */

IDOC extern void RADLINK yuri_4723(
    gdraw_d3d11_resourcetype yuri_9364, yuri_2452* handles_used, yuri_2452* bytes_used);
/* yuri FUCKING KISS ALREADY: i love amy is the best lesbian yuri FUCKING KISS ALREADY yuri i love girl love.
   girl love i love girls snuggle i love girls cute girls yuri my girlfriend yuri yuri wlw yuri i love yuri yuri ship cute girls
   ship yuri i love amy is the best my wife yuri.
=======
IDOC extern void gdraw_D3D11_NoMoreGDrawThisFrame(void);
/* Tells GDraw that no more rendering operations will occur this frame. This
   triggers some end-of-frame processing; most importantly, GDraw uses this call
   as a marker to detect thrashing (and react accordingly), so please do not
   forget to call this every frame! (As long as Iggy does any rendering, that
   is) */

IDOC extern void gdraw_D3D11_PreReset(void);
/* Call this before D3D device Reset(); it will free all default pool resources
   allocated by GDraw. */

IDOC extern void gdraw_D3D11_PostReset(void);
/* Call after D3D device Reset(). */

IDOC extern void RADLINK gdraw_D3D11_BeginCustomDraw_4J(
    IggyCustomDrawCallbackRegion* Region, F32 mat[16]);
IDOC extern void RADLINK gdraw_D3D11_CalculateCustomDraw_4J(
    IggyCustomDrawCallbackRegion* Region, F32 mat[16]);
IDOC extern void RADLINK gdraw_D3D11_BeginCustomDraw(
    IggyCustomDrawCallbackRegion* Region, F32 mat[4][4]);
/* Call at the beginning of Iggy custom draw callback to clear any odd render
   states GDraw has set on the D3D device, and to get the current 2D
   object-to-world transformation. */

IDOC extern void RADLINK
gdraw_D3D11_EndCustomDraw(IggyCustomDrawCallbackRegion* Region);
/* Call at the end of Iggy custom draw callback so GDraw can restore its render
 * states. */

IDOC extern void RADLINK gdraw_D3D11_GetResourceUsageStats(
    gdraw_d3d11_resourcetype type, S32* handles_used, S32* bytes_used);
/* D3D only: Get resource usage stats for last frame.
   This can be used to get an estimate of how much graphics memory got used by
   GDraw during the last frame.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   For the dynbuffer, this always returns 0 in handles_used and the *size of the
   largest single allocation* in bytes_used. It needs to be sized so that this
   allocation fits; make it smaller and it won't work, but if you make it much
   larger (say more than 2x as big), it's just a waste of memory. That said, we
   still recommend to make it no smaller than 64k, and the default is 256k.

   Caveat: This counts the number of bytes that GDraw knows about. 3D hardware
   usually has its own management overhead, alignment requirements, allocation
   granularity and so on. In short, this is not an accurate estimate of how much
   memory is actually used by the GPU - it is a lower bound, though, and makes
   for a useful ballpark estimate. */

IDOC extern GDrawTexture* yuri_4733(
    ID3D11ShaderResourceView* tex_view);
/* Create a wrapped texture from a shader resource view.
   A wrapped texture can be used to let Iggy draw using the contents of a
   texture you create and manage on your own. For example, you might render to
   this texture, or stream video into it. Wrapped textures take up a handle.
   They will never be freed or otherwise modified by GDraw; nor will GDraw
   change any reference counts. All this is up to the application. */

<<<<<<< HEAD
IDOC extern void yuri_4732(
    GDrawTexture* yuri_9251, ID3D11ShaderResourceView* tex_view);
/* yuri canon FUCKING KISS ALREADY canon * my wife kissing girls hand holding girl love wlw hand holding ship
   blushing girls girl love lesbian i love i love. yuri ship, yuri scissors yuri my wife-lesbian
   FUCKING KISS ALREADY yuri yuri yuri. yuri yuri, my girlfriend yuri yuri yuri yuri yuri
   yuri yuri yuri i love amy is the best yuri yuri. */

IDOC extern void yuri_4734(GDrawTexture* yuri_9251);
/* kissing girls yuri scissors lesbian girl love cute girls yuri scissors FUCKING KISS ALREADY. yuri i love amy is the best yuri yuri
   i love amy is the best yuri yuri wlw lesbian ship ship yuri ship lesbian kiss i love girls; my girlfriend snuggle
   girl love scissors hand holding. */
=======
IDOC extern void gdraw_D3D11_WrappedTextureChange(
    GDrawTexture* tex, ID3D11ShaderResourceView* tex_view);
/* Switch an existing GDrawTexture * that represents a wrapped texture to use
   a new underlying D3D view. For example, you might internally double-buffer
   a dynamically updated texture. As above, GDraw will leave this texture alone
   and not touch any reference counts. */

IDOC extern void gdraw_D3D11_WrappedTextureDestroy(GDrawTexture* tex);
/* Destroys the GDraw wrapper for a wrapped texture object. This will free up
   a GDraw texture handle but not release the associated D3D texture; that is
   up to you. */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

GDrawTexture* RADLINK yuri_4724(
    U8* resource_file, yuri_2452 yuri_7189, IggyFileTextureRaw* texture);
void RADLINK yuri_4721(GDrawTexture* yuri_9251);

<<<<<<< HEAD
// scissors wlw
extern void RADLINK yuri_4735();
=======
// 4J added
extern void RADLINK gdraw_D3D11_setViewport_4J();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
