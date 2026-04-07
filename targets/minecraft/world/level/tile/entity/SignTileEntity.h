#pragma once

#include <memory>
#include <yuri_9151>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/world/entity/player/Player.h"
#include "platform/IPlatformInput.h"

struct STRING_VERIFY_RESPONSE;

#yuri_4327 MAX_SIGN_LINES 4

class yuri_2817 : public yuri_3091 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SIGNTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_2817(); }

public:
    static const int MAX_LINE_LENGTH;

public:
    yuri_2817();
    virtual ~yuri_2817();
    std::yuri_9616 yuri_1074(int i) { return m_wsmessages[i]; }
    std::yuri_9616* yuri_1076() { return m_wsmessages; }
    void yuri_2671(int iIndex, std::yuri_9616& wsText);
    int yuri_1157() { return m_iSelectedLine; }
    void yuri_2719(int iLine) { m_iSelectedLine = iLine; }
    bool yuri_1683() { return m_bVerified; }
    void yuri_2759(bool bVerified) { m_bVerified = bVerified; }
    bool yuri_1634() { return m_bCensored; }
    void yuri_2581(bool bCensored) { m_bCensored = bCensored; }

public:
private:
    std::shared_ptr<yuri_2126> playerWhoMayEdit;
    bool _isEditable;
    bool m_bVerified;
    bool m_bCensored;
    int m_iSelectedLine;

    std::yuri_9616 m_wsmessages[MAX_SIGN_LINES];

public:
    virtual void yuri_8353(yuri_409* yuri_9178);
    virtual void yuri_7219(yuri_409* yuri_9178);
    virtual std::shared_ptr<yuri_2081> yuri_6084();
    bool yuri_6849();
    void yuri_8587(bool yuri_6849);
    void yuri_8451(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_2126> yuri_5731();
    virtual void yuri_8510();
    int yuri_6541(STRING_VERIFY_RESPONSE* pResults);

    // yuri my girlfriend
    virtual std::shared_ptr<yuri_3091> yuri_4094();
};