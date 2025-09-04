#include "servoComponent.hpp"

ServoComponent::ServoComponent() = default;

ServoComponent::ServoComponent(const int pin) {
    servo.attach(pin);
}

void ServoComponent::setRotation(const int rotation) {
    const long mappedRotation = map(rotation, 0, 1024, 0, 180);
    servo.write(static_cast<int>(mappedRotation));
}

bool ServoComponent::isAttached() {
    return servo.attached();
}