#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n *next;
};
typedef struct n node;

void printlist(node *ptr){
	node *iter = ptr;
	printf("%d ", iter->data);
	iter=iter->next;
	
	while(iter != ptr){
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}

void ekle(node *ptr, int x){
	node *iter = ptr;
	while(iter->next != ptr){
		iter=iter->next;
	}
	iter->next = malloc(sizeof(node));
	iter->next->next = ptr;
	iter->next->data = x;
}

node *siraylaekle(node *ptr, int x){
	if(ptr == NULL){
		ptr= malloc(sizeof(node));
		ptr->next = ptr;
		ptr->data = x;
		return ptr;
	}
	
	if(ptr->data > x){
		node *temp = malloc(sizeof(node));
		temp->next = ptr;
		temp->data = x;
		node *iter = ptr;
		while(iter->next != ptr)
			iter=iter->next;
		iter->next = temp;
		return temp;	
	}
	
	node *iter = ptr;
	while(iter->next != ptr && iter->next->data < x){
		iter= iter->next;
	}
	node *temp = malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = x;
	return ptr;
}

node * sil(node* ptr, int x){
	if(ptr== NULL){
		printf("Liste bos!");
		return ptr;
	}
	node *iter = ptr;
	if(ptr->data == x){
		while(iter->next != ptr)
			iter = iter->next;
		iter->next = ptr->next;
		free(ptr);
		return iter->next;
	}
	
	while(iter->next != ptr && iter->next->data !=x)
		iter=iter->next;
		
	if(iter->next == ptr){
		printf("Sayi bulunamadi. \n");
		return ptr;
	}
	node *temp = iter->next;
	iter->next = temp->next;
	free(temp);
	return ptr;
}



int main(int argc, char *argv[]) {
	node * root = NULL;
	root = siraylaekle(root, 40);
	root = 	siraylaekle(root, 4);
	root = 	siraylaekle(root, 450);
	root = 	siraylaekle(root, 50);
	root = 	siraylaekle(root, 20);
	
	printlist(root);
	
	root = sil(root, 4);
	printlist(root);

	root = sil(root, 450);
	printlist(root);
	
	root = sil(root, 20);
	printlist(root);
	
	root = sil(root, 9);
	printlist(root);

	
	return 0;
}
