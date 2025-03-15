/*Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array*/

#include <stdio.h>

void swp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int rndPivot(int low, int high, int n) {
    return low + (n % (high - low + 1));
}

int part(int arr[], int low, int high, int *cmp, int *swpCount) {
    int pivotIdx = rndPivot(low, high, high - low + 1);
    swp(&arr[pivotIdx], &arr[high]);
    (*swpCount)++;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*cmp)++;
        if (arr[j] < pivot) {
            i++;
            swp(&arr[i], &arr[j]);
            (*swpCount)++;
        }
    }
    swp(&arr[i + 1], &arr[high]);
    (*swpCount)++;
    return i + 1;
}


void qSort(int arr[], int low, int high, int *cmp, int *swpCount) {
    if (low < high) {
        int pi = part(arr, low, high, cmp, swpCount);
        qSort(arr, low, pi - 1, cmp, swpCount);
        qSort(arr, pi + 1, high, cmp, swpCount);
    }
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int cmp = 0, swpCount = 0;
        qSort(arr, 0, n - 1, &cmp, &swpCount);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Total comparisons: %d\n", cmp);
        printf("Total swaps: %d\n", swpCount);
    }

    return 0;
}
