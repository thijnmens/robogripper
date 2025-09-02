#include "PressureSensorComponent.hpp"

PressureSensorComponent::PressureSensorComponent() = default;

PressureSensorComponent::PressureSensorComponent(const int pin) {
    pinMode(pin, INPUT);
    PressureSensorComponent::pin = pin;
}

int PressureSensorComponent::getPressure() const {
    return analogRead(pin);
}
