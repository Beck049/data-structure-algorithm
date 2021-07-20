#include <iostream>
#include <cstdio>
#include <iomanip>   
#include <cmath>        
#include <cstring>     
#include <cctype>       
#include <stdlib.h>
#include <cassert>//								radix[4][3]
#include <cstdarg>	//								n=4			[0][0]  [0][1]  [0][2]
#include <climits>	//								m=3			[1][0]  [1][1]  [1][2]
#include <stdio.h>	//											[2][0]  [2][1]  [2][2]
#include <string>	//											[3][0]  [3][1]  [3][2]
#include <stdint.h>
void add	(int *, int, int, int *, int, int);
void sub	(int *, int, int, int *, int, int);
void multi  (int *, int, int, int *, int, int);
void inverse(int *, int, int);
int  det	(int *, int, int);//  // 
void trans	(int *, int, int);
void print	(int *, int, int);

int main()
{
	int n1, n2, m1, m2;
	printf("Input the size of radix1:\n");
	scanf("%d %d",&n1,&m1);
	printf("Input the size of radix2:\n");
	scanf("%d %d",&n2,&m2);//set the size of radix1 & radix2
	
	int *mat1, *mat2;
	mat1 = (int*)malloc(n1*m1*sizeof(int));
	mat2 = (int*)malloc(n2*m2*sizeof(int));//give the radixs a dynamic space
										   // radix[i][j] = radix[i*m+j]
	printf("Matrix 1:\n");
	for(int i = 0; i < n1*m1; i++)
	{
			scanf("%d",&mat1[i]);
	}
	printf("Matrix 2:\n");
	for(int i = 0; i < n2*m2; i++)
	{
			scanf("%d",&mat2[i]);
	}										//set the element of the radixs
	printf("-------------------------------------------------------------\n");
/////HERE/////HERE/////HERE/////HERE/////HERE/////HERE/////HERE/////HERE/////HERE

	int select;
	scanf("%d",&select);
	
	printf("Press 1 to do   addition    , Press 2 to do substraction ,\n");
	printf("Press 3 to do multiplication, Press 4 to do determination,\n");
	printf("Press 5 to do  the inverse  , Press 6 to do the transfer ,\n");
	printf("Press 7 to print  matrix  1 , Press 8 to print  matrix 1 ,\n");
	
	if(select == 1)
	{
		add(mat1,n1,m1,mat2,n2,m2);
	}
	else if(select == 2)
	{
		sub(mat1,n1,m1,mat2,n2,m2);
	}
	else if(select == 3)
	{
		multi(mat1,n1,m1,mat2,n2,m2);
	}
	else if(select == 4)
	{
		if( n1 != m1 )
		{	printf ("matrix 1 has no determination\n");	}
		else
		{   printf("The determination of matrix 1 is %d\n",det(mat1,n1,m1));	}
		
		if( n2 != m2 )
		{	printf ("matrix 2 has no determination\n");	}
		else
		{	printf("The determination of matrix 2 is %d\n",det(mat2,n2,m2));	}
	}
	else if(select == 5)
	{////////
		inverse(mat1,n1,m1);
		inverse(mat2,n2,m2);
	}
	else if(select == 6)
	{
		printf("The tansfer of matrix 1 is\n");
		trans(mat1,n1,m1);
		printf("The tansfer of matrix 1 is\n");
		trans(mat2,n2,m2);
	}
	else if(select == 7)
	{
		printf("The matrix 1 is\n");
		print(mat1,n1,m1);
	}
	else if(select == 8)
	{
		printf("The matrix 2 is\n");
		print(mat2,n2,m2);
	}
	else
	{
		printf("Undefined key");
	}

	inverse(mat1,n1,m1);

	return 0;
}

void add	(int *mat1, int n1, int m1, int *mat2, int n2, int m2)
{
	if(n1 == n2 && m1 == m2)
	{
		int *matrix;
		int temp;
		
		matrix = (int*)malloc(n1*m1*sizeof(int));
		
		for(int i = 0; i < n1*m1; i++)
		{
			temp = mat1[i] + mat2[i] ;
			printf("\n%d %d = %d",mat1[i],mat2[i],temp);
			matrix[i] = temp;
			printf("\n%d",matrix[i]);
		}
		
		printf("\nAddition:\n");
		print(matrix,n1,m1);
		
		free(matrix);
	}
	else
	{
		printf("ERROR\n");
	}
}

void sub	(int *mat1, int n1, int m1, int *mat2, int n2, int m2)
{
	if(n1 == n2 && m1 == m2)
	{
		int *matrix;
		int temp;
		
		matrix = (int*)malloc(n1*m1*sizeof(int));
		
		for(int i = 0; i < n1*m1; i++)
		{
			temp = mat1[i] + mat2[i] ;
			printf("\n%d %d = %d",mat1[i],mat2[i],temp);
			matrix[i] = temp;
			printf("\n%d",matrix[i]);
		}
		
		printf("\nSubstraction:\n");
		print(matrix,n1,m1);
		
		free(matrix);
	}
	else
	{
		printf("ERROR\n");
	}
}

void multi	(int *mat1, int n1, int m1, int *mat2, int n2, int m2)
{
	if(n1 == m2 && m1 == n2)
	{
		int *matrix;
		int n, m, p;
		
		n = n1;		//radix column//
		m = m2;		//radix row   //
		p = m1;//=n2//count
		
		matrix = (int*)malloc(n*m*sizeof(int));
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				int temp = 0;
				
				for(int k = 0; k < p; k++)
				{
					temp = temp + mat1[i*p+k]*mat2[k*m+j];
				}
				
				matrix[i*m+j] = temp;
			}
		}
		
		printf("\nMultiplication:\n");
		print(matrix,n,m);
		
		free(matrix);
	}
	else
	{
		printf("ERROR\n");
	}
}
int det 	(int *matrix, int n, int m)
{
	int det = 0;
	int ad = 0, mi = 0;
	int a = 1, b = 1, t = 0;
	
	for(int j = 0; j < n; j++)
	{
		t = j;
		for(int i = 0; i < n; i++)
		{
			t %= n;
			a *= matrix[i*n + t];
		//  printf("[%d, %d] = %d\n", i, t, matrix[i*n + t]);
			t++;
		}
		ad += a;
		a = 1;
	}
//  printf("add = %d\n", ad);

	for(int j = 0; j < n; j++)
	{
		t = j;
		for(int i = 0; i < n; i++)
		{
			t %= n;
			b *= matrix[i*n + t];
		//  printf("[%d, %d] = %d\n", i, t, matrix[i*n + t]);
			t += (n-1);
		}
		mi += b;
		b = 1;
	}
//  printf("min = %d\n", mi);

	det = ad - mi;

//  printf("%d - %d = %d\n", ad, mi, det);
	
	return det;
}
// radix[3][3]
//
// n=3			[0][0]  [0][1]  [0][2]
// m=3			[1][0]  [1][1]  [1][2]
//  			[2][0]  [2][1]  [2][2]
// 
// radix[i][j] = radix[i*m+j]
//EDITING//EDITING//EDITING//EDITING//EDITING//EDITING//EDITING
void inverse(int *matrix, int n, int m)
{
	if(det(matrix,n,m) != 0)
	{
		printf("GUESS JORDEN !");
	}
	else
	{
		printf("Inverse matrix not exist");
	}
}

void trans	(int *matrix, int n, int m)
{
	print(matrix,m,n);
}

void print	(int *matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%d ",matrix[(i*m)+j]);
		}
		printf("\n");
	}
}

