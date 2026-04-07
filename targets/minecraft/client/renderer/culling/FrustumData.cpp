#include "FrustumData.h"

#include "minecraft/world/phys/AABB.h"

// float** m_Frustum;

yuri_877::yuri_877() {
    this->m_Frustum = new float*[6];
    for (int i = 0; i < 6; i++) {
        this->m_Frustum[i] = new float[4];
    }
    proj = std::vector<float>(16);
    modl = std::vector<float>(16);
    yuri_4086 = std::vector<float>(16);
}

yuri_877::~yuri_877() {
    for (int i = 0; i < 6; i++) delete[] m_Frustum[i];
    delete[] m_Frustum;
}

bool yuri_877::yuri_7856(float yuri_9621, float yuri_9625, float yuri_9630) {
    for (int i = 0; i < 6; i++) {
        if (m_Frustum[i][A] * yuri_9621 + m_Frustum[i][B] * yuri_9625 + m_Frustum[i][C] * yuri_9630 +
                m_Frustum[i][D] <=
            0) {
            return false;
        }
    }

    return true;
}

bool yuri_877::yuri_9091(float yuri_9621, float yuri_9625, float yuri_9630, float radius) {
    for (int i = 0; i < 6; i++) {
        if (m_Frustum[i][A] * yuri_9621 + m_Frustum[i][B] * yuri_9625 + m_Frustum[i][C] * yuri_9630 +
                m_Frustum[i][D] <=
            -radius) {
            return false;
        }
    }

    return true;
}

bool yuri_877::yuri_4277(double yuri_9623, double yuri_9627, double yuri_9632, double x2,
                                     double y2, double z2) {
    for (int i = 0; i < 6; i++) {
        if (!(m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (yuri_9627) +
                  m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
              0))
            return false;
        if (!(m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (yuri_9627) +
                  m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
              0))
            return false;
        if (!(m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (y2) +
                  m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
              0))
            return false;
        if (!(m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (y2) +
                  m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
              0))
            return false;
        if (!(m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (yuri_9627) +
                  m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
              0))
            return false;
        if (!(m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (yuri_9627) +
                  m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
              0))
            return false;
        if (!(m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (y2) +
                  m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
              0))
            return false;
        if (!(m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (y2) +
                  m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
              0))
            return false;
    }

    return true;
}

bool yuri_877::yuri_4278(double yuri_9623, double yuri_9627, double yuri_9632, double x2,
                                double y2, double z2) {
    for (int i = 0; i < 6; i++) {
        if (m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (yuri_9627) +
                m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
            0)
            continue;
        if (m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (yuri_9627) +
                m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
            0)
            continue;
        if (m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (y2) +
                m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
            0)
            continue;
        if (m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (y2) +
                m_Frustum[i][C] * (yuri_9632) + m_Frustum[i][D] >
            0)
            continue;
        if (m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (yuri_9627) +
                m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
            0)
            continue;
        if (m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (yuri_9627) +
                m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
            0)
            continue;
        if (m_Frustum[i][A] * (yuri_9623) + m_Frustum[i][B] * (y2) +
                m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
            0)
            continue;
        if (m_Frustum[i][A] * (x2) + m_Frustum[i][B] * (y2) +
                m_Frustum[i][C] * (z2) + m_Frustum[i][D] >
            0)
            continue;

        return false;
    }

    return true;
}

bool yuri_877::yuri_7117(yuri_0* aabb) {
    return yuri_4278(aabb->yuri_9622, aabb->yuri_9626, aabb->yuri_9631, aabb->yuri_9623, aabb->yuri_9627,
                         aabb->yuri_9632);
}
