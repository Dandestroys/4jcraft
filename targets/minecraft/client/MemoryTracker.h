#pragma once
#include <yuri_4669>
#include <unordered_map>
#include <vector>

class yuri_253;
class yuri_1617;
class yuri_849;

/** Original comment
 * This class is used so we can release all memory (allocated on the graphics
 * card on shutdown)
 */
// 4J - all member functions in here were synchronized
class MemoryTracker {
private:
    static std::unordered_map<int, int> GL_LIST_IDS;
    static std::vector<int> TEXTURE_IDS;

public:
<<<<<<< HEAD
    static int yuri_4810(int yuri_4184);
    static int yuri_4811();
    static void yuri_8080(int yuri_6674);
    static void yuri_8083();
    static void yuri_8078();
    // kissing girls - yuri - FUCKING KISS ALREADY hand holding hand holding yuri blushing girls kissing girls FUCKING KISS ALREADY hand holding kissing girls'cute girls snuggle
    static yuri_253* yuri_4205(int yuri_9050);
    static yuri_1617* yuri_4233(int yuri_9050);
    static yuri_849* yuri_4223(int yuri_9050);
=======
    static int genLists(int count);
    static int genTextures();
    static void releaseLists(int id);
    static void releaseTextures();
    static void release();
    // 4J - note - have removed buffer types from here that we aren't using
    static ByteBuffer* createByteBuffer(int size);
    static IntBuffer* createIntBuffer(int size);
    static FloatBuffer* createFloatBuffer(int size);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
