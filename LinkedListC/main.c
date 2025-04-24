#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct node_t *head = NULL;
    head = init(4);
    addNode(head, 5);   
    head = pushFront(head, 5);
    head = pushBack(head, 6);
    head = insertAt(head, 0, 44);
    printList(head);
    head = removeNodeByValue(head,44);
    printList(head);
    freeList(head);
    return 0;
}

