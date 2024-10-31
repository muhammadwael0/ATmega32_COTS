/*
 *  File Name :   LED_interface.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   HAL
 *  SWC       :   LED
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* LED PORTS */
#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

/* LED PINS */
#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

/* LED CONNECTION */
#define LED_ACTIVE_LOW   0
#define LED_ACTIVE_HIGH  1

/* LED TYPE */
typedef struct {
    u8 port;
    u8 pin;
    u8 connectionState;
} LED_Type;

/* ERROR STATE */
typedef enum {
    LED_NOK,
    LED_OK
} LED_ErrorState;

/* LED FUNCTIONS */
LED_ErrorState LED_enumInitLed  (LED_Type LED_Configuration);
LED_ErrorState LED_enumTurnOn   (LED_Type LED_Configuration);
LED_ErrorState LED_enumTurnOff  (LED_Type LED_Configuration);
LED_ErrorState LED_enumToggle   (LED_Type LED_Configuration);


#endif