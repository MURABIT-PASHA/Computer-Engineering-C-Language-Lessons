#include <stdio.h>
#include <locale.h>
int x,y,z,j,k,l,m; 
int basamakdegeri(int sayi){
	x=sayi%10;
	y=sayi%100;
	z=sayi%1000;
	j=sayi%10000;
	k=sayi%100000;
	l=sayi%1000000;
	m=sayi%10000000;
	printf("\nSay�n�n birler basama��ndaki rakam�n basamak de�eri: %d",x);
	printf("\nSay�n�n onlar basama��ndaki rakam�n basamak de�eri: %d",y-x);
	printf("\nSay�n�n y�zler basama��ndaki rakam�n basamak de�eri: %d",z-y);
	printf("\nSay�n�n binler basama��ndaki rakam�n basamak de�eri: %d",j-z);
	printf("\nSay�n�n on binler basama��ndaki rakam�n basamak de�eri: %d",k-j);
	printf("\nSay�n�n y�z binler basama��ndaki rakam�n basamak de�eri: %d",l-k);
	printf("\nSay�n�n milyonlar basama��ndaki rakam�n basamak de�eri: %d",m-l);
	printf("\nSay�n�n basamak de�erlerinin toplam� %d",sayi);

	
}
main(){
	setlocale (LC_ALL, "Turkish");
	int sayi;
		printf("En fazla milyon olmak �zere bir say� giriniz: ");
		scanf("%d",&sayi);
		basamakdegeri(sayi);

}

// Created by MURABIT-PASHA
