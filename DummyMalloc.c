#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node {
	bool endWord;
	int count;
	struct node *list[26];
} TrieNode;

void initTrie(TrieNode **head) 
{
	*head = malloc(sizeof(TrieNode));
	(*head)->endWord = false;
	for(int i = 0; i < 26; i++) {
		(*head)->list[i] = NULL;
	}
	(*head)->count = 0;
}

void InsertNode(TrieNode **head, char *name)
{
	TrieNode *cur = *head;
	TrieNode *new;
	if (head == NULL || *head == NULL) {
		printf("Invalid Trie");
		return;
	}

	if (name[0] == '\0') {
		cur->endWord = true;
		return;
	}

	if (cur->list[name[0] - 'a'] == NULL) {
		initTrie(&new);
		cur->list[name[0] - 'a'] = new;
	} else {
		new = cur->list[name[0] - 'a'];
		new->count++;
	}
	InsertNode(&new, name + 1);
}

int CountNode(TrieNode *head)
{
	int count = 0;
	if (head == NULL) {
		return 0;
	}	

	for(int i = 0; i < 26; i++) {
		TrieNode *cur = head->list[i];
		if (cur != NULL) {
			if (cur->endWord == true) {
				count = count + 1;
			}
			count += CountNode(cur);
		}
	}

	return count;
}

bool findNode(TrieNode *head, char *name, TrieNode **lastNode) {
	bool result = false;
	if (name[0] == '\0') {
		return true;
	}

	TrieNode *cur = head->list[name[0] - 'a'];
	if (cur == NULL) {
		return false;
	}
	for (int i = 0; i < 26; i++) {
		result = findNode(cur, name + 1, lastNode);
	}
	if (result) {
		*lastNode = cur;
	}
	return result;
}

int main(void)
{
	TrieNode *head, *res;
	int count;
	initTrie(&head);
	InsertNode(&head, "chandu");
	InsertNode(&head, "chandumadan");
	InsertNode(&head, "chandraman");
	InsertNode(&head, "palak");
	printf("\ncount = %d", CountNode(head));
	if (findNode(head, "chan", &res)) {
		printf("\nFound chan");
		printf("Result : %d", CountNode(res));
	}	
	if (findNode(head, "chtn", &res)) {
		printf("\nFound");
	}	
}



