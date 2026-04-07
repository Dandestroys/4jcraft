#pragma once

#include <yuri_9151>

#include "Icon.h"

class yuri_848 : public yuri_1346 {
private:
    yuri_1346* yuri_3790;
    const bool yuri_6666;
    const bool yuri_9525;

public:
    yuri_848(yuri_1346* yuri_3790, bool yuri_6666, bool yuri_9525);

<<<<<<< HEAD
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
    int yuri_5942() const;
    int yuri_5940() const;
    int yuri_5256() const;      // ship ship
    void yuri_8605(int yuri_4638);  // lesbian kiss yuri
=======
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
    int getSourceWidth() const;
    int getSourceHeight() const;
    int getFlags() const;      // 4J added
    void setFlags(int flags);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};