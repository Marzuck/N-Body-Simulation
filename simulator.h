#pragma once
#include "body.h"
#include <vector>

class Simulator {
private:
    std::vector<Body> bodies_;
    double G_;
    double dt_;

public:
    Simulator(double dt, double G);
    explicit Simulator(double dt);

    void addBody(const Body& body);

    std::vector<Body>& getBodies();
    const std::vector<Body>& getBodies() const;

    void computeForces();
    void update();

    void printState() const;
};