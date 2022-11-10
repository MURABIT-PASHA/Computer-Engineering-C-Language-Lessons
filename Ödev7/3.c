#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
struct sonuc{
	int EnBuyuk;
	int EnKucuk;
	float ortalama;
	float stdsap;
};
int boyut=10;
struct sonuc Hesapla(int sayi[])
{
	struct sonuc snc;
	int min=sayi[0],max=sayi[0];
	float ort, std=0;
	int toplam=0;
	for (int i=0 ; i<boyut ; i++)
	{
		if (sayi[i]<min)
		{
			min=sayi[i];
		}
		if(sayi[i]>max)
		{
			max=sayi[i];
		}
		toplam+=sayi[i];
	}
	ort=(float)toplam/boyut;
	for (int i=0 ; i<boyut ; i++){
		std += (float)pow(sayi[i] - ort, 2);
		
	}
	std=(float)sqrt(std/(boyut-1));
	snc.EnBuyuk=max;
	snc.EnKucuk=min;
	snc.ortalama=ort;
	snc.stdsap=std;
	return snc;
}
int main(){
	srand(time(NULL));
	struct sonuc snc;
	int sayi[boyut];
	for (int i=0 ; i<boyut ; i++)
	{
		sayi[i]=rand()%101;
		printf ("%d. sayi= %d \n",i+1,sayi[i]);
	}
	printf("\n SONUCLAR \n");
	snc=Hesapla(sayi);
	
	printf ("\nEn buyuk sayi: %d",snc.EnBuyuk);
	printf ("\nEn kucuk sayi: %d",snc.EnKucuk);
	printf ("\nTum sayilarin ortalamasi: %0.2f",snc.ortalama);
	printf ("\nStandart sapmasi: %0.2f",snc.stdsap);
		
	return 0;
}
// Created by MURABIT-PASHA