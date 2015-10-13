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

    printf("Value is %d\n", root->data);
    PrintTree(root->left);
    PrintTree(root->right);
}

/*
 * ----------------------------------------------------------------
 *  IsSymmetricTree --
 *      Check if the tree is truely symmetric.
 * ---------------------------------------------------------------
 */
int
IsSymmetricTree(Node *leftSubTree, Node *rightSubTree)
{
    if (leftSubTree == NULL || rightSubTree == NULL) {
        return (leftSubTree == NULL && rightSubTree == NULL);
    }

    return (leftSubTree->data == rightSubTree->data) && 
            IsSymmetricTree(leftSubTree->left, rightSubTree->right) && 
            IsSymmetricTree(leftSubTree->right, rightSubTree->left);
}

int
main(void) {
    Node *root = NULL;
    root = InsertNode(root, 15);
    root = InsertNode(root, 20);
    root = InsertNode(root, 10);
    root = InsertNode(root, 25);
    root = InsertNode(root, 17);
    root = InsertNode(root, 7);
    root = InsertNode(root, 13);
    PrintTree(root);
    if (IsSymmetricTree(root->left, root->right)) {
        printf("Tree is symmetric.");
    } 
}
