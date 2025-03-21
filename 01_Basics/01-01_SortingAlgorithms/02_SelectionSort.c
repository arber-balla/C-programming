#include <stdio.h>

// Function to perform Selection Sort (Ascending Order)
void selectionSort(int collection[], int collectionSize) {
    int tempMinValue, minValueIndex, temp;

    // Iterate over the array, setting each element in place one at a time
    for (int i = 0; i < collectionSize - 1; i++) {
        // Assume the current element is the smallest
        tempMinValue = collection[i];
        minValueIndex = i;

        // Scan the rest of the array to find the actual smallest element
        for (int j = i + 1; j < collectionSize; j++) {
            if (collection[j] < tempMinValue) { // Change '<' to '>' for descending order
                tempMinValue = collection[j];
                minValueIndex = j;
            }
        }

        // Swap the smallest element found with the current element at index 'i'
        temp = collection[i];
        collection[i] = collection[minValueIndex];
        collection[minValueIndex] = temp;
    }
}

int main() {
    int collectionSize;

    // Ask the user for the number of elements
    printf("Enter the number of elements in the collection: ");
    scanf("%d", &collectionSize);

    // Validate input (collection size must be positive)
    while (collectionSize < 1) {
        printf("Invalid size! Please enter a positive number.\n");
        scanf("%d", &collectionSize);
    }

    // Declare the array with user-specified size
    int collection[collectionSize];

    // Prompt the user to enter each element of the collection
    printf("Enter %d elements:\n", collectionSize);
    for (int i = 0; i < collectionSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &collection[i]);
    }

    // Sort the collection using Selection Sort
    selectionSort(collection, collectionSize);

    // Display the sorted collection
    printf("\nSorted collection (Ascending Order):\n");
    for (int i = 0; i < collectionSize; i++) {
        printf("%d ", collection[i]);
    }
    printf("\n");

    return 0;
}
