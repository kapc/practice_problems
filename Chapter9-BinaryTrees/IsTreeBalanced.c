#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"


static int inline
max(int a, int b)
{
    return (a < b) ? b : a;
}
/*
 * -----------------------------------------------------
 *  Height -- 
 *      Return the height of the tree.
 * -----------------------------------------------------
 */
int
Height(Node *root)
{
    if (root == NULL) {
        return 0;
    }

    return max(Height(root->left), Height(root->right)) + 1;
}

/*
 * -----------------------------------------------------
 *  IsTreeBalanced --
 *      Check if the tree is balanced or not.
 *
 *  Results:
 *      returns true if balanced, false otherwise.
 * -----------------------------------------------------
 */
bool
IsTreeBalanced(Node *root)
{
    int leftHeight = 0, rightHeight = 0;
    if (root == NULL) {
        return true;
    }

    leftHeight = Height(root->left);
    rightHeight = Height(root->right);
    
    return ((leftHeight - rightHeight) < 2);

}

int main(void) {
    Node *root = NULL;
    root = InsertNode(root, 1);
    root = InsertNode(root, 3);
    root = InsertNode(root, 5);
    root = InsertNode(root, 10);

    PrintTree(root);
    printf("Height of the tree is %d\n", Height(root));

    printf("Is the tree balanced? %s\n", IsTreeBalanced(root) ? "true" : "false");

}

