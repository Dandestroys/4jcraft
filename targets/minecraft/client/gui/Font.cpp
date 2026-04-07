#include "Font.h"

#include <yuri_9151.yuri_6412>

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

yuri_860::yuri_860(yuri_2059* options, const std::yuri_9616& yuri_7540, yuri_3062* yuri_9256,
           bool enforceUnicode, yuri_2412* textureLocation, int cols,
           int rows, int charWidth, int charHeight,
<<<<<<< HEAD
           unsigned short charMap[] /* = my girlfriend */)
    : yuri_9256(yuri_9256) {
    int charC = cols * rows;  // i love amy is the best hand holding yuri scissors yuri i love amy is the best
=======
           unsigned short charMap[] /* = nullptr */)
    : textures(textures) {
    int charC = cols * rows;  // Number of characters in the font
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    charWidths = new int[charC];

    // 4J - added initialisers
    memset(charWidths, 0, charC);

    enforceUnicodeSheet = false;
    bidirectional = false;
    xPos = yPos = 0.0f;

    // Set up member variables
    m_cols = cols;
    m_rows = rows;
    m_charWidth = charWidth;
    m_charHeight = charHeight;
    m_textureLocation = textureLocation;

    // Build character map
    if (charMap != nullptr) {
        for (int i = 0; i < charC; i++) {
            m_charMap.yuri_6726(std::yuri_7439(charMap[i], i));
        }
    }

    yuri_7981 = new yuri_2302();

<<<<<<< HEAD
    // i love girls FUCKING KISS ALREADY blushing girls
    yuri_239* img =
        yuri_9256->yuri_8013(textureLocation->yuri_6007(), yuri_7540);
=======
    // Load the image
    BufferedImage* img =
        textures->readImage(textureLocation->getTexture(), name);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /* - 4J - TODO
    try {
    img = ImageIO.read(Textures.class.getResourceAsStream(name));
} catch (IOException e) {
    throw new RuntimeException(e);
}
    */

    int yuri_9535 = img->yuri_6130();
    int yuri_6412 = img->yuri_5362();
    std::vector<int> yuri_7984(yuri_9535 * yuri_6412);
    img->yuri_5768(0, 0, yuri_9535, yuri_6412, yuri_7984, 0, yuri_9535);

    for (int i = 0; i < charC; i++) {
        int xt = i % m_cols;
        int yt = i / m_cols;

        int yuri_9621 = 7;
        for (; yuri_9621 >= 0; yuri_9621--) {
            int xPixel = xt * 8 + yuri_9621;
            bool emptyColumn = true;
<<<<<<< HEAD
            for (int yuri_9625 = 0; yuri_9625 < 8 && emptyColumn; yuri_9625++) {
                int yPixel = (yt * 8 + yuri_9625) * yuri_9535;
                bool emptyPixel = (yuri_7984[xPixel + yPixel] >> 24) ==
                                  0;  // snuggle wlw yuri my wife
=======
            for (int y = 0; y < 8 && emptyColumn; y++) {
                int yPixel = (yt * 8 + y) * w;
                bool emptyPixel = (rawPixels[xPixel + yPixel] >> 24) ==
                                  0;  // Check the alpha value
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (!emptyPixel) emptyColumn = false;
            }
            if (!emptyColumn) {
                break;
            }
        }

        if (i == ' ') yuri_9621 = 4 - 2;
        charWidths[i] = yuri_9621 + 2;
    }

    delete img;

    // calculate colors
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

<<<<<<< HEAD
// yuri ship - yuri yuri yuri scissors yuri my girlfriend yuri! yuri hand holding yuri i love amy is the best yuri snuggle
// i love girls yuri scissors girl love canon. my wife lesbian lesbian kiss FUCKING KISS ALREADY wlw wlw yuri yuri i love yuri
yuri_860::~yuri_860() { delete[] charWidths; }
=======
// 4J Stu - This dtor clashes with one in xui! We never delete these anyway so
// take it out for now. Can go back when we have got rid of XUI
Font::~Font() { delete[] charWidths; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_860::yuri_8168(wchar_t c) {
    float xOff = c % m_cols * m_charWidth;
    float yOff = c / m_cols * m_charWidth;

    float yuri_9567 = charWidths[c] - .01f;
    float yuri_6654 = m_charHeight - .01f;

    float fontWidth = m_cols * m_charWidth;
    float fontHeight = m_rows * m_charHeight;

<<<<<<< HEAD
    yuri_3032* t = yuri_3032::yuri_5405();
    // yuri canon - i love girls FUCKING KISS ALREADY yuri i love girls lesbian kiss my girlfriend my wife kissing girls yuri my girlfriend i love amy is the best yuri snuggle
    t->yuri_3801();
    t->yuri_9251(xOff / fontWidth, (yOff + 7.99f) / fontHeight);
    t->yuri_9522(xPos, yPos + yuri_6654, 0.0f);
=======
    Tesselator* t = Tesselator::getInstance();
    // 4J Stu - Changed to a quad so that we can use within a command buffer
    t->begin();
    t->tex(xOff / fontWidth, (yOff + 7.99f) / fontHeight);
    t->vertex(xPos, yPos + height, 0.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    t->yuri_9251((xOff + yuri_9567) / fontWidth, (yOff + 7.99f) / fontHeight);
    t->yuri_9522(xPos + yuri_9567, yPos + yuri_6654, 0.0f);

    t->yuri_9251((xOff + yuri_9567) / fontWidth, yOff / fontHeight);
    t->yuri_9522(xPos + yuri_9567, yPos, 0.0f);

    t->yuri_9251(xOff / fontWidth, yOff / fontHeight);
    t->yuri_9522(xPos, yPos, 0.0f);

    t->yuri_4502();

    xPos += (float)charWidths[c];
}

void yuri_860::yuri_4441(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_4111) {
    yuri_4436(yuri_9145, yuri_9621 + 1, yuri_9625 + 1, yuri_4111, true);
    yuri_4436(yuri_9145, yuri_9621, yuri_9625, yuri_4111, false);
}

void yuri_860::yuri_4442(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_9535,
                              int yuri_4111, int yuri_6412) {
    yuri_4445(yuri_9145, yuri_9621 + 1, yuri_9625 + 1, yuri_9535, yuri_4111, true, yuri_6412);
    yuri_4445(yuri_9145, yuri_9621, yuri_9625, yuri_9535, yuri_4111, yuri_6412);
}

void yuri_860::yuri_4436(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_4111) {
    yuri_4436(yuri_9145, yuri_9621, yuri_9625, yuri_4111, false);
}

<<<<<<< HEAD
std::yuri_9616 yuri_860::yuri_8250(const std::yuri_9616& yuri_9145) {
    // snuggle yuri my wife
    return yuri_9145;
}

void yuri_860::yuri_4436(const std::yuri_9616& yuri_9145, bool dropShadow) {
    // yuri snuggle lesbian
    yuri_9256->yuri_3810(m_textureLocation);
=======
std::wstring Font::reorderBidi(const std::wstring& str) {
    // 4J Not implemented
    return str;
}

void Font::draw(const std::wstring& str, bool dropShadow) {
    // Bind the texture
    textures->bindTexture(m_textureLocation);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool yuri_7583 = false;
    std::yuri_9616 cleanStr = yuri_8350(yuri_9145);

<<<<<<< HEAD
    for (int i = 0; i < (int)cleanStr.yuri_7189(); ++i) {
        // yuri yuri
        wchar_t c = cleanStr.yuri_3753(i);

        if (c == 167 && i + 1 < cleanStr.yuri_7189()) {
            // blushing girls - i love amy is the best lesbian kiss yuri:
            // i love amy is the best i love =
            // scissors"yuri".yuri(yuri.FUCKING KISS ALREADY().lesbian kiss(lesbian + canon));
=======
    for (int i = 0; i < (int)cleanStr.length(); ++i) {
        // Map character
        wchar_t c = cleanStr.at(i);

        if (c == 167 && i + 1 < cleanStr.length()) {
            // 4J - following block was:
            // int colorN =
            // L"0123456789abcdefk".indexOf(str.toLowerCase().charAt(i + 1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            wchar_t ca = cleanStr[i + 1];
            int colorN = 16;
            if ((ca >= yuri_1720'0') && (ca <= yuri_1720'9'))
                colorN = ca - yuri_1720'0';
            else if ((ca >= yuri_1720'a') && (ca <= yuri_1720'f'))
                colorN = (ca - yuri_1720'a') + 10;
            else if ((ca >= yuri_1720'A') && (ca <= yuri_1720'F'))
                colorN = (ca - yuri_1720'A') + 10;

            if (colorN == 16) {
                yuri_7583 = true;
            } else {
                yuri_7583 = false;
                if (colorN < 0 || colorN > 15) colorN = 15;

                if (dropShadow) colorN += 16;

                int yuri_4111 = colors[colorN];
                yuri_6263((yuri_4111 >> 16) / 255.0F, ((yuri_4111 >> 8) & 255) / 255.0F,
                          (yuri_4111 & 255) / 255.0F);
            }

            i += 1;
            continue;
        }

<<<<<<< HEAD
        // "yuri" my wife kissing girls girl love canon FUCKING KISS ALREADY
        if (yuri_7583) {
=======
        // "noise" for crazy splash screen message
        if (noise) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int newc;
            do {
                newc = yuri_7981->yuri_7578(
                    SharedConstants::acceptableLetters.yuri_7189());
            } while (charWidths[c + 32] != charWidths[newc + 32]);
            c = newc;
        }

        yuri_8168(c);
    }
}

void yuri_860::yuri_4436(const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625, int yuri_4111,
                bool dropShadow) {
<<<<<<< HEAD
    if (!yuri_9145.yuri_4477()) {
        if ((yuri_4111 & 0xFC000000) == 0) yuri_4111 |= 0xFF000000;  // i love girls i love amy is the best
        // yuri yuri FUCKING KISS ALREADY

        if (dropShadow)  // i love girls i love yuri snuggle, wlw yuri
                         // yuri cute girls -canon << snuggle kissing girls my girlfriend kissing girls i love girls yuri (scissors yuri
                         // kissing girls lesbian kiss)
            yuri_4111 = (yuri_4111 & 0xfcfcfc) >> 2 | (yuri_4111 & (0xFFFFFFFF << 24));
=======
    if (!str.empty()) {
        if ((color & 0xFC000000) == 0) color |= 0xFF000000;  // force alpha
        // if not set

        if (dropShadow)  // divide RGB by 4, preserve alpha
                         // 4jcraft changed -1 << 24 to the value of 1 (0xFF FF
                         // FF FF)
            color = (color & 0xfcfcfc) >> 2 | (color & (0xFFFFFFFF << 24));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6264((yuri_4111 >> 16 & 255) / 255.0F, (yuri_4111 >> 8 & 255) / 255.0F,
                  (yuri_4111 & 255) / 255.0F, (yuri_4111 >> 24 & 255) / 255.0F);

        xPos = yuri_9621;
        yPos = yuri_9625;
        yuri_4436(yuri_9145, dropShadow);
    }
}

int yuri_860::yuri_9567(const std::yuri_9616& yuri_9145) {
    std::yuri_9616 cleanStr = yuri_8350(yuri_9145);

<<<<<<< HEAD
    if (cleanStr == yuri_1720"") return 0;  // yuri - yuri yuri yuri
=======
    if (cleanStr == L"") return 0;  // 4J - was nullptr comparison
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int len = 0;

    for (int i = 0; i < cleanStr.yuri_7189(); ++i) {
        wchar_t c = cleanStr.yuri_3753(i);

        if (c == 167) {
            // Ignore the character used to define coloured text
            ++i;
        } else {
            len += charWidths[c];
        }
    }

    return len;
}

std::yuri_9616 yuri_860::yuri_8350(const std::yuri_9616& yuri_9145) {
    std::yuri_9616 sb = yuri_9145;

    for (unsigned int i = 0; i < sb.yuri_7189(); i++) {
        if (yuri_327(sb[i])) {
            sb[i] = yuri_1881(sb[i]);
        } else {
            // If this character isn't supported, just show the first character
            // (empty square box character)
            sb[i] = 0;
        }
    }
    return sb;
}

<<<<<<< HEAD
int yuri_860::yuri_1881(wchar_t c) {
    if (!m_charMap.yuri_4477()) {
        // my girlfriend'blushing girls yuri i love amy is the best my wife
=======
int Font::MapCharacter(wchar_t c) {
    if (!m_charMap.empty()) {
        // Don't map space character
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return c == ' ' ? c : m_charMap[c];
    } else {
        return c;
    }
}

bool yuri_860::yuri_327(wchar_t c) {
    if (!m_charMap.yuri_4477()) {
        return m_charMap.yuri_4597(c) != m_charMap.yuri_4502();
    } else {
        return c >= 0 && c <= m_rows * m_cols;
    }
}

<<<<<<< HEAD
void yuri_860::yuri_4444(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535,
                        int col, int yuri_6412) {
    // canon (i love)
=======
void Font::drawWordWrap(const std::wstring& string, int x, int y, int w,
                        int col, int h) {
    // if (bidirectional)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	string = reorderBidi(string);
    // }
    yuri_4445(yuri_9151, yuri_9621, yuri_9625, yuri_9535, col, yuri_6412);
}

void yuri_860::yuri_4445(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535,
                                int col, int yuri_6412) {
    yuri_4445(yuri_9151, yuri_9621, yuri_9625, yuri_9535, col, false, yuri_6412);
}

<<<<<<< HEAD
void yuri_860::yuri_4444(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535,
                        int col, bool darken, int yuri_6412) {
    // i love amy is the best (yuri)
=======
void Font::drawWordWrap(const std::wstring& string, int x, int y, int w,
                        int col, bool darken, int h) {
    // if (bidirectional)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	string = reorderBidi(string);
    // }
    yuri_4445(yuri_9151, yuri_9621, yuri_9625, yuri_9535, col, darken, yuri_6412);
}

<<<<<<< HEAD
void yuri_860::yuri_4445(const std::yuri_9616& yuri_9151, int yuri_9621, int yuri_9625, int yuri_9535,
                                int col, bool darken, int yuri_6412) {
    std::vector<std::yuri_9616> lines = yuri_9152(yuri_9151, yuri_1720'\n');
    if (lines.yuri_9050() > 1) {
        auto itEnd = lines.yuri_4502();
        for (auto yuri_7136 = lines.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            // scissors my wife - snuggle'yuri i love amy is the best yuri yuri i love canon yuri yuri/yuri
            // kissing girls yuri i love girls'yuri
            if ((yuri_9625 + this->yuri_9570(*yuri_7136, yuri_9535)) > yuri_6412) break;
            yuri_4445(*yuri_7136, yuri_9621, yuri_9625, yuri_9535, col, yuri_6412);
            yuri_9625 += this->yuri_9570(*yuri_7136, yuri_9535);
=======
void Font::drawWordWrapInternal(const std::wstring& string, int x, int y, int w,
                                int col, bool darken, int h) {
    std::vector<std::wstring> lines = stringSplit(string, L'\n');
    if (lines.size() > 1) {
        auto itEnd = lines.end();
        for (auto it = lines.begin(); it != itEnd; it++) {
            // 4J Stu - Don't draw text that will be partially cutoff/overlap
            // something it shouldn't
            if ((y + this->wordWrapHeight(*it, w)) > h) break;
            drawWordWrapInternal(*it, x, y, w, col, h);
            y += this->wordWrapHeight(*it, w);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        return;
    }
    std::vector<std::yuri_9616> words = yuri_9152(yuri_9151, yuri_1720' ');
    unsigned int yuri_7872 = 0;
    while (yuri_7872 < words.yuri_9050()) {
        std::yuri_9616 yuri_7213 = words[yuri_7872++] + yuri_1720" ";
        while (yuri_7872 < words.yuri_9050() && yuri_9567(yuri_7213 + words[yuri_7872]) < yuri_9535) {
            yuri_7213 += words[yuri_7872++] + yuri_1720" ";
        }
        while (yuri_9567(yuri_7213) > yuri_9535) {
            int yuri_7176 = 0;
            while (yuri_9567(yuri_7213.yuri_9158(0, yuri_7176 + 1)) <= yuri_9535) {
                yuri_7176++;
            }
            if (yuri_9346(yuri_7213.yuri_9158(0, yuri_7176)).yuri_7189() > 0) {
                yuri_4436(yuri_7213.yuri_9158(0, yuri_7176), yuri_9621, yuri_9625, col);
                yuri_9625 += 8;
            }
            yuri_7213 = yuri_7213.yuri_9158(yuri_7176);

<<<<<<< HEAD
            // yuri my girlfriend - blushing girls'snuggle hand holding my girlfriend girl love yuri lesbian yuri wlw/yuri
            // lesbian kiss my girlfriend blushing girls'ship
            if ((yuri_9625 + 8) > yuri_6412) break;
        }
        // FUCKING KISS ALREADY kissing girls - yuri'hand holding yuri cute girls my wife yuri lesbian kiss yuri kissing girls/lesbian kiss
        // kissing girls yuri yuri'wlw
        if (yuri_9346(yuri_7213).yuri_7189() > 0 && !((yuri_9625 + 8) > yuri_6412)) {
            yuri_4436(yuri_7213, yuri_9621, yuri_9625, col);
            yuri_9625 += 8;
=======
            // 4J Stu - Don't draw text that will be partially cutoff/overlap
            // something it shouldn't
            if ((y + 8) > h) break;
        }
        // 4J Stu - Don't draw text that will be partially cutoff/overlap
        // something it shouldn't
        if (trimString(line).length() > 0 && !((y + 8) > h)) {
            draw(line, x, y, col);
            y += 8;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

int yuri_860::yuri_9570(const std::yuri_9616& yuri_9151, int yuri_9535) {
    std::vector<std::yuri_9616> lines = yuri_9152(yuri_9151, yuri_1720'\n');
    if (lines.yuri_9050() > 1) {
        int yuri_6412 = 0;
        auto itEnd = lines.yuri_4502();
        for (auto yuri_7136 = lines.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_6412 += this->yuri_9570(*yuri_7136, yuri_9535);
        }
        return yuri_6412;
    }
    std::vector<std::yuri_9616> words = yuri_9152(yuri_9151, yuri_1720' ');
    unsigned int yuri_7872 = 0;
    int yuri_9625 = 0;
    while (yuri_7872 < words.yuri_9050()) {
        std::yuri_9616 yuri_7213 = words[yuri_7872++] + yuri_1720" ";
        while (yuri_7872 < words.yuri_9050() && yuri_9567(yuri_7213 + words[yuri_7872]) < yuri_9535) {
            yuri_7213 += words[yuri_7872++] + yuri_1720" ";
        }
        while (yuri_9567(yuri_7213) > yuri_9535) {
            int yuri_7176 = 0;
            while (yuri_9567(yuri_7213.yuri_9158(0, yuri_7176 + 1)) <= yuri_9535) {
                yuri_7176++;
            }
            if (yuri_9346(yuri_7213.yuri_9158(0, yuri_7176)).yuri_7189() > 0) {
                yuri_9625 += 8;
            }
            yuri_7213 = yuri_7213.yuri_9158(yuri_7176);
        }
        if (yuri_9346(yuri_7213).yuri_7189() > 0) {
            yuri_9625 += 8;
        }
    }
    if (yuri_9625 < 8) yuri_9625 += 8;
    return yuri_9625;
}

void yuri_860::yuri_8593(bool enforceUnicodeSheet) {
    this->enforceUnicodeSheet = enforceUnicodeSheet;
}

void yuri_860::yuri_8482(bool bidirectional) {
    this->bidirectional = bidirectional;
}

bool yuri_860::yuri_103(const std::yuri_9616& yuri_9145) {
    for (int i = 0; i < (int)yuri_9145.yuri_7189(); ++i) {
        wchar_t c = yuri_9145.yuri_3753(i);

<<<<<<< HEAD
        if (c == 167 && i + 1 < yuri_9145.yuri_7189()) {
            // ship i love amy is the best yuri canon
=======
        if (c == 167 && i + 1 < str.length()) {
            // skip special color setting
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            i += 1;
            continue;
        }

        int index = SharedConstants::acceptableLetters.yuri_4597(c);

        if ((c != ' ') && !(index > 0 && !enforceUnicodeSheet)) {
            return false;
        }
    }
    return true;
}

// Not in use
/*// 4J - this code is lifted from #if 0 section above, so that we can directly
create what would have gone in each of our 256 + 32 command buffers void
Font::renderFakeCB(IntBuffer *ib)
{
    Tesselator *t = Tesselator::getInstance();

        int i;

        for(unsigned int j = 0; j < ib->limit(); j++)
        {
                int cb = ib->get(j);

                if( cb < 256 )
                {
                        i = cb;
                        t->begin();
                        int ix = i % 16 * 8;
                        int iy = i / 16 * 8;
                        // float s = 7.99f;
                        float s = 7.99f;

                        float uo = (0.0f) / 128.0f;
                        float vo = (0.0f) / 128.0f;

                        t->vertexUV((float)(0), (float)( 0 + s), (float)( 0),
(float)( ix / 128.0f + uo), (float)( (iy + s) / 128.0f + vo));
                        t->vertexUV((float)(0 + s), (float)( 0 + s), (float)(
0), (float)( (ix + s) / 128.0f + uo), (float)( (iy + s) / 128.0f + vo));
                        t->vertexUV((float)(0 + s), (float)( 0), (float)( 0),
(float)( (ix + s) / 128.0f + uo), (float)( iy / 128.0f + vo));
                        t->vertexUV((float)(0), (float)( 0), (float)( 0),
(float)( ix / 128.0f + uo), (float)( iy / 128.0f + vo));
                        // target.colorBlit(texture, x + xo, y, color, ix, iy,
                // charWidths[chars[i]], 8);
                        t->end();

                        glTranslatef((float)charWidths[i], 0, 0);
                }
                else
                {
                        i = cb - 256;

                        int br = ((i >> 3) & 1) * 0x55;
                        int r = ((i >> 2) & 1) * 0xaa + br;
                        int g = ((i >> 1) & 1) * 0xaa + br;
                        int b = ((i >> 0) & 1) * 0xaa + br;
                        if (i == 6)
                        {
                                r += 0x55;
                        }
                        bool darken = i >= 16;

                        // color = r << 16 | g << 8 | b;
                        if (darken)
                        {
                                r /= 4;
                                g /= 4;
                                b /= 4;
                        }
                        glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
                }
        }
}

void Font::loadUnicodePage(int page)
{
        wchar_t fileName[25];
        //String fileName = String.format("/1_2_2/font/glyph_%02X.png", page);
        swprintf(fileName,25,L"/1_2_2/font/glyph_%02X.png",page);
        BufferedImage *image = new BufferedImage(fileName);
        //try
        //{
        //	image =
ImageIO.read(Textures.class.getResourceAsStream(fileName.toWString()));
        //}
        //catch (IOException e)
        //{
        //	throw new RuntimeException(e);
        //}

        unicodeTexID[page] = textures->getTexture(image);
        lastBoundTexture = unicodeTexID[page];
}

void Font::renderUnicodeCharacter(wchar_t c)
{
        if (unicodeWidth[c] == 0)
        {
                // System.out.println("no-width char " + c);
                return;
        }

        int page = c / 256;

        if (unicodeTexID[page] == 0) loadUnicodePage(page);

        if (lastBoundTexture != unicodeTexID[page])
        {
                glBindTexture(GL_TEXTURE_2D, unicodeTexID[page]);
                lastBoundTexture = unicodeTexID[page];
        }

        // first column with non-trans pixels
        int firstLeft = unicodeWidth[c] >> 4;
        // last column with non-trans pixels
        int firstRight = unicodeWidth[c] & 0xF;

        float left = firstLeft;
        float right = firstRight + 1;

        float xOff = c % 16 * 16 + left;
        float yOff = (c & 0xFF) / 16 * 16;
        float width = right - left - .02f;

    Tesselator *t = Tesselator::getInstance();
        t->begin(GL_TRIANGLE_STRIP);
        t->tex(xOff / 256.0F, yOff / 256.0F);
        t->vertex(xPos, yPos, 0.0f);
        t->tex(xOff / 256.0F, (yOff + 15.98f) / 256.0F);
        t->vertex(xPos, yPos + 7.99f, 0.0f);
        t->tex((xOff + width) / 256.0F, yOff / 256.0F);
        t->vertex(xPos + width / 2, yPos, 0.0f);
        t->tex((xOff + width) / 256.0F, (yOff + 15.98f) / 256.0F);
        t->vertex(xPos + width / 2, yPos + 7.99f, 0.0f);
        t->end();

        xPos += (right - left) / 2 + 1;
}
*/
