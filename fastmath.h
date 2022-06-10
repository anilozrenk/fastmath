#ifndef _FASTMATH_H
#define _FASTMATH_H
/**
 * @file fastmath.h
 * @brief header file of fastmath 
 * Stolen from a youtube video
 * @author Anil Ozrenk anil.ozrenk@gmail.com
 * @date June 2022
 */

/// binary representation of 1.0f
const unsigned int OneAsInt = 0x3f800000;
///
const float ScaleUp = float(0x00800000);
///
const float ScaleDown = 1.0f/ScaleUp;

/// transform a float to integer
inline unsigned int AsInt(float f){
	return *(unsigned int *)&f;
}
/// transform a integer to float
inline float AsFloat(unsigned int i){
	return *(float*)&i;
}
/// negate a float faster then multiply with -1
float negateFloat(float f);
/// take the log2 of a float
float flog2(float x);
/// square of a float in faster way
float fexp2(float x);
/**
 * power of floats
 * @param x index
 * @param p exponent
 */ 
float fpow(float x,float p);
/**
 * 
 * square root of a float in faster way
 * 
 */ 
float fsqrt(float x);
/**
 * quake 3 magic of 1/sqrt(x) 
 * 
 */
float rsqrt(float number);

#endif