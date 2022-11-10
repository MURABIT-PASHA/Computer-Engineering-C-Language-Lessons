#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct OGRENCI{
	int id;
	float vize,final,ortalama;
	struct OGRENCI* onceki;
	struct OGRENCI* sonraki;
};
int main(){
	struct OGRENCI* ilkNod=NULL;
	struct OGRENCI* sonNod=NULL;
	struct OGRENCI* temporary=NULL;
	struct OGRENCI* ptr=NULL;
	float a,d;
	int c=1;
	char b;
	do{
	printf("%d. Ogrencinin Vize Notunu Giriniz: ",c);
	scanf("%f",&a);
	printf("%d. Ogrencinin Final Notunu Giriniz: ",c);
	scanf("%f",&d);
	if (ilkNod==NULL){
		ilkNod = (struct OGRENCI*) malloc(sizeof(struct OGRENCI));
		ilkNod->vize = a;
		ilkNod->final = d;
		ilkNod->id = c;
		ilkNod->ortalama = a*0.4 + d*0.6;
		ilkNod->sonraki = NULL;
		ilkNod->onceki = NULL;
		sonNod = ilkNod;
	}
	else{
		sonNod->sonraki = (struct OGRENCI*) malloc(sizeof(struct OGRENCI));
		ptr = sonNod;
		sonNod = sonNod->sonraki;
		sonNod->vize = a;
		sonNod->final = d;
		sonNod->id = c;
		sonNod->ortalama = a*0.4 + d*0.6;
		sonNod->onceki = ptr;
		sonNod->sonraki = NULL;
	}
	c++;
	temporary=ilkNod;
	printf("Devam edilsin mi?(E/H)");
	b=getch();
	system("CLS");
}while(b=='E' || b=='e');
float ort=0;
int i=1;
		printf ("Liste:\n");
		while(temporary!=NULL){
		ort+=temporary->ortalama;
		printf("%d. Ogrencinin Vizesi: %.2f\tFinali: %.2f\tOrtalama: %.2f\n",
		i,temporary->vize,temporary->final,temporary->ortalama);
		i++;
		temporary = temporary->sonraki;
		}	
		printf("Sinif ortalamasi: %.2f",(float)ort/(i-1));
	return 0;
}
// Created by MURABIT-PASHA