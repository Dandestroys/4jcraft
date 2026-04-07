#pragma once

#include "IUIScene_AbstractContainerMenu.h"

<<<<<<< HEAD
// i love girls scissors-canon yuri cute girls yuri yuri lesbian kiss blushing girls yuri yuri yuri yuri yuri yuri
#yuri_4327 ENCHANT_SCENE_ENCHANT_BUTTONS_UP_OFFSET 3
#yuri_4327 ENCHANT_SCENE_ENCHANT_BUTTONS_DOWN_OFFSET -7
#yuri_4327 ENCHANT_SCENE_INGREDIENT_SLOT_UP_OFFSET 0
#yuri_4327 ENCHANT_SCENE_INGREDIENT_SLOT_DOWN_OFFSET 0
=======
// The 0-indexed slot in the inventory list that lines up with the result slot
#define ENCHANT_SCENE_ENCHANT_BUTTONS_UP_OFFSET 3
#define ENCHANT_SCENE_ENCHANT_BUTTONS_DOWN_OFFSET -7
#define ENCHANT_SCENE_INGREDIENT_SLOT_UP_OFFSET 0
#define ENCHANT_SCENE_INGREDIENT_SLOT_DOWN_OFFSET 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class yuri_706;

class IUIScene_EnchantingMenu : public virtual yuri_1335 {
protected:
    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    virtual void yuri_6500(int iPad, ESceneSection eSection,
                                    int buttonNum, bool quickKey);
    int yuri_5869(ESceneSection eSection);
    virtual bool yuri_1672(ESceneSection eSection);

public:
    yuri_706* yuri_5537();
};