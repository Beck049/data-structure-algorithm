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

double* add    (double *, int, int, double *, int, int);
double* sub    (double *, int, int, double *, int, int);
double* multi  (double *, int, int, double *, int, int);
double* inverse(double *, int, int);
double   det   (double *, int, int);
double* trans  (double *, int, int);
void    print  (double *, int, int);

int main()
{
    //set the size of radix1 & radix2
    int n1, n2, m1, m2;
    printf("Input the size of radix1 (nxm) :\n");
	scanf("%d %d",&n1,&m1);
	printf("Input the size of radix2 (nxm) :\n");
	scanf("%d %d",&n2,&m2);

    //give the radixs a dynamic space
    double *mat1, *mat2;
	mat1 = (double*)malloc(n1*m1*sizeof(double));
	mat2 = (double*)malloc(n2*m2*sizeof(double));
	
    // radix[i][j] = radix[i*m+j]
	
    //set the element of the radixs
    printf("Matrix 1:\n");
	for(int i = 0; i < n1*m1; i++)
	{
			scanf("%lf",&mat1[i]);
	}
	printf("Matrix 2:\n");
	for(int i = 0; i < n2*m2; i++)
	{
			scanf("%lf",&mat2[i]);
	}
	printf("-------------------------------------------------------------\n");


    // int op;
	// scanf("%d",&op);
	
	printf("Press 1 to do   addition    , Press 2 to do substraction ,\n");
	printf("Press 3 to do multiplication, Press 4 to do determination,\n");
	printf("Press 5 to do  the inverse  , Press 6 to do the transfer ,\n");
	printf("Press 7 to print  matrix  1 , Press 8 to print  matrix 1 ,\n");

    add  (mat1, n1, m1, mat2, n2, m2);
    sub  (mat1, n1, m1, mat2, n2, m2);
    multi(mat1, n1, m1, mat2, n2, m2);
    det  (mat1, n1, m1);
    trans(mat1, n1, m1);
    inverse(mat1, n1, m1);

	return 0;
}

double* add	   (double *mat1, int n1, int m1, double *mat2, int n2, int m2)
{
    if(n1 != n2 || m1 != m2)
    {
        printf("You can't add these two matrix\n");
        return NULL;
    }

    double* a = (double*)malloc(sizeof(double)*n1*m1);

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < m1; j++)
        {
            a[ (m1*i) + j ] = mat1[ (m1*i) + j ] + mat2[ (m2*i) + j ];
        }
    }

    printf("the addition is:\n");
    print(a, n1, m1);

    return a;
}

double* sub	   (double *mat1, int n1, int m1, double *mat2, int n2, int m2)
{
    if(n1 != n2 || m1 != m2)
    {
        printf("You can't add these two matrix\n");
        return NULL;
    }

    double* s = (double*)malloc(sizeof(double)*n1*m1);

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < m1; j++)
        {
            s[ (m1*i) + j ] = mat1[ (m1*i) + j ] - mat2[ (m2*i) + j ];
        }
    }

    printf("the substraction is:\n");
    print(s, n1, m1);

    return s;
}

double* multi  (double *mat1, int n1, int m1, double *mat2, int n2, int m2)
{
    if( m1 != n2 )
    {
        printf("You can't multiply these two matrix\n");
        return NULL;
    }

    double* mul = (double*)calloc(sizeof(double),n1*m2);

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < m2; j++)
        {
            for(int k = 0; k < m1; k++)
            {
                mul[ (m2*i) + j ] += mat1[(i*m1)+k] * mat2[(k*m2)+j];
            }
        }
    }

    printf("the multiplication is:\n");
    print(mul, n1, m2);

    return mul;
}

double  det    (double *mat, int n, int m)
{
    if( n != m )
    {
        printf("the matrix has no determination\n");
        return -1;
    }

    double d = 0, add = 0, sub = 0;
    int a = 1, b = 1, t = 0;

    for(int j = 0; j < n; j++)
	{
		t = j;
		for(int i = 0; i < n; i++)
		{
			t %= n;
			a *= mat[i*n + t];
			t++;
		}
		add += a;
		a = 1;
	}

    for(int j = 0; j < n; j++)
	{
		t = j;
		for(int i = 0; i < n; i++)
		{
			t %= n;
			b *= mat[i*n + t];
			t += (n-1);
		}
		sub += b;
		b = 1;
	}

    d = add - sub;

    printf("the determination is %lf\n", d);

    return d;

}

double* trans  (double *mat, int n, int m)
{
    double* t = (double*)malloc(sizeof(double)*n*m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            t[ (n*j) + i ] = mat[ (m*i) + j ];
        }
    }

    printf("the transfer is :\n");
    print(t, m, n);

    return t;
}

void    print  (double *mat, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%lf\t", mat[ (m*i) + j ]);
        }
        printf("\n");
    }
    printf("\n");
}

double* inverse(double *mat, int n, int m)
{
    if( n != m || det(mat, n, m) == 0)
    {
        printf("the matrix has no determination\n");
        return NULL;
    }

    double* in = (double*)calloc(sizeof(double), n*m);
    // initial in[]
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if( i == j )
            {
                in[ (m*i) + j ] = 1;
            }
        }
    }
    
    // reduce row echelon form
    for(int i = 0; i < n; i++)
    {
        // make sure selected value is not 0
        if( mat[(i*m) + i] == 0 )
        {
            if( i == n-1 ){ break; }
            else
            {
                // find nonzero row
                int k = -1;
                for(int j = i+1; j < n; j++)
                {
                    if( mat[ (j*m) + j ] != 0 )
                    {
                        k = j;
                        break;
                    }
                }
                // if can't found
                if( k == -1 ){ k = i+1; }
                // add to current row
                for(int j = 0; j < m; j++)
                {
                    mat[ (i*m) + j ] += mat[ ((i+1)*m) + j ];
                    in [ (i*m) + j ] += in [ ((i+1)*m) + j ];
                }
            }
        }
        double temp = 0;
        // turn it into 1
        temp = mat[ (i*m) + i ];
        for(int j = 0; j < m; j++)
        {
            mat[ (i*m) + i ] /= temp;
            in [ (i*m) + i ] /= temp;
        }
        // clear the other value
        for(int j = 0; j < n; j++)
        {
            if( j == i ){ continue; }

            temp = (-1)* mat[ (j*m) + i ];
            for(int k = 0; k < m; k++)
            {
                mat[ (j*m) + k ] += temp * mat[ (i*m) + k ];
                in [ (j*m) + k ] += temp * in [ (i*m) + k ];
            }
        }
    }

    printf("the inverse is :\n");
    print(in, n, n);

    return in;
}
