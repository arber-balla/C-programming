#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define IN_FILE "lists.txt"

// Count valid characters (letters or *) in a word
int countValidChars(char string[]) {
    int count = 0;
    while (string[count] != '\0') {
        char c = string[count];
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '*') {
            count++;
        } else {
            break;  // Stop at first invalid character
        }
    }
    return count;
}

// Validate all characters in a word are valid (letters or *)
int isValidString(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        char c = string[i];
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c == '*'))) {
            return 0;  // Invalid character found
        }
    }
    return 1;
}

// Check if jolly string matches compare string
int isJollyMatch(const char* jolly_string, const char* compare_string) {
    int jolly_len = countValidChars(jolly_string);
    int compare_len = countValidChars(compare_string);

    // Length mismatch check
    if (jolly_len != compare_len) return 0;

    // Character-by-character comparison
    for (int i = 0; i < jolly_len; i++) {
        if (jolly_string[i] != '*' && jolly_string[i] != compare_string[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char jolly_word[MAX_LEN + 1];  // +1 for null terminator (\0)

    printf("Enter jolly word (letters and * only): ");
    if (scanf("%100s", jolly_word) != 1) {
        printf("Error reading input\n");
        return 1;
    }

    // Validate jolly word format
    if (!isValidString(jolly_word)) {
        printf("Error: Jolly word contains invalid characters\n");
        return 1;
    }

    FILE* file = fopen(IN_FILE, "r");
    if (!file) {
        printf("Error: Could not open %s\n", IN_FILE);
        return 1;
    }

    char current_word[MAX_LEN];
    while (fgets(current_word, sizeof(current_word), file) != NULL) {
        // Remove newline character
        current_word[strcspn(current_word, "\n")] = '\0';

        // Skip empty lines
        if (current_word[0] == '\0') continue;

        if (isJollyMatch(jolly_word, current_word)) {
            printf("%s\n", current_word);
        }
    }

    fclose(file);
    return 0;
}
