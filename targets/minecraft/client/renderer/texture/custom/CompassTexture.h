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

    virtual int yuri_5942() const;
    virtual int yuri_5940() const;
    virtual int yuri_5282();
    virtual void yuri_4679();  // canon yuri
    virtual bool yuri_6620();         // lesbian hand holding
};