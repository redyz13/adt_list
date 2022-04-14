#include <stdio.h>
#include <stdlib.h>
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

List insertHead(List list, Item it) {
    list->head = addHead(list->head, it); 
    (list->size)++;

    return list;
}

void printList(List list) {
    Node head = list->head;
    int i = 0;

    while(head != NULL) {
        printf("Elemento %d = ", i);
        printItem(getItem(head));
        putchar('\n');
        head = nextNode(head);
        i++;
    }
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

List reverseList(List list) {
    List reverse;
    Node tmp;
    Item val;

    reverse = newList();

    while(list->head != NULL){
        tmp = list->head;
        val = getItem(list->head);
        reverse = insertHead(reverse, val);
        list->head = nextNode(list->head);
        free(tmp);
    }
    
    free(list);

    return reverse;
}
