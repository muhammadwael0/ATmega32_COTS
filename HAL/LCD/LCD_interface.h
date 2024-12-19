/*
 *  File Name :   LCD_interface.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   HAL
 *  SWC       :   LCD
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/* LCD ROWs */
#define LCD_ROW_1 0
#define LCD_ROW_2 1

/* LCD COLUMNs */
#define LCD_COL_1    0
#define LCD_COL_2    1
#define LCD_COL_3    2
#define LCD_COL_4    3
#define LCD_COL_5    4
#define LCD_COL_6    5
#define LCD_COL_7    6
#define LCD_COL_8    7
#define LCD_COL_9    8
#define LCD_COL_10   9
#define LCD_COL_11  10
#define LCD_COL_12  11
#define LCD_COL_13  12
#define LCD_COL_14  13
#define LCD_COL_15  14
#define LCD_COL_16  15

/* LCD COMMANDs */
#define LCD_HOME          0x02
#define LCD_ENTRY         0x06
#define LCD_CLEAR         0x01
#define LCD_8BIT          0x38
#define LCD_4BIT          0x28
#define LCD_CGRAM         0x40
#define LCD_DDRAM         0x80
#define LCD_BLINK         0x09
#define LCD_CURSOR        0x0A
#define LCD_DISPLAY       0x0C
#define LCD_NO_BCD        0x08  /* No Blink Cursor Display (No BCD) */
#define LCD_DEFAULT      (LCD_BLINK | LCD_CURSOR | LCD_DISPLAY)

/* LED TYPE */
typedef struct {
    u8 port;
    u8 pin;
    u8 connectionState;
} LED_Type;

/* ERROR STATE */
typedef enum {
    LCD_NOK,
    LCD_OK
} LCD_ErrorState;

/* LCD FUNCTIONS */

LCD_ErrorState LCD_enumInit         (void                           );
LCD_ErrorState LCD_enumSendCommand  (u8 LOC_u8command               );
LCD_ErrorState LCD_enumSendData     (u8 LOC_u8data                  );
LCD_ErrorState LCD_enumSendString   (const u8* LOC_u8PtrString      );
LCD_ErrorState LCD_enumSetPosition  (u8 LOC_u8row, u8 LOC_u8col     ); /* to set cursor position */
void           LCD_voidClear        (void                           );
void           LCD_voidHome         (void                           );



#endif