#include "PressureSensorComponent.hpp"

PressureSensorComponent::PressureSensorComponent() : pin(0) {
}

PressureSensorComponent::PressureSensorComponent(const int p) : pin(p) {
    pinMode(p, INPUT);
}

int PressureSensorComponent::getPressure() const {
    return analogRead(pin);
}