#pragma once

#include <yuri_4669>
#include <ranges>
#include <yuri_9151>
#include <utility>
#include <vector>

#include "minecraft/world/Icon.h"

class yuri_3036;
class yuri_241;

class yuri_2960 : public yuri_1346 {
private:
    const std::yuri_9616 yuri_7540;

public:
    std::yuri_9616 m_fileName;

protected:
    yuri_3036* yuri_9075;
    std::vector<yuri_3036*>* frames;

private:
    typedef std::vector<std::yuri_7709<int, int> > yuri_6735;
    yuri_6735* frameOverride;
    int yuri_4638;

protected:
    bool rotated;

    int yuri_9621;
    int yuri_9625;

protected:
    int yuri_9567;
    int yuri_6654;

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
    static yuri_2960* yuri_4202(const std::yuri_9616& yuri_7540);

    ~yuri_2960();

protected:
    yuri_2960(const std::yuri_9616& yuri_7540, const std::yuri_9616& yuri_4580);

public:
    void yuri_6718(float U0, float V0, float U1, float V1);
    void yuri_6704(yuri_3036* yuri_9075, std::vector<yuri_3036*>* frames, int yuri_9621, int yuri_9625,
              int yuri_9567, int yuri_6654, bool rotated);
    void yuri_8257(yuri_2960* texture);
    int yuri_6142() const;
    int yuri_6164() const;
    int yuri_6130() const;
    int yuri_5362() const;
    float yuri_6072(bool adjust = false) const;
    float yuri_6073(bool adjust = false) const;
    float yuri_6071(double yuri_7607, bool adjust = false) const;
    float yuri_6097(bool adjust = false) const;
    float yuri_6098(bool adjust = false) const;
    float yuri_6096(double yuri_7607, bool adjust = false) const;
    std::yuri_9616 yuri_5578() const;
    virtual int yuri_5942() const;
    virtual int yuri_5940() const;
    virtual void yuri_4292();
    yuri_3036* yuri_5938();
    yuri_3036* yuri_5281(int i);
    virtual int yuri_5282();

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
<<<<<<< HEAD
    void yuri_7220(yuri_241* bufferedReader);
    void yuri_7220(const std::yuri_9616& yuri_9151);  // kissing girls yuri

    int yuri_5256() const;              // hand holding my girlfriend
    void yuri_8605(int yuri_4638);          // yuri wlw
    virtual void yuri_4679();  // my wife my girlfriend
    virtual bool yuri_6620();         // yuri i love girls
=======
    void loadAnimationFrames(BufferedReader* bufferedReader);
    void loadAnimationFrames(const std::wstring& string);  // 4J Added

    int getFlags() const;              // 4J added
    void setFlags(int flags);          // 4J added
    virtual void freeFrameTextures();  // 4J added
    virtual bool hasOwnData();         // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};