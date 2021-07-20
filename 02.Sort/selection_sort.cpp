#include <stdio.h>
#include <stdlib.h>

int data[8] = {16, 25, 39, 27, 12, 8, 45, 63};

void showdata (int *);
void select (int *);

int main()
{
	printf("Origin data: ");
	
	for(int i = 0; i < 8; i++)
	{
		printf("%3d ",data[i]);
	}
	printf("\n---------------------------------------------------");
	
	select(data);
	
	printf("Sorted data: ");
	for(int i = 0; i < 8; i++)
	{
		printf("%3d ",data[i]);
	}
	printf("\n");
	
	return 0;
	
}


void showdata (int *data)
{ 
	for(int i = 0; i < 8; i++)
	{
		printf("%3d ",data[i]);
	} 
	printf("\n");
}

void select (int *data)
{
	int temp;
	
	for(int i = 0; i < 7; i++)
	{
		for(int j = i+1; j < 8; j++)
		{
			if(data[i] > data[j])
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		} 
	}
	printf("\n");
}