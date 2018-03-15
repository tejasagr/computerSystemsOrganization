
#include <stdio.h> 
#include <assert.h>

#include "p1.h" 

/* 
 * Test program for is_valid_triangle.
 */ 

int main ( ) {
    
    
    assert( is_valid_triangle(-1) == 1 ); 
    
    assert( is_valid_triangle(1) == 0 ); 
    
    assert( is_valid_triangle(50595085) == 1 ); 
    
    assert( is_valid_triangle(50397197) == 0 ); 
    
    printf("Preliminary tests completed.\n"
            "You should make sure to thoroughly test your"
            " code even when these tests succeed.\n\n" );
    
    return 0; 
}
