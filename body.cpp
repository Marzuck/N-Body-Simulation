#include "body.h"
#include <sstream>
#include <iomanip>

Body::Body()
    : mass_(0.0), position_({0.0, 0.0, 0.0}),
      velocity_({0.0, 0.0, 0.0}), acceleration_({0.0, 0.0, 0.0}) {}

Body::Body(double mass, const std::array<double, 3>& position,
           const std::array<double, 3>& velocity)
    : mass_(mass), position_(position), velocity_(velocity), acceleration_({0.0, 0.0, 0.0}) {}

void Body::updatePosition(double dt) {
    for (int i = 0; i < 3; ++i)
        position_[i] += velocity_[i] * dt + 0.5 * acceleration_[i] * dt * dt;
}

void Body::updateVelocity(double dt) {
    for (int i = 0; i < 3; ++i)
        velocity_[i] += acceleration_[i] * dt;
}

void Body::resetAcceleration() {
    acceleration_ = {0.0, 0.0, 0.0};
}

std::string Body::toString() const {
    std::ostringstream ss;
    ss << std::scientific << std::setprecision(6);
    ss << "Mass: " << mass_
       << " | Pos: (" << position_[0] << ", " << position_[1] << ", " << position_[2] << ")"
       << " | Vel: (" << velocity_[0] << ", " << velocity_[1] << ", " << velocity_[2] << ")"
       << " | Acc: (" << acceleration_[0] << ", " << acceleration_[1] << ", " << acceleration_[2] << ")";
    return ss.str();
}
