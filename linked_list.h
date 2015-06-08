/*
 * Basic Header for linux kernel style linked list.
 */
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#endif

typedef struct ListElement {
    struct ListElement *next;
    struct ListElement *prev;
} ListElement;

typedef struct LinkedList {
    struct ListElement *head;
    struct ListElement *tail;
} LinkedList;

// List of APIs.
bool LinkedList_Insert(ListElement *elem, LinkedList **list);
bool LinkedList_Delete(ListElement *elem, LinkedList **list);
void LinkedList_Print(LinkedList *list);


#ifdef  _LINED_LIST_H_





























#endif
