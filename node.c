#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node {
     Item data;
     struct Node *next;
};

Node newNode(Item it) {
    Node new; 

    new = malloc(sizeof(struct Node));
    if(new == NULL) return NULL;

    new->next = NULL;
    new->data = it;
    
    return new;
}

Node nextNode(Node node) {
    node = node->next;

    return node;
}

Node addHead(Node head, Item it) {
    Node new; 

    new = newNode(it);
    if(new == NULL) return NULL;

    if(head == NULL) {
        head = new; 
        return head;
    }

    new->next = head; 
    head = new; 

    return head;
}

Item getItem(Node node) {
    if(node != NULL) {
        return node->data;
    }
    
    return NULLITEM; 
}
