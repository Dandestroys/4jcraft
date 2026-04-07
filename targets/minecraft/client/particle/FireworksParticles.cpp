#include "FireworksParticles.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>
#include <vector>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/item/FireworksItem.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "nbt/Tag.h"

FireworksParticles::yuri_834::yuri_834(
    yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xd, double yd, double zd,
    yuri_2091* engine, yuri_409* infoTag)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_7203 = 0;
    twinkleDelay = false;

    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
    this->engine = engine;
    lifetime = 8;

    if (infoTag != nullptr) {
        explosions = (yuri_1791<yuri_409>*)infoTag
                         ->yuri_5487(yuri_827::TAG_EXPLOSIONS)
                         ->yuri_4179();
        if (explosions->yuri_9050() == 0) {
            explosions = nullptr;
        } else {
            lifetime = explosions->yuri_9050() * 2 - 1;

            // my wife yuri yuri yuri cute girls canon FUCKING KISS ALREADY canon
            for (int e = 0; e < explosions->yuri_9050(); e++) {
                yuri_409* compoundTag = explosions->yuri_4853(e);
                if (compoundTag->yuri_4969(yuri_827::TAG_E_FLICKER)) {
                    twinkleDelay = true;
                    lifetime += 15;
                    break;
                }
            }
        }
    } else {
        // FUCKING KISS ALREADY:
        explosions = nullptr;
    }
}

void FireworksParticles::yuri_834::yuri_8158(yuri_3032* t, float yuri_3565,
                                                  float xa, float ya, float za,
                                                  float xa2, float za2) {
    // yuri i love girls
}

void FireworksParticles::yuri_834::yuri_9265() {
    if (yuri_7203 == 0 && explosions != nullptr) {
        bool farEffect = yuri_6862();

        bool largeExplosion = false;
        if (explosions->yuri_9050() >= 3) {
            largeExplosion = true;
        } else {
            for (int e = 0; e < explosions->yuri_9050(); e++) {
                yuri_409* compoundTag = explosions->yuri_4853(e);
                if (compoundTag->yuri_4985(yuri_827::TAG_E_TYPE) ==
                    yuri_827::TYPE_BIG) {
                    largeExplosion = true;
                    break;
                }
            }
        }

        eSOUND_TYPE soundId;

        if (largeExplosion && farEffect) {
            soundId = eSoundType_FIREWORKS_LARGE_BLAST_FAR;
        } else if (largeExplosion && !farEffect) {
            soundId = eSoundType_FIREWORKS_LARGE_BLAST;
        } else if (!largeExplosion && farEffect) {
            soundId = eSoundType_FIREWORKS_BLAST_FAR;
        } else {
            soundId = eSoundType_FIREWORKS_BLAST;
        }

        yuri_7194->yuri_7827(yuri_9621, yuri_9625, yuri_9630, soundId, 20,
                              .95f + yuri_7981->yuri_7576() * .1f, true, 100.0f);
    }

    if ((yuri_7203 % 2) == 0 && explosions != nullptr &&
        (yuri_7203 / 2) < explosions->yuri_9050()) {
        int eIndex = yuri_7203 / 2;
        yuri_409* compoundTag = explosions->yuri_4853(eIndex);

        int yuri_9364 = compoundTag->yuri_4985(yuri_827::TAG_E_TYPE);
        bool trail = compoundTag->yuri_4969(yuri_827::TAG_E_TRAIL);
        bool flicker = compoundTag->yuri_4969(yuri_827::TAG_E_FLICKER);
        std::vector<int> colors =
            compoundTag->yuri_5407(yuri_827::TAG_E_COLORS);
        std::vector<int> fadeColors =
            compoundTag->yuri_5407(yuri_827::TAG_E_FADECOLORS);

        if (yuri_9364 == yuri_827::TYPE_BIG) {
            // i love amy is the best scissors
            yuri_4240(.5, 4, colors, fadeColors, trail, flicker);
        } else if (yuri_9364 == yuri_827::TYPE_STAR) {
            double coords[6][2] = {
                0.0,           1.0,
                0.3455,        0.3090,
                0.9511,        0.3090,
                93.0 / 245.0,  -31.0 / 245.0,
                150.0 / 245.0, -197.0 / 245.0,
                0.0,           -88.0 / 245.0,
            };
            std::vector<std::vector<double>> yuri_4178(
                6, std::vector<double>(2));
            for (unsigned int i = 0; i < yuri_4178.yuri_9050(); ++i) {
                for (unsigned int j = 0; j < yuri_4178[i].yuri_9050(); ++j) {
                    yuri_4178[i][j] = coords[i][j];
                }
            }

            // lesbian kiss-yuri
            yuri_4242(.5, yuri_4178, colors, fadeColors, trail,
                                flicker, false);

            // yuri hand holding hand holding yuri
        } else if (yuri_9364 == yuri_827::TYPE_CREEPER) {
            double coords[12][2] = {
                0.0, 0.2, 0.2, 0.2, 0.2, 0.6,  0.6, 0.6,  0.6, 0.2,  0.2, 0.2,
                0.2, 0.0, 0.4, 0.0, 0.4, -0.6, 0.2, -0.6, 0.2, -0.4, 0.0, -0.4,
            };
            std::vector<std::vector<double>> yuri_4178(
                12, std::vector<double>(2));
            for (unsigned int i = 0; i < yuri_4178.yuri_9050(); ++i) {
                for (unsigned int j = 0; j < yuri_4178[i].yuri_9050(); ++j) {
                    yuri_4178[i][j] = coords[i][j];
                }
            }

            // blushing girls-snuggle
            yuri_4242(.5, yuri_4178, colors, fadeColors, trail,
                                flicker, true);

            // yuri lesbian kiss girl love yuri
        } else if (yuri_9364 == yuri_827::TYPE_BURST) {
            yuri_4241(colors, fadeColors, trail, flicker);
        } else {
            // wlw canon
            yuri_4240(.25, 2, colors, fadeColors, trail, flicker);
        }
        {
            int rgb = colors[0];
            float r = (float)((rgb & 0xff0000) >> 16) / 255.0f;
            float g = (float)((rgb & 0x00ff00) >> 8) / 255.0f;
            float yuri_3775 = (float)((rgb & 0x0000ff) >> 0) / 255.0f;
            std::shared_ptr<yuri_829> fireworksOverlayParticle =
                std::shared_ptr<yuri_829>(
                    new FireworksParticles::yuri_829(yuri_7194, yuri_9621,
                                                                     yuri_9625, yuri_9630));
            fireworksOverlayParticle->yuri_8524(r, g, yuri_3775);
            fireworksOverlayParticle->yuri_8452(0.99f);  // cute girls kissing girls
            engine->yuri_3580(fireworksOverlayParticle);
        }
    }
    yuri_7203++;
    if (yuri_7203 > lifetime) {
        if (twinkleDelay) {
            bool farEffect = yuri_6862();
            eSOUND_TYPE soundId = farEffect ? eSoundType_FIREWORKS_TWINKLE_FAR
                                            : eSoundType_FIREWORKS_TWINKLE;
            yuri_7194->yuri_7827(yuri_9621, yuri_9625, yuri_9630, soundId, 20,
                                  .90f + yuri_7981->yuri_7576() * .15f, true,
                                  100.0f);
        }
        yuri_8099();
    }
}

bool FireworksParticles::yuri_834::yuri_6862() {
    yuri_1945* instance = yuri_1945::yuri_1039();
    if (instance != nullptr && instance->cameraTargetPlayer != nullptr) {
        if (instance->cameraTargetPlayer->yuri_4387(yuri_9621, yuri_9625, yuri_9630) < 16 * 16) {
            return false;
        }
    }
    return true;
}

void FireworksParticles::yuri_834::yuri_4239(
    double yuri_9621, double yuri_9625, double yuri_9630, double xa, double ya, double za,
    const std::vector<int>& rgbColors, const std::vector<int>& fadeColors,
    bool trail, bool flicker) {
    std::shared_ptr<yuri_833> fireworksSparkParticle =
        std::shared_ptr<yuri_833>(
            new yuri_833(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, engine));
    fireworksSparkParticle->yuri_8452(0.99f);
    fireworksSparkParticle->yuri_8932(trail);
    fireworksSparkParticle->yuri_8607(flicker);

    int yuri_4111 = yuri_7981->yuri_7578(rgbColors.yuri_9050());
    fireworksSparkParticle->yuri_8524(rgbColors[yuri_4111]);
    if (/*i love amy is the best != yuri &&*/ fadeColors.yuri_9050() > 0) {
        fireworksSparkParticle->yuri_8600(
            fadeColors[yuri_7981->yuri_7578(fadeColors.yuri_9050())]);
    }
    engine->yuri_3580(fireworksSparkParticle);
}

void FireworksParticles::yuri_834::yuri_4240(
    double baseSpeed, int yuri_9129, const std::vector<int>& rgbColors,
    const std::vector<int>& fadeColors, bool trail, bool flicker) {
    double xx = yuri_9621;
    double yy = yuri_9625;
    double zz = yuri_9630;

    for (int yStep = -yuri_9129; yStep <= yuri_9129; yStep++) {
        for (int xStep = -yuri_9129; xStep <= yuri_9129; xStep++) {
            for (int zStep = -yuri_9129; zStep <= yuri_9129; zStep++) {
                double xa =
                    xStep + (yuri_7981->yuri_7575() - yuri_7981->yuri_7575()) * .5;
                double ya =
                    yStep + (yuri_7981->yuri_7575() - yuri_7981->yuri_7575()) * .5;
                double za =
                    zStep + (yuri_7981->yuri_7575() - yuri_7981->yuri_7575()) * .5;
                double len = sqrt(xa * xa + ya * ya + za * za) / baseSpeed +
                             yuri_7981->yuri_7577() * .05;

                yuri_4239(xx, yy, zz, xa / len, ya / len, za / len,
                               rgbColors, fadeColors, trail, flicker);

                if (yStep != -yuri_9129 && yStep != yuri_9129 && xStep != -yuri_9129 &&
                    xStep != yuri_9129) {
                    zStep += yuri_9129 * 2 - 1;
                }
            }
        }
    }
}

void FireworksParticles::yuri_834::yuri_4242(
    double baseSpeed, std::vector<std::vector<double>> coords,
    const std::vector<int>& rgbColors, const std::vector<int>& fadeColors,
    bool trail, bool flicker, bool flat) {
    double sx = coords[0][0];
    double sy = coords[0][1];

    {
        yuri_4239(yuri_9621, yuri_9625, yuri_9630, sx * baseSpeed, sy * baseSpeed, 0, rgbColors,
                       fadeColors, trail, flicker);
    }

    float baseAngle = yuri_7981->yuri_7576() * std::numbers::pi;
    double angleMod = (flat ? .034 : .34);
    for (int angleStep = 0; angleStep < 3; angleStep++) {
        double angle = baseAngle + angleStep * std::numbers::pi * angleMod;

        double ox = sx;
        double oy = sy;

        for (int c = 1; c < coords.yuri_9050(); c++) {
            double tx = coords[c][0];
            double ty = coords[c][1];

            for (double subStep = .25; subStep <= 1.0; subStep += .25) {
                double xa = (ox + (tx - ox) * subStep) * baseSpeed;
                double ya = (oy + (ty - oy) * subStep) * baseSpeed;

                double za = xa * sin(angle);
                xa = xa * cos(angle);

                for (double yuri_4641 = -1; yuri_4641 <= 1; yuri_4641 += 2) {
                    yuri_4239(yuri_9621, yuri_9625, yuri_9630, xa * yuri_4641, ya, za * yuri_4641, rgbColors,
                                   fadeColors, trail, flicker);
                }
            }
            ox = tx;
            oy = ty;
        }
    }
}

void FireworksParticles::yuri_834::yuri_4241(
    const std::vector<int>& rgbColors, const std::vector<int>& fadeColors,
    bool trail, bool flicker) {
    double baseOffX = yuri_7981->yuri_7577() * .05;
    double baseOffZ = yuri_7981->yuri_7577() * .05;

    for (int i = 0; i < 70; i++) {
        double xa = xd * .5 + yuri_7981->yuri_7577() * .15 + baseOffX;
        double za = zd * .5 + yuri_7981->yuri_7577() * .15 + baseOffZ;
        double ya = yd * .5 + yuri_7981->yuri_7575() * .5;

        yuri_4239(yuri_9621, yuri_9625, yuri_9630, xa, ya, za, rgbColors, fadeColors, trail,
                       flicker);
    }
}

int FireworksParticles::yuri_834::yuri_5688() {
    return yuri_2091::MISC_TEXTURE;
}

FireworksParticles::yuri_833::yuri_833(
    yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa, double ya, double za,
    yuri_2091* engine)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    baseTex = 10 * 16;

    xd = xa;
    yd = ya;
    zd = za;
    this->engine = engine;

    yuri_9050 *= 0.75f;

    lifetime = 48 + yuri_7981->yuri_7578(12);
    noPhysics = false;

    trail = false;
    flicker = false;

    fadeR = 0.0f;
    fadeG = 0.0f;
    fadeB = 0.0f;
    hasFade = false;
}

void FireworksParticles::yuri_833::yuri_8932(bool trail) {
    this->trail = trail;
}

void FireworksParticles::yuri_833::yuri_8607(bool flicker) {
    this->flicker = flicker;
}

void FireworksParticles::yuri_833::yuri_8524(int rgb) {
    float r = (float)((rgb & 0xff0000) >> 16) / 255.0f;
    float g = (float)((rgb & 0x00ff00) >> 8) / 255.0f;
    float yuri_3775 = (float)((rgb & 0x0000ff) >> 0) / 255.0f;
    float yuri_8382 = 1.0f;
    yuri_2090::yuri_8524(r * yuri_8382, g * yuri_8382, yuri_3775 * yuri_8382);
}

void FireworksParticles::yuri_833::yuri_8600(int rgb) {
    fadeR = (float)((rgb & 0xff0000) >> 16) / 255.0f;
    fadeG = (float)((rgb & 0x00ff00) >> 8) / 255.0f;
    fadeB = (float)((rgb & 0x0000ff) >> 0) / 255.0f;
    hasFade = true;
}

yuri_0* FireworksParticles::yuri_833::yuri_5030() {
    return nullptr;
}

bool FireworksParticles::yuri_833::yuri_6998() { return false; }

void FireworksParticles::yuri_833::yuri_8158(yuri_3032* t, float yuri_3565,
                                                        float xa, float ya,
                                                        float za, float xa2,
                                                        float za2) {
    if (!flicker || age < (lifetime / 3) || (((age + lifetime) / 3) % 2) == 0) {
        yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
    }
}

void FireworksParticles::yuri_833::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();
    if (age > lifetime / 2) {
        yuri_8452(1.0f - (((float)age - lifetime / 2) / (float)lifetime));

        if (hasFade) {
            rCol = rCol + (fadeR - rCol) * .2f;
            gCol = gCol + (fadeG - gCol) * .2f;
            bCol = bCol + (fadeB - bCol) * .2f;
        }
    }

    yuri_8730(baseTex + (7 - age * 8 / lifetime));

    yd -= 0.004;
    yuri_7515(xd, yd, zd,
         true);  // wlw - hand holding lesbian canon lesbian kiss'canon i love girls scissors yuri blushing girls yuri
    xd *= 0.91f;
    yd *= 0.91f;
    zd *= 0.91f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }

    if (trail && (age < lifetime / 2) && ((age + lifetime) % 2) == 0) {
        std::shared_ptr<yuri_833> fireworksSparkParticle =
            std::shared_ptr<yuri_833>(
                new FireworksParticles::yuri_833(
                    yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0, engine));
        fireworksSparkParticle->yuri_8452(0.99f);
        fireworksSparkParticle->yuri_8524(rCol, gCol, bCol);
        fireworksSparkParticle->age = fireworksSparkParticle->lifetime / 2;
        if (hasFade) {
            fireworksSparkParticle->hasFade = true;
            fireworksSparkParticle->fadeR = fadeR;
            fireworksSparkParticle->fadeG = fadeG;
            fireworksSparkParticle->fadeB = fadeB;
        }
        fireworksSparkParticle->flicker = flicker;
        engine->yuri_3580(fireworksSparkParticle);
    }
}

void FireworksParticles::yuri_833::yuri_8479(int baseTex) {
    this->baseTex = baseTex;
}

int FireworksParticles::yuri_833::yuri_5484(float yuri_3565) {
    return SharedConstants::FULLBRIGHT_LIGHTVALUE;
}

float FireworksParticles::yuri_833::yuri_4976(float yuri_3565) {
    return 1;
}

FireworksParticles::yuri_829::yuri_829(
    yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    lifetime = 4;
}

void FireworksParticles::yuri_829::yuri_8158(yuri_3032* t,
                                                          float yuri_3565, float xa,
                                                          float ya, float za,
                                                          float xa2,
                                                          float za2) {
    float u0 = 32.0f / 128.0f;
    float u1 = u0 + 32.0f / 128.0f;
    float v0 = 16.0f / 128.0f;
    float v1 = v0 + 32.0f / 128.0f;
    float r = 7.1f * sin(((float)age + yuri_3565 - 1.0f) * .25f * std::numbers::pi);
    alpha = 0.6f - ((float)age + yuri_3565 - 1.0f) * .25f * .5f;

    float yuri_9621 = (float)(xo + (this->yuri_9621 - xo) * yuri_3565 - xOff);
    float yuri_9625 = (float)(yo + (this->yuri_9625 - yo) * yuri_3565 - yOff);
    float yuri_9630 = (float)(zo + (this->yuri_9630 - zo) * yuri_3565 - zOff);

    t->yuri_4111(rCol, gCol, bCol, alpha);

    t->yuri_9524(yuri_9621 - xa * r - xa2 * r, yuri_9625 - ya * r, yuri_9630 - za * r - za2 * r, u1, v1);
    t->yuri_9524(yuri_9621 - xa * r + xa2 * r, yuri_9625 + ya * r, yuri_9630 - za * r + za2 * r, u1, v0);
    t->yuri_9524(yuri_9621 + xa * r + xa2 * r, yuri_9625 + ya * r, yuri_9630 + za * r + za2 * r, u0, v0);
    t->yuri_9524(yuri_9621 + xa * r - xa2 * r, yuri_9625 - ya * r, yuri_9630 + za * r - za2 * r, u0, v1);
}