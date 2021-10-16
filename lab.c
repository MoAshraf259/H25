#include <stdio.h>
#include "STD_type.h"
#include <stdlib.h>
#define Null 0
typedef struct New_Str {
	
	u32 Data;
	struct New_Str * Next;
	
}Mynode;

Mynode * head=Null;

void Add_First(u32 data);
void print_list(void);
void delete_first (void);
void add_last (u32 mydata);
void delete_last(void);
void insert_ele(u32 mydata , u32 counter);       //assignment
void delete_ele(u32 num);                        //assignment

void main (void){
	delete_first();
	
	print_list();
	
	Add_First(5);
	Add_First(6);
	Add_First(7);
	Add_First(9);
	Add_First(10);
	
	insert_ele(99,3);
	
	print_list();
	
	delete_ele(6);
	
	print_list();
	
}

void print_list(){
	
	if(head==Null){
		printf("Your node is empty ! \n");
	}
	else {
		u8 i=1;
		Mynode *Temp=head;
		do{
			printf("Element number %d is : %d\n",i,Temp -> Data);
			Temp=Temp->Next ;
			i++;
			
		}while(Temp !=Null);
		printf("********************\n");
	}
}

void Add_First(u32 MyData){
	Mynode * node=(Mynode *)malloc(sizeof(Mynode));
	node -> Data =MyData ;
	node ->Next = head;
	head = node;
}


void delete_first (void){
	
	if(head==Null){
		printf("Your node is Empty ! \n");
	}
	else{
		Mynode *temp=head;
		head = head->Next;
		temp ->Data = 0;
		temp ->Next=Null;
		free(temp);
	}
	
}


void add_last(u32 mydata){
	if (head==Null){
		Add_First(mydata);
	}
	else{
	    Mynode * data =(Mynode *) malloc( sizeof(Mynode) );
	    Mynode * temp = head;
	
	    data ->Data =mydata ;
	    data ->Next =Null;
	
	    while(temp ->Next !=Null ){
		     temp = temp->Next;
	}
	temp ->Next = data;
}

}

void delete_last (void){
	if(head==Null){
		printf("Your node is empty ! \n");
	}
	else {
	Mynode * front= head->Next;
	Mynode * back =head ;
	while(front->Next !=Null){
	
	front = front->Next ;
	back = back->Next ;
	
}
front->Next = Null;
front->Data = 0;
back ->Next =Null ;
free(front);
}
}

void insert_ele(u32 mydata , u32 counter){
	Mynode *front=head->Next;
	Mynode *back=head;
	
	for(u8 i=0;i<counter-1;i++){
		front=front->Next ;
		back=back->Next;
	}
	Mynode * data =(Mynode *) malloc( sizeof(Mynode) );
	data ->Data=mydata;
	data ->Next=front;
	back->Next =data;
}


void delete_ele (u32 num){
	Mynode *back = head;
	Mynode *front= head ->Next;
	
	for (int i=0;i<num-2;i++){
		back =back->Next;
		front =front->Next;
		
	}
	back->Next =front->Next ;
	front=0;
	free(front);
	
	
}