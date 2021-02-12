/*
TI-202 F/R
Dmitrii Dronov
24.09.2020
Lucrarea Laborator N4
Basic 2D array stuff
Variant 10
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int **arr, int cols, int rows);
void fillArr(int **arr, int cols, int rows);
void fillArrKeyboard(int **arr, int cols, int rows);
void sort(int **arr, int cols, int rows);

int main(void)
{
    int columns = 0, rows = 0;

    int len;
    int **arr;
    int *ptr;

    printf(":::::::MENU:::::::\n1.Malloc memory for 2D Array\n2.Fill from keyboard\n3.Fill with rands\n4.Sort\n5.Print 2D array\n6.Free memory\n0.Quit\n");
    int choice = 0;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    do {
        switch (choice)
        {
        case (1):
            printf("Enter columns: ");
            scanf("%d", &columns);
            printf("Enter rows: ");
            scanf("%d", &rows);
            len = sizeof(int *) * rows + sizeof(int) * columns * rows;
            arr = (int **)malloc(len);
            ptr = (int *)(arr + rows);

            for(int i = 0; i < rows; i++) 
                arr[i] = (ptr + columns * i); 
            break;
        case (2):
            fillArrKeyboard(arr, columns, rows);
            break;
        case (3):
            fillArr(arr, columns, rows);
            break;
        case (4):
            sort(arr, columns, rows);
            break;
        case (5):
            printArr(arr, columns, rows);
            break;
        case (6):
            free(ptr);
            free(arr);
            printf("free() - SUCCESS\n");
            break;
        case (0):
            printf("Bye!\n");
            free(ptr);             
            free(arr);
            break;
        default:
            printf("Unknown choice...\n");
            break;
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while(choice != 0);
    //for loop to point rows pointer to appropriate location in 2D array 
    free(arr);
    return 0;
}

void printArr(int **arr, int cols, int rows)
{
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return;
}

void fillArr(int **arr, int cols, int rows)
{
    srand(time(0));

    int min = 0, max = 0;
    printf("Enter a range to fill the array: \n");
    scanf("%d", &min);
    scanf("%d", &max);

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j)
        {
            arr[i][j] = rand() % (min - max + 1) + min;
        }
    }
    return;
}

void sort(int **arr, int cols, int rows)
{
    printf("\nSorting\n");
    for (int j = 0; j < rows; ++j) {
        if (j % 2 != 0)
            continue;
        for (int i = 0; i < cols; ++i) {
            for (int k = 1 + i; k < cols; ++k) {
                if (arr[i][j] < arr[k][j]) {
                    int a = arr[i][j];
                    arr[i][j] = arr[k][j];
                    arr[k][j] = a;
                }
            }
        }
    }
    return;
}

void fillArrKeyboard(int **arr, int cols, int rows) {
    int num = 0;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j)
        {
            printf("Enter a number for arr[%d][%d]: ", i, j);
            scanf("%d", &num);
            arr[i][j] = num;
        }
    }
}