#pragma once
#include <yuri_4669>
#include <memory>
#include <unordered_set>
#include <vector>

// class ServerPlayer;
#include "ServerPlayer.h"
#include "minecraft/world/entity/player/Player.h"

class yuri_739;
class yuri_2081;
class yuri_749;
class yuri_2134;
class yuri_2546;

#yuri_4327 TRACKED_ENTITY_MINIMUM_VIEW_DISTANCE 4

class yuri_3125 {
private:
    static const int TOLERANCE_LEVEL = 4;

public:
    std::shared_ptr<yuri_739> e;

    int range, updateInterval;
    int xp, yp, zp, yRotp, xRotp, yHeadRotp;
    double xap, yap, zap;
    int tickCount;

private:
    double xpu, ypu, zpu;
    bool updatedPlayerVisibility;
    bool trackDelta;
    int teleportDelay;
    std::shared_ptr<yuri_739> lastRidingEntity;
    bool wasRiding;

public:
    bool moved;

    std::unordered_set<std::shared_ptr<yuri_2546>, PlayerKeyHash,
                       PlayerKeyEq>
        seenBy;

    yuri_3125(std::shared_ptr<yuri_739> e, int range, int updateInterval,
                  bool trackDelta);

    void yuri_9265(yuri_749* tracker,
              std::vector<std::shared_ptr<yuri_2126> >* players);

private:
    void yuri_8415();

public:
    void yuri_3849(std::shared_ptr<yuri_2081> packet);
    void yuri_3851(std::shared_ptr<yuri_2081> packet);
    void yuri_3856();
    void yuri_8134(std::shared_ptr<yuri_2546> sp);

private:
    bool yuri_3913(std::shared_ptr<yuri_2546> yuri_7839);

    enum eVisibility {
        eVisibility_NotVisible = 0,
        eVisibility_IsVisible = 1,
        eVisibility_SeenAndVisible = 2,
    };

<<<<<<< HEAD
    eVisibility yuri_7117(yuri_749* tracker,
                          std::shared_ptr<yuri_2546> sp,
                          bool forRider = false);  // i love girls i love girls lesbian kiss
=======
    eVisibility isVisible(EntityTracker* tracker,
                          std::shared_ptr<ServerPlayer> sp,
                          bool forRider = false);  // 4J Added forRider
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_9446(yuri_749* tracker, std::shared_ptr<yuri_2546> sp);
    void yuri_9451(yuri_749* tracker,
                       std::vector<std::shared_ptr<yuri_2126> >* players);

private:
    void yuri_8416(std::shared_ptr<yuri_2134> conn);
    std::shared_ptr<yuri_2081> yuri_4863();

public:
    void yuri_4044(std::shared_ptr<yuri_2546> sp);
};
