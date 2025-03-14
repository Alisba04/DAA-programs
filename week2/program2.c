#include <stdio.h>

void find_indices(int arr[], int n) {
    int found = 0;
    for (int k = n - 1; k >= 0; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (arr[i] + arr[j] == arr[k]) {
                printf("%d %d %d\n", i, j, k);
                found = 1;
                return;
            } else if (arr[i] + arr[j] < arr[k]) {
                i++;
            } else {
                j--;
            }
        }
    }
    if (!found) {
        printf("No sequence found\n");
    }
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    while (T--) {
        int n;
        printf("Enter the size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements of array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        find_indices(arr, n);
    }
    return 0;
}
