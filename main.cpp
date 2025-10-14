#include "simulator.h"
#include <iostream>

int main() {
    // Example 1: Use real gravitational constant
    std::cout << "Simulation using real G (6.67430e-11)\n";
    Simulator sim1(60.0 * 60. );  // dt = 1 hour, regular G

    // Sun and Earth
    Body sun(1.989e30, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
    Body earth(5.972e24, {1.496e11, 0.0, 0.0}, {0.0, 29.78e3, 0.0});

    sim1.addBody(sun);
    sim1.addBody(earth);

    for (int step = 1; step < 10000; ++step) {
        sim1.update();
        if (step % 1000 == 0) {
            std::cout << "Step " << step << ":\n";
            sim1.printState();
        }
    }

    //Example 2: Use normalized units
    std::cout << "\nSimulation using normalized G = 1.0\n";
    Simulator sim2(0.01, 1.0);  // dt = 0.01, G = 1.0

    // Two equal-mass bodies orbiting each other
    Body bodyA(1.0, {-1.0, 0.0, 0.0}, {0.0, 0.5, 0.0});
    Body bodyB(1.0, {1.0, 0.0, 0.0}, {0.0, -0.5, 0.0});

    sim2.addBody(bodyA);
    sim2.addBody(bodyB);

    for (int step = 1; step < 1000; ++step) {
        sim2.update();
        if (step % 100 == 0) {
            std::cout << "Step " << step << ":\n";
            sim2.printState();
        }
    }

    return 0;
}
