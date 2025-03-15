/*Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting)
(Time Complexity = O(n log n))*/


#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int hasDuplicates(int arr[], int n) {
   
    qsort(arr, n, sizeof(int), compare);

   
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return 1;
        }
    }
    return 0; 

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

        if (hasDuplicates(arr, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
