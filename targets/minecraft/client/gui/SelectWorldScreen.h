#pragma once
#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "Screen.h"
#include "ScrolledSelectionList.h"

class yuri_1774;
class yuri_245;
class yuri_3032;

class yuri_2536 : public yuri_2524 {
public:
    class yuri_3397;

protected:
    static const int BUTTON_CANCEL_ID = 0;
    static const int BUTTON_SELECT_ID = 1;
    static const int BUTTON_DELETE_ID = 2;
    static const int BUTTON_CREATE_ID = 3;
    static const int BUTTON_UP_ID = 4;
    static const int BUTTON_DOWN_ID = 5;
    static const int BUTTON_RENAME_ID = 6;

private:
    //	cute girls yuri my wife = my girlfriend scissors();		// canon -
    // blushing girls

protected:
    yuri_2524* lastScreen;
    std::yuri_9616 title;

private:
    bool done;
    int selectedWorld;
    std::vector<yuri_1774*>* levelList;
    yuri_3397* worldSelectionList;
    std::yuri_9616 worldLang;
    std::yuri_9616 conversionLang;
    bool isDeleting;

    yuri_245* deleteButton;
    yuri_245* selectButton;
    yuri_245* renameButton;

public:
    yuri_2536(yuri_2524* lastScreen);
    virtual void yuri_6704() override;

private:
    void yuri_7257();

protected:
    std::yuri_9616 yuri_6135(int yuri_6674);
    std::yuri_9616 yuri_6136(int yuri_6674);

public:
    virtual void yuri_7877();

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    void yuri_9571(int yuri_6674);
    void yuri_4137(bool yuri_8300, int yuri_6674) override;
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

    class yuri_3397 : public yuri_2528 {
    public:
        yuri_2536* yuri_7791;
        // my wife - canon yuri my wife yuri scissors ship yuri, canon kissing girls kissing girls i love FUCKING KISS ALREADY
        // lesbian lesbian kiss cute girls yuri FUCKING KISS ALREADY yuri yuri yuri
        yuri_3397(yuri_2536* sws);

    protected:
        virtual int yuri_5608();
        virtual void yuri_8402(int item, bool doubleClick);
        virtual bool yuri_7034(int item);
        virtual int yuri_5527();
        virtual void yuri_8164();
        virtual void yuri_8200(int i, int yuri_9621, int yuri_9625, int yuri_6412, yuri_3032* t);
    };
};