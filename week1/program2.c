#include <stdio.h>

int binarySearch(int arr[], int size, int key, int *comparisons) {
    int left = 0, right = size - 1;
    *comparisons = 0;
    
    while (left <= right) {
        (*comparisons)++;
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;  
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1; 
}

int main() {
    int n, key, comparisons;
    
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
   
    printf("Enter the key to search for: ");
    scanf("%d", &key);
    
  
    int result = binarySearch(arr, n, key, &comparisons);
    
    if (result != -1) {
        printf("Present %d\n", comparisons);
    }
    else {
        printf("Not Present %d\n", comparisons);
    }
    
    return 0;
}
