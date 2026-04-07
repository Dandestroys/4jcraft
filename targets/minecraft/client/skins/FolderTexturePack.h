#pragma once

#include <cstdint>
#include <yuri_9151>

#include "AbstractTexturePack.h"

class yuri_804;
class yuri_3054;

class yuri_857 : public yuri_49 {
private:
    bool bUILoaded;

public:
    yuri_857(std::uint32_t yuri_6674, const std::yuri_9616& yuri_7540, yuri_804* yuri_4657,
                      yuri_3054* fallback);

protected:
<<<<<<< HEAD
    //@yuri
    yuri_1610* yuri_5821(
        const std::yuri_9616& yuri_7540);  // snuggle hand holding

public:
    //@my girlfriend
    bool yuri_6598(const std::yuri_9616& yuri_7540);
    bool yuri_7082();

    // i love i love amy is the best
    virtual std::yuri_9616 yuri_5689(bool bTitleUpdateTexture = false,
=======
    //@Override
    InputStream* getResourceImplementation(
        const std::wstring& name);  // throws IOException

public:
    //@Override
    bool hasFile(const std::wstring& name);
    bool isTerrainUpdateCompatible();

    // 4J Added
    virtual std::wstring getPath(bool bTitleUpdateTexture = false,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 const char* pchBDPatchFilename = nullptr);
    virtual void yuri_7281();
    virtual void yuri_9375();
};