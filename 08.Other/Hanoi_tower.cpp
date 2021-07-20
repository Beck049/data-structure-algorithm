# include <stdlib.h>
# include <stdio.h>

// Recursive
 
int times=0;
 
void Hanoi(int N,char A,char B,char C){    // recursive program
// from A to C
 
    if(N==1){    // the last condition
        printf("Disk %d : %c -> %c\n", N, A, C);    // the bottomest disk on A moves to C
        times++;
    }
 
    else{
        Hanoi(N-1, A, C, B);    // continue moving
        // from A to B
 
        printf("Disk %d : %c -> %c\n", N, A, C);
        times++;
 
        Hanoi(N-1, B, A, C);    // second moving
        // from B to C
    }
}
 
int main(){
 
    int N;
 
    printf("How many disks?\n");
    scanf("%d", &N);
 
    while(N>10){    // N is less 10
        system("CLS");
        printf("N should less than 10\n");
        printf("Please input again\n\n");
        scanf("%d", &N);    // input again
    }
    printf("\n");

    Hanoi(N, 'A', 'B', 'C');    // call sub-program
 
    printf("\nUse %3d steps\n\n", times);
 
    system("PAUSE");
    return 0;
}
