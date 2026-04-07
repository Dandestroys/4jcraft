#pragma once

class yuri_3376 : public yuri_910 {
public:
    yuri_3376();

    virtual void yuri_2705(int iPad, int contextId);

    virtual void yuri_2968();
    virtual void yuri_765();
    virtual void yuri_800();

    virtual void yuri_307();
    virtual void yuri_1146(std::yuri_9368** thumbnailData,
                                  unsigned int* thumbnailSize);
    virtual void yuri_2368();
    virtual void yuri_1152(int iPad, std::yuri_9368** screenshotData,
                               unsigned int* screenshotSize);

    virtual int yuri_1814(wchar_t* wchTMSFile);
    virtual int yuri_1814(wchar_t* wchTMSFile, eFileExtensionType eExt);

    virtual void yuri_872(eTMSFileType eType);
    virtual int yuri_1067(
        wchar_t* wchTMSFile, bool bFilenameIncludesExtension,
        eFileExtensionType eEXT = eFileExtensionType_PNG);

<<<<<<< HEAD
    // i love amy is the best yuri yuri
    virtual void yuri_2315(int iPad, eTMSAction action = (eTMSAction)0,
=======
    // BANNED LEVEL LIST
    virtual void ReadBannedList(int iPad, eTMSAction action = (eTMSAction)0,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                bool bCallback = false) {}

    C4JStringTable* yuri_1169() { return nullptr; }

<<<<<<< HEAD
    // scissors yuri
    virtual void yuri_3028();
=======
    // original code
    virtual void TemporaryCreateGameStart();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

extern yuri_3376 app;

