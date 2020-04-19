#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;



void setUp(void)

{

 Leds_Create(&ledsVirtuales);

 Leds_Create(&ledsVirtuales);

}



void tearDown(void)

{



}



void test_LedsOffAfterCreate(void)

{

 uint16_t ledsVirtuales = 0xFFFF;

 Leds_Create(&ledsVirtuales);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_IndividualLedOn(void)

{

 const uint8_t led = 3;

 Leds_On(led);

 UnityAssertEqualNumber((UNITY_INT)((1 << (led - 1))), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}



void test_IndividualLedOff(void)

{

 const uint8_t led = 3;

 Leds_On(led);

 Leds_Off(led);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}



void test_MultipleLedOnAndOff(void)

{

 const uint8_t led1 = 3, led2 = 15;

 Leds_On(led1);

 Leds_On(led2);

 Leds_Off(led1);

 UnityAssertEqualNumber((UNITY_INT)(((1 << led2 - 1))), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

}



void test_AllLedsOn(void)

{

 Leds_TurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

}



void test_AllLedsOff(void)

{

 Leds_TurnAllOff();

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}



void test_LedStatus(void)

{

 const uint8_t led1 = 3, led2 = 15;

 Leds_On(led1);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((Leds_Status(led1))), (

((void *)0)

), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((Leds_Status(led2))), (

((void *)0)

), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

}
