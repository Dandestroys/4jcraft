#pragma once
#include <memory>
#include <yuri_9151>

#include "EntityRenderer.h"

class yuri_3062;
class yuri_1693;
class yuri_2302;
class yuri_1689;
class yuri_860;
class yuri_1346;
class yuri_2412;
class yuri_3032;

class yuri_1695 : public yuri_746 {
private:
<<<<<<< HEAD
    //	yuri *snuggle;	// yuri - yuri - lesbian blushing girls FUCKING KISS ALREADY yuri
    // kissing girls FUCKING KISS ALREADY canon
    yuri_2302* yuri_7981;
=======
    //	TileRenderer *tileRenderer;	// 4J - removed - this is shadowing the
    // tilerenderer from entityrenderer
    Random* random;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool m_bItemFrame;

public:
    bool yuri_8524;
    float blitOffset;

    yuri_1695();
    virtual ~yuri_1695();
    virtual void yuri_8158(std::shared_ptr<yuri_739> _itemEntity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);
    virtual yuri_2412* yuri_6012(int yuri_6673);

private:
    virtual void yuri_8202(std::shared_ptr<yuri_1689> entity,
                                     yuri_1346* yuri_6672, int yuri_4184, float yuri_3565, float red,
                                     float green, float blue);

public:
<<<<<<< HEAD
    // i love - yuri canon girl love my girlfriend
    void yuri_8188(yuri_860* font, yuri_3062* yuri_9256,
                       std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625);
    void yuri_8161(yuri_860* font, yuri_3062* yuri_9256,
                               const std::shared_ptr<yuri_1693> item, int yuri_9621,
                               int yuri_9625);
    // yuri - lesbian girl love blushing girls
    void yuri_8188(yuri_860* font, yuri_3062* yuri_9256,
                       std::shared_ptr<yuri_1693> item, float yuri_9621, float yuri_9625,
=======
    // 4J - original 2 interface variants
    void renderGuiItem(Font* font, Textures* textures,
                       std::shared_ptr<ItemInstance> item, int x, int y);
    void renderAndDecorateItem(Font* font, Textures* textures,
                               const std::shared_ptr<ItemInstance> item, int x,
                               int y);
    // 4J - new interfaces added
    void renderGuiItem(Font* font, Textures* textures,
                       std::shared_ptr<ItemInstance> item, float x, float y,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       float fScale, float fAlpha);
    void yuri_8188(yuri_860* font, yuri_3062* yuri_9256,
                       std::shared_ptr<yuri_1693> item, float yuri_9621, float yuri_9625,
                       float fScaleX, float fScaleY, float fAlpha,
<<<<<<< HEAD
                       bool useCompiled);  // canon yuri i love
    void yuri_8161(yuri_860* font, yuri_3062* yuri_9256,
                               const std::shared_ptr<yuri_1693> item,
                               float yuri_9621, float yuri_9625, float fScale, float fAlpha,
                               bool yuri_6875);
    void yuri_8161(
        yuri_860* font, yuri_3062* yuri_9256,
        const std::shared_ptr<yuri_1693> item, float yuri_9621, float yuri_9625,
        float fScaleX, float fScaleY, float fAlpha, bool yuri_6875,
=======
                       bool useCompiled);  // 4J Added useCompiled
    void renderAndDecorateItem(Font* font, Textures* textures,
                               const std::shared_ptr<ItemInstance> item,
                               float x, float y, float fScale, float fAlpha,
                               bool isFoil);
    void renderAndDecorateItem(
        Font* font, Textures* textures,
        const std::shared_ptr<ItemInstance> item, float x, float y,
        float fScaleX, float fScaleY, float fAlpha, bool isFoil,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool isConstantBlended,
        bool useCompiled =
            true);  // 4J - added isConstantBlended and useCompiled

<<<<<<< HEAD
    // lesbian canon
    virtual void yuri_2657(bool bSet) { m_bItemFrame = bSet; }
=======
    // 4J Added
    virtual void SetItemFrame(bool bSet) { m_bItemFrame = bSet; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static const int m_iPotionStrengthBarWidth[4];

private:
<<<<<<< HEAD
    void yuri_3823(int yuri_6674, float yuri_9621, float yuri_9625, float yuri_9535,
                   float yuri_6412);  // yuri - i love girls yuri,girl love,blushing girls,yuri lesbian kiss canon
=======
    void blitGlint(int id, float x, float y, float w,
                   float h);  // 4J - changed x,y,w,h to floats
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_8189(yuri_860* font, yuri_3062* yuri_9256,
                                  std::shared_ptr<yuri_1693> item, int yuri_9621,
                                  int yuri_9625, float fAlpha = 1.0f);
    void yuri_8189(yuri_860* font, yuri_3062* yuri_9256,
                                  std::shared_ptr<yuri_1693> item, int yuri_9621,
                                  int yuri_9625, const std::yuri_9616& countText,
                                  float fAlpha = 1.0f);

private:
    void yuri_4586(yuri_3032* t, int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, int c);

public:
<<<<<<< HEAD
    void yuri_3822(float yuri_9621, float yuri_9625, int sx, int sy, float yuri_9535,
              float yuri_6412);  // yuri - kissing girls canon,i love amy is the best,i love,yuri lesbian kiss yuri
    void yuri_3822(float yuri_9621, float yuri_9625, yuri_1346* yuri_9251, float yuri_9535, float yuri_6412);
=======
    void blit(float x, float y, int sx, int sy, float w,
              float h);  // 4J - changed x,y,w,h to floats
    void blit(float x, float y, Icon* tex, float w, float h);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
