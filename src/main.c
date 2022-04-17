#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;
    List list2;

    list = newList();
    removeItem(list, 11);

    for(int i = 0; i < 7; i++) {
        addFirst(list, i);
    }

    list = reverseList(list);

    printList(list);

    printf("\nContained: %d\n\n", contains(list, 5));

    list2 = clone(list);

    removeItem(list2, 0);
    removeItemPos(list2, 3);

    printList(list2);
    
    printf("\nContained: %d\n", contains(list2, 1));

    freeList(list);
    freeList(list2);

    return 0;
}
