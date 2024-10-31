/*
 *  File Name :   DIO_program.c
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   MCAL
 *  SWC       :   DIO/GPIO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <stdio.h>

#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"


DIO_ErrorStatus DIO_enumSetPinDir (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    if (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7)
    {
        if (copy_u8Direction == DIO_PIN_DIR_OUTPUT)
        {
            switch (copy_u8Port) {
                case DIO_PORTA:
                    SET_BIT (DDRA, copy_u8Pin);
                    break;
                case DIO_PORTB:
                    SET_BIT (DDRB, copy_u8Pin);
                    break;
                case DIO_PORTC:
                    SET_BIT (DDRC, copy_u8Pin);
                    break;
                case DIO_PORTD:
                    SET_BIT (DDRD, copy_u8Pin);
                    break;
                default:
                    LOC_enumErrorStatus = DIO_NOK;
            }
        }
        else if (copy_u8Direction == DIO_PIN_DIR_INPUT)
        {
            switch (copy_u8Port) {
                case DIO_PORTA:
                    CLR_BIT (DDRA, copy_u8Pin);
                    break;
                case DIO_PORTB:
                    CLR_BIT (DDRB, copy_u8Pin);
                    break;
                case DIO_PORTC:
                    CLR_BIT (DDRC, copy_u8Pin);
                    break;
                case DIO_PORTD:
                    CLR_BIT (DDRD, copy_u8Pin);
                    break;
                default:
                    LOC_enumErrorStatus = DIO_NOK;
            }
        }
        else
        {
            LOC_enumErrorStatus = DIO_NOK;
        }
    }
    else
    {
        LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}


DIO_ErrorStatus DIO_enumSetPinValue (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    if (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7)
    {
        if (copy_u8Value == DIO_PIN_VALUE_HIGH)
        {
            switch (copy_u8Port) {
                case DIO_PORTA:
                    SET_BIT(PORTA, copy_u8Pin);
                    break;
                case DIO_PORTB:
                    SET_BIT(PORTB, copy_u8Pin);
                    break;
                case DIO_PORTC:
                    SET_BIT(PORTC, copy_u8Pin);
                    break;
                case DIO_PORTD:
                    SET_BIT(PORTD, copy_u8Pin);
                    break;
                default:
                    LOC_enumErrorStatus = DIO_NOK;
            }
        }
        else if (copy_u8Value == DIO_PIN_VALUE_LOW)
        {
            switch (copy_u8Port) {
                case DIO_PORTA:
                    CLR_BIT(PORTA, copy_u8Pin);
                    break;
                case DIO_PORTB:
                    CLR_BIT(PORTB, copy_u8Pin);
                    break;
                case DIO_PORTC:
                    CLR_BIT(PORTC, copy_u8Pin);
                    break;
                case DIO_PORTD:
                    CLR_BIT(PORTD, copy_u8Pin);
                    break;
                default:
                    LOC_enumErrorStatus = DIO_NOK;
            }
        }
        else
        {
            LOC_enumErrorStatus = DIO_NOK;
        }
    }
    else
    {
        LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}


DIO_ErrorStatus DIO_enumReadPinValue (u8 copy_u8Port, u8 copy_u8Pin, u8 *copy_ptrData)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    if (copy_ptrData != NULL)
    {
        if (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7)
        {
            switch (copy_u8Port) {
                case DIO_PORTA:
                    *copy_ptrData = GET_BIT(PINA, copy_u8Pin);
                    break;
                case DIO_PORTB:
                    *copy_ptrData = GET_BIT(PINB, copy_u8Pin);
                    break;
                case DIO_PORTC:
                    *copy_ptrData = GET_BIT(PINC, copy_u8Pin);
                    break;
                case DIO_PORTD:
                    *copy_ptrData = GET_BIT(PIND, copy_u8Pin);
                    break;
                default:
                    LOC_enumErrorStatus = DIO_NOK;
            }
        }
        else
        {
            LOC_enumErrorStatus = DIO_NOK;
        }
    }
    else
    {
        LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}


DIO_ErrorStatus DIO_enumTogglePinValue (u8 copy_u8Port, u8 copy_u8Pin)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    if (copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7)
    {
        switch (copy_u8Port) {
            case DIO_PORTA:
                TOG_BIT(PORTA, copy_u8Pin);
                break;
            case DIO_PORTB:
                TOG_BIT(PORTB, copy_u8Pin);
                break;
            case DIO_PORTC:
                TOG_BIT(PORTC, copy_u8Pin);
                break;
            case DIO_PORTD:
                TOG_BIT(PORTD, copy_u8Pin);
                break;
            default:
                LOC_enumErrorStatus = DIO_NOK;
        }
    }
    else
    {
        LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}


DIO_ErrorStatus DIO_enumSetPortDir (u8 copy_u8Port, u8 copy_u8Direction)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    if (copy_u8Direction >= DIO_PORT_DIR_INPUT && copy_u8Direction <= DIO_PORT_DIR_OUTPUT)
    {
        switch (copy_u8Port) {
            case DIO_PORTA:
                DDRA = copy_u8Direction;
                break;
            case DIO_PORTB:
                DDRB = copy_u8Direction;
                break;
            case DIO_PORTC:
                DDRC = copy_u8Direction;
                break;
            case DIO_PORTD:
                DDRD = copy_u8Direction;
                break;
            default:
                LOC_enumErrorStatus = DIO_NOK;
        }
    }
    else
    {
        LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}


DIO_ErrorStatus DIO_enumSetPortValue (u8 copy_u8Port, u8 copy_u8Value)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    if (copy_u8Value >= DIO_PORT_VALUE_LOW && copy_u8Value <= DIO_PORT_VALUE_HIGH)
    {
        switch (copy_u8Port) {
            case DIO_PORTA:
                PORTA = copy_u8Value;
                break;
            case DIO_PORTB:
                PORTB = copy_u8Value;
                break;
            case DIO_PORTC:
                PORTC = copy_u8Value;
                break;
            case DIO_PORTD:
                PORTD = copy_u8Value;
                break;
            default:
                LOC_enumErrorStatus = DIO_NOK;
        }
    }
    else
    {
        LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}


DIO_ErrorStatus DIO_enumReadPortValue (u8 copy_u8Port, u8 *copy_ptrData)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    if (copy_ptrData != NULL)
    {
        switch (copy_u8Port) {
            case DIO_PORTA:
                *copy_ptrData = PINA;
                break;
            case DIO_PORTB:
                *copy_ptrData = PINB;
                break;
            case DIO_PORTC:
                *copy_ptrData = PINC;
                break;
            case DIO_PORTD:
                *copy_ptrData = PIND;
                break;
            default:
                LOC_enumErrorStatus = DIO_NOK;
        }
    }
    else
    {
        LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}


DIO_ErrorStatus DIO_enumTogglePortValue (u8 copy_u8Port)
{
    DIO_ErrorStatus LOC_enumErrorStatus = DIO_OK;
    switch (copy_u8Port) {
        case DIO_PORTA:
            PORTA = ~PORTA;
            break;
        case DIO_PORTB:
            PORTB = ~PORTB;
            break;
        case DIO_PORTC:
            PORTC = ~PORTC;
            break;
        case DIO_PORTD:
            PORTD = ~PORTD;
            break;
        default:
            LOC_enumErrorStatus = DIO_NOK;
    }
    return LOC_enumErrorStatus;
}
