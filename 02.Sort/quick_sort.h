#include "array_func.h"

int partition(int *number, int left, int right) 
{ 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) 
	{ 
        if(number[j] <= number[right]) 
		{ 
            i++; 
            SWAP(number[i], number[j]); 
        } 
    }

    SWAP(number[i+1], number[right]);
    return i+1; 
} 

void quickSort(int *number, int left, int right) 
{ 
    if(left < right) 
	{ 
        int q = partition(number, left, right); 
        quickSort(number, left, q-1); 
        quickSort(number, q+1, right); 
    } 
}