#include "fastmath.h"

/**
 * @file fastmath.c
 * @brief header file of fastmath 
 * Stolen from a youtube video
 * @author Anil Ozrenk anil.ozrenk@gmail.com
 * @date June 2022
 */

/// negate a float faster then multiply with -1
float negateFloat(float f){
	return AsFloat(AsInt(f)^0x80000000);
}
/// take the log2 of a float
float flog2(float x){
	if(x>0)
		return float (AsInt(x)-OneAsInt)*ScaleDown;
	else return 0;
}
/// square of a float in faster way
float fexp2(float x){
	return AsFloat(int(x*ScaleUp)+OneAsInt);
}
/**
 * power of floats
 * @param x index
 * @param p exponent
 */ 
float fpow(float x,float p){
	return AsFloat ( int ( p * (AsInt(x) - OneAsInt) ) + OneAsInt);
}
/**
 * 
 * square root of a float in faster way
 * 
 */ 
float fsqrt(float x){
	return AsFloat((AsInt(x)>>1)+(OneAsInt>>1));
}
/**
 * quake 3 magic of 1/sqrt(x) 
 * 
 */
float rsqrt(float number){
	int i;
	float x2,y;
	const float threehalfs = 1.5F;
	x2= number*0.5F;
	y=number;
	i=*(int*)&y; ///< 
	i=0x5f3759df - (i>>1); ///< wtf
	y=*(float*)&i;
	y= y*(threehalfs - (x2*y*y));
	y= y*(threehalfs - (x2*y*y));
	return y;
}


