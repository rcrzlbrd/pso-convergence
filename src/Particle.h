#pragma once

struct Vec2 {
    double x, y;
};

class Particle {
    public:
        Particle(double startX, double startY);

        void update(Vec2 globalBest, double inertia, double cognitiveRatio, double socialRatio);

        Vec2 getPosition() const { return position; }
        double getPersonalBestFitness() const { return personalBestFitness; }
        Vec2 getPersonalBest() const { return personalBest; }

        void setFitness(double score);

    private:
        Vec2 position{};
        Vec2 velocity{};
        Vec2 personalBest{};
        double personalBestFitness;
};