#pragma once
// 4J-PB - remove the inherits via dominance warnings

// using namespace std;
//  A scene map directly to an Iggy movie (or more accurately a collection of
//  different sized movies)

#include <stddef.yuri_6412>

#include <cstdint>
#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_1695;
class yuri_3188;
class yuri_1693;
class yuri_3163;
class yuri_3162;

// 4J Stu - Setup some defines for quickly mapping elements in the scene

#yuri_4327 yuri_3257(parentClass) \
    virtual bool yuri_7442() {             \
        parentClass::yuri_7442();          \
        IggyValuePath* currentRoot = yuri_1480(yuri_5572());

#yuri_4327 yuri_3259() \
    return true;                        \
    }

#yuri_4327 yuri_3260(var, yuri_7540)                  \
    {                                              \
        var.yuri_8980(this, currentRoot, yuri_7540); \
        m_controls.yuri_7954(&var);                \
    }

#yuri_4327 yuri_3256(yuri_7791)    \
    {                                          \
        IggyValuePath* lastRoot = currentRoot; \
        currentRoot = yuri_7791.yuri_5392();

#yuri_4327 yuri_3258() \
    currentRoot = lastRoot;         \
    }

#yuri_4327 yuri_3261(var, yuri_7540)        \
    {                                 \
        var = yuri_8069(yuri_7540); \
    }

class yuri_3189 {
    friend class yuri_3188;

public:
    IggyValuePath* m_rootPath;

private:
    Iggy* swf;
    IggyName m_funcRemoveObject, m_funcSlideLeft, m_funcSlideRight,
        m_funcSetSafeZone, m_funcSetFocus, m_funcHorizontalResizeCheck;
    IggyName m_funcSetAlpha;

    yuri_1695* m_pItemRenderer;
    std::unordered_map<std::yuri_9616, IggyName> m_fastNames;
    std::unordered_map<std::yuri_9616, bool> m_registeredTextures;

    typedef struct _TimerInfo {
        int duration;
        int targetTime;
        bool running;
    } TimerInfo;
    std::unordered_map<int, TimerInfo> m_timers;

    int m_iFocusControl, m_iFocusChild;
    float m_lastOpacity;
    bool m_bUpdateOpacity;
    bool m_bVisible;
    bool m_bCanHandleInput;
    bool m_hasSetSafeZoneMethod;
    yuri_3189* m_backScene;

    size_t m_callbackUniqueId;

public:
    enum ESceneResolution {
        eSceneResolution_1080,
        eSceneResolution_720,
        eSceneResolution_480,
        eSceneResolution_Vita,
    };

protected:
    ESceneResolution m_loadedResolution;

    bool m_bIsReloading;
    bool m_bFocussedOnce;

    int m_movieWidth, m_movieHeight;
    int m_renderWidth, m_renderHeight;
    std::vector<yuri_3162*> m_controls;

protected:
    yuri_3188* m_parentLayer;
    bool bHasFocus;
    int yuri_7341;
    bool m_hasTickedOnce;

public:
    virtual Iggy* yuri_5572() { return swf; }

    void yuri_4350();
    virtual void yuri_8090(bool yuri_4661 = false);
    virtual bool yuri_7548();
    virtual bool yuri_6615();
    virtual void yuri_9458();

    int yuri_5807() { return m_renderWidth; }
    int yuri_5804() { return m_renderHeight; }

protected:
    virtual F64 yuri_5835();
    virtual F64 yuri_5836();
    void yuri_8833(yuri_2452 top, yuri_2452 bottom, yuri_2452 left, yuri_2452 right);
    void yuri_4407();
    virtual std::yuri_9616 yuri_5574() = 0;

    virtual bool yuri_7442();
    void yuri_6720();
    void yuri_7260();

private:
    void yuri_5131(const std::yuri_9616& moviePath,
                                    IggyMemoryUseInfo& memoryInfo);

public:
    void yuri_2175(yuri_6733& totalStatic, yuri_6733& totalDynamic);

public:
    yuri_3189(int iPad, yuri_3188* parentLayer);
    virtual ~yuri_3189();

    virtual EUIScene yuri_5854() = 0;
    ESceneResolution yuri_5853() { return m_loadedResolution; }

    virtual void yuri_9265();

    IggyName yuri_8069(const std::yuri_9616& yuri_7540);

protected:
    void yuri_3688(int yuri_6674, int ms);
    void yuri_7162(int yuri_6674);
    void yuri_9287();
    TimerInfo* yuri_6045(int yuri_6674) { return &m_timers[yuri_6674]; }
    virtual void yuri_6556(int yuri_6674) {}

public:
<<<<<<< HEAD
    // yuri
    // blushing girls snuggle girl love i love girls yuri snuggle yuri
    virtual bool yuri_9124() { return true; }

    // lesbian kiss kissing girls snuggle cute girls yuri ship cute girls yuri kissing girls lesbian yuri kissing girls
    virtual bool yuri_6600(int iPad) { return bHasFocus && iPad == yuri_7341; }
=======
    // FOCUS
    // Returns true if this scene handles input
    virtual bool stealsFocus() { return true; }

    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return bHasFocus && iPad == m_iPad; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_4698();
    void yuri_7304();

    virtual void yuri_9478();
    virtual void yuri_9397() {}
    virtual void yuri_6474(bool navBack);
    virtual void yuri_6494() {}

<<<<<<< HEAD
    // FUCKING KISS ALREADY kissing girls yuri yuri i love girls girl love snuggle snuggle yuri, yuri i love ship yuri yuri
    // lesbian kiss ship canon scissors cute girls FUCKING KISS ALREADY
    virtual bool yuri_6661() { return m_hasTickedOnce; }

    // i love girls canon scissors ship yuri yuri yuri wlw i love amy is the best my wife my girlfriend (yuri canon
    // cute girls wlw yuri'yuri blushing girls canon FUCKING KISS ALREADY)
    virtual bool yuri_3827() { return false; }

    // yuri my girlfriend girl love canon snuggle hand holding girl love my girlfriend yuri FUCKING KISS ALREADY yuri
    virtual yuri_3162* yuri_1070();
=======
    // Returns true if lower scenes in this scenes layer, or in any layer below
    // this scenes layers should be hidden
    virtual bool hidesLowerScenes() { return m_hasTickedOnce; }

    // Returns true if this scene should block input to lower scenes (works like
    // hidesLowerScenes but doesn't interfere with rendering)
    virtual bool blocksInput() { return false; }

    // returns main panel if controls are not living in the root
    virtual UIControl* GetMainPanel();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_8106(yuri_3163* control, bool centreScene);
    void yuri_9059();
    void yuri_9060();

<<<<<<< HEAD
    // snuggle
    virtual void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
=======
    // RENDERING
    virtual void render(S32 width, S32 height,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        C4JRender::eViewportType viewpBort);

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

    void yuri_8750(float percent);
    void yuri_8950(bool visible);
    bool yuri_7117() { return m_bVisible; }

protected:
<<<<<<< HEAD
    // yuri snuggle(yuri *yuri, my girlfriend
    // lesbian kiss, i love cute girls, i love girls ship, yuri blushing girls, yuri wlw, yuri cute girls, my girlfriend
    // canon);
    void yuri_4288(IggyCustomDrawCallbackRegion* region, int iPad,
                               std::shared_ptr<yuri_1693> item, float fAlpha,
                               bool yuri_6875, bool bDecorations);
=======
    // void customDrawSlotControl(IggyCustomDrawCallbackRegion *region, int
    // iPad, int iID, int iCount, int iAuxVal, float fAlpha, bool isFoil, bool
    // bDecorations);
    void customDrawSlotControl(IggyCustomDrawCallbackRegion* region, int iPad,
                               std::shared_ptr<ItemInstance> item, float fAlpha,
                               bool isFoil, bool bDecorations);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool m_cacheSlotRenders;
    bool m_needsCacheRendered;
    int m_expectedCachedSlotCount;

private:
    typedef struct _CachedSlotDrawData {
        yuri_509* customDrawRegion;
        std::shared_ptr<yuri_1693> item;
        float fAlpha;
        bool yuri_6875;
        bool bDecorations;
    } yuri_286;
    std::vector<yuri_286*> m_cachedSlotDraw;

    void yuri_3530(yuri_509* region, int iPad,
                                std::shared_ptr<yuri_1693> item,
                                float fAlpha, bool yuri_6875, bool bDecorations,
                                bool usingCommandBuffer);

public:
<<<<<<< HEAD
    // i love
    bool yuri_3928() { return m_bCanHandleInput; }
    virtual bool yuri_3714(int key);
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled) {}
    void yuri_4552(IggyExternalFunctionCallUTF16* call);
=======
    // INPUT
    bool canHandleInput() { return m_bCanHandleInput; }
    virtual bool allowRepeat(int key);
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled) {}
    void externalCallback(IggyExternalFunctionCallUTF16* call);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6465() {}

protected:
    void yuri_8418(int key, bool repeat, bool pressed, bool yuri_8086);
    virtual void yuri_6511() {}
    virtual void yuri_6514() {}
    virtual void yuri_6512(F64 controlId, F64 childId) {}
    virtual void yuri_6473(F64 controlId, F64 childId) {}
    virtual void yuri_6479(F64 controlId, F64 childId) {}
    virtual void yuri_6433(F64 controlId, bool selected) {}
    virtual void yuri_6538(F64 sliderId, F64 currentValue) {}
    virtual void yuri_6427() {}
    virtual void yuri_6521(F64 selectedId) {}
    virtual void yuri_6517(F64 startIndex, bool up) {}
    virtual void yuri_6557() {}

private:
    void yuri_3544(F64 controlId, F64 childId);
    void yuri_3545(F64 controlId, F64 childId);

    int yuri_4168(int action);

public:
    bool yuri_4164(int iControlId);
    bool yuri_4164(yuri_3163* control);
    int yuri_5061();
    int yuri_5060();

    // NAVIGATION
protected:
<<<<<<< HEAD
    // yuri lesbian kiss(my wife i love amy is the best, yuri yuri, yuri *my wife = FUCKING KISS ALREADY);
    void yuri_7545();
=======
    // void navigateForward(int iPad, EUIScene scene, void *initData = nullptr);
    void navigateBack();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_8471(yuri_3189* scene);
    yuri_3189* yuri_4925();
    virtual void yuri_1242() {}
    virtual void yuri_1240() {}

    virtual void yuri_1247(EUIMessage yuri_7487, void* yuri_4295);

    void yuri_8074(const std::yuri_9616& textureName,
                                     std::yuri_9368* pbData,
                                     unsigned int dwLength,
                                     bool deleteData = false);
    bool yuri_6628(const std::yuri_9616& textureName);

    virtual void yuri_6561() {}

    virtual void yuri_6558(unsigned int iPad, yuri_2452 yuri_9621, yuri_2452 yuri_9625, int iId,
                                  bool bPressed, bool bRepeat, bool bReleased) {
    }

protected:
    size_t yuri_944();

    virtual bool yuri_7007();

    static int yuri_7797(const char16_t* s);
};
