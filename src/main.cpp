#include <main.hpp>

ServoComponent servoComponent;
PressureSensorComponent pressureSensorComponent;
Robot robot;

void setup() {
    servoComponent = ServoComponent(SERVO_PIN);
    pressureSensorComponent = PressureSensorComponent(PRESSURE_PIN);
    robot = Robot(CONFIRM_PIN, COMMAND_PIN);

    Serial.begin(115200);
}

void loop() {
    // Open cage on command
    robot.waitForCommand();
    servoComponent.setRotation(70);
    robot.sendConfirmation();

    // delay(5000);

    // Close cage on command
    robot.waitForCommand();
    servoComponent.setRotation(95);
    robot.sendConfirmation();

    // delay(5000);
}