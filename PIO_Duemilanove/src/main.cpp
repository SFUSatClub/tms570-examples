#include <Arduino.h>

char buf [100];
volatile byte pos;
volatile boolean process_it;

void setup (void) {
	Serial.begin(9600);
	Serial.println("OBC SPI Testing");

	// master in, *slave out*
	pinMode(MISO, OUTPUT);

	// turn on SPI in slave mode
	SPCR |= _BV(SPE);

	// turn on interrupts
	SPCR |= _BV(SPIE);

	pos = 0;
	process_it = false;
}

// SPI interrupt routine
ISR (SPI_STC_vect) {
	byte c = SPDR;
	Serial.println((char)c);
	Serial.println(c);

	// add to buffer if room
	if (pos < sizeof buf) {
		buf [pos++] = c;

		// example: newline means time to process buffer
		if (c == '\n')
			process_it = true;

	} else {
		process_it = true;
	}
}

void loop (void) {
	if (process_it) {
		buf[pos] = 0;  
		//Serial.println(buff);
		pos = 0;
		process_it = false;
	}
}

/* const int csPin = 10; */

/* void setup() { */
/* 	Serial.begin(9600); */
/* 	SPI.begin(); */
/* 	SPI.setBitOrder(MSBFIRST); //We know this from the Data Sheet */

/* 	pinMode(csPin,OUTPUT); */
/* 	digitalWrite(csPin, HIGH); */
/* 	Serial.println("OBC SPI Testing"); */
/* } */

/* void obcWrite(int address, int value) { */
/* 	digitalWrite(csPin, LOW); //select slave */
/* 	byte command = 0xB0; //0xB0 = 10110000 */ 
/* 	command += address; */ 
/* 	SPI.transfer(command); */ 
/* 	byte byte1 = (value >> 8); */
/* 	byte byte0 = (value & 0xFF); //0xFF = B11111111 */
/* 	SPI.transfer(byte1); */
/* 	SPI.transfer(byte0); */
/* 	digitalWrite(csPin, HIGH); //de-select slave */
/* } */

/* void loop() { */
/* 	for(int i=0; i<1023; i++) { */ 
/* 		obcWrite(0,i); */
/* 		delay(10); */
/* 	} */ 
/* } */

