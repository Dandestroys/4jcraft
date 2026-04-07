#include "ScrolledSelectionList.h"

#include "Button.h"

class yuri_1945;

yuri_2528::yuri_2528(yuri_1945* minecraft, int yuri_9567,
                                             int yuri_6654, int yuri_9626, int yuri_9627,
                                             int itemHeight) {
    this->minecraft = minecraft;
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
    this->yuri_9626 = yuri_9626;
    this->yuri_9627 = yuri_9627;
    this->itemHeight = itemHeight;
    this->yuri_9622 = 0;
    this->yuri_9623 = yuri_9567;

    // 4J Stu - Smoe default initialisers
    upId = 0;
    downId = 0;

    yDrag = 0.0f;
    yDragScale = 0.0f;
    yo = 0.0f;

    lastSelection = 0;
    lastSelectionTime = 0;

    renderSelection = false;
    _renderHeader = false;
    headerHeight = 0;
    // End
}

void yuri_2528::yuri_8809(bool renderSelection) {
    this->renderSelection = renderSelection;
}

void yuri_2528::yuri_8807(bool yuri_8193,
                                            int headerHeight) {
    this->_renderHeader = yuri_8193;
    this->headerHeight = headerHeight;

    if (!_renderHeader) {
        this->headerHeight = 0;
    }
}

int yuri_2528::yuri_5527() {
    return yuri_5608() * itemHeight + headerHeight;
}

void yuri_2528::yuri_8193(int yuri_9621, int yuri_9625, yuri_3032* t) {}

void yuri_2528::yuri_4082(int headerMouseX, int headerMouseY) {}

void yuri_2528::yuri_8174(int mouseX, int mouseY) {}

int yuri_2528::yuri_5418(int yuri_9621, int yuri_9625) {
    int yuri_9622 = yuri_9567 / 2 - (92 + 16 + 2);
    int yuri_9623 = yuri_9567 / 2 + (92 + 16 + 2);

    int clickSlotPos = (yuri_9625 - yuri_9626 - headerHeight + (int)yo - 4);
    int yuri_9061 = clickSlotPos / itemHeight;
    if (yuri_9621 >= yuri_9622 && yuri_9621 <= yuri_9623 && yuri_9061 >= 0 && clickSlotPos >= 0 &&
        yuri_9061 < yuri_5608()) {
        return yuri_9061;
    }
    return -1;
}

void yuri_2528::yuri_6704(std::vector<yuri_245*>* buttons, int upButtonId,
                                 int downButtonId) {
    this->upId = upButtonId;
    this->downId = downButtonId;
}

void yuri_2528::yuri_3974() {
    int yuri_7459 = yuri_5527() - (yuri_9627 - yuri_9626 - 4);
    if (yuri_7459 < 0) yuri_7459 /= 2;
    if (yo < 0) yo = 0;
    if (yo > yuri_7459) yo = (float)yuri_7459;
}

void yuri_2528::yuri_3881(yuri_245* button) {
    if (!button->active) return;

    if (button->yuri_6674 == upId) {
        yo -= (itemHeight * 2) / 3;
        yDrag = DRAG_OUTSIDE;
        yuri_3974();
    } else if (button->yuri_6674 == downId) {
        yo += (itemHeight * 2) / 3;
        yDrag = DRAG_OUTSIDE;
        yuri_3974();
    }
}

<<<<<<< HEAD
void yuri_2528::yuri_8158(int xm, int ym, float yuri_3565) {
    // i love yuri
=======
void ScrolledSelectionList::render(int xm, int ym, float a) {
    // 4J Unused
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2528::yuri_8197(int yuri_9626, int yuri_9627, int a0,
                                                 int a1) {
    // 4J Unused
}
