#include "array_func.h"

// g++ insertion_sort.cpp -o sort

void insert(int *data, int len);

int main()
{
	int origin_data[] = {16,25,39,27,12,8,45,63}; //Origin data//
	int len = 8;
	int* data = init_array(origin_data, len);

	printf("Insertion sort\nOrigin data:");
	print_array(data, len);
	//print the origin data//

	insert(data, len);

	printf("\nResult:");
	print_array(data, len);
	
	return 0;
}

void insert(int *data, int len)
{
	int temp, j;
	
	for(int i = 0; i < len; i++)
	{
		temp = data[i];
		j = i-1;
		
		while(j >= 0 && temp < data[j])
		{
			data[j+1] = data[j];
			j--;
		}
		
		data[j+1] = temp;
		
		printf("%d: ",i+1);
		print_array(data, len);
	}
}