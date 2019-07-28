// C program for insertion sort 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>

/* Function to sort an array using insertion sort*/

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

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

/* Driver program to test insertion sort */
int main() 
{ 
    
    int i, n = 1000000;
    int a[n];
    for(i=0; i<n; ++i)
     {
          a[i] = i;
     }
    swap(a,4,n-1);
    swap(a,5,n-2);
    swap(a,6,n-3);
    swap(a,7,n-4);
    swap(a,10,n-20);
    swap(a,15,n-40);
    swap(a,18,n-100);
    swap(a,40,n-150);
    swap(a,100,n-200);
    swap(a,300,n-230);
    swap(a,700,n-1000);
    swap(a,1500,n-2000);
    swap(a,2000,n-3000);
    swap(a,4000,n-4000);
    swap(a,7000,n-1000);
    swap(a,10000,n-20000);
    swap(a,20000,n-30000);
    swap(a,40000,n-40000);

    swap(a,90000,n-90000);
    swap(a,120000,n-100000);
    swap(a,150000,n-150000);
    swap(a,300000,n-300000);
    swap(a,350000,n-350000);
    swap(a,380000,n-380000);
    swap(a,400000,n-400000);
    swap(a,405000,n-405000);
    swap(a,405900,n-405900);
    swap(a,459999,n-459999);
    swap(a,470000,n-470000);
    swap(a,500000,n-500000);
    swap(a,550050,n-550000);
    swap(a,600020,n-600000);
    swap(a,700000,n-700000);
    /*
    swap(a,0,n-1);
    swap(a,1,n-2);
    swap(a,2,n-3);
    swap(a,3,n-4);
    swap(a,4,n-5);
    swap(a,5,n-6);
    swap(a,6,n-7);
    */
    
    //int a[] = {8,9,10,11,12,3,4,5,18,19,20,16,17,13,14,15,16};
    //int n = sizeof(a) / sizeof(a[0]); 

    printArray(a, n);
    insertionSort(a, n); 
    printArray(a, n); 

    return 0; 
} 
