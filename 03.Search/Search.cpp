#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int array[8] = {2, 25, 42, 51, 61, 71, 73, 93};
#define SIZE 8

int sequential(int*, int);
int binary(int*, int);
int interpolation(int*, int);

int main()
{
    int num;

    printf("Enter the number to find :");
    scanf("%d", &num);

    // sequential search
    sequential(array, num);
    // binary search
    binary(array, num);
    // interpolation search
    // interpolation(array, num);

    return 0;
}

int sequential(int* array, int num)
{
    printf("sequential search :\n");
    for(int i = 0; i < SIZE; i++)
    {
        if( array[i] == num )
        {
            printf("Found %d in the array %d position\n", num, i);
            return i;
        }
    }

    printf("Can't find the number %d\n", num);
    return 0;
}
int binary(int* array, int num) // {2, 25, 42, 51, 61, 71, 73, 93}
{
    printf("binary search :\n");
    int high = SIZE;
    int mid;
    int low = 0;
    
    while(low <= high && num != -1)
    {
        mid = (low + high) /2;

        if(num < array[mid])
        {
            high = mid -1;
        }
        else if(num > array[mid])
        {
            low = mid +1;
        }
        else
        {
            printf("Found %d in the array %d position\n", num, mid);
            return mid;
        }
    }

    printf("Can't find the number %d\n", num);
    return -1;
}
int interpolation(int* array, int num) //  {2, 25, 42, 51, 61, 71, 73, 93}
{
    printf("interpolation search :\n");
    // Mid = low + ( (key - data[low]) / (data[high] - data[low]) )* (high - low)
    int low = 0, high = SIZE, mid = 0;
    
    while( low < high && num != -1 )
    {
        mid = low + ( (num - array[low]) * (high - low) / (array[high] - array[low]) ); // 內差法

        printf("mid = %d\t", mid);
        if( num == array[mid] )
        {
            printf("Found %d in the array %d position\n", num, mid);
            return mid;
        }
        else if( num < array[mid] )
        {
            high = mid -1;
        }
        else if( num > array[mid] )
        {
            low = mid +1;
        }
        printf("mid = %d\n", mid);
    }
    
    printf("Can't find the number %d\n", num);
    return -1;
}