
#ifndef P3_H
#define P3_H

#define NUM_OF_BITS 6
#define NUM_OF_FRAC_BITS 2
#define NUM_OF_EXP_BITS 3 

//value of BIAS is defined in p3.c file 
extern const short BIAS;

/*
 * Determines the value of E from the IEEE754-like encoding 
 * Parameters: 
 *  bit_vector - bit sequence to be interpretted as a float
 * Returns the value of E. 
 */ 
short get_E_from_bits( short bit_vector ) ;

/*
 * Determines the value of exp from the IEEE754-like encoding 
 * Parameters: 
 *  bit_vector - bit sequence to be interpretted as a float
 * Returns the value of exp (just the bits by themselves). 
 */ 
short get_exp_from_bits ( short bit_vector ) ;

/*
 * Determines if the bit_vector represents normalized value in the IEEE754-like encoding 
 * Parameters: 
 *  bit_vector - bit sequence to be interpretted as a float
 * Returns 1 if the bit_vector represents normalized value; 0 otherwise. 
 */ 
short is_normalized(short bit_vector );

/*
 * Determines if the bit_vector represents denormalized value in the IEEE754-like encoding 
 * Parameters: 
 *  bit_vector - bit sequence to be interpretted as a float
 * Returns 1 if the bit_vector represents denormalized value; 0 otherwise. 
 */ 
short is_denormalized(short bit_vector );

/*
 * Determines the value of M from the IEEE754-like encoding 
 * Parameters: 
 *  bit_vector - bit sequence to be interpretted as a float
 * Returns the value of M  as a floating point number (this value includes
 * the leading 1 or the leading 0 before the "binary point" for normalized and 
 * denormalized values) . 
 */ 
float get_M_from_bits ( short bit_vector );

/*
 * Determines the sign of the number from the IEEE754-like encoding 
 * Parameters: 
 *  bit_vector - bit sequence to be interpretted as a float
 * Returns 1 if the value is positive or zero, and -1 if the value is negative. 
 */ 
short get_sign_from_bits (  short bit_vector ) ;

/*
 * Determines the value of bit_vector interpretted according to the IEEE754-like encoding 
 * Parameters: 
 *  bit_vector - bit sequence to be interpretted as a float
 * Returns the value of the given bit_vector 
 */ 
float get_value_from_bits ( short bit_vector ); 



#endif
