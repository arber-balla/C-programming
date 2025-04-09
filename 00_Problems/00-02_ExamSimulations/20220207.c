#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the forst instance of the word in a phrase
int findWord(const char phrase[], const char word[]) {
    // Get the length of both strings
    int phrase_length = strlen(phrase);
    int word_length = strlen(word);

    // Used to store the number of matching charsachters in strings
    int matching_chars = 0;

    // If word is null it is always found first
    if (word_length == 0) {
        return 0;
    }

    // Iterate over the phrase
    for (int i = 0; i <= phrase_length - word_length; i++) {
        matching_chars = 0;
        // Iterate over the word and comare the characters
        for (int j = 0; j < word_length; j++) {
            // If charachters match go to the next one
            if (word[j] == phrase[i + j]) {
                // Increment the number of matching chars
                matching_chars++;
            } else {
                // If charachters don't match then break the cycle and move the word
                break;
            }
        }

        // If all charachters match then return the index of the forst letter
        if (matching_chars == word_length) {
            return i;
        }
    }

    // If the word is not found return a negative index
    return -1;
}

//! FOR TESTING PUPROSES
int main() {
    char phrase[] = "La volpe e l'uva";
    char word[] = "uva";

    int found_position = findWord(phrase, word);

    printf("%d\n", found_position);

    return 0;
}
