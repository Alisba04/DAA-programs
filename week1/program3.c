/*Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],. ,arr[2k] and so on. Once the interval (arr[2k] <
key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): Jump Search*/



#include <stdio.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int jumpSearch(int arr[], int size, int key, int *comparisons) {
    int step = 1;
    while (step * step < size) {
        step++;
    }
    
    int prev = 0;
    *comparisons = 0;
    
  
    while (arr[min(step, size) - 1] < key) {
        (*comparisons)++;
        prev = step;
        step += step;
        if (prev >= size) {
            return -1; 
        }
    }
    
  
    while (arr[prev] < key) {
        (*comparisons)++;
        prev++;
        if (prev == min(step, size)) {
            return -1;  
        }
    }
    
   
    if (arr[prev] == key) {
        (*comparisons)++;
        return prev;  
    
    return -1; 

int main() {
    int T, n, key, comparisons;
    
   
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        
        int arr[n];
        
        
        printf("Enter the elements of the sorted array:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
      
        printf("Enter the key to search for: ");
        scanf("%d", &key);
        
        
        int result = jumpSearch(arr, n, key, &comparisons);
        
        if (result != -1) {
            printf("Present %d\n", comparisons);
        } else {
            printf("Not Present %d\n", comparisons);
        }
    }
    
    return 0;
}
