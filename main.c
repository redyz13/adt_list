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
    list = addLast(list, 55);

    printList(list);

    freeList(list);

    return 0;
}
