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
void in   (tree);
void post (tree);
void pre  (tree);

int data[] = {5,6,24,8,12,3,17,1,9};

int main()
{
    tree ptr  = NULL;
    tree root = NULL;

    for(int i = 0; i < 9; i++)
    {
        ptr = create(ptr,data[i]);
    }



    printf("===================================\n");
    printf("PreOrder：\n");
    pre(ptr);
    printf("\n");

    printf("===================================\n");
    printf("InOrder：\n");
    in(ptr);
    printf("\n");

    printf("===================================\n");
    printf("PostOrder：\n");
    post(ptr);
    printf("\n");
}

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

void in (tree ptr)      //中序走訪
{                       //
    if(ptr != NULL)
    {
        in (ptr->left);//left tree
        printf("[%2d] ",ptr->data);//root
        in(ptr->right);//right tree
    }
}

void pre (tree ptr)     //前序走訪
{                       //
    if(ptr != NULL)
    {
        printf("[%2d] ",ptr->data);//root
        in (ptr->left);//left tree
        in(ptr->right);//right tree
    }
}

void post (tree ptr)    //後序走訪
{                       //
    if(ptr != NULL)
    {
        in (ptr->left);//left tree
        in(ptr->right);//right tree
        printf("[%2d] ",ptr->data);//root
    }
}