#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 8 
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

int partition(int*, int, int); 
void quickSort(int*, int, int); 

int main(void) 
{ 
    srand(time(NULL)); 
    
    int number[MAX] = {0}; 

    printf("Before sort: "); 
    int i;
    for(i = 0; i < MAX; i++) 
	{ 
        number[i] = rand() % 100; 
        printf("%d ", number[i]); 
    } 

    quickSort(number, 0, MAX-1); 

    printf("\nAfter sort: "); 
    for(i = 0; i < MAX; i++) 
    {
        printf("%d ", number[i]); 
	}
    printf("\n"); 

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

        // printf("\nPrint sort: "); 
        // for(int k = 0; k < MAX; k++) 
        // {
        //     printf("%d ", number[k]); 
        // }
        // printf("\n"); 

    } 


    SWAP(number[i+1], number[right]); 
    // printf("\nswap sort: "); 
    //     for(int k = 0; k < MAX; k++) 
    //     {
    //         printf("%d ", number[k]); 
    //     }
    //     printf("\n"); 
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
