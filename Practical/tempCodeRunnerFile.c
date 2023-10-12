// Implement operations (traverse, insert, delete, linear search, selection sort) on an array.
#include <stdbool.h>
#include <stdio.h>

// Function to traverse and print the elements of the array
void traverseArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specified position in the array
void insertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position. Element not inserted.\n");
        return;
    }

    // Shift elements to make space for the new element
    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d.\n", element, position);
}

// Function to delete an element at a specified position in the array
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position. Element not deleted.\n");
        return;
    }

    // Shift elements to fill the gap left by the deleted element
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element at position %d deleted.\n", position);
}

// Function to perform linear search for an element in the array
bool linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at position %d.\n", target, i);
            return true;  // Element found
        }
    }
    printf("Element %d not found in the array.\n", target);
    return false;  // Element not found
}

int main() {
    int choice, element, position, target;

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];  // Declare an array of the user-defined size
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);  // Input each element directly into the array
    }

    while (1) {
        printf("\n+-------------------------------------+\n");
        printf("|        Choose Array Operation         |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Traverse Array                    |\n");
        printf("|2. Insert Element                    |\n");
        printf("|3. Delete Element                    |\n");
        printf("|4. Linear Search                     |\n");
        printf("|5. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseArray(arr, size);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                traverseArray(arr, size);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                traverseArray(arr, size);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &target);
                linearSearch(arr, size, target);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}