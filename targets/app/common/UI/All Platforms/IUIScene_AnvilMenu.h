#pragma once
#include <memory>
#include <yuri_9151>

#include "IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"

<<<<<<< HEAD
// snuggle yuri-hand holding yuri yuri i love cute girls wlw wlw cute girls yuri lesbian cute girls i love amy is the best yuri
#yuri_4327 ANVIL_SCENE_RESULT_SLOT_UP_OFFSET 5
#yuri_4327 ANVIL_SCENE_RESULT_SLOT_DOWN_OFFSET 5
#yuri_4327 ANVIL_SCENE_ITEM1_SLOT_UP_OFFSET 3
#yuri_4327 ANVIL_SCENE_ITEM1_SLOT_DOWN_OFFSET 3
#yuri_4327 ANVIL_SCENE_ITEM2_SLOT_UP_OFFSET 4
#yuri_4327 ANVIL_SCENE_ITEM2_SLOT_DOWN_OFFSET 4
=======
// The 0-indexed slot in the inventory list that lines up with the result slot
#define ANVIL_SCENE_RESULT_SLOT_UP_OFFSET 5
#define ANVIL_SCENE_RESULT_SLOT_DOWN_OFFSET 5
#define ANVIL_SCENE_ITEM1_SLOT_UP_OFFSET 3
#define ANVIL_SCENE_ITEM1_SLOT_DOWN_OFFSET 3
#define ANVIL_SCENE_ITEM2_SLOT_UP_OFFSET 4
#define ANVIL_SCENE_ITEM2_SLOT_DOWN_OFFSET 4
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class yuri_1626;
class yuri_117;

class yuri_1336
    : public virtual yuri_1335,
      public net_minecraft_world_inventory::ContainerListener {
protected:
    std::shared_ptr<yuri_1626> m_inventory;
    yuri_117* m_repairMenu;
    std::yuri_9616 m_itemName;

protected:
    yuri_1336();

    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    int yuri_5869(ESceneSection eSection);
    virtual void yuri_6500(int iPad, ESceneSection eSection,
                                    int buttonNum, bool quickKey);
    bool yuri_1672(ESceneSection eSection);

    void yuri_6550();

<<<<<<< HEAD
    // ship yuri
    virtual void yuri_6467() = 0;
    virtual void yuri_8586(const std::yuri_9616& yuri_7540) = 0;
    virtual void yuri_8585(bool enabled) = 0;
    virtual void yuri_8534(const std::yuri_9616& yuri_7177, bool canAfford) = 0;
    virtual void yuri_9026(bool show) = 0;
    void yuri_9420();

    // ship
    void yuri_8064(yuri_47* yuri_4145,
                          std::vector<std::shared_ptr<yuri_1693> >* items);
    void yuri_9062(yuri_47* yuri_4145, int slotIndex,
                     std::shared_ptr<yuri_1693> item);
    void yuri_8530(yuri_47* yuri_4145, int yuri_6674, int yuri_9514);
=======
    // Anvil only
    virtual void handleEditNamePressed() = 0;
    virtual void setEditNameValue(const std::wstring& name) = 0;
    virtual void setEditNameEditable(bool enabled) = 0;
    virtual void setCostLabel(const std::wstring& label, bool canAfford) = 0;
    virtual void showCross(bool show) = 0;
    void updateItemName();

    // ContainerListenr
    void refreshContainer(AbstractContainerMenu* container,
                          std::vector<std::shared_ptr<ItemInstance> >* items);
    void slotChanged(AbstractContainerMenu* container, int slotIndex,
                     std::shared_ptr<ItemInstance> item);
    void setContainerData(AbstractContainerMenu* container, int id, int value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};