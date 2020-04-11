#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;



void setup(void){



 Leds_Create(&ledsVirtuales);

}



void tearDown(void){

}



void test_LedsOffAfterCreate(void){



 ledsVirtuales = 0xFFFF;

 Leds_Create(&ledsVirtuales);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}



void test_IndividualLedOn(void){



 const uint8_t led = 3;

 Leds_Create(&ledsVirtuales);

 Leds_On(led);

 UnityAssertEqualNumber((UNITY_INT)((1 << (led - 1))), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}



void test_IndividualLedOff(void){



 const uint8_t led = 3;

 Leds_Create(&ledsVirtuales);

 Leds_On(led);

 Leds_Off(led);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}



void test_MultipleLedOnAndOff(void){



 const uint8_t led1 = 3, led2 = 15;

 Leds_Create(&ledsVirtuales);

 Leds_On(led1);

 Leds_On(led2);

 Leds_Off(led1);

 UnityAssertEqualNumber((UNITY_INT)(((1 << led2 - 1))), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

}



void test_AllLedsOn(void){



 uint16_t i = 0;

 Leds_Create(&ledsVirtuales);

 for(i=1;i<17;i++)

 {

  Leds_On(i);

 }

 UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}



void test_AllLedsOff(void){



 uint16_t i = 0;

 Leds_Create(&ledsVirtuales);

 for(i=1;i<17;i++)

 {

  Leds_Off(i);

 }

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

}



void test_LedStatus(void){



 const uint8_t led = 3;

 uint8_t status;

 Leds_Create(&ledsVirtuales);

 Leds_On(led);

 status = Leds_Status(led);



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_INT);

}
