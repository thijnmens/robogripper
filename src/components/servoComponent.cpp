#include "servoComponent.hpp"

ServoComponent::ServoComponent() {
}

ServoComponent::ServoComponent(int pin)
{
	servo.attach(pin);
}

void ServoComponent::setRotation(int rotation) {
	servo.write(map(rotation, 0, 1024, 0, 180));
}

bool ServoComponent::isAttached()
{
	return servo.attached();
}