#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>

void swap(int A[], int i, int j) { 
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int antesQue(int r1, int r2) { 
    return r1 < r2;
}

void insertionSort(int A[], int n) {
    int i, j;
    for (i = 1; i < n; i++){
        for (j = i; (j > 0) && (antesQue(A[j], A[j-1])); j--)
        {
            swap(A, j, j-1);
        }
    }   
}
 
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() 
{ 
    
    int i, n = 10;
    int a[n];
    for(i=0; i<n; ++i)
     {
          a[i] = i;
     }
    swap(a,4,n-1);
    swap(a,5,n-2);
    swap(a,6,n-3);

    printArray(a, n);
    insertionSort(a, n); 
    printArray(a, n); 

    return 0; 
} 
