
#ifndef P1_H
#define P1_H

/* 
 * Determine if the integer n encodes 
 * a valid triangle or not. 
 * 
 * The three sides of the triangle are 
 * encoded using sets of 10 bits from the 
 * 32-bit int parameter. The lowest order
 * 10 bits are the value for one side, the 
 * next 10 bits are the value for the second
 * side, the next 10 bits are the value 
 * for the third side. The highest order 2 
 * bits are ignored. 
 * 
 * In a valid triangle the sum of two shortest
 * sides has to be larger than the value 
 * of the largest side. 
 * 
 * This function returns 0 if the triangle is 
 * invalid and 1 if it is valid. 
 */ 

int is_valid_triangle ( int n );

#endif
