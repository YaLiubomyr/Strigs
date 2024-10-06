#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("Enter a string to convert to uppercase (up to 99 characters, or type 'q' to quit): ");

        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (strcmp(input, "q\n") == 0) {
                break;
            }

            size_t length = strcspn(input, "\n");
            if (length >= MAX_INPUT_SIZE - 1) {
                input[MAX_INPUT_SIZE - 1] = '\0';
                printf("\nInput is too long. Only the first 99 characters will be processed.\n\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
            else {
                input[length] = '\0';
            }

            for (int i = 0; input[i] != '\0'; i++) {
                if (input[i] >= 'a' && input[i] <= 'z') {
                    input[i] = input[i] - ('a' - 'A');
                }
            }

            printf("Uppercase: %s\n\n", input);
        }
        else {
            printf("Error reading input.\n\n");
        }
    }

    return 0;
}
