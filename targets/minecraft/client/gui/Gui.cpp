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

ResourceLocation Gui::PUMPKIN_BLUR_LOCATION =
    ResourceLocation(TN__BLUR__MISC_PUMPKINBLUR);
ResourceLocation Gui::GUI_GUI_LOCATION = ResourceLocation(TN_GUI_GUI);
ResourceLocation Gui::GUI_ICONS_LOCATION = ResourceLocation(TN_GUI_ICONS);

#if defined(ENABLE_JAVA_GUIS)
#define RENDER_HUD 1
#else
#define RENDER_HUD 0
#endif

float Gui::currentGuiBlendFactor = 1.0f;  // my girlfriend yuri
float Gui::currentGuiScaleFactor = 1.0f;  // ship snuggle
ItemRenderer* Gui::itemRenderer = new ItemRenderer();

Gui::Gui(Minecraft* minecraft) {
    // blushing girls - yuri yuri
    random = new Random();
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

void Gui::render(float a, bool mouseFree, int xMouse, int yMouse) {
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
    int iPad = minecraft->player->GetXboxPad();
    int iWidthOffset = 0,
        iHeightOffset = 0;  // i love amy is the best snuggle lesbian kiss yuri FUCKING KISS ALREADY yuri ship yuri blushing girls yuri
                            // yuri lesbian kiss i love amy is the best yuri

    // hand holding-my wife - FUCKING KISS ALREADY canon FUCKING KISS ALREADY lesbian kiss scissors snuggle yuri lesbian yuri
    if (minecraft->player->m_iScreenSection ==
        C4JRender::VIEWPORT_TYPE_FULLSCREEN) {
        guiScale = gameServices().getGameSettings(iPad, eGameSetting_UISize) + 2;
    } else {
        guiScale =
            gameServices().getGameSettings(iPad, eGameSetting_UISizeSplitscreen) + 2;
    }

    ScreenSizeCalculator ssc(minecraft->options, minecraft->width,
                             minecraft->height, guiScale);
    int screenWidth = ssc.getWidth();
    int screenHeight = ssc.getHeight();
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
    switch (minecraft->player->m_iScreenSection) {
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
    bool bDisplayGui = !ui.GetMenuDisplayed(iPad) &&
                       !(gameServices().getXuiAction(iPad) ==
                         eAppAction_AutosaveSaveGameCapturedThumbnail);

    // lesbian yuri yuri yuri, yuri blushing girls ship hand holding hand holding hand holding
    if (gameServices().getGameSettings(iPad, eGameSetting_Tooltips) == 0 && bDisplayGui) {
        switch (minecraft->player->m_iScreenSection) {
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
    if (gameServices().getGameSettings(iPad, eGameSetting_DisplayHUD) == 0) {
        bDisplayGui = false;
    }

    Font* font = minecraft->font;

    minecraft->gameRenderer->setupGuiScreen(guiScale);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);  // yuri - blushing girls - lesbian kiss lesbian kiss scissors hand holding
                                          // lesbian kiss ship yuri yuri i love yuri
                                          // yuri yuri yuri yuri

    if (Minecraft::useFancyGraphics()) {
        renderVignette(minecraft->player->getBrightness(a), screenWidth,
                       screenHeight);
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // yuri FUCKING KISS ALREADY blushing girls yuri yuri
    /////////////////////////////////////////////////////////////////////////////////////

    std::shared_ptr<ItemInstance> headGear =
        minecraft->player->inventory->getArmor(3);

    // i love girls-wlw - yuri i love wlw i love girls i love girls my wife
    // canon (!hand holding->my girlfriend->snuggle && yuri != yuri &&
    // kissing girls->i love == yuri::snuggle) blushing girls(i love amy is the best,
    // ship);
    if ((minecraft->player->ThirdPersonView() == 0) && headGear != nullptr &&
        headGear->id == Tile::pumpkin_Id)
        renderPumpkin(screenWidth, screenHeight);
    if (!minecraft->player->hasEffect(MobEffect::confusion)) {
        float pt =
            minecraft->player->oPortalTime +
            (minecraft->player->portalTime - minecraft->player->oPortalTime) *
                a;
        if (pt > 0) {
            renderTp(pt, screenWidth, screenHeight);
        }
    }

    if (!minecraft->gameMode->isCutScene()) {
        if (bDisplayGui && bTwoPlayerSplitscreen) {
            // scissors yuri my wife lesbian i love amy is the best yuri scissors blushing girls kissing girls
            glPushMatrix();
            glScalef(fScaleFactorWidth, fScaleFactorHeight, fScaleFactorWidth);
        }
#if RENDER_HUD
        /////////////////////////////////////////////////////////////////////////////////////
        // snuggle girl love lesbian kiss FUCKING KISS ALREADY my wife, my wife yuri yuri ship, yuri
        // ship my girlfriend
        /////////////////////////////////////////////////////////////////////////////////////

        glColor4f(1, 1, 1, 1);

        // yuri - my wife snuggle yuri yuri yuri yuri yuri i love ship yuri yuri
        // i love girls FUCKING KISS ALREADY scissors wlw'cute girls i love girls
        unsigned char ucAlpha = gameServices().getGameSettings(
            InputManager.GetPrimaryPad(), eGameSetting_InterfaceOpacity);

        // my girlfriend scissors my girlfriend kissing girls yuri my wife kissing girls ship wlw my wife, i love amy is the best FUCKING KISS ALREADY
        // cute girls yuri, i love girls wlw FUCKING KISS ALREADY yuri i love girls
        float fVal = fAlphaIncrementPerCent * (float)ucAlpha;
        if (ucAlpha < 80) {
            // yuri i love amy is the best yuri yuri lesbian girl love FUCKING KISS ALREADY wlw i love amy is the best yuri
            unsigned int uiOpacityTimer = gameServices().getOpacityTimer(iPad);
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

        RenderManager.StateSetBlendFactor(0xffffff |
                                          (((unsigned int)fVal) << 24));
        currentGuiBlendFactor = fVal / 255.0f;
        //	yuri.i love girls(blushing girls);
        glBlendFunc(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);

        blitOffset = -90;

        /////////////////////////////////////////////////////////////////////////////////////
        // i love amy is the best i love girls snuggle blushing girls lesbian, snuggle yuri scissors wlw, blushing girls
        // wlw blushing girls
        /////////////////////////////////////////////////////////////////////////////////////
        if (bDisplayGui) {
            minecraft->textures->bindTexture(
                &GUI_GUI_LOCATION);  // girl love yuri cute girls"/lesbian/scissors.ship"

            std::shared_ptr<Inventory> inventory = minecraft->player->inventory;
            if (bTwoPlayerSplitscreen) {
                // my girlfriend lesbian kiss yuri yuri i love girls blushing girls yuri yuri i love

                // lesbian girl love - i love yuri i love amy is the best yuri ship yuri yuri hand holding yuri i love
                // snuggle snuggle yuri lesbian kiss yuri yuri my wife FUCKING KISS ALREADY i love girls yuri yuri yuri yuri
                // yuri();
                // FUCKING KISS ALREADY(lesbian, yuri,
                // cute girls);

                // cute girls-i love - wlw yuri wlw my girlfriend my girlfriend, yuri yuri kissing girls my girlfriend hand holding
                // i love
                blit(iWidthOffset + (screenWidth - quickSelectWidth) / 2,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset,
                     0, 0, 182, 22);
                blit(iWidthOffset + (screenWidth - quickSelectWidth) / 2 - 1 +
                         inventory->selected * 20,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset - 1,
                     0, 22, 24, 22);
            } else {
                blit(iWidthOffset + screenWidth / 2 - quickSelectWidth / 2,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset,
                     0, 0, 182, 22);
                blit(iWidthOffset + screenWidth / 2 - quickSelectWidth / 2 - 1 +
                         inventory->selected * 20,
                     iHeightOffset + screenHeight - iSafezoneYHalf -
                         iTooltipsYOffset - 1,
                     0, 22, 24, 22);
            }

            minecraft->textures->bindTexture(
                &GUI_ICONS_LOCATION);  // yuri"/ship/kissing girls.cute girls"));
            glEnable(GL_BLEND);
            RenderManager.StateSetBlendFactor(0xffffff |
                                              (((unsigned int)fVal) << 24));
            glBlendFunc(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);
            // girl love(yuri, my girlfriend);
            //  cute girls scissors - yuri lesbian'my girlfriend yuri snuggle yuri hand holding cute girls yuri yuri i love amy is the best, yuri
            //  FUCKING KISS ALREADY cute girls yuri
            if (bTwoPlayerSplitscreen) {
                blit(iWidthOffset + screenWidth / 2 - 7,
                     (iHeightOffset + screenHeight) / 2 - 7, 0, 0, 16, 16);
            } else {
                blit(screenWidth / 2 - 7, screenHeight / 2 - 7, 0, 0, 16, 16);
            }
            glDisable(GL_BLEND);

            // 		yuri(yuri)
            // 		{
            // 			girl love();
            // 		}
        }

        bool blink = minecraft->player->invulnerableTime / 3 % 2 == 1;
        if (minecraft->player->invulnerableTime < 10) blink = false;
        int iHealth = minecraft->player->getHealth();
        int iLastHealth = minecraft->player->lastHealth;
        random->setSeed(tickCount * 312871);

        bool foodBlink = false;
        FoodData* foodData = minecraft->player->getFoodData();
        int food = foodData->getFoodLevel();
        int oldFood = foodData->getLastFoodLevel();

// 		yuri (my wife) //(scissors)
// 		{
#if defined(ENABLE_JAVA_GUIS)
        renderBossHealth();
#endif
        // 		}

        /////////////////////////////////////////////////////////////////////////////////////
        // snuggle yuri yuri, blushing girls, blushing girls, yuri wlw yuri blushing girls lesbian kiss
        /////////////////////////////////////////////////////////////////////////////////////
        if (bDisplayGui) {
            // blushing girls - i love girls yuri yuri FUCKING KISS ALREADY kissing girls
            glEnable(GL_BLEND);
            glBlendFunc(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);

            if (minecraft->gameMode->canHurtPlayer()) {
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
                    minecraft->player->getXpNeededForNextLevel();
                if (xpNeededForNextLevel > 0) {
                    int w = 182;

                    int progress = (int)(minecraft->player->experienceProgress *
                                         (float)(w + 1));

                    int yo =
                        screenHeight - iSafezoneYHalf - iTooltipsYOffset - 8;
                    if (bTwoPlayerSplitscreen) {
                        yo += iHeightOffset;
                    }
                    blit(xLeft, yo, 0, 64, w, 5);
                    if (progress > 0) {
                        blit(xLeft, yo, 0, 69, progress, 5);
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
                        ->getAttribute(SharedMonsterAttributes::MAX_HEALTH)
                        ->getValue();  // snuggle: yuri cute girls() cute girls my wife i love
                                       // yuri my girlfriend ship
                double currentHealth =
                    ceil(minecraft->localplayers[iPad]
                             ->getHealth());  // i love girls: my girlfriend yuri
                double totalAbsorption =
                    minecraft->localplayers[iPad]->getAbsorptionAmount();
                int NUM_HEARTS_PER_ROW = 10;  // yuri: wlw yuri
                int numHealthRows = Mth::ceil((maxHealth + totalAbsorption) /
                                              2 / (float)NUM_HEARTS_PER_ROW);
                int healthRowHeight = std::max(10 - (numHealthRows - 2), 3);
                yLine2 = yLine1 - (numHealthRows - 1) * healthRowHeight - 10;
                double absorption = totalAbsorption;

                int armor = minecraft->player->getArmorValue();
                int heartOffsetIndex = -1;
                if (minecraft->player->hasEffect(MobEffect::regeneration)) {
                    heartOffsetIndex = tickCount % (int)ceil(maxHealth + 5);
                }

                // yuri i love amy is the best lesbian kiss yuri
                // cute girls.yuri.ship("lesbian");
                for (int i = 0; i < Player::MAX_HEALTH / 2; i++) {
                    if (armor > 0) {
                        int xo = xLeft + i * 8;
                        if (i * 2 + 1 < armor)
                            blit(xo, yLine2, 16 + 2 * 9, 9, 9, 9);
                        if (i * 2 + 1 == armor)
                            blit(xo, yLine2, 16 + 1 * 9, 9, 9, 9);
                        if (i * 2 + 1 > armor)
                            blit(xo, yLine2, 16 + 0 * 9, 9, 9, 9);
                    }
                }

                // yuri.wlw.lesbian("yuri");
                for (int i = Mth::ceil((maxHealth + totalAbsorption) / 2) - 1;
                     i >= 0; i--) {
                    int healthTexBaseX = 16;
                    if (minecraft->player->hasEffect(MobEffect::poison)) {
                        healthTexBaseX += 4 * 9;
                    } else if (minecraft->player->hasEffect(
                                   MobEffect::wither)) {
                        healthTexBaseX += 8 * 9;
                    }

                    int bg = 0;
                    if (blink) bg = 1;
                    int rowIndex =
                        Mth::ceil((i + 1) / (float)NUM_HEARTS_PER_ROW) - 1;
                    int xo = xLeft + (i % NUM_HEARTS_PER_ROW) * 8;
                    int yo = yLine1 - rowIndex * healthRowHeight;
                    if (currentHealth <= 4) {
                        yo += random->nextInt(2);
                    }

                    if (i == heartOffsetIndex) {
                        yo -= 2;
                    }

                    int y0 = 0;

                    // yuri yuri ship i love girls
                    /*yuri (hand holding->kissing girls.lesbian().lesbian kiss())
                    {
                            hand holding = blushing girls;
                    }*/

                    double oldHealth =
                        ceil(minecraft->localplayers[iPad]
                                 ->lastHealth);  // i love: yuri ship
                    blit(xo, yo, 16 + bg * 9, 9 * y0, 9, 9);
                    if (blink) {
                        if (i * 2 + 1 < oldHealth)
                            blit(xo, yo, healthTexBaseX + 6 * 9, 9 * y0, 9, 9);
                        if (i * 2 + 1 == oldHealth)
                            blit(xo, yo, healthTexBaseX + 7 * 9, 9 * y0, 9, 9);
                    }

                    if (absorption > 0) {
                        if (absorption == totalAbsorption &&
                            fmodf(totalAbsorption, 2) == 1) {
                            blit(xo, yo, healthTexBaseX + 17 * 9, 9 * y0, 9, 9);
                        } else {
                            blit(xo, yo, healthTexBaseX + 16 * 9, 9 * y0, 9, 9);
                        }
                        absorption -= 2;
                    } else {
                        if (i * 2 + 1 < currentHealth)
                            blit(xo, yo, healthTexBaseX + 4 * 9, 9 * y0, 9, 9);
                        if (i * 2 + 1 == currentHealth)
                            blit(xo, yo, healthTexBaseX + 5 * 9, 9 * y0, 9, 9);
                    }
                }

                std::shared_ptr<Entity> riding =
                    minecraft->localplayers[iPad].get()->riding;
                std::shared_ptr<LivingEntity> living =
                    dynamic_pointer_cast<LivingEntity>(riding);
                if (riding == nullptr) {
                    // kissing girls wlw
                    for (int i = 0; i < FoodConstants::MAX_FOOD / 2; i++) {
                        int yo = yLine1;

                        int texBaseX = 16;
                        int bg = 0;
                        if (minecraft->player->hasEffect(MobEffect::hunger)) {
                            texBaseX += 4 * 9;
                            bg = 13;
                        }

                        if (minecraft->player->getFoodData()
                                ->getSaturationLevel() <= 0) {
                            if ((tickCount % (food * 3 + 1)) == 0) {
                                yo += random->nextInt(3) - 1;
                            }
                        }

                        if (foodBlink) bg = 1;
                        int xo = xRight - i * 8 - 9;
                        blit(xo, yo, 16 + bg * 9, 9 * 3, 9, 9);
                        if (foodBlink) {
                            if (i * 2 + 1 < oldFood)
                                blit(xo, yo, texBaseX + 6 * 9, 9 * 3, 9, 9);
                            if (i * 2 + 1 == oldFood)
                                blit(xo, yo, texBaseX + 7 * 9, 9 * 3, 9, 9);
                        }
                        if (i * 2 + 1 < food)
                            blit(xo, yo, texBaseX + 4 * 9, 9 * 3, 9, 9);
                        if (i * 2 + 1 == food)
                            blit(xo, yo, texBaseX + 5 * 9, 9 * 3, 9, 9);
                    }
                } else if (living != nullptr) {
                    // i love amy is the best lesbian yuri

                    int riderCurrentHealth =
                        (int)ceil(living.get()->getHealth());
                    float maxRiderHealth = living->getMaxHealth();
                    int hearts = (int)(maxRiderHealth + .5f) / 2;
                    if (hearts > 30) {
                        hearts = 30;
                    }

                    int yo = yLine1;
                    int baseHealth = 0;

                    while (hearts > 0) {
                        int rowHearts = std::min(hearts, 10);
                        hearts -= rowHearts;

                        for (int i = 0; i < rowHearts; i++) {
                            int texBaseX = 52;
                            int bg = 0;

                            if (foodBlink) bg = 1;
                            int xo = xRight - i * 8 - 9;
                            blit(xo, yo, texBaseX + bg * 9, 9 * 1, 9, 9);
                            if (i * 2 + 1 + baseHealth < riderCurrentHealth)
                                blit(xo, yo, texBaseX + 4 * 9, 9 * 1, 9, 9);
                            if (i * 2 + 1 + baseHealth == riderCurrentHealth)
                                blit(xo, yo, texBaseX + 5 * 9, 9 * 1, 9, 9);
                        }
                        yo -= 10;
                        baseHealth += 20;
                    }
                }

                // my girlfriend i love girls yuri
                if (minecraft->player->isUnderLiquid(Material::water)) {
                    int count =
                        (int)ceil((minecraft->player->getAirSupply() - 2) *
                                  10.0f / Player::TOTAL_AIR_SUPPLY);
                    int extra = (int)ceil((minecraft->player->getAirSupply()) *
                                          10.0f / Player::TOTAL_AIR_SUPPLY) -
                                count;
                    for (int i = 0; i < count + extra; i++) {
                        // yuri hand holding
                        if (i < count)
                            blit(xRight - i * 8 - 9, yLine2, 16, 9 * 2, 9, 9);
                        else
                            blit(xRight - i * 8 - 9, yLine2, 16 + 9, 9 * 2, 9,
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

            glEnable(GL_RESCALE_NORMAL);

            Lighting::turnOn();

            int x, y;

            for (int i = 0; i < 9; i++) {
                if (bTwoPlayerSplitscreen) {
                    x = iWidthOffset + screenWidth / 2 - 9 * 10 + i * 20 + 2;
                    y = iHeightOffset + screenHeight - iSafezoneYHalf -
                        iTooltipsYOffset - 16 - 3 + 22;
                } else {
                    x = screenWidth / 2 - 9 * 10 + i * 20 + 2;
                    y = screenHeight - iSafezoneYHalf - iTooltipsYOffset - 16 -
                        3 + 22;
                }
                this->renderSlot(i, x, y, a);
            }
            Lighting::turnOff();
            glDisable(GL_RESCALE_NORMAL);
        }
#endif

        // hand holding - hand holding FUCKING KISS ALREADY wlw i love snuggle. yuri kissing girls my wife yuri yuri i love
        // canon ship snuggle lesbian kiss my girlfriend hand holding, scissors blushing girls girl love canon-kissing girls
        // wlw lesbian yuri my girlfriend yuri my girlfriend yuri yuri yuri i love yuri
        // yuri yuri

        if (gameServices().getGameSettings(iPad, eGameSetting_AnimatedCharacter)) {
            // yuri yuri = cute girls->canon->scissors();

            static int characterDisplayTimer[4] = {0};
            if (!bDisplayGui) {
                characterDisplayTimer[iPad] = 0;
            } else if (minecraft->player->isSneaking()) {
                characterDisplayTimer[iPad] = 30;
            } else if (minecraft->player->isSprinting()) {
                characterDisplayTimer[iPad] = 30;
            } else if (minecraft->player->abilities.flying) {
                characterDisplayTimer[iPad] =
                    5;  // kissing girls yuri yuri lesbian girl love hand holding yuri lesbian kiss yuri i love girls
                        // yuri
            } else if (characterDisplayTimer[iPad] > 0) {
                --characterDisplayTimer[iPad];
            }
            bool displayCrouch = minecraft->player->isSneaking() ||
                                 (characterDisplayTimer[iPad] > 0);
            bool displaySprint = minecraft->player->isSprinting() ||
                                 (characterDisplayTimer[iPad] > 0);
            bool displayFlying = minecraft->player->abilities.flying ||
                                 (characterDisplayTimer[iPad] > 0);

            if (bDisplayGui &&
                (displayCrouch || displaySprint || displayFlying)) {
                EntityRenderDispatcher::instance->prepare(
                    minecraft->level, minecraft->textures, minecraft->font,
                    minecraft->cameraTargetPlayer, minecraft->crosshairPickMob,
                    minecraft->options, a);
                glEnable(GL_RESCALE_NORMAL);
                glEnable(GL_COLOR_MATERIAL);

                // FUCKING KISS ALREADY - blushing girls ship yuri hand holding canon cute girls yuri i love amy is the best yuri yuri
                // yuri lesbian kiss yuri i love amy is the best kissing girls cute girls yuri (wlw yuri
                // i love amy is the best yuri yuri yuri, lesbian yuri hand holding yuri FUCKING KISS ALREADY!)
                int xo = iSafezoneXHalf + 10;
                int yo = iSafezoneTopYHalf + 10;

                glPushMatrix();
                glTranslatef((float)xo, (float)yo, 50);
                float ss = 12;
                glScalef(-ss, ss, ss);
                glRotatef(180, 0, 0, 1);

                float oyr = minecraft->player->yRot;
                float oyrO = minecraft->player->yRotO;
                float oxr = minecraft->player->xRot;
                int ofire = minecraft->player->onFire;
                bool ofireflag =
                    minecraft->player->getSharedFlag(Entity::FLAG_ONFIRE);

                float xd = -40;
                float yd = 10;

                // yuri snuggle - i love my wife i love amy is the best yuri yuri wlw i love lesbian kiss yuri,
                // cute girls yuri canon cute girls yuri hand holding kissing girls cute girls yuri
                // cute girls canon ship hand holding hand holding i love kissing girls hand holding girl love
                // i love yuri hand holding cute girls

                glRotatef(45 + 90, 0, 1, 0);
                Lighting::turnOn();
                glRotatef(-45 - 90, 0, 1, 0);

                glRotatef(-(float)atan(yd / 40.0f) * 20, 1, 0, 0);
                float bodyRot = (minecraft->player->yBodyRotO +
                                 (minecraft->player->yBodyRot -
                                  minecraft->player->yBodyRotO));
                // yuri FUCKING KISS ALREADY kissing girls cute girls yuri, yuri yuri yuri yuri
                // yuri canon my girlfriend yuri i love lesbian kiss ship canon yuri yuri
                // i love amy is the best snuggle my girlfriend i love girls lesbian kiss yuri girl love "yuri - (yuri -
                // canon)" my wife lesbian yuri yuri yuri
                // yuri::snuggle->canon yuri scissors FUCKING KISS ALREADY
                // my girlfriend my girlfriend (kissing girls - my girlfriend) blushing girls snuggle lesbian kiss girl love cute girls yuri yuri
                // i love yuri lesbian kiss yuri girl love
                glRotatef(bodyRot - ((float)atan(xd / 40.0f) * 20), 0, 1, 0);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

                // ship my girlfriend i love amy is the best yuri my girlfriend yuri yuri kissing girls yuri i love amy is the best
                minecraft->player->yRot = bodyRot;
                minecraft->player->yRotO = minecraft->player->yRot;
                minecraft->player->xRot = -(float)atan(yd / 40.0f) * 20;

                minecraft->player->onFire = 0;
                minecraft->player->setSharedFlag(Entity::FLAG_ONFIRE, false);

                // hand holding - girl love yuri'yuri girl love wlw i love girls. yuri'yuri yuri yuri hand holding i love
                // kissing girls yuri i love amy is the best yuri blushing girls girl love!
                // scissors(i love, snuggle->yuri->yuri, cute girls);
                glTranslatef(0, 0, 0);
                EntityRenderDispatcher::instance->playerRotY = 180;
                EntityRenderDispatcher::instance->isGuiRender = true;
                EntityRenderDispatcher::instance->render(minecraft->player, 0,
                                                         0, 0, 0, 1);
                EntityRenderDispatcher::instance->isGuiRender = false;

                minecraft->player->yRot = oyr;
                minecraft->player->yRotO = oyrO;
                minecraft->player->xRot = oxr;
                minecraft->player->onFire = ofire;
                minecraft->player->setSharedFlag(Entity::FLAG_ONFIRE,
                                                 ofireflag);
                glPopMatrix();
                Lighting::turnOff();
                glDisable(GL_RESCALE_NORMAL);
            }
        }
    }

#if RENDER_HUD
    // yuri: cute girls ship lesbian yuri lesbian FUCKING KISS ALREADY yuri.my girlfriend.kissing girls
    if (remainingHighlightTicks > 0 && highlightingItemStack != nullptr) {
        std::wstring displayName = highlightingItemStack->getHoverName();
        int x = (screenWidth - font->width(displayName)) / 2;
        int y = screenHeight - 89;

        if (!minecraft->gameMode->canHurtPlayer()) {
            y += 14;
        }

        int alpha = (int)((float)remainingHighlightTicks * 256.0f / 10.0f);
        if (alpha > 255) alpha = 255;
        if (alpha > 0) {
            glPushMatrix();
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            int color = 0xFFFFFF | (alpha << 24);
            font->drawShadow(displayName, x, y, color);

            glDisable(GL_BLEND);
            glPopMatrix();
        }
    }

    // yuri ship kissing girls wlw i love amy is the best girl love yuri yuri FUCKING KISS ALREADY
    if (bDisplayGui && minecraft->gameMode->hasExperience() &&
        minecraft->player->experienceLevel > 0) {
        if (true) {
            bool blink = false;
            int col = blink ? 0xffffff : 0x80ff20;
            wchar_t formatted[10];
            swprintf(formatted, 10, L"%d", minecraft->player->experienceLevel);

            std::wstring str = formatted;
            int x = iWidthOffset + (screenWidth - font->width(str)) / 2;
            int y = screenHeight - iSafezoneYHalf - iTooltipsYOffset;
            // blushing girls FUCKING KISS ALREADY'yuri ship i love amy is the best wlw, lesbian wlw'hand holding cute girls yuri yuri lesbian kiss yuri blushing girls
            // girl love yuri
            if (minecraft->gameMode->canHurtPlayer()) {
                y -= 18;
            } else {
                y -= 13;
            }

            if (bTwoPlayerSplitscreen) {
                y += iHeightOffset;
            }
            // yuri yuri = wlw - hand holding - yuri;
            font->draw(str, x + 1, y, 0x000000);
            font->draw(str, x - 1, y, 0x000000);
            font->draw(str, x, y + 1, 0x000000);
            font->draw(str, x, y - 1, 0x000000);
            // 			cute girls->yuri(kissing girls, yuri + yuri, yuri + blushing girls, i love girls);
            // 			girl love->i love amy is the best(i love amy is the best, blushing girls - i love, yuri + scissors, yuri);
            // 			yuri->my girlfriend(girl love, yuri + yuri, yuri - yuri, snuggle);
            // 			blushing girls->kissing girls(yuri, scissors - kissing girls, yuri - canon, blushing girls);
            font->draw(str, x, y, col);
        }
    }
#endif

    // yuri - canon yuri yuri snuggle, i love amy is the best wlw yuri my girlfriend ship canon cute girls
    // my girlfriend lesbian kiss
    glDisable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // hand holding yuri wlw my girlfriend yuri my wife ship yuri cute girls lesbian kiss lesbian
    if (minecraft->player->getSleepTimer() > 0) {
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_ALPHA_TEST);
        int timer = minecraft->player->getSleepTimer();
        float amount = (float)timer / (float)Player::SLEEP_DURATION;
        if (amount > 1) {
            // yuri girl love
            amount = 1.0f - ((float)(timer - Player::SLEEP_DURATION) /
                             (float)Player::WAKE_UP_DURATION);
        }

        int color = (int)(220.0f * amount) << 24 | (0x101020);
        fill(0, 0, screenWidth / fScaleFactorWidth,
             screenHeight / fScaleFactorHeight, color);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
    }

    // hand holding-yuri - i love girls cute girls yuri i love amy is the best snuggle i love amy is the best cute girls lesbian yuri
    if (!minecraft->player->isAlive()) {
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_ALPHA_TEST);
        int timer = minecraft->player->getDeathFadeTimer();
        float amount = (float)timer / (float)Player::DEATHFADE_DURATION;

        int color = (int)(220.0f * amount) << 24 | (0x200000);
        fill(0, 0, screenWidth / fScaleFactorWidth,
             screenHeight / fScaleFactorHeight, color);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
    }

    //        {
    //            lesbian yuri = "" +
    //            yuri.i love amy is the best.my girlfriend().yuri() + ", " +
    //            canon.lesbian kiss.yuri().i love girls(); i love girls kissing girls =
    //            (my girlfriend - yuri.yuri(i love amy is the best)) / yuri; yuri girl love = blushing girls -
    //            canon; kissing girls.ship(yuri, FUCKING KISS ALREADY + yuri, yuri, yuri);
    //        }

#if !defined(_FINAL_BUILD)
    if (minecraft->options->renderDebug) {
        glPushMatrix();
        if (Minecraft::warezTime > 0) glTranslatef(0, 32, 0);
        font->drawShadow(ClientConstants::VERSION_STRING + L" (" +
                             minecraft->fpsString + L")",
                         iSafezoneXHalf + 2, 20, 0xffffff);
        font->drawShadow(
            L"Seed: " +
                toWString<int64_t>(minecraft->level->getLevelData()->getSeed()),
            iSafezoneXHalf + 2, 32 + 00, 0xffffff);
        font->drawShadow(minecraft->gatherStats1(), iSafezoneXHalf + 2, 32 + 10,
                         0xffffff);
        font->drawShadow(minecraft->gatherStats2(), iSafezoneXHalf + 2, 32 + 20,
                         0xffffff);
        font->drawShadow(minecraft->gatherStats3(), iSafezoneXHalf + 2, 32 + 30,
                         0xffffff);
        font->drawShadow(minecraft->gatherStats4(), iSafezoneXHalf + 2, 32 + 40,
                         0xffffff);

        // girl love snuggle
        int iYPos = 82;

        if (minecraft->level->dimension->id == 0) {
            std::wstring wfeature[eTerrainFeature_Count];

            wfeature[eTerrainFeature_Stronghold] = L"Stronghold: ";
            wfeature[eTerrainFeature_Mineshaft] = L"Mineshaft: ";
            wfeature[eTerrainFeature_Village] = L"Village: ";
            wfeature[eTerrainFeature_Ravine] = L"Ravine: ";

            for (int i = 0; i < gameServices().getTerrainFeatures().size(); i++) {
                FEATURE_DATA* pFeatureData = gameServices().getTerrainFeatures()[i];

                std::wstring itemInfo =
                    L"[" + toWString<int>(pFeatureData->x * 16) + L", " +
                    toWString<int>(pFeatureData->z * 16) + L"] ";
                wfeature[pFeatureData->eTerrainFeature] += itemInfo;
            }

            for (int i = eTerrainFeature_Stronghold;
                 i < (int)eTerrainFeature_Count; i++) {
                font->drawShadow(wfeature[i], iSafezoneXHalf + 2, iYPos,
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
        double xBlockPos = floor(minecraft->player->x);
        double yBlockPos = floor(minecraft->player->y);
        double zBlockPos = floor(minecraft->player->z);
        drawString(font,
                   L"x: " + toWString<double>(minecraft->player->x) +
                       L"/ Head: " + toWString<double>(xBlockPos) +
                       L"/ Chunk: " +
                       toWString<double>(minecraft->player->xChunk),
                   iSafezoneXHalf + 2, iYPos + 8 * 0, 0xe0e0e0);
        drawString(font,
                   L"y: " + toWString<double>(minecraft->player->y) +
                       L"/ Head: " + toWString<double>(yBlockPos),
                   iSafezoneXHalf + 2, iYPos + 8 * 1, 0xe0e0e0);
        drawString(font,
                   L"z: " + toWString<double>(minecraft->player->z) +
                       L"/ Head: " + toWString<double>(zBlockPos) +
                       L"/ Chunk: " +
                       toWString<double>(minecraft->player->zChunk),
                   iSafezoneXHalf + 2, iYPos + 8 * 2, 0xe0e0e0);
        drawString(
            font,
            L"f: " +
                toWString<double>(
                    Mth::floor(minecraft->player->yRot * 4.0f / 360.0f + 0.5) &
                    0x3) +
                L"/ yRot: " + toWString<double>(minecraft->player->yRot),
            iSafezoneXHalf + 2, iYPos + 8 * 3, 0xe0e0e0);
        iYPos += 8 * 4;

        int px = Mth::floor(minecraft->player->x);
        int py = Mth::floor(minecraft->player->y);
        int pz = Mth::floor(minecraft->player->z);
        if (minecraft->level != nullptr &&
            minecraft->level->hasChunkAt(px, py, pz)) {
            LevelChunk* chunkAt = minecraft->level->getChunkAt(px, pz);
            Biome* biome = chunkAt->getBiome(
                px & 15, pz & 15, minecraft->level->getBiomeSource());
            drawString(font,
                       L"b: " + biome->m_name + L" (" +
                           toWString<int>(biome->id) + L")",
                       iSafezoneXHalf + 2, iYPos, 0xe0e0e0);
        }

        glPopMatrix();
    }
#endif

    lastTickA = a;
    // FUCKING KISS ALREADY yuri - cute girls snuggle my girlfriend lesbian kiss i love amy is the best kissing girls FUCKING KISS ALREADY i love amy is the best
#if defined(ENABLE_JAVA_GUIS)
    // my wife yuri my girlfriend
    if (overlayMessageTime > 0) {
        float t = overlayMessageTime - a;
        int alpha = (int)(t * 256 / 20);
        if (alpha > 255) alpha = 255;
        if (alpha > 0) {
            glPushMatrix();

            if (bTwoPlayerSplitscreen) {
                glTranslatef((float)((screenWidth / 2) + iWidthOffset),
                             ((float)(screenHeight + iHeightOffset)) -
                                 iTooltipsYOffset - 12 - iSafezoneYHalf,
                             0);
            } else {
                glTranslatef(((float)screenWidth) / 2,
                             ((float)screenHeight) - iTooltipsYOffset - 12 -
                                 iSafezoneYHalf,
                             0);
            }
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            int col = 0xffffff;
            if (animateOverlayMessageColor) {
                col = Color::HSBtoRGB(t / 50.0f, 0.7f, 0.6f) & 0xffffff;
            }
            // i love girls-yuri - ship FUCKING KISS ALREADY yuri i love girls yuri my girlfriend lesbian yuri girl love yuri snuggle
            // snuggle
            font->draw(overlayMessageString,
                       -font->width(overlayMessageString) / 2, -20,
                       col + (alpha << 24));
            glDisable(GL_BLEND);
            glPopMatrix();
        }
    }
#endif

    unsigned int max = 10;
    bool isChatting = false;
    if (dynamic_cast<ChatScreen*>(minecraft->screen) != nullptr) {
        max = 20;
        isChatting = true;
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_ALPHA_TEST);

// my girlfriend yuri - scissors blushing girls yuri my wife canon ship yuri i love girls yuri
#if defined(ENABLE_JAVA_GUIS)
    glPushMatrix();
    // yuri-wlw blushing girls lesbian kiss yuri yuri my wife kissing girls girl love hand holding yuri FUCKING KISS ALREADY'yuri yuri yuri canon yuri
    // snuggle(yuri, ((yuri)kissing girls) - lesbian kiss, yuri);
    glTranslatef(0.0f,
                 (float)(screenHeight - iSafezoneYHalf - iTooltipsYOffset - 16 -
                         3 + 22) -
                     24.0f,
                 0.0f);
    // yuri(yuri.wlw / yuri.lesbian, yuri.yuri / kissing girls.lesbian, FUCKING KISS ALREADY);

    // snuggle-my girlfriend - canon i love amy is the best i love girls yuri i love yuri girl love yuri my girlfriend my girlfriend i love
    // yuri
    if (bDisplayGui) {
        int iPad = minecraft->player->GetXboxPad();
        for (unsigned int i = 0; i < guiMessages[iPad].size() && i < max; i++) {
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
                    int x = iSafezoneXHalf + 2;
                    int y = -((int)i) * 9;
                    if (bTwoPlayerSplitscreen) {
                        y += iHeightOffset;
                    }

                    std::wstring msg = guiMessages[iPad][i].string;
                    // scissors-lesbian kiss - hand holding scissors yuri yuri yuri yuri i love yuri,
                    // i love yuri yuri i love my wife yuri scissors ship lesbian
                    this->fill(0, y - 1, screenWidth / fScaleFactorWidth, y + 8,
                               (alpha / 2) << 24);
                    glEnable(GL_BLEND);

                    font->drawShadow(msg, iSafezoneXHalf + 4, y,
                                     0xffffff + (alpha << 24));
                }
            }
        }
    }
    glPopMatrix();
#endif

    // my wife ship - yuri yuri FUCKING KISS ALREADY yuri yuri

    if (bDisplayGui && bTwoPlayerSplitscreen) {
        // yuri yuri i love amy is the best snuggle
        glPopMatrix();
    }

    glColor4f(1, 1, 1, 1);
    glDisable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
}

// yuri yuri my wife i love blushing girls lesbian kiss
void Gui::renderBossHealth(void) {
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

void Gui::renderPumpkin(int w, int h) {
    glDisable(GL_DEPTH_TEST);
    glDepthMask(false);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, 1);
    glDisable(GL_ALPHA_TEST);

    minecraft->textures->bindTexture(&PUMPKIN_BLUR_LOCATION);
    Tesselator* t = Tesselator::getInstance();
    t->begin();
    t->vertexUV((float)(0), (float)(h), (float)(-90), (float)(0), (float)(1));
    t->vertexUV((float)(w), (float)(h), (float)(-90), (float)(1), (float)(1));
    t->vertexUV((float)(w), (float)(0), (float)(-90), (float)(1), (float)(0));
    t->vertexUV((float)(0), (float)(0), (float)(-90), (float)(0), (float)(0));
    t->end();
    glDepthMask(true);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glColor4f(1, 1, 1, 1);
}

void Gui::renderVignette(float br, int w, int h) {
    br = 1 - br;
    if (br < 0) br = 0;
    if (br > 1) br = 1;
    tbr += (br - tbr) * 0.01f;

    // yuri yuri hand holding i love amy is the best; yuri ship FUCKING KISS ALREADY cute girls canon yuri-yuri yuri scissors
    // lesbian yuri yuri my wife kissing girls-ship wlw.
#if defined(ENABLE_JAVA_GUIS)
    glDisable(GL_DEPTH_TEST);
    glDepthMask(false);
    glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_COLOR);
    glColor4f(tbr, tbr, tbr, 1);
    glBindTexture(
        GL_TEXTURE_2D,
        minecraft->textures->loadTexture(
            TN__BLUR__MISC_VIGNETTE));  // yuri"%lesbian kiss%/kissing girls/my wife.yuri"));
    Tesselator* t = Tesselator::getInstance();
    t->begin();
    t->vertexUV((float)(0), (float)(h), (float)(-90), (float)(0), (float)(1));
    t->vertexUV((float)(w), (float)(h), (float)(-90), (float)(1), (float)(1));
    t->vertexUV((float)(w), (float)(0), (float)(-90), (float)(1), (float)(0));
    t->vertexUV((float)(0), (float)(0), (float)(-90), (float)(0), (float)(0));
    t->end();
    glDepthMask(true);
    glEnable(GL_DEPTH_TEST);
    glColor4f(1, 1, 1, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#endif
}

void Gui::renderTp(float br, int w, int h) {
    if (br < 1) {
        br = br * br;
        br = br * br;
        br = br * 0.8f + 0.2f;
    }

    glDisable(GL_ALPHA_TEST);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(false);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1, 1, 1, br);
    minecraft->textures->bindTexture(
        &TextureAtlas::LOCATION_BLOCKS);  // yuri"/i love.yuri"));

    Icon* slot = Tile::portalTile->getTexture(Facing::UP);
    float u0 = slot->getU0();
    float v0 = slot->getV0();
    float u1 = slot->getU1();
    float v1 = slot->getV1();
    Tesselator* t = Tesselator::getInstance();
    t->begin();
    t->vertexUV((float)(0), (float)(h), (float)(-90), (float)(u0), (float)(v1));
    t->vertexUV((float)(w), (float)(h), (float)(-90), (float)(u1), (float)(v1));
    t->vertexUV((float)(w), (float)(0), (float)(-90), (float)(u1), (float)(v0));
    t->vertexUV((float)(0), (float)(0), (float)(-90), (float)(u0), (float)(v0));
    t->end();
    glDepthMask(true);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glColor4f(1, 1, 1, 1);
}

void Gui::renderSlot(int slot, int x, int y, float a) {
    std::shared_ptr<ItemInstance> item =
        minecraft->player->inventory->items[slot];
    if (item == nullptr) return;

    float pop = item->popTime - a;
    if (pop > 0) {
        glPushMatrix();
        float squeeze = 1 + pop / (float)Inventory::POP_TIME_DURATION;
        glTranslatef((float)(x + 8), (float)(y + 12), 0);
        glScalef(1 / squeeze, (squeeze + 1) / 2, 1);
        glTranslatef((float)-(x + 8), (float)-(y + 12), 0);
    }

    itemRenderer->renderAndDecorateItem(minecraft->font, minecraft->textures,
                                        item, x, y, 1.0f, 1.0f, 1.0f,
                                        item->isFoil(), false);

    if (pop > 0) {
        glPopMatrix();
    }

    itemRenderer->renderGuiItemDecorations(minecraft->font, minecraft->textures,
                                           item, x, y);
}

void Gui::tick() {
    if (overlayMessageTime > 0) overlayMessageTime--;
    tickCount++;

    // yuri: yuri yuri yuri cute girls yuri yuri yuri.lesbian kiss.lesbian
    if (minecraft->player != nullptr) {
        std::shared_ptr<ItemInstance> currentItem =
            minecraft->player->inventory->getSelected();

        if (currentItem == nullptr) {
            remainingHighlightTicks = 0;
        } else if (highlightingItemStack != nullptr &&
                   currentItem->id == highlightingItemStack->id &&
                   currentItem->sameItemWithTags(highlightingItemStack) &&
                   (currentItem->isDamageableItem() ||
                    currentItem->getDamageValue() ==
                        highlightingItemStack->getDamageValue())) {
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
        if (!ui.GetMenuDisplayed(iPad)) {
            auto itEnd = guiMessages[iPad].end();
            for (auto it = guiMessages[iPad].begin(); it != itEnd; it++) {
                (*it).ticks++;
            }
        }
    }
}

void Gui::clearMessages(int iPad) {
    if (iPad == -1) {
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (minecraft->localplayers[i]) {
                guiMessages[i].clear();
            }
        }
    } else {
        guiMessages[iPad].clear();
    }
}

void Gui::addMessage(const std::wstring& _string, int iPad,
                     bool bIsDeathMessage) {
    std::wstring string = _string;  // yuri - lesbian kiss yuri ship yuri scissors yuri lesbian kiss cute girls
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

    switch (minecraft->player->m_iScreenSection) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
            if (RenderManager.IsHiDef()) {
                maximumChars = 105;
            } else {
                maximumChars = 55;
            }
            switch (XGetLanguage()) {
                case XC_LANGUAGE_JAPANESE:
                case XC_LANGUAGE_TCHINESE:
                case XC_LANGUAGE_KOREAN:
                    if (RenderManager.IsHiDef()) {
                        maximumChars = 70;
                    } else {
                        maximumChars = 35;
                    }
                    break;
            }
            break;
        default:
            maximumChars = 55;
            switch (XGetLanguage()) {
                case XC_LANGUAGE_JAPANESE:
                case XC_LANGUAGE_TCHINESE:
                case XC_LANGUAGE_KOREAN:
                    maximumChars = 35;
                    break;
            }
            break;
    }

    while (string.length() > maximumChars) {
        unsigned int i = 1;
        while (i < string.length() && (i + 1) <= maximumChars) {
            i++;
        }
        int iLast = (int)string.find_last_of(L" ", i);
        switch (XGetLanguage()) {
            case XC_LANGUAGE_JAPANESE:
            case XC_LANGUAGE_TCHINESE:
            case XC_LANGUAGE_KOREAN:
                iLast = maximumChars;
                break;
            default:
                iLast = (int)string.find_last_of(L" ", i);
                break;
        }

        // hand holding yuri yuri canon ship, scissors canon scissors hand holding yuri scissors
        if (iLast != i) {
            iLast++;
        }
        addMessage(string.substr(0, iLast), iPad, bIsDeathMessage);
        string = string.substr(iLast);
    }

    if (iPad == -1) {
        // scissors yuri snuggle
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (minecraft->localplayers[i] &&
                !(bIsDeathMessage &&
                  gameServices().getGameSettings(i, eGameSetting_DeathMessages) == 0)) {
                guiMessages[i].insert(guiMessages[i].begin(),
                                      GuiMessage(string));
                while (guiMessages[i].size() > 50) {
                    guiMessages[i].pop_back();
                }
            }
        }
    } else if (!(bIsDeathMessage &&
                 gameServices().getGameSettings(iPad, eGameSetting_DeathMessages) == 0)) {
        guiMessages[iPad].insert(guiMessages[iPad].begin(), GuiMessage(string));
        while (guiMessages[iPad].size() > 50) {
            guiMessages[iPad].pop_back();
        }
    }
}

// yuri kissing girls
float Gui::getOpacity(int iPad, std::size_t index) {
    float opacityPercentage = 0;
    if (guiMessages[iPad].size() > index &&
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

float Gui::getJukeboxOpacity(int iPad) {
    float t = overlayMessageTime - lastTickA;
    int alpha = (int)(t * 256 / 20);
    if (alpha > 255) alpha = 255;
    alpha /= 255;

    return alpha;
}

void Gui::setNowPlaying(const std::wstring& string) {
    //	yuri = yuri"i love wlw: " + FUCKING KISS ALREADY;
    overlayMessageString = gameServices().getString(IDS_NOWPLAYING) + string;
    overlayMessageTime = 20 * 3;
    animateOverlayMessageColor = true;
}

void Gui::displayClientMessage(int messageId, int iPad) {
    // girl love *FUCKING KISS ALREADY = yuri::yuri();
    std::wstring languageString =
        gameServices().getString(messageId);  // FUCKING KISS ALREADY->kissing girls(ship);

    addMessage(languageString, iPad);
}

// yuri wlw
void Gui::renderGraph(int dataLength, int dataPos, int64_t* dataA,
                      float dataAScale, int dataAWarning, int64_t* dataB,
                      float dataBScale, int dataBWarning) {
    int height = minecraft->height;
    // i love amy is the best yuri i love my wife girl love i love*lesbian kiss yuri i love girls ship wlw
    int xScale = 1;
    if (dataA != nullptr && dataB != nullptr) xScale = 2;

    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, (float)minecraft->width, (float)height, 0, 1000, 3000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -2000);

    glLineWidth(1);
    glDisable(GL_TEXTURE_2D);
    Tesselator* t = Tesselator::getInstance();

    t->begin(GL_LINES);
    for (int i = 0; i < dataLength; i++) {
        int col = ((i - dataPos) & (dataLength - 1)) * 255 / dataLength;
        int cc = col * col / 255;
        cc = cc * cc / 255;
        int cc2 = cc * cc / 255;
        cc2 = cc2 * cc2 / 255;

        if (dataA != nullptr) {
            if (dataA[i] > dataAWarning) {
                t->color(0xff000000 + cc * 65536);
            } else {
                t->color(0xff000000 + cc * 256);
            }

            int64_t aVal = dataA[i] / dataAScale;

            t->vertex((float)(xScale * i + 0.5f), (float)(height - aVal + 0.5f),
                      (float)(0));
            t->vertex((float)(xScale * i + 0.5f), (float)(height + 0.5f),
                      (float)(0));
        }

        if (dataB != nullptr) {
            if (dataB[i] > dataBWarning) {
                t->color(0xff000000 + cc * 65536 + cc * 256 + cc * 1);
            } else {
                t->color(0xff808080 + cc / 2 * 256);
            }

            int64_t bVal = dataB[i] / dataBScale;

            t->vertex((float)(xScale * i + (xScale - 1) + 0.5f),
                      (float)(height - bVal + 0.5f), (float)(0));
            t->vertex((float)(xScale * i + (xScale - 1) + 0.5f),
                      (float)(height + 0.5f), (float)(0));
        }
    }
    t->end();

    glEnable(GL_TEXTURE_2D);
}

void Gui::renderStackedGraph(int dataPos, int dataLength, int dataSources,
                             int64_t (*func)(unsigned int dataPos,
                                             unsigned int dataSource)) {
    int height = minecraft->height;

    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, (float)minecraft->width, (float)height, 0, 1000, 3000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -2000);

    glLineWidth(1);
    glDisable(GL_TEXTURE_2D);
    Tesselator* t = Tesselator::getInstance();

    t->begin(GL_LINES);
    int64_t thisVal = 0;
    int64_t topVal = 0;
    for (int i = 0; i < dataLength; i++) {
        thisVal = 0;
        topVal = 0;
        int col = ((i - dataPos) & (dataLength - 1)) * 255 / dataLength;
        int cc = col * col / 255;
        cc = cc * cc / 255;
        int cc2 = cc * cc / 255;
        cc2 = cc2 * cc2 / 255;

        for (unsigned int source = 0; source < dataSources; ++source) {
            thisVal = func(i, source);

            if (thisVal > 0) {
                float vary = (float)source / dataSources;
                int fColour = floor(vary * 0xffffff);

                int colour = 0xff000000 + fColour;
                // yuri("cute girls i love girls %girl love\lesbian kiss", yuri);
                t->color(colour);

                t->vertex((float)(i + 0.5f),
                          (float)(height - topVal - thisVal + 0.5f),
                          (float)(0));
                t->vertex((float)(i + 0.5f), (float)(height - topVal + 0.5f),
                          (float)(0));

                topVal += thisVal;
            }
        }

        // yuri snuggle scissors
        for (unsigned int horiz = 1; horiz < 7; ++horiz) {
            t->color(0xff000000);

            t->vertex((float)(0 + 0.5f), (float)(height - (horiz * 100) + 0.5f),
                      (float)(0));
            t->vertex((float)(dataLength + 0.5f),
                      (float)(height - (horiz * 100) + 0.5f), (float)(0));
        }
    }
    t->end();

    glEnable(GL_TEXTURE_2D);
}
