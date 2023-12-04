
// Function to perform Heap Sort
void heapify(int array[], int size, int rootIndex) {
    int largest = rootIndex;
    int leftChildIndex = 2 * rootIndex + 1;
    int rightChildIndex = 2 * rootIndex + 2;

    // If left child is larger than root
    if (leftChildIndex < size && array[leftChildIndex] > array[largest])
        largest = leftChildIndex;

    // If right child is larger than the largest so far
    if (rightChildIndex < size && array[rightChildIndex] > array[largest])
        largest = rightChildIndex;

    // If the largest is not the root
    if (largest != rootIndex) {
        // Swap the root with the largest element
        int temp = array[rootIndex];
        array[rootIndex] = array[largest];
        array[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(array, size, largest);
    }
}

void heapSort(int array[], int size) {
    // Build the initial heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // Extract elements from the heap one by one
    for (int i = size - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Heapify the reduced heap
        heapify(array, i, 0);
    }
}

// Function to perform Counting Sort
void countingSort(int array[], int size) {
    // Find the maximum value in the array
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Create an array to store the count of each element
    int count[max + 1];
    int output[size];

    // Initialize count array elements to 0
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Count the occurrences of each element in the input array
    for (int i = 0; i < size; i++)
        count[array[i]]++;

    // Modify the count array to store the actual position of elements
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build the output array based on the count array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}
// Function to find the maximum value in the array
int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Function to perform counting sort based on the digits at a specific place value (exp)
void countSort(int array[], int size, int exp) {
    // Temporary array to store the sorted output
    int output[size];

    // Initialize an array to store the count of each digit (0 to 9)
    int count[10] = {0};

    // Count the occurrences of each digit at the specified place value (exp)
    for (int i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Modify the count array to store the actual position of each digit in the output
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array based on the count array and place value (exp)
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

// Function to perform Radix Sort
void radixSort(int array[], int size) {
    // Find the maximum value in the array
    int max = getMax(array, size);

    // Iterate through each digit place value (1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(array, size, exp);
}

// Function to perform Bucket Sort
void bucketSort(int array[], int size) {
    // Find the maximum and minimum values in the array
    int max = array[0];
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }

    // Calculate the range of values
    int range = max - min + 1;

    // Allocate memory for buckets
    int** buckets = (int**)malloc(range * sizeof(int*));
    for (int i = 0; i < range; i++) {
        buckets[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the buckets
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < size; j++) {
            buckets[i][j] = 0;
        }
    }

    // Distribute elements into the buckets based on their value
    for (int i = 0; i < size; i++) {
        buckets[array[i] - min][i] = array[i];
    }

    // Merge the elements from the buckets back into the original array
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j] != 0) {
                array[index++] = buckets[i][j];
            }
        }
    }

    // Free memory used by buckets
    for (int i = 0; i < range; i++) {
        free(buckets[i]);
    }
    free(buckets);
}
