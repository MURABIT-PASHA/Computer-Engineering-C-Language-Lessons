// Bir yapi olusturup bu yapiya bilgi kaydediniz. Kaydedilen bilgileri ekrana yazdiriniz
#include <stdio.h>

int main(){
struct{
char isim[30];
char soyisim[30];
int yas;
int aylikmaas;
}amele;
	printf("Calisanin adini giriniz: ");
	scanf("%s",&amele.isim);
	printf("Calisanin soyadini giriniz: ");
	scanf("%s",&amele.soyisim);
	printf("Calisanin yasini giriniz: ");
	scanf("%d",&amele.yas);
	printf("Calisanin aylik maasini giriniz: ");
	scanf("%d",&amele.aylikmaas);
	printf ("Calisanin adi-soyadi: %s %s\nCalisanin yasi: %d\nCalisanin aylik maasi: %d",amele.isim
																						,amele.soyisim
																						,amele.yas
																						,amele.aylikmaas);
	
	
	return 0;
}
// Created by MURABIT-PASHA