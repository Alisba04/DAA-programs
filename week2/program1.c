#include <stdio.h>

int BSfirst(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;  
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int BSlast(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

void find_key_and_count(int arr[], int n, int key) {
    int firstoccur = BSfirst(arr, n, key);
    if (firstoccur == -1) {
        printf("Key %d not present\n", key);
        return;
    }
    int lastoccur = BSlast(arr, n, key);
    int count = lastoccur - firstoccur + 1;
    printf("Key %d occurs %d times\n", key, count);
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    while (T--) {
        int n, key;
        printf("Enter the size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements of array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Elements entered: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Enter the key element: ");
        scanf("%d", &key);
        printf("Key entered: %d\n", key);
        find_key_and_count(arr, n, key);
    }
    return 0;
}
