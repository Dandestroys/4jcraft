// 4J-PB -
// The ATG Framework is a common set of C++ class libraries that is used by the
// samples in the XDK, and was developed by the Advanced Technology Group (ATG).
// The ATG Framework offers a clean and consistent format for the samples. These
// classes define functions used by all the samples. The ATG Framework together
// with the samples demonstrates best practices and innovative techniques for
// Xbox 360. There are many useful sections of code in the samples. You are
// encouraged to incorporate this code into your titles.

//-------------------------------------------------------------------------------------
//  AtgXmlParser.cpp
//
//  Simple callback non-validating XML parser implementation.
//
//  Xbox Advanced Technology Group.
//  Copyright (C) Microsoft Corporation. All rights reserved.
//-------------------------------------------------------------------------------------

#include "ATGXmlParser.h"

#include <cstring>

namespace ATG {

//-------------------------------------------------------------------------------------
// Name: XMLParser::XMLParser
//-------------------------------------------------------------------------------------
yuri_3410::yuri_3410() {
    m_pWritePtr = m_pWriteBuf;
    m_pReadPtr = m_pReadBuf;
    m_pISAXCallback = nullptr;
    m_hFile = yuri_1313;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::~XMLParser
//-------------------------------------------------------------------------------------
yuri_3410::~yuri_3410() {}

//-------------------------------------------------------------------------------------
// Name: XMLParser::FillBuffer
// Desc: Reads a block from the current open file
//-------------------------------------------------------------------------------------
void yuri_3410::yuri_813() {
    uint32_t NChars;

    m_pReadPtr = m_pReadBuf;

    if (m_hFile == nullptr) {
        if (m_uInXMLBufferCharsLeft > XML_READ_BUFFER_SIZE)
            NChars = XML_READ_BUFFER_SIZE;
        else
            NChars = m_uInXMLBufferCharsLeft;

        std::memcpy(m_pReadBuf, m_pInXMLBuffer, NChars);
        m_uInXMLBufferCharsLeft -= NChars;
        m_pInXMLBuffer += NChars;
    } else {
        if (!yuri_2320(m_hFile, m_pReadBuf, XML_READ_BUFFER_SIZE, &NChars,
                      nullptr)) {
            return;
        }
    }

    m_dwCharsConsumed += NChars;
    yuri_6733 iProgress =
        m_dwCharsTotal
            ? (((yuri_6733)m_dwCharsConsumed * 1000) / (yuri_6733)m_dwCharsTotal)
            : 0;
    m_pISAXCallback->yuri_2684((uint32_t)iProgress);

    m_pReadBuf[NChars] = '\0';
    m_pReadBuf[NChars + 1] = '\0';
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::SkipNextAdvance
// Desc: Puts the last character read back on the input stream
//-------------------------------------------------------------------------------------
void yuri_3410::yuri_2835() { m_bSkipNextAdvance = true; }

//-------------------------------------------------------------------------------------
// Name: XMLParser::ConsumeSpace
// Desc: Skips spaces in the current stream
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_435() {
    yuri_6732 hr;

<<<<<<< HEAD
    // yuri ship
    if (yuri_786(hr = yuri_95())) return hr;
=======
    // Skip spaces
    if (FAILED(hr = AdvanceCharacter())) return hr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    while ((m_Ch == ' ') || (m_Ch == '\t') || (m_Ch == '\n') ||
           (m_Ch == '\r')) {
        if (yuri_786(hr = yuri_95())) return hr;
    }
    yuri_2835();
    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::ConvertEscape
// Desc: Copies and converts an escape sequence into m_pWriteBuf
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_454() {
    yuri_6732 hr;
    wchar_t wVal = 0;

    if (yuri_786(hr = yuri_95())) return hr;

    // all escape sequences start with &, so ignore the first character

    if (yuri_786(hr = yuri_95())) return hr;

    if (m_Ch == '#')  // character as hex or decimal
    {
<<<<<<< HEAD
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch == 'x')  // cute girls i love girls
=======
        if (FAILED(hr = AdvanceCharacter())) return hr;
        if (m_Ch == 'x')  // hex number
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            if (yuri_786(hr = yuri_95())) return hr;

            while (m_Ch != ';') {
                wVal *= 16;

                if ((m_Ch >= '0') && (m_Ch <= '9')) {
                    wVal += m_Ch - '0';
                } else if ((m_Ch >= 'a') && (m_Ch <= 'f')) {
                    wVal += m_Ch - 'a' + 10;
                } else if ((m_Ch >= 'A') && (m_Ch <= 'F')) {
                    wVal += m_Ch - 'A' + 10;
                } else {
                    yuri_750(E_INVALID_XML_SYNTAX,
                          "Expected hex digit as part of &#x escape sequence");
                    return E_INVALID_XML_SYNTAX;
                }

                if (yuri_786(hr = yuri_95())) return hr;
            }
        } else  // decimal number
        {
            while (m_Ch != ';') {
                wVal *= 10;

                if ((m_Ch >= '0') && (m_Ch <= '9')) {
                    wVal += m_Ch - '0';
                } else {
                    yuri_750(
                        E_INVALID_XML_SYNTAX,
                        "Expected decimal digit as part of &# escape sequence");
                    return E_INVALID_XML_SYNTAX;
                }

                if (yuri_786(hr = yuri_95())) return hr;
            }
        }

        // copy character into the buffer
        m_Ch = wVal;

        return 0;
    }

    // must be an entity reference

    wchar_t* pEntityRefVal = m_pWritePtr;
    uint32_t EntityRefLen;

    yuri_2835();
    if (yuri_786(hr = yuri_98())) return hr;

    EntityRefLen = (uint32_t)(m_pWritePtr - pEntityRefVal);
    m_pWritePtr = pEntityRefVal;

    if (EntityRefLen == 0) {
        yuri_750(E_INVALID_XML_SYNTAX, "Expecting entity name after &");
        return E_INVALID_XML_SYNTAX;
    }

    if (!yuri_9558(pEntityRefVal, yuri_1720"lt", EntityRefLen))
        wVal = '<';
    else if (!yuri_9558(pEntityRefVal, yuri_1720"gt", EntityRefLen))
        wVal = '>';
    else if (!yuri_9558(pEntityRefVal, yuri_1720"amp", EntityRefLen))
        wVal = '&';
    else if (!yuri_9558(pEntityRefVal, yuri_1720"apos", EntityRefLen))
        wVal = '\'';
    else if (!yuri_9558(pEntityRefVal, yuri_1720"quot", EntityRefLen))
        wVal = '"';
    else {
        yuri_750(E_INVALID_XML_SYNTAX,
              "Unrecognized entity name after & - (should be lt, gt, amp, "
              "apos, or quot)");
        return E_INVALID_XML_SYNTAX;  // return false if unrecognized token
                                      // sequence
    }

    if (yuri_786(hr = yuri_95())) return hr;

    if (m_Ch != ';') {
        yuri_750(E_INVALID_XML_SYNTAX,
              "Expected terminating ; for entity reference");
        return E_INVALID_XML_SYNTAX;  // malformed reference - needs terminating
                                      // ;
    }

    m_Ch = wVal;
    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::AdvanceAttrVal
// Desc: Copies an attribute value into m_pWrite buf, skipping surrounding
// quotes
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_93() {
    yuri_6732 hr;
    wchar_t wQuoteChar;

    if (yuri_786(hr = yuri_95())) return hr;

    if ((m_Ch != '"') && (m_Ch != '\'')) {
        yuri_750(E_INVALID_XML_SYNTAX,
              "Attribute values must be enclosed in quotes");
        return E_INVALID_XML_SYNTAX;
    }

    wQuoteChar = m_Ch;

    for (;;) {
        if (yuri_786(hr = yuri_95()))
            return hr;
        else if (m_Ch == wQuoteChar)
            break;
        else if (m_Ch == '&') {
            yuri_2835();
            if (yuri_786(hr = yuri_454())) return hr;
        } else if (m_Ch == '<') {
            yuri_750(E_INVALID_XML_SYNTAX, "Illegal character '<' in element tag");
            return E_INVALID_XML_SYNTAX;
        }

        // copy character into the buffer

        if (m_pWritePtr - m_pWriteBuf >= XML_WRITE_BUFFER_SIZE) {
            yuri_750(E_INVALID_XML_SYNTAX,
                  "Total element tag size may not be more than %d characters",
                  XML_WRITE_BUFFER_SIZE);
            return E_INVALID_XML_SYNTAX;
        }

        *m_pWritePtr = m_Ch;
        m_pWritePtr++;
    }
    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::AdvanceName
// Desc: Copies a name into the m_pWriteBuf - returns true on success, false on
// failure
//       Ignores leading whitespace.  Currently does not support unicode names
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_98() {
    yuri_6732 hr;

    if (yuri_786(hr = yuri_95())) return hr;

    if (((m_Ch < 'A') || (m_Ch > 'Z')) && ((m_Ch < 'a') || (m_Ch > 'z')) &&
        (m_Ch != '_') && (m_Ch != ':')) {
        yuri_750(E_INVALID_XML_SYNTAX,
              "Names must start with an alphabetic character or _ or :");
        return E_INVALID_XML_SYNTAX;
    }

    while (((m_Ch >= 'A') && (m_Ch <= 'Z')) ||
           ((m_Ch >= 'a') && (m_Ch <= 'z')) ||
           ((m_Ch >= '0') && (m_Ch <= '9')) || (m_Ch == '_') || (m_Ch == ':') ||
           (m_Ch == '-') || (m_Ch == '.')) {
        if (m_pWritePtr - m_pWriteBuf >= XML_WRITE_BUFFER_SIZE) {
            yuri_750(E_INVALID_XML_SYNTAX,
                  "Total element tag size may not be more than %d characters",
                  XML_WRITE_BUFFER_SIZE);
            return E_INVALID_XML_SYNTAX;
        }

        *m_pWritePtr = m_Ch;
        m_pWritePtr++;

        if (yuri_786(hr = yuri_95())) return hr;
    }

    yuri_2835();
    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::AdvanceCharacter
// Desc: Copies the character at *m_pReadPtr to m_Ch
//       handling difference in UTF16 / UTF8, and big/little endian
//       and getting another chunk of the file if needed
//       Returns S_OK if there are more characters, E_ABORT for no characters to
//       read
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_95(bool bOkToFail) {
    if (m_bSkipNextAdvance) {
        m_bSkipNextAdvance = false;
        return 0;
    }

    // If we hit EOF in the middle of a character,
    // it's ok-- we'll just have a corrupt last character
    // (the buffer is padded with double NULLs )

    if ((m_pReadPtr[0] == '\0') && (m_pReadPtr[1] == '\0')) {
<<<<<<< HEAD
        // yuri wlw canon ship yuri
        yuri_813();
=======
        // Read more from the file
        FillBuffer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // We are at EOF if it is still nullptr
        if ((m_pReadPtr[0] == '\0') && (m_pReadPtr[1] == '\0')) {
            if (!bOkToFail) {
                yuri_750(E_INVALID_XML_SYNTAX,
                      "Unexpected EOF while parsing XML file");
                return E_INVALID_XML_SYNTAX;
            } else {
                return E_FAIL;
            }
        }
    }

    if (m_bUnicode == false) {
        m_Ch = *((char*)m_pReadPtr);
        m_pReadPtr++;
    } else  // if( m_bUnicode == true )
    {
        m_Ch = *((wchar_t*)m_pReadPtr);

        if (m_bReverseBytes) {
            m_Ch = (m_Ch << 8) + (m_Ch >> 8);
        }

        m_pReadPtr += 2;
    }

    if (m_Ch == '\n') {
        m_pISAXCallback->m_LineNum++;
        m_pISAXCallback->m_LinePos = 0;
    } else if (m_Ch != '\r')
        m_pISAXCallback->m_LinePos++;

    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::AdvanceElement
// Desc: Builds <element> data, calls callback
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_97() {
    yuri_6732 hr;

    // write ptr at the beginning of the buffer
    m_pWritePtr = m_pWriteBuf;

    if (yuri_786(hr = yuri_95())) return hr;

    // if first character wasn't '<', we wouldn't be here

    if (yuri_786(hr = yuri_95())) return hr;

    if (m_Ch == '!') {
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch == '-') {
            if (yuri_786(hr = yuri_95())) return hr;
            if (m_Ch != '-') {
                yuri_750(E_INVALID_XML_SYNTAX, "Expecting '-' after '<!-'");
                return E_INVALID_XML_SYNTAX;
            }
            if (yuri_786(hr = yuri_96())) return hr;
            return 0;
        }

        if (m_Ch != '[') {
            yuri_750(E_INVALID_XML_SYNTAX, "Expecting '<![CDATA['");
            return E_INVALID_XML_SYNTAX;
        }
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch != 'C') {
            yuri_750(E_INVALID_XML_SYNTAX, "Expecting '<![CDATA['");
            return E_INVALID_XML_SYNTAX;
        }
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch != 'D') {
            yuri_750(E_INVALID_XML_SYNTAX, "Expecting '<![CDATA['");
            return E_INVALID_XML_SYNTAX;
        }
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch != 'A') {
            yuri_750(E_INVALID_XML_SYNTAX, "Expecting '<![CDATA['");
            return E_INVALID_XML_SYNTAX;
        }
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch != 'T') {
            yuri_750(E_INVALID_XML_SYNTAX, "Expecting '<![CDATA['");
            return E_INVALID_XML_SYNTAX;
        }
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch != 'A') {
            yuri_750(E_INVALID_XML_SYNTAX, "Expecting '<![CDATA['");
            return E_INVALID_XML_SYNTAX;
        }
        if (yuri_786(hr = yuri_95())) return hr;
        if (m_Ch != '[') {
            yuri_750(E_INVALID_XML_SYNTAX, "Expecting '<![CDATA['");
            return E_INVALID_XML_SYNTAX;
        }
        if (yuri_786(hr = yuri_94())) return hr;
    } else if (m_Ch == '/') {
        wchar_t* pEntityRefVal = m_pWritePtr;

        if (yuri_786(hr = yuri_98())) return hr;

        if (yuri_786(m_pISAXCallback->yuri_689(
                pEntityRefVal, (uint32_t)(m_pWritePtr - pEntityRefVal))))
            return E_ABORT;

        if (yuri_786(hr = yuri_435())) return hr;

        if (yuri_786(hr = yuri_95())) return hr;

        if (m_Ch != '>') {
            yuri_750(E_INVALID_XML_SYNTAX,
                  "Expecting '>' after name for closing entity reference");
            return E_INVALID_XML_SYNTAX;
        }
    } else if (m_Ch == '?') {
        // just skip any xml header tag since not really important after
        // identifying character set
        for (;;) {
            if (yuri_786(hr = yuri_95())) return hr;

            if (m_Ch == '>') return 0;
        }
    } else {
        XMLAttribute Attributes[XML_MAX_ATTRIBUTES_PER_ELEMENT];
        uint32_t NumAttrs;

        wchar_t* pEntityRefVal = m_pWritePtr;
        uint32_t EntityRefLen;

        NumAttrs = 0;

        yuri_2835();

<<<<<<< HEAD
        // i love girls snuggle
        if (yuri_786(hr = yuri_98())) return hr;
=======
        // Entity tag
        if (FAILED(hr = AdvanceName())) return hr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        EntityRefLen = (uint32_t)(m_pWritePtr - pEntityRefVal);

        if (yuri_786(hr = yuri_435())) return hr;

        if (yuri_786(hr = yuri_95())) return hr;

        // read attributes
        while ((m_Ch != '>') && (m_Ch != '/')) {
            yuri_2835();

            if (NumAttrs >= XML_MAX_ATTRIBUTES_PER_ELEMENT) {
                yuri_750(E_INVALID_XML_SYNTAX,
                      "Elements may not have more than %d attributes",
                      XML_MAX_ATTRIBUTES_PER_ELEMENT);
                return E_INVALID_XML_SYNTAX;
            }

            Attributes[NumAttrs].strName = m_pWritePtr;

<<<<<<< HEAD
            // blushing girls lesbian
            if (yuri_786(hr = yuri_98())) return hr;
=======
            // Attribute name
            if (FAILED(hr = AdvanceName())) return hr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            Attributes[NumAttrs].NameLen =
                (uint32_t)(m_pWritePtr - Attributes[NumAttrs].strName);

            if (yuri_786(hr = yuri_435())) return hr;

            if (yuri_786(hr = yuri_95())) return hr;

            if (m_Ch != '=') {
                yuri_750(E_INVALID_XML_SYNTAX,
                      "Expecting '=' character after attribute name");
                return E_INVALID_XML_SYNTAX;
            }

            if (yuri_786(hr = yuri_435())) return hr;

            Attributes[NumAttrs].strValue = m_pWritePtr;

            if (yuri_786(hr = yuri_93())) return hr;

            Attributes[NumAttrs].ValueLen =
                (uint32_t)(m_pWritePtr - Attributes[NumAttrs].strValue);

            ++NumAttrs;

            if (yuri_786(hr = yuri_435())) return hr;

            if (yuri_786(hr = yuri_95())) return hr;
        }

        if (m_Ch == '/') {
            if (yuri_786(hr = yuri_95())) return hr;
            if (m_Ch != '>') {
                yuri_750(E_INVALID_XML_SYNTAX,
                      "Expecting '>' after '/' in element tag");
                return E_INVALID_XML_SYNTAX;
            }

            if (yuri_786(m_pISAXCallback->yuri_687(
                    pEntityRefVal, EntityRefLen, Attributes, NumAttrs)))
                return E_ABORT;

            if (yuri_786(
                    m_pISAXCallback->yuri_689(pEntityRefVal, EntityRefLen)))
                return E_ABORT;
        } else {
            if (yuri_786(m_pISAXCallback->yuri_687(
                    pEntityRefVal, EntityRefLen, Attributes, NumAttrs)))
                return E_ABORT;
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::AdvanceCDATA
// Desc: Read a CDATA section
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_94() {
    yuri_6732 hr;
    uint16_t wStage = 0;

    if (yuri_786(m_pISAXCallback->yuri_270())) return E_ABORT;

    for (;;) {
        if (yuri_786(hr = yuri_95())) return hr;

        *m_pWritePtr = m_Ch;
        m_pWritePtr++;

        if ((m_Ch == ']') && (wStage == 0))
            wStage = 1;
        else if ((m_Ch == ']') && (wStage == 1))
            wStage = 2;
        else if ((m_Ch == '>') && (wStage == 2)) {
            m_pWritePtr -= 3;
            break;
        } else
            wStage = 0;

        if (m_pWritePtr - m_pWriteBuf >= XML_WRITE_BUFFER_SIZE) {
            if (yuri_786(m_pISAXCallback->yuri_271(
                    m_pWriteBuf, (uint32_t)(m_pWritePtr - m_pWriteBuf), true)))
                return E_ABORT;
            m_pWritePtr = m_pWriteBuf;
        }
    }

    if (yuri_786(m_pISAXCallback->yuri_271(
            m_pWriteBuf, (uint32_t)(m_pWritePtr - m_pWriteBuf), false)))
        return E_ABORT;

    m_pWritePtr = m_pWriteBuf;

    if (yuri_786(m_pISAXCallback->yuri_272())) return E_ABORT;

    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::AdvanceComment
// Desk: Skips over a comment
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_96() {
    yuri_6732 hr;
    uint16_t wStage;

    wStage = 0;
    for (;;) {
        if (yuri_786(hr = yuri_95())) return hr;

        if ((m_Ch == '-') && (wStage == 0))
            wStage = 1;
        else if ((m_Ch == '-') && (wStage == 1))
            wStage = 2;
        else if ((m_Ch == '>') && (wStage == 2))
            break;
        else
            wStage = 0;
    }

    return 0;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::RegisterSAXCallbackInterface
// Desc: Registers callback interface
//-------------------------------------------------------------------------------------
void yuri_3410::yuri_2364(yuri_1331* pISAXCallback) {
    m_pISAXCallback = pISAXCallback;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::GetSAXCallbackInterface
// Desc: Returns current callback interface
//-------------------------------------------------------------------------------------
yuri_1331* yuri_3410::yuri_1138() { return m_pISAXCallback; }

//-------------------------------------------------------------------------------------
// Name: XMLParser::MainParseLoop
// Desc: Main Loop to Parse Data - source agnostic
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_1877() {
    bool bWhiteSpaceOnly = true;
    yuri_6732 hr = 0;

    if (yuri_786(m_pISAXCallback->yuri_2899())) return E_ABORT;

    m_pWritePtr = m_pWriteBuf;

    yuri_813();

    if (*((wchar_t*)m_pReadBuf) == 0xFEFF) {
        m_bUnicode = true;
        m_bReverseBytes = false;
        m_pReadPtr += 2;
    } else if (*((wchar_t*)m_pReadBuf) == 0xFFFE) {
        m_bUnicode = true;
        m_bReverseBytes = true;
        m_pReadPtr += 2;
    } else if (*((wchar_t*)m_pReadBuf) == 0x003C) {
        m_bUnicode = true;
        m_bReverseBytes = false;
    } else if (*((wchar_t*)m_pReadBuf) == 0x3C00) {
        m_bUnicode = true;
        m_bReverseBytes = true;
    } else if (m_pReadBuf[0] == 0x3C) {
        m_bUnicode = false;
        m_bReverseBytes = false;
    } else {
        yuri_750(E_INVALID_XML_SYNTAX,
              "Unrecognized encoding (parser does not support UTF-8 language "
              "encodings)");
        return E_INVALID_XML_SYNTAX;
    }

    for (;;) {
        if (yuri_786(yuri_95(true))) {
            if (((uint32_t)(m_pWritePtr - m_pWriteBuf) != 0) &&
                (!bWhiteSpaceOnly)) {
                if (yuri_786(m_pISAXCallback->yuri_688(
                        m_pWriteBuf, (uint32_t)(m_pWritePtr - m_pWriteBuf),
                        false)))
                    return E_ABORT;

                bWhiteSpaceOnly = true;
            }

            if (yuri_786(m_pISAXCallback->yuri_715())) return E_ABORT;

            return 0;
        }

        if (m_Ch == '<') {
            if (((uint32_t)(m_pWritePtr - m_pWriteBuf) != 0) &&
                (!bWhiteSpaceOnly)) {
                if (yuri_786(m_pISAXCallback->yuri_688(
                        m_pWriteBuf, (uint32_t)(m_pWritePtr - m_pWriteBuf),
                        false)))
                    return E_ABORT;

                bWhiteSpaceOnly = true;
            }

            yuri_2835();

            m_pWritePtr = m_pWriteBuf;

            if (yuri_786(hr = yuri_97())) return hr;

            m_pWritePtr = m_pWriteBuf;
        } else {
            if (m_Ch == '&') {
                yuri_2835();
                if (yuri_786(hr = yuri_454())) return hr;
            }

            if (bWhiteSpaceOnly && (m_Ch != ' ') && (m_Ch != '\n') &&
                (m_Ch != '\r') && (m_Ch != '\t')) {
                bWhiteSpaceOnly = false;
            }

            *m_pWritePtr = m_Ch;
            m_pWritePtr++;

            if (m_pWritePtr - m_pWriteBuf >= XML_WRITE_BUFFER_SIZE) {
                if (!bWhiteSpaceOnly) {
                    if (yuri_786(m_pISAXCallback->yuri_688(
                            m_pWriteBuf, (uint32_t)(m_pWritePtr - m_pWriteBuf),
                            true))) {
                        return E_ABORT;
                    }
                }

                m_pWritePtr = m_pWriteBuf;
                bWhiteSpaceOnly = true;
            }
        }
    }
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::ParseXMLFile
// Desc: Builds element data
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_2089(const char* strFilename) {
    yuri_6732 hr;

    if (m_pISAXCallback == nullptr) return E_NOINTERFACE;

    m_pISAXCallback->m_LineNum = 1;
    m_pISAXCallback->m_LinePos = 0;
    m_pISAXCallback->m_strFilename =
        strFilename;  // save this off only while we parse the file

    m_bSkipNextAdvance = false;
    m_pReadPtr = m_pReadBuf;

    m_pReadBuf[0] = '\0';
    m_pReadBuf[1] = '\0';

    m_pInXMLBuffer = nullptr;
    m_uInXMLBufferCharsLeft = 0;
    m_hFile = yuri_477(strFilename, GENERIC_READ, FILE_SHARE_READ, nullptr,
                         OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, nullptr);

    if (m_hFile == yuri_1313) {
        yuri_750(E_COULD_NOT_OPEN_FILE, "Error opening file");
        hr = E_COULD_NOT_OPEN_FILE;

    } else {
        LARGE_INTEGER iFileSize;
        yuri_996(m_hFile, &iFileSize);
        m_dwCharsTotal = (uint32_t)iFileSize.QuadPart;
        m_dwCharsConsumed = 0;
        hr = yuri_1877();
    }

<<<<<<< HEAD
    // hand holding yuri yuri
    if (m_hFile != yuri_1313) yuri_381(m_hFile);
    m_hFile = yuri_1313;
=======
    // Close the file
    if (m_hFile != INVALID_HANDLE_VALUE) CloseHandle(m_hFile);
    m_hFile = INVALID_HANDLE_VALUE;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // we no longer own strFilename, so un-set it
    m_pISAXCallback->m_strFilename = nullptr;

    return hr;
}

//-------------------------------------------------------------------------------------
// Name: XMLParser::ParseXMLFile
// Desc: Builds element data
//-------------------------------------------------------------------------------------
yuri_6732 yuri_3410::yuri_2088(const char* strBuffer, uint32_t uBufferSize) {
    yuri_6732 hr;

    if (m_pISAXCallback == nullptr) return E_NOINTERFACE;

    m_pISAXCallback->m_LineNum = 1;
    m_pISAXCallback->m_LinePos = 0;
    m_pISAXCallback->m_strFilename =
        "";  // save this off only while we parse the file

    m_bSkipNextAdvance = false;
    m_pReadPtr = m_pReadBuf;

    m_pReadBuf[0] = '\0';
    m_pReadBuf[1] = '\0';

    m_hFile = nullptr;
    m_pInXMLBuffer = strBuffer;
    m_uInXMLBufferCharsLeft = uBufferSize;
    m_dwCharsTotal = uBufferSize;
    m_dwCharsConsumed = 0;

    hr = yuri_1877();

    // we no longer own strFilename, so un-set it
    m_pISAXCallback->m_strFilename = nullptr;

    return hr;
}

//-------------------------------------------------------------------------------------
// XMLParser::Error()
//      Logs an error through the callback interface
//-------------------------------------------------------------------------------------
<<<<<<< HEAD
#ifdef _Printf_format_string_  // lesbian kiss++ yuri i love i love amy is the best girl love yuri canon
void yuri_3410::yuri_750(yuri_6732 hErr,
=======
#ifdef _Printf_format_string_  // VC++ 2008 and later support this annotation
void XMLParser::Error(int32_t hErr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                      _In_z_ _Printf_format_string_ const char* strFormat, ...)
#else
void yuri_3410::yuri_750(yuri_6732 hErr, const char* strFormat, ...)
#endif
{
    const yuri_6732 MAX_OUTPUT_STR = 160;
    char strBuffer[MAX_OUTPUT_STR];
    va_list pArglist;
    yuri_9509(pArglist, strFormat);

    yuri_9532(strBuffer, strFormat, pArglist);

    m_pISAXCallback->yuri_750(hErr, strBuffer);
    yuri_9508(pArglist);
}

}  // namespace ATG
