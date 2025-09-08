#pragma once
#ifndef A0
#include <Arduino.h>
#endif

class PressureSensorComponent {
public:
    PressureSensorComponent();

    /// @brief Creates a PressureSensorComponent and attaches it to a pin
    /// @param p The analog pin the pressure sensor is physically connected to
    explicit PressureSensorComponent(int p);

    /// @brief Gets the current pressure value of the sensor
    /// @return Int between 0 and 1024, where 0 is no pressure and 1024 is maximum pressure
    int getPressure() const;

private:
    int pin;
};
