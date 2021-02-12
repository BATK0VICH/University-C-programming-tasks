/*
TI-202 F/R
Dmitrii Dronov
24.09.2020
Lucrarea Laborator N2
Find first positive number in the array and 
find the number of negative numbers
Variant 10
*/
#include <stdio.h>
#include <stdlib.h>
#include "arrayOperations.h"

int main() 
{
    ArrayInfo inf;
    printf("Enter size of the array: ");
    scanf("%d", &inf.size);

    int *arr = (int *)malloc(sizeof(int) * inf.size);
    printf("Enter a range for the array: ");
    scanf("%d", &inf.min);
    scanf("%d", &inf.max);

    printf("Filling array with random numbers...\n");
    fill_array(arr, inf);
    quickSort(arr, 0, inf.size);
    printArray(arr, inf.size);

    int index = findFirstPositive(arr, inf.size);
    if (index != -1)
        printf("First positive number is %d at index %d\n", arr[index], index);
    else
        printf("All numbers are negative\n");

    int numOfNegative = quantityOfNegative(arr, inf.size);

    if (numOfNegative != 0)
        printf("Number of negative numbers: %d\n", numOfNegative);

    free(arr);
    return 0;
}
