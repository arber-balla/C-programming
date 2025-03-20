#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    int lastSwap = size, temp;

    while (lastSwap > 0) {
        int newSwap = 0;  // Track the last swap position

        for (int i = 0; i < lastSwap - 1; i++) {  // Ensure we stay within bounds
            if (arr[i] < arr[i + 1]) { // Swap for descending order
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                newSwap = i + 1; // Store last swap index
            }
        }

        lastSwap = newSwap; // Reduce the sorting boundary
    }
}

int main() {
    int collectionSize;

    // Ask the user for the collection size
    printf("Enter the number of elements in the collection: ");
    scanf("%d", &collectionSize);

    // Validate input
    while (collectionSize < 1) {
        printf("Invalid size! Please enter a positive number.\n");
        scanf("%d", &collectionSize);
    }


    int collection[collectionSize];

    // Prompt user to enter elements
    printf("Enter %d elements:\n", collectionSize);
    for (int i = 0; i < collectionSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &collection[i]);
    }

    // Call the sorting function
    bubbleSort(collection, collectionSize);

    // Display the sorted collection
    printf("\nSorted collection (Descending Order):\n");
    for (int i = 0; i < collectionSize; i++) {
        printf("%d ", collection[i]);
    }
    printf("\n");

    return 0;
}
