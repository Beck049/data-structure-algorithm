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

void print  (int* , int);
int  add    (int*, int, int);
int  search (int*, int, int);
int  delete (int*, int, int);
int  append (int*, int*, int, int);

int main()
{
    int len1 = 0, len2 = 0;
    int *arr1 = (int*)malloc(sizeof(int) *len1);
    int *arr2 = (int*)calloc(sizeof(int), len2);

    print(arr1, len1);
    print(arr2, len2);

    len1 = add(arr1, len1, 23);
    len2 = add(arr2, len2, 34);
    len2 = add(arr2, len2, 45);
    len2 = add(arr2, len2, 56);
    len2 = add(arr2, len2, 67);
    
    print(arr1, len1);
    print(arr2, len2);

    search(arr1, len1, 34);
    search(arr2, len2, 34);

    len2 = delete(arr2, len2, 45);
    print(arr2, len2);

    len1 = append(arr1, arr2, len1, len2);
    print(arr1, len1);

    return 0;
}

int  append (int* arr1, int* arr2, int len1, int len2)
{
    if( len2 == 0 )
    {
        return len1;
    }

    arr1 = realloc( arr1 , sizeof(int) * (len1 + len2));
    memcpy( arr1+len1, arr2, sizeof(int)*len2);

    return len1+len2;

}

int  delete (int* arr, int len, int num)
{
    int position = search(arr, len, num);

    if( position == -1 )
    {
        printf("Delete nothing...\n");
        return len;
    }
    else
    {
        memcpy ( arr+position, arr+position+1, sizeof(int)*(len - position) );
        arr = realloc( arr, sizeof(int)*(len-1) );
        return len-1;
    }
}

int search(int* arr, int len, int num)
{
    for(int i = 0; i < len; i++)
    {
        if( arr[i] == num )
        {
            printf("%d at %d\n", num, i);
            return i;
        }
    }

    printf("Can't find %d\n", num);
    return -1;
}

int add(int* arr, int len, int num)
{
    arr = (int*)realloc(arr,sizeof(int)*(len+1));
    arr[len] = num;

    return len+1;
}

void print(int* arr, int len)
{
    if(len == 0)
    {
        printf("The array is empty\n");
        return;
    }

    printf("|");
    for(int i = 0; i < len; i++)
    {
        printf(" %3d |", arr[i]);
    }
    printf("\n");
}
