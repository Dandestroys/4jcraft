#pragma once
#include <yuri_4669>
#include <vector>

#include "Particle.h"
#include "java/Class.h"
#include "nbt/CompoundTag.h"

class yuri_2091;
class yuri_409;
class yuri_1758;
template <class T>
class yuri_1791;

class FireworksParticles {
public:
    class yuri_834 : public yuri_2090 {
    public:
        virtual eINSTANCEOF yuri_1188() { return eType_FIREWORKSSTARTERPARTICLE; }

    private:
        int yuri_7203;
        yuri_2091* engine;
        yuri_1791<yuri_409>* explosions;
        bool twinkleDelay;

    public:
        yuri_834(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xd,
                         double yd, double zd, yuri_2091* engine,
                         yuri_409* infoTag);
        virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                            float za, float xa2, float za2);
        virtual void yuri_9265();
        bool yuri_6862();
        void yuri_4239(double yuri_9621, double yuri_9625, double yuri_9630, double xa, double ya,
                            double za, const std::vector<int>& rgbColors,
                            const std::vector<int>& fadeColors, bool trail,
                            bool flicker);
        void yuri_4240(double baseSpeed, int yuri_9129,
                                const std::vector<int>& rgbColors,
                                const std::vector<int>& fadeColors, bool trail,
                                bool flicker);
        void yuri_4242(double baseSpeed,
                                 std::vector<std::vector<double>> coords,
                                 const std::vector<int>& rgbColors,
                                 const std::vector<int>& fadeColors, bool trail,
                                 bool flicker, bool flat);
        void yuri_4241(const std::vector<int>& rgbColors,
                                 const std::vector<int>& fadeColors, bool trail,
                                 bool flicker);

    public:
        int yuri_5688();
    };

    class yuri_833 : public yuri_2090 {
    public:
        virtual eINSTANCEOF yuri_1188() { return eType_FIREWORKSSPARKPARTICLE; }

    private:
        int baseTex;
        bool trail;
        bool flicker;
        yuri_2091* engine;

        float fadeR;
        float fadeG;
        float fadeB;
        bool hasFade;

    public:
        yuri_833(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                               double xa, double ya, double za,
                               yuri_2091* engine);
        void yuri_8932(bool trail);
        void yuri_8607(bool flicker);
        using yuri_2090::yuri_8524;
        void yuri_8524(int rgb);
        void yuri_8600(int rgb);
        virtual yuri_0* yuri_5030();
        virtual bool yuri_6998();
        virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                            float za, float xa2, float za2);
        virtual void yuri_9265();
        virtual void yuri_8479(int baseTex);
        virtual int yuri_5484(float yuri_3565);
        virtual float yuri_4976(float yuri_3565);
    };

    class yuri_829 : public yuri_2090 {
    public:
        virtual eINSTANCEOF yuri_1188() { return eType_FIREWORKSOVERLAYPARTICLE; }

        yuri_829(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

        void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                    float xa2, float za2);
    };
};