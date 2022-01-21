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

// ASCII code
//    +    -    *    /    (    )  
// | 43 | 45 | 42 | 47 | 40 | 41 |

struct list
{
    int element;
    int isnum;

    struct list *next;
};

typedef struct list node;
typedef node *link;

int convert(char);

int main()
{
    char string[256];
    printf("Enter the Infix form :\n");
    scanf("%s", string);

    int len = strlen(string);

    // linked list to save everything
    link head = (link)malloc(sizeof(node));
    head->isnum = -1;
    head ->next = NULL;
    link curr = head;
    link new;

    // postfix
    int buffer = 0; // save number
    int op, brack = 0; // save operator
    int* stack = (int*)malloc(sizeof(int)*0);
    int stack_size = 0;
    // go throuth string
    for(int i = 0; i < len; i++)
    {
        if( isdigit(string[i]) )
        {
            buffer = (buffer*10) + (string[i]-48);
        }
        else
        {
            // check operator
            op = convert( string[i] );
            if( op == 40 )
            {
                brack++;
            }
            else if(op == 41)
            {
                brack--;
            }
            else // operator not ()
            {
                // put buffer in to linked list
                new = (link)malloc(sizeof(node));
                new->element = buffer;
                new->isnum = 1;
                new->next = NULL;
                buffer = 0;

                curr->next = new;
                curr = new;

                // compare the priority
                op += 100*brack;
                if( stack_size == 0 )
                {
                    stack = (int*)realloc(stack, sizeof(int)*(stack_size+1) );
                    stack[stack_size] = op;
                    stack_size++;
                }
                else // compare the priority
                {
                    if(stack[stack_size-1]/10 > op/10)// push all stack to linked list
                    {
                        for(int i = stack_size-1; i >= 0; i--)
                        {
                            new = (link)malloc(sizeof(node));
                            new->element = stack[i]%100;
                            new->isnum = 0;
                            new->next = NULL;

                            curr->next = new;
                            curr = new;
                        }
                        stack_size = 0;
                    
                        stack = (int*)realloc(stack, sizeof(int)*(stack_size+1) );
                        stack[stack_size] = op;
                        stack_size++;
                    }
                    else // push into stack
                    {
                        stack = (int*)realloc(stack, sizeof(int)*(stack_size+1) );
                        stack[stack_size] = op;
                        stack_size++;
                    }
                }
            }
        }
    }
        // push the last number
        new = (link)malloc(sizeof(node));
        new->element = buffer;
        new->isnum = 1;
        new->next = NULL;

        curr->next = new;
        curr = new;
        // clear the stack
        for(int i = stack_size-1; i >= 0; i--)
        {
        new = (link)malloc(sizeof(node));
        new->element = stack[i]%100;
        new->isnum = 0;
        new->next = NULL;

        curr->next = new;
        curr = new;
        }
        // free stack
        free(stack);


    // print current linked list
    link temp = head;
    printf("the Profix of the given string:\n|");
    while(temp != NULL)
    {
        if(temp->isnum == 1)
        {
            printf(" %3d |", temp->element);
        }
        else if(temp->isnum == 0)
        {
            if(temp->element == 11)
            { printf("  +  |"); }
            else if(temp->element == 12)
            { printf("  -  |"); }
            else if(temp->element == 21)
            { printf("  *  |"); }
            else if(temp->element == 22)
            { printf("  /  |"); }
        }
        // if(temp->isnum != -1)
        // {printf(" %3d |", temp->element);}

        temp = temp->next;
    }
    printf("\n");

    // do calculate
    double result = 0;
    double* stack2 = (double*)realloc(stack, sizeof(double));
    stack_size = 0;
    curr = head;
    while(curr != NULL)
    {
        if(curr->isnum == 1)
        {
            // push 1
            stack2 = (double*)realloc(stack2, sizeof(double)*(stack_size+1));
            stack2[stack_size] = curr->element;
            stack_size++;
        }
        else if(curr->isnum == 0)
        {
            // do operation
            if(curr->element == 11)
            {
                result = stack2[stack_size-1] + stack2[stack_size-2];
            }
            else if(curr->element == 12)
            {
                result = stack2[stack_size-1] - stack2[stack_size-2];
            }
            else if(curr->element == 21)
            {
                result = stack2[stack_size-1] * stack2[stack_size-2];
            }
            else if(curr->element == 22)
            {
                result = stack2[stack_size-2] / stack2[stack_size-1];
            }
            // pop 2 & push result
            stack2 = (double*)realloc(stack2, sizeof(double)*(stack_size-1) );
            stack_size -= 1;
            stack2[stack_size-1] = result;
        }
        curr = curr->next;
    }
    printf("The result is: %lf\n", stack2[0]);
    free(stack2);


    // free the linked list
    temp = head;
    while(temp != NULL)
    {
        new = temp->next;
        free(temp);
        temp = new;
    }
    return 0;
}

int convert(char num)
{
// ASCII code
//    +    -    *    /    (    )
// | 43 | 45 | 42 | 47 | 40 | 41 |
// | 11 | 12 | 21 | 22 |

         if(num == 43){ return 11; }
    else if(num == 45){ return 12; }
    else if(num == 42){ return 21; }
    else if(num == 47){ return 22; }
       else{ return num; }
}
