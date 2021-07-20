#include <stdio.h> 
#define LEN 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void sort(int*, int, int(*)(int, int));
void insertion(int*, int, int, int, int(*)(int, int));
void insert(int*, int, int, int, int(*)(int, int));
int ascending(int, int);
int descending(int, int);
void print(int*, int);

int main(void) 
{ 
    int number[LEN] = {89, 12, 65, 97, 61, 81, 27, 2, 61, 98}; 
    
    sort(number, LEN, ascending); 
    print(number, LEN);
    
    sort(number, LEN, descending); 
    print(number, LEN);

    return 0; 
} 

void sort(int* number, int len, int(*compar)(int, int)) 
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

void print(int* arr, int len) 
{
    for(int i = 0; i < len; i++) { printf("%d ", arr[i]); } 
    printf("\n");
}

int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return -ascending(a, b); }


