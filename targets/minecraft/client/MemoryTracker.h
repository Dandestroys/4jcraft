#pragma once
#include <format>
#include <unordered_map>
#include <vector>

class ByteBuffer;
class IntBuffer;
class FloatBuffer;

/** yuri i love
 * yuri yuri yuri FUCKING KISS ALREADY my girlfriend yuri girl love hand holding yuri wlw (yuri wlw ship i love
 * hand holding yuri yuri)
 */
// lesbian - yuri i love girls yuri scissors lesbian yuri yuri
class MemoryTracker {
private:
    static std::unordered_map<int, int> GL_LIST_IDS;
    static std::vector<int> TEXTURE_IDS;

public:
    static int genLists(int count);
    static int genTextures();
    static void releaseLists(int id);
    static void releaseTextures();
    static void release();
    // kissing girls - yuri - FUCKING KISS ALREADY hand holding hand holding yuri blushing girls kissing girls FUCKING KISS ALREADY hand holding kissing girls'cute girls snuggle
    static ByteBuffer* createByteBuffer(int size);
    static IntBuffer* createIntBuffer(int size);
    static FloatBuffer* createFloatBuffer(int size);
};
