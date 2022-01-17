#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n *next;
	struct n *prev;
};
typedef struct n node;

void printlist(node *ptr){
	node *iter = ptr;
	printf("%d ", iter->data);
	while(iter->next !=NULL){
		iter = iter->next;
		printf("%d ", iter->data);
	}
	printf("\n");
}

node * siraylaekle(node *ptr, int x){
	if(ptr == NULL){
		ptr= malloc(sizeof(node));
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->data = x;
		return ptr;		
	}
	if(ptr->data > x){
		node *temp= malloc(sizeof(node));
		ptr->prev = temp;
		temp->next = ptr;
		temp->data = x;
		return temp;
	}
	
	node *iter = ptr;
	while(iter->next != NULL && iter->next->data < x){
		iter = iter->next;
	}
	node *temp = malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;
	temp->data = x;
	if(temp->next != NULL)
		temp->next->prev = temp;
	temp->data = x;
	return ptr;
}

node *sil(node *ptr, int x){
	if(ptr==NULL){
		printf("Liste Bos!");
		return ptr;
	}
	
	if(ptr->data == x){
		node *temp = ptr;
		ptr= ptr->next;
		ptr->prev = NULL;
		free(temp);
		return ptr;
	}
	
	node *iter = ptr;
	while(iter->next != NULL && iter->next->data != x)
		iter = iter->next;
		
	if(iter->next == NULL){
		printf("Sayi Bulunamadi. \n");
		return ptr;
	}
	node *temp = iter->next;
	iter->next = temp->next;
	if(iter->next != NULL)
		iter->next->prev = iter;
	free(temp);
	return ptr;
	
	
}


int main(int argc, char *argv[]) {
	node * root;
	root =NULL;
	
	root=siraylaekle(root, 400);
	root=siraylaekle(root, 40);
	root=siraylaekle(root, 4);
	root=siraylaekle(root, 450);
	root=siraylaekle(root, 50);
	
	printlist(root);
	
	root=sil(root, 40);
	printlist(root);
	root=sil(root, 80);
	printlist(root);
	root=sil(root, 4);
	printlist(root);
	root=sil(root, 450);
	printlist(root);
	
	return 0;
}
