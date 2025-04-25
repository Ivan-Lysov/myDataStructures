#include <stdio.h>
#include <stdlib.h>
struct node_t {
  struct node_t *next;
  int data;
};
struct node_t *init(int a);
struct node_t *addNode(struct node_t *lem, int data_);
struct node_t *removeNode(struct node_t *lst, struct node_t *root);
int getSize(const struct node_t *head);
void printList(const struct node_t *plist);
void freeList(struct node_t *plist);
struct node_t *readList(FILE *f);
struct node_t *swapNodes(struct node_t *head, struct node_t *a,
                         struct node_t *b);
struct node_t *pushFront(struct node_t *head, int data_);
struct node_t *pushBack(struct node_t *head, int data);
struct node_t *insertAt(struct node_t *head, int index, int data);
struct node_t *removeNodeByValue(struct node_t *head, int value);
struct node_t *findNode(struct node_t *head, int value);
struct node_t *removeAt(struct node_t *head, int index);
