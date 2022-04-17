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

    //printList(list);
    
    list = reverseList(list);

    //putchar('\n');

    printList(list);

    putchar('\n');

    printf("\nContained: %d\n\n", contains(list, 5));

    //removeItem(list, 2);
    //removeItem(list, 3);
    //removeItem(list, 4);
    //addFirst(list, 3);
    

    //removeItemPos(list, 0);
    //removeItemPos(list, 0);

    //removeItemPos(list, 0);
    //removeItemPos(list, 0);
    
    list2 = clone(list);

    printList(list2);
    
    printf("\nContained: %d\n", contains(list2, 1));

    freeList(list);
    freeList(list2);

    return 0;
}
