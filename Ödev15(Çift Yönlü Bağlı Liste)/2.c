#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct dll{
	int data1,data2;
	struct dll* back;//geri
	struct dll* forward;//ileri
};
int main(){
	struct dll* firstNode=NULL;//�lk d���m
	struct dll* lastNode=NULL;//Son d���m
	struct dll* temporary=NULL;//Ge�ici
	struct dll* ptr=NULL;//Son d���m�n bir �ncesine gelecek. Son d���m�n �ncesini g�steren pointer
	struct dll* find=NULL;//Bulmak i�in
	struct dll* other=NULL;//Bulmak i�in
	int a,d;//Girilecek say�lar
	int c=0;//Anahtar i�in
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
		printf("Onceki Adresi: %x, Adresi: %x, De�eri: %d, Sonraki Adresi: %x\n",
		temporary->back,temporary,temporary->data1,temporary->forward);
		temporary = temporary->forward;
		}
		temporary=firstNode;//Yukar�daki d�ng�y� ekrana yazarken ge�iciciyi sona getirmi�tim. Bununla yeniden ba�a ald�m.
		
		printf ("Aramak ve de silmek istediginiz degeri giriniz: ");
		scanf("%d",&d);
		while(temporary!=NULL){
			if (temporary->data1==d){
				find = temporary;
				c=1;
				break;
			}
			else{
				temporary = temporary->forward;
			}
		}
		switch(c){
			case 0:
				printf("Aradiginiz sayi bulunamadi...");
				break;
			case 1:
				if (find==firstNode){//Aranan say� ilk d���mde ise
				printf ("\nAranan deger bulundu!\n%x adresindeki sayi silindi.\n",temporary);
					firstNode=firstNode->forward;
					free(find);
				}
				else{
				printf ("\nAranan deger bulundu!\n%x adresindeki sayi silindi.\n",temporary);
				temporary=firstNode;
				while(temporary->forward!=find)
				temporary=temporary->forward;
				other=temporary->forward->forward;
				temporary->forward=temporary->forward->forward;
				other->back=temporary;
				free(find);						
				}
				break;
		}
				temporary=firstNode;
	printf ("Son Durum:\n");
	while(temporary!=NULL){
	printf("Onceki Adresi: %x, Adresi: %x, Degeri: %d, Sonraki Adresi: %x\n",
	temporary->back,temporary,temporary->data1,temporary->forward);
	temporary = temporary->forward;
	}
	return 0;
}
// Created by MURABIT-PASHA