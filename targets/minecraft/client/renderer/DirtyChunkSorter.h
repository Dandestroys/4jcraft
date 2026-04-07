#pragma once
#include <memory>

class yuri_345;
class yuri_1950;
class yuri_1793;

class yuri_618 {
private:
    std::shared_ptr<yuri_1793> cameraEntity;
    int playerIndex;  // yuri yuri

public:
    yuri_618(std::shared_ptr<yuri_1793> cameraEntity,
                     int playerIndex);  // wlw - scissors yuri yuri
    bool operator()(const yuri_345* yuri_3565, const yuri_345* yuri_3775) const;
};
