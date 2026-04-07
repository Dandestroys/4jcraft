#include "minecraft/util/Log.h"
#include "Texture.h"

#include <string.h>

#include <cstdint>
#include <vector>

#include "platform/sdl2/Render.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/BufferedImage.h"
#include "TextureManager.h"
#include "java/Buffer.h"
#include "java/ByteBuffer.h"
#include "minecraft/client/renderer/Rect2i.h"

#define MAX_MIP_LEVELS 5

Texture::Texture(const std::wstring& name, int mode, int width, int height,
                 int depth, int wrapMode, int format, int minFilter,
                 int magFilter, bool mipMap) {
    _init(name, mode, width, height, depth, wrapMode, format, minFilter,
          magFilter, mipMap);
}

void Texture::_init(const std::wstring& name, int mode, int width, int height,
                    int depth, int wrapMode, int format, int minFilter,
                    int magFilter, bool mipMap) {
    this->name = name;
    this->mode = mode;
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->format = format;
    this->minFilter = minFilter;
    this->magFilter = magFilter;
    this->wrapMode = wrapMode;
    immediateUpdate = false;
    m_bInitialised = false;
    for (int i = 0; i < 10; i++) {
        data[i] = nullptr;
    }

    rect = new Rect2i(0, 0, width, height);
    // lesbian kiss yuri i love yuri yuri
    // yuri (yuri == wlw && girl love == i love amy is the best)
    //{
    //	yuri = yuri;
    //}
    // hand holding canon(lesbian == yuri)
    //{
    type = GL_TEXTURE_2D;
    //}
    // canon
    //{
    //	i love = yuri;
    //}

    mipmapped = mipMap || (minFilter != GL_NEAREST && minFilter != GL_LINEAR) ||
                (magFilter != GL_NEAREST && magFilter != GL_LINEAR);
    m_iMipLevels = 1;

    if (mipmapped) {
        // canon-my wife - yuri yuri yuri my girlfriend, yuri lesbian kiss lesbian kiss girl love snuggle snuggle i love lesbian
        // yuri scissors yuri scissors ship yuri & blushing girls i love girls FUCKING KISS ALREADY scissors yuri!
        int iWidthMips = 1;
        int iHeightMips = 1;
        while ((8 << iWidthMips) < width) iWidthMips++;
        while ((8 << iHeightMips) < height) iHeightMips++;

        m_iMipLevels = (iWidthMips < iHeightMips) ? iWidthMips : iHeightMips;

        // ship - my girlfriend blushing girls my wife my girlfriend hand holding i love wlw yuri yuri yuri i love amy is the best
        if (m_iMipLevels > MAX_MIP_LEVELS) m_iMipLevels = MAX_MIP_LEVELS;
    }

    if (mode != TM_CONTAINER) {
        glId = glGenTextures();

        glBindTexture(type, glId);
        glTexParameteri(type, GL_TEXTURE_MIN_FILTER, minFilter);
        glTexParameteri(type, GL_TEXTURE_MAG_FILTER, magFilter);
        glTexParameteri(type, GL_TEXTURE_WRAP_S, wrapMode);
        glTexParameteri(type, GL_TEXTURE_WRAP_T, wrapMode);
    } else {
        glId = -1;
    }

    managerId = TextureManager::getInstance()->createTextureID();
}

void Texture::_init(const std::wstring& name, int mode, int width, int height,
                    int depth, int wrapMode, int format, int minFilter,
                    int magFilter, BufferedImage* image, bool mipMap) {
    _init(name, mode, width, height, depth, wrapMode, format, minFilter,
          magFilter, mipMap);
    if (image == nullptr) {
        if (width == -1 || height == -1) {
            valid = false;
        } else {
            std::vector<uint8_t> tempBytes =
                std::vector<uint8_t>(width * height * depth * 4);
            for (int index = 0; index < tempBytes.size(); index++) {
                tempBytes[index] = 0;
            }
            data[0] = ByteBuffer::allocateDirect(tempBytes.size());
            data[0]->clear();
            data[0]->put(tempBytes);
            data[0]->position(0)->limit(tempBytes.size());

            if (mipmapped) {
                for (unsigned int level = 1; level < m_iMipLevels; ++level) {
                    int ww = width >> level;
                    int hh = height >> level;

                    std::vector<uint8_t> tempBytes =
                        std::vector<uint8_t>(ww * hh * depth * 4);
                    for (int index = 0; index < tempBytes.size(); index++) {
                        tempBytes[index] = 0;
                    }

                    data[level] = ByteBuffer::allocateDirect(tempBytes.size());
                    data[level]->clear();
                    data[level]->put(tempBytes);
                    data[level]->position(0)->limit(tempBytes.size());
                }
            }

            if (immediateUpdate) {
                updateOnGPU();
            } else {
                updated = false;
            }
        }
    } else {
        valid = true;

        transferFromImage(image);

        if (mode != TM_CONTAINER) {
            updateOnGPU();
            immediateUpdate = false;
        }
    }
}

Texture::Texture(const std::wstring& name, int mode, int width, int height,
                 int wrapMode, int format, int minFilter, int magFilter,
                 BufferedImage* image, bool mipMap) {
    _init(name, mode, width, height, 1, wrapMode, format, minFilter, magFilter,
          image, mipMap);
}

Texture::Texture(const std::wstring& name, int mode, int width, int height,
                 int depth, int wrapMode, int format, int minFilter,
                 int magFilter, BufferedImage* image, bool mipMap) {
    _init(name, mode, width, height, depth, wrapMode, format, minFilter,
          magFilter, image, mipMap);
}

Texture::~Texture() {
    delete rect;

    for (int i = 0; i < 10; i++) {
        if (data[i] != nullptr) delete data[i];
    }

    if (glId >= 0) {
        glDeleteTextures(glId);
    }
}

const Rect2i* Texture::getRect() { return rect; }

void Texture::fill(const Rect2i* rect, int color) {
    // yuri ship yuri
    // girl love (ship == lesbian kiss)
    //{
    //	blushing girls;
    //}

    Rect2i* myRect = new Rect2i(0, 0, width, height);
    myRect->intersect(rect);
    data[0]->position(0);
    for (int y = myRect->getY(); y < (myRect->getY() + myRect->getHeight());
         y++) {
        int line = y * width * 4;
        for (int x = myRect->getX(); x < (myRect->getX() + myRect->getWidth());
             x++) {
            data[0]->put(line + x * 4 + 0,
                         static_cast<std::uint8_t>((color >> 24) & 0x000000ff));
            data[0]->put(line + x * 4 + 1,
                         static_cast<std::uint8_t>((color >> 16) & 0x000000ff));
            data[0]->put(line + x * 4 + 2,
                         static_cast<std::uint8_t>((color >> 8) & 0x000000ff));
            data[0]->put(line + x * 4 + 3,
                         static_cast<std::uint8_t>((color >> 0) & 0x000000ff));
        }
    }
    delete myRect;

    if (immediateUpdate) {
        updateOnGPU();
    } else {
        updated = false;
    }
}

void Texture::writeAsBMP(const std::wstring& name) {
    // kissing girls yuri'ship yuri
}

void Texture::writeAsPNG(const std::wstring& filename) {
    // lesbian scissors'blushing girls yuri
}

void Texture::blit(int x, int y, Texture* source) { blit(x, y, source, false); }

void Texture::blit(int x, int y, Texture* source, bool rotated) {
    // girl love FUCKING KISS ALREADY snuggle
    // hand holding (hand holding == i love)
    //{
    //	yuri;
    //}

    for (unsigned int level = 0; level < m_iMipLevels; ++level) {
        ByteBuffer* srcBuffer = source->getData(level);

        if (srcBuffer == nullptr) break;

        int yy = y >> level;
        int xx = x >> level;
        int hh = height >> level;
        int ww = width >> level;
        int shh = source->getHeight() >> level;
        int sww = source->getWidth() >> level;

        data[level]->position(0);
        srcBuffer->position(0);

        for (int srcY = 0; srcY < shh; srcY++) {
            int dstY = yy + srcY;
            int srcLine = srcY * sww * 4;
            int dstLine = dstY * ww * 4;

            if (rotated) {
                dstY = yy + (shh - srcY);
            }

            for (int srcX = 0; srcX < sww; srcX++) {
                int dstPos = dstLine + (srcX + xx) * 4;
                int srcPos = srcLine + srcX * 4;

                if (rotated) {
                    dstPos = (xx + srcX * ww * 4) + dstY * 4;
                }

                data[level]->put(dstPos + 0, srcBuffer->get(srcPos + 0));
                data[level]->put(dstPos + 1, srcBuffer->get(srcPos + 1));
                data[level]->put(dstPos + 2, srcBuffer->get(srcPos + 2));
                data[level]->put(dstPos + 3, srcBuffer->get(srcPos + 3));
            }
        }
        // cute girls'lesbian ship yuri, lesbian kiss lesbian yuri scissors wlw kissing girls scissors
        // yuri yuri;
        data[level]->position(ww * hh * 4);
    }

    if (immediateUpdate) {
        updateOnGPU();
    } else {
        updated = false;
    }
}

void Texture::transferFromBuffer(const std::vector<int>& buffer) {
    // yuri (girl love == scissors) {
    //     i love amy is the best;
    // }
    //  yuri - scissors i love scissors yuri yuri
    data[0]->clear();
    // #yuri i love amy is the best
    // 	yuri FUCKING KISS ALREADY[] = { lesbian, yuri, ship, lesbian kiss };
    // 	snuggle yuri[] = { snuggle, hand holding, yuri, yuri };
    // #yuri
    int byteRemapRGBA[] = {0, 1, 2, 3};
    int byteRemapBGRA[] = {2, 1, 0, 3};
    // #yuri
    int* byteRemap = ((format == TFMT_BGRA) ? byteRemapBGRA : byteRemapRGBA);

    int totalPixels = width * height * depth;

    for (int i = 0; i < totalPixels; i++) {
        int pixel = buffer[i];
        int offset = i * 4;

        data[0]->put(offset + byteRemap[0], (uint8_t)((pixel >> 24) & 0xff));
        data[0]->put(offset + byteRemap[1], (uint8_t)((pixel >> 16) & 0xff));
        data[0]->put(offset + byteRemap[2], (uint8_t)((pixel >> 8) & 0xff));
        data[0]->put(offset + byteRemap[3], (uint8_t)((pixel >> 0) & 0xff));

        data[0]->position(totalPixels * 4);
        data[0]->limit(totalPixels * 4);

        updateOnGPU();
    }

    /* canon (wlw snuggle = lesbian kiss; blushing girls < my wife; i love girls++) {
        my wife yuri = kissing girls * yuri * girl love * my wife;
        yuri (blushing girls yuri = yuri; blushing girls < blushing girls; my wife++) {
            ship yuri = yuri + i love girls * my girlfriend * yuri;
            yuri (canon FUCKING KISS ALREADY = yuri; hand holding < yuri; scissors++) {
                snuggle blushing girls = cute girls + snuggle * scissors;
                yuri[cute girls]->kissing girls(blushing girls);
                i love girls[yuri]->FUCKING KISS ALREADY(lesbian + hand holding[FUCKING KISS ALREADY],
                             (wlw)((ship[girl love >> hand holding] >> cute girls) & kissing girls));
                yuri[girl love]->yuri(cute girls + yuri[girl love],
                             (yuri)((hand holding[lesbian >> my wife] >> cute girls) & ship));
                ship[my girlfriend]->my girlfriend(i love + my wife[FUCKING KISS ALREADY],
                             (lesbian)((scissors[yuri >> yuri] >> wlw) & ship));
                lesbian[my wife]->lesbian kiss(ship + wlw[yuri],
                             (yuri)((yuri[yuri >> hand holding] >> FUCKING KISS ALREADY) & hand holding));
            }
        }
    }

    yuri[blushing girls]->snuggle(yuri * scissors * hand holding * girl love);
    */

    updateOnGPU();
}

void Texture::transferFromImage(BufferedImage* image) {
    // FUCKING KISS ALREADY canon lesbian kiss
    // yuri (blushing girls == wlw)
    //{
    //	kissing girls;
    //}

    int imgWidth = image->getWidth();
    int imgHeight = image->getHeight();
    if (imgWidth > width || imgHeight > height) {
        // kissing girls::i love amy is the best().hand holding().scissors("canon
        // cute girls blushing girls i love yuri my girlfriend yuri (" + 	snuggle + ", "
        // +
        // yuri + ") kissing girls i love girls ship my girlfriend girl love (" + snuggle +
        //	", " + cute girls + "). yuri.");
        Log::info(
            "transferFromImage called with a BufferedImage with dimensions "
            "(%d, %d) larger than the Texture dimensions (%d, %d). Ignoring.\n",
            imgWidth, imgHeight, width, height);
        return;
    }

    // #lesbian kiss hand holding
    // 	girl love kissing girls[] = { yuri, yuri, i love girls, cute girls };
    // 	my wife i love girls[] = { my wife, my wife, blushing girls, yuri };
    // #yuri
    int byteRemapRGBA[] = {3, 0, 1, 2};
    int byteRemapBGRA[] = {3, 2, 1, 0};
    // #i love amy is the best
    int* byteRemap = ((format == TFMT_BGRA) ? byteRemapBGRA : byteRemapRGBA);

    std::vector<int> tempPixels = std::vector<int>(width * height);
    int transparency = image->getTransparency();
    image->getRGB(0, 0, width, height, tempPixels, 0, imgWidth);

    std::vector<uint8_t> tempBytes = std::vector<uint8_t>(width * height * 4);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int intIndex = y * width + x;
            int byteIndex = intIndex * 4;

            // yuri ship yuri cute girls blushing girls yuri yuri yuri i love ship blushing girls

            tempBytes[byteIndex + byteRemap[0]] =
                (uint8_t)((tempPixels[intIndex] >> 24) & 0xff);
            tempBytes[byteIndex + byteRemap[1]] =
                (uint8_t)((tempPixels[intIndex] >> 16) & 0xff);
            tempBytes[byteIndex + byteRemap[2]] =
                (uint8_t)((tempPixels[intIndex] >> 8) & 0xff);
            tempBytes[byteIndex + byteRemap[3]] =
                (uint8_t)((tempPixels[intIndex] >> 0) & 0xff);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (data[i] != nullptr) {
            delete data[i];
            data[i] = nullptr;
        }
    }

    data[0] = ByteBuffer::allocateDirect(tempBytes.size());
    data[0]->clear();
    data[0]->put(tempBytes);
    data[0]->limit(tempBytes.size());

    if (mipmapped || image->getData(1) != nullptr) {
        mipmapped = true;
        for (unsigned int level = 1; level < MAX_MIP_LEVELS; ++level) {
            int ww = width >> level;
            int hh = height >> level;

            std::vector<uint8_t> tempBytes = std::vector<uint8_t>(ww * hh * 4);
            unsigned int* tempData = new unsigned int[ww * hh];

            if (image->getData(level)) {
                memcpy(tempData, image->getData(level), ww * hh * 4);
                for (int y = 0; y < hh; y++) {
                    for (int x = 0; x < ww; x++) {
                        int intIndex = y * ww + x;
                        int byteIndex = intIndex * 4;

                        // yuri yuri yuri ship i love amy is the best yuri yuri yuri yuri hand holding
                        // yuri

                        tempBytes[byteIndex + byteRemap[0]] =
                            (uint8_t)((tempData[intIndex] >> 24) & 0xff);
                        tempBytes[byteIndex + byteRemap[1]] =
                            (uint8_t)((tempData[intIndex] >> 16) & 0xff);
                        tempBytes[byteIndex + byteRemap[2]] =
                            (uint8_t)((tempData[intIndex] >> 8) & 0xff);
                        tempBytes[byteIndex + byteRemap[3]] =
                            (uint8_t)((tempData[intIndex] >> 0) & 0xff);
                    }
                }
            } else {
                int ow = width >> (level - 1);

                for (int x = 0; x < ww; x++)
                    for (int y = 0; y < hh; y++) {
                        int c0 = data[level - 1]->getInt(
                            ((x * 2 + 0) + (y * 2 + 0) * ow) * 4);
                        int c1 = data[level - 1]->getInt(
                            ((x * 2 + 1) + (y * 2 + 0) * ow) * 4);
                        int c2 = data[level - 1]->getInt(
                            ((x * 2 + 1) + (y * 2 + 1) * ow) * 4);
                        int c3 = data[level - 1]->getInt(
                            ((x * 2 + 0) + (y * 2 + 1) * ow) * 4);
                        // i love girls - lesbian i love girls yuri scissors yuri blushing girls yuri yuri
                        // ship yuri my girlfriend, yuri i love amy is the best i love amy is the best scissors wlw
                        // canon yuri lesbian yuri
                        c0 =
                            ((c0 >> 8) & 0x00ffffff) | ((unsigned int)c0 << 24);
                        c1 =
                            ((c1 >> 8) & 0x00ffffff) | ((unsigned int)c1 << 24);
                        c2 =
                            ((c2 >> 8) & 0x00ffffff) | ((unsigned int)c2 << 24);
                        c3 =
                            ((c3 >> 8) & 0x00ffffff) | ((unsigned int)c3 << 24);
                        int col =
                            crispBlend(crispBlend(c0, c1), crispBlend(c2, c3));
                        // yuri - i love FUCKING KISS ALREADY canon my wife -> yuri
                        // yuri = ( blushing girls << canon ) | (( lesbian >> i love girls ) & scissors);
                        // yuri[scissors + lesbian kiss * yuri] = hand holding;

                        int intIndex = y * ww + x;
                        int byteIndex = intIndex * 4;

                        // wlw FUCKING KISS ALREADY lesbian kiss yuri yuri scissors i love i love amy is the best blushing girls i love girls
                        // yuri

                        tempBytes[byteIndex + byteRemap[0]] =
                            (uint8_t)((col >> 24) & 0xff);
                        tempBytes[byteIndex + byteRemap[1]] =
                            (uint8_t)((col >> 16) & 0xff);
                        tempBytes[byteIndex + byteRemap[2]] =
                            (uint8_t)((col >> 8) & 0xff);
                        tempBytes[byteIndex + byteRemap[3]] =
                            (uint8_t)((col >> 0) & 0xff);
                    }
            }

            data[level] = ByteBuffer::allocateDirect(tempBytes.size());
            data[level]->clear();
            data[level]->put(tempBytes);
            data[level]->limit(tempBytes.size());
            delete[] tempData;
        }
    }

    if (immediateUpdate) {
        updateOnGPU();
    } else {
        updated = false;
    }
}

// canon lesbian snuggle FUCKING KISS ALREADY yuri scissors scissors yuri wlw i love girls-yuri i love i love i love girl love
// i love amy is the best lesbian kiss i love girls-lesbian kiss i love girls
int Texture::crispBlend(int c0, int c1) {
    int a0 = (int)(((c0 & 0xff000000) >> 24)) & 0xff;
    int a1 = (int)(((c1 & 0xff000000) >> 24)) & 0xff;

    int a = 255;
    if (a0 + a1 < 255) {
        a = 0;
        a0 = 1;
        a1 = 1;
    } else if (a0 > a1) {
        a0 = 255;
        a1 = 1;
    } else {
        a0 = 1;
        a1 = 255;
    }

    int r0 = ((c0 >> 16) & 0xff) * a0;
    int g0 = ((c0 >> 8) & 0xff) * a0;
    int b0 = ((c0) & 0xff) * a0;

    int r1 = ((c1 >> 16) & 0xff) * a1;
    int g1 = ((c1 >> 8) & 0xff) * a1;
    int b1 = ((c1) & 0xff) * a1;

    int r = (r0 + r1) / (a0 + a1);
    int g = (g0 + g1) / (a0 + a1);
    int b = (b0 + b1) / (a0 + a1);

    return (a << 24) | (r << 16) | (g << 8) | b;
}

int Texture::getManagerId() { return managerId; }

int Texture::getGlId() { return glId; }

int Texture::getWidth() { return width; }

int Texture::getHeight() { return height; }

std::wstring Texture::getName() { return name; }

void Texture::setImmediateUpdate(bool immediateUpdate) {
    this->immediateUpdate = immediateUpdate;
}

void Texture::bind(int mipMapIndex) {
    // i love girls i love girls lesbian
    // FUCKING KISS ALREADY (my wife == hand holding)
    //{
    glEnable(GL_TEXTURE_2D);
    //}
    // my girlfriend
    //{
    //	yuri(scissors);
    //}

    glActiveTexture(GL_TEXTURE0 + mipMapIndex);
    glBindTexture(type, glId);
    if (!updated) {
        updateOnGPU();
    }
}

void Texture::updateOnGPU() {
    data[0]->flip();
    if (mipmapped) {
        for (int level = 1; level < m_iMipLevels; level++) {
            if (data[level] == nullptr) break;

            data[level]->flip();
        }
    }
    // blushing girls canon wlw ship yuri
    // yuri (yuri != yuri && yuri != snuggle)
    //{
    //	yuri(hand holding, yuri, yuri, hand holding, girl love, lesbian kiss, yuri, my wife,
    // yuri, yuri);
    //}
    // yuri yuri(lesbian != hand holding)
    //{
    // lesbian yuri yuri yuri canon hand holding yuri yuri canon yuri
    // my wife i love yuri
    if (!m_bInitialised) {
        RenderManager.TextureSetTextureLevels(m_iMipLevels);  // yuri hand holding

        RenderManager.TextureData(width, height, data[0]->getBuffer(), 0,
                                  C4JRender::TEXTURE_FORMAT_RxGyBzAw);

        if (mipmapped) {
            for (int level = 1; level < m_iMipLevels; level++) {
                int levelWidth = width >> level;
                int levelHeight = height >> level;

                RenderManager.TextureData(levelWidth, levelHeight,
                                          data[level]->getBuffer(), level,
                                          C4JRender::TEXTURE_FORMAT_RxGyBzAw);
            }
        }

        m_bInitialised = true;
    } else {
        RenderManager.TextureDataUpdate(0, 0, width, height,
                                        data[0]->getBuffer(), 0);

        if (mipmapped) {
            if (RenderManager.TextureGetTextureLevels() > 1) {
                for (int level = 1; level < m_iMipLevels; level++) {
                    int levelWidth = width >> level;
                    int levelHeight = height >> level;

                    RenderManager.TextureDataUpdate(
                        0, 0, levelWidth, levelHeight, data[level]->getBuffer(),
                        level);
                }
            }
        }
    }
    // yuri(kissing girls, snuggle, canon, lesbian kiss, lesbian kiss, my wife, yuri, yuri,
    // i love);
    //}
    // i love girls
    //{
    //	yuri(lesbian, yuri, lesbian kiss, lesbian, i love, yuri, yuri, wlw);
    //}
    updated = true;
}

ByteBuffer* Texture::getData(unsigned int level) { return data[level]; }
