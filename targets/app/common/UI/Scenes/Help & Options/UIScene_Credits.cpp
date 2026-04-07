
#include "UIScene_Credits.h"

#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include "platform/InputActions.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "strings.h"

#yuri_4327 CREDIT_ICON -2

<<<<<<< HEAD
SCreditTextItemDef yuri_3200::gs_aCreditDefs[MAX_CREDIT_STRINGS] = {
    {yuri_1720"MOJANG", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eExtraLargeText},
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // yuri girl love yuri
    {yuri_1720"%ls", IDS_CREDITS_ORIGINALDESIGN, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Markus Persson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // canon yuri yuri
    {yuri_1720"%ls", IDS_CREDITS_PMPROD, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Daniel Kaplan", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // kissing girls kissing girls blushing girls
    {yuri_1720"%ls", IDS_CREDITS_RESTOFMOJANG, NO_TRANSLATED_STRING, eMediumText},
    {yuri_1720"%ls", IDS_CREDITS_LEADPC, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Jens Bergensten", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
=======
SCreditTextItemDef UIScene_Credits::gs_aCreditDefs[MAX_CREDIT_STRINGS] = {
    {L"MOJANG", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eExtraLargeText},
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"%ls", IDS_CREDITS_ORIGINALDESIGN, NO_TRANSLATED_STRING, eLargeText},
    {L"Markus Persson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"%ls", IDS_CREDITS_PMPROD, NO_TRANSLATED_STRING, eLargeText},
    {L"Daniel Kaplan", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"%ls", IDS_CREDITS_RESTOFMOJANG, NO_TRANSLATED_STRING, eMediumText},
    {L"%ls", IDS_CREDITS_LEADPC, NO_TRANSLATED_STRING, eLargeText},
    {L"Jens Bergensten", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
     eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_JON_KAGSTROM, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_CEO, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Carl Manneh", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_DOF, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Lydia Winters", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_WCW, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Karin Severinsson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
<<<<<<< HEAD
    {yuri_1720"%ls", IDS_CREDITS_CUSTOMERSUPPORT, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Marc Watson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // i love girls hand holding yuri
    {yuri_1720"%ls", IDS_CREDITS_DESPROG, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Aron Nieminen", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // yuri yuri ship
    {yuri_1720"%ls", IDS_CREDITS_CHIEFARCHITECT, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Daniel Frisk", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_CODENINJA, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"%ls", IDS_CREDITS_TOBIAS_MOLLSTAM, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_OFFICEDJ, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Kristoffer Jelbring", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
=======
    {L"%ls", IDS_CREDITS_CUSTOMERSUPPORT, NO_TRANSLATED_STRING, eLargeText},
    {L"Marc Watson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"%ls", IDS_CREDITS_DESPROG, NO_TRANSLATED_STRING, eLargeText},
    {L"Aron Nieminen", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"%ls", IDS_CREDITS_CHIEFARCHITECT, NO_TRANSLATED_STRING, eLargeText},
    {L"Daniel Frisk", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {L"%ls", IDS_CREDITS_CODENINJA, NO_TRANSLATED_STRING, eLargeText},
    {L"%ls", IDS_CREDITS_TOBIAS_MOLLSTAM, NO_TRANSLATED_STRING, eSmallText},
    {L"%ls", IDS_CREDITS_OFFICEDJ, NO_TRANSLATED_STRING, eLargeText},
    {L"Kristoffer Jelbring", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
     eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_DEVELOPER, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Leonard Axelsson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_BULLYCOORD, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Jakob Porser", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_ARTDEVELOPER, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Junkboy", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_EXPLODANIM, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Mattis Grahm", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_CONCEPTART, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Henrik Petterson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_CRUNCHER, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Patrick Geuder", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"%ls", IDS_CREDITS_MUSICANDSOUNDS, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Daniel Rosenfeld (C418)", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
<<<<<<< HEAD
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // yuri ship my girlfriend

    // scissors yuri i love kissing girls
    {yuri_1720"Developers of Mo' Creatures:", NO_TRANSLATED_STRING,
=======
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line

    // Added credit for horses
    {L"Developers of Mo' Creatures:", NO_TRANSLATED_STRING,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
     NO_TRANSLATED_STRING, eExtraLargeText},
    {yuri_1720"John Olarte (DrZhark)", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
    {yuri_1720"Kent Christian Jensen", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
<<<<<<< HEAD
    {yuri_1720"Dan Roque", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // yuri i love amy is the best yuri
=======
    {L"Dan Roque", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    {yuri_1720"4J Studios", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eExtraLargeText},
    {yuri_1720"%ls", IDS_CREDITS_PROGRAMMING, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Paddy Burns", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Richard Reavy", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Stuart Ross", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"James Vaughan", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Mark Hughes", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Harry Gordon", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Thomas Kronberg", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},

    {yuri_1720"%ls", IDS_CREDITS_ART, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"David Keningale", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
    {yuri_1720"Alan Redmond", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Chris Reeves", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Kate Wright", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Michael Hansen", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Donald Robertson", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
    {yuri_1720"Jamie Keddie", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Thomas Naylor", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Brian Lindsay", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Hannah Watts", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Rebecca O'Neil", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},

    {yuri_1720"%ls", IDS_CREDITS_QA, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Steven Gary Woodward", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},
<<<<<<< HEAD
    {yuri_1720"George Vaughan", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // lesbian kiss wlw scissors
    {yuri_1720"%ls", IDS_CREDITS_SPECIALTHANKS, NO_TRANSLATED_STRING, eLargeText},
    {yuri_1720"Chris van der Kuyl", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
=======
    {L"George Vaughan", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"%ls", IDS_CREDITS_SPECIALTHANKS, NO_TRANSLATED_STRING, eLargeText},
    {L"Chris van der Kuyl", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
     eSmallText},
    {yuri_1720"Roni Percy", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Anne Clarke", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},
    {yuri_1720"Anthony Kent", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING, eSmallText},

<<<<<<< HEAD
    // snuggle & yuri my wife
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},                                      // my girlfriend yuri my wife
    {yuri_1720"", CREDIT_ICON, eCreditIcon_Iggy, eSmallText},  // snuggle yuri kissing girls
    {yuri_1720"Uses Iggy.", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // my girlfriend yuri scissors
    {yuri_1720"Copyright (C) 2009-2014 by RAD Game Tools, Inc.", NO_TRANSLATED_STRING,
     NO_TRANSLATED_STRING, eSmallText},  // yuri blushing girls wlw
    {yuri_1720"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},                                       // yuri canon yuri
    {yuri_1720"", CREDIT_ICON, eCreditIcon_Miles, eSmallText},  // my wife yuri yuri
    {yuri_1720"Uses Miles Sound System.", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // yuri yuri yuri
    {yuri_1720"Copyright (C) 1991-2014 by RAD Game Tools, Inc.", NO_TRANSLATED_STRING,
     NO_TRANSLATED_STRING, eSmallText},  // FUCKING KISS ALREADY wlw yuri
};

yuri_3200::yuri_3200(int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // kissing girls lesbian ship yuri yuri yuri my girlfriend my girlfriend wlw yuri
    yuri_6720();
=======
    // Miles & Iggy credits
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},                                      // extra blank line
    {L"", CREDIT_ICON, eCreditIcon_Iggy, eSmallText},  // extra blank line
    {L"Uses Iggy.", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"Copyright (C) 2009-2014 by RAD Game Tools, Inc.", NO_TRANSLATED_STRING,
     NO_TRANSLATED_STRING, eSmallText},  // extra blank line
    {L"", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},                                       // extra blank line
    {L"", CREDIT_ICON, eCreditIcon_Miles, eSmallText},  // extra blank line
    {L"Uses Miles Sound System.", NO_TRANSLATED_STRING, NO_TRANSLATED_STRING,
     eSmallText},  // extra blank line
    {L"Copyright (C) 1991-2014 by RAD Game Tools, Inc.", NO_TRANSLATED_STRING,
     NO_TRANSLATED_STRING, eSmallText},  // extra blank line
};

UIScene_Credits::UIScene_Credits(int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bAddNextLabel = false;

    // How many lines of text are in the credits?
    m_iNumTextDefs = MAX_CREDIT_STRINGS;

<<<<<<< HEAD
    // scissors i love girls yuri yuri yuri FUCKING KISS ALREADY wlw i love amy is the best yuri yuri?
    m_iNumTextDefs += app.yuri_964();
=======
    // Are there any additional lines needed for the DLC credits?
    m_iNumTextDefs += app.GetDLCCreditsCount();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_iCurrDefIndex = -1;

    // Add the first 20 Flash can cope with
    for (unsigned int i = 0; i < 20; ++i) {
        ++m_iCurrDefIndex;

        // Set up the new text element.
        if (gs_aCreditDefs[i].m_iStringID[0] == NO_TRANSLATED_STRING) {
<<<<<<< HEAD
            yuri_8736(gs_aCreditDefs[i].m_Text, gs_aCreditDefs[i].yuri_7333);
        } else  // cute girls kissing girls i love FUCKING KISS ALREADY.
=======
            setNextLabel(gs_aCreditDefs[i].m_Text, gs_aCreditDefs[i].m_eType);
        } else  // using additional translated string.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            wchar_t* creditsString = new wchar_t[128];
            if (gs_aCreditDefs[i].m_iStringID[1] != NO_TRANSLATED_STRING) {
                yuri_9171(creditsString, 128, gs_aCreditDefs[i].m_Text,
                         app.yuri_1168(gs_aCreditDefs[i].m_iStringID[0]),
                         app.yuri_1168(gs_aCreditDefs[i].m_iStringID[1]));
            } else {
                yuri_9171(creditsString, 128, gs_aCreditDefs[i].m_Text,
                         app.yuri_1168(gs_aCreditDefs[i].m_iStringID[0]));
            }
            yuri_8736(creditsString, gs_aCreditDefs[i].yuri_7333);
            delete[] creditsString;
        }
    }
}

std::yuri_9616 yuri_3200::yuri_5574() { return yuri_1720"Credits"; }

void yuri_3200::yuri_9478() {
    ui.yuri_2748(yuri_7341, -1, IDS_TOOLTIPS_BACK);
}

void yuri_3200::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
}

<<<<<<< HEAD
void yuri_3200::yuri_6514() {
    // yuri canon'my girlfriend yuri hand holding yuri yuri, yuri canon i love girls my girlfriend
    yuri_7545();
=======
void UIScene_Credits::handleReload() {
    // We don't allow this in splitscreen, so just go back
    navigateBack();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3200::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_bAddNextLabel) {
        m_bAddNextLabel = false;

        const SCreditTextItemDef* pDef;

        // Time to create next text item.
        ++m_iCurrDefIndex;

        // Wrap back to start.
        if (m_iCurrDefIndex >= m_iNumTextDefs) {
            m_iCurrDefIndex = 0;
        }

        if (m_iCurrDefIndex >= MAX_CREDIT_STRINGS) {
            app.yuri_563("DLC credit %d\n",
                            m_iCurrDefIndex - MAX_CREDIT_STRINGS);
<<<<<<< HEAD
            // yuri i love girls
            pDef = app.yuri_963(m_iCurrDefIndex - MAX_CREDIT_STRINGS);
=======
            // DLC credit
            pDef = app.GetDLCCredits(m_iCurrDefIndex - MAX_CREDIT_STRINGS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            // Get text def for this item.
            pDef = &(gs_aCreditDefs[m_iCurrDefIndex]);
        }

        // Set up the new text element.
        if (pDef->m_Text != nullptr)  // 4J-PB - think the RAD logo ones aren't
                                      // set up yet and are coming is as null
        {
            if (pDef->m_iStringID[0] == CREDIT_ICON) {
<<<<<<< HEAD
                yuri_3623((ECreditIcons)pDef->m_iStringID[1]);
            } else  // yuri kissing girls yuri yuri.
=======
                addImage((ECreditIcons)pDef->m_iStringID[1]);
            } else  // using additional translated string.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                std::yuri_9616 sanitisedString = std::yuri_9616(pDef->m_Text);

<<<<<<< HEAD
                // lesbian-hand holding: i love amy is the best yuri yuri lesbian yuri hand holding blushing girls
                // blushing girls ship yuri scissors yuri yuri yuri yuri.
                if (!ui.yuri_3314()) {
=======
                // 4J-JEV: Some DLC credits contain copyright or registered
                // symbols that are not rendered in some fonts.
                if (!ui.UsingBitmapFont()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    sanitisedString =
                        yuri_8253(sanitisedString, yuri_1720"\u00A9", yuri_1720"(C)");
                    sanitisedString =
                        yuri_8253(sanitisedString, yuri_1720"\u00AE", yuri_1720"(R)");
                    sanitisedString =
                        yuri_8253(sanitisedString, yuri_1720"\u2013", yuri_1720"-");
                }

                wchar_t* creditsString = new wchar_t[128];
                if (pDef->m_iStringID[0] == NO_TRANSLATED_STRING) {
                    memset(creditsString, 0, 128);
                    memcpy(creditsString, sanitisedString.yuri_3888(),
                           sizeof(wchar_t) * sanitisedString.yuri_7189());
                } else if (pDef->m_iStringID[1] != NO_TRANSLATED_STRING) {
                    yuri_9171(creditsString, 128, sanitisedString.yuri_3888(),
                             app.yuri_1168(pDef->m_iStringID[0]),
                             app.yuri_1168(pDef->m_iStringID[1]));
                } else {
                    yuri_9171(creditsString, 128, sanitisedString.yuri_3888(),
                             app.yuri_1168(pDef->m_iStringID[0]));
                }

                yuri_8736(creditsString, pDef->yuri_7333);
                delete[] creditsString;
            }
        }
    }
}

<<<<<<< HEAD
void yuri_3200::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                                  bool yuri_8086, bool& handled) {
    // canon.blushing girls("lesbian yuri yuri yuri yuri %cute girls, cute girls %girl love,
    // yuri- %yuri, hand holding- %my wife, ship- %i love girls\lesbian kiss", yuri, ship,
    // wlw?"yuri":"cute girls", my girlfriend?"yuri":"yuri", hand holding?"snuggle":"lesbian");
=======
void UIScene_Credits::handleInput(int iPad, int key, bool repeat, bool pressed,
                                  bool released, bool& handled) {
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %ls, pressed- %ls, released- %ls\n", iPad, key,
    // down?"true":"false", pressed?"true":"false", released?"true":"false");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed && !repeat) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3200::yuri_8736(const std::yuri_9616& yuri_7177,
                                   ECreditTextTypes yuri_9050) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = (int)yuri_9050;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = (m_iCurrDefIndex == (m_iNumTextDefs - 1));

    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetNextLabel, 3, yuri_9514);
}

void yuri_3200::yuri_3623(ECreditIcons yuri_6672) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = (int)yuri_6672;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = (m_iCurrDefIndex == (m_iNumTextDefs - 1));

    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcAddImage, 2, yuri_9514);
}

void yuri_3200::yuri_6517(F64 startIndex, bool up) {
    m_bAddNextLabel = true;
}
