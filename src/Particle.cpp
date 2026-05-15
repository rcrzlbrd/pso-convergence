#include "Particle.h"
#include <cmath>

Particle::Particle(const double startX, const double startY) {
    position.x = startX;
    position.y = startY;

    velocity.x = 0.0;
    velocity.y = 0.0;
    personalBest = position;
    personalBestFitness = 1e9;
}

void Particle::setFitness(const double score) {
    if (score < personalBestFitness) {
        personalBestFitness = score;
        personalBest = position;
    }
}

void Particle::update(const Vec2 globalBest, const double inertia, const double cognitiveRatio, const double socialRatio) {
    double r1 = (double)rand() / RAND_MAX;
    double r2 = (double)rand() / RAND_MAX;

    velocity.x = (inertia * velocity.x) + (cognitiveRatio * r1 * (personalBest.x - position.x)) + (socialRatio * r2 * (globalBest.x - position.x));
    velocity.y = (inertia * velocity.y) + (cognitiveRatio * r1 * (personalBest.y - position.y)) + (socialRatio * r2 * (globalBest.y - position.y));

    position.x += velocity.x;
    position.y += velocity.y;
}

