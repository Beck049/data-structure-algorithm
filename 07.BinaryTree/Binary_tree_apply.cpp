#include <iostream>
#include <cstdio>
#include <iomanip>   
#include <cmath>        
#include <cstring>     
#include <cctype>
#include <stdlib.h>
#include <cassert>
#include <cstdarg>
#include <climits>
#include <stdio.h>
#include <string>
#include <stdint.h>	
#include <time.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

typedef struct Node node;
typedef node *tree;

tree create(tree,int);
tree search(tree,int);
tree del(tree, int);
// find_big(tree);

void in   (tree);
int data[] = {7,1,4,2,8,13,12,11,15,9,5};

int main()
{
    tree ptr  = NULL;
    tree root = NULL;

    int key = 0;
    int value = 0;
    //create the bynary tree
    for(int i = 0; i < 9; i++)
    {
        ptr = create(ptr,data[i]);
    }

    while(key != -1)
    {
        printf("Enter 1 to search\nEnter 2 to add\nEnter 3 to delete\nEnter 4 to print\n");
        scanf("%d", &key);

        if(key == -1)//leave
            break;
        else if(key == 1)//search
        {
            printf("Enter the value to find : ");
            scanf("%d",&value);

            if(search(ptr,value) != NULL)
            {
                printf("The value is exist\n");
            }
            else
            {
                printf("value not found\n");
            }
        }
        else if(key == 2)//add
        {
            printf("Enter the value to add : ");
            scanf("%d",&value);

            if(search(ptr,value) != NULL)
            {
                printf("The value is already exist\n");
            }
            else
            {
                ptr = create(ptr,value);
                printf("value %3d add success\n",value);
            }
        }

        else if(key == 3)//delete
        {                //找 value = key 的左子樹 的最右下
            printf("Enter the value to delete : ");
            scanf("%d",&value);

            del(ptr,value);
        }
        else if(key == 4)//print current tree
        {
            printf("Current tree：\n");
            in(ptr);
            printf("\n");
        }
        else//error
        {
            printf("Invalid key\n");
        }
    }
    printf("===================================\n");
    printf("Result：\n");
    in(ptr);
    printf("\n");

    return 0;
}
//////////////////////////////////////////////////////////
tree create (tree root, int value)
{
    tree newnode, current, backup;
    //set values
    newnode = (tree)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->data = value;
    newnode->right= NULL;

    if(root == NULL)//第一項
    {
        root = newnode;// newnode 的值 複製到 root
        return root;
    }
    else
    {
        for(current = root; current != NULL;)//不改變current值
        {
            backup = current;

            if(current->data > value)//比 root 小就往左，直到 current->left = NULL
            {
                current = current->left;
            }
            else                    //比 root 大就往右，直到 current->right = NULL
            {
                current = current->right;
            }
        }//backup 為 newnode 的 root

        if(backup->data > value)
        {
            backup->left = newnode;
        }
        else
        {
            backup->right = newnode;
        }

        return root;
    }
}

tree search(tree ptr, int value)
{
    int i = 1 ;//找了幾次

    while(1)
    {
        if(ptr == NULL)         // not found
        {   return NULL;    }
        if(ptr->data == value) 
        {
        //  printf("Search %3d times\n",i);
            return ptr;
        }
        else if(ptr->data > value)
        {
            ptr = ptr->left;//大於value -> 向左找
        }
        else if(ptr->data < value)
        {
            ptr = ptr->right;//小於value -> 向右找
        }

        i++;
    }
}

void in (tree ptr)      //中序走訪
{                       //
    if(ptr != NULL)
    {
        in (ptr->left);//left tree
        printf("[%2d] ",ptr->data);//root
        in(ptr->right);//right tree
    }
}

tree del(tree ref, int value)
{
    printf("It is not avaliable");
    return ref;
}