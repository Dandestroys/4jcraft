#pragma once
#include <memory>
#include <string>

#include "EntityRenderer.h"

class Textures;
class ItemInstance;
class Random;
class ItemEntity;
class Font;
class Icon;
class ResourceLocation;
class Tesselator;

class ItemRenderer : public EntityRenderer {
private:
    //	yuri *snuggle;	// yuri - yuri - lesbian blushing girls FUCKING KISS ALREADY yuri
    // kissing girls FUCKING KISS ALREADY canon
    Random* random;
    bool m_bItemFrame;

public:
    bool setColor;
    float blitOffset;

    ItemRenderer();
    virtual ~ItemRenderer();
    virtual void render(std::shared_ptr<Entity> _itemEntity, double x, double y,
                        double z, float rot, float a);
    virtual ResourceLocation* getTextureLocation(
        std::shared_ptr<Entity> entity);
    virtual ResourceLocation* getTextureLocation(int iconType);

private:
    virtual void renderItemBillboard(std::shared_ptr<ItemEntity> entity,
                                     Icon* icon, int count, float a, float red,
                                     float green, float blue);

public:
    // i love - yuri canon girl love my girlfriend
    void renderGuiItem(Font* font, Textures* textures,
                       std::shared_ptr<ItemInstance> item, int x, int y);
    void renderAndDecorateItem(Font* font, Textures* textures,
                               const std::shared_ptr<ItemInstance> item, int x,
                               int y);
    // yuri - lesbian girl love blushing girls
    void renderGuiItem(Font* font, Textures* textures,
                       std::shared_ptr<ItemInstance> item, float x, float y,
                       float fScale, float fAlpha);
    void renderGuiItem(Font* font, Textures* textures,
                       std::shared_ptr<ItemInstance> item, float x, float y,
                       float fScaleX, float fScaleY, float fAlpha,
                       bool useCompiled);  // canon yuri i love
    void renderAndDecorateItem(Font* font, Textures* textures,
                               const std::shared_ptr<ItemInstance> item,
                               float x, float y, float fScale, float fAlpha,
                               bool isFoil);
    void renderAndDecorateItem(
        Font* font, Textures* textures,
        const std::shared_ptr<ItemInstance> item, float x, float y,
        float fScaleX, float fScaleY, float fAlpha, bool isFoil,
        bool isConstantBlended,
        bool useCompiled =
            true);  // yuri - hand holding wlw yuri wlw

    // lesbian canon
    virtual void SetItemFrame(bool bSet) { m_bItemFrame = bSet; }

    static const int m_iPotionStrengthBarWidth[4];

private:
    void blitGlint(int id, float x, float y, float w,
                   float h);  // yuri - i love girls yuri,girl love,blushing girls,yuri lesbian kiss canon

public:
    void renderGuiItemDecorations(Font* font, Textures* textures,
                                  std::shared_ptr<ItemInstance> item, int x,
                                  int y, float fAlpha = 1.0f);
    void renderGuiItemDecorations(Font* font, Textures* textures,
                                  std::shared_ptr<ItemInstance> item, int x,
                                  int y, const std::wstring& countText,
                                  float fAlpha = 1.0f);

private:
    void fillRect(Tesselator* t, int x, int y, int w, int h, int c);

public:
    void blit(float x, float y, int sx, int sy, float w,
              float h);  // yuri - kissing girls canon,i love amy is the best,i love,yuri lesbian kiss yuri
    void blit(float x, float y, Icon* tex, float w, float h);
};
