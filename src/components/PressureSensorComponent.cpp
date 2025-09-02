#include "PressureSensorComponent.hpp"

PressureSensorComponent::PressureSensorComponent() : pin(0) {
}

PressureSensorComponent::PressureSensorComponent(const int pin) : pin(pin) {
    pinMode(pin, INPUT);
}

int PressureSensorComponent::getPressure() const {
    return analogRead(pin);
}
