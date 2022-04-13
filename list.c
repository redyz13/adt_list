#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "list.h"

struct List {
    struct Node *head;
    int size;
};

struct Node {
     item value;
     struct Node *next;
};

typedef struct Node *Node; 

List newList(void) {
    List l; 
    
    l = malloc(sizeof(struct List));
    if(l == NULL) return NULL;

    l->head = NULL;
    l->size = 0;

    return l;
}

static Node newNode(item value) {
    Node new; 

    new = malloc(sizeof(struct Node));
    if(new == NULL) return NULL;

    new->next = NULL;
    new->value = value;
    
    return new;
}

static Node nextNode(Node node) {
    node = node->next;
    return node; 
}

static Node getHead(List list) {
    return list->head;
}

static Node addHead(Node head, item val) {
    Node new; 

    new = newNode(val);
    if(new == NULL) return NULL;

    //assegno new ad head se head è nulla
    if(head == NULL) {
        head = new; 
        return head;
    }

    new->next = head; 
    head = new; 

    return head;
}

List insertHead(List list, item val) {

    list->head = addHead(list->head, val); 
    (list->size)++;

    return list;
}

static void print(Node head) { 
    int i = 0;

    while(head != NULL) {
        printf("Elemento %d = ", i);
        printItem(head->value);
        putchar('\n');
        head = nextNode(head);
        i++;
    }
}

void printList(List list) {
    print(list->head);
}

void freeList(List list) {
    Node head, tmp;

    head = list->head;

    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    free(list);
}


