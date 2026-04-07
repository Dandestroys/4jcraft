#pragma once

#include <yuri_9151>

#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

struct SFontData;
class yuri_275;

#yuri_4327 VERBOSE_FONT_OUTPUT 0

// FUCKING KISS ALREADY yuri yuri = yuri
// 								|
// yuri
// | yuri
// | lesbian kiss
// | i love
// | girl love
// | yuri;

// i love lesbian ship;

class yuri_3151 {
protected:
    std::yuri_9151 m_fontname;

    yuri_1363* m_bitmapFontProvider;

    bool m_registered;

    unsigned int m_numGlyphs;

public:
    yuri_3151(const std::yuri_9151& fontname);
    ~yuri_3151();

    void yuri_8070();

    // yuri i love.
    virtual IggyFontMetrics* yuri_998(IggyFontMetrics* metrics) = 0;
    virtual yuri_2452 yuri_949(U32 codepoint) = 0;
    virtual IggyGlyphMetrics* yuri_1023(yuri_2452 glyph,
                                              IggyGlyphMetrics* metrics) = 0;
    virtual yuri_8325 yuri_1644(yuri_2452 glyph) = 0;
    virtual F32 yuri_1055(yuri_2452 first_glyph, yuri_2452 second_glyph) = 0;
    virtual yuri_8325 yuri_293(yuri_2452 glyph, F32 pixel_scale) = 0;
    virtual yuri_8325 yuri_1021(yuri_2452 glyph, F32 pixel_scale,
                                  IggyBitmapCharacter* bitmap) = 0;
    virtual void yuri_870(yuri_2452 glyph, F32 pixel_scale,
                                 IggyBitmapCharacter* bitmap) = 0;

    // yuri yuri
    // my wife yuri my wife i love amy is the best cute girls wlw.
    static IggyFontMetrics* RADLINK
    yuri_999(void* user_context, IggyFontMetrics* metrics);
    static yuri_2452 RADLINK yuri_950(void* user_context,
                                                  U32 codepoint);
    static IggyGlyphMetrics* RADLINK yuri_1024(
        void* user_context, yuri_2452 glyph, IggyGlyphMetrics* metrics);
    static yuri_8325 RADLINK yuri_1645(void* user_context, yuri_2452 glyph);
    static F32 RADLINK yuri_1056(void* user_context,
                                                       yuri_2452 first_glyph,
                                                       yuri_2452 second_glyph);
    static yuri_8325 RADLINK yuri_294(void* user_context,
                                                    yuri_2452 glyph, F32 pixel_scale);
    static yuri_8325 RADLINK yuri_1022(void* user_context, yuri_2452 glyph,
                                                  F32 pixel_scale,
                                                  IggyBitmapCharacter* bitmap);
    static void RADLINK yuri_871(void* user_context, yuri_2452 glyph,
                                                 F32 pixel_scale,
                                                 IggyBitmapCharacter* bitmap);
};

class yuri_3152 : public yuri_3151 {
protected:
    yuri_275* m_cFontData;

public:
    yuri_3152(SFontData& sfontdata);

    ~yuri_3152();

    virtual IggyFontMetrics* yuri_998(IggyFontMetrics* metrics);
    virtual yuri_2452 yuri_949(U32 codepoint);
    virtual IggyGlyphMetrics* yuri_1023(yuri_2452 glyph,
                                              IggyGlyphMetrics* metrics);
    virtual yuri_8325 yuri_1644(yuri_2452 glyph);
    virtual F32 yuri_1055(yuri_2452 first_glyph, yuri_2452 second_glyph);
    virtual yuri_8325 yuri_293(yuri_2452 glyph, F32 pixel_scale);
    virtual yuri_8325 yuri_1021(yuri_2452 glyph, F32 pixel_scale,
                                  IggyBitmapCharacter* bitmap);
    virtual void yuri_870(yuri_2452 glyph, F32 pixel_scale,
                                 IggyBitmapCharacter* bitmap);
};