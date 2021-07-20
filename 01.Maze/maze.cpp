#include <stdio.h>
#include <stdlib.h>

#define ASCII_ESC "\033"

#define BOLD ASCII_ESC"[1m"
#define FLASH ASCII_ESC"[5m"

#define RST ASCII_ESC"[0m"
#define RED ASCII_ESC"[31m"
#define GRN ASCII_ESC"[32m"
#define YLW ASCII_ESC"[33m"
#define BL ASCII_ESC"[34m"
#define MGT ASCII_ESC"[35m"
#define CYN ASCII_ESC"[36m"
#define WHT ASCII_ESC"[37m"
#define GRY ASCII_ESC"[90m"
#define LRED ASCII_ESC"[91m"
#define LGRN ASCII_ESC"[92m"
#define LYLW ASCII_ESC"[93m"
#define LBL ASCII_ESC"[94m"
#define LMGT ASCII_ESC"[95m"
#define LCYN ASCII_ESC"[96m"
#define LWHT ASCII_ESC"[97m"

#define EAST MAZE[x][y+1]   /*定義相對東方*/
#define WEST MAZE[x][y-1]   /*定義相對西方*/
#define SOUTH MAZE[x+1][y]  /*定義相對南方*/
#define NORTH MAZE[x-1][y]  /*定義相對北方*/

#define ExitX 8
#define ExitY 10

int MAZE[10][12] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                     1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
                     1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 
                     1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 
                     1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 
                     1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
                     1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
                     1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
                     1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
                     1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 3 };

struct list{
    int x, y;
    struct list* next;
};
typedef struct list node;
typedef node *link;

link push (link, int , int );
link pop  (link, int*, int*);
int chk_exit(int, int, int, int);
void print_map();

int main()
{
    int i, j, x, y;
    link path = NULL;

    x = 1; // entrance x
    y = 1; // entrance y
    printf("The maze :"LYLW"\n(0 is the path)"WHT"\n(1 is wall) "GRN"\n(2 is entrance) "RED"\n(3 is exit)\n"RST);
    print_map();

    while( x <= ExitX && y <= ExitY )
    {
        MAZE[x][y] = 6;
        if(NORTH == 0) // if north is avaliable
        {
            x -= 1;
            path = push(path, x, y);
        }
        else if(SOUTH == 0) // if south is avaliable
        {
            x += 1;
            path = push(path, x, y);
        }
        else if(WEST == 0) // if west is avaliable
        {
            y -= 1;
            path = push(path, x, y);
        }
        else if(EAST == 0) // if east is avaliable
        {
            y += 1;
            path = push(path, x, y);
        }
        else if( chk_exit(x, y, ExitX, ExitY) == 1 )
        {
            break; // if get to the exit, end
        }
        else // if met dead, set a new start, and go back until somewhere avaliable
        {
            MAZE[x][y] = 2;
            path = pop(path, &x, &y);
        }
        // print_map();
    }

    printf(BL"(6 is the path)\n"RST);

    print_map();

    return 0;
}

link push (link stack, int x, int y)
{
    link newnode;
    newnode = (link)malloc(sizeof(node));

    if(!newnode)
    {
        printf("Error\n");
        return NULL;
    }
    newnode->x = x;
    newnode->y = y;
    newnode->next = stack;
    stack = newnode;

    return stack;
}

link pop  (link stack, int* x, int* y)
{
    link top;

    if(stack != NULL)
    {
        top = stack;
        stack = stack->next;
        *x = top->x;
        *y = top->y;
        free(top);

        return stack;
    }
    else
    {
        *x = -1;
    }

    return stack;
}

int chk_exit(int x, int y, int ex, int ey)
{
    if( x == ex && y == ey)
    {
        if(NORTH == 1 || SOUTH == 1 || WEST == 1 || EAST == 2)
        {
            return 1;
        }
        if(NORTH == 1 || SOUTH == 1 || WEST == 2 || EAST == 1)
        {
            return 1;
        }
        if(NORTH == 1 || SOUTH == 2 || WEST == 1 || EAST == 1)
        {
            return 1;
        }
        if(NORTH == 2 || SOUTH == 1 || WEST == 1 || EAST == 1)
        {
            return 1;
        }
    }
    return 0;
}


void print_map()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(MAZE[i][j] == 0)
            {
                printf(LYLW"%2d "RST,MAZE[i][j]);
            }
            else if(MAZE[i][j] == 1)
            {
                printf(WHT"%2d "RST,MAZE[i][j]);
            }
            else if(MAZE[i][j] == 2)
            {
                printf(GRN"%2d "RST,MAZE[i][j]);
            }
            else if(MAZE[i][j] == 3)
            {
                printf(RED"%2d "RST,MAZE[i][j]);
            }
            else if(MAZE[i][j] == 6)
            {
                printf(BL"%2d "RST,MAZE[i][j]);
            }
            else
            {
                printf("%2d ",MAZE[i][j]);
            }
        }
    printf("\n"); 
    }
    printf("\n");
}