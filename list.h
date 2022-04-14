#include "item.h"

typedef struct List *List;

// Create a new list
List newList(void);

/* Insert a value into the list, if there are
*  no values, set the given one as the first value 
*/
List insertHead(List list, Item it);

// Print the entire list to stdout
void printList(List list);

// Free the entire list
void freeList(List list);

// Reverse the entire list
List reverseList(List list);
