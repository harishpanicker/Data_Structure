#include<stdio.h>
#include<stdlib.h>


typedef struct stack{

	int data;
	struct stack *next;

}SLL;


void push(SLL**);
void display(SLL*);
void pop(SLL**);

int main()
{

	int choice;
	SLL *hptr=NULL;

	system("clear");	

	

	while(1){
	
		printf("*********Enter the option********\n");
		printf("|\t1) PUSH\t\t\t|\n");
		printf("|\t2) POP\t\t\t|\n");
		printf("|\t3) DISPLAY\t\t|\n");
		printf("|\t4) EXIT\t\t\t|\n");
		printf("*********************************\n");

		scanf("%d",&choice);

		switch(choice){

			case 1: printf("Entered choice is Push\n");
				push(&hptr);
				break;
			case 2: printf("Entered choice is Pop\n");
				pop(&hptr);
				break;
			case 3: printf("Entered choice is display\n");
				display(hptr);
				break;
			case 4: printf("Entered choice is exit\n");
				exit(0);
				break;
		}

	}

	return 0;
}

void push(SLL**ptr){

	SLL *new = (SLL*)malloc(sizeof(SLL));


	if(new == NULL)  
    	{  
        	printf("******not able to push the element******\n");   
    	}  
	else{
		printf("\nEnter the data = ");
		scanf("%d",&new->data);
		if(*ptr==NULL)  
		{         
			new->next = NULL;  
			*ptr=new;  
		}   
		else   
		{  
			new->next = *ptr;  
			*ptr=new;                 
		}  
	}
}

void pop(SLL **ptr){

	int item;  
	SLL *temp = (SLL*)malloc(sizeof(SLL));
	if (*ptr == NULL)  
	{  
		printf("*****Underflow******\n");  
	}  
	else  
	{  
		item = (*ptr)->data;  
		temp = (*ptr);  
		*ptr = (*ptr)->next;  
		free(temp);  
		printf("Item popped = %d\n",item);  

	}  

}

void display(SLL* ptr){

	printf("Printing the value in the stack\n");

	while(ptr!=NULL){
		printf("%d --> ",ptr->data);
		ptr=ptr->next;

	}
	printf("\n");
}
