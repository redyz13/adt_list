#include "item.h"

typedef struct List *List;

// Create a new list
List newList(void);

// Check if the list is empty
int isEmpty(List list);

/* Add a value into the first position of the list
*  in case of error return the same list
*/
List addFirst(List list, Item it);

/* Add a value into the last position of the list
*  if there are no values, add it as the first
*  in case of error return the same list
*/
List addLast(List list, Item it);

/* Add a value to the given position, if the position
*  doesn't exist return the same list, if the position is the last,
*  add the value to the end, if the position is 0, add the
*  value at the beginning
*/
List add(List list, Item it, int pos);

// Print the entire list to stdout
void printList(List list);

// Free the entire list
void freeList(List list);

/* Return a reversed list of the given list
*  and free the old list
*/
List reverseList(List list);
