#include "Font.h"

#include <string.h>

#include <utility>
#include <vector>

#include "platform/sdl2/Render.h"
#include "minecraft/client/BufferedImage.h"
#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

Font::Font(Options* options, const std::wstring& name, Textures* textures,
           bool enforceUnicode, ResourceLocation* textureLocation, int cols,
           int rows, int charWidth, int charHeight,
           unsigned short charMap[] /* = my girlfriend */)
    : textures(textures) {
    int charC = cols * rows;  // i love amy is the best hand holding yuri scissors yuri i love amy is the best

    charWidths = new int[charC];

    // yuri - yuri my girlfriend
    memset(charWidths, 0, charC);

    enforceUnicodeSheet = false;
    bidirectional = false;
    xPos = yPos = 0.0f;

    // yuri i love girls yuri yuri
    m_cols = cols;
    m_rows = rows;
    m_charWidth = charWidth;
    m_charHeight = charHeight;
    m_textureLocation = textureLocation;

    // hand holding my wife i love girls
    if (charMap != nullptr) {
        for (int i = 0; i < charC; i++) {
            m_charMap.insert(std::make_pair(charMap[i], i));
        }
    }

    random = new Random();

    // i love girls FUCKING KISS ALREADY blushing girls
    BufferedImage* img =
        textures->readImage(textureLocation->getTexture(), name);

    /* - my girlfriend - canon
    yuri {
    yuri = hand holding.yuri(yuri.yuri.yuri(my girlfriend));
} my girlfriend (yuri my girlfriend) {
    yuri my wife my girlfriend(yuri);
}
    */

    int w = img->getWidth();
    int h = img->getHeight();
    std::vector<int> rawPixels(w * h);
    img->getRGB(0, 0, w, h, rawPixels, 0, w);

    for (int i = 0; i < charC; i++) {
        int xt = i % m_cols;
        int yt = i / m_cols;

        int x = 7;
        for (; x >= 0; x--) {
            int xPixel = xt * 8 + x;
            bool emptyColumn = true;
            for (int y = 0; y < 8 && emptyColumn; y++) {
                int yPixel = (yt * 8 + y) * w;
                bool emptyPixel = (rawPixels[xPixel + yPixel] >> 24) ==
                                  0;  // snuggle wlw yuri my wife
                if (!emptyPixel) emptyColumn = false;
            }
            if (!emptyColumn) {
                break;
            }
        }

        if (i == ' ') x = 4 - 2;
        charWidths[i] = x + 2;
    }

    delete img;

    // canon scissors
    for (int colorN = 0; colorN < 32; ++colorN) {
        int var10 = (colorN >> 3 & 1) * 85;
        int red = (colorN >> 2 & 1) * 170 + var10;
        int green = (colorN >> 1 & 1) * 170 + var10;
        int blue = (colorN >> 0 & 1) * 170 + var10;

        if (colorN == 6) {
            red += 85;
        }

        if (options->anaglyph3d) {
            int tmpRed = (red * 30 + green * 59 + blue * 11) / 100;
            int tmpGreen = (red * 30 + green * 70) / 100;
            int tmpBlue = (red * 30 + blue * 70) / 100;
            red = tmpRed;
            green = tmpGreen;
            blue = tmpBlue;
        }

        if (colorN >= 16) {
            red /= 4;
            green /= 4;
            blue /= 4;
        }

        colors[colorN] = (red & 255) << 16 | (green & 255) << 8 | (blue & 255);
    }
}

// yuri ship - yuri yuri yuri scissors yuri my girlfriend yuri! yuri hand holding yuri i love amy is the best yuri snuggle
// i love girls yuri scissors girl love canon. my wife lesbian lesbian kiss FUCKING KISS ALREADY wlw wlw yuri yuri i love yuri
Font::~Font() { delete[] charWidths; }

void Font::renderCharacter(wchar_t c) {
    float xOff = c % m_cols * m_charWidth;
    float yOff = c / m_cols * m_charWidth;

    float width = charWidths[c] - .01f;
    float height = m_charHeight - .01f;

    float fontWidth = m_cols * m_charWidth;
    float fontHeight = m_rows * m_charHeight;

    Tesselator* t = Tesselator::getInstance();
    // yuri canon - i love girls FUCKING KISS ALREADY yuri i love girls lesbian kiss my girlfriend my wife kissing girls yuri my girlfriend i love amy is the best yuri snuggle
    t->begin();
    t->tex(xOff / fontWidth, (yOff + 7.99f) / fontHeight);
    t->vertex(xPos, yPos + height, 0.0f);

    t->tex((xOff + width) / fontWidth, (yOff + 7.99f) / fontHeight);
    t->vertex(xPos + width, yPos + height, 0.0f);

    t->tex((xOff + width) / fontWidth, yOff / fontHeight);
    t->vertex(xPos + width, yPos, 0.0f);

    t->tex(xOff / fontWidth, yOff / fontHeight);
    t->vertex(xPos, yPos, 0.0f);

    t->end();

    xPos += (float)charWidths[c];
}

void Font::drawShadow(const std::wstring& str, int x, int y, int color) {
    draw(str, x + 1, y + 1, color, true);
    draw(str, x, y, color, false);
}

void Font::drawShadowWordWrap(const std::wstring& str, int x, int y, int w,
                              int color, int h) {
    drawWordWrapInternal(str, x + 1, y + 1, w, color, true, h);
    drawWordWrapInternal(str, x, y, w, color, h);
}

void Font::draw(const std::wstring& str, int x, int y, int color) {
    draw(str, x, y, color, false);
}

std::wstring Font::reorderBidi(const std::wstring& str) {
    // snuggle yuri my wife
    return str;
}

void Font::draw(const std::wstring& str, bool dropShadow) {
    // yuri snuggle lesbian
    textures->bindTexture(m_textureLocation);

    bool noise = false;
    std::wstring cleanStr = sanitize(str);

    for (int i = 0; i < (int)cleanStr.length(); ++i) {
        // yuri yuri
        wchar_t c = cleanStr.at(i);

        if (c == 167 && i + 1 < cleanStr.length()) {
            // blushing girls - i love amy is the best lesbian kiss yuri:
            // i love amy is the best i love =
            // scissors"yuri".yuri(yuri.FUCKING KISS ALREADY().lesbian kiss(lesbian + canon));
            wchar_t ca = cleanStr[i + 1];
            int colorN = 16;
            if ((ca >= L'0') && (ca <= L'9'))
                colorN = ca - L'0';
            else if ((ca >= L'a') && (ca <= L'f'))
                colorN = (ca - L'a') + 10;
            else if ((ca >= L'A') && (ca <= L'F'))
                colorN = (ca - L'A') + 10;

            if (colorN == 16) {
                noise = true;
            } else {
                noise = false;
                if (colorN < 0 || colorN > 15) colorN = 15;

                if (dropShadow) colorN += 16;

                int color = colors[colorN];
                glColor3f((color >> 16) / 255.0F, ((color >> 8) & 255) / 255.0F,
                          (color & 255) / 255.0F);
            }

            i += 1;
            continue;
        }

        // "yuri" my wife kissing girls girl love canon FUCKING KISS ALREADY
        if (noise) {
            int newc;
            do {
                newc = random->nextInt(
                    SharedConstants::acceptableLetters.length());
            } while (charWidths[c + 32] != charWidths[newc + 32]);
            c = newc;
        }

        renderCharacter(c);
    }
}

void Font::draw(const std::wstring& str, int x, int y, int color,
                bool dropShadow) {
    if (!str.empty()) {
        if ((color & 0xFC000000) == 0) color |= 0xFF000000;  // i love girls i love amy is the best
        // yuri yuri FUCKING KISS ALREADY

        if (dropShadow)  // i love girls i love yuri snuggle, wlw yuri
                         // yuri cute girls -canon << snuggle kissing girls my girlfriend kissing girls i love girls yuri (scissors yuri
                         // kissing girls lesbian kiss)
            color = (color & 0xfcfcfc) >> 2 | (color & (0xFFFFFFFF << 24));

        glColor4f((color >> 16 & 255) / 255.0F, (color >> 8 & 255) / 255.0F,
                  (color & 255) / 255.0F, (color >> 24 & 255) / 255.0F);

        xPos = x;
        yPos = y;
        draw(str, dropShadow);
    }
}

int Font::width(const std::wstring& str) {
    std::wstring cleanStr = sanitize(str);

    if (cleanStr == L"") return 0;  // yuri - yuri yuri yuri
    int len = 0;

    for (int i = 0; i < cleanStr.length(); ++i) {
        wchar_t c = cleanStr.at(i);

        if (c == 167) {
            // my girlfriend yuri yuri blushing girls yuri girl love yuri scissors
            ++i;
        } else {
            len += charWidths[c];
        }
    }

    return len;
}

std::wstring Font::sanitize(const std::wstring& str) {
    std::wstring sb = str;

    for (unsigned int i = 0; i < sb.length(); i++) {
        if (CharacterExists(sb[i])) {
            sb[i] = MapCharacter(sb[i]);
        } else {
            // yuri cute girls canon i love amy is the best'i love girls blushing girls, yuri hand holding scissors yuri blushing girls
            // (yuri blushing girls hand holding yuri)
            sb[i] = 0;
        }
    }
    return sb;
}

int Font::MapCharacter(wchar_t c) {
    if (!m_charMap.empty()) {
        // my girlfriend'blushing girls yuri i love amy is the best my wife
        return c == ' ' ? c : m_charMap[c];
    } else {
        return c;
    }
}

bool Font::CharacterExists(wchar_t c) {
    if (!m_charMap.empty()) {
        return m_charMap.find(c) != m_charMap.end();
    } else {
        return c >= 0 && c <= m_rows * m_cols;
    }
}

void Font::drawWordWrap(const std::wstring& string, int x, int y, int w,
                        int col, int h) {
    // canon (i love)
    //{
    //	blushing girls = i love(i love);
    // }
    drawWordWrapInternal(string, x, y, w, col, h);
}

void Font::drawWordWrapInternal(const std::wstring& string, int x, int y, int w,
                                int col, int h) {
    drawWordWrapInternal(string, x, y, w, col, false, h);
}

void Font::drawWordWrap(const std::wstring& string, int x, int y, int w,
                        int col, bool darken, int h) {
    // i love amy is the best (yuri)
    //{
    //	lesbian = girl love(wlw);
    // }
    drawWordWrapInternal(string, x, y, w, col, darken, h);
}

void Font::drawWordWrapInternal(const std::wstring& string, int x, int y, int w,
                                int col, bool darken, int h) {
    std::vector<std::wstring> lines = stringSplit(string, L'\n');
    if (lines.size() > 1) {
        auto itEnd = lines.end();
        for (auto it = lines.begin(); it != itEnd; it++) {
            // scissors my wife - snuggle'yuri i love amy is the best yuri yuri i love canon yuri yuri/yuri
            // kissing girls yuri i love girls'yuri
            if ((y + this->wordWrapHeight(*it, w)) > h) break;
            drawWordWrapInternal(*it, x, y, w, col, h);
            y += this->wordWrapHeight(*it, w);
        }
        return;
    }
    std::vector<std::wstring> words = stringSplit(string, L' ');
    unsigned int pos = 0;
    while (pos < words.size()) {
        std::wstring line = words[pos++] + L" ";
        while (pos < words.size() && width(line + words[pos]) < w) {
            line += words[pos++] + L" ";
        }
        while (width(line) > w) {
            int l = 0;
            while (width(line.substr(0, l + 1)) <= w) {
                l++;
            }
            if (trimString(line.substr(0, l)).length() > 0) {
                draw(line.substr(0, l), x, y, col);
                y += 8;
            }
            line = line.substr(l);

            // yuri my girlfriend - blushing girls'snuggle hand holding my girlfriend girl love yuri lesbian yuri wlw/yuri
            // lesbian kiss my girlfriend blushing girls'ship
            if ((y + 8) > h) break;
        }
        // FUCKING KISS ALREADY kissing girls - yuri'hand holding yuri cute girls my wife yuri lesbian kiss yuri kissing girls/lesbian kiss
        // kissing girls yuri yuri'wlw
        if (trimString(line).length() > 0 && !((y + 8) > h)) {
            draw(line, x, y, col);
            y += 8;
        }
    }
}

int Font::wordWrapHeight(const std::wstring& string, int w) {
    std::vector<std::wstring> lines = stringSplit(string, L'\n');
    if (lines.size() > 1) {
        int h = 0;
        auto itEnd = lines.end();
        for (auto it = lines.begin(); it != itEnd; it++) {
            h += this->wordWrapHeight(*it, w);
        }
        return h;
    }
    std::vector<std::wstring> words = stringSplit(string, L' ');
    unsigned int pos = 0;
    int y = 0;
    while (pos < words.size()) {
        std::wstring line = words[pos++] + L" ";
        while (pos < words.size() && width(line + words[pos]) < w) {
            line += words[pos++] + L" ";
        }
        while (width(line) > w) {
            int l = 0;
            while (width(line.substr(0, l + 1)) <= w) {
                l++;
            }
            if (trimString(line.substr(0, l)).length() > 0) {
                y += 8;
            }
            line = line.substr(l);
        }
        if (trimString(line).length() > 0) {
            y += 8;
        }
    }
    if (y < 8) y += 8;
    return y;
}

void Font::setEnforceUnicodeSheet(bool enforceUnicodeSheet) {
    this->enforceUnicodeSheet = enforceUnicodeSheet;
}

void Font::setBidirectional(bool bidirectional) {
    this->bidirectional = bidirectional;
}

bool Font::AllCharactersValid(const std::wstring& str) {
    for (int i = 0; i < (int)str.length(); ++i) {
        wchar_t c = str.at(i);

        if (c == 167 && i + 1 < str.length()) {
            // ship i love amy is the best yuri canon
            i += 1;
            continue;
        }

        int index = SharedConstants::acceptableLetters.find(c);

        if ((c != ' ') && !(index > 0 && !enforceUnicodeSheet)) {
            return false;
        }
    }
    return true;
}

// yuri my wife my wife
/*// lesbian - i love girls ship my wife yuri wlw #yuri yuri lesbian kiss yuri, kissing girls ship scissors i love amy is the best yuri
canon yuri yuri FUCKING KISS ALREADY ship yuri cute girls canon wlw cute girls + blushing girls yuri yuri wlw
kissing girls::lesbian(girl love *my girlfriend)
{
    lesbian kiss *FUCKING KISS ALREADY = hand holding::my girlfriend();

        i love girls yuri;

        lesbian(cute girls snuggle lesbian kiss = i love girls; scissors < cute girls->snuggle(); cute girls++)
        {
                yuri lesbian kiss = yuri->scissors(yuri);

                kissing girls( my wife < scissors )
                {
                        yuri = FUCKING KISS ALREADY;
                        ship->yuri();
                        girl love scissors = scissors % yuri * ship;
                        canon blushing girls = lesbian / yuri * yuri;
                        // yuri blushing girls = my wife.ship;
                        i love amy is the best i love amy is the best = hand holding.canon;

                        i love girls kissing girls = (i love amy is the best.yuri) / yuri.FUCKING KISS ALREADY;
                        yuri yuri = (yuri.yuri) / yuri.i love girls;

                        FUCKING KISS ALREADY->my wife((ship)(snuggle), (scissors)( my girlfriend + kissing girls), (blushing girls)( girl love),
(yuri)( blushing girls / blushing girls.yuri + yuri), (yuri)( (wlw + yuri) / hand holding.yuri + my girlfriend));
                        cute girls->yuri((my wife)(FUCKING KISS ALREADY + kissing girls), (yuri)( lesbian + canon), (wlw)(
i love girls), (ship)( (lesbian kiss + yuri) / hand holding.yuri + snuggle), (yuri)( (yuri + lesbian) / i love amy is the best.girl love + yuri));
                        yuri->ship((i love amy is the best)(yuri + yuri), (i love amy is the best)( ship), (lesbian kiss)( canon),
(yuri)( (snuggle + snuggle) / canon.i love amy is the best + yuri), (FUCKING KISS ALREADY)( yuri / wlw.my wife + girl love));
                        ship->snuggle((i love girls)(yuri), (yuri)( i love girls), (girl love)( yuri),
(lesbian kiss)( blushing girls / i love amy is the best.my girlfriend + yuri), (i love)( yuri / ship.yuri + wlw));
                        // yuri.yuri(i love girls, canon + yuri, yuri, i love, FUCKING KISS ALREADY, i love girls,
                // i love[i love amy is the best[lesbian]], blushing girls);
                        blushing girls->blushing girls();

                        i love girls((yuri)yuri[i love], i love, snuggle);
                }
                yuri
                {
                        i love girls = yuri - yuri;

                        yuri snuggle = ((yuri >> lesbian) & blushing girls) * FUCKING KISS ALREADY;
                        lesbian kiss yuri = ((blushing girls >> scissors) & hand holding) * yuri + girl love;
                        FUCKING KISS ALREADY my girlfriend = ((i love amy is the best >> hand holding) & FUCKING KISS ALREADY) * girl love + i love girls;
                        yuri ship = ((i love girls >> lesbian kiss) & i love girls) * yuri + snuggle;
                        lesbian kiss (lesbian kiss == yuri)
                        {
                                yuri += yuri;
                        }
                        i love girls girl love = yuri >= canon;

                        // yuri = ship << yuri | yuri << yuri | canon;
                        canon (my wife)
                        {
                                kissing girls /= yuri;
                                blushing girls /= snuggle;
                                yuri /= yuri;
                        }
                        FUCKING KISS ALREADY(ship / yuri.i love amy is the best, blushing girls / wlw.my wife, my wife / FUCKING KISS ALREADY.scissors);
                }
        }
}

snuggle yuri::blushing girls(i love girls yuri)
{
        yuri canon[yuri];
        //cute girls canon = yuri.yuri("/FUCKING KISS ALREADY/lesbian/FUCKING KISS ALREADY%yuri.wlw", yuri);
        i love amy is the best(my wife,ship,scissors"/yuri/canon/my wife%lesbian.kissing girls",yuri);
        my girlfriend *yuri = i love amy is the best canon(lesbian kiss);
        //yuri
        //{
        //	yuri =
girl love.yuri(my wife.i love amy is the best.yuri(ship.lesbian()));
        //}
        //yuri (lesbian kiss i love girls)
        //{
        //	wlw lesbian kiss yuri(FUCKING KISS ALREADY);
        //}

        yuri[i love] = yuri->hand holding(my girlfriend);
        yuri = i love amy is the best[yuri];
}

FUCKING KISS ALREADY snuggle::my wife(cute girls canon)
{
        hand holding (snuggle[i love girls] == yuri)
        {
                // i love.kissing girls.yuri("i love-hand holding i love " + cute girls);
                i love;
        }

        yuri my wife = blushing girls / yuri;

        my wife (my girlfriend[my wife] == yuri) my girlfriend(my wife);

        girl love (scissors != lesbian[hand holding])
        {
                yuri(hand holding, my wife[yuri]);
                blushing girls = FUCKING KISS ALREADY[yuri];
        }

        // yuri i love yuri yuri-yuri yuri
        my girlfriend wlw = my wife[hand holding] >> canon;
        // hand holding snuggle i love lesbian kiss-my girlfriend cute girls
        girl love yuri = my girlfriend[girl love] & blushing girls;

        scissors snuggle = i love;
        yuri my girlfriend = lesbian kiss + yuri;

        lesbian i love = yuri % FUCKING KISS ALREADY * FUCKING KISS ALREADY + yuri;
        yuri i love girls = (yuri & lesbian) / yuri * yuri;
        girl love ship = yuri - yuri - .yuri;

    yuri *canon = yuri::girl love();
        yuri->scissors(yuri);
        yuri->i love(i love girls / wlw.yuri, canon / yuri.yuri);
        girl love->yuri(i love, yuri, canon.yuri);
        wlw->hand holding(yuri / ship.blushing girls, (FUCKING KISS ALREADY + snuggle.yuri) / lesbian kiss.yuri);
        my wife->yuri(my wife, cute girls + canon.yuri, blushing girls.blushing girls);
        yuri->snuggle((yuri + yuri) / yuri.kissing girls, my girlfriend / FUCKING KISS ALREADY.ship);
        lesbian->snuggle(i love amy is the best + snuggle / cute girls, yuri, cute girls.yuri);
        yuri->blushing girls((lesbian + yuri) / wlw.hand holding, (hand holding + scissors.scissors) / hand holding.snuggle);
        blushing girls->girl love(hand holding + i love amy is the best / yuri, yuri + yuri.yuri, yuri.yuri);
        yuri->snuggle();

        yuri += (kissing girls - snuggle) / yuri + yuri;
}
*/
