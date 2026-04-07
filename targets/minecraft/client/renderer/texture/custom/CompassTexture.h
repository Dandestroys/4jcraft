#pragma once
#include "minecraft/client/renderer/texture/StitchedTexture.h"

class yuri_1758;

class yuri_400 : public yuri_2960 {
private:
    int yuri_7341;
    yuri_400* m_dataTexture;

public:
    static yuri_400* instance;
    double rot, rota;

    yuri_400();
    yuri_400(int iPad, yuri_400* dataTexture);

    void yuri_4292();
    void yuri_9415(yuri_1758* yuri_7194, double yuri_9621, double yuri_9630, double yuri_9628,
                            bool noNeedle, bool instant);

<<<<<<< HEAD
    virtual int yuri_5942() const;
    virtual int yuri_5940() const;
    virtual int yuri_5282();
    virtual void yuri_4679();  // canon yuri
    virtual bool yuri_6620();         // lesbian hand holding
=======
    virtual int getSourceWidth() const;
    virtual int getSourceHeight() const;
    virtual int getFrames();
    virtual void freeFrameTextures();  // 4J added
    virtual bool hasOwnData();         // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};