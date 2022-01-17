#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n *sag;
	struct n *sol;
};
typedef struct n node;

node *ekle(node *agac, int a){
	if(agac == NULL){
		node *root = (node*)malloc(sizeof(node));
		root->sag = NULL;
		root->sol = NULL;
		root->data = a;
		return root;
	}
	if(agac->data < a){
		agac->sag=ekle(agac->sag, a);
		return agac;
	}
	agac->sol=ekle(agac->sol, a);
	return agac;
}

void dolas(node *agac){
	if(agac == NULL)
		return ;
	dolas(agac->sag);
	printf("%d ", agac->data);
	dolas(agac->sol);
}

int bul(node *agac, int aranan){
	if(agac == NULL)
		return -1;
	if(agac->data == aranan)
		return 1;
	if(bul(agac->sag, aranan)==1)
		return 1;
	if(bul(agac->sol, aranan)==1)
		return 1;
	return -1;
}

int max(node *agac){
	while(agac->sag != NULL)
		agac = agac->sag;
	return agac->data;
}

int min(node *agac){
	while(agac->sol != NULL)
		agac = agac->sol;
	return agac->data;
}

node *sil(node *agac, int x){
	if(agac == NULL)
		return NULL;
	if(agac->data == x){
		if(agac->sol == NULL && agac->sag == NULL)
			return NULL;
		if(agac->sag != NULL)	{
			agac->data = min(agac->sag);
			agac->sag = sil(agac->sag, min(agac));
			return agac;
		}
		agac->data = max(agac->sol);
		agac->sol = sil(agac->sol, max(agac));
		return agac;
	}
	if(agac->data < x){
		agac->sag = sil(agac->sag, x);
		return agac;
	}
	agac->sol = sil(agac->sol, x);
	return agac;	
	
	
}

int main(int argc, char *argv[]) {
	node *agac = NULL;
	agac = ekle(agac, 56);
	agac = ekle(agac, 200);
	agac = ekle(agac, 213);
	agac = ekle(agac, 26);
	agac = ekle(agac, 28);
	agac = ekle(agac, 27);
	agac = ekle(agac, 190);
	dolas(agac);
	printf("\nArama sonucu: %d", bul(agac, 22));
	printf("\nMax: %d \nMin: %d \n", max(agac), min(agac));
	sil(agac, 28);
	dolas(agac);
	sil(agac, 190);
	dolas(agac);
	
	
	return 0;
}
