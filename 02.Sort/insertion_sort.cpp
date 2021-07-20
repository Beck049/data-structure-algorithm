#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void inputarr (int *, int);
void showdata (int *);
void insert   (int *);

int main()
{
	int data[SIZE];
	inputarr(data,SIZE);
	insert(data);
	
	return 0;
}

//input array
void inputarr (int *data, int size)
{
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d: ",i+1);
		scanf("%d",&data[i]);
	}
}

//print the data
void showdata (int *data)
{
	for(int i = 0; i < SIZE; i++)
	{
		printf("%3d ",data[i]);
	}
	printf("\n");
}

void insert(int *data)
{
	int temp, j;
	
	for(int i = 1; i < SIZE; i++)
	{
		temp = data[i];
		j = i-1;
		
		while(j >= 0 && temp < data[j])
		{
			data[j+1] = data[j];
			j--;
		}
		
		data[j+1] = temp;
		
		printf("%d: ",i);
		showdata(data);
	}
}