#include<stdio.h>

// Merges two subarrays of collection
// First subarray is leftCollection[left --> center]
// Second subarray is rightCollection[(center + 1) --> right]
void merge(int collection[], int left, int center, int right){
    int i, j, k;
    int n1 = center - left + 1;
    int n2 = right - center;

    // Create temporary arrays
    int leftCollection[n1], rightCollection[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++){
        leftCollection[i] = collection[left + i];
    }

    for(j = 0; j < n2; j++){
        rightCollection[j] = collection[center + 1 + j];
    }

    // Merge the temp arrays back into collection[left --> right]
    i = j = 0;
    k = left;

    while(i < n1 && j < n2){
        if(leftCollection[i] <= rightCollection[j]){
            collection[k] = leftCollection[i];
            i++;
        } else {
            collection[k] = rightCollection[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftCollection[].
    // If there are any
    while(i < n1){
        collection[k] = leftCollection[i];
        i++;
        k++; // Missing increment
    }

    // Copy the remaining elements of rightCollection[],
    // If there are any
    while(j < n2){
        collection[k] = rightCollection[j];
        j++;
        k++; // Missing increment
    }
}

void mergeSort(int collection[], int left, int right){
    if(left < right) {
        // Find the middle point to divide the collection into two halves
        int center = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSort(collection, left, center);
        mergeSort(collection, center + 1, right);

        merge(collection, left, center, right);
    }
}

int main() {
    int collectionSize;

    // Ask the user for the number of elements
    printf("Enter the number of elements in the collection: ");
    scanf("%d", &collectionSize);

    // Validate the input (collection size must be positive)
    while(collectionSize < 1){
        printf("Invalid size! Please enter a positive number.\n");
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

    // Sort the collection using the Merge Sort algorithm
    mergeSort(collection, 0, collectionSize - 1);

     // Display the sorted array after applying Merge Sort
     printf("\nSorted collection (Ascending Order):\n");
     for(int i = 0; i < collectionSize; i++) {
         printf("%d ", collection[i]);
     }
     printf("\n");

    return 0;
}
