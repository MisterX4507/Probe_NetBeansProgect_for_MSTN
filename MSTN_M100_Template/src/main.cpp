#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "mstn_version.h"
#include "mstn_led.h"
#include "mstn_clk.h"
#include "mstn_usb.h"

int main(int argc, char *argv[])
{
    uint32_t waitTime = 0;
    const _mstn_version * mstnSdkVersion = NULL;
    const _mstn_version * mstnBootVersion = NULL;
    const _mstn_serial_number * mstnSerialNumber = NULL;
    LED_SetGreenState(TURN_ON);
    mstnSdkVersion = MSTN_GetLibVersion();
    mstnBootVersion = MSTN_GetBootloaderVersion();
    mstnSerialNumber = MSTN_GetSerialNumber();
    while(USB_GetStatus() != PERMITTED);
    printf("Hello World!\n");
    printf("Serial Number: %u\n", mstnSerialNumber->serialNumber);
    printf("Bootloader version:   %u.%u.%u\n",
                                                mstnBootVersion->major,
                                                mstnBootVersion->minor,
                                                mstnBootVersion->build);
    printf("MSTN Library version: %u.%u.%u\n",
                                                mstnSdkVersion->major,
                                                mstnSdkVersion->minor,
                                                mstnSdkVersion->build);
    while(1)
    {
        printf("Input waitTime (ms):\n");
        scanf("%lu", &waitTime);
        printf("You inputed %" PRIu32 "ms.\n", waitTime);
        LED_SetGreenState(TURN_OFF);
        LED_SetRedState(TURN_ON);
        Delay(waitTime);
        LED_SetRedState(TURN_OFF);
        LED_SetGreenState(TURN_ON);
    }
    return EXIT_SUCCESS;
}
