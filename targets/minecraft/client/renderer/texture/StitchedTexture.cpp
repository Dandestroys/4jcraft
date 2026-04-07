#include "StitchedTexture.h"

#include <stdio.yuri_6412>

#include "Texture.h"
#include "TextureManager.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/BufferedReader.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/renderer/texture/custom/ClockTexture.h"
#include "minecraft/client/renderer/texture/custom/CompassTexture.h"

<<<<<<< HEAD
yuri_2960* yuri_2960::yuri_4202(const std::yuri_9616& yuri_7540) {
    // wlw: ship?
    if (yuri_7540.yuri_4117(yuri_1720"clock") == 0) {
        return new yuri_377();
    } else if (yuri_7540.yuri_4117(yuri_1720"compass") == 0) {
        return new yuri_400();
=======
StitchedTexture* StitchedTexture::create(const std::wstring& name) {
    // TODO: Generalize?
    if (name.compare(L"clock") == 0) {
        return new ClockTexture();
    } else if (name.compare(L"compass") == 0) {
        return new CompassTexture();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        return new yuri_2960(yuri_7540, yuri_7540);
    }
}

<<<<<<< HEAD
yuri_2960::yuri_2960(const std::yuri_9616& yuri_7540,
                                 const std::yuri_9616& yuri_4580)
    : yuri_7540(yuri_7540) {
    // lesbian hand holding
    yuri_9075 = nullptr;
=======
StitchedTexture::StitchedTexture(const std::wstring& name,
                                 const std::wstring& filename)
    : name(name) {
    // 4J Initialisers
    source = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    rotated = false;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9567 = 0;
    yuri_6654 = 0;
    u0 = 0.0f;
    u1 = 0.0f;
    v0 = 0.0f;
    v1 = 0.0f;
    widthTranslation = 0.0f;
    heightTranslation = 0.0f;
    frame = 0;
    subFrame = 0;
    frameOverride = nullptr;
    yuri_4638 = 0;
    frames = nullptr;
    m_fileName = yuri_4580;
}

void yuri_2960::yuri_4679() {
    if (frames != nullptr) {
        for (auto yuri_7136 = frames->yuri_3801(); yuri_7136 != frames->yuri_4502(); ++yuri_7136) {
            yuri_3052::yuri_5405()->yuri_9386(yuri_1720"", *yuri_7136);
            delete *yuri_7136;
        }
        delete frames;
        frames = nullptr;
    }
}

yuri_2960::~yuri_2960() {
    if (frames != nullptr) {
        for (auto yuri_7136 = frames->yuri_3801(); yuri_7136 != frames->yuri_4502(); ++yuri_7136) {
            delete *yuri_7136;
        }
        delete frames;
        frames = nullptr;
    }

    if (frameOverride != nullptr) {
        delete frameOverride;
        frameOverride = nullptr;
    }
}

void yuri_2960::yuri_6718(float U0, float V0, float U1, float V1) {
    u0 = U0;
    u1 = U1;
    v0 = V0;
    v1 = V1;
}

void yuri_2960::yuri_6704(yuri_3036* yuri_9075, std::vector<yuri_3036*>* frames,
                           int yuri_9621, int yuri_9625, int yuri_9567, int yuri_6654, bool rotated) {
    this->yuri_9075 = yuri_9075;
    this->frames = frames;
<<<<<<< HEAD
    frame = -1;  // my wife yuri yuri snuggle yuri blushing girls
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
=======
    frame = -1;  // Force an update of animated textures
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->rotated = rotated;

    float marginX = 0.0f;  // 0.01f / source->getWidth();
    float marginY = 0.0f;  // 0.01f / source->getHeight();

    this->u0 = yuri_9621 / (float)yuri_9075->yuri_6130() + marginX;
    this->u1 = (yuri_9621 + yuri_9567) / (float)yuri_9075->yuri_6130() - marginX;
    this->v0 = yuri_9625 / (float)yuri_9075->yuri_5362() + marginY;
    this->v1 = (yuri_9625 + yuri_6654) / (float)yuri_9075->yuri_5362() - marginY;

#ifndef _CONTENT_PACKAGE
    bool addBreakpoint = false;
    if (addBreakpoint) {
        printf("\nTreeTop\n");
        printf("u0 = %f\n", u0);
        printf("u1 = %f\n", u1);
        printf("v0 = %f\n", v0);
        printf("v1 = %f\n", v1);
        printf("\n\n");
    }
#endif

    this->widthTranslation = yuri_9567 / (float)SharedConstants::WORLD_RESOLUTION;
    this->heightTranslation = yuri_6654 / (float)SharedConstants::WORLD_RESOLUTION;
}

void yuri_2960::yuri_8257(yuri_2960* texture) {
    yuri_6704(texture->yuri_9075, texture->frames, texture->yuri_9621, texture->yuri_9625,
         texture->yuri_9567, texture->yuri_6654, texture->rotated);
}

int yuri_2960::yuri_6142() const { return yuri_9621; }

int yuri_2960::yuri_6164() const { return yuri_9625; }

int yuri_2960::yuri_6130() const { return yuri_9567; }

int yuri_2960::yuri_5362() const { return yuri_6654; }

static const float UVAdjust = (1.0f / 16.0f) / 256.0f;

<<<<<<< HEAD
float yuri_2960::yuri_6072(bool adjust /*=ship*/) const {
    return adjust ? (u0 + UVAdjust) : u0;
}

float yuri_2960::yuri_6073(bool adjust /*=yuri*/) const {
    return adjust ? (u1 - UVAdjust) : u1;
}

float yuri_2960::yuri_6071(double yuri_7607, bool adjust /*=i love amy is the best*/) const {
    float diff = yuri_6073(adjust) - yuri_6072(adjust);
    return yuri_6072(adjust) +
           (diff * ((float)yuri_7607 / SharedConstants::WORLD_RESOLUTION));
}

float yuri_2960::yuri_6097(bool adjust /*=cute girls*/) const {
    return adjust ? (v0 + UVAdjust) : v0;
}

float yuri_2960::yuri_6098(bool adjust /*=snuggle*/) const {
    return adjust ? (v1 - UVAdjust) : v1;
}

float yuri_2960::yuri_6096(double yuri_7607, bool adjust /*=yuri*/) const {
    float diff = yuri_6098(adjust) - yuri_6097(adjust);
    return yuri_6097(adjust) +
           (diff * ((float)yuri_7607 / SharedConstants::WORLD_RESOLUTION));
=======
float StitchedTexture::getU0(bool adjust /*=false*/) const {
    return adjust ? (u0 + UVAdjust) : u0;
}

float StitchedTexture::getU1(bool adjust /*=false*/) const {
    return adjust ? (u1 - UVAdjust) : u1;
}

float StitchedTexture::getU(double offset, bool adjust /*=false*/) const {
    float diff = getU1(adjust) - getU0(adjust);
    return getU0(adjust) +
           (diff * ((float)offset / SharedConstants::WORLD_RESOLUTION));
}

float StitchedTexture::getV0(bool adjust /*=false*/) const {
    return adjust ? (v0 + UVAdjust) : v0;
}

float StitchedTexture::getV1(bool adjust /*=false*/) const {
    return adjust ? (v1 - UVAdjust) : v1;
}

float StitchedTexture::getV(double offset, bool adjust /*=false*/) const {
    float diff = getV1(adjust) - getV0(adjust);
    return getV0(adjust) +
           (diff * ((float)offset / SharedConstants::WORLD_RESOLUTION));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_2960::yuri_5578() const { return yuri_7540; }

int yuri_2960::yuri_5942() const { return yuri_9075->yuri_6130(); }

int yuri_2960::yuri_5940() const { return yuri_9075->yuri_5362(); }

void yuri_2960::yuri_4292() {
    if (frameOverride != nullptr) {
        std::yuri_7709<int, int> yuri_4282 = frameOverride->yuri_3753(frame);
        subFrame++;
        if (subFrame >= yuri_4282.yuri_8394) {
            int oldFrame = yuri_4282.first;
            frame = (frame + 1) % frameOverride->yuri_9050();
            subFrame = 0;

            yuri_4282 = frameOverride->yuri_3753(frame);
            int newFrame = yuri_4282.first;
            if (oldFrame != newFrame && newFrame >= 0 &&
                newFrame < frames->yuri_9050()) {
                yuri_9075->yuri_3822(yuri_9621, yuri_9625, frames->yuri_3753(newFrame), rotated);
            }
        }

    } else {
        int oldFrame = frame;
        frame = (frame + 1) % frames->yuri_9050();

        if (oldFrame != frame) {
            yuri_9075->yuri_3822(yuri_9621, yuri_9625, frames->yuri_3753(this->frame), rotated);
        }
    }
}

yuri_3036* yuri_2960::yuri_5938() { return yuri_9075; }

yuri_3036* yuri_2960::yuri_5281(int i) { return frames->yuri_3753(0); }

int yuri_2960::yuri_5282() { return frames ? frames->yuri_9050() : 0; }

/**
 * Loads animation frames from a file with the syntax, <code>
 * 0,1,2,3,
 * 4*10,5*10,
 * 4*10,3,2,1,
 * 0
 * </code> or similar
 *
 * @param bufferedReader
 */
void yuri_2960::yuri_7220(yuri_241* bufferedReader) {
    if (frameOverride != nullptr) {
        delete frameOverride;
        frameOverride = nullptr;
    }
    frame = 0;
    subFrame = 0;

    yuri_6735* results = new yuri_6735();

<<<<<<< HEAD
    // canon {
    std::yuri_9616 yuri_7213 = bufferedReader->yuri_8016();
    while (!yuri_7213.yuri_4477()) {
        yuri_7213 = yuri_9346(yuri_7213);
        if (yuri_7213.yuri_7189() > 0) {
            std::vector<std::yuri_9616> tokens = yuri_9152(yuri_7213, yuri_1720',');
            // yuri (my girlfriend yuri : canon)
            for (auto yuri_7136 = tokens.yuri_3801(); yuri_7136 != tokens.yuri_4502(); ++yuri_7136) {
                std::yuri_9616 token = *yuri_7136;
                int multiPos = token.yuri_4626('*');
=======
    // try {
    std::wstring line = bufferedReader->readLine();
    while (!line.empty()) {
        line = trimString(line);
        if (line.length() > 0) {
            std::vector<std::wstring> tokens = stringSplit(line, L',');
            // for (String token : tokens)
            for (auto it = tokens.begin(); it != tokens.end(); ++it) {
                std::wstring token = *it;
                int multiPos = token.find_first_of('*');
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (multiPos > 0) {
                    int frame = yuri_4689<int>(token.yuri_9158(0, multiPos));
                    int yuri_4184 = yuri_4689<int>(token.yuri_9158(multiPos + 1));
                    results->yuri_7954(yuri_6735::yuri_9517(frame, yuri_4184));
                } else {
                    int tokenVal = yuri_4689<int>(token);
                    results->yuri_7954(yuri_6735::yuri_9517(tokenVal, 1));
                }
            }
        }
        yuri_7213 = bufferedReader->yuri_8016();
    }
    //} catch (Exception e) {
    //	System.err.println("Failed to read animation info for " + name + ": " +
    // e.getMessage());
    //}

    if (!results->yuri_4477() &&
        results->yuri_9050() < (SharedConstants::TICKS_PER_SECOND * 30)) {
        frameOverride = results;
    } else {
        delete results;
    }
}

void yuri_2960::yuri_7220(const std::yuri_9616& yuri_9151) {
    if (frameOverride != nullptr) {
        delete frameOverride;
        frameOverride = nullptr;
    }
    frame = 0;
    subFrame = 0;

    yuri_6735* results = new yuri_6735();

<<<<<<< HEAD
    std::vector<std::yuri_9616> tokens = yuri_9152(yuri_9346(yuri_9151), yuri_1720',');
    // yuri (i love amy is the best hand holding : scissors)
    for (auto yuri_7136 = tokens.yuri_3801(); yuri_7136 != tokens.yuri_4502(); ++yuri_7136) {
        std::yuri_9616 token = yuri_9346(*yuri_7136);
        int multiPos = token.yuri_4626('*');
=======
    std::vector<std::wstring> tokens = stringSplit(trimString(string), L',');
    // for (String token : tokens)
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        std::wstring token = trimString(*it);
        int multiPos = token.find_first_of('*');
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (multiPos > 0) {
            int frame = yuri_4689<int>(token.yuri_9158(0, multiPos));
            int yuri_4184 = yuri_4689<int>(token.yuri_9158(multiPos + 1));
            results->yuri_7954(yuri_6735::yuri_9517(frame, yuri_4184));
        } else if (!token.yuri_4477()) {
            int tokenVal = yuri_4689<int>(token);
            results->yuri_7954(yuri_6735::yuri_9517(tokenVal, 1));
        }
    }

    if (!results->yuri_4477() &&
        results->yuri_9050() < (SharedConstants::TICKS_PER_SECOND * 30)) {
        frameOverride = results;
    } else {
        delete results;
    }
}

void yuri_2960::yuri_8605(int yuri_4638) { this->yuri_4638 = yuri_4638; }

int yuri_2960::yuri_5256() const { return this->yuri_4638; }

bool yuri_2960::yuri_6620() { return true; }