#include "Swarm.h"
#include <cstdlib>

#include "Functions.h"

Swarm::Swarm(const int numParticles) {
    globalBestFitness = 1e9;
    for (int i = 0; i < numParticles; i++) {
        double rx = -10.0 + ((double)rand() / RAND_MAX) * 10.0;
        double ry = -10.0 + ((double)rand() / RAND_MAX) * 10.0;

        particles.push_back({rx, ry});
    }
}

void Swarm::step(const double inertia, const double cognitiveRatio, const double socialRatio) {
    for (auto &p : particles) {
        double score = calculateAckley(p.getPosition());
        p.setFitness(score);
        if (score < globalBestFitness) {
            globalBestFitness = score;
            globalBest = p.getPosition();
        }
    }

    for (auto &p : particles) {
        p.update(globalBest, inertia, cognitiveRatio, socialRatio);
    }
}