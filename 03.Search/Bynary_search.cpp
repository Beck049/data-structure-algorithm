#include <iostream>
#include <cstdio>
#include <iomanip>   
#include <cmath>        
#include <cstring>     
#include <cctype>       
#include <stdlib.h>
#include <cassert>
#include <cstdarg>
#include <climits>
#include <stdio.h>
#include <string>
#include <stdint.h>

#define SIZE 10

int data[SIZE] = {5, 7, 13, 4, 9, 18, 24, 11, 6, 0};

typedef unsigned int Mytype;

int bin_search(int *, int);
void print(int *, int);
int compare(const void*, const void*);

int main()
{	
	int key = 0, num;

	qsort(data,SIZE,sizeof(int),compare);
	
	print(data,SIZE);
	
	while(1)
	{
		num = 0;
		
		printf("Enter the key: ");
		scanf("%d",&key);
		
		if(key == -1)
		{
			break;
		}
		
		num = bin_search(data, key);
		
		if(num == -1)
		{
			printf("can't find %3d\n",key);
		}
		else
		{
			printf("found %3d at %2d\n", data[num], num+1);
		}
		
		return 0;
	}
	
	return 0;
} 

int bin_search(int *data, int key)
{
	int low, mid, high;
	low = 0;
	high= SIZE-1;
	
	while(low <= high && key != -1)
	{
		mid = (low + high) / 2;
		
		if(key < data[mid])
		{
			high = mid-1;
		}
		else if(key > data[mid])
		{
			low = mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void print(int *data, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%3d ",data[i]);
	}
	printf("\n");
}

int compare(const void *a, const void *b)
{
	if( *(Mytype*)a < *(Mytype*)b) {return -1;}
	if( *(Mytype*)a == *(Mytype*)b){return  0;}
	if( *(Mytype*)a > *(Mytype*)b) {return  1;}
}
