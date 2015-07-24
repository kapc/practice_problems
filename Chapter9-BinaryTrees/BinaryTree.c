#include "BinaryTree.h"


/*
 * ---------------------------------------------------------------
 *  InsertNode --
 *      Insert a node into given binary tree.
 * ---------------------------------------------------------------
 */
Node *
InsertNode(Node *root, int data)
{
    int res = 0;
    if (root == NULL) {
        Node *newNode = calloc(sizeof(Node), 0);
        newNode->data = data;
        printf("Added node %d\n", newNode->data);
        return newNode;
    }

    if (data > root->data) {
        root->left = InsertNode(root->left, data);
    } else {
        root->right = InsertNode(root->right, data);
    }

    return root;
}

/*
 * -----------------------------------------------------------------
 *  CompareData -- 
 *      Custom comparator function.
 * -----------------------------------------------------------------
 */
int CompareData(void *data1, void *data2)
{
    int val1 = * (int *)data1;
    int val2 = * (int *)data2;

    if (val1 < val2) {
        return -1;
    } else {
        return 1;
    }
}

/*
 * -----------------------------------------------------------------
 *  PrintTree --
 *      Print whole tree.
 * -----------------------------------------------------------------
 */
void
PrintTree(Node *root)
{
    if (root == NULL) {
        return;
    }
    PrintTree(root->left);
    printf("Value is %d\n", root->data);
    PrintTree(root->right);
}

int main(void) {
    Node *root = NULL;

    root = InsertNode(root, 4);
    root = InsertNode(root, 15);
    root = InsertNode(root, -34);

    PrintTree(root);
}
