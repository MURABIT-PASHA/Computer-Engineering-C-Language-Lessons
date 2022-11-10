// Tek ve cift olanlarin geometrik ortalamasini alan program yaziniz
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
int main(){
	setlocale (LC_ALL, "Turkish");
	int a,i=0;
	double sayac=0,b=1,c=0;
	int dizi[100];
	char cevap;
	do{
		printf("Numara giriniz: ");
		scanf("%d",&a);
		dizi[i]=a;
		i++;
		printf("Devam edilsin mi? (E)vet/(H)ayir\n");
		cevap=getch();
	}while(cevap=='E'||cevap=='e');
	for(int k=0 ; k<i ; k++){
		if(dizi[k]%2==0){
			sayac++;
			b=b*dizi[k];
		}
		else
			c=c+dizi[k];
	}
	double tsonuc,csonuc;
	tsonuc=c/(i-sayac);
	csonuc=pow(b,1/sayac);
	printf("Tek olanalarin aritmetik ortalamasi: %.2f\n",tsonuc);
	printf("Cift olanlarin geometrik ortalamasi: %.2f\n",csonuc);
}
// Created by MURABIT-PASHA