#include "item.h"

typedef struct List *List;

// Create a new list
List newList(void);

// Check if the list is empty
int isEmpty(List list);

// Add a value into the first position of the list
List addFirst(List list, Item it);

/* Add a value into the last position of the list
*  if there are no values, add it as the first
*/
List addLast(List list, Item it);

// Print the entire list to stdout
void printList(List list);

// Free the entire list
void freeList(List list);

/* Return a reversed list of the given list
*  and free the old list
*/
List reverseList(List list);
