/*
 *  File Name :   LCD_config.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   HAL
 *  SWC       :   LCD
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_MODE                8

/*  Data Configuration  */
#define LCD_PORT                DIO_PORTA


/*  Control Configuration  */
#define LCD_CONTROL_PORT        DIO_PORTC
#define LCD_RS_PIN              DIO_PIN7
#define LCD_EN_PIN              DIO_PIN6

#define LCD_RW_ENABLE           1        /*  1 -> for enable  2 -> for disable  */

#if LCD_RW_ENABLE == 1
    #define LCD_RW_PIN          DIO_PIN0

#elif LCD_RW_ENABLE == 2

#else
#error "LCD Not Configured"
#endif

#if LCD_MODE == 4
#define LCD_NIBBLE DIO_NIBBLE_UPPER

#elif LCD_MODE == 8

#else
    #error "LCD Not Configured"

#endif


#endif