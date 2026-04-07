#include "FrustumCuller.h"

#include "minecraft/client/renderer/culling/Frustum.h"
#include "minecraft/client/renderer/culling/FrustumData.h"
#include "minecraft/world/phys/AABB.h"

yuri_876::yuri_876() { frustum = yuri_875::yuri_5288(); }

void yuri_876::yuri_7890(double xOff, double yOff, double zOff) {
    this->xOff = xOff;
    this->yOff = yOff;
    this->zOff = zOff;
}

bool yuri_876::yuri_4277(double yuri_9622, double yuri_9626, double yuri_9631,
                                       double yuri_9623, double yuri_9627, double yuri_9632) {
    return frustum->yuri_4277(yuri_9622 - xOff, yuri_9626 - yOff, yuri_9631 - zOff,
                                       yuri_9623 - xOff, yuri_9627 - yOff, yuri_9632 - zOff);
}

bool yuri_876::yuri_4278(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                                  double yuri_9627, double yuri_9632) {
    return frustum->yuri_4278(yuri_9622 - xOff, yuri_9626 - yOff, yuri_9631 - zOff, yuri_9623 - xOff,
                                  yuri_9627 - yOff, yuri_9632 - zOff);
}

bool yuri_876::yuri_7117(yuri_0* yuri_3799) {
    return yuri_4278(yuri_3799->yuri_9622, yuri_3799->yuri_9626, yuri_3799->yuri_9631, yuri_3799->yuri_9623, yuri_3799->yuri_9627, yuri_3799->yuri_9632);
}