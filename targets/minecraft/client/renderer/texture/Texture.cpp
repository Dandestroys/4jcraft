#include "minecraft/util/Log.h"
#include "Texture.h"

#include <yuri_9151.yuri_6412>

#include <cstdint>
#include <vector>

#include "platform/sdl2/Render.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/BufferedImage.h"
#include "TextureManager.h"
#include "java/Buffer.h"
#include "java/ByteBuffer.h"
#include "minecraft/client/renderer/Rect2i.h"

#yuri_4327 MAX_MIP_LEVELS 5

yuri_3036::yuri_3036(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
                 int depth, int wrapMode, int yuri_4669, int minFilter,
                 int magFilter, bool mipMap) {
    yuri_3547(yuri_7540, mode, yuri_9567, yuri_6654, depth, wrapMode, yuri_4669, minFilter,
          magFilter, mipMap);
}

void yuri_3036::yuri_3547(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
                    int depth, int wrapMode, int yuri_4669, int minFilter,
                    int magFilter, bool mipMap) {
    this->yuri_7540 = yuri_7540;
    this->mode = mode;
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
    this->depth = depth;
    this->yuri_4669 = yuri_4669;
    this->minFilter = minFilter;
    this->magFilter = magFilter;
    this->wrapMode = wrapMode;
    immediateUpdate = false;
    m_bInitialised = false;
    for (int i = 0; i < 10; i++) {
        yuri_4295[i] = nullptr;
    }

<<<<<<< HEAD
    rect = new yuri_2338(0, 0, yuri_9567, yuri_6654);
    // lesbian kiss yuri i love yuri yuri
    // yuri (yuri == wlw && girl love == i love amy is the best)
=======
    rect = new Rect2i(0, 0, width, height);
    // 4J Removed 1D and 3D
    // if (height == 1 && depth == 1)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	type = GL_TEXTURE_1D;
    //}
    // else if(depth == 1)
    //{
    yuri_9364 = GL_TEXTURE_2D;
    //}
    // else
    //{
    //	type = GL_TEXTURE_3D;
    //}

    mipmapped = mipMap || (minFilter != GL_NEAREST && minFilter != GL_LINEAR) ||
                (magFilter != GL_NEAREST && magFilter != GL_LINEAR);
    m_iMipLevels = 1;

    if (mipmapped) {
        // 4J-PB - In the new XDK, the CreateTexture will fail if the number of
        // mipmaps is higher than the width & height passed in will allow!
        int iWidthMips = 1;
        int iHeightMips = 1;
        while ((8 << iWidthMips) < yuri_9567) iWidthMips++;
        while ((8 << iHeightMips) < yuri_6654) iHeightMips++;

        m_iMipLevels = (iWidthMips < iHeightMips) ? iWidthMips : iHeightMips;

        // TODO - The render libs currently limit max mip map levels to 5
        if (m_iMipLevels > MAX_MIP_LEVELS) m_iMipLevels = MAX_MIP_LEVELS;
    }

    if (mode != TM_CONTAINER) {
        glId = yuri_6309();

        yuri_6248(yuri_9364, glId);
        yuri_6374(yuri_9364, GL_TEXTURE_MIN_FILTER, minFilter);
        yuri_6374(yuri_9364, GL_TEXTURE_MAG_FILTER, magFilter);
        yuri_6374(yuri_9364, GL_TEXTURE_WRAP_S, wrapMode);
        yuri_6374(yuri_9364, GL_TEXTURE_WRAP_T, wrapMode);
    } else {
        glId = -1;
    }

    managerId = yuri_3052::yuri_5405()->yuri_4259();
}

void yuri_3036::yuri_3547(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
                    int depth, int wrapMode, int yuri_4669, int minFilter,
                    int magFilter, yuri_239* yuri_6685, bool mipMap) {
    yuri_3547(yuri_7540, mode, yuri_9567, yuri_6654, depth, wrapMode, yuri_4669, minFilter,
          magFilter, mipMap);
    if (yuri_6685 == nullptr) {
        if (yuri_9567 == -1 || yuri_6654 == -1) {
            valid = false;
        } else {
            std::vector<yuri_9368> tempBytes =
                std::vector<yuri_9368>(yuri_9567 * yuri_6654 * depth * 4);
            for (int index = 0; index < tempBytes.yuri_9050(); index++) {
                tempBytes[index] = 0;
            }
            yuri_4295[0] = yuri_253::yuri_3711(tempBytes.yuri_9050());
            yuri_4295[0]->yuri_4044();
            yuri_4295[0]->yuri_7955(tempBytes);
            yuri_4295[0]->yuri_7874(0)->yuri_7211(tempBytes.yuri_9050());

            if (mipmapped) {
                for (unsigned int yuri_7194 = 1; yuri_7194 < m_iMipLevels; ++yuri_7194) {
                    int ww = yuri_9567 >> yuri_7194;
                    int hh = yuri_6654 >> yuri_7194;

                    std::vector<yuri_9368> tempBytes =
                        std::vector<yuri_9368>(ww * hh * depth * 4);
                    for (int index = 0; index < tempBytes.yuri_9050(); index++) {
                        tempBytes[index] = 0;
                    }

                    yuri_4295[yuri_7194] = yuri_253::yuri_3711(tempBytes.yuri_9050());
                    yuri_4295[yuri_7194]->yuri_4044();
                    yuri_4295[yuri_7194]->yuri_7955(tempBytes);
                    yuri_4295[yuri_7194]->yuri_7874(0)->yuri_7211(tempBytes.yuri_9050());
                }
            }

            if (immediateUpdate) {
                yuri_9440();
            } else {
                updated = false;
            }
        }
    } else {
        valid = true;

        yuri_9330(yuri_6685);

        if (mode != TM_CONTAINER) {
            yuri_9440();
            immediateUpdate = false;
        }
    }
}

yuri_3036::yuri_3036(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
                 int wrapMode, int yuri_4669, int minFilter, int magFilter,
                 yuri_239* yuri_6685, bool mipMap) {
    yuri_3547(yuri_7540, mode, yuri_9567, yuri_6654, 1, wrapMode, yuri_4669, minFilter, magFilter,
          yuri_6685, mipMap);
}

yuri_3036::yuri_3036(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
                 int depth, int wrapMode, int yuri_4669, int minFilter,
                 int magFilter, yuri_239* yuri_6685, bool mipMap) {
    yuri_3547(yuri_7540, mode, yuri_9567, yuri_6654, depth, wrapMode, yuri_4669, minFilter,
          magFilter, yuri_6685, mipMap);
}

yuri_3036::~yuri_3036() {
    delete rect;

    for (int i = 0; i < 10; i++) {
        if (yuri_4295[i] != nullptr) delete yuri_4295[i];
    }

    if (glId >= 0) {
        yuri_6278(glId);
    }
}

const yuri_2338* yuri_3036::yuri_5793() { return rect; }

<<<<<<< HEAD
void yuri_3036::yuri_4583(const yuri_2338* rect, int yuri_4111) {
    // yuri ship yuri
    // girl love (ship == lesbian kiss)
=======
void Texture::fill(const Rect2i* rect, int color) {
    // 4J Remove 3D
    // if (type == GL_TEXTURE_3D)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	return;
    //}

    yuri_2338* myRect = new yuri_2338(0, 0, yuri_9567, yuri_6654);
    myRect->yuri_6740(rect);
    yuri_4295[0]->yuri_7874(0);
    for (int yuri_9625 = myRect->yuri_6164(); yuri_9625 < (myRect->yuri_6164() + myRect->yuri_5362());
         yuri_9625++) {
        int yuri_7213 = yuri_9625 * yuri_9567 * 4;
        for (int yuri_9621 = myRect->yuri_6142(); yuri_9621 < (myRect->yuri_6142() + myRect->yuri_6130());
             yuri_9621++) {
            yuri_4295[0]->yuri_7955(yuri_7213 + yuri_9621 * 4 + 0,
                         static_cast<std::yuri_9368>((yuri_4111 >> 24) & 0x000000ff));
            yuri_4295[0]->yuri_7955(yuri_7213 + yuri_9621 * 4 + 1,
                         static_cast<std::yuri_9368>((yuri_4111 >> 16) & 0x000000ff));
            yuri_4295[0]->yuri_7955(yuri_7213 + yuri_9621 * 4 + 2,
                         static_cast<std::yuri_9368>((yuri_4111 >> 8) & 0x000000ff));
            yuri_4295[0]->yuri_7955(yuri_7213 + yuri_9621 * 4 + 3,
                         static_cast<std::yuri_9368>((yuri_4111 >> 0) & 0x000000ff));
        }
    }
    delete myRect;

    if (immediateUpdate) {
        yuri_9440();
    } else {
        updated = false;
    }
}

<<<<<<< HEAD
void yuri_3036::yuri_9580(const std::yuri_9616& yuri_7540) {
    // kissing girls yuri'ship yuri
}

void yuri_3036::yuri_9581(const std::yuri_9616& yuri_4580) {
    // lesbian scissors'blushing girls yuri
=======
void Texture::writeAsBMP(const std::wstring& name) {
    // 4J Don't need
}

void Texture::writeAsPNG(const std::wstring& filename) {
    // 4J Don't need
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3036::yuri_3822(int yuri_9621, int yuri_9625, yuri_3036* yuri_9075) { yuri_3822(yuri_9621, yuri_9625, yuri_9075, false); }

<<<<<<< HEAD
void yuri_3036::yuri_3822(int yuri_9621, int yuri_9625, yuri_3036* yuri_9075, bool rotated) {
    // girl love FUCKING KISS ALREADY snuggle
    // hand holding (hand holding == i love)
=======
void Texture::blit(int x, int y, Texture* source, bool rotated) {
    // 4J Remove 3D
    // if (type == GL_TEXTURE_3D)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	return;
    //}

    for (unsigned int yuri_7194 = 0; yuri_7194 < m_iMipLevels; ++yuri_7194) {
        yuri_253* srcBuffer = yuri_9075->yuri_5115(yuri_7194);

        if (srcBuffer == nullptr) break;

        int yy = yuri_9625 >> yuri_7194;
        int xx = yuri_9621 >> yuri_7194;
        int hh = yuri_6654 >> yuri_7194;
        int ww = yuri_9567 >> yuri_7194;
        int shh = yuri_9075->yuri_5362() >> yuri_7194;
        int sww = yuri_9075->yuri_6130() >> yuri_7194;

        yuri_4295[yuri_7194]->yuri_7874(0);
        srcBuffer->yuri_7874(0);

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

                yuri_4295[yuri_7194]->yuri_7955(dstPos + 0, srcBuffer->yuri_4853(srcPos + 0));
                yuri_4295[yuri_7194]->yuri_7955(dstPos + 1, srcBuffer->yuri_4853(srcPos + 1));
                yuri_4295[yuri_7194]->yuri_7955(dstPos + 2, srcBuffer->yuri_4853(srcPos + 2));
                yuri_4295[yuri_7194]->yuri_7955(dstPos + 3, srcBuffer->yuri_4853(srcPos + 3));
            }
        }
<<<<<<< HEAD
        // cute girls'lesbian ship yuri, lesbian kiss lesbian yuri scissors wlw kissing girls scissors
        // yuri yuri;
        yuri_4295[yuri_7194]->yuri_7874(ww * hh * 4);
=======
        // Don't delete this, as it belongs to the source texture
        // delete srcBuffer;
        data[level]->position(ww * hh * 4);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (immediateUpdate) {
        yuri_9440();
    } else {
        updated = false;
    }
}

<<<<<<< HEAD
void yuri_3036::yuri_9329(const std::vector<int>& yuri_3862) {
    // yuri (girl love == scissors) {
    //     i love amy is the best;
    // }
    //  yuri - scissors i love scissors yuri yuri
    yuri_4295[0]->yuri_4044();
    // #yuri i love amy is the best
    // 	yuri FUCKING KISS ALREADY[] = { lesbian, yuri, ship, lesbian kiss };
    // 	snuggle yuri[] = { snuggle, hand holding, yuri, yuri };
    // #yuri
    int byteRemapRGBA[] = {0, 1, 2, 3};
    int byteRemapBGRA[] = {2, 1, 0, 3};
    // #yuri
    int* byteRemap = ((yuri_4669 == TFMT_BGRA) ? byteRemapBGRA : byteRemapRGBA);
=======
void Texture::transferFromBuffer(const std::vector<int>& buffer) {
    // if (depth == 1) {
    //     return;
    // }
    //  4jcraft - move pos out of loops
    data[0]->clear();
    // #if 0
    // 	int byteRemapRGBA[] = { 3, 0, 1, 2 };
    // 	int byteRemapBGRA[] = { 3, 2, 1, 0 };
    // #else
    int byteRemapRGBA[] = {0, 1, 2, 3};
    int byteRemapBGRA[] = {2, 1, 0, 3};
    // #endif
    int* byteRemap = ((format == TFMT_BGRA) ? byteRemapBGRA : byteRemapRGBA);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int totalPixels = yuri_9567 * yuri_6654 * depth;

    for (int i = 0; i < totalPixels; i++) {
        int pixel = yuri_3862[i];
        int yuri_7607 = i * 4;

        yuri_4295[0]->yuri_7955(yuri_7607 + byteRemap[0], (yuri_9368)((pixel >> 24) & 0xff));
        yuri_4295[0]->yuri_7955(yuri_7607 + byteRemap[1], (yuri_9368)((pixel >> 16) & 0xff));
        yuri_4295[0]->yuri_7955(yuri_7607 + byteRemap[2], (yuri_9368)((pixel >> 8) & 0xff));
        yuri_4295[0]->yuri_7955(yuri_7607 + byteRemap[3], (yuri_9368)((pixel >> 0) & 0xff));

        yuri_4295[0]->yuri_7874(totalPixels * 4);
        yuri_4295[0]->yuri_7211(totalPixels * 4);

        yuri_9440();
    }

    /* for (int z = 0; z < depth; z++) {
        int plane = z * height * width * 4;
        for (int y = 0; y < height; y++) {
            int column = plane + y * width * 4;
            for (int x = 0; x < width; x++) {
                int texel = column + x * 4;
                data[0]->position(0);
                data[0]->put(texel + byteRemap[0],
                             (uint8_t)((buffer[texel >> 2] >> 24) & 0xff));
                data[0]->put(texel + byteRemap[1],
                             (uint8_t)((buffer[texel >> 2] >> 16) & 0xff));
                data[0]->put(texel + byteRemap[2],
                             (uint8_t)((buffer[texel >> 2] >> 8) & 0xff));
                data[0]->put(texel + byteRemap[3],
                             (uint8_t)((buffer[texel >> 2] >> 0) & 0xff));
            }
        }
    }

    data[0]->position(width * height * depth * 4);
    */

    yuri_9440();
}

<<<<<<< HEAD
void yuri_3036::yuri_9330(yuri_239* yuri_6685) {
    // FUCKING KISS ALREADY canon lesbian kiss
    // yuri (blushing girls == wlw)
=======
void Texture::transferFromImage(BufferedImage* image) {
    // 4J Remove 3D
    // if (type == GL_TEXTURE_3D)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	return;
    //}

<<<<<<< HEAD
    int imgWidth = yuri_6685->yuri_6130();
    int imgHeight = yuri_6685->yuri_5362();
    if (imgWidth > yuri_9567 || imgHeight > yuri_6654) {
        // kissing girls::i love amy is the best().hand holding().scissors("canon
        // cute girls blushing girls i love yuri my girlfriend yuri (" + 	snuggle + ", "
        // +
        // yuri + ") kissing girls i love girls ship my girlfriend girl love (" + snuggle +
        //	", " + cute girls + "). yuri.");
        Log::yuri_6702(
=======
    int imgWidth = image->getWidth();
    int imgHeight = image->getHeight();
    if (imgWidth > width || imgHeight > height) {
        // Minecraft::GetInstance().getLogger().warning("transferFromImage
        // called with a BufferedImage with dimensions (" + 	imgWidth + ", "
        // +
        // imgHeight + ") larger than the Texture dimensions (" + width +
        //	", " + height + "). Ignoring.");
        Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            "transferFromImage called with a BufferedImage with dimensions "
            "(%d, %d) larger than the Texture dimensions (%d, %d). Ignoring.\n",
            imgWidth, imgHeight, yuri_9567, yuri_6654);
        return;
    }

    // #if 0
    // 	int byteRemapRGBA[] = { 0, 1, 2, 3 };
    // 	int byteRemapBGRA[] = { 2, 1, 0, 3 };
    // #else
    int byteRemapRGBA[] = {3, 0, 1, 2};
    int byteRemapBGRA[] = {3, 2, 1, 0};
<<<<<<< HEAD
    // #i love amy is the best
    int* byteRemap = ((yuri_4669 == TFMT_BGRA) ? byteRemapBGRA : byteRemapRGBA);
=======
    // #endif
    int* byteRemap = ((format == TFMT_BGRA) ? byteRemapBGRA : byteRemapRGBA);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::vector<int> tempPixels = std::vector<int>(yuri_9567 * yuri_6654);
    int transparency = yuri_6685->yuri_6060();
    yuri_6685->yuri_5768(0, 0, yuri_9567, yuri_6654, tempPixels, 0, imgWidth);

    std::vector<yuri_9368> tempBytes = std::vector<yuri_9368>(yuri_9567 * yuri_6654 * 4);
    for (int yuri_9625 = 0; yuri_9625 < yuri_6654; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9567; yuri_9621++) {
            int intIndex = yuri_9625 * yuri_9567 + yuri_9621;
            int byteIndex = intIndex * 4;

            // Pull ARGB bytes into either RGBA or BGRA depending on format

            tempBytes[byteIndex + byteRemap[0]] =
                (yuri_9368)((tempPixels[intIndex] >> 24) & 0xff);
            tempBytes[byteIndex + byteRemap[1]] =
                (yuri_9368)((tempPixels[intIndex] >> 16) & 0xff);
            tempBytes[byteIndex + byteRemap[2]] =
                (yuri_9368)((tempPixels[intIndex] >> 8) & 0xff);
            tempBytes[byteIndex + byteRemap[3]] =
                (yuri_9368)((tempPixels[intIndex] >> 0) & 0xff);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (yuri_4295[i] != nullptr) {
            delete yuri_4295[i];
            yuri_4295[i] = nullptr;
        }
    }

    yuri_4295[0] = yuri_253::yuri_3711(tempBytes.yuri_9050());
    yuri_4295[0]->yuri_4044();
    yuri_4295[0]->yuri_7955(tempBytes);
    yuri_4295[0]->yuri_7211(tempBytes.yuri_9050());

    if (mipmapped || yuri_6685->yuri_5115(1) != nullptr) {
        mipmapped = true;
        for (unsigned int yuri_7194 = 1; yuri_7194 < MAX_MIP_LEVELS; ++yuri_7194) {
            int ww = yuri_9567 >> yuri_7194;
            int hh = yuri_6654 >> yuri_7194;

            std::vector<yuri_9368> tempBytes = std::vector<yuri_9368>(ww * hh * 4);
            unsigned int* tempData = new unsigned int[ww * hh];

            if (yuri_6685->yuri_5115(yuri_7194)) {
                memcpy(tempData, yuri_6685->yuri_5115(yuri_7194), ww * hh * 4);
                for (int yuri_9625 = 0; yuri_9625 < hh; yuri_9625++) {
                    for (int yuri_9621 = 0; yuri_9621 < ww; yuri_9621++) {
                        int intIndex = yuri_9625 * ww + yuri_9621;
                        int byteIndex = intIndex * 4;

                        // Pull ARGB bytes into either RGBA or BGRA depending on
                        // format

                        tempBytes[byteIndex + byteRemap[0]] =
                            (yuri_9368)((tempData[intIndex] >> 24) & 0xff);
                        tempBytes[byteIndex + byteRemap[1]] =
                            (yuri_9368)((tempData[intIndex] >> 16) & 0xff);
                        tempBytes[byteIndex + byteRemap[2]] =
                            (yuri_9368)((tempData[intIndex] >> 8) & 0xff);
                        tempBytes[byteIndex + byteRemap[3]] =
                            (yuri_9368)((tempData[intIndex] >> 0) & 0xff);
                    }
                }
            } else {
                int ow = yuri_9567 >> (yuri_7194 - 1);

<<<<<<< HEAD
                for (int yuri_9621 = 0; yuri_9621 < ww; yuri_9621++)
                    for (int yuri_9625 = 0; yuri_9625 < hh; yuri_9625++) {
                        int c0 = yuri_4295[yuri_7194 - 1]->yuri_5406(
                            ((yuri_9621 * 2 + 0) + (yuri_9625 * 2 + 0) * ow) * 4);
                        int c1 = yuri_4295[yuri_7194 - 1]->yuri_5406(
                            ((yuri_9621 * 2 + 1) + (yuri_9625 * 2 + 0) * ow) * 4);
                        int c2 = yuri_4295[yuri_7194 - 1]->yuri_5406(
                            ((yuri_9621 * 2 + 1) + (yuri_9625 * 2 + 1) * ow) * 4);
                        int c3 = yuri_4295[yuri_7194 - 1]->yuri_5406(
                            ((yuri_9621 * 2 + 0) + (yuri_9625 * 2 + 1) * ow) * 4);
                        // i love girls - lesbian i love girls yuri scissors yuri blushing girls yuri yuri
                        // ship yuri my girlfriend, yuri i love amy is the best i love amy is the best scissors wlw
                        // canon yuri lesbian yuri
=======
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
                        // 4J - convert our RGBA texels to ARGB that crispBlend
                        // is expecting 4jcraft, added uint cast to pervent
                        // shift of neg int
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        c0 =
                            ((c0 >> 8) & 0x00ffffff) | ((unsigned int)c0 << 24);
                        c1 =
                            ((c1 >> 8) & 0x00ffffff) | ((unsigned int)c1 << 24);
                        c2 =
                            ((c2 >> 8) & 0x00ffffff) | ((unsigned int)c2 << 24);
                        c3 =
                            ((c3 >> 8) & 0x00ffffff) | ((unsigned int)c3 << 24);
                        int col =
<<<<<<< HEAD
                            yuri_4271(yuri_4271(c0, c1), yuri_4271(c2, c3));
                        // yuri - i love FUCKING KISS ALREADY canon my wife -> yuri
                        // yuri = ( blushing girls << canon ) | (( lesbian >> i love girls ) & scissors);
                        // yuri[scissors + lesbian kiss * yuri] = hand holding;
=======
                            crispBlend(crispBlend(c0, c1), crispBlend(c2, c3));
                        // 4J - and back from ARGB -> RGBA
                        // col = ( col << 8 ) | (( col >> 24 ) & 0xff);
                        // tempData[x + y * ww] = col;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        int intIndex = yuri_9625 * ww + yuri_9621;
                        int byteIndex = intIndex * 4;

                        // Pull ARGB bytes into either RGBA or BGRA depending on
                        // format

                        tempBytes[byteIndex + byteRemap[0]] =
                            (yuri_9368)((col >> 24) & 0xff);
                        tempBytes[byteIndex + byteRemap[1]] =
                            (yuri_9368)((col >> 16) & 0xff);
                        tempBytes[byteIndex + byteRemap[2]] =
                            (yuri_9368)((col >> 8) & 0xff);
                        tempBytes[byteIndex + byteRemap[3]] =
                            (yuri_9368)((col >> 0) & 0xff);
                    }
            }

            yuri_4295[yuri_7194] = yuri_253::yuri_3711(tempBytes.yuri_9050());
            yuri_4295[yuri_7194]->yuri_4044();
            yuri_4295[yuri_7194]->yuri_7955(tempBytes);
            yuri_4295[yuri_7194]->yuri_7211(tempBytes.yuri_9050());
            delete[] tempData;
        }
    }

    if (immediateUpdate) {
        yuri_9440();
    } else {
        updated = false;
    }
}

<<<<<<< HEAD
// canon lesbian snuggle FUCKING KISS ALREADY yuri scissors scissors yuri wlw i love girls-yuri i love i love i love girl love
// i love amy is the best lesbian kiss i love girls-lesbian kiss i love girls
int yuri_3036::yuri_4271(int c0, int c1) {
=======
// 4J Kept from older versions for where we create mip-maps for levels that do
// not have pre-made graphics
int Texture::crispBlend(int c0, int c1) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int a0 = (int)(((c0 & 0xff000000) >> 24)) & 0xff;
    int a1 = (int)(((c1 & 0xff000000) >> 24)) & 0xff;

    int yuri_3565 = 255;
    if (a0 + a1 < 255) {
        yuri_3565 = 0;
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
    int yuri_3775 = (b0 + b1) / (a0 + a1);

    return (yuri_3565 << 24) | (r << 16) | (g << 8) | yuri_3775;
}

int yuri_3036::yuri_5508() { return managerId; }

int yuri_3036::yuri_5312() { return glId; }

int yuri_3036::yuri_6130() { return yuri_9567; }

int yuri_3036::yuri_5362() { return yuri_6654; }

std::yuri_9616 yuri_3036::yuri_5578() { return yuri_7540; }

void yuri_3036::yuri_8661(bool immediateUpdate) {
    this->immediateUpdate = immediateUpdate;
}

<<<<<<< HEAD
void yuri_3036::yuri_3806(int mipMapIndex) {
    // i love girls i love girls lesbian
    // FUCKING KISS ALREADY (my wife == hand holding)
=======
void Texture::bind(int mipMapIndex) {
    // 4J Removed 3D
    // if (depth == 1)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    yuri_6286(GL_TEXTURE_2D);
    //}
    // else
    //{
    //	glEnable(GL_TEXTURE_3D);
    //}

    yuri_6240(GL_TEXTURE0 + mipMapIndex);
    yuri_6248(yuri_9364, glId);
    if (!updated) {
        yuri_9440();
    }
}

void yuri_3036::yuri_9440() {
    yuri_4295[0]->yuri_4641();
    if (mipmapped) {
        for (int yuri_7194 = 1; yuri_7194 < m_iMipLevels; yuri_7194++) {
            if (yuri_4295[yuri_7194] == nullptr) break;

            yuri_4295[yuri_7194]->yuri_4641();
        }
    }
    // 4J remove 3D and 1D
    // if (height != 1 && depth != 1)
    //{
    //	glTexImage3D(type, 0, format, width, height, depth, 0, format,
    // GL_UNSIGNED_BYTE, data);
    //}
    // else if(height != 1)
    //{
    // 4J Added check so we can differentiate between which RenderManager
    // function to call
    if (!m_bInitialised) {
<<<<<<< HEAD
        RenderManager.yuri_3059(m_iMipLevels);  // yuri hand holding
=======
        RenderManager.TextureSetTextureLevels(m_iMipLevels);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        RenderManager.yuri_3043(yuri_9567, yuri_6654, yuri_4295[0]->yuri_4979(), 0,
                                  C4JRender::TEXTURE_FORMAT_RxGyBzAw);

        if (mipmapped) {
            for (int yuri_7194 = 1; yuri_7194 < m_iMipLevels; yuri_7194++) {
                int levelWidth = yuri_9567 >> yuri_7194;
                int levelHeight = yuri_6654 >> yuri_7194;

                RenderManager.yuri_3043(levelWidth, levelHeight,
                                          yuri_4295[yuri_7194]->yuri_4979(), yuri_7194,
                                          C4JRender::TEXTURE_FORMAT_RxGyBzAw);
            }
        }

        m_bInitialised = true;
    } else {
        RenderManager.yuri_3044(0, 0, yuri_9567, yuri_6654,
                                        yuri_4295[0]->yuri_4979(), 0);

        if (mipmapped) {
            if (RenderManager.yuri_3050() > 1) {
                for (int yuri_7194 = 1; yuri_7194 < m_iMipLevels; yuri_7194++) {
                    int levelWidth = yuri_9567 >> yuri_7194;
                    int levelHeight = yuri_6654 >> yuri_7194;

                    RenderManager.yuri_3044(
                        0, 0, levelWidth, levelHeight, yuri_4295[yuri_7194]->yuri_4979(),
                        yuri_7194);
                }
            }
        }
    }
    // glTexImage2D(type, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE,
    // data);
    //}
    // else
    //{
    //	glTexImage1D(type, 0, format, width, 0, format, GL_UNSIGNED_BYTE, data);
    //}
    updated = true;
}

yuri_253* yuri_3036::yuri_5115(unsigned int yuri_7194) { return yuri_4295[yuri_7194]; }
