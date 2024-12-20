/*
 *  File Name :   BIT_MATH.h
 *  Author    :   Muhammad Wael El-Sayed
 *  Layer     :   LIB
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit) reg |= (1 << bit)
#define CLR_BIT(reg, bit) reg &= (~ (1 << bit))
#define TOG_BIT(reg, bit) reg ^= (1 << bit)
#define GET_BIT(reg, bit) ((reg & (1 << bit)) >> bit)

#define IS_BIT_SET(reg, bit) (reg & (1 << bit)) >> bit
#define IS_BIT_CIR(reg, bit) !((reg & (1 << bit)) >> bit)
#define ROR(reg, num) reg = (reg << (REGISTER_SIZE - num)) | (reg >> (num))
#define ROL(reg, num) reg = (reg >> (REGISTER_SIZE - num)) | (reg << (num))


#endif