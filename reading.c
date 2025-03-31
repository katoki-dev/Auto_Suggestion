#include "linkedlist.h"
#include "operation.h"
#include "readcsv.h"

int main() {
    readcsv();
    struct termios originalMode;
    tcgetattr(STDIN_FILENO, &originalMode);

    char letter = '_', word[20] = "";
    int length = 0;

    printf("-press \\ for exiting-\n\n");

    memset(word, 0, sizeof(word));

    while (letter != '\\') {
        setRawMode();
        printf("%s", SENTENCE);
        suggestion(word);
        letter = getchar();  // Waits for a key press without Enter
        printf("\n");
        resetMode(&originalMode);
	if(letter=='\\')
		exit(0);

        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            SENTENCE[SIZE] = word[length] = letter;
            SIZE++;
            length++;
            word[length] = '\0'; // Ensure null termination
        } else {
            if (letter == ' ') {
                SENTENCE[SIZE] = ' ';
                SIZE++;
                length = 0;
                memset(word, 0, sizeof(word));
            } else if (letter == '\b' && length > 0) {
                length--;
                word[length] = '\0';
                SENTENCE[SIZE - 1] = '\0';
                SIZE--;
            }
        }
    }

    printf("\nTotal Prefixes Loaded: %d\n", dictSize);
    return 0;
}
