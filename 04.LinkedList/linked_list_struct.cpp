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

// g++ linked_list_struct.cpp -o linklist

typedef struct data{
	int num, score;
	char* name;
}data_s;                // data_s is a Variable, not Pointer

struct list	{		//List element contain (num, name, score) & a pointer to next
	data_s data_n;
	struct list *next;
};
typedef struct list node;	// 		  node = list    	// node is Variable of the struct
typedef node *link; 		// link is node's pointer  	// link is Pointer of the struct

link new_node(int num, int score);
link init_list(int len, char namedata[][10]);
link concat_list(link a, link b);
link insert_node(link a, link node);
void delete_node(link node);
link find_del_name(link head, char* name);
void print_list(link head);

int main() {
    srand((unsigned)time(NULL));

    char namedata1[12][10] = {  {"Allen"},{"Scott"},{"Mary"},
								{"Jon"},{"Mark"},{"Ricky"},
								{"Lisa"},{"Jassica"},{"Hanson"},
								{"Amy"},{"Bob"},{"Jack"}};

    char namedata2[12][10] = {{"May"},{"John"},{"Michael"},
							  {"Andy"},{"Tom"},{"Jane"},
							  {"Yoko"},{"Alex"},{"Alexa"},
							  {"Judy"},{"Kelly"},{"Lucy"}};
    // printf("%lu = %lu + %lu\n", sizeof(node), sizeof(data_s), sizeof(struct list*));
    // printf("%lu = %lu + %lu + %lu\n", sizeof(data_s), sizeof(int), sizeof(int), sizeof(char*));
    // printf("%lu\n", sizeof(&namedata1[0]));
    
    link head1 = init_list(12, namedata1);
    link head2 = init_list(12, namedata2);
    printf("\nList 1: \n");
    print_list(head1);
    printf("\nList 2: \n");
    print_list(head2);

    printf("\nconcat list1  and list2:\n");
    head1 = concat_list(head1, head2);
    print_list(head1);

    printf("\nremove Mark:\n");
    link find = find_del_name(head1, "Mark");
    delete_node(find);
    print_list(head1);
}
void delete_node(link node){
    link tmp = node->next;
    node->next = tmp->next;
    free(tmp);
    return;
}
link find_del_name(link head, char* name){
    link cur = head;
    while(cur->next != NULL){
        if(strncmp(cur->next->data_n.name, name, strlen(name))==1){
            return cur;
        }
    }
    return NULL;
}
link concat_list(link a, link b){
    link cur = a;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = b;
    return a;
}
link init_list(int len, char namedata[][10]){
    link cur = new_node(1, rand()%50 + 51);
    cur->data_n.name = &namedata[0][0];
    link head = cur;
    for(int i = 1; i < len; i++){
        link newNode = new_node(i+1, rand()%50+ 51);
        newNode->data_n.name = &namedata[i][0];
        cur->next = newNode;
        cur = cur->next;
    }
    return head;
}
link new_node(int num, int score){
    link n = (link)malloc(sizeof(node));
    n->data_n.num = num;
    n->data_n.score = score;
    n->next = NULL;

    return n;
}
void print_list(link head){
    link cur = head;
    int i = 0;
    while(cur != NULL){
        printf("[%2d %10s %3d] -> ", cur->data_n.num, cur->data_n.name, cur->data_n.score);
        i++;
        if(i == 3){
            printf("\n");
            i = 0;
        }
        cur = cur->next;
    }
    printf("NULL\n");

    return;
}