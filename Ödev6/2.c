// Bir yapiya birden fazla kisi kaydedip, kisi bilgilerini getiriniz.

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale (LC_ALL, "Turkish");

	struct{
		char isim[30];
		char soyisim[30];
		int num;
		struct{
		char ders_kod[10];
		int vize;
		int final;
	}ders[5];
	}ogrenci[5];
	for (int i=0 ; i<5 ; i++){
		printf("%d. Ogrencinin ismini giriniz: ",i+1);
		scanf("%s",&ogrenci[i].isim);	
		printf("%d. Ogrencinin soyismini giriniz: ",i+1);
		scanf("%s",&ogrenci[i].soyisim);
		printf("%d. Ogrencinin numarasini giriniz: ",i+1);
		scanf("%d",&ogrenci[i].num);
		printf("%d. Ogrencinin aldigi dersin adini giriniz: ",i+1);
		scanf("%s",&ogrenci[i].ders[i].ders_kod);
		printf("%d. Ogrencinin %s dersinde almis oldugu vize notunu giriniz: ",i+1,ogrenci[i].ders[i].ders_kod);
		scanf("%d",&ogrenci[i].ders[i].vize);
		printf("%d. Ogrencinin %s dersinde almis oldugu final notunu giriniz: ",i+1,ogrenci[i].ders[i]);
		scanf("%d",&ogrenci[i].ders[i].final);			
	}
	for (int i=0 ; i<5 ; i++){
		printf ("\n%d. Ogrencinin Bilgileri:\nAdi Soyadi: %s %s\nNumarasi: %d\nAldigi Ders: %s\nGecme Notu: %.2f",
		i+1,
		ogrenci[i].isim,
		ogrenci[i].soyisim,
		ogrenci[i].num,
		ogrenci[i].ders[i],
		(float) (ogrenci[i].ders[i].vize*(0.4)) + (ogrenci[i].ders[i].final*(0.6)));
		printf("\n");
	}
	
	
	
	return 0;
}
// Created by MURABIT-PASHA