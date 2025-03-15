/*Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted from their place) required for sorting the array.*/



#include <stdio.h>


void insertionSort(int arr[], int n, int *comparisons, int *shifts) {
    *comparisons = 0;
    *shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        (*shifts)++; 

      
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
            (*shifts)++;
        }

        if (j >= 0) {
            (*comparisons)++; 
        }

        arr[j + 1] = key;
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

        int comparisons = 0, shifts = 0;
        insertionSort(arr, n, &comparisons, &shifts);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Total comparisons: %d\n", comparisons);
        printf("Total shifts: %d\n", shifts);
    }

    return 0;
}
