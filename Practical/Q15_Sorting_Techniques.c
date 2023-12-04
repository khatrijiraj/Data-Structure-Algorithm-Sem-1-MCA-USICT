/*  Make  a  menu  driven  program  to  perform  various  sorting  techniques  -
insertion, merge, heap, quick, counting, radix, bucket. */
#include <stdio.h>
#include <stdlib.h>

// Function to display the main menu
void displayMenu() {
    printf("\n+----------------------------------------+\n");
    printf("|      Sorting Techniques Menu          |\n");
    printf("+----------------------------------------+\n");
    printf("|1. Insertion Sort                      |\n");
    printf("|2. Merge Sort                          |\n");
    printf("|3. Quick Sort                          |\n");
    printf("|4. Exit                                |\n");
    printf("+----------------------------------------+\n");
    printf("Enter your choice: ");
}

// Function to perform Insertion Sort
void insertionSort(int array[], int size) {
    int currentIndex, currentElement, comparisonIndex;

    for (currentIndex = 1; currentIndex < size; currentIndex++) {
        // Select the current element as the key to be inserted
        currentElement = array[currentIndex];
        // Find the correct position for the current element in the sorted part of the array

        comparisonIndex = currentIndex - 1;

        // Shift elements greater than the current element to the right
        while (comparisonIndex >= 0 && array[comparisonIndex] > currentElement) {
            array[comparisonIndex + 1] = array[comparisonIndex];
            comparisonIndex = comparisonIndex - 1;
        }

        // Place the current element at its correct position in the sorted part of the array
        array[comparisonIndex + 1] = currentElement;
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

// Function to partition the array and return the index of the pivot
int partition(int array[], int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = array[high];

    // Initialize the index of the smaller element
    int smallerIndex = (low - 1);

    // Iterate through the elements from low to high-1
    for (int currentIndex = low; currentIndex <= high - 1; currentIndex++) {
        // If the current element is smaller than or equal to the pivot
        if (array[currentIndex] <= pivot) {
            // Swap array[smallerIndex + 1] and array[currentIndex]
            smallerIndex++;
            int temp = array[smallerIndex];
            array[smallerIndex] = array[currentIndex];
            array[currentIndex] = temp;
        }
    }

    // Swap array[smallerIndex + 1] and array[high] to place the pivot in its correct position
    int temp = array[smallerIndex + 1];
    array[smallerIndex + 1] = array[high];
    array[high] = temp;

    // Return the index of the pivot
    return (smallerIndex + 1);
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
    printf("Ahh!!! Shit here we go again!\n");
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