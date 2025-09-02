#include "PressureSensorComponent.hpp"

PressureSensorComponent::PressureSensorComponent() {
    pin = 0;
}

PressureSensorComponent::PressureSensorComponent(const int pin) {
    pinMode(pin, INPUT);
    PressureSensorComponent::pin = pin;
}

int PressureSensorComponent::getPressure() const {
    return analogRead(pin);
}
