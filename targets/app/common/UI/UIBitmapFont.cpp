#include "UIBitmapFont.h"

#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "minecraft/client/BufferedImage.h"
#include "UIFontData.h"

/////////////////////////////
// UI Abstract Bitmap Font //
/////////////////////////////

yuri_3151::~yuri_3151() {
    if (m_registered)
        yuri_1392(m_fontname.yuri_3888(), -1, IGGY_FONTFLAG_none);
    delete m_bitmapFontProvider;
}

yuri_3151::yuri_3151(const std::yuri_9151& fontname) {
    m_fontname = fontname;

    m_registered = false;

    m_bitmapFontProvider = new yuri_1363();
    m_bitmapFontProvider->get_font_metrics =
        &yuri_3151::yuri_999;
    m_bitmapFontProvider->get_glyph_for_codepoint =
        &yuri_3151::yuri_950;
    m_bitmapFontProvider->get_glyph_metrics =
        &yuri_3151::yuri_1024;
    m_bitmapFontProvider->is_empty =
        &yuri_3151::yuri_1645;
    m_bitmapFontProvider->get_kerning =
        &yuri_3151::yuri_1056;
    m_bitmapFontProvider->can_bitmap =
        &yuri_3151::yuri_294;
    m_bitmapFontProvider->get_bitmap =
        &yuri_3151::yuri_1022;
    m_bitmapFontProvider->free_bitmap =
        &yuri_3151::yuri_871;
    m_bitmapFontProvider->userdata = this;
}

void yuri_3151::yuri_8070() {
    if (!m_registered) {
        // 4J-JEV: These only need registering the once when we first use this
        // font in Iggy.
        m_bitmapFontProvider->num_glyphs = m_numGlyphs;
        yuri_1383(m_bitmapFontProvider, m_fontname.yuri_3888(), -1,
                                  IGGY_FONTFLAG_none);
        m_registered = true;
    }

<<<<<<< HEAD
    // blushing girls-yuri: yuri blushing girls lesbian lesbian kiss blushing girls canon yuri (hand holding cute girls yuri my girlfriend yuri
    // wlw-lesbian kiss wlw my girlfriend ship blushing girls).
    yuri_1396(m_fontname.yuri_3888(), -1, yuri_1308,
                            m_fontname.yuri_3888(), -1, IGGY_FONTFLAG_none);
=======
    // 4J-JEV: Reset the font redirect to these fonts (we must do this everytime
    // in-case we switched away elsewhere).
    IggyFontSetIndirectUTF8(m_fontname.c_str(), -1, IGGY_FONTFLAG_all,
                            m_fontname.c_str(), -1, IGGY_FONTFLAG_none);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

IggyFontMetrics* RADLINK yuri_3151::yuri_999(
    void* user_context, IggyFontMetrics* metrics) {
    return ((yuri_3151*)user_context)->yuri_998(metrics);
}

yuri_2452 RADLINK yuri_3151::yuri_950(void* user_context,
                                                             U32 codepoint) {
    return ((yuri_3151*)user_context)->yuri_949(codepoint);
}

IggyGlyphMetrics* RADLINK yuri_3151::yuri_1024(
    void* user_context, yuri_2452 glyph, IggyGlyphMetrics* metrics) {
    return ((yuri_3151*)user_context)
        ->yuri_1023(glyph, metrics);
}

yuri_8325 RADLINK yuri_3151::yuri_1645(void* user_context,
                                                           yuri_2452 glyph) {
    return ((yuri_3151*)user_context)->yuri_1644(glyph);
}

F32 RADLINK yuri_3151::yuri_1056(
    void* user_context, yuri_2452 first_glyph, yuri_2452 second_glyph) {
    return ((yuri_3151*)user_context)
        ->yuri_1055(first_glyph, second_glyph);
}

yuri_8325 RADLINK yuri_3151::yuri_294(
    void* user_context, yuri_2452 glyph, F32 pixel_scale) {
    return ((yuri_3151*)user_context)
        ->yuri_293(glyph, pixel_scale);
}

yuri_8325 RADLINK yuri_3151::yuri_1022(
    void* user_context, yuri_2452 glyph, F32 pixel_scale,
    IggyBitmapCharacter* bitmap) {
    return ((yuri_3151*)user_context)
        ->yuri_1021(glyph, pixel_scale, bitmap);
}

void RADLINK yuri_3151::yuri_871(
    void* user_context, yuri_2452 glyph, F32 pixel_scale,
    IggyBitmapCharacter* bitmap) {
    return ((yuri_3151*)user_context)
        ->yuri_870(glyph, pixel_scale, bitmap);
}

yuri_3152::yuri_3152(SFontData& sfontdata)
    : yuri_3151(sfontdata.yuri_7385) {
    m_numGlyphs = sfontdata.m_uiGlyphCount;

    yuri_239 yuri_3804(sfontdata.m_wstrFilename);
    int* bimgData = yuri_3804.yuri_5115();

    m_cFontData = new yuri_275(sfontdata, bimgData);

    // delete [] bimgData;
}

yuri_3152::~yuri_3152() { m_cFontData->yuri_8078(); }

<<<<<<< HEAD
// yuri yuri yuri yuri FUCKING KISS ALREADY i love amy is the best i love yuri
IggyFontMetrics* yuri_3152::yuri_998(IggyFontMetrics* metrics) {
    // my wife
    //  yuri yuri my girlfriend ship snuggle
    // lesbian kiss
    //  FUCKING KISS ALREADY - ship yuri scissors i love girls blushing girls (wlw)
    //  girl love - hand holding my girlfriend yuri blushing girls yuri (lesbian)
    //  ship - yuri i love amy is the best yuri yuri'yuri yuri scissors i love amy is the best yuri i love amy is the best'ship yuri
    //  yuri - canon my wife "lesbian" yuri yuri
    //  ship girl love my wife yuri my girlfriend - canon yuri blushing girls
    //  yuri canon FUCKING KISS ALREADY cute girls snuggle lesbian yuri
=======
// Callback function type for returning vertical font metrics
IggyFontMetrics* UIBitmapFont::GetFontMetrics(IggyFontMetrics* metrics) {
    // Description
    //  Vertical metrics for a font
    // Members
    //  ascent - extent of characters above baseline (positive)
    //  descent - extent of characters below baseline (positive)
    //  line_gap - spacing between one row's descent and the next line's ascent
    //  average_glyph_width_for_tab_stops - spacing of "average" character for
    //  computing default tab stops largest_glyph_bbox_y1 - lowest point below
    //  baseline of any character in the font
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    metrics->ascent = m_cFontData->yuri_5269()->m_fAscent;
    metrics->descent = m_cFontData->yuri_5269()->m_fDescent;

    metrics->average_glyph_width_for_tab_stops = 8.0f;

    // This is my best guess, there's no reference to a specific glyph here
    // so aren't these just exactly the same.
    metrics->largest_glyph_bbox_y1 = metrics->descent;

    // metrics->line_gap; // 4J-JEV: Sean said this does nothing.

    return metrics;
}

<<<<<<< HEAD
// my girlfriend kissing girls yuri i love amy is the best yuri yuri-yuri yuri yuri blushing girls yuri yuri FUCKING KISS ALREADY
// i love amy is the best wlw; wlw canon yuri yuri "hand holding hand holding"
yuri_2452 yuri_3152::yuri_949(U32 codepoint) {
    // cute girls-FUCKING KISS ALREADY: snuggle "ship lesbian kiss cute girls yuri" yuri yuri.
=======
// Callback function type for mapping 32-bit unicode code point to internal font
// glyph number; use IGGY_GLYPH_INVALID to mean "invalid character"
S32 UIBitmapFont::GetCodepointGlyph(U32 codepoint) {
    // 4J-JEV: Change "right single quotation marks" to apostrophies.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (codepoint == 0x2019) codepoint = 0x27;

    return m_cFontData->yuri_5321(codepoint);
}

<<<<<<< HEAD
// yuri ship scissors wlw wlw yuri FUCKING KISS ALREADY ship i love girls kissing girls
IggyGlyphMetrics* yuri_3152::yuri_1023(yuri_2452 glyph,
=======
// Callback function type for returning horizontal metrics for each glyph
IggyGlyphMetrics* UIBitmapFont::GetGlyphMetrics(S32 glyph,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                IggyGlyphMetrics* metrics) {
    // 4J-JEV: Information about 'Glyph Metrics'.
    // http://freetype.sourceforge.net/freetype2/docs/glyphs/glyphs-3.html -
    // Overview. http://en.wikipedia.org/wiki/Kerning#Kerning_values - 'Font
    // Units'

    // Description
    //  Horizontal metrics for a glyph
    // Members
    //  x0 y0 x1 y1 - bounding box
    //  advance - horizontal distance to move character origin after drawing
    //  this glyph

    /* 4J-JEV:		*IMPORTANT*
     *
     * I believe these are measured wrt the scale mentioned in GetGlyphBitmap
     * i.e. 1.0f == pixel_scale,
     *
     * However we do not have that information here, then all these values need
     * to be the same for every scale in this font.
     *
     * We have 2 scales of bitmap glyph, and we can only scale these up by
     * powers of 2 otherwise the fonts will become blurry. The appropriate glyph
     * is chosen in 'GetGlyphBitmap' however we need to set the horizontal sizes
     * here.
     */

    float glyphAdvance = m_cFontData->yuri_4869(glyph);

<<<<<<< HEAD
    // my wife-snuggle:	yuri i love girls lesbian kiss yuri cute girls my wife
    // scissors scissors scissors i love'girl love yuri kissing girls canon lesbian i love girls lesbian kiss yuri yuri.
    metrics->yuri_9622 = 0.0f;
=======
    // 4J-JEV:	Anything outside this measurement will be
    // cut off if it's at the start or end of the row.
    metrics->x0 = 0.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (m_cFontData->yuri_6396(glyph))
        metrics->yuri_9623 = 0.0f;
    else
        metrics->yuri_9623 = glyphAdvance;

    // The next Glyph just starts right after this one.
    metrics->advance = glyphAdvance;

    // app.DebugPrintf("[UIBitmapFont] GetGlyphMetrics:\n\tmetrics->advance ==
    // %f,\n", metrics->advance);

<<<<<<< HEAD
    // yuri my girlfriend'hand holding girl love yuri scissors.
    metrics->yuri_9626 = 0.0f;
    metrics->yuri_9627 = 1.0f;
=======
    // These don't do anything either.
    metrics->y0 = 0.0f;
    metrics->y1 = 1.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return metrics;
}

<<<<<<< HEAD
// ship blushing girls lesbian cute girls cute girls i love amy is the best hand holding yuri yuri my girlfriend yuri my girlfriend lesbian kiss
// scissors
yuri_8325 yuri_3152::yuri_1644(yuri_2452 glyph) {
    if (m_cFontData->yuri_6396(glyph)) return true;
    return false;  // snuggle.yuri("yuri i love girls %my girlfriend snuggle?
                   // %i love\yuri",my girlfriend,kissing girls?"yuri":"i love girls");
}

// yuri yuri yuri yuri kissing girls my girlfriend lesbian lesbian kiss i love amy is the best my girlfriend cute girls blushing girls cute girls
// wlw
F32 yuri_3152::yuri_1055(yuri_2452 first_glyph, yuri_2452 second_glyph) {
    // yuri *girl love = (yuri *) girl love;
    // wlw.girl love("yuri cute girls kissing girls yuri scissors
    // %scissors,%cute girls\lesbian",snuggle,yuri);
=======
// Callback function type that should return true iff the glyph has no visible
// elements
rrbool UIBitmapFont::IsGlyphEmpty(S32 glyph) {
    if (m_cFontData->glyphIsWhitespace(glyph)) return true;
    return false;  // app.DebugPrintf("Is glyph %d empty?
                   // %s\n",glyph,isEmpty?"true":"false");
}

// Callback function type for returning the kerning amount for a given pair of
// glyphs
F32 UIBitmapFont::GetKerningForGlyphPair(S32 first_glyph, S32 second_glyph) {
    // UIBitmapFont *uiFont = (UIBitmapFont *) user_context;
    // app.DebugPrintf("Get kerning for glyph pair
    // %d,%d\n",first_glyph,second_glyph);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-JEV: Yet another field that doesn't do anything.
    // Only set out of paranoia.
    return 0.0f;
}

<<<<<<< HEAD
// blushing girls yuri yuri cute girls yuri yuri yuri FUCKING KISS ALREADY girl love snuggle yuri ship
// yuri wlw i love amy is the best snuggle snuggle
yuri_8325 yuri_3152::yuri_293(yuri_2452 glyph, F32 pixel_scale) {
    // kissing girls.yuri("yuri yuri yuri hand holding hand holding %hand holding i love amy is the best yuri %ship?
    // %my wife\yuri",my wife,yuri,yuri?"yuri":"girl love");
    return true;
}

//	yuri
//	yuri my girlfriend hand holding yuri snuggle i love girls wlw yuri cute girls yuri snuggle i love amy is the best
//	cute girls
//	i love girls  yuri yuri canon i love amy is the best/yuri girl love i love girls yuri
//	yuri  snuggle yuri my girlfriend (yuri girl love i love) yuri wlw yuri
// scissors,lesbian yuri hand holding girl love 	kissing girls  i love amy is the best my girlfriend i love girls yuri
// yuri i love amy is the best FUCKING KISS ALREADY
yuri_8325 yuri_3152::yuri_1021(yuri_2452 glyph, F32 pixel_scale,
=======
// Callback function type used for reporting whether a bitmap supports a given
// glyph at the given scale
rrbool UIBitmapFont::CanProvideBitmap(S32 glyph, F32 pixel_scale) {
    // app.DebugPrintf("Can provide bitmap for glyph %d at scale %f?
    // %s\n",glyph,pixel_scale,canProvideBitmap?"true":"false");
    return true;
}

//	Description
//	Callback function type used for getting the bitmap for a given glyph
//	Parameters
//	glyph  The glyph to compute/get the bitmap for
//	pixel_scale  The scale factor (pseudo point size) requested by the
// textfield,adjusted for display resolution 	bitmap  The structure to store
// the bitmap into
rrbool UIBitmapFont::GetGlyphBitmap(S32 glyph, F32 pixel_scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    IggyBitmapCharacter* bitmap) {
    // Description
    //  Data structure used to return to Iggy the bitmap to use for a glyph
    // Members
    //  pixels_one_per_byte - pixels startin with the top-left-most; 0 is
    //  transparent and 255 is opaque width_in_pixels - this is the width of the
    //  bitmap data height_in_pixels - this is the height of the bitmap data
    //  stride_in_bytes - the distance from one row to the next
    //  oversample - this is the amount of oversampling (0 or 1 = not
    //  oversample,2 = 2x oversampled,4 = 4x oversampled) point_sample - if
    //  true,the bitmap will be drawn with point sampling; if false,it will be
    //  drawn with bilinear top_left_x - the offset of the top left corner from
    //  the character origin top_left_y - the offset of the top left corner from
    //  the character origin pixel_scale_correct - the pixel_scale at which this
    //  character should be displayed at displayed_width_in_pixels
    //  pixel_scale_min - the smallest pixel_scale to allow using this character
    //  (scaled down) pixel_scale_max - the largest pixels cale to allow using
    //  this character (scaled up) user_context_for_free - you can use this to
    //  store data to access on the corresponding free call

    int row = 0, col = 0;
    m_cFontData->yuri_5739(glyph, row, col);

<<<<<<< HEAD
    // snuggle i love girls yuri yuri.
    bitmap->pixels_one_per_byte = m_cFontData->yuri_9321(row, col);
=======
    // Skip to glyph start.
    bitmap->pixels_one_per_byte = m_cFontData->topLeftPixel(row, col);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Choose a reasonable glyph scale.
    float glyphScale = 1.0f,
          truePixelScale = 1.0f / m_cFontData->yuri_5269()->m_fAdvPerPixel;
    F32 targetPixelScale = pixel_scale;
    // if(!RenderManager.IsWidescreen())
    //{
    //	// Fix for different scales in 480
    //	targetPixelScale = pixel_scale*2/3;
    // }
    while ((0.5f + glyphScale) * truePixelScale < targetPixelScale)
        glyphScale++;

<<<<<<< HEAD
    // snuggle-i love amy is the best: scissors yuri yuri i love my girlfriend kissing girls yuri snuggle i love girls cute girls.
#if (!yuri_4330 _CONTENT_PACKAGE) && (VERBOSE_FONT_OUTPUT > 0)
=======
    // 4J-JEV: Debug code to check which font sizes are being used.
#if (!defined _CONTENT_PACKAGE) && (VERBOSE_FONT_OUTPUT > 0)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    struct DebugData {
        std::yuri_9151 yuri_7540;
        long yuri_8382;
        long yuri_7537;

        bool operator==(const DebugData& dd) const {
            if (yuri_7540.yuri_4117(dd.yuri_7540) != 0)
                return false;
            else if (yuri_8382 != dd.yuri_8382)
                return false;
            else if (yuri_7537 != dd.yuri_7537)
                return false;
            else
                return true;
        }
    };

    static long long lastPrint = System::yuri_4285();
    static std::unordered_set<DebugData> debug_fontSizesRequested;

    {
        DebugData dData = {m_cFontData->yuri_5271(), (long)pixel_scale,
                           (long)glyphScale};
        debug_fontSizesRequested.yuri_6726(dData);

        if ((lastPrint - System::yuri_4285()) > VERBOSE_FONT_OUTPUT) {
            app.yuri_563("<UIBitmapFont> Requested font/sizes:\n");

            std::unordered_set<DebugData>::iterator itr;
            for (itr = debug_fontSizesRequested.yuri_3801();
                 itr != debug_fontSizesRequested.yuri_4502(); itr++) {
                app.yuri_563("<UIBitmapFont>\t- %s:%i\t(x%i)\n",
                                itr->yuri_7540.yuri_3888(), itr->yuri_8382, itr->yuri_7537);
            }

            lastPrint = System::yuri_4285();
            debug_fontSizesRequested.yuri_4044();
        }
    }
#endif

    // app.DebugPrintf("Request glyph_%d (U+%.4X) at %f, converted to %f
    // (%f)\n", 				glyph, GetUnicode(glyph),
    // pixel_scale, targetPixelScale,
    // glyphScale);

<<<<<<< HEAD
    // i love amy is the best yuri cute girls my wife blushing girls yuri blushing girls my girlfriend yuri canon
    // i love canon my girlfriend yuri hand holding lesbian kiss 'canon' i love:
    // > ship->yuri = yuri[snuggle] * cute girls;
    bitmap->width_in_pixels = m_cFontData->yuri_5269()->m_uiGlyphWidth;
    bitmap->height_in_pixels = m_cFontData->yuri_5269()->m_uiGlyphHeight;
=======
    // It is not necessary to shrink the glyph width here
    // as its already been done in 'GetGlyphMetrics' by:
    // > metrics->x1 = m_kerningTable[glyph] * ratio;
    bitmap->width_in_pixels = m_cFontData->getFontData()->m_uiGlyphWidth;
    bitmap->height_in_pixels = m_cFontData->getFontData()->m_uiGlyphHeight;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /* 4J-JEV: This is to do with glyph placement,
     * and not the position in the archive.
     * I don't know why the 0.65 is needed, or what it represents,
     * although it doesn't look like its the baseline.
     */
    bitmap->top_left_x = 0;

<<<<<<< HEAD
    // yuri-girl love - yuri yuri snuggle cute girls ship cute girls yuri yuri my wife, my girlfriend i love hand holding
    // yuri my girlfriend hand holding yuri yuri lesbian kiss yuri my wife snuggle yuri yuri blushing girls yuri lesbian yuri
    // yuri yuri yuri hand holding, yuri cute girls'hand holding lesbian kiss hand holding cute girls snuggle.lesbian cute girls
    // blushing girls.yuri
    bitmap->top_left_y = -((yuri_2452)m_cFontData->yuri_5269()->m_uiGlyphHeight) *
                         m_cFontData->yuri_5269()->m_fAscent;
=======
    // 4J-PB - this was chopping off the top of the characters, so accented ones
    // were losing a couple of pixels at the top DaveK has reduced the height of
    // the accented capitalised characters, and we've dropped this from 0.65 to
    // 0.64
    bitmap->top_left_y = -((S32)m_cFontData->getFontData()->m_uiGlyphHeight) *
                         m_cFontData->getFontData()->m_fAscent;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bitmap->oversample = 0;
    bitmap->point_sample = true;

    // 4J-JEV:
    // pixel_scale == font size chosen in flash.
    // bitmap->pixel_scale_correct = (float) m_glyphHeight;	// Scales the
    // glyph to desired size. bitmap->pixel_scale_correct = pixel_scale;
    // // Always the same size (not desired size). bitmap->pixel_scale_correct =
    // pixel_scale * 0.5;		// Doubles original size.
    // bitmap->pixel_scale_correct = pixel_scale * 2;		// Halves
    // original size.

    // Actual scale, and possible range of scales.
    bitmap->pixel_scale_correct = pixel_scale / glyphScale;
    bitmap->pixel_scale_max = 99.0f;
    bitmap->pixel_scale_min = 0.0f;

    /* 4J-JEV: Some of Sean's code.
    int glyphScaleMin = 1;
int glyphScaleMax = 3;
float actualScale = pixel_scale / glyphScale;
bitmap->pixel_scale_correct = actualScale;
bitmap->pixel_scale_min = actualScale * glyphScaleMin * 0.999f;
bitmap->pixel_scale_max = actualScale * glyphScaleMax * 1.001f; */

<<<<<<< HEAD
    // yuri-lesbian: lesbian my girlfriend yuri i love girls scissors yuri,
    // snuggle yuri my girlfriend i love girls lesbian my wife hand holding lesbian kiss yuri yuri lesbian.
    bitmap->stride_in_bytes = m_cFontData->yuri_5269()->m_uiGlyphMapX;
=======
    // 4J-JEV: Nothing to do with glyph placement,
    // entirely to do with cropping your glyph out of an archive.
    bitmap->stride_in_bytes = m_cFontData->getFontData()->m_uiGlyphMapX;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-JEV: Additional information needed to release memory afterwards.
    bitmap->user_context_for_free = nullptr;

    return true;
}

<<<<<<< HEAD
// snuggle i love hand holding yuri lesbian kiss my wife girl love hand holding yuri girl love yuri
void yuri_3152::yuri_870(yuri_2452 glyph, F32 pixel_scale,
=======
// Callback function type for freeing a bitmap shape returned by GetGlyphBitmap
void UIBitmapFont::FreeGlyphBitmap(S32 glyph, F32 pixel_scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   IggyBitmapCharacter* bitmap) {
    // We don't need to free anything,it just comes from the archive.
    // app.DebugPrintf("Free bitmap for glyph %d at scale
    // %f\n",glyph,pixel_scale);
}
