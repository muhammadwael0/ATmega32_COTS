/*
 *  File Name :   DIO_interface.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   MCAL
 *  SWC       :   DIO/GPIO
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/* DIO ERROR STATUS */
typedef enum {
    DIO_NOK,
    DIO_OK
} DIO_ErrorStatus;

/* PUD PIN in SFIO */
#define PUD 2

/* DIRECTIONS OF PINS */
#define DIO_PIN_DIR_OUTPUT  1
#define DIO_PIN_DIR_INPUT   0

/* DIRECTIONS OF PORTS */
#define DIO_PORT_DIR_OUTPUT  0xFF
#define DIO_PORT_DIR_INPUT   0x00

/* DIRECTIONS OF NIBBLES */
#define DIO_NIBBLE_DIR_OUTPUT  0xF
#define DIO_NIBBLE_DIR_INPUT   0x0

/* PORTS */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/* PINS */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/* VALUES OF PINS */
#define DIO_PIN_VALUE_HIGH  1
#define DIO_PIN_VALUE_LOW   0

/* VALUES OF PORTS */
#define DIO_PORT_VALUE_HIGH  0xFF
#define DIO_PORT_VALUE_LOW   0x00

/* VALUES OF NIBBLES */
#define DIO_NIBBLE_VALUE_HIGH  0xF
#define DIO_NIBBLE_VALUE_LOW   0x0

/* NIBBLE TYPE */
#define DIO_NIBBLE_UPPER  0
#define DIO_NIBBLE_LOWER  1


/* DIO PIN FUNCTIONS */
DIO_ErrorStatus DIO_enumSetPinDir       (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPinValue     (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value    );
DIO_ErrorStatus DIO_enumReadPinValue    (u8 copy_u8Port, u8 copy_u8Pin, u8 *copy_ptrData   );
DIO_ErrorStatus DIO_enumTogglePinValue  (u8 copy_u8Port, u8 copy_u8Pin                     );

/* DIO PORT FUNCTIONS */
DIO_ErrorStatus DIO_enumSetPortDir      (u8 copy_u8Port, u8 copy_u8Direction );
DIO_ErrorStatus DIO_enumSetPortValue    (u8 copy_u8Port, u8 copy_u8Value     );
DIO_ErrorStatus DIO_enumReadPortValue   (u8 copy_u8Port, u8 *copy_ptrData    );
DIO_ErrorStatus DIO_enumTogglePortValue (u8 copy_u8Port                      );

/* DIO NIBBLE FUNCTIONS */
DIO_ErrorStatus DIO_enumSetNibbleDir      (u8 copy_u8Port, u8 copy_u8NibbleType, u8 copy_u8Direction );
DIO_ErrorStatus DIO_enumSetNibbleValue    (u8 copy_u8Port, u8 copy_u8NibbleType, u8 copy_u8Value     );
DIO_ErrorStatus DIO_enumReadNibbleValue   (u8 copy_u8Port, u8 copy_u8NibbleType, u8 *copy_ptrData    );
DIO_ErrorStatus DIO_enumToggleNibbleValue (u8 copy_u8Port, u8 copy_u8NibbleType                      );

/* DIO INTERNAL PULL-UP FUNCTIONS */
DIO_ErrorStatus DIO_enumEnableInternalPullUp      (u8 copy_u8Port, u8 copy_u8Pin );
DIO_ErrorStatus DIO_enumDisableInternalPullUp     (u8 copy_u8Port, u8 copy_u8Pin );
DIO_ErrorStatus DIO_enumDisableAllInternalPullUp  (void                          );

#endif