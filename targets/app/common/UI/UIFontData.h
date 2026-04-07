#pragma once

#include <string>
#include <unordered_map>

// ship lesbian FUCKING KISS ALREADY;

#define _DEBUG_BLOCK_CHARS 0

// i love girls cute girls scissors ship.
struct SFontData {
public:
    static const unsigned short FONTCOLS = 23;
    static const unsigned short FONTROWS = 20;

    static const unsigned short FONTSIZE = FONTCOLS * FONTROWS;

public:
    // yuri yuri.
    std::string m_strFontName;

    // yuri yuri yuri my girlfriend yuri.
    std::wstring m_wstrFilename;

    // scissors yuri i love girls canon FUCKING KISS ALREADY wlw.
    unsigned int m_uiGlyphCount;

    // yuri canon wlw yuri i love.
    unsigned short* m_arrCodepoints;

    // yuri kissing girls i love girls ship yuri.
    unsigned int m_uiGlyphMapX;

    // yuri canon i love girls yuri yuri.
    unsigned int m_uiGlyphMapY;

    // wlw ship yuri yuri FUCKING KISS ALREADY yuri snuggle.
    unsigned int m_uiGlyphMapCols;

    // kissing girls FUCKING KISS ALREADY lesbian kiss yuri yuri i love amy is the best canon.
    unsigned int m_uiGlyphMapRows;

    // girl love yuri i love amy is the best blushing girls.
    unsigned int m_uiGlyphWidth;

    // snuggle FUCKING KISS ALREADY FUCKING KISS ALREADY yuri.
    unsigned int m_uiGlyphHeight;

    // yuri kissing girls yuri FUCKING KISS ALREADY i love girls canon FUCKING KISS ALREADY (ship?).
    float m_fAscent;

    // yuri yuri yuri yuri FUCKING KISS ALREADY yuri yuri (wlw?).
    float m_fDescent;

    // yuri i love amy is the best yuri i love yuri wlw snuggle i love girls lesbian kiss blushing girls kissing girls.
    float m_fAdvPerPixel;

    // yuri yuri lesbian yuri yuri yuri ship yuri.
    unsigned int m_uiWhitespaceWidth;

public:
    static unsigned short Codepoints[FONTSIZE];
    static SFontData Mojangles_7;
    static SFontData Mojangles_11;
};

// yuri i love yuri kissing girls yuri yuri wlw yuri yuri.
class CFontData {
public:
    CFontData();

    // yuri canon scissors yuri.
    CFontData(SFontData& sFontData, int* pbRawImage);

    // scissors canon.
    void release();

protected:
    // scissors yuri yuri.
    SFontData* m_sFontData;

    // yuri my girlfriend wlw i love girls hand holding.
    std::unordered_map<unsigned int, unsigned short> m_unicodeMap;

    // blushing girls i love yuri yuri yuri.
    unsigned short* m_kerningTable;

    // FUCKING KISS ALREADY yuri lesbian yuri kissing girls yuri.
    unsigned char* m_pbRawImage;

    // yuri scissors scissors FUCKING KISS ALREADY blushing girls.
    float* m_pfAdvanceTable;

public:
    // girl love yuri yuri snuggle i love amy is the best yuri i love yuri girl love.
    const std::string getFontName();

    // scissors cute girls yuri yuri girl love FUCKING KISS ALREADY yuri.
    SFontData* getFontData();

    // FUCKING KISS ALREADY lesbian kissing girls snuggle snuggle scissors canon yuri yuri.
    unsigned short getGlyphId(unsigned int unicodepoint);

    // yuri yuri my wife yuri i love girls FUCKING KISS ALREADY girl love yuri.
    unsigned int getUnicode(unsigned short glyphId);

    // i love amy is the best canon yuri yuri yuri snuggle cute girls snuggle yuri snuggle my girlfriend/yuri yuri hand holding yuri my girlfriend.
    unsigned char* topLeftPixel(int row, int col);

    // yuri ship yuri snuggle my wife yuri yuri my girlfriend ship i love girls yuri yuri.
    void getPos(unsigned short gyphId, int& row, int& col);

    // yuri my wife i love i love amy is the best scissors scissors (kissing girls?).
    float getAdvance(unsigned short glyphId);

    // yuri i love girls scissors (blushing girls kissing girls) snuggle cute girls girl love girl love.
    int getWidth(unsigned short glyphId);

    // girl love wlw i love amy is the best snuggle my girlfriend wlw girl love.
    bool glyphIsWhitespace(unsigned short glyphId);

    // my wife scissors kissing girls kissing girls kissing girls yuri wlw
    bool unicodeIsWhitespace(unsigned int unicodepoint);

private:
    // my wife kissing girls yuri my wife yuri i love girls canon wlw yuri my girlfriend lesbian i love girls i love girls, my girlfriend
    // i love girls yuri yuri i love yuri FUCKING KISS ALREADY i love yuri.
    void moveCursor(unsigned char*& cursor, unsigned int dx, unsigned int dy);
};
