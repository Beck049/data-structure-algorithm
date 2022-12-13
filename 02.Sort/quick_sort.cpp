#include "array_func.h"

// g++ quick_sort.cpp -o sort 

int partition(int*, int, int); 
void quickSort(int*, int, int); 

int main(void) { 
    int len = 8;
    int* origin_data;
    printf("Before sort: ");
    origin_data = rand_array(len);
    
    printf("Quick sort\nOrigin data:");
	print_array(origin_data, len);
	//print the origin data//

    int* data = init_array(origin_data, len);

    quickSort(data, 0, len-1);

    printf("\nAfter sort: ");
    print_array(data, len);

    return 0; 
} 

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