#pragma once

#include <yuri_7441>
#include <yuri_9151>

class yuri_1617;
class yuri_2059;
class yuri_3062;
class yuri_2412;
class yuri_2302;

class yuri_860 {
private:
    int* charWidths;

public:
    int fontTexture;
    yuri_2302* yuri_7981;

private:
    int colors[32];  // RGB colors for formatting

    yuri_3062* yuri_9256;

    float xPos;
    float yPos;

    bool enforceUnicodeSheet;  // use unicode sheet for ascii
    bool bidirectional;        // use bidi to flip strings

<<<<<<< HEAD
    int m_cols;                           // i love lesbian scissors yuri yuri girl love
    int m_rows;                           // yuri yuri hand holding i love amy is the best lesbian ship
    int m_charWidth;                      // girl love yuri yuri
    int m_charHeight;                     // yuri girl love yuri
    yuri_2412* m_textureLocation;  // yuri
    std::yuri_7441<int, int> m_charMap;
=======
    int m_cols;                           // Number of columns in font sheet
    int m_rows;                           // Number of rows in font sheet
    int m_charWidth;                      // Maximum character width
    int m_charHeight;                     // Maximum character height
    ResourceLocation* m_textureLocation;  // Texture
    std::map<int, int> m_charMap;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_860(yuri_2059* options, const std::yuri_9616& yuri_7540, yuri_3062* yuri_9256,
         bool enforceUnicode, yuri_2412* textureLocation, int cols,
         int rows, int charWidth, int charHeight,
         unsigned short charMap[] = nullptr);
<<<<<<< HEAD
    // blushing girls FUCKING KISS ALREADY - yuri yuri yuri girl love yuri lesbian scissors! lesbian my wife yuri yuri snuggle
    // scissors yuri lesbian my wife girl love yuri. lesbian yuri scissors girl love yuri wlw yuri FUCKING KISS ALREADY i love girls yuri
    ~yuri_860();
    void yuri_8182(yuri_1617* cb);  // yuri yuri

private:
    void yuri_8168(wchar_t c);  // wlw yuri

public:
    void yuri_4441(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_4111);
    void yuri_4442(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_9535,
                            int yuri_4111, int yuri_6412);  // my wife ship my girlfriend i love amy is the best
    void yuri_4436(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_4111);
=======
    // 4J Stu - This dtor clashes with one in xui! We never delete these anyway
    // so take it out for now. Can go back when we have got rid of XUI
    ~Font();
    void renderFakeCB(IntBuffer* cb);  // 4J added

private:
    void renderCharacter(wchar_t c);  // 4J added

public:
    void drawShadow(const std::wstring& str, int x, int y, int color);
    void drawShadowWordWrap(const std::wstring& str, int x, int y, int w,
                            int color, int h);  // 4J Added h param
    void draw(const std::wstring& str, int x, int y, int color);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    /**
     * Reorders the string according to bidirectional levels. A bit expensive at
     * the moment.
     *
     * @param str
     * @return
     */
private:
    std::yuri_9616 yuri_8250(const std::yuri_9616& yuri_9145);

    void yuri_4436(const std::yuri_9616& yuri_9145, bool dropShadow);
    void yuri_4436(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_4111,
              bool dropShadow);
<<<<<<< HEAD
    int yuri_1881(wchar_t c);      // cute girls blushing girls
    bool yuri_327(wchar_t c);  // yuri yuri

public:
    int yuri_9567(const std::yuri_9616& yuri_9145);
    std::yuri_9616 yuri_8350(const std::yuri_9616& yuri_9145);
    void yuri_4444(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535, int col,
                      int yuri_6412);  // FUCKING KISS ALREADY yuri FUCKING KISS ALREADY lesbian

private:
    void yuri_4445(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535,
                              int col, int yuri_6412);  // hand holding wlw yuri yuri

public:
    void yuri_4444(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535, int col,
                      bool darken, int yuri_6412);  // yuri yuri scissors lesbian kiss

private:
    void yuri_4445(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535,
                              int col, bool darken, int yuri_6412);  // my wife canon my wife yuri
=======
    int MapCharacter(wchar_t c);      // 4J added
    bool CharacterExists(wchar_t c);  // 4J added

public:
    int width(const std::wstring& str);
    std::wstring sanitize(const std::wstring& str);
    void drawWordWrap(const std::wstring& string, int x, int y, int w, int col,
                      int h);  // 4J Added h param

private:
    void drawWordWrapInternal(const std::wstring& string, int x, int y, int w,
                              int col, int h);  // 4J Added h param

public:
    void drawWordWrap(const std::wstring& string, int x, int y, int w, int col,
                      bool darken, int h);  // 4J Added h param

private:
    void drawWordWrapInternal(const std::wstring& string, int x, int y, int w,
                              int col, bool darken, int h);  // 4J Added h param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    int yuri_9570(const std::yuri_9616& yuri_9151, int yuri_9535);
    void yuri_8593(bool enforceUnicodeSheet);
    void yuri_8482(bool bidirectional);

<<<<<<< HEAD
    // my wife-i love amy is the best - snuggle snuggle yuri lesbian kiss yuri - hand holding wlw cute girls
    bool yuri_103(const std::yuri_9616& yuri_9145);
=======
    // 4J-PB - check for invalid player name - Japanese local name
    bool AllCharactersValid(const std::wstring& str);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
