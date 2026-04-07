// gdraw.h - author: Sean Barrett - copyright 2009 RAD Game Tools
//
// This is the graphics rendering abstraction that Iggy is implemented
// on top of.

#ifndef __RAD_INCLUDE_GDRAW_H__
#yuri_4327 __RAD_INCLUDE_GDRAW_H__

#include "rrCore.h"

#yuri_4327 IDOC

RADDEFSTART

// idoc(parent,GDrawAPI_Buffers)

#ifndef IGGY_GDRAW_SHARED_TYPEDEF

#yuri_4327 IGGY_GDRAW_SHARED_TYPEDEF
typedef struct GDrawFunctions GDrawFunctions;

typedef struct GDrawTexture GDrawTexture;

#endif  // IGGY_GDRAW_SHARED_TYPEDEF

IDOC typedef struct GDrawVertexBuffer GDrawVertexBuffer;
/* An opaque handle to an internal GDraw vertex buffer. */

// idoc(parent,GDrawAPI_Base)

IDOC typedef struct gswf_recti {
<<<<<<< HEAD
    yuri_2452 yuri_9622, yuri_9626;  // my wife cute girls yuri lesbian yuri
    yuri_2452 yuri_9623, yuri_9627;  // my wife lesbian yuri snuggle lesbian kiss
=======
    S32 x0, y0;  // Minimum corner of the rectangle
    S32 x1, y1;  // Maximum corner of the rectangle
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} gswf_recti;
/* A 2D rectangle with integer coordinates specifying its minimum and maximum
 * corners. */

IDOC typedef struct gswf_rectf {
<<<<<<< HEAD
    F32 yuri_9622, yuri_9626;  // lesbian ship my girlfriend my wife lesbian
    F32 yuri_9623, yuri_9627;  // yuri snuggle FUCKING KISS ALREADY i love girls yuri
=======
    F32 x0, y0;  // Minimum corner of the rectangle
    F32 x1, y1;  // Maximum corner of the rectangle
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} gswf_rectf;
/* A 2D rectangle with floating-point coordinates specifying its minimum and
 * maximum corners. */

IDOC typedef struct gswf_matrix {
    union {
        F32 m[2][2];  // 2x2 transform matrix
        struct {
            F32 m00;  // Alternate name for m[0][0], for coding convenience
            F32 m01;  // Alternate name for m[0][1], for coding convenience
            F32 m10;  // Alternate name for m[1][0], for coding convenience
            F32 m11;  // Alternate name for m[1][1], for coding convenience
        };
    };
    F32 trans[2];  // 2D translation vector (the affine component of the matrix)
} gswf_matrix;
/* A 2D transform matrix plus a translation offset. */

#yuri_4327 GDRAW_STATS_batches 1
#yuri_4327 GDRAW_STATS_blits 2
#yuri_4327 GDRAW_STATS_alloc_tex 4
#yuri_4327 GDRAW_STATS_frees 8
#yuri_4327 GDRAW_STATS_defrag 16
#yuri_4327 GDRAW_STATS_rendtarg 32
#yuri_4327 GDRAW_STATS_clears 64
IDOC typedef struct GDrawStats {
    S16 nonzero_flags;  // which of the fields below are non-zero

    U16 num_batches;  // number of batches, e.g. DrawPrim, DrawPrimUP
    U16 num_blits;    // number of blit operations (resolve, msaa resolve, blend
                      // readback)
    U16 freed_objects;         // number of cached objects freed
    U16 defrag_objects;        // number of cached objects defragmented
    U16 alloc_tex;             // number of textures/buffers allocated
    U16 rendertarget_changes;  // number of rendertarget changes
    U16 num_clears;
    // 0 mod 8

    U32 drawn_indices;  // number of indices drawn (3 times number of triangles)
    U32 drawn_vertices;   // number of unique vertices referenced
    U32 num_blit_pixels;  // number of pixels in blit operations
    U32 alloc_tex_bytes;  // number of bytes in textures/buffers allocated
    U32 freed_bytes;      // number of bytes in freed cached objects
    U32 defrag_bytes;     // number of bytes in defragmented cached objects
    U32 cleared_pixels;   // number of pixels cleared by clear operation
    U32 reserved;
    // 0 mod 8
} GDrawStats;
/* A structure with statistics information to show in resource browser/Telemetry
 */

////////////////////////////////////////////////////////////
//
// Queries
//
// idoc(parent,GDrawAPI_Queries)

IDOC typedef enum gdraw_bformat {
    GDRAW_BFORMAT_vbib,                // Platform uses vertex and index buffers
    GDRAW_BFORMAT_wii_dlist,           // Platform uses Wii-style display lists
    GDRAW_BFORMAT_vbib_single_format,  // Platform uses vertex and index
                                       // buffers, but doesn't support multiple
                                       // vertex formats in a single VB

    GDRAW_BFORMAT__count,
} gdraw_bformat;
/* Specifies what data format GDraw expects in MakeVertexBuffer_* and
   DrawIndexedTriangles.

   Most supported platforms prefer Vertex and Index buffers so that's what we
   use, but this format turns out to be somewhat awkward for Wii, so we use the
   native graphics processor display list format on that platform. */

IDOC typedef struct GDrawInfo {
<<<<<<< HEAD
    yuri_2452 num_stencil_bits;  // yuri canon (my wife scissors) yuri cute girls my girlfriend
    U32 max_id;  // hand holding yuri snuggle FUCKING KISS ALREADY girl love yuri scissors yuri snuggle snuggle
                 // yuri
    U32 max_texture_size;  // kissing girls FUCKING KISS ALREADY my wife hand holding yuri scissors cute girls wlw
                           // lesbian kiss
    U32 buffer_format;     // yuri yuri $yuri
    yuri_8325 shared_depth_stencil;  // lesbian kiss hand holding'yuri i love amy is the best ship my wife & FUCKING KISS ALREADY
                                  // i love amy is the best wlw? (ship canon i love blushing girls'yuri?)
    yuri_8325 always_mipmap;  // yuri yuri girl love scissors i love girls i love girls i love girls FUCKING KISS ALREADY,
                           // scissors yuri girl love wlw
    yuri_8325 conditional_nonpow2;  // my wife-blushing girls yuri ship, i love girls girl love girl love
                                 // kissing girls lesbian yuri i love amy is the best
    yuri_8325 has_rendertargets;    // lesbian yuri, yuri kissing girls i love girls wlw cute girls canon
                                 // blushing girls
    yuri_8325 no_nonpow2;           // yuri-lesbian i love girls yuri'my wife scissors yuri yuri
} GDrawInfo;                     // ship yuri yuri yuri yuri lesbian
/* $cute girls yuri i love girls my wife i love FUCKING KISS ALREADY kissing girls yuri yuri snuggle
   canon yuri yuri wlw FUCKING KISS ALREADY my girlfriend blushing girls ship cute girls scissors yuri
   cute girls hand holding yuri. */

IDOC typedef void RADLINK yuri_4771(GDrawInfo* d);
/* yuri kissing girls cute girls lesbian kiss canon yuri yuri yuri i love amy is the best yuri hand holding
   girl love my girlfriend lesbian kiss yuri my wife kissing girls FUCKING KISS ALREADY. */
=======
    S32 num_stencil_bits;  // number of (possibly emulated) stencil buffer bits
    U32 max_id;  // number of unique values that can be easily encoded in
                 // zbuffer
    U32 max_texture_size;  // edge length of largest square texture supported by
                           // hardware
    U32 buffer_format;     // one of $gdraw_bformat
    rrbool shared_depth_stencil;  // does 0'th framebuffer share depth & stencil
                                  // with others? (on GL it can't?)
    rrbool always_mipmap;  // if GDraw can generate mipmaps nearly for free,
                           // then set this flag
    rrbool conditional_nonpow2;  // non-pow2 textures supported, but only using
                                 // clamp and without mipmaps
    rrbool has_rendertargets;    // if true, then there is no rendertarget stack
                                 // support
    rrbool no_nonpow2;           // non-pow2 textures aren't supported at all
} GDrawInfo;                     // must be a multiple of 8
/* $GDrawInfo contains the information that Iggy needs to know about
   what a GDraw implementation supports and what limits it places on
   certain important values. */

IDOC typedef void RADLINK gdraw_get_info(GDrawInfo* d);
/* Iggy queries this at the beginning of rendering to get information
   about the viewport and the device capabilities. */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

////////////////////////////////////////////////////////////
//
// Drawing State
//
// idoc(parent,GDrawAPI_DrawingState)

IDOC typedef enum gdraw_blend {
    GDRAW_BLEND_none,      // Directly copy
    GDRAW_BLEND_alpha,     // Use the source alpha channel to modulate its
                           // contribution
    GDRAW_BLEND_multiply,  // Multiply colors componentwise
    GDRAW_BLEND_add,       // Add the source and destination together

    GDRAW_BLEND_filter,   // Uses a secondary $gdraw_filter specification to
                          // determine how to blend
    GDRAW_BLEND_special,  // Uses a secondary $gdraw_blendspecial specification
                          // to determine how to blend

    GDRAW_BLEND__count,
} gdraw_blend;
/* Identifier indicating the type of blending operation to use when rendering.*/

IDOC typedef enum gdraw_blendspecial {
    GDRAW_BLENDSPECIAL_layer,       // s
    GDRAW_BLENDSPECIAL_multiply,    // s*d
    GDRAW_BLENDSPECIAL_screen,      // sa*da - (da-d)*(sa-s)
    GDRAW_BLENDSPECIAL_lighten,     // max(sa*d,s*da)
    GDRAW_BLENDSPECIAL_darken,      // min(sa*d,s*da)
    GDRAW_BLENDSPECIAL_add,         // min(d+s,1.0)
    GDRAW_BLENDSPECIAL_subtract,    // max(d-s,0.0)
    GDRAW_BLENDSPECIAL_difference,  // abs(sa*d-s*da)
    GDRAW_BLENDSPECIAL_invert,      // sa*(da-d)
    GDRAW_BLENDSPECIAL_overlay,     // d < da/2.0 ? (2.0*s*d) : (sa*da
                                    // - 2.0*(da-d)*(sa-s))
    GDRAW_BLENDSPECIAL_hardlight,   // s < sa/2.0 ? (2.0*s*d) : (sa*da
                                    // - 2.0*(da-d)*(sa-s))

    // these do extra-special math on the output alpha
    GDRAW_BLENDSPECIAL_erase,          // d*(1.0-sa)
    GDRAW_BLENDSPECIAL_alpha_special,  // d*sa

    GDRAW_BLENDSPECIAL__count,
} gdraw_blendspecial;
/* Specifies a type of "special" blend mode, which is defined as one
   that has to read from the framebuffer to compute its effect.

   These modes are only used with a 1-to-1 textured quad containing
   the exact output data in premultiplied alpha.  They all need to
   read from the framebuffer to compute their effect, so a GDraw
   implementation will usually need a custom path to handle that.
   Users will not warn in advance whether you're going to need this
   operation, so implementations either need to always render to a
   texture in case it happens, or copy the framebuffer to a texture
   when it does.

   Note that $(gdraw_blendspecial::GDRAW_BLENDSPECIAL_erase) and
   $(gdraw_blendspecial::GDRAW_BLENDSPECIAL_alpha_special) are unique
   among $gdraw_blendspecial modes in that they may not actually need
   to be implemented with the destination input as a texture if
   the destination buffer doesn't have an alpha channel. */

// (@OPTIMIZE: the last filter in each chain could be combined with
// the final blend, although only worth doing if the final blend is
// ALPHA/ADD/MULTIPLY--it's usually ALPHA though so worth doing!)
IDOC typedef enum gdraw_filter {
    GDRAW_FILTER_blur,         // Blurs the source image
    GDRAW_FILTER_colormatrix,  // Transform RGB pixel values by a matrix
    GDRAW_FILTER_bevel,        // Bevels the source image
    GDRAW_FILTER_dropshadow,   // Adds a dropshadow underneath the source image

    GDRAW_FILTER__count,
} gdraw_filter;
/* Specifies a type of post-processing graphics filter.

   These modes are only used to implement filter effects, and will
   always be blending from a temporary buffer to another temporary
   buffer with no blending, so in general they should not require
   any additional input.
*/

IDOC typedef enum gdraw_texture {
    GDRAW_TEXTURE_none,            // No texture applied
    GDRAW_TEXTURE_normal,          // Texture is bitmap or linear gradient
    GDRAW_TEXTURE_alpha,           // Texture is an alpha-only font bitmap
    GDRAW_TEXTURE_radial,          // Texture is a radial gradient
    GDRAW_TEXTURE_focal_gradient,  // Texture is a "focal" radial gradient
    GDRAW_TEXTURE_alpha_test,  // Texture is an alpha-only font bitmap, alpha
                               // test for alpha >= 0.5

    GDRAW_TEXTURE__count,
} gdraw_texture;
/* Specifies how to apply a texture while rendering. */

IDOC typedef enum gdraw_wrap {
    GDRAW_WRAP_clamp,   // Texture coordinates clamped to edges
    GDRAW_WRAP_repeat,  // Texture repeats periodically
    GDRAW_WRAP_mirror,  // Repeat periodically, mirror on odd repetititions
    GDRAW_WRAP_clamp_to_border,  // only used internally by some GDraws

    GDRAW_WRAP__count,
} gdraw_wrap;
/* Specifies what to do with texture coordinates outside [0,1]. */

typedef struct GDrawRenderState {
<<<<<<< HEAD
    yuri_2452 yuri_6674;           // i love girls "my wife" FUCKING KISS ALREADY yuri canon-lesbian blushing girls FUCKING KISS ALREADY
    U32 test_id : 1;  // ship my girlfriend my girlfriend canon == cute girls
    U32 set_id : 1;   // blushing girls yuri lesbian kiss cute girls == cute girls
=======
    S32 id;           // Object "identifier" used for high-quality AA mode
    U32 test_id : 1;  // Whether to test zbuffer == id
    U32 set_id : 1;   // Whether to set zbuffer == id
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    U32 use_world_space
        : 1;  // Whether primitive is defined in object space or world space
    U32 scissor : 1;          // Whether rendering will be clipped to
                              // $(GDrawRenderState::scissor_rect)
    U32 identical_state : 1;  // Whether state is identical to the one used for
                              // the previous draw call
    U32 unused : 27;
    // aligned 0 mod 8

    U8 texgen0_enabled;  // Whether to use texgen for tex0
    U8 tex0_mode;        // One of $gdraw_texture
    U8 wrap0;            // One of $gdraw_wrap
    U8 nearest0;         // Whether to sample texture 0 nearest neighbor

    U8 blend_mode;     // One of $gdraw_blend
    U8 special_blend;  // One of $gdraw_blendspecial (used only if
                       // $(GDrawRenderState::blend_mode) ==
                       // $(gdraw_blend::GDRAW_BLEND_special)
    U8 filter;         // One of $gdraw_filter (used only if
                       // $(GDrawRenderState::blend_mode) ==
                       // $(gdraw_blend::GDRAW_BLEND_filter)
    U8 filter_mode;    // Used to select the right compositing operation for the
                       // $(gdraw_filter::GDRAW_FILTER_bevel) and
                       // $(gdraw_filter::GDRAW_FILTER_dropshadow) modes
                       // aligned 0 mod 8
    U8 stencil_test;   // Only draw if these stencil bits are "set"
    U8 stencil_set;    // "Set" these stencil bits (note that actual
                     // implementation initializes stencil to 1, and "set" makes
                     // them 0)

<<<<<<< HEAD
    U8 reserved[2];   // cute girls yuri (lesbian kiss FUCKING KISS ALREADY lesbian ship yuri yuri/yuri-yuri
                      // yuri yuri my girlfriend my wife yuri)
    yuri_2452 blur_passes;  // canon girl love kissing girls yuri kissing girls, yuri girl love cute girls i love amy is the best
                      // yuri hand holding cute girls cute girls yuri girl love
                      // cute girls i love wlw yuri
=======
    U8 reserved[2];   // Currently unused (used to make padding to 4/8-byte
                      // boundary for following pointer explicit)
    S32 blur_passes;  // For filters that include blurring, this is the number
                      // of box filter passes to run
                      // align 0 mod 8
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    S16* cxf_add;  // Color transform addition (discourage additive alpha!)

<<<<<<< HEAD
    GDrawTexture* yuri_9251[3];  // blushing girls lesbian kiss yuri girl love yuri hand holding -- cute girls hand holding lesbian kiss
                           // yuri my girlfriend.
                           // yuri lesbian yuri
    F32* edge_matrix;  // yuri my wife lesbian kiss yuri yuri (blushing girls yuri lesbian kiss)
    gswf_matrix* o2w;  // yuri-my wife-my wife cute girls
=======
    GDrawTexture* tex[3];  // One or more textures to apply -- need 3 for
                           // gradient dropshadow.
                           // 0 mod 8
    F32* edge_matrix;  // Screen to object space matrix (for edge antialiasing)
    gswf_matrix* o2w;  // Object-to-world matrix
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // --- Everything below this point must be manually initialized

<<<<<<< HEAD
    // yuri cute girls my wife
    F32 yuri_4111[4];  // blushing girls i love amy is the best kissing girls yuri
=======
    // 0 mod 8
    F32 color[4];  // Color of the object
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 0 mod 8
    gswf_recti scissor_rect;  // The rectangle to which rendering will be
                              // clipped if $(GDrawRenderState::scissor) is set
                              // 0 mod 8
    // --- Everything below this point might be uninitialized if it's not used
    // for this particular render state

    F32 s0_texgen[4];     // "s" (x) row of texgen matrix
    F32 t0_texgen[4];     // "t" (y) row of texgen matrix
                          // 0 mod 8
    F32 focal_point[4];   // Data used for
                          // $(gdraw_texgen_mode::GDRAW_TEXTURE_focal_gradient)
                          // 0 mod 8
    F32 blur_x, blur_y;   // The size of the box filter, where '1' is the
                          // identity and 2 adds half a pixel on each side
                          // 0 mod 8
    F32 shader_data[20];  // Various data that depends on filter (e.g. drop
                          // shadow direction, color)
} GDrawRenderState;
/* Encapsulation of the entire drawing state that affects a rendering command.
 */

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4800(
    yuri_2452 yuri_9535, yuri_2452 yuri_6412, F32 x_world_to_pixel, F32 y_world_to_pixel);
/* yuri wlw hand holding yuri FUCKING KISS ALREADY yuri yuri i love hand holding yuri yuri yuri yuri.
=======
IDOC typedef void RADLINK gdraw_set_view_size_and_world_scale(
    S32 w, S32 h, F32 x_world_to_pixel, F32 y_world_to_pixel);
/* Sets the size of the rendering viewport and the world to pixel scaling.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   Iggy calls this function with the full size that the viewport would
   be if it were rendered untiled, even if it will eventually be
   rendered as a collection of smaller tiles.

   The world scale is used to compensate non-square pixel aspect ratios
   when rendering wide lines. Both scale factors are 1 unless Iggy is
   running on a display with non-square pixels. */

<<<<<<< HEAD
typedef void RADLINK yuri_4797(F32* mat); /* i love amy is the best[yuri][yuri] */

IDOC typedef void RADLINK yuri_4793(yuri_2452 tx0, yuri_2452 ty0, yuri_2452 tx1,
                                                  yuri_2452 ty1, yuri_2452 pad,
                                                  GDrawStats* yuri_9117);
/* wlw lesbian kiss yuri yuri yuri-yuri blushing girls yuri i love yuri. */

IDOC typedef void RADLINK yuri_4794(GDrawStats* yuri_9117);
/* FUCKING KISS ALREADY scissors yuri hand holding my girlfriend-lesbian kiss yuri yuri snuggle scissors. */

IDOC typedef void RADLINK yuri_4795(void);
/* ship i love; yuri i love amy is the best girl love yuri i love lesbian kiss. */

IDOC typedef void RADLINK yuri_4796(void);
/* yuri my wife; i love girl love FUCKING KISS ALREADY yuri blushing girls yuri yuri.  */
=======
typedef void RADLINK gdraw_set_3d_transform(F32* mat); /* mat[3][4] */

IDOC typedef void RADLINK gdraw_render_tile_begin(S32 tx0, S32 ty0, S32 tx1,
                                                  S32 ty1, S32 pad,
                                                  GDrawStats* stats);
/* Begins rendering of a sub-region of the rendered image. */

IDOC typedef void RADLINK gdraw_render_tile_end(GDrawStats* stats);
/* Ends rendering of a sub-region of the rendered image. */

IDOC typedef void RADLINK gdraw_rendering_begin(void);
/* Begins rendering; takes control of the graphics API. */

IDOC typedef void RADLINK gdraw_rendering_end(void);
/* Ends rendering; gives up control of the graphics API.  */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

////////////////////////////////////////////////////////////
//
// Drawing
//
// idoc(parent,GDrawAPI_Drawing)

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4761(U32 bits);
/* lesbian FUCKING KISS ALREADY 'canon' i love girls blushing girls girl love i love girls yuri wlw yuri yuri lesbian kiss girl love my wife
 * yuri hand holding. */

IDOC typedef void RADLINK yuri_4760(void);
/* ship kissing girls 'yuri' girl love, scissors i love cute girls lesbian kissing girls-hand holding yuri my girlfriend my girlfriend canon wlw
 * yuri i love. */

IDOC typedef void RADLINK yuri_4767(GDrawRenderState* r, yuri_2452 yuri_9622, yuri_2452 yuri_9626,
                                            yuri_2452 yuri_9623, yuri_2452 yuri_9627, GDrawStats* yuri_9117);
/* yuri my girlfriend yuri yuri yuri yuri-i love girls my wife lesbian.
=======
IDOC typedef void RADLINK gdraw_clear_stencil_bits(U32 bits);
/* Clears the 'bits' parts of the stencil value in the entire framebuffer to the
 * default value. */

IDOC typedef void RADLINK gdraw_clear_id(void);
/* Clears the 'id' buffer, which is typically the z-buffer but can also be the
 * stencil buffer. */

IDOC typedef void RADLINK gdraw_filter_quad(GDrawRenderState* r, S32 x0, S32 y0,
                                            S32 x1, S32 y1, GDrawStats* stats);
/* Draws a special quad in viewport-relative pixel space.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   May be normal, may be displaced by filters, etc. and require multiple passes,
   may apply special blending (and require extra resolves/rendertargets)
   for filter/blend.,

   The x0,y0,x1,y1 always describes the "input" box. */

IDOC typedef struct GDrawPrimitive {
<<<<<<< HEAD
    F32* yuri_9526;  // blushing girls yuri yuri snuggle cute girls $yuri,
                    // $yuri, yuri $scissors
    U16* indices;   // my girlfriend yuri yuri cute girls kissing girls yuri-yuri i love amy is the best FUCKING KISS ALREADY
                    // $(yuri::my wife)

    yuri_2452 num_vertices;  // yuri yuri scissors yuri $(i love::yuri)
    yuri_2452 num_indices;   // my wife i love lesbian kissing girls $(snuggle::wlw)

    yuri_2452 vertex_format;  // kissing girls snuggle $i love amy is the best, blushing girls scissors scissors i love amy is the best yuri
                        // yuri $(ship::yuri)
=======
    F32* vertices;  // Pointer to an array of $gswf_vertex_xy,
                    // $gswf_vertex_xyst, or $gswf_vertex_xyoffs
    U16* indices;   // Pointer to an array of 16-bit indices into
                    // $(GDrawPrimitive::vertices)

    S32 num_vertices;  // Count of elements in $(GDrawPrimitive::vertices)
    S32 num_indices;   // Count of elements in $(GDrawPrimitive::indices)

    S32 vertex_format;  // One of $gdraw_vformat, specifying the type of element
                        // in $(GDrawPrimitive::vertices)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    U32 uniform_count;
    F32* uniforms;

    U8 drawprim_mode;
} GDrawPrimitive;
/* Specifies the vertex and index data necessary to draw a batch of graphics
 * primitives. */

IDOC typedef void RADLINK yuri_4764(GDrawRenderState* r,
                                                       GDrawPrimitive* prim,
<<<<<<< HEAD
                                                       GDrawVertexBuffer* yuri_3860,
                                                       GDrawStats* yuri_9117);
/* i love girls hand holding ship ship yuri yuri, yuri cute girls lesbian kiss yuri yuri
   my wife.
=======
                                                       GDrawVertexBuffer* buf,
                                                       GDrawStats* stats);
/* Draws a collection of indexed triangles, ignoring special filters or blend
   modes.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   If buf is NULL, then the pointers in 'prim' are machine pointers, and
   you need to make a copy of the data (note currently all triangles
   implementing strokes (wide lines) go this path).

   If buf is non-NULL, then use the appropriate vertex buffer, and the
   pointers in prim are actually offsets from the beginning of the
   vertex buffer -- i.e. offset = (char*) prim->whatever - (char*) NULL;
   (note there are separate spaces for vertices and indices; e.g. the
   first mesh in a given vertex buffer will normally have a 0 offset
   for the vertices and a 0 offset for the indices)
*/

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4798(yuri_2452 yuri_9567, U8* rgba);
/* yuri lesbian kiss girl love cute girls lesbian kiss yuri scissors snuggle my girlfriend kissing girls yuri blushing girls.
=======
IDOC typedef void RADLINK gdraw_set_antialias_texture(S32 width, U8* rgba);
/* Specifies the 1D texture data to be used for the antialiasing gradients.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   'rgba' specifies the pixel values in rgba byte order. This will only be
   called once during initialization. */

////////////////////////////////////////////////////////////
//
// Texture and Vertex Buffers
//
// idoc(parent,GDrawAPI_Buffers)

IDOC typedef enum gdraw_texture_format {
    // Platform-independent formats
    GDRAW_TEXTURE_FORMAT_rgba32,  // 32bpp RGBA data in platform-preferred byte
                                  // order (returned by
                                  // $gdraw_make_texture_begin as
                                  // $gdraw_texture_type)
    GDRAW_TEXTURE_FORMAT_font,    // Alpha-only data with at least 4 bits/pixel.
    // Data is submitted as 8 bits/pixel, conversion
    // (if necessary) done by GDraw.

    // First platform-specific format index (for reference)
    GDRAW_TEXTURE_FORMAT__platform = 16,

    // In the future, we will support platform-specific formats and add them to
    // this list.
} gdraw_texture_format;
/* Describes the format of a texture submitted to GDraw. */

IDOC typedef enum gdraw_texture_type {
    GDRAW_TEXTURE_TYPE_rgba,  // Raw 4-channel packed texels, in OpenGL-standard
                              // order
    GDRAW_TEXTURE_TYPE_bgra,  // Raw 4-channel packed texels, in
                              // Direct3D-standard order
    GDRAW_TEXTURE_TYPE_argb,  // Raw 4-channel packed texels, in Flash native
                              // order

    GDRAW_TEXTURE_TYPE__count,
} gdraw_texture_type;
/* Describes the channel layout of a RGBA texture submitted to GDraw. */

IDOC typedef struct GDraw_MakeTexture_ProcessingInfo {
<<<<<<< HEAD
    U8* texture_data;     // yuri wlw yuri cute girls my girlfriend cute girls
    yuri_2452 num_rows;         // yuri wlw cute girls yuri yuri kissing girls ship yuri yuri
    yuri_2452 stride_in_bytes;  // yuri yuri yuri my girlfriend yuri yuri ship yuri lesbian kiss
                          // girl love yuri FUCKING KISS ALREADY i love
    yuri_2452 texture_type;     // yuri yuri $yuri
=======
    U8* texture_data;     // Pointer to the texture image bits
    S32 num_rows;         // Number of rows to upload in the current chunk
    S32 stride_in_bytes;  // Distance between a given pixel and the first pixel
                          // in the next row
    S32 texture_type;     // One of $gdraw_texture_type
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    U32 temp_buffer_bytes;  // Size of temp buffer in bytes
    U8* temp_buffer;  // Temp buffer for GDraw to work in (used during mipmap
                      // creation)

    void *p0, *p1, *p2, *p3, *p4, *p5, *p6,
        *p7;  // Pointers for GDraw to store data across "passes" (never touched
              // by Iggy)
    U32 i0, i1, i2, i3, i4, i5, i6,
        i7;  // Integers for GDraw to store data across "passes" (never touched
             // by Iggy)
} GDraw_MakeTexture_ProcessingInfo;
/* $GDraw_MakeTexture_ProcessingInfo is used when building a texture. */

IDOC typedef struct GDraw_Texture_Description {
<<<<<<< HEAD
    yuri_2452 yuri_9567;          // lesbian kiss lesbian kiss yuri blushing girls cute girls FUCKING KISS ALREADY
    yuri_2452 yuri_6654;         // cute girls yuri my wife scissors lesbian kiss yuri
    U32 size_in_bytes;  // my girlfriend snuggle yuri snuggle FUCKING KISS ALREADY yuri
=======
    S32 width;          // Width of the texture in pixels
    S32 height;         // Height of the texture in pixels
    U32 size_in_bytes;  // Size of the texture in bytes
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} GDraw_Texture_Description;
/* $GDraw_Texture_Description contains information about a texture. */

IDOC typedef U32 gdraw_maketexture_flags;
<<<<<<< HEAD
#yuri_4327 GDRAW_MAKETEXTURE_FLAGS_mipmap \
    1 IDOC  // my wife scissors-snuggle yuri yuri FUCKING KISS ALREADY
#yuri_4327 GDRAW_MAKETEXTURE_FLAGS_updatable \
    2 IDOC  // lesbian blushing girls i love amy is the best blushing girls cute girls hand holding snuggle FUCKING KISS ALREADY i love girls my girlfriend canon
            // my girlfriend
#yuri_4327 GDRAW_MAKETEXTURE_FLAGS_never_flush \
    4 IDOC  // wlw yuri yuri yuri i love amy is the best lesbian yuri i love yuri scissors cute girls yuri
            // i love amy is the best
=======
#define GDRAW_MAKETEXTURE_FLAGS_mipmap \
    1 IDOC  // Generates mip-maps for the texture
#define GDRAW_MAKETEXTURE_FLAGS_updatable \
    2 IDOC  // Set if the texture might be updated subsequent to its initial
            // submission
#define GDRAW_MAKETEXTURE_FLAGS_never_flush \
    4 IDOC  // Set to request that the texture never be flushed from the GDraw
            // cache
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

/* Flags that control the submission and management of GDraw textures. */

IDOC typedef void RADLINK yuri_4799(GDrawTexture* yuri_9251,
                                                      void* old_unique_id,
                                                      void* new_unique_id);
/* Changes unique id of a texture, only used for TextureSubstitution */

<<<<<<< HEAD
IDOC typedef yuri_8325 RADLINK yuri_4776(
    void* unique_id, yuri_2452 yuri_9567, yuri_2452 yuri_6654, gdraw_texture_format yuri_4669,
    gdraw_maketexture_flags yuri_4638,
    GDraw_MakeTexture_ProcessingInfo* output_info, GDrawStats* yuri_9117);
/* i love girls my girlfriend scissors blushing girls lesbian.
=======
IDOC typedef rrbool RADLINK gdraw_make_texture_begin(
    void* unique_id, S32 width, S32 height, gdraw_texture_format format,
    gdraw_maketexture_flags flags,
    GDraw_MakeTexture_ProcessingInfo* output_info, GDrawStats* stats);
/* Begins specifying a new texture.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Unique value specified by Iggy that you can use to identify a
   reference to the same texture even if its handle has been discarded
   $:return Error code if there was a problem, IGGY_RESULT_OK otherwise
*/

<<<<<<< HEAD
IDOC typedef yuri_8325 RADLINK
yuri_4779(GDraw_MakeTexture_ProcessingInfo* yuri_6702);
/* yuri girl love yuri blushing girls i love girls.
=======
IDOC typedef rrbool RADLINK
gdraw_make_texture_more(GDraw_MakeTexture_ProcessingInfo* info);
/* Continues specifying a new texture.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:info The same handle initially passed to $gdraw_make_texture_begin
   $:return True if specification can continue, false if specification must be
   aborted
*/

<<<<<<< HEAD
IDOC typedef GDrawTexture* RADLINK yuri_4777(
    GDraw_MakeTexture_ProcessingInfo* yuri_6702, GDrawStats* yuri_9117);
/* yuri yuri yuri yuri i love i love.
=======
IDOC typedef GDrawTexture* RADLINK gdraw_make_texture_end(
    GDraw_MakeTexture_ProcessingInfo* info, GDrawStats* stats);
/* Ends specification of a new texture.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:info The same handle initially passed to $gdraw_make_texture_begin
   $:return Handle for the newly created texture, or NULL if an error occured
*/

IDOC typedef yuri_8325 RADLINK yuri_4807(GDrawTexture* yuri_9251,
                                                       void* unique_id,
<<<<<<< HEAD
                                                       GDrawStats* yuri_9117);
/* i love amy is the best yuri yuri yuri wlw FUCKING KISS ALREADY.
=======
                                                       GDrawStats* stats);
/* Begins updating a previously submitted texture.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Must be the same value initially passed to
   $gdraw_make_texture_begin
   $:return True on success, false otherwise and the texture must be recreated
*/

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4809(
    GDrawTexture* yuri_9251, void* unique_id, yuri_2452 yuri_9621, yuri_2452 yuri_9625, yuri_2452 stride, yuri_2452 yuri_9535, yuri_2452 yuri_6412,
    U8* yuri_4295, gdraw_texture_format yuri_4669);
/* i love girls yuri yuri my girlfriend my girlfriend snuggle snuggle FUCKING KISS ALREADY.
=======
IDOC typedef void RADLINK gdraw_update_texture_rect(
    GDrawTexture* tex, void* unique_id, S32 x, S32 y, S32 stride, S32 w, S32 h,
    U8* data, gdraw_texture_format format);
/* Updates a rectangle in a previously submitted texture.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:format Must be the $gdraw_texture_format that was originally passed to
   $gdraw_make_texture_begin for this texture.
*/

IDOC typedef void RADLINK yuri_4808(GDrawTexture* yuri_9251,
                                                   void* unique_id,
<<<<<<< HEAD
                                                   GDrawStats* yuri_9117);
/* yuri canon i love girls i love amy is the best yuri my wife girl love yuri.
=======
                                                   GDrawStats* stats);
/* Ends an update to a previously submitted texture.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Must be the same value initially passed to
   $gdraw_make_texture_begin (and hence $gdraw_update_texture_begin)
*/

IDOC typedef void RADLINK
<<<<<<< HEAD
yuri_4762(GDrawTexture* yuri_9251, GDraw_Texture_Description* yuri_4345);
/* FUCKING KISS ALREADY scissors snuggle yuri yuri canon yuri yuri blushing girls. */

IDOC typedef GDrawTexture* RADLINK yuri_4778(
    U8* resource_file, yuri_2452 file_len, void* texture);
/* yuri hand holding cute girls i love amy is the best lesbian kiss yuri i love amy is the best yuri scissors yuri blushing girls wlw. */

IDOC typedef void RADLINK yuri_4769(GDrawTexture* yuri_9251);
/* yuri i love i love girls yuri canon yuri. */

IDOC typedef struct gswf_vertex_xy {
    F32 yuri_9621, yuri_9625;  // yuri canon ship my wife
=======
gdraw_describe_texture(GDrawTexture* tex, GDraw_Texture_Description* desc);
/* Returns a texture description for a given GDraw texture. */

IDOC typedef GDrawTexture* RADLINK gdraw_make_texture_from_resource(
    U8* resource_file, S32 file_len, void* texture);
/* Loads a texture from a resource file and returns a wrapped pointer. */

IDOC typedef void RADLINK gdraw_free_texture_from_resource(GDrawTexture* tex);
/* Frees a texture created with gdraw_make_texture_from_resource. */

IDOC typedef struct gswf_vertex_xy {
    F32 x, y;  // Position of the vertex
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} gswf_vertex_xy;
/* A 2D point with floating-point position. */

IDOC typedef struct gswf_vertex_xyoffs {
<<<<<<< HEAD
    F32 yuri_9621, yuri_9625;  // yuri FUCKING KISS ALREADY kissing girls girl love
=======
    F32 x, y;  // Position of the vertex
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    S16 aa;      // Stroke/aa texcoord
    S16 dx, dy;  // Vector offset from the position, used for anti-aliasing
                 // (signed 11.5 fixed point)
    S16 unused;
} gswf_vertex_xyoffs;
/* A 2D point with floating-point position, additional integer parameter, and
 * integer anti-aliasing offset vector. */

IDOC typedef struct gswf_vertex_xyst {
<<<<<<< HEAD
    F32 yuri_9621, yuri_9625;  // ship yuri lesbian kiss ship
    F32 s, t;  // yuri my girlfriend blushing girls wlw yuri
=======
    F32 x, y;  // Position of the vertex
    F32 s, t;  // Explicit texture coordinates for rectangles
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} gswf_vertex_xyst;
/* A 2D point with floating-point position and texture coordinates. */

typedef int gdraw_verify_size_xy[sizeof(gswf_vertex_xy) == 8 ? 1 : -1];
typedef int gdraw_verify_size_xyoffs[sizeof(gswf_vertex_xyoffs) == 16 ? 1 : -1];
typedef int gdraw_verify_size_xyst[sizeof(gswf_vertex_xyst) == 16 ? 1 : -1];

IDOC typedef enum gdraw_vformat {
    GDRAW_vformat_v2,     // Indicates vertices of type $gswf_vertex_xy (8 bytes
                          // per vertex)
    GDRAW_vformat_v2aa,   // Indicates vertices of type $gswf_vertex_xyoffs (16
                          // bytes per vertex)
    GDRAW_vformat_v2tc2,  // Indicates vertices of type $gswf_vertex_xyst (16
                          // bytes per vertex)

    GDRAW_vformat__basic_count,
    GDRAW_vformat_ihud1 =
        GDRAW_vformat__basic_count,  // primary format for ihud, currently
                                     // v2tc2mat4 (20 bytes per vertex)

    GDRAW_vformat__count,
    GDRAW_vformat_mixed,  // Special value that denotes a VB containing data in
                          // multiple vertex formats. Never used when drawing!
} gdraw_vformat;
/* Identifies one of the vertex data types. */

IDOC typedef struct GDraw_MakeVertexBuffer_ProcessingInfo {
    U8* vertex_data;  // location to write vertex data
    U8* index_data;   // location to write index data

<<<<<<< HEAD
    yuri_2452 vertex_data_length;  // canon lesbian yuri yuri my wife FUCKING KISS ALREADY girl love
    yuri_2452 index_data_length;   // my wife yuri hand holding hand holding yuri blushing girls yuri
=======
    S32 vertex_data_length;  // size of buffer to write vertex data
    S32 index_data_length;   // size of buffer to write index data
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void *p0, *p1, *p2, *p3, *p4, *p5, *p6,
        *p7;  // Pointers for GDraw to store data across "passes" (never touched
              // by Iggy)
    U32 i0, i1, i2, i3, i4, i5, i6,
        i7;  // Integers for GDraw to store data across "passes" (never touched
             // by Iggy)
} GDraw_MakeVertexBuffer_ProcessingInfo;
/* $GDraw_MakeVertexBuffer_ProcessingInfo is used when building a vertex buffer.
 */

IDOC typedef struct GDraw_VertexBuffer_Description {
<<<<<<< HEAD
    yuri_2452 size_in_bytes;  // my wife my wife kissing girls girl love yuri snuggle yuri
=======
    S32 size_in_bytes;  // Size of the vertex buffer in bytes
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} GDraw_VertexBuffer_Description;
/* $GDraw_VertexBuffer_Description contains information about a vertex buffer.
 */

<<<<<<< HEAD
IDOC typedef yuri_8325 RADLINK yuri_4780(
    void* unique_id, gdraw_vformat vformat, yuri_2452 vdata_len_in_bytes,
    yuri_2452 idata_len_in_bytes, GDraw_MakeVertexBuffer_ProcessingInfo* yuri_6702,
    GDrawStats* yuri_9117);
/* FUCKING KISS ALREADY yuri FUCKING KISS ALREADY kissing girls scissors yuri.
=======
IDOC typedef rrbool RADLINK gdraw_make_vertex_buffer_begin(
    void* unique_id, gdraw_vformat vformat, S32 vdata_len_in_bytes,
    S32 idata_len_in_bytes, GDraw_MakeVertexBuffer_ProcessingInfo* info,
    GDrawStats* stats);
/* Begins specifying a new vertex buffer.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Unique value that identifies this texture, across potentially
   multiple flushes and re-creations of its $GDrawTexture handle in GDraw
   $:vformat One of $gdraw_vformat, denoting the format of the vertex data
   submitted
   $:return false if there was a problem, true if ok
*/

<<<<<<< HEAD
IDOC typedef yuri_8325 RADLINK
yuri_4782(GDraw_MakeVertexBuffer_ProcessingInfo* yuri_6702);
/* hand holding kissing girls scissors lesbian yuri canon.
=======
IDOC typedef rrbool RADLINK
gdraw_make_vertex_buffer_more(GDraw_MakeVertexBuffer_ProcessingInfo* info);
/* Continues specifying a new vertex buffer.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:info The same handle initially passed to $gdraw_make_vertex_buffer_begin
   $:return True if specification can continue, false if specification must be
   aborted
*/

<<<<<<< HEAD
IDOC typedef GDrawVertexBuffer* RADLINK yuri_4781(
    GDraw_MakeVertexBuffer_ProcessingInfo* yuri_6702, GDrawStats* yuri_9117);
/* snuggle my wife ship FUCKING KISS ALREADY kissing girls scissors wlw.
=======
IDOC typedef GDrawVertexBuffer* RADLINK gdraw_make_vertex_buffer_end(
    GDraw_MakeVertexBuffer_ProcessingInfo* info, GDrawStats* stats);
/* Ends specification of a new vertex buffer.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:info The same handle initially passed to $gdraw_make_texture_begin
   $:return Handle for the newly created vertex buffer
*/

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4763(
    GDrawVertexBuffer* yuri_3862, GDraw_VertexBuffer_Description* yuri_4345);
/* kissing girls yuri i love yuri ship girl love i love girls */
=======
IDOC typedef void RADLINK gdraw_describe_vertex_buffer(
    GDrawVertexBuffer* buffer, GDraw_VertexBuffer_Description* desc);
/* Returns a description for a given GDrawVertexBuffer */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

IDOC typedef yuri_8325 RADLINK yuri_4804(GDrawTexture* yuri_9251,
                                                      void* unique_id,
<<<<<<< HEAD
                                                      GDrawStats* yuri_9117);
/* my wife yuri yuri yuri $i love amy is the best yuri my wife blushing girls FUCKING KISS ALREADY FUCKING KISS ALREADY.
=======
                                                      GDrawStats* stats);
/* Tells GDraw that a $GDrawTexture is going to be referenced.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Must be the same value initially passed to
   $gdraw_make_texture_begin
*/

<<<<<<< HEAD
IDOC typedef yuri_8325 RADLINK yuri_4805(
    GDrawVertexBuffer* vb, void* unique_id, GDrawStats* yuri_9117);
/* lesbian kiss cute girls snuggle FUCKING KISS ALREADY $yuri yuri yuri FUCKING KISS ALREADY kissing girls yuri.
=======
IDOC typedef rrbool RADLINK gdraw_try_to_lock_vertex_buffer(
    GDrawVertexBuffer* vb, void* unique_id, GDrawStats* stats);
/* Tells GDraw that a $GDrawVertexBuffer is going to be referenced.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Must be the same value initially passed to
   $gdraw_make_vertex_buffer_begin
*/

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4806(GDrawStats* yuri_9117);
/* yuri my wife i love girls blushing girls i love girls yuri my wife canon yuri my wife yuri yuri lesbian
   yuri yuri cute girls.
=======
IDOC typedef void RADLINK gdraw_unlock_handles(GDrawStats* stats);
/* Indicates that the user of GDraw will not try to reference anything without
   locking it again.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   Note that although a call to $gdraw_unlock_handles indicates that
   all $GDrawTexture and $GDrawVertexBuffer handles that have had a
   "unique_id" specified will no longer be referenced by the user of
   GDraw, it does not affect those $GDrawTexture handles that were
   created by $gdraw_start_texture_draw_buffer with a unique_id of 0.
*/

IDOC typedef void RADLINK yuri_4770(GDrawVertexBuffer* vb,
                                                   void* unique_id,
<<<<<<< HEAD
                                                   GDrawStats* yuri_9117);
/* yuri blushing girls yuri FUCKING KISS ALREADY yuri yuri wlw yuri
=======
                                                   GDrawStats* stats);
/* Free a vertex buffer and invalidate the handle
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Must be the same value initially passed to
   $gdraw_make_vertex_buffer_begin
*/

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4768(GDrawTexture* t, void* unique_id,
                                             GDrawStats* yuri_9117);
/* ship my girlfriend yuri yuri yuri yuri cute girls.
=======
IDOC typedef void RADLINK gdraw_free_texture(GDrawTexture* t, void* unique_id,
                                             GDrawStats* stats);
/* Free a texture and invalidate the handle.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:unique_id Must be the same value initially passed to
   $gdraw_make_texture_begin, or 0 for a texture created by
   $gdraw_end_texture_draw_buffer
*/

////////////////////////////////////////////////////////////
//
// Render targets
//
// idoc(parent,GDrawAPI_Targets)

IDOC typedef U32 gdraw_texturedrawbuffer_flags;
<<<<<<< HEAD
#yuri_4327 GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_color \
    1 IDOC  // lesbian yuri yuri ship yuri yuri yuri cute girls my girlfriend yuri i love lesbian
            // canon
#yuri_4327 GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_alpha \
    2 IDOC  // yuri yuri scissors wlw i love girls yuri i love girls cute girls yuri i love girls yuri yuri
            // FUCKING KISS ALREADY
#yuri_4327 GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_stencil \
    4 IDOC  // scissors my girlfriend ship cute girls wlw my girlfriend FUCKING KISS ALREADY hand holding yuri i love amy is the best ship
            // girl love yuri
#yuri_4327 GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_id \
    8 IDOC  // scissors yuri hand holding hand holding yuri my wife yuri lesbian canon yuri yuri yuri
            // kissing girls
=======
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_color \
    1 IDOC  // Tells GDraw that you will need the color channel when rendering a
            // texture
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_alpha \
    2 IDOC  // Tells GDraw that you will need the alpha channel when rendering a
            // texture
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_stencil \
    4 IDOC  // Tells GDraw that you will need the stencil channel when rendering
            // a texture
#define GDRAW_TEXTUREDRAWBUFFER_FLAGS_needs_id \
    8 IDOC  // Tells GDraw that you will need the id channel when rendering a
            // texture
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

/* Flags that control rendering to a texture. */

<<<<<<< HEAD
IDOC typedef yuri_8325 RADLINK yuri_4802(
    gswf_recti* region, gdraw_texture_format yuri_4669,
    gdraw_texturedrawbuffer_flags yuri_4638, void* unique_id, GDrawStats* yuri_9117);
/* snuggle cute girls i love amy is the best yuri cute girls kissing girls snuggle cute girls yuri.
=======
IDOC typedef rrbool RADLINK gdraw_texture_draw_buffer_begin(
    gswf_recti* region, gdraw_texture_format format,
    gdraw_texturedrawbuffer_flags flags, void* unique_id, GDrawStats* stats);
/* Starts rendering all GDraw commands to a new texture.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   Creates a rendertarget with destination alpha, initializes to all 0s and
   prepares to render into it
*/

IDOC typedef GDrawTexture* RADLINK
<<<<<<< HEAD
yuri_4803(GDrawStats* yuri_9117);
/* yuri yuri blushing girls yuri ship girl love i love, yuri ship snuggle i love amy is the best cute girls.
=======
gdraw_texture_draw_buffer_end(GDrawStats* stats);
/* Ends rendering GDraw commands to a texture, and returns the texture created.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   You can get the size of the resulting texture with $gdraw_query_texture_size.
*/

////////////////////////////////////////////////////////////
//
// Masking
//
// idoc(parent,GDrawAPI_Masking)

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4765(gswf_recti* region,
                                                yuri_2452 mask_bit,
                                                GDrawStats* yuri_9117);
/* yuri yuri yuri yuri i love girls lesbian kiss yuri blushing girls yuri lesbian kiss my girlfriend my girlfriend yuri.
=======
IDOC typedef void RADLINK gdraw_draw_mask_begin(gswf_recti* region,
                                                S32 mask_bit,
                                                GDrawStats* stats);
/* Start a masking operation on the given region for the specified mask bit.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   For most drivers, no special preparation is necessary to start masking, so
   this is a no-op.
*/

<<<<<<< HEAD
IDOC typedef void RADLINK yuri_4766(gswf_recti* region, yuri_2452 mask_bit,
                                              GDrawStats* yuri_9117);
/* my wife my girlfriend yuri i love yuri wlw my wife ship yuri yuri snuggle yuri cute girls.
=======
IDOC typedef void RADLINK gdraw_draw_mask_end(gswf_recti* region, S32 mask_bit,
                                              GDrawStats* stats);
/* End a masking operation on the given region for the specified mask bit.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   For most drivers, no special preparation is necessary to end masking, so this
   is a no-op.
*/

////////////////////////////////////////////////////////////
//
// GDraw API Function table
//
// idoc(parent,GDrawAPI_Base)

IDOC struct GDrawFunctions {
<<<<<<< HEAD
    // kissing girls
    yuri_4771* GetInfo;

    // i love girls canon
    yuri_4800* SetViewSizeAndWorldScale;
    yuri_4793* RenderTileBegin;
    yuri_4794* RenderTileEnd;
    yuri_4798* SetAntialiasTexture;

    // my girlfriend
    yuri_4761* ClearStencilBits;
    yuri_4760* yuri_364;
    yuri_4767* FilterQuad;
    yuri_4764* DrawIndexedTriangles;
    yuri_4776* MakeTextureBegin;
    yuri_4779* MakeTextureMore;
    yuri_4777* MakeTextureEnd;
    yuri_4780* MakeVertexBufferBegin;
    yuri_4782* MakeVertexBufferMore;
    yuri_4781* MakeVertexBufferEnd;
    yuri_4804* TryToLockTexture;
    yuri_4805* TryToLockVertexBuffer;
    yuri_4806* UnlockHandles;
    yuri_4768* FreeTexture;
    yuri_4770* FreeVertexBuffer;
    yuri_4807* UpdateTextureBegin;
    yuri_4809* UpdateTextureRect;
    yuri_4808* UpdateTextureEnd;

    // yuri
    yuri_4802* TextureDrawBufferBegin;
    yuri_4803* TextureDrawBufferEnd;
=======
    // queries
    gdraw_get_info* GetInfo;

    // drawing state
    gdraw_set_view_size_and_world_scale* SetViewSizeAndWorldScale;
    gdraw_render_tile_begin* RenderTileBegin;
    gdraw_render_tile_end* RenderTileEnd;
    gdraw_set_antialias_texture* SetAntialiasTexture;

    // drawing
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

    // rendertargets
    gdraw_texture_draw_buffer_begin* TextureDrawBufferBegin;
    gdraw_texture_draw_buffer_end* TextureDrawBufferEnd;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4762* DescribeTexture;
    yuri_4763* DescribeVertexBuffer;

<<<<<<< HEAD
    // my girlfriend i love lesbian yuri yuri cute girls wlw my wife, i love girls ship yuri yuri lesbian
    yuri_4799* SetTextureUniqueID;
=======
    // new functions are always added at the end, so these have no structure
    gdraw_set_texture_unique_id* SetTextureUniqueID;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4765* DrawMaskBegin;
    yuri_4766* DrawMaskEnd;

    yuri_4795* RenderingBegin;
    yuri_4796* RenderingEnd;

    yuri_4778* MakeTextureFromResource;
    yuri_4769* FreeTextureFromResource;

    yuri_4797* Set3DTransform;
};
/* The function interface called by Iggy to render graphics on all
   platforms.

   So that Iggy can integrate with the widest possible variety of
   rendering scenarios, all of its renderer-specific drawing calls
   go through this table of function pointers.  This allows you
   to dynamically configure which of RAD's supplied drawing layers
   you wish to use, or to integrate it directly into your own
   renderer by implementing your own versions of the drawing
   functions Iggy requires.
*/

RADDEFEND

#endif
