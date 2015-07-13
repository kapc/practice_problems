#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct linkedNode {
    int data;
    struct linkedNode *next;
} Node;

/*
 * ------------------------------------------------------------
 *  InsertNode --
 *      Insert a node into the linked list.
 * ------------------------------------------------------------
 */
Node * 
InsertNode(Node *head, int data)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);

    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head = newNode;
    return head;
}

/*
 * -------------------------------------------------------------
 *  PrintLinkedList --
 *      Print a linked list.
 * -------------------------------------------------------------
 */
void
PrintLinkedList(Node *head)
{
    Node *tmp = head;

    while(tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

/*
 * -------------------------------------------------------------
 *  MergeLinkedList --
 *      Merget two linked lists.
 * -------------------------------------------------------------
 */
Node *
MergeLinkedLists(Node *head1, Node *head2)
{
    Node *newList, *head;

    if (head1->data < head2->data) {
        newList = head1;
        head1 = head1->next;
    } else {
        newList = head2;
        head2 = head2->next;
    }

    head = newList;
    while(head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            newList->next = head1;
            head1 = head1->next;
        } else {
            newList->next = head2;
            head2 = head2->next;
        }
        newList = newList->next;
    }

    while (head1 != NULL) {
        newList->next = head1;
        newList = newList->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        newList->next = head2;
        newList = newList->next;
        head2 = head2->next;
    }

    return head;
}

int main(void)
{
    Node *head1 = NULL, *head2 = NULL;
    Node *result;

    head1 = InsertNode(head1, 44);
    head1 = InsertNode(head1, 22);
    head1 = InsertNode(head1, 11);

    head2 = InsertNode(head2, 41);
    head2 = InsertNode(head2, 31);
    head2 = InsertNode(head2, 11);

    result = MergeLinkedLists(head1, head2);
    PrintLinkedList(result);
}

