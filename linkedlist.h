#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
    char word[20];
    struct node *next;
} NODE;

typedef struct item {
    char prefix[20];
    NODE *head; // Pointer to the first word in the list
} ITEM;

ITEM dict[MAX]; // Dictionary storing prefixes and their words
int dictSize = 0;

// Function to create a linked list for a given prefix
NODE* createLinkedList(char prefix[20]) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if (!node) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(node->word, prefix);
    node->next = NULL;

    strcpy(dict[dictSize].prefix, prefix);
    dict[dictSize].head = node;
    dictSize++;

    return node;
}

// Function to insert a word into an existing linked list
void insertIntoLinkedList(NODE *head, char word[20]) {
    if (!head) return;

    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(temp->word, word);
    temp->next = NULL;

    NODE *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

// Function to search for a prefix in the dictionary
NODE* search(char prefix[20]) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dict[i].prefix, prefix) == 0) {
            return dict[i].head->next; // Return linked list of words
        }
    }
    return NULL; // Prefix not found
}

#endif
