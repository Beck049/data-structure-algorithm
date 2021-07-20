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

#define MAXSTACK 20
// Limited Stack

int stack[MAXSTACK];//array

int top = -1;

int isEmpty();
int push(int);
int pop();

int main()
{
	int value;
	int i = 0;

	while(i != -1)
	{
		printf("Enter 1 to push, 0 to pop, -1 to stop : ");
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
	if(top == -1)
	{	return 1;	}
	else
	{	return 0;	}
}

int push(int data)
{
	if(top >= MAXSTACK)
	{
		printf("Stack is full.\n");
		return 0;
	}
	else
	{
		top++;
		stack[top] = data;
	//	stack[++top];
		return 1;
	}
}

int pop()
{
	if(isEmpty() == 1)
	{
		printf("Stack is empty.\n");
		return 0;
	}
	else
	{
		top--;
		return stack[top+1];
	//	return stack[top--];
	}
}
