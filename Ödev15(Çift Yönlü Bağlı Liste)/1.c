#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct dll{//double linked list
	int data1;
	struct dll* back;//geri
	struct dll* forward;//ileri
};
int main(){
	struct dll* firstNode=NULL;//�lk d���m
	struct dll* lastNode=NULL;//Son d���m
	struct dll* temporary=NULL;//Ge�ici
	struct dll* ptr=NULL;//Son d���m�n bir �ncesine gelecek.
	int a,d;//Girilecek say�lar
	char b;//getch i�in karakter
	do{
	printf("Bir sayi gir: ");
	scanf("%d",&a);
	if (firstNode==NULL){
		firstNode = (struct dll*) malloc(sizeof(struct dll));
		firstNode->data1 = a;
		firstNode->forward = NULL;
		firstNode->back = NULL;
		lastNode = firstNode;
	}
	else{
		lastNode->forward = (struct dll*) malloc(sizeof(struct dll));
		ptr = lastNode;
		lastNode = lastNode->forward;
		lastNode->data1 = a;
		lastNode->back = ptr;
		lastNode->forward = NULL;
	}
	temporary=firstNode;
	printf("Devam edilsin mi?(E/H)");
	b=getch();
	system("CLS");//Her seferinde ekran� silecek
}while(b=='E' || b=='e');
		printf ("Ilk Durum:\n");
		while(temporary!=NULL){
		printf("Onceki Adresi: %x, Adresi: %x, Degeri: %d, Sonraki Adresi: %x\n",
		temporary->back,temporary,temporary->data1,temporary->forward);
		temporary = temporary->forward;
		}

	return 0;
}
// Created by MURABIT-PASHA