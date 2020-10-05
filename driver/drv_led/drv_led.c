#include <wiringPi.h>

int main(void) {

	// Red LED: Physical pin 18, BCM GPIO24, and WiringPi pin 5.
	// const int led = 22; // green
	const int led = 23; // yellow

	wiringPiSetup();

	pinMode(led, OUTPUT);

	while (1) {
		digitalWrite(led, HIGH);
		delay(500);
		digitalWrite(led, LOW);
		delay(500);
	}

	return 0;
}
