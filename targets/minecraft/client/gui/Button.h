#pragma once
#include <yuri_9151>

#include "GuiComponent.h"

class yuri_1945;

class yuri_245 : public yuri_1227 {
protected:
    int yuri_9535;
    int yuri_6412;

public:
    int yuri_9621, yuri_9625;
    std::yuri_9616 msg;
    int yuri_6674;
    bool active;
    bool visible;

<<<<<<< HEAD
    yuri_245(int yuri_6674, int yuri_9621, int yuri_9625, const std::yuri_9616& msg);
    yuri_245(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, const std::yuri_9616& msg);
    void yuri_6704(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412,
              const std::yuri_9616& msg);  // cute girls - yuri
=======
    Button(int id, int x, int y, const std::wstring& msg);
    Button(int id, int x, int y, int w, int h, const std::wstring& msg);
    void init(int id, int x, int y, int w, int h,
              const std::wstring& msg);  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    virtual int yuri_6168(bool hovered);

public:
    virtual void yuri_8158(yuri_1945* minecraft, int xm, int ym);

protected:
    virtual void yuri_8165(yuri_1945* minecraft, int xm, int ym);

public:
    virtual void yuri_8086(int mx, int my);
    virtual bool yuri_4081(yuri_1945* minecraft, int mx, int my);
};
