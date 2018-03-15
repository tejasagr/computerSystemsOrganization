/*
* Author:           Tejas Agrawal
* Date Submitted:   February 23, 2018
*
* Description:      Program that implements a 6-bit version of a floating number. Follows the model of IEEE754 encoding with 1 sign bit,
*                   3 exp bits, and 2 frac bits. Bitwise operators were used wherever possible.
*                   Takes input as a short. Only the last 6 bits of the short are used, while the first 10 bits are ignored.
*                   Returns a float with the relevant value coming from the 6 bits inputted.
*
*/

#include <math.h>
#include "p3.h"

/*
 * Implementation file for functions
 * declared in p3.h
 */ 

const short BIAS = (1 << (NUM_OF_EXP_BITS-1)) - 1;  //calculation of BIAS, depends solely on the number of exp bits used

//will calculate E based on the bit vector, will depend on normalized or denormalized, special values shouldn't call this method
short get_E_from_bits( short bit_vector ) {         

    if ( is_normalized ( bit_vector )) {            //normalized case
    	short exp = get_exp_from_bits(bit_vector);
    	return ( exp - BIAS );                      //normalized formula
    }

   	else if (is_denormalized ( bit_vector )) {      //denormalized case
   		return ( 1 - BIAS );                        //denormalized formula
   	}

    else                                            //failure of method case
    	return 0;
}

//will simply retrieve the relevant exp bits and return them
short get_exp_from_bits ( short bit_vector ) { 

    short adjustedBit = bit_vector >> NUM_OF_FRAC_BITS; //exp bits are now the rightmost bits
    short mask = 0b000111;
    
    adjustedBit = adjustedBit & mask;                   //turn off all other bits
    
    return adjustedBit;                                 //return relevant bits
}

//method to return 1 if normalized and 0 if not
short is_normalized( short bit_vector ) {           

    short exp = get_exp_from_bits(bit_vector);
   	
    if( (exp == 0b000) || (exp == 0b111) )              //either denormalized or special case
    	return 0;
    else                                                //normalized case
    	return 1; 
}

//method to return 1 if denormalized and 0 if not
short is_denormalized( short bit_vector ) {
    
    short exp = get_exp_from_bits(bit_vector);          

    if (exp == 0)                                       //denormalized case
    	return 1;
    else
		return 0; 
}
        

//calculates and returns M based on the relevant frac bits from the given bit_vector
float get_M_from_bits ( short bit_vector ) {
    short frac1 = bit_vector & 0b10;                    //have to seperate frac bits
    short frac2 = bit_vector & 0b01;                    //since,    2^e + 2^f != 1/(2^-e + 2^-f)
                                                        //but,      2^e + 2^f  = 1/(2^-e) + 1/(2^-f) 

    float dig1 = 0;
    float dig2 = 0;

    if (frac1 == 0b10) {                                //if bit is on we need to calculate the value, otherwise leave 0
    	short invDig1 = frac1 << 0;                     //frac1 represents 2^-1, it is already in 2^1 so no shift required
    	dig1 = 1 / ((float) invDig1);
    }

    if (frac2 == 0b1) {                                 //if bit is on we need to calculate the value, otherwise leave 0
    	short invDig2 = frac2 << 2;                     //frac2 represents 2^-2, it is in 2^0 position so needs a left shift of 2
    	dig2 = 1 / ((float) invDig2);
    }

    float mDec = dig1 + dig2;                           //add individual digits together to get portion after binary point

    float M;
   	if( is_normalized ( bit_vector ) )                  //add one to M if normalized
   		M = 1 + mDec;
   	else if(is_denormalized ( bit_vector ))             //don't add anything if denormalized
   		M = mDec;

    return M;
}

//gets relevant sign to multiply by based on leading bit
short get_sign_from_bits ( short bit_vector ) {
    short sign = (bit_vector & 0b100000 ) >> (NUM_OF_FRAC_BITS + NUM_OF_EXP_BITS);
                                                        //either 1 or 0
    if (sign == 1)                                      //1 denotes negative
    	return -1;

    else                                                //0 denotes positive
    	return 1;     
}


//using other methods, will return the float value given bit_vector
float get_value_from_bits ( short bit_vector ) {
    
    short exp = get_exp_from_bits( bit_vector );
    short frac = bit_vector & 0b11;
    short sign = get_sign_from_bits (bit_vector);
    float ans;

    if ( exp == 0b111 ) {				               //special values
    	if ( frac == 0 ) {                             //infinity values
    		if ( sign == -1 )                          //neg inf
    			ans = -INFINITY;
    		else
    			ans = INFINITY;                        //pos inf
    	}
    	else {                                         //NaN values, frac isn't 0

    		if ( sign == -1 )                          //neg NaN
    			ans = -NAN;
    		else
    			ans = NAN;                             //pos NaN

    	}
    }

    else if ( is_normalized(bit_vector) || is_denormalized(bit_vector) ) {  
                                                       //normalized and denormalized are similar, both use same formula
    	short E = get_E_from_bits (bit_vector);
    	float M = get_M_from_bits (bit_vector);
    	float TwoToTheE;

    	if ( E < 0 ) {                                 //special case, e is negative, need to apply formula 2^e = 1/(2^-e)
    		short negE = E * -1;
    		short invTwoToTheE = 0b1 << negE;
    		TwoToTheE = 1 / (float) invTwoToTheE;
    	}

    	else if ( E == 0 || E > 0 ) {                  //left shift will cause raising to to the power of amount shifted
    		short shiftedE = 0b1 << E;
    		TwoToTheE = (float) shiftedE ;
    	}

    	ans = sign * M * TwoToTheE;                    //(-1)^S * M * 2^E formula applied
    }
    
    return ans;                                        //final value returned
    
}
