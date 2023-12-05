#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int target, int n) {
    int first = 0, last = n - 1, mid;

    while (first <= last) {
        mid = (first + last) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index 'mid'
        } else if (arr[mid] < target) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }

    return -1; // Target not found in the list
}

int main() {
    int n, target;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the sorted list of numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target number to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, target, n);

    if (result != -1) {
        printf("Target %d found at index %d.\n", target, result);
    } else {
        printf("Target %d not found in the list.\n", target);
    }

    return 0;
}
