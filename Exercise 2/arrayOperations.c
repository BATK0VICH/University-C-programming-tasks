#include "arrayOperations.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void fill_array(int *arr, ArrayInfo inf) 
{
    srand(time(0)); 

    printf("Array: \n");
    //filling and printing array with random numbers in provided range.
    for (int i = 0; i < inf.size; ++i) 
    {
        arr[i] = rand() % (inf.min - inf.max + 1) + inf.min; 
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

void swap(int* num1, int* num2) 
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition (int* arr, int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int* arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void printArray(int* arr, int size) 
{
    printf("Sorted array: \n");
    for (int i = 0; i < size; ++i)
        printf("%d\t", arr[i]);
    printf("\n");
}

int findFirstPositive(int* arr, int size) 
{
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            return i;
    }
    return -1;
}

int quantityOfNegative(int* arr, int size) 
{
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0)
            return i;
    }
    return 0;
}