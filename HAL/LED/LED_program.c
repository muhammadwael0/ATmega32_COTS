/*
 *  File Name :   LED_program.c
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   HAL
 *  SWC       :   LED
 */


#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


LED_ErrorState LED_enumInitLed (LED_Type LED_Configuration)
{
    LED_ErrorState LOC_ErrorState = LED_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    LOC_DIO_ErrorState = DIO_enumSetPinDir(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_DIR_OUTPUT);
    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = LED_OK;
    }
    else
    {
        LOC_ErrorState = LED_NOK;
    }

    return LOC_ErrorState;
}


LED_ErrorState LED_enumTurnOn (LED_Type LED_Configuration)
{
    LED_ErrorState LOC_ErrorState = LED_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    if (LED_Configuration.connectionState == LED_ACTIVE_HIGH)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_VALUE_HIGH);
    }
    else if (LED_Configuration.connectionState == LED_ACTIVE_LOW)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_VALUE_LOW);
    }
    else
    {
        LOC_DIO_ErrorState = DIO_NOK;
    }

    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = LED_OK;
    }
    else
    {
        LOC_ErrorState = LED_NOK;
    }

    return LOC_ErrorState;
}
LED_ErrorState LED_enumTurnOff (LED_Type LED_Configuration)
{
    LED_ErrorState LOC_ErrorState = LED_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    if (LED_Configuration.connectionState == LED_ACTIVE_HIGH)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_VALUE_LOW);
    }
    else if (LED_Configuration.connectionState == LED_ACTIVE_LOW)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_VALUE_HIGH);
    }
    else
    {
        LOC_DIO_ErrorState = DIO_NOK;
    }

    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = LED_OK;
    }
    else
    {
        LOC_ErrorState = LED_NOK;
    }

    return LOC_ErrorState;
}

LED_ErrorState LED_enumToggle (LED_Type LED_Configuration)
{
    LED_ErrorState LOC_ErrorState = LED_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    LOC_DIO_ErrorState = DIO_enumTogglePinValue(LED_Configuration.port, LED_Configuration.pin);

    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = LED_OK;
    }
    else
    {
        LOC_ErrorState = LED_NOK;
    }

    return LOC_ErrorState;
}