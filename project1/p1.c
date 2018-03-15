/*
* Author: 			Tejas Agrawal
* Date Submitted: 	February 23, 2018
* Description: 		Program to determines if a triangle is valid based on length of it's three sides.
* 					Takes input as last 30 bits of integer. Each set of 10 bits represents a triangle side. First two bits ignored.
*					Returns a 1 if valid triangle sides and a 0 if invalid.
*
*/
#include "p1.h"
#include <stdio.h>

/*
 * Implementation file for functions
 * declared in p1.h
 */ 

//method takes int with bits of triangles and returns 1 or 0 for valid and invalid triangle
int is_valid_triangle ( int n ) {		
	int mask = 0b1111111111;							//turns off all but last 10 bits
	int side1 = (n >> 0 ) & mask;						//first side saved in last 10 bits, no need for a shift
	int side2 = (n >> 10) & mask;						//shift by 10 to get second side
	int side3 = (n >> 20) & mask;						//shift by 20 to get the third side


	int largest, small1, small2;						//will fill these variables relevantly based on sides

	//figures out largest side
	if ( (side1 >= side2) && (side1 >= side3) ) {		//side1 is largest case
		largest = side1;
		small1 = side2;
		small2 = side3;
	}
	else if ( (side2 >= side1) && (side2 >= side3) ) {	//side2 is largest
		largest = side2;
		small1 = side1;
		small2 = side3;
	}
	else {												//side3 largest
		largest = side3;
		small1 = side1;
		small2 = side2;
	}

    return ((small1 + small2) > largest);				//valid triangle if smallest two sides sum to greater than largest side

}