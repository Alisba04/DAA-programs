#include <stdio.h>

void linearSearch(int arr[], int size, int key) {
    int comparisons = 0;
    int found = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            printf("Present %d\n", comparisons);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Not Present %d\n", comparisons);
    }
}

int main() {
    int n, key;
    
   
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
  
    printf("Enter the key to search for: ");
    scanf("%d", &key);
    
    
    linearSearch(arr, n, key);
    
    return 0;
}
