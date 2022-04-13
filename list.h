#include "item.h"
#include "node.h"

typedef struct List *List;

List newList(void);

List insertHead(List list, item val);

void printList(List list);

void freeList(List list);

List reverseList(List list);

