#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;
    List list2;

    list = newList();

    for(int i = 0; i <= 1000; i++) {
        addFirst(list, i);
    }

    list = reverseList(list);

    list2 = clone(list);

    printList(list2);

    freeList(list);

    return 0;
}
