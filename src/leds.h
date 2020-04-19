#include <stdint.h>

void Leds_Create(uint16_t *direccion);

void Leds_On(uint8_t led);

void Leds_Off(uint8_t led);

uint8_t Leds_Status (uint8_t led);

uint16_t Leds_Bits(uint8_t led);

void Leds_TurnAllOn(void);

void Leds_TurnAllOff(void); 
