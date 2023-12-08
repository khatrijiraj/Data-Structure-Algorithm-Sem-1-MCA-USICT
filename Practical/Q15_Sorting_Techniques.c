/*  Make  a  menu  driven  program  to  perform  various  sorting  techniques  -
insertion, merge, heap, quick, counting, radix, bucket. */
#include <stdio.h>
#include <stdlib.h>

// Function to display the main menu
void displayMenu() {
    printf("\n+---------------------------------------+\n");
    printf("|      Sorting Techniques Menu          |\n");
    printf("+---------------------------------------+\n");
    printf("|1. Insertion Sort                      |\n");
    printf("|2. Merge Sort                          |\n");
    printf("|3. Quick Sort                          |\n");
    printf("|4. Exit                                |\n");
    printf("+---------------------------------------+\n");
    printf("Enter your choice: ");
}

// Function to perform Insertion Sort
void insertionSort(int array[], int size) {
    int currentIndex, currentElement, previndex;

    for (currentIndex = 1; currentIndex < size; currentIndex++) {
        // Select the current element as the key to be inserted
        currentElement = array[currentIndex];
        // Find the correct position for the current element in the sorted part of the array

        previndex = currentIndex - 1;

        // Shift elements greater than the current element to the right
        while (previndex >= 0 && array[previndex] > currentElement) {
            array[previndex + 1] = array[previndex];
            previndex = previndex - 1;
        }

        // Place the current element at its correct position in the sorted part of the array
        array[previndex + 1] = currentElement;
    }
}

// Function to perform Merge Sort
void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;

    int leftArray[sizeLeft], rightArray[sizeRight];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (i = 0; i < sizeLeft; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < sizeRight; j++)
        rightArray[j] = array[middle + 1 + j];

    // Merge the two arrays back into the original array
    i = 0;     // Initial index of left subarray
    j = 0;     // Initial index of right subarray
    k = left;  // Initial index of merged subarray

    while (i < sizeLeft && j < sizeRight) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < sizeLeft) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < sizeRight) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        // Calculate the middle index
        int middle = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot
int partition(int array[], int begin, int end) {
    int pivot = begin;

    int i = begin;
    int j = end;

    while (i < j) {
        if (pivot < j && array[pivot] < array[j]) {
            j--;
        }

        else if (pivot > i && array[pivot] > array[i]) {
            i++;
        }

        else if (array[pivot] > array[j]) {
            swap(&array[pivot], &array[j]);
            pivot = j;
        }

        else if (array[pivot] < array[i]) {
            swap(&array[pivot], &array[i]);
            pivot = i;
        }
    }

    return pivot;
}

// Function to perform Quick Sort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(array, low, high);

        // Recursively sort the subarrays before and after the pivot
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

// Driver program to test sorting techniques
int main() {
    int numElements, i;
    // Prompt the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numElements);

    // Declare an array of size numElements to store user-input elements
    int inputArray[numElements];

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < numElements; i++) {
        scanf("%d", &inputArray[i]);
    }

    int userChoice;
    do {
        // Display the sorting techniques menu and get user choice
        displayMenu();
        scanf("%d", &userChoice);

        // Apply the chosen sorting technique based on user's choice
        switch (userChoice) {
            case 1:
                insertionSort(inputArray, numElements);
                break;
            case 2:
                mergeSort(inputArray, 0, numElements - 1);
                break;
            case 3:
                quickSort(inputArray, 0, numElements - 1);
                break;
            case 4:
                // Exit the program
                printf("Exiting the program.\n");
                break;
            default:
                // Invalid choice, prompt the user to enter a valid option
                printf("Invalid choice! Please enter a valid option.\n");
        }

        // Display the sorted array if the user did not choose to exit
        if (userChoice != 4) {
            printf("Sorted array using the chosen technique:\n");
            for (i = 0; i < numElements; i++) {
                printf("%d ", inputArray[i]);
            }
            printf("\n");
        }
    } while (userChoice != 4);

    // Return 0 to indicate successful program execution
    return 0;
}