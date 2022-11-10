#include<stdio.h>
int yuzsayidanasalibulmafonksiyonu(int sayilar[100]){
	for (int c=0 ; c<100 ; c++){
		for(int g=2 ; g<sayilar[c] ; g++){
			if(sayilar[c]%g==0){
			sayilar[c]=0;
			}
		}	
	}
	FILE *filep2 = fopen("Say�lar2.txt","w");
	for (int f=0 ; f<100 ; f++){
		if (sayilar[f]==0){
		}
		else{
		fprintf (filep2,"%d	",sayilar[f]);
		}
	}
	fclose(filep2);
	printf("Mevcut dosyadaki asal sayilar basariyla yazildi");
}

int main(){
	int yenisayilar[100];
	FILE *filep1 = fopen("Say�lar.txt","r");
	if ((filep1) == NULL){
		printf ("Dosya bulunamadi");
	}
	else{
		for(int k=0 ; k<100 ; k++){
		fscanf(filep1,"%d",&yenisayilar[k]);
		}
		fclose(filep1);
	yuzsayidanasalibulmafonksiyonu(yenisayilar);		
	}
}
// Created by MURABIT-PASHA