#ifndef READCSV_H
#define READCSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

int readcsv() {
    FILE* fp = fopen("vocabulary.csv", "r");
    if (!fp) {
        printf("Can't open file\n");
        return -1;
    }

    char buffer[1024];
    int row = 0;
    char prefix[20];
    NODE *head = NULL;

    while (fgets(buffer, 1024, fp)) {
        if (row++ == 0) continue; // Skip header row

        char* value = strtok(buffer, ",\n");
        if (value) {
            strcpy(prefix, value);
            head = createLinkedList(prefix);
        }

        while ((value = strtok(NULL, ",\n")) != NULL) {
            insertIntoLinkedList(head, value);
        }
    }
    fclose(fp);
    return 0;
}

#endif
