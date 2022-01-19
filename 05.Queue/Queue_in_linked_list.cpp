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

int push(char* ,int);

int pop();

int peek(); 

void print();

struct list
{
	char name[10];
	int score;
	
	struct list *next;
};

typedef struct list node;
typedef node *link;

link front = NULL;
link rear  = NULL;

int main()
{
	int score, key = 0;
	char name[10];
	
	while(key != -1)
	{
		printf("Enter 1 to push, 2 to peek, 3 to pop, -1 to end : ");
		scanf("%d",&key);
		
		if(key == -1)
			break;
		else if(key == 1)//push
		{
			printf("Enter the name : ");
			scanf("%s",name);
			
			printf("Enter the score: ");
			scanf("%d",&score);
			
			push(name, score);
		}
		else if(key == 2)//peek
		{
			peek();
		}
		else if(key == 3)//pop
		{
			pop();
		}
		else
		{
			printf("Invalid key\n");
		}
	}
	
	print();
	
	return 0;
}
////////////////////////////////////////////////////
int push(char *name, int score)
{
	link newnode;
	
	newnode = (link)malloc(sizeof(node));
	
	strcpy(newnode->name, name);
	newnode->score = score;			// set values
	
	if(front == NULL)	// if empty 
	{
		front = newnode ;
		/////////////////
		rear  = newnode ;
	}
	else
	{
		rear->next = newnode;
	}
	
	rear = newnode;
	rear->next = NULL;

	return 0;	
}

int pop()
{
	//link temp;
	
	if(front == NULL)	//if empty
	{
		printf("The queue is empty.\n");
	}
	else
	{
		printf("Pop out name : %s\tscore : %d\n",front->name,front->score);
		
		temp = front;
		front = front->next;
		
		free(temp);
	}
	return 0;
}

int peek()
{
	//link temp;
	
	if(front == NULL)	//if empty
	{
		printf("The queue is empty.\n");
	}
	else
	{
		printf("Peek name : %s\tscore : %d\n",front->name,front->score);
	}
	return 0;
}

void print()
{
	link ptr;
	ptr = front;

	if(ptr == NULL)
	{
		printf("The queue is empty.\n");
	}
	else
	{
		printf("All element: \n");
		
		while(ptr != NULL)
		{
			printf("name : %s\tscore : %d\n",ptr->name,ptr->score);
			ptr = ptr->next;
		}
	}
	free(ptr);
	return;
}
