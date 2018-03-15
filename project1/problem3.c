
#include <stdio.h> 
#include <assert.h>

#include "p3.h" 

/* 
 * Test program for a circular doubly linked list. 
 */ 



int main ( ) {
    
    short bit_vector = 0; 
    float value = 0.0; 
    
    short vectors [] = { 0b0, 0b100011, 0b000001, 0b000100, 0b011011, 0b111100, 0b011101} ;
    int size = 6; 
    
    int i = 0; 
    for (i = 0; i < size; i ++ ){ 
        
        bit_vector = vectors[i]; 
        
        value = get_value_from_bits(bit_vector); 
        
        printf("0x%02X is %+9.5f\n", bit_vector, value); 
    }
    
    
    //to see all possible values of a 6-bit encouding uncomment the following lines
    
    /*
    for (short bit_vector = 0b0; bit_vector <= 0b00111111; bit_vector++) {
        value = get_value_from_bits(bit_vector); 
        
        printf("0x%02X is %+9.5f\n", bit_vector, value); 
    }
    */
    
    
    printf("\n\nExamine the output above to determine correctness of your code. \n"
            "You should make sure to thoroughly test your"
            " code even when the above output seems reasonable.\n\n" );
    
    return 0; 
}

