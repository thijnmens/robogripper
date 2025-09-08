#include "../robot.hpp"

Robot::Robot(const int conPin, const int comPin) : confirmPin(conPin), commandPin(comPin) {
    pinMode(conPin, OUTPUT);
    pinMode(comPin, INPUT);
}

void Robot::waitForCommand() const {
    // Wait for command pin to go high
    while (digitalRead(commandPin) == LOW) {
        delay(COMMAND_INTERVAL);
    }

    // Acknowledge command
    digitalWrite(confirmPin, HIGH);

    // Wait for acknowledge to be recieved
    while (digitalRead(commandPin) == HIGH) {
        delay(COMMAND_INTERVAL);
    }

    // Disable acknowledge message
    digitalWrite(confirmPin, LOW);
}

void Robot::sendConfirmation() const {
    // Send confirmation
    digitalWrite(confirmPin, HIGH);

    // Wait for acknowledgement
    while (digitalRead(commandPin) == LOW) {
        delay(COMMAND_INTERVAL);
    }

    // End confirmation message
    digitalWrite(confirmPin, LOW);

    // Wait for acknowledgement message to stop

    while (digitalRead(commandPin) == HIGH) {
        delay(COMMAND_INTERVAL);
    }
}
