#include <stdio.h>
#include <stdlib.h>
#include "Stack_ll.h"

void bastir(node * r){
	if(r == NULL)
		printf("Stack bos!\n");
	while(r != NULL){
		printf("%d ", r->data);
		r = r->next;
	}
	printf("\n");
}

int pop(node *r){
	if(r == NULL){
		printf("Stack zaten bos!\n");
		return -1;
	}
	node *iter = r;
	if(r->next == NULL){
		int rvalue = r->data;
		free(r);
		return rvalue;
	}
	
	while(iter->next->next != NULL){
		iter = iter->next;
	}
	node *temp = iter->next;
	int rvalue = temp->data;
	iter->next = NULL;
	free(temp); 
	return rvalue;	
}

node * push(node *r, int a){
	if(r == NULL){
		r= (node *)malloc(sizeof(node));
		r->data = a;
		r->next = NULL;
		return r;
	}
	node *iter = r;
	while(iter->next != NULL){
		iter= iter->next;
	}
		node *temp = (node *)malloc(sizeof(node));
		iter->next = temp;
		temp->next = NULL;
		temp->data = a;
		return r;
		
}




int main(int argc, char *argv[]) {
	node *root =(node*)malloc(sizeof(node));
	root = NULL;
	root = push(root, 10);
	root = push(root, 20);
	bastir(root);
	printf("%d \n",pop(root));
	bastir(root);
	
	return 0;
}
