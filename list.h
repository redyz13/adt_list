#include "item.h"

typedef struct List *List;

// Create a new list
List newList(void);

// Check if the list is empty
int isEmpty(List list);

/* Add a value into the first position of the list
*  in case of error return 0
*/
int addFirst(List list, Item it);

/* Add a value into the last position of the list
*  if there are no values, add it as the first
*  in case of error return 0
*/
int addLast(List list, Item it);

/* Add a value to the given position, if the position
*  doesn't exist return 0, if the position is the last,
*  add the value to the end, if the position is 0, add the
*  value at the beginning
*/
int add(List list, Item it, int pos);

/* Remove the first occurence of the given data,
*  if the list is empty or the data to delete
*  isn't found return 0
*/
int removeItem(List list, Item it);

// Print the entire list to stdout
void printList(List list);

// Free the entire list
void freeList(List list);

/* Return a reversed list of the given list
*  and free the old list
*/
List reverseList(List list);
