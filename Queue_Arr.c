#include <stdio.h>
#include <stdlib.h>

int *dizi;
int sirabasi = 0;
int sira = 0;
int boyut = 2;

void enque(int a){
	if(dizi == NULL){
		dizi = (int*)(malloc(sizeof(int)*2));
	}
	if(sira >= boyut){
		boyut = boyut*2;
		int *dizi2 = (int*)(malloc(sizeof(int)*boyut));
		int i;
		for(i=0; i<boyut/2; i++){
			dizi2[i] = dizi[sirabasi+i];
		}
		free(dizi);
		dizi = dizi2;
	}
	dizi[sira++]= a;

}

int deque(){
	if(sira-sirabasi == 0){
		printf("Sira Bos!!!\n");
		return -1;
	}
	if(sira-sirabasi <= boyut/4){
		boyut = boyut/2;
		int *dizi2 = (int*)(malloc(sizeof(int)*boyut));
		int i;
		for( i=0; i<sira-sirabasi; i++){
			dizi2[i] = dizi[sirabasi+i];
		}
		sira-=sirabasi;
		sirabasi = 0;
		free(dizi);
		dizi = dizi2;
	}
	return dizi[sirabasi++];
}

void toparla(){
	int i;
	for(i = 0; i<boyut; i++){
		dizi[i] = dizi[i+sirabasi];
	}
	sira -= sira-sirabasi;
	sirabasi = 0; 
}

int main(int argc, char *argv[]) {
	int i;
	for(i = 0; i<20; i++){
		enque(i*10);
	}
	printf(" durum: boyut: %d sira: %d sirabasi: %d \n", boyut, sira, sirabasi);
	
	for(i = 1; i<13; i++){
		printf(" %d ", deque());
	}
	printf(" durum: boyut: %d sira: %d sirabasi: %d \n", boyut, sira, sirabasi);
	for( i = 0; i<30; i++){
		printf(" %d", deque());
	}	
	printf(" durum: boyut: %d sira: %d sirabasi: %d \n", boyut, sira, sirabasi);
	
	return 0;
}
