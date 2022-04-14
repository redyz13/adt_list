#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;

    list = newList();

    list = addLast(list, 31);

    for(int i = 0; i < 5; i++) {
        list = addFirst(list, i);
    }

    printList(list);
    
    list = reverseList(list);

    putchar('\n');
    
    list = addLast(list, 25);
    list = add(list, 33, 2);
    list = add(list, 533, 22);
    list = add(list, 533, 8);
    list = add(list, 11, 9);

    printList(list);

    freeList(list);

    return 0;
}
