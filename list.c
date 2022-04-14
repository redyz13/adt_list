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

    // Set the head pointer to NULL and the size to 0
    l->head = NULL;
    l->size = 0;

    return l;
}

int isEmpty(List list) {
    return (list->size) == 0;
}

List addFirst(List list, Item it) {
    list->head = addHead(list->head, it); 
    (list->size)++;

    return list;
}

// FIXME
List addLast(List list, Item it) {
    list->head = addTail(list->head, it); 
    (list->size)++;

    return list;
}

void printList(List list) {
    Node head = list->head;
    int i = 0;

    // Traverse through nodes of the list and print data of each node
    while(!isNull(head)) {
        printf("Elemento %d = ", i);
        printItem(getItem(head));
        putchar('\n');
        head = nextNode(head);
        i++;
    }
}

List reverseList(List list) {
    List reverse;
    Node head;
    Item val;

    head = list->head;

    reverse = newList();

    while(!isNull(head)){
        val = getItem(head);
        reverse = addFirst(reverse, val);
        head = nextNode(head);
    }
    
    freeList(list);

    return reverse;
}

void freeList(List list) {
    Node head, tmp;

    head = list->head;

    // Travers through nodes of the list and free each node
    while(!isNull(head)) {
        tmp = head;
        head = nextNode(head);
        free(tmp);
    }

    free(list);
}
