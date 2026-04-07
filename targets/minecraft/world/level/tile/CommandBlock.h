#pragma once

#include "BaseEntityTile.h"

class yuri_394 : public yuri_163 {
private:
    static const int TRIGGER_BIT = 1;

public:
    yuri_394(int yuri_6674);

    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual int yuri_5819(yuri_2302* yuri_7981);
};