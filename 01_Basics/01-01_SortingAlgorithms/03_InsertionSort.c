#include <stdio.h>

// Function to perform Insertion Sort (Ascending order)
void insertSort(int collection[], int collectionSize){
    // Declaration of temporary variable and indexing variable
    int temp, j;

    // Start iterating over the array from the second element
    // (since the first element is already considered sorted)
    for(int i = 1; i < collectionSize; i++){
        // Store the current element to be inserted into the sorted portion
        temp = collection[i];

        // Start comparing from the element before the current element
        j = i-1;

        // Shift elements in the sorted portion to the right until the correct position for temp is found
        while(j >= 0 && temp < collection[j]){
            collection[j+1] = collection[j];
            j--;
        }
        collection[j+1] = temp;
    }
}

int main() {
    int collectionSize;

    // Ask the user for the number of elements
    printf("Enter the number of elements in the collection: ");
    scanf("%d", &collectionSize);

    // Validate the input (collection size must be positive)
    while(collectionSize < 1){
        printf("invalid size! Pleaze insert a positive number.\n");
        scanf("%d", &collectionSize);
    }

    // Declare the array with the user-specified size
    int collection[collectionSize];

    // Prompt the user to enter each element of the collection
    printf("Enter %d elements:\n", collectionSize);
    for(int i = 0; i < collectionSize; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &collection[i]);
    }

    // Sort the collection using the Insertion Sort algorithm
    insertSort(collection, collectionSize);

     // Display the sorted array after applying Insertion Sort
     printf("\nSorted collection (Ascending Order):\n");
     for(int i = 0; i < collectionSize; i++) {
         printf("%d ", collection[i]);
     }
     printf("\n");

    return 0;
}
