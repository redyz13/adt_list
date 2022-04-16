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

int addFirst(List list, Item it) {
    Node head = list->head;

    head = addHead(list->head, it);
    
    if(head == NULL) return 0;

    list->head = head;
    (list->size)++;

    return 1;
}

int addLast(List list, Item it) {
    Node head = list->head;

    head = addTail(list->head, it);
    
    if(head == NULL) return 0;

    list->head = head;
    (list->size)++;

    return 1;
}

int add(List list, Item it, int pos) {
    Node head = list->head;

    head = addPos(list->head, it, pos);
    
    if(head == NULL) return 0;

    list->head = head;
    (list->size)++;

    return 1;
}

int removeItem(List list, Item it) {
    Node head = list->head;

    head = removeNode(list->head, it);
   
    // Check if this is the last value to remove
    if(list->size > 1) {
        if(head == NULL) return 0;
    }

    list->head = head;
    (list->size)--;

    return 1;
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
        addFirst(reverse, val);
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
        /* If the items are allocated they will be deallocated 
        *  You can comment this line if you don't need it (XXX)
        */
        freeItem(getItem(tmp));

        head = nextNode(head);
        free(tmp);
    }

    free(list);
}
