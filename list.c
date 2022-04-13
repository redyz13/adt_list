#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "list.h"
#include "node.h"

struct List {
    struct Node *head;
    int size;
};

List newList(void) {
    List l; 
    
    l = malloc(sizeof(struct List));
    if(l == NULL) return NULL;

    l->head = NULL;
    l->size = 0;

    return l;
}

List insertHead(List list, item val) {
    list->head = addHead(list->head, val); 
    (list->size)++;

    return list;
}

void printList(List list) {
//    list = reverseList(list);
    print(list->head);
}

void freeList(List list) {
    Node head, tmp;

    head = list->head;

    while(head != NULL) {
        tmp = head;
        head = nextNode(head);
        free(tmp);
    }

    free(list);
}

/*List reverseList(List list) {
    List reverse;
    Node tmp;
    item val;

    reverse = newList();

    while(list->head != NULL){
        tmp = list->head;
        val = getItem(list->head);
        reverse = insertHead(reverse, val);
        list->head = nextNode(list->head);
        free(tmp);
    }

    return reverse;
}
*/
