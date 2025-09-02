#include <main.hpp>

ServoComponent servoComponent;

void setup() {
  servoComponent = ServoComponent(SERVO_PIN);
  pinMode(A1, INPUT);

  Serial.begin(115200);
}

void loop() {

  // servoComponent.setRotation(0);
  // delay(5000);

  // servoComponent.setRotation(90);
  // delay(5000);

  int res = analogRead(A1);
  Serial.write(res);
  servoComponent.setRotation(res);

}
