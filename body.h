#pragma once
#include <array>
#include <string>

class Body {
private:
    double mass_;
    std::array<double, 3> position_;
    std::array<double, 3> velocity_;
    std::array<double, 3> acceleration_;

public:
    Body();
    Body(double mass, const std::array<double, 3>& position,
         const std::array<double, 3>& velocity);

    double getMass() const { return mass_; }
    const std::array<double, 3>& getPosition() const { return position_; }
    const std::array<double, 3>& getVelocity() const { return velocity_; }
    const std::array<double, 3>& getAcceleration() const { return acceleration_; }

    void setMass(double mass) { mass_ = mass; }
    void setPosition(const std::array<double, 3>& position) { position_ = position; }
    void setVelocity(const std::array<double, 3>& velocity) { velocity_ = velocity; }
    void setAcceleration(const std::array<double, 3>& acceleration) { acceleration_ = acceleration; }

    void updatePosition(double dt);
    void updateVelocity(double dt);
    void resetAcceleration();
    std::string toString() const;
};
