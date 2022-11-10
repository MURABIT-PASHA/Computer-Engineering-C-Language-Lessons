#include <stdio.h>
#include <math.h>
#include <locale.h>
int yeni, x, sayac=1;
int basamakdegeri(int sayi){
	do{
	sayi=sayi/10;
	sayac++;
}while(sayi>=10);
	printf("Basamak say�s� %d", sayac);
	yeni=pow(10,sayac-1);
	x=sayi%yeni;
	printf("\nSay�n�n ilk basama�� %d ve basamak de�eri %d",x,x*yeni);
	return (sayi);
}
int main() {
	setlocale (LC_ALL, "Turkish");
	int sayi;
	printf ("Bir say� gir: ");
	scanf("%d",&sayi);
	basamakdegeri(sayi);

	return 0;	
}
// Created by MURABIT-PASHA