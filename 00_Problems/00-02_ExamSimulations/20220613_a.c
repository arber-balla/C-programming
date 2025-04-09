#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold pointers to the sum and average matches
typedef struct {
    float* sum_ptr;       // Pointer to element in V2 matching the sum of V1
    float* average_ptr;   // Pointer to element in V2 matching the average of V1
} Pointers;

// Function to find elements in V2 that match the sum and average of V1
Pointers findSumAndAverage(float* v1, int s1, float* v2, int s2) {
    // Initialize result pointers to NULL (no matches found yet)
    Pointers pointers = {NULL, NULL};
    float sum = 0, average = 0;

    // Calculate the sum of all elements in V1
    for (int i = 0; i < s1; i++) {
        sum += v1[i];
    }

    // Calculate the average of elements in V1
    average = sum / s1;

    // Search through V2 for elements matching sum and average
    for (int i = 0; i < s2; i++) {
        // Check for sum match (note: direct float comparison is not recommended)
        if (v2[i] == sum) pointers.sum_ptr = &v2[i];
        // Check for average match
        if (v2[i] == average) pointers.average_ptr = &v2[i];
    }

    return pointers;
}

int main() {
    // Test data: V1 and V2 arrays
    float v1[] = {1, 2, 3, 4};    // Sum = 10, Average = 2.5
    int len1 = sizeof(v1)/sizeof(v1[0]);  // Calculate length of V1
    float v2[] = {5, 34, 10, 2.5}; // Expected matches: 10 (sum) and 2.5 (average)
    int len2 = sizeof(v2)/sizeof(v2[0]);  // Calculate length of V2

    // Find the matching elements
    Pointers p = findSumAndAverage(v1, len1, v2, len2);

    // Print results (with null check for safety)
    if (p.average_ptr != NULL && p.sum_ptr != NULL) {
        printf("Average match: %.2f at position %ld\n",
               *(p.average_ptr),
               p.average_ptr - v2);
        printf("Sum match: %.2f at position %ld\n",
               *(p.sum_ptr),
               p.sum_ptr - v2);
    } else {
        printf("Not all matches were found.\n");
    }

    return 0;
}
