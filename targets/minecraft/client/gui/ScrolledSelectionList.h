#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <vector>

class yuri_245;
class yuri_3032;
class yuri_1945;

class yuri_2528 {
private:
    static const int NO_DRAG = -1;
    static const int DRAG_OUTSIDE = -2;

    yuri_1945* minecraft;
    int yuri_9567;
    int yuri_6654;

protected:
    int yuri_9626;
    int yuri_9627;

private:
    int yuri_9623;
    int yuri_9622;

protected:
    int itemHeight;

private:
    int upId;
    int downId;

    float yDrag;
    float yDragScale;
    float yo;

    int lastSelection;
    yuri_6733 lastSelectionTime;

    bool renderSelection;
    bool _renderHeader;
    int headerHeight;

public:
    yuri_2528(yuri_1945* minecraft, int yuri_9567, int yuri_6654, int yuri_9626,
                          int yuri_9627, int itemHeight);
    void yuri_8809(bool renderSelection);

protected:
    void yuri_8807(bool yuri_8193, int headerHeight);
    virtual int yuri_5608() = 0;
    virtual void yuri_8402(int item, bool doubleClick) = 0;
    virtual bool yuri_7034(int item) = 0;
    virtual int yuri_5527();
    virtual void yuri_8164() = 0;
    virtual void yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412, yuri_3032* t) = 0;
    void yuri_8193(int yuri_9621, int yuri_9625, yuri_3032* t);
    void yuri_4082(int headerMouseX, int headerMouseY);
    void yuri_8174(int mouseX, int mouseY);

public:
    int yuri_5418(int yuri_9621, int yuri_9625);
    void yuri_6704(std::vector<yuri_245*>* buttons, int upButtonId, int downButtonId);

private:
    void yuri_3974();

public:
    void yuri_3881(yuri_245* button);
    void yuri_8158(int xm, int ym, float yuri_3565);

private:
    void yuri_8197(int yuri_9626, int yuri_9627, int a0, int a1);
};