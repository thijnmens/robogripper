    #include <main.hpp>

    ServoComponent servoComponent;
    PressureSensorComponent pressureSensorComponent;

    void setup() {
        servoComponent = ServoComponent(SERVO_PIN);
        pressureSensorComponent = PressureSensorComponent(PRESSURE_PIN);

        Serial.begin(115200);
    }

    void loop() {
        const int res = pressureSensorComponent.getPressure();
        servoComponent.setRotation(res);
        Serial.println(res);
    }