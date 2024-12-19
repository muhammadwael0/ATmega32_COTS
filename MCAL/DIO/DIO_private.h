/*
 *  File Name :   DIO_private.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   MCAL
 *  SWC       :   DIO/GPIO
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Group A */
#define DDRA   *((volatile u8 *) 0x3A)
#define PORTA  *((volatile u8 *) 0x3B)
#define PINA   *((volatile u8 *) 0x39)

/* Group B */
#define DDRB   *((volatile u8 *) 0x37)
#define PORTB  *((volatile u8 *) 0x38)
#define PINB   *((volatile u8 *) 0x36)

/* Group C */
#define DDRC   *((volatile u8 *) 0x34)
#define PORTC  *((volatile u8 *) 0x35)
#define PINC   *((volatile u8 *) 0x33)

/* Group D */
#define DDRD   *((volatile u8 *) 0x31)
#define PORTD  *((volatile u8 *) 0x32)
#define PIND   *((volatile u8 *) 0x30)

/* Special Function I/O */
#define SFIO   *((volatile u8 *) 0x50)

#endif