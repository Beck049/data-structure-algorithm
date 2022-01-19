#include <math.h>        
#include <string.h>     
#include <ctype.h>       
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>	
#include <stdio.h>	
#include <string.h>	
#include <stdint.h>

void print(int*);
int  isEmpty(); // return size, if -1 : empty
void push(int* ,int);
void pop (int*);
int  peek(int*);

int size = 0;

int main()
{
    int* stack = (int*)malloc(sizeof(int)*size);

    pop(stack);

    push(stack, 12);
    print(stack);
    push(stack, 23);
    print(stack);
    push(stack, 34);
    print(stack);
    printf("%d\n", peek(stack));
    pop(stack);
    print(stack);
    printf("%d\n", peek(stack));

    return 0;
}

void print(int* stack)
{
    for(int i = 0; i < size; i++)
    {
        printf(" %3d |", stack[i]);
    }
    printf("\n");
    return;
}

int peek(int* stack)
{
    return stack[size-1];
}

void pop(int* stack)
{
    if(isEmpty() == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    stack = realloc(stack, size-1);
    
    size--;
    return;
}

void push(int* stack, int num)
{
    stack = realloc(stack, size+1);
    stack[size] = num;

    size++;
    return;
}

int isEmpty()
{
    if( size == 0 )
    {
        return -1;
    }
    else
    {
        return size;
    }
}