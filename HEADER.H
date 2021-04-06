#include<stdio.h>
#include<stdlib.h>

typedef struct singlelinklist{

	int data;
	struct singlelinklist *next;

}SLL;

void add_begin(SLL**);
void add_mid(SLL**);
void add_last(SLL**);
void delete(SLL**);
void display(SLL*);
int count_node(SLL *);
void reverse(SLL**);
void find_mid_element(SLL*);

