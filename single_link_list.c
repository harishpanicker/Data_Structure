/*In this program I have tried to explore the Data structure 
*
* Data Structure is a way of collecting data(store) and organising(arrange) data in such a way that 
* we can perform various kind of operation(insert,dislpay,delete,search etc) 
* on these data in an efficient or effective way 
*
* Using single link list I have tried to perform various operation which I have mentioned in the README.txt file
*
*Author : harishpanicker
*
*/


#include "HEADER.H"

int main(){

	int choice,count;
	SLL *hptr=NULL;
	system("clear");

	while(1){

		printf("*******************Enter the option**********************\n");
		printf("|\t1) ADD NODE AT THE BEGINNING\t\t\t|\n");
		printf("|\t2) ADD NODE AT THE END\t\t\t\t|\n");
		printf("|\t3) ADD NODE AT THE MID(SORT THE LINKED LIST)\t|\n");
		printf("|\t4) DELETE PARTICULAR NODE\t\t\t|\n");
		printf("|\t5) COUNT THE NUMBER OF NODE\t\t\t|\n");
		printf("|\t6) REVERSE THE LINKED LIST\t\t\t|\n");
		printf("|\t7) FIND THE MID ELEMENT OF THE LINKLIST\t\t|\n");
		printf("|\t8) DISPLAY\t\t\t\t\t|\n");
		printf("|\t9) EXIT\t\t\t\t\t\t|\n");
		printf("*********************************************************\n");

		scanf("%d",&choice);

		switch(choice){
			case 1 : printf("Entered choice is to insert the element in manner of FILO or LIFO\n");
				 add_begin(&hptr);
				 break;
			case 2 : printf("Entered choice is to insert the element in manner of FIFO or LILO\n");
				 add_last(&hptr);
				 break;
			case 3 : printf("Entered choice is to get the element sorted in ascending order\n");
				 add_mid(&hptr);
				 break;
			case 4 : printf("Entered choice is to delete a particular node\n");
				 delete(&hptr);
				 break;
			case 5 : printf("Entered choice is to know how much node has been created = ");
				 count=count_node(hptr);
				 printf("%d\n",count);
				 break;
			case 6 : printf("Entered choice is to Reverse the Linklist\n");
				 reverse(&hptr);
				 break;
			case 7 : printf("Entered choice is to find the mid element in link list without count\n");
				 find_mid_element(hptr);
				 break;
			case 8 : printf("Entered choice is to display the content of link list\n");
				 display(hptr);
				 break;
			case 9 : printf("Entered choice is to Exit\n");
				 exit(0);
				 break;
			default : printf("Entered choice is in correct !!! Please try again...\n");

		}
	}

return 0;

}

/*This function helps to insert data in link list in FILO or LIFO manner*/

void add_begin(SLL**ptr){

	char choice;
	printf("\n");

	do{

		
		SLL *new=(SLL *)malloc(sizeof(SLL));
		printf("Enter the data = ");
		scanf("%d",&new->data);

		if(*ptr==NULL){
			*ptr=new;
			new->next=NULL;
		}
		else{
			new->next=*ptr;
			*ptr=new;
		}

		printf("Do you want to continue ? (y/n) = ");
		scanf(" %c",&choice);
	
	}while(choice=='y');


}


/*This function helps to insert data in link list in LILO or FIFO  manner*/

void add_last(SLL**ptr){


	char choice;
	printf("\n");
	
	do{
		SLL *new=(SLL *)malloc(sizeof(SLL));
		printf("Enter the data = ");
		scanf("%d",&new->data);


		if(*ptr==NULL){
			*ptr=new;
			new->next=NULL;
		}
		else{
			SLL *last=*ptr;	

			while(last->next!=NULL)
				last=last->next;

			new->next=last->next;
			last->next=new;
		}
		printf("Do you want to continue ? (y/n) = ");
		scanf(" %c",&choice);

	}while(choice=='y');
}


/*This function helps to insert data in link list in sorted manner*/

void add_mid(SLL**ptr){

	char choice;
	printf("\n");
	
	do{
		SLL *new=(SLL *)malloc(sizeof(SLL));

		printf("Enter the data = ");
		scanf("%d",&new->data);

		if((*ptr==NULL) || ((*ptr)->data > new->data)){
			new->next=*ptr;
			*ptr=new;
		}
		else{
			SLL *last=*ptr;

			while((last->next!=NULL) && (last->next->data < new->data))
				last=last->next;

			new->next=last->next;
			last->next=new;
		}
		printf("Do you want to continue ? (y/n) = ");
		scanf(" %c",&choice);

	}while(choice=='y');

}

/*This function helps to display the content of link list*/

void display(SLL*ptr){

	while(ptr!=NULL){
		printf("%d --> ",ptr->data);
		ptr=ptr->next;
	}
	printf("END\n\n");
}

/*This function helps to delete the from link list*/

void delete(SLL **ptr){

	SLL *temp=*ptr,*prev;
	int count=0,node;

	printf("Enter the node to be deleted= ");
	scanf("%d",&node);


	while(*ptr){
		count++;

		if(count==node){

			if(*ptr==temp)
				*ptr=temp->next;
			else{
				prev->next=temp->next;
			}
			free(temp);
			return;

		}
			prev=temp;
			temp=temp->next;

	}

}

/*This function helps to count the number of nodes created in linked list*/

int count_node(SLL *ptr){

	int count=0;

	while(ptr!=NULL){
		ptr=ptr->next;
		count++;
	}
	return count;
}

/*This function helps to reverse the linked list*/

void reverse(SLL** ptr){

	int count,idx=0;

	SLL **temp,*temp1;

	count=count_node(*ptr);

	temp=(SLL**)malloc(sizeof(SLL*)*count);
	temp1=*ptr;
	

	while(temp1){
		temp[idx++]=temp1;
		temp1=temp1->next;
	}

	temp[0]->next=0;

	for(idx=1;idx<count;idx++){
		temp[idx]->next=temp[idx-1];
	}

	*ptr = temp[count - 1];

	printf("\nReversing the entire link list\n");
}

/*This function helps to find mid element from the linked list */

void find_mid_element(SLL*ptr){

	int count;
	SLL *fast_ptr,*slow_ptr;

	fast_ptr=ptr;
	slow_ptr=ptr;


	while(fast_ptr!=NULL && fast_ptr->next!=NULL){
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
	}
	printf("Middle Element =  %d\n",slow_ptr->data);
}
