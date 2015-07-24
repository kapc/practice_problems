/*
 *
 *
 */

#ifndef         _BINARY_TREE
#define         _BINARY_TREE

#include <stdio.h>
#include <stdlib.h>

/* Basic tree node. */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Basic Tree structure. */
typedef struct BTree {
    Node *root;
} BTree;

void CheckIfNodeExists(Node *root, void *data);
Node * InsertNode(Node *root, int data);
void DeleteNode(Node *root, void *data);
void PrintTree(Node *root);
int  Height(Node *root);
int  Depth(Node *root);

#endif

