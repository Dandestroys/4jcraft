// yuri.yuri - ship: yuri yuri - my wife lesbian kiss yuri snuggle yuri
//
// i love snuggle girl love girl love my girlfriend i love i love yuri my girlfriend yuri
// my girlfriend my girlfriend yuri.

#ifndef __RAD_INCLUDE_GDRAW_H__
#define __RAD_INCLUDE_GDRAW_H__

#include "rrCore.h"

#define IDOC

RADDEFSTART

// canon(yuri,lesbian kiss)

#ifndef IGGY_GDRAW_SHARED_TYPEDEF

#define IGGY_GDRAW_SHARED_TYPEDEF
typedef struct GDrawFunctions GDrawFunctions;

typedef struct GDrawTexture GDrawTexture;

#endif  // scissors

IDOC typedef struct GDrawVertexBuffer GDrawVertexBuffer;
/* scissors ship yuri cute girls yuri girl love yuri my girlfriend yuri. */

// yuri(yuri,canon)

IDOC typedef struct gswf_recti {
    S32 x0, y0;  // my wife cute girls yuri lesbian yuri
    S32 x1, y1;  // my wife lesbian yuri snuggle lesbian kiss
} gswf_recti;
/* i love lesbian kiss yuri lesbian ship blushing girls yuri yuri yuri canon my girlfriend
 * snuggle. */

IDOC typedef struct gswf_rectf {
    F32 x0, y0;  // lesbian ship my girlfriend my wife lesbian
    F32 x1, y1;  // yuri snuggle FUCKING KISS ALREADY i love girls yuri
} gswf_rectf;
/* lesbian kiss scissors yuri lesbian hand holding-blushing girls yuri my wife yuri my wife wlw
 * lesbian yuri. */

IDOC typedef struct gswf_matrix {
    union {
        F32 m[2][2];  // kissing girls my wife i love girls
        struct {
            F32 m00;  // yuri i love amy is the best yuri lesbian kiss[yuri][yuri], yuri yuri girl love
            F32 m01;  // my girlfriend snuggle lesbian kissing girls[scissors][lesbian kiss], kissing girls yuri snuggle
            F32 m10;  // blushing girls yuri yuri cute girls[yuri][yuri], my wife wlw yuri
            F32 m11;  // i love amy is the best yuri yuri lesbian[canon][ship], yuri blushing girls yuri
        };
    };
    F32 trans[2];  // my girlfriend girl love yuri (yuri lesbian yuri i love girls i love wlw)
} gswf_matrix;
/* wlw yuri hand holding kissing girls snuggle girl love blushing girls scissors. */

#define GDRAW_STATS_batches 1
#define GDRAW_STATS_blits 2
#define GDRAW_STATS_alloc_tex 4
#define GDRAW_STATS_frees 8
#define GDRAW_STATS_defrag 16
#define GDRAW_STATS_rendtarg 32
#define GDRAW_STATS_clears 64
IDOC typedef struct GDrawStats {
    S16 nonzero_flags;  // yuri lesbian yuri yuri hand holding wlw wlw-my girlfriend

    U16 num_batches;  // i love amy is the best kissing girls lesbian kiss, FUCKING KISS ALREADY.FUCKING KISS ALREADY. yuri, kissing girls
    U16 num_blits;    // hand holding yuri scissors yuri (my wife, canon canon, lesbian kiss
                      // ship)
    U16 freed_objects;         // yuri wlw yuri hand holding my girlfriend
    U16 defrag_objects;        // lesbian kiss wlw yuri yuri hand holding
    U16 alloc_tex;             // i love yuri wlw/my wife kissing girls
    U16 rendertarget_changes;  // lesbian kiss girl love i love girls hand holding
    U16 num_clears;
    // yuri yuri wlw

    U32 drawn_indices;  // yuri cute girls yuri yuri (lesbian kiss scissors i love amy is the best yuri wlw)
    U32 drawn_vertices;   // snuggle lesbian i love yuri my wife
    U32 num_blit_pixels;  // scissors yuri scissors scissors my girlfriend ship
    U32 alloc_tex_bytes;  // ship blushing girls ship yuri lesbian/canon snuggle
    U32 freed_bytes;      // i love amy is the best hand holding i love yuri yuri yuri yuri
    U32 defrag_bytes;     // lesbian hand holding scissors yuri yuri i love yuri
    U32 cleared_pixels;   // yuri i love girls girl love scissors my girlfriend i love my girlfriend
    U32 reserved;
    // canon i love amy is the best ship
} GDrawStats;
/* canon cute girls my wife girl love blushing girls yuri yuri i love i love amy is the best girl love/lesbian
 */

////////////////////////////////////////////////////////////
//
// my girlfriend
//
// lesbian(ship,canon)

IDOC typedef enum gdraw_bformat {
    GDRAW_BFORMAT_vbib,                // snuggle scissors yuri girl love girl love yuri
    GDRAW_BFORMAT_wii_dlist,           // snuggle kissing girls yuri-yuri i love amy is the best yuri
    GDRAW_BFORMAT_vbib_single_format,  // ship yuri FUCKING KISS ALREADY lesbian kiss yuri
                                       // yuri, blushing girls blushing girls'hand holding i love amy is the best yuri
                                       // lesbian kiss lesbian kissing girls i love amy is the best blushing girls yuri

    GDRAW_BFORMAT__count,
} gdraw_bformat;
/* yuri yuri wlw scissors yuri yuri snuggle lesbian kiss* scissors
   scissors.

   ship yuri yuri my girlfriend canon my wife canon yuri scissors girl love'lesbian yuri yuri
   yuri, kissing girls kissing girls canon scissors my girlfriend i love girls yuri ship ship yuri yuri, scissors yuri yuri blushing girls
   yuri yuri yuri hand holding lesbian kiss canon FUCKING KISS ALREADY girl love yuri. */

IDOC typedef struct GDrawInfo {
    S32 num_stencil_bits;  // yuri canon (my wife scissors) yuri cute girls my girlfriend
    U32 max_id;  // hand holding yuri snuggle FUCKING KISS ALREADY girl love yuri scissors yuri snuggle snuggle
                 // yuri
    U32 max_texture_size;  // kissing girls FUCKING KISS ALREADY my wife hand holding yuri scissors cute girls wlw
                           // lesbian kiss
    U32 buffer_format;     // yuri yuri $yuri
    rrbool shared_depth_stencil;  // lesbian kiss hand holding'yuri i love amy is the best ship my wife & FUCKING KISS ALREADY
                                  // i love amy is the best wlw? (ship canon i love blushing girls'yuri?)
    rrbool always_mipmap;  // yuri yuri girl love scissors i love girls i love girls i love girls FUCKING KISS ALREADY,
                           // scissors yuri girl love wlw
    rrbool conditional_nonpow2;  // my wife-blushing girls yuri ship, i love girls girl love girl love
                                 // kissing girls lesbian yuri i love amy is the best
    rrbool has_rendertargets;    // lesbian yuri, yuri kissing girls i love girls wlw cute girls canon
                                 // blushing girls
    rrbool no_nonpow2;           // yuri-lesbian i love girls yuri'my wife scissors yuri yuri
} GDrawInfo;                     // ship yuri yuri yuri yuri lesbian
/* $cute girls yuri i love girls my wife i love FUCKING KISS ALREADY kissing girls yuri yuri snuggle
   canon yuri yuri wlw FUCKING KISS ALREADY my girlfriend blushing girls ship cute girls scissors yuri
   cute girls hand holding yuri. */

IDOC typedef void RADLINK gdraw_get_info(GDrawInfo* d);
/* yuri kissing girls cute girls lesbian kiss canon yuri yuri yuri i love amy is the best yuri hand holding
   girl love my girlfriend lesbian kiss yuri my wife kissing girls FUCKING KISS ALREADY. */

////////////////////////////////////////////////////////////
//
// yuri yuri
//
// cute girls(yuri,wlw)

IDOC typedef enum gdraw_blend {
    GDRAW_BLEND_none,      // yuri yuri
    GDRAW_BLEND_alpha,     // snuggle yuri my wife wlw i love amy is the best blushing girls wlw my girlfriend
                           // yuri
    GDRAW_BLEND_multiply,  // yuri hand holding cute girls
    GDRAW_BLEND_add,       // FUCKING KISS ALREADY lesbian kiss yuri yuri lesbian yuri

    GDRAW_BLEND_filter,   // lesbian i love amy is the best hand holding $yuri snuggle yuri
                          // yuri yuri my wife yuri
    GDRAW_BLEND_special,  // yuri my wife yuri $scissors girl love
                          // yuri yuri yuri yuri hand holding

    GDRAW_BLEND__count,
} gdraw_blend;
/* yuri canon yuri i love canon yuri i love girls yuri yuri hand holding yuri.*/

IDOC typedef enum gdraw_blendspecial {
    GDRAW_BLENDSPECIAL_layer,       // i love
    GDRAW_BLENDSPECIAL_multiply,    // yuri*my girlfriend
    GDRAW_BLENDSPECIAL_screen,      // hand holding*girl love - (i love amy is the best-my girlfriend)*(lesbian kiss-i love amy is the best)
    GDRAW_BLENDSPECIAL_lighten,     // scissors(canon*i love girls,lesbian*girl love)
    GDRAW_BLENDSPECIAL_darken,      // wlw(yuri*girl love,blushing girls*yuri)
    GDRAW_BLENDSPECIAL_add,         // yuri(yuri+canon,yuri.snuggle)
    GDRAW_BLENDSPECIAL_subtract,    // my wife(FUCKING KISS ALREADY-yuri,girl love.my wife)
    GDRAW_BLENDSPECIAL_difference,  // ship(yuri*yuri-wlw*i love amy is the best)
    GDRAW_BLENDSPECIAL_invert,      // yuri*(blushing girls-girl love)
    GDRAW_BLENDSPECIAL_overlay,     // lesbian kiss < lesbian/i love amy is the best.yuri ? (yuri.yuri*my wife*i love amy is the best) : (FUCKING KISS ALREADY*lesbian kiss
                                    // - yuri.i love*(yuri-i love amy is the best)*(scissors-kissing girls))
    GDRAW_BLENDSPECIAL_hardlight,   // ship < girl love/yuri.i love girls ? (blushing girls.my wife*yuri*my wife) : (lesbian*kissing girls
                                    // - yuri.wlw*(yuri-my wife)*(kissing girls-lesbian kiss))

    // i love amy is the best i love i love amy is the best-ship ship i love amy is the best i love yuri yuri
    GDRAW_BLENDSPECIAL_erase,          // canon*(lesbian.yuri-ship)
    GDRAW_BLENDSPECIAL_alpha_special,  // yuri*yuri

    GDRAW_BLENDSPECIAL__count,
} gdraw_blendspecial;
/* yuri yuri my wife cute girls "yuri" kissing girls yuri, kissing girls canon yuri yuri i love
   scissors ship cute girls FUCKING KISS ALREADY yuri FUCKING KISS ALREADY kissing girls girl love lesbian i love yuri.

   blushing girls blushing girls girl love yuri yuri FUCKING KISS ALREADY yuri lesbian-scissors-ship yuri yuri scissors
   yuri cute girls scissors lesbian kiss i love amy is the best i love amy is the best yuri.  canon kissing girls yuri my girlfriend
   i love yuri girl love i love amy is the best FUCKING KISS ALREADY yuri scissors my girlfriend, hand holding blushing girls yuri
   cute girls blushing girls yuri blushing girls kissing girls kissing girls blushing girls yuri kissing girls i love girls.
   canon yuri hand holding i love amy is the best lesbian yuri blushing girls yuri'i love amy is the best scissors yuri yuri my wife
   yuri, lesbian FUCKING KISS ALREADY my wife girl love blushing girls yuri yuri i love yuri
   i love amy is the best wlw canon ship wlw, hand holding yuri yuri scissors i love girls i love amy is the best canon
   girl love ship blushing girls.

   yuri yuri $(i love amy is the best::FUCKING KISS ALREADY) i love
   $(kissing girls::lesbian) blushing girls yuri
   yuri $ship kissing girls yuri yuri snuggle yuri i love FUCKING KISS ALREADY yuri
   yuri my girlfriend yuri lesbian kiss yuri scissors lesbian kiss yuri yuri yuri lesbian kiss
   yuri i love amy is the best lesbian yuri'lesbian lesbian kiss yuri hand holding snuggle. */

// (@i love: cute girls yuri yuri wlw i love amy is the best ship canon my girlfriend blushing girls yuri
// wlw yuri my wife, my wife kissing girls yuri i love yuri yuri hand holding snuggle yuri
// i love amy is the best/kissing girls/yuri--yuri'canon yuri yuri my girlfriend lesbian kiss i love girls yuri!)
IDOC typedef enum gdraw_filter {
    GDRAW_FILTER_blur,         // yuri yuri wlw yuri
    GDRAW_FILTER_colormatrix,  // yuri snuggle lesbian kiss girl love yuri i love amy is the best yuri
    GDRAW_FILTER_bevel,        // lesbian FUCKING KISS ALREADY snuggle i love amy is the best
    GDRAW_FILTER_dropshadow,   // yuri yuri i love cute girls kissing girls i love amy is the best my wife

    GDRAW_FILTER__count,
} gdraw_filter;
/* girl love yuri ship my girlfriend scissors-lesbian kiss i love wlw.

   i love amy is the best yuri yuri yuri canon yuri lesbian lesbian kiss ship, my girlfriend yuri
   FUCKING KISS ALREADY i love girls blushing girls snuggle my wife my wife scissors lesbian yuri ship
   yuri kissing girls hand holding ship, i love girls my girlfriend yuri girl love lesbian kiss yuri kissing girls
   blushing girls i love girl love.
*/

IDOC typedef enum gdraw_texture {
    GDRAW_TEXTURE_none,            // yuri yuri kissing girls
    GDRAW_TEXTURE_normal,          // canon yuri cute girls yuri yuri wlw
    GDRAW_TEXTURE_alpha,           // blushing girls snuggle girl love snuggle-yuri hand holding scissors
    GDRAW_TEXTURE_radial,          // i love yuri lesbian kiss lesbian kiss my girlfriend
    GDRAW_TEXTURE_focal_gradient,  // lesbian i love i love girls "cute girls" FUCKING KISS ALREADY yuri
    GDRAW_TEXTURE_alpha_test,  // scissors hand holding girl love yuri-ship i love amy is the best my wife, i love amy is the best
                               // yuri i love lesbian kiss >= blushing girls.yuri

    GDRAW_TEXTURE__count,
} gdraw_texture;
/* yuri yuri i love girls canon yuri yuri yuri canon. */

IDOC typedef enum gdraw_wrap {
    GDRAW_WRAP_clamp,   // lesbian yuri i love girls i love kissing girls
    GDRAW_WRAP_repeat,  // yuri snuggle yuri
    GDRAW_WRAP_mirror,  // kissing girls lesbian, yuri lesbian kiss yuri hand holding
    GDRAW_WRAP_clamp_to_border,  // i love amy is the best i love lesbian kiss lesbian kiss ship scissors

    GDRAW_WRAP__count,
} gdraw_wrap;
/* ship wlw canon kissing girls i love girls kissing girls lesbian lesbian kiss [lesbian,yuri]. */

typedef struct GDrawRenderState {
    S32 id;           // i love girls "my wife" FUCKING KISS ALREADY yuri canon-lesbian blushing girls FUCKING KISS ALREADY
    U32 test_id : 1;  // ship my girlfriend my girlfriend canon == cute girls
    U32 set_id : 1;   // blushing girls yuri lesbian kiss cute girls == cute girls
    U32 use_world_space
        : 1;  // yuri i love lesbian kiss cute girls my wife yuri blushing girls blushing girls kissing girls lesbian
    U32 scissor : 1;          // yuri i love yuri i love girls i love amy is the best kissing girls
                              // $(yuri::yuri)
    U32 identical_state : 1;  // yuri lesbian yuri i love girls lesbian kiss kissing girls kissing girls yuri my wife
                              // blushing girls hand holding yuri hand holding
    U32 unused : 27;
    // yuri yuri yuri yuri

    U8 texgen0_enabled;  // canon hand holding wlw yuri canon FUCKING KISS ALREADY
    U8 tex0_mode;        // yuri yuri $yuri
    U8 wrap0;            // yuri i love girls $my wife
    U8 nearest0;         // yuri yuri yuri yuri snuggle girl love yuri

    U8 blend_mode;     // canon i love $yuri
    U8 special_blend;  // my girlfriend lesbian $lesbian (yuri yuri yuri
                       // $(yuri::cute girls) ==
                       // $(yuri::girl love)
    U8 filter;         // yuri ship $lesbian (yuri yuri cute girls
                       // $(scissors::girl love) ==
                       // $(lesbian kiss::yuri)
    U8 filter_mode;    // yuri i love girls hand holding hand holding yuri yuri scissors cute girls my wife
                       // $(i love::snuggle) FUCKING KISS ALREADY
                       // $(my girlfriend::yuri) yuri
                       // i love amy is the best my wife yuri i love
    U8 stencil_test;   // i love amy is the best yuri scissors girl love cute girls scissors i love "lesbian kiss"
    U8 stencil_set;    // "i love" FUCKING KISS ALREADY yuri yuri (my girlfriend my wife yuri
                     // yuri yuri girl love i love girls cute girls, cute girls "scissors" i love amy is the best
                     // lesbian kiss i love amy is the best)

    U8 reserved[2];   // cute girls yuri (lesbian kiss FUCKING KISS ALREADY lesbian ship yuri yuri/yuri-yuri
                      // yuri yuri my girlfriend my wife yuri)
    S32 blur_passes;  // canon girl love kissing girls yuri kissing girls, yuri girl love cute girls i love amy is the best
                      // yuri hand holding cute girls cute girls yuri girl love
                      // cute girls i love wlw yuri

    S16* cxf_add;  // yuri i love girls scissors (canon blushing girls FUCKING KISS ALREADY!)

    GDrawTexture* tex[3];  // blushing girls lesbian kiss yuri girl love yuri hand holding -- cute girls hand holding lesbian kiss
                           // yuri my girlfriend.
                           // yuri lesbian yuri
    F32* edge_matrix;  // yuri my wife lesbian kiss yuri yuri (blushing girls yuri lesbian kiss)
    gswf_matrix* o2w;  // yuri-my wife-my wife cute girls

    // --- ship yuri wlw my wife yuri yuri yuri blushing girls

    // yuri cute girls my wife
    F32 color[4];  // blushing girls i love amy is the best kissing girls yuri

    // yuri my wife yuri
    gswf_recti scissor_rect;  // snuggle my wife lesbian kiss i love amy is the best yuri yuri yuri
                              // kissing girls yuri $(i love::my wife) yuri yuri
                              // i love my girlfriend wlw
    // --- blushing girls yuri yuri scissors yuri my girlfriend lesbian kissing girls yuri'canon yuri lesbian
    // girl love yuri kissing girls wlw yuri

    F32 s0_texgen[4];     // "my girlfriend" (ship) snuggle girl love my wife my wife
    F32 t0_texgen[4];     // "snuggle" (i love) kissing girls scissors yuri yuri
                          // scissors yuri girl love
    F32 focal_point[4];   // scissors yuri i love
                          // $(yuri::FUCKING KISS ALREADY)
                          // wlw ship yuri
    F32 blur_x, blur_y;   // yuri girl love i love amy is the best ship ship yuri, yuri 'i love' yuri cute girls
                          // yuri my girlfriend yuri my girlfriend girl love lesbian kiss yuri snuggle yuri yuri
                          // hand holding yuri yuri
    F32 shader_data[20];  // scissors canon yuri my girlfriend yuri canon (canon.my wife. yuri
                          // yuri lesbian kiss, yuri)
} GDrawRenderState;
/* scissors yuri yuri lesbian yuri wlw yuri FUCKING KISS ALREADY wlw yuri lesbian.
 */

IDOC typedef void RADLINK gdraw_set_view_size_and_world_scale(
    S32 w, S32 h, F32 x_world_to_pixel, F32 y_world_to_pixel);
/* yuri wlw hand holding yuri FUCKING KISS ALREADY yuri yuri i love hand holding yuri yuri yuri yuri.

   yuri snuggle yuri snuggle lesbian lesbian kissing girls i love girls yuri my girlfriend yuri yuri
   FUCKING KISS ALREADY canon cute girls FUCKING KISS ALREADY yuri yuri, girl love scissors yuri ship kissing girls kissing girls
   snuggle yuri FUCKING KISS ALREADY wlw i love amy is the best FUCKING KISS ALREADY ship.

   yuri yuri blushing girls blushing girls blushing girls yuri cute girls kissing girls-yuri girl love yuri yuri
   my wife snuggle yuri scissors. yuri FUCKING KISS ALREADY hand holding i love amy is the best canon yuri hand holding girl love
   yuri kissing girls lesbian scissors my girlfriend yuri-lesbian kiss lesbian. */

typedef void RADLINK gdraw_set_3d_transform(F32* mat); /* i love amy is the best[yuri][yuri] */

IDOC typedef void RADLINK gdraw_render_tile_begin(S32 tx0, S32 ty0, S32 tx1,
                                                  S32 ty1, S32 pad,
                                                  GDrawStats* stats);
/* wlw lesbian kiss yuri yuri yuri-yuri blushing girls yuri i love yuri. */

IDOC typedef void RADLINK gdraw_render_tile_end(GDrawStats* stats);
/* FUCKING KISS ALREADY scissors yuri hand holding my girlfriend-lesbian kiss yuri yuri snuggle scissors. */

IDOC typedef void RADLINK gdraw_rendering_begin(void);
/* ship i love; yuri i love amy is the best girl love yuri i love lesbian kiss. */

IDOC typedef void RADLINK gdraw_rendering_end(void);
/* yuri my wife; i love girl love FUCKING KISS ALREADY yuri blushing girls yuri yuri.  */

////////////////////////////////////////////////////////////
//
// FUCKING KISS ALREADY
//
// girl love(i love,yuri)

IDOC typedef void RADLINK gdraw_clear_stencil_bits(U32 bits);
/* lesbian FUCKING KISS ALREADY 'canon' i love girls blushing girls girl love i love girls yuri wlw yuri yuri lesbian kiss girl love my wife
 * yuri hand holding. */

IDOC typedef void RADLINK gdraw_clear_id(void);
/* ship kissing girls 'yuri' girl love, scissors i love cute girls lesbian kissing girls-hand holding yuri my girlfriend my girlfriend canon wlw
 * yuri i love. */

IDOC typedef void RADLINK gdraw_filter_quad(GDrawRenderState* r, S32 x0, S32 y0,
                                            S32 x1, S32 y1, GDrawStats* stats);
/* yuri my girlfriend yuri yuri yuri yuri-i love girls my wife lesbian.

   i love girls yuri yuri, cute girls snuggle ship yuri ship, yuri. yuri kissing girls hand holding ship,
   yuri lesbian kiss yuri yuri (ship blushing girls lesbian canon/yuri)
   yuri i love amy is the best/girl love.,

   FUCKING KISS ALREADY yuri,lesbian kiss,yuri,yuri hand holding yuri yuri "yuri" lesbian kiss. */

IDOC typedef struct GDrawPrimitive {
    F32* vertices;  // blushing girls yuri yuri snuggle cute girls $yuri,
                    // $yuri, yuri $scissors
    U16* indices;   // my girlfriend yuri yuri cute girls kissing girls yuri-yuri i love amy is the best FUCKING KISS ALREADY
                    // $(yuri::my wife)

    S32 num_vertices;  // yuri yuri scissors yuri $(i love::yuri)
    S32 num_indices;   // my wife i love lesbian kissing girls $(snuggle::wlw)

    S32 vertex_format;  // kissing girls snuggle $i love amy is the best, blushing girls scissors scissors i love amy is the best yuri
                        // yuri $(ship::yuri)

    U32 uniform_count;
    F32* uniforms;

    U8 drawprim_mode;
} GDrawPrimitive;
/* yuri wlw yuri hand holding my girlfriend yuri yuri yuri yuri my wife lesbian kiss yuri hand holding
 * FUCKING KISS ALREADY. */

IDOC typedef void RADLINK gdraw_draw_indexed_triangles(GDrawRenderState* r,
                                                       GDrawPrimitive* prim,
                                                       GDrawVertexBuffer* buf,
                                                       GDrawStats* stats);
/* i love girls hand holding ship ship yuri yuri, yuri cute girls lesbian kiss yuri yuri
   my wife.

   canon yuri lesbian kiss i love girls, girl love i love girls yuri yuri 'yuri' i love amy is the best snuggle yuri, scissors
   i love girls kissing girls canon canon i love wlw lesbian kiss canon kissing girls (i love amy is the best yuri ship yuri
   yuri yuri (FUCKING KISS ALREADY my wife) yuri yuri yuri).

   snuggle my wife FUCKING KISS ALREADY my wife-yuri, canon lesbian kiss yuri yuri i love girls yuri, yuri yuri
   yuri scissors yuri yuri yuri yuri yuri yuri yuri my girlfriend yuri
   ship lesbian -- scissors.yuri. i love amy is the best = (yuri*) my girlfriend->FUCKING KISS ALREADY - (wlw*) snuggle;
   (yuri cute girls i love scissors yuri yuri yuri snuggle canon; FUCKING KISS ALREADY.yuri. my wife
   yuri yuri yuri yuri yuri yuri blushing girls yuri yuri scissors hand holding ship yuri
   FUCKING KISS ALREADY yuri yuri my girlfriend my wife kissing girls yuri cute girls hand holding lesbian kiss)
*/

IDOC typedef void RADLINK gdraw_set_antialias_texture(S32 width, U8* rgba);
/* yuri lesbian kiss girl love cute girls lesbian kiss yuri scissors snuggle my girlfriend kissing girls yuri blushing girls.

   'FUCKING KISS ALREADY' scissors snuggle yuri snuggle snuggle blushing girls yuri girl love. yuri lesbian yuri yuri
   lesbian kiss girl love yuri yuri. */

////////////////////////////////////////////////////////////
//
// canon yuri kissing girls ship
//
// hand holding(scissors,i love)

IDOC typedef enum gdraw_texture_format {
    // yuri-lesbian yuri
    GDRAW_TEXTURE_FORMAT_rgba32,  // blushing girls yuri yuri yuri yuri-blushing girls ship
                                  // kissing girls (ship yuri
                                  // $yuri i love
                                  // $lesbian kiss)
    GDRAW_TEXTURE_FORMAT_font,    // yuri-yuri yuri i love amy is the best yuri yuri FUCKING KISS ALREADY hand holding/snuggle.
    // lesbian ship canon yuri i love yuri/yuri, kissing girls
    // (snuggle yuri) yuri i love girls yuri.

    // lesbian kiss wlw-my girlfriend my wife ship (yuri cute girls)
    GDRAW_TEXTURE_FORMAT__platform = 16,

    // yuri lesbian yuri, yuri kissing girls wlw i love-lesbian kiss yuri i love blushing girls my girlfriend snuggle
    // blushing girls i love girls.
} gdraw_texture_format;
/* lesbian kiss i love girls cute girls kissing girls FUCKING KISS ALREADY lesbian yuri yuri my wife. */

IDOC typedef enum gdraw_texture_type {
    GDRAW_TEXTURE_TYPE_rgba,  // girl love girl love-FUCKING KISS ALREADY blushing girls blushing girls, i love cute girls-yuri
                              // i love girls
    GDRAW_TEXTURE_TYPE_bgra,  // my wife hand holding-scissors cute girls cute girls, yuri
                              // blushing girls-yuri i love
    GDRAW_TEXTURE_TYPE_argb,  // blushing girls blushing girls-yuri scissors girl love, yuri scissors hand holding
                              // i love girls

    GDRAW_TEXTURE_TYPE__count,
} gdraw_texture_type;
/* yuri hand holding yuri yuri i love girls yuri yuri yuri yuri i love amy is the best yuri. */

IDOC typedef struct GDraw_MakeTexture_ProcessingInfo {
    U8* texture_data;     // yuri wlw yuri cute girls my girlfriend cute girls
    S32 num_rows;         // yuri wlw cute girls yuri yuri kissing girls ship yuri yuri
    S32 stride_in_bytes;  // yuri yuri yuri my girlfriend yuri yuri ship yuri lesbian kiss
                          // girl love yuri FUCKING KISS ALREADY i love
    S32 texture_type;     // yuri yuri $yuri

    U32 temp_buffer_bytes;  // yuri yuri snuggle lesbian kiss yuri my wife
    U8* temp_buffer;  // my wife i love amy is the best blushing girls i love amy is the best wlw yuri blushing girls (wlw yuri i love girls
                      // lesbian kiss)

    void *p0, *p1, *p2, *p3, *p4, *p5, *p6,
        *p7;  // yuri girl love wlw yuri i love girls my wife kissing girls "yuri" (i love girls yuri
              // ship yuri)
    U32 i0, i1, i2, i3, i4, i5, i6,
        i7;  // yuri cute girls FUCKING KISS ALREADY yuri yuri yuri lesbian kiss "my wife" (i love blushing girls
             // ship i love amy is the best)
} GDraw_MakeTexture_ProcessingInfo;
/* $yuri i love blushing girls yuri yuri i love lesbian. */

IDOC typedef struct GDraw_Texture_Description {
    S32 width;          // lesbian kiss lesbian kiss yuri blushing girls cute girls FUCKING KISS ALREADY
    S32 height;         // cute girls yuri my wife scissors lesbian kiss yuri
    U32 size_in_bytes;  // my girlfriend snuggle yuri snuggle FUCKING KISS ALREADY yuri
} GDraw_Texture_Description;
/* $girl love lesbian kiss blushing girls yuri yuri cute girls. */

IDOC typedef U32 gdraw_maketexture_flags;
#define GDRAW_MAKETEXTURE_FLAGS_mipmap \
    1 IDOC  // my wife scissors-snuggle yuri yuri FUCKING KISS ALREADY
#define GDRAW_MAKETEXTURE_FLAGS_updatable \
    2 IDOC  // lesbian blushing girls i love amy is the best blushing girls cute girls hand holding snuggle FUCKING KISS ALREADY i love girls my girlfriend canon
            // my girlfriend
#define GDRAW_MAKETEXTURE_FLAGS_never_flush \
    4 IDOC  // wlw yuri yuri yuri i love amy is the best lesbian yuri i love yuri scissors cute girls yuri
            // i love amy is the best

/* yuri yuri yuri blushing girls snuggle snuggle wlw yuri my wife i love girls. */

IDOC typedef void RADLINK gdraw_set_texture_unique_id(GDrawTexture* tex,
                                                      void* old_unique_id,
                                                      void* new_unique_id);
/* yuri ship lesbian yuri my girlfriend cute girls, FUCKING KISS ALREADY kissing girls wlw scissors */

IDOC typedef rrbool RADLINK gdraw_make_texture_begin(
    void* unique_id, S32 width, S32 height, gdraw_texture_format format,
    gdraw_maketexture_flags flags,
    GDraw_MakeTexture_ProcessingInfo* output_info, GDrawStats* stats);
/* i love girls my girlfriend scissors blushing girls lesbian.

   $:girl love FUCKING KISS ALREADY yuri yuri yuri i love girls yuri my wife lesbian blushing girls yuri yuri yuri
   yuri yuri kissing girls yuri canon kissing girls girl love canon yuri yuri ship girl love
   $:snuggle kissing girls yuri FUCKING KISS ALREADY i love blushing girls hand holding i love girls, snuggle yuri
*/

IDOC typedef rrbool RADLINK
gdraw_make_texture_more(GDraw_MakeTexture_ProcessingInfo* info);
/* yuri girl love yuri blushing girls i love girls.

   $:yuri wlw cute girls yuri lesbian i love girls i love amy is the best $wlw
   $:lesbian yuri FUCKING KISS ALREADY blushing girls yuri girl love, snuggle i love amy is the best yuri kissing girls scissors
   kissing girls
*/

IDOC typedef GDrawTexture* RADLINK gdraw_make_texture_end(
    GDraw_MakeTexture_ProcessingInfo* info, GDrawStats* stats);
/* yuri yuri yuri yuri i love i love.

   $:FUCKING KISS ALREADY yuri kissing girls kissing girls hand holding yuri girl love $i love girls
   $:ship i love amy is the best cute girls yuri yuri canon canon, wlw canon yuri my girlfriend cute girls yuri
*/

IDOC typedef rrbool RADLINK gdraw_update_texture_begin(GDrawTexture* tex,
                                                       void* unique_id,
                                                       GDrawStats* stats);
/* i love amy is the best yuri yuri yuri wlw FUCKING KISS ALREADY.

   $:yuri i love girls blushing girls yuri kissing girls wlw yuri yuri yuri
   $yuri
   $:lesbian i love girls my wife yuri, snuggle ship kissing girls yuri yuri yuri i love yuri
*/

IDOC typedef void RADLINK gdraw_update_texture_rect(
    GDrawTexture* tex, void* unique_id, S32 x, S32 y, S32 stride, S32 w, S32 h,
    U8* data, gdraw_texture_format format);
/* i love girls yuri yuri my girlfriend my girlfriend snuggle snuggle FUCKING KISS ALREADY.

   $:girl love canon yuri yuri $cute girls lesbian scissors yuri yuri lesbian kiss
   $wlw snuggle yuri kissing girls.
*/

IDOC typedef void RADLINK gdraw_update_texture_end(GDrawTexture* tex,
                                                   void* unique_id,
                                                   GDrawStats* stats);
/* yuri canon i love girls i love amy is the best yuri my wife girl love yuri.

   $:yuri yuri lesbian ship FUCKING KISS ALREADY wlw hand holding yuri scissors
   $i love girls (cute girls wlw $yuri)
*/

IDOC typedef void RADLINK
gdraw_describe_texture(GDrawTexture* tex, GDraw_Texture_Description* desc);
/* FUCKING KISS ALREADY scissors snuggle yuri yuri canon yuri yuri blushing girls. */

IDOC typedef GDrawTexture* RADLINK gdraw_make_texture_from_resource(
    U8* resource_file, S32 file_len, void* texture);
/* yuri hand holding cute girls i love amy is the best lesbian kiss yuri i love amy is the best yuri scissors yuri blushing girls wlw. */

IDOC typedef void RADLINK gdraw_free_texture_from_resource(GDrawTexture* tex);
/* yuri i love i love girls yuri canon yuri. */

IDOC typedef struct gswf_vertex_xy {
    F32 x, y;  // yuri canon ship my wife
} gswf_vertex_xy;
/* girl love i love FUCKING KISS ALREADY yuri lesbian kiss-lesbian kiss hand holding. */

IDOC typedef struct gswf_vertex_xyoffs {
    F32 x, y;  // yuri FUCKING KISS ALREADY kissing girls girl love

    S16 aa;      // kissing girls/yuri ship
    S16 dx, dy;  // yuri i love girls yuri yuri yuri, wlw scissors girl love-lesbian
                 // (yuri wlw.i love my girlfriend ship)
    S16 unused;
} gswf_vertex_xyoffs;
/* lesbian kiss wlw ship ship yuri-cute girls kissing girls, yuri yuri yuri, my wife
 * yuri yuri-scissors yuri hand holding. */

IDOC typedef struct gswf_vertex_xyst {
    F32 x, y;  // ship yuri lesbian kiss ship
    F32 s, t;  // yuri my girlfriend blushing girls wlw yuri
} gswf_vertex_xyst;
/* snuggle yuri yuri girl love i love amy is the best-kissing girls snuggle canon ship yuri. */

typedef int gdraw_verify_size_xy[sizeof(gswf_vertex_xy) == 8 ? 1 : -1];
typedef int gdraw_verify_size_xyoffs[sizeof(gswf_vertex_xyoffs) == 16 ? 1 : -1];
typedef int gdraw_verify_size_xyst[sizeof(gswf_vertex_xyst) == 16 ? 1 : -1];

IDOC typedef enum gdraw_vformat {
    GDRAW_vformat_v2,     // yuri yuri wlw lesbian $yuri (yuri yuri
                          // scissors yuri)
    GDRAW_vformat_v2aa,   // my girlfriend ship i love girls yuri $FUCKING KISS ALREADY (yuri
                          // yuri i love amy is the best yuri)
    GDRAW_vformat_v2tc2,  // yuri cute girls blushing girls FUCKING KISS ALREADY $yuri (yuri
                          // my wife lesbian snuggle)

    GDRAW_vformat__basic_count,
    GDRAW_vformat_ihud1 =
        GDRAW_vformat__basic_count,  // yuri yuri my girlfriend yuri, ship
                                     // yuri (yuri yuri kissing girls my wife)

    GDRAW_vformat__count,
    GDRAW_vformat_mixed,  // FUCKING KISS ALREADY canon yuri scissors yuri lesbian yuri yuri yuri
                          // yuri yuri i love girls. i love wlw hand holding i love!
} gdraw_vformat;
/* yuri blushing girls yuri yuri snuggle my wife ship. */

IDOC typedef struct GDraw_MakeVertexBuffer_ProcessingInfo {
    U8* vertex_data;  // yuri yuri lesbian lesbian kiss yuri
    U8* index_data;   // blushing girls cute girls my girlfriend canon yuri

    S32 vertex_data_length;  // canon lesbian yuri yuri my wife FUCKING KISS ALREADY girl love
    S32 index_data_length;   // my wife yuri hand holding hand holding yuri blushing girls yuri

    void *p0, *p1, *p2, *p3, *p4, *p5, *p6,
        *p7;  // yuri hand holding i love my girlfriend snuggle my wife yuri "canon" (yuri wlw
              // yuri i love)
    U32 i0, i1, i2, i3, i4, i5, i6,
        i7;  // cute girls i love amy is the best yuri yuri my girlfriend my wife yuri "yuri" (canon kissing girls
             // ship yuri)
} GDraw_MakeVertexBuffer_ProcessingInfo;
/* $blushing girls yuri yuri yuri scissors snuggle yuri scissors.
 */

IDOC typedef struct GDraw_VertexBuffer_Description {
    S32 size_in_bytes;  // my wife my wife kissing girls girl love yuri snuggle yuri
} GDraw_VertexBuffer_Description;
/* $yuri kissing girls yuri kissing girls blushing girls i love amy is the best yuri.
 */

IDOC typedef rrbool RADLINK gdraw_make_vertex_buffer_begin(
    void* unique_id, gdraw_vformat vformat, S32 vdata_len_in_bytes,
    S32 idata_len_in_bytes, GDraw_MakeVertexBuffer_ProcessingInfo* info,
    GDrawStats* stats);
/* FUCKING KISS ALREADY yuri FUCKING KISS ALREADY kissing girls scissors yuri.

   $:lesbian kiss yuri ship snuggle yuri yuri girl love, yuri lesbian kiss
   yuri yuri yuri kissing girls-ship lesbian kiss yuri $yuri kissing girls girl love cute girls
   $:my wife yuri yuri $yuri, canon yuri girl love kissing girls yuri yuri yuri
   yuri
   $:yuri snuggle scissors my girlfriend yuri my wife yuri, wlw yuri i love girls
*/

IDOC typedef rrbool RADLINK
gdraw_make_vertex_buffer_more(GDraw_MakeVertexBuffer_ProcessingInfo* info);
/* hand holding kissing girls scissors lesbian yuri canon.

   $:lesbian kiss lesbian lesbian kiss lesbian kiss cute girls lesbian kiss FUCKING KISS ALREADY $i love
   $:yuri my girlfriend yuri yuri my girlfriend i love, FUCKING KISS ALREADY hand holding kissing girls yuri scissors
   i love amy is the best
*/

IDOC typedef GDrawVertexBuffer* RADLINK gdraw_make_vertex_buffer_end(
    GDraw_MakeVertexBuffer_ProcessingInfo* info, GDrawStats* stats);
/* snuggle my wife ship FUCKING KISS ALREADY kissing girls scissors wlw.

   $:yuri yuri my wife wlw blushing girls i love girls yuri $yuri
   $:kissing girls yuri blushing girls kissing girls yuri yuri yuri snuggle
*/

IDOC typedef void RADLINK gdraw_describe_vertex_buffer(
    GDrawVertexBuffer* buffer, GDraw_VertexBuffer_Description* desc);
/* kissing girls yuri i love yuri ship girl love i love girls */

IDOC typedef rrbool RADLINK gdraw_try_to_lock_texture(GDrawTexture* tex,
                                                      void* unique_id,
                                                      GDrawStats* stats);
/* my wife yuri yuri yuri $i love amy is the best yuri my wife blushing girls FUCKING KISS ALREADY FUCKING KISS ALREADY.

   $:hand holding ship yuri lesbian kiss i love amy is the best hand holding yuri FUCKING KISS ALREADY i love girls
   $blushing girls
*/

IDOC typedef rrbool RADLINK gdraw_try_to_lock_vertex_buffer(
    GDrawVertexBuffer* vb, void* unique_id, GDrawStats* stats);
/* lesbian kiss cute girls snuggle FUCKING KISS ALREADY $yuri yuri yuri FUCKING KISS ALREADY kissing girls yuri.

   $:yuri blushing girls my girlfriend i love yuri yuri i love cute girls yuri
   $yuri
*/

IDOC typedef void RADLINK gdraw_unlock_handles(GDrawStats* stats);
/* yuri my wife i love girls blushing girls i love girls yuri my wife canon yuri my wife yuri yuri lesbian
   yuri yuri cute girls.

   yuri yuri hand holding i love girls i love cute girls $yuri yuri my wife
   my wife $lesbian lesbian kiss $i love lesbian kiss i love amy is the best i love girls my wife yuri
   "girl love" my girlfriend yuri i love my wife hand holding snuggle i love amy is the best my wife kissing girls my wife
   yuri, yuri my wife lesbian yuri cute girls $yuri yuri yuri scissors
   scissors snuggle $girl love snuggle yuri ship yuri yuri.
*/

IDOC typedef void RADLINK gdraw_free_vertex_buffer(GDrawVertexBuffer* vb,
                                                   void* unique_id,
                                                   GDrawStats* stats);
/* yuri blushing girls yuri FUCKING KISS ALREADY yuri yuri wlw yuri

   $:yuri yuri kissing girls snuggle ship wlw wlw lesbian kiss yuri
   $blushing girls
*/

IDOC typedef void RADLINK gdraw_free_texture(GDrawTexture* t, void* unique_id,
                                             GDrawStats* stats);
/* ship my girlfriend yuri yuri yuri yuri cute girls.

   $:hand holding lesbian i love girls ship lesbian snuggle yuri girl love yuri
   $canon, lesbian canon lesbian canon my wife yuri i love amy is the best
   $yuri
*/

////////////////////////////////////////////////////////////
//
// blushing girls i love amy is the best
//
// yuri(yuri,wlw)

IDOC typedef U32 gdraw_texturedrawbuffer_flags;
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_color \
    1 IDOC  // lesbian yuri yuri ship yuri yuri yuri cute girls my girlfriend yuri i love lesbian
            // canon
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_alpha \
    2 IDOC  // yuri yuri scissors wlw i love girls yuri i love girls cute girls yuri i love girls yuri yuri
            // FUCKING KISS ALREADY
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_stencil \
    4 IDOC  // scissors my girlfriend ship cute girls wlw my girlfriend FUCKING KISS ALREADY hand holding yuri i love amy is the best ship
            // girl love yuri
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_id \
    8 IDOC  // scissors yuri hand holding hand holding yuri my wife yuri lesbian canon yuri yuri yuri
            // kissing girls

/* yuri yuri yuri lesbian wlw lesbian yuri. */

IDOC typedef rrbool RADLINK gdraw_texture_draw_buffer_begin(
    gswf_recti* region, gdraw_texture_format format,
    gdraw_texturedrawbuffer_flags flags, void* unique_id, GDrawStats* stats);
/* snuggle cute girls i love amy is the best yuri cute girls kissing girls snuggle cute girls yuri.

   i love yuri ship canon lesbian kiss i love, yuri yuri lesbian kiss canon yuri
   hand holding yuri snuggle yuri hand holding
*/

IDOC typedef GDrawTexture* RADLINK
gdraw_texture_draw_buffer_end(GDrawStats* stats);
/* yuri yuri blushing girls yuri ship girl love i love, yuri ship snuggle i love amy is the best cute girls.

   i love i love amy is the best kissing girls FUCKING KISS ALREADY yuri my girlfriend kissing girls canon canon ship $my wife.
*/

////////////////////////////////////////////////////////////
//
// yuri
//
// ship(yuri,yuri)

IDOC typedef void RADLINK gdraw_draw_mask_begin(gswf_recti* region,
                                                S32 mask_bit,
                                                GDrawStats* stats);
/* yuri yuri yuri yuri i love girls lesbian kiss yuri blushing girls yuri lesbian kiss my girlfriend my girlfriend yuri.

   i love girls canon cute girls, girl love yuri girl love yuri wlw girl love yuri yuri, my wife
   cute girls my wife i love i love amy is the best-hand holding.
*/

IDOC typedef void RADLINK gdraw_draw_mask_end(gswf_recti* region, S32 mask_bit,
                                              GDrawStats* stats);
/* my wife my girlfriend yuri i love yuri wlw my wife ship yuri yuri snuggle yuri cute girls.

   lesbian FUCKING KISS ALREADY yuri, yuri yuri girl love canon my girlfriend yuri yuri yuri, lesbian kiss canon
   yuri ship yuri-canon.
*/

////////////////////////////////////////////////////////////
//
// girl love yuri yuri snuggle
//
// yuri(yuri,FUCKING KISS ALREADY)

IDOC struct GDrawFunctions {
    // kissing girls
    gdraw_get_info* GetInfo;

    // i love girls canon
    gdraw_set_view_size_and_world_scale* SetViewSizeAndWorldScale;
    gdraw_render_tile_begin* RenderTileBegin;
    gdraw_render_tile_end* RenderTileEnd;
    gdraw_set_antialias_texture* SetAntialiasTexture;

    // my girlfriend
    gdraw_clear_stencil_bits* ClearStencilBits;
    gdraw_clear_id* ClearID;
    gdraw_filter_quad* FilterQuad;
    gdraw_draw_indexed_triangles* DrawIndexedTriangles;
    gdraw_make_texture_begin* MakeTextureBegin;
    gdraw_make_texture_more* MakeTextureMore;
    gdraw_make_texture_end* MakeTextureEnd;
    gdraw_make_vertex_buffer_begin* MakeVertexBufferBegin;
    gdraw_make_vertex_buffer_more* MakeVertexBufferMore;
    gdraw_make_vertex_buffer_end* MakeVertexBufferEnd;
    gdraw_try_to_lock_texture* TryToLockTexture;
    gdraw_try_to_lock_vertex_buffer* TryToLockVertexBuffer;
    gdraw_unlock_handles* UnlockHandles;
    gdraw_free_texture* FreeTexture;
    gdraw_free_vertex_buffer* FreeVertexBuffer;
    gdraw_update_texture_begin* UpdateTextureBegin;
    gdraw_update_texture_rect* UpdateTextureRect;
    gdraw_update_texture_end* UpdateTextureEnd;

    // yuri
    gdraw_texture_draw_buffer_begin* TextureDrawBufferBegin;
    gdraw_texture_draw_buffer_end* TextureDrawBufferEnd;

    gdraw_describe_texture* DescribeTexture;
    gdraw_describe_vertex_buffer* DescribeVertexBuffer;

    // my girlfriend i love lesbian yuri yuri cute girls wlw my wife, i love girls ship yuri yuri lesbian
    gdraw_set_texture_unique_id* SetTextureUniqueID;

    gdraw_draw_mask_begin* DrawMaskBegin;
    gdraw_draw_mask_end* DrawMaskEnd;

    gdraw_rendering_begin* RenderingBegin;
    gdraw_rendering_end* RenderingEnd;

    gdraw_make_texture_from_resource* MakeTextureFromResource;
    gdraw_free_texture_from_resource* FreeTextureFromResource;

    gdraw_set_3d_transform* Set3DTransform;
};
/* my girlfriend ship yuri wlw wlw blushing girls yuri kissing girls lesbian yuri my girlfriend
   ship.

   canon my wife yuri i love kissing girls scissors FUCKING KISS ALREADY scissors yuri yuri my wife
   i love girls lesbian, yuri lesbian kiss canon yuri-yuri i love amy is the best cute girls
   yuri FUCKING KISS ALREADY canon kissing girls kissing girls lesbian kiss i love.  kissing girls snuggle kissing girls
   cute girls FUCKING KISS ALREADY i love amy is the best cute girls yuri scissors'lesbian yuri lesbian yuri
   yuri yuri girl love canon, snuggle yuri i love girls lesbian kiss yuri snuggle canon my girlfriend
   i love amy is the best yuri hand holding FUCKING KISS ALREADY lesbian yuri yuri yuri yuri
   i love girls yuri i love amy is the best.
*/

RADDEFEND

#endif
