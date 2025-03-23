#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int collection[], int low, int high){
    // Choose the pivot
    int pivot = collection[high];

    // Index of the smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse the collection[low --> high] and move all smaller
    // elements to the left side. Elements from low to i are
    // smaller after every iteration
    for(int j = low; j <= high - 1; j++){
        if(collection[j] < pivot){
            i++;
            swap(&collection[i], &collection[j]);
        }
    }

    // Move the pivot after the smaller elements and
    // Return its position
    swap(&collection[i + 1], &collection[high]);
    return i + 1;
}

// The QuickSort function implememtation
void quickSort(int collection[], int low, int high){
    if(low < high){
        // pi is the parition return index of pivot
        int pi = partition(collection, low, high);

        // Recursion calls for smaller elemets
        // and greater elememts or equal elements
        quickSort(collection, low, pi - 1);
        quickSort(collection, pi + 1, high);
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
    quickSort(collection, 0, collectionSize - 1);

     // Display the sorted array after applying Merge Sort
     printf("\nSorted collection (Ascending Order):\n");
     for(int i = 0; i < collectionSize; i++) {
         printf("%d ", collection[i]);
     }
     printf("\n");

    return 0;
}
