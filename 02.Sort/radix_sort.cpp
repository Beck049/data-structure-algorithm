#include "array_func.h"

// g++ radix_sort.cpp -o sort

void radixSort(int*);

int main(void) 
{ 
    int data[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81}; 
      
    printf("\nBefore sort: "); 
    int len = 8;
	int* data = init_array(data, len);
	
	printf("Radix sort\nOrigin data:");
	print_array(data, len);
	//print the origin data//

    radixSort(data);
    
    printf("\nResult:");
	print_array(data, len);
    
    return 0; 
} 

void radixSort(int *data) 
{
    int temp[10][10] = {0}; 
    int order[10] = {0}; 
    
    int n = 1; 
    while(n <= 10) 
	{ 
        
        int i;
        for(i = 0; i < 10; i++) 
		{ 
            int lsd = ((data[i] / n) % 10); 
            temp[lsd][order[lsd]] = data[i]; 
            order[lsd]++; 
        } 
        
        // re-sort
        int k = 0;
        for(i = 0; i < 10; i++) 
		{ 
            if(order[i] != 0)  
			{
                int j;
                for(j = 0; j < order[i]; j++, k++) 
				{ 
                    data[k] = temp[i][j]; 
                } 
            }
            order[i] = 0; 
        } 

        n *= 10; 
    }     
}
