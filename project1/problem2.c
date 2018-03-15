
#include <stdio.h> 
#include <assert.h>

#include "p2.h" 

/* 
 * Test program for a circular doubly linked list. 
 */ 

int main ( ) {
    
    node * head = 0;
    
    add_to_front('O', &head);
    print_list(head); 
    
    add_to_front('S', &head);
    print_list(head); 
    
    add_to_front('C', &head);
    print_list(head); 
    
    
    add_to_back('f', &head);
    add_to_back('u', &head);
    add_to_back('n', &head);
    print_list(head); 
    
    assert(index_of('f', head) == 3 );
    
    empty(&head);
    print_list(head); 
    
    add_to_back('1', &head);
    print_list(head); 
    remove_first(&head);
    print_list(head);  
    
    add_to_back('0', &head);
    print_list(head); 
    remove_last(&head);
    print_list(head); 
    
    int i; 
    for ( i = 0; i < 5; i=i+2 ) {
        add_to_front (i+'A', &head);
        add_to_back (i+1+'A', &head);
    }
    print_list(head); 
    
    assert(num_of_nodes(head) == 6); 
    assert(index_of('A', head) == 2);
    assert(index_of('D', head) == 4); 
    
    for ( i = 0; i < 5; i=i+2 ) {
        remove_first(&head); 
        remove_last(&head); 
    }
    print_list(head); 
    
    
    
    printf("\n\nExamine the output above to determine correctness of your code. \n"
            "You should make sure to thoroughly test your"
            " code even when the above output seems reasonable.\n\n" );
    
    return 0; 
}
