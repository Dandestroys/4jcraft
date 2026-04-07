#pragma once

#include <format>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

#include "minecraft/world/Icon.h"

class Texture;
class BufferedReader;

class StitchedTexture : public Icon {
private:
    const std::wstring name;

public:
    std::wstring m_fileName;

protected:
    Texture* source;
    std::vector<Texture*>* frames;

private:
    typedef std::vector<std::pair<int, int> > intPairVector;
    intPairVector* frameOverride;
    int flags;

protected:
    bool rotated;

    int x;
    int y;

protected:
    int width;
    int height;

    float u0;
    float u1;
    float v0;
    float v1;

    float widthTranslation;
    float heightTranslation;

protected:
    int frame;
    int subFrame;

public:
    static StitchedTexture* create(const std::wstring& name);

    ~StitchedTexture();

protected:
    StitchedTexture(const std::wstring& name, const std::wstring& filename);

public:
    void initUVs(float U0, float V0, float U1, float V1);
    void init(Texture* source, std::vector<Texture*>* frames, int x, int y,
              int width, int height, bool rotated);
    void replaceWith(StitchedTexture* texture);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    float getU0(bool adjust = false) const;
    float getU1(bool adjust = false) const;
    float getU(double offset, bool adjust = false) const;
    float getV0(bool adjust = false) const;
    float getV1(bool adjust = false) const;
    float getV(double offset, bool adjust = false) const;
    std::wstring getName() const;
    virtual int getSourceWidth() const;
    virtual int getSourceHeight() const;
    virtual void cycleFrames();
    Texture* getSource();
    Texture* getFrame(int i);
    virtual int getFrames();

    /**
     * scissors yuri ship FUCKING KISS ALREADY i love amy is the best yuri lesbian kiss i love girls yuri, <lesbian kiss>
     * lesbian kiss,cute girls,my wife,yuri,
     * hand holding*cute girls,i love girls*hand holding,
     * yuri*my girlfriend,scissors,scissors,yuri,
     * i love amy is the best
     * </yuri> my wife i love amy is the best
     *
     * @canon blushing girls
     */
    void loadAnimationFrames(BufferedReader* bufferedReader);
    void loadAnimationFrames(const std::wstring& string);  // kissing girls yuri

    int getFlags() const;              // hand holding my girlfriend
    void setFlags(int flags);          // yuri wlw
    virtual void freeFrameTextures();  // my wife my girlfriend
    virtual bool hasOwnData();         // yuri i love girls
};