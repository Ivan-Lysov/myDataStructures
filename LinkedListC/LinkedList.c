#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct node_t* init(int a) {
    struct node_t* node = calloc(1, sizeof(*node));
    if (!node) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }
    node->data = a;
    node->next = NULL;
    return node;
}

void printList(const struct node_t *plist) {
    for (const struct node_t *p = plist; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void freeList(struct node_t *plist) {
    struct node_t *p = plist;
    while (p) {
        struct node_t *tmp = p->next;
        free(p);
        p = tmp;
    }
}

int getSize(const struct node_t *head) {
    int count = 0;
    for (const struct node_t *p = head; p; p = p->next) {
        count++;
    }
    return count;
}

struct node_t* addNode(struct node_t* lem, int data_) {
    struct node_t *newNode = calloc(1, sizeof(*newNode));
    if (!newNode) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data_;
    if (!lem) {
        newNode->next = NULL;
        return newNode;
    }
    newNode->next = lem->next;
    lem->next = newNode;
    return newNode;
}

struct node_t* removeNode(struct node_t *head, struct node_t *target) {
    if (!head)
        return NULL;
    if (!target)
        return head;

    if (head == target) {
        struct node_t *newHead = head->next;
        free(head);
        return newHead;
    }

    struct node_t *prev = head;
    while (prev->next && prev->next != target) {
        prev = prev->next;
    }
    if (prev->next == target) {
        prev->next = target->next;
        free(target);
    }
    return head;
}

struct node_t* swapNodes(struct node_t *head, struct node_t *a, struct node_t *b) {
    if (!head || !a || !b || a == b)
        return head;

    struct node_t *prevA = NULL, *prevB = NULL, *cur = head;
    while (cur) {
        if (cur->next == a) prevA = cur;
        if (cur->next == b) prevB = cur;
        cur = cur->next;
    }
    if ((head != a && !prevA) || (head != b && !prevB))
        return head;

    if (prevA)
        prevA->next = b;
    else
        head = b;
    if (prevB)
        prevB->next = a;
    else
        head = a;
        
    struct node_t *tmp = a->next;
    a->next = b->next;
    b->next = tmp;

    return head;
}

struct node_t* pushFront(struct node_t *head, int data_) {
    struct node_t *newNode = calloc(1, sizeof(*newNode));
    if (!newNode) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data_;
    newNode->next = head;
    return newNode;
}

struct node_t* pushBack(struct node_t *head, int data_){
    struct node_t *tmp = init(data_);
    if (!head){
        return tmp;
    }
    struct node_t *newNode = head;
    while(newNode->next!=NULL){
        newNode = newNode->next;
    }
    newNode -> next = tmp;
    return head;
}

struct node_t* insertAt(struct node_t *head, int index, int data_){
    if (index < 0 || index > getSize(head)){
        fprintf(stderr, "insertAt: incorrect index %d (size %d)\n", index, getSize(head));
        abort();
    }
    int i = 0;
    struct node_t *cur = head;
    if (index==0){
        return pushFront(head,data_);
    }
    else{
        while(i!=index-1){
            cur=cur->next;
            i++;
        }
    }
    addNode(cur,data_);
    return head;
}

struct node_t* removeNodeByValue (struct node_t *head, int value)
{
    if (!head){
        return NULL;
    }
    if(head->data==value){
        struct node_t *newHead = head->next;
        free(head);
        return newHead;
    }
    struct node_t *cur = head->next;
    struct node_t *prev = head;
    while (cur && cur->data != value){
        prev = cur;
        cur=cur->next;
    }
    if(!cur){
        return head;
    }
    prev->next = cur->next;
    free(cur);
    return head;
}