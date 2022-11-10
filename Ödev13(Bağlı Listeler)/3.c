#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct OGRENCI{
	float vize;
	float final;
	float ortalama;
	struct OGRENCI *sonraki;
};
int main(){
	struct OGRENCI *ilk=NULL;
	struct OGRENCI *ptr=NULL;
	struct OGRENCI *gecici=NULL;	
	int b,c,i=0;//b=vize c=final i=sayac
	float d;//ortalama
	char a;//cevap
	do{
	printf ("%d. Ogrencinin vize notunu giriniz: ",i+1);
	scanf("%d",&b);
	printf ("%d. Ogrencinin final notunu giriniz: ",i+1);
	scanf("%d",&c);
		if (ilk==NULL){
			ilk = (struct OGRENCI*) malloc(sizeof(struct OGRENCI));
			ilk->vize = b;
			ilk->final = c;
			ilk->ortalama= (b*0.4)+(c*0.6);
			ilk->sonraki = NULL;
			ptr = ilk;
		}	
		else{
			ptr->sonraki = (struct OGRENCI*) malloc(sizeof(struct OGRENCI));
			ptr=ptr->sonraki;
			ptr->vize = b;
			ptr->final = c;
			ptr->ortalama= (b*0.4)+(c*0.6);
			ptr->sonraki = NULL;
		}
	gecici=ilk;
	i++;
	printf("Devam edilsin mi? (E)vet - (H)ayir\n");
	a=getch();
	}while(a=='E' || a=='e');
	while(gecici!=NULL){
		d+=gecici->ortalama;
		gecici=gecici->sonraki;
	}
	d=d/i;
	printf ("Girdiginiz Ogrencilerin akademik ortalamalari: %.2f",(float)d);
	return 0;
}
// Created by MURABIT-PASHA