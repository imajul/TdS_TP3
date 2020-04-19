#include "leds.h"

#define ALL_OFF 0
#define ALL_ON 0xFFFF

static uint16_t *leds;

uint16_t Leds_Bits(uint8_t led)
{
	return (1 << led - 1);
}

void Leds_Create(uint16_t *direccion)
{
	leds = direccion;
	*direccion = 0;
}

void Leds_On(uint8_t led)
{
	*leds |= Leds_Bits(led);
}

void Leds_Off(uint8_t led)
{
	*leds &= ~Leds_Bits(led);
}

void Leds_TurnAllOn(void)
{
	*leds = ALL_ON;
}

void Leds_TurnAllOff(void)
{
	*leds = ALL_OFF;
}

uint8_t Leds_Status(uint8_t led)
{
	return (*leds &= Leds_Bits(led)) >> (led - 1);
}
