#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <string.h>


void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}


void quick_sort(char** arr, size_t length)
{
    if (length <= 1)
    {
        return; 
    }

    size_t pivot_index = 0; 
    char* pivot_value = arr[length - 1]; 

    for (size_t i = 0; i < length - 1; i++) 
    {
        if (strcmp(arr[i], pivot_value) < 0)
        {
            swap(&arr[i], &arr[pivot_index++]);
        }
    }

    swap(&arr[pivot_index], &arr[length - 1]);

    
    quick_sort(arr, pivot_index);           
    quick_sort(arr + pivot_index + 1, length - pivot_index - 1); 
}

#endif // !SORT
