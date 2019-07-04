#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include "mstn_led.h"
#include "mstn_button.h"
#include "mstn_clk.h"

int main(int argc, char *argv[])
{
    while(1)
    {
        BTN_UserButtonInit();
        LED_SetGreenState(TURN_OFF);
        printf("------Wait for Button Press------\n");
        Delay(500);
        while (BTN_UserButtonRead() != PRESSED)
            ;
        LED_SetGreenState(TURN_ON)
        Delay(1000);
        LED_SetGreenState(TURN_OFF);
    }
    return EXIT_SUCCESS;
}
