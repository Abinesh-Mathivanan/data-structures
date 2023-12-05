#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, j, curr, temp;
    for (i = 1; i < n; i++) {
        curr = arr[i];
        j = i - 1;

        // Move elements that are greater than curr to one position ahead of their current position
        while (j >= 0 && arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements to be sorted:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted data: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
