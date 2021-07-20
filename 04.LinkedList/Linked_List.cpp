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
 
struct list			//List element contain (num, name, score) & a pointer to next
{
	int num, score;
	char name[10];
	
	struct list *next;
};

typedef struct list node;	// 		  node = list    	// node is Variable of the struct
														//  node.age  = 24
typedef node *link; 		// link is node's pointer  	// link is Pointer of the struct
														//  link->age = 24
link concatlist(link, link);

link del(link, link);

int main()
{
	link head; 		// 
	link ptr; 		//
	link newnode; 	// 
//	link last;		//
//	link before;	//
	link head1, head2;
	int data[12][2];
	int number;
//// set 1st linked list element	
	// set List element : (name) 
	char namedata1[12][10] = {  {"Allen"},{"Scott"},{"Mary"},
								{"Jon"},{"Mark"},{"Ricky"},
								{"Lisa"},{"Jassica"},{"Hanson"},
								{"Amy"},{"Bob"},{"Jack"}};
	//
	srand((unsigned)time(NULL));// set first-time rand seed
	
	for(int i = 0; i < 12; i++) // set List element : (num, score)
	{
		data[i][0] = i+1;				//data[i][0] is num
		data[i][1] = rand()%50 + 51;	//data[i][1] is score
	}
	// namedata & data are buffer
////
//// set first struct in Linked List

	// open space for linked List 1
	head1 = (link)malloc(sizeof(node)); 
	
	if(!head1)
	{
		printf("ERROR\n");
		exit(1);
	}
	
	head1->num = data[0][0];  //set head1's num = data[0][0]
	//
	//
	for(int j = 0; j < 10; j++)
	{
		head1->name[j] = namedata1[0][j];
		// set newnode's name = namedata1[0][j]
		// its a string that's less then 10 charactor
	}
	head1->score = data[0][1];  //set head1's score = data[0][1]
	head1->next = NULL;  //set head1's  next = NULL
	//
	
	ptr = head1;// let ptr = the pointer of the head of link list 
	
	for(int i = 1; i< 12; i++)
	{
		newnode = (link)malloc(sizeof(node));// open space for newnode
 
		newnode->num   = data[i][0];//set newnode's num   = data[i][0]
		newnode->score = data[i][1];//set newnode's score = data[i][1]
		
		for(int j = 0; j < 10; j++)
		{
			newnode->name[j] = namedata1[i][j];
			//set newnode's name = namedata1[i][j]
		}
		
		newnode->next = NULL;// let newnode's next to be NULL 
		
		ptr->next = newnode;// previous struct's next to be current struct's pointer
		
		ptr = newnode;// set current struct's pointer to be new head
	//	ptr = ptr->next;
	}
////
//// set 2nd linked list element	
	// set List element : (name) 
	char namedata2[12][10] = {{"May"},{"John"},{"Michael"},
							  {"Andy"},{"Tom"},{"Jane"},
							  {"Yoko"},{"Alex"},{"Alexa"},
							  {"Judy"},{"Kelly"},{"Lucy"}};
							
	srand((unsigned)time(NULL)); // set second-time rand seed
								 // not essentially required
	
	for(int i = 0; i < 12; i++)  // set List element : (num, score)
	{
		data[i][0] = i+13;			// data[i][0] is num
		data[i][1] = rand()%40 + 41;// data[i][1] is score
		number = i+13;
	}
////
//// set first struct in Linked List

	// open space for linked List 2
	head2 = (link)malloc(sizeof(node));
	
	if(!head2)
	{
		printf("ERROR");
		exit(1);
	}
	
	head2->num = data[0][0];//set head2's num = data[0][0]
	
	for(int j = 0; j < 10; j++)
	{
		head2->name[j] = namedata2[0][j];
		//set newnode's name = namedata2[0][j]
	}
	head2->score = data[0][1];  //set head1's score = data[0][1]
	head2->next = NULL;  //set head1's  next = NULL
	
	ptr = head2;// let ptr = the pointer of the head of link list
	
	for(int i = 1; i < 12; i++)
	{
		newnode = (link)malloc(sizeof(node));// open space for newnode

		newnode->num   = data[i][0];//set head's  num   = data[i][0]
		newnode->score = data[i][1];//set head2's score = data[i][1]

		for(int j = 0; j < 10; j++)
		{
			newnode->name[j] = namedata2[i][j];
			//set newnode's name = namedata2[i][j]
		}

		newnode->next = NULL;// let newnode's next to be NULL 
		
		ptr->next = newnode;// previous struct's next to be current struct's pointer

		ptr = newnode;// set current struct's pointer to be new head
	//	ptr = ptr->next;
	}
////
//// concat two Linked List 
	ptr = concatlist(head1,head2);
	head  = ptr;
	
	printf("the concat of Linked List is : \n");
	
	int i = 0;
	while(ptr != NULL)
	{
		printf("[%2d %10s %3d] -> ", ptr->num, ptr->name, ptr->score);
				// print num  name  score// 
		i++;
		
		if(i >= 3)// end line for every 4 element (0 ~ 3) // 
		{
			printf("\n");
			i = 0;
		}
		
		ptr = ptr->next;
	}
	printf("NULL\n");
////	
//// Delete struct in linked list
	char delname[10] = {0};
	char end[10] = "0";
	int find = 0;
	// ptr = the address to be deleted 
	while(1)
	{
		printf("Enter the name to delete, 0 if end delete : \n");
		scanf("%s",delname);
		
		// press 0 to exit delete phase
		if(strcmp(delname, end) == 0) 
			break;	
		else
		{
			ptr  = head;
			find =  0 ; // the key to tell if founded or not
			
			while(ptr != NULL) // keep find until last struct (ptr == NULL)
			{
				// if found the struct
				if(strcmp(ptr->name, delname) == 0)
				{
					ptr = del(head, ptr);
					find++; // find == 1, means found
					head = ptr;
					break; // jump out [ while(ptr != NULL) ] loop
				}
				// if not found then go to next struct
				ptr = ptr->next;
			}

			if(find == 0)
			{
				printf("404 Not Found");
			}
		}
	}
	//	
	printf("New linked list : \n");
	
	ptr = head;
	i = 0;
	while(ptr != NULL)
	{
		printf("[%2d %10s %3d] -> ", ptr->num, ptr->name, ptr->score);
				// print num  name  score// 
		i++;
		
		if(i >= 3)// end line for every 4 element (0 ~ 3) //
		{
			printf("\n");
			i = 0;
		}
		
		ptr = ptr->next;
	}
	printf("NULL\n");
//// 
//// Add new struct in linked list
	int keynum;
	find = 0;
	
	char newname[10];
	int newscore = 0;
	
	// ptr = the address to be added
	while(1)
	{
		srand((unsigned)time(NULL)); // set n-time rand seed
		newscore = rand()%10 + 90;
		
		number++;
		
		printf("Enter the number to put before ,-1 if end adding: ");
		scanf("%d",&keynum);
		
		if(keynum == -1) // enter -1 to exit
			break;	
		else
		{
			printf("Enter the new member's name : \n");
			scanf("%s",newname);
		
			ptr = head;
			find = 0;
			
			// open space for newnode
			newnode = (link)malloc(sizeof(node));
			
			// put elements into new struck
			strcpy(newnode->name,newname);
			newnode->num  = number;
			newnode->score= newscore;
			newnode->next = NULL;
			
			// if put newnode to the head
			if(keynum == 0) 
			{
				newnode->next = ptr;
				head = newnode;
			}
			else
			{
				while(ptr != NULL)
				{
					if(ptr->num == keynum) // go to the number to insert
					{
						// insert the struct
						link n_ptr;
						n_ptr = ptr->next;
						newnode->next = n_ptr;
						ptr->next = newnode;
						
						find++;
						break;
					}
					ptr = ptr->next; // else keep going
				}
			
				if(find == 0)
				{
					printf("404 Not Found");
				}
			}
		}
	}
	//	
	printf("New linked list : \n");
	
	ptr = head;
	i = 0;
	while(ptr != NULL)
	{
		printf("[%2d %10s %3d] -> ", ptr->num, ptr->name, ptr->score);
				//print num  name  score// 
		i++;
		
		if(i >= 3)// end line for every 4 element (0 ~ 3) //
		{
			printf("\n");
			i = 0;
		}
		
		ptr = ptr->next;
	}
	printf("NULL\n");
////
	return 0;
}
/*
link add()
{
	
}
*/
link del(link head, link ptr)
{
	link top;
	top = head;
	
	if(ptr == top)//if delete the first node
	{
		head = head->next;
		printf("Deleted\n");
	}
	else
	{
		while(top->next != ptr)
		{
			top = top->next;
		}
		if(ptr->next == NULL)//if delete the last node
		{
			top->next = NULL;
			printf("Deleted\n");
		}
		else
		{
			top->next = ptr->next;
			printf("Deleted\n");
		}
	}
	free(ptr);
	
	return head;
}

link concatlist(link ptr1, link ptr2) // head of linked list 1 & 2 //
{
	link ptr;
	ptr = ptr1;
	
// find the adderss when ptr1->next == NULL 
// let that ptr1->next = ptr2 
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = ptr2;
	
	return ptr1;
}

