#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

int* cpy_array(int* origin_data, int* data, int len){
	for(int i = 0; i < len; i++){
		data[i] = origin_data[i];
	}
	return data;
}

int* rand_array(int len){
    srand(time(NULL));
    int* data = (int*)malloc(sizeof(int)*len);
    for(int i = 0; i < len; i++){
        data[i] = rand() % 100;
    }
    return data;
}

int* init_array(int* origin, int len){
    int* data = (int*)malloc(sizeof(int) * len);
    data = cpy_array(origin, data, len);
    return data;
}

void print_array(int* arr, int len){
	for(int i = 0; i < len; i++){
		printf("%3d ",arr[i]);
	}
	printf("\n");
}