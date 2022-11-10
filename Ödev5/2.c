// Girilen sayinin asal olup olmadigini bulan makine
#include <stdio.h>

int deger(int sayi){
	if ((sayi!=2) && (sayi%2==0) || (sayi!=3) && (sayi%3==0) || (sayi!=5) && (sayi%5==0) || (sayi!=7) && (sayi%7==0))
	printf("Sayiniz asal degil");
	else
	printf("Sayiniz asal");
	return(sayi);	
}
int main (){
	int sayi;
	printf("Bir sayi giriniz: ");
	scanf("%d",&sayi);
	deger(sayi);
	return 0;

}
// Created by MURABIT-PASHA