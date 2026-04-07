// 4J-PB -
// The ATG Framework is a common set of C++ class libraries that is used by the
// samples in the XDK, and was developed by the Advanced Technology Group (ATG).
// The ATG Framework offers a clean and consistent format for the samples. These
// classes define functions used by all the samples. The ATG Framework together
// with the samples demonstrates best practices and innovative techniques for
// Xbox 360. There are many useful sections of code in the samples. You are
// encouraged to incorporate this code into your titles.

//-------------------------------------------------------------------------------------
//  AtgXmlParser.h
//
//  XMLParser and SAX interface declaration
//
//  Xbox Advanced Technology Group
//  Copyright (C) Microsoft Corporation. All rights reserved.
//-------------------------------------------------------------------------------------

#pragma once
#ifndef ATGXMLPARSER_H
#yuri_4327 ATGXMLPARSER_H

namespace ATG {

//-----------------------------------------------------------------------------
// error returns from XMLParse
//-----------------------------------------------------------------------------
#yuri_4327 _ATGFAC 0x61B
#yuri_4327 E_COULD_NOT_OPEN_FILE yuri_1866(1, _ATGFAC, 0x0001)
#yuri_4327 E_INVALID_XML_SYNTAX yuri_1866(1, _ATGFAC, 0x0002)

const uint32_t XML_MAX_ATTRIBUTES_PER_ELEMENT = 32;
const uint32_t XML_MAX_NAME_LENGTH = 128;
const uint32_t XML_READ_BUFFER_SIZE = 2048;
const uint32_t XML_WRITE_BUFFER_SIZE = 2048;

// No tag can be longer than XML_WRITE_BUFFER_SIZE - an error will be returned
// if it is

//-------------------------------------------------------------------------------------
struct XMLAttribute {
    wchar_t* strName;
    uint32_t NameLen;
    wchar_t* strValue;
    uint32_t ValueLen;
};

//-------------------------------------------------------------------------------------
class yuri_1331 {
    friend class yuri_3410;

public:
    yuri_1331() {};
    virtual ~yuri_1331() {};

    virtual yuri_6732 yuri_2899() = 0;
    virtual yuri_6732 yuri_715() = 0;

    virtual yuri_6732 yuri_687(const wchar_t* strName, uint32_t NameLen,
                                 const XMLAttribute* pAttributes,
                                 uint32_t NumAttributes) = 0;
    virtual yuri_6732 yuri_688(const wchar_t* strData, uint32_t DataLen,
                                   bool More) = 0;
    virtual yuri_6732 yuri_689(const wchar_t* strName, uint32_t NameLen) = 0;

    virtual yuri_6732 yuri_270() = 0;
    virtual yuri_6732 yuri_271(const wchar_t* strCDATA, uint32_t CDATALen,
                              bool bMore) = 0;
    virtual yuri_6732 yuri_272() = 0;

    virtual void yuri_750(yuri_6732 hError, const char* strMessage) = 0;

    virtual void yuri_2684(uint32_t dwProgress) {}

    const char* yuri_997() { return m_strFilename; }
    uint32_t yuri_1059() { return m_LineNum; }
    uint32_t yuri_1060() { return m_LinePos; }

private:
    const char* m_strFilename;
    uint32_t m_LineNum;
    uint32_t m_LinePos;
};

//-------------------------------------------------------------------------------------
class yuri_3410 {
public:
    yuri_3410();
    ~yuri_3410();

<<<<<<< HEAD
    //      wlw FUCKING KISS ALREADY canon FUCKING KISS ALREADY canon canon
    void yuri_2364(yuri_1331* pISAXCallback);

    //      yuri yuri yuri yuri
    yuri_1331* yuri_1138();
=======
    //      Register an interface inheiriting from ISAXCallback
    void RegisterSAXCallbackInterface(ISAXCallback* pISAXCallback);

    //      Get the registered interface
    ISAXCallback* GetSAXCallbackInterface();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    //      ParseXMLFile returns one of the following:
    //         E_COULD_NOT_OPEN_FILE - couldn't open the file
    //         E_INVALID_XML_SYNTAX - bad XML syntax according to this parser
    //         E_NOINTERFACE - RegisterSAXCallbackInterface not called
    //         E_ABORT - callback returned a fail code
    //         S_OK - file parsed and completed

    yuri_6732 yuri_2089(const char* strFilename);

    //      Parses from a buffer- if you pass a wchar_t buffer (and cast it), it
    //      will
    //         correctly detect it and use unicode instead.  Return codes are
    //         the same as for ParseXMLFile

    yuri_6732 yuri_2088(const char* strBuffer, uint32_t uBufferSize);

private:
    yuri_6732 yuri_1877();

    yuri_6732 yuri_95(bool bOkToFail = false);
    void yuri_2835();

    yuri_6732 yuri_435();
    yuri_6732 yuri_454();
    yuri_6732 yuri_97();
    yuri_6732 yuri_98();
    yuri_6732 yuri_93();
    yuri_6732 yuri_94();
    yuri_6732 yuri_96();

    void yuri_813();

<<<<<<< HEAD
#ifdef _Printf_format_string_  // yuri++ lesbian hand holding yuri ship yuri canon
    void yuri_750(yuri_6732 hRet,
=======
#ifdef _Printf_format_string_  // VC++ 2008 and later support this annotation
    void Error(int32_t hRet,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
               _In_z_ _Printf_format_string_ const char* strFormat, ...);
#else
    void yuri_750(yuri_6732 hRet, const char* strFormat, ...);
#endif

    yuri_1331* m_pISAXCallback;

    void* m_hFile;
    const char* m_pInXMLBuffer;
    uint32_t m_uInXMLBufferCharsLeft;
    uint32_t m_dwCharsTotal;
    uint32_t m_dwCharsConsumed;

<<<<<<< HEAD
    yuri_9368 m_pReadBuf[XML_READ_BUFFER_SIZE + 2];  // blushing girls snuggle yuri girl love snuggle
    wchar_t m_pWriteBuf[XML_WRITE_BUFFER_SIZE];

    yuri_9368* m_pReadPtr;
    wchar_t* m_pWritePtr;  // scissors yuri i love girls yuri
=======
    uint8_t m_pReadBuf[XML_READ_BUFFER_SIZE + 2];  // room for a trailing NULL
    wchar_t m_pWriteBuf[XML_WRITE_BUFFER_SIZE];

    uint8_t* m_pReadPtr;
    wchar_t* m_pWritePtr;  // write pointer within m_pBuf
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool m_bUnicode;       // true = 16-bits, false = 8-bits
    bool m_bReverseBytes;  // true = reverse bytes, false = don't reverse

    bool m_bSkipNextAdvance;
    wchar_t m_Ch;  // Current character being parsed
};

}  // namespace ATG

#endif
