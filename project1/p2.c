/*
* Author: Tejas Agrawal
* Date Submitted: February 23, 2018
*
* Description:  A circular doubley linked list implementation.
*               Made for the storage of characters and allows adds, removals and other list tracking methods.
*               Other methods include getting the index of a particular character, getting size, printing the list and emptying it.
*               List is designed to to store memory dynamically, and free memory not being used.
*
*/

#include <stdlib.h> 
#include <stdio.h> 
#include "p2.h"

/*
 * Implementation file for functions
 * declared in p2.h
 */ 

//will create a node for a character and add it to the front of the linked list, adjusting links necessary
int add_to_front ( char to_add, node ** head_pointer ) {

    node* newNode_pointer = (node*) malloc (sizeof(node));          //allocates memory for the new node
    (*newNode_pointer).value = to_add;                              //adds relevant character

    if (*head_pointer == 0) {                                       //empty list case, this is the only node so
        (*newNode_pointer).next = newNode_pointer;                  //next and previous pointers are this node
        (*newNode_pointer).prev = newNode_pointer;
    }

    else {
        (*newNode_pointer).prev = (**head_pointer).prev;            //previous node will be old head's previous node
        (**head_pointer).prev = newNode_pointer;                    //previous node of head will be this node
        
        (*newNode_pointer).next = *head_pointer;                    //new nodes next node is the old head
        (*( (*newNode_pointer).prev ) ).next = newNode_pointer;     //'back' node's next node is the new node (new head)
        
    }

    *head_pointer = newNode_pointer;                                //offically assign new node as head

    return 1; 
}

//will create a node for a character and add it to the back of the linked list, adjusting links necessary
int add_to_back ( char to_add, node ** head_pointer ) {

    node * newNode_pointer = (node *) malloc (sizeof(node));        //allocates memory for the new node
    (*newNode_pointer).value = to_add;                              //adds relevant character

    if (*head_pointer == 0) {                                       //empty list case, this is the only node so
        (*newNode_pointer).next = newNode_pointer;                  //next and previous pointers are this node
        (*newNode_pointer).prev = newNode_pointer;
        *head_pointer = newNode_pointer;                            //assign as head, only node so the back is the front as well
    }

    else {

        (*newNode_pointer).prev = (**head_pointer).prev;            //previous back node is the node before the new back
        (**head_pointer).prev = newNode_pointer;                    //head's previous node is the new back node

        (*newNode_pointer).next = *head_pointer;                    //new back node's next node is the head
        ( *( (*newNode_pointer).prev ) ).next = newNode_pointer;    //old back node's next node is the new back node

    }

    return 1; 
}

//will remove the first node of the list and return it's char
char remove_first ( node ** head_pointer ) { 
    
    if (*head_pointer == 0)                                         //special case: empty list
        return '\0';
    
    //do we need to remove anything else? pointers?
    else if ( (**head_pointer).next == *head_pointer ) {            //special case: only one node list

        char ans = (**head_pointer).value;                          //retrieve and store answer
        node* toFree = *head_pointer;                               //mark this node for removal
                                        
        *head_pointer = 0;                                          //mark list as empty
        free(toFree);                                               //free space of removed node

        return ans;
    }


    else {

        char ans = (**head_pointer).value;                          //retrieve and store answer
        node* toFree = *head_pointer;                               //mark this node for removal

        (* (**head_pointer).next ).prev = (**head_pointer).prev;    //node after head will now have head's old previous node as prev
        (* (**head_pointer).prev ).next = (**head_pointer).next;    //node before head will now have head's old next node as next

        *head_pointer = (**head_pointer).next;                      //head will be assigned to node after old head
        free(toFree);                                               //free space of old head is removed

        return ans;
    }

}

//will remove the last node of the list and return it's char
char remove_last ( node ** head_pointer ){

    if (*head_pointer == 0)                                         //special case: empty list
        return '\0';
    
    else if ( (**head_pointer).next == *head_pointer ) {            //special case: only one node list
                                                                    //node before head is head

        char ans = (**head_pointer).value;                          //retrieve and store answer
        node* toFree = *head_pointer;                               //mark this node for removal
        
        *head_pointer = 0;                                          //mark list as empty
        free(toFree);                                               //free space of removed node

        return ans;
    }

    else {

        char ans = (*( (**head_pointer).prev ) ).value;             //we are dealing with node before head now
        node* toFree = (**head_pointer).prev;                       //mark this node for removal
        
        ( (*( (*( (**head_pointer ).prev) ).prev)) ).next = *head_pointer;  //the node before the old back node's next node is head
        (**head_pointer).prev = (*( (**head_pointer).prev) ).prev;          //the node before head is now the node before the old back node

        *head_pointer = (**head_pointer).next;                      //officially assign new head node
        free(toFree);                                               //free space of removed node

        return ans;
    }
}

//returns the index of the first node that contains the given char, -1 if not found
int index_of ( char to_locate, node * head ) {

    int index = 0;                                          //0 based index system, start at 0

    if ( (*head).value == to_locate ){                      //value is found in first node
        return index;
    }
    
    index++;                                                //not found in head, increase index and
    node* walk = (*head).next;                              //check the next node
    
    while ( ( (*walk).value != to_locate) ) {               //while we don't find the value

        index++;                                            //keep traversing list
        walk = (*walk).next;
        
        if ( walk == head ) {                               //we have traversed the list, not found
            return -1;
        }
    }

    return index;                                           //if we reach here we found the val, return index
}

//returns the number of nodes in this list
int num_of_nodes ( node * head ) {
    
    if (head == 0)                          //empty list, size 0
        return 0;

    else if ( (*head).next == head )        //special case, one node, size 1
        return 1;

    else {

        int count = 1;                      //counted head
        node* walk = (*head).next;
        
        while ( walk != head ) {            //while we haven't completed traversal
            count++;                        //keep counting and traversing
            walk = (*walk).next;
        }

        return count;
    }

}

//empties the linked list of any nodes
void empty ( node ** head_pointer ) {

    if (*head_pointer == 0)                 //already empty
        return;

    node* walk = *head_pointer;
    while ( (*walk).next != *head_pointer ) {
        walk = (*walk).next;                    //travserses the list
        free((*walk).prev);                     //have to free previous one to use next function
    }

    free(walk);                             //last node of list, no need for next, free it
    *head_pointer = 0;                      //signify empty list
}

//prints the contents of the linked list given the head
void print_list ( node * head ) { 

    if (head == 0){                         //special case: empty list
        printf("[ ]");
    }

    else {
        printf("[");

        if ( num_of_nodes(head) > 1)       //don't print this if a single node list, it has a comma
            printf(" %c, ", (*head).value);

        node *walk = (*head).next;

        while ( (*walk).next != head) {    //traverse list, printing along the way
            printf(" %c, ", (*walk).value);
            walk = (*walk).next;
        }

        printf(" %c ", (*walk).value);     //non-comma is always printed

        printf("]");
    }

    printf("\n");
}