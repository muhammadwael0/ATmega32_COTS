/*
 *  File Name :   BUZ_interface.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   HAL
 *  SWC       :   BUZZER
 */

#ifndef BUZ_INTERFACE_H_
#define BUZ_INTERFACE_H_

/* BUZ PORTS */
#define BUZ_PORTA 0
#define BUZ_PORTB 1
#define BUZ_PORTC 2
#define BUZ_PORTD 3

/* BUZ PINS */
#define BUZ_PIN0 0
#define BUZ_PIN1 1
#define BUZ_PIN2 2
#define BUZ_PIN3 3
#define BUZ_PIN4 4
#define BUZ_PIN5 5
#define BUZ_PIN6 6
#define BUZ_PIN7 7

/* BUZ CONNECTION */
#define BUZ_ACTIVE_LOW   0
#define BUZ_ACTIVE_HIGH  1

/* BUZ TYPE */
typedef struct {
    u8 port;
    u8 pin;
    u8 connectionState;
} BUZ_Type;

/* ERROR STATE */
typedef enum {
    BUZ_NOK,
    BUZ_OK
} BUZ_ErrorState;

/* BUZ FUNCTIONS */
BUZ_ErrorState BUZ_enumInitLed  (BUZ_Type BUZ_Configuration);
BUZ_ErrorState BUZ_enumTurnOn   (BUZ_Type BUZ_Configuration);
BUZ_ErrorState BUZ_enumTurnOff  (BUZ_Type BUZ_Configuration);
BUZ_ErrorState BUZ_enumToggle   (BUZ_Type BUZ_Configuration);


#endif