/*
• Después de la inicialización todos los LEDs deben quedar apagados.
• Se puede prender un LED individual.
• Se puede apagar un LED individual.
• Se pueden prender y apagar múltiples LED’s.
• Se pueden prender todos los LEDs de una vez.
• Se pueden apagar todos los LEDs de una vez.
• Se puede consultar el estado de un LED.
• Revisar limites de los parametros.
• Revisar parámetros fuera de los limites.
 */

#include "unity.h"
#include "leds.h"

static uint16_t ledsVirtuales;

void setup(void){

	Leds_Create(&ledsVirtuales);
}

void tearDown(void){
}

void test_LedsOffAfterCreate(void){

	ledsVirtuales = 0xFFFF;
	Leds_Create(&ledsVirtuales);
	TEST_ASSERT_EQUAL(0, ledsVirtuales);	
}

void test_IndividualLedOn(void){

	const uint8_t led = 3;
	Leds_Create(&ledsVirtuales);
	Leds_On(led);
	TEST_ASSERT_EQUAL(1 << (led - 1), ledsVirtuales);
}

void test_IndividualLedOff(void){

	const uint8_t led = 3;
	Leds_Create(&ledsVirtuales);
	Leds_On(led);
	Leds_Off(led);
	TEST_ASSERT_EQUAL(0, ledsVirtuales);
}

void test_MultipleLedOnAndOff(void){

	const uint8_t led1 = 3, led2 = 15;
	Leds_Create(&ledsVirtuales);
	Leds_On(led1);
	Leds_On(led2);
	Leds_Off(led1);
	TEST_ASSERT_EQUAL((1 << led2 - 1), ledsVirtuales);
}

void test_AllLedsOn(void){

	uint16_t i = 0;
	Leds_Create(&ledsVirtuales);
	for(i=1;i<17;i++)
	{
		Leds_On(i);
	}
	TEST_ASSERT_EQUAL(0xFFFF, ledsVirtuales);
}

void test_AllLedsOff(void){

	uint16_t i = 0;
	Leds_Create(&ledsVirtuales);
	for(i=1;i<17;i++)
	{
		Leds_Off(i);
	}
	TEST_ASSERT_EQUAL(0, ledsVirtuales);
}

void test_LedStatus(void){

	const uint8_t led = 3;
	uint8_t status;
	Leds_Create(&ledsVirtuales);
	Leds_On(led);
	status = Leds_Status(led);

	TEST_ASSERT_EQUAL(1, status);
}

