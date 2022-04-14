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

int isNull(Node node) {
    return node == NULL;
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

Node addTail(Node head, Item it) {
    Node new;

    new = newNode(it);
    if(new == NULL) return NULL;

    // If there are no nodes, set the created one as head 
    if(head == NULL) {
        head = new;
        return head;
    }

    Node last = head;
    Node new_head = head;

    // Traverse until the last node 
    while(last->next != NULL) {
        last = nextNode(last);
    }

    // Change the next of last node
    last->next = new;

    return new_head;

    /* The new node node will already point to NULL
    *  thanks to the newNode function
    */
}

Item getItem(Node node) {
    if(node != NULL) {
        return node->data;
    }

    return NULLITEM; 
}
