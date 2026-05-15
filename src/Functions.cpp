#include "Functions.h"
#include <cmath>

double calculateAckley(Vec2 position) {
    const double x = position.x;
    const double y = position.y;
    const double PI = acos(-1);

    const double firstTerm = -20 * std::exp(-0.2 * std::sqrt(0.5 * (x * x + y * y)));
    const double secondTerm = -std::exp(0.5 * (std::cos(2 * PI * x) + std::cos(2 * PI * y)));

    return firstTerm + secondTerm + std::exp(1) + 20;
}

double calculateRastrigin(Vec2 position) {
    const double x = position.x;
    const double y = position.y;
    const double PI = acos(-1);

    const double firstTerm =  x * x - 10 * std::cos(2 * PI * x);
    const double secondTerm =  y * y -10 * std::cos(2 * PI * y);

    return 20 + firstTerm + secondTerm;
}