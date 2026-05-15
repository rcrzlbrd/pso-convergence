#pragma once
#include "Particle.h"
#include <vector>

class Swarm {
    public:
        Swarm(int numParticles);
        void step(double inertia, double cognitive, double social);

        const std::vector<Particle>& getParticles() const { return particles; }
        double getGlobalBestFitness() const { return globalBestFitness; }

    private:
        std::vector<Particle> particles;
        Vec2 globalBest;
        double globalBestFitness;
};
