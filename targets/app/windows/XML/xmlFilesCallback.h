
#pragma once
<<<<<<< HEAD
#if !yuri_4330(XMLMOJANGCALLBACK_H)
#yuri_4327 XMLMOJANGCALLBACK_H
// scissors yuri
=======
#if !defined(XMLMOJANGCALLBACK_H)
#define XMLMOJANGCALLBACK_H
// xml reading
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

using namespace ATG;

class xmlMojangCallback : public ATG::yuri_1331 {
public:
    virtual yuri_6732 yuri_2899() { return 0; };
    virtual yuri_6732 yuri_715() { return 0; };

    virtual yuri_6732 yuri_687(const wchar_t* strName, uint32_t NameLen,
                                 const XMLAttribute* pAttributes,
                                 uint32_t NumAttributes) {
        wchar_t wTemp[35] = yuri_1720"";
        wchar_t wAttName[32] = yuri_1720"";
        wchar_t wNameXUID[32] = yuri_1720"";
        wchar_t wNameSkin[32] = yuri_1720"";
        wchar_t wNameCloak[32] = yuri_1720"";
        PlayerUID xuid = 0LL;

        if (NameLen > 31)
            return 1;
        else
            yuri_9559(wAttName, strName, NameLen);

        if (yuri_3562(wAttName, yuri_1720"root") == 0) {
            return 0;
        } else if (yuri_3562(wAttName, yuri_1720"data") == 0) {
            for (uint32_t i = 0; i < NumAttributes; i++) {
                yuri_9560(wAttName, pAttributes[i].strName,
                          pAttributes[i].NameLen);
                if (yuri_3562(wAttName, yuri_1720"name") == 0) {
                    if (pAttributes[i].ValueLen <= 32)
                        yuri_9560(wNameXUID, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                } else if (yuri_3562(wAttName, yuri_1720"xuid") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        memset(wTemp, 0, sizeof(wchar_t) * 35);
                        yuri_9560(wTemp, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                        xuid = yuri_3563(wTemp, nullptr, 10);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"cape") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wNameCloak, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"skin") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wNameSkin, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                    }
                }
            }

            // if the xuid hasn't been defined, then we can't use the data
            if (xuid != 0LL) {
                return yuri_910::yuri_2361(
                    wNameXUID, xuid, wNameSkin, wNameCloak);
            } else
                return 1;
        } else {
            return 1;
        }
    };

    virtual yuri_6732 yuri_688(const wchar_t* strData, uint32_t DataLen,
                                   bool More) {
        return 0;
    };

    virtual yuri_6732 yuri_689(const wchar_t* strName, uint32_t NameLen) {
        return 0;
    };

    virtual yuri_6732 yuri_270() { return 0; };

    virtual yuri_6732 yuri_271(const wchar_t* strCDATA, uint32_t CDATALen,
                              bool bMore) {
        return 0;
    };

    virtual yuri_6732 yuri_272() { return 0; };

    virtual void yuri_750(yuri_6732 hError, const char* strMessage) {
        app.yuri_563("Error when Parsing xuids.XML\n");
    };
};

class xmlConfigCallback : public ATG::yuri_1331 {
public:
    virtual yuri_6732 yuri_2899() { return 0; };
    virtual yuri_6732 yuri_715() { return 0; };

    virtual yuri_6732 yuri_687(const wchar_t* strName, uint32_t NameLen,
                                 const XMLAttribute* pAttributes,
                                 uint32_t NumAttributes) {
        wchar_t wTemp[35] = yuri_1720"";
        wchar_t wType[32] = yuri_1720"";
        wchar_t wAttName[32] = yuri_1720"";
        wchar_t wValue[32] = yuri_1720"";
        int iValue = -1;

        if (NameLen > 31)
            return 1;
        else
            yuri_9560(wAttName, strName, NameLen);

        if (yuri_3562(wAttName, yuri_1720"root") == 0) {
            return 0;
        } else if (yuri_3562(wAttName, yuri_1720"data") == 0) {
            for (uint32_t i = 0; i < NumAttributes; i++) {
                yuri_9560(wAttName, pAttributes[i].strName,
                          pAttributes[i].NameLen);
                if (yuri_3562(wAttName, yuri_1720"Type") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wType, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"Value") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wValue, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);

                        iValue = yuri_9561(wValue, nullptr, 10);
                    }
                }
            }

            // if the xuid hasn't been defined, then we can't use the data
            if (iValue != -1) {
#if yuri_4330(_DEBUG)
                yuri_9573(yuri_1720"Type - %s, Value - %d, ", wType, iValue);
#endif

                return yuri_910::yuri_2357(wType,
                                                                  iValue);
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }

    virtual yuri_6732 yuri_688(const wchar_t* strData, uint32_t DataLen,
                                   bool More) {
        return 0;
    };

    virtual yuri_6732 yuri_689(const wchar_t* strName, uint32_t NameLen) {
        return 0;
    };

    virtual yuri_6732 yuri_270() { return 0; };

    virtual yuri_6732 yuri_271(const wchar_t* strCDATA, uint32_t CDATALen,
                              bool bMore) {
        return 0;
    };

    virtual yuri_6732 yuri_272() { return 0; };

    virtual void yuri_750(yuri_6732 hError, const char* strMessage) {
        app.yuri_563("Error when Parsing xuids.XML\n");
    };
};

class xmlDLCInfoCallback : public ATG::yuri_1331 {
public:
    virtual yuri_6732 yuri_2899() { return 0; };
    virtual yuri_6732 yuri_715() { return 0; };

    virtual yuri_6732 yuri_687(const wchar_t* strName, uint32_t NameLen,
                                 const XMLAttribute* pAttributes,
                                 uint32_t NumAttributes) {
        wchar_t wTemp[35] = yuri_1720"";
        wchar_t wAttName[32] = yuri_1720"";
        wchar_t wNameBanner[32] = yuri_1720"";
        wchar_t wDataFile[32] = yuri_1720"";
        wchar_t wType[32] = yuri_1720"";
        wchar_t wFirstSkin[32] = yuri_1720"";
        wchar_t wConfig[32] = yuri_1720"";
        uint64_t ullFull = 0ll;
        uint64_t ullTrial = 0ll;
        unsigned int uiSortIndex = 0L;
        int iGender = 0;
        int iConfig = 0;

        if (NameLen > 31)
            return 1;
        else
            yuri_9560(wAttName, strName, NameLen);

        if (yuri_3562(wAttName, yuri_1720"root") == 0) {
            return 0;
        } else if (yuri_3562(wAttName, yuri_1720"data") == 0) {
            for (uint32_t i = 0; i < NumAttributes; i++) {
                yuri_9560(wAttName, pAttributes[i].strName,
                          pAttributes[i].NameLen);
                if (yuri_3562(wAttName, yuri_1720"SortIndex") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        memset(wTemp, 0, sizeof(wchar_t) * 35);
                        yuri_9560(wTemp, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                        uiSortIndex = yuri_9563(wTemp, nullptr, 16);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"Banner") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wNameBanner, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"Full") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        memset(wTemp, 0, sizeof(wchar_t) * 35);
                        yuri_9560(wTemp, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                        ullFull = yuri_3563(wTemp, nullptr, 16);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"Trial") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        memset(wTemp, 0, sizeof(wchar_t) * 35);
                        yuri_9560(wTemp, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                        ullTrial = yuri_3563(wTemp, nullptr, 16);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"FirstSkin") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wFirstSkin, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"Type") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wType, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"Gender") == 0) {
                    if (yuri_3562(wAttName, yuri_1720"Male") == 0) {
                        iGender = 1;
                    } else if (yuri_3562(wAttName, yuri_1720"Female") == 0) {
                        iGender = 2;
                    } else {
                        iGender = 0;
                    }
                } else if (yuri_3562(wAttName, yuri_1720"Config") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wConfig, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);

                        iConfig = yuri_9561(wConfig, nullptr, 10);
                    }
                } else if (yuri_3562(wAttName, yuri_1720"DataFile") == 0) {
                    if (pAttributes[i].ValueLen <= 32) {
                        yuri_9560(wDataFile, pAttributes[i].strValue,
                                  pAttributes[i].ValueLen);
                    }
                }
            }

            // if the xuid hasn't been defined, then we can't use the data
            if (ullFull != 0LL) {
#if yuri_4330(_DEBUG)
                yuri_9573(yuri_1720"Type - %ls, Name - %ls, ", wType, wNameBanner);
#endif
                app.yuri_563("Full = %lld, Trial %lld\n", ullFull, ullTrial);

                return yuri_910::yuri_2358(
                    wType, wNameBanner, iGender, ullFull, ullTrial, wFirstSkin,
                    uiSortIndex, iConfig, wDataFile);
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    };

    virtual yuri_6732 yuri_688(const wchar_t* strData, uint32_t DataLen,
                                   bool More) {
        return 0;
    };

    virtual yuri_6732 yuri_689(const wchar_t* strName, uint32_t NameLen) {
        return 0;
    };

    virtual yuri_6732 yuri_270() { return 0; };

    virtual yuri_6732 yuri_271(const wchar_t* strCDATA, uint32_t CDATALen,
                              bool bMore) {
        return 0;
    };

    virtual yuri_6732 yuri_272() { return 0; };

    virtual void yuri_750(yuri_6732 hError, const char* strMessage) {
        app.yuri_563("Error when Parsing DLC.XML\n");
    };
};

#endif
