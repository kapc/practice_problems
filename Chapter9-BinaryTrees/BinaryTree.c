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
