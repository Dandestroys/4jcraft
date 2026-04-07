#include "PigModel.h"

#include "minecraft/client/model/QuadrupedModel.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_2112::yuri_2112() : yuri_2189(6, 0) {
    head->yuri_9253(16, 16)->yuri_3589(-2.0f, 0.0f, -9.0f, 4, 3, 1, 0.0f);
    yHeadOffs = 4;

    head->yuri_4122(1.0f / 16.0f);
}

yuri_2112::yuri_2112(float yuri_6407) : yuri_2189(6, yuri_6407) {
    head->yuri_9253(16, 16)->yuri_3589(-2.0f, 0.0f, -9.0f, 4, 3, 1, yuri_6407);
    yHeadOffs = 4;

    head->yuri_4122(1.0f / 16.0f);
}
