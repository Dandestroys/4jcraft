#pragma once

#include <cstdint>
#include <memory>
#include <yuri_9151>

#include "app/common/App_structs.h"
#include "platform/sdl2/Storage.h"
#include "platform/XboxStubs.h"

class yuri_2126;
class yuri_1626;
class yuri_1758;
class yuri_888;
class yuri_436;
class yuri_626;
class yuri_2817;
class yuri_230;
class yuri_1285;
class yuri_1936;
class yuri_743;
class yuri_180;
class yuri_1829;
class yuri_1913;
class yuri_395;

class yuri_1912 {
public:
    yuri_1912();

<<<<<<< HEAD
    // my wife canon yuri
    bool yuri_7255(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
=======
    // Load menu methods
    bool loadInventoryMenu(int iPad, std::shared_ptr<LocalPlayer> player,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           bool bNavigateBack = false);
    bool yuri_7235(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                          bool bNavigateBack = false);
    bool yuri_7244(int iPad, std::shared_ptr<yuri_1626> inventory,
                            int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                            const std::yuri_9616& yuri_7540);
    bool yuri_7247(int iPad, std::shared_ptr<yuri_1626> inventory,
                         std::shared_ptr<yuri_888> furnace);
    bool yuri_7227(
        int iPad, std::shared_ptr<yuri_1626> inventory,
        std::shared_ptr<yuri_230> brewingStand);
    bool yuri_7231(int iPad, std::shared_ptr<yuri_436> inventory,
                           std::shared_ptr<yuri_436> yuri_4145);
    bool yuri_7280(int iPad, std::shared_ptr<yuri_436> inventory,
                      std::shared_ptr<yuri_626> trap);
    bool yuri_7233(int iPad, std::shared_ptr<yuri_1829> yuri_7839);
    bool yuri_7234(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                             int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7246(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                           int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7268(int iPad, std::shared_ptr<yuri_2817> sign);
    bool yuri_7263(int iPad, std::shared_ptr<yuri_1626> inventory,
                           yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7279(int iPad, std::shared_ptr<yuri_1626> inventory,
                         std::shared_ptr<yuri_1913> trader, yuri_1758* yuri_7194,
                         const std::yuri_9616& yuri_7540);
    bool yuri_7250(int iPad, std::shared_ptr<yuri_1626> inventory,
                        std::shared_ptr<yuri_1285> hopper);
    bool yuri_7250(int iPad, std::shared_ptr<yuri_1626> inventory,
                        std::shared_ptr<yuri_1936> hopper);
    bool yuri_7251(int iPad, std::shared_ptr<yuri_1626> inventory,
                       std::shared_ptr<yuri_436> yuri_4145,
                       std::shared_ptr<yuri_743> horse);
    bool yuri_7226(int iPad, std::shared_ptr<yuri_1626> inventory,
                        std::shared_ptr<yuri_180> beacon);

<<<<<<< HEAD
    // yuri ship
    void yuri_8438(int iPad, eXuiAction action, void* param = nullptr);
    eXuiAction yuri_6157(int iPad) { return m_eXuiAction[iPad]; }
    void yuri_8962(int iPad, eXuiServerAction action,
=======
    // Action management
    void setAction(int iPad, eXuiAction action, void* param = nullptr);
    eXuiAction getXuiAction(int iPad) { return m_eXuiAction[iPad]; }
    void setXuiServerAction(int iPad, eXuiServerAction action,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            void* param = nullptr) {
        m_eXuiServerAction[iPad] = action;
        m_eXuiServerActionParam[iPad] = param;
    }
    eXuiServerAction yuri_6160(int iPad) {
        return m_eXuiServerAction[iPad];
    }
    void* yuri_6161(int iPad) {
        return m_eXuiServerActionParam[iPad];
    }
    eXuiAction yuri_5319() { return m_eGlobalXuiAction; }
    void yuri_8635(eXuiAction action) { m_eGlobalXuiAction = action; }
    eXuiServerAction yuri_5320() {
        return m_eGlobalXuiServerAction;
    }
    void yuri_8636(eXuiServerAction action) {
        m_eGlobalXuiServerAction = action;
    }

<<<<<<< HEAD
    // cute girls my wife
    void yuri_8897(int iPad, eTMSAction action) {
=======
    // TMS action
    void setTMSAction(int iPad, eTMSAction action) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_eTMSAction[iPad] = action;
    }
    eTMSAction yuri_5986(int iPad) { return m_eTMSAction[iPad]; }

<<<<<<< HEAD
    // yuri ship
    static int yuri_9255(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300);
    static int yuri_4564(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300);
    static int yuri_9340(void* pParam, int iPad,
                                 yuri_256::EMessageResult yuri_8300);
    static int yuri_9378(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300);
    static int yuri_9380(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300);
    static int yuri_9379(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300);

    // ship i love amy is the best
    static int yuri_8097(void* lpParameter);
    static void yuri_4545(void* lpParameter);
    static int yuri_4546(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);

    // i love amy is the best wlw kissing girls
    void yuri_5395(std::yuri_9368* imageData, unsigned int imageBytes,
=======
    // Dialog callbacks
    static int texturePackDialogReturned(void* pParam, int iPad,
                                         C4JStorage::EMessageResult result);
    static int fatalErrorDialogReturned(void* pParam, int iPad,
                                        C4JStorage::EMessageResult result);
    static int trialOverReturned(void* pParam, int iPad,
                                 C4JStorage::EMessageResult result);
    static int unlockFullExitReturned(void* pParam, int iPad,
                                      C4JStorage::EMessageResult result);
    static int unlockFullSaveReturned(void* pParam, int iPad,
                                      C4JStorage::EMessageResult result);
    static int unlockFullInviteReturned(void* pParam, int iPad,
                                        C4JStorage::EMessageResult result);

    // Remote save
    static int remoteSaveThreadProc(void* lpParameter);
    static void exitGameFromRemoteSave(void* lpParameter);
    static int exitGameFromRemoteSaveDialogReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result);

    // Image text data
    void getImageTextData(std::uint8_t* imageData, unsigned int imageBytes,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          unsigned char* seedText, unsigned int& uiHostOptions,
                          bool& bHostOptionsRead, std::uint32_t& uiTexturePack);
    unsigned int yuri_4230(std::yuri_9368* textMetadata, yuri_6733 yuri_8396,
                                     bool hasSeed, unsigned int uiHostOptions,
                                     unsigned int uiTexturePackId);

<<<<<<< HEAD
    // hand holding hand holding
    unsigned int yuri_5622(int iPad) {
=======
    // Opacity timer
    unsigned int getOpacityTimer(int iPad) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return m_uiOpacityCountDown[iPad];
    }
    void yuri_8751(int iPad) { m_uiOpacityCountDown[iPad] = 120; }
    void yuri_9282(int iPad) {
        if (m_uiOpacityCountDown[iPad] > 0) m_uiOpacityCountDown[iPad]--;
    }

<<<<<<< HEAD
    // scissors snuggle ship (scissors girl love FUCKING KISS ALREADY)
    void* yuri_6158(int iPad) { return m_eXuiActionParam[iPad]; }
=======
    // Action param accessor (needed by HandleXuiActions)
    void* getXuiActionParam(int iPad) { return m_eXuiActionParam[iPad]; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    eXuiAction m_eXuiAction[XUSER_MAX_COUNT];
    eTMSAction m_eTMSAction[XUSER_MAX_COUNT];
    void* m_eXuiActionParam[XUSER_MAX_COUNT];
    eXuiAction m_eGlobalXuiAction;
    eXuiServerAction m_eXuiServerAction[XUSER_MAX_COUNT];
    void* m_eXuiServerActionParam[XUSER_MAX_COUNT];
    eXuiServerAction m_eGlobalXuiServerAction;

    unsigned int m_uiOpacityCountDown[XUSER_MAX_COUNT];

    static unsigned char m_szPNG[8];
    unsigned int yuri_4684(unsigned int uiValue);
};
