/*Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.*/


#include <stdio.h>

int count_pairs(int arr[], int n, int K) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == K || arr[j] - arr[i] == K) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    while (T--) {
        int n, K;
        printf("Enter the size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements of array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Enter the key element: ");
        scanf("%d", &K);
        int result = count_pairs(arr, n, K);
        printf("%d\n", result);
    }
    return 0;
}
