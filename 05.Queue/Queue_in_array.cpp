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
#include <time.h>

#define MAXQUEUE 20
// Limited Queue

int front = -1, rear = -1;

int isEmpty()
{
	if(rear == -1)
	{	return 1;	}
	else
	{	return 0;	}
}

int main()
{
	int value, queue[MAXQUEUE] = {0};
	int key = 2;
	
	front = rear = -1;	// not exist
	 
	while(rear < MAXQUEUE-1 && key != -1)
	{
		printf("Enter 1 to push, 2 to peek, 0 to pop, -1 to end : ");
		scanf("%d",&key);
		if(key == -1)//end
			break;
		else if(key == 1)//push
		{
			printf("Enter the value to push : \n");
			scanf("%d",&value);
			rear++;				// rear go back 
				
			if(rear == MAXQUEUE)		//max amount of queue 
			{
				printf("The queue is full\n");
			}
			else				// push value
			{
				queue[rear] = value; 
			//	printf("////%d////",rear);
			}
			
		}
		else if(key == 0)//pop
		{
			if(isEmpty() == 1)
			{
				printf("Stack is empty.\n");
			}
			else
			{
				printf("Pop out %d\n",queue[0]);		// output value 
				
				for(int i = 1; i < rear+1; i++)
				{
					queue[i-1] = queue[i];
					queue[i] = 0;			// Queue value 
				}							// delete value
				
				rear--;	// rear 
			}
		}
		else if(key == 2)//peek
		{
			if(isEmpty() == 1)
			{
				printf("Queue is empty.\n");
			}
			else
			{
				printf("Peek the value : %d\n",queue[0]);
			}
		}
		else
		{
			printf("Invalid key\n");
		}
	}
	
	printf("All element: ");
	
	if(rear == -1)
	{
		printf("The queue is empty.\n");
	}
	else
	{
	//	printf("%d\n",rear);
		for(int i = 0; i < rear+1; i++)
		{
			printf("[%d]%d ",i,queue[i]);
		}
	}
	
	return 0;
}
