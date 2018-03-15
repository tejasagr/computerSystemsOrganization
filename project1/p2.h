
#ifndef P2_H
#define P2_H

/*
 * Define the node for a circular doubly
 * linked list.
 */ 
typedef struct node {
    char value;
    struct node * next;
    struct node * prev;
} node; 

/*
 * Add a new node to the front of the list. 
 * Parameters: 
 *  to_add - character to be stored in the list
 *  head_pointer - pointer to the head pointer for the list 
 * Return value:
 *  0 if the node was not created
 *  1 if the node was created and attached to the list
 */
int add_to_front ( char to_add, node ** head_pointer );

/*
 * Add a new node to the back of the list. If the list is currently
 * empty, the new node should be added as its first node. 
 * Parameters: 
 *  to_add - character to be stored in the list
 *  head_pointer - pointer to the head pointer for the list 
 * Return value:
 *  0 if the node was not created
 *  1 if the node was created and attached to the list
 */
int add_to_back ( char to_add, node ** head_pointer );

/*
 * Remove a node from the front of the list. 
 * Parameters: 
 *  head_pointer - pointer to the head pointer for the list 
 * Return value:
 *  character stored in the node that was removed or '\0' if 
 *  the list was empty 
 */
char remove_first ( node ** head_pointer );


/*
 * Remove a node from the back of the list. 
 * Parameters: 
 *  head_pointer - pointer to the head pointer for the list 
 * Return value:
 *  character stored in the node that was removed or '\0' if 
 *  the list was empty 
 */
char remove_last ( node ** head_pointer );


/*
 * Determine the index (zero-based) of an element in the list
 * (if there are multiple matching elements, the index of the first
 * one should be returned).  
 * Parameters: 
 *  to_located  - character that should be located 
 *  head - pointer to the head of (the first node) in the list 
 * Return value:
 *  zero based integer indicating the position of character in the list
 *  or -1 if the character is not stored in the list 
 */
int index_of ( char to_locate, node * head ); 


/*
 * Determine the number of nodes in the list 
 * Parameters: 
 *  head - pointer to the head of (the first node) in the list 
 * Return value:
 *  number of nodes in the list or 0 if the list is empty 
 */
int num_of_nodes ( node * head ); 

/*
 * Remove all nodes from the list. 
 * Parameters: 
 *  head_pointer - pointer to the head pointer for the list 
 */
void empty ( node ** head_pointer ); 

/*
 * Print the content of the list to the standard output stream.
 * The elements should be inside square brackets and separated by
 * comma and a single space. There should be a sinlge space between
 * a character and each of the square brackets. There should be a single
 * space between a set of brackets to indicate an empty list. 
 * Parameters: 
 *  head - pointer to the head of (the first node) in the list 
 * Example output:
 *  [ ]   for an empty list
 *  [ a, A, b, B ]   for a list of four characters 
 */

void print_list ( node * head ); 






#endif
