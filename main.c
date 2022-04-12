#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List list;

    list = newList();

    for(int i = 0; i < 5; i++) {
        list = insertHead(list, i);
    }

    printList(list);
    
    freeList(list);

    return 0;
}
