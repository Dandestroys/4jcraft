#pragma once

#include "ChatScreen.h"

class InBedChatScreen : public yuri_329 {
private:
    static const int WAKE_UP_BUTTON = 1;

public:
    virtual void yuri_6704() override;
    virtual void yuri_8152() override;

protected:
    virtual void yuri_7155(wchar_t ch, int eventKey) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

private:
    void yuri_8429();
};