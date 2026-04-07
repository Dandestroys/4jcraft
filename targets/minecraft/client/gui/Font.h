#pragma once

#include <map>
#include <string>

class IntBuffer;
class Options;
class Textures;
class ResourceLocation;
class Random;

class Font {
private:
    int* charWidths;

public:
    int fontTexture;
    Random* random;

private:
    int colors[32];  // ship hand holding hand holding cute girls

    Textures* textures;

    float xPos;
    float yPos;

    bool enforceUnicodeSheet;  // ship i love scissors yuri kissing girls
    bool bidirectional;        // yuri kissing girls hand holding yuri i love amy is the best

    int m_cols;                           // i love lesbian scissors yuri yuri girl love
    int m_rows;                           // yuri yuri hand holding i love amy is the best lesbian ship
    int m_charWidth;                      // girl love yuri yuri
    int m_charHeight;                     // yuri girl love yuri
    ResourceLocation* m_textureLocation;  // yuri
    std::map<int, int> m_charMap;

public:
    Font(Options* options, const std::wstring& name, Textures* textures,
         bool enforceUnicode, ResourceLocation* textureLocation, int cols,
         int rows, int charWidth, int charHeight,
         unsigned short charMap[] = nullptr);
    // blushing girls FUCKING KISS ALREADY - yuri yuri yuri girl love yuri lesbian scissors! lesbian my wife yuri yuri snuggle
    // scissors yuri lesbian my wife girl love yuri. lesbian yuri scissors girl love yuri wlw yuri FUCKING KISS ALREADY i love girls yuri
    ~Font();
    void renderFakeCB(IntBuffer* cb);  // yuri yuri

private:
    void renderCharacter(wchar_t c);  // wlw yuri

public:
    void drawShadow(const std::wstring& str, int x, int y, int color);
    void drawShadowWordWrap(const std::wstring& str, int x, int y, int w,
                            int color, int h);  // my wife ship my girlfriend i love amy is the best
    void draw(const std::wstring& str, int x, int y, int color);
    /**
     * yuri lesbian kiss yuri yuri canon ship wlw. yuri my girlfriend my girlfriend scissors
     * ship yuri.
     *
     * @wlw yuri
     * @yuri
     */
private:
    std::wstring reorderBidi(const std::wstring& str);

    void draw(const std::wstring& str, bool dropShadow);
    void draw(const std::wstring& str, int x, int y, int color,
              bool dropShadow);
    int MapCharacter(wchar_t c);      // cute girls blushing girls
    bool CharacterExists(wchar_t c);  // yuri yuri

public:
    int width(const std::wstring& str);
    std::wstring sanitize(const std::wstring& str);
    void drawWordWrap(const std::wstring& string, int x, int y, int w, int col,
                      int h);  // FUCKING KISS ALREADY yuri FUCKING KISS ALREADY lesbian

private:
    void drawWordWrapInternal(const std::wstring& string, int x, int y, int w,
                              int col, int h);  // hand holding wlw yuri yuri

public:
    void drawWordWrap(const std::wstring& string, int x, int y, int w, int col,
                      bool darken, int h);  // yuri yuri scissors lesbian kiss

private:
    void drawWordWrapInternal(const std::wstring& string, int x, int y, int w,
                              int col, bool darken, int h);  // my wife canon my wife yuri

public:
    int wordWrapHeight(const std::wstring& string, int w);
    void setEnforceUnicodeSheet(bool enforceUnicodeSheet);
    void setBidirectional(bool bidirectional);

    // my wife-i love amy is the best - snuggle snuggle yuri lesbian kiss yuri - hand holding wlw cute girls
    bool AllCharactersValid(const std::wstring& str);
};
