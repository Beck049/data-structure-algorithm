#include <stdio.h>
#include <stdlib.h>

int data[8]={16,25,39,27,12,8,45,63}; //Origin data// 

int main()
{
	int temp;
	
	printf("Bubble sort\nOrigin data:");
	
	for(int i = 0; i <8; i++)
	{
		printf("%3d ",data[i]);
	}
	printf("\n\n");
	//print the origin data//
	
	for(int i = 7; i >= 0; i--)//scan times//
	{
		for(int j = 0; j < i; j++)//compare times//
		{
			if(data[j] > data[j+1])//if the front is bigger then switch//
			{
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
		printf("%d :",8-i);
		for(int j = 0; j < 8; j++)
		{
			printf("%3d ",data[j]);
		}
		
		printf("\n");
	} 
	
	printf("\nResult:");
	for(int i = 0; i < 8; i++)
	{
		printf("%3d ",data[i]);
	}
	printf("\n");
	
	return 0;
} 
