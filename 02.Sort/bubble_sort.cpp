#include "array_func.h"

// g++ bubble_sort.cpp -o sort

int* arr_bubble(int* data, int len);

int main()
{
	int origin_data[] = {16,25,39,27,12,8,45,63}; //Origin data//
	int len = 8;
	int* data = init_array(origin_data, len);
	
	printf("Bubble sort\nOrigin data:");
	print_array(data, len);
	//print the origin data//
	
	data = arr_bubble(data, len);
	
	printf("\nResult:");
	print_array(data, len);
	
	return 0;
} 

int* arr_bubble(int* data, int len){
	int temp;
	for(int i = len-1; i >= 0; i--)//scan times//
	{
		int exec = 0;
		for(int j = 0; j < i; j++)//compare times//
		{
			if(data[j] > data[j+1])//if the front is bigger then switch//
			{
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
				exec++;
			}
		}
		printf("%d: ", len-i);
		print_array(data, len);
		
		if(exec == 0){
			break;
		}
	} 
	return data;
}