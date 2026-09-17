/*
 * StdTypes.h
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#ifndef COMMON_STDTYPES_H_
#define COMMON_STDTYPES_H_

typedef unsigned char u8;
typedef signed long int s32;
typedef signed char s8;


typedef enum
{
    E_OK,
    E_NOK,
    E_NULL_POINTER,
    E_WRONG_CONFIG
} ErrorState_t;

#endif /* COMMON_STDTYPES_H_ */
