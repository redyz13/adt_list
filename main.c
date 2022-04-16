#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;

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

    removeItem(list, 2);
    removeItem(list, 3);
    removeItem(list, 4);
    addFirst(list, 1);

    removeItemPos(list, 0);
    removeItemPos(list, 0);

    int x = getFirst(list);

    printf("%d\n\n", x);

    printList(list);

    freeList(list);

    return 0;
}
