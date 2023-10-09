#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int size) {
    for (int currentIndex = 1; currentIndex < size; currentIndex++) {
        int currentValue = arr[currentIndex];
        int previousIndex = currentIndex - 1;

        while (previousIndex >= 0 && arr[previousIndex] > currentValue) {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex = previousIndex - 1;
        }
        arr[previousIndex + 1] = currentValue;

        // Print the array after each pass
        printf("Array after pass %d: ", currentIndex);
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1;  // Return an error code
    }

    int arr[size];
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;  // Return an error code
        }
    }

    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, size);

    printf("Final sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}