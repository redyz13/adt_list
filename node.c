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

    // Set the next pointer to NULL and give the data to the node
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

    // If there are no nodes, set the created one as head 
    if(head == NULL) {
        head = new; 
        return head;
    }

    // Make the next of the new node as head
    new->next = head; 
    // Move the head to point to the new node
    head = new; 

    return head;
}

Item getItem(Node node) {
    if(node != NULL) {
        return node->data;
    }
    
    return NULLITEM; 
}
