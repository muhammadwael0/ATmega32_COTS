/*
 *  File Name :   LCD_program.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   HAL
 *  SWC       :   LCD
 */

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/STD_TYPES.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

#include <delay.h>

LCD_ErrorState LCD_enumInit (void)
{
    DIO_enumSetPinDir(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_DIR_OUTPUT);
    DIO_enumSetPinDir(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_DIR_OUTPUT);

#if LCD_RW_ENABLE == 1
    DIO_enumSetPinDir(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_DIR_OUTPUT);
#elif LCD_RW_ENABLE == 2

#endif
    _delay_ms(40);
#if LCD_MODE == 8

    DIO_enumSetPortDir(LCD_PORT, DIO_PORT_DIR_OUTPUT);

    LCD_voidHome();

    LCD_enumSendCommand(LCD_8BIT);
    _delay_ms(1);

    LCD_enumSendCommand(LCD_DEFAULT);
    _delay_ms(1);

    LCD_voidClear();

    LCD_enumSendCommand(LCD_ENTRY);
    _delay_ms(1);

#elif LCD_MODE == 4
    DIO_enumSetNibbleDir(LCD_PORT, LCD_NIBBLE, DIO_NIBBLE_DIR_OUTPUT);

    LCD_voidHome();

    LCD_enumSendCommand((LCD_4BIT >> 4));
    LCD_enumSendCommand((LCD_4BIT & 0x0F));
    _delay_ms(1);

    LCD_enumSendCommand((LCD_DEFAULT >> 4));
    LCD_enumSendCommand((LCD_DEFAULT & 0x0F));
    _delay_ms(1);

    LCD_voidClear();

    LCD_enumSendCommand((LCD_ENTRY >> 4));
    LCD_enumSendCommand((LCD_ENTRY & 0x0F));
    _delay_ms(1);
#endif
}


LCD_ErrorState LCD_enumSendCommand (u8 LOC_u8command)
{
#if LCD_MODE == 8
    DIO_enumSetPortValue(LCD_PORT, LOC_u8command);
    DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_VALUE_LOW);


#elif LCD_MODE == 4
    DIO_enumSetNibbleValue(LCD_PORT, LCD_NIBBLE, LOC_u8command);
#endif

#if LCD_RW_PIN == 1
    DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_VALUE_LOW);
#elif LCD_RW_PIN == 2

#endif
    LCD_voidEnableLCD();
}


LCD_ErrorState LCD_enumSendData (u8 LOC_u8data)
{
    DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_VALUE_HIGH);

#if LCD_MODE == 8
    DIO_enumSetPortValue(LCD_PORT, LOC_u8data);

#elif LCD_MODE == 4
    DIO_enumSetNibbleValue(LCD_PORT, LCD_NIBBLE, LOC_u8data);
#endif

#if LCD_RW_PIN == 1
    DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_VALUE_LOW);
#elif LCD_RW_PIN == 2

#endif
    LCD_voidEnableLCD();
}


LCD_ErrorState LCD_enumSendString (const u8* LOC_u8PtrString)
{
    u8 LOC_u8Iterator = 0;

    while (LOC_u8PtrString[LOC_u8Iterator] != '\0')
    {
#if LCD_MODE == 8
        LCD_enumSendData(LOC_u8PtrString[LOC_u8Iterator]);
#elif LCD_MODE == 4
        LCD_enumSendData((LOC_u8PtrString[LOC_u8Iterator] >> 4));
        LCD_enumSendData((LOC_u8PtrString[LOC_u8Iterator] & 0x0F));
#endif
        LOC_u8Iterator++;
    }
}


LCD_ErrorState LCD_enumSetPosition (u8 LOC_u8row, u8 LOC_u8col)
{
    u8 LOC_u8data = 0x00;

    if (LOC_u8row > LCD_ROW_2 || LOC_u8row < LCD_ROW_1 || LOC_u8col > LCD_COL_16 || LOC_u8col < LCD_COL_1)
    {
        LOC_u8data = LCD_DDRAM; /* position 0 0 in LCD */
    }
    else if (LOC_u8row == LCD_ROW_1)
    {
        LOC_u8data = LCD_DDRAM + LOC_u8col;
    }
    else if (LOC_u8row == LCD_ROW_2)
    {
        LOC_u8data = LCD_DDRAM + 64 + LOC_u8col;
    }
#if LCD_MODE == 8
    LCD_enumSendCommand(LOC_u8data);
#elif LCD_MODE == 4
    LCD_enumSendCommand((LOC_u8data >> 4));
    LCD_enumSendCommand((LOC_u8data & 0x0F));
#endif
    _delay_ms(1);
}

void LCD_voidClear (void)
{
#if LCD_MODE == 8
    LCD_enumSendCommand(LCD_CLEAR);
#elif LCD_MODE == 4
    LCD_enumSendCommand((LCD_CLEAR >> 4));
    LCD_enumSendCommand((LCD_CLEAR & 0x0F));
#endif
    _delay_ms(5);
}


void LCD_voidHome (void)
{
#if LCD_MODE == 8
    LCD_enumSendCommand(LCD_HOME);
#elif LCD_MODE == 4
    LCD_enumSendCommand((LCD_HOME >> 4));
    LCD_enumSendCommand((LCD_HOME & 0x0F));
#endif
    _delay_ms(5);
}


static void LCD_voidEnableLCD (void)
{
    DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_VALUE_HIGH);
    _delay_ms(1);
    DIO_enumSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_VALUE_LOW);
    _delay_ms(1);
}