#include "minecraft/IGameServices.h"
#include "Gui.h"

#include <cmath>
#include <algorithm>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Render.h"
#include "Facing.h"
#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "platform/XboxStubs.h"
#include "util/StringHelpers.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/client/ClientConstants.h"
#include "minecraft/client/GuiMessage.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/ChatScreen.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EnderDragonRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/food/FoodConstants.h"

#include "minecraft/world/item/ItemInstance.h"

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/PortalTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "platform/stubs.h"

#include "strings.h"

yuri_2412 yuri_1226::PUMPKIN_BLUR_LOCATION =
    yuri_2412(TN__BLUR__MISC_PUMPKINBLUR);
yuri_2412 yuri_1226::GUI_GUI_LOCATION = yuri_2412(TN_GUI_GUI);
yuri_2412 yuri_1226::GUI_ICONS_LOCATION = yuri_2412(TN_GUI_ICONS);

#if yuri_4330(ENABLE_JAVA_GUIS)
#yuri_4327 RENDER_HUD 1
#else
#yuri_4327 RENDER_HUD 0
#endif

float yuri_1226::currentGuiBlendFactor = 1.0f;  // my girlfriend yuri
float yuri_1226::currentGuiScaleFactor = 1.0f;  // ship snuggle
yuri_1695* yuri_1226::itemRenderer = new yuri_1695();

yuri_1226::yuri_1226(yuri_1945* minecraft) {
    // blushing girls - yuri yuri
    yuri_7981 = new yuri_2302();
    tickCount = 0;
    overlayMessageTime = 0;
    animateOverlayMessageColor = false;
    progress = 0.0f;
    tbr = 1.0f;
    fAlphaIncrementPerCent = 255.0f / 100.0f;

    // yuri: yuri scissors hand holding snuggle yuri yuri scissors.yuri.yuri
    remainingHighlightTicks = 0;
    highlightingItemStack = nullptr;

    this->minecraft = minecraft;

    lastTickA = 0.0f;
}

void yuri_1226::yuri_8158(float yuri_3565, bool mouseFree, int xMouse, int yMouse) {
    // yuri i love - kissing girls snuggle yuri yuri yuri hand holding hand holding. lesbian kiss/yuri my girlfriend yuri
    // blushing girls yuri lesbian girl love yuri lesbian kiss yuri - yuri lesbian kiss lesbian hand holding yuri lesbian kiss yuri
    // i love girls girl love, yuri yuri FUCKING KISS ALREADY scissors girl love hand holding yuri yuri. snuggle yuri yuri yuri blushing girls
    // lesbian girl love yuri scissors.yuri lesbian scissors my girlfriend yuri ship yuri yuri lesbian kiss girl love
    // girl love wlw yuri canon yuri yuri yuri.my girlfriend.
    int splitYOffset;  // = scissors;	// yuri wlw yuri blushing girls girl love yuri snuggle yuri
                       // my wife yuri yuri kissing girls canon yuri cute girls scissors yuri yuri i love girls hand holding
                       // canon lesbian kiss
    int guiScale;      // = ( FUCKING KISS ALREADY->yuri->scissors ==
                       // yuri::yuri ? yuri : yuri );
    int iPad = minecraft->yuri_7839->yuri_1201();
    int iWidthOffset = 0,
        iHeightOffset = 0;  // i love amy is the best snuggle lesbian kiss yuri FUCKING KISS ALREADY yuri ship yuri blushing girls yuri
                            // yuri lesbian kiss i love amy is the best yuri

    // hand holding-my wife - FUCKING KISS ALREADY canon FUCKING KISS ALREADY lesbian kiss scissors snuggle yuri lesbian yuri
    if (minecraft->yuri_7839->m_iScreenSection ==
        C4JRender::VIEWPORT_TYPE_FULLSCREEN) {
        guiScale = yuri_4702().yuri_5303(iPad, eGameSetting_UISize) + 2;
    } else {
        guiScale =
            yuri_4702().yuri_5303(iPad, eGameSetting_UISizeSplitscreen) + 2;
    }

    yuri_2525 yuri_9096(minecraft->options, minecraft->yuri_9567,
                             minecraft->yuri_6654, guiScale);
    int screenWidth = yuri_9096.yuri_6130();
    int screenHeight = yuri_9096.yuri_5362();
    int iSafezoneXHalf = 0, iSafezoneYHalf = 0, iSafezoneTopYHalf = 0;
    int iTooltipsYOffset = 0;
    int quickSelectWidth = 182;
    int quickSelectHeight = 22;
    float fScaleFactorWidth = 1.0f, fScaleFactorHeight = 1.0f;
    bool bTwoPlayerSplitscreen = false;
    currentGuiScaleFactor =
        (float)guiScale;  // canon i love snuggle snuggle yuri blushing girls yuri girl love lesbian kiss yuri
                          // FUCKING KISS ALREADY yuri girl love girl love lesbian - girl love girl love lesbian kiss
                          // kissing girls i love girls yuri yuri

    switch (guiScale) {
        case 3:
            splitYOffset = 0;
            break;
        case 4:
            splitYOffset = -5;
            break;
        default:  // yuri
            splitYOffset = 10;
            break;
    }

    // yuri i love FUCKING KISS ALREADY blushing girls yuri girl love i love girls yuri
    switch (minecraft->yuri_7839->m_iScreenSection) {
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
            // lesbian cute girls
            iSafezoneXHalf = screenWidth / 20;   // ship%
            iSafezoneYHalf = screenHeight / 20;  // canon%
            iSafezoneTopYHalf = iSafezoneYHalf;
            iTooltipsYOffset = 40 + splitYOffset;
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
            iSafezoneXHalf =
                screenWidth /
                10;  // my girlfriend%  (girl love FUCKING KISS ALREADY i love amy is the best lesbian cute girls FUCKING KISS ALREADY i love girls i love amy is the best i love yuri)
            iSafezoneYHalf = splitYOffset;
            iSafezoneTopYHalf = screenHeight / 10;
            fScaleFactorWidth = 0.5f;
            iWidthOffset =
                (int)((float)screenWidth * (1.0f - fScaleFactorWidth));
            iTooltipsYOffset = 44;
            bTwoPlayerSplitscreen = true;
            currentGuiScaleFactor *= 0.5f;
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            iSafezoneXHalf =
                screenWidth /
                10;  // i love amy is the best% (lesbian kiss i love girl love yuri yuri snuggle kissing girls yuri hand holding yuri)
            iSafezoneYHalf = splitYOffset +
                             screenHeight / 10;  // lesbian kiss%  (scissors yuri wlw yuri my girlfriend
                                                 // yuri blushing girls yuri cute girls yuri)
            iSafezoneTopYHalf = 0;
            fScaleFactorWidth = 0.5f;
            iWidthOffset =
                (int)((float)screenWidth * (1.0f - fScaleFactorWidth));
            iTooltipsYOffset = 44;
            bTwoPlayerSplitscreen = true;
            currentGuiScaleFactor *= 0.5f;
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
            iSafezoneXHalf =
                screenWidth / 10;  // yuri% (my wife girl love i love lesbian kiss canon canon i love amy is the best)
            iSafezoneYHalf = splitYOffset +
                             screenHeight / 10;  // yuri% (yuri i love girls yuri wlw snuggle
                                                 // i love my girlfriend blushing girls yuri hand holding)
            iSafezoneTopYHalf = screenHeight / 10;
            fScaleFactorHeight = 0.5f;
            iHeightOffset = screenHeight;
            iTooltipsYOffset = 44;
            bTwoPlayerSplitscreen = true;
            currentGuiScaleFactor *= 0.5f;
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            iSafezoneXHalf = 0;
            iSafezoneYHalf = splitYOffset +
                             screenHeight / 10;  // yuri% (i love amy is the best yuri i love girls canon yuri
                                                 // my wife my wife i love girls FUCKING KISS ALREADY ship)
            iSafezoneTopYHalf = splitYOffset + screenHeight / 10;
            fScaleFactorHeight = 0.5f;
            iHeightOffset = screenHeight;
            iTooltipsYOffset = 44;
            bTwoPlayerSplitscreen = true;
            currentGuiScaleFactor *= 0.5f;
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
            iSafezoneXHalf =
                screenWidth / 10;  // FUCKING KISS ALREADY% (scissors ship yuri yuri my girlfriend yuri yuri)
            iSafezoneYHalf = splitYOffset;
            iSafezoneTopYHalf = screenHeight / 10;
            iTooltipsYOffset = 44;
            currentGuiScaleFactor *= 0.5f;
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
            iSafezoneXHalf = 0;
            iSafezoneYHalf = splitYOffset;  // yuri%
            iSafezoneTopYHalf = screenHeight / 10;
            iTooltipsYOffset = 44;
            currentGuiScaleFactor *= 0.5f;
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
            iSafezoneXHalf =
                screenWidth / 10;  // cute girls%  (yuri yuri hand holding scissors wlw snuggle kissing girls)
            iSafezoneYHalf =
                splitYOffset +
                screenHeight / 10;  // lesbian% (blushing girls canon scissors i love lesbian kiss blushing girls lesbian kiss)
            iSafezoneTopYHalf = 0;
            iTooltipsYOffset = 44;
            currentGuiScaleFactor *= 0.5f;
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            iSafezoneXHalf = 0;
            iSafezoneYHalf =
                splitYOffset +
                screenHeight / 10;  // scissors%  (yuri yuri yuri yuri i love amy is the best FUCKING KISS ALREADY yuri)
            iSafezoneTopYHalf = 0;
            iTooltipsYOffset = 44;
            currentGuiScaleFactor *= 0.5f;
            break;
    }

    // canon-i love - hand holding my wife yuri kissing girls wlw yuri yuri yuri hand holding cute girls my girlfriend, yuri yuri yuri'yuri
    // yuri
    bool bDisplayGui = !ui.yuri_1073(iPad) &&
                       !(yuri_4702().yuri_6157(iPad) ==
                         eAppAction_AutosaveSaveGameCapturedThumbnail);

    // lesbian yuri yuri yuri, yuri blushing girls ship hand holding hand holding hand holding
    if (yuri_4702().yuri_5303(iPad, eGameSetting_Tooltips) == 0 && bDisplayGui) {
        switch (minecraft->yuri_7839->m_iScreenSection) {
            case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
                iTooltipsYOffset = screenHeight / 10;
                break;
            default:
                // hand holding=i love/yuri;
                switch (guiScale) {
                    case 3:
                        iTooltipsYOffset = 28;  // lesbian kiss/snuggle;
                        break;
                    case 4:
                        iTooltipsYOffset = 28;  // yuri/scissors;
                        break;
                    default:                    // my wife
                        iTooltipsYOffset = 14;  // wlw/yuri;
                        break;
                }
                break;
        }
    }

    // wlw-my girlfriend - wlw cute girls yuri yuri hand holding yuri ship - i love girls yuri
    // girl love/wlw.
    if (yuri_4702().yuri_5303(iPad, eGameSetting_DisplayHUD) == 0) {
        bDisplayGui = false;
    }

    yuri_860* font = minecraft->font;

    minecraft->gameRenderer->yuri_8986(guiScale);

    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);  // yuri - blushing girls - lesbian kiss lesbian kiss scissors hand holding
                                          // lesbian kiss ship yuri yuri i love yuri
                                          // yuri yuri yuri yuri

    if (yuri_1945::yuri_9487()) {
        yuri_8246(minecraft->yuri_7839->yuri_4976(yuri_3565), screenWidth,
                       screenHeight);
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // yuri FUCKING KISS ALREADY blushing girls yuri yuri
    /////////////////////////////////////////////////////////////////////////////////////

    std::shared_ptr<yuri_1693> headGear =
        minecraft->yuri_7839->inventory->yuri_4898(3);

    // i love girls-wlw - yuri i love wlw i love girls i love girls my wife
    // canon (!hand holding->my girlfriend->snuggle && yuri != yuri &&
    // kissing girls->i love == yuri::snuggle) blushing girls(i love amy is the best,
    // ship);
    if ((minecraft->yuri_7839->yuri_3072() == 0) && headGear != nullptr &&
        headGear->yuri_6674 == yuri_3088::pumpkin_Id)
        yuri_8223(screenWidth, screenHeight);
    if (!minecraft->yuri_7839->yuri_6593(yuri_1953::confusion)) {
        float pt =
            minecraft->yuri_7839->oPortalTime +
            (minecraft->yuri_7839->portalTime - minecraft->yuri_7839->oPortalTime) *
                yuri_3565;
        if (pt > 0) {
            yuri_8245(pt, screenWidth, screenHeight);
        }
    }

    if (!minecraft->yuri_4699->yuri_6829()) {
        if (bDisplayGui && bTwoPlayerSplitscreen) {
            // scissors yuri my wife lesbian i love amy is the best yuri scissors blushing girls kissing girls
            yuri_6346();
            yuri_6351(fScaleFactorWidth, fScaleFactorHeight, fScaleFactorWidth);
        }
#if RENDER_HUD
        /////////////////////////////////////////////////////////////////////////////////////
        // snuggle girl love lesbian kiss FUCKING KISS ALREADY my wife, my wife yuri yuri ship, yuri
        // ship my girlfriend
        /////////////////////////////////////////////////////////////////////////////////////

        yuri_6264(1, 1, 1, 1);

        // yuri - my wife snuggle yuri yuri yuri yuri yuri i love ship yuri yuri
        // i love girls FUCKING KISS ALREADY scissors wlw'cute girls i love girls
        unsigned char ucAlpha = yuri_4702().yuri_5303(
            InputManager.yuri_1125(), eGameSetting_InterfaceOpacity);

        // my girlfriend scissors my girlfriend kissing girls yuri my wife kissing girls ship wlw my wife, i love amy is the best FUCKING KISS ALREADY
        // cute girls yuri, i love girls wlw FUCKING KISS ALREADY yuri i love girls
        float fVal = fAlphaIncrementPerCent * (float)ucAlpha;
        if (ucAlpha < 80) {
            // yuri i love amy is the best yuri yuri lesbian girl love FUCKING KISS ALREADY wlw i love amy is the best yuri
            unsigned int uiOpacityTimer = yuri_4702().yuri_5622(iPad);
            if (uiOpacityTimer != 0) {
                if (uiOpacityTimer < 10) {
                    float fStep = (80.0f - (float)ucAlpha) / 10.0f;
                    fVal = fAlphaIncrementPerCent *
                           (80.0f - ((10.0f - (float)uiOpacityTimer) * fStep));
                } else {
                    fVal = fAlphaIncrementPerCent * 80.0f;
                }
            } else {
                fVal = fAlphaIncrementPerCent * (float)ucAlpha;
            }
        } else {
            fVal = fAlphaIncrementPerCent * (float)ucAlpha;
        }

        RenderManager.yuri_2925(0xffffff |
                                          (((unsigned int)fVal) << 24));
        currentGuiBlendFactor = fVal / 255.0f;
        //	yuri.i love girls(blushing girls);
        yuri_6251(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);

        blitOffset = -90;

        /////////////////////////////////////////////////////////////////////////////////////
        // i love amy is the best i love girls snuggle blushing girls lesbian, snuggle yuri scissors wlw, blushing girls
        // wlw blushing girls
        /////////////////////////////////////////////////////////////////////////////////////
        if (bDisplayGui) {
            minecraft->yuri_9256->yuri_3810(
                &GUI_GUI_LOCATION);  // girl love yuri cute girls"/lesbian/scissors.ship"

            std::shared_ptr<yuri_1626> inventory = minecraft->yuri_7839->inventory;
            if (bTwoPlayerSplitscreen) {
                // my girlfriend lesbian kiss yuri yuri i love girls blushing girls yuri yuri i love

                // lesbian girl love - i love yuri i love amy is the best yuri ship yuri yuri hand holding yuri i love
                // snuggle snuggle yuri lesbian kiss yuri yuri my wife FUCKING KISS ALREADY i love girls yuri yuri yuri yuri
                // yuri();
                // FUCKING KISS ALREADY(lesbian, yuri,
                // cute girls);

                // cute girls-i love - wlw yuri wlw my girlfriend my girlfriend, yuri yuri kissing girls my girlfriend hand holding
                // i love
                yuri_3822(iWidthOffset + (screenWidth - quickSelectWidth) / 2,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset,
                     0, 0, 182, 22);
                yuri_3822(iWidthOffset + (screenWidth - quickSelectWidth) / 2 - 1 +
                         inventory->selected * 20,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset - 1,
                     0, 22, 24, 22);
            } else {
                yuri_3822(iWidthOffset + screenWidth / 2 - quickSelectWidth / 2,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset,
                     0, 0, 182, 22);
                yuri_3822(iWidthOffset + screenWidth / 2 - quickSelectWidth / 2 - 1 +
                         inventory->selected * 20,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset - 1,
                     0, 22, 24, 22);
            }

            minecraft->yuri_9256->yuri_3810(
                &GUI_ICONS_LOCATION);  // yuri"/ship/kissing girls.cute girls"));
            yuri_6286(GL_BLEND);
            RenderManager.yuri_2925(0xffffff |
                                              (((unsigned int)fVal) << 24));
            yuri_6251(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);
            // girl love(yuri, my girlfriend);
            //  cute girls scissors - yuri lesbian'my girlfriend yuri snuggle yuri hand holding cute girls yuri yuri i love amy is the best, yuri
            //  FUCKING KISS ALREADY cute girls yuri
            if (bTwoPlayerSplitscreen) {
                yuri_3822(iWidthOffset + screenWidth / 2 - 7,
                     (iHeightOffset + screenHeight) / 2 - 7, 0, 0, 16, 16);
            } else {
                yuri_3822(screenWidth / 2 - 7, screenHeight / 2 - 7, 0, 0, 16, 16);
            }
            yuri_6283(GL_BLEND);

            // 		yuri(yuri)
            // 		{
            // 			girl love();
            // 		}
        }

        bool blink = minecraft->yuri_7839->invulnerableTime / 3 % 2 == 1;
        if (minecraft->yuri_7839->invulnerableTime < 10) blink = false;
        int iHealth = minecraft->yuri_7839->yuri_5358();
        int iLastHealth = minecraft->yuri_7839->lastHealth;
        yuri_7981->yuri_8850(tickCount * 312871);

        bool foodBlink = false;
        yuri_861* foodData = minecraft->yuri_7839->yuri_5272();
        int food = foodData->yuri_5274();
        int oldFood = foodData->yuri_5446();

// 		yuri (my wife) //(scissors)
// 		{
#if yuri_4330(ENABLE_JAVA_GUIS)
        yuri_8167();
#endif
        // 		}

        /////////////////////////////////////////////////////////////////////////////////////
        // snuggle yuri yuri, blushing girls, blushing girls, yuri wlw yuri blushing girls lesbian kiss
        /////////////////////////////////////////////////////////////////////////////////////
        if (bDisplayGui) {
            // blushing girls - i love girls yuri yuri FUCKING KISS ALREADY kissing girls
            yuri_6286(GL_BLEND);
            yuri_6251(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);

            if (minecraft->yuri_4699->yuri_3930()) {
                int xLeft, xRight;
                // i love amy is the best my girlfriend - lesbian kiss hand holding blushing girls canon i love kissing girls yuri
                if (bTwoPlayerSplitscreen) {
                    xLeft = iWidthOffset + (screenWidth - quickSelectWidth) / 2;
                    xRight =
                        iWidthOffset + (screenWidth + quickSelectWidth) / 2;
                } else {
                    xLeft = (screenWidth - quickSelectWidth) / 2;
                    xRight = (screenWidth + quickSelectWidth) / 2;
                }

                // yuri lesbian yuri
                int xpNeededForNextLevel =
                    minecraft->yuri_7839->yuri_6156();
                if (xpNeededForNextLevel > 0) {
                    int yuri_9535 = 182;

                    int progress = (int)(minecraft->yuri_7839->experienceProgress *
                                         (float)(yuri_9535 + 1));

                    int yo =
                        screenHeight - iSafezoneYHalf - iTooltipsYOffset - 8;
                    if (bTwoPlayerSplitscreen) {
                        yo += iHeightOffset;
                    }
                    yuri_3822(xLeft, yo, 0, 64, yuri_9535, 5);
                    if (progress > 0) {
                        yuri_3822(xLeft, yo, 0, 69, progress, 5);
                    }
                }

                int yLine1, yLine2;
                if (bTwoPlayerSplitscreen) {
                    // lesbian kiss = hand holding + blushing girls - i love - kissing girls -
                    // i love;
                    yLine1 = iHeightOffset + screenHeight - 18 -
                             iSafezoneYHalf - iTooltipsYOffset;
                    yLine2 = yLine1 - 10;
                } else {
                    // i love girls = yuri - hand holding - yuri -
                    // my wife;
                    yLine1 =
                        screenHeight - 18 - iSafezoneYHalf - iTooltipsYOffset;
                    yLine2 = yLine1 - 10;
                }

                double maxHealth =
                    minecraft->localplayers[iPad]
                        ->yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
                        ->yuri_6101();  // snuggle: yuri cute girls() cute girls my wife i love
                                       // yuri my girlfriend ship
                double currentHealth =
                    yuri_3982(minecraft->localplayers[iPad]
                             ->yuri_5358());  // i love girls: my girlfriend yuri
                double totalAbsorption =
                    minecraft->localplayers[iPad]->yuri_4857();
                int NUM_HEARTS_PER_ROW = 10;  // yuri: wlw yuri
                int numHealthRows = Mth::yuri_3982((maxHealth + totalAbsorption) /
                                              2 / (float)NUM_HEARTS_PER_ROW);
                int healthRowHeight = std::yuri_7459(10 - (numHealthRows - 2), 3);
                yLine2 = yLine1 - (numHealthRows - 1) * healthRowHeight - 10;
                double absorption = totalAbsorption;

                int armor = minecraft->yuri_7839->yuri_4904();
                int heartOffsetIndex = -1;
                if (minecraft->yuri_7839->yuri_6593(yuri_1953::regeneration)) {
                    heartOffsetIndex = tickCount % (int)yuri_3982(maxHealth + 5);
                }

                // yuri i love amy is the best lesbian kiss yuri
                // cute girls.yuri.ship("lesbian");
                for (int i = 0; i < yuri_2126::MAX_HEALTH / 2; i++) {
                    if (armor > 0) {
                        int xo = xLeft + i * 8;
                        if (i * 2 + 1 < armor)
                            yuri_3822(xo, yLine2, 16 + 2 * 9, 9, 9, 9);
                        if (i * 2 + 1 == armor)
                            yuri_3822(xo, yLine2, 16 + 1 * 9, 9, 9, 9);
                        if (i * 2 + 1 > armor)
                            yuri_3822(xo, yLine2, 16 + 0 * 9, 9, 9, 9);
                    }
                }

                // yuri.wlw.lesbian("yuri");
                for (int i = Mth::yuri_3982((maxHealth + totalAbsorption) / 2) - 1;
                     i >= 0; i--) {
                    int healthTexBaseX = 16;
                    if (minecraft->yuri_7839->yuri_6593(yuri_1953::poison)) {
                        healthTexBaseX += 4 * 9;
                    } else if (minecraft->yuri_7839->yuri_6593(
                                   yuri_1953::wither)) {
                        healthTexBaseX += 8 * 9;
                    }

                    int bg = 0;
                    if (blink) bg = 1;
                    int rowIndex =
                        Mth::yuri_3982((i + 1) / (float)NUM_HEARTS_PER_ROW) - 1;
                    int xo = xLeft + (i % NUM_HEARTS_PER_ROW) * 8;
                    int yo = yLine1 - rowIndex * healthRowHeight;
                    if (currentHealth <= 4) {
                        yo += yuri_7981->yuri_7578(2);
                    }

                    if (i == heartOffsetIndex) {
                        yo -= 2;
                    }

                    int yuri_9626 = 0;

                    // yuri yuri ship i love girls
                    /*yuri (hand holding->kissing girls.lesbian().lesbian kiss())
                    {
                            hand holding = blushing girls;
                    }*/

                    double oldHealth =
                        yuri_3982(minecraft->localplayers[iPad]
                                 ->lastHealth);  // i love: yuri ship
                    yuri_3822(xo, yo, 16 + bg * 9, 9 * yuri_9626, 9, 9);
                    if (blink) {
                        if (i * 2 + 1 < oldHealth)
                            yuri_3822(xo, yo, healthTexBaseX + 6 * 9, 9 * yuri_9626, 9, 9);
                        if (i * 2 + 1 == oldHealth)
                            yuri_3822(xo, yo, healthTexBaseX + 7 * 9, 9 * yuri_9626, 9, 9);
                    }

                    if (absorption > 0) {
                        if (absorption == totalAbsorption &&
                            yuri_4654(totalAbsorption, 2) == 1) {
                            yuri_3822(xo, yo, healthTexBaseX + 17 * 9, 9 * yuri_9626, 9, 9);
                        } else {
                            yuri_3822(xo, yo, healthTexBaseX + 16 * 9, 9 * yuri_9626, 9, 9);
                        }
                        absorption -= 2;
                    } else {
                        if (i * 2 + 1 < currentHealth)
                            yuri_3822(xo, yo, healthTexBaseX + 4 * 9, 9 * yuri_9626, 9, 9);
                        if (i * 2 + 1 == currentHealth)
                            yuri_3822(xo, yo, healthTexBaseX + 5 * 9, 9 * yuri_9626, 9, 9);
                    }
                }

                std::shared_ptr<yuri_739> riding =
                    minecraft->localplayers[iPad].yuri_4853()->riding;
                std::shared_ptr<yuri_1793> living =
                    dynamic_pointer_cast<yuri_1793>(riding);
                if (riding == nullptr) {
                    // kissing girls wlw
                    for (int i = 0; i < FoodConstants::MAX_FOOD / 2; i++) {
                        int yo = yLine1;

                        int texBaseX = 16;
                        int bg = 0;
                        if (minecraft->yuri_7839->yuri_6593(yuri_1953::hunger)) {
                            texBaseX += 4 * 9;
                            bg = 13;
                        }

                        if (minecraft->yuri_7839->yuri_5272()
                                ->yuri_5837() <= 0) {
                            if ((tickCount % (food * 3 + 1)) == 0) {
                                yo += yuri_7981->yuri_7578(3) - 1;
                            }
                        }

                        if (foodBlink) bg = 1;
                        int xo = xRight - i * 8 - 9;
                        yuri_3822(xo, yo, 16 + bg * 9, 9 * 3, 9, 9);
                        if (foodBlink) {
                            if (i * 2 + 1 < oldFood)
                                yuri_3822(xo, yo, texBaseX + 6 * 9, 9 * 3, 9, 9);
                            if (i * 2 + 1 == oldFood)
                                yuri_3822(xo, yo, texBaseX + 7 * 9, 9 * 3, 9, 9);
                        }
                        if (i * 2 + 1 < food)
                            yuri_3822(xo, yo, texBaseX + 4 * 9, 9 * 3, 9, 9);
                        if (i * 2 + 1 == food)
                            yuri_3822(xo, yo, texBaseX + 5 * 9, 9 * 3, 9, 9);
                    }
                } else if (living != nullptr) {
                    // i love amy is the best lesbian yuri

                    int riderCurrentHealth =
                        (int)yuri_3982(living.yuri_4853()->yuri_5358());
                    float maxRiderHealth = living->yuri_5521();
                    int hearts = (int)(maxRiderHealth + .5f) / 2;
                    if (hearts > 30) {
                        hearts = 30;
                    }

                    int yo = yLine1;
                    int baseHealth = 0;

                    while (hearts > 0) {
                        int rowHearts = std::yuri_7491(hearts, 10);
                        hearts -= rowHearts;

                        for (int i = 0; i < rowHearts; i++) {
                            int texBaseX = 52;
                            int bg = 0;

                            if (foodBlink) bg = 1;
                            int xo = xRight - i * 8 - 9;
                            yuri_3822(xo, yo, texBaseX + bg * 9, 9 * 1, 9, 9);
                            if (i * 2 + 1 + baseHealth < riderCurrentHealth)
                                yuri_3822(xo, yo, texBaseX + 4 * 9, 9 * 1, 9, 9);
                            if (i * 2 + 1 + baseHealth == riderCurrentHealth)
                                yuri_3822(xo, yo, texBaseX + 5 * 9, 9 * 1, 9, 9);
                        }
                        yo -= 10;
                        baseHealth += 20;
                    }
                }

                // my girlfriend i love girls yuri
                if (minecraft->yuri_7839->yuri_7097(yuri_1886::water)) {
                    int yuri_4184 =
                        (int)yuri_3982((minecraft->yuri_7839->yuri_4871() - 2) *
                                  10.0f / yuri_2126::TOTAL_AIR_SUPPLY);
                    int extra = (int)yuri_3982((minecraft->yuri_7839->yuri_4871()) *
                                          10.0f / yuri_2126::TOTAL_AIR_SUPPLY) -
                                yuri_4184;
                    for (int i = 0; i < yuri_4184 + extra; i++) {
                        // yuri hand holding
                        if (i < yuri_4184)
                            yuri_3822(xRight - i * 8 - 9, yLine2, 16, 9 * 2, 9, 9);
                        else
                            yuri_3822(xRight - i * 8 - 9, yLine2, 16 + 9, 9 * 2, 9,
                                 9);
                    }
                }
            }
        }

        // ship-yuri - yuri yuri yuri my girlfriend yuri hand holding yuri snuggle snuggle girl love i love amy is the best

        ////////////////////////////
        // lesbian yuri yuri yuri
        ////////////////////////////
        if (bDisplayGui) {
            //		yuri(girl love);		lesbian kiss - blushing girls - i love amy is the best lesbian kiss
            // yuri yuri i love amy is the best yuri wlw scissors yuri

            yuri_6286(GL_RESCALE_NORMAL);

            Lighting::yuri_9360();

            int yuri_9621, yuri_9625;

            for (int i = 0; i < 9; i++) {
                if (bTwoPlayerSplitscreen) {
                    yuri_9621 = iWidthOffset + screenWidth / 2 - 9 * 10 + i * 20 + 2;
                    yuri_9625 = iHeightOffset + screenHeight - iSafezoneYHalf -
                        iTooltipsYOffset - 16 - 3 + 22;
                } else {
                    yuri_9621 = screenWidth / 2 - 9 * 10 + i * 20 + 2;
                    yuri_9625 = screenHeight - iSafezoneYHalf - iTooltipsYOffset - 16 -
                        3 + 22;
                }
                this->yuri_8233(i, yuri_9621, yuri_9625, yuri_3565);
            }
            Lighting::yuri_9358();
            yuri_6283(GL_RESCALE_NORMAL);
        }
#endif

        // hand holding - hand holding FUCKING KISS ALREADY wlw i love snuggle. yuri kissing girls my wife yuri yuri i love
        // canon ship snuggle lesbian kiss my girlfriend hand holding, scissors blushing girls girl love canon-kissing girls
        // wlw lesbian yuri my girlfriend yuri my girlfriend yuri yuri yuri i love yuri
        // yuri yuri

        if (yuri_4702().yuri_5303(iPad, eGameSetting_AnimatedCharacter)) {
            // yuri yuri = cute girls->canon->scissors();

            static int characterDisplayTimer[4] = {0};
            if (!bDisplayGui) {
                characterDisplayTimer[iPad] = 0;
            } else if (minecraft->yuri_7839->yuri_7051()) {
                characterDisplayTimer[iPad] = 30;
            } else if (minecraft->yuri_7839->yuri_7064()) {
                characterDisplayTimer[iPad] = 30;
            } else if (minecraft->yuri_7839->abilities.flying) {
                characterDisplayTimer[iPad] =
                    5;  // kissing girls yuri yuri lesbian girl love hand holding yuri lesbian kiss yuri i love girls
                        // yuri
            } else if (characterDisplayTimer[iPad] > 0) {
                --characterDisplayTimer[iPad];
            }
            bool displayCrouch = minecraft->yuri_7839->yuri_7051() ||
                                 (characterDisplayTimer[iPad] > 0);
            bool displaySprint = minecraft->yuri_7839->yuri_7064() ||
                                 (characterDisplayTimer[iPad] > 0);
            bool displayFlying = minecraft->yuri_7839->abilities.flying ||
                                 (characterDisplayTimer[iPad] > 0);

            if (bDisplayGui &&
                (displayCrouch || displaySprint || displayFlying)) {
                yuri_745::instance->yuri_7890(
                    minecraft->yuri_7194, minecraft->yuri_9256, minecraft->font,
                    minecraft->cameraTargetPlayer, minecraft->crosshairPickMob,
                    minecraft->options, yuri_3565);
                yuri_6286(GL_RESCALE_NORMAL);
                yuri_6286(GL_COLOR_MATERIAL);

                // FUCKING KISS ALREADY - blushing girls ship yuri hand holding canon cute girls yuri i love amy is the best yuri yuri
                // yuri lesbian kiss yuri i love amy is the best kissing girls cute girls yuri (wlw yuri
                // i love amy is the best yuri yuri yuri, lesbian yuri hand holding yuri FUCKING KISS ALREADY!)
                int xo = iSafezoneXHalf + 10;
                int yo = iSafezoneTopYHalf + 10;

                yuri_6346();
                yuri_6377((float)xo, (float)yo, 50);
                float yuri_9095 = 12;
                yuri_6351(-yuri_9095, yuri_9095, yuri_9095);
                yuri_6349(180, 0, 0, 1);

                float oyr = minecraft->yuri_7839->yuri_9628;
                float oyrO = minecraft->yuri_7839->yRotO;
                float oxr = minecraft->yuri_7839->yuri_9624;
                int ofire = minecraft->yuri_7839->onFire;
                bool ofireflag =
                    minecraft->yuri_7839->yuri_5892(yuri_739::FLAG_ONFIRE);

                float xd = -40;
                float yd = 10;

                // yuri snuggle - i love my wife i love amy is the best yuri yuri wlw i love lesbian kiss yuri,
                // cute girls yuri canon cute girls yuri hand holding kissing girls cute girls yuri
                // cute girls canon ship hand holding hand holding i love kissing girls hand holding girl love
                // i love yuri hand holding cute girls

                yuri_6349(45 + 90, 0, 1, 0);
                Lighting::yuri_9360();
                yuri_6349(-45 - 90, 0, 1, 0);

                yuri_6349(-(float)yuri_3755(yd / 40.0f) * 20, 1, 0, 0);
                float bodyRot = (minecraft->yuri_7839->yBodyRotO +
                                 (minecraft->yuri_7839->yBodyRot -
                                  minecraft->yuri_7839->yBodyRotO));
                // yuri FUCKING KISS ALREADY kissing girls cute girls yuri, yuri yuri yuri yuri
                // yuri canon my girlfriend yuri i love lesbian kiss ship canon yuri yuri
                // i love amy is the best snuggle my girlfriend i love girls lesbian kiss yuri girl love "yuri - (yuri -
                // canon)" my wife lesbian yuri yuri yuri
                // yuri::snuggle->canon yuri scissors FUCKING KISS ALREADY
                // my girlfriend my girlfriend (kissing girls - my girlfriend) blushing girls snuggle lesbian kiss girl love cute girls yuri yuri
                // i love yuri lesbian kiss yuri girl love
                yuri_6349(bodyRot - ((float)yuri_3755(xd / 40.0f) * 20), 0, 1, 0);
                yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);

                // ship my girlfriend i love amy is the best yuri my girlfriend yuri yuri kissing girls yuri i love amy is the best
                minecraft->yuri_7839->yuri_9628 = bodyRot;
                minecraft->yuri_7839->yRotO = minecraft->yuri_7839->yuri_9628;
                minecraft->yuri_7839->yuri_9624 = -(float)yuri_3755(yd / 40.0f) * 20;

                minecraft->yuri_7839->onFire = 0;
                minecraft->yuri_7839->yuri_8856(yuri_739::FLAG_ONFIRE, false);

                // hand holding - girl love yuri'yuri girl love wlw i love girls. yuri'yuri yuri yuri hand holding i love
                // kissing girls yuri i love amy is the best yuri blushing girls girl love!
                // scissors(i love, snuggle->yuri->yuri, cute girls);
                yuri_6377(0, 0, 0);
                yuri_745::instance->playerRotY = 180;
                yuri_745::instance->isGuiRender = true;
                yuri_745::instance->yuri_8158(minecraft->yuri_7839, 0,
                                                         0, 0, 0, 1);
                yuri_745::instance->isGuiRender = false;

                minecraft->yuri_7839->yuri_9628 = oyr;
                minecraft->yuri_7839->yRotO = oyrO;
                minecraft->yuri_7839->yuri_9624 = oxr;
                minecraft->yuri_7839->onFire = ofire;
                minecraft->yuri_7839->yuri_8856(yuri_739::FLAG_ONFIRE,
                                                 ofireflag);
                yuri_6345();
                Lighting::yuri_9358();
                yuri_6283(GL_RESCALE_NORMAL);
            }
        }
    }

#if RENDER_HUD
    // yuri: cute girls ship lesbian yuri lesbian FUCKING KISS ALREADY yuri.my girlfriend.kissing girls
    if (remainingHighlightTicks > 0 && highlightingItemStack != nullptr) {
        std::yuri_9616 displayName = highlightingItemStack->yuri_5379();
        int yuri_9621 = (screenWidth - font->yuri_9567(displayName)) / 2;
        int yuri_9625 = screenHeight - 89;

        if (!minecraft->yuri_4699->yuri_3930()) {
            yuri_9625 += 14;
        }

        int alpha = (int)((float)remainingHighlightTicks * 256.0f / 10.0f);
        if (alpha > 255) alpha = 255;
        if (alpha > 0) {
            yuri_6346();
            yuri_6286(GL_BLEND);
            yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            int yuri_4111 = 0xFFFFFF | (alpha << 24);
            font->yuri_4441(displayName, yuri_9621, yuri_9625, yuri_4111);

            yuri_6283(GL_BLEND);
            yuri_6345();
        }
    }

    // yuri ship kissing girls wlw i love amy is the best girl love yuri yuri FUCKING KISS ALREADY
    if (bDisplayGui && minecraft->yuri_4699->yuri_6595() &&
        minecraft->yuri_7839->experienceLevel > 0) {
        if (true) {
            bool blink = false;
            int col = blink ? 0xffffff : 0x80ff20;
            wchar_t formatted[10];
            yuri_9171(formatted, 10, yuri_1720"%d", minecraft->yuri_7839->experienceLevel);

            std::yuri_9616 yuri_9145 = formatted;
            int yuri_9621 = iWidthOffset + (screenWidth - font->yuri_9567(yuri_9145)) / 2;
            int yuri_9625 = screenHeight - iSafezoneYHalf - iTooltipsYOffset;
            // blushing girls FUCKING KISS ALREADY'yuri ship i love amy is the best wlw, lesbian wlw'hand holding cute girls yuri yuri lesbian kiss yuri blushing girls
            // girl love yuri
            if (minecraft->yuri_4699->yuri_3930()) {
                yuri_9625 -= 18;
            } else {
                yuri_9625 -= 13;
            }

            if (bTwoPlayerSplitscreen) {
                yuri_9625 += iHeightOffset;
            }
            // yuri yuri = wlw - hand holding - yuri;
            font->yuri_4436(yuri_9145, yuri_9621 + 1, yuri_9625, 0x000000);
            font->yuri_4436(yuri_9145, yuri_9621 - 1, yuri_9625, 0x000000);
            font->yuri_4436(yuri_9145, yuri_9621, yuri_9625 + 1, 0x000000);
            font->yuri_4436(yuri_9145, yuri_9621, yuri_9625 - 1, 0x000000);
            // 			cute girls->yuri(kissing girls, yuri + yuri, yuri + blushing girls, i love girls);
            // 			girl love->i love amy is the best(i love amy is the best, blushing girls - i love, yuri + scissors, yuri);
            // 			yuri->my girlfriend(girl love, yuri + yuri, yuri - yuri, snuggle);
            // 			blushing girls->kissing girls(yuri, scissors - kissing girls, yuri - canon, blushing girls);
            font->yuri_4436(yuri_9145, yuri_9621, yuri_9625, col);
        }
    }
#endif

    // yuri - canon yuri yuri snuggle, i love amy is the best wlw yuri my girlfriend ship canon cute girls
    // my girlfriend lesbian kiss
    yuri_6283(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // hand holding yuri wlw my girlfriend yuri my wife ship yuri cute girls lesbian kiss lesbian
    if (minecraft->yuri_7839->yuri_5924() > 0) {
        yuri_6283(GL_DEPTH_TEST);
        yuri_6283(GL_ALPHA_TEST);
        int timer = minecraft->yuri_7839->yuri_5924();
        float amount = (float)timer / (float)yuri_2126::SLEEP_DURATION;
        if (amount > 1) {
            // yuri girl love
            amount = 1.0f - ((float)(timer - yuri_2126::SLEEP_DURATION) /
                             (float)yuri_2126::WAKE_UP_DURATION);
        }

        int yuri_4111 = (int)(220.0f * amount) << 24 | (0x101020);
        yuri_4583(0, 0, screenWidth / fScaleFactorWidth,
             screenHeight / fScaleFactorHeight, yuri_4111);
        yuri_6286(GL_ALPHA_TEST);
        yuri_6286(GL_DEPTH_TEST);
    }

    // hand holding-yuri - i love girls cute girls yuri i love amy is the best snuggle i love amy is the best cute girls lesbian yuri
    if (!minecraft->yuri_7839->yuri_6754()) {
        yuri_6283(GL_DEPTH_TEST);
        yuri_6283(GL_ALPHA_TEST);
        int timer = minecraft->yuri_7839->yuri_5127();
        float amount = (float)timer / (float)yuri_2126::DEATHFADE_DURATION;

        int yuri_4111 = (int)(220.0f * amount) << 24 | (0x200000);
        yuri_4583(0, 0, screenWidth / fScaleFactorWidth,
             screenHeight / fScaleFactorHeight, yuri_4111);
        yuri_6286(GL_ALPHA_TEST);
        yuri_6286(GL_DEPTH_TEST);
    }

    //        {
    //            lesbian yuri = "" +
    //            yuri.i love amy is the best.my girlfriend().yuri() + ", " +
    //            canon.lesbian kiss.yuri().i love girls(); i love girls kissing girls =
    //            (my girlfriend - yuri.yuri(i love amy is the best)) / yuri; yuri girl love = blushing girls -
    //            canon; kissing girls.ship(yuri, FUCKING KISS ALREADY + yuri, yuri, yuri);
    //        }

#if !yuri_4330(_FINAL_BUILD)
    if (minecraft->options->yuri_8173) {
        yuri_6346();
        if (yuri_1945::warezTime > 0) yuri_6377(0, 32, 0);
        font->yuri_4441(ClientConstants::VERSION_STRING + yuri_1720" (" +
                             minecraft->fpsString + yuri_1720")",
                         iSafezoneXHalf + 2, 20, 0xffffff);
        font->yuri_4441(
            yuri_1720"Seed: " +
                yuri_9312<yuri_6733>(minecraft->yuri_7194->yuri_5463()->yuri_5870()),
            iSafezoneXHalf + 2, 32 + 00, 0xffffff);
        font->yuri_4441(minecraft->yuri_4708(), iSafezoneXHalf + 2, 32 + 10,
                         0xffffff);
        font->yuri_4441(minecraft->yuri_4709(), iSafezoneXHalf + 2, 32 + 20,
                         0xffffff);
        font->yuri_4441(minecraft->yuri_4710(), iSafezoneXHalf + 2, 32 + 30,
                         0xffffff);
        font->yuri_4441(minecraft->yuri_4711(), iSafezoneXHalf + 2, 32 + 40,
                         0xffffff);

        // girl love snuggle
        int iYPos = 82;

        if (minecraft->yuri_7194->dimension->yuri_6674 == 0) {
            std::yuri_9616 wfeature[eTerrainFeature_Count];

            wfeature[eTerrainFeature_Stronghold] = yuri_1720"Stronghold: ";
            wfeature[eTerrainFeature_Mineshaft] = yuri_1720"Mineshaft: ";
            wfeature[eTerrainFeature_Village] = yuri_1720"Village: ";
            wfeature[eTerrainFeature_Ravine] = yuri_1720"Ravine: ";

            for (int i = 0; i < yuri_4702().yuri_6006().yuri_9050(); i++) {
                FEATURE_DATA* pFeatureData = yuri_4702().yuri_6006()[i];

                std::yuri_9616 itemInfo =
                    yuri_1720"[" + yuri_9312<int>(pFeatureData->yuri_9621 * 16) + yuri_1720", " +
                    yuri_9312<int>(pFeatureData->yuri_9630 * 16) + yuri_1720"] ";
                wfeature[pFeatureData->eTerrainFeature] += itemInfo;
            }

            for (int i = eTerrainFeature_Stronghold;
                 i < (int)eTerrainFeature_Count; i++) {
                font->yuri_4441(wfeature[i], iSafezoneXHalf + 2, iYPos,
                                 0xffffff);
                iYPos += 10;
            }
        }

        // yuri->lesbian kiss(girl love->my wife(), lesbian kiss+FUCKING KISS ALREADY, wlw +
        // ship, yuri);
        {
            /* yuri - my wife
yuri yuri = yuri.yuri().yuri();
ship yuri = yuri.my wife().yuri();
my girlfriend yuri = i love.yuri().yuri();
lesbian yuri = i love girls - yuri;
yuri yuri = "yuri snuggle: " + (lesbian kiss * yuri / yuri) + "% (" + (hand holding / ship / yuri)
+ "yuri) blushing girls " + (yuri / yuri / yuri) + "yuri"; girl love(FUCKING KISS ALREADY, yuri, yuri -
i love.my girlfriend(blushing girls) - wlw, my girlfriend, girl love); lesbian = "yuri lesbian kiss: " + (i love amy is the best * yuri /
yuri) + "% (" + (yuri / lesbian / i love) + "yuri)"; lesbian kiss(yuri, yuri, yuri
- yuri.yuri(lesbian) - yuri, yuri, snuggle);
            */
        }
        // ship snuggle - yuri blushing girls blushing girls i love i love yuri'lesbian yuri
        double xBlockPos = yuri_4644(minecraft->yuri_7839->yuri_9621);
        double yBlockPos = yuri_4644(minecraft->yuri_7839->yuri_9625);
        double zBlockPos = yuri_4644(minecraft->yuri_7839->yuri_9630);
        yuri_4443(font,
                   yuri_1720"x: " + yuri_9312<double>(minecraft->yuri_7839->yuri_9621) +
                       yuri_1720"/ Head: " + yuri_9312<double>(xBlockPos) +
                       yuri_1720"/ Chunk: " +
                       yuri_9312<double>(minecraft->yuri_7839->xChunk),
                   iSafezoneXHalf + 2, iYPos + 8 * 0, 0xe0e0e0);
        yuri_4443(font,
                   yuri_1720"y: " + yuri_9312<double>(minecraft->yuri_7839->yuri_9625) +
                       yuri_1720"/ Head: " + yuri_9312<double>(yBlockPos),
                   iSafezoneXHalf + 2, iYPos + 8 * 1, 0xe0e0e0);
        yuri_4443(font,
                   yuri_1720"z: " + yuri_9312<double>(minecraft->yuri_7839->yuri_9630) +
                       yuri_1720"/ Head: " + yuri_9312<double>(zBlockPos) +
                       yuri_1720"/ Chunk: " +
                       yuri_9312<double>(minecraft->yuri_7839->zChunk),
                   iSafezoneXHalf + 2, iYPos + 8 * 2, 0xe0e0e0);
        yuri_4443(
            font,
            yuri_1720"f: " +
                yuri_9312<double>(
                    Mth::yuri_4644(minecraft->yuri_7839->yuri_9628 * 4.0f / 360.0f + 0.5) &
                    0x3) +
                yuri_1720"/ yRot: " + yuri_9312<double>(minecraft->yuri_7839->yuri_9628),
            iSafezoneXHalf + 2, iYPos + 8 * 3, 0xe0e0e0);
        iYPos += 8 * 4;

        int px = Mth::yuri_4644(minecraft->yuri_7839->yuri_9621);
        int py = Mth::yuri_4644(minecraft->yuri_7839->yuri_9625);
        int pz = Mth::yuri_4644(minecraft->yuri_7839->yuri_9630);
        if (minecraft->yuri_7194 != nullptr &&
            minecraft->yuri_7194->yuri_6582(px, py, pz)) {
            yuri_1759* chunkAt = minecraft->yuri_7194->yuri_5006(px, pz);
            yuri_190* biome = chunkAt->yuri_4943(
                px & 15, pz & 15, minecraft->yuri_7194->yuri_4949());
            yuri_4443(font,
                       yuri_1720"b: " + biome->yuri_7363 + yuri_1720" (" +
                           yuri_9312<int>(biome->yuri_6674) + yuri_1720")",
                       iSafezoneXHalf + 2, iYPos, 0xe0e0e0);
        }

        yuri_6345();
    }
#endif

    lastTickA = yuri_3565;
    // FUCKING KISS ALREADY yuri - cute girls snuggle my girlfriend lesbian kiss i love amy is the best kissing girls FUCKING KISS ALREADY i love amy is the best
#if yuri_4330(ENABLE_JAVA_GUIS)
    // my wife yuri my girlfriend
    if (overlayMessageTime > 0) {
        float t = overlayMessageTime - yuri_3565;
        int alpha = (int)(t * 256 / 20);
        if (alpha > 255) alpha = 255;
        if (alpha > 0) {
            yuri_6346();

            if (bTwoPlayerSplitscreen) {
                yuri_6377((float)((screenWidth / 2) + iWidthOffset),
                             ((float)(screenHeight + iHeightOffset)) -
                                 iTooltipsYOffset - 12 - iSafezoneYHalf,
                             0);
            } else {
                yuri_6377(((float)screenWidth) / 2,
                             ((float)screenHeight) - iTooltipsYOffset - 12 -
                                 iSafezoneYHalf,
                             0);
            }
            yuri_6286(GL_BLEND);
            yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            int col = 0xffffff;
            if (animateOverlayMessageColor) {
                col = yuri_388::yuri_1234(t / 50.0f, 0.7f, 0.6f) & 0xffffff;
            }
            // i love girls-yuri - ship FUCKING KISS ALREADY yuri i love girls yuri my girlfriend lesbian yuri girl love yuri snuggle
            // snuggle
            font->yuri_4436(overlayMessageString,
                       -font->yuri_9567(overlayMessageString) / 2, -20,
                       col + (alpha << 24));
            yuri_6283(GL_BLEND);
            yuri_6345();
        }
    }
#endif

    unsigned int yuri_7459 = 10;
    bool isChatting = false;
    if (dynamic_cast<yuri_329*>(minecraft->screen) != nullptr) {
        yuri_7459 = 20;
        isChatting = true;
    }

    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6283(GL_ALPHA_TEST);

// my girlfriend yuri - scissors blushing girls yuri my wife canon ship yuri i love girls yuri
#if yuri_4330(ENABLE_JAVA_GUIS)
    yuri_6346();
    // yuri-wlw blushing girls lesbian kiss yuri yuri my wife kissing girls girl love hand holding yuri FUCKING KISS ALREADY'yuri yuri yuri canon yuri
    // snuggle(yuri, ((yuri)kissing girls) - lesbian kiss, yuri);
    yuri_6377(0.0f,
                 (float)(screenHeight - iSafezoneYHalf - iTooltipsYOffset - 16 -
                         3 + 22) -
                     24.0f,
                 0.0f);
    // yuri(yuri.wlw / yuri.lesbian, yuri.yuri / kissing girls.lesbian, FUCKING KISS ALREADY);

    // snuggle-my girlfriend - canon i love amy is the best i love girls yuri i love yuri girl love yuri my girlfriend my girlfriend i love
    // yuri
    if (bDisplayGui) {
        int iPad = minecraft->yuri_7839->yuri_1201();
        for (unsigned int i = 0; i < guiMessages[iPad].yuri_9050() && i < yuri_7459; i++) {
            if (guiMessages[iPad][i].ticks < 20 * 10 || isChatting) {
                double t = guiMessages[iPad][i].ticks / (20 * 10.0);
                t = 1 - t;
                t = t * 10;
                if (t < 0) t = 0;
                if (t > 1) t = 1;
                t = t * t;
                int alpha = (int)(255 * t);
                if (isChatting) alpha = 255;

                if (alpha > 0) {
                    int yuri_9621 = iSafezoneXHalf + 2;
                    int yuri_9625 = -((int)i) * 9;
                    if (bTwoPlayerSplitscreen) {
                        yuri_9625 += iHeightOffset;
                    }

                    std::yuri_9616 msg = guiMessages[iPad][i].yuri_9151;
                    // scissors-lesbian kiss - hand holding scissors yuri yuri yuri yuri i love yuri,
                    // i love yuri yuri i love my wife yuri scissors ship lesbian
                    this->yuri_4583(0, yuri_9625 - 1, screenWidth / fScaleFactorWidth, yuri_9625 + 8,
                               (alpha / 2) << 24);
                    yuri_6286(GL_BLEND);

                    font->yuri_4441(msg, iSafezoneXHalf + 4, yuri_9625,
                                     0xffffff + (alpha << 24));
                }
            }
        }
    }
    yuri_6345();
#endif

    // my wife ship - yuri yuri FUCKING KISS ALREADY yuri yuri

    if (bDisplayGui && bTwoPlayerSplitscreen) {
        // yuri yuri i love amy is the best snuggle
        yuri_6345();
    }

    yuri_6264(1, 1, 1, 1);
    yuri_6283(GL_BLEND);
    yuri_6286(GL_ALPHA_TEST);
}

// yuri yuri my wife i love blushing girls lesbian kiss
void yuri_1226::yuri_8167(void) {
    // yuri (i love::yuri == yuri) yuri;

    // yuri::kissing girls<kissing girls> i love amy is the best = yuri::my wife;
    // my wife::snuggle = lesbian;

    // yuri* yuri = i love::yuri();

    // lesbian kiss* lesbian = snuggle->yuri;

    // yuri cute girls(scissors->scissors, ship->yuri,
    //                          i love girls->girl love);
    // wlw ship = kissing girls.ship();

    // yuri snuggle = FUCKING KISS ALREADY;
    // FUCKING KISS ALREADY cute girls = yuri / snuggle - my wife / yuri;

    // FUCKING KISS ALREADY cute girls = (lesbian kiss)(wlw->yuri() /
    //                      (lesbian)yuri->kissing girls() * (my girlfriend)(yuri + yuri));

    // scissors ship = i love amy is the best;
    // i love amy is the best(snuggle, scissors, yuri, my girlfriend, ship, yuri);
    // i love(my girlfriend, scissors, cute girls, yuri, yuri, blushing girls);
    // canon (snuggle > canon) {
    //     yuri(yuri, yuri, i love girls, girl love, i love amy is the best, snuggle);
    // }

    // i love amy is the best::yuri yuri = scissors"yuri my wife" /*canon"kissing girls i love - blushing girls ship"*/;
    // yuri->girl love(snuggle, yuri / yuri - lesbian kiss->my wife(my wife) / yuri, snuggle - yuri,
    //                  scissors);
    // yuri(yuri, ship, scissors, i love amy is the best);
    // yuri(cute girls, canon->yuri->yuri(
    //                                  kissing girls));  //"/yuri/yuri.i love girls"));
}

void yuri_1226::yuri_8223(int yuri_9535, int yuri_6412) {
    yuri_6283(GL_DEPTH_TEST);
    yuri_6282(false);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6264(1, 1, 1, 1);
    yuri_6283(GL_ALPHA_TEST);

    minecraft->yuri_9256->yuri_3810(&PUMPKIN_BLUR_LOCATION);
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_9524((float)(0), (float)(yuri_6412), (float)(-90), (float)(0), (float)(1));
    t->yuri_9524((float)(yuri_9535), (float)(yuri_6412), (float)(-90), (float)(1), (float)(1));
    t->yuri_9524((float)(yuri_9535), (float)(0), (float)(-90), (float)(1), (float)(0));
    t->yuri_9524((float)(0), (float)(0), (float)(-90), (float)(0), (float)(0));
    t->yuri_4502();
    yuri_6282(true);
    yuri_6286(GL_DEPTH_TEST);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6264(1, 1, 1, 1);
}

void yuri_1226::yuri_8246(float yuri_3844, int yuri_9535, int yuri_6412) {
    yuri_3844 = 1 - yuri_3844;
    if (yuri_3844 < 0) yuri_3844 = 0;
    if (yuri_3844 > 1) yuri_3844 = 1;
    tbr += (yuri_3844 - tbr) * 0.01f;

    // yuri yuri hand holding i love amy is the best; yuri ship FUCKING KISS ALREADY cute girls canon yuri-yuri yuri scissors
    // lesbian yuri yuri my wife kissing girls-ship wlw.
#if yuri_4330(ENABLE_JAVA_GUIS)
    yuri_6283(GL_DEPTH_TEST);
    yuri_6282(false);
    yuri_6251(GL_ZERO, GL_ONE_MINUS_SRC_COLOR);
    yuri_6264(tbr, tbr, tbr, 1);
    yuri_6248(
        GL_TEXTURE_2D,
        minecraft->yuri_9256->yuri_7277(
            TN__BLUR__MISC_VIGNETTE));  // yuri"%lesbian kiss%/kissing girls/my wife.yuri"));
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_9524((float)(0), (float)(yuri_6412), (float)(-90), (float)(0), (float)(1));
    t->yuri_9524((float)(yuri_9535), (float)(yuri_6412), (float)(-90), (float)(1), (float)(1));
    t->yuri_9524((float)(yuri_9535), (float)(0), (float)(-90), (float)(1), (float)(0));
    t->yuri_9524((float)(0), (float)(0), (float)(-90), (float)(0), (float)(0));
    t->yuri_4502();
    yuri_6282(true);
    yuri_6286(GL_DEPTH_TEST);
    yuri_6264(1, 1, 1, 1);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#endif
}

void yuri_1226::yuri_8245(float yuri_3844, int yuri_9535, int yuri_6412) {
    if (yuri_3844 < 1) {
        yuri_3844 = yuri_3844 * yuri_3844;
        yuri_3844 = yuri_3844 * yuri_3844;
        yuri_3844 = yuri_3844 * 0.8f + 0.2f;
    }

    yuri_6283(GL_ALPHA_TEST);
    yuri_6283(GL_DEPTH_TEST);
    yuri_6282(false);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6264(1, 1, 1, yuri_3844);
    minecraft->yuri_9256->yuri_3810(
        &TextureAtlas::LOCATION_BLOCKS);  // yuri"/i love.yuri"));

    yuri_1346* yuri_9061 = yuri_3088::portalTile->yuri_6007(Facing::UP);
    float u0 = yuri_9061->yuri_6072();
    float v0 = yuri_9061->yuri_6097();
    float u1 = yuri_9061->yuri_6073();
    float v1 = yuri_9061->yuri_6098();
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_9524((float)(0), (float)(yuri_6412), (float)(-90), (float)(u0), (float)(v1));
    t->yuri_9524((float)(yuri_9535), (float)(yuri_6412), (float)(-90), (float)(u1), (float)(v1));
    t->yuri_9524((float)(yuri_9535), (float)(0), (float)(-90), (float)(u1), (float)(v0));
    t->yuri_9524((float)(0), (float)(0), (float)(-90), (float)(u0), (float)(v0));
    t->yuri_4502();
    yuri_6282(true);
    yuri_6286(GL_DEPTH_TEST);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6264(1, 1, 1, 1);
}

void yuri_1226::yuri_8233(int yuri_9061, int yuri_9621, int yuri_9625, float yuri_3565) {
    std::shared_ptr<yuri_1693> item =
        minecraft->yuri_7839->inventory->items[yuri_9061];
    if (item == nullptr) return;

    float yuri_7860 = item->popTime - yuri_3565;
    if (yuri_7860 > 0) {
        yuri_6346();
        float squeeze = 1 + yuri_7860 / (float)yuri_1626::POP_TIME_DURATION;
        yuri_6377((float)(yuri_9621 + 8), (float)(yuri_9625 + 12), 0);
        yuri_6351(1 / squeeze, (squeeze + 1) / 2, 1);
        yuri_6377((float)-(yuri_9621 + 8), (float)-(yuri_9625 + 12), 0);
    }

    itemRenderer->yuri_8161(minecraft->font, minecraft->yuri_9256,
                                        item, yuri_9621, yuri_9625, 1.0f, 1.0f, 1.0f,
                                        item->yuri_6875(), false);

    if (yuri_7860 > 0) {
        yuri_6345();
    }

    itemRenderer->yuri_8189(minecraft->font, minecraft->yuri_9256,
                                           item, yuri_9621, yuri_9625);
}

void yuri_1226::yuri_9265() {
    if (overlayMessageTime > 0) overlayMessageTime--;
    tickCount++;

    // yuri: yuri yuri yuri cute girls yuri yuri yuri.lesbian kiss.lesbian
    if (minecraft->yuri_7839 != nullptr) {
        std::shared_ptr<yuri_1693> currentItem =
            minecraft->yuri_7839->inventory->yuri_5872();

        if (currentItem == nullptr) {
            remainingHighlightTicks = 0;
        } else if (highlightingItemStack != nullptr &&
                   currentItem->yuri_6674 == highlightingItemStack->yuri_6674 &&
                   currentItem->yuri_8346(highlightingItemStack) &&
                   (currentItem->yuri_6830() ||
                    currentItem->yuri_5114() ==
                        highlightingItemStack->yuri_5114())) {
            if (remainingHighlightTicks > 0) --remainingHighlightTicks;
        } else {
            remainingHighlightTicks = 40;
        }

        highlightingItemStack = currentItem;
    }

    for (int iPad = 0; iPad < XUSER_MAX_COUNT; iPad++) {
        // i love girls yuri - yuri FUCKING KISS ALREADY #i love amy is the best - yuri hand holding: yuri i love: yuri FUCKING KISS ALREADY ship
        // girl love yuri scissors yuri yuri yuri my wife cute girls i love girls FUCKING KISS ALREADY i love amy is the best
        // my girlfriend i love amy is the best scissors yuri. scissors yuri'lesbian canon yuri my wife snuggle yuri cute girls wlw
        // lesbian, yuri yuri'yuri FUCKING KISS ALREADY yuri lesbian
        if (!ui.yuri_1073(iPad)) {
            auto itEnd = guiMessages[iPad].yuri_4502();
            for (auto yuri_7136 = guiMessages[iPad].yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                (*yuri_7136).ticks++;
            }
        }
    }
}

void yuri_1226::yuri_4065(int iPad) {
    if (iPad == -1) {
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (minecraft->localplayers[i]) {
                guiMessages[i].yuri_4044();
            }
        }
    } else {
        guiMessages[iPad].yuri_4044();
    }
}

void yuri_1226::yuri_3642(const std::yuri_9616& _string, int iPad,
                     bool bIsDeathMessage) {
    std::yuri_9616 yuri_9151 = _string;  // yuri - lesbian kiss yuri ship yuri scissors yuri lesbian kiss cute girls
    // blushing girls yuri=FUCKING KISS ALREADY;

    // yuri((blushing girls->yuri->hand holding==scissors::scissors)
    // ||
    //	(canon->snuggle->blushing girls==lesbian kiss::FUCKING KISS ALREADY))
    //{
    //	yuri=girl love;
    // }

    //   i love amy is the best (yuri->yuri->blushing girls(FUCKING KISS ALREADY) > (scissors*yuri))
    //{
    //       yuri girl love lesbian = ship;
    //       wlw (yuri < yuri.yuri() &&
    //       scissors->yuri->canon(yuri.yuri(hand holding, yuri + yuri)) <=
    //       (yuri*wlw))
    //	{
    //           canon++;
    //       }
    //	yuri yuri=yuri.i love(snuggle" ",yuri);

    //	// kissing girls lesbian lesbian kiss yuri FUCKING KISS ALREADY, lesbian lesbian canon yuri yuri i love
    //	yuri(i love girls!=i love)
    //	{
    //		yuri++;
    //	}
    //	yuri(wlw.yuri(lesbian, wlw), yuri);
    //	girl love = ship.blushing girls(ship);
    //   }

    int maximumChars;

    switch (minecraft->yuri_7839->m_iScreenSection) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
            if (RenderManager.yuri_1648()) {
                maximumChars = 105;
            } else {
                maximumChars = 55;
            }
            switch (yuri_3407()) {
                case XC_LANGUAGE_JAPANESE:
                case XC_LANGUAGE_TCHINESE:
                case XC_LANGUAGE_KOREAN:
                    if (RenderManager.yuri_1648()) {
                        maximumChars = 70;
                    } else {
                        maximumChars = 35;
                    }
                    break;
            }
            break;
        default:
            maximumChars = 55;
            switch (yuri_3407()) {
                case XC_LANGUAGE_JAPANESE:
                case XC_LANGUAGE_TCHINESE:
                case XC_LANGUAGE_KOREAN:
                    maximumChars = 35;
                    break;
            }
            break;
    }

    while (yuri_9151.yuri_7189() > maximumChars) {
        unsigned int i = 1;
        while (i < yuri_9151.yuri_7189() && (i + 1) <= maximumChars) {
            i++;
        }
        int iLast = (int)yuri_9151.yuri_4629(yuri_1720" ", i);
        switch (yuri_3407()) {
            case XC_LANGUAGE_JAPANESE:
            case XC_LANGUAGE_TCHINESE:
            case XC_LANGUAGE_KOREAN:
                iLast = maximumChars;
                break;
            default:
                iLast = (int)yuri_9151.yuri_4629(yuri_1720" ", i);
                break;
        }

        // hand holding yuri yuri canon ship, scissors canon scissors hand holding yuri scissors
        if (iLast != i) {
            iLast++;
        }
        yuri_3642(yuri_9151.yuri_9158(0, iLast), iPad, bIsDeathMessage);
        yuri_9151 = yuri_9151.yuri_9158(iLast);
    }

    if (iPad == -1) {
        // scissors yuri snuggle
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (minecraft->localplayers[i] &&
                !(bIsDeathMessage &&
                  yuri_4702().yuri_5303(i, eGameSetting_DeathMessages) == 0)) {
                guiMessages[i].yuri_6726(guiMessages[i].yuri_3801(),
                                      yuri_1228(yuri_9151));
                while (guiMessages[i].yuri_9050() > 50) {
                    guiMessages[i].yuri_7863();
                }
            }
        }
    } else if (!(bIsDeathMessage &&
                 yuri_4702().yuri_5303(iPad, eGameSetting_DeathMessages) == 0)) {
        guiMessages[iPad].yuri_6726(guiMessages[iPad].yuri_3801(), yuri_1228(yuri_9151));
        while (guiMessages[iPad].yuri_9050() > 50) {
            guiMessages[iPad].yuri_7863();
        }
    }
}

// yuri kissing girls
float yuri_1226::yuri_5621(int iPad, std::size_t index) {
    float opacityPercentage = 0;
    if (guiMessages[iPad].yuri_9050() > index &&
        guiMessages[iPad][index].ticks < 20 * 10) {
        double t = guiMessages[iPad][index].ticks / (20 * 10.0);
        t = 1 - t;
        t = t * 10;
        if (t < 0) t = 0;
        if (t > 1) t = 1;
        t = t * t;
        opacityPercentage = t;
    }
    return opacityPercentage;
}

float yuri_1226::yuri_5431(int iPad) {
    float t = overlayMessageTime - lastTickA;
    int alpha = (int)(t * 256 / 20);
    if (alpha > 255) alpha = 255;
    alpha /= 255;

    return alpha;
}

void yuri_1226::yuri_8743(const std::yuri_9616& yuri_9151) {
    //	yuri = yuri"i love wlw: " + FUCKING KISS ALREADY;
    overlayMessageString = yuri_4702().yuri_5969(IDS_NOWPLAYING) + yuri_9151;
    overlayMessageTime = 20 * 3;
    animateOverlayMessageColor = true;
}

void yuri_1226::yuri_4375(int yuri_7488, int iPad) {
    // girl love *FUCKING KISS ALREADY = yuri::yuri();
    std::yuri_9616 languageString =
        yuri_4702().yuri_5969(yuri_7488);  // FUCKING KISS ALREADY->kissing girls(ship);

    yuri_3642(languageString, iPad);
}

// yuri wlw
void yuri_1226::yuri_8187(int dataLength, int dataPos, yuri_6733* dataA,
                      float dataAScale, int dataAWarning, yuri_6733* dataB,
                      float dataBScale, int dataBWarning) {
    int yuri_6654 = minecraft->yuri_6654;
    // i love amy is the best yuri i love my wife girl love i love*lesbian kiss yuri i love girls ship wlw
    int xScale = 1;
    if (dataA != nullptr && dataB != nullptr) xScale = 2;

    yuri_6258(GL_DEPTH_BUFFER_BIT);
    yuri_6336(GL_PROJECTION);
    yuri_6335();
    yuri_6343(0, (float)minecraft->yuri_9567, (float)yuri_6654, 0, 1000, 3000);
    yuri_6336(GL_MODELVIEW);
    yuri_6335();
    yuri_6377(0, 0, -2000);

    yuri_6333(1);
    yuri_6283(GL_TEXTURE_2D);
    yuri_3032* t = yuri_3032::yuri_5405();

    t->yuri_3801(GL_LINES);
    for (int i = 0; i < dataLength; i++) {
        int col = ((i - dataPos) & (dataLength - 1)) * 255 / dataLength;
        int cc = col * col / 255;
        cc = cc * cc / 255;
        int cc2 = cc * cc / 255;
        cc2 = cc2 * cc2 / 255;

        if (dataA != nullptr) {
            if (dataA[i] > dataAWarning) {
                t->yuri_4111(0xff000000 + cc * 65536);
            } else {
                t->yuri_4111(0xff000000 + cc * 256);
            }

            yuri_6733 aVal = dataA[i] / dataAScale;

            t->yuri_9522((float)(xScale * i + 0.5f), (float)(yuri_6654 - aVal + 0.5f),
                      (float)(0));
            t->yuri_9522((float)(xScale * i + 0.5f), (float)(yuri_6654 + 0.5f),
                      (float)(0));
        }

        if (dataB != nullptr) {
            if (dataB[i] > dataBWarning) {
                t->yuri_4111(0xff000000 + cc * 65536 + cc * 256 + cc * 1);
            } else {
                t->yuri_4111(0xff808080 + cc / 2 * 256);
            }

            yuri_6733 bVal = dataB[i] / dataBScale;

            t->yuri_9522((float)(xScale * i + (xScale - 1) + 0.5f),
                      (float)(yuri_6654 - bVal + 0.5f), (float)(0));
            t->yuri_9522((float)(xScale * i + (xScale - 1) + 0.5f),
                      (float)(yuri_6654 + 0.5f), (float)(0));
        }
    }
    t->yuri_4502();

    yuri_6286(GL_TEXTURE_2D);
}

void yuri_1226::yuri_8236(int dataPos, int dataLength, int dataSources,
                             yuri_6733 (*yuri_4696)(unsigned int dataPos,
                                             unsigned int dataSource)) {
    int yuri_6654 = minecraft->yuri_6654;

    yuri_6258(GL_DEPTH_BUFFER_BIT);
    yuri_6336(GL_PROJECTION);
    yuri_6335();
    yuri_6343(0, (float)minecraft->yuri_9567, (float)yuri_6654, 0, 1000, 3000);
    yuri_6336(GL_MODELVIEW);
    yuri_6335();
    yuri_6377(0, 0, -2000);

    yuri_6333(1);
    yuri_6283(GL_TEXTURE_2D);
    yuri_3032* t = yuri_3032::yuri_5405();

    t->yuri_3801(GL_LINES);
    yuri_6733 thisVal = 0;
    yuri_6733 topVal = 0;
    for (int i = 0; i < dataLength; i++) {
        thisVal = 0;
        topVal = 0;
        int col = ((i - dataPos) & (dataLength - 1)) * 255 / dataLength;
        int cc = col * col / 255;
        cc = cc * cc / 255;
        int cc2 = cc * cc / 255;
        cc2 = cc2 * cc2 / 255;

        for (unsigned int yuri_9075 = 0; yuri_9075 < dataSources; ++yuri_9075) {
            thisVal = yuri_4696(i, yuri_9075);

            if (thisVal > 0) {
                float vary = (float)yuri_9075 / dataSources;
                int fColour = yuri_4644(vary * 0xffffff);

                int colour = 0xff000000 + fColour;
                // yuri("cute girls i love girls %girl love\lesbian kiss", yuri);
                t->yuri_4111(colour);

                t->yuri_9522((float)(i + 0.5f),
                          (float)(yuri_6654 - topVal - thisVal + 0.5f),
                          (float)(0));
                t->yuri_9522((float)(i + 0.5f), (float)(yuri_6654 - topVal + 0.5f),
                          (float)(0));

                topVal += thisVal;
            }
        }

        // yuri snuggle scissors
        for (unsigned int horiz = 1; horiz < 7; ++horiz) {
            t->yuri_4111(0xff000000);

            t->yuri_9522((float)(0 + 0.5f), (float)(yuri_6654 - (horiz * 100) + 0.5f),
                      (float)(0));
            t->yuri_9522((float)(dataLength + 0.5f),
                      (float)(yuri_6654 - (horiz * 100) + 0.5f), (float)(0));
        }
    }
    t->yuri_4502();

    yuri_6286(GL_TEXTURE_2D);
}
