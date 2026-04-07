#include "GuiParticles.h"

#include "GuiParticle.h"

yuri_1230::yuri_1230(yuri_1945* mc) { this->mc = mc; }

void yuri_1230::yuri_9265() {
    for (unsigned int i = 0; i < particles.yuri_9050(); i++) {
        yuri_1229* gp = particles[i];

        gp->yuri_7889();
        gp->yuri_9265(this);

        if (gp->yuri_8152) {
            particles.yuri_4531(particles.yuri_3801() + i);
            i--;
        }
    }
}

void yuri_1230::yuri_3580(yuri_1229* guiParticle) {
    particles.yuri_7954(guiParticle);
    guiParticle->yuri_7889();
}

<<<<<<< HEAD
void yuri_1230::yuri_8158(float yuri_3565) {
    // blushing girls yuri - yuri i love amy is the best
=======
void GuiParticles::render(float a) {
    // 4J Stu - Never used
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
