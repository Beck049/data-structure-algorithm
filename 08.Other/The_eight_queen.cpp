#include <stdio.h>

// Recursive

int Queenes[8] = {0};
//  Queen[row] = col;
int Counts=0;

void eight_queen(int);
void print();
int Check(int, int);

int main() {
    eight_queen(0);

    printf("There are %d ways",Counts);
    return 0;
}

int Check(int line,int list)
{
    // Go through all row before
    for (int index=0; index<line; index++) 
    {
        //挨個取出前面行中皇后所在位置的列座標
        int data=Queenes[index];
        //如果在同一列，該位置不能放
        if (list==data) 
        {
            return 0;
        }
        //如果當前位置的斜上方有皇后，在一條斜線上，也不行
        if ((index+data)==(line+list)) 
        {
            return 0;
        }
        //如果當前位置的斜下方有皇后，在一條斜線上，也不行
        if ((index-data)==(line-list)) 
        {
            return 0;
        }
    }
    // avaliable
    return 1;
}

void print()
{
    for (int line = 0; line < 8; line++)
    {
        int list;
        for (list = 0; list < Queenes[line]; list++)
            printf("<->");
        printf("<q>");
        for (list = Queenes[line] + 1; list < 8; list++){
            printf("<->");
        }
        printf("\n");
    }
    printf("============================\n");
}

void eight_queen(int line)
{
    //在陣列中為0-7列
    for (int list=0; list<8; list++) {
        //對於固定的行列，檢查是否和之前的皇后位置衝突
        if (Check(line, list)) {
            //不衝突，以行為下標的陣列位置記錄列數
            Queenes[line]=list;
            //如果最後一樣也不衝突，證明為一個正確的擺法
            if (line==7) {
                //統計擺法的Counts加1
                Counts++;
                //輸出這個擺法
                print();
                //每次成功，都要將陣列重歸為0
                Queenes[line]=0;
                return;
            }
            //繼續判斷下一樣皇后的擺法，遞迴
            eight_queen(line+1);
            //不管成功失敗，該位置都要重新歸0，以便重複使用。
            Queenes[line]=0;
        }
    }
}
