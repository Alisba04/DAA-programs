/*Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find number of comparisons and inversions during sorting the array.*/

#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right, int *comparisons) {
    int i = left, j = mid + 1, k = left;
    int inversions = 0;

    while (i <= mid && j <= right) {
        (*comparisons)++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); 
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}


int mergeSort(int arr[], int temp[], int left, int right, int *comparisons) {
    int mid, inversions = 0;

    if (left < right) {
        mid = (left + right) / 2;

        inversions += mergeSort(arr, temp, left, mid, comparisons);
        inversions += mergeSort(arr, temp, mid + 1, right, comparisons);
        inversions += merge(arr, temp, left, mid, right, comparisons);
    }

    return inversions;
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);

        int arr[n], temp[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int comparisons = 0;
        int inversions = mergeSort(arr, temp, 0, n - 1, &comparisons);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Total comparisons: %d\n", comparisons);
        printf("Total inversions: %d\n", inversions);
    }

    return 0;
}
