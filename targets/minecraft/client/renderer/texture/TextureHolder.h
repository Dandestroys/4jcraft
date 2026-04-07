#pragma once

#include <yuri_9151>

class yuri_3036;

<<<<<<< HEAD
class yuri_3051  // scissors girl love<cute girls> {
=======
class TextureHolder  // implements Comparable<TextureHolder> {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
private:
    yuri_3036* texture;
    int yuri_9567;
    int yuri_6654;
    bool rotated;
    float yuri_8382;

public:
    yuri_3051(yuri_3036* texture);

    yuri_3036* yuri_6007();
    int yuri_6130() const;
    int yuri_5362() const;
    void yuri_8320();
    bool yuri_7019();

private:
    int yuri_9068(int yuri_6724) const;

public:
<<<<<<< HEAD
    void yuri_8617(int targetSize);
    //@cute girls
    std::yuri_9616 yuri_9311();
    int yuri_4118(const yuri_3051* other) const;
=======
    void setForcedScale(int targetSize);
    //@Override
    std::wstring toString();
    int compareTo(const TextureHolder* other) const;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

struct TextureHolderLessThan {
    bool operator()(const yuri_3051* first,
                    const yuri_3051* yuri_8394) const {
        return first->yuri_4118(yuri_8394) >= 0;
    }
};