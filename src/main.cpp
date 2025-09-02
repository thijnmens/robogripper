#include <main.hpp>

ServoComponent servoComponent;

void setup() {
  servoComponent = ServoComponent(SERVO_PIN);
  pinMode(A1, INPUT);

  Serial.begin(115200);
}

void loop() {

  const int res = analogRead(A1);
  Serial.write(res);
  servoComponent.setRotation(res);

}
