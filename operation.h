#ifndef OPERATION_H
#define OPERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "linkedlist.h"

char SENTENCE[200] = "";
int SIZE = 0;

void setRawMode() {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void resetMode(struct termios *tty) {
    tcsetattr(STDIN_FILENO, TCSANOW, tty);
}

// Function to display suggestions for a prefix
int compareWords(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void suggestion(char word[20]) {
    if (strlen(word) >= 3) {
        char *matchedWords[20]; // Array to store matching words
        int matchedCount = 0;

        // Scan all words in the dictionary
        for (int i = 0; i < dictSize; i++) {
            NODE* result = dict[i].head; // Start from the prefix node
            
            while (result != NULL) {
                // Check if the word starts with the user's input
                if (strncmp(result->word, word, strlen(word)) == 0) {
                    matchedWords[matchedCount] = result->word;
                    matchedCount++;
                }
                result = result->next;
            }
        }

        // Sort matched words alphabetically
        qsort(matchedWords, matchedCount, sizeof(char *), compareWords);

        // Display suggestions
        int n;
        if(matchedCount>5)
            n=5;
        else
            n=matchedCount;
	if(n>0){
        printf(" [ Suggestions: ");
        for (int i = 0; i < n; i++) {
            printf("%s ", matchedWords[i]);
        }
        printf("] ");
	}
    }
}

#endif
