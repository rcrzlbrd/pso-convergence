#include <iostream>
#include <ctime>
#include <fstream>
#include "Swarm.h"

int main() {
    std::srand(std::time(nullptr));

    int numParticles = 30;
    int iterations = 100;
    double inertia = 0.5;
    double cognitiveRatio = 1.5;
    double socialRatio = 1.5;

    Swarm Birds(numParticles);

    std::ofstream outFile("../output/data.csv");
    outFile << "iteration,id,x,y\n";

    for (int i = 0; i < iterations; i++) {
        Birds.step(inertia, cognitiveRatio, socialRatio);
        std::cout << Birds.getGlobalBestFitness() << "\n";
        
        const auto& allParticles = Birds.getParticles();
        for (int j = 0; j < allParticles.size(); j++) {
            outFile << i << "," << j << ","
                    << allParticles[j].getPosition().x << ","
                    << allParticles[j].getPosition().y << "\n";
        }
    }
    outFile.close();

    return 0;
}