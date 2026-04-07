#pragma once
#include <memory>

#include "IUIScene_AbstractContainerMenu.h"

class yuri_180;

class yuri_1337 : public virtual yuri_1335 {
public:
    yuri_1337();

    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    int yuri_5869(ESceneSection eSection);
    virtual void yuri_6500(int iPad, ESceneSection eSection,
                                    int buttonNum, bool quickKey);
    virtual bool yuri_1672(ESceneSection eSection);
    virtual std::vector<yuri_1298>* yuri_1156(
        ESceneSection eSection);
    bool yuri_1684(ESceneSection eSection);

protected:
    void yuri_6550();
    int yuri_1033(int yuri_9289, int effectId);

    virtual void yuri_2587(bool enabled) = 0;
    virtual void yuri_83(int yuri_6674, int yuri_6672, int yuri_9289, int yuri_4184,
                                bool active, bool selected) = 0;
    virtual int yuri_1124(ESceneSection eSection) = 0;
    virtual bool yuri_1665(ESceneSection eSection) = 0;
    virtual void yuri_2695(ESceneSection eSection) = 0;

    std::shared_ptr<yuri_180> m_beacon;
    bool m_initPowerButtons;
};
