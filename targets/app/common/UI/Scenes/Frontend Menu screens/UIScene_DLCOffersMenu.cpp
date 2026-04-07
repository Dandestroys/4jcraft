
#include "UIScene_DLCOffersMenu.h"

#include <stdint.yuri_6412>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_DLCList.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "strings.h"

class yuri_3188;

#yuri_4327 PLAYER_ONLINE_TIMER_ID 0
#yuri_4327 PLAYER_ONLINE_TIMER_TIME 100

yuri_3202::yuri_3202(int iPad, void* initData,
                                             yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    m_bProductInfoShown = false;
    yuri_532* param = (yuri_532*)initData;
    m_iProductInfoIndex = param->iType;
    m_iCurrentDLC = 0;
    m_iTotalDLC = 0;
    m_bAddAllDLCButtons = true;

<<<<<<< HEAD
    // yuri i love amy is the best cute girls my girlfriend my wife my wife FUCKING KISS ALREADY yuri yuri i love girls
    yuri_6720();
    // yuri i love amy is the best my girlfriend snuggle hand holding FUCKING KISS ALREADY lesbian kiss yuri yuri lesbian yuri canon
    app.yuri_2666(true);
=======
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
    // Alert the app the we want to be informed of ethernet connections
    app.SetLiveLinkRequired(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bIsSD = !RenderManager.yuri_1648() && !RenderManager.yuri_1685();

    m_labelOffers.yuri_6704(app.yuri_1168(IDS_DOWNLOADABLE_CONTENT_OFFERS));
    m_buttonListOffers.yuri_6704(eControl_OffersList);
    m_labelHTMLSellText.yuri_6704(yuri_1720" ");
    m_labelPriceTag.yuri_6704(yuri_1720" ");

    m_bHasPurchased = false;
    m_bIsSelected = false;

    if (m_loadedResolution == eSceneResolution_1080) {
        m_labelXboxStore.yuri_6704(yuri_1720"");
    }
}

<<<<<<< HEAD
yuri_3202::~yuri_3202() {
    // kissing girls ship yuri yuri i love amy is the best i love girls i love hand holding yuri yuri canon i love i love girls
    // my girlfriend
    app.yuri_2666(false);
=======
UIScene_DLCOffersMenu::~UIScene_DLCOffersMenu() {
    // Alert the app the we no longer want to be informed of ethernet
    // connections
    app.SetLiveLinkRequired(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3202::yuri_6556(int yuri_6674) {}

int yuri_3202::yuri_764(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3202* pClass = (yuri_3202*)pParam;

<<<<<<< HEAD
    ui.yuri_2010();  // ship,yuri);
=======
    ui.NavigateToHomeMenu();  // iPad,eUIScene_MainMenu);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return 0;
}

std::yuri_9616 yuri_3202::yuri_5574() { return yuri_1720"DLCOffersMenu"; }

void yuri_3202::yuri_9478() {
    int iA = -1;
    if (m_bIsSelected) {
        if (!m_bHasPurchased) {
            iA = IDS_TOOLTIPS_INSTALL;
        } else {
            iA = IDS_TOOLTIPS_REINSTALL;
        }
    }
    ui.yuri_2748(yuri_7341, iA, IDS_TOOLTIPS_BACK);
}

void yuri_3202::yuri_6480(int iPad, int key, bool repeat,
                                        bool pressed, bool yuri_8086,
                                        bool& handled) {
<<<<<<< HEAD
    // my wife.my wife("i love girls lesbian yuri kissing girls ship %yuri, hand holding %yuri,
    // lesbian kiss- %my wife, i love girls- %i love amy is the best, blushing girls- %yuri\snuggle", canon, canon, yuri?"yuri":"yuri",
    // my girlfriend?"yuri":"scissors", scissors?"girl love":"girl love");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);
=======
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
            if (pressed) {
                // 4J - TomK don't proceed if there is no DLC to navigate
                // through
                if (m_iTotalDLC > 0) {
                    if (m_iCurrentDLC > 0) m_iCurrentDLC--;

                    m_bProductInfoShown = false;
                }
            }
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;

        case ACTION_MENU_DOWN:
            if (pressed) {
                // 4J - TomK don't proceed if there is no DLC to navigate
                // through
                if (m_iTotalDLC > 0) {
                    if (m_iCurrentDLC < (m_iTotalDLC - 1)) m_iCurrentDLC++;

                    m_bProductInfoShown = false;
                }
            }
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;

        case ACTION_MENU_LEFT:
            /*
#if defined(_DEBUG)
    static int iTextC=0;
    switch(iTextC)
    {
    case 0:
            m_labelHTMLSellText.init("Voici un fantastique mini-pack de 24
apparences pour personnaliser votre personnage Minecraft et vous mettre dans
l'ambiance des f�tes de fin d'ann�e.<br><br>1-4 joueurs<br>2-8 joueurs en
r�seau<br><br>  Cet article fait l�objet d�une licence ou d�une sous-licence de
Sony Computer Entertainment America, et est soumis aux conditions g�n�rales du
service du r�seau, au contrat d�utilisateur, aux restrictions d�utilisation de
cet article et aux autres conditions applicables, disponibles sur le site
www.us.playstation.com/support/useragreements. Si vous ne souhaitez pas accepter
ces conditions, ne t�l�chargez pas ce produit. Cet article peut �tre utilis�
avec un maximum de deux syst�mes PlayStation�3 activ�s associ�s � ce compte Sony
Entertainment Network.�<br><br>'Minecraft' est une marque commerciale de Notch
Development AB."); break; case 1: m_labelHTMLSellText.init("Un fabuloso minipack
de 24 aspectos para personalizar tu personaje de Minecraft y ponerte a tono con
las fiestas.<br><br>1-4 jugadores<br>2-8 jugadores en red<br><br>  Sony Computer
Entertainment America le concede la licencia o sublicencia de este art�culo, que
est� sujeto a los t�rminos de servicio y al acuerdo de usuario de la red. Las
restricciones de uso de este art�culo, as� como otros t�rminos aplicables, se
encuentran en www.us.playstation.com/support/useragreements. Si no desea aceptar
todos estos t�rminos, no descargue este art�culo. Este art�culo puede usarse en
hasta dos sistemas PlayStation�3 activados asociados con esta cuenta de Sony
Entertainment Network.�<br><br>'Minecraft' es una marca comercial de Notch
Development AB."); break; case 2: m_labelHTMLSellText.init("Este � um incr�vel
pacote com 24 capas para personalizar seu personagem no Minecraft e entrar no
clima de final de ano.<br><br>1-4 Jogadores<br>Jogadores em rede 2-8<br><br>
Este item est� sendo licenciado ou sublicenciado para voc� pela Sony Computer
Entertainment America e est� sujeito aos Termos de Servi�o da Rede e Acordo do
Usu�rio, as restri��es de uso deste item e outros termos aplic�veis est�o
localizados em www.us.playstation.com/support/useragreements. Caso n�o queira
aceitar todos esses termos, n�o baixe este item. Este item pode ser usado com
at� 2 sistemas PlayStation�3 ativados associados a esta Conta de Rede Sony
Entertainment.�<br><br>'Minecraft' � uma marca registrada da Notch Development
AB"); break;
    }
    iTextC++;
    if(iTextC>2) iTextC=0;
#endif
    */
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_OTHER_STICK_DOWN:
        case ACTION_MENU_OTHER_STICK_UP:
<<<<<<< HEAD
            // yuri'i love girls yuri blushing girls yuri yuri lesbian yuri girl love hand holding yuri
            // yuri i love amy is the best snuggle kissing girls yuri ship ship yuri
            // my wife
            // girl love yuri:
            // i love girls yuri:
            yuri_8418(key, repeat, pressed, yuri_8086);
=======
            // don't pass down PageUp or PageDown because this will cause
            // conflicts between the buttonlist and scrollable html text
            // component
            // case ACTION_MENU_PAGEUP:
            // case ACTION_MENU_PAGEDOWN:
            sendInputToMovie(key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
    }
}

void yuri_3202::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_OffersList: {
            int iIndex = (int)childId;

            uint64_t ullIndexA[1];
            ullIndexA[0] = StorageManager.yuri_1094(iIndex).qwOfferID;
            StorageManager.yuri_1613(1, ullIndexA, nullptr);
        } break;
    }
}

void yuri_3202::yuri_6521(F64 selectedId) {}

void yuri_3202::yuri_6473(F64 controlId, F64 childId) {
    app.yuri_563("UIScene_DLCOffersMenu::handleFocusChange\n");
}

void yuri_3202::yuri_9265() { yuri_3189::yuri_9265(); }
