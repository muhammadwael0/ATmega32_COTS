/*
 *  File Name :   BUZ_program.c
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   HAL
 *  SWC       :   BUZZER
 */


#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "BUZ_interface.h"
#include "BUZ_config.h"
#include "BUZ_private.h"


BUZ_ErrorState BUZ_enumInitLed (BUZ_Type BUZ_Configuration)
{
    BUZ_ErrorState LOC_ErrorState = BUZ_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    LOC_DIO_ErrorState = DIO_enumSetPinDir(BUZ_Configuration.port, BUZ_Configuration.pin, DIO_PIN_DIR_OUTPUT);
    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = BUZ_OK;
    }
    else
    {
        LOC_ErrorState = BUZ_NOK;
    }

    return LOC_ErrorState;
}


BUZ_ErrorState BUZ_enumTurnOn (BUZ_Type BUZ_Configuration)
{
    BUZ_ErrorState LOC_ErrorState = BUZ_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    if (BUZ_Configuration.connectionState == BUZ_ACTIVE_HIGH)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(BUZ_Configuration.port, BUZ_Configuration.pin, DIO_PIN_VALUE_HIGH);
    }
    else if (BUZ_Configuration.connectionState == BUZ_ACTIVE_LOW)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(BUZ_Configuration.port, BUZ_Configuration.pin, DIO_PIN_VALUE_LOW);
    }
    else
    {
        LOC_DIO_ErrorState = DIO_NOK;
    }

    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = BUZ_OK;
    }
    else
    {
        LOC_ErrorState = BUZ_NOK;
    }

    return LOC_ErrorState;
}


BUZ_ErrorState BUZ_enumTurnOff (BUZ_Type BUZ_Configuration)
{
    BUZ_ErrorState LOC_ErrorState = BUZ_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    if (BUZ_Configuration.connectionState == BUZ_ACTIVE_HIGH)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(BUZ_Configuration.port, BUZ_Configuration.pin, DIO_PIN_VALUE_LOW);
    }
    else if (BUZ_Configuration.connectionState == BUZ_ACTIVE_LOW)
    {
        LOC_DIO_ErrorState = DIO_enumSetPinValue(BUZ_Configuration.port, BUZ_Configuration.pin, DIO_PIN_VALUE_HIGH);
    }
    else
    {
        LOC_DIO_ErrorState = DIO_NOK;
    }

    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = BUZ_OK;
    }
    else
    {
        LOC_ErrorState = BUZ_NOK;
    }

    return LOC_ErrorState;
}


BUZ_ErrorState BUZ_enumToggle   (BUZ_Type BUZ_Configuration)
{
    BUZ_ErrorState LOC_ErrorState = BUZ_OK;
    DIO_ErrorStatus LOC_DIO_ErrorState = DIO_OK;

    LOC_DIO_ErrorState = DIO_enumTogglePinValue(BUZ_Configuration.port, BUZ_Configuration.pin);

    if (LOC_DIO_ErrorState == DIO_OK)
    {
        LOC_ErrorState = BUZ_OK;
    }
    else
    {
        LOC_ErrorState = BUZ_NOK;
    }

    return LOC_ErrorState;
}
