#include "item.h"

typedef struct Node *Node;

Node newNode(item value);

Node nextNode(Node node);

Node addHead(Node head, item val);

void print(Node head);

item getItem(Node node);
