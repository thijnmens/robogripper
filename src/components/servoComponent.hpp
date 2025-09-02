#ifndef A0
	#include <Arduino.h>
#endif

#ifndef Servo
	#include <Servo.h>
#endif


class ServoComponent {
	public:
		ServoComponent();
		/// @brief Attaches the servo to a pin
		/// @param Pin The analog pin the servo should be attached to
		ServoComponent(int);

		/// @brief Sets the rotation of the servo
		/// @param Rotation in degrees
		void setRotation(int);

		/// @brief Returns if the Servo Component has an attached pin
		/// @return True if attached
		bool isAttached();
	private:
		Servo servo;
};