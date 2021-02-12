#ifndef ARR_H_
#define ARR_H_


//Information about array
typedef struct {
    int size;
    int min;
    int max;
} ArrayInfo;

//filling and printing array with random numbers in provided range.
void fill_array(int *arr, ArrayInfo inf);

void swap(int* num1, int* num2);

int partition (int* arr, int low, int high);

void quickSort(int* arr, int low, int high);

//prints the Array
void printArray(int* arr, int size);

//returns index of first positive number in the array. Array must be sorted!
int findFirstPositive(int* arr, int size);

//returns number of negative numbers in the array. Array must be sorted!
int quantityOfNegative(int* arr, int size);

#endif