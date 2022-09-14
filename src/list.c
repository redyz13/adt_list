#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node {
    struct Node *next;
    Item data;
};

struct List {
    struct Node *head;
    int size;
};

List newList(void) {
    List l;

    l = malloc(sizeof(struct List));
    if (l == NULL) return l;

    l->head = NULL;
    l->size = 0;

    return l;
}

int isEmpty(List list) {
    return (list->size) == 0;
}

static Item getItem(struct Node *n) {
    if (n == NULL) return NULLITEM;

    return n->data;
}

int addFirst(List l, Item it) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return 0;

    new->data = it;

    // If there are no nodes, set the created one as head 
    if (l->head == NULL) {
        new->next = NULL;
        l->head = new;
        (l->size)++;
        return 1;
    }

    
    // Make the next of the new node as head
    new->next = l->head;
    // Move the head to point to the new node
    l->head = new;
    (l->size)++;

    return 1;
}

int addLast(List l, Item it) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return 0;

    new->data = it;
    new->next = NULL;

    // If there are no nodes, set the created one as head 
    if (l->head == NULL) {
        l->head = new;
        (l->size)++;
        return 1;
    }

    struct Node *last = l->head;

    // Traverse until the last node 
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new;
    (l->size)++;

    return 1;
}

int add(List l, Item it, int pos) {
    struct Node *new;

    new = malloc(sizeof(struct Node));
    if (new == NULL) return 0;

    new->data = it;

    // If the position is 0, add the node to the head
    if (pos == 0) {
        new->next = l->head;
        l->head = new;
        (l->size)++;
        return 1;
    }

    int i = 0;
    struct Node *tmp = l->head;

    // Traverse until the given pos - 1 is found or you reach the end of the list 
    while (i < pos - 1 && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }

    // If the position doesn't exist return null
    if (tmp == NULL) {
        free(new);
        return 0;
    }

    /* If the position is found, set the new node to the given
    *  position and its next node to the current one that was in
    *  that position
    */
    new->next = tmp->next;
    tmp->next = new;

    (l->size)++;

    return 1;
}

int removeItem(List l, Item it) {
    // If there are no nodes, there is nothing to delete
    if (l->head == NULL) return 0;

    struct Node *tmp = l->head;

    /* If the data is at head set head to next node
    *  and free the previous head
    */
    if (isEqual(l->head->data, it)) {
        l->head = l->head->next;
        // freeItem(tmp->data);
        free(tmp);
        (l->size)--;
        return 1;
    }

    struct Node *prev;

    // Traverse until the data is found or you reach the end of the list 
    while (!isEqual(getItem(tmp), it) && tmp != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Data not found
    if (tmp == NULL) return 0;

    /* If the data is found set the next pointer of the previous node
    *  to the next node of the node to delete
    */
    prev->next = tmp->next;
    // You can comment this line if you don't need it (XXX)
    // freeItem(tmp->data);
    // Deallocate the node
    free(tmp);
    (l->size)--;

    return 1;
}

int removeFirst(List l) {
    if (l->head == NULL) return 0;

    struct Node *tmp = l->head;

    l->head = l->head->next;
    // freeItem(tmp->data);
    free(tmp);
    (l->size)--;

    return 1;
}

int removeLast(List l) {
    return removeItemPos(l, (l->size) - 1);
}

int removeItemPos(List l, int pos) {
    // If there are no nodes, there is nothing to delete
    if (l->head == NULL) return 0;

    struct Node *tmp = l->head;

    // If the position is 0, remove the head
    if (pos == 0) {
        l->head = l->head->next;
        /* If the items are allocated they will be deallocated 
        *  You can comment this line if you don't need it (XXX)
        */
        // freeItem(tmp->data);

        // Deallocate the node
        free(tmp);
        (l->size)--;
        return 1;
    }

    int i = 0;
    struct Node *prev = l->head;

    // Traverse until the given pos - 1 is found or you reach the end of the list 
    while (i < pos - 1 && prev != NULL) {
        prev = prev->next;
        i++;
    }

    // If the position doesn't exist return null
    if (prev == NULL)  return 0;
    if (prev->next == NULL)  return 0;

    // Give to tmp the next of the previous node (the node to delete)
    tmp = prev->next;
    /* If the pos is found set the next pointer of the previous node
    *  to the next node of the node to delete
    */
    prev->next = tmp->next;
    /* If the items are allocated they will be deallocated 
    *  You can comment this line if you don't need it (XXX)
    */
    // freeItem(tmp->data);

    free(tmp);
    (l->size)--;

    return 1;
}

int set(List l, Item it, int pos) {
    // If there are no nodes, there is nothing to set
    if (l->head == NULL) return 0;

    // Item tmp_ = l->head->data;

    if (pos == 0) {
        /* If the items are allocated they will be deallocated 
        *  You can comment this line if you don't need it (XXX)
        */  
        // freeItem(tmp_);
        l->head->data = it;
        return 1;
    }

    struct Node *tmp = l->head;
    int i = 0;

    while (i < pos && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }

    // Data not found
    if (tmp == NULL) return 0;

    // tmp_ = tmp->data;

    // If the position is found set the new value
    tmp->data = it;

    /* If the items are allocated they will be deallocated 
    *  You can comment this line if you don't need it (XXX)
    */  
    // freeItem(tmp_);

    return 1;
}

Item get(List l, int pos) {
    // If there are no nodes, there is nothing to return
    if (l->head == NULL) return NULLITEM;

    // If the position is 0, return the value of the head
    if (pos == 0) return l->head->data;

    int i = 0;
    struct Node *tmp = l->head;

    // Traverse until the given pos is found or you reach the end of the list 
    while (i < pos && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }

    // If the pos isn't found getItem will return NULLITEM
    if (tmp == NULL) return NULLITEM;

    return tmp->data;
}

Item getFirst(List l) {
    if (l->head == NULL) return NULLITEM;

    return l->head->data;
}

Item getLast(List l) {
    return get(l, (l->size) - 1);
}

int contains(List l, Item it) {
    struct Node *head = l->head; 
    
    while (head != NULL){
        if (isEqual(it, getItem(head)))
            return 1;
        
        head = head->next;
    }

    return 0;
}

int indexOf(List l, Item it) {
    struct Node *head = l->head;
    int i = 0;

    while (head != NULL) {
        if (isEqual(it, getItem(head)))
            return i;
        
        i++;

        head = head->next;
    }

    return -1;
}


List clone(List l) {
    if (l->head == NULL) return NULL;

    List clone = newList();
    struct Node *head = l->head;
    Item it;

    while (head != NULL) {
        it = getItem(head);
        addFirst(clone, it);
        head = head->next;
    }

    clone = reverseList(clone);

    return clone;
}


void printList(List l) {
    struct Node *head = l->head;
    int i = 0;

    // Traverse through nodes of the list and print data of each node
    while (head != NULL) {
        printf("--- Element %d ---\n", i++);
        printItem(head->data);
        putchar('\n');
        head = head->next;
    }
}

List reverseList(List l) {
    if (l->head == NULL) return NULL;

    List reversed = newList();
    struct Node *head = l->head;
    Item it;

    while (head != NULL) {
        it = getItem(head);
        addFirst(reversed, it);
        head = head->next;
    }

    freeList(l);

    return reversed;
}

void freeList(List l) {
    struct Node *tmp;

    // Travers through nodes of the list and free each node
    while (l->head != NULL) {
        tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    }

    free(l);
}

// This function will also deallocate data (XXX)
void destroyList(List l) {
    struct Node *tmp;

    // Travers through nodes of the list and free each node
    while(l->head != NULL) {
        tmp = l->head;
        freeItem(tmp->data);
        l->head = l->head->next;
        free(tmp);
    }

    free(l);
}