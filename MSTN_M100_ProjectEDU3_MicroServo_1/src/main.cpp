#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include "mstn_led.h"
#include "mstn_usb.h"
#include "mstn_pwm.h"

#define LEFT_IMPLEN     620
#define MIDDLE_IMPLEN   1500
#define RIGHT_IMPLEN    2520

#define SERVO_PIN       D1

int main(int argc, char *argv[])
{
    int impDurat = 0;
    LED_SetGreenState(TURN_ON);
    PWM_SetFreq(PWMFREQ_50HZ);
    while(USB_GetStatus() != PERMITTED);
    while(1)
    {
        printf("Input duration (us):\n");
        if (scanf("%d", &impDurat) == 0) 
        {
            printf("Input error!\n");
            fseek(stdin,0,SEEK_END);
            impDurat = 0;
        }
        PWM_AnalogWrite(SERVO_PIN, ((impDurat*10)/4));
    }
    return EXIT_SUCCESS;
}
