#include <stdio.h>
#include <stdlib.h>

struct n
{
	int data;
	struct n * next;
};
typedef struct n node;

void printlist(node *temp){
		while(temp != NULL){
			printf("%d ", temp->data);
			temp= temp->next;	
	}
	printf("\n");
}

void ekle(node *r, int x){
	while(r->next != NULL){
		r=r->next;
	}
	r->next = malloc(sizeof(node));
	r->next->data = x;
	r->next->next = NULL; 
}

void arayaekle (node *ptr, int nereye, int deger ){
	int i;
	node *temp = malloc(sizeof(node));
	for(i=0; i<nereye-1; i++){
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next = temp;
	temp->data = deger;
}

node *siraylaekle(node *ptr, int x){
	if(ptr == NULL){
		ptr=malloc(sizeof(node));
		ptr->next = NULL;
		ptr->data = x;
		return ptr;
	}
	if(ptr->data > x){
			node *temp = malloc(sizeof(node));
			temp->next = ptr;
			temp->data = x;
			return temp;
	}

		
	node *iter = ptr;
	while(iter->next !=NULL && iter->next->data < x){
			iter = iter->next;
	}
	node *temp = malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = x;
	return ptr;
}

node * sil(node *ptr, int x){
	node *temp;
	node *iter = ptr;
	if(ptr->data == x){
		temp = ptr;
		ptr= ptr->next;
		free(temp);
		return ptr;
	}
	
	while(iter->next !=NULL && iter->next->data != x){
		iter = iter->next;
	}
	if(iter->next == NULL){
		printf("Sayi bulunamadi! \n");
		return ptr;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return ptr;
}


int main() {
	
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
