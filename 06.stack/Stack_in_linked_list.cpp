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

// Unlimited Stack
int count = 0;

struct Node
{
	int data;
	int count;
	struct Node *next;
};

typedef struct Node node;
typedef node *link;

link top = NULL;

int isEmpty();
int pop();
int peek();
void push(int data);

int main()
{
	int value;
	int i = 0;
	
	while(i != -1)
	{
		printf("Enter 1 to push, 2 to peek, 0 to pop, -1 to stop : ");
		scanf("%d",&i);
		
		if(i == -1) // -1 to stop
		{
			break;
		}
		else if(i == 1) // 1 to push
		{
			printf("Enter the value to push : ");
			scanf("%d",&value);
			push(value);
		}
		else if(i == 2) // 2 to peek
		{
			printf("Peek the value : %d\n",peek());
		}
		else if(i == 0) // 0 to pop
		{
			printf("pop out %d\n",pop());
		}
		else
		{
			printf("Error value\n");
		}
	}
	
	// print
	printf("The stack:");

	while(!isEmpty())
	{
		printf("%d, ",pop());
	}
	
	return 0;
} 

int isEmpty()
{
	if(top == NULL)
	{	return 1;	}//isEmpty
	else
	{	return 0;	}//notEmpty
}

void push(int data)
{
	count++;
	link newnode;
	newnode = (link)malloc(sizeof(node));
	
	newnode->count = count;
	newnode->data  = data ;
	newnode->next  = NULL ;
	
	top = newnode;
}

int pop()
{
	link ptr;
	int temp;
	
	if(isEmpty() == 1)
	{
		printf("Stack is empty.\n");
		return 0;
	}
	else
	{
		ptr = top;			//
		top = top->next;	// top = NULL
		temp = ptr->data;	// take out the data of top
		
		free(ptr); // free
		
		return temp;//return data that pop out 
	}
}

int peek()
{
	int temp;
	
	if(isEmpty() == 1)
	{
		printf("Stack is empty.\n");
		return 0;
	}
	else
	{
		temp = top->data;
		
		return temp;
	}
}
