#include <stdio.h> 
#include <math.h>            
#include <ctype.h>    
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>	
#include <time.h>

void print_option();

void print(int*, int);

void union_0  (int*, int);
    void union_a_b(int*, int, int, int);

int find_0 (int*, int);
    int find_a (int* ,int);

void compression(int*, int);

int main()
{
    int num = 0;
    printf("Enter tne number of nodes: ");
    scanf("%d", &num);

    int* arr = (int*)malloc(num*sizeof(int));
    for(int i = 0; i < num; i++)
    { arr[i] = -1; }

    int leave = 0;
    while(leave != 1)
    {
        int op = -1;
        print_option();
        scanf("%d", &op);

        switch(op)
        {
            case  1: // union
                union_0(arr, num);
                break;
            case  2: // find
                find_0(arr, num);
                break;
            case  3: // print array
                print(arr, num);
                break;
            case -1: // leave
                leave = 1;
                break;
            default: // error 
                printf("Error\n");
                break;
        }
    }

    compression(arr, num);

    print(arr, num);

    return 0;
}

void compression(int* arr, int num)
{
    printf("Path Compression : n");
    
    for(int i = 0; i < num; i++)
    {
        int root = find_a(arr, i);
        if(arr[i] >= 0)
        { arr[i] = root; }
    }
    
    return;
}

int find_0(int* arr, int num)
{
    int a;
    printf("Enter the node to find : ");
    scanf("%d", &a);

    printf("Root of %d is %d\n", a, find_a(arr, a) );

    return 0;
}

int find_a(int* arr, int a)
{
    int temp = 0, parent = 0;

    temp = a;
    parent = arr[temp];

    if(parent < 0) // if its a root
    { return temp; }

    while( parent >= 0 ) // else
    {
        temp = parent;
        parent = arr[temp];
    }

    return temp;
}

void union_0(int* arr, int num)
{
    int a, b;
    printf("Enter two node to union : ");
    scanf("%d %d", &a, &b);

    if( find_a(arr, a) != find_a(arr, b) ) // !same tree
    {
        union_a_b(arr, num, a, b);
    }
    else
    {
        printf("Same group(tree)\n");
    }

    print(arr, num);

    return;
}

void union_a_b(int* arr, int num, int a, int b)
{
    int root_a, root_b;
    root_a = find_a(arr, a);
    root_b = find_a(arr, b);

    if(arr[root_a] <= arr[root_b]) // a has more node
    {
        arr[root_a] += arr[root_b];
        arr[root_b] = root_a;
    }
    else if(arr[root_a] > arr[root_b]) // b has more node
    {
        arr[root_b] += arr[root_a];
        arr[root_a] = root_b;
    }

    return;
}

void print_option()
{
    printf("Choose what to do :\n");
    printf("(1) union(a, b)   ( 2) find root of a\n");
    printf("(3) print array   (-1) end the loop\n");
    return;
}

void print(int* arr, int num)
{
    printf("|");
    for(int i = 0; i < num; i++)
    { printf(" %3d |", i); }
    printf("\n|");
    for(int i = 0; i < num; i++)
    { printf(" %3d |", arr[i]); }
    printf("\n");

    return;
}
