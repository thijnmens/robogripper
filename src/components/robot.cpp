#include "robot.hpp"

Robot::Robot() : confirmPin(0), commandPin(0) {
}

Robot::Robot(const int conPin, const int comPin) : confirmPin(conPin), commandPin(comPin) {
    pinMode(conPin, OUTPUT);
    pinMode(comPin, INPUT);
}

void Robot::waitForCommand() const {
    Serial.println("Waiting for command...");

    // Wait for command pin to go high
    while (digitalRead(commandPin) == LOW) {
        delay(COMMAND_INTERVAL);
    }

    Serial.println("Command recieved, writing ack");

    // Acknowledge command
    digitalWrite(confirmPin, HIGH);

    // Wait for acknowledge to be recieved
    while (digitalRead(commandPin) == HIGH) {
        delay(COMMAND_INTERVAL);
    }

    Serial.println("Ack recieved, command recieved succesfully");

    // Disable acknowledge message
    digitalWrite(confirmPin, LOW);
}

void Robot::sendConfirmation() const {
    Serial.println("Sending confirmation...");

    // Send confirmation
    digitalWrite(confirmPin, HIGH);

    // Wait for acknowledgement
    while (digitalRead(commandPin) == LOW) {
        delay(COMMAND_INTERVAL);
    }

    Serial.println("Ack recieved, cancelling");

    // End confirmation message
    digitalWrite(confirmPin, LOW);

    // Wait for acknowledgement message to stop
    while (digitalRead(commandPin) == HIGH) {
        delay(COMMAND_INTERVAL);
    }

    Serial.println("Ack dissapeared, confirmation succesfull");
}
