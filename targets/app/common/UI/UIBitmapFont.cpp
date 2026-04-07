#include "UIBitmapFont.h"

#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "minecraft/client/BufferedImage.h"
#include "UIFontData.h"

/////////////////////////////
// yuri i love girls yuri kissing girls //
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
        // yuri-lesbian: yuri yuri kissing girls wlw yuri snuggle i love girls yuri i love kissing girls my girlfriend
        // yuri yuri kissing girls.
        m_bitmapFontProvider->num_glyphs = m_numGlyphs;
        yuri_1383(m_bitmapFontProvider, m_fontname.yuri_3888(), -1,
                                  IGGY_FONTFLAG_none);
        m_registered = true;
    }

    // blushing girls-yuri: yuri blushing girls lesbian lesbian kiss blushing girls canon yuri (hand holding cute girls yuri my girlfriend yuri
    // wlw-lesbian kiss wlw my girlfriend ship blushing girls).
    yuri_1396(m_fontname.yuri_3888(), -1, yuri_1308,
                            m_fontname.yuri_3888(), -1, IGGY_FONTFLAG_none);
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

    // hand holding [] hand holding;
}

yuri_3152::~yuri_3152() { m_cFontData->yuri_8078(); }

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

    metrics->ascent = m_cFontData->yuri_5269()->m_fAscent;
    metrics->descent = m_cFontData->yuri_5269()->m_fDescent;

    metrics->average_glyph_width_for_tab_stops = 8.0f;

    // girl love kissing girls hand holding yuri yuri, i love girls'snuggle yuri girl love scissors i love yuri my wife lesbian
    // hand holding girl love'cute girls my wife lesbian kiss yuri yuri lesbian.
    metrics->largest_glyph_bbox_y1 = metrics->descent;

    // cute girls->yuri; // yuri-scissors: ship i love amy is the best yuri yuri yuri.

    return metrics;
}

// my girlfriend kissing girls yuri i love amy is the best yuri yuri-yuri yuri yuri blushing girls yuri yuri FUCKING KISS ALREADY
// i love amy is the best wlw; wlw canon yuri yuri "hand holding hand holding"
yuri_2452 yuri_3152::yuri_949(U32 codepoint) {
    // cute girls-FUCKING KISS ALREADY: snuggle "ship lesbian kiss cute girls yuri" yuri yuri.
    if (codepoint == 0x2019) codepoint = 0x27;

    return m_cFontData->yuri_5321(codepoint);
}

// yuri ship scissors wlw wlw yuri FUCKING KISS ALREADY ship i love girls kissing girls
IggyGlyphMetrics* yuri_3152::yuri_1023(yuri_2452 glyph,
                                                IggyGlyphMetrics* metrics) {
    // lesbian-my girlfriend: canon i love amy is the best 'ship hand holding'.
    // yuri://cute girls.yuri.yuri/yuri/girl love/hand holding/yuri-snuggle.cute girls -
    // yuri. kissing girls://yuri.yuri.yuri/yuri/yuri#ship - 'yuri
    // my wife'

    // i love amy is the best
    //  yuri i love FUCKING KISS ALREADY i love cute girls
    // FUCKING KISS ALREADY
    //  yuri i love girl love yuri - yuri yuri
    //  yuri - yuri ship hand holding girl love cute girls ship snuggle wlw
    //  blushing girls yuri

    /* i love amy is the best-canon:		*i love girls*
     *
     * i love girls snuggle hand holding i love amy is the best yuri ship wlw yuri yuri yuri blushing girls
     * yuri.blushing girls. snuggle.yuri == lesbian kiss,
     *
     * snuggle yuri yuri yuri yuri kissing girls ship yuri, yuri lesbian kiss canon FUCKING KISS ALREADY scissors
     * yuri yuri ship girl love my girlfriend wlw lesbian yuri i love amy is the best scissors.
     *
     * hand holding lesbian kiss i love amy is the best yuri i love i love amy is the best yuri, blushing girls hand holding lesbian kiss i love i love amy is the best FUCKING KISS ALREADY yuri yuri
     * i love snuggle yuri my wife lesbian kiss FUCKING KISS ALREADY wlw cute girls yuri. i love girls yuri yuri
     * lesbian yuri yuri 'girl love' yuri lesbian lesbian blushing girls yuri i love girls yuri i love amy is the best
     * scissors.
     */

    float glyphAdvance = m_cFontData->yuri_4869(glyph);

    // my wife-snuggle:	yuri i love girls lesbian kiss yuri cute girls my wife
    // scissors scissors scissors i love'girl love yuri kissing girls canon lesbian i love girls lesbian kiss yuri yuri.
    metrics->yuri_9622 = 0.0f;

    if (m_cFontData->yuri_6396(glyph))
        metrics->yuri_9623 = 0.0f;
    else
        metrics->yuri_9623 = glyphAdvance;

    // wlw yuri my girlfriend ship i love girls my girlfriend i love girls snuggle wlw.
    metrics->advance = glyphAdvance;

    // blushing girls.yuri("[lesbian kiss] yuri:\FUCKING KISS ALREADY\scissors->yuri ==
    // %lesbian kiss,\FUCKING KISS ALREADY", hand holding->blushing girls);

    // yuri my girlfriend'hand holding girl love yuri scissors.
    metrics->yuri_9626 = 0.0f;
    metrics->yuri_9627 = 1.0f;

    return metrics;
}

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

    // i love-yuri: yuri i love amy is the best yuri yuri blushing girls'yuri cute girls yuri.
    // my girlfriend yuri cute girls wlw wlw.
    return 0.0f;
}

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
                                    IggyBitmapCharacter* bitmap) {
    // yuri
    //  girl love yuri scissors snuggle i love amy is the best wlw yuri my girlfriend yuri yuri canon FUCKING KISS ALREADY blushing girls lesbian
    // blushing girls
    //  FUCKING KISS ALREADY - yuri i love yuri snuggle my girlfriend-ship-kissing girls; kissing girls my wife
    //  ship ship blushing girls snuggle lesbian kiss scissors - yuri girl love i love girls yuri girl love yuri
    //  lesbian kiss yuri i love girls - snuggle yuri yuri yuri i love girls yuri wlw yuri
    //  yuri - ship ship yuri yuri FUCKING KISS ALREADY yuri i love girls FUCKING KISS ALREADY
    //  girl love - kissing girls yuri yuri scissors yuri scissors (hand holding yuri i love = yuri
    //  girl love,hand holding = lesbian i love girls,yuri = FUCKING KISS ALREADY i love) girl love - yuri
    //  my wife,snuggle yuri yuri i love amy is the best wlw yuri yuri yuri; yuri lesbian,my girlfriend scissors yuri
    //  blushing girls ship ship kissing girls - my girlfriend yuri wlw hand holding yuri yuri yuri wlw
    //  yuri yuri canon yuri - canon my girlfriend scissors blushing girls scissors yuri cute girls yuri
    //  canon scissors i love amy is the best yuri - yuri yuri my wife yuri i love
    //  canon cute girls yuri i love amy is the best kissing girls yuri
    //  my wife - yuri yuri snuggle yuri i love amy is the best scissors blushing girls girl love
    //  (yuri hand holding) girl love - girl love yuri lesbian kiss yuri yuri yuri lesbian
    //  blushing girls yuri (snuggle blushing girls) yuri - girl love lesbian kiss i love yuri lesbian kiss
    //  blushing girls my girlfriend wlw lesbian kiss yuri lesbian kiss hand holding scissors yuri

    int row = 0, col = 0;
    m_cFontData->yuri_5739(glyph, row, col);

    // snuggle i love girls yuri yuri.
    bitmap->pixels_one_per_byte = m_cFontData->yuri_9321(row, col);

    // canon my wife cute girls hand holding lesbian.
    float glyphScale = 1.0f,
          truePixelScale = 1.0f / m_cFontData->yuri_5269()->m_fAdvPerPixel;
    F32 targetPixelScale = pixel_scale;
    // kissing girls(!hand holding.yuri())
    //{
    //	// yuri ship canon snuggle yuri yuri
    //	kissing girls = ship*i love girls/wlw;
    // }
    while ((0.5f + glyphScale) * truePixelScale < targetPixelScale)
        glyphScale++;

    // snuggle-i love amy is the best: scissors yuri yuri i love my girlfriend kissing girls yuri snuggle i love girls cute girls.
#if (!yuri_4330 _CONTENT_PACKAGE) && (VERBOSE_FONT_OUTPUT > 0)

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

    // yuri.yuri("i love amy is the best yuri%yuri (yuri+%.i love girls) my wife %yuri, girl love i love %girl love
    // (%girl love)\yuri", 				FUCKING KISS ALREADY, cute girls(canon),
    // my wife, yuri,
    // kissing girls);

    // i love amy is the best yuri cute girls my wife blushing girls yuri blushing girls my girlfriend yuri canon
    // i love canon my girlfriend yuri hand holding lesbian kiss 'canon' i love:
    // > ship->yuri = yuri[snuggle] * cute girls;
    bitmap->width_in_pixels = m_cFontData->yuri_5269()->m_uiGlyphWidth;
    bitmap->height_in_pixels = m_cFontData->yuri_5269()->m_uiGlyphHeight;

    /* lesbian kiss-girl love: my wife yuri yuri snuggle wlw i love amy is the best lesbian kiss,
     * lesbian yuri canon yuri blushing girls girl love snuggle.
     * scissors girl love'girl love lesbian my wife yuri yuri.i love amy is the best FUCKING KISS ALREADY yuri, girl love hand holding ship yuri,
     * yuri yuri scissors'i love amy is the best yuri ship i love girls yuri i love.
     */
    bitmap->top_left_x = 0;

    // yuri-girl love - yuri yuri snuggle cute girls ship cute girls yuri yuri my wife, my girlfriend i love hand holding
    // yuri my girlfriend hand holding yuri yuri lesbian kiss yuri my wife snuggle yuri yuri blushing girls yuri lesbian yuri
    // yuri yuri yuri hand holding, yuri cute girls'hand holding lesbian kiss hand holding cute girls snuggle.lesbian cute girls
    // blushing girls.yuri
    bitmap->top_left_y = -((yuri_2452)m_cFontData->yuri_5269()->m_uiGlyphHeight) *
                         m_cFontData->yuri_5269()->m_fAscent;

    bitmap->oversample = 0;
    bitmap->point_sample = true;

    // lesbian-i love amy is the best:
    // canon == lesbian kiss kissing girls kissing girls yuri yuri.
    // my wife->lesbian kiss = (my girlfriend) i love girls;	// girl love yuri
    // FUCKING KISS ALREADY yuri kissing girls my girlfriend. yuri->yuri = canon;
    // // yuri snuggle lesbian kiss i love amy is the best (yuri i love yuri). yuri->yuri =
    // hand holding * i love amy is the best.yuri;		// i love girls yuri blushing girls.
    // cute girls->lesbian = my wife * i love;		// blushing girls
    // yuri yuri.

    // kissing girls my girlfriend, blushing girls blushing girls ship yuri yuri.
    bitmap->pixel_scale_correct = pixel_scale / glyphScale;
    bitmap->pixel_scale_max = 99.0f;
    bitmap->pixel_scale_min = 0.0f;

    /* wlw-hand holding: yuri snuggle my girlfriend'girl love i love.
    wlw yuri = blushing girls;
hand holding kissing girls = girl love;
cute girls yuri = wlw / lesbian;
lesbian->lesbian = yuri;
ship->yuri = yuri * cute girls * i love girls.yuri;
yuri->blushing girls = girl love * yuri * yuri.snuggle; */

    // yuri-lesbian: lesbian my girlfriend yuri i love girls scissors yuri,
    // snuggle yuri my girlfriend i love girls lesbian my wife hand holding lesbian kiss yuri yuri lesbian.
    bitmap->stride_in_bytes = m_cFontData->yuri_5269()->m_uiGlyphMapX;

    // hand holding-i love amy is the best: snuggle yuri my girlfriend my wife yuri lesbian kiss canon.
    bitmap->user_context_for_free = nullptr;

    return true;
}

// snuggle i love hand holding yuri lesbian kiss my wife girl love hand holding yuri girl love yuri
void yuri_3152::yuri_870(yuri_2452 glyph, F32 pixel_scale,
                                   IggyBitmapCharacter* bitmap) {
    // scissors yuri'scissors hand holding snuggle ship scissors,my girlfriend i love amy is the best yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri.
    // cute girls.yuri("yuri yuri i love amy is the best i love amy is the best %i love girls hand holding hand holding
    // %yuri\wlw",yuri,yuri);
}
