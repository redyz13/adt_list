#include "item.h"

typedef struct Node *Node;

// Create a new node
Node newNode(Item it);

// Return data of a node
Item getItem(Node node);

// Given a node return the next node
Node nextNode(Node node);

/* Add a node to the front, if there are
*  no nodes, set the created one as head 
*/
Node addHead(Node head, Item it);
