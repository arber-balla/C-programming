#include <stdio.h>

void selectionSort(int collection[], int collectionSize) {

    int tempMinValue, minValueIndex, temp;

    // Iterate over the colletion from first to the n - 2 element
    for(int i = 0; i < collectionSize - 1; i++){
        // Initialize the temporary values to the first element in range
        tempMinValue = collection[i];
        minValueIndex = i;

        // Iterate from the i + 1 element to the last one and keep track of the smallest you encounter (initial value too)
        for(int j = i + 1; j < collectionSize; j++){
            if(collection[j] < tempMinValue){  // '<' for ascending order || '>' for descending order
                tempMinValue = collection[j];
                minValueIndex = j;
            }
        }

        // Exchange the variables so the smallest one goes first
        temp = collection[i];
        collection[i] = collection[minValueIndex];
        collection[minValueIndex] = temp;
    }
}

int main() {

    // Get the number of elements in data collection
    int collectionSize;
    printf("Insert the number of elements in the collection: ");
    scanf("%d", &collectionSize);

    // Read the data collection
    int collection[collectionSize];
    printf("Insert the data elements: ");
    
    for(int i = 0; i < collectionSize; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &collection[i]);
    }

    // Sort the data using the selection sort algorithm
    selectionSort(collection, collectionSize);

    // Print the ordered array
    for(int i = 0; i < collectionSize; i++) {
        printf("%d ", collection[i]);
    }

    return 0;
}
