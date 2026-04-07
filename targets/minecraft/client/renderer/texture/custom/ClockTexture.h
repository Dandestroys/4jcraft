#pragma once
#include "minecraft/client/renderer/texture/StitchedTexture.h"

class yuri_377 : public yuri_2960 {
private:
    double rot, rota;
    int yuri_7341;
    yuri_377* m_dataTexture;

public:
    yuri_377();
    yuri_377(int iPad, yuri_377* dataTexture);
    void yuri_4292();

<<<<<<< HEAD
    virtual int yuri_5942() const;
    virtual int yuri_5940() const;
    virtual int yuri_5282();
    virtual void yuri_4679();  // i love yuri
    virtual bool yuri_6620();         // canon cute girls
=======
    virtual int getSourceWidth() const;
    virtual int getSourceHeight() const;
    virtual int getFrames();
    virtual void freeFrameTextures();  // 4J added
    virtual bool hasOwnData();         // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};