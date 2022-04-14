#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;

    list = newList();
    removeItem(list, 11);

    addLast(list, 31);

    for(int i = 0; i < 5; i++) {
        addFirst(list, i);
    }

    //printList(list);
    
    list = reverseList(list);

    //putchar('\n');
    
    addLast(list, 25);
    add(list, 33, 2);
    add(list, 533, 22);
    add(list, 533, 8);
    add(list, 11, 9);

    printList(list);

    putchar('\n');

    removeItem(list, 533);
    removeItem(list, 1);
    removeItem(list, 31);

    printList(list);

    freeList(list);

    return 0;
}
