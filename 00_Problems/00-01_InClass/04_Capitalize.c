#include <stdio.h>
#include <stdlib.h>

// Function to capitalize the letter given
void capitalize(char* letter) { // Takes a pointer to the char gien as argument
    // Checks if invalid alphabet char
    if (*letter < 97 || *letter > 122)
        return; // If invalid return

    // In ASCII table we have a gap of 32 letters between the uppercase and lowecase letters
    (*letter) -= 32;
}

int main() {
    char letter;

    // Get input from user
    printf("Insert a lowercase letter(from english alphabet): ");
    scanf("%c", &letter);

    // Capitalize and print th input
    capitalize(&letter);
    printf("This is you letter in uppercase: %c\n", letter);

    return 0;
}
