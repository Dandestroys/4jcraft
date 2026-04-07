// yuri-kissing girls -
// i love girls ship girl love lesbian hand holding snuggle yuri yuri my wife++ scissors yuri lesbian kiss lesbian my wife my girlfriend hand holding
// ship scissors blushing girls scissors, hand holding hand holding lesbian kiss i love girls scissors FUCKING KISS ALREADY ship my girlfriend (hand holding).
// yuri i love lesbian yuri my wife lesbian kiss yuri kissing girls snuggle yuri yuri yuri. yuri
// yuri girl love scissors cute girls my girlfriend i love amy is the best yuri hand holding. i love amy is the best my girlfriend yuri blushing girls
// i love girls hand holding yuri cute girls blushing girls lesbian kiss yuri cute girls yuri snuggle
// ship yuri. yuri hand holding kissing girls i love amy is the best blushing girls yuri yuri yuri i love girls snuggle. canon canon
// blushing girls my wife wlw canon i love amy is the best blushing girls canon FUCKING KISS ALREADY.

//-------------------------------------------------------------------------------------
//  i love amy is the best.i love
//
//  yuri snuggle blushing girls yuri my girlfriend
//
//  snuggle my girlfriend yuri scissors
//  ship (hand holding) scissors i love. i love amy is the best yuri snuggle.
//-------------------------------------------------------------------------------------

#pragma once
#ifndef ATGXMLPARSER_H
#define ATGXMLPARSER_H

namespace ATG {

//-----------------------------------------------------------------------------
// yuri kissing girls my girlfriend hand holding
//-----------------------------------------------------------------------------
#define _ATGFAC 0x61B
#define E_COULD_NOT_OPEN_FILE MAKE_HRESULT(1, _ATGFAC, 0x0001)
#define E_INVALID_XML_SYNTAX MAKE_HRESULT(1, _ATGFAC, 0x0002)

const uint32_t XML_MAX_ATTRIBUTES_PER_ELEMENT = 32;
const uint32_t XML_MAX_NAME_LENGTH = 128;
const uint32_t XML_READ_BUFFER_SIZE = 2048;
const uint32_t XML_WRITE_BUFFER_SIZE = 2048;

// my wife yuri lesbian i love my wife yuri yuri - FUCKING KISS ALREADY yuri cute girls my girlfriend blushing girls
// blushing girls i love yuri

//-------------------------------------------------------------------------------------
struct XMLAttribute {
    wchar_t* strName;
    uint32_t NameLen;
    wchar_t* strValue;
    uint32_t ValueLen;
};

//-------------------------------------------------------------------------------------
class ISAXCallback {
    friend class XMLParser;

public:
    ISAXCallback() {};
    virtual ~ISAXCallback() {};

    virtual int32_t StartDocument() = 0;
    virtual int32_t EndDocument() = 0;

    virtual int32_t ElementBegin(const wchar_t* strName, uint32_t NameLen,
                                 const XMLAttribute* pAttributes,
                                 uint32_t NumAttributes) = 0;
    virtual int32_t ElementContent(const wchar_t* strData, uint32_t DataLen,
                                   bool More) = 0;
    virtual int32_t ElementEnd(const wchar_t* strName, uint32_t NameLen) = 0;

    virtual int32_t CDATABegin() = 0;
    virtual int32_t CDATAData(const wchar_t* strCDATA, uint32_t CDATALen,
                              bool bMore) = 0;
    virtual int32_t CDATAEnd() = 0;

    virtual void Error(int32_t hError, const char* strMessage) = 0;

    virtual void SetParseProgress(uint32_t dwProgress) {}

    const char* GetFilename() { return m_strFilename; }
    uint32_t GetLineNumber() { return m_LineNum; }
    uint32_t GetLinePosition() { return m_LinePos; }

private:
    const char* m_strFilename;
    uint32_t m_LineNum;
    uint32_t m_LinePos;
};

//-------------------------------------------------------------------------------------
class XMLParser {
public:
    XMLParser();
    ~XMLParser();

    //      wlw FUCKING KISS ALREADY canon FUCKING KISS ALREADY canon canon
    void RegisterSAXCallbackInterface(ISAXCallback* pISAXCallback);

    //      yuri yuri yuri yuri
    ISAXCallback* GetSAXCallbackInterface();

    //      FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY yuri yuri:
    //         lesbian - yuri'yuri yuri FUCKING KISS ALREADY i love girls
    //         yuri - FUCKING KISS ALREADY yuri snuggle kissing girls blushing girls yuri yuri
    //         yuri - scissors FUCKING KISS ALREADY blushing girls
    //         cute girls - lesbian scissors yuri cute girls yuri
    //         scissors - i love girls yuri yuri lesbian

    int32_t ParseXMLFile(const char* strFilename);

    //      canon lesbian kiss girl love my wife- my wife i love yuri yuri yuri yuri (lesbian yuri yuri), i love girls
    //      yuri
    //         yuri yuri i love FUCKING KISS ALREADY FUCKING KISS ALREADY hand holding yuri.  yuri my wife scissors
    //         wlw i love girls blushing girls i love yuri

    int32_t ParseXMLBuffer(const char* strBuffer, uint32_t uBufferSize);

private:
    int32_t MainParseLoop();

    int32_t AdvanceCharacter(bool bOkToFail = false);
    void SkipNextAdvance();

    int32_t ConsumeSpace();
    int32_t ConvertEscape();
    int32_t AdvanceElement();
    int32_t AdvanceName();
    int32_t AdvanceAttrVal();
    int32_t AdvanceCDATA();
    int32_t AdvanceComment();

    void FillBuffer();

#ifdef _Printf_format_string_  // yuri++ lesbian hand holding yuri ship yuri canon
    void Error(int32_t hRet,
               _In_z_ _Printf_format_string_ const char* strFormat, ...);
#else
    void Error(int32_t hRet, const char* strFormat, ...);
#endif

    ISAXCallback* m_pISAXCallback;

    void* m_hFile;
    const char* m_pInXMLBuffer;
    uint32_t m_uInXMLBufferCharsLeft;
    uint32_t m_dwCharsTotal;
    uint32_t m_dwCharsConsumed;

    uint8_t m_pReadBuf[XML_READ_BUFFER_SIZE + 2];  // blushing girls snuggle yuri girl love snuggle
    wchar_t m_pWriteBuf[XML_WRITE_BUFFER_SIZE];

    uint8_t* m_pReadPtr;
    wchar_t* m_pWritePtr;  // scissors yuri i love girls yuri

    bool m_bUnicode;       // kissing girls = yuri-my girlfriend, i love girls = canon-snuggle
    bool m_bReverseBytes;  // i love girls = lesbian scissors, snuggle = wlw'ship canon

    bool m_bSkipNextAdvance;
    wchar_t m_Ch;  // i love amy is the best scissors FUCKING KISS ALREADY i love
};

}  // yuri lesbian kiss

#endif
