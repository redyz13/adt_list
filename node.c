#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node {
     item value;
     struct Node *next;
};

Node newNode(item value) {
    Node new; 

    new = malloc(sizeof(struct Node));
    if(new == NULL) return NULL;

    new->next = NULL;
    new->value = value;
    
    return new;
}

Node nextNode(Node node) {
    node = node->next;

    return node;
}

Node addHead(Node head, item val) {
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

void print(Node head) { 
    int i = 0;

    while(head != NULL) {
        printf("Elemento %d = ", i);
        printItem(head->value);
        putchar('\n');
        head = nextNode(head);
        i++;
    }
}

item getItem(Node node) {
    if(node != NULL) {
        return node->value;
    }
    
    return NULLITEM; 
}

