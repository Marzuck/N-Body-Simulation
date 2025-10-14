#include "simulator.h"
#include <iostream>
#include <cmath>

Simulator::Simulator(double dt, double G)
    : dt_(dt), G_(G) {}

Simulator::Simulator(double dt)
    : Simulator(dt, 6.67430e-11) {}

void Simulator::addBody(const Body& body) {
    bodies_.push_back(body);
}

std::vector<Body>& Simulator::getBodies() {
    return bodies_;
}

const std::vector<Body>& Simulator::getBodies() const {
    return bodies_;
}

void Simulator::computeForces() {
    for (auto& body : bodies_)
        body.resetAcceleration();

    for (size_t i = 0; i < bodies_.size(); ++i) {
        for (size_t j = i + 1; j < bodies_.size(); ++j) {
            const auto& r_i = bodies_[i].getPosition();
            const auto& r_j = bodies_[j].getPosition();

            double m_i = bodies_[i].getMass();
            double m_j = bodies_[j].getMass();

            std::array<double, 3> r;
            for (int k = 0; k < 3; ++k)
                r[k] = r_j[k] - r_i[k];

            double distSq = r[0]*r[0] + r[1]*r[1] + r[2]*r[2];
            double dist = std::sqrt(distSq) + 1e-9;  // to avoid division by zero
            double force = G_ * m_i * m_j / distSq;

            auto acc_i = bodies_[i].getAcceleration();
            auto acc_j = bodies_[j].getAcceleration();

            for (int k = 0; k < 3; ++k) {
                double f = force * r[k] / dist;
                acc_i[k] += f / m_i;
                acc_j[k] -= f / m_j;
            }

            bodies_[i].setAcceleration(acc_i);
            bodies_[j].setAcceleration(acc_j);
        }
    }
}

void Simulator::update() {
    computeForces();

    for (auto& body : bodies_) {
        body.updateVelocity(dt_);
        body.updatePosition(dt_);
    }
}

void Simulator::printState() const {
    for (const auto& body : bodies_) {
        std::cout << body.toString() << "\n";
    }
    std::cout << "--------------------------------\n";
}
