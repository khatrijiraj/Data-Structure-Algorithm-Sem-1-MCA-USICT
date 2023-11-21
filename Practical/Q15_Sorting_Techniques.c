/*  Make  a  menu  driven  program  to  perform  various  sorting  techniques  -
insertion, merge, heap, quick, counting, radix, bucket. */
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void countingSort(int arr[], int n);
void radixSort(int arr[], int n);
void bucketSort(int arr[], int n);

// Function to display the main menu
void displayMenu() {
    printf("\n+----------------------------------------+\n");
    printf("|      Sorting Techniques Menu          |\n");
    printf("+----------------------------------------+\n");
    printf("|1. Insertion Sort                      |\n");
    printf("|2. Merge Sort                          |\n");
    printf("|3. Heap Sort                           |\n");
    printf("|4. Quick Sort                          |\n");
    printf("|5. Counting Sort                       |\n");
    printf("|6. Radix Sort                          |\n");
    printf("|7. Bucket Sort                         |\n");
    printf("|8. Exit                                |\n");
    printf("+----------------------------------------+\n");
    printf("Enter your choice: ");
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to perform Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// Function to perform Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];
    int output[n];

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to perform Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int** buckets = (int**)malloc(range * sizeof(int*));

    for (int i = 0; i < range; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < n; j++) {
            buckets[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        buckets[arr[i] - min][i] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < range; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Driver program to test sorting techniques
int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertionSort(arr, n);
                break;

            case 2:
                mergeSort(arr, 0, n - 1);
                break;

            case 3:
                heapSort(arr, n);
                break;

            case 4:
                quickSort(arr, 0, n - 1);
                break;

            case 5:
                countingSort(arr, n);
                break;

            case 6:
                radixSort(arr, n);
                break;

            case 7:
                bucketSort(arr, n);
                break;

            case 8:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

        if (choice != 8) {
            printf("Sorted array using the chosen technique:\n");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

    } while (choice != 8);

    return 0;
}