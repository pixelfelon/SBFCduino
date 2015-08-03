#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

//Atmel ATMega1284 on Skybot Flight Controller v0.1 (SBFC 1)

#define SBFC
#define SBFC_VERSION 1

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  (((p) < NUM_ANALOG_INPUTS) ? (( (p) < 4 ) ? (p) + 28 : 7 - (p) ) : -1)

#ifdef __cplusplus
extern "C"{
#endif
extern const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS];
extern const uint16_t __pcmsk[];
extern const uint8_t digital_pin_to_timer_PGM[NUM_DIGITAL_PINS];
#ifdef __cplusplus
}
#endif

#define ifpin(p,what,ifnot)	    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (what) : (ifnot))
#define digitalPinHasPWM(p)         ifpin(p,pgm_read_byte(digital_pin_to_timer_PGM + (p)) != NOT_ON_TIMER,1==0)

#define digitalPinToAnalogPin(p)    ( (p) >= 0 && (p) <= 3 ? 7 - (p) : ( (p) >= 28 && (p) <= 31 ? (p) - 28 : -1 ) )
#define analogPinToChannel(p)	    ( (p) < NUM_ANALOG_INPUTS ? (p) : -1 )

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 14;
static const uint8_t SCL = 15;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 28;
static const uint8_t A1 = 29;
static const uint8_t A2 = 30;
static const uint8_t A3 = 31;
static const uint8_t A4 = 3;
static const uint8_t A5 = 2;
static const uint8_t A6 = 1;
static const uint8_t A7 = 0;

static const uint8_t RC1 = 20;
static const uint8_t RC2 = 21;
static const uint8_t RC3 = 22;
static const uint8_t RC4 = 23;
static const uint8_t RC5 = 5;
static const uint8_t RC6 = 6;
static const uint8_t RC7 = 12;
static const uint8_t RC8 = 13;

#define digitalPinToPCICR(p)    ifpin(p,&PCICR,(uint8_t *)0)
#define digitalPinToPCICRbit(p) ifpin(p, digital_pin_to_pcint[p] >> 3, 0)
#define digitalPinToPCMSK(p)    ifpin(p,(uint16_t *)__pcmsk[digital_pin_to_pcint[p]],(uint16_t *)0)
#define digitalPinToPCMSKbit(p) ifpin(p, digital_pin_to_pcint[p] & 0x7, 0)

#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS] =
{
  7,  // D0  PA7
  6,  // D1  PA6
  5,  // D2  PA5
  4,  // D3  PA4
  8,  // D4  PB0
  11, // D5  PB3
  12, // D6  PB4
  9,  // D7  PB1
  10, // D8  PB2
  19, // D9  PC3
  18, // D10 PC2
  13, // D11 PB5
  14, // D12 PB6
  15, // D13 PB7
  17, // D14 PC1
  16, // D15 PC0
  24, // D16 PD0
  25, // D17 PD1
  26, // D18 PD2
  27, // D19 PD3
  28, // D20 PD4
  29, // D21 PD5
  30, // D22 PD6
  31, // D23 PD7
  20, // D24 PC4
  21, // D25 PC5
  22, // D26 PC6
  23, // D27 PC7
  0,  // D28 PA0
  1,  // D29 PA1
  2,  // D30 PA2
  3,  // D31 PA3
};

const uint16_t __pcmsk[] = 
{
  (uint16_t)&PCMSK0, 
  (uint16_t)&PCMSK1, 
  (uint16_t)&PCMSK2, 
  (uint16_t)&PCMSK3
};

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[NUM_DIGITAL_PINS] =
{
  PA, // D0
  PA, // D1
  PA, // D2
  PA, // D3
  PB, // D4
  PB, // D5
  PB, // D6
  PB, // D7
  PB, // D8
  PC, // D9
  PC, // D10
  PB, // D11
  PB, // D12
  PB, // D13
  PC, // D14
  PC, // D15
  PD, // D16
  PD, // D17
  PD, // D18
  PD, // D19
  PD, // D20
  PD, // D21
  PD, // D22
  PD, // D23
  PC, // D24
  PC, // D25
  PC, // D26
  PC, // D27
  PA, // D28
  PA, // D29
  PA, // D30
  PA, // D31
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[NUM_DIGITAL_PINS] =
{
  _BV(7), // D0  PA7
  _BV(6), // D1  PA6
  _BV(5), // D2  PA5
  _BV(4), // D3  PA4
  _BV(0), // D4  PB0
  _BV(3), // D5  PB3
  _BV(4), // D6  PB4
  _BV(1), // D7  PB1
  _BV(2), // D8  PB2
  _BV(3), // D9  PC3
  _BV(2), // D10 PC2
  _BV(5), // D11 PB5
  _BV(6), // D12 PB6
  _BV(7), // D13 PB7
  _BV(1), // D14 PC1
  _BV(0), // D15 PC0
  _BV(0), // D16 PD0
  _BV(1), // D17 PD1
  _BV(2), // D18 PD2
  _BV(3), // D19 PD3
  _BV(4), // D20 PD4
  _BV(5), // D21 PD5
  _BV(6), // D22 PD6
  _BV(7), // D23 PD7
  _BV(4), // D24 PC4
  _BV(5), // D25 PC5
  _BV(6), // D26 PC6
  _BV(7), // D27 PC7
  _BV(0), // D28 PA0
  _BV(1), // D29 PA1
  _BV(2), // D30 PA2
  _BV(3), // D31 PA3
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[NUM_DIGITAL_PINS] =
{
  NOT_ON_TIMER, // D0 PD0
  NOT_ON_TIMER, // D1 PD1
  NOT_ON_TIMER, // D2 PD2
  NOT_ON_TIMER, // D3 PD3
  NOT_ON_TIMER, // D4 PB0
  TIMER0A,      // D5 PB1
  TIMER0B,      // D6 PB2
  NOT_ON_TIMER, // D7 PB3
  NOT_ON_TIMER, // D8 PD6
  NOT_ON_TIMER, // D9 PD5
  NOT_ON_TIMER, // D10 PB4
  NOT_ON_TIMER, // D11 PB5
  TIMER3A,      // D12 PB6
  TIMER3B,      // D13 PB7
  NOT_ON_TIMER, // D14 PC7
  NOT_ON_TIMER, // D15 PC6
  NOT_ON_TIMER, // D16 PC5
  NOT_ON_TIMER, // D17 PC4
  NOT_ON_TIMER, // D18 PC3
  NOT_ON_TIMER, // D19 PC2
  TIMER1B,      // D20 PC1
  TIMER1A,      // D21 PC0
  TIMER2B,      // D22 PD4
  TIMER2A,      // D23 PD7
  NOT_ON_TIMER, // D24 PA7
  NOT_ON_TIMER, // D25 PA6
  NOT_ON_TIMER, // D26 PA5
  NOT_ON_TIMER, // D27 PA4
  NOT_ON_TIMER, // D28 PA3
  NOT_ON_TIMER, // D29 PA2
  NOT_ON_TIMER, // D30 PA1
  NOT_ON_TIMER, // D31 PA0
};

#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
// vim:ai:cin:sts=2 sw=2 ft=cpp
