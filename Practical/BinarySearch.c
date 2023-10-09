#include <stdio.h>
#include <stdlib.h>

void BinarySearchIterative(int arr[], int item, int size) {
    /* We can't calculate size of array using sizeof() function inside 
    this function because once an array passed to an function it decays 
    into a pointer and you lose the information about its size */
    int beg = 0;
    int end = size - 1;
    int flag = 0;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        if (arr[mid] == item) {
            flag = 1;
            printf("Element %d found at index: %d\n", item, mid);
            break;
        } else if (arr[mid] > item) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    if (flag == 0) {
        printf("Element %d not found in the array\n", item);
    }
}

int BinarySearchRecursive(int arr[], int beg, int end, int item) {
    /* We can't calculate size of array using sizeof() function inside 
    this function because once an array passed to an function it decays 
    into a pointer and you lose the information about its size */
    if (beg > end) {
        return -1;
    }
    int mid = beg + (end - beg) / 2;
    if (arr[mid] == item) {
        return mid;
    } else if (arr[mid] > item) {
        end = mid - 1;
        return BinarySearchRecursive(arr, beg, end, item);
    } else {
        beg = mid + 1;
        return BinarySearchRecursive(arr, beg, end, item);
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int item;

    while (1) {
        int choice;
        printf("\n+-------------------------------------+\n");
        printf("|             Main Menu               |\n");
        printf("+-------------------------------------+\n");
        printf("|1. Iterative Binary Search           |\n");
        printf("|2. Recursive Binary Search           |\n");
        printf("|3. Exit                              |\n");
        printf("+-------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &item);
                BinarySearchIterative(arr, item, size);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &item);
                int result = BinarySearchRecursive(arr, 0, size - 1, item);
                if (result != -1) {
                    printf("Element %d found at index: %d\n", item, result);
                } else {
                    printf("Element %d not found in the array\n", item);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}