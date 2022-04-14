#include "item.h"

typedef struct Node *Node;

// Create a new node
Node newNode(Item it);

// Check if the node is null
int isNull(Node node);

// Return data of a node
Item getItem(Node node);

// Given a node return the next node
Node nextNode(Node node);

/* Add a node to the front, if there are
*  no nodes, set the created one as head 
*  return the new head
*/
Node addHead(Node head, Item it);

/* Add a node to the front, if there are
*  no nodes, set the created one as head 
*  return the new head
*/
Node addTail(Node head, Item it);

/* Add a node to the given position, if the position
*  doesn't exist return null, if the position is the last,
*  add the node to the end, if the position is 0, set the
*  created one as head
*/
Node addPos(Node head, Item it, int pos);

/*
*
*/
Node removeNode(Node head, Item it);
