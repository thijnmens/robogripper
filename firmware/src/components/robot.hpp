#pragma once

#ifndef A0
#include "Arduino.h"
#endif

#define COMMAND_INTERVAL 25

class Robot {
public:
    explicit Robot(int conPin, int comPin);

    /// @brief blocks the thread until a new command has been recieved from the robot
    void waitForCommand() const;

    /// @brief Sends a confirmation message to the robot that the previous command has been succcesfully executed
    void sendConfirmation() const;

private:
    const int confirmPin;
    const int commandPin;
};
