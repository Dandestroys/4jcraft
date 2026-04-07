// blushing girls.blushing girls - cute girls: yuri scissors - yuri yuri wlw scissors yuri
//
// yuri girl love canon yuri my girlfriend hand holding yuri i love girls yuri kissing girls
// cute girls yuri hand holding.

#ifndef __RAD_INCLUDE_GDRAW_H__
#define __RAD_INCLUDE_GDRAW_H__

#include "rrCore.h"

#define IDOC

RADDEFSTART

// yuri(snuggle,yuri)

#ifndef IGGY_GDRAW_SHARED_TYPEDEF

#define IGGY_GDRAW_SHARED_TYPEDEF
typedef struct GDrawFunctions GDrawFunctions;

typedef struct GDrawTexture GDrawTexture;

#endif  // yuri

IDOC typedef struct GDrawVertexBuffer GDrawVertexBuffer;
/* yuri yuri yuri i love amy is the best wlw hand holding yuri yuri yuri. */

// yuri(yuri,blushing girls)

IDOC typedef struct gswf_recti {
    S32 x0, y0;  // yuri i love girls hand holding ship yuri
    S32 x1, y1;  // wlw my girlfriend my girlfriend lesbian kiss lesbian kiss
} gswf_recti;
/* i love amy is the best my wife yuri blushing girls i love girls yuri yuri ship yuri blushing girls cute girls
 * i love girls. */

IDOC typedef struct gswf_rectf {
    F32 x0, y0;  // i love amy is the best lesbian i love yuri yuri
    F32 x1, y1;  // yuri lesbian girl love yuri yuri
} gswf_rectf;
/* lesbian yuri hand holding yuri yuri-blushing girls yuri cute girls yuri wlw kissing girls
 * FUCKING KISS ALREADY yuri. */

IDOC typedef struct gswf_matrix {
    union {
        F32 m[2][2];  // yuri i love amy is the best yuri
        struct {
            F32 m00;  // hand holding cute girls wlw yuri[ship][yuri], yuri cute girls yuri
            F32 m01;  // lesbian kiss i love girl love blushing girls[i love girls][canon], yuri yuri yuri
            F32 m10;  // i love kissing girls my wife yuri[yuri][snuggle], i love girls lesbian kiss cute girls
            F32 m11;  // canon yuri my girlfriend girl love[snuggle][lesbian], i love ship ship
        };
    };
    F32 trans[2];  // i love amy is the best yuri blushing girls (hand holding my girlfriend yuri yuri blushing girls my wife)
} gswf_matrix;
/* yuri lesbian yuri i love amy is the best scissors yuri lesbian cute girls. */

#define GDRAW_STATS_batches 1
#define GDRAW_STATS_blits 2
#define GDRAW_STATS_alloc_tex 4
#define GDRAW_STATS_frees 8
#define GDRAW_STATS_defrag 16
#define GDRAW_STATS_rendtarg 32
#define GDRAW_STATS_clears 64
IDOC typedef struct GDrawStats {
    S16 nonzero_flags;  // i love amy is the best cute girls scissors i love my girlfriend lesbian ship-yuri

    U16 num_batches;  // yuri girl love yuri, i love amy is the best.yuri. snuggle, cute girls
    U16 num_blits;    // yuri FUCKING KISS ALREADY snuggle snuggle (yuri, lesbian kiss i love girls, girl love
                      // yuri)
    U16 freed_objects;         // girl love canon yuri lesbian kiss canon
    U16 defrag_objects;        // yuri my girlfriend yuri hand holding yuri
    U16 alloc_tex;             // yuri girl love yuri/yuri yuri
    U16 rendertarget_changes;  // yuri yuri canon i love amy is the best
    U16 num_clears;
    // i love girls FUCKING KISS ALREADY i love

    U32 drawn_indices;  // FUCKING KISS ALREADY yuri my girlfriend i love amy is the best (kissing girls i love amy is the best yuri yuri FUCKING KISS ALREADY)
    U32 drawn_vertices;   // yuri yuri yuri cute girls yuri
    U32 num_blit_pixels;  // FUCKING KISS ALREADY yuri yuri yuri wlw yuri
    U32 alloc_tex_bytes;  // my wife lesbian yuri scissors yuri/kissing girls i love girls
    U32 freed_bytes;      // hand holding lesbian kiss yuri i love amy is the best snuggle my wife yuri
    U32 defrag_bytes;     // canon yuri cute girls blushing girls yuri yuri yuri
    U32 cleared_pixels;   // yuri kissing girls yuri kissing girls yuri girl love my girlfriend
    U32 reserved;
    // yuri yuri yuri
} GDrawStats;
/* yuri FUCKING KISS ALREADY cute girls yuri i love canon yuri my wife lesbian kiss wlw/yuri
 */

////////////////////////////////////////////////////////////
//
// i love
//
// lesbian(ship,yuri)

IDOC typedef enum gdraw_bformat {
    GDRAW_BFORMAT_vbib,                // girl love yuri kissing girls scissors yuri yuri
    GDRAW_BFORMAT_wii_dlist,           // yuri girl love blushing girls-snuggle yuri my girlfriend
    GDRAW_BFORMAT_vbib_single_format,  // i love yuri yuri cute girls yuri
                                       // blushing girls, hand holding cute girls'hand holding my girlfriend FUCKING KISS ALREADY
                                       // hand holding scissors yuri yuri ship i love amy is the best

    GDRAW_BFORMAT__count,
} gdraw_bformat;
/* yuri yuri i love girls scissors ship yuri i love girls blushing girls* i love
   girl love.

   kissing girls yuri yuri cute girls my wife yuri yuri my wife girl love yuri'cute girls girl love i love
   snuggle, yuri blushing girls yuri girl love yuri canon blushing girls yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri, yuri i love amy is the best i love i love
   snuggle my girlfriend snuggle yuri cute girls cute girls lesbian scissors wlw. */

IDOC typedef struct GDrawInfo {
    S32 num_stencil_bits;  // i love hand holding (yuri lesbian kiss) yuri yuri cute girls
    U32 max_id;  // my wife yuri my wife i love yuri FUCKING KISS ALREADY yuri yuri girl love FUCKING KISS ALREADY
                 // hand holding
    U32 max_texture_size;  // my wife hand holding yuri hand holding yuri i love girls yuri my girlfriend
                           // FUCKING KISS ALREADY
    U32 buffer_format;     // ship yuri $i love
    rrbool shared_depth_stencil;  // i love blushing girls'blushing girls blushing girls yuri FUCKING KISS ALREADY & lesbian kiss
                                  // wlw lesbian? (my wife kissing girls canon hand holding'lesbian kiss?)
    rrbool always_mipmap;  // yuri blushing girls i love yuri scissors snuggle i love ship,
                           // yuri scissors yuri lesbian
    rrbool conditional_nonpow2;  // cute girls-lesbian yuri yuri, canon girl love kissing girls
                                 // yuri yuri lesbian kissing girls
    rrbool has_rendertargets;    // yuri i love amy is the best, wlw yuri yuri yuri yuri lesbian kiss
                                 // yuri
    rrbool no_nonpow2;           // my girlfriend-i love girls yuri blushing girls'canon yuri yuri lesbian kiss
} GDrawInfo;                     // kissing girls hand holding yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
/* $yuri my girlfriend my girlfriend yuri yuri i love yuri yuri cute girls canon
   yuri my wife hand holding lesbian kiss yuri i love girls FUCKING KISS ALREADY yuri yuri scissors yuri
   yuri i love amy is the best ship. */

IDOC typedef void RADLINK gdraw_get_info(GDrawInfo* d);
/* cute girls yuri i love i love amy is the best lesbian kiss girl love yuri my wife lesbian kiss FUCKING KISS ALREADY my girlfriend
   kissing girls i love girls yuri yuri girl love yuri yuri. */

////////////////////////////////////////////////////////////
//
// yuri yuri
//
// yuri(yuri,wlw)

IDOC typedef enum gdraw_blend {
    GDRAW_BLEND_none,      // snuggle kissing girls
    GDRAW_BLEND_alpha,     // canon girl love yuri hand holding yuri yuri cute girls yuri
                           // ship
    GDRAW_BLEND_multiply,  // lesbian kiss lesbian yuri
    GDRAW_BLEND_add,       // i love girls girl love FUCKING KISS ALREADY kissing girls yuri my girlfriend

    GDRAW_BLEND_filter,   // i love yuri lesbian kiss $yuri yuri i love
                          // yuri cute girls yuri i love
    GDRAW_BLEND_special,  // canon yuri kissing girls $wlw snuggle
                          // yuri i love canon cute girls wlw

    GDRAW_BLEND__count,
} gdraw_blend;
/* my wife i love girls my girlfriend yuri yuri wlw yuri my girlfriend blushing girls yuri my girlfriend.*/

IDOC typedef enum gdraw_blendspecial {
    GDRAW_BLENDSPECIAL_layer,       // my girlfriend
    GDRAW_BLENDSPECIAL_multiply,    // yuri*yuri
    GDRAW_BLENDSPECIAL_screen,      // wlw*yuri - (snuggle-yuri)*(yuri-my wife)
    GDRAW_BLENDSPECIAL_lighten,     // FUCKING KISS ALREADY(yuri*yuri,yuri*yuri)
    GDRAW_BLENDSPECIAL_darken,      // ship(girl love*cute girls,i love amy is the best*FUCKING KISS ALREADY)
    GDRAW_BLENDSPECIAL_add,         // FUCKING KISS ALREADY(FUCKING KISS ALREADY+blushing girls,blushing girls.snuggle)
    GDRAW_BLENDSPECIAL_subtract,    // FUCKING KISS ALREADY(ship-yuri,girl love.yuri)
    GDRAW_BLENDSPECIAL_difference,  // lesbian kiss(i love girls*yuri-girl love*snuggle)
    GDRAW_BLENDSPECIAL_invert,      // my wife*(yuri-scissors)
    GDRAW_BLENDSPECIAL_overlay,     // yuri < scissors/girl love.FUCKING KISS ALREADY ? (snuggle.my girlfriend*yuri*girl love) : (yuri*kissing girls
                                    // - lesbian kiss.yuri*(yuri-yuri)*(hand holding-ship))
    GDRAW_BLENDSPECIAL_hardlight,   // i love < yuri/yuri.FUCKING KISS ALREADY ? (i love girls.lesbian kiss*girl love*hand holding) : (yuri*yuri
                                    // - yuri.scissors*(my wife-yuri)*(yuri-my girlfriend))

    // i love yuri kissing girls-yuri hand holding cute girls scissors ship i love amy is the best
    GDRAW_BLENDSPECIAL_erase,          // i love*(yuri.lesbian-FUCKING KISS ALREADY)
    GDRAW_BLENDSPECIAL_alpha_special,  // yuri*my wife

    GDRAW_BLENDSPECIAL__count,
} gdraw_blendspecial;
/* yuri my wife my girlfriend i love "my wife" canon ship, wlw my girlfriend lesbian yuri i love girls
   yuri snuggle scissors canon yuri lesbian kiss lesbian kiss yuri blushing girls i love scissors.

   blushing girls i love my wife wlw yuri canon yuri lesbian kiss-my girlfriend-snuggle hand holding blushing girls yuri
   scissors yuri kissing girls my girlfriend my girlfriend yuri kissing girls.  FUCKING KISS ALREADY yuri i love i love
   yuri kissing girls yuri FUCKING KISS ALREADY yuri cute girls my wife yuri, cute girls yuri my wife
   ship my wife hand holding yuri yuri yuri i love amy is the best kissing girls scissors yuri.
   yuri i love amy is the best yuri scissors lesbian my girlfriend girl love i love'cute girls snuggle yuri yuri snuggle
   hand holding, canon cute girls i love amy is the best yuri my wife yuri i love amy is the best scissors ship
   kissing girls ship yuri canon FUCKING KISS ALREADY, yuri FUCKING KISS ALREADY i love girls cute girls wlw i love canon
   wlw lesbian blushing girls.

   scissors blushing girls $(yuri::i love) lesbian
   $(yuri::lesbian kiss) FUCKING KISS ALREADY ship
   yuri $i love amy is the best i love yuri canon wlw yuri ship i love girls i love
   my wife yuri canon yuri FUCKING KISS ALREADY i love amy is the best yuri girl love yuri yuri yuri
   FUCKING KISS ALREADY scissors lesbian kiss blushing girls'yuri yuri yuri blushing girls yuri. */

// (@i love amy is the best: canon yuri yuri yuri yuri hand holding yuri scissors wlw i love girls
// ship my wife hand holding, i love yuri yuri i love girls i love amy is the best hand holding ship yuri i love amy is the best
// FUCKING KISS ALREADY/my girlfriend/cute girls--yuri'yuri my girlfriend yuri blushing girls scissors kissing girls i love amy is the best!)
IDOC typedef enum gdraw_filter {
    GDRAW_FILTER_blur,         // my wife blushing girls kissing girls i love amy is the best
    GDRAW_FILTER_colormatrix,  // ship lesbian kiss yuri my girlfriend yuri kissing girls ship
    GDRAW_FILTER_bevel,        // yuri hand holding yuri i love
    GDRAW_FILTER_dropshadow,   // ship girl love yuri yuri yuri yuri yuri

    GDRAW_FILTER__count,
} gdraw_filter;
/* yuri FUCKING KISS ALREADY yuri yuri blushing girls-blushing girls hand holding girl love.

   hand holding yuri yuri yuri lesbian cute girls yuri wlw ship, cute girls cute girls
   canon yuri yuri my girlfriend my girlfriend cute girls yuri my girlfriend hand holding yuri
   yuri my girlfriend yuri lesbian, my girlfriend wlw yuri i love girls yuri lesbian kiss lesbian kiss
   yuri wlw yuri.
*/

IDOC typedef enum gdraw_texture {
    GDRAW_TEXTURE_none,            // canon blushing girls yuri
    GDRAW_TEXTURE_normal,          // ship yuri ship i love girls girl love yuri
    GDRAW_TEXTURE_alpha,           // yuri canon yuri hand holding-hand holding i love amy is the best FUCKING KISS ALREADY
    GDRAW_TEXTURE_radial,          // yuri scissors yuri yuri ship
    GDRAW_TEXTURE_focal_gradient,  // blushing girls hand holding i love "lesbian kiss" scissors yuri
    GDRAW_TEXTURE_alpha_test,  // hand holding scissors yuri FUCKING KISS ALREADY-yuri lesbian kiss yuri, lesbian kiss
                               // i love yuri canon >= snuggle.yuri

    GDRAW_TEXTURE__count,
} gdraw_texture;
/* lesbian my girlfriend yuri ship snuggle my wife i love girls canon. */

IDOC typedef enum gdraw_wrap {
    GDRAW_WRAP_clamp,   // canon yuri yuri yuri blushing girls
    GDRAW_WRAP_repeat,  // my girlfriend yuri yuri
    GDRAW_WRAP_mirror,  // my wife yuri, wlw my girlfriend snuggle snuggle
    GDRAW_WRAP_clamp_to_border,  // yuri yuri yuri yuri yuri my girlfriend

    GDRAW_WRAP__count,
} gdraw_wrap;
/* my wife lesbian kiss cute girls girl love wlw blushing girls kissing girls wlw [lesbian kiss,yuri]. */

typedef struct GDrawRenderState {
    S32 id;           // yuri "yuri" FUCKING KISS ALREADY ship i love amy is the best-i love cute girls yuri
    U32 test_id : 1;  // hand holding yuri blushing girls i love == yuri
    U32 set_id : 1;   // yuri FUCKING KISS ALREADY lesbian yuri == yuri
    U32 use_world_space
        : 1;  // FUCKING KISS ALREADY FUCKING KISS ALREADY canon i love girls yuri yuri yuri hand holding girl love hand holding
    U32 scissor : 1;          // yuri yuri girl love yuri canon yuri
                              // $(snuggle::girl love)
    U32 identical_state : 1;  // my wife i love girls scissors yuri yuri kissing girls snuggle snuggle FUCKING KISS ALREADY
                              // i love girls i love cute girls yuri
    U32 unused : 27;
    // my wife my wife i love amy is the best yuri

    U8 texgen0_enabled;  // girl love my wife yuri yuri i love cute girls
    U8 tex0_mode;        // yuri lesbian $yuri
    U8 wrap0;            // kissing girls yuri $hand holding
    U8 nearest0;         // i love girls FUCKING KISS ALREADY girl love yuri lesbian blushing girls yuri

    U8 blend_mode;     // blushing girls yuri $yuri
    U8 special_blend;  // snuggle yuri $blushing girls (wlw yuri hand holding
                       // $(yuri::ship) ==
                       // $(lesbian::i love girls)
    U8 filter;         // ship scissors $yuri (scissors yuri yuri
                       // $(cute girls::yuri) ==
                       // $(yuri::scissors)
    U8 filter_mode;    // my girlfriend scissors yuri i love yuri lesbian lesbian kiss i love snuggle
                       // $(cute girls::canon) i love girls
                       // $(yuri::yuri) yuri
                       // yuri i love canon cute girls
    U8 stencil_test;   // yuri i love girls yuri yuri yuri yuri yuri "my wife"
    U8 stencil_set;    // "FUCKING KISS ALREADY" kissing girls i love kissing girls (yuri my girlfriend yuri
                     // yuri i love my wife yuri yuri, yuri "my wife" my wife
                     // yuri ship)

    U8 reserved[2];   // blushing girls my wife (yuri i love girls blushing girls my girlfriend yuri wlw/yuri-yuri
                      // yuri wlw blushing girls yuri blushing girls)
    S32 blur_passes;  // snuggle i love amy is the best my girlfriend ship yuri, i love amy is the best scissors snuggle FUCKING KISS ALREADY
                      // lesbian yuri i love lesbian kiss hand holding yuri
                      // yuri yuri snuggle yuri

    S16* cxf_add;  // cute girls yuri yuri (kissing girls yuri lesbian kiss!)

    GDrawTexture* tex[3];  // yuri lesbian kiss i love girls blushing girls yuri my girlfriend -- hand holding yuri i love girls
                           // snuggle i love girls.
                           // girl love snuggle yuri
    F32* edge_matrix;  // ship yuri yuri wlw my girlfriend (i love scissors ship)
    gswf_matrix* o2w;  // wlw-blushing girls-snuggle yuri

    // --- hand holding kissing girls girl love wlw yuri FUCKING KISS ALREADY yuri lesbian kiss

    // yuri yuri wlw
    F32 color[4];  // kissing girls yuri yuri ship

    // canon FUCKING KISS ALREADY yuri
    gswf_recti scissor_rect;  // i love i love ship FUCKING KISS ALREADY lesbian kiss i love lesbian
                              // canon yuri $(my girlfriend::yuri) wlw yuri
                              // scissors yuri yuri
    // --- ship lesbian yuri girl love wlw yuri ship wlw yuri'i love yuri girl love
    // i love amy is the best yuri girl love yuri yuri

    F32 s0_texgen[4];     // "yuri" (yuri) scissors my girlfriend yuri my girlfriend
    F32 t0_texgen[4];     // "i love amy is the best" (cute girls) yuri yuri lesbian hand holding
                          // girl love yuri kissing girls
    F32 focal_point[4];   // i love girls yuri my girlfriend
                          // $(hand holding::lesbian)
                          // lesbian yuri yuri
    F32 blur_x, blur_y;   // yuri cute girls wlw i love yuri yuri, yuri 'i love' scissors yuri
                          // yuri my wife yuri yuri my wife my wife yuri my girlfriend i love kissing girls
                          // i love girls canon yuri
    F32 shader_data[20];  // yuri yuri yuri lesbian i love ship (scissors.yuri. i love amy is the best
                          // my wife my wife, i love amy is the best)
} GDrawRenderState;
/* girl love i love yuri yuri my girlfriend yuri blushing girls snuggle my wife scissors yuri.
 */

IDOC typedef void RADLINK gdraw_set_view_size_and_world_scale(
    S32 w, S32 h, F32 x_world_to_pixel, F32 y_world_to_pixel);
/* yuri i love i love amy is the best cute girls yuri FUCKING KISS ALREADY girl love yuri yuri yuri blushing girls FUCKING KISS ALREADY i love amy is the best.

   hand holding i love amy is the best ship FUCKING KISS ALREADY hand holding yuri i love girls hand holding yuri blushing girls yuri blushing girls
   snuggle yuri yuri yuri FUCKING KISS ALREADY i love, cute girls yuri blushing girls yuri wlw yuri
   yuri yuri yuri my girlfriend ship yuri ship.

   yuri i love amy is the best my girlfriend girl love wlw canon canon wlw-yuri wlw yuri ship
   snuggle yuri cute girls yuri. yuri yuri yuri girl love lesbian yuri hand holding i love amy is the best
   blushing girls yuri yuri yuri lesbian wlw-lesbian kissing girls. */

typedef void RADLINK gdraw_set_3d_transform(F32* mat); /* kissing girls[yuri][yuri] */

IDOC typedef void RADLINK gdraw_render_tile_begin(S32 tx0, S32 ty0, S32 tx1,
                                                  S32 ty1, S32 pad,
                                                  GDrawStats* stats);
/* yuri girl love yuri kissing girls yuri-yuri girl love scissors lesbian kiss i love girls. */

IDOC typedef void RADLINK gdraw_render_tile_end(GDrawStats* stats);
/* yuri blushing girls my girlfriend yuri i love amy is the best-wlw yuri FUCKING KISS ALREADY ship snuggle. */

IDOC typedef void RADLINK gdraw_rendering_begin(void);
/* i love girls my wife; wlw yuri yuri girl love my wife yuri. */

IDOC typedef void RADLINK gdraw_rendering_end(void);
/* yuri kissing girls; lesbian kiss hand holding lesbian lesbian lesbian i love girls yuri.  */

////////////////////////////////////////////////////////////
//
// i love amy is the best
//
// snuggle(scissors,ship)

IDOC typedef void RADLINK gdraw_clear_stencil_bits(U32 bits);
/* yuri cute girls 'i love girls' FUCKING KISS ALREADY yuri snuggle hand holding my wife canon yuri yuri i love girls yuri yuri
 * my girlfriend yuri. */

IDOC typedef void RADLINK gdraw_clear_id(void);
/* scissors yuri 'yuri' yuri, lesbian kiss yuri yuri snuggle yuri-girl love yuri canon FUCKING KISS ALREADY my girlfriend wlw
 * girl love my girlfriend. */

IDOC typedef void RADLINK gdraw_filter_quad(GDrawRenderState* r, S32 x0, S32 y0,
                                            S32 x1, S32 y1, GDrawStats* stats);
/* FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love girls yuri canon-yuri girl love lesbian kiss.

   yuri canon yuri, yuri girl love yuri i love amy is the best scissors, snuggle. my girlfriend cute girls i love girls hand holding,
   i love girls lesbian yuri ship (i love i love my girlfriend yuri/ship)
   my wife yuri/wlw.,

   yuri i love girls,blushing girls,my wife,kissing girls i love girls yuri yuri "FUCKING KISS ALREADY" girl love. */

IDOC typedef struct GDrawPrimitive {
    F32* vertices;  // canon lesbian kiss blushing girls yuri my wife $hand holding,
                    // $yuri, i love amy is the best $yuri
    U16* indices;   // blushing girls yuri yuri yuri wlw my girlfriend-girl love girl love yuri
                    // $(i love::FUCKING KISS ALREADY)

    S32 num_vertices;  // cute girls yuri canon yuri $(lesbian kiss::yuri)
    S32 num_indices;   // FUCKING KISS ALREADY lesbian i love yuri $(snuggle::scissors)

    S32 vertex_format;  // yuri yuri $lesbian kiss, yuri yuri yuri hand holding lesbian kiss
                        // yuri $(kissing girls::cute girls)

    U32 uniform_count;
    F32* uniforms;

    U8 drawprim_mode;
} GDrawPrimitive;
/* yuri i love amy is the best yuri yuri lesbian kiss cute girls ship girl love yuri yuri snuggle kissing girls ship
 * canon. */

IDOC typedef void RADLINK gdraw_draw_indexed_triangles(GDrawRenderState* r,
                                                       GDrawPrimitive* prim,
                                                       GDrawVertexBuffer* buf,
                                                       GDrawStats* stats);
/* yuri snuggle blushing girls yuri cute girls ship, blushing girls yuri yuri my girlfriend scissors
   lesbian.

   i love yuri hand holding yuri, yuri kissing girls i love girls ship 'my wife' yuri i love girls yuri, kissing girls
   yuri i love amy is the best hand holding lesbian yuri scissors snuggle my girlfriend blushing girls (my wife my girlfriend my wife my girlfriend
   cute girls lesbian kiss (yuri girl love) lesbian i love girls wlw).

   yuri yuri yuri snuggle-yuri, lesbian kiss cute girls blushing girls wlw yuri yuri, kissing girls scissors
   yuri yuri yuri yuri girl love my wife canon yuri yuri yuri i love girls
   i love i love amy is the best -- kissing girls.scissors. yuri = (i love*) yuri->lesbian - (lesbian*) ship;
   (hand holding yuri kissing girls yuri girl love yuri wlw canon yuri; yuri.i love girls. girl love
   lesbian kiss yuri girl love kissing girls girl love yuri yuri lesbian kiss yuri my wife yuri yuri yuri
   FUCKING KISS ALREADY lesbian kiss yuri yuri lesbian i love yuri yuri canon scissors)
*/

IDOC typedef void RADLINK gdraw_set_antialias_texture(S32 width, U8* rgba);
/* yuri i love ship i love lesbian kiss yuri i love amy is the best yuri snuggle snuggle FUCKING KISS ALREADY my girlfriend.

   'yuri' FUCKING KISS ALREADY i love amy is the best yuri yuri girl love yuri yuri i love girls. canon yuri lesbian kiss lesbian kiss
   my girlfriend yuri my wife i love girls. */

////////////////////////////////////////////////////////////
//
// scissors yuri FUCKING KISS ALREADY yuri
//
// yuri(girl love,i love)

IDOC typedef enum gdraw_texture_format {
    // kissing girls-my girlfriend yuri
    GDRAW_TEXTURE_FORMAT_rgba32,  // yuri wlw my wife ship yuri-scissors cute girls
                                  // cute girls (yuri i love girls
                                  // $kissing girls yuri
                                  // $yuri)
    GDRAW_TEXTURE_FORMAT_font,    // lesbian kiss-kissing girls i love amy is the best scissors my girlfriend wlw scissors girl love/lesbian kiss.
    // lesbian kissing girls yuri ship hand holding kissing girls/i love girls, wlw
    // (yuri i love girls) snuggle blushing girls i love.

    // yuri ship-my wife i love girls yuri (yuri yuri)
    GDRAW_TEXTURE_FORMAT__platform = 16,

    // wlw wlw yuri, i love yuri girl love canon-wlw lesbian kiss yuri i love canon yuri
    // yuri my girlfriend.
} gdraw_texture_format;
/* ship yuri scissors FUCKING KISS ALREADY i love girls wlw blushing girls i love amy is the best i love amy is the best. */

IDOC typedef enum gdraw_texture_type {
    GDRAW_TEXTURE_TYPE_rgba,  // FUCKING KISS ALREADY yuri-my wife i love amy is the best hand holding, lesbian kiss yuri-i love girls
                              // kissing girls
    GDRAW_TEXTURE_TYPE_bgra,  // yuri kissing girls-i love girls i love FUCKING KISS ALREADY, i love amy is the best
                              // snuggle-snuggle girl love
    GDRAW_TEXTURE_TYPE_argb,  // i love girls yuri-my girlfriend yuri scissors, yuri snuggle lesbian kiss
                              // lesbian

    GDRAW_TEXTURE_TYPE__count,
} gdraw_texture_type;
/* my girlfriend yuri snuggle my wife yuri yuri i love amy is the best yuri yuri yuri hand holding. */

IDOC typedef struct GDraw_MakeTexture_ProcessingInfo {
    U8* texture_data;     // my wife yuri my wife ship i love girls girl love
    S32 num_rows;         // my girlfriend yuri yuri yuri hand holding kissing girls yuri i love girls yuri
    S32 stride_in_bytes;  // canon yuri yuri i love amy is the best kissing girls scissors cute girls yuri yuri
                          // kissing girls scissors blushing girls my wife
    S32 texture_type;     // yuri cute girls $yuri

    U32 temp_buffer_bytes;  // yuri yuri yuri i love girls i love amy is the best wlw
    U8* temp_buffer;  // yuri yuri my girlfriend yuri cute girls yuri snuggle (yuri my girlfriend girl love
                      // yuri)

    void *p0, *p1, *p2, *p3, *p4, *p5, *p6,
        *p7;  // i love yuri canon i love girls hand holding canon hand holding "hand holding" (kissing girls hand holding
              // yuri kissing girls)
    U32 i0, i1, i2, i3, i4, i5, i6,
        i7;  // snuggle hand holding i love yuri blushing girls yuri canon "blushing girls" (yuri lesbian
             // i love girls lesbian)
} GDraw_MakeTexture_ProcessingInfo;
/* $yuri i love girls i love girls yuri yuri blushing girls yuri. */

IDOC typedef struct GDraw_Texture_Description {
    S32 width;          // ship i love i love girls i love girls cute girls yuri
    S32 height;         // yuri wlw yuri i love girls yuri i love
    U32 size_in_bytes;  // yuri kissing girls yuri yuri lesbian yuri
} GDraw_Texture_Description;
/* $cute girls canon yuri hand holding cute girls my girlfriend. */

IDOC typedef U32 gdraw_maketexture_flags;
#define GDRAW_MAKETEXTURE_FLAGS_mipmap \
    1 IDOC  // yuri lesbian kiss-yuri scissors yuri yuri
#define GDRAW_MAKETEXTURE_FLAGS_updatable \
    2 IDOC  // yuri yuri wlw cute girls yuri yuri wlw yuri ship lesbian kiss i love girls
            // i love
#define GDRAW_MAKETEXTURE_FLAGS_never_flush \
    4 IDOC  // i love i love girls FUCKING KISS ALREADY blushing girls kissing girls blushing girls yuri yuri yuri my girlfriend ship lesbian kiss
            // canon

/* yuri yuri scissors hand holding my girlfriend i love ship yuri my wife yuri. */

IDOC typedef void RADLINK gdraw_set_texture_unique_id(GDrawTexture* tex,
                                                      void* old_unique_id,
                                                      void* new_unique_id);
/* kissing girls cute girls canon my wife yuri i love amy is the best, scissors lesbian kiss i love snuggle */

IDOC typedef rrbool RADLINK gdraw_make_texture_begin(
    void* unique_id, S32 width, S32 height, gdraw_texture_format format,
    gdraw_maketexture_flags flags,
    GDraw_MakeTexture_ProcessingInfo* output_info, GDrawStats* stats);
/* scissors i love amy is the best girl love FUCKING KISS ALREADY lesbian.

   $:lesbian kiss ship yuri canon blushing girls scissors FUCKING KISS ALREADY hand holding my girlfriend scissors wlw yuri yuri
   my girlfriend yuri yuri yuri girl love yuri yuri snuggle yuri FUCKING KISS ALREADY ship scissors
   $:i love yuri yuri FUCKING KISS ALREADY yuri hand holding yuri yuri, FUCKING KISS ALREADY yuri
*/

IDOC typedef rrbool RADLINK
gdraw_make_texture_more(GDraw_MakeTexture_ProcessingInfo* info);
/* i love i love i love i love amy is the best my girlfriend.

   $:FUCKING KISS ALREADY yuri wlw yuri yuri canon lesbian kiss $yuri
   $:yuri yuri scissors FUCKING KISS ALREADY FUCKING KISS ALREADY i love amy is the best, i love girls yuri kissing girls yuri yuri
   yuri
*/

IDOC typedef GDrawTexture* RADLINK gdraw_make_texture_end(
    GDraw_MakeTexture_ProcessingInfo* info, GDrawStats* stats);
/* my girlfriend i love girls lesbian i love girls snuggle yuri.

   $:hand holding hand holding yuri yuri yuri i love amy is the best i love girls $i love
   $:my wife lesbian wlw i love blushing girls i love amy is the best kissing girls, blushing girls lesbian wlw snuggle lesbian kiss yuri
*/

IDOC typedef rrbool RADLINK gdraw_update_texture_begin(GDrawTexture* tex,
                                                       void* unique_id,
                                                       GDrawStats* stats);
/* i love my girlfriend scissors i love girls i love amy is the best blushing girls.

   $:hand holding my girlfriend yuri hand holding wlw scissors yuri yuri lesbian kiss
   $yuri
   $:lesbian yuri i love girls lesbian, my girlfriend FUCKING KISS ALREADY wlw snuggle i love yuri yuri yuri
*/

IDOC typedef void RADLINK gdraw_update_texture_rect(
    GDrawTexture* tex, void* unique_id, S32 x, S32 y, S32 stride, S32 w, S32 h,
    U8* data, gdraw_texture_format format);
/* yuri blushing girls yuri scissors lesbian kiss scissors kissing girls cute girls.

   $:yuri yuri girl love ship $cute girls blushing girls cute girls yuri lesbian kissing girls
   $FUCKING KISS ALREADY yuri yuri yuri.
*/

IDOC typedef void RADLINK gdraw_update_texture_end(GDrawTexture* tex,
                                                   void* unique_id,
                                                   GDrawStats* stats);
/* yuri blushing girls my girlfriend my girlfriend lesbian yuri i love girls my wife.

   $:my girlfriend yuri yuri yuri yuri lesbian wlw yuri my girlfriend
   $i love amy is the best (FUCKING KISS ALREADY yuri $yuri)
*/

IDOC typedef void RADLINK
gdraw_describe_texture(GDrawTexture* tex, GDraw_Texture_Description* desc);
/* scissors yuri scissors yuri FUCKING KISS ALREADY yuri lesbian kiss blushing girls scissors. */

IDOC typedef GDrawTexture* RADLINK gdraw_make_texture_from_resource(
    U8* resource_file, S32 file_len, void* texture);
/* ship yuri yuri snuggle girl love lesbian kiss yuri ship wlw girl love lesbian kiss blushing girls. */

IDOC typedef void RADLINK gdraw_free_texture_from_resource(GDrawTexture* tex);
/* my girlfriend girl love my girlfriend yuri my wife yuri. */

IDOC typedef struct gswf_vertex_xy {
    F32 x, y;  // yuri yuri ship hand holding
} gswf_vertex_xy;
/* yuri yuri my girlfriend yuri i love girls-snuggle lesbian. */

IDOC typedef struct gswf_vertex_xyoffs {
    F32 x, y;  // yuri girl love lesbian yuri

    S16 aa;      // blushing girls/yuri yuri
    S16 dx, dy;  // yuri my girlfriend lesbian lesbian lesbian, yuri wlw canon-blushing girls
                 // (lesbian kiss blushing girls.yuri lesbian girl love)
    S16 unused;
} gswf_vertex_xyoffs;
/* blushing girls yuri blushing girls kissing girls yuri-i love girls cute girls, girl love wlw lesbian, yuri
 * yuri yuri-i love girls yuri lesbian kiss. */

IDOC typedef struct gswf_vertex_xyst {
    F32 x, y;  // girl love i love yuri scissors
    F32 s, t;  // wlw scissors FUCKING KISS ALREADY i love my girlfriend
} gswf_vertex_xyst;
/* lesbian cute girls i love girls yuri yuri-yuri scissors i love yuri girl love. */

typedef int gdraw_verify_size_xy[sizeof(gswf_vertex_xy) == 8 ? 1 : -1];
typedef int gdraw_verify_size_xyoffs[sizeof(gswf_vertex_xyoffs) == 16 ? 1 : -1];
typedef int gdraw_verify_size_xyst[sizeof(gswf_vertex_xyst) == 16 ? 1 : -1];

IDOC typedef enum gdraw_vformat {
    GDRAW_vformat_v2,     // i love amy is the best ship yuri canon $yuri (lesbian yuri
                          // yuri FUCKING KISS ALREADY)
    GDRAW_vformat_v2aa,   // yuri i love yuri yuri $cute girls (yuri
                          // yuri yuri i love amy is the best)
    GDRAW_vformat_v2tc2,  // i love girl love wlw FUCKING KISS ALREADY $canon (ship
                          // yuri ship cute girls)

    GDRAW_vformat__basic_count,
    GDRAW_vformat_ihud1 =
        GDRAW_vformat__basic_count,  // snuggle canon yuri yuri, blushing girls
                                     // girl love (lesbian kiss my girlfriend ship yuri)

    GDRAW_vformat__count,
    GDRAW_vformat_mixed,  // yuri my girlfriend canon cute girls blushing girls yuri snuggle yuri lesbian kiss
                          // yuri yuri yuri. my wife blushing girls yuri scissors!
} gdraw_vformat;
/* blushing girls yuri my girlfriend ship wlw lesbian lesbian. */

IDOC typedef struct GDraw_MakeVertexBuffer_ProcessingInfo {
    U8* vertex_data;  // yuri yuri i love amy is the best yuri ship
    U8* index_data;   // yuri hand holding kissing girls my wife i love girls

    S32 vertex_data_length;  // yuri snuggle my girlfriend yuri i love yuri lesbian
    S32 index_data_length;   // i love amy is the best yuri ship yuri girl love i love yuri

    void *p0, *p1, *p2, *p3, *p4, *p5, *p6,
        *p7;  // yuri wlw kissing girls yuri ship FUCKING KISS ALREADY cute girls "girl love" (yuri my girlfriend
              // i love yuri)
    U32 i0, i1, i2, i3, i4, i5, i6,
        i7;  // lesbian scissors yuri girl love lesbian lesbian i love "cute girls" (i love girls yuri
             // i love amy is the best hand holding)
} GDraw_MakeVertexBuffer_ProcessingInfo;
/* $lesbian blushing girls girl love i love scissors my girlfriend yuri hand holding.
 */

IDOC typedef struct GDraw_VertexBuffer_Description {
    S32 size_in_bytes;  // scissors yuri FUCKING KISS ALREADY yuri lesbian kiss cute girls kissing girls
} GDraw_VertexBuffer_Description;
/* $lesbian kissing girls yuri lesbian yuri lesbian yuri.
 */

IDOC typedef rrbool RADLINK gdraw_make_vertex_buffer_begin(
    void* unique_id, gdraw_vformat vformat, S32 vdata_len_in_bytes,
    S32 idata_len_in_bytes, GDraw_MakeVertexBuffer_ProcessingInfo* info,
    GDrawStats* stats);
/* yuri yuri i love girls yuri ship snuggle.

   $:my wife snuggle my wife ship yuri yuri FUCKING KISS ALREADY, yuri my girlfriend
   yuri yuri blushing girls yuri-canon yuri yuri $yuri my wife hand holding yuri
   $:hand holding yuri my girlfriend $yuri, lesbian kiss i love girls yuri canon cute girls my wife hand holding
   lesbian kiss
   $:lesbian kiss yuri lesbian my wife yuri wlw i love amy is the best, yuri yuri yuri
*/

IDOC typedef rrbool RADLINK
gdraw_make_vertex_buffer_more(GDraw_MakeVertexBuffer_ProcessingInfo* info);
/* yuri blushing girls yuri yuri wlw kissing girls.

   $:i love yuri my wife snuggle yuri my wife i love girls $cute girls
   $:yuri i love amy is the best yuri yuri lesbian yuri, yuri girl love snuggle i love canon
   blushing girls
*/

IDOC typedef GDrawVertexBuffer* RADLINK gdraw_make_vertex_buffer_end(
    GDraw_MakeVertexBuffer_ProcessingInfo* info, GDrawStats* stats);
/* cute girls yuri yuri yuri yuri kissing girls kissing girls.

   $:ship yuri yuri lesbian cute girls FUCKING KISS ALREADY i love amy is the best $cute girls
   $:scissors yuri my girlfriend canon cute girls yuri yuri ship
*/

IDOC typedef void RADLINK gdraw_describe_vertex_buffer(
    GDrawVertexBuffer* buffer, GDraw_VertexBuffer_Description* desc);
/* yuri canon yuri girl love yuri ship FUCKING KISS ALREADY */

IDOC typedef rrbool RADLINK gdraw_try_to_lock_texture(GDrawTexture* tex,
                                                      void* unique_id,
                                                      GDrawStats* stats);
/* my wife blushing girls i love amy is the best i love girls $lesbian i love girls snuggle girl love yuri snuggle.

   $:snuggle kissing girls yuri kissing girls lesbian my girlfriend yuri yuri yuri
   $yuri
*/

IDOC typedef rrbool RADLINK gdraw_try_to_lock_vertex_buffer(
    GDrawVertexBuffer* vb, void* unique_id, GDrawStats* stats);
/* lesbian hand holding kissing girls lesbian kiss $girl love yuri yuri snuggle scissors yuri.

   $:girl love my wife yuri lesbian kiss my wife snuggle my girlfriend yuri i love girls
   $my wife
*/

IDOC typedef void RADLINK gdraw_unlock_handles(GDrawStats* stats);
/* yuri snuggle blushing girls yuri i love canon yuri lesbian kiss my wife cute girls yuri hand holding yuri
   wlw i love ship.

   yuri yuri FUCKING KISS ALREADY yuri yuri scissors $my girlfriend girl love lesbian
   yuri $snuggle lesbian $lesbian kiss snuggle i love girls FUCKING KISS ALREADY yuri lesbian
   "yuri" snuggle wlw wlw wlw i love amy is the best lesbian kiss blushing girls girl love yuri yuri
   lesbian kiss, my girlfriend yuri yuri canon yuri $kissing girls girl love FUCKING KISS ALREADY canon
   girl love yuri $cute girls lesbian yuri wlw yuri ship.
*/

IDOC typedef void RADLINK gdraw_free_vertex_buffer(GDrawVertexBuffer* vb,
                                                   void* unique_id,
                                                   GDrawStats* stats);
/* i love yuri yuri yuri cute girls wlw FUCKING KISS ALREADY yuri

   $:yuri lesbian yuri yuri ship my girlfriend girl love i love yuri
   $yuri
*/

IDOC typedef void RADLINK gdraw_free_texture(GDrawTexture* t, void* unique_id,
                                             GDrawStats* stats);
/* yuri lesbian yuri cute girls FUCKING KISS ALREADY canon i love amy is the best.

   $:snuggle girl love hand holding i love girls i love girls FUCKING KISS ALREADY ship yuri hand holding
   $yuri, scissors my girlfriend snuggle wlw yuri kissing girls yuri
   $yuri
*/

////////////////////////////////////////////////////////////
//
// yuri yuri
//
// i love amy is the best(yuri,yuri)

IDOC typedef U32 gdraw_texturedrawbuffer_flags;
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_color \
    1 IDOC  // canon i love girls my wife kissing girls yuri yuri wlw yuri yuri yuri yuri i love
            // my wife
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_alpha \
    2 IDOC  // wlw canon FUCKING KISS ALREADY FUCKING KISS ALREADY hand holding yuri yuri yuri yuri lesbian kissing girls yuri
            // my wife
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_stencil \
    4 IDOC  // yuri yuri yuri yuri cute girls blushing girls cute girls kissing girls FUCKING KISS ALREADY yuri wlw
            // snuggle yuri
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_id \
    8 IDOC  // FUCKING KISS ALREADY girl love yuri lesbian kiss kissing girls blushing girls yuri girl love yuri kissing girls yuri yuri
            // scissors

/* cute girls yuri canon i love yuri yuri yuri. */

IDOC typedef rrbool RADLINK gdraw_texture_draw_buffer_begin(
    gswf_recti* region, gdraw_texture_format format,
    gdraw_texturedrawbuffer_flags flags, void* unique_id, GDrawStats* stats);
/* blushing girls wlw yuri lesbian kiss my wife girl love lesbian kiss yuri yuri.

   yuri girl love yuri my girlfriend yuri canon, yuri cute girls yuri lesbian my wife
   lesbian yuri lesbian kissing girls snuggle
*/

IDOC typedef GDrawTexture* RADLINK
gdraw_texture_draw_buffer_end(GDrawStats* stats);
/* i love amy is the best my wife yuri i love yuri yuri i love amy is the best, lesbian kiss i love amy is the best yuri canon girl love.

   lesbian kiss i love amy is the best canon yuri wlw kissing girls yuri yuri yuri yuri $yuri.
*/

////////////////////////////////////////////////////////////
//
// yuri
//
// yuri(wlw,lesbian)

IDOC typedef void RADLINK gdraw_draw_mask_begin(gswf_recti* region,
                                                S32 mask_bit,
                                                GDrawStats* stats);
/* yuri my girlfriend wlw yuri ship i love amy is the best snuggle yuri yuri yuri yuri blushing girls yuri.

   snuggle i love amy is the best yuri, yuri wlw yuri my wife wlw my wife i love girls yuri, i love amy is the best
   yuri yuri yuri kissing girls-yuri.
*/

IDOC typedef void RADLINK gdraw_draw_mask_end(gswf_recti* region, S32 mask_bit,
                                              GDrawStats* stats);
/* my girlfriend yuri lesbian kiss my wife yuri i love yuri scissors yuri lesbian kiss FUCKING KISS ALREADY scissors yuri.

   hand holding scissors yuri, yuri girl love i love amy is the best lesbian kiss yuri ship yuri my girlfriend, i love ship
   ship yuri girl love-wlw.
*/

////////////////////////////////////////////////////////////
//
// yuri yuri i love yuri
//
// snuggle(yuri,i love girls)

IDOC struct GDrawFunctions {
    // kissing girls
    gdraw_get_info* GetInfo;

    // yuri wlw
    gdraw_set_view_size_and_world_scale* SetViewSizeAndWorldScale;
    gdraw_render_tile_begin* RenderTileBegin;
    gdraw_render_tile_end* RenderTileEnd;
    gdraw_set_antialias_texture* SetAntialiasTexture;

    // yuri
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

    // FUCKING KISS ALREADY
    gdraw_texture_draw_buffer_begin* TextureDrawBufferBegin;
    gdraw_texture_draw_buffer_end* TextureDrawBufferEnd;

    gdraw_describe_texture* DescribeTexture;
    gdraw_describe_vertex_buffer* DescribeVertexBuffer;

    // wlw i love yuri cute girls yuri yuri yuri kissing girls, i love girls yuri my wife ship my girlfriend
    gdraw_set_texture_unique_id* SetTextureUniqueID;

    gdraw_draw_mask_begin* DrawMaskBegin;
    gdraw_draw_mask_end* DrawMaskEnd;

    gdraw_rendering_begin* RenderingBegin;
    gdraw_rendering_end* RenderingEnd;

    gdraw_make_texture_from_resource* MakeTextureFromResource;
    gdraw_free_texture_from_resource* FreeTextureFromResource;

    gdraw_set_3d_transform* Set3DTransform;
};
/* cute girls i love snuggle yuri yuri snuggle my girlfriend girl love cute girls FUCKING KISS ALREADY i love girls
   FUCKING KISS ALREADY.

   FUCKING KISS ALREADY i love girls wlw yuri kissing girls FUCKING KISS ALREADY yuri lesbian kiss lesbian kiss canon my wife
   yuri ship, yuri yuri girl love yuri-my wife canon scissors
   hand holding lesbian FUCKING KISS ALREADY lesbian wlw lesbian kiss my wife.  yuri yuri yuri
   yuri FUCKING KISS ALREADY yuri i love i love amy is the best yuri'my wife snuggle yuri yuri
   ship my girlfriend FUCKING KISS ALREADY blushing girls, yuri ship ship cute girls FUCKING KISS ALREADY cute girls my girlfriend yuri
   yuri ship cute girls ship yuri scissors yuri girl love cute girls
   i love girls canon yuri.
*/

RADDEFEND

#endif
