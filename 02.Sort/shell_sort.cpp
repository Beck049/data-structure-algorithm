#include "array_func.h"

// g++ shell_sort.cpp -o sort
#define LEN 10

void shell_sort(int*, int, int(*)(int, int));
void insertion(int*, int, int, int, int(*)(int, int));
void insert(int*, int, int, int, int(*)(int, int));
int ascending(int, int);
int descending(int, int);

int main(void) 
{ 
    int origin_data[LEN] = {89, 12, 65, 97, 61, 81, 27, 2, 61, 98}; 
    int len = 10;
	int* data = init_array(origin_data, len);

    printf("Ascending: \n");
    shell_sort(origin_data, LEN, ascending); 
    print_array(data, len);
    
    printf("Descending: \n");
    shell_sort(origin_data, LEN, descending); 
    print_array(data, len);

    return 0; 
} 

void shell_sort(int* number, int len, int(*compar)(int, int)) 
{
    int gap;
    for(gap = len / 2; gap > 0; gap /= 2) 
	{
        int begin;
        for(begin = 0; begin < gap; begin++) 
		{ 
            insertion(number, len, begin, gap, compar);
        }
    }
}

void insertion(int* number, int len, int begin, int gap, int(*compar)(int, int)) 
{
    for(int i = begin + gap; i < len; i += gap) 
	{ 
        insert(number, begin, gap, i, compar); 
    } 
}

void insert(int* number, int begin, int gap, int i, int(*compar)(int, int)) 
{
    for(int j = i - gap; j >= begin && compar(number[j], number[j + gap]) > 0 ; j -= gap) 
	{ 
        SWAP(number[j], number[j + gap]); 
    }
}

int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return -ascending(a, b); }


