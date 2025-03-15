/*Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))*/
  
  
  #include <stdio.h>


void swp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swp(&arr[i], &arr[j]);
        }
    }
    swp(&arr[i + 1], &arr[high]);
    return i + 1;
}


int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);


        if (pi == k - 1)
            return arr[pi];
        else if (pi > k - 1)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1; 
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int n, k;
        printf("Enter size of array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("Enter value of K: ");
        scanf("%d", &k);

        if (k > 0 && k <= n) {
            int result = quickSelect(arr, 0, n - 1, k);
            printf("%d\n", result); // Kth smallest element
        } else {
            printf("not present\n");
        }
    }

    return 0;
}
